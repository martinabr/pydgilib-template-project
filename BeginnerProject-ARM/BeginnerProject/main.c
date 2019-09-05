/**
 * \file
 *
 * \brief Application implement
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "atmel_start.h"
#include "atmel_start_pins.h"
#include <string.h>

#include "Serial/serial.h"
#include "Measurements/measurements.h"

/*******************************************************************/
/* WARNING: -Wno-unused-variable Wno-unused-value might be enabled */
/*******************************************************************/

int main(void)
{
	atmel_start_init();

	// Unused
	//usart_async_register_callback(&EDBG_COM, USART_ASYNC_TXC_CB, tx_cb_EDBG_COM);
	//usart_async_register_callback(&EDBG_COM, USART_ASYNC_ERROR_CB, err_cb_EDBG_COM);
	
	usart_async_register_callback(&EDBG_COM, USART_ASYNC_RXC_CB, rx_cb_EDBG_COM);
	usart_async_enable(&EDBG_COM);
	
	/*************/
	/* GPIO pins */
	/*************/
	// Initialize pins for output
	gpio_set_pin_direction(DGI_GPIO0, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(DGI_GPIO1, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(DGI_GPIO2, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(DGI_GPIO3, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(DGI_GPIO0, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(DGI_GPIO1, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(DGI_GPIO2, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(DGI_GPIO3, GPIO_PIN_FUNCTION_OFF);


	/*****************/
	/* Program start */
	/*****************/
	
			
	int i = 0;
	for (i = 0; i < 100; i++) {	
		RESET_MEASUREMENT;
		
		START_MEASURE(DGI_GPIO0); // red
		gpio_set_pin_level(LED0, GPIO_LOW);
		delay_ms(250);
		gpio_set_pin_level(LED0, GPIO_HIGH);
		STOP_MEASURE(DGI_GPIO0);
		
		delay_ms(250);
		
		START_MEASURE(DGI_GPIO1); // yellow
		gpio_set_pin_level(LED0, GPIO_LOW);
		delay_ms(250);
		gpio_set_pin_level(LED0, GPIO_HIGH);
		STOP_MEASURE(DGI_GPIO1);
		
		delay_ms(250);
		
		START_MEASURE(DGI_GPIO2); // blue
		gpio_set_pin_level(LED0, GPIO_LOW);
		delay_ms(250);
		gpio_set_pin_level(LED0, GPIO_HIGH);
		STOP_MEASURE(DGI_GPIO2);
		
		delay_ms(250);
		
		START_MEASURE(DGI_GPIO3); // green
		gpio_set_pin_level(LED0, GPIO_LOW);
		delay_ms(250);
		gpio_set_pin_level(LED0, GPIO_HIGH);
		/*
		char sentence[] = "This is cycle no. ";
		printline(sentence, 18);
		printint(i);
		print_endline();
		*/
		STOP_MEASURE(DGI_GPIO3);
		
		delay_ms(250);
	}
	
	END_MEASUREMENT;
	
	while(1) {
		1+1; // Dummy loop
	}
}
