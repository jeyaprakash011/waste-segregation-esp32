# waste-segregation-esp32
Smart Waste Segregation System using ESP32 that automatically classifies wet, metal, and normal waste using sensors and a servo-controlled dumping mechanism.
# Smart Waste Segregation System using ESP32

## Overview
This project is an automated **Waste Segregation System** developed using **ESP32**. The system detects and separates waste into different categories such as **wet waste, metal waste, and normal waste** using multiple sensors.

The system improves waste management efficiency by automatically identifying the type of waste and directing it to the correct bin using a **servo-controlled gate mechanism**.

## Features
- Automatic waste detection using **IR sensor**
- Wet waste detection using **Moisture sensor**
- Metal waste detection using **Proximity sensor**
- Rotating bin system controlled by **DC motor**
- Waste dumping mechanism using **Servo motor**
- Buzzer alert for system actions
- Timer-based waste checking using ESP32 hardware timer

## Hardware Components
- ESP32
- Servo Motor
- DC Motor
- IR Sensor
- Moisture Sensor
- Proximity Sensor
- Position Sensor
- Buzzer
- Motor Driver (if used)
- Power Supply

## Working Principle

1. The **IR sensor** detects when waste is placed in the input area.
2. Once detected, the system checks the waste using:
   - Moisture Sensor → Detects **wet waste**
   - Proximity Sensor → Detects **metal waste**
3. If neither sensor is triggered, the waste is considered **normal waste**.
4. The **DC motor rotates the bin platform** to the correct waste category position.
5. The **servo motor opens the gate** to drop the waste into the appropriate bin.
6. After dumping, the gate closes and the system resets for the next waste.

## Waste Categories

| Waste Type | Detection Method |
|------------|-----------------|
| Wet Waste | Moisture Sensor |
| Metal Waste | Proximity Sensor |
| Normal Waste | Default condition |

## Pin Configuration

| Component | ESP32 Pin |
|----------|-----------|
| Servo Motor | 18 |
| IR Sensor | 19 |
| Moisture Sensor | 21 |
| Proximity Sensor | 5 |
| Position Sensor | 4 |
| Motor Control | 15 |
| Buzzer | 23 |

## Project Images

### System Setup
![Setup](images/setup.jpg)

### Hardware Circuit
![Circuit](images/circuit.jpg)

### Working Model
![Working](images/working1.jpg)

## Future Improvements
- Add **IoT monitoring**
- Waste level detection
- Mobile application integration
- Smart bin fill alerts

## Author
Developed as an **Embedded Systems / IoT Project using ESP32**.
