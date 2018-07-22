/*
 * PIC16 port features.
 *
 * This file is part of the GNU PIC Library.
 *
 * January, 2004
 * The GNU PIC Library is maintained by,
 * 	Vangelis Rokas <vrokas@otenet.gr>
 *
 * $Id: features.h,v 1.4 2005/04/02 13:13:48 vrokas Exp $
 *
 */
#ifndef __PIC16_ASM_FEATURES_H
#define __PIC16_ASM_FEATURES_H   1

#define _REENTRANT

#define _IL_REENTRANT
#define _FS_REENTRANT
#define _MATH_REENTRANT

#define _CODE	__code
#define _DATA	__data
#define _AUTOMEM
#define _STATMEM

#endif	/* __PIC16_ASM_FEATURES_H */
