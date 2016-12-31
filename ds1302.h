#ifndef DS1302_H
#define DS1302_H

//registers defines
#define DS_SEC 0x80
#define DS_MIN 0x82
#define DS_HRS 0x84
#define DS_DATE 0x86
#define DS_MON 0x88
#define DS_DAY 0x8A
#define DS_YEAR 0x8C
#define DS_WPR 0x8E

//Pin definition, FIXME
#define CTRL_PIN PINC;
#define CTRL_PORT PORTC;
#define CTRL_DDR DDRC;

uint8_t DS_read(uint8_t);
void DS_write(uint8_t,uint8_t);
void ds1302Init(void);

#endif
