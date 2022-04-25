objects = \
	attr_constant.hpp.gch\
	attr_tuple.hpp.gch\
	attr_enumerate.hpp.gch\
	attr_anything.o\
	attr_interger.o\
	attr_list-of-numbers.o\
	attr_URL.o\
	attr_transform-list.o\
	attr_percentage.o\
	attr_length.o\
	attr_IRI.o\
	attr_paint.o\
	attr_name.o\
	attr_angle.o\
	attr_opacity-value.o\
	attr_number.o\
	attr_FuncIRI.o
cc = g++

.PHONY: all
all: $(objects)

attr_anything.o: attr_anything.cpp attr_anything.h
	$(cc) -c attr_anything.cpp
attr_interger.o: attr_interger.cpp attr_interger.h
	$(cc) -c attr_interger.cpp
attr_list-of-numbers.o: attr_list-of-numbers.cpp attr_list-of-numbers.h
	$(cc) -c attr_list-of-numbers.cpp
attr_URL.o: attr_URL.cpp attr_URL.h
	$(cc) -c attr_URL.cpp
attr_transform-list.o: attr_transform-list.cpp attr_transform-list.h
	$(cc) -c attr_transform-list.cpp
attr_percentage.o: attr_percentage.cpp attr_percentage.h
	$(cc) -c attr_percentage.cpp
attr_length.o: attr_length.cpp attr_length.h
	$(cc) -c attr_length.cpp
attr_IRI.o: attr_IRI.cpp attr_IRI.h
	$(cc) -c attr_IRI.cpp
attr_paint.o: attr_paint.cpp attr_paint.h
	$(cc) -c attr_paint.cpp
attr_name.o: attr_name.cpp attr_name.h
	$(cc) -c attr_name.cpp
attr_angle.o: attr_angle.cpp attr_angle.h
	$(cc) -c attr_angle.cpp
attr_opacity-value.o: attr_opacity-value.cpp attr_opacity-value.h
	$(cc) -c attr_opacity-value.cpp
attr_number.o: attr_number.cpp attr_number.h
	$(cc) -c attr_number.cpp
attr_FuncIRI.o: attr_FuncIRI.cpp attr_FuncIRI.h
	$(cc) -c attr_FuncIRI.cpp
attr_constant.hpp.gch: attr_constant.hpp
	$(cc) -c attr_constant.hpp
attr_tuple.hpp.gch: attr_tuple.hpp
	$(cc) -c attr_tuple.hpp
attr_enumerate.hpp.gch: attr_enumerate.hpp
	$(cc) -c attr_enumerate.hpp

.PHONY: all
clean:
	-rm $(objects)
