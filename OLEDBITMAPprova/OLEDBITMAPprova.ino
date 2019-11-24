#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
 
// visualizzazione di un testo su display OLED
// Prof. Michele Maffucci
// 02.10.15
 
// utilizzo di dispositivo SPI
// dispositivo -> Arduino
 
#define OLED_MOSI   11
#define OLED_CLK   12
#define OLED_DC    9
#define OLED_CS    8
#define OLED_RESET 10
 
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

 
void setup()   {
  Serial.begin(9600);
 
  // per default by default viene impostata una tensione ionterna di 3.3V
  display.begin(SSD1306_SWITCHCAPVCC);
 
  // cancelliamo lo schermo
  display.clearDisplay();
 
  // impostiamo il colore a bianco (in questo tipo di dsiplay possimo impostare solo bianco e nero)
  display.setTextColor(WHITE);
 
  // fissiamo la dimensione del testo
  display.setTextSize(1);
 
  // posizioniamo il cursore nella posizione x: 35; y: 32
  display.setCursor(32,32);
 
  // stampiamo su display il messaggio
  display.print("Salve mondo");
 
  // abilitiamo il display alla visualizzazione
  display.display();
}
 
 
void loop() {
// loop vuoto
}
