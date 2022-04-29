objects = \
	utils.o\
    geometry.o\
	svg_el.o\
	svgi_el.o
allobjs = $(shell find . -type f -iregex ".*\.o")
cc = g++

.PHONY: all
all: $(objects)
	cd utils && make
	cd geometry && make
	cd svg_el && make
	cd svgi_el && make
	ar rvs lewzen.lib $(allobjs)

utils.o: utils.cpp utils.h
	$(cc) -c utils.cpp
geometry.o: geometry.cpp geometry.h
	$(cc) -w -c geometry.cpp
svg_el.o: svg_el.cpp svg_el.h
	$(cc) -c svg_el.cpp
svgi_el.o: svgi_el.cpp svgi_el.h
	$(cc) -w -c svgi_el.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	cd svg_el && make clean
	cd svgi_el && make clean
	-rm $(objects)