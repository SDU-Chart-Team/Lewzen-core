#include <string>
#include <memory>
#include "point.h"
#include "xml_element.h"
#include 
#ifndef __LZ_SVG_ELEMENT__
#define __LZ_SVG_ELEMENT__

namespace Lewzen {
    /**
    * A SVG element in SVG context.
    */
    class SVGElement: public XMLElement {
    private:
        // id
        std::string _id;
        // point number maps to way point
        ordered_map<double, std::shared_ptr<Point2D>> _way_points;
        // fill style
        SVGFillStyle _fill_style;
        // stroke style
        SVGStrokeStyle _stroke_style;
    public:
        /**
        * Constructor of SVG Element.
        */
        SVGElement();

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

        /// Way Points
        /**
        * Get all way points in way point list.
        *
        * @return the pointer list of the way points.
        */
        const std::vector<std::shared_ptr<Point2D>> get_way_points() const;
        /**
        * Convert the rank in way point list to way point's number.
        *
        * @param rank the rank in way point list.
        * @return way point's number.
        */
        double rank_to_num(const int &rank) const;
        /**
        * Convert way point's number to the rank in way point list.
        *
        * @param num way point's number.
        * @return the rank in way point list.
        */
        int num_to_rank(const double &num) const;
        /**
        * Get a way point in way point list.
        *
        * @param rank the rank in way point list.
        * @return the pointer of the way point; NULL for non-exist.
        */
       std::shared_ptr<Point2D> get_way_point(const int &rank) const;
        /**
        * Get a way point in way point list.
        *
        * @param num way point's number.
        * @return the pointer of the way point; NULL for non-exist.
        */
       std::shared_ptr<Point2D> get_way_point(const double &num) const;
        /**
        * Add a new way point to way point list.
        *
        * @param way_point the pointer of way point to be added.
        */
        void add_way_point(const double &num, std::shared_ptr<Point2D> way_point);
        /**
        * Remove a SVG element from SVG.
        *
        * @param num way point's number.
        * @return true for successful removal.
        */
        bool remove_way_point(const double &num);

        /// Styles
        /**
        * Get the fill style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        const SVGFillStyle &get_fill_style() const;
        /**
        * Set the fill style of the SVG element.
        *
        * @param fill_style the fill style.
        */
        void set_fill_style(const SVGFillStyle &fill_style);
        /**
        * Get the stroke style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        const SVGStrokeStyle &get_stroke_style() const;
        /**
        * Set the stroke style of the SVG element.
        *
        * @param stroke_style the stroke style.
        */
        void set_stroke_style(const SVGStrokeStyle &stroke_style);

        /// Functional
        /**
        * Parse this SVG element object to XML. (Unimplemented)
        */
        virtual const std::string &to_XML(const CoordinateSystem &coordinate_system_system) const = 0;
    }
}
#endif