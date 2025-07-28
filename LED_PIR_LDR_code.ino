#define LDR A0
#define PIR1 4
#define PIR2 6
#define PIR3 7
#define PIR4 8
#define PIR5 12
#define LED1 3
#define LED2 5
#define LED3 9
#define LED4 10
#define LED5 11

void setup() {
  pinMode (A0, INPUT);
  pinMode (4, INPUT);
  pinMode (6, INPUT);
  pinMode (7, INPUT);
  pinMode (8, INPUT);
  pinMode (12, INPUT);
  pinMode (3, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);

}

void loop() {
  int status_ldr = digitalRead(LDR);
  int status_pir1 = digitalRead(PIR1);
  int status_pir2 = digitalRead(PIR2);
  int status_pir3 = digitalRead(PIR3);
  int status_pir4 = digitalRead(PIR4);
  int status_pir5 = digitalRead(PIR5);
 
  if (status_ldr ==1 && status_pir1 ==1 )
  {
   digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }

 
  if (status_ldr ==1 && status_pir2 ==1 )
  {
   digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }

  if (status_ldr ==1 && status_pir3 ==1 )
  {
   digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }

  if (status_ldr ==1 && status_pir4 ==1 )
  {
   digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }

  if (status_ldr ==1 && status_pir5 ==1 )
  {
   digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
  }

}
