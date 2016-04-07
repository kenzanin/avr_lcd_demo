#include <avr/io.h>
#include <util/delay.h>
#include "displayFB.h"
#include "keypad.h"

__flash
const
uint8_t
hasilKey[][5]=
{
    {'0','0','0','0','0'},
    {'1','1','1','1','1'},
    {'2','A','B','C','2'},
    {'3','D','E','F','3'},
    {'4','G','H','I','4'},
    {'5','7','K','L','5'},
    {'6','M','N','O','6'},
    {'7','P','Q','R','S'},
    {'8','T','U','V','8'},
    {'9','W','X','Y','Y'},
    {'*',0b01111111,0b01111111,0b01111111,'*'},
    {'#',' ',0b11010011,' ','#'},
};

uint_fast8_t lcdFB[32]= {0};

uint_fast8_t
getTombol(uint_fast8_t x)
{
    uint_fast16_t   i=0;
    uint_fast8_t    keyPrev=0;
    uint_fast8_t    keyNow=0;
    uint_fast8_t    tmp01=0;
    uint_fast8_t    tmp02=0;
    _Bool adaKey=0;

    for(i=0; i<10; ++i)
    {
        tmp01=getKey();
        if(tmp01!=0xff)
        {
            adaKey=1;
            i=0;
            keyNow=tmp01;
            if (keyNow==keyPrev)
            {
                ++tmp02;
                if (tmp02>4)
                {
                    tmp02=0;
                }
            }
            else
            {
                tmp02=0;
            }
            keyPrev=keyNow;
            lcdFB[x]=hasilKey[keyNow][tmp02];
            _delay_ms(300);
        }
    }

    if (adaKey==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
