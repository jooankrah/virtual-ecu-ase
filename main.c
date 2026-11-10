/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-1
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "init.h"

#include "xpc56el.h"
#include "siu.h"



/* Global variables **********************************************************/
// put any global variables you need here
volatile int counter_value = 0; /* Range: 0 to 7 \*/ 
volatile int count_direction = 1; /* 1 = UP, -1 = DOWN \*/


/* Task-1 implementation *****************************************************/
void task_pot(int x){

	/* TO-DO: your task implementations **************************************/

	SIU.GPDO[56].R = (x >= 0) ? 1 : 0; // P (Red) 
	SIU.GPDO[57].R = (x >= 682) ? 1 : 0; // Rx (Yellow) 
	SIU.GPDO[58].R = (x >= 1364) ? 1 : 0; // Tx (Yellow) 
	SIU.GPDO[6].R = (x >= 2046) ? 1 : 0; // U3 (Green) 
	SIU.GPDO[43].R = (x >= 2728) ? 1 : 0; // U2 (Green) 
	SIU.GPDO[59].R = (x >= 3410) ? 1 : 0; // U1 (Green) 

	/*************************************************************************/

}

/* Task-2 implementation *****************************************************/
void task_ldr(int x){

	/* TO-DO: your task implementations **************************************/
	
	task_pot(x);

	/*************************************************************************/

}

/* Task-3 implementation *****************************************************/
void task_counter(void){

	/* TO-DO: your task implementations **************************************/

	/* Bitwise extraction: Bit 0 -> U3, Bit 1 -> U2, Bit 2 -> U1 \*/ 
	SIU.GPDO[6].R = (counter_value >> 0) & 1; /* U3 (LSB) */ 
	SIU.GPDO[43].R = (counter_value >> 1) & 1; /* U2 */ 
	SIU.GPDO[59].R = (counter_value >> 2) & 1; /* U1 (MSB) */

	/*************************************************************************/
}

/*
 * @brief	Main program
 *
 * @param	void
 * @retval	int
 */
int main(void) {
	/* peripherals initialization, do not remove */
	peripheralsInit();


	/* TO-DO: your task implementations **************************************/
 	
	 /* Switch states */
    bool isSwitch1On = false;
    bool isSwitch2On = false;
    bool isSwitch3On = false;
    bool isSwitch4On = false;
	
	// Button states
    bool bt1Pressed = false;
    bool bt2Pressed = false;

    // Previous button states for edge detection 
    bool previousBT1State = false;
    bool previousBT2State = false;

    // Previous SW4 state for timer control
    bool previousSW4State = false;


	/* Configure and start timer channels */	
    PIT_ConfigureTimer(1, 1000); // Channel 1, 1000 ms interval
	/*************************************************************************/

	/* main program */
	while(1){
		/* System function, do not remove */
		systemFunction();
		/* TO-DO: your task implementations **********************************/

        // Read button states

        bt1Pressed = (SIU.GPDI[60].R == 1);
        bt2Pressed = (SIU.GPDI[62].R == 1);


        //  Detect button presses and select direction
        if (bt1Pressed && !previousBT1State)
        {
            count_direction = 1;  
        }
        else if (bt2Pressed && !previousBT2State)
        {
            count_direction = -1; 
        }

		previousBT1State = bt1Pressed;
        previousBT2State = bt2Pressed;


		isSwitch1On = (SIU.GPDI[52].R == 1);
        isSwitch2On = (SIU.GPDI[53].R == 1);
        isSwitch3On = (SIU.GPDI[54].R == 1);
        isSwitch4On = (SIU.GPDI[55].R == 1);


		if (isSwitch4On != previousSW4State)
        {
            if (isSwitch4On)
            {
                // Start timer channel 1
                PIT_StartTimer(1);
            }
            else
            {
                // Stop timer channel 1
                PIT_StopTimer(1);
            }

            // Remember the current SW4 state
            previousSW4State = isSwitch4On;
        }



		// 3. Conditional execution branch
		if (isSwitch1On) {
			int pot_value = (ADC0.CDR[5].R & 0x00000FFF);
			task_pot(pot_value);
		} 
		else if (isSwitch2On) {
			int ldr_value = (ADC1.CDR[3].R & 0x00000FFF);
			task_ldr(ldr_value);
		}
		else if (isSwitch3On) { /* Switch 3 (PCR 54) is ON */ 
			task_counter(); 
		} 
		else { 
			// If none of the switches are ON, turn off all LEDs
			SIU.GPDO[56].R = 0; 
			SIU.GPDO[57].R = 0; 
			SIU.GPDO[58].R = 0; 
			SIU.GPDO[6].R  = 0; 
			SIU.GPDO[43].R = 0; 
			SIU.GPDO[59].R = 0;
		}

		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
	}
}


/*
 * @brief	PIT timer channel 1 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_1(void){

	/* TO-DO: your task implementations **************************************/
	/* Check if Switch 4 (PCR 55) is ON \*/ 
	if (SIU.GPDI[55].R == 1) { 
		if (count_direction == 1) { 
			counter_value = (counter_value + 1) % 8; /* Count UP with wrap-around */ 
		} else { 
			counter_value = (counter_value + 7 ) % 8; /* Count DOWN with wrap-around */ 
		} 
	}

	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void){

	/* TO-DO: your task implementations **************************************/


	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void){

	/* TO-DO: your task implementations **************************************/


	/*************************************************************************/
}
