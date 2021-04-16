#include <stdint.h>
#include "board.h"


void BoardInit( void )
{

    /* Setup SysTick Timer for 1 us interrupts ( not too often to save power ) */
    if( SysTick_Config( SystemCoreClock / 1000 ) )
    {
        /* Capture error */
        while (1);
    }
}

