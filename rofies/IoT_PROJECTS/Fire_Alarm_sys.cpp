
// element/components used 
/*

Tinker cad:
1. Temperature sensor:  if v inc - Voltage also inc (for every 1*C change of  mili voltage)
2. bread board
3. Arduino
4. gas sensor: based on gas in surrounding - it produces a potential difference by changing resitance of material inside
for alert :
5. led 
6. piezo buzzer
// blue wire - i/p signal 
// orange - o/p signal
*/ 

#include<bits/stdc++.h>
using namespace std;
int main(){

float temp ;
float vout ; //output of temp sensor 
float vout1 ; // temp inc and new voltage produced
int LED = 13 ; 
int gasSensor; //concentrationof smoke
int piezo = 7; // pin 7
void setup()
{
  pinMode(A0, INPUT); // gas sensor i/p
  pinMode(A1, INPUT); //temp
  pinMode(LED, OUTPUT); //alert
  pinMode(piezo, OUTPUT); //buzz
  serial.begin(9600); //serial monitor activate
}
void loop()
{
  vout = analogRead(A1); 
  vout1 = (vout/1023)*5000; //new voltage
  temp = (vout1-500)/10;
  gasSensor=analogRead(A0);
  if (temp>=80) //threshhold value 
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  if (gasSensor>=100)
  {
    digitalWrite(piezo,HIGH);
  }
  else 
  {
   digitalWrite(piezo,LOW); 
  }
  Serial.print("in DegreeC= ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("GasSensor= ");
  Serial.print(" ");
  Serial.print(gasSensor);
  Seral.println();
  delay(1000);
}
               
}