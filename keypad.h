#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_ROW_PORT PORTD
#define KEYPAD_ROW_DDR *(&KEYPAD_ROW_PORT-1)
#define KEYPAD_COL_PORT PORTD
#define KEYPAD_COL_DDR *(&KEYPAD_COL_PORT-1)
#define KEYPAD_COL_PIN *(&KEYPAD_COL_PORT-2)
#define ROW01   PD4
#define ROW02   PD5
#define ROW03   PD6
#define ROW04   PD7
#define COL01   PD1
#define COL02   PD2
#define COL03   PD3
#define KEYPAD_ROW  4

void
initTombol(void);
uint_fast8_t
getKey(void);

extern
uint_fast8_t buffTom;

#endif /* KEYPAD_H_ */
