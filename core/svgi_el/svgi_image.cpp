#include "svgi_image.h"

namespace Lewzen {
    SVGIImage::SVGIImage(): SVGIElement() { SVGIImage::_bind_getter_setter(); }
    void SVGIImage::_bind_getter_setter() {
        std::function<const std::string()> _getter_width = std::bind(&SVGImage::get_width, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGImage::set_width, (SVGImage *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[0]), Width.callback_bind_func(_attr_on_bind[0]), Width.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_height = std::bind(&SVGImage::get_height, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGImage::set_height, (SVGImage *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[1]), Height.callback_bind_func(_attr_on_bind[1]), Height.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_x = std::bind(&SVGImage::get_x, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGImage::set_x, (SVGImage *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[2]), X.callback_bind_func(_attr_on_bind[2]), X.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_y = std::bind(&SVGImage::get_y, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGImage::set_y, (SVGImage *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[3]), Y.callback_bind_func(_attr_on_bind[3]), Y.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_href = std::bind(&SVGImage::get_href, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_href = std::bind(&SVGImage::set_href, (SVGImage *)this, std::placeholders::_1);
        Href.set_getter(_getter_href), Href.set_setter(_setter_href);
        Href.callback_assign(_attr_on_assign[4]), Href.callback_bind_func(_attr_on_bind[4]), Href.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_xlinkZhref = std::bind(&SVGImage::get_xlinkZhref, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_xlinkZhref = std::bind(&SVGImage::set_xlinkZhref, (SVGImage *)this, std::placeholders::_1);
        XlinkHref.set_getter(_getter_xlinkZhref), XlinkHref.set_setter(_setter_xlinkZhref);
        XlinkHref.callback_assign(_attr_on_assign[5]), XlinkHref.callback_bind_func(_attr_on_bind[5]), XlinkHref.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_preserve_aspect_ratio = std::bind(&SVGImage::get_preserve_aspect_ratio, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_preserve_aspect_ratio = std::bind(&SVGImage::set_preserve_aspect_ratio, (SVGImage *)this, std::placeholders::_1);
        PreserveAspectRatio.set_getter(_getter_preserve_aspect_ratio), PreserveAspectRatio.set_setter(_setter_preserve_aspect_ratio);
        PreserveAspectRatio.callback_assign(_attr_on_assign[6]), PreserveAspectRatio.callback_bind_func(_attr_on_bind[6]), PreserveAspectRatio.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_crossorigin = std::bind(&SVGImage::get_crossorigin, (SVGImage *)this);
        std::function<void(const std::string &)> _setter_crossorigin = std::bind(&SVGImage::set_crossorigin, (SVGImage *)this, std::placeholders::_1);
        Crossorigin.set_getter(_getter_crossorigin), Crossorigin.set_setter(_setter_crossorigin);
        Crossorigin.callback_assign(_attr_on_assign[7]), Crossorigin.callback_bind_func(_attr_on_bind[7]), Crossorigin.callback_bind_ptr(_attr_on_bind[7]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIImage::get_tag() const {
        return "image";
    }
    const std::string SVGIImage::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIImage::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        for (auto &i : modified) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIImage::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIImage> SVGIImage::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIImage>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIImage::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIImage &SVGIImage::operator=(const SVGIImage &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Width = element.Width;
        Height = element.Height;
        X = element.X;
        Y = element.Y;
        Href = element.Href;
        XlinkHref = element.XlinkHref;
        PreserveAspectRatio = element.PreserveAspectRatio;
        Crossorigin = element.Crossorigin;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIImage::operator-(const SVGElement &element) const {
        return SVGImage::operator-(element);
    }
}
