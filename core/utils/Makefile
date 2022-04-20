objects = \
    constant.o\
	data_structure.o\
	hash.o\
	uuid.o\
	warning.o\
	lambda.hpp.gch
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
warning.o: warning.cpp warning.h
	$(cc) -c warning.cpp
lambda.hpp.gch: lambda.hpp
	$(cc) -c lambda.hpp

.PHONY: clean
clean:
	-rm $(objects)