#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>;
const int d0 = 13, d1 = 11, res = 8, dc = 9, cs = 10;
int display1(d0, d1, res, dc, cs);
void setup() {
 display1.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display1.clear();
  display1.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
