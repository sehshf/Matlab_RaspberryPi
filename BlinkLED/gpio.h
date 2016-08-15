/*
 * gpio.h
 *
 *  Created on: 04/08/2016
 *      Author: ses
 */

#ifndef _GPIO_H_
#define _GPIO_H_

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */
#include <stdio.h>
#include <fcntl.h>
#include "mman.h"
/*#include <sys/mman.h>
*/
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */



/*
 * **************************************************
 * SYSTEM DEFINITIONS               				*
 * **************************************************
 */
#ifndef O_DSYNC
#define O_DSYNC		00010000	/* used to be O_SYNC, see below */
#endif

#ifndef O_SYNC
#define __O_SYNC	04000000
#define O_SYNC		(__O_SYNC|O_DSYNC)
#endif

/*
 * **************************************************
 * DEFINITIONS										*
 * **************************************************
 */
#define BCM2836_PERI_BASE_ADR    0x3F000000    						   /* Peripheral starting address	*/
#define GPIO_BASE_ADR            (BCM2836_PERI_BASE_ADR + 0x200000)    /* GPIO starting address			*/
#define BLOCK_SIZE 				 (4 * 1024)							   /* Block size for memory map     */


/*
 * **************************************************
 * MACROS											*
 * **************************************************
 */
/* GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) */
#define INP_GPIO(x)         *(gpio.pAdr + ((x) / 10)) &= ~(7 << (((x) % 10) * 3))
#define OUT_GPIO(x)   	    *(gpio.pAdr + ((x) / 10)) |=  (1 << (((x) % 10) * 3))

#define SET_GPIO_ALT(x,a)	*(gpio.pAdr + ((x) / 10)) |=  (((a) <= 3 ? (a) + 4 : (a) == 4 ? 3 : 2) << (((x) % 10) * 3))

#define SET_GPIO  			*(gpio.pAdr + 7 )  	 /* sets   bits which are 1 ignores bits which are 0 */
#define CLR_GPIO  			*(gpio.pAdr + 10)    /* clears bits which are 1 ignores bits which are 0 */

#define READ_GPIO(x)  		*(gpio.pAdr + 13) &= (1 << (x))


/*
 * **************************************************
 * TYPE DEFINITIONS									*
 * **************************************************
 */
/* IO Access */
typedef struct
{
	uint32_T    adr;
    int16_T     mem_fd;
    void 	  * pMap;
    volatile uint16_T * pAdr;
}bcm2836_peripheral_t;



/*
 * **************************************************
 * GLOBAL VARIABLES (storage allocation)			*
 * **************************************************
 */


/*
 * **************************************************
 * GLOBAL VARIABLES (extern)						*
 * **************************************************
 */
extern bcm2836_peripheral_t gpio;



/*
 * **************************************************
 * PROTOTYPES										*
 * **************************************************
 */
uint16_T map_peripheral  (bcm2836_peripheral_t *p);
void 	 unmap_peripheral(bcm2836_peripheral_t *p);


uint16_T test_fun(uint8_T x);

#endif /* _GPIO_H_ */
/* EOF: gpio.h */
