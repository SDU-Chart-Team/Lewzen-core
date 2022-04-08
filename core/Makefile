objects = \
    geometry.o
cc = g++

.PHONY: all
all: $(objects)
	cd geometry && make

geometry.o: geometry.cpp geometry.h
	$(cc) -c geometry.cpp

.PHONY: clean
clean:
	cd geometry && make clean
	-rm $(objects)