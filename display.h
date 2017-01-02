#ifndef DISPLAY_H
#define DISPLAY_H

#define displayPort PORTA
#define displayDDR DDRA
#define DIN 6
#define LOAD 7
#define CLK 5

void displayinit(void);
void displayWrite(uint8_t hours, uint8_t minutes);

#endif
