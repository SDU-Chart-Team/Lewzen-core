#ifndef __LZ_SVG_ELEMENT__
#define __LZ_SVG_ELEMENT__
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "utils.h"

namespace Lewzen {
    /**
    * Rectangle in DOM.
    *
    * according to https://developer.mozilla.org/en-US/docs/Web/API/DOMRect
    */
    class DOMRect {
    private:
        double _x, _y, _width, _height;
    public:
        /**
        * Constructor of DOM Rect.
        */
        DOMRect(const double &x = 0, const double &y = 0, const double &width = 0, const double &height = 0);
        /**
        * Deep copy of DOM Rect.
        */
        DOMRect(const DOMRect &rect);
        /**
        * The x coordinate of the DOMRect's origin (typically the top-left corner of the rectangle).
        */
        double get_x() const;
        /**
        * The x coordinate of the DOMRect's origin (typically the top-left corner of the rectangle).
        */
        double set_x(const double &x);
        /**
        * The y coordinate of the DOMRect's origin (typically the top-left corner of the rectangle).
        */
        double get_y() const;
        /**
        * The y coordinate of the DOMRect's origin (typically the top-left corner of the rectangle).
        */
        double set_y(const double &y);
        /**
        * The width of the DOMRect.
        */
        double get_width() const;
        /**
        * The width of the DOMRect.
        */
        double set_width(const double &width);
        /**
        * The height of the DOMRect.
        */
        double get_height() const;
        /**
        * The height of the DOMRect.
        */
        double set_height(const double &height);
        /**
        * Returns the top coordinate value of the DOMRect (has the same value as y, or y + height if height is negative.)
        */
        double get_top() const;
        /**
        * Returns the top coordinate value of the DOMRect (has the same value as y, or y + height if height is negative.)
        */
        double set_top(const double &top);
        /**
        * Returns the left coordinate value of the DOMRect (has the same value as x, or x + width if width is negative.)
        */
        double get_left() const;
        /**
        * Returns the left coordinate value of the DOMRect (has the same value as x, or x + width if width is negative.)
        */
        double set_left(const double &left);
        /**
        * Returns the bottom coordinate value of the DOMRect (has the same value as y + height, or y if height is negative.)
        */
        double get_bottom() const;
        /**
        * Returns the bottom coordinate value of the DOMRect (has the same value as y + height, or y if height is negative.)
        */
        double set_bottom(const double &bottom);
        /**
        * Returns the right coordinate value of the DOMRect (has the same value as x + width, or x if width is negative.)
        */
        double get_right() const;
        /**
        * Returns the right coordinate value of the DOMRect (has the same value as x + width, or x if width is negative.)
        */
        double set_right(const double &right);
    };
    /**
    * Matrix in DOM.
    *
    * according to https://developer.mozilla.org/en-US/docs/Web/API/DOMMatrix
    */
    class DOMMatrix {
    private:
        bool _2d, _identity;
        double _m11, _m12, _m13, _m14, _m21, _m22, _m23, _m24, _m31, _m32, _m33, _m34, _m41, _m42, _m43, _m44;
    public:
        /**
        * Constructor of DOM Matrix, 3D.
        */
        DOMMatrix(const double &m11, const double &m12, const double &m13, const double &m14, const double &m21, const double &m22, const double &m23, const double &m24, const double &m31, const double &m32, const double &m33, const double &m34, const double &m41, const double &m42, const double &m43, const double &m44);
        /**
        * Constructor of DOM Matrix, 2D.
        */
        DOMMatrix(const double &a = 1, const double &b = 0, const double &c = 0, const double &d = 1, const double &e = 0, const double &f = 0);
        /**
        * Constructor of DOM Matrix. If size is 6, 2D; else if size is 16, 3D; else, lower case and zero fill.
        */
        DOMMatrix(const double *mat, int size);
        /**
        * Deep copy of DOM Matrix.
        */
        DOMMatrix(const DOMMatrix &matrix);
        /**
        * A Boolean flag whose value is true if the matrix was initialized as a 2D matrix. If false, the matrix is 3D.
        */
        const bool is2D() const;
        /**
        * A Boolean whose value is true if the matrix is the identity matrix. The identity matrix is one in which every value is 0 except those on the main diagonal from top-left to bottom-right corner (in other words, where the offsets in each direction are equal).
        */
        const bool isIdentity() const;
        /**
        * Set matrix by given double array. If size is 6, 2D; else if size is 16, 3D; else, lower case and zero fill.
        */
        void set_matrix(const double *mat, int size);
        /**
        * Return double array of this matrix.
        */
        const double *get_matrix() const;
        /**
        * Modifies the matrix by inverting it. If the matrix can't be inverted, its components are all set to NaN, and is2D returns false.
        */
        DOMMatrix &invert_self();
        /**
        * Modifies the matrix by post-multiplying it with the specified DOMMatrix. This is equivalent to the dot product A⋅B, where matrix A is the source matrix and B is the matrix given as an input to the method. Returns itself.
        */
        DOMMatrix &multiplySelf(const DOMMatrix &matrix);
        /**
        * Modifies the matrix by pre-multiplying it with the specified DOMMatrix. This is equivalent to the dot product B⋅A, where matrix A is the source matrix and B is the matrix given as an input to the method. Returns itself.
        */
        DOMMatrix &preMultiplySelf(const DOMMatrix &matrix);
        /**
        * Modifies the matrix by applying the specified vector. The default vector is [0, 0, 0]. Returns itself.
        */
        DOMMatrix &translateSelf(const double &v1, const double &v2, const double &v3);
        /**
        * Modifies the matrix by applying the specified scaling factors, with the center located at the specified origin. Also returns itself. By default, the scaling factor is 1 for all three axes, and the origin is (0, 0, 0). Returns itself.
        */
        DOMMatrix &scaleSelf(const double &v1, const double &v2, const double &v3);
        /**
        * Modifies the matrix by applying the specified scaling factor to all three axes, centered on the given origin. Returns itself.
        */
        DOMMatrix &scale3dSelf(const double &v1, const double &v2, const double &v3);
        /**
        * Modifies the matrix by rotating itself around each axis by the specified number of degrees. Returns itself.
        */
        DOMMatrix &rotateSelf(const double &thetaX, const double &thetY, const double &thetZ);
        /**
        * Modifies the matrix by rotating it by the specified angle around the given vector. Returns itself.
        */
        DOMMatrix &rotateAxisAngleSelf(const double &v1, const double &v2, const double &v3, const double &theta);
        /**
        * Modifies the matrix by rotating it by the angle between the specified vector and (1, 0). Returns itself.
        */
        DOMMatrix &rotateFromVectorSelf(const double &v1, const double &v2, const double &v3, const double &theta);
        /**
        * Modifies the matrix by applying the specified skew transformation along the X-axis. Returns itself.
        */
        DOMMatrix &skewXSelf(const double &theta);
        /**
        * Modifies the matrix by applying the specified skew transformation along the Y-axis. Returns itself.
        */
        DOMMatrix &skewYSelf(const double &theta);
    };
    /**
    * Point in DOM.
    *
    * according to https://developer.mozilla.org/en-US/docs/Web/API/DOMPoint
    */
    class DOMPoint {
    private:
        double _x, _y, _z, _w;
    public:
        /**
        * Constructor of DOM Point.
        */
        DOMPoint(const double &x = 0, const double &y = 0, const double &z = 0, const double &w = 0);
        /**
        * Deep copy of DOM Point.
        */
        DOMPoint(const DOMPoint &point);
        /**
        * The x coordinate of the DOMPoint.
        */
        double get_x() const;
        /**
        * The x coordinate of the DOMPoint.
        */
        double set_x(const double &x);
        /**
        * The y coordinate of the DOMPoint.
        */
        double get_y() const;
        /**
        * The y coordinate of the DOMPoint.
        */
        double set_y(const double &y);
        /**
        * The z coordinate of the DOMPoint.
        */
        double get_z() const;
        /**
        * The z coordinate of the DOMPoint.
        */
        double set_z(const double &z);
        /**
        * The perspective value of the DOMPoint.
        */
        double get_w() const;
        /**
        * The perspective value of the DOMPoint.
        */
        double set_w(const double &w);
    };
    

    /**
    * An SVG element.
    */
    class SVGElement {
    public:
        /**
        * Constructor of SVG element.
        */
        SVGElement();
        /**
        * Deep copy of SVG element.
        */
        SVGElement(const SVGElement &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const;

        /// Class
    public:
        std::set<std::string> _classes;
        /**
        * Add a class to this SVG element.
        *
        * @param cls a class.
        */
        void add_class(const std::string &cls);
        /**
        * Remove a class from this SVG element.
        *
        * @param cls a class.
        */
        void remove_class(const std::string &cls);
        /**
        * Get all classes from this SVG element, readonly.
        *
        * @return classes, readonly.
        */
        const std::set<std::string> get_classes() const;
        /**
        * Set classes list in this SVG element.
        *
        * @param cls_list classes list.
        */
        void set_inner_elements(const std::set<std::string> &cls_list);
        /**
        * Get classes list in this SVG element.
        *
        * @return class attributes.
        */
        const std::string get_class_attributes() const;

        /// Presentation Attributes
    private:
        std::string _clip_path;
    public:
        enum class ClipRule { NONZERO, EVENODD, INHERIT };
    private:
        ClipRule _clip_rule;
    private:
        std::string _color;
    public:
        enum class ColorInterpolation { AUTO, S_RGB, LINEAR_RGB };
    private:
        ColorInterpolation _color_interpolation;
    public:
        enum class Cursor { AUTO, CROSSHAIR, DEFAULT, POINTER, MOVE, E_RESIZE, NE_RESIZE, NW_RESIZE, N_RESIZE, SE_RESIZE, SW_RESIZE, S_RESIZE, W_RESIZE, TEXT, WAIT, HELP, INHERIT };
    private:
        Cursor _cursor;
    private:
        std::string _display;
    private:
        std::string _fill;
    private:
        double _fill_opacity;
    public:
        enum class FillRule { NONZERO, EVENODD };
    private:
        FillRule _fill_rule;
    private:
        std::string _filter;
    private:
        std::string _mask;
    private:
        double _opacity;
    public:
        enum class PointerEvents { BOUNDING_BOX, VISIBLE_PAINTED, VISIBLE_FILL, VISIBLE_STROKE, VISIBLE, PAINTED, FILL, STROKE, ALL, NONE };
    private:
        PointerEvents _pointer_events;
    public:
        enum class ShapeRendering { AUTO, OPTIMIZE_SPEED, CRISP_EDGES, GEOMETRIC_PRECISION };
    private:
        ShapeRendering _shape_rendering;
    private:
        std::string _stroke;
    private:
        std::string _stroke_dasharray;
    private:
        double _stroke_dashoffset;
    public:
        enum class StrokeLinecap { BUTT, ROUND, SQUARE };
    private:
        StrokeLinecap _stroke_linecap;
    public:
        enum class StrokeLinejoin { ARCS, BEVEL, MITER, MITER_CLIP, ROUND };
    private:
        StrokeLinejoin _stroke_linejoin;
    private:
        double _stroke_miterlimit;
    private:
        double _stroke_opacity;
    private:
        double _stroke_width;
    private:
        std::string _transform;
    public:
        enum class VectorEffect { NONE, NON_SCALING_STROKE, NON_SCALING_SIZE, NON_ROTATION, FIXED_POSITION };
    private:
        VectorEffect _vector_effect;
    public:
        enum class Visibility { VISIBLE, HIDDEN, COLLAPSE };
    private:
        Visibility _visibility;
    public:
        /**
        * Get a clipping path with the element it is related to.
        *
        * @return a clipping path with the element it is related to.
        */
        const std::string get_clip_path() const;
        /**
        * Set a clipping path with the element it is related to.
        *
        * @param clip_path a clipping path with the element it is related to.
        */
        void set_clip_path(const std::string &clip_path);
        /**
        * Get only applies to graphics elements that are contained within a <clipPath> element. basically works as the fill-rule attribute, except that it applies to <clipPath> definitions.
        *
        * @return only applies to graphics elements that are contained within a <clipPath> element. basically works as the fill-rule attribute, except that it applies to <clipPath> definitions.
        */
        const ClipRule get_clip_rule() const;
        /**
        * Set only applies to graphics elements that are contained within a <clipPath> element. basically works as the fill-rule attribute, except that it applies to <clipPath> definitions.
        *
        * @param clip_rule only applies to graphics elements that are contained within a <clipPath> element. basically works as the fill-rule attribute, except that it applies to <clipPath> definitions.
        */
        void set_clip_rule(const ClipRule &clip_rule);
        /**
        * Get used to provide a potential indirect value, currentcolor, for the fill, stroke, stop-color, flood-color, and lighting-color attributes.
        *
        * @return used to provide a potential indirect value, currentcolor, for the fill, stroke, stop-color, flood-color, and lighting-color attributes.
        */
        const std::string get_color() const;
        /**
        * Set used to provide a potential indirect value, currentcolor, for the fill, stroke, stop-color, flood-color, and lighting-color attributes.
        *
        * @param color used to provide a potential indirect value, currentcolor, for the fill, stroke, stop-color, flood-color, and lighting-color attributes.
        */
        void set_color(const std::string &color);
        /**
        * Get specifies the color space for gradient interpolations, color animations, and alpha compositing.
        *
        * @return specifies the color space for gradient interpolations, color animations, and alpha compositing.
        */
        const ColorInterpolation get_color_interpolation() const;
        /**
        * Set specifies the color space for gradient interpolations, color animations, and alpha compositing.
        *
        * @param color_interpolation specifies the color space for gradient interpolations, color animations, and alpha compositing.
        */
        void set_color_interpolation(const ColorInterpolation &color_interpolation);
        /**
        * Get specifies the mouse cursor displayed when the mouse pointer is over an element.
        *
        * @return specifies the mouse cursor displayed when the mouse pointer is over an element.
        */
        const Cursor get_cursor() const;
        /**
        * Set specifies the mouse cursor displayed when the mouse pointer is over an element.
        *
        * @param cursor specifies the mouse cursor displayed when the mouse pointer is over an element.
        */
        void set_cursor(const Cursor &cursor);
        /**
        * Get control the rendering of graphical or container elements.
        *
        * @return control the rendering of graphical or container elements.
        */
        const std::string get_display() const;
        /**
        * Set control the rendering of graphical or container elements.
        *
        * @param display control the rendering of graphical or container elements.
        */
        void set_display(const std::string &display);
        /**
        * Get for shapes and text it's a presentation attribute that defines the color (or any SVG paint servers like gradients or patterns) used to paint the element; for animation it defines the final state of the animation. eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @return for shapes and text it's a presentation attribute that defines the color (or any SVG paint servers like gradients or patterns) used to paint the element; for animation it defines the final state of the animation. eg: 'red', '#FFFFFF', 'url(#my_define)'.
        */
        const std::string get_fill() const;
        /**
        * Set for shapes and text it's a presentation attribute that defines the color (or any SVG paint servers like gradients or patterns) used to paint the element; for animation it defines the final state of the animation. eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @param fill for shapes and text it's a presentation attribute that defines the color (or any SVG paint servers like gradients or patterns) used to paint the element; for animation it defines the final state of the animation. eg: 'red', '#FFFFFF', 'url(#my_define)'.
        */
        void set_fill(const std::string &fill);
        /**
        * Get a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to a shape.
        *
        * @return a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to a shape.
        */
        double get_fill_opacity() const;
        /**
        * Set a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to a shape.
        *
        * @param fill_opacity a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to a shape.
        */
        void set_fill_opacity(const double &fill_opacity);
        /**
        * Get a presentation attribute defining the algorithm to use to determine the inside part of a shape.
        *
        * @return a presentation attribute defining the algorithm to use to determine the inside part of a shape.
        */
        const FillRule get_fill_rule() const;
        /**
        * Set a presentation attribute defining the algorithm to use to determine the inside part of a shape.
        *
        * @param fill_rule a presentation attribute defining the algorithm to use to determine the inside part of a shape.
        */
        void set_fill_rule(const FillRule &fill_rule);
        /**
        * Get specifies the filter effects defined by the <filter> element that shall be applied to its element.
        *
        * @return specifies the filter effects defined by the <filter> element that shall be applied to its element.
        */
        const std::string get_filter() const;
        /**
        * Set specifies the filter effects defined by the <filter> element that shall be applied to its element.
        *
        * @param filter specifies the filter effects defined by the <filter> element that shall be applied to its element.
        */
        void set_filter(const std::string &filter);
        /**
        * Get a presentation attribute mainly used to bind a given <mask> element with the element the attribute belongs to.
        *
        * @return a presentation attribute mainly used to bind a given <mask> element with the element the attribute belongs to.
        */
        const std::string get_mask() const;
        /**
        * Set a presentation attribute mainly used to bind a given <mask> element with the element the attribute belongs to.
        *
        * @param mask a presentation attribute mainly used to bind a given <mask> element with the element the attribute belongs to.
        */
        void set_mask(const std::string &mask);
        /**
        * Get specifies the transparency of an object or of a group of objects, that is, the degree to which the background behind the element is overlaid.
        *
        * @return specifies the transparency of an object or of a group of objects, that is, the degree to which the background behind the element is overlaid.
        */
        double get_opacity() const;
        /**
        * Set specifies the transparency of an object or of a group of objects, that is, the degree to which the background behind the element is overlaid.
        *
        * @param opacity specifies the transparency of an object or of a group of objects, that is, the degree to which the background behind the element is overlaid.
        */
        void set_opacity(const double &opacity);
        /**
        * Get a presentation attribute that allows defining whether or when an element may be the target of a mouse event.
        *
        * @return a presentation attribute that allows defining whether or when an element may be the target of a mouse event.
        */
        const PointerEvents get_pointer_events() const;
        /**
        * Set a presentation attribute that allows defining whether or when an element may be the target of a mouse event.
        *
        * @param pointer_events a presentation attribute that allows defining whether or when an element may be the target of a mouse event.
        */
        void set_pointer_events(const PointerEvents &pointer_events);
        /**
        * Get provides hints to the renderer about what tradeoffs to make when rendering shapes like paths, circles, or rectangles.
        *
        * @return provides hints to the renderer about what tradeoffs to make when rendering shapes like paths, circles, or rectangles.
        */
        const ShapeRendering get_shape_rendering() const;
        /**
        * Set provides hints to the renderer about what tradeoffs to make when rendering shapes like paths, circles, or rectangles.
        *
        * @param shape_rendering provides hints to the renderer about what tradeoffs to make when rendering shapes like paths, circles, or rectangles.
        */
        void set_shape_rendering(const ShapeRendering &shape_rendering);
        /**
        * Get a presentation attribute defining the color (or any SVG paint servers like gradients or patterns) used to paint the outline of the shape.
        *
        * @return a presentation attribute defining the color (or any SVG paint servers like gradients or patterns) used to paint the outline of the shape.
        */
        const std::string get_stroke() const;
        /**
        * Set a presentation attribute defining the color (or any SVG paint servers like gradients or patterns) used to paint the outline of the shape.
        *
        * @param stroke a presentation attribute defining the color (or any SVG paint servers like gradients or patterns) used to paint the outline of the shape.
        */
        void set_stroke(const std::string &stroke);
        /**
        * Get a presentation attribute defining the pattern of dashes and gaps used to paint the outline of the shape.
        *
        * @return a presentation attribute defining the pattern of dashes and gaps used to paint the outline of the shape.
        */
        const std::string get_stroke_dasharray() const;
        /**
        * Set a presentation attribute defining the pattern of dashes and gaps used to paint the outline of the shape.
        *
        * @param stroke_dasharray a presentation attribute defining the pattern of dashes and gaps used to paint the outline of the shape.
        */
        void set_stroke_dasharray(const std::string &stroke_dasharray);
        /**
        * Get a presentation attribute defining an offset on the rendering of the associated dash array.
        *
        * @return a presentation attribute defining an offset on the rendering of the associated dash array.
        */
        double get_stroke_dashoffset() const;
        /**
        * Set a presentation attribute defining an offset on the rendering of the associated dash array.
        *
        * @param stroke_dashoffset a presentation attribute defining an offset on the rendering of the associated dash array.
        */
        void set_stroke_dashoffset(const double &stroke_dashoffset);
        /**
        * Get a presentation attribute defining the shape to be used at the end of open subpaths when they are stroked.
        *
        * @return a presentation attribute defining the shape to be used at the end of open subpaths when they are stroked.
        */
        const StrokeLinecap get_stroke_linecap() const;
        /**
        * Set a presentation attribute defining the shape to be used at the end of open subpaths when they are stroked.
        *
        * @param stroke_linecap a presentation attribute defining the shape to be used at the end of open subpaths when they are stroked.
        */
        void set_stroke_linecap(const StrokeLinecap &stroke_linecap);
        /**
        * Get a presentation attribute defining the shape to be used at the corners of paths when they are stroked.
        *
        * @return a presentation attribute defining the shape to be used at the corners of paths when they are stroked.
        */
        const StrokeLinejoin get_stroke_linejoin() const;
        /**
        * Set a presentation attribute defining the shape to be used at the corners of paths when they are stroked.
        *
        * @param stroke_linejoin a presentation attribute defining the shape to be used at the corners of paths when they are stroked.
        */
        void set_stroke_linejoin(const StrokeLinejoin &stroke_linejoin);
        /**
        * Get a presentation attribute defining a limit on the ratio of the miter length to the stroke-width used to draw a miter join. when the limit is exceeded, the join is converted from a miter to a bevel.
        *
        * @return a presentation attribute defining a limit on the ratio of the miter length to the stroke-width used to draw a miter join. when the limit is exceeded, the join is converted from a miter to a bevel.
        */
        double get_stroke_miterlimit() const;
        /**
        * Set a presentation attribute defining a limit on the ratio of the miter length to the stroke-width used to draw a miter join. when the limit is exceeded, the join is converted from a miter to a bevel.
        *
        * @param stroke_miterlimit a presentation attribute defining a limit on the ratio of the miter length to the stroke-width used to draw a miter join. when the limit is exceeded, the join is converted from a miter to a bevel.
        */
        void set_stroke_miterlimit(const double &stroke_miterlimit);
        /**
        * Get a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to the stroke of a shape.
        *
        * @return a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to the stroke of a shape.
        */
        double get_stroke_opacity() const;
        /**
        * Set a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to the stroke of a shape.
        *
        * @param stroke_opacity a presentation attribute defining the opacity of the paint server (color, gradient, pattern, etc) applied to the stroke of a shape.
        */
        void set_stroke_opacity(const double &stroke_opacity);
        /**
        * Get a presentation attribute defining the width of the stroke to be applied to the shape.
        *
        * @return a presentation attribute defining the width of the stroke to be applied to the shape.
        */
        double get_stroke_width() const;
        /**
        * Set a presentation attribute defining the width of the stroke to be applied to the shape.
        *
        * @param stroke_width a presentation attribute defining the width of the stroke to be applied to the shape.
        */
        void set_stroke_width(const double &stroke_width);
        /**
        * Get defines a list of transform definitions that are applied to an element and the element's children.
        *
        * @return defines a list of transform definitions that are applied to an element and the element's children.
        */
        const std::string get_transform() const;
        /**
        * Set defines a list of transform definitions that are applied to an element and the element's children.
        *
        * @param transform defines a list of transform definitions that are applied to an element and the element's children.
        */
        void set_transform(const std::string &transform);
        /**
        * Get specifies the vector effect to use when drawing an object.vector effects are applied before any of the other compositing operations, i.e. filters, masks and clips.
        *
        * @return specifies the vector effect to use when drawing an object.vector effects are applied before any of the other compositing operations, i.e. filters, masks and clips.
        */
        const VectorEffect get_vector_effect() const;
        /**
        * Set specifies the vector effect to use when drawing an object.vector effects are applied before any of the other compositing operations, i.e. filters, masks and clips.
        *
        * @param vector_effect specifies the vector effect to use when drawing an object.vector effects are applied before any of the other compositing operations, i.e. filters, masks and clips.
        */
        void set_vector_effect(const VectorEffect &vector_effect);
        /**
        * Get control the visibility of graphical elements.
        *
        * @return control the visibility of graphical elements.
        */
        const Visibility get_visibility() const;
        /**
        * Set control the visibility of graphical elements.
        *
        * @param visibility control the visibility of graphical elements.
        */
        void set_visibility(const Visibility &visibility);
        
        /// Inner SVG
    private:
        std::string _inner_text;
        std::vector<std::shared_ptr<SVGElement>> _inner_elements;
    public:
        /**
        * Get inner SVG of this SVG element.
        *
        * @return inner SVG.
        */
        const std::string inner_SVG() const;
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        void set_inner_text(const std::string &text);
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        const std::string get_inner_text() const;
        /**
        * Add a class to this SVG element.
        *
        * @param element an inner element.
        */
        void add_inner_element(const std::shared_ptr<SVGElement> &element);
        /**
        * Remove a class from this SVG element.
        *
        * @param element an inner element.
        */
        void remove_inner_element(const std::shared_ptr<SVGElement> &element);
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner elements, readonly.
        */
        const std::vector<std::shared_ptr<SVGElement>> get_inner_elements() const;
        /**
        * Set inner SVG elements list in this SVG element.
        *
        * @param inner_elements inner elements list.
        */
        void set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        virtual const std::string get_attributes() const;

        /// Web Methods
    protected:
        /**
        * Returns a DOMRect representing the computed bounding box of the current element.
        *
        * @return computed bounding box.
        */
        const DOMRect getBBox() const;
        /**
        * Returns a DOMMatrix representing the matrix that transforms the current element's coordinate system to its SVG viewport's coordinate system.
        *
        * @return the matrix.
        */
        const DOMMatrix getCTM() const;
        /**
        * Returns a DOMMatrix representing the matrix that transforms the current element's coordinate system to the coordinate system of the SVG viewport for the SVG document fragment.
        *
        * @return the matrix.
        */
        const DOMMatrix getScreenCTM() const;
        /**
        * Determines whether a given point is within the fill shape of an element. Normal hit testing rules apply; the value of the pointer-events property on the element determines whether a point is considered to be within the fill.
        *
        * @return whether a given point is within.
        */
        const bool isPointInFill() const;
        /**
        * Determines whether a given point is within the stroke shape of an element. Normal hit testing rules apply; the value of the pointer-events property on the element determines whether a point is considered to be within the stroke.
        *
        * @return whether a given point is within.
        */
        const bool isPointInStroke() const;
        /**
        * Returns the user agent's computed value for the total length of the path in user units.
        *
        * @return total length of the path.
        */
        const double getTotalLength() const;
        /**
        * Returns the point at a given distance along the path.
        *
        * @return the point.
        */
        const DOMPoint getPointAtLength() const;

        /// Outer SVG
    public:
        /**
        * Get SVG of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string outer_SVG() const;

        /// Hash
    private:
        HASH_CODE _attribute_hash;
        HASH_CODE _inner_hash;
        HASH_CODE _outer_hash;
    protected:
        /**
        * Update hash of this element.
        *
        * @return hash code.
        */
        void update_hash();
    public:
        /**
        * Get hash of attributes of this element.
        *
        * @return hash code.
        */
        const HASH_CODE get_attribute_hash() const;
        /**
        * Get hash of inner content of this element.
        *
        * @return inner hash code.
        */
        const HASH_CODE get_inner_hash() const;
        /**
        * Get hash of this element, including tag, attributes and inner content.
        *
        * @return outer hash code.
        */
        const HASH_CODE get_outer_hash() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        virtual std::shared_ptr<SVGElement> clone() const;
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGElement
        */
        bool operator==(const SVGElement &element) const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const;
    };
}

#include "svg_element/svg_radial_gradient.h"
#include "svg_element/svg_circle.h"
#include "svg_element/svg_ellipse.h"
#include "svg_element/svg_path.h"
#include "svg_element/svg_line.h"
#include "svg_element/svg_g.h"
#include "svg_element/svg_mask.h"
#include "svg_element/svg_rect.h"
#include "svg_element/svg_image.h"
#include "svg_element/svg_text.h"
#include "svg_element/svg_pattern.h"
#include "svg_element/svg_polyline.h"
#include "svg_element/svg_marker.h"
#include "svg_element/svg_polygon.h"
#include "svg_element/svg_defs.h"
#include "svg_element/svg_foreign_object.h"
#include "svg_element/svg_linear_gradient.h"
#include "svg_element/svg_stop.h"
#include "svg_element/svg_use.h"
#endif