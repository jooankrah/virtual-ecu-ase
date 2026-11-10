/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.h
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

#ifndef SIU_H_
#define SIU_H_

// PCR NUMBER DEFINITIONS
#define PCR_6 6
#defibe PCR_32 32
#define PCR_43 43
#define PCR_52 52
#define PCR_53 53
#define PCR_54 54
#define PCR_55 55
#define PCR_56 56
#define PCR_57 57
#define PCR_58 58
#define PCR_59 59
#define PCR_60 60
#define PCR_62 62
#define PCR_66 66

// INPUT PIN DEFINITIONS
#define SWITCH_1 PCR_52
#define SWITCH_2 PCR_53
#define SWITCH_3 PCR_54
#define SWITCH_4 PCR_55

#define BUTTON_1 PCR_60
#define BUTTON_2 PCR_62


// OUTPUT PIN DEFINITIONS
#define LED_RED PCR_56
#define LED_RX PCR_57
#define LED_TX PCR_58
#define LED_U3 PCR_6
#define LED_U2 PCR_43
#define LED_U1 PCR_59

// ANALOG PIN DEFINITION
#define POTENTIOMETER PCR_66
#define LDR PCR_32


/* Function prototypes *******************************************************/
void SIU_Init(void);

#endif /* SIU_H_ */
