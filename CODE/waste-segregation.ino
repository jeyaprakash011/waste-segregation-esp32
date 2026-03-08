/*
 * Waste Segerication  
 * 11.02.2026 
 */

 
volatile int interruptCounter;
int ssec,ok;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR onTimer() 
{
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
 
}


#include <ESP32_Servo.h> 



Servo myservo1; 



#define SERVO 18

#define ir    19
#define moi   21
#define prox  5
#define MOT 15
#define buzz 23
#define pos 4

#define ON  0
#define OFF 1


int run,sec,position,check,place,ena;
int d,distance,duration;
int IR,PROX,POS,MOIST;

void setup()
{
Serial.begin(9600);


 timer = timerBegin(0, 80, true);
 timerAttachInterrupt(timer, &onTimer, true);
 timerAlarmWrite(timer, 100000, true);
 timerAlarmEnable(timer);
 Serial.println("STARTED...");


  
myservo1.attach(SERVO);
pinMode(ir,INPUT_PULLUP);
pinMode(moi,INPUT);
pinMode(prox,INPUT_PULLUP);
pinMode(pos,INPUT_PULLUP);
pinMode(buzz, OUTPUT);

 
pinMode(MOT,OUTPUT);

digitalWrite(MOT,LOW);

digitalWrite(buzz,LOW);



 Serial.println("Relay on"); 
digitalWrite(MOT,HIGH);
while(1)
{
if(digitalRead(pos)==LOW){digitalWrite(MOT,LOW);place=1;break;}
}
Serial.print("Place: ");Serial.println(place);
ssec=sec=0;
close1();
digitalWrite(buzz,HIGH); delay(1500);digitalWrite(buzz,LOW);


}

void loop()
{
IR=digitalRead(ir);
MOIST=digitalRead(moi);
PROX=digitalRead(prox);
POS=digitalRead(pos);

/*Serial.print("IR: ");Serial.print(IR);
Serial.print("WET: ");Serial.print(MOIST);
Serial.print("METAL: ");Serial.print(PROX);
Serial.print("POS: ");Serial.println(POS);*/

//if(digitalRead(L1)==LOW){Serial.println("pRESSED");}
//if(digitalRead(L1)==HIGH){Serial.println("-------");}


if (interruptCounter > 0 && ena==1) 
  {  
    portENTER_CRITICAL(&timerMux);
    interruptCounter=0;
    portEXIT_CRITICAL(&timerMux);
    ssec++;if(ssec>10){ssec=0;sec++;}
    if(sec>8){sec=0;}
    Serial.print("SEC:");Serial.println(sec);
  }

 if(IR==0){check=1;ena=1;sec=0;Serial.println("waste detected... checking progress");}

 if(check==1 && MOIST==0 && sec<5){Serial.println("WET WASTE");ena=0;check=0;sec=0;position=1;delay(1500);}
 if(check==1 && PROX==0 && sec<5){Serial.println("METAL WASTE");ena=0;check=0;sec=0;position=2;delay(1500);}
 if(sec>5 && MOIST==1 && PROX==1){Serial.println("NORMAL WASTE");ena=0;check=0;sec=0;position=3;delay(1500);}


if(position==1)
{
  if(place!=1){digitalWrite(MOT,HIGH);delay(1000);}
    while(position==1)
    {
    Serial.println("position-1 check");
    if(digitalRead(pos)==LOW){Serial.println("position detected");place++;delay(300);if(place>3){place=1;}}
    if(place==1){digitalWrite(MOT,LOW);delay(1000);open1();delay(2000);close1();position=0;break;}
    }
}

if(position==2)
{
  if(place!=2){digitalWrite(MOT,HIGH);delay(1000);}
    while(position==2)
    {
    Serial.println("position-2 check");
    if(digitalRead(pos)==LOW){Serial.println("position detected");place++;delay(300);if(place>3){place=1;}}
    if(place==2){digitalWrite(MOT,LOW);delay(1000);open1();delay(2000);close1();position=0;break;}
    }
}
if(position==3)
{
  if(place!=3){digitalWrite(MOT,HIGH);delay(1000);}
    while(position==3)
    {
    Serial.println("position-3 check");
    if(digitalRead(pos)==LOW){Serial.println("position detected");place++;delay(300);if(place>3){place=1;}}
    if(place==3){digitalWrite(MOT,LOW);delay(1000);open1();delay(2000);close1();position=0;break;}
    }
}


}


void open1()  //L1  open, L2 cose
{
Serial.println("Opening..");
myservo1.write(0);
}

void close1()  //L1  open, L2 cose
{
Serial.println("closing...");
myservo1.write(160);
} 
