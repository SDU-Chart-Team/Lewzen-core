objects = \
	utils.o\
    geometry.o
cc = g++

.PHONY: all
all: $(objects)
	cd utils && make
	cd geometry && make

utils.o: utils.cpp utils.h
	$(cc) -c utils.cpp
geometry.o: geometry.cpp geometry.h
	$(cc) -c geometry.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	-rm $(objects)