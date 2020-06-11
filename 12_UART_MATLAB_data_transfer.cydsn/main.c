#include "project.h"
#include<stdio.h>
char buffer[5];
uint8_t tx_buffer[256];
uint8_t buffer_index = 0;// software buffer

// Interrupt function to be activcated ever time a Byte is received
void ISR_UART_Rx(void){
    if (buffer_index <= 5){
    buffer[buffer_index] = UART_GetByte();
    buffer_index++;
    }
}

// Triangular wave generator ,load data to tx_buffer
int triangle_wave(){ 
      int x = 127;
      for (int i= 0 ; i<=255;i++){
          if (i <= 128) {
           tx_buffer[i] = i;
           }
          if (i>128){
           tx_buffer[i] = x;
           x--;
          }
      }
         
    return 0;
    }

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    // Interrupt function to be activcated ever time a Byte is received
    ISR_UART_Rx_StartEx(ISR_UART_Rx);
    for(;;)
       { 
        // transmit the data only when data is received
        if((buffer_index >0)&& (buffer[buffer_index-1] == 's')){
            triangle_wave();
            //for(int i = 0;i<=255;i++){ // no for loop needed if we increase the size of the tx buffer in ssetting
            UART_PutArray(tx_buffer,256 * sizeof(uint8_t));//<-----------------------------sending data
            // }
                
            buffer_index = 0;
            }
        //optional else block to transmit data after the delay when ever.. 
                                                  // .. the buffer is empty 
        else{
               //UART_PutString("No Data \n");
            }
        //some other process the processor can do when idle
        CyDelay(1000);
       }
       
}
       

/* [] END OF FILE */
