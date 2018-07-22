#
# Makefile - Makefile to build pic16 int upport library
#
# This file is part of the GNU PIC Library.
#
# January, 2004
# The GNU PIC Library is maintained by,
# 	Vangelis Rokas <vrokas@otenet.gr>
#
# $Id: Makefile,v 1.1 2004/06/04 22:44:08 vrokas Exp $
#
#


LIB	= sdccint.lib

SRCS	=	divsint	\
		divuint	\
		modsint	\
		moduint	\
		mulint

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
		echo adding $$object ; \
	done ;
