#include <string>
#include "../svg/point.h"
#ifndef __LZ_TEXT_SVG__
#define __LZ_TEXT_SVG__

namespace Lewzen
{
    /**
     * @brief The decorator of text, containing the coordinate system
     *
     */

    class TextSVG
    {
        /**
         * @brief  the translater between ComponentCoordinateSystem and ComponentRelativeCoordinateSystem
         *
         */
        class CoordinateSystemTranslater
        {
        private:
            Point2D _origin;
        };

    private:
        Text _text;
        CoordinateSystemTranslater _tanslater;

        /**
         * @brief generate the text
         *
         * @param text_content
         */
        void _generate_text(std::string text_content);

        /**
         * @brief generate the coordinate system translater
         *
         * @param origin the origin of the ComponentRelativeCoordinateSystem
         */
        void _generate_coordinate system_translater(Point2D origin);

    public:
        /**
         * @brief Construct a new Text SVG object
         * genetater text and coordinate system translater
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
         * @param point the point in ComponentCoordinateSystem
         * @return true for the point being in this text SVG
         * @return false
         */
        bool is_in(const Point2D &point) const;
    }
}
#endif