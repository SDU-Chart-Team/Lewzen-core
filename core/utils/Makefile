objects = \
    constant.o\
	data_structure.o\
	hash.o\
	uuid.o
cc = g++

.PHONY: all
all: $(objects)

constant.o: constant.cpp constant.h
	$(cc) -c constant.cpp
data_structure.o: data_structure.cpp data_structure.h
	$(cc) -c data_structure.cpp
hash.o: hash.cpp hash.h
	$(cc) -c hash.cpp
uuid.o: uuid.cpp uuid.h
	$(cc) -c uuid.cpp

.PHONY: clean
clean:
	-rm $(objects)