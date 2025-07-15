# ESP32 Fire, Gas, and Temperature Alert System

This project uses an ESP32 to detect:
- 🔥 Fire (Flame sensor)
- 💨 Gas (MQ2)
- 🌡️ Temperature & Humidity (DHT11)

It sends data to ThingSpeak, activates a buzzer, LEDs, and can call/SMS via SIM800L on detection.

## Components Used
- ESP32
- Flame Sensor
- MQ2 Gas Sensor
- DHT11 Sensor
- SIM800L Module
- LEDs (Red & Green)
- Buzzer

## Pin Connections
| Component       | ESP32 Pin |
|----------------|-----------|
| DHT11          | 19        |
| Flame Sensor   | 23        |
| MQ2 (Analog)   | 34        |
| Red LED        | 2         |
| Green LED      | 4         |
| Buzzer         | 32        |
| SIM800L Rx     | GPIO17    |
| SIM800L Tx     | GPIO16    |

## Author
Emmanuel Siyanbola
