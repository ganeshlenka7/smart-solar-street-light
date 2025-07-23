int ldr = A0;         // LDR connected to analog pin A0
int pir = 2;          // PIR sensor connected to digital pin 2
int relay = 3;        // Relay module connected to digital pin 3

// Threshold for darkness 
int ldrThreshold = 600;

void setup() {
  pinMode(ldr,INPUT);
  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW); // Light OFF initially
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldr);
  int pirValue = digitalRead(pir);
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print("PIR: ");
  Serial.println(pirValue);
  if (ldrValue > ldrThreshold && pirValue == HIGH)
   {
    digitalWrite(relay, LOW); // Turn ON the light
    delay(10000);                  // Keep light ON for 1 minute
    digitalWrite(relay, HIGH);  // Turn OFF the light
  } else {
    digitalWrite(relay, HIGH);  // Ensure light stays OFF
  }

  delay(100);
}
