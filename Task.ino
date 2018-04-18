int echoPin = 8; 
int trigPin = 9; 
const int buttonPin = 3;
int buttonState = 0;         // переменная для хранения состояния кнопки
long int sum=0;

void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buttonPin, INPUT); 
} 
 
void loop() { 
  buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH) {
    int duration, mm; 
    sum=0;
    int i=0;
    while(i<20)
    {
      digitalWrite(trigPin, LOW); 
      delayMicroseconds(2); 
      digitalWrite(trigPin, HIGH); 
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW); 
      duration = pulseIn(echoPin, HIGH); 
      mm = duration / 5.8;
      delay(100);
      Serial.println(mm);
      if(mm>70)
      {
        sum=sum+mm;
        i++;
      }
    }
    sum=sum/20;
    Serial.print("Middle 'length' ");
    Serial.println(sum);
  }
  else {
  }

}
