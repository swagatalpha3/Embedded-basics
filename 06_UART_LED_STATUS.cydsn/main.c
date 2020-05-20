
#include "project.h"
CY_ISR_PROTO(isr_button_Handler);
uint8 button_state;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   
      //  uint8 led_state;
    UART_Start();
   // isr_button_StartEx(isr_button_Handler);
    for(;;)
    {   
        
        button_state= button_Read();
        if (button_state==0){
             led_Write(1);
             UART_PutString("LED ON!!!\n");
             }
        
        else{
             led_Write(0);
             UART_PutString("LED OFF!!!\n");
    
           }
        CyDelay(1000);
    }
    
}
    CY_ISR(isr_button_Handler)
    {   
        button_ClearInterrupt();
        button_state= button_Read();
        if (button_state==0){
             led_Write(1);
             UART_PutString("LED ON!!!\r\n");
             UART_ClearTxBuffer();
             //UART_Stop();
            }
       
        else
            {//UART_Start();
             led_Write(0);
             UART_PutString("LED OFF!!\r\n");
             UART_ClearTxBuffer();
             //UART_Stop();
            }
        
    }


/* [] END OF FILE */
