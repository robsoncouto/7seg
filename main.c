#define F_CPU 8000000UL

#include <avr/io.h>
#include "display.h"
#include "RTC/rtc.h"
#include <util/delay.h>


uint8_t test_dig=0;
int main (void){
  displayinit();
  displayWrite(12, 00);
  struct rtc_time ds1302;
	struct rtc_time *rtc;
	rtc = &ds1302;

	ds1302_init();
	ds1302_update(rtc);   // update all fields in the struct

  //ds1302_write_byte(w_protect,0x00);
  //ds1302_set_time(rtc, SEC, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, SEC, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, MIN, 01);	//set the seconds to 31
  //ds1302_set_time(rtc, HOUR, 01);	//set the seconds to 31

  //test_dig=ds1302_read_byte(min_r|0x01);
  //displayWrite(0,test_dig);
  ds1302_update(rtc);

    while(1){
      //dsReset();
      ds1302_update_time(rtc, SEC);	//read the seconds
      ds1302_update_time(rtc, MIN);	//read the seconds
      ds1302_update_time(rtc, HOUR);	//read the seconds
      displayWrite(rtc->minute,rtc->second);
      _delay_ms(500);

  }
}
