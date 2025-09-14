# DS18B20 온도센서 + OLED 출력 (Arduino MEGA 2560)

## 📌 프로젝트 소개
Arduino MEGA 2560 보드에 DS18B20 디지털 온도 센서를 연결하여 온도를 측정하고,  
OLED(SSD1306 I2C 모듈)에 실시간으로 출력하는 프로젝트입니다.  
센서 값은 시리얼 모니터에도 동시에 표시됩니다.

---

## 🔧 하드웨어 구성
- Arduino MEGA 2560
- DS18B20 온도센서 (모듈형, 3핀: VCC, GND, DATA)
- 0.96" OLED (SSD1306, I2C, 128x64)
- 점퍼 케이블, 브레드보드
- 풀업 저항 4.7kΩ (DATA ↔ VCC)

---

## ⚡ 회로 연결

### DS18B20
| DS18B20 핀 | Arduino MEGA 2560 |
|------------|-------------------|
| VCC (+)    | 5V                |
| GND (-)    | GND               |
| DATA (S)   | D5 (Digital 5)    |
| 저항 4.7kΩ | DATA ↔ VCC        |

### OLED (SSD1306, I2C)
| OLED 핀 | Arduino MEGA 2560 |
|---------|-------------------|
| VCC     | 5V                |
| GND     | GND               |
| SDA     | 20 (SDA)          |
| SCL     | 21 (SCL)          |

---

## 📚 사용 라이브러리
아두이노 IDE → **라이브러리 매니저**에서 설치
- [OneWire](https://github.com/PaulStoffregen/OneWire)
- [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
