#include <unordered_map>
#include <map>
#include <string>
#include "point.h"
#include "svg_element.h"
#include "svg_define.h"
#ifndef __LZ_SVG__
#define __LZ_SVG__

namespace Lewzen {
    /**
    * The SVG element.
    */
    class SVGElement {
    private:
        std::map<double, WayPoint *> _way_points;
        FillStyle *_fill_style;
        StrokeStyle *_stroke_style;
    public:
         /**
        * Constructor of SVG Element.
        */
        SVGElement();
        /**
        * Destructor of SVG Element.
        */
        ~SVG();

        /// Way Points
        /**
        * Get all way points in way point list.
        *
        * @return the pointer list of the way points.
        */
        std::vector<WayPoint *> get_way_points();
        /**
        * Convert the rank in way point list to way point's number.
        *
        * @param rank the rank in way point list.
        * @return way point's number.
        */
        double rank_to_num(int rank);
        /**
        * Convert way point's number to the rank in way point list.
        *
        * @param num way point's number.
        * @return the rank in way point list.
        */
        double num_to_rank(double num);
        /**
        * Get a way point in way point list.
        *
        * @param rank the rank in way point list.
        * @return the pointer of the way point; NULL for non-exist.
        */
        WayPoint *get_way_point(int rank);
        /**
        * Get a way point in way point list.
        *
        * @param num way point's number.
        * @return the pointer of the way point; NULL for non-exist.
        */
        WayPoint *get_way_point(double num);
        /**
        * Add a new way point to way point list.
        *
        * @param way_point the pointer of way point to be added.
        */
        void add_way_point(WayPoint *way_point);
        /**
        * Remove a SVG element from SVG.
        *
        * @param num way point's number.
        * @return true for successful removal.
        */
        bool remove_way_point(double num);

        /// Styles
        /**
        * Get the fill style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        FillStyle *get_fill_style();
        /**
        * Copy and set the fill style of the SVG element.
        *
        * @param fill_style_to_copy the fill style to copy.
        */
        FillStyle *set_fill_style(FillStyle &fill_style_to_copy);
        /**
        * Get the stroke style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        StrokeStyle *get_stroke_style();
        /**
        * Copy and set the stroke style of the SVG element.
        *
        * @param stroke_style_to_copy the stroke style to copy.
        */
        StrokeStyle *set_stroke_style(StrokeStyle &stroke_style_to_copy);

        /// Functional
        /**
        * Parse this SVG element object to XML.
        */
        string to_XML();
        /**
        * Determine if a point is inside this SVG element.
        *
        * @param point the point, must in Component Coordinate System or Component Relative Coordinate System.
        * @return true for the point being in this SVG element.
        */
        bool is_in(const Point2D &point);
    }

    /**
    * The SVG context, consisting of SVG elements and SVG defines.
    */
    class SVG {
    private:
        // SVG element map
        std::unordered_map<const std::string &, const SVGElement *> _elements;
        // SVG public defines
        std::unordered_map<const std::string &, const SVGDefine *> _defines;
    public:
         /**
        * Constructor of SVG.
        */
        SVG();
        /**
        * Destructor of SVG.
        */
        ~SVG();

        /// Elements
        /**
        * Add a new SVG element to SVG.
        *
        * @param id the id of SVG element in this SVG.
        * @param element the SVG element.
        */
        void add_element(const SVGElement *element);
        /**
        * Remove a SVG element from SVG.
        *
        * @param id the id of SVG element in this SVG.
        * @param destory whether to destory SVG element object.
        * @return true for successful removal.
        */
        bool remove_element(const string &id, const bool destory);

        /**
        * Get a SVG element in SVG.
        *
        * @param id the id of SVG element in this SVG.
        * @return the pointer of the SVG element; NULL for non-exist.
        */
        SVGElement *get_element(const string &id);
        /**
        * Get all SVG elements in SVG.
        *
        * @return the pointer list of the SVG elements.
        */
        std::vector<SVGElement *> get_elements();
        /**
        * Get SVG elements in SVG, where the point locates.
        *
        * @param id the id of SVG element in this SVG.
        * @return the pointer list of the SVG elements.
        */
        std::vector<SVGElement *> get_elements(const Point2D &point);

        /// Defines
        /**
        * Add a new SVG define to SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @param define the SVG define.
        */
        void add_define(const SVGDefine *define);
        /**
        * Remoev a SVG define in SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @param destory whether to destory SVG define object.
        * @return true for successfully removal.
        */
        bool remove_define(const string &id, const bool destory);
        /**
        * Get a SVG define in SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @return the pointer of the SVG define; NULL for non-exist.
        */
        SVGdefine *get_define(const string &id);

        /// Functional
        /**
        * Parse this SVG object to XML.
        */
        string to_XML();
        /**
        * Determine if a point is inside this SVG.
        *
        * @param point the point, must in Component Coordinate System or Component Relative Coordinate System.
        * @return true for the point being in this SVG.
        */
        bool is_in(const Point2D &point);
    }
}
#endif