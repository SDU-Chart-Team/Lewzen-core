objects = \
	utils.o\
    geometry.o\
	svg_el.o
cc = g++

.PHONY: all
all: $(objects)
	cd utils && make
	cd geometry && make
	cd svg_el && make

utils.o: utils.cpp utils.h
	$(cc) -c utils.cpp
geometry.o: geometry.cpp geometry.h
	$(cc) -c geometry.cpp
svg_el.o: svg_el.cpp svg_el.h
	$(cc) -c svg_el.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	cd svg_el && make clean
	-rm $(objects)