
#include "project.h"
#include<stdio.h>
#include<string.h>

/*void getMinMaxFromArray(uint8* array, uint16 arrSize, uint8 min, uint8 max)
{
    min=max=array[0];
    for (uint16 i;i<arrSize;i++)
    {
       if(array[i] < min)
        {
            min = array[i];
        }
        
        if(array[i] > max)
        {
            max = array[i];
        }
            
        
    }
}*/

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start();
    ADC_out_Start();
    
    ADC_StartConvert();
    ADC_out_StartConvert();
   
    PWM_Start();
    //uint8 ADC_result;
    uint8 pwm_cmp_val=130;
    uint8 ADC_out_result;
    UART_Start();
    char storage[1000];
    uint8 my_arr[1000];
    uint8 my_newarr[1000];
    uint16 count =0;
    uint16 count2 =0;
    uint16 sum=0;
    float avg=0;
   
    for(;;)
    {  
        //ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        //ADC_result=ADC_GetResult8(); 
        
        //ADC_out_IsEndConversion(ADC_out_WAIT_FOR_RESULT);
        //ADC_out_result=ADC_out_GetResult8(); 
        //PWM_WriteCompare(130);
        //sprintf(storage, "%d\n", ADC_out_result);
        //UART_PutString(storage);
        //CyDelay(10);
      while (count <=999)
         {  ADC_out_IsEndConversion(ADC_out_WAIT_FOR_RESULT);
            ADC_out_result=ADC_out_GetResult8();
            PWM_WritePeriod(210);
            PWM_WriteCompare(pwm_cmp_val);
            my_arr[count]=ADC_out_result;
            count++;
            CyDelay(1);
         }
      /* if (count == 1000)
        { for(uint16 i=0 ;i<=999;i++)
         {
          sprintf(storage, "%d\n", my_arr[i]);
          UART_PutString(storage);
          CyDelay(10);
         }}*/
       if (count == 1000)
        {
        for(uint16 i=50 ;i<=999;i++)
          { 
            //uint8 my_arr[1000];
            uint8  min;
            uint8 max;
            min=max=my_arr[50];
            for (uint16 k=50;k<970;k++)
             {
                 if(my_arr[k] < min)
                 { if (min != 0)
                      min = my_arr[k];
                 }
        
                 if(my_arr[k] > max)
                 {
                      max = my_arr[k];
                 }
            }
               /* sprintf(storage, "%d\n",min);
                UART_PutString(storage); 
                CyDelay(100);
                for(;;);*/
            
            if ((my_arr[i] >= min) && (my_arr[i] <=min+3)) 
             {
               my_newarr[count2]=my_arr[i];
               count2++;
               i++;
              while (my_arr[i]>= my_newarr[count2-1])
                { my_newarr[count2]=my_arr[i];
                  count2++;
                  i++;
                }
              while (my_arr[i]<= my_newarr[count2-1])                                    
                {
                  my_newarr[count2]=my_arr[i];
                  count2++;
                  i++;
                }
               for(uint j=0 ; j<=count2-1 ; j++)
                    { 
                      sum+=my_newarr[j];
                    
                     avg=(sum/count2);
                     avg=(avg*5*1000)/255;
                     
                      //avg=(int)avg;
                    }
                     //sprintf(storage, "%d mV\n",(int)avg);
                    // UART_PutString(storage); 
                    // CyDelay(1);
                     count=0;
                     count2=0;
                     sum=0;
                    // control loop 
                    if((avg>=2700)&&(avg<=2900))
                    { sprintf(storage, "=%d\n",(int)avg);
                      UART_PutString(storage); 
      
                     }
                    if((avg<2700))
                    { PWM_WriteCompare(pwm_cmp_val++);
                      sprintf(storage, "+%d\n",(int)avg);
                      UART_PutString(storage); 
                    
                      }
                    if ((avg>2900))
                    { PWM_WriteCompare(pwm_cmp_val--);
                      sprintf(storage, "-%d\n",(int)avg);
                      UART_PutString(storage); 
                      
                    }
                    
                    avg=0;
                    CyDelay(10);
                      break;
                    
                //for(;;);
              
                     }
               //break; 
             }
      }
       
    }



}

/* [] END OF FILE */
