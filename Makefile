CC := g++
CXXFLAGS += -Wall -O0 -g3 -std=gnu++11
TARGETS := P1000 P1018
OBJECTS := $(TARGETS:=.o)

.PHONY : all clean dist-clean

all : $(TARGETS)

$(TARGETS) : % : %.o

clean :
	$(RM) *.o *~

dist-clean :
	$(RM) *.o *~ $(TARGETS)
