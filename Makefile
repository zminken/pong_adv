CXX=g++
RM=rm -f
CPPFLAGS=-std=gnu++11
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=main.cpp Bat.cpp Ball.cpp gameplay.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: pong-app

pong-app: $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) .depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c $<

Bat.o: Bat.cpp Bat.h
	$(CXX) $(CPPFLAGS) -c $<

Ball.o: Ball.cpp Ball.h
	$(CXX) $(CPPFLAGS) -c $<

gameplay.o: gameplay.cpp gameplay.h
	$(CXX) $(CPPFLAGS) -c $<

.PHONY: clean

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend pong-app

include .depend
