#include <string>
#include "xml_property.h"
#ifndef __LZ_SVG_STROKE_STYLE__
#define __LZ_SVG_STROKE_STYLE__

namespace Lewzen {
    /**
    * Stroke style for SVG element.
    */
    class SVGStrokeStyle {
    public:
        enum class StrokeLinecap { BUTT, SQUARE, ROUND };
        enum class StrokeLinejoin { MITER, ROUND, BEVEL };
    private:
        // stroke content, eg: 'red', '#FFFFFF'.
        std::string _stroke;
        // stroke width
        double _stroke_width;
        // stroke opacity
        double _stroke_opacity;
        // stroke linecap
        StrokeLinecap _stroke_linecap;
        // stroke linejoin
        StrokeLinejoin _stroke_linejoin;
        // stroke miterlimit
        double _stroke_miterlimit;
        // string of stroke dasharray, eg: '2', '2.2 1.6'.
        std::string _stroke_dasharray;
        // stroke dashoffset
        double _stroke_dashoffset;
    public:
         /**
        * Constructor of stroke style.
        */
        SVGStrokeStyle();

        /// Properties
        /**
        * Get the stroke content, eg: 'red', '#FFFFFF'.
        *
        * @return the stroke content.
        */
        const std::string &get_stroke() const;
        /**
        * Set the stroke content, eg: 'red', '#FFFFFF'.
        *
        * @param stroke the stroke content.
        */
        void set_stroke(const std::string &stroke);
        /**
        * Get the stroke width.
        *
        * @return the stroke width.
        */
        double get_stroke_width() const;
        /**
        * Set the stroke width.
        *
        * @param stroke_width the stroke width.
        */
        void set_stroke_width(const double &stroke_width);
        /**
        * Get the stroke opacity.
        *
        * @return the stroke opacity.
        */
        double get_stroke_opacity() const;
        /**
        * Set the stroke opacity.
        *
        * @param stroke_opacity the stroke opacity.
        */
        void set_stroke_opacity(const double &stroke_opacity);
        /**
        * Get the stroke linecap.
        *
        * @return the stroke linecap.
        */
        const StrokeLinecap &get_stroke_linecap() const;
        /**
        * Set the stroke linecap.
        *
        * @param stroke_linecap the stroke linecap.
        */
        void set_stroke_linecap(const StrokeLinecap &stroke_linecap);
        /**
        * Get the stroke linejoin.
        *
        * @return the stroke linejoin.
        */
        const StrokeLinejoin &get_stroke_linejoin() const;
        /**
        * Set the stroke linejoin.
        *
        * @param stroke_linejoin the stroke linejoin.
        */
        void set_stroke_linejoin(const StrokeLinejoin &stroke_linejoin);
        /**
        * Get the stroke miterlimit.
        *
        * @return the stroke miterlimit.
        */
        double get_stroke_miterlimit() const;
        /**
        * Set the stroke miterlimit.
        *
        * @param stroke_miterlimit the stroke miterlimit.
        */
        void set_stroke_miterlimit(const double &stroke_miterlimit);
        /**
        * Get string of stroke dasharray, eg: '2', '2.2 1.6'.
        *
        * @return string of stroke dasharray.
        */
        const std::string &get_stroke_dasharray() const;
        /**
        * Set string of stroke dasharray, eg: '2', '2.2 1.6'.
        *
        * @param stroke string of stroke dasharray.
        */
        void set_stroke_dasharray(const std::string &stroke_dasharray);
        /**
        * Get the stroke dashoffset.
        *
        * @return the stroke dashoffset.
        */
        double get_stroke_dashoffset() const;
        /**
        * Set the stroke dashoffset.
        *
        * @param stroke_dashoffset the stroke dashoffset.
        */
        void set_stroke_dashoffset(const double &stroke_dashoffset);

        /// Functional
        /**
        * Parse this stroke style to XML properties.
        */
        const std::string &to_properties() const override;
    }
}
#endif  