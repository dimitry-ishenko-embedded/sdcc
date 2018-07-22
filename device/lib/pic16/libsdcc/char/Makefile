#
# Makefile - Makefile to build pic16 char support library
#
# This file is part of the GNU PIC Library.
#
# January, 2004
# The GNU PIC Library is maintained by,
# 	Vangelis Rokas <vrokas@otenet.gr>
#
# $Id: Makefile,v 1.2 2005/03/31 16:25:03 vrokas Exp $
#
#


LIB	= sdccchar.lib

SRCS	=	divschar \
		divuchar \
		modschar \
		moduchar

#SRCS	=	

#		modschar \
#		moduchar

#AS_SRCS	=	divchar \
#		modchar


include ../Makefile.rules


all: build-library

build-library: $(LIB)

$(LIB): $(OFILES)
	@echo Creating $(LIB) ...
	@for object in $(OFILES) ; do \
		if [ ! -e $(LIB) ]; then \
			$(AR) -c $(LIB) $$object ; \
		else \
			$(AR) -r $(LIB) $$object ; \
		fi; \
		echo -n "$$object " ; \
	done ;
	@echo
	