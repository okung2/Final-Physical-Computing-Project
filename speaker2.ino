const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int MAX_DISTANCE = 450;
const int speaker2 = 8;
const long SOUND_SPEED = 34000;
const long TIMEOUT = (2 * MAX_DISTANCE * 1000000)/SOUND_SPEED;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  
  pinMode(speaker2, OUTPUT);
  digitalWrite(speaker2, LOW);
  
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
      tone(speaker2, 880);
    } else if(distance > 1 && distance <= 4) {
      tone(speaker2, 932);
    } else if(distance > 4 && distance <= 7) {
      tone(speaker2, 988);
    } else if(distance > 7 && distance <= 10) {
      tone(speaker2, 1047);
    } else if(distance > 10 && distance <= 15) {
      tone(speaker2, 1109);
    } else if(distance > 15 && distance <= 20) {
      tone(speaker2, 1175);
    } else if(distance > 20 && distance <= 25) {
      tone(speaker2, 1245);
    } else if(distance > 25 && distance <= 30) {
      tone(speaker2, 1319);
    } else if(distance > 30 && distance <= 35) {
      tone(speaker2, 1397);
    } else if(distance > 35 && distance <= 40) {
      tone(speaker2, 1480);
    } else if(distance > 40 && distance <= 45) {
      tone(speaker2, 1568);
    } else if(distance > 45 && distance <= 50) {
      tone(speaker2, 1661);
    } else if(distance > 50 && distance <= 60) {
      tone(speaker2, 1760);
    } else if(distance > 60 && distance <= 70) {
      tone(speaker2, 1865);
    } else if(distance > 70 && distance <= 80) {
      tone(speaker2, 1976);
    } else if(distance > 80 && distance <= 90) {
      tone(speaker2, 2093);
    } else if(distance > 90 && distance <= 100) {
      tone(speaker2, 2217);
    } else if(distance > 100 && distance <= 150) {
      tone(speaker2, 2349);
    } else if(distance > 150 && distance <= 200) {
      tone(speaker2, 2489);
    } else if(distance > 200 && distance <= 250) {
      tone(speaker2, 2637);
    } else if(distance > 250 && distance <= 300) {
      tone(speaker2, 2794);
    } else if(distance > 300 && distance <= 350) {
      tone(speaker2, 2960);
    } else if(distance > 350 && distance <= 400) {
      tone(speaker2, 3136);
    } else {
      tone(speaker2, 3322);
    }
  } else {
    Serial.println("No ping.");
    tone(speaker2, 3520);
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
