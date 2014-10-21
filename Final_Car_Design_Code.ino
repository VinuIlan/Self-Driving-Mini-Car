//Variables

const int sensorOne = 2;
const int sensorTwo = 3;
const int sensorThree = 4;
const int sensorFour = 5;
const int sensorFive = 6; //sensor 5 is in analog A0
const int sensorSix = 7;
const int sensorSeven = 8;

const int outputLeft = 10;
const int outputRight = 11;


const int runMotor = 125;//125
const int stopMotor = 0;
const float white = 838.0;
const float black = 200.0;
const float colorLow = 409.0;
const float colorHigh = 716.0;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Defining Inputs
  pinMode(sensorOne, INPUT);
  pinMode(sensorTwo, INPUT);
  pinMode(sensorThree, INPUT);
  pinMode(sensorFour, INPUT);
  pinMode(sensorFive, INPUT);
  pinMode(sensorSix, INPUT);
  pinMode(sensorSeven, INPUT);
 
  //Defining Outputs
  pinMode(outputLeft, OUTPUT);
  pinMode(outputRight, OUTPUT);
}

 
void loop()
{
  // put your main code here, to run repeatedly:

 //Stop Sequence
 if (digitalRead(sensorOne) == HIGH && digitalRead(sensorTwo) == HIGH && digitalRead(sensorThree) == HIGH && digitalRead(sensorFour) == HIGH && digitalRead(sensorSix) == HIGH
     && digitalRead(sensorSeven) == HIGH)
 {
    analogWrite(outputLeft, stopMotor);
    analogWrite(outputRight, stopMotor);
 }
 else
 {
   //Split Sequence
   if (digitalRead(sensorOne) == HIGH && digitalRead(sensorTwo) == HIGH && digitalRead(sensorFour) == HIGH
            && digitalRead(sensorSix) == HIGH && digitalRead(sensorThree) == LOW && digitalRead(sensorSeven) == LOW)
   {
     if (analogRead(A0) >= white) //reads white
     {
       analogWrite(outputLeft, stopMotor);
       analogWrite(outputRight, runMotor);
     }
     else if (analogRead(A0) >= colorLow && analogRead(A0) <= colorHigh) //reads color
     {
       analogWrite(outputLeft, runMotor);
       analogWrite(outputRight, stopMotor);
     }
   }
  
   //Navigation Sequence
   else
   {
      if (digitalRead(sensorOne) == LOW && digitalRead(sensorTwo) == LOW && digitalRead(sensorFour) == HIGH
          && digitalRead(sensorSix) == HIGH)
      {
        analogWrite(outputLeft, runMotor);
        analogWrite(outputRight, runMotor);
      }
      else if ((digitalRead(sensorOne) == HIGH && digitalRead(sensorTwo) == LOW) || (digitalRead(sensorFour) == HIGH
               && digitalRead(sensorSix) == LOW))
      {
        analogWrite(outputLeft, stopMotor);
        analogWrite(outputRight, runMotor);
      }
      else if ((digitalRead(sensorOne) == LOW && digitalRead(sensorTwo) == HIGH) || (digitalRead(sensorFour) == LOW
               && digitalRead(sensorSix) == HIGH))
      {
        analogWrite(outputLeft, runMotor);
        analogWrite(outputRight, stopMotor);
      }
   }
 }
}


