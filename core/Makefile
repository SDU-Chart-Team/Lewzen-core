objects = \
	utils.o\
    geometry.o\
	svg_el.o\
	svgi_el.o\
	core.o
cc = g++
ar = ar

ifeq ($(OS),Windows_NT) 
    platform = Windows
else
    platform = $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif
ifeq ($(platform), Windows)
.PHONY: all
all: sub_all
	$(ar) rvs lewzen-core.lib $(shell dir . /S /b | findstr /i ".*\.o$")
endif
ifeq ($(platform), Linux)
.PHONY: all
all: sub_all
	$(ar) rvs lewzen-core.lib $(shell find . -type f -iregex ".*\.o")
endif

sub_all: $(objects)
	cd utils && make
	cd geometry && make
	cd svg_el && make
	cd svgi_el && make

utils.o: utils.cpp utils.h
	$(cc) -c utils.cpp
geometry.o: geometry.cpp geometry.h
	$(cc) -w -c geometry.cpp
svg_el.o: svg_el.cpp svg_el.h
	$(cc) -c svg_el.cpp
svgi_el.o: svgi_el.cpp svgi_el.h
	$(cc) -w -c svgi_el.cpp
core.o: core.cpp core.h
	$(cc) -w -c core.cpp

.PHONY: clean
clean:
	cd utils && make clean
	cd geometry && make clean
	cd svg_el && make clean
	cd svgi_el && make clean
	-rm $(objects)