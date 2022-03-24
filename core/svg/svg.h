#include <unordered_map>
#include <map>
#include <std::string>
#include "point.h"
#include "svg_element.h"
#include "svg_define.h"
#ifndef __LZ_SVG__
#define __LZ_SVG__

namespace Lewzen {
    /**
    * The SVG context, consisting of SVG elements and SVG defines.
    */
    class SVG {
    private:
        // SVG element id maps to SVG element
        std::unordered_map<const std::string, const SVGElement *> _elements;
        // SVG element maps to SVG element id
        std::unordered_map<const SVGElement *, const std::string> _elements_r;

        // z_index  maps to SVG element id
        std::map<int, const std::string> _z_index;
        // SVG element id maps to z_index
        std::unordered_map<const std::string, int> _z_index_r;

        // SVG public define id maps to SVG define
        std::unordered_map<const std::string, const SVGDefine *> _defines;
        // SVG public define maps to SVG public define id
        std::unordered_map<const SVGElement *, const std::string> _elements_r;

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
        * @param z_index z_index of the SVG element. -1 means automatic allocation.
        */
        void add_element(const std::string &id, SVGElement *element, int z_index = -1);
        /**
        * Remove a SVG element from SVG.
        *
        * @param id the id of SVG element in this SVG.
        * @param destory whether to destory SVG element object.
        * @return true for successful removal.
        */
        bool remove_element(const std::string &id, const bool &destory);

        /**
        * Get a SVG element in SVG.
        *
        * @param id the id of SVG element in this SVG.
        * @return the pointer of the SVG element; NULL for non-exist.
        */
        SVGElement *get_element(const std::string &id) const;
        /**
        * Get a SVG element in SVG, where the point locates, with z_index the largest.
        *
        * @param id the id of SVG element in this SVG.
        * @return the pointer of the SVG element; NULL for non-exist.
        */
        SVGElement *get_element(const Point2D &point) const;
        /**
        * Get all SVG elements in SVG.
        *
        * @return the pointer list of the SVG elements.
        */
        const std::vector<SVGElement *> get_elements() const;
        /**
        * Get SVG elements in SVG, where the point locates.
        *
        * @param id the id of SVG element in this SVG.
        * @return the pointer list of the SVG elements.
        */
        const std::vector<SVGElement *> get_elements(const Point2D &point) const;

        /**
        * Get id of a SVG element.
        *
        * @return the pointer list of the SVG elements.
        */
        const std::string &get_element_id(const SVGElement *element) const;
        /**
        * Get id list of SVG elements.
        *
        * @return the list of the SVG elements' id.
        */
        const std::vector<const std::string &> get_elements_id() const;
        
        /// Z-Index
        /**
        * Get z_index of a SVG element.
        *
        * @param id the id of SVG element in this SVG.
        * @return the z_index of the SVG element.
        */
        int get_z_index(const std::string &id) const;

        /// Defines
        /**
        * Add a new SVG define to SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @param define the SVG define.
        */
        void add_define(const std::string &id, SVGDefine *define);
        /**
        * Remoev a SVG define in SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @param destory whether to destory SVG define object.
        * @return true for successfully removal.
        */
        bool remove_define(const std::string &id, const bool destory);
        /**
        * Get a SVG define in SVG.
        *
        * @param id the id of SVG define in this SVG.
        * @return the pointer of the SVG define; NULL for non-exist.
        */
        SVGDefine *get_define(const std::string &id) const;
        
        /**
        * Get id of a SVG element.
        *
        * @return the pointer list of the SVG elements.
        */
        const std::string &get_define_id(const SVGElement *element) const;
        /**
        * Get id list of SVG elements.
        *
        * @return the list of the SVG elements' id.
        */
        const std::vector<const std::string&> get_defines_id() const;

        /// Functional
        /**
        * Parse this SVG object to XML.
        */
        std::string to_XML() const;
        /**
        * Determine if a point is inside this SVG.
        *
        * @param point the point, must in Component Coordinate System or Component Relative Coordinate System.
        * @return true for the point being in this SVG.
        */
        bool is_in(const Point2D &point) const;
    }
}
#endif