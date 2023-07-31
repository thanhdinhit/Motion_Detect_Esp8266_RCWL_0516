int relay_pin = D4;
int output_sensor_pin = D6;

bool detection = false;
int flg = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
  pinMode(output_sensor_pin, INPUT);
}

void loop() {
  detection = digitalRead(output_sensor_pin);
  show_status_detect(detection);
  
  if ((detection > 0) && (flg == 0))
  {
    digitalWrite(relay_pin, LOW);
    flg = 1;
  }
  if (detection == 0)
  {
    digitalWrite(relay_pin, HIGH);
    flg = 0;
  }
}

void show_status_detect(int para_detect)
{
  if (para_detect > 0) {
    Serial.println("Motion Detect !!!");
  } else {
    Serial.println("NO Motion Detect !!!");
  }
}
