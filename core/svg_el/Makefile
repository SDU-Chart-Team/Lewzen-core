objects = \
	svg_radial_gradient.o\
	svg_circle.o\
	svg_ellipse.o\
	svg_path.o\
	svg_line.o\
	svg_g.o\
	svg_mask.o\
	svg_rect.o\
	svg_image.o\
	svg_text.o\
	svg_pattern.o\
	svg_polyline.o\
	svg_marker.o\
	svg_polygon.o\
	svg_defs.o\
	svg_foreign_object.o\
	svg_linear_gradient.o\
	svg_rect.o\
	svg_stop.o\
	svg_use.o
cc = g++

.PHONY: all
all: $(objects)

svg_radial_gradient.o: svg_radial_gradient.cpp svg_radial_gradient.h
	$(cc) -c svg_radial_gradient.cpp
svg_circle.o: svg_circle.cpp svg_circle.h
	$(cc) -c svg_circle.cpp
svg_ellipse.o: svg_ellipse.cpp svg_ellipse.h
	$(cc) -c svg_ellipse.cpp
svg_path.o: svg_path.cpp svg_path.h
	$(cc) -c svg_path.cpp
svg_line.o: svg_line.cpp svg_line.h
	$(cc) -c svg_line.cpp
svg_g.o: svg_g.cpp svg_g.h
	$(cc) -c svg_g.cpp
svg_mask.o: svg_mask.cpp svg_mask.h
	$(cc) -c svg_mask.cpp
svg_rect.o: svg_rect.cpp svg_rect.h
	$(cc) -c svg_rect.cpp
svg_image.o: svg_image.cpp svg_image.h
	$(cc) -c svg_image.cpp
svg_text.o: svg_text.cpp svg_text.h
	$(cc) -c svg_text.cpp
svg_pattern.o: svg_pattern.cpp svg_pattern.h
	$(cc) -c svg_pattern.cpp
svg_polyline.o: svg_polyline.cpp svg_polyline.h
	$(cc) -c svg_polyline.cpp
svg_marker.o: svg_marker.cpp svg_marker.h
	$(cc) -c svg_marker.cpp
svg_polygon.o: svg_polygon.cpp svg_polygon.h
	$(cc) -c svg_polygon.cpp
svg_defs.o: svg_defs.cpp svg_defs.h
	$(cc) -c svg_defs.cpp
svg_foreign_object.o: svg_foreign_object.cpp svg_foreign_object.h
	$(cc) -c svg_foreign_object.cpp
svg_linear_gradient.o: svg_linear_gradient.cpp svg_linear_gradient.h
	$(cc) -c svg_linear_gradient.cpp
svg_rect.o: svg_rect.cpp svg_rect.h
	$(cc) -c svg_rect.cpp
svg_stop.o: svg_stop.cpp svg_stop.h
	$(cc) -c svg_stop.cpp
svg_use.o: svg_use.cpp svg_use.h
	$(cc) -c svg_use.cpp

.PHONY: all
clean:
	-rm $(objects)
