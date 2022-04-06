#include <unordered_map>
#include <map>
#include <string>
#include <memory>
#include "svg/xml_element.h"
#include "svg/point.h"
#include "svg/svg_element.h"
#include "svg/svg_define.h"
#ifndef __LZ_SVG__
#define __LZ_SVG__

namespace Lewzen {
    /**
    * SVG context, consisting of SVG elements and SVG defines.
    */
    class SVG: public XMLElement {
    private:
        // SVG element id maps to SVG element
        std::unordered_map<const std::string &, std::shared_ptr<SVGElement>> _elements;
        // SVG element maps to SVG element id
        std::unordered_map<std::shared_ptr<SVGElement>, const std::string &> _elements_r;

        // z_index  maps to SVG element id
        std::map<int, const std::string &> _z_index;
        // SVG element id maps to z_index
        std::unordered_map<const std::string &, int> _z_index_r;

        // SVG public define id maps to SVG define
        std::unordered_map<const std::string &, std::shared_ptr<SVGDefine>> _defines;
        // SVG public define maps to SVG public define id
        std::unordered_map<std::shared_ptr<SVGDefine>, const std::string &> _defines_r;

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
        * @param element the SVG element.
        * @param z_index z_index of the SVG element. -1 means automatic allocation.
        */
        void add_element(std::shared_ptr<SVGElement> element, int z_index = -1);
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
        std::shared_ptr<SVGElement> get_element(const std::string &id) const;
        /**
        * Get a SVG element in SVG, where the point locates, with z_index the largest.
        *
        * @param point a point in ComponentCoordinateSystem or ComponentRelativeCoordinateSystem.
        * @return the pointer of the SVG element; NULL for non-exist.
        */
        std::shared_ptr<SVGElement> get_element(const Point2D &point) const;
        /**
        * Get all SVG elements in SVG.
        *
        * @return the pointer list of the SVG elements.
        */
        const std::vector<std::shared_ptr<SVGElement> > get_elements() const;
        /**
        * Get SVG elements in SVG, where the point locates.
        *
        * @param point a point in ComponentCoordinateSystem or ComponentRelativeCoordinateSystem.
        * @return the pointer list of the SVG elements.
        */
        const std::vector<std::shared_ptr<SVGElement> > get_elements(const Point2D &point) const;

        /**
        * Get id of a SVG element.
        *
        * @param element the pointer of the SVG element
        * @return the id of the SVG element.
        */
        const std::string &get_element_id(std::shared_ptr<SVGElement> element) const;
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
        * @param define the SVG define.
        */
        void add_define(std::shared_ptr<SVGDefine> define);
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
        std::shared_ptr<SVGDefine> get_define(const std::string &id) const;
        
        /**
        * Get id of a SVG define.
        *
        * @param define the pointer of the SVG define
        * @return the id of the SVG define.
        */
        const std::string &get_define_id(std::shared_ptr<SVGElement>define) const;
        /**
        * Get id list of SVG defines.
        *
        * @return the list of the SVG defines' id.
        */
        const std::vector<const std::string &> get_defines_id() const;

        /// Functional
        /**
        * Parse this SVG object to XML, in CanvasCoordinateSystem.
        */
        const std::string &to_XML() const override;
        /**
        * Parse this SVG object to XML.
        */
        const std::string &to_XML(const CoordinateSystem &coordinate_system) const;
    }
}
#endif