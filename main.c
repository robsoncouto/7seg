#define F_CPU 8000000UL

#include <avr/io.h>
#include "display.h"
#include "RTC/rtc.h"
#include <util/delay.h>
#include <avr/interrupt.h>

struct rtc_time ds1302;
struct rtc_time *rtc;

ISR(INT0_vect){
  uint8_t press=0;
    while(!(PIND&(1<<PIND2))){
      press++;
    }
    if(press>500){
      ds1302_update_time(rtc, MIN);	//read the seconds
      ds1302_set_time(rtc, MIN, rtc->minute+1);	//set the seconds to 31
    }
}
ISR(INT1_vect){
  uint8_t press=0;
    while(!(PIND&(1<<PIND2))){
      press++;
    }
    if(press>500){
      ds1302_update_time(rtc, HOUR);
      ds1302_set_time(rtc, HOUR, rtc->hour+1);
    }
}

int main (void){
  rtc = &ds1302;
  displayinit();
  displayWrite(12, 00);


	ds1302_init();
	ds1302_update(rtc);   // update all fields in the struct

  //ds1302_write_byte(w_protect,0x00);
  //ds1302_set_time(rtc, SEC, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, SEC, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, MIN, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, HOUR, 01);	//set the seconds to 31

  //test_dig=ds1302_read_byte(min_r|0x01);
  //displayWrite(0,test_dig);
  //ds1302_update(rtc);

    while(1){
      //dsReset();
      ds1302_update_time(rtc, SEC);	//read the seconds
      ds1302_update_time(rtc, MIN);	//read the seconds
      ds1302_update_time(rtc, HOUR);	//read the seconds
      displayWrite(rtc->minute,rtc->second);
      _delay_ms(500);

  }
}
