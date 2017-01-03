#include "uart.h"
#include "rtc.c"
// Baud rate setting
#define BAUD 9600

void main(void)	{
	// Serial channel (9600, N,8,1)
        uart_init((UART_BAUD_SELECT((BAUD),F_OSC)));

        sei(); // interrupt enable
	unsigned char sec, temp;
	sec = 0;
	struct rtc_time ds1302;
	struct rtc_time *rtc;
	rtc = &ds1302;

	ds1302_init();
	ds1302_update(rtc);   // update all fields in the struct
	ds1302_set_time(rtc, SEC, 31);	//set the seconds to 31

	while (1)   // read seconds and send it via uart continuously
	{
		ds1302_update_time(rtc, SEC);	//read the seconds
                uart_putc(rtc->second); // send byte to serial line , you may not send it via uart,
                uart_puts_P( "\r"); // LF	// I just want to mention how to use the data with this
		_delay_ms(100);
	}
}
