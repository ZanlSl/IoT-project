int ledPin = 13;
int mcrbit = 1;
int motionsen = 0;
int Left = 2;
int Right = 3;
int Spd = 4;
int btn = 5;
int val = LOW;


void setup() {
  pinMode(ledPin, OUTPUT);    
  pinMode(btn, INPUT); 
  pinMode(mcrbit, INPUT);
  pinMode(motionsen, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(Left, OUTPUT);
  pinMode(Right, OUTPUT);
  pinMode(Spd, OUTPUT);
  Serial.begin(9600);
}



void loop() {

    if ((digitalRead(btn)) == HIGH) {
        if ((digitalRead(motionsen)) == HIGH && (digitalRead(mcrbit)) == LOW) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(100);
        }
        else {
          digitalWrite(LED_BUILTIN, LOW);
          delay(100);
        } 

        
        if ((digitalRead(mcrbit)) == HIGH && val == HIGH) {
          digitalWrite(Left, HIGH);
          digitalWrite(Right, LOW);
          analogWrite(Spd, 150);
          digitalWrite(Left, LOW);
          delay(1000);
          int val = LOW;
        }
        if ((digitalRead(mcrbit)) == LOW && val == LOW) {
          digitalWrite(Left, HIGH);
          digitalWrite(Right, LOW);
          analogWrite(Spd, 150);
          digitalWrite(Left, LOW);
          delay(1000);
          int val = HIGH;
        }
    }
    else if ((digitalRead(btn)) == LOW && val == HIGH) {
        digitalWrite(Left, HIGH);
        digitalWrite(Right, LOW);
        analogWrite(Spd, 150);
        digitalWrite(Left, LOW);
        delay(1000);
        int val = LOW;
    }
}
