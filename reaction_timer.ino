const int buttonPin = 2;
unsigned long startTime;
unsigned long endTime;
bool waiting = false;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Drücke den Taster zum Starten...");
}

void loop() {
  if (digitalRead(buttonPin) == HIGH && !waiting) {
    startTime = millis();
    waiting = true;
    Serial.println("Gestartet! Drücke erneut...");
    delay(500);
  }

  if (digitalRead(buttonPin) == HIGH && waiting) {
    endTime = millis();
    Serial.print("Reaktionszeit: ");
    Serial.print(endTime - startTime);
    Serial.println(" ms");
    waiting = false;
    delay(1000);
  }
}
