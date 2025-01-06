void setup() {
  for (int i = 1; i <= 10; i++) {
    pinMode(i, OUTPUT); // PINS 2-10 are set as output
  }
  pinMode(A0, OUTPUT); // PIN A0 set as output
  pinMode(A1, OUTPUT); // PIN A1 set as output
  pinMode(A2, OUTPUT); // PIN A2 set as output
}


void loop() {

  //WAVE
 for (int i = 1; i <= 7; i++) {
   switch(i) {
      case 1:
      digitalWrite(A0, LOW); // layer 1 of cube is enabled
      digitalWrite(A1, HIGH); // layer 2 of cube is disabled
      digitalWrite(A2, HIGH); // layer 3 of cube is disabled
      break;
 
      case 2:
      digitalWrite(A0, LOW); // layer 1 of cube is enabled
      digitalWrite(A1, LOW); // layer 2 of cube is enabled
      digitalWrite(A2, HIGH); // layer 3 of cube is disabled
      break;
 
      case 3:
      digitalWrite(A0, HIGH); // layer 1 of cube is disabled
      digitalWrite(A1, LOW); // layer 2 of cube is enabled
      digitalWrite(A2, HIGH); // layer 3 of cube is disabled
      break;
 
      case 4:
      digitalWrite(A0, HIGH); // layer 1 of cube is disabled
      digitalWrite(A1, LOW); // layer 2 of cube is enabled
      digitalWrite(A2, LOW); // layer 3 of cube is enabled
      break;

      case 5:
      digitalWrite(A0, HIGH); // layer 1 of cube is disabled
      digitalWrite(A1, HIGH); // layer 2 of cube is disabled
      digitalWrite(A2, LOW); // layer 3 of cube is enabled
      break;

      default:
      digitalWrite(A0, LOW); // layer 1 of cube is disabled
      digitalWrite(A1, LOW); // layer 2 of cube is disabled
      digitalWrite(A2, LOW); // layer 3 of cube is enabled
      break;
    }

    //ROUND 1
    digitalWrite(1, HIGH);
    delay(150);
    digitalWrite(1, LOW);

    //ROUND 2
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(150);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    //ROUND 3
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(150);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    
    //ROUND 4
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(150);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    
    //ROUND 5
    digitalWrite(9, HIGH);
    delay(150);
    digitalWrite(9, LOW);
    
    //ROUND 6
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    delay(150);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    
    //ROUND 7
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    delay(150);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    
    //ROUND 8
    digitalWrite(4, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    delay(150);
    digitalWrite(4, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
  }   

  //SPINNY
  for (int x = 1; x <= 6; x++) {
    switch(x) {
      case 1:
      digitalWrite(A0, LOW); // layer 1 of cube is enabled
      digitalWrite(A1, HIGH); // layer 2 of cube is disabled
      digitalWrite(A2, HIGH); // layer 3 of cube is disabled
      break;

      case 2:
      digitalWrite(A0, HIGH); // layer 1 of cube is enabled
      digitalWrite(A1, LOW); // layer 2 of cube is enabled
      digitalWrite(A2, HIGH); // layer 3 of cube is disabled
      break;

      case 3:
      digitalWrite(A0, HIGH); // layer 1 of cube is disabled
      digitalWrite(A1, HIGH); // layer 2 of cube is enabled
      digitalWrite(A2, LOW); // layer 3 of cube is enabled
      break;

      default:
      digitalWrite(A0, LOW); // layer 1 of cube is disabled
      digitalWrite(A1, LOW); // layer 2 of cube is disabled
      digitalWrite(A2, LOW); // layer 3 of cube is enabled
      break;
    }


    //ROUND 1
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);


    //ROUND 2
    // digitalWrite(2, HIGH);
    // digitalWrite(1, HIGH);
    // delay(100);
    // digitalWrite(2, LOW);
    // digitalWrite(1, LOW);


    //ROUND 3
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);


    //ROUND 4
    digitalWrite(6, HIGH);
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    digitalWrite(3, LOW);


    //ROUND 5
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);


    //ROUND 6
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);


    //ROUND 7
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);


    //ROUND 8
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);

    //ROUND 9
    digitalWrite(1, HIGH);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    digitalWrite(4, LOW);
  }

  //IN POP
  for (int i = 1; i <= 5; i++) {
    switch(i) {
      case 1:
      digitalWrite(A0, LOW); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;

      case 2:
      digitalWrite(A0, HIGH); // disable layer 1
      digitalWrite(A1, LOW); // enable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;

      case 3:
      digitalWrite(A0, HIGH); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, LOW); // disable layer 3
      break;

      case 4:
      digitalWrite(A0, LOW); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, LOW); // disable layer 3
      break;

      default:
      digitalWrite(A0, HIGH); // enable layer 1
      digitalWrite(A1, HIGH); // disable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;
    }

    digitalWrite(1, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(150);
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);


    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(150);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);


    digitalWrite(5, HIGH);
    delay(150);
    digitalWrite(5, LOW);
  }

  //OUT POP
  for (int x = 1; x <= 5; x++){

    switch(x) {
      case 1:
      digitalWrite(A0, LOW); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;

      case 2:
      digitalWrite(A0, HIGH); // disable layer 1
      digitalWrite(A1, LOW); // enable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;

      case 3:
      digitalWrite(A0, HIGH); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, LOW); // disable layer 3
      break;

      case 4:
      digitalWrite(A0, LOW); // enable layer 1
      digitalWrite(A1, LOW); // disable layer 2
      digitalWrite(A2, LOW); // disable layer 3
      break;

      default:
      digitalWrite(A0, HIGH); // enable layer 1
      digitalWrite(A1, HIGH); // disable layer 2
      digitalWrite(A2, HIGH); // disable layer 3
      break;
    }

    digitalWrite(5, HIGH);
    delay(150);
    digitalWrite(5, LOW);


    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(150);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);


    digitalWrite(1, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(150);
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
  }
}

