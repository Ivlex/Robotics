//UART
//RX: ->(Out)
//TX: <-(In)
//TX0,RX0 - for communication with a computer
//
//Serial - class for working with UART
//.begin(speed) - initialization
//.end()
//.available() - function returns the number of bytes available for reading
//.read() - function returns the next readable value and deletes it
//.peek() - function returns the next readable value but does not delete it
//.print(val,format) - function sends the value as an ASCII code
//.println(val,format)
//.write(var) - function sends the value as a binary code
//.write(buf,length)
//
//speed values:
//300 bit per second
//600
//1200
//2400
//9600 
//19200
//
//formats:
//byte, pin, ...
//numerical value - number of symbols after the decimal point

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
char ch[] = "0 0";

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() == 3)
  {
    ch[0] = Serial.read();
    ch[1] = Serial.read();
    ch[2] = Serial.read();


    switch(ch[0])
    {
      case '1':
        if(ch[2] == '1')
          digitalWrite(led1,HIGH);
        else if(ch[2] == '0')
          digitalWrite(led1,LOW);
      break;
    
      case '2':
        if(ch[2] == '1')
          digitalWrite(led2,HIGH);
        else if(ch[2] == '0')
          digitalWrite(led2,LOW);
      break;

      case '3':
        if(ch[2] == '1')
          digitalWrite(led3,HIGH);
        else if(ch[2] == '0')
          digitalWrite(led3,LOW);
      break;
      
      case '4':
        if(ch[2] == '1')
          digitalWrite(led4,HIGH);
        else if(ch[2] == '0')
          digitalWrite(led4,LOW);
      break;
      default:
      break;
    }
  }
}
