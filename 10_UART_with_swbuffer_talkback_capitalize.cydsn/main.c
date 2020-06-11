
#include "project.h"
#include<stdio.h>
char buffer[100];
uint8_t buffer_index = 0;// software buffer

// Interrupt function to be activcated ever time a Byte is received
void ISR_UART_Rx(void){
    if (buffer_index < 100){
    buffer[buffer_index] = UART_GetByte();
    buffer_index++;
    }
}

// upper to lower case conversion
char* lower_to_upper(char* string,int current_index){
      for (int i= 0 ; ((string[i] !='\0') && (i<= current_index));i++)
           { 
        if (string[i]>=97 && string[i]<=122)
               string[i] = (string[i] - ('a' - 'A')) ;
           
        else{
                string[i] = string[i];
        }
        }
    return string;
    }


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    
    // Interrupt function to be activcated ever time a Byte is received
    ISR_UART_Rx_StartEx(ISR_UART_Rx);
    
    for(;;){ 
        
        // transmit the data only when data is received
        if(buffer_index >0){
            for(int i = 0;i<buffer_index;i++){
                UART_PutChar(buffer[i]);//<------------------------------------ original data
            }
            
            UART_PutChar('\n');
            UART_PutString(lower_to_upper(buffer,buffer_index));//<-------- converted data
            UART_PutChar('\n');
            // RESETING/Emptying buffer to null after transmission of data
            for(int i = 0;i<buffer_index;i++){
                buffer[i] ='\0';}
            //Reseting buffer index to 0
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
