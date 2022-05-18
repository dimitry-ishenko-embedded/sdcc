/* Coff file dumper.
   Copyright (C) 1994-2022 Free Software Foundation, Inc.

   This file is part of GNU Binutils.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or (at
   your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */


/* Written by Steve Chamberlain <sac@cygnus.com>

   This module reads a type tree generated by coffgrok and prints
   it out so we can test the grokker.  */

#include "sysdep.h"
#include "bfd.h"
#include <stdint.h>
#include "libiberty.h"
#include "bucomm.h"

#include "coffgrok.h"
#include "getopt.h"

static int atnl;

static void tab (int);
static void nl (void);
static void dump_coff_lines (struct coff_line *);
static void dump_coff_type (struct coff_type *);
static void dump_coff_where (struct coff_where *);
static void dump_coff_visible (struct coff_visible *);
static void dump_coff_scope (struct coff_scope *);
static void dump_coff_sfile (struct coff_sfile *);
static void dump_coff_section (struct coff_section *);
static void show_usage (FILE *, int);
extern int main (int, char **);

static void
tab (int x)
{
  static int indent;
  int i;

  if (atnl)
    {
      if (x < 0)
	{
	  printf (")");
	  indent += x;

	  return;
	}
      else
	{
	  printf ("\n");
	  atnl = 0;
	}
    }

  if (x == -1)
    {
      for (i = 0; i < indent; i++)
	printf ("   ");

      indent += x;
      printf (")");
      return;
    }

  indent += x;

  for (i = 0; i < indent; i++)
    printf ("   ");

  if (x)
    {
      printf ("(");
    }
}

static void
nl (void)
{
  atnl = 1;
}

static void
dump_coff_lines (struct coff_line *p)
{
  int i;
  int online = 0;

  tab (1);
  printf (_("#lines %d "),p->nlines);

  for (i = 0; i < p->nlines; i++)
    {
      printf ("(%d 0x%x)", p->lines[i], p->addresses[i]);

      online++;

      if (online > 6)
	{
	  nl ();
	  tab (0);
	  online = 0;
	}
    }
  nl ();
  tab (-1);
}

static void
dump_coff_type (struct coff_type *p)
{
  tab (1);
  printf (_("size %d "), p->size);

  switch (p->type)
    {
    case coff_secdef_type:
      printf (_("section definition at %x size %x\n"),
	      p->u.asecdef.address,
	      p->u.asecdef.size);
      nl ();
      break;
    case coff_pointer_type:
      printf (_("pointer to"));
      nl ();
      dump_coff_type (p->u.pointer.points_to);
      break;
    case coff_array_type:
      printf (_("array [%d] of"), p->u.array.dim);
      nl ();
      dump_coff_type (p->u.array.array_of);
      break;
    case coff_function_type:
      printf (_("function returning"));
      nl ();
      dump_coff_type (p->u.function.function_returns);
      dump_coff_lines (p->u.function.lines);
      printf (_("arguments"));
      nl ();
      dump_coff_scope (p->u.function.parameters);
      tab (0);
      printf (_("code"));
      nl ();
      dump_coff_scope (p->u.function.code);
      tab(0);
      break;
    case coff_structdef_type:
      printf (_("structure definition"));
      nl ();
      dump_coff_scope (p->u.astructdef.elements);
      break;
    case coff_structref_type:
      if (!p->u.aenumref.ref)
	printf (_("structure ref to UNKNOWN struct"));
      else
	printf (_("structure ref to %s"), p->u.aenumref.ref->name);
      break;
    case coff_enumref_type:
      printf (_("enum ref to %s"), p->u.astructref.ref->name);
      break;
    case coff_enumdef_type:
      printf (_("enum definition"));
      nl ();
      dump_coff_scope (p->u.aenumdef.elements);
      break;
    case coff_basic_type:
      switch (p->u.basic)
	{
	case T_NULL:
	  printf ("NULL");
	  break;
	case T_VOID:
	  printf ("VOID");
	  break;
	case T_CHAR:
	  printf ("CHAR");
	  break;
	case T_SHORT:
	  printf ("SHORT");
	  break;
	case T_INT:
	  printf ("INT ");
	  break;
	case T_LONG:
	  printf ("LONG");
	  break;
	case T_FLOAT:
	  printf ("FLOAT");
	  break;
	case T_DOUBLE:
	  printf ("DOUBLE");
	  break;
	case T_STRUCT:
	  printf ("STRUCT");
	  break;
	case T_UNION:
	  printf ("UNION");
	  break;
	case T_ENUM:
	  printf ("ENUM");
	  break;
	case T_MOE:
	  printf ("MOE ");
	  break;
	case T_UCHAR:
	  printf ("UCHAR");
	  break;
	case T_USHORT:
	  printf ("USHORT");
	  break;
	case T_UINT:
	  printf ("UINT");
	  break;
	case T_ULONG:
	  printf ("ULONG");
	  break;
	case T_LNGDBL:
	  printf ("LNGDBL");
	  break;
	default:
	  abort ();
	}
    }
  nl ();
  tab (-1);
}

static void
dump_coff_where (struct coff_where *p)
{
  tab (1);
  switch (p->where)
    {
    case coff_where_stack:
      printf (_("Stack offset %x"), p->offset);
      break;
    case coff_where_memory:
      printf (_("Memory section %s+%x"), p->section->name, p->offset);
      break;
    case coff_where_register:
      printf (_("Register %d"), p->offset);
      break;
    case coff_where_member_of_struct:
      printf (_("Struct Member offset %x"), p->offset);
      break;
    case coff_where_member_of_enum:
      printf (_("Enum Member offset %x"), p->offset);
      break;
    case coff_where_unknown:
      printf (_("Undefined symbol"));
      break;
    case coff_where_strtag:
      printf ("STRTAG");
      break;
    case coff_where_entag:
      printf ("ENTAG");
      break;
    case coff_where_typedef:
      printf ("TYPEDEF");
      break;
    default:
      abort ();
    }
  nl ();
  tab (-1);
}

static void
dump_coff_visible (struct coff_visible *p)
{
  tab (1);
  switch (p->type)
    {
    case coff_vis_ext_def:
      printf ("coff_vis_ext_def");
      break;
    case coff_vis_ext_ref:
      printf ("coff_vis_ext_ref");
      break;
    case coff_vis_int_def:
      printf ("coff_vis_int_def");
      break;
    case coff_vis_common:
      printf ("coff_vis_common");
      break;
    case coff_vis_auto:
      printf ("coff_vis_auto");
      break;
    case coff_vis_autoparam:
      printf ("coff_vis_autoparam");
      break;
    case coff_vis_regparam:
      printf ("coff_vis_regparam");
      break;
    case coff_vis_register:
      printf ("coff_vis_register");
      break;
    case coff_vis_tag:
      printf ("coff_vis_tag");
      break;
    case coff_vis_member_of_struct:
      printf ("coff_vis_member_of_struct");
      break;
    case coff_vis_member_of_enum:
      printf ("coff_vis_member_of_enum");
      break;
    default:
      abort ();
    }
  nl ();
  tab (-1);
}

static void
dump_coff_symbol (struct coff_symbol *p)
{
  tab (1);
  printf (_("List of symbols"));
  nl ();

  while (p)
    {
      tab (1);
      tab (1);
      printf (_("Symbol  %s, tag %d, number %d"), p->name, p->tag, p->number);
      nl ();
      tab (-1);
      tab (1);
      printf (_("Type"));
      nl ();
      dump_coff_type (p->type);
      tab (-1);
      tab (1);
      printf (_("Where"));
      dump_coff_where (p->where);
      tab (-1);
      tab (1);
      printf (_("Visible"));
      dump_coff_visible (p->visible);
      tab (-1);
      p = p->next;
      tab (-1);
    }
  tab (-1);
}

static void
dump_coff_scope (struct coff_scope *p)
{
  if (p)
    {
      tab (1);
      printf ("%s %" BFD_VMA_FMT "x ",
	      _("List of blocks "), (bfd_vma) (uintptr_t) p);

      if (p->sec)
	printf( "  %s %x..%x",  p->sec->name,p->offset, p->offset + p->size -1);

      nl ();
      tab (0);
      printf ("*****************");
      nl ();

      while (p)
	{
	  tab (0);
	  printf (_("vars %d"), p->nvars);
	  nl ();
	  dump_coff_symbol (p->vars_head);
	  printf (_("blocks"));
	  nl ();
	  dump_coff_scope (p->list_head);
	  nl ();
	  p = p->next;
	}

      tab (0);
      printf ("*****************");
      nl ();
      tab (-1);
    }
}

static void
dump_coff_sfile (struct coff_sfile *p)
{
  tab (1);
  printf (_("List of source files"));
  nl ();

  while (p)
    {
      tab (0);
      printf (_("Source file %s"), p->name);
      nl ();
      dump_coff_scope (p->scope);
      p = p->next;
    }
  tab (-1);
}

static void
dump_coff_section (struct coff_section *ptr)
{
  unsigned int i;

  tab (1);
  printf (_("section %s %d %d address %x size %x number %d nrelocs %u"),
	  ptr->name, ptr->code, ptr->data, ptr->address,ptr->size,
	  ptr->number, ptr->nrelocs);
  nl ();

  for (i = 0; i < ptr->nrelocs; i++)
    {
      struct coff_reloc * r = ptr->relocs + i;
      tab (0);
      printf ("(%x %s %x)",
	      r->offset,
	      /* PR 17512: file: 0a38fb7c.  */
	      r->symbol == NULL ? _("<no sym>") : r->symbol->name,
	      r->addend);
      nl ();
    }

  tab (-1);
}

static void
coff_dump (struct coff_ofile *ptr)
{
  int i;

  printf ("Coff dump");
  nl ();
  printf (_("#sources %d"), ptr->nsources);
  nl ();
  dump_coff_sfile (ptr->source_head);

  for (i = 0; i < ptr->nsections; i++)
    dump_coff_section (ptr->sections + i);
}

static void
show_usage (FILE *file, int status)
{
  fprintf (file, _("Usage: %s [option(s)] in-file\n"), program_name);
  fprintf (file, _(" Print a human readable interpretation of a COFF object file\n"));
  fprintf (file, _(" The options are:\n\
  @<file>                Read options from <file>\n\
  -h --help              Display this information\n\
  -v --version           Display the program's version\n\
\n"));

  if (REPORT_BUGS_TO[0] && status == 0)
    fprintf (file, _("Report bugs to %s\n"), REPORT_BUGS_TO);

  exit (status);
}

int
main (int ac, char **av)
{
  bfd *abfd;
  struct coff_ofile *tree;
  char **matching;
  char *input_file = NULL;
  int opt;
  static struct option long_options[] =
    {
      { "help", no_argument, 0, 'h' },
      { "version", no_argument, 0, 'V' },
      { NULL, no_argument, 0, 0 }
    };

#ifdef HAVE_LC_MESSAGES
  setlocale (LC_MESSAGES, "");
#endif
  setlocale (LC_CTYPE, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  program_name = av[0];
  xmalloc_set_program_name (program_name);
  bfd_set_error_program_name (program_name);

  expandargv (&ac, &av);

  while ((opt = getopt_long (ac, av, "HhVv", long_options,
			     (int *) NULL))
	 != EOF)
    {
      switch (opt)
	{
	case 'H':
	case 'h':
	  show_usage (stdout, 0);
	  break;
	case 'v':
	case 'V':
	  print_version ("coffdump");
	  exit (0);
	case 0:
	  break;
	default:
	  show_usage (stderr, 1);
	  break;
	}
    }

  if (optind < ac)
    {
      input_file = av[optind];
    }

  if (!input_file)
    fatal (_("no input file specified"));

  abfd = bfd_openr (input_file, 0);

  if (!abfd)
    bfd_fatal (input_file);

  if (! bfd_check_format_matches (abfd, bfd_object, &matching))
    {
      bfd_nonfatal (input_file);

      if (bfd_get_error () == bfd_error_file_ambiguously_recognized)
	{
	  list_matching_formats (matching);
	  free (matching);
	}
      exit (1);
    }

  tree = coff_grok (abfd);
  if (tree)
    {
      coff_dump (tree);
      printf ("\n");
    }

  return 0;
}
