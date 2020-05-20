/*******************************************************************************
* File Name: CAP_OUT.h  
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

#if !defined(CY_PINS_CAP_OUT_H) /* Pins CAP_OUT_H */
#define CY_PINS_CAP_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAP_OUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAP_OUT__PORT == 15 && ((CAP_OUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CAP_OUT_Write(uint8 value);
void    CAP_OUT_SetDriveMode(uint8 mode);
uint8   CAP_OUT_ReadDataReg(void);
uint8   CAP_OUT_Read(void);
void    CAP_OUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   CAP_OUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CAP_OUT_SetDriveMode() function.
     *  @{
     */
        #define CAP_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CAP_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CAP_OUT_DM_RES_UP          PIN_DM_RES_UP
        #define CAP_OUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define CAP_OUT_DM_OD_LO           PIN_DM_OD_LO
        #define CAP_OUT_DM_OD_HI           PIN_DM_OD_HI
        #define CAP_OUT_DM_STRONG          PIN_DM_STRONG
        #define CAP_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CAP_OUT_MASK               CAP_OUT__MASK
#define CAP_OUT_SHIFT              CAP_OUT__SHIFT
#define CAP_OUT_WIDTH              1u

/* Interrupt constants */
#if defined(CAP_OUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CAP_OUT_SetInterruptMode() function.
     *  @{
     */
        #define CAP_OUT_INTR_NONE      (uint16)(0x0000u)
        #define CAP_OUT_INTR_RISING    (uint16)(0x0001u)
        #define CAP_OUT_INTR_FALLING   (uint16)(0x0002u)
        #define CAP_OUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CAP_OUT_INTR_MASK      (0x01u) 
#endif /* (CAP_OUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAP_OUT_PS                     (* (reg8 *) CAP_OUT__PS)
/* Data Register */
#define CAP_OUT_DR                     (* (reg8 *) CAP_OUT__DR)
/* Port Number */
#define CAP_OUT_PRT_NUM                (* (reg8 *) CAP_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define CAP_OUT_AG                     (* (reg8 *) CAP_OUT__AG)                       
/* Analog MUX bux enable */
#define CAP_OUT_AMUX                   (* (reg8 *) CAP_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define CAP_OUT_BIE                    (* (reg8 *) CAP_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define CAP_OUT_BIT_MASK               (* (reg8 *) CAP_OUT__BIT_MASK)
/* Bypass Enable */
#define CAP_OUT_BYP                    (* (reg8 *) CAP_OUT__BYP)
/* Port wide control signals */                                                   
#define CAP_OUT_CTL                    (* (reg8 *) CAP_OUT__CTL)
/* Drive Modes */
#define CAP_OUT_DM0                    (* (reg8 *) CAP_OUT__DM0) 
#define CAP_OUT_DM1                    (* (reg8 *) CAP_OUT__DM1)
#define CAP_OUT_DM2                    (* (reg8 *) CAP_OUT__DM2) 
/* Input Buffer Disable Override */
#define CAP_OUT_INP_DIS                (* (reg8 *) CAP_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define CAP_OUT_LCD_COM_SEG            (* (reg8 *) CAP_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAP_OUT_LCD_EN                 (* (reg8 *) CAP_OUT__LCD_EN)
/* Slew Rate Control */
#define CAP_OUT_SLW                    (* (reg8 *) CAP_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAP_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) CAP_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAP_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAP_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAP_OUT_PRTDSI__OE_SEL0        (* (reg8 *) CAP_OUT__PRTDSI__OE_SEL0) 
#define CAP_OUT_PRTDSI__OE_SEL1        (* (reg8 *) CAP_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAP_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) CAP_OUT__PRTDSI__OUT_SEL0) 
#define CAP_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) CAP_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAP_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) CAP_OUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CAP_OUT__SIO_CFG)
    #define CAP_OUT_SIO_HYST_EN        (* (reg8 *) CAP_OUT__SIO_HYST_EN)
    #define CAP_OUT_SIO_REG_HIFREQ     (* (reg8 *) CAP_OUT__SIO_REG_HIFREQ)
    #define CAP_OUT_SIO_CFG            (* (reg8 *) CAP_OUT__SIO_CFG)
    #define CAP_OUT_SIO_DIFF           (* (reg8 *) CAP_OUT__SIO_DIFF)
#endif /* (CAP_OUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(CAP_OUT__INTSTAT)
    #define CAP_OUT_INTSTAT            (* (reg8 *) CAP_OUT__INTSTAT)
    #define CAP_OUT_SNAP               (* (reg8 *) CAP_OUT__SNAP)
    
	#define CAP_OUT_0_INTTYPE_REG 		(* (reg8 *) CAP_OUT__0__INTTYPE)
#endif /* (CAP_OUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAP_OUT_H */


/* [] END OF FILE */
