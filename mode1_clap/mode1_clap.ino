const int soundPin = 2;
const int relayPin = 8;
const int ledPin = 13;

bool lightState = false;

unsigned long lastTrigger = 0;

const int debounceDelay = 500;

void setup() {

  pinMode(soundPin, INPUT);

  pinMode(relayPin, OUTPUT);

  pinMode(ledPin, OUTPUT);

  digitalWrite(relayPin, HIGH);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);

  Serial.println("MODE 1 READY");
}

void loop() {

  int sound = digitalRead(soundPin);

  if (sound == HIGH &&
      millis() - lastTrigger > debounceDelay) {

    lightState = !lightState;

    if (lightState) {

      digitalWrite(relayPin, LOW);

      digitalWrite(ledPin, HIGH);

      Serial.println("LIGHT ON");
    }

    else {

      digitalWrite(relayPin, HIGH);

      digitalWrite(ledPin, LOW);

      Serial.println("LIGHT OFF");
    }

    lastTrigger = millis();
  }
}