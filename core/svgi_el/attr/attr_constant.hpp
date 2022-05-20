#ifndef __LZ_ATTR_CONSTANT__
#define __LZ_ATTR_CONSTANT__
#include <sstream>
#include "../../utils.h"
#include <sstream>
#include <functional>
#include <memory>

namespace Lewzen {
    template<char const *const_val>
    class AttrConstant {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
        std::string _const_val = const_val;
    public:
        /**
        * Empty constructor of Constant.
        */
        AttrConstant() {}
        /**
        * Constructor of Constant, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrConstant(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}

        /**
        * Set getter of Constant this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
        }
        /**
        * Set setter of Constant this attribute.
        *
        * @param setter setter function
        */
        void set_setter(std::function<void(const std::string &)> setter) {
            _setter = setter;
        }
        /**
        * Return attribute string, from getter.
        *
        * @return attribute string.
        */
        const std::string get() const {
            if (!_getter) return STR_NULL;
            return _getter();
        }
        /**
        * Return attribute string to be committed.
        *
        * @return attribute string.
        */
        const std::string get_commit() const {
            if (!_commit) return STR_NULL;
            return _commit();   
        }
        /**
        * Commit binding or value by setter.
        */
        void commit() {
            if (!_setter || !_commit) return;
            _setter(_commit());
        }

    public:
        /**
        * Set attribute from value, conver to string. This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr)  {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
        }
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrConstant &operator=(const T &attr)  {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
            return *this;
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(std::function<const T()>bind_func)  {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrConstant &operator[](std::function<const T()>bind_func) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
            return *this;
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrConstant &operator[](const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrConstant.set with no implementation. Reset value.")
            return *this;
        }
    
    private:
        std::string _con_val_legal_string;
        const std::string _from_con_val_legal_string() {
            return legal_string_to_string(_con_val_legal_string);
        }
        std::function<const std::string()> _bind_func_legal_string;
        const std::string _from_bind_func_legal_string() {
            return legal_string_to_string(_bind_func_legal_string());
        }
        std::weak_ptr<std::string> _bind_ptr_legal_string;
        const std::string _from_bind_ptr_legal_string() {
            if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert legal string to string of Constant.
        */
        std::string legal_string_to_string(const std::string &attr) {
            if (!is_legal_string(attr)) {
                _LZ_WARNING("Illegal string when converting \"" << attr << "\" to " << _const_val << ".")
                return STR_NULL;
            } else {
                return attr;
            }
        }
    public:
        /**
        * Set attribute from legal string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        void set(const std::string &attr) {
            _con_val_legal_string = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrConstant::_from_con_val_legal_string, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from legal string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        AttrConstant &operator=(const std::string &attr) {
            _con_val_legal_string = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrConstant::_from_con_val_legal_string, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Set attribute from legal string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        void set(const char * attr) {
            set(std::string(attr));
        }
        /**
        * Set attribute from legal string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        AttrConstant &operator=(const char * attr) {
            operator=(std::string(attr));
            return *this;
        }
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::string()> bind_func) {
            _bind_func_legal_string = bind_func;
            _commit = std::bind(&AttrConstant::_from_bind_func_legal_string, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrConstant &operator[](std::function<const std::string()> bind_func) {
            _bind_func_legal_string = bind_func;
            _commit = std::bind(&AttrConstant::_from_bind_func_legal_string, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::string> &bind_ptr) {
            _bind_ptr_legal_string = bind_ptr;
            _commit = std::bind(&AttrConstant::_from_bind_ptr_legal_string, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrConstant &operator[](const std::weak_ptr<std::string> &bind_ptr) {
            _bind_ptr_legal_string = bind_ptr;
            _commit = std::bind(&AttrConstant::_from_bind_ptr_legal_string, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Check if a string is legal as a Constant attribute.
        */
        bool is_legal_string(const std::string &attr) {
            return attr == _const_val;
        }

        /// Callback
        private:
            std::function<void(const std::string &)> _on_assign = [](const std::string &last){};
            std::function<void()> _on_bind_func = [](){};
            std::function<void()> _on_bind_ptr = [](){};
        public:
            /**
            * Set callback for assignment operation.
            *
            * @param on_assign callback function.
            */
            void callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
            /**
            * Remove callback for assignment operation.
            */
            void callback_assign() { _on_assign = [](const std::string &last){}; }
            /**
            * Set callback for binding function operation.
            *
            * @param on_bind_func callback function.
            */
            void callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
            /**
            * Remove callback for binding function operation.
            */
            void callback_bind_func() { _on_bind_func = [](){}; }
            /**
            * Set callback for binding pointer operation.
            *
            * @param on_bind_ptr callback function.
            */
            void callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
            /**
            * Remove callback for binding pointer operation.
            */
            void callback_bind_ptr() { _on_bind_ptr = [](){}; }
    };

    static const char _const_[] = "";
    using AttrConst = AttrConstant<_const_>;
    static const char _const_100[] = "100";
    using AttrConst100 = AttrConstant<_const_100>;
    static const char _const_200[] = "200";
    using AttrConst200 = AttrConstant<_const_200>;
    static const char _const_300[] = "300";
    using AttrConst300 = AttrConstant<_const_300>;
    static const char _const_400[] = "400";
    using AttrConst400 = AttrConstant<_const_400>;
    static const char _const_500[] = "500";
    using AttrConst500 = AttrConstant<_const_500>;
    static const char _const_600[] = "600";
    using AttrConst600 = AttrConstant<_const_600>;
    static const char _const_700[] = "700";
    using AttrConst700 = AttrConstant<_const_700>;
    static const char _const_800[] = "800";
    using AttrConst800 = AttrConstant<_const_800>;
    static const char _const_900[] = "900";
    using AttrConst900 = AttrConstant<_const_900>;
    static const char _const_Accumulate[] = "accumulate";
    using AttrConstAccumulate = AttrConstant<_const_Accumulate>;
    static const char _const_AfterEdge[] = "after-edge";
    using AttrConstAfterEdge = AttrConstant<_const_AfterEdge>;
    static const char _const_All[] = "all";
    using AttrConstAll = AttrConstant<_const_All>;
    static const char _const_Alphabetic[] = "alphabetic";
    using AttrConstAlphabetic = AttrConstant<_const_Alphabetic>;
    static const char _const_Arcs[] = "arcs";
    using AttrConstArcs = AttrConstant<_const_Arcs>;
    static const char _const_Auto[] = "auto";
    using AttrConstAuto = AttrConstant<_const_Auto>;
    static const char _const_AutoStartReverse[] = "auto-start-reverse";
    using AttrConstAutoStartReverse = AttrConstant<_const_AutoStartReverse>;
    static const char _const_Baseline[] = "baseline";
    using AttrConstBaseline = AttrConstant<_const_Baseline>;
    static const char _const_BeforeEdge[] = "before-edge";
    using AttrConstBeforeEdge = AttrConstant<_const_BeforeEdge>;
    static const char _const_Bevel[] = "bevel";
    using AttrConstBevel = AttrConstant<_const_Bevel>;
    static const char _const_Blink[] = "blink";
    using AttrConstBlink = AttrConstant<_const_Blink>;
    static const char _const_Bold[] = "bold";
    using AttrConstBold = AttrConstant<_const_Bold>;
    static const char _const_Bolder[] = "bolder";
    using AttrConstBolder = AttrConstant<_const_Bolder>;
    static const char _const_BoundingBox[] = "bounding-box";
    using AttrConstBoundingBox = AttrConstant<_const_BoundingBox>;
    static const char _const_Butt[] = "butt";
    using AttrConstButt = AttrConstant<_const_Butt>;
    static const char _const_Center[] = "center";
    using AttrConstCenter = AttrConstant<_const_Center>;
    static const char _const_Central[] = "central";
    using AttrConstCentral = AttrConstant<_const_Central>;
    static const char _const_Collapse[] = "collapse";
    using AttrConstCollapse = AttrConstant<_const_Collapse>;
    static const char _const_CrispEdges[] = "crispEdges";
    using AttrConstCrispEdges = AttrConstant<_const_CrispEdges>;
    static const char _const_Currentcolor[] = "currentcolor";
    using AttrConstCurrentcolor = AttrConstant<_const_Currentcolor>;
    static const char _const_Default[] = "default";
    using AttrConstDefault = AttrConstant<_const_Default>;
    static const char _const_End[] = "end";
    using AttrConstEnd = AttrConstant<_const_End>;
    static const char _const_Evenodd[] = "evenodd";
    using AttrConstEvenodd = AttrConstant<_const_Evenodd>;
    static const char _const_Fill[] = "fill";
    using AttrConstFill = AttrConstant<_const_Fill>;
    static const char _const_GeometricPrecision[] = "geometricPrecision";
    using AttrConstGeometricPrecision = AttrConstant<_const_GeometricPrecision>;
    static const char _const_Hanging[] = "hanging";
    using AttrConstHanging = AttrConstant<_const_Hanging>;
    static const char _const_Hidden[] = "hidden";
    using AttrConstHidden = AttrConstant<_const_Hidden>;
    static const char _const_Ideographic[] = "ideographic";
    using AttrConstIdeographic = AttrConstant<_const_Ideographic>;
    static const char _const_Inherit[] = "inherit";
    using AttrConstInherit = AttrConstant<_const_Inherit>;
    static const char _const_Italic[] = "italic";
    using AttrConstItalic = AttrConstant<_const_Italic>;
    static const char _const_Left[] = "left";
    using AttrConstLeft = AttrConstant<_const_Left>;
    static const char _const_Lighter[] = "lighter";
    using AttrConstLighter = AttrConstant<_const_Lighter>;
    static const char _const_LineThrough[] = "line-through";
    using AttrConstLineThrough = AttrConstant<_const_LineThrough>;
    static const char _const_LinearRGB[] = "linearRGB";
    using AttrConstLinearRGB = AttrConstant<_const_LinearRGB>;
    static const char _const_Lr[] = "lr";
    using AttrConstLr = AttrConstant<_const_Lr>;
    static const char _const_LrTb[] = "lr-tb";
    using AttrConstLrTb = AttrConstant<_const_LrTb>;
    static const char _const_Ltr[] = "ltr";
    using AttrConstLtr = AttrConstant<_const_Ltr>;
    static const char _const_Mathematical[] = "mathematical";
    using AttrConstMathematical = AttrConstant<_const_Mathematical>;
    static const char _const_Meet[] = "meet";
    using AttrConstMeet = AttrConstant<_const_Meet>;
    static const char _const_Middle[] = "middle";
    using AttrConstMiddle = AttrConstant<_const_Middle>;
    static const char _const_Miter[] = "miter";
    using AttrConstMiter = AttrConstant<_const_Miter>;
    static const char _const_MiterClip[] = "miter-clip";
    using AttrConstMiterClip = AttrConstant<_const_MiterClip>;
    static const char _const_New[] = "new";
    using AttrConstNew = AttrConstant<_const_New>;
    static const char _const_NonScalingStroke[] = "non-scaling-stroke";
    using AttrConstNonScalingStroke = AttrConstant<_const_NonScalingStroke>;
    static const char _const_None[] = "none";
    using AttrConstNone = AttrConstant<_const_None>;
    static const char _const_Nonezero[] = "nonezero";
    using AttrConstNonezero = AttrConstant<_const_Nonezero>;
    static const char _const_Nonzero[] = "nonzero";
    using AttrConstNonzero = AttrConstant<_const_Nonzero>;
    static const char _const_Normal[] = "normal";
    using AttrConstNormal = AttrConstant<_const_Normal>;
    static const char _const_ObjectBoundingBox[] = "objectBoundingBox";
    using AttrConstObjectBoundingBox = AttrConstant<_const_ObjectBoundingBox>;
    static const char _const_Oblique[] = "oblique";
    using AttrConstOblique = AttrConstant<_const_Oblique>;
    static const char _const_OptimizeLegibility[] = "optimizeLegibility";
    using AttrConstOptimizeLegibility = AttrConstant<_const_OptimizeLegibility>;
    static const char _const_OptimizeQuality[] = "optimizeQuality";
    using AttrConstOptimizeQuality = AttrConstant<_const_OptimizeQuality>;
    static const char _const_OptimizeSpeed[] = "optimizeSpeed";
    using AttrConstOptimizeSpeed = AttrConstant<_const_OptimizeSpeed>;
    static const char _const_Overline[] = "overline";
    using AttrConstOverline = AttrConstant<_const_Overline>;
    static const char _const_Pad[] = "pad";
    using AttrConstPad = AttrConstant<_const_Pad>;
    static const char _const_Painted[] = "painted";
    using AttrConstPainted = AttrConstant<_const_Painted>;
    static const char _const_Preserve[] = "preserve";
    using AttrConstPreserve = AttrConstant<_const_Preserve>;
    static const char _const_Reflect[] = "reflect";
    using AttrConstReflect = AttrConstant<_const_Reflect>;
    static const char _const_Repeat[] = "repeat";
    using AttrConstRepeat = AttrConstant<_const_Repeat>;
    static const char _const_Right[] = "right";
    using AttrConstRight = AttrConstant<_const_Right>;
    static const char _const_Rl[] = "rl";
    using AttrConstRl = AttrConstant<_const_Rl>;
    static const char _const_RlTb[] = "rl-tb";
    using AttrConstRlTb = AttrConstant<_const_RlTb>;
    static const char _const_Round[] = "round";
    using AttrConstRound = AttrConstant<_const_Round>;
    static const char _const_Rtl[] = "rtl";
    using AttrConstRtl = AttrConstant<_const_Rtl>;
    static const char _const_SRGB[] = "sRGB";
    using AttrConstSRGB = AttrConstant<_const_SRGB>;
    static const char _const_Scroll[] = "scroll";
    using AttrConstScroll = AttrConstant<_const_Scroll>;
    static const char _const_Slice[] = "slice";
    using AttrConstSlice = AttrConstant<_const_Slice>;
    static const char _const_Spacing[] = "spacing";
    using AttrConstSpacing = AttrConstant<_const_Spacing>;
    static const char _const_SpacingAndGlyphs[] = "spacingAndGlyphs";
    using AttrConstSpacingAndGlyphs = AttrConstant<_const_SpacingAndGlyphs>;
    static const char _const_Square[] = "square";
    using AttrConstSquare = AttrConstant<_const_Square>;
    static const char _const_Start[] = "start";
    using AttrConstStart = AttrConstant<_const_Start>;
    static const char _const_Stroke[] = "stroke";
    using AttrConstStroke = AttrConstant<_const_Stroke>;
    static const char _const_StrokeWidth[] = "strokeWidth";
    using AttrConstStrokeWidth = AttrConstant<_const_StrokeWidth>;
    static const char _const_Sub[] = "sub";
    using AttrConstSub = AttrConstant<_const_Sub>;
    static const char _const_Super[] = "super";
    using AttrConstSuper = AttrConstant<_const_Super>;
    static const char _const_Tb[] = "tb";
    using AttrConstTb = AttrConstant<_const_Tb>;
    static const char _const_TbRl[] = "tb-rl";
    using AttrConstTbRl = AttrConstant<_const_TbRl>;
    static const char _const_TextAfterEdge[] = "text-after-edge";
    using AttrConstTextAfterEdge = AttrConstant<_const_TextAfterEdge>;
    static const char _const_TextBeforeEdge[] = "text-before-edge";
    using AttrConstTextBeforeEdge = AttrConstant<_const_TextBeforeEdge>;
    static const char _const_TextBottom[] = "text-bottom";
    using AttrConstTextBottom = AttrConstant<_const_TextBottom>;
    static const char _const_TextTop[] = "text-top";
    using AttrConstTextTop = AttrConstant<_const_TextTop>;
    static const char _const_Underline[] = "underline";
    using AttrConstUnderline = AttrConstant<_const_Underline>;
    static const char _const_UserSpaceOnUse[] = "userSpaceOnUse";
    using AttrConstUserSpaceOnUse = AttrConstant<_const_UserSpaceOnUse>;
    static const char _const_Visible[] = "visible";
    using AttrConstVisible = AttrConstant<_const_Visible>;
    static const char _const_VisibleFil[] = "visibleFil";
    using AttrConstVisibleFil = AttrConstant<_const_VisibleFil>;
    static const char _const_VisiblePainted[] = "visiblePainted";
    using AttrConstVisiblePainted = AttrConstant<_const_VisiblePainted>;
    static const char _const_VisibleStroke[] = "visibleStroke";
    using AttrConstVisibleStroke = AttrConstant<_const_VisibleStroke>;
    static const char _const_XMaxYMax[] = "xMaxYMax";
    using AttrConstXMaxYMax = AttrConstant<_const_XMaxYMax>;
    static const char _const_XMaxYMid[] = "xMaxYMid";
    using AttrConstXMaxYMid = AttrConstant<_const_XMaxYMid>;
    static const char _const_XMaxYMin[] = "xMaxYMin";
    using AttrConstXMaxYMin = AttrConstant<_const_XMaxYMin>;
    static const char _const_XMidYMax[] = "xMidYMax";
    using AttrConstXMidYMax = AttrConstant<_const_XMidYMax>;
    static const char _const_XMidYMid[] = "xMidYMid";
    using AttrConstXMidYMid = AttrConstant<_const_XMidYMid>;
    static const char _const_XMidYMin[] = "xMidYMin";
    using AttrConstXMidYMin = AttrConstant<_const_XMidYMin>;
    static const char _const_XMinYMax[] = "xMinYMax";
    using AttrConstXMinYMax = AttrConstant<_const_XMinYMax>;
    static const char _const_XMinYMid[] = "xMinYMid";
    using AttrConstXMinYMid = AttrConstant<_const_XMinYMid>;
    static const char _const_XMinYMin[] = "xMinYMin";
    using AttrConstXMinYMin = AttrConstant<_const_XMinYMin>;
}
#endif
