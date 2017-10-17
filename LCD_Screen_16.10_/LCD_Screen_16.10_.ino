//Screen
//1 VSS - GND
//2 VDD - 5V
//3 V0 - contrast
//4 RS - PIN 13
//5 R/W - GND
//6 E - PIN 12
//7
//8
//9
//10
//11 - DB4 - PIN 8
//12 - DB5 - PIN 9
//13 - DB6 - PIN 10
//14 - DB7 - PIN 11
//15 - 5V
//16 - GND
#include<LiquidCrystal.h>


float UltrIn;
int but = 2;
int pinRS = 13;
int pinE = 12;
int pinDB4 = 8;
int pinDB5 = 9;
int pinDB6 = 10;
int pinDB7 = 11;
char str[4][80];
int i,n = 0,t;

int lng[4];
int str_in_now = 0;
int str_out_now = 0;

void func1()
{
  delay(50);
  if(digitalRead(but))
  {
    if(str_out_now>3)
        str_out_now = 0;
     else
        str_out_now++;
     n = lng[str_out_now];
     t = 0;  
  }
}

LiquidCrystal lcd(pinRS,pinE,pinDB4,pinDB5,pinDB6,pinDB7);

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,func1,RISING);
  pinMode(but,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
     if(str_in_now>3)
        str_in_now = 0;
     else
        str_in_now++;
     delay(500);
     lng[str_in_now] = 0;
     while(Serial.available()>0)
     {
        str[str_in_now][i] = Serial.read();
        lng[str_in_now]++;
     }
  }
  //t - current char
  //n - number of remaining chars
 
  if (n<=0)
  {
    n = lng[str_out_now];
    t = 0;
  }
  while(n>0)
  {
    lcd.setCursor(0,0);
    lcd.clear();
    if(n<16)
    {
      while(t<lng[str_out_now])
      {
         lcd.print(str[str_out_now][t]);
         t++;
      }
    }
    else
    {
      for(int k = 0; k<16;k++,t++)
         lcd.print(str[str_out_now][t]);
      lcd.setCursor(0,1);
      if(n<32)
      {
        while(t<lng[str_out_now])
        {
         lcd.print(str[str_out_now][t]);
         t++;
        }
      }
      else
      {
        for(int k = 0; k<16;k++,t++)
          lcd.print(str[str_out_now][t]);
      }
    }
    n = n-32;
    delay(3000);
  }
}
