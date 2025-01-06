// 4x4x4 LED Cube Wave and Spin code - Written by Ryan T - 2023.04.20
/* To create a wave and spin pattern on the 4x4 cube. 
This is done by powering the LEDs in columns and grounding in layers to
 control which LEDs are lit at a time and thus create interesting and complex patterns.
 (A0 = pin 14, A1 = pin 15, A2 = pin 16, A3 = pin 17, A4 = pin 18, A5 = pin 19)
*/

void setup() {
 for (int i = 0; i <= 19; i++) {
 pinMode(i, OUTPUT); // PINS are set as output
 }
}

//ARRAYS
int wave1[7][7] {{1}, {2,5,6}, {3,7,9,10,11}, {4,8,12,13,14,15,16}, {8,12,14,15,16}, {12,15,16}, {16}}; //Pin 0 - 15 wave, bumped one value to deal with autofill
int wave2[7][7] {{16}, {15,12,11}, {14,10,8,7,6}, {13,9,5,4,3,2,1}, {9,5,3,2,1}, {5,2,1}, {1}}; //Pin 15 - 0 wave, bumped one value to deal with autofill
int wave3[7][7] {{4}, {3,7,8}, {2,6,10,11,12}, {1,5,9,13,14,15,16}, {5,9,13,14,15}, {9,13,14}, {13}}; //Pin 3 - 12 wave, bumped one value to deal with autofill
int wave4[7][7] {{13}, {14,10,9}, {15,11,7,6,5}, {16,12,8,4,3,2,1}, {12,8,4,3,2}, {8,4,3}, {4}}; //Pin 12 - 13 wave, bumped one value to deal with autofill

int spin[12][2] = {{5, 0}, {5, 4}, {9, 8}, {9, 12}, {9, 13}, {10, 14}, {10, 15}, {10, 11}, {6, 7}, {6, 3}, {6, 2}, {5, 1}}; // looping spin progression

void loop() { 

  //WAVE patterns
  for (int v = 1; v <= 2; v++) {
  
    int flip1 = 1; //This variable is used to determine the order of the pattern progression
    int time = 75; //This variable represents the amount of delay in milliseconds between the power 'on' and power 'off' phases of the wave. ie. the speed of the wave.

    //This for-loop holds all the running code and dictates the amount of cycles the waves run for:
    for (int n = 1; n < 9; n++) {

      //Switch(n) controls the grounded layers. This allows the code to switch which layer is enabled per cycle
      switch (n) {
        case 1:
        //Layer 1 
        digitalWrite(A2, LOW); // layer 1 of cube is enabled
        digitalWrite(A3, HIGH); // layer 2 of cube is disabled
        digitalWrite(A4, HIGH); // layer 3 of cube is disabled
        digitalWrite(A5, HIGH); // layer 4 of cube is disabled
        break;

        case 2:
        //Layer 2 
        digitalWrite(A2, HIGH); // layer 1 of cube is disabled
        digitalWrite(A3, LOW); // layer 2 of cube is enabled
        digitalWrite(A4, HIGH); // layer 3 of cube is disabled
        digitalWrite(A5, HIGH); // layer 4 of cube is disabled
        break;

        case 3:
        //Layer 3 
        digitalWrite(A2, HIGH); // layer 1 of cube is disabled
        digitalWrite(A3, HIGH); // layer 2 of cube is disabled
        digitalWrite(A4, LOW); // layer 3 of cube is enabled
        digitalWrite(A5, HIGH); // layer 4 of cube is disabled
        break;

        case 4:
        //Layer 4
        digitalWrite(A2, HIGH); // layer 1 of cube is disabled
        digitalWrite(A3, HIGH); // layer 2 of cube is disabled
        digitalWrite(A4, HIGH); // layer 3 of cube is disabled
        digitalWrite(A5, LOW); // layer 4 of cube is enabled
        break;

        case 5:
        //ALL LAYERS
        digitalWrite(A2, LOW); // layer 1 of cube is enabled
        digitalWrite(A3, LOW); // layer 2 of cube is enabled
        digitalWrite(A4, LOW); // layer 3 of cube is enabled
        digitalWrite(A5, LOW); // layer 4 of cube is enabled
        break;

        default:
        //ALL LAYERS
        digitalWrite(A2, LOW); // layer 1 of cube is enabled
        digitalWrite(A3, LOW); // layer 2 of cube is enabled
        digitalWrite(A4, LOW); // layer 3 of cube is enabled
        digitalWrite(A5, LOW); // layer 4 of cube is enabled
        break;
      }

      //Switch(flip1) controls the pattern progression, ie. it determines which wave array is called on which alters the mapped direction of the wave.
      switch(flip1) {

        //pin 0-15 Wave
        case 1:
        //for (int x = 0; x < 7; x++) loops through all the 2d arrays which represents the phases of the wave
        for (int x = 0; x < 7; x++) {
          //for (int a = 0; a < 7; a++) loops through all the mapped pin values within the 2d arrays
          for (int a = 0; a < 7; a++) {
            digitalWrite(wave1[x][a] - 1, HIGH); //This powers on all the mapped pins in the array, "x" represents the phase of the wave/the 2d array called on, and "a" represents the pin value within the 2d arrray.
            //The pin value called on must be pushed 1 value higher and then subtracted from because Arduino code will fill arrays with 0s if they do not have the dictated maximum
            //This means that pin 0 will be powered on and off an uneven amount of time ruining the wave. To get around this we ensure that all the values are pushed by 1 to eliminate 0 values
            //When subtracted from all the added/irrelevant 0s become -1 which isn't a pin that the arduino cna read. ie. they are rendered meaningless.
          }
          delay(time); //Delay between powering on and powering off. ie the amount of time each LED stays lit
          for (int b = 0; b < 7; b++) { //Inverse of previous for-loop to power off all the mapped pins.
            digitalWrite(wave1[x][b] - 1, LOW);
          }
        }
        flip1 += 1; // this changes which wave array is called on in the next cycle
        break;

        //pin 15 - 0 wave
        case 2:
        for (int x = 0; x < 7; x++) {
          for (int a = 0; a < 7; a++) {
            digitalWrite(wave2[x][a] - 1, HIGH);
          }
          delay(time);
          for (int b = 0; b < 7; b++) {
            digitalWrite(wave2[x][b] - 1, LOW);
          }
        }
        flip1 += 1;
        break;

        //pin 3 - 12 wave
        case 3:
        //for (int x = 0; x < 7; x++) loops through all the 2d arrays which represents the phases of the wave
        for (int x = 0; x < 7; x++) {
          for (int a = 0; a < 7; a++) {
            digitalWrite(wave3[x][a] - 1, HIGH);
          }
          delay(time);
          for (int b = 0; b < 7; b++) {
            digitalWrite(wave3[x][b] - 1, LOW);
          }
        }
        flip1 += 1;
        break;

        // pin 12 - 3 wave
        case 4:
        //for (int x = 0; x < 7; x++) loops through all the 2d arrays which represents the phases of the wave
        for (int x = 0; x < 7; x++) {
          for (int a = 0; a < 7; a++) {
            digitalWrite(wave4[x][a] - 1, HIGH);
          }
          delay(time);
          for (int b = 0; b < 7; b++) {
            digitalWrite(wave4[x][b] - 1, LOW);
          }
        }
        flip1 -= 3;
        break;
      }
    }
  }



  //SPIN CODE
  //This for-loop contains all the code to ensure the full code runs 3 times
  for (int o = 1; o <= 2; o += 1) {

    int thing = 50; //This variabled represents the amount of delay in milliseconds between the "on" and "off" stages of the LED and consequently, the speed of the spinning

    //This for loop is used in conjunction with an if and else if statement to change the direction of the spin.
    for (int flip = 1; flip < 3; flip++) {
      //This for-loop contains all the code and is used to create a full cycle of 6 phases
      for (int i = 1; i <= 6; i++) {
        //This switch statement uses the cycle counter 'i' to change which layers are grounded/enabled and which are powered/disabled
        switch(i) {
          case 1:
          digitalWrite(A5, LOW); //Layer 1 grounded
          digitalWrite(A4, HIGH); //Layer 2 powered
          digitalWrite(A3, HIGH); //Layer 3 powered
          digitalWrite(A2, HIGH); //Layer 4 powered
          break;

          case 2:
          digitalWrite(A5, HIGH); //Layer 1 powered
          digitalWrite(A4, LOW); //Layer 2 grounded
          digitalWrite(A3, HIGH); //Layer 3 powered
          digitalWrite(A2, HIGH); //Layer 4 powered
          break;

          case 3:
          digitalWrite(A5, HIGH); //Layer 1 powered
          digitalWrite(A4, HIGH); //Layer 2 powered
          digitalWrite(A3, LOW); //Layer 3 grounded
          digitalWrite(A2, HIGH); //Layer 4 powered
          break;

          case 4:
          digitalWrite(A5, HIGH); //Layer 1 powered
          digitalWrite(A4, HIGH); //Layer 2 powered
          digitalWrite(A3, HIGH); //Layer 3 powered
          digitalWrite(A2, LOW); //Layer 4 grounded
          break;

          default:
          digitalWrite(A5, LOW); //Layer 1 grounded
          digitalWrite(A4, LOW); //Layer 2 grounded
          digitalWrite(A3, LOW); //Layer 3 grounded
          digitalWrite(A2, LOW); //Layer 4 grounded
          break;
        }

        //this for-loop ensures that the code runs through every single phase of the spin
        for (int x = 0; x < 12; x++) {
          //Clockwise spin:
          if (flip == 1) {
            digitalWrite(spin[x][0], HIGH); // Powers on the 1st pin of the 2d array at 'x'
            digitalWrite(spin[x][1], HIGH); // Powers on the 2nd pin of the 2d array at 'x'
            delay(thing);
            digitalWrite(spin[x][0], LOW); // Powers off the 1st pin of the 2d array at 'x'
            digitalWrite(spin[x][1], LOW); // Powers off the 2nd pin of the 2d array at 'x'
          //counter clockwise spin:
          } else if(flip == 2) {
            digitalWrite(spin[11 - x][0], HIGH); // Powers on the 1st pin of the 2d array at '11 - x'
            digitalWrite(spin[11 - x][1], HIGH); // Powers on the 2nd pin of the 2d array at '11 - x'
            delay(thing);
            digitalWrite(spin[11 - x][0], LOW); // Powers off the 1st pin of the 2d array at '11 - x'
            digitalWrite(spin[11 - x][1], LOW); // Powers off the 2nd pin of the 2d array at '11 - x'
          }
        }
      }
    }
  }
}

