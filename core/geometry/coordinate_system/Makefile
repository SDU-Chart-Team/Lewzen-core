objects = \
	canvas_coordinate_system.o\
	component_coordinate_system.o\
	component_relative_coordinate_system.o\
	point_coordinate_system.o\
	point_relative_coordinate_system.o\
	vector_coordinate_system.o\
	vector_relative_coordinate_system.o
cc = g++

.PHONY: all
all: $(objects)

canvas_coordinate_system.o: canvas_coordinate_system.cpp canvas_coordinate_system.h
	$(cc) -w -c canvas_coordinate_system.cpp
component_coordinate_system.o: component_coordinate_system.cpp component_coordinate_system.h
	$(cc) -w -c component_coordinate_system.cpp
component_relative_coordinate_system.o: component_relative_coordinate_system.cpp component_relative_coordinate_system.h
	$(cc) -w -c component_relative_coordinate_system.cpp
point_coordinate_system.o: point_coordinate_system.cpp point_coordinate_system.h
	$(cc) -w -c point_coordinate_system.cpp
point_relative_coordinate_system.o: point_relative_coordinate_system.cpp point_relative_coordinate_system.h
	$(cc) -w -c point_relative_coordinate_system.cpp
vector_coordinate_system.o: vector_coordinate_system.cpp vector_coordinate_system.h
	$(cc) -w -c vector_coordinate_system.cpp
vector_relative_coordinate_system.o: vector_relative_coordinate_system.cpp vector_relative_coordinate_system.h
	$(cc) -w -c vector_relative_coordinate_system.cpp

.PHONY: clean
clean:
	-rm $(objects)