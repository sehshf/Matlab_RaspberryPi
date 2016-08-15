/*
 * gpio.c
 *
 *  Created on: 04/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "portable.h"
#include "gpio.h"

/*
 * **************************************************
 * LOCAL DECLARATIONS								*
 * **************************************************
 */



/*
 * **************************************************
 * GLOBAL VARIABLES (extern)						*
 * **************************************************
 */
bcm2836_peripheral_t gpio = {GPIO_BASE_ADR};



/*
 * **************************************************
 * FILE SCOPE VARIABLES (static)					*
 * **************************************************
 */



/*
 * **************************************************
 * LOCAL PROTOTYPES									*
 * **************************************************
 */



/*
 * **************************************************
 * PUBLIC FUNCTIONS									*
 * **************************************************
 */

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      MAP_PERIPHERAL()
*      Exposes the physical address defined in the passed structure using mmap on /dev/mem.
*
*  Outputs:
*      Return 0 when succeeded.
*
*  Author:
*
*  -------------------------------------------------------  *
*/
uint16_T map_peripheral(bcm2836_peripheral_t *p)
{
	/* Open /dev/mem */
	p->mem_fd = open("/dev/mem", O_RDWR|O_SYNC);

    if (p->mem_fd < 0)
    {
    	printf("Failed to open /dev/mem, try checking permissions.\n");
        return RETURN_FAIL;
    }

    p->pMap = mmap(
    			   NULL,
				   BLOCK_SIZE,
				   PROT_READ|PROT_WRITE,
				   MAP_SHARED,
				   p->mem_fd,        /* File descriptor to physical memory virtual file '/dev/mem'		 */
				   p->adr            /* Address in physical map that we want this memory block to expose */
    			  );

    if (p->pMap == MAP_FAILED)
    {
    	perror("mmap");
        return -1;
    }

    p->pAdr = (volatile uint16_T *)p->pMap;

    return 0;

} /* END: map_peripheral() */


/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      UNMAP_PERIPHERAL()*
*
*  Outputs:*
*
*  Author:
*
*  -------------------------------------------------------  *
*/
void unmap_peripheral(bcm2836_peripheral_t *p)
{
	munmap(p->pMap, BLOCK_SIZE);
    close(p->mem_fd);

} /* END: unmap_peripheral() */


/*
 * **************************************************
 * LOCAL FUNCTIONS									*
 * **************************************************
 */


/* EOF: gpio.c */


uint16_T test_fun(uint8_T x)
{
    uint16_T y;
    y = 2 * x;
    return y;
}
