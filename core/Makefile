objects = \
	utils.o\
    geometry.o\
	svg_element.o
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
svg_element.o: svg_element.cpp svg_element.h
	$(cc) -c svg_element.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	cd svg_el && make clean
	-rm $(objects)