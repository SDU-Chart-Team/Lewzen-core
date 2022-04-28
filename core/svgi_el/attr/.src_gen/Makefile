cc = g++-8 -lstdc++fs -std=c++17 -O3

src_gen: src_gen.cpp ../../../json.hpp
	$(cc) -o src_gen src_gen.cpp ../../../json.hpp -lstdc++fs

type_list: type_list.cpp ../../../json.hpp
	$(cc) -o type_list type_list.cpp ../../../json.hpp -lstdc++fs

.PHONY: clean
clean:
	-rm type_list src_gen