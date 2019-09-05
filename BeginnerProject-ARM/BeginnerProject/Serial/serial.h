/*
 * printlines.h
 *
 * Created: 2019-02-11 12:12:25
 *  Author: Dragos
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

// ---------

#include <atmel_start.h>
#include <stdint.h>

// ---------

#define DELAY_SERIAL delay_ms(2)

#define BUFFER_SIZE 8
#define MAX_NO_DIGITS 8

#define CR_LF cr_lf
#define LF (cr_lf + 1)
#define COMMA comma

// ---------

#define printchar(c) io_write(&EDBG_COM.io, (uint8_t *)(c), 1); DELAY_SERIAL;
#define readchar(c) while (data_arrived == 0); io_read(&EDBG_COM.io, (uint8_t *)(c), 1); data_arrived = 0

#define print_endline() io_write(&EDBG_COM.io, CR_LF, 2)
#define print_comma() io_write(&EDBG_COM.io, COMMA, 1)

// ---------

extern const uint8_t ready_string[4];
extern const uint8_t error_string[4];
extern const uint8_t cr_lf[2];
extern const uint8_t comma[1];

extern volatile uint8_t data_arrived;
extern volatile uint8_t data_in_transit;

// ---------

typedef struct usart_async_descriptor USART_ASYNC_DESCRIPTOR;

void tx_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr);
void rx_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr);
void err_cb_EDBG_COM(const USART_ASYNC_DESCRIPTOR *const io_descr);

// ---------

void skipline();
unsigned int readline(char* line, int length);
void printline(char *line, int length);
void printint(int value);

// ---------

#endif /* PRINTLINES_H_ */