void setup() {
  for (int i = 0; i <= 19; i++) {
    pinMode(i, OUTPUT);
  }
}
                                                 
int green4 = 0; 
int red4 = 0;
int blue4 = 0;
int green5 = 0; 
int red5 = 0; 
int blue5 = 0; 

void loop() {
  for (int ground = 0; ground <= 13; ground++) {
    digitalWrite(ground, LOW);
  }

  for (int i = 0; i <= 25; i++) {

    red4 = random(0, 255);
    blue4 = random(0, 255);
    green4 = random(0, 255);
    red5 = random(0, 255);
    blue5 = random(0, 255);
    green5 = random(0, 255);

    analogWrite(A0, green4);
    analogWrite(A1, red4);
    analogWrite(A2, blue4);

    analogWrite(A3, green5);
    analogWrite(A4, red5);
    analogWrite(A5, blue5);

    delay(1000);
  }
}
