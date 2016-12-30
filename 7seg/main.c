#include <avr/io.h>
#include "i2clib/i2c_master.h"

//the seven segments display table
uint8_t numbers[]={
//0b0gfedcba
  0b01111111, //zero
  0b00000110, //one
  0b01011011, //two
  0b01001111, //three
  0b01100110, //four
  0b01101101, //five
  0b01111101, //six
  0b00000111, //seven
  0b01111111, //eight
  0b01101111  //nine
};

int main (void){

  while(1){

  }
}
