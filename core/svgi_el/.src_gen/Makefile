cc = g++-8 -lstdc++fs -std=c++17 -O3

src_gen: src_gen.cpp ../../json.hpp
	$(cc) -o src_gen src_gen.cpp ../../json.hpp -lstdc++fs

.PHONY: clean
clean:
	-rm src_gen