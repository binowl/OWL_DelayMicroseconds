/*
 * OWL_DelayMicroseconds.h
 *
 *  Copyright BinOwl 2018
 *
 *  Created on: 05.09.2018
 *      Author: BinOwl
 */

#ifndef OWL_DELAYMICROSECONDS_H_
#define OWL_DELAYMICROSECONDS_H_


/* Dont forget to change this include to your MCU */
#include "stm32f3xx_hal.h"

/**
 * OWL_DelayMicroseconds - Delay for microseconds
 *
 * @param microseconds
 */
__STATIC_INLINE void OWL_DelayMicroseconds(uint16_t microseconds) {
	uint16_t _delay = microseconds * SystemCoreClock / 1000 / 1000;
	DWT->CYCCNT = 0;
	DWT->CTRL |= 1;
	uint8_t _DWT_CYCCNT_START = DWT->CYCCNT;
	while((DWT->CYCCNT - _DWT_CYCCNT_START) < _delay);
	DWT->CTRL |= 0;
}


#endif /* OWL_DELAYMICROSECONDS_H_ */

