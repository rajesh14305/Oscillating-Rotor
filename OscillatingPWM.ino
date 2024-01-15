float t=0;
void setup() {
  Serial.begin(9600);
  TCCR3A =0;
  TCCR3B =0;
  TCCR3A |= B10000010;
  TCCR3B |=B00011011;
  TIMSK3 |=B00000010;
  
  ICR3= 5000;
  DDRE|= B00001000;

TCCR1A = 0;
TCCR1B = 0;
TCCR1B |= B00000010; // How to controll the timer conter or upodating the prescaller 8
TCNT1= 0; // Setting the counter register to zero for 16 bit timer 1 its max value 65535
TIMSK1 |=B00000010; // To set comparematch mode for timer 1
OCR1A = 799;
  
  


}

void loop() {
  // put your main code here, to run repeatedly:t
 

}
ISR(TIMER1_COMPA_vect)
{ 
  
  TCNT1=0;

  
    OCR3A=345+100*sin(1.57*t);//T=4sec;t is made small for smoothness
    t=t+0.0004;
    if (t>4)
    {
      t=0;
      
    }

    
  

}
ISR(TIMER3_COMPA_vect)
{
PORTE|=B00001000;    //D5 pin output
}