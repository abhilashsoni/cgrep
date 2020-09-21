CXX=g++
RM=rm -f

all:
	$(CXX) -std=c++11 -o cgrep.out cgrep.cpp

clean:
	$(RM) cgrep.out

install:
	alias cgrep='./cgrep.out'