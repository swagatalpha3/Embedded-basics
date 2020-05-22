
#include "project.h"
#include<stdio.h>
CY_ISR_PROTO(isr_button_Handler);
uint8 button_state;
uint8 out_array[3];
uint8 count = 0;

// function to convert decimal to binary 
uint8* decToBinary(uint8 n) 
{ 
    // array to store binary number //not required in case of global variable
    //uint8 binaryNum[3]; 
    // counter for binary array 
    uint8 i = 0; 
    while (n > 0) { 
        // storing remainder in binary array 
        out_array[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    return out_array;
}
// Function for counter
uint8 counter(uint8 size,uint8 variable)
{
     if (variable == size-1)
        variable = 0;
     else
        variable +=1;
    return variable;

}
    
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
      //  uint8 led_state;
    UART_Start();
    isr_button_StartEx(isr_button_Handler);
   // isr_button_StartEx(isr_button_Handler);
    for(;;)
    {   
        char storage[10];
        button_state= button_Read();
        if (button_state==0){
             decToBinary(count);
             led_red_Write(out_array[0]);
             led_green_Write(out_array[1]);
             led_blue_Write(out_array[2]);
             sprintf(storage, "+%d\n", count);
             UART_PutString(storage); 
             UART_ClearTxBuffer();
             //UART_Stop();
            }
       
        else
            {
             UART_PutString(storage);
             UART_ClearTxBuffer();
            }
        CyDelay(500);
        
        /*button_state= button_Read();
        if (button_state==0){
             led_Write(1);
             UART_PutString("LED ON!!!\n");
             }
        
        else{
             led_Write(0);
             UART_PutString("LED OFF!!!\n");
    
           }
        CyDelay(1000);*/
    }
    
}
    CY_ISR(isr_button_Handler)
    {   
        //button_ClearInterrupt(); //no need in case of a debouncer
        count=counter(7,count);
    }


/* [] END OF FILE */
