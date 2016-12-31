#include<avr/io.h>
#define displayPort PORTB
#define displayDDR DDRB

#define digitPort PORTC
#define digitDDR DDRC


//todo timer interrupt
uint8_t time[4];
uint8_t curr_digit;


//interrupt code, sketch
void interrupt(){
  curr_digit++;
  if (curr_digit==4) curr_digit=0;
  //put number onto digit
  displayPort=0x00;
  displayPort=time[curr_digit];

  //enable digit
  digitPort&=~(0x0f);
  digitPort=(1<<curr_digit);

}

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

void displayinit(void){
  displayDDR=0x7F;
  displayPort=0x00;

  digitDDR=0x0F;
  digitPort=0x00;
}
void displayWrite(uint8_t hours, uint8_t minutes){
  time[1]=minutes/10;      //digit for sets of ten
  time[0]=minutes-time[1]; //digit for set of ones

  time[3]=hours/10;      //digit for sets of ten
  time[2]=hours-time[3]; //digit for set of ones
}
