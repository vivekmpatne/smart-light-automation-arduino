const int relayPin = 8;
const int ledPin = 13;

void setup() {

  pinMode(relayPin, OUTPUT);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(relayPin, HIGH);

  digitalWrite(ledPin, LOW);

  Serial.println("VOICE CONTROL READY");
}

void loop() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');

    cmd.trim();

    if (cmd == "ON") {

      digitalWrite(relayPin, LOW);

      digitalWrite(ledPin, HIGH);

      Serial.println("LIGHT ON");
    }

    else if (cmd == "OFF") {

      digitalWrite(relayPin, HIGH);

      digitalWrite(ledPin, LOW);

      Serial.println("LIGHT OFF");
    }
  }
}