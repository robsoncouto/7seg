#include "ds1302.h"
#include <util/delay.h>

void dsWriteByte(uint8_t data){
  RTC_DDR|=(1<<IO);
  for(uint8_t i=0;i<8;i++){
    RTC_PORT&=~(1<<SCLK);
    _delay_ms(1);
    if(data&(1<<i)){
      RTC_PORT|=(1<<IO);
    }else{
      RTC_PORT&=~(1<<IO);
    }
    RTC_PORT|=(1<<SCLK);
    _delay_ms(1);
  }
}
uint8_t dsReadByte(void){
  uint8_t data=0;
  RTC_DDR&=~(1<<IO);
  RTC_PORT|=(1<<IO);
  for(uint8_t i=0;i<8;i++){
    RTC_PORT&=~(1<<SCLK);
    _delay_ms(1);
    if(RTC_PIN&(1<<IO)){
      data|=(1<<i);
    }else{
      data&=~(1<<i);
    }
      RTC_PORT|=(1<<SCLK);
      _delay_ms(1);
  }
  return data;
}

uint8_t DS_read(uint8_t addr){
  uint8_t data;
  RTC_PORT|=(1<<CE);
  _delay_ms(1);
  dsWriteByte(addr|READ);
  data=dsReadByte();
  RTC_PORT&=~(1<<CE);
  return data;

}

void DS_write(uint8_t addr,uint8_t data){
  RTC_PORT|=(1<<CE);
  _delay_ms(1);
  dsWriteByte(addr|WRITE);
  dsWriteByte(data);
  RTC_PORT&=~(1<<CE);

}

void ds1302Init(void){
  RTC_DDR|=(1<<IO)|(1<<SCLK)|(1<<CE);
  RTC_PORT|=((1<<IO)|(1<<SCLK)|(1<<CE));

}
uint8_t dsGetSeconds(void){
  uint8_t sec=DS_read(DS_SEC)&0x7F;
  return (sec>>4)*10+(sec&0x0F);
}
uint8_t dsGetMinutes(void){
  uint8_t min=DS_read(DS_MIN)&0x7F;
  return (min>>4)*10+(min&0x0F);
}
uint8_t dsGetHours(void){
  uint8_t hours=DS_read(DS_HRS)&0x1F;
  return ((hours>>4)*10+(hours&0x0F));
}
uint8_t dsGetDay(void){
  uint8_t day=DS_read(DS_DAY);
  return (day&0x07);
}
uint8_t dsGetMonth(void){
  uint8_t month=DS_read(DS_MON)&0x1F;
  return (month>>4)*10+(month&0x0F);
}
uint8_t dsGetYear(void){
  uint8_t year=DS_read(DS_YEAR);
  return (year>>4)*10+(year&0x0F);
}
void dsReset(void){
  DS_write(DS_WPR,0x00);
  DS_write(DS_SEC,0x00);
  DS_write(DS_MIN,0x00);
  DS_write(DS_HRS,0x81);
  DS_write(DS_DATE,0x01);
  DS_write(DS_MON,0x01);
  DS_write(DS_DAY,0x01);
  DS_write(DS_YEAR,0x16);
  DS_write(DS_TIC,0x00);

}
