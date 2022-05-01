objects = \
    coordinate_system.o\
	point_func.o\
	component_rotatable.o\
	point.o
cc = g++

.PHONY: all
all: $(objects)
	cd coordinate_system && make

coordinate_system.o: coordinate_system.cpp coordinate_system.h
	$(cc) -w -c coordinate_system.cpp
point_func.o: point_func.cpp point_func.h
	$(cc) -w -c point_func.cpp
component_rotatable.o: component_rotatable.cpp component_rotatable.h
	$(cc) -w -c component_rotatable.cpp
point.o: point.cpp point.h
	$(cc) -w -c point.cpp

.PHONY: clean
clean:
	cd coordinate_system && make clean
	-rm $(objects)