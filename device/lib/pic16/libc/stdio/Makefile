#
# Makefile - Makefile to build pic16 C Library
#
# This file is part of the GNU PIC Library.
#
# January, 2004
# The GNU PIC Library is maintained by,
# 	Vangelis Rokas <vrokas@otenet.gr>
#
# $Id: Makefile,v 1.3 2005/03/31 16:24:44 vrokas Exp $
#
#

include ../Makefile.rules

SRCS	= 	printf_tiny \
		printf_small \
		printf \
		sprintf \
		fprintf \
		vprintf \
		vsprintf \
		vfprintf \
		strmusart \
		strmmssp \
		strmgpsim \
		strmputchar \
		streams


CFILES	= $(patsubst %,%.c,$(SRCS))
OFILES	= $(patsubst %.c,%.o,$(CFILES))


DEBUG=
#COMPILE_FLAGS   += --pomit-config-words --pomit-ivt --no-peep
COMPILE_FLAGS	+= $(DEBUG)

CFILES	= $(patsubst %,%.c,$(SRCS))
OFILES	= $(patsubst %.c,%.o,$(CFILES))

%.o: %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $<

build-library: $(OFILES)

