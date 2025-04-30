# energy-usage-monitor

This Arduino project simulates energy monitoring by toggling an LED using a pushbutton and calculating the simulated energy used.

## 🔧 Features
- Tracks how long an LED is turned on
- Simulates energy usage in watt-hours (Wh)
- Prints results to Serial Monitor
- Simple circuit using an LED, button, and resistors

## ⚡ How It Works
When the button is pressed, the LED turns on and a timer starts. When pressed again, the LED turns off and the elapsed time is used to calculate energy use assuming a 5W load.

## 🧰 Components Used
- Arduino UNO
- LED
- 220Ω resistor
- Pushbutton
- 10kΩ pull-down resistor
- Breadboard & jumper wires
