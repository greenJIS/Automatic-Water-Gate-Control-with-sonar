/*
 * Project Name: Water gate control using Sonar Sensor
 * 
 */


/*
 * Variables (GLOBAL)
 */
byte motor1Left = 2;
byte motor1Right = 3;
byte motor2Left = 4;
byte motor2Right = 5;
byte motor3Left = 6;
byte motor3Right = 7;

byte sonar1Trig = 14;
byte sonar1Echo = 15;
byte sonar2Trig = 16;
byte sonar2Echo = 17;
byte sonar3Trig = 18;
byte sonar3Echo = 19;

bool motor1PresentState = false;
bool motor1PriviousState = false;
bool motor2PresentState = false;
bool motor2PriviousState = false;
bool motor3PresentState = false;
bool motor3PriviousState = false;

int TH = 14;

int motor1Delay = 2000;
int motor2Delay = 2000;
int motor3Delay = 2000;

/*
 * Extra Functions On the CODE
 */
int sonarCheck(byte, byte);
void motorClock(byte,byte,int);
void motorAntiClock(byte,byte,int);

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1Left, OUTPUT);
  pinMode(motor1Right, OUTPUT);
  pinMode(motor2Left, OUTPUT);
  pinMode(motor2Right, OUTPUT);
  pinMode(motor3Left, OUTPUT);
  pinMode(motor3Right, OUTPUT);
  
  pinMode(sonar1Trig, OUTPUT);
  pinMode(sonar1Echo, INPUT);
  pinMode(sonar2Trig, OUTPUT);
  pinMode(sonar2Echo, INPUT);
  pinMode(sonar3Trig, OUTPUT);
  pinMode(sonar3Echo, INPUT);
}

void loop() {
  if(sonarCheck(sonar1Trig, sonar1Echo)<TH){
    motor1PresentState = true;
  }
  else{
    motor1PresentState = false;
  }
  
  if(sonarCheck(sonar2Trig, sonar2Echo)<TH){
    motor2PresentState = true;
  }
  else{
    motor2PresentState = false;
  }
  
  if(sonarCheck(sonar3Trig, sonar3Echo)<TH){
    motor3PresentState = true;
  }
  else{
    motor3PresentState = false;
  }

  
  if(motor1PresentState!=motor1PriviousState && motor1PresentState){
    motorClock(motor1Left, motor1Right, motor1Delay);
  }
  else if(motor1PresentState!=motor1PriviousState && !motor1PresentState){
    motorClock(motor1Left, motor1Right, motor1Delay);
  }
  
  if(motor2PresentState!=motor2PriviousState && motor2PresentState){
    motorClock(motor2Left, motor2Right, motor2Delay);
  }
  else if(motor2PresentState!=motor2PriviousState && !motor2PresentState){
    motorClock(motor2Left, motor2Right, motor2Delay);
  }
  
  if(motor3PresentState!=motor3PriviousState && motor3PresentState){
    motorClock(motor3Left, motor3Right, motor3Delay);
  }
  else if(motor3PresentState!=motor3PriviousState && !motor3PresentState){
    motorClock(motor3Left, motor3Right, motor3Delay);
  }

  
  motor1PriviousState = motor1PresentState;
  motor2PriviousState = motor2PresentState;
  motor3PriviousState = motor3PresentState;
}

/*
 * Extra Functions Definations
 */
void motorClock(byte left,byte right, int t){
  digitalWrite(left, HIGH);
  digitalWrite(right, LOW);
  delay(t);
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
} 

void motorAntiClock(byte left,byte right, int t){
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(t);
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
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

