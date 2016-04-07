#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "keypad.h"
#include "displayFB.h"

void
initAvr(void)
{
    lcd_init(LCD_DISP_ON);
    initTombol();
    DDRC=0xff;
    sei();
}

int
main(void)
{
    uint_fast8_t tmp=0;
    initAvr();

    while(1)
    {
        if(getTombol(tmp))
        {
            if(lcdFB[tmp]==0b01111111)
            {
                lcdFB[tmp]=0;
                tmp-=1;
                lcdFB[tmp]=0;
            }
            else
            {
                ++tmp;
            }
            if(tmp>=32)
            {
                tmp=0;
            }
        }
    }
}
