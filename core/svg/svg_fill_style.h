#include <string>
#ifndef __LZ_SVG_FILL_STYLE__
#define __LZ_SVG_FILL_STYLE__

namespace Lewzen {
    /**
    * Fill style for SVG element.
    */
    class SVGFillStyle {
    private:
        enum class  FillRule;
        
        // fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        std::string _fill;
        // fill opacity
        double _fill_opacity;
        // fill rule
        FillRule _fill_rule;
    public:
        enum class  FillRule { DEFAULT, NONEZERO, EVEN_ODD };

        /**
        * Constructor of fill style.
        */
        SVGFillStyle();
        /**
        * Destructor of fill style.
        */
        ~SVGFillStyle();

        /// Properties
        /**
        * Get the fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @return the fill content.
        */
        const std::string &get_fill() const;
        /**
        * Set the fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @param fill the fill content.
        */
        void set_fill(const std::string &fill);
        /**
        * Get the fill opacity.
        *
        * @return the fill opacity.
        */
        double &get_fill_opacity() const;
        /**
        * Set the fill opacity.
        *
        * @param fill_opacity the fill opacity.
        */
        void set_fill_opacity(const double &fill_opacity);
        /**
        * Get the fill rule.
        *
        * @return the fill rule.
        */
        const FillRule &get_fill_rule() const;
        /**
        * Set the fill rule.
        *
        * @param fill_rule the fill rule.
        */
        void set_fill_rule(const FillRule &fill_rule);

        /// Functional
        /**
        * Parse this fill style to XML properties.
        */
        virtual std::string to_properties() const;
    }
}
#endif  