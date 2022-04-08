objects = \
    coordinate_system.o\
	point_func.o\
	point.o
cc = g++

.PHONY: all
all: $(objects)
	cd coordinate_system && make

coordinate_system.o: coordinate_system.cpp coordinate_system.h
	$(cc) -c coordinate_system.cpp
point_func.o: point_func.cpp point_func.h
	$(cc) -c point_func.cpp
point.o: point.cpp point.h
	$(cc) -c point.cpp

.PHONY: clean
clean:
	cd coordinate_system && make clean
	-rm $(objects)