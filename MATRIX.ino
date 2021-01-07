#define STRIP_PIN 2     // пин ленты
// для генерации битмапа используется программа imageProcessor
// https://github.com/AlexGyver/imageProcessor
// со стандартными настройками, выбираем только глубину цвета (RGB888/565/232)
// остальные - PROGMEM вкл, массив 1D
const uint16_t bitmap_8x8[] PROGMEM = {
  0x792A, 0x792A, 0x792A, 0x792A, 0x792A, 0x792A, 0x792A, 0x792A, 
  0x792A, 0x792A, 0x0000, 0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x792A, 0x792A, 0x0000, 0x0000, 0x0000, 
};


#define COLOR_DEBTH 2
#include <microLED.h>
microLED<16 * 16, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_HIGH> matrix(16, 16, ZIGZAG, LEFT_TOP, DIR_DOWN);


void setup() {
      matrix.setBrightness(50);
 
  
  // также есть drawBitmap8 и drawBitmap32
  // (x, y, массив, ширина, высота)
}

void loop() {

      for (int i = 14; i>-7; i--){
      matrix.drawBitmap16(i, 0, bitmap_8x8, 8, 8);
      matrix.setBrightness(50);
      matrix.show();
      delay(40);
      matrix.clear();}


}
