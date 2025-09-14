#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ----- DS18B20 -----
#define ONE_WIRE_BUS 5     // DS18B20 데이터 핀 D5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ----- OLED -----
#define SCREEN_WIDTH 128 // OLED 가로 픽셀
#define SCREEN_HEIGHT 64 // OLED 세로 픽셀
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // DS18B20 시작
  sensors.begin();

  // OLED 시작
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 보통 0x3C 주소
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // 멈춤
  }
  display.clearDisplay();
  display.setTextSize(2);      // 글자 크기
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Temp Init");
  display.display();
  delay(2000);
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // 시리얼 출력
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" *C");

  // OLED 출력
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  display.println("Temp:");
  display.setTextSize(3);
  display.setCursor(0,30);
  display.print(tempC);
  display.print(" C");
  display.display();

  delay(1000);
}
