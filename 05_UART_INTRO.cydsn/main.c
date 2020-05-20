/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    

    for(;;)
    {
        UART_Start();
        UART_PutString("Hello World\n");
        CyDelay(2000);
        UART_ClearTxBuffer();
    }
}

/* [] END OF FILE */
