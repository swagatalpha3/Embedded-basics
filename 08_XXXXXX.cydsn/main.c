
#include "project.h"
CY_ISR_PROTO(isr_Handler);
char buffer;
//uint8 button_state;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   
      //  uint8 led_state;
    UART_Start();
    isr_StartEx(isr_Handler);
    //UART_EnableRxInt();
    //UART_SetRxInterruptMode(UART_RX_STS_FIFO_NOTEMPTY);
    for(;;)
    {   
        
        /*button_state= button_Read();
        if (UART_GetChar()=='0'){
             led_red_Write(1);
             led_green_Write(0);
             led_blue_Write(0);
             UART_PutString("LED RED ON!!!\n");
             }
        
        else if(UART_GetChar()=='1')
           {
             led_red_Write(0);
             led_green_Write(1);
             led_blue_Write(0);
             UART_PutString("LED GREEN ON!!!\n");
            }
        else if(UART_GetChar()=='2')
           {
             led_red_Write(0);
             led_green_Write(0);
             led_blue_Write(1);
             UART_PutString("LED BLUE ON!!!\n");*/
            }
        }
       // CyDelay(1000);
    
    

    CY_ISR(isr_Handler) {  
        buffer = UART_GetChar();
        //rx_interrupt_ClearInterrupt();
        if (buffer=='0'){
            for(;;){
             led_red_Write(0);
             led_green_Write(0);
             led_blue_Write(0);
            // UART_PutString("LED RED ON!!!\n");
             }
        }
        else if(buffer=='1')
          for(;;)
        { {
             led_red_Write(0);
             led_green_Write(1);
             led_green_Write(0);
             CyDelay(1000);
             led_green_Write(1);
             led_green_Write(0);
             led_green_Write(0);
             CyDelay(1000);
             led_blue_Write(0);
             led_green_Write(0);
             led_green_Write(1);
            // UART_PutString("LED GREEN ON!!!\n");
            }}
        else if(buffer=='2')
           {
             led_red_Write(0);
             led_green_Write(0);
             led_blue_Write(1);
             //UART_PutString("LED BLUE ON!!!\n");
            }
        }
        
 


/* [] END OF FILE */
