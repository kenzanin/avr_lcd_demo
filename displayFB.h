#include <avr/io.h>

#ifndef DISPLAY_H_
#define DISPLAY_H_

extern
uint_fast8_t
lcdFB[32];

uint_fast8_t
getTombol(uint_fast8_t x);

#endif /* DISPLAY_H_ */
