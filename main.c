#include <avr/io.h>
#include "i2clib/i2c_master.h"
#include "display.h"


int main (void){
  i2c_init();
  displayinit();
  while(1){

  }
}
