objects = \
	attr_tuple.hpp.gch\
	attr_percentage.o\
	attr_length.o\
	attr_number.o
cc = g++

.PHONY: all
all: $(objects)

attr_percentage.o: attr_percentage.cpp attr_percentage.h
	$(cc) -c attr_percentage.cpp
attr_length.o: attr_length.cpp attr_length.h
	$(cc) -c attr_length.cpp
attr_number.o: attr_number.cpp attr_number.h
	$(cc) -c attr_number.cpp
attr_tuple.hpp.gch: attr_tuple.hpp
	$(cc) -c attr_tuple.hpp

.PHONY: all
clean:
	-rm $(objects)
