CXX = g++
CXXFLAGS = -Wall -Wextra -O3

%: %.cpp
	$(CXX) $(CXXFLAGS) $? -o $@
	./$@

clean:
	rm $$(find -maxdepth 1 -type f -not -name "*.cpp"\
										 						 -not -name Makefile\
										 						 -not -name compile_flags.txt\
										 						 -not -name ".git*"\
																 -not -name LICENSE)
