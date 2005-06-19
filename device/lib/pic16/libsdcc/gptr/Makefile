#
# Makefile - Makefile to build pic16 generic pointer support library
#
# This file is part of the GNU PIC Library.
#
# January, 2004
# The GNU PIC Library is maintained by,
# 	Vangelis Rokas <vrokas@otenet.gr>
#
# $Id: Makefile,v 1.2 2004/10/10 20:45:18 vrokas Exp $
#
#


SRCS	=	gptrget1 \
		gptrget2 \
		gptrget3 \
		gptrget4 \
		gptrput1 \
		gptrput2 \
		gptrput3 \
		gptrput4


include ../Makefile.rules

#OFILES	+= gptrcommon.o


all: build-library

#gptrcommon.o: gptrcommon.S
#	$(AS) -c $< -o $@

build-library: $(OFILES)
#	@$(CP) -v $(OFILES) ../../bin
