#include <Arduino.h>
#include <Wire.h>
#include <dht11.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define I2C_SDA 6
#define I2C_SCL 7


dht11 DHT;
#define DHT11_PIN 3

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



// 'splashNico', 128x64px
const unsigned char epd_bitmap_splashNico [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xe8, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7c, 0x01, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7e, 0x03, 0x80, 0x03, 0x80, 0x01, 0xf8, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7f, 0x03, 0x80, 0x03, 0x80, 0x07, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7f, 0x83, 0x80, 0x03, 0x80, 0x0f, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x7b, 0xc3, 0x80, 0x03, 0x80, 0x0f, 0xdf, 0xc0, 0x00, 0x3c, 0x07, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x78, 0xe3, 0x80, 0x03, 0x80, 0x1c, 0x03, 0x80, 0x00, 0xf8, 0x01, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x78, 0xe3, 0x80, 0x03, 0x80, 0x3c, 0x00, 0x00, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x78, 0x73, 0x80, 0x03, 0x80, 0x3c, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x78, 0x7b, 0x80, 0x03, 0xc0, 0x78, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x38, 0x3f, 0x80, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x38, 0x1f, 0x80, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x38, 0x0f, 0x80, 0x01, 0x80, 0x78, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x0f, 0x80, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x60, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x0f, 0x80, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0xc0, 0x00, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x07, 0x80, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0xc0, 0x00, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x07, 0x80, 0x07, 0x80, 0x3c, 0x00, 0x00, 0x03, 0xc0, 0x00, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x07, 0xc0, 0x07, 0x00, 0x1f, 0x00, 0x20, 0x03, 0xe0, 0x01, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x03, 0xc0, 0x07, 0x00, 0x1f, 0xe0, 0xf0, 0x01, 0xe0, 0x01, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x1e, 0x01, 0xc0, 0x07, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0xf0, 0x03, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x1e, 0x01, 0xc0, 0x07, 0x80, 0x03, 0xff, 0xc0, 0x00, 0x70, 0x7e, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0e, 0x00, 0x80, 0x03, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
  epd_bitmap_splashNico
};

#define x1 5
#define y1 40
#define x2 72
#define y2 y1


void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 50);
  // Display static text
  display.println("Hello, world Oled!");
  Serial.println("Hello, world monitor!");

  display.drawBitmap(0, -5, epd_bitmap_splashNico, 128, 64, 1);
  // drawBitmap() method that accepts the following arguments (x, y, image array, image width, image height, rotation)
  
  display.display(); 
  delay(2000);
}

void loop() {

  
  int chk;
  Serial.print("DHT11, \t");
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk){
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;

case DHTLIB_ERROR_CHECKSUM: 

                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
    }

  // clear display
  display.clearDisplay();

   display.drawBitmap(0, -5, epd_bitmap_splashNico, 128, 64, 1);
  
  // display temperature
  display.setTextSize(1);
  display.setCursor(x1,y1);
  display.print("Temp: ");
  display.setTextSize(2);
  display.setCursor(x1,(y1+10));
  display.print(DHT.temperature);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(x2, y2);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(x2, (y2+10));
  display.print(DHT.humidity);
  display.print(" %"); 
  
  display.display(); 
  delay(4000);
}