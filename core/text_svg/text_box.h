#include <string>
#include "../svg/point.h"
#ifndef __LZ_TEXT_BOX__
#define __LZ_TEXT_BOX__

namespace Lewzen
{

    /**
     * @brief  the translater between Component Coordinate System and CAN
     *
     */
    class CoordinateTranslater
    {
    private:
        Point2D _text_box_origin;
        Point2D _COM_origin;

    public:
        /**
         * @brief Construct a new Coordinate Translater object
         *
         */
        CoordinateTranslater();

        /**
         * @brief Destroy the Coordinate Translater object
         *
         */
        ~CoordinateTranslater();

        /**
         * @brief transfer COM point to CAN point
         *
         * @param COM_pos
         * @return Point2D
         */
        Point2D COM_to_CAN(Point2D COM_pos);

        /**
         * @brief transfer CAN point to COM point
         *
         * @param CAN_pos
         * @return Point2D
         */
        Point2D CAN_to_COM(Point2D CAN_pos);

        /**
         * @brief Set the text box origin point
         *
         * @param text_origin
         */
        void set_text_box_origin(Point2D text_origin);

        /**
         * @brief Get the text box origin point
         *
         * @return Point2D
         */
        Point2D get_text_box_origin();

        /**
         * @brief Set the COM origin point
         *
         * @param COM_origin
         */
        void set_COM_origin(Point2D COM_origin);

        /**
         * @brief Get the COM orign point
         *
         * @return Point2D
         */
        Point2D get_COM_orign();
    };

    /**
     * @brief The text box
     *
     */
    class TextBox
    {
    private:
        // the text compoment id in frontend/HTML DOM
        std::string _compoment_id;
        // the string of text HTML
        std::string _text_HTML;
        // record the position in COM, and transfer point into CAN
        CoordinateTranslater _tanslater;

    public:
        /**
         * @brief Construct a new Text Box object
         */
        TextBox();

        /**
         * @brief Destroy the Text Box object
         *
         */
        ~TextBox();

        /**
         * @brief Set the compoment id
         *
         * @param compoment_id
         */
        void set_compoment_id(std::string compoment_id);

        /**
         * @brief Get the compoment id
         *
         * @return std::string
         */
        std::string get_compoment_id();

        /**
         * @brief Set the text HTML string
         *
         * @param text_HTML
         */
        void set_text_HTML(std::string text_HTML);

        /**
         * @brief Get the text HTML string
         *
         * @return std::string
         */
        std::string get_text_HTML();

        /**
         * @brief Set the translater origins: COM_origin and text_box_origin
         *
         * @param COM_origin
         * @param text_box_origin
         */
        void set_translater_origins(Point2D COM_origin, Point2D text_box_origin);

        /**
         * @brief generate js script to transform the frontend compoment
         *
         * @param new_source_code the updated text content
         */
        std::string update_arrange(std::string angle);

        /**
         * @brief update the position of text box
         *
         * @param new_text_box_origin
         */
        void update_position(Point2D new_text_box_origin);

        /**
         * @brief generate a SVG with HTML, according to arrange
         *
         * @return std::string
         */
        std::string to_XML();
    }
}
#endif