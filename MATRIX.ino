#define STRIP_PIN 2     // пин ленты
// для генерации битмапа используется программа imageProcessor
// https://github.com/AlexGyver/imageProcessor
// со стандартными настройками, выбираем только глубину цвета (RGB888/565/232)
// остальные - PROGMEM вкл, массив 1D

#include "bitmap.h"

#define COLOR_DEBTH 2
#include <microLED.h>
#include <FastLEDsupport.h> 
#define BALLS_AMOUNT 20
boolean loadingFlag = true;
int coord[BALLS_AMOUNT][2];
#define M_WIDTH 16    // ширина матрицы
#define M_HEIGHT 16    // высота матрицы
int8_t vector[BALLS_AMOUNT][2];
mData ballColors[BALLS_AMOUNT];
microLED<16 * 16, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_HIGH> matrix(16, 16, ZIGZAG, LEFT_TOP, DIR_DOWN);
int i=1;

void setup() {
      matrix.setBrightness(50);
      palka();

}

void loop() {
     
      balls();
      matrix.show();
      delay(30);
}

void balls() {
  if (loadingFlag) {
    loadingFlag = false;
    for (byte j = 0; j < BALLS_AMOUNT; j++) {
      int sign;
      // забиваем случайными данными
      coord[j][0] = M_WIDTH / 2 * 10;
      random8(0, 2) ? sign = 1 : sign = -1;
      vector[j][0] = random8(4, 15) * sign;
      coord[j][1] = M_HEIGHT / 2 * 10;
      random8(0, 2) ? sign = 1 : sign = -1;
      vector[j][1] = random8(4, 15) * sign;
      ballColors[j] = mWheel8(random8(0, 9) * 28);
    }
  }

  matrix.clear();  // очистить

  // движение шариков
  for (byte j = 0; j < BALLS_AMOUNT; j++) {
    for (byte i = 0; i < 2; i++) {
      coord[j][i] += vector[j][i];
      if (coord[j][i] < 0) {
        coord[j][i] = 0;
        vector[j][i] = -vector[j][i];
      }
    }
    if (coord[j][0] > (M_WIDTH - 1) * 10) {
      coord[j][0] = (M_WIDTH - 1) * 10;
      vector[j][0] = -vector[j][0];
    }
    if (coord[j][1] > (M_HEIGHT - 1) * 10) {
      coord[j][1] = (M_HEIGHT - 1) * 10;
      vector[j][1] = -vector[j][1];
    }
    matrix.set(coord[j][0] / 10, coord[j][1] / 10, ballColors[j]);
  }
}

void palka(){

     for(int i = 0; i <= 10; i++){
      matrix.drawBitmap16(5, 5, frame00, 8, 8);
      matrix.show();
      delay(20);
     // matrix.clear();

      matrix.drawBitmap16(5, 5, frame01, 8, 8);
      matrix.show();
      delay(20);
      //matrix.clear();

      matrix.drawBitmap16(5, 5, frame02, 8, 8);
      matrix.show();
      delay(20);
      //matrix.clear();

      matrix.drawBitmap16(5, 5, frame03, 8, 8);
      matrix.show();
      delay(20);
      //matrix.clear();

      matrix.drawBitmap16(5, 5, frame04, 8, 8);
      matrix.show();
      delay(20); 
      }
      matrix.clear();
  }
