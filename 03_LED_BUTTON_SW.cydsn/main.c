
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   
        uint8 led_state;
        
    for(;;)
    {
        uint8 button_state;
        button_state= button_Read();
        if (button_state==0)
             led_Write(1);
        else
             led_Write(0);
        
    }
}

/* [] END OF FILE */
