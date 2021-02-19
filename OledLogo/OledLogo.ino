#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define SCREEN_BLUE_LINE_OFFSET 8 //Offset for blue lines, in pixels
#define SCREEN_ID 0x3C  // OLED display adress

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Robot logo
#define LOGO_HEIGHT 24 // Logo display height, in pixels
#define LOGO_WIDTH 24 // Logo display height, in pixels
static const unsigned char myRobot [] PROGMEM = {
 // 'robot, 24x24px
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xdd, 0xff, 0xff, 0xc0, 0x7e, 0xff, 0x00, 0x37, 0xfc, 0xe0, 0x53, 0xf1, 0xf0, 0xe9, 0xeb, 0xf0, 
  0xf5, 0xe3, 0xf8, 0xe7, 0xd3, 0xf0, 0x03, 0xf1, 0xf0, 0x03, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x73, 
  0xff, 0xff, 0x83, 0xf8, 0x00, 0x07, 0xf8, 0x00, 0x07, 0xfc, 0x00, 0x0f, 0xfe, 0x00, 0x3f, 0xff, 
  0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ID)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
  printPicture();
  delay(1500);
}

void loop() {
}

void printPicture() {
  display.clearDisplay(); // Clear

  display.setTextSize(1);             // The fontsize
  display.setTextColor(WHITE);        // Draw white text  
  display.setCursor(25, 0);           // Start at top-left corner
  display.print("Robot logo :)");       //the text (13 char)
  
  display.drawBitmap(52, SCREEN_BLUE_LINE_OFFSET, myRobot, LOGO_HEIGHT, LOGO_WIDTH, WHITE);    // Display robot logo
  
  display.display();                  //call to display
}
