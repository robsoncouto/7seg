#include "ds1302.h"

void writeByte(uint8_t data){
  for(uint8_t i=0;i<8;i++){
    if(data&(1<<i)){
      CTRL_PORT|=(1<<IO);
    }else{
      CTRL_PORT&=~(1<<IO);
    }
      CTRL_PORT|=(1<<SCK);
      CTRL_PORT&=~(1<<SCK);
  }
}
uint8_t readByte(void){
  uint8_t data=0;
  //FIXME input
  for(uint8_t i=0;i<8;i++){
    if(CTRL_PIN&(1<<IO)){
      data|=(1<<i);
    }else{
      data&=~(1<<i);
    }
      CTRL_PORT|=(1<<SCK);
      CTRL_PORT&=~(1<<SCK);
  }
}

uint8_t DS_read(uint8_t addr){
  uint8_t data;
  CTRL_PORT|=(1<<CE);
  writeByte(addr|READ);
  data=readByte();
  CTRL_PORT&=~(1<<CE);
  return data;

}

void DS_write(uint8_t addr,uint8_t data){
  CTRL_PORT|=(1<<CE);
  writeByte(addr|WRITE);
  writeByte(addr|WRITE);
  CTRL_PORT&=~(1<<CE);

}

void ds1302Init(void){
  CTRL_DDR|=(1<<IO)|(1<<SCK)|(1<<CE);
  CTRL_PORT|=~((0<<IO)|(0<<SCK)|(0<<CE));
}
