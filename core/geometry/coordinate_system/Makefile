objects = \
	canvas_coordinate_system.o\
	component_coordinate_system.o\
	component_relative_coordinate_system.o\
	point_coordinate_system.o\
	point_relative_coordinate_system.o\
	vector_coordinate_system.o\
	vector_relative_coordinate_system.o
cc = g++ -w

.PHONY: all
all: $(objects)

canvas_coordinate_system.o: canvas_coordinate_system.cpp canvas_coordinate_system.h
	$(cc) -c canvas_coordinate_system.cpp
component_coordinate_system.o: component_coordinate_system.cpp component_coordinate_system.h
	$(cc) -c component_coordinate_system.cpp
component_relative_coordinate_system.o: component_relative_coordinate_system.cpp component_relative_coordinate_system.h
	$(cc) -c component_relative_coordinate_system.cpp
point_coordinate_system.o: point_coordinate_system.cpp point_coordinate_system.h
	$(cc) -c point_coordinate_system.cpp
point_relative_coordinate_system.o: point_relative_coordinate_system.cpp point_relative_coordinate_system.h
	$(cc) -c point_relative_coordinate_system.cpp
vector_coordinate_system.o: vector_coordinate_system.cpp vector_coordinate_system.h
	$(cc) -c vector_coordinate_system.cpp
vector_relative_coordinate_system.o: vector_relative_coordinate_system.cpp vector_relative_coordinate_system.h
	$(cc) -c vector_relative_coordinate_system.cpp

.PHONY: clean
clean:
	-rm $(objects)