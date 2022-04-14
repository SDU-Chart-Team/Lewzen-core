cc = g++-8 -lstdc++fs -std=c++17 -O3

src_gen: src_gen.cpp ../../.svg_def/json.hpp
	$(cc) -o src_gen src_gen.cpp ../../.svg_def/json.hpp -lstdc++fs

.PHONY: clean
clean:
	-rm src_gen