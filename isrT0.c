#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include "keypad.h"
#include "lcd.h"
#include "displayFB.h"


ISR(TIMER0_COMPA_vect)
{
    uint_fast8_t i;
    lcd_gotoxy(0,0);
    for(i=0; i<16; ++i)
    {
        lcd_putc(lcdFB[i]);
    }
    lcd_gotoxy(0,1);
    for(; i<32; ++i)
    {
        lcd_putc(lcdFB[i]);
    }
}
