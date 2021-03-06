CC := g++
CXXFLAGS += -Wall -Wnarrowing -O0 -g3 -std=gnu++11
TARGETS := P1000 P1018 P1061
OBJECTS := $(TARGETS:=.o)

.PHONY : all clean dist-clean

all : $(TARGETS)

$(TARGETS) : % : %.o

$(OBJECTS) : EntryPoint.h SolutionBase.h NonCopyable.h

clean :
	$(RM) *.o *~

dist-clean :
	$(RM) *.o *~ $(TARGETS)
