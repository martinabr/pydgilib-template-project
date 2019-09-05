/*
 * printlines.c
 *
 * Created: 2019-02-11 12:13:21
 *  Author: Dragos
 */ 

#include "serial.h"

const uint8_t ready_string[4] = "RDY\n";
const uint8_t cr_lf[2] = "\r\n";
const uint8_t comma[1] = ",";

volatile uint8_t data_arrived = 0;
volatile uint8_t data_in_transit = 0;

char buffer[BUFFER_SIZE] = { '\0' };

void tx_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr)
{
	/* Transfer completed */
	data_in_transit = 0;
}

void rx_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr)
{
	/* Receive completed */
	data_arrived = 1;
}

void err_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr)
{
	/* error handle */
	io_write(&EDBG_COM.io, error_string, 4);
}

void skipline() {
	readline(buffer, BUFFER_SIZE);
}

unsigned int readline(char* line, int length) {
	char c = '2';
	int index = 0;
	
	while (index < length) {
		readchar(&c);
		
		line[index++] = c;
	}
	
	return index;
}

void printline(char *line, int length) {
	int index = 0;
	
	while (index < length) {		
		printchar(&(line[index++]));
	}
}

void printint(int value) {
	char value_char[MAX_NO_DIGITS] = { '\0' };
	int value_temp = value;
	
	// Count digits
	int no_digits = 0;
	do {
		no_digits++;
		value_temp /= 10;
	} while(value_temp > 0);
	
	int index = no_digits;
	do {
		index--;
		value_char[index] = '0' + (value % 10);
		value /= 10;
	} while ((value > 0) && (index > 0));
	
	int i;
	for (i = 0; i < no_digits; i++) {
		printchar(&(value_char[i])); DELAY_SERIAL;
	}
}