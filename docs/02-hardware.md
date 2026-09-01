# Rozpiska elementów
## 0.96inch OLED Module
[datasheet](https://www.lcdwiki.com/0.96inch_OLED_Module_MC096VX)
### Pinout

| Pin No. | Pin Name | Pin Description        |
| ------- | -------- | ---------------------- |
| 1.      | GND      | Ground                 |
| 2.      | VDD      | Power source 3.3V - 5V |
| 3.      | SCK      | Serial Clock           |
| 4.      | SDA      | Serial Data            |

### Tested Address
0x3C
## Capacitive Soil Moisture Sensor 1.2V
### Pinout
| Pin No. | Pin Name | Pin Description           |
| ------- | -------- | ------------------------- |
| 1.      | GND      | Ground                    |
| 2.      | VCC      | power source of 3.3V - 5V |
| 3.      | AOUT     | analog output 0V-3V       |
### Specs
- Sensor type: Analogue
- Operating voltage: 3.3 VDC
- Output voltage: 0-3.0 VDC
- Interface: PH2.54 3-pin
- Size: 98 x 23mm
## GY-BMP280 Module
[datasheet](https://components101.com/sensors/gy-bmp280-module)
### Pins
| **Pin No.** | **Pin Name** | **Pin Description**                                                                                                    |
| ----------- | ------------ | ---------------------------------------------------------------------------------------------------------------------- |
| 1           | VCC          | Power source of 3.3VDC                                                                                                 |
| 2           | GND          | Ground                                                                                                                 |
| 3           | SCL          | Serial Clock                                                                                                           |
| 4           | SDA          | Serial Data                                                                                                            |
| 5           | CSB          | CSB pin to GND to have SPI and to VCC(3.3V) for I2C. It’s an input to the chip.                                        |
| 6           | SDO          | **S**erial **D**ata **O**ut / **M**aster **I**n **S**lave **O**ut pin, for data sent from the BMP280 to your processor |

### Tested Address
0x76
### Specs
- Model: GY-BMP280-3.3
- Chip: BMP280
- Power supply:  3V/3.3V DC
- Peak current: 1.12mA
- Air pressure range : 300-1100hPa (equi. to +9000…-500m above sea level)
- Temperature range: -40 … +85 °C
- Digital interfaces: I²C (up to 3.4 MHz) and SPI (3 and 4 wire, up to 10 MHz)
- Current consumption of sensor BMP280: 2.7µA @ 1 Hz sampling rate
## Battery charger TP4056
datasheet
### Specs
- Input voltage: 4.5V – 5.5V (USB micro-B or USB-C connector on module)
- Charging voltage: 4.2V (precisely regulated for Li-ion chemistry)
- Charging current: 1A default (adjustable by changing RPROG resistor)
- Charging method: CC/CV (constant current until 4.2V, then constant voltage until current drops to ~100 mA)
- Termination: Automatic when charge current drops below 1/10th of set current
- Temperature protection: Built-in thermal regulation (reduces current if chip overheats)
- Package: Tiny PCB module, ~25mm x 19mm
## GY-302 BH1750 BH1750FVI (light sensor)
[[bh1750fvi-e-186247.pdf|datasheet]]
### Pinout
| Pin No. | Pin Name | Pin Description                     |
| ------- | -------- | ----------------------------------- |
| 1.      | VCC      | Ground                              |
| 2.      | GND      | power source of 3.3V                |
| 3.      | SCL      | Serial Clock                        |
| 4.      | SDA      | Serial Data                         |
| 5.      | ADDR     | address H - "1011100" L - "0100011" |
### Tested Address
0x23
### Features
- I2C bus Interface ( f / s Mode Support )
- Spectral responsibility is approximately human eye response
- Illuminance to Digital Converter
- Wide range and High resolution. ( 1 - 65535 lx )
- Low Current by power down function
- 50Hz / 60Hz Light noise reject-function
- 1.8V Logic input interface
- No need any external parts
- Light source dependency is little. ( ex. Incandescent Lamp. Fluorescent Lamp. Halogen Lamp. White LED. Sun Light )
- It is possible to select 2 type of I2C slave-address.
- Adjustable measurement result for influence of optical window
- ( It is possible to detect min. 0.11 lx, max. 100000 lx by using this function. )
- Small measurement variation (+/- 20%)
- The influence of infrared is very small.
##  ESP32 WROOM-32 TYPE-C CH340C/CP2102
[[esp-wroom-32_datasheet_en-1223836.pdf|datasheet]]
![[Pasted image 20260820183527.png]]

### Pinout


| Pin Name | Pin Eqv      | Pin Description                       |
| -------- | ------------ | ------------------------------------- |
| 3v3      | power source | Gives power of 3.3V to other elements |
| GND      | ground       | ground for 3.3                        |
| D21      | SDA          | serial data                           |
| D22      | SCK          | serial clock                          |
| D12      | AIN          | Analog data from moisture sensor      |


