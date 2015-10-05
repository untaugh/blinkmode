#include "CppUTest/TestHarness.h"

#include "blinkmode.h"

uint8_t pattern[] = {0x01,0x02,0x01,0x00};

TEST_GROUP(Blinkmode)
{
  void setup()
  {
    blinkmode_init();
  }

  void teardown()
  {

  }
  
  void load_test_pattern(void)
    {
  
      struct Blinkmode bm1 = {
	10,
	sizeof(pattern),
	pattern
      };

      blinkmode_current_pattern = bm1; 
    }
  
};

TEST(Blinkmode, clocktick)
{
  blinkmode_clock = 10;

  LONGS_EQUAL(10,blinkmode_clock);
  
  blinkmode_tick();

  LONGS_EQUAL(9,blinkmode_clock);
}

TEST(Blinkmode, setpattern)
{
  load_test_pattern();

  LONGS_EQUAL(10,blinkmode_current_pattern.delay);
  
  LONGS_EQUAL(4,blinkmode_current_pattern.size);

  LONGS_EQUAL(2,blinkmode_current_pattern.pattern[1]);  
}

