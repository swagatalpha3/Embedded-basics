
#include "project.h"
#include<stdio.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start();
    ADC_StartConvert();
    PWM_Start();
    uint8 ADC_result;
    for(;;)
    {  
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        ADC_result=ADC_GetResult8(); 
        PWM_WritePeriod(ADC_result);
    }
}

/* [] END OF FILE */
