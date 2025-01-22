

float temp ;
float vout ; //output of temp sensor 
float vout1 ; // temp inc and new voltage produced
int LED = 13 ; 
int gasSensor; //concentration of smoke
int piezo = 7; // pin 7
void setup()
{
  pinMode(A0, INPUT); // gas sensor i/p
  pinMode(A2, INPUT); //temp
  pinMode(LED, OUTPUT); //alert
  pinMode(piezo, OUTPUT); //buzz
  Serial.begin(9600); //serial monitor activate
}
void loop()
{
  vout  =analogRead(A2); 
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
  if (gasSensor>=90)
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
  Serial.println();
  delay(1000);
}
               
  
