/**
 * Multiplexed scrolling lights demo.
 *
 * See README.md for pinout / circuit configuration
 * Tom Armitage [tom@infovore.org]
 */

#include "pico/stdlib.h"

#define FIRST_MUX_PIN 2
#define MUX_PIN_COUNT 4
#define OUTPUT_PIN 6

int counter = 0;
int countOffset = 6;
int maxCount = 20;
int delay = 50;

int muxMask;

int main() {
  // setup mux pinmask
  for (int i = 0; i < MUX_PIN_COUNT; i++) {
    int pinNumber = FIRST_MUX_PIN + i;
    muxMask |= 1 << pinNumber;
  }

  // setup LED pin
  gpio_init(OUTPUT_PIN);
  gpio_set_dir(OUTPUT_PIN, GPIO_OUT);

  // setup mux pins using the mask.
  gpio_init_mask(muxMask);
  gpio_set_dir_out_masked(muxMask);

  while (true) {
    // LED output pin is always on
    gpio_put(OUTPUT_PIN, 1);
    // convert counter to binary
    uint outputCount = counter;
    if(outputCount >= 10) {
      outputCount = maxCount-outputCount-1;
    }
    uint outputCountMask = (outputCount+countOffset) << FIRST_MUX_PIN;
    // write counter
    gpio_put_masked(muxMask,outputCountMask);
    // sleep for a while
    sleep_ms(delay);
    // increment counter
    counter = (counter+1) % maxCount;
  }
}
