#define F_CPU 8000000UL

#include <avr/io.h>
#include "i2clib/i2c_master.h"
#include "display.h"
#include "ds1302.h"
#include <util/delay.h>


uint8_t test_dig=0;
int main (void){
  //i2c_init();
  displayinit();
  displayWrite(12, 00);
    while(1){

  }
}
