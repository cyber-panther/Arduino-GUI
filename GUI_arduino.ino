int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int operate;
int time_keep = 1;

void setup()
{
  pinMode(pin8, OUTPUT);  // Digital pin 08 set as output Pin
  pinMode(pin9, OUTPUT);  // Digital pin 09 set as output Pin
  pinMode(pin10, OUTPUT); // Digital pin 10 set as output Pin
  pinMode(pin11, OUTPUT); // Digital pin 11 set as output Pin

  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
    operate = Serial.parseInt();

    if (operate <= 10)
    {
      time_keep = operate;
    }
  }

  switch (operate)
  {
  case 111: // hardcoded value to turn robot left

    digitalWrite(pin8, LOW);
    digitalWrite(pin9, LOW);
    digitalWrite(pin10, HIGH);
    digitalWrite(pin11, LOW);

    break;

  case 222: // hardcoded value to turn robot right

    digitalWrite(pin8, HIGH);
    digitalWrite(pin9, LOW);
    digitalWrite(pin10, LOW);
    digitalWrite(pin11, LOW);

    break;

  case 333: // hardcoded value to move robot forward

    digitalWrite(pin8, HIGH);
    digitalWrite(pin9, LOW);
    digitalWrite(pin10, HIGH);
    digitalWrite(pin11, LOW);

    break;

  case 444: // hardcoded value to move robot backward

    digitalWrite(pin8, LOW);
    digitalWrite(pin9, HIGH);
    digitalWrite(pin10, LOW);
    digitalWrite(pin11, HIGH);

    break;

  case 555: // hardcoded value to stop robot

    digitalWrite(pin8, LOW);
    digitalWrite(pin9, LOW);
    digitalWrite(pin10, LOW);
    digitalWrite(pin11, LOW);

    break;
  }

  delay(time_keep * 1000);
  operate = 555;
}
