/*******************************************************************************
* File Name: capacitor.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_capacitor_H) /* Pins capacitor_H */
#define CY_PINS_capacitor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "capacitor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 capacitor__PORT == 15 && ((capacitor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    capacitor_Write(uint8 value);
void    capacitor_SetDriveMode(uint8 mode);
uint8   capacitor_ReadDataReg(void);
uint8   capacitor_Read(void);
void    capacitor_SetInterruptMode(uint16 position, uint16 mode);
uint8   capacitor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the capacitor_SetDriveMode() function.
     *  @{
     */
        #define capacitor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define capacitor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define capacitor_DM_RES_UP          PIN_DM_RES_UP
        #define capacitor_DM_RES_DWN         PIN_DM_RES_DWN
        #define capacitor_DM_OD_LO           PIN_DM_OD_LO
        #define capacitor_DM_OD_HI           PIN_DM_OD_HI
        #define capacitor_DM_STRONG          PIN_DM_STRONG
        #define capacitor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define capacitor_MASK               capacitor__MASK
#define capacitor_SHIFT              capacitor__SHIFT
#define capacitor_WIDTH              1u

/* Interrupt constants */
#if defined(capacitor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in capacitor_SetInterruptMode() function.
     *  @{
     */
        #define capacitor_INTR_NONE      (uint16)(0x0000u)
        #define capacitor_INTR_RISING    (uint16)(0x0001u)
        #define capacitor_INTR_FALLING   (uint16)(0x0002u)
        #define capacitor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define capacitor_INTR_MASK      (0x01u) 
#endif /* (capacitor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define capacitor_PS                     (* (reg8 *) capacitor__PS)
/* Data Register */
#define capacitor_DR                     (* (reg8 *) capacitor__DR)
/* Port Number */
#define capacitor_PRT_NUM                (* (reg8 *) capacitor__PRT) 
/* Connect to Analog Globals */                                                  
#define capacitor_AG                     (* (reg8 *) capacitor__AG)                       
/* Analog MUX bux enable */
#define capacitor_AMUX                   (* (reg8 *) capacitor__AMUX) 
/* Bidirectional Enable */                                                        
#define capacitor_BIE                    (* (reg8 *) capacitor__BIE)
/* Bit-mask for Aliased Register Access */
#define capacitor_BIT_MASK               (* (reg8 *) capacitor__BIT_MASK)
/* Bypass Enable */
#define capacitor_BYP                    (* (reg8 *) capacitor__BYP)
/* Port wide control signals */                                                   
#define capacitor_CTL                    (* (reg8 *) capacitor__CTL)
/* Drive Modes */
#define capacitor_DM0                    (* (reg8 *) capacitor__DM0) 
#define capacitor_DM1                    (* (reg8 *) capacitor__DM1)
#define capacitor_DM2                    (* (reg8 *) capacitor__DM2) 
/* Input Buffer Disable Override */
#define capacitor_INP_DIS                (* (reg8 *) capacitor__INP_DIS)
/* LCD Common or Segment Drive */
#define capacitor_LCD_COM_SEG            (* (reg8 *) capacitor__LCD_COM_SEG)
/* Enable Segment LCD */
#define capacitor_LCD_EN                 (* (reg8 *) capacitor__LCD_EN)
/* Slew Rate Control */
#define capacitor_SLW                    (* (reg8 *) capacitor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define capacitor_PRTDSI__CAPS_SEL       (* (reg8 *) capacitor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define capacitor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) capacitor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define capacitor_PRTDSI__OE_SEL0        (* (reg8 *) capacitor__PRTDSI__OE_SEL0) 
#define capacitor_PRTDSI__OE_SEL1        (* (reg8 *) capacitor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define capacitor_PRTDSI__OUT_SEL0       (* (reg8 *) capacitor__PRTDSI__OUT_SEL0) 
#define capacitor_PRTDSI__OUT_SEL1       (* (reg8 *) capacitor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define capacitor_PRTDSI__SYNC_OUT       (* (reg8 *) capacitor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(capacitor__SIO_CFG)
    #define capacitor_SIO_HYST_EN        (* (reg8 *) capacitor__SIO_HYST_EN)
    #define capacitor_SIO_REG_HIFREQ     (* (reg8 *) capacitor__SIO_REG_HIFREQ)
    #define capacitor_SIO_CFG            (* (reg8 *) capacitor__SIO_CFG)
    #define capacitor_SIO_DIFF           (* (reg8 *) capacitor__SIO_DIFF)
#endif /* (capacitor__SIO_CFG) */

/* Interrupt Registers */
#if defined(capacitor__INTSTAT)
    #define capacitor_INTSTAT            (* (reg8 *) capacitor__INTSTAT)
    #define capacitor_SNAP               (* (reg8 *) capacitor__SNAP)
    
	#define capacitor_0_INTTYPE_REG 		(* (reg8 *) capacitor__0__INTTYPE)
#endif /* (capacitor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_capacitor_H */


/* [] END OF FILE */
