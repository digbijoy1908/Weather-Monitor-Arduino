# Weather Monitor (Arduino + DHT11 + I2C LCD)

A simple weather monitor that reads temperature and humidity from a DHT11 sensor and shows them on a 16x2 I2C LCD. Values are also printed to the Serial Monitor.

![image alt](https://github.com/digbijoy1908/Weather-Monitor-Arduino/blob/5c7c093ff5d97474a6a2a8f9fe8bf683c2f8c345/Arduino%20Weather%20Monitor%20Showcase.jpg)

## Features
- Live temperature (°C) and humidity (%) display
- Custom degree symbol on the LCD
- Serial Monitor output at 9600 baud
- Updates every 1 second

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno (or compatible) | 1 |
| DHT11 temperature & humidity sensor | 1 |
| 16x2 LCD with I2C module | 1 |
| Jumper wires | several |
| Breadboard | 1 |

## Wiring

**DHT11**
| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC (+)   | 5V          |
| DATA (S)  | A3          |
| GND (-)   | GND         |

**I2C LCD**
| LCD Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

## Libraries required
Install via **Sketch → Include Library → Manage Libraries**:
- **DHT sensor library** by Adafruit (also install **Adafruit Unified Sensor** when asked)
- **LiquidCrystal I2C** by Frank de Brabander

## How to use
1. Wire the components as shown above.
2. Open `Weather_Monitor.ino` in the Arduino IDE.
3. Install the libraries listed above.
4. Select your board and port, then click **Upload**.
5. Open the Serial Monitor at 9600 baud to see the readings.

## Troubleshooting
- **LCD is blank:** change the address `0x27` to `0x3F` in the code, and adjust the contrast screw on the I2C module.
- **Readings show 0 or garbage:** check the DHT11 wiring and the pin number.

