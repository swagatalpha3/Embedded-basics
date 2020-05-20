
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    uint8 led_state = 0; 

    for(;;)
    {
       uint8 led_state;
       led_state= LED_Read(); 
       if (led_state==0) 
            LED_Write(1);
       else
            LED_Write(0);
       CyDelay(100);
    }
}

/* [] END OF FILE */
