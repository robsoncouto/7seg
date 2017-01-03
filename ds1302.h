#ifndef DS1302_H
#define DS1302_H

#include<avr/io.h>

//registers defines
#define DS_SEC 0x80
#define DS_MIN 0x82
#define DS_HRS 0x84
#define DS_DATE 0x86
#define DS_MON 0x88
#define DS_DAY 0x8A
#define DS_YEAR 0x8C
#define DS_WPR 0x8E
#define DS_TIC 0x90

#define READ 0x01
#define WRITE 0x00

//Pin definition, FIXME
#define RTC_PIN PIND
#define RTC_PORT PORTD
#define RTC_DDR DDRD

#define CE 5
#define IO 6
#define SCLK 7


uint8_t DS_read(uint8_t);
void DS_write(uint8_t,uint8_t);
void ds1302Init(void);
uint8_t dsGetSeconds(void);
uint8_t dsGetMinutes(void);
uint8_t dsGetHours(void);
uint8_t dsGetDay(void);
uint8_t dsGetMonth(void);
uint8_t dsGetYear(void);

void dsReset(void);
#endif
