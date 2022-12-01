/*
 * Copyright 2022, Sebastian Herrera <sebaherrera152@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */


#include "bsp.h"
#include <stdbool.h>
#include "chip.h"
#include  "poncho.h"

/* === Macros definitions ====================================================================== */

//Definiciones de bits asociados a cada segmento para construir los digitos
#define SEGMENT_A  (1<<0)
#define SEGMENT_B  (1<<1)
#define SEGMENT_C  (1<<2)
#define SEGMENT_D  (1<<3)
#define SEGMENT_E  (1<<4)
#define SEGMENT_F  (1<<5)
#define SEGMENT_G  (1<<6)
#define SEGMENT_P  (1<<7)



/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static const uint8_t IMAGES[]={
		SEGMENT_A |SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F,             //< 0
		SEGMENT_B|SEGMENT_C,                                                      //< 1
		SEGMENT_A |SEGMENT_B|SEGMENT_D|SEGMENT_E|SEGMENT_G,         	          //< 2
		SEGMENT_A |SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_G,                       //< 3
		SEGMENT_F |SEGMENT_B|SEGMENT_G|SEGMENT_C,                                 //< 4
		SEGMENT_A |SEGMENT_F|SEGMENT_G|SEGMENT_C|SEGMENT_D,                       //< 5
		SEGMENT_A |SEGMENT_F|SEGMENT_G|SEGMENT_C|SEGMENT_D|SEGMENT_E ,            //< 6
		SEGMENT_A |SEGMENT_B|SEGMENT_C,                                           //< 7
		SEGMENT_A |SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G ,  //< 8
		SEGMENT_A |SEGMENT_B|SEGMENT_C|SEGMENT_F|SEGMENT_G ,                      //< 9

};


/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
void WriteNumber(uint8_t number){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, SEGMENTS_GPIO,IMAGES[number]);
}

void SelectDigit (uint8_t digit){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, DIGITS_GPIO,(1<<digit));
}

void ScreenOff(void){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, DIGITS_GPIO,DIGITS_MASK);
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, SEGMENTS_GPIO,SEGMENTS_MASK);
}

/* === Public function implementation ========================================================= */

int main(void) {

	int divisor  = 0;
	bool current_state, last_state = false;
	uint8_t actual=0;
	bool refrescar =true;

	uint8_t screen[4]={1,2,3,4};


	board_t board=BoardCreate();



	while (true) {
		ScreenOff();
		WriteNumber(screen[actual]);
		SelectDigit(actual);
		if (actual==3){
			actual=0;
		}else {

			actual=actual+1;
		}



		/*if (DigitalInputGetState(board->botonPrueba) == 0) {
        	DigitalOutputActivate(board->ledAzul);
        } else {
        	 DigitalOutputDeactivate(board->ledAzul);
        }

        current_state = (DigitalInputGetState(board->botonPrender) == 0);
        if ((current_state) && (!last_state)) {
        	 DigitalOutputToogle(board->ledRojo);

        }
        last_state = current_state;

        if (DigitalInputGetState(board->botonPrueba) == 0) {
        	DigitalOutputActivate(board->ledAmarillo);

        }
        if (DigitalInputGetState(board->botonApagar) == 0) {
        	DigitalOutputDeactivate(board->ledAmarillo);

        }

        divisor++;
        if (divisor == 5) {
            divisor = 0;
            DigitalOutputToogle(board->ledVerde);

        }
        //DigitalOutputActivate(board->);*/

		//for (int index = 0; index < 100; index++) {
			for (int delay = 0; delay < 25000; delay++) {
				__asm("NOP");
			//}
		}
	}
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
