#ifndef BLINKMODE_H
#define BLINKMODE_H

#include <stdint.h>

extern uint8_t blinkmode_clock;

extern struct Blinkmode blinkmode_current_pattern;

void blinkmode_tick(void); // clock tick tock

void blinkmode_setset(void (), uint8_t); // set the led setters

void blinkmode_setclr(void (), uint8_t); // set the led clearers

void blinkmode_init(void);

// this defines the blinking pattern and speed
struct Blinkmode
{
  uint8_t delay; // delay in ticks
  uint8_t size; // size of the pattern
  uint8_t * pattern; // one byte for each state
};

#endif // BLINKMODE_H
