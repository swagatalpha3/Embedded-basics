/*******************************************************************************
* File Name: ADC_out_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_out.h"


/***************************************
* Local data allocation
***************************************/

static ADC_out_BACKUP_STRUCT  ADC_out_backup =
{
    ADC_out_DISABLED
};


/*******************************************************************************
* Function Name: ADC_out_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_out_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_out_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_out_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_out_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_out_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_out_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_out_Sleep(void)
{
    if((ADC_out_PWRMGR_SAR_REG  & ADC_out_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_out_SAR_CSR0_REG & ADC_out_SAR_SOF_START_CONV) != 0u)
        {
            ADC_out_backup.enableState = ADC_out_ENABLED | ADC_out_STARTED;
        }
        else
        {
            ADC_out_backup.enableState = ADC_out_ENABLED;
        }
        ADC_out_Stop();
    }
    else
    {
        ADC_out_backup.enableState = ADC_out_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_out_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_out_Sleep() was called. If the component was enabled before the
*  ADC_out_Sleep() function was called, the
*  ADC_out_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_out_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_out_Wakeup(void)
{
    if(ADC_out_backup.enableState != ADC_out_DISABLED)
    {
        ADC_out_Enable();
        #if(ADC_out_DEFAULT_CONV_MODE != ADC_out__HARDWARE_TRIGGER)
            if((ADC_out_backup.enableState & ADC_out_STARTED) != 0u)
            {
                ADC_out_StartConvert();
            }
        #endif /* End ADC_out_DEFAULT_CONV_MODE != ADC_out__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
