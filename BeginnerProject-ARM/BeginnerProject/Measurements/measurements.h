/*
 * measurements.h
 *
 * Created: 2019-02-25 12:45:01
 *  Author: Dragos
 */ 


#ifndef MEASUREMENTS_H_
#define MEASUREMENTS_H_

#include "../Serial/serial.h"

// The pins have been double checked to be correct
#define DGI_GPIO0 GPIO(GPIO_PORTA, 10)
#define DGI_GPIO1 GPIO(GPIO_PORTA, 11)
#define DGI_GPIO2 GPIO(GPIO_PORTA, 23)
#define DGI_GPIO3 GPIO(GPIO_PORTA, 27)

// These smart defines below are credit of E.W.
#define DELAY_MEASUREMENT delay_ms(2)

#define GPIO_HIGH true
#define GPIO_LOW false

#define START_MEASURE(PIN) DELAY_MEASUREMENT; gpio_set_pin_level(PIN, GPIO_HIGH)
#define STOP_MEASURE(PIN) gpio_set_pin_level(PIN, GPIO_LOW); DELAY_MEASUREMENT
#define END_MEASUREMENT DELAY_MEASUREMENT; gpio_set_pin_level(DGI_GPIO0, GPIO_HIGH); gpio_set_pin_level(DGI_GPIO1, GPIO_HIGH); gpio_set_pin_level(DGI_GPIO2, GPIO_HIGH); gpio_set_pin_level(DGI_GPIO3, GPIO_HIGH)
#define RESET_MEASUREMENT STOP_MEASURE(DGI_GPIO0); STOP_MEASURE(DGI_GPIO0); STOP_MEASURE(DGI_GPIO0); STOP_MEASURE(DGI_GPIO0); DELAY_MEASUREMENT

#endif /* MEASUREMENTS_H_ */