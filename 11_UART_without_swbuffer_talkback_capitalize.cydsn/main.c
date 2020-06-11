
#include "project.h"
#include<stdio.h>
char buffer[100];
uint8_t buffer_index = 0;// software buffer
uint8 bytes_received ;
uint8  bytes_remaining;


// upper to lower case conversion
char* lower_to_upper(char* string){
      for (int i= 0 ; ((string[i] !='\0'));i++)
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
    
    for(;;){
        // data receive pipeline
        bytes_received =bytes_remaining = UART_GetRxBufferSize(); // number of bytes received
        while ((buffer_index <= bytes_received) && (bytes_remaining !=0)){
            buffer[buffer_index] = UART_GetByte(); 
            while (buffer[buffer_index] == '\0')  // make sure the data is received and copied to the sw buffer
                buffer[buffer_index] = UART_GetByte(); // or else try unil the data is copied to buffer
            buffer_index +=1;
            bytes_remaining = UART_GetRxBufferSize();  // check how much data is remaining in the UART buffer
            
            }
        // data transfer only when data received
        if (bytes_received != 0){
            UART_PutChar('\n');
            UART_PutString(buffer);
            UART_PutChar('\n');
            //sprintf(buffer, "\n");
            UART_PutString(lower_to_upper(buffer));
            // RESETING/Emptying buffer to null after transmission of data
            for(int i = 0;i<buffer_index;i++){
                buffer[i] ='\0';}
                //Reseting buffer index to 0
                buffer_index = 0;
        
            }  
        //when no data received do something else
        CyDelay(10);
       }
       
}
       

/* [] END OF FILE */
