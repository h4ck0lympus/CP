CXX      ?= g++
STD      ?= c++17
CXXFLAGS ?= -std=$(STD) -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -fsanitize=address -g3
PCHCHECK ?= -Winvalid-pch

bits/stdc++.h.gch: bits/stdc++.h
	$(CXX) $(CXXFLAGS) -x c++-header $< -o $@

%: %.cpp bits/stdc++.h.gch
	$(CXX) $(CXXFLAGS) $(PCHCHECK) $< -o $@
