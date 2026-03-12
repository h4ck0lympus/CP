CXX ?= g++
STD ?= c++17

CXXFLAGS ?= -std=$(STD) -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -fsanitize=address -g3

PCHCHECK ?= -Winvalid-pch

%: %.cpp
	$(CXX) $(CXXFLAGS) $(PCHCHECK) $< -o $@
