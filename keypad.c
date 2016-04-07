#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
#include "keypad.h"
#include "displayFB.h"


__flash
const
uint8_t urutan_tombol[][4]=
{
    {1,4,7,10},
    {2,5,8,0},
    {3,6,9,11}
};

void
initTombol(void)
{
    OCR0A=223;
    TCCR0A|=_BV(WGM01);
    TCCR0B|=_BV(CS02)|_BV(CS00);
    TIMSK0|=_BV(OCIE0A);

    KEYPAD_ROW_PORT    &=  ~(_BV(ROW01)|_BV(ROW02)|_BV(ROW03)|_BV(ROW04));
    KEYPAD_ROW_DDR     |=  _BV(ROW01)|_BV(ROW02)|_BV(ROW03)|_BV(ROW04);
    KEYPAD_COL_PORT    |=  _BV(COL01)|_BV(COL02)|_BV(COL03);
    KEYPAD_COL_DDR     &=  ~(_BV(COL01)|_BV(COL02)|_BV(COL03));
}

uint_fast8_t
getKey(void)
{
    uint_fast8_t i=0;
    uint_fast8_t tom=0;


    tom=KEYPAD_COL_PIN;
    if (
        !(tom&(_BV(COL01))) ||
        !(tom&(_BV(COL02))) ||
        !(tom&(_BV(COL03)))
    )
    {
        for(i=0; i<KEYPAD_ROW; ++i)
        {
            KEYPAD_ROW_PORT|=(_BV(ROW01)|_BV(ROW02)|_BV(ROW03)|_BV(ROW04));
            uint_fast8_t ii=0;
            switch(i)
            {
            case 0:
                ii  = (uint8_t)~(_BV(ROW01));
                break;
            case 1:
                ii  = (uint8_t)~(_BV(ROW02));
                break;
            case 2:
                ii  = (uint8_t)~(_BV(ROW03));
                break;
            case 3:
                ii  = (uint8_t)~(_BV(ROW04));
                break;
            }
            tom=i;
            KEYPAD_ROW_PORT&=ii;
            ii=~(KEYPAD_COL_PIN);
            KEYPAD_ROW_PORT    &=~(_BV(ROW01)|_BV(ROW02)|_BV(ROW03)|_BV(ROW04));
            if(ii&_BV(COL01))
            {
                return urutan_tombol[0][tom];
            }
            else if(ii&_BV(COL02))
            {
                return urutan_tombol[1][tom];
            }
            else if(ii&_BV(COL03))
            {
                return urutan_tombol[2][tom];
            }
        }
    }
    return 0xff;
}
