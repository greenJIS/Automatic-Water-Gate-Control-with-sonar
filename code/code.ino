/*
 * Project Name: Water gate control using Sonar Sensor
 * 
 * Prepared By: VP
 *              Roll: 1205xxx
 */


/*
 * Variables (GLOBAL)
 */
byte motor1Left = 2;
byte motor1Right = 3;

byte sonar1Trig = 14;
byte sonar1Echo = 15;

int gate1TH1 = 7;
int gate1TH2 = 10;

/*
 * Extra Functions On the CODE
 */
int sonarCheck(byte, byte);
void motorClock(byte,byte);
void motorAntiClock(byte,byte);

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1Left, OUTPUT);
  pinMode(motor1Right, OUTPUT);
  
  pinMode(sonar1Trig, OUTPUT);
  pinMode(sonar1Echo, INPUT);
}

void loop() {
  motorClock(motor1Left, motor1Right);
  delay(2000);
  motorAntiClock(motor1Left, motor1Right);
  delay(2000);
  /*
  if(sonarCheck(sonar1Trig, sonar1Echo)<gate1TH1){
    motorClock(motor1Left, motor1Right);
    delay(2000);
  }
  
  if(sonarCheck(sonar1Trig, sonar1Echo)>gate1TH2){
    motorClock(motor1Left, motor1Right);
    delay(2000);
  }*/
}

/*
 * Extra Functions Definations
 */
void motorClock(byte left,byte right){
  digitalWrite(left, HIGH);
  digitalWrite(right, LOW);
  delay(10);
}

void motorAntiClock(byte left,byte right){
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(10);
}

int sonarCheck(byte trigPin, byte echoPin){
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

