TESTS = BlinkmodeTests.cpp BlinkmodeMockTests.cpp
INCLUDE = -I ../
CPPUTEST_HOME = $(CPPUTEST_PATH)
CPPFLAGS += -std=c++11 -I$(CPPUTEST_HOME)/include
LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

test: $(TESTS) AllTests.cpp ../blinkmode.c
	g++ ../blinkmode.c $(TESTS) -Wall -Wextra AllTests.cpp -o test $(INCLUDE) $(CPPFLAGS) $(CFLAGS) $(LIBRARIES) 

.phony: clean

clean:
	rm -rf test
