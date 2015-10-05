#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "blinkmode.h"

uint8_t patternmock[] = {0x01,0x82,0x83,0x00};

TEST_GROUP(BlinkmodeMock)
{
  void setup()
  {
    blinkmode_init();
  }

  void teardown()
  {
    mock().clear();
  }
  
  void load_test_pattern(void)
    {
  
      struct Blinkmode bm1 = {
	10,
	sizeof(patternmock),
	patternmock
      };

      blinkmode_current_pattern = bm1; 
    }
  
};

void red_test_set()
{
  mock().actualCall("red_test_set");
}

void red_test_clr()
{
  mock().actualCall("red_test_clr");
}

void green_test_set()
{
  mock().actualCall("green_test_set");
}

void green_test_clr()
{
  mock().actualCall("green_test_clr");
}


TEST(BlinkmodeMock, onecall)
{
  load_test_pattern();

  blinkmode_setset(red_test_set,0);
  blinkmode_setclr(red_test_clr,0);
  
  mock().expectOneCall("red_test_set");
  blinkmode_tick();    
  
  mock().checkExpectations();
}

TEST(BlinkmodeMock, runpattern)
{
  int i;
  
  load_test_pattern();

  blinkmode_setset(red_test_set,0);
  blinkmode_setclr(red_test_clr,0);
  
  mock().expectOneCall("red_test_set");

  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }
  
  mock().expectOneCall("red_test_clr");
  
  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }
  
  mock().checkExpectations();
}

TEST(BlinkmodeMock, fullpattern)
{
  int i;
  
  load_test_pattern();

  blinkmode_setset(red_test_set,0);
  blinkmode_setclr(red_test_clr,0);
  
  mock().expectOneCall("red_test_set");
  mock().expectOneCall("red_test_clr");
  
  for (i=0; i<20; i++)
    {
      blinkmode_tick();    
    }

  mock().expectOneCall("red_test_set");
  mock().expectOneCall("red_test_clr");    
  
  for (i=0; i<20; i++)
    {
      blinkmode_tick();    
    }

  mock().expectOneCall("red_test_set");
  mock().expectOneCall("red_test_clr");    
  
  for (i=0; i<20; i++)
    {
      blinkmode_tick();    
    }
  
  mock().checkExpectations();
}

TEST(BlinkmodeMock,redandgreen)
{
  int i;
  
  load_test_pattern();

  blinkmode_setset(red_test_set,0);
  blinkmode_setclr(red_test_clr,0);
  blinkmode_setset(green_test_set,7);
  blinkmode_setclr(green_test_clr,7);
  
  mock().expectOneCall("red_test_set");
  mock().expectOneCall("green_test_clr");
  
  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }

  mock().expectOneCall("red_test_clr");
  mock().expectOneCall("green_test_set");
  
  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }

  mock().expectOneCall("red_test_set");
  mock().expectOneCall("green_test_set");
  
  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }

  mock().expectOneCall("red_test_clr");
  mock().expectOneCall("green_test_clr");
  
  for (i=0; i<10; i++)
    {
      blinkmode_tick();    
    }
  
  mock().checkExpectations();
  
}
