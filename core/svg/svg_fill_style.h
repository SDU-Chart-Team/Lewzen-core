#include <string>
#ifndef __LZ_SVG_FILL_STYLE__
#define __LZ_SVG_FILL_STYLE__

namespace Lewzen {
    class SVGFillStyle {
        enum class  FillRule { NONEZERO, EVEN_ODD };
    protected:
        std::string _fill;
        double _fill_opacity;
        FillRule _fill_rule;
    public:
        const std::string &get_fill() const;
        void set_fill(const std::string &fill);
        double &get_fill_opacity() const;
        void set_fill_opacity(const double &fill_opacity);
        const FillRule &get_fill_rule() const;
        void set_fill_rule(const FillRule &fill_rule);
        
        virtual std::string to_properties() const;
    }
}
#endif  