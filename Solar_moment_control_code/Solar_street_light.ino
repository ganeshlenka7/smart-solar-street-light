#define LDR_EAST A0     // East_facing LDR
#define LDR_WEST A1     // West_facing LDR

#define RELAY_EAST 8   // Relay controlling East motor(in1)
#define RELAY_WEST 9    // Relay controlling West motor(in2)

int thresholdDiff = 350;  // Minimum difference to move panel

void setup() {
  pinMode(RELAY_EAST, OUTPUT);
  pinMode(RELAY_WEST, OUTPUT);

  digitalWrite(RELAY_EAST, HIGH);  // Relays OFF initially (active LOW)
  digitalWrite(RELAY_WEST, HIGH);

  Serial.begin(9600);
}

void loop() {
  int eastValue = analogRead(LDR_EAST);  // Higher when more sunlight
  int westValue = analogRead(LDR_WEST);

  Serial.print("East: "); Serial.print(eastValue);
  Serial.print(" | West: "); Serial.print(westValue);
  Serial.print(" | Diff: "); Serial.println(abs(eastValue - westValue));

  if (abs(eastValue - westValue) < thresholdDiff) {
    // Balanced light -> Stop movement
    digitalWrite(RELAY_EAST, HIGH);
    digitalWrite(RELAY_WEST, HIGH);
    Serial.println("Balanced - No Movement");
  } 
  else if (eastValue > westValue) {
    // East is brighter -> move West (RELAY_WEST ON)
    digitalWrite(RELAY_EAST, HIGH);   // OFF
    digitalWrite(RELAY_WEST, LOW);    // ON
    Serial.println("East brighter → Turning West");
  } 
  else {
    // West is brighter -> move East (RELAY_EAST ON)
    digitalWrite(RELAY_EAST, LOW);    // ON
    digitalWrite(RELAY_WEST, HIGH);   // OFF
    Serial.println("West brighter → Turning East");
  }

  delay(500);
}