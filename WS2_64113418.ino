#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// การกำหนดค่าเซ็นเซอร์ DHT
float temperature;
float humidity;
DHT dht(D4, DHT11);

// การกำหนดค่าหน้าจอ LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // การเริ่มต้นการทำงานของ Serial
  Serial.begin(9600);
  
  // การเริ่มต้นการทำงานของเซ็นเซอร์ DHT
  dht.begin();
  
  // การเริ่มต้นการทำงานของหน้าจอ LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hum:       %");
  lcd.setCursor(0,1);
  lcd.print("Temp:       c");
}

void loop() {
  // การอ่านค่าจากเซ็นเซอร์ DHT
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // การแสดงผลลัพธ์บน Serial Monitor
  Serial.print("Hum:       %");
  Serial.print(humidity);
  Serial.print("Temp:       C");
  Serial.print(temperature);

  // การแสดงผลลัพธ์บนหน้าจอ LCD
  lcd.setCursor(5, 0);
  lcd.print(humidity);
  lcd.setCursor(6, 1);
  lcd.print(temperature);  

  delay(500); // หน่วงเวลาความเร็ว
}
