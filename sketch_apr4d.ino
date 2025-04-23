void setup() {
  Serial.begin(9600);
  
  // GSR Sensor Setup
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  
  // Flex Sensor Setup
  pinMode(3, OUTPUT);
}

void loop() {
  int gsrValue = analogRead(A2);  // Read GSR Sensor
  int flexValue = analogRead(A0); // Read Flex Sensor

  // GSR Sensor Logic
  digitalWrite(12, gsrValue > 200 ? HIGH : LOW);
  digitalWrite(8, gsrValue > 45 ? HIGH : LOW);
  digitalWrite(10, gsrValue > 100 ? HIGH : LOW);

  // Flex Sensor Logic
  flexValue = map(flexValue, 700, 900, 0, 255);
  analogWrite(3, flexValue);

  // Serial Output for Serial Plotter
  Serial.print("GSR: ");
  Serial.print(gsrValue);
  Serial.print("\t , \t");  // Tab separator for plotting multiple values
  Serial.print("Flex: ");
  Serial.println(flexValue);

  delay(100);
}