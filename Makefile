CXX ?= g++
STD ?= c++17

CXXFLAGS ?= -std=$(STD) -O2 -Wall -Wextra -Wshadow -Wconversion

PCHCHECK ?= -Winvalid-pch

%: %.cpp
	$(CXX) $(CXXFLAGS) $(PCHCHECK) $< -o $@
