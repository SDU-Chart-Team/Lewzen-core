cc = g++-8 -lstdc++fs -std=c++17 -O3

classify: classify.cpp ../../../.svg_def/json.hpp
	$(cc) -o classify classify.cpp ../../../.svg_def/json.hpp -lstdc++fs

.PHONY: clean
clean:
	-rm classify