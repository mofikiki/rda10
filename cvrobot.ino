
int ENA = 3;
int ENB = 11;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
String data;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    data = Serial.readString();
    Serial.println(data);

      if (data == "f") {
      forward(110);
    }
    else if (data == "b") {
      reverse(110);
    }
    else if (data == "r") {
      turn_right(110);
    }
    else if (data == "l") {
      turn_left(110);
    }
    else if (data == "s") {
      brake();
    }
  }
}
void turn_right(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed / 2);
  analogWrite(ENB, Speed);
}

void turn_left(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed / 2);
}

void brake() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void forward(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}

void reverse(int Speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}
