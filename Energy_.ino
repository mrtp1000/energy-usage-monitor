const int ledPin = 8;        // Pin connected to LED
const int buttonPin = 7;     // Pin connected to pushbutton

bool ledState = false;       // Tracks if LED is ON or OFF
bool lastButtonState = LOW;  // Stores previous button state
unsigned long onStart = 0;   // When the LED turned ON
unsigned long totalOnTime = 0;  // Total time LED has been ON

void setup() {
  pinMode(ledPin, OUTPUT);      // Set LED pin as OUTPUT
  pinMode(buttonPin, INPUT);    // Set button pin as INPUT
  Serial.begin(9600);           // Start Serial Monitor
}

void loop() {
  bool buttonState = digitalRead(buttonPin);  // Read current button state

  // If button is pressed (LOW → HIGH transition)
  if (buttonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;  // Toggle the LED state

    if (ledState) {
      onStart = millis();             // Record start time
      digitalWrite(ledPin, HIGH);     // Turn ON LED
    } else {
      totalOnTime += millis() - onStart;  // Add time LED was ON
      digitalWrite(ledPin, LOW);          // Turn OFF LED

      // Calculate energy used
      float hours = totalOnTime / 1000.0 / 3600.0;  // convert ms to hours
      float powerWatts = 5.0;                       // simulate 5W device
      float energyWh = hours * powerWatts;          // E = P × t

      // Display results
      Serial.print("LED ON Time: ");
      Serial.print(totalOnTime / 1000);
      Serial.println(" seconds");

      Serial.print("Simulated Energy Used: ");
      Serial.print(energyWh, 3);
      Serial.println(" Wh");

      totalOnTime = 0;  // Reset timer for next session
    }

    delay(200);  // debounce delay
  }

  lastButtonState = buttonState;  // Save current button state
}
