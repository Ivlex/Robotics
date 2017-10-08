//attachInterrupt(interrupt,function,mod)
//interrupts:
//0 - Pin2
//1 - Pin3
//2 - Pin21
//3 - Pin20
//4 - Pin19
//5 - Pin18
//
//mods:
//LOW
//HIGH
//CHANGE: LOW->HIGH or HIGH->LOW
//RISING: LOW->HIGH
//FALLING: HIGH->LOW

int but = 2;
int led = 12;
int led_2 = 11;
int led_3 = 10;
int tmr = 0;
unsigned long long time_1;
unsigned long long time_2;
unsigned long long time_3;
bool stat1 = false;
bool stat2 = false;
bool stat3 = false;

void func1()
{
  delay(50);
  if(digitalRead(but))
    stat1 = !stat1;
}

void func2()
{
  tmr = 0;
  delay(50);
  if (digitalRead(but))
  {
    while(digitalRead(but))
    {
      tmr++;
      delay(1);
    }
  }
}

void setup() {
  pinMode(but,INPUT);
  pinMode(led,OUTPUT);
  attachInterrupt(0,func2,RISING);
}

void loop() {
  if(tmr>0)
  {
    if (time_1+tmr/2<millis())
    {
        digitalWrite(led,stat1);
        stat1=!stat1;
        time_1 = millis();
    }
  }
  if(time_2+500<millis())
  {
    digitalWrite(led_2,stat2);
    stat2=!stat2;
    time_2 = millis();
  }
  if(time_3+1000<millis())
  {
    digitalWrite(led_3,stat3);
    stat3=!stat3;
    time_3 = millis();
  }
}
