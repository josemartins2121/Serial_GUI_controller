#include "LedControl.h"

/* Arduino Pin to Display Pin
   7 to DIN,
   6 to CS,
   5 to CLK */

LedControl lc = LedControl(3,5,4,1);

int row;
int row_prev;
int col;
int col_prev;
int ball_timer = 100;  // time in between firing leds – ‘speed’ variable
long randNumber;     // variable for the random generator
long updown=1;         // directs movement: +1 is one row up up and -1 is one row down
long leftright=1;         // directs movement: +1 is one col right and -1 is one col left

const int green_led = 8;
const int blue_led = 9;
const int red_led = 10;

byte smiley[] =          // fill array for the smiley
{
B00111110,
B01000001,
B10010101,
B10100001,
B10100001,
B10010101,
B01000001,
B00111110
};
void smile() // here we build up the smiley, row after row
{
  for (int i = 0; i < 8; i++)
    lc.setRow(0,i,smiley[i]);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(blue_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  lc.shutdown (0,false);
  lc.setIntensity (0,8);
  smile();
  delay(1000);

  lc.clearDisplay(0);
  randomSeed (analogRead (0));
  col = random (1, 7);                     // sets a col position between 1 and 7
  row = random (1, 7);                    // sets a row position between 1 and 7
       
}

void loop() {
  // put your main code here, to run repeatedly:

  char read;
  if(Serial.available()>0)
    read = Serial.read();

  int current_led;

  switch(read){

    case 'R' :
       current_led = red_led;
      break;
    case 'G' :
       current_led = green_led;
      break;
    case 'B' :
       current_led = blue_led;
      break;

    
  }
 
  digitalWrite(current_led,HIGH);
  delay(1000);
  digitalWrite(current_led,LOW);



  
  /*digitalWrite(red_led,HIGH);
  delay(150);
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,HIGH);
  delay(150);
  digitalWrite(green_led,LOW);
  digitalWrite(blue_led,HIGH);
  delay(150);
  digitalWrite(blue_led,LOW);

  randNumber = random(1,50);

  if(randNumber == 1){
    lc.setLed(0, col,row, false);
    col = random(1,7);
    row = random(1,7);
  }
  
  col_prev= col;                                // log position of ball
  row_prev = row;                             // log position of ball
  row = row+updown;                     // calculate new position of ball
  col = col+leftright;
  checkVectors ();
  lc.setLed(0, col_prev, row_prev, false); // erase previous ball position
  lc.setLed(0, col, row, true);            // light up new ball position
  delay(ball_timer);*/
   
}




void checkVectors () {
  if ((row>7) && (updown=1)){
  updown=-1;
  row=6;
  }

  if ((row<0) && (updown=-1)){
  updown=1;
  row=1;
  }

  if ((col>7) && (leftright=1)){
  leftright=-1;
  col=6;
  }

  if ((col<0) && (leftright=-1)){
  leftright=1;
  col=1;
  }
}
