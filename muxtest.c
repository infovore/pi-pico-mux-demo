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
int maxCount = 20; // 2x the number of LEDs we have
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

    // setup the actual LED to light
    // we count to 20, then use the second half of the loop
    // as our 'reversed' output for the ping-pong effect.
    uint outputCount = counter;
    if(outputCount >= 10) {
      outputCount = maxCount-outputCount-1;
    }
    
    // convert our number to binary, and turn it into a valid output mask
    uint outputCountMask = (outputCount+countOffset) << FIRST_MUX_PIN;
    gpio_put_masked(muxMask,outputCountMask);

    sleep_ms(delay);
    counter = (counter+1) % maxCount;
  }
}
