  //programma di avvio per bitmap e animazione bitmap con cerchi
  
  #include <SPI.h>
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64  //17 = giallo, 47 = blu
#define OLED_MOSI  10
#define OLED_CLK    9
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#define NUMFLAKES      5  
#define LOGO_HEIGHT   15
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =  
{ B11111111, B11000000,
  B10000000, B01100000,
  B10000000, B00110000,
  B10000000, B00011000,
  B10000000, B00001100,
  B10000000, B00000110,
  B10000000, B00000011,
  B10000000, B00000001,
  B10000000, B00000011,
  B10000000, B00000110,
  B10000000, B00001100,
  B10000000, B00011000,
  B10000000, B00110000,
  B10000000, B01100000,
  B11111111, B11000000,  };


#define XPOS   0
#define YPOS   1
#define DELTAY 2

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  int8_t f, icons[NUMFLAKES][3];

    for(f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
    icons[f][YPOS]   = -LOGO_HEIGHT;
    icons[f][DELTAY] = random(1, 6);
    Serial.print(F("x: "));
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(F(" y: "));
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(F(" dy: "));
    Serial.println(icons[f][DELTAY], DEC);
  }

  for(;;) { 
    display.clearDisplay(); 

      for(f=0; f< NUMFLAKES; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, WHITE);
    }

    display.display(); 
    delay(200);
    
    for(f=0; f< NUMFLAKES; f++) {
      icons[f][YPOS] += icons[f][DELTAY];
      if (icons[f][YPOS] >= display.height()) {
        
        icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
        icons[f][YPOS]   = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
      }
      
    }
  }
}


  


void testdrawcircle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testdrawbitmap(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(1000);
}

void testdrawstyles(void) {
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(("Ciao Papa'!"));
  delay(3000);

}

void testdrawroundrect(void) {
 // display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=1) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,display.height()/5, WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {  
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
 display.display();
 delay(4000);
 display.clearDisplay();

testdrawbitmap();    
display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  testdrawroundrect();
  testdrawcircle();
  testdrawstyles();
  testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); 
}

void loop(){
  
  }
