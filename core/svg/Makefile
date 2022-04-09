objects = \
	svg_radial_gradient.o\
	svg_g.o\
	svg_mask.o\
	svg_image.o\
	svg_pattern.o\
	svg_marker.o\
	svg_defs.o\
	svg_foreign_object.o\
	svg_linear_gradient.o\
	svg_stop.o
cc = g++

.PHONY: all
all: $(objects)

svg_radial_gradient.o: svg_radial_gradient.cpp svg_radial_gradient.h
	$(cc) -c svg_radial_gradient.cpp
svg_g.o: svg_g.cpp svg_g.h
	$(cc) -c svg_g.cpp
svg_mask.o: svg_mask.cpp svg_mask.h
	$(cc) -c svg_mask.cpp
svg_image.o: svg_image.cpp svg_image.h
	$(cc) -c svg_image.cpp
svg_pattern.o: svg_pattern.cpp svg_pattern.h
	$(cc) -c svg_pattern.cpp
svg_marker.o: svg_marker.cpp svg_marker.h
	$(cc) -c svg_marker.cpp
svg_defs.o: svg_defs.cpp svg_defs.h
	$(cc) -c svg_defs.cpp
svg_foreign_object.o: svg_foreign_object.cpp svg_foreign_object.h
	$(cc) -c svg_foreign_object.cpp
svg_linear_gradient.o: svg_linear_gradient.cpp svg_linear_gradient.h
	$(cc) -c svg_linear_gradient.cpp
svg_stop.o: svg_stop.cpp svg_stop.h
	$(cc) -c svg_stop.cpp

.PHONY: all
clean:
	-rm $(objects)
