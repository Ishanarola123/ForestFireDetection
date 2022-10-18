#include<SoftwareSerial.h>
SoftwareSerial gsmSerial(0, 1);

int flame = 2;
int smoke = 3;
int state = 0;
int buzz= 4;

void setup()
{
  //Set Exact Baud rate of the GSM/GPRS Module.
  pinMode(flame,INPUT);
  pinMode(smoke,INPUT);
  gsmSerial.begin(9600); 
  Serial.begin(9600);
  delay(1000);
  Serial.println("Preparing to send SMS");
  delay(2000);
  pinMode(buzz,OUTPUT);
}

void loop()
{
  if ((digitalRead(flame) == HIGH || digitalRead(smoke) == HIGH )&& state==0) 
  {
    Serial.print(digitalRead(flame));
    gsmSerial.println("AT+CMGF=1\r");
    delay(2000);
    Serial.print("AT+CMGS=\"+919328778840\"\r \n");	
    //number on which message to be send
    gsmSerial.println("AT+CMGS=\"+919328778840\"\r");	
    Serial.println("message has been sent \n");
    //number on which message to be send
    delay(2000);
    Serial.print("FIRE HAS BEEN DETECTED \n");

    
     digitalWrite(buzz,HIGH);
     delay(2000);
     digitalWrite(buzz,LOW);
     delay(2000);
     Serial.println("buzzer is started!!!!!!! ");
     Serial.println();

    //MSG going on mobile
    gsmSerial.println("FIRE HAS BEEN DETECTED"); 
    Serial.println();   
    Serial.write(0x1A);
    delay(2000);
    state=1;
    
  }
 if ((digitalRead(flame) == LOW && digitalRead(smoke) == LOW )&& state==1) {
     state=0;
     digitalWrite(buzz,LOW);
     delay(2000);
  }
}
