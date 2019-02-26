int IN1 = 5;  // Control de velocidad
int IN2 = 6;  // Motor
                      

void setup() 
{ 
    Serial.begin (9600);
    pinMode(IN2, OUTPUT);   
} 

void loop() 
{ 
    int potentiometerVal = analogRead(A0);
    Serial.println(potentiometerVal);
    activa_motor(potentiometerVal);
}

void activa_motor(int potValue)
{
    if (potValue < 512) {
      int mappedVal = map(potValue,0,512,0,255);
      // Adelante
      digitalWrite(IN2,HIGH);         
      analogWrite(IN1, mappedVal);   //Control de velocidad PWM
      delay(30); 
   } 
   else {
      // Reversa
      int mappedVal = map(potValue-512,0,512,0,255);
      digitalWrite(IN2,LOW);         
      analogWrite(IN1, mappedVal);   //Control de velocidad PWM
      delay(30); 
   }
}
