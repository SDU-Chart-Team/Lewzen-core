#include <string>
#include "../svg/point.h"
#ifndef __LZ_TEXT_SVG__
#define __LZ_TEXT_SVG__

namespace Lewzen
{

    /**
     * @brief  the translater between Component Coordinate System and Component Relative Coordinate System
     *
     */
    class CoordinateTranslater
    {
    private:
        Point2D _origin;

    public:
        Point2D COM2COMR(Point2D COM_pos);
        Point2D COMR2COM(Point2D COMR_pos);
    };

    /**
     * @brief The decorator of text, containing the coordinate
     *
     */
    class TextSVG
    {
    private:
        Text _text;
        CoordinateTranslater _tanslater;

        /**
         * @brief generate the text
         *
         * @param text_content
         */
        void _generate_text(std::string text_content);

        /**
         * @brief generate the coordinate translater
         *
         * @param origin the origin of the Component Relative Coordinate System
         */
        void _generate_coordinate_translater(Point2D origin);

    public:
        /**
         * @brief Construct a new Text SVG object
         * genetater text and coordinate translater
         */
        TextSVG();

        /**
         * @brief Destroy the Text SVG object
         *
         */
        ~TextSVG();

        /**
         * @brief generate the text again when update the text content
         *
         * @param new_source_code the updated text content
         */
        void update(std::string new_source_code);

        /**
         * @brief
         *
         * @param point the point in Component Coordinate System
         * @return true for the point being in this text SVG
         * @return false
         */
        bool is_in(const Point2D &point) const;
    }
}
#endif