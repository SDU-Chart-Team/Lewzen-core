objects = \
	svgi_radial_gradient.o\
	svgi_circle.o\
	svgi_ellipse.o\
	svgi_path.o\
	svgi_line.o\
	svgi_g.o\
	svgi_mask.o\
	svgi_rect.o\
	svgi_image.o\
	svgi_text.o\
	svgi_pattern.o\
	svgi_polyline.o\
	svgi_marker.o\
	svgi_polygon.o\
	svgi_defs.o\
	svgi_foreign_object.o\
	svgi_linear_gradient.o\
	svgi_svg.o\
	svgi_stop.o\
	svgi_use.o
cc = g++

.PHONY: all
all: $(objects)

svgi_radial_gradient.o: svgi_radial_gradient.cpp svgi_radial_gradient.h
	$(cc) -w -c svgi_radial_gradient.cpp
svgi_circle.o: svgi_circle.cpp svgi_circle.h
	$(cc) -w -c svgi_circle.cpp
svgi_ellipse.o: svgi_ellipse.cpp svgi_ellipse.h
	$(cc) -w -c svgi_ellipse.cpp
svgi_path.o: svgi_path.cpp svgi_path.h
	$(cc) -w -c svgi_path.cpp
svgi_line.o: svgi_line.cpp svgi_line.h
	$(cc) -w -c svgi_line.cpp
svgi_g.o: svgi_g.cpp svgi_g.h
	$(cc) -w -c svgi_g.cpp
svgi_mask.o: svgi_mask.cpp svgi_mask.h
	$(cc) -w -c svgi_mask.cpp
svgi_rect.o: svgi_rect.cpp svgi_rect.h
	$(cc) -w -c svgi_rect.cpp
svgi_image.o: svgi_image.cpp svgi_image.h
	$(cc) -w -c svgi_image.cpp
svgi_text.o: svgi_text.cpp svgi_text.h
	$(cc) -w -c svgi_text.cpp
svgi_pattern.o: svgi_pattern.cpp svgi_pattern.h
	$(cc) -w -c svgi_pattern.cpp
svgi_polyline.o: svgi_polyline.cpp svgi_polyline.h
	$(cc) -w -c svgi_polyline.cpp
svgi_marker.o: svgi_marker.cpp svgi_marker.h
	$(cc) -w -c svgi_marker.cpp
svgi_polygon.o: svgi_polygon.cpp svgi_polygon.h
	$(cc) -w -c svgi_polygon.cpp
svgi_defs.o: svgi_defs.cpp svgi_defs.h
	$(cc) -w -c svgi_defs.cpp
svgi_foreign_object.o: svgi_foreign_object.cpp svgi_foreign_object.h
	$(cc) -w -c svgi_foreign_object.cpp
svgi_linear_gradient.o: svgi_linear_gradient.cpp svgi_linear_gradient.h
	$(cc) -w -c svgi_linear_gradient.cpp
svgi_svg.o: svgi_svg.cpp svgi_svg.h
	$(cc) -w -c svgi_svg.cpp
svgi_stop.o: svgi_stop.cpp svgi_stop.h
	$(cc) -w -c svgi_stop.cpp
svgi_use.o: svgi_use.cpp svgi_use.h
	$(cc) -w -c svgi_use.cpp

.PHONY: all
clean:
	-rm $(objects)
