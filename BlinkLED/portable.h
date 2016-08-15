/*
 * portable.h
 *
 *  Created on: 01/08/2016
 *      Author: ses
 */

#ifndef _PORTABLE_H_
#define _PORTABLE_H_

/*
 * **************************************************
 * DECLARATION										*
 * **************************************************
 */
typedef enum {FALSE, TRUE}  boolean_T;
typedef unsigned char 		uint8_T;
typedef unsigned int 		uint16_T;
typedef unsigned long int 	uint32_T;
typedef signed char 		int8_T;
typedef signed int 			int16_T;
typedef signed long int 	int32_T;

/*
 * **************************************************
 * DEFINITION										*
 * **************************************************
 */
#define BIT0            0x0001
#define BIT1            0x0002
#define BIT2            0x0004
#define BIT3            0x0008
#define BIT4            0x0010
#define BIT5            0x0020
#define BIT6            0x0040
#define BIT7            0x0080
#define BIT8            0x0100
#define BIT9            0x0200
#define BIT10           0x0400
#define BIT11           0x0800
#define BIT12           0x1000
#define BIT13           0x2000
#define BIT14           0x4000
#define BIT15           0x8000
#define BIT16           0x00010000
#define BIT17           0x00020000
#define BIT18           0x00040000
#define BIT19           0x00080000
#define BIT20           0x00100000
#define BIT21           0x00200000
#define BIT22           0x00400000
#define BIT23           0x00800000
#define BIT24           0x01000000
#define BIT25           0x02000000
#define BIT26           0x04000000
#define BIT27           0x08000000
#define BIT28           0x10000000
#define BIT29           0x20000000
#define BIT30           0x40000000
#define BIT31           0x80000000

#define RETURN_FAIL		-1

/*
 * **************************************************
 * MACRO											*
 * **************************************************
 */
#define min(a, b)		(((a) < (b)) ? (a) : (b))
#define max(a, b)		(((a) > (b)) ? (a) : (b))

#define BITSET(a, bit)	((a) |=  (bit))
#define BITCLR(a, bit)	((a) &= ~(bit))

#define NUM_ELEM(array) (sizeof(array) / sizeof(*(array)))


#endif /* _PORTABLE_H_ */
/* EOF: portable.h */
