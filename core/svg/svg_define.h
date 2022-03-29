#include <string>
#ifndef __LZ_SVG_DEFINE__
#define __LZ_SVG_DEFINE__

namespace Lewzen {
    /**
    * A SVG define in SVG context.
    */
    class SVGDefine {
    private:
        // id
        std::string _id;
    public:
        /**
        * Constructor of stroke style.
        */
        SVGDefine();
        /**
        * Destructor of stroke style.
        */
        ~SVGDefine();

        /// ID
        /**
        * Get element's id.
        *
        * @return element's id.
        */
        const std::string &get_id() const;
        /**
        * Set element's id.
        *
        * @param id element's id.
        */
        void set_id(const std::string &id);
        
        /// Functional
        /**
        * Parse this SVG object to XML.
        */
        virtual std::string to_XML() const;
    }

    // Define for patterns: https://developer.mozilla.org/en-US/docs/Web/SVG/Tutorial/Patterns
    /**
    * A pattern define in SVG context.
    */
    class SVGPattern: public SVGDefine {
    private:
        enum class PatternContentUnits;
        enum class PatternUnits;

        double x;
        double y;
        double width;
        double height;
        PatternContentUnits _pattern_content_units;
        PatternUnits _pattern_units;
    public:
        enum class PatternContentUnits { OBJECT_BOUNDING_BOX, USER_SPACT_ON_USE };
        enum class PatternUnits { OBJECT_BOUNDING_BOX, USER_SPACT_ON_USE };

        /**
        * Get x of offset.
        *
        * @return x of offset.
        */
        double &get_x() const;
        /**
        * Set x of offset.
        *
        * @param x x of offset.
        */
        void set_x(double x);
        /**
        * Get y of offset.
        *
        * @return y of offset.
        */
        double &get_y() const;
        /**
        * Set y of offset.
        *
        * @param y y of offset.
        */
        void set_y(double y);
        /**
        * Get the width.
        *
        * @return the width.
        */
        double &get_width() const;
        /**
        * Set the width.
        *
        * @param width the width.
        */
        void set_width(double width);
        /**
        * Get the height.
        *
        * @return the height.
        */
        double &get_height() const;
        /**
        * Set the height.
        *
        * @param height the height.
        */
        void set_height(double height);
        /**
        * Get the pattern content units.
        *
        * @return the pattern content units.
        */
        const PatternContentUnits &get_pattern_content_units() const;
        /**
        * Set the pattern content units.
        *
        * @param pattern_content_units the pattern content units.
        */
        void set_pattern_content_units(const PatternContentUnits &pattern_content_units);
        /**
        * Get the pattern units.
        *
        * @return the pattern units.
        */
        const PatternUnits &get_pattern_units() const;
        /**
        * Set the pattern units.
        *
        * @param pattern_units the pattern units.
        */
        void set_pattern_units(const PatternUnits &pattern_units);
    }

    // Define for gradients: https://developer.mozilla.org/en-US/docs/Web/SVG/Tutorial/Gradients
    /**
    * A gradient define in SVG context.
    */
    class SVGGradient: public SVGDefine {
    private:
        enum class  SpreadMethod;
        enum class GradientUnits;

        double cx;
        double cy;
        double r;
        double fx;
        double fy;
        SpreadMethod _spread_method;
        GradientUnits _gradient_units;
    public:
        enum class  SpreadMethod { PAD, REFLECT, REPEAT };
        enum class GradientUnits { OBJECT_BOUNDING_BOX, USER_SPACT_ON_USE };
        /**
        * Constructor of gradient.
        */
        SVGGradient();
        /**
        * Destructor of gradient.
        */
        ~SVGGradient();

        /// Properties
        /**
        * Get x of center point.
        *
        * @return x of center point.
        */
        double &get_cx() const;
        /**
        * Set x of center point.
        *
        * @param cx x of center point.
        */
        void set_cx(double cx);
        /**
        * Get y of center point.
        *
        * @return y of center point.
        */
        double &get_cy() const;
        /**
        * Set y of center point.
        *
        * @param cy y of center point.
        */
        void set_cy(double cy);
        /**
        * Get the radius.
        *
        * @return the radius.
        */
        double &get_r() const;
        /**
        * Set the radius.
        *
        * @param r the radius.
        */
        void set_r(double r);
        /**
        * Get x of focal point.
        *
        * @return x of focal point.
        */
        double &get_fx() const;
        /**
        * Set x of focal point.
        *
        * @param fx x of focal point.
        */
        void set_fx(double fx);
        /**
        * Get y of focal point.
        *
        * @return y of focal point.
        */
        double &get_fy() const;
        /**
        * Set y of focal point.
        *
        * @param fy y of focal point.
        */
        void set_fy(double fy);
        /**
        * Get the spread method.
        *
        * @return the spread method.
        */
        const SpreadMethod &get_spread_method() const;
        /**
        * Set the spread method.
        *
        * @param spread_method the spread method.
        */
        void set_spread_method(const SpreadMethod &spread_method);
        /**
        * Get the gradient units.
        *
        * @return the gradient units.
        */
        const GradientUnits &get_gradient_units() const;
        /**
        * Set the gradient units.
        *
        * @param gradient_units the gradient units.
        */
        void set_gradient_units(const GradientUnits &gradient_units);

        /// Functional
        /**
        * Parse this gradient to XML.
        */
        std::string to_XML() const;
    }
}
#endif