objects = \
	utils.o\
    geometry.o\
	svg.o
cc = g++

.PHONY: all
all: $(objects)
	cd utils && make
	cd geometry && make
	cd svg && make

utils.o: utils.cpp utils.h
	$(cc) -c utils.cpp
geometry.o: geometry.cpp geometry.h
	$(cc) -c geometry.cpp
svg.o: svg.cpp svg.h
	$(cc) -c svg.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	cd svg && make clean
	-rm $(objects)