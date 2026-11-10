/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "siu.h"
#include "xpc56el.h"

/*
 * @brief	SIU pin configuration function
 *
 * @param	void
 * @retval	void
 */
void SIU_Init(void)
{
	// Configure all pins which are required for your task here

	/* TO-DO: your task implementations **************************************/


	/* Input pin configurations */

	// SWITCHES
	SIU.PCR[52].R = 0x100; // Switch 1 (PCR 52) - Input
	SIU.PCR[53].R = 0x100; // Switch 2 (PCR 53) - Input
	SIU.PCR[54].R = 0x100; // Switch 3 (PCR 54) - Input
	SIU.PCR[55].R = 0x100; // Switch 4 (PCR 55) - Input

	// BUTTONS
	SIU.PCR[60].R = 0x0100; // Button 1 (PCR 60) - Input
	SIU.PCR[62].R = 0x0100; // Button 2 (PCR 62) - Input


	/* Output pin configurations */

	// LEDS
	SIU.PCR[56].R = 0x200; // P (Red) (PCR 56) - Output
	SIU.PCR[57].R = 0x200; // Rx (Yellow) (PCR 57) - Output
	SIU.PCR[58].R = 0x200; // Tx (Yellow) (PCR 58) - Output
	SIU.PCR[6].R = 0x200; // U3 (Green) (PCR 6) - Output
	SIU.PCR[43].R = 0x200; // U2 (Green) (PCR 43) - Output
	SIU.PCR[59].R = 0x200; // U1 (Green) (PCR 59) - Output




	/* Analog pin configurations */

	// POTENTIOMETER
	SIU.PCR[66].R = 0x2500; // Potentiometer

	// LDR
	SIU.PCR[32].R = 0x2500; // LDR
	/*************************************************************************/
}
