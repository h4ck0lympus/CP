CXX ?= g++
STD ?= c++17

CXXFLAGS ?= -std=$(STD) -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address -g3

PCHCHECK ?= -Winvalid-pch

%: %.cpp
	$(CXX) $(CXXFLAGS) $(PCHCHECK) $< -o $@

debug: CXXFLAGS += -fsanitize=address -g3
debug: %: %.cpp
	$(CXX) $(CXXFLAGS) $(PCHCHECK) $< -o $@

