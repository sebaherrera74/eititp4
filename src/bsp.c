/* * Copyright 2022, Sebastian Herrera <sebaherrera152@gmail.com>
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

/** @file plantilla.c
 **
 ** @brief Plantilla de archivos fuente
 **
 ** Plantilla para los archivos de codigo fuente de prácticos de las 
 ** asignaturas Diseño Integrado de Sistemas Emebebidos y Sistemas Embebidos
 ** de Tiempo Real dictadas en de la Especialización en Integración de
 ** Sistemas Informaticos de la Univesidad Nacional de Tucumán
 ** 
 ** | RV | YYYY.MM.DD | Autor       | Descripción de los cambios              |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.10.10 | Sebastian   | Version inicial del archivo             |
 ** 
 ** @defgroup plantilla Plantilals de Archivos
 ** @brief Plantillas de archivos normalizadas
 ** @{ 
 */

/* === Inclusiones de cabeceras ============================================ */
#include "bsp.h"
#include "chip.h"
#include "poncho.h"
#include "ciaa.h"

//* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static struct board_s board={0};

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */
board_t BoardCreate(void){
	//Configuracion de salidas en este caso EL BUZZER
	 Chip_SCU_PinMuxSet(BUZZER_PORT, BUZZER_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | BUZZER_FUNC);
	 board.buzzer=DigitalOutputCreate(BUZZER_GPIO,BUZZER_BIT);

	/******************/
	//Chip_SCU_PinMuxSet(LED_1_PORT, LED_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_1_FUNC);
	//Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT, false);
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT, true);
	//board.ledRojo=DigitalOutputCreate(LED_1_GPIO,LED_1_BIT);

	//Chip_SCU_PinMuxSet(LED_2_PORT, LED_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_2_FUNC);
	//Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, false);
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, true);
	//board.ledAmarillo=DigitalOutputCreate(LED_2_GPIO,LED_2_BIT);

	//Chip_SCU_PinMuxSet(LED_3_PORT, LED_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_3_FUNC);
	//Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT, false);
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT, true);
	//board.ledVerde=DigitalOutputCreate(LED_3_GPIO,LED_3_BIT);

	//Configuracion de entradas en este caso las LAS 6 TECLAS
	/******************/
	Chip_SCU_PinMuxSet(KEY_F1_PORT,KEY_F1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F1_FUNC);
	board.set_time=DigitalInputCreate(KEY_F1_GPIO,KEY_F1_BIT);

	Chip_SCU_PinMuxSet(KEY_F2_PORT,KEY_F2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F2_FUNC);
	board.set_alarm=DigitalInputCreate(KEY_F2_GPIO,KEY_F2_BIT);

	Chip_SCU_PinMuxSet(KEY_F3_PORT,KEY_F3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F3_FUNC);
	board.increment=DigitalInputCreate(KEY_F3_GPIO,KEY_F3_BIT);

	Chip_SCU_PinMuxSet(KEY_F4_PORT,KEY_F4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F4_FUNC);
	board.decrement=DigitalInputCreate(KEY_F4_GPIO,KEY_F4_BIT);

	Chip_SCU_PinMuxSet(KEY_ACCEPT_PORT,KEY_ACCEPT_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_ACCEPT_FUNC);
	board.accept=DigitalInputCreate(KEY_ACCEPT_GPIO,KEY_ACCEPT_BIT);

	Chip_SCU_PinMuxSet(KEY_CANCEL_PORT,KEY_CANCEL_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_CANCEL_FUNC);
	board.set_alarm=DigitalInputCreate(KEY_CANCEL_GPIO,KEY_CANCEL_BIT);
	return &board;
}


/* === End of documentation ==================================================================== */

/** @} Final de la definición del modulo para doxygen */

