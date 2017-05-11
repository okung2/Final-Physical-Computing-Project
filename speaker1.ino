const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int MAX_DISTANCE = 450;
const int speaker = 8;
const long SOUND_SPEED = 34000;
const long TIMEOUT = (2 * MAX_DISTANCE * 1000000)/SOUND_SPEED;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(speaker, OUTPUT);
  digitalWrite(speaker, LOW);
 
  
  pinMode(ECHO_PIN, INPUT);
}

void loop()
{
  long duration = ping_sonar(); 
  if (duration > 0) {
    float distance = (duration * 1e-6 * SOUND_SPEED) / 2;

    //Serial.print("Ping: ");
    //Serial.print(duration);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    if(distance <= 1) {
      tone(speaker, 220);
    } else if(distance > 1 && distance <= 4) {
      tone(speaker, 233);
    } else if(distance > 4 && distance <= 7) {
      tone(speaker, 247);
    } else if(distance > 7 && distance <= 10) {
      tone(speaker, 262);
    } else if(distance > 10 && distance <= 15) {
      tone(speaker, 277);
    } else if(distance > 15 && distance <= 20) {
      tone(speaker, 294);
    } else if(distance > 20 && distance <= 25) {
      tone(speaker, 311);
    } else if(distance > 25 && distance <= 30) {
      tone(speaker, 330);
    } else if(distance > 30 && distance <= 35) {
      tone(speaker, 349);
    } else if(distance > 35 && distance <= 40) {
      tone(speaker, 370);
    } else if(distance > 40 && distance <= 45) {
      tone(speaker, 392);
    } else if(distance > 45 && distance <= 50) {
      tone(speaker, 415);
    } else if(distance > 50 && distance <= 60) {
      tone(speaker, 440);
    } else if(distance > 60 && distance <= 70) {
      tone(speaker, 466);
    } else if(distance > 70 && distance <= 80) {
      tone(speaker, 494);
    } else if(distance > 80 && distance <= 90) {
      tone(speaker, 523);
    } else if(distance > 90 && distance <= 100) {
      tone(speaker, 554);
    } else if(distance > 100 && distance <= 150) {
      tone(speaker, 587);
    } else if(distance > 150 && distance <= 200) {
      tone(speaker, 622);
    } else if(distance > 200 && distance <= 250) {
      tone(speaker, 659);
    } else if(distance > 250 && distance <= 300) {
      tone(speaker, 698);
    } else if(distance > 300 && distance <= 350) {
      tone(speaker, 740);
    } else if(distance > 350 && distance <= 400) {
      tone(speaker, 784);
    } else {
      tone(speaker, 831);
    }
  } else {
    Serial.println("No ping.");
    tone(speaker, 550);
  }

 delay(100);
}

long ping_sonar(void)
{
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH, TIMEOUT);
}
