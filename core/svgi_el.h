#ifndef __LZ_SVGI_ELEMENT__
#define __LZ_SVGI_ELEMENT__
#include <set>
#include "svgi_el/attr.hpp"
#include "svg_el.h"

namespace Lewzen {
    /**
    * An SVG element interface.
    */
    class SVGIElement : public virtual SVGElement {
    public:
        /**
        * Constructor of SVG element interface.
        */
        SVGIElement();
    protected:
        virtual void _bind_getter_setter();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Attributes
    public:
        /**
        * Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        */
        AttrAnything Id;
    public:
        /**
        * Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        */
        AttrAnything Lang;
    public:
        /**
        * The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
        * Value type: <integer>; Animatable: No
        */
        AttrInteger Tabindex;
    public:
        /**
        * Specifies a base IRI other than the base IRI of the document. 
        * Value type: <IRI>; Animatable: No
        */
        AttrIRI XmlBase;
    public:
        /**
        * It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        */
        AttrAnything XmlLang;
    public:
        /**
        * SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        */
        AttrEnumerate<AttrConstDefault, AttrConstPreserve> XmlSpace;
    public:
        /**
        * Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        */
        AttrAnything Class;
    public:
        /**
        * It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        */
        AttrAnything Style;
    public:
        /**
        * Event of onbegin.
        */
        AttrAnything Onbegin;
    public:
        /**
        * Event of onend.
        */
        AttrAnything Onend;
    public:
        /**
        * Event of onrepeat.
        */
        AttrAnything Onrepeat;
    public:
        /**
        * Event of onabort.
        */
        AttrAnything Onabort;
    public:
        /**
        * Event of onerror.
        */
        AttrAnything Onerror;
    public:
        /**
        * Event of onresize.
        */
        AttrAnything Onresize;
    public:
        /**
        * Event of onscroll.
        */
        AttrAnything Onscroll;
    public:
        /**
        * Event of onunload.
        */
        AttrAnything Onunload;
    public:
        /**
        * Event of oncopy.
        */
        AttrAnything Oncopy;
    public:
        /**
        * Event of oncut.
        */
        AttrAnything Oncut;
    public:
        /**
        * Event of onpaste.
        */
        AttrAnything Onpaste;
    public:
        /**
        * Event of oncancel.
        */
        AttrAnything Oncancel;
    public:
        /**
        * Event of oncanplay.
        */
        AttrAnything Oncanplay;
    public:
        /**
        * Event of oncanplaythrough.
        */
        AttrAnything Oncanplaythrough;
    public:
        /**
        * Event of onchange.
        */
        AttrAnything Onchange;
    public:
        /**
        * Event of onclick.
        */
        AttrAnything Onclick;
    public:
        /**
        * Event of onclose.
        */
        AttrAnything Onclose;
    public:
        /**
        * Event of oncuechange.
        */
        AttrAnything Oncuechange;
    public:
        /**
        * Event of ondblclick.
        */
        AttrAnything Ondblclick;
    public:
        /**
        * Event of ondrag.
        */
        AttrAnything Ondrag;
    public:
        /**
        * Event of ondragend.
        */
        AttrAnything Ondragend;
    public:
        /**
        * Event of ondragenter.
        */
        AttrAnything Ondragenter;
    public:
        /**
        * Event of ondragleave.
        */
        AttrAnything Ondragleave;
    public:
        /**
        * Event of ondragover.
        */
        AttrAnything Ondragover;
    public:
        /**
        * Event of ondragstart.
        */
        AttrAnything Ondragstart;
    public:
        /**
        * Event of ondrop.
        */
        AttrAnything Ondrop;
    public:
        /**
        * Event of ondurationchange.
        */
        AttrAnything Ondurationchange;
    public:
        /**
        * Event of onemptied.
        */
        AttrAnything Onemptied;
    public:
        /**
        * Event of onended.
        */
        AttrAnything Onended;
    public:
        /**
        * Event of onfocus.
        */
        AttrAnything Onfocus;
    public:
        /**
        * Event of oninput.
        */
        AttrAnything Oninput;
    public:
        /**
        * Event of oninvalid.
        */
        AttrAnything Oninvalid;
    public:
        /**
        * Event of onkeydown.
        */
        AttrAnything Onkeydown;
    public:
        /**
        * Event of onkeypress.
        */
        AttrAnything Onkeypress;
    public:
        /**
        * Event of onkeyup.
        */
        AttrAnything Onkeyup;
    public:
        /**
        * Event of onload.
        */
        AttrAnything Onload;
    public:
        /**
        * Event of onloadeddata.
        */
        AttrAnything Onloadeddata;
    public:
        /**
        * Event of onloadedmetadata.
        */
        AttrAnything Onloadedmetadata;
    public:
        /**
        * Event of onloadstart.
        */
        AttrAnything Onloadstart;
    public:
        /**
        * Event of onmousedown.
        */
        AttrAnything Onmousedown;
    public:
        /**
        * Event of onmouseenter.
        */
        AttrAnything Onmouseenter;
    public:
        /**
        * Event of onmouseleave.
        */
        AttrAnything Onmouseleave;
    public:
        /**
        * Event of onmousemove.
        */
        AttrAnything Onmousemove;
    public:
        /**
        * Event of onmouseout.
        */
        AttrAnything Onmouseout;
    public:
        /**
        * Event of onmouseover.
        */
        AttrAnything Onmouseover;
    public:
        /**
        * Event of onmouseup.
        */
        AttrAnything Onmouseup;
    public:
        /**
        * Event of onmousewheel.
        */
        AttrAnything Onmousewheel;
    public:
        /**
        * Event of onpause.
        */
        AttrAnything Onpause;
    public:
        /**
        * Event of onplay.
        */
        AttrAnything Onplay;
    public:
        /**
        * Event of onplaying.
        */
        AttrAnything Onplaying;
    public:
        /**
        * Event of onprogress.
        */
        AttrAnything Onprogress;
    public:
        /**
        * Event of onratechange.
        */
        AttrAnything Onratechange;
    public:
        /**
        * Event of onreset.
        */
        AttrAnything Onreset;
    public:
        /**
        * Event of onseeked.
        */
        AttrAnything Onseeked;
    public:
        /**
        * Event of onseeking.
        */
        AttrAnything Onseeking;
    public:
        /**
        * Event of onselect.
        */
        AttrAnything Onselect;
    public:
        /**
        * Event of onshow.
        */
        AttrAnything Onshow;
    public:
        /**
        * Event of onstalled.
        */
        AttrAnything Onstalled;
    public:
        /**
        * Event of onsubmit.
        */
        AttrAnything Onsubmit;
    public:
        /**
        * Event of onsuspend.
        */
        AttrAnything Onsuspend;
    public:
        /**
        * Event of ontimeupdate.
        */
        AttrAnything Ontimeupdate;
    public:
        /**
        * Event of ontoggle.
        */
        AttrAnything Ontoggle;
    public:
        /**
        * Event of onvolumechange.
        */
        AttrAnything Onvolumechange;
    public:
        /**
        * Event of onwaiting.
        */
        AttrAnything Onwaiting;
    public:
        /**
        * Event of onactivate.
        */
        AttrAnything Onactivate;
    public:
        /**
        * Event of onfocusin.
        */
        AttrAnything Onfocusin;
    public:
        /**
        * Event of onfocusout.
        */
        AttrAnything Onfocusout;
    public:
        /**
        * It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstBaseline, AttrConstBeforeEdge, AttrConstTextBeforeEdge, AttrConstMiddle, AttrConstCentral, AttrConstAfterEdge, AttrConstTextAfterEdge, AttrConstIdeographic, AttrConstAlphabetic, AttrConstHanging, AttrConstMathematical, AttrConstInherit> AlignmentBaseline;
    public:
        /**
        * It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstBaseline, AttrConstSuper, AttrConstSub, AttrPercentage, AttrLength, AttrConstInherit> BaselineShift;
    public:
        /**
        * It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstNone, AttrFuncIRI, AttrConstInherit> ClipPath;
    public:
        /**
        * It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstNonezero, AttrConstEvenodd, AttrConstInherit> ClipRule;
    public:
        /**
        * It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrColor, AttrConstInherit> Color;
    public:
        /**
        * It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstSRGB, AttrConstLinearRGB, AttrConstInherit> ColorInterpolation;
    public:
        /**
        * It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstSRGB, AttrConstLinearRGB, AttrConstInherit> ColorInterpolationFilters;
    public:
        /**
        * It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstSRGB, AttrConstLinearRGB, AttrName, AttrIRI, AttrConstInherit> ColorProfile;
    public:
        /**
        * It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstOptimizeSpeed, AttrConstOptimizeQuality, AttrConstInherit> ColorRendering;
    public:
        /**
        * It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<anything>:cursorKeywords|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrFuncIRI, AttrAnything, AttrConstInherit> Cursor;
    public:
        /**
        * It defines a path to be drawn. 
        * Value: path()|none
        */
        AttrEnumerate<AttrAnything, AttrConstNone> D;
    public:
        /**
        * It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstLtr, AttrConstRtl, AttrConstInherit> Direction;
    public:
        /**
        * It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        */
        AttrAnything Display;
    public:
        /**
        * It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstTextBottom, AttrConstAlphabetic, AttrConstIdeographic, AttrConstMiddle, AttrConstCentral, AttrConstMathematical, AttrConstHanging, AttrConstTextTop> DominantBaseline;
    public:
        /**
        * It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        */
        AttrEnumerate<AttrConstAccumulate, AttrConstNew, AttrConstInherit> EnableBackground;
    public:
        /**
        * It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        */
        AttrPaint Fill;
    public:
        /**
        * It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        AttrEnumerate<AttrNumber, AttrPercentage> FillOpacity;
    public:
        /**
        * It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstNonzero, AttrConstEvenodd, AttrConstInherit> FillRule;
    public:
        /**
        * It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrFuncIRI, AttrConstNone, AttrConstInherit> Filter;
    public:
        /**
        * It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        */
        AttrColor FloodColor;
    public:
        /**
        * It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        AttrEnumerate<AttrNumber, AttrPercentage> FloodOpacity;
    public:
        /**
        * It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        */
        AttrAnything FontFamily;
    public:
        /**
        * It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        */
        AttrAnything FontSize;
    public:
        /**
        * It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrNumber, AttrConstNone, AttrConstInherit> FontSizeAdjust;
    public:
        /**
        * It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        */
        AttrAnything FontStretch;
    public:
        /**
        * It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        */
        AttrEnumerate<AttrConstNormal, AttrConstItalic, AttrConstOblique> FontStyle;
    public:
        /**
        * It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        */
        AttrAnything FontVariant;
    public:
        /**
        * It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        */
        AttrEnumerate<AttrConstNormal, AttrConstBold, AttrConstLighter, AttrConstBolder, AttrConst100, AttrConst200, AttrConst300, AttrConst400, AttrConst500, AttrConst600, AttrConst700, AttrConst800, AttrConst900> FontWeight;
    public:
        /**
        * It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        */
        AttrEnumerate<AttrAngle, AttrConstInherit> GlyphOrientationHorizontal;
    public:
        /**
        * It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        */
        AttrEnumerate<AttrConstAuto, AttrAngle, AttrConstInherit> GlyphOrientationVertical;
    public:
        /**
        * It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstOptimizeQuality, AttrConstOptimizeSpeed> ImageRendering;
    public:
        /**
        * It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrConstInherit> Kerning;
    public:
        /**
        * It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstNormal, AttrLength, AttrConstInherit> LetterSpacing;
    public:
        /**
        * It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        */
        AttrColor LightingColor;
    public:
        /**
        * It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrFuncIRI, AttrConstNone, AttrConstInherit> MarkerEnd;
    public:
        /**
        * It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrFuncIRI, AttrConstNone, AttrConstInherit> MarkerMid;
    public:
        /**
        * It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrFuncIRI, AttrConstNone, AttrConstInherit> MarkerStart;
    public:
        /**
        * It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        */
        AttrAnything Mask;
    public:
        /**
        * It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        */
        AttrOpacityValue Opacity;
    public:
        /**
        * Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstVisible, AttrConstHidden, AttrConstScroll, AttrConstAuto, AttrConstInherit> Overflow;
    public:
        /**
        * Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        */
        AttrEnumerate<AttrConstBoundingBox, AttrConstVisiblePainted, AttrConstVisibleFil, AttrConstVisibleStroke, AttrConstVisible, AttrConstPainted, AttrConstFill, AttrConstStroke, AttrConstAll, AttrConstNone> PointerEvents;
    public:
        /**
        * Hints about what tradeoffs to make as the browser renders <anything>:path element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstOptimizeSpeed, AttrConstCrispEdges, AttrConstGeometricPrecision, AttrConstInherit> ShapeRendering;
    public:
        /**
        * - 
        * Value:; Animatable: -
        */
        AttrAnything SolidColor;
    public:
        /**
        * - 
        * Value:; Animatable: -
        */
        AttrAnything SolidOpacity;
    public:
        /**
        * Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<color>:icccolor|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstCurrentcolor, AttrColor, AttrColor, AttrConstInherit> StopColor;
    public:
        /**
        * Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrOpacityValue, AttrConstInherit> StopOpacity;
    public:
        /**
        * Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        */
        AttrPaint Stroke;
    public:
        /**
        * Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<list-of-numbers>:dasharray; Animatable: Yes
        */
        AttrEnumerate<AttrConstNone, AttrListOfNumbers> StrokeDasharray;
    public:
        /**
        * Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        */
        AttrEnumerate<AttrPercentage, AttrLength> StrokeDashoffset;
    public:
        /**
        * Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        */
        AttrEnumerate<AttrConstButt, AttrConstRound, AttrConstSquare> StrokeLinecap;
    public:
        /**
        * Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        */
        AttrEnumerate<AttrConstArcs, AttrConstBevel, AttrConstMiter, AttrConstMiterClip, AttrConstRound> StrokeLinejoin;
    public:
        /**
        * Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        */
        AttrNumber StrokeMiterlimit;
    public:
        /**
        * Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        */
        AttrEnumerate<AttrOpacityValue, AttrPercentage> StrokeOpacity;
    public:
        /**
        * Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> StrokeWidth;
    public:
        /**
        * Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstStart, AttrConstMiddle, AttrConstEnd, AttrConstInherit> TextAnchor;
    public:
        /**
        * Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstNone, AttrConstUnderline, AttrConstOverline, AttrConstLineThrough, AttrConstBlink, AttrConstInherit> TextDecoration;
    public:
        /**
        * Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstOptimizeSpeed, AttrConstOptimizeLegibility, AttrConstGeometricPrecision, AttrConstInherit> TextRendering;
    public:
        /**
        * Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        */
        AttrTransformList Transform;
    public:
        /**
        * - 
        * Value:; Animatable: -
        */
        AttrAnything UnicodeBidi;
    public:
        /**
        * Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<IRI>:uri; Animatable: Yes
        */
        AttrEnumerate<AttrConstDefault, AttrConstNonScalingStroke, AttrConstInherit, AttrIRI> VectorEffect;
    public:
        /**
        * Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstVisible, AttrConstHidden, AttrConstCollapse, AttrConstInherit> Visibility;
    public:
        /**
        * Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrLength, AttrConstInherit> WordSpacing;
    public:
        /**
        * Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        */
        AttrEnumerate<AttrConstLrTb, AttrConstRlTb, AttrConstTbRl, AttrConstLr, AttrConstRl, AttrConstTb, AttrConstInherit> WritingMode;

    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 138> _attr_on_assign = {
            [this](const std::string &last){
                if (Id.get() == Id.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Lang.get() == Lang.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Tabindex.get() == Tabindex.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (XmlBase.get() == XmlBase.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (XmlLang.get() == XmlLang.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (XmlSpace.get() == XmlSpace.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (Class.get() == Class.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (Style.get() == Style.get_commit()) modified.erase(7);
                else modified.insert(7);
                bound.erase(7);
            },
            [this](const std::string &last){
                if (Onbegin.get() == Onbegin.get_commit()) modified.erase(8);
                else modified.insert(8);
                bound.erase(8);
            },
            [this](const std::string &last){
                if (Onend.get() == Onend.get_commit()) modified.erase(9);
                else modified.insert(9);
                bound.erase(9);
            },
            [this](const std::string &last){
                if (Onrepeat.get() == Onrepeat.get_commit()) modified.erase(10);
                else modified.insert(10);
                bound.erase(10);
            },
            [this](const std::string &last){
                if (Onabort.get() == Onabort.get_commit()) modified.erase(11);
                else modified.insert(11);
                bound.erase(11);
            },
            [this](const std::string &last){
                if (Onerror.get() == Onerror.get_commit()) modified.erase(12);
                else modified.insert(12);
                bound.erase(12);
            },
            [this](const std::string &last){
                if (Onresize.get() == Onresize.get_commit()) modified.erase(13);
                else modified.insert(13);
                bound.erase(13);
            },
            [this](const std::string &last){
                if (Onscroll.get() == Onscroll.get_commit()) modified.erase(14);
                else modified.insert(14);
                bound.erase(14);
            },
            [this](const std::string &last){
                if (Onunload.get() == Onunload.get_commit()) modified.erase(15);
                else modified.insert(15);
                bound.erase(15);
            },
            [this](const std::string &last){
                if (Oncopy.get() == Oncopy.get_commit()) modified.erase(16);
                else modified.insert(16);
                bound.erase(16);
            },
            [this](const std::string &last){
                if (Oncut.get() == Oncut.get_commit()) modified.erase(17);
                else modified.insert(17);
                bound.erase(17);
            },
            [this](const std::string &last){
                if (Onpaste.get() == Onpaste.get_commit()) modified.erase(18);
                else modified.insert(18);
                bound.erase(18);
            },
            [this](const std::string &last){
                if (Oncancel.get() == Oncancel.get_commit()) modified.erase(19);
                else modified.insert(19);
                bound.erase(19);
            },
            [this](const std::string &last){
                if (Oncanplay.get() == Oncanplay.get_commit()) modified.erase(20);
                else modified.insert(20);
                bound.erase(20);
            },
            [this](const std::string &last){
                if (Oncanplaythrough.get() == Oncanplaythrough.get_commit()) modified.erase(21);
                else modified.insert(21);
                bound.erase(21);
            },
            [this](const std::string &last){
                if (Onchange.get() == Onchange.get_commit()) modified.erase(22);
                else modified.insert(22);
                bound.erase(22);
            },
            [this](const std::string &last){
                if (Onclick.get() == Onclick.get_commit()) modified.erase(23);
                else modified.insert(23);
                bound.erase(23);
            },
            [this](const std::string &last){
                if (Onclose.get() == Onclose.get_commit()) modified.erase(24);
                else modified.insert(24);
                bound.erase(24);
            },
            [this](const std::string &last){
                if (Oncuechange.get() == Oncuechange.get_commit()) modified.erase(25);
                else modified.insert(25);
                bound.erase(25);
            },
            [this](const std::string &last){
                if (Ondblclick.get() == Ondblclick.get_commit()) modified.erase(26);
                else modified.insert(26);
                bound.erase(26);
            },
            [this](const std::string &last){
                if (Ondrag.get() == Ondrag.get_commit()) modified.erase(27);
                else modified.insert(27);
                bound.erase(27);
            },
            [this](const std::string &last){
                if (Ondragend.get() == Ondragend.get_commit()) modified.erase(28);
                else modified.insert(28);
                bound.erase(28);
            },
            [this](const std::string &last){
                if (Ondragenter.get() == Ondragenter.get_commit()) modified.erase(29);
                else modified.insert(29);
                bound.erase(29);
            },
            [this](const std::string &last){
                if (Ondragleave.get() == Ondragleave.get_commit()) modified.erase(30);
                else modified.insert(30);
                bound.erase(30);
            },
            [this](const std::string &last){
                if (Ondragover.get() == Ondragover.get_commit()) modified.erase(31);
                else modified.insert(31);
                bound.erase(31);
            },
            [this](const std::string &last){
                if (Ondragstart.get() == Ondragstart.get_commit()) modified.erase(32);
                else modified.insert(32);
                bound.erase(32);
            },
            [this](const std::string &last){
                if (Ondrop.get() == Ondrop.get_commit()) modified.erase(33);
                else modified.insert(33);
                bound.erase(33);
            },
            [this](const std::string &last){
                if (Ondurationchange.get() == Ondurationchange.get_commit()) modified.erase(34);
                else modified.insert(34);
                bound.erase(34);
            },
            [this](const std::string &last){
                if (Onemptied.get() == Onemptied.get_commit()) modified.erase(35);
                else modified.insert(35);
                bound.erase(35);
            },
            [this](const std::string &last){
                if (Onended.get() == Onended.get_commit()) modified.erase(36);
                else modified.insert(36);
                bound.erase(36);
            },
            [this](const std::string &last){
                if (Onfocus.get() == Onfocus.get_commit()) modified.erase(37);
                else modified.insert(37);
                bound.erase(37);
            },
            [this](const std::string &last){
                if (Oninput.get() == Oninput.get_commit()) modified.erase(38);
                else modified.insert(38);
                bound.erase(38);
            },
            [this](const std::string &last){
                if (Oninvalid.get() == Oninvalid.get_commit()) modified.erase(39);
                else modified.insert(39);
                bound.erase(39);
            },
            [this](const std::string &last){
                if (Onkeydown.get() == Onkeydown.get_commit()) modified.erase(40);
                else modified.insert(40);
                bound.erase(40);
            },
            [this](const std::string &last){
                if (Onkeypress.get() == Onkeypress.get_commit()) modified.erase(41);
                else modified.insert(41);
                bound.erase(41);
            },
            [this](const std::string &last){
                if (Onkeyup.get() == Onkeyup.get_commit()) modified.erase(42);
                else modified.insert(42);
                bound.erase(42);
            },
            [this](const std::string &last){
                if (Onload.get() == Onload.get_commit()) modified.erase(43);
                else modified.insert(43);
                bound.erase(43);
            },
            [this](const std::string &last){
                if (Onloadeddata.get() == Onloadeddata.get_commit()) modified.erase(44);
                else modified.insert(44);
                bound.erase(44);
            },
            [this](const std::string &last){
                if (Onloadedmetadata.get() == Onloadedmetadata.get_commit()) modified.erase(45);
                else modified.insert(45);
                bound.erase(45);
            },
            [this](const std::string &last){
                if (Onloadstart.get() == Onloadstart.get_commit()) modified.erase(46);
                else modified.insert(46);
                bound.erase(46);
            },
            [this](const std::string &last){
                if (Onmousedown.get() == Onmousedown.get_commit()) modified.erase(47);
                else modified.insert(47);
                bound.erase(47);
            },
            [this](const std::string &last){
                if (Onmouseenter.get() == Onmouseenter.get_commit()) modified.erase(48);
                else modified.insert(48);
                bound.erase(48);
            },
            [this](const std::string &last){
                if (Onmouseleave.get() == Onmouseleave.get_commit()) modified.erase(49);
                else modified.insert(49);
                bound.erase(49);
            },
            [this](const std::string &last){
                if (Onmousemove.get() == Onmousemove.get_commit()) modified.erase(50);
                else modified.insert(50);
                bound.erase(50);
            },
            [this](const std::string &last){
                if (Onmouseout.get() == Onmouseout.get_commit()) modified.erase(51);
                else modified.insert(51);
                bound.erase(51);
            },
            [this](const std::string &last){
                if (Onmouseover.get() == Onmouseover.get_commit()) modified.erase(52);
                else modified.insert(52);
                bound.erase(52);
            },
            [this](const std::string &last){
                if (Onmouseup.get() == Onmouseup.get_commit()) modified.erase(53);
                else modified.insert(53);
                bound.erase(53);
            },
            [this](const std::string &last){
                if (Onmousewheel.get() == Onmousewheel.get_commit()) modified.erase(54);
                else modified.insert(54);
                bound.erase(54);
            },
            [this](const std::string &last){
                if (Onpause.get() == Onpause.get_commit()) modified.erase(55);
                else modified.insert(55);
                bound.erase(55);
            },
            [this](const std::string &last){
                if (Onplay.get() == Onplay.get_commit()) modified.erase(56);
                else modified.insert(56);
                bound.erase(56);
            },
            [this](const std::string &last){
                if (Onplaying.get() == Onplaying.get_commit()) modified.erase(57);
                else modified.insert(57);
                bound.erase(57);
            },
            [this](const std::string &last){
                if (Onprogress.get() == Onprogress.get_commit()) modified.erase(58);
                else modified.insert(58);
                bound.erase(58);
            },
            [this](const std::string &last){
                if (Onratechange.get() == Onratechange.get_commit()) modified.erase(59);
                else modified.insert(59);
                bound.erase(59);
            },
            [this](const std::string &last){
                if (Onreset.get() == Onreset.get_commit()) modified.erase(60);
                else modified.insert(60);
                bound.erase(60);
            },
            [this](const std::string &last){
                if (Onseeked.get() == Onseeked.get_commit()) modified.erase(61);
                else modified.insert(61);
                bound.erase(61);
            },
            [this](const std::string &last){
                if (Onseeking.get() == Onseeking.get_commit()) modified.erase(62);
                else modified.insert(62);
                bound.erase(62);
            },
            [this](const std::string &last){
                if (Onselect.get() == Onselect.get_commit()) modified.erase(63);
                else modified.insert(63);
                bound.erase(63);
            },
            [this](const std::string &last){
                if (Onshow.get() == Onshow.get_commit()) modified.erase(64);
                else modified.insert(64);
                bound.erase(64);
            },
            [this](const std::string &last){
                if (Onstalled.get() == Onstalled.get_commit()) modified.erase(65);
                else modified.insert(65);
                bound.erase(65);
            },
            [this](const std::string &last){
                if (Onsubmit.get() == Onsubmit.get_commit()) modified.erase(66);
                else modified.insert(66);
                bound.erase(66);
            },
            [this](const std::string &last){
                if (Onsuspend.get() == Onsuspend.get_commit()) modified.erase(67);
                else modified.insert(67);
                bound.erase(67);
            },
            [this](const std::string &last){
                if (Ontimeupdate.get() == Ontimeupdate.get_commit()) modified.erase(68);
                else modified.insert(68);
                bound.erase(68);
            },
            [this](const std::string &last){
                if (Ontoggle.get() == Ontoggle.get_commit()) modified.erase(69);
                else modified.insert(69);
                bound.erase(69);
            },
            [this](const std::string &last){
                if (Onvolumechange.get() == Onvolumechange.get_commit()) modified.erase(70);
                else modified.insert(70);
                bound.erase(70);
            },
            [this](const std::string &last){
                if (Onwaiting.get() == Onwaiting.get_commit()) modified.erase(71);
                else modified.insert(71);
                bound.erase(71);
            },
            [this](const std::string &last){
                if (Onactivate.get() == Onactivate.get_commit()) modified.erase(72);
                else modified.insert(72);
                bound.erase(72);
            },
            [this](const std::string &last){
                if (Onfocusin.get() == Onfocusin.get_commit()) modified.erase(73);
                else modified.insert(73);
                bound.erase(73);
            },
            [this](const std::string &last){
                if (Onfocusout.get() == Onfocusout.get_commit()) modified.erase(74);
                else modified.insert(74);
                bound.erase(74);
            },
            [this](const std::string &last){
                if (AlignmentBaseline.get() == AlignmentBaseline.get_commit()) modified.erase(75);
                else modified.insert(75);
                bound.erase(75);
            },
            [this](const std::string &last){
                if (BaselineShift.get() == BaselineShift.get_commit()) modified.erase(76);
                else modified.insert(76);
                bound.erase(76);
            },
            [this](const std::string &last){
                if (ClipPath.get() == ClipPath.get_commit()) modified.erase(77);
                else modified.insert(77);
                bound.erase(77);
            },
            [this](const std::string &last){
                if (ClipRule.get() == ClipRule.get_commit()) modified.erase(78);
                else modified.insert(78);
                bound.erase(78);
            },
            [this](const std::string &last){
                if (Color.get() == Color.get_commit()) modified.erase(79);
                else modified.insert(79);
                bound.erase(79);
            },
            [this](const std::string &last){
                if (ColorInterpolation.get() == ColorInterpolation.get_commit()) modified.erase(80);
                else modified.insert(80);
                bound.erase(80);
            },
            [this](const std::string &last){
                if (ColorInterpolationFilters.get() == ColorInterpolationFilters.get_commit()) modified.erase(81);
                else modified.insert(81);
                bound.erase(81);
            },
            [this](const std::string &last){
                if (ColorProfile.get() == ColorProfile.get_commit()) modified.erase(82);
                else modified.insert(82);
                bound.erase(82);
            },
            [this](const std::string &last){
                if (ColorRendering.get() == ColorRendering.get_commit()) modified.erase(83);
                else modified.insert(83);
                bound.erase(83);
            },
            [this](const std::string &last){
                if (Cursor.get() == Cursor.get_commit()) modified.erase(84);
                else modified.insert(84);
                bound.erase(84);
            },
            [this](const std::string &last){
                if (D.get() == D.get_commit()) modified.erase(85);
                else modified.insert(85);
                bound.erase(85);
            },
            [this](const std::string &last){
                if (Direction.get() == Direction.get_commit()) modified.erase(86);
                else modified.insert(86);
                bound.erase(86);
            },
            [this](const std::string &last){
                if (Display.get() == Display.get_commit()) modified.erase(87);
                else modified.insert(87);
                bound.erase(87);
            },
            [this](const std::string &last){
                if (DominantBaseline.get() == DominantBaseline.get_commit()) modified.erase(88);
                else modified.insert(88);
                bound.erase(88);
            },
            [this](const std::string &last){
                if (EnableBackground.get() == EnableBackground.get_commit()) modified.erase(89);
                else modified.insert(89);
                bound.erase(89);
            },
            [this](const std::string &last){
                if (Fill.get() == Fill.get_commit()) modified.erase(90);
                else modified.insert(90);
                bound.erase(90);
            },
            [this](const std::string &last){
                if (FillOpacity.get() == FillOpacity.get_commit()) modified.erase(91);
                else modified.insert(91);
                bound.erase(91);
            },
            [this](const std::string &last){
                if (FillRule.get() == FillRule.get_commit()) modified.erase(92);
                else modified.insert(92);
                bound.erase(92);
            },
            [this](const std::string &last){
                if (Filter.get() == Filter.get_commit()) modified.erase(93);
                else modified.insert(93);
                bound.erase(93);
            },
            [this](const std::string &last){
                if (FloodColor.get() == FloodColor.get_commit()) modified.erase(94);
                else modified.insert(94);
                bound.erase(94);
            },
            [this](const std::string &last){
                if (FloodOpacity.get() == FloodOpacity.get_commit()) modified.erase(95);
                else modified.insert(95);
                bound.erase(95);
            },
            [this](const std::string &last){
                if (FontFamily.get() == FontFamily.get_commit()) modified.erase(96);
                else modified.insert(96);
                bound.erase(96);
            },
            [this](const std::string &last){
                if (FontSize.get() == FontSize.get_commit()) modified.erase(97);
                else modified.insert(97);
                bound.erase(97);
            },
            [this](const std::string &last){
                if (FontSizeAdjust.get() == FontSizeAdjust.get_commit()) modified.erase(98);
                else modified.insert(98);
                bound.erase(98);
            },
            [this](const std::string &last){
                if (FontStretch.get() == FontStretch.get_commit()) modified.erase(99);
                else modified.insert(99);
                bound.erase(99);
            },
            [this](const std::string &last){
                if (FontStyle.get() == FontStyle.get_commit()) modified.erase(100);
                else modified.insert(100);
                bound.erase(100);
            },
            [this](const std::string &last){
                if (FontVariant.get() == FontVariant.get_commit()) modified.erase(101);
                else modified.insert(101);
                bound.erase(101);
            },
            [this](const std::string &last){
                if (FontWeight.get() == FontWeight.get_commit()) modified.erase(102);
                else modified.insert(102);
                bound.erase(102);
            },
            [this](const std::string &last){
                if (GlyphOrientationHorizontal.get() == GlyphOrientationHorizontal.get_commit()) modified.erase(103);
                else modified.insert(103);
                bound.erase(103);
            },
            [this](const std::string &last){
                if (GlyphOrientationVertical.get() == GlyphOrientationVertical.get_commit()) modified.erase(104);
                else modified.insert(104);
                bound.erase(104);
            },
            [this](const std::string &last){
                if (ImageRendering.get() == ImageRendering.get_commit()) modified.erase(105);
                else modified.insert(105);
                bound.erase(105);
            },
            [this](const std::string &last){
                if (Kerning.get() == Kerning.get_commit()) modified.erase(106);
                else modified.insert(106);
                bound.erase(106);
            },
            [this](const std::string &last){
                if (LetterSpacing.get() == LetterSpacing.get_commit()) modified.erase(107);
                else modified.insert(107);
                bound.erase(107);
            },
            [this](const std::string &last){
                if (LightingColor.get() == LightingColor.get_commit()) modified.erase(108);
                else modified.insert(108);
                bound.erase(108);
            },
            [this](const std::string &last){
                if (MarkerEnd.get() == MarkerEnd.get_commit()) modified.erase(109);
                else modified.insert(109);
                bound.erase(109);
            },
            [this](const std::string &last){
                if (MarkerMid.get() == MarkerMid.get_commit()) modified.erase(110);
                else modified.insert(110);
                bound.erase(110);
            },
            [this](const std::string &last){
                if (MarkerStart.get() == MarkerStart.get_commit()) modified.erase(111);
                else modified.insert(111);
                bound.erase(111);
            },
            [this](const std::string &last){
                if (Mask.get() == Mask.get_commit()) modified.erase(112);
                else modified.insert(112);
                bound.erase(112);
            },
            [this](const std::string &last){
                if (Opacity.get() == Opacity.get_commit()) modified.erase(113);
                else modified.insert(113);
                bound.erase(113);
            },
            [this](const std::string &last){
                if (Overflow.get() == Overflow.get_commit()) modified.erase(114);
                else modified.insert(114);
                bound.erase(114);
            },
            [this](const std::string &last){
                if (PointerEvents.get() == PointerEvents.get_commit()) modified.erase(115);
                else modified.insert(115);
                bound.erase(115);
            },
            [this](const std::string &last){
                if (ShapeRendering.get() == ShapeRendering.get_commit()) modified.erase(116);
                else modified.insert(116);
                bound.erase(116);
            },
            [this](const std::string &last){
                if (SolidColor.get() == SolidColor.get_commit()) modified.erase(117);
                else modified.insert(117);
                bound.erase(117);
            },
            [this](const std::string &last){
                if (SolidOpacity.get() == SolidOpacity.get_commit()) modified.erase(118);
                else modified.insert(118);
                bound.erase(118);
            },
            [this](const std::string &last){
                if (StopColor.get() == StopColor.get_commit()) modified.erase(119);
                else modified.insert(119);
                bound.erase(119);
            },
            [this](const std::string &last){
                if (StopOpacity.get() == StopOpacity.get_commit()) modified.erase(120);
                else modified.insert(120);
                bound.erase(120);
            },
            [this](const std::string &last){
                if (Stroke.get() == Stroke.get_commit()) modified.erase(121);
                else modified.insert(121);
                bound.erase(121);
            },
            [this](const std::string &last){
                if (StrokeDasharray.get() == StrokeDasharray.get_commit()) modified.erase(122);
                else modified.insert(122);
                bound.erase(122);
            },
            [this](const std::string &last){
                if (StrokeDashoffset.get() == StrokeDashoffset.get_commit()) modified.erase(123);
                else modified.insert(123);
                bound.erase(123);
            },
            [this](const std::string &last){
                if (StrokeLinecap.get() == StrokeLinecap.get_commit()) modified.erase(124);
                else modified.insert(124);
                bound.erase(124);
            },
            [this](const std::string &last){
                if (StrokeLinejoin.get() == StrokeLinejoin.get_commit()) modified.erase(125);
                else modified.insert(125);
                bound.erase(125);
            },
            [this](const std::string &last){
                if (StrokeMiterlimit.get() == StrokeMiterlimit.get_commit()) modified.erase(126);
                else modified.insert(126);
                bound.erase(126);
            },
            [this](const std::string &last){
                if (StrokeOpacity.get() == StrokeOpacity.get_commit()) modified.erase(127);
                else modified.insert(127);
                bound.erase(127);
            },
            [this](const std::string &last){
                if (StrokeWidth.get() == StrokeWidth.get_commit()) modified.erase(128);
                else modified.insert(128);
                bound.erase(128);
            },
            [this](const std::string &last){
                if (TextAnchor.get() == TextAnchor.get_commit()) modified.erase(129);
                else modified.insert(129);
                bound.erase(129);
            },
            [this](const std::string &last){
                if (TextDecoration.get() == TextDecoration.get_commit()) modified.erase(130);
                else modified.insert(130);
                bound.erase(130);
            },
            [this](const std::string &last){
                if (TextRendering.get() == TextRendering.get_commit()) modified.erase(131);
                else modified.insert(131);
                bound.erase(131);
            },
            [this](const std::string &last){
                if (Transform.get() == Transform.get_commit()) modified.erase(132);
                else modified.insert(132);
                bound.erase(132);
            },
            [this](const std::string &last){
                if (UnicodeBidi.get() == UnicodeBidi.get_commit()) modified.erase(133);
                else modified.insert(133);
                bound.erase(133);
            },
            [this](const std::string &last){
                if (VectorEffect.get() == VectorEffect.get_commit()) modified.erase(134);
                else modified.insert(134);
                bound.erase(134);
            },
            [this](const std::string &last){
                if (Visibility.get() == Visibility.get_commit()) modified.erase(135);
                else modified.insert(135);
                bound.erase(135);
            },
            [this](const std::string &last){
                if (WordSpacing.get() == WordSpacing.get_commit()) modified.erase(136);
                else modified.insert(136);
                bound.erase(136);
            },
            [this](const std::string &last){
                if (WritingMode.get() == WritingMode.get_commit()) modified.erase(137);
                else modified.insert(137);
                bound.erase(137);
            },
        };
        const std::array<std::function<void()>, 138> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
            std::bind([this](){
                modified.erase(1);
                bound.insert(1);
            }),
            std::bind([this](){
                modified.erase(2);
                bound.insert(2);
            }),
            std::bind([this](){
                modified.erase(3);
                bound.insert(3);
            }),
            std::bind([this](){
                modified.erase(4);
                bound.insert(4);
            }),
            std::bind([this](){
                modified.erase(5);
                bound.insert(5);
            }),
            std::bind([this](){
                modified.erase(6);
                bound.insert(6);
            }),
            std::bind([this](){
                modified.erase(7);
                bound.insert(7);
            }),
            std::bind([this](){
                modified.erase(8);
                bound.insert(8);
            }),
            std::bind([this](){
                modified.erase(9);
                bound.insert(9);
            }),
            std::bind([this](){
                modified.erase(10);
                bound.insert(10);
            }),
            std::bind([this](){
                modified.erase(11);
                bound.insert(11);
            }),
            std::bind([this](){
                modified.erase(12);
                bound.insert(12);
            }),
            std::bind([this](){
                modified.erase(13);
                bound.insert(13);
            }),
            std::bind([this](){
                modified.erase(14);
                bound.insert(14);
            }),
            std::bind([this](){
                modified.erase(15);
                bound.insert(15);
            }),
            std::bind([this](){
                modified.erase(16);
                bound.insert(16);
            }),
            std::bind([this](){
                modified.erase(17);
                bound.insert(17);
            }),
            std::bind([this](){
                modified.erase(18);
                bound.insert(18);
            }),
            std::bind([this](){
                modified.erase(19);
                bound.insert(19);
            }),
            std::bind([this](){
                modified.erase(20);
                bound.insert(20);
            }),
            std::bind([this](){
                modified.erase(21);
                bound.insert(21);
            }),
            std::bind([this](){
                modified.erase(22);
                bound.insert(22);
            }),
            std::bind([this](){
                modified.erase(23);
                bound.insert(23);
            }),
            std::bind([this](){
                modified.erase(24);
                bound.insert(24);
            }),
            std::bind([this](){
                modified.erase(25);
                bound.insert(25);
            }),
            std::bind([this](){
                modified.erase(26);
                bound.insert(26);
            }),
            std::bind([this](){
                modified.erase(27);
                bound.insert(27);
            }),
            std::bind([this](){
                modified.erase(28);
                bound.insert(28);
            }),
            std::bind([this](){
                modified.erase(29);
                bound.insert(29);
            }),
            std::bind([this](){
                modified.erase(30);
                bound.insert(30);
            }),
            std::bind([this](){
                modified.erase(31);
                bound.insert(31);
            }),
            std::bind([this](){
                modified.erase(32);
                bound.insert(32);
            }),
            std::bind([this](){
                modified.erase(33);
                bound.insert(33);
            }),
            std::bind([this](){
                modified.erase(34);
                bound.insert(34);
            }),
            std::bind([this](){
                modified.erase(35);
                bound.insert(35);
            }),
            std::bind([this](){
                modified.erase(36);
                bound.insert(36);
            }),
            std::bind([this](){
                modified.erase(37);
                bound.insert(37);
            }),
            std::bind([this](){
                modified.erase(38);
                bound.insert(38);
            }),
            std::bind([this](){
                modified.erase(39);
                bound.insert(39);
            }),
            std::bind([this](){
                modified.erase(40);
                bound.insert(40);
            }),
            std::bind([this](){
                modified.erase(41);
                bound.insert(41);
            }),
            std::bind([this](){
                modified.erase(42);
                bound.insert(42);
            }),
            std::bind([this](){
                modified.erase(43);
                bound.insert(43);
            }),
            std::bind([this](){
                modified.erase(44);
                bound.insert(44);
            }),
            std::bind([this](){
                modified.erase(45);
                bound.insert(45);
            }),
            std::bind([this](){
                modified.erase(46);
                bound.insert(46);
            }),
            std::bind([this](){
                modified.erase(47);
                bound.insert(47);
            }),
            std::bind([this](){
                modified.erase(48);
                bound.insert(48);
            }),
            std::bind([this](){
                modified.erase(49);
                bound.insert(49);
            }),
            std::bind([this](){
                modified.erase(50);
                bound.insert(50);
            }),
            std::bind([this](){
                modified.erase(51);
                bound.insert(51);
            }),
            std::bind([this](){
                modified.erase(52);
                bound.insert(52);
            }),
            std::bind([this](){
                modified.erase(53);
                bound.insert(53);
            }),
            std::bind([this](){
                modified.erase(54);
                bound.insert(54);
            }),
            std::bind([this](){
                modified.erase(55);
                bound.insert(55);
            }),
            std::bind([this](){
                modified.erase(56);
                bound.insert(56);
            }),
            std::bind([this](){
                modified.erase(57);
                bound.insert(57);
            }),
            std::bind([this](){
                modified.erase(58);
                bound.insert(58);
            }),
            std::bind([this](){
                modified.erase(59);
                bound.insert(59);
            }),
            std::bind([this](){
                modified.erase(60);
                bound.insert(60);
            }),
            std::bind([this](){
                modified.erase(61);
                bound.insert(61);
            }),
            std::bind([this](){
                modified.erase(62);
                bound.insert(62);
            }),
            std::bind([this](){
                modified.erase(63);
                bound.insert(63);
            }),
            std::bind([this](){
                modified.erase(64);
                bound.insert(64);
            }),
            std::bind([this](){
                modified.erase(65);
                bound.insert(65);
            }),
            std::bind([this](){
                modified.erase(66);
                bound.insert(66);
            }),
            std::bind([this](){
                modified.erase(67);
                bound.insert(67);
            }),
            std::bind([this](){
                modified.erase(68);
                bound.insert(68);
            }),
            std::bind([this](){
                modified.erase(69);
                bound.insert(69);
            }),
            std::bind([this](){
                modified.erase(70);
                bound.insert(70);
            }),
            std::bind([this](){
                modified.erase(71);
                bound.insert(71);
            }),
            std::bind([this](){
                modified.erase(72);
                bound.insert(72);
            }),
            std::bind([this](){
                modified.erase(73);
                bound.insert(73);
            }),
            std::bind([this](){
                modified.erase(74);
                bound.insert(74);
            }),
            std::bind([this](){
                modified.erase(75);
                bound.insert(75);
            }),
            std::bind([this](){
                modified.erase(76);
                bound.insert(76);
            }),
            std::bind([this](){
                modified.erase(77);
                bound.insert(77);
            }),
            std::bind([this](){
                modified.erase(78);
                bound.insert(78);
            }),
            std::bind([this](){
                modified.erase(79);
                bound.insert(79);
            }),
            std::bind([this](){
                modified.erase(80);
                bound.insert(80);
            }),
            std::bind([this](){
                modified.erase(81);
                bound.insert(81);
            }),
            std::bind([this](){
                modified.erase(82);
                bound.insert(82);
            }),
            std::bind([this](){
                modified.erase(83);
                bound.insert(83);
            }),
            std::bind([this](){
                modified.erase(84);
                bound.insert(84);
            }),
            std::bind([this](){
                modified.erase(85);
                bound.insert(85);
            }),
            std::bind([this](){
                modified.erase(86);
                bound.insert(86);
            }),
            std::bind([this](){
                modified.erase(87);
                bound.insert(87);
            }),
            std::bind([this](){
                modified.erase(88);
                bound.insert(88);
            }),
            std::bind([this](){
                modified.erase(89);
                bound.insert(89);
            }),
            std::bind([this](){
                modified.erase(90);
                bound.insert(90);
            }),
            std::bind([this](){
                modified.erase(91);
                bound.insert(91);
            }),
            std::bind([this](){
                modified.erase(92);
                bound.insert(92);
            }),
            std::bind([this](){
                modified.erase(93);
                bound.insert(93);
            }),
            std::bind([this](){
                modified.erase(94);
                bound.insert(94);
            }),
            std::bind([this](){
                modified.erase(95);
                bound.insert(95);
            }),
            std::bind([this](){
                modified.erase(96);
                bound.insert(96);
            }),
            std::bind([this](){
                modified.erase(97);
                bound.insert(97);
            }),
            std::bind([this](){
                modified.erase(98);
                bound.insert(98);
            }),
            std::bind([this](){
                modified.erase(99);
                bound.insert(99);
            }),
            std::bind([this](){
                modified.erase(100);
                bound.insert(100);
            }),
            std::bind([this](){
                modified.erase(101);
                bound.insert(101);
            }),
            std::bind([this](){
                modified.erase(102);
                bound.insert(102);
            }),
            std::bind([this](){
                modified.erase(103);
                bound.insert(103);
            }),
            std::bind([this](){
                modified.erase(104);
                bound.insert(104);
            }),
            std::bind([this](){
                modified.erase(105);
                bound.insert(105);
            }),
            std::bind([this](){
                modified.erase(106);
                bound.insert(106);
            }),
            std::bind([this](){
                modified.erase(107);
                bound.insert(107);
            }),
            std::bind([this](){
                modified.erase(108);
                bound.insert(108);
            }),
            std::bind([this](){
                modified.erase(109);
                bound.insert(109);
            }),
            std::bind([this](){
                modified.erase(110);
                bound.insert(110);
            }),
            std::bind([this](){
                modified.erase(111);
                bound.insert(111);
            }),
            std::bind([this](){
                modified.erase(112);
                bound.insert(112);
            }),
            std::bind([this](){
                modified.erase(113);
                bound.insert(113);
            }),
            std::bind([this](){
                modified.erase(114);
                bound.insert(114);
            }),
            std::bind([this](){
                modified.erase(115);
                bound.insert(115);
            }),
            std::bind([this](){
                modified.erase(116);
                bound.insert(116);
            }),
            std::bind([this](){
                modified.erase(117);
                bound.insert(117);
            }),
            std::bind([this](){
                modified.erase(118);
                bound.insert(118);
            }),
            std::bind([this](){
                modified.erase(119);
                bound.insert(119);
            }),
            std::bind([this](){
                modified.erase(120);
                bound.insert(120);
            }),
            std::bind([this](){
                modified.erase(121);
                bound.insert(121);
            }),
            std::bind([this](){
                modified.erase(122);
                bound.insert(122);
            }),
            std::bind([this](){
                modified.erase(123);
                bound.insert(123);
            }),
            std::bind([this](){
                modified.erase(124);
                bound.insert(124);
            }),
            std::bind([this](){
                modified.erase(125);
                bound.insert(125);
            }),
            std::bind([this](){
                modified.erase(126);
                bound.insert(126);
            }),
            std::bind([this](){
                modified.erase(127);
                bound.insert(127);
            }),
            std::bind([this](){
                modified.erase(128);
                bound.insert(128);
            }),
            std::bind([this](){
                modified.erase(129);
                bound.insert(129);
            }),
            std::bind([this](){
                modified.erase(130);
                bound.insert(130);
            }),
            std::bind([this](){
                modified.erase(131);
                bound.insert(131);
            }),
            std::bind([this](){
                modified.erase(132);
                bound.insert(132);
            }),
            std::bind([this](){
                modified.erase(133);
                bound.insert(133);
            }),
            std::bind([this](){
                modified.erase(134);
                bound.insert(134);
            }),
            std::bind([this](){
                modified.erase(135);
                bound.insert(135);
            }),
            std::bind([this](){
                modified.erase(136);
                bound.insert(136);
            }),
            std::bind([this](){
                modified.erase(137);
                bound.insert(137);
            }),
        };
        const std::array<std::function<const std::string()>, 138> _attr_commit = {
            [this](){
                if (SVGElement::get_id() == Id.get_commit()) return std::string("");
                Id.commit();
                if (Id.get() == STR_NULL) return std::string("reset id");
                else return std::string("modify id \"" + Id.get() + "\"");
            },
            [this](){
                if (SVGElement::get_lang() == Lang.get_commit()) return std::string("");
                Lang.commit();
                if (Lang.get() == STR_NULL) return std::string("reset lang");
                else return std::string("modify lang \"" + Lang.get() + "\"");
            },
            [this](){
                if (SVGElement::get_tabindex() == Tabindex.get_commit()) return std::string("");
                Tabindex.commit();
                if (Tabindex.get() == STR_NULL) return std::string("reset tabindex");
                else return std::string("modify tabindex \"" + Tabindex.get() + "\"");
            },
            [this](){
                if (SVGElement::get_xmlZbase() == XmlBase.get_commit()) return std::string("");
                XmlBase.commit();
                if (XmlBase.get() == STR_NULL) return std::string("reset xml:base");
                else return std::string("modify xml:base \"" + XmlBase.get() + "\"");
            },
            [this](){
                if (SVGElement::get_xmlZlang() == XmlLang.get_commit()) return std::string("");
                XmlLang.commit();
                if (XmlLang.get() == STR_NULL) return std::string("reset xml:lang");
                else return std::string("modify xml:lang \"" + XmlLang.get() + "\"");
            },
            [this](){
                if (SVGElement::get_xmlZspace() == XmlSpace.get_commit()) return std::string("");
                XmlSpace.commit();
                if (XmlSpace.get() == STR_NULL) return std::string("reset xml:space");
                else return std::string("modify xml:space \"" + XmlSpace.get() + "\"");
            },
            [this](){
                if (SVGElement::get_class() == Class.get_commit()) return std::string("");
                Class.commit();
                if (Class.get() == STR_NULL) return std::string("reset class");
                else return std::string("modify class \"" + Class.get() + "\"");
            },
            [this](){
                if (SVGElement::get_style() == Style.get_commit()) return std::string("");
                Style.commit();
                if (Style.get() == STR_NULL) return std::string("reset style");
                else return std::string("modify style \"" + Style.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onbegin() == Onbegin.get_commit()) return std::string("");
                Onbegin.commit();
                if (Onbegin.get() == STR_NULL) return std::string("reset onbegin");
                else return std::string("modify onbegin \"" + Onbegin.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onend() == Onend.get_commit()) return std::string("");
                Onend.commit();
                if (Onend.get() == STR_NULL) return std::string("reset onend");
                else return std::string("modify onend \"" + Onend.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onrepeat() == Onrepeat.get_commit()) return std::string("");
                Onrepeat.commit();
                if (Onrepeat.get() == STR_NULL) return std::string("reset onrepeat");
                else return std::string("modify onrepeat \"" + Onrepeat.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onabort() == Onabort.get_commit()) return std::string("");
                Onabort.commit();
                if (Onabort.get() == STR_NULL) return std::string("reset onabort");
                else return std::string("modify onabort \"" + Onabort.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onerror() == Onerror.get_commit()) return std::string("");
                Onerror.commit();
                if (Onerror.get() == STR_NULL) return std::string("reset onerror");
                else return std::string("modify onerror \"" + Onerror.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onresize() == Onresize.get_commit()) return std::string("");
                Onresize.commit();
                if (Onresize.get() == STR_NULL) return std::string("reset onresize");
                else return std::string("modify onresize \"" + Onresize.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onscroll() == Onscroll.get_commit()) return std::string("");
                Onscroll.commit();
                if (Onscroll.get() == STR_NULL) return std::string("reset onscroll");
                else return std::string("modify onscroll \"" + Onscroll.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onunload() == Onunload.get_commit()) return std::string("");
                Onunload.commit();
                if (Onunload.get() == STR_NULL) return std::string("reset onunload");
                else return std::string("modify onunload \"" + Onunload.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncopy() == Oncopy.get_commit()) return std::string("");
                Oncopy.commit();
                if (Oncopy.get() == STR_NULL) return std::string("reset oncopy");
                else return std::string("modify oncopy \"" + Oncopy.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncut() == Oncut.get_commit()) return std::string("");
                Oncut.commit();
                if (Oncut.get() == STR_NULL) return std::string("reset oncut");
                else return std::string("modify oncut \"" + Oncut.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onpaste() == Onpaste.get_commit()) return std::string("");
                Onpaste.commit();
                if (Onpaste.get() == STR_NULL) return std::string("reset onpaste");
                else return std::string("modify onpaste \"" + Onpaste.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncancel() == Oncancel.get_commit()) return std::string("");
                Oncancel.commit();
                if (Oncancel.get() == STR_NULL) return std::string("reset oncancel");
                else return std::string("modify oncancel \"" + Oncancel.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncanplay() == Oncanplay.get_commit()) return std::string("");
                Oncanplay.commit();
                if (Oncanplay.get() == STR_NULL) return std::string("reset oncanplay");
                else return std::string("modify oncanplay \"" + Oncanplay.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncanplaythrough() == Oncanplaythrough.get_commit()) return std::string("");
                Oncanplaythrough.commit();
                if (Oncanplaythrough.get() == STR_NULL) return std::string("reset oncanplaythrough");
                else return std::string("modify oncanplaythrough \"" + Oncanplaythrough.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onchange() == Onchange.get_commit()) return std::string("");
                Onchange.commit();
                if (Onchange.get() == STR_NULL) return std::string("reset onchange");
                else return std::string("modify onchange \"" + Onchange.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onclick() == Onclick.get_commit()) return std::string("");
                Onclick.commit();
                if (Onclick.get() == STR_NULL) return std::string("reset onclick");
                else return std::string("modify onclick \"" + Onclick.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onclose() == Onclose.get_commit()) return std::string("");
                Onclose.commit();
                if (Onclose.get() == STR_NULL) return std::string("reset onclose");
                else return std::string("modify onclose \"" + Onclose.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oncuechange() == Oncuechange.get_commit()) return std::string("");
                Oncuechange.commit();
                if (Oncuechange.get() == STR_NULL) return std::string("reset oncuechange");
                else return std::string("modify oncuechange \"" + Oncuechange.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondblclick() == Ondblclick.get_commit()) return std::string("");
                Ondblclick.commit();
                if (Ondblclick.get() == STR_NULL) return std::string("reset ondblclick");
                else return std::string("modify ondblclick \"" + Ondblclick.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondrag() == Ondrag.get_commit()) return std::string("");
                Ondrag.commit();
                if (Ondrag.get() == STR_NULL) return std::string("reset ondrag");
                else return std::string("modify ondrag \"" + Ondrag.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondragend() == Ondragend.get_commit()) return std::string("");
                Ondragend.commit();
                if (Ondragend.get() == STR_NULL) return std::string("reset ondragend");
                else return std::string("modify ondragend \"" + Ondragend.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondragenter() == Ondragenter.get_commit()) return std::string("");
                Ondragenter.commit();
                if (Ondragenter.get() == STR_NULL) return std::string("reset ondragenter");
                else return std::string("modify ondragenter \"" + Ondragenter.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondragleave() == Ondragleave.get_commit()) return std::string("");
                Ondragleave.commit();
                if (Ondragleave.get() == STR_NULL) return std::string("reset ondragleave");
                else return std::string("modify ondragleave \"" + Ondragleave.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondragover() == Ondragover.get_commit()) return std::string("");
                Ondragover.commit();
                if (Ondragover.get() == STR_NULL) return std::string("reset ondragover");
                else return std::string("modify ondragover \"" + Ondragover.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondragstart() == Ondragstart.get_commit()) return std::string("");
                Ondragstart.commit();
                if (Ondragstart.get() == STR_NULL) return std::string("reset ondragstart");
                else return std::string("modify ondragstart \"" + Ondragstart.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondrop() == Ondrop.get_commit()) return std::string("");
                Ondrop.commit();
                if (Ondrop.get() == STR_NULL) return std::string("reset ondrop");
                else return std::string("modify ondrop \"" + Ondrop.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ondurationchange() == Ondurationchange.get_commit()) return std::string("");
                Ondurationchange.commit();
                if (Ondurationchange.get() == STR_NULL) return std::string("reset ondurationchange");
                else return std::string("modify ondurationchange \"" + Ondurationchange.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onemptied() == Onemptied.get_commit()) return std::string("");
                Onemptied.commit();
                if (Onemptied.get() == STR_NULL) return std::string("reset onemptied");
                else return std::string("modify onemptied \"" + Onemptied.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onended() == Onended.get_commit()) return std::string("");
                Onended.commit();
                if (Onended.get() == STR_NULL) return std::string("reset onended");
                else return std::string("modify onended \"" + Onended.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onfocus() == Onfocus.get_commit()) return std::string("");
                Onfocus.commit();
                if (Onfocus.get() == STR_NULL) return std::string("reset onfocus");
                else return std::string("modify onfocus \"" + Onfocus.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oninput() == Oninput.get_commit()) return std::string("");
                Oninput.commit();
                if (Oninput.get() == STR_NULL) return std::string("reset oninput");
                else return std::string("modify oninput \"" + Oninput.get() + "\"");
            },
            [this](){
                if (SVGElement::get_oninvalid() == Oninvalid.get_commit()) return std::string("");
                Oninvalid.commit();
                if (Oninvalid.get() == STR_NULL) return std::string("reset oninvalid");
                else return std::string("modify oninvalid \"" + Oninvalid.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onkeydown() == Onkeydown.get_commit()) return std::string("");
                Onkeydown.commit();
                if (Onkeydown.get() == STR_NULL) return std::string("reset onkeydown");
                else return std::string("modify onkeydown \"" + Onkeydown.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onkeypress() == Onkeypress.get_commit()) return std::string("");
                Onkeypress.commit();
                if (Onkeypress.get() == STR_NULL) return std::string("reset onkeypress");
                else return std::string("modify onkeypress \"" + Onkeypress.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onkeyup() == Onkeyup.get_commit()) return std::string("");
                Onkeyup.commit();
                if (Onkeyup.get() == STR_NULL) return std::string("reset onkeyup");
                else return std::string("modify onkeyup \"" + Onkeyup.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onload() == Onload.get_commit()) return std::string("");
                Onload.commit();
                if (Onload.get() == STR_NULL) return std::string("reset onload");
                else return std::string("modify onload \"" + Onload.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onloadeddata() == Onloadeddata.get_commit()) return std::string("");
                Onloadeddata.commit();
                if (Onloadeddata.get() == STR_NULL) return std::string("reset onloadeddata");
                else return std::string("modify onloadeddata \"" + Onloadeddata.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onloadedmetadata() == Onloadedmetadata.get_commit()) return std::string("");
                Onloadedmetadata.commit();
                if (Onloadedmetadata.get() == STR_NULL) return std::string("reset onloadedmetadata");
                else return std::string("modify onloadedmetadata \"" + Onloadedmetadata.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onloadstart() == Onloadstart.get_commit()) return std::string("");
                Onloadstart.commit();
                if (Onloadstart.get() == STR_NULL) return std::string("reset onloadstart");
                else return std::string("modify onloadstart \"" + Onloadstart.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmousedown() == Onmousedown.get_commit()) return std::string("");
                Onmousedown.commit();
                if (Onmousedown.get() == STR_NULL) return std::string("reset onmousedown");
                else return std::string("modify onmousedown \"" + Onmousedown.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmouseenter() == Onmouseenter.get_commit()) return std::string("");
                Onmouseenter.commit();
                if (Onmouseenter.get() == STR_NULL) return std::string("reset onmouseenter");
                else return std::string("modify onmouseenter \"" + Onmouseenter.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmouseleave() == Onmouseleave.get_commit()) return std::string("");
                Onmouseleave.commit();
                if (Onmouseleave.get() == STR_NULL) return std::string("reset onmouseleave");
                else return std::string("modify onmouseleave \"" + Onmouseleave.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmousemove() == Onmousemove.get_commit()) return std::string("");
                Onmousemove.commit();
                if (Onmousemove.get() == STR_NULL) return std::string("reset onmousemove");
                else return std::string("modify onmousemove \"" + Onmousemove.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmouseout() == Onmouseout.get_commit()) return std::string("");
                Onmouseout.commit();
                if (Onmouseout.get() == STR_NULL) return std::string("reset onmouseout");
                else return std::string("modify onmouseout \"" + Onmouseout.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmouseover() == Onmouseover.get_commit()) return std::string("");
                Onmouseover.commit();
                if (Onmouseover.get() == STR_NULL) return std::string("reset onmouseover");
                else return std::string("modify onmouseover \"" + Onmouseover.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmouseup() == Onmouseup.get_commit()) return std::string("");
                Onmouseup.commit();
                if (Onmouseup.get() == STR_NULL) return std::string("reset onmouseup");
                else return std::string("modify onmouseup \"" + Onmouseup.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onmousewheel() == Onmousewheel.get_commit()) return std::string("");
                Onmousewheel.commit();
                if (Onmousewheel.get() == STR_NULL) return std::string("reset onmousewheel");
                else return std::string("modify onmousewheel \"" + Onmousewheel.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onpause() == Onpause.get_commit()) return std::string("");
                Onpause.commit();
                if (Onpause.get() == STR_NULL) return std::string("reset onpause");
                else return std::string("modify onpause \"" + Onpause.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onplay() == Onplay.get_commit()) return std::string("");
                Onplay.commit();
                if (Onplay.get() == STR_NULL) return std::string("reset onplay");
                else return std::string("modify onplay \"" + Onplay.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onplaying() == Onplaying.get_commit()) return std::string("");
                Onplaying.commit();
                if (Onplaying.get() == STR_NULL) return std::string("reset onplaying");
                else return std::string("modify onplaying \"" + Onplaying.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onprogress() == Onprogress.get_commit()) return std::string("");
                Onprogress.commit();
                if (Onprogress.get() == STR_NULL) return std::string("reset onprogress");
                else return std::string("modify onprogress \"" + Onprogress.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onratechange() == Onratechange.get_commit()) return std::string("");
                Onratechange.commit();
                if (Onratechange.get() == STR_NULL) return std::string("reset onratechange");
                else return std::string("modify onratechange \"" + Onratechange.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onreset() == Onreset.get_commit()) return std::string("");
                Onreset.commit();
                if (Onreset.get() == STR_NULL) return std::string("reset onreset");
                else return std::string("modify onreset \"" + Onreset.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onseeked() == Onseeked.get_commit()) return std::string("");
                Onseeked.commit();
                if (Onseeked.get() == STR_NULL) return std::string("reset onseeked");
                else return std::string("modify onseeked \"" + Onseeked.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onseeking() == Onseeking.get_commit()) return std::string("");
                Onseeking.commit();
                if (Onseeking.get() == STR_NULL) return std::string("reset onseeking");
                else return std::string("modify onseeking \"" + Onseeking.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onselect() == Onselect.get_commit()) return std::string("");
                Onselect.commit();
                if (Onselect.get() == STR_NULL) return std::string("reset onselect");
                else return std::string("modify onselect \"" + Onselect.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onshow() == Onshow.get_commit()) return std::string("");
                Onshow.commit();
                if (Onshow.get() == STR_NULL) return std::string("reset onshow");
                else return std::string("modify onshow \"" + Onshow.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onstalled() == Onstalled.get_commit()) return std::string("");
                Onstalled.commit();
                if (Onstalled.get() == STR_NULL) return std::string("reset onstalled");
                else return std::string("modify onstalled \"" + Onstalled.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onsubmit() == Onsubmit.get_commit()) return std::string("");
                Onsubmit.commit();
                if (Onsubmit.get() == STR_NULL) return std::string("reset onsubmit");
                else return std::string("modify onsubmit \"" + Onsubmit.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onsuspend() == Onsuspend.get_commit()) return std::string("");
                Onsuspend.commit();
                if (Onsuspend.get() == STR_NULL) return std::string("reset onsuspend");
                else return std::string("modify onsuspend \"" + Onsuspend.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ontimeupdate() == Ontimeupdate.get_commit()) return std::string("");
                Ontimeupdate.commit();
                if (Ontimeupdate.get() == STR_NULL) return std::string("reset ontimeupdate");
                else return std::string("modify ontimeupdate \"" + Ontimeupdate.get() + "\"");
            },
            [this](){
                if (SVGElement::get_ontoggle() == Ontoggle.get_commit()) return std::string("");
                Ontoggle.commit();
                if (Ontoggle.get() == STR_NULL) return std::string("reset ontoggle");
                else return std::string("modify ontoggle \"" + Ontoggle.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onvolumechange() == Onvolumechange.get_commit()) return std::string("");
                Onvolumechange.commit();
                if (Onvolumechange.get() == STR_NULL) return std::string("reset onvolumechange");
                else return std::string("modify onvolumechange \"" + Onvolumechange.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onwaiting() == Onwaiting.get_commit()) return std::string("");
                Onwaiting.commit();
                if (Onwaiting.get() == STR_NULL) return std::string("reset onwaiting");
                else return std::string("modify onwaiting \"" + Onwaiting.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onactivate() == Onactivate.get_commit()) return std::string("");
                Onactivate.commit();
                if (Onactivate.get() == STR_NULL) return std::string("reset onactivate");
                else return std::string("modify onactivate \"" + Onactivate.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onfocusin() == Onfocusin.get_commit()) return std::string("");
                Onfocusin.commit();
                if (Onfocusin.get() == STR_NULL) return std::string("reset onfocusin");
                else return std::string("modify onfocusin \"" + Onfocusin.get() + "\"");
            },
            [this](){
                if (SVGElement::get_onfocusout() == Onfocusout.get_commit()) return std::string("");
                Onfocusout.commit();
                if (Onfocusout.get() == STR_NULL) return std::string("reset onfocusout");
                else return std::string("modify onfocusout \"" + Onfocusout.get() + "\"");
            },
            [this](){
                if (SVGElement::get_alignment_baseline() == AlignmentBaseline.get_commit()) return std::string("");
                AlignmentBaseline.commit();
                if (AlignmentBaseline.get() == STR_NULL) return std::string("reset alignment-baseline");
                else return std::string("modify alignment-baseline \"" + AlignmentBaseline.get() + "\"");
            },
            [this](){
                if (SVGElement::get_baseline_shift() == BaselineShift.get_commit()) return std::string("");
                BaselineShift.commit();
                if (BaselineShift.get() == STR_NULL) return std::string("reset baseline-shift");
                else return std::string("modify baseline-shift \"" + BaselineShift.get() + "\"");
            },
            [this](){
                if (SVGElement::get_clip_path() == ClipPath.get_commit()) return std::string("");
                ClipPath.commit();
                if (ClipPath.get() == STR_NULL) return std::string("reset clip-path");
                else return std::string("modify clip-path \"" + ClipPath.get() + "\"");
            },
            [this](){
                if (SVGElement::get_clip_rule() == ClipRule.get_commit()) return std::string("");
                ClipRule.commit();
                if (ClipRule.get() == STR_NULL) return std::string("reset clip-rule");
                else return std::string("modify clip-rule \"" + ClipRule.get() + "\"");
            },
            [this](){
                if (SVGElement::get_color() == Color.get_commit()) return std::string("");
                Color.commit();
                if (Color.get() == STR_NULL) return std::string("reset color");
                else return std::string("modify color \"" + Color.get() + "\"");
            },
            [this](){
                if (SVGElement::get_color_interpolation() == ColorInterpolation.get_commit()) return std::string("");
                ColorInterpolation.commit();
                if (ColorInterpolation.get() == STR_NULL) return std::string("reset color-interpolation");
                else return std::string("modify color-interpolation \"" + ColorInterpolation.get() + "\"");
            },
            [this](){
                if (SVGElement::get_color_interpolation_filters() == ColorInterpolationFilters.get_commit()) return std::string("");
                ColorInterpolationFilters.commit();
                if (ColorInterpolationFilters.get() == STR_NULL) return std::string("reset color-interpolation-filters");
                else return std::string("modify color-interpolation-filters \"" + ColorInterpolationFilters.get() + "\"");
            },
            [this](){
                if (SVGElement::get_color_profile() == ColorProfile.get_commit()) return std::string("");
                ColorProfile.commit();
                if (ColorProfile.get() == STR_NULL) return std::string("reset color-profile");
                else return std::string("modify color-profile \"" + ColorProfile.get() + "\"");
            },
            [this](){
                if (SVGElement::get_color_rendering() == ColorRendering.get_commit()) return std::string("");
                ColorRendering.commit();
                if (ColorRendering.get() == STR_NULL) return std::string("reset color-rendering");
                else return std::string("modify color-rendering \"" + ColorRendering.get() + "\"");
            },
            [this](){
                if (SVGElement::get_cursor() == Cursor.get_commit()) return std::string("");
                Cursor.commit();
                if (Cursor.get() == STR_NULL) return std::string("reset cursor");
                else return std::string("modify cursor \"" + Cursor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_d() == D.get_commit()) return std::string("");
                D.commit();
                if (D.get() == STR_NULL) return std::string("reset d");
                else return std::string("modify d \"" + D.get() + "\"");
            },
            [this](){
                if (SVGElement::get_direction() == Direction.get_commit()) return std::string("");
                Direction.commit();
                if (Direction.get() == STR_NULL) return std::string("reset direction");
                else return std::string("modify direction \"" + Direction.get() + "\"");
            },
            [this](){
                if (SVGElement::get_display() == Display.get_commit()) return std::string("");
                Display.commit();
                if (Display.get() == STR_NULL) return std::string("reset display");
                else return std::string("modify display \"" + Display.get() + "\"");
            },
            [this](){
                if (SVGElement::get_dominant_baseline() == DominantBaseline.get_commit()) return std::string("");
                DominantBaseline.commit();
                if (DominantBaseline.get() == STR_NULL) return std::string("reset dominant-baseline");
                else return std::string("modify dominant-baseline \"" + DominantBaseline.get() + "\"");
            },
            [this](){
                if (SVGElement::get_enable_background() == EnableBackground.get_commit()) return std::string("");
                EnableBackground.commit();
                if (EnableBackground.get() == STR_NULL) return std::string("reset enable-background");
                else return std::string("modify enable-background \"" + EnableBackground.get() + "\"");
            },
            [this](){
                if (SVGElement::get_fill() == Fill.get_commit()) return std::string("");
                Fill.commit();
                if (Fill.get() == STR_NULL) return std::string("reset fill");
                else return std::string("modify fill \"" + Fill.get() + "\"");
            },
            [this](){
                if (SVGElement::get_fill_opacity() == FillOpacity.get_commit()) return std::string("");
                FillOpacity.commit();
                if (FillOpacity.get() == STR_NULL) return std::string("reset fill-opacity");
                else return std::string("modify fill-opacity \"" + FillOpacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_fill_rule() == FillRule.get_commit()) return std::string("");
                FillRule.commit();
                if (FillRule.get() == STR_NULL) return std::string("reset fill-rule");
                else return std::string("modify fill-rule \"" + FillRule.get() + "\"");
            },
            [this](){
                if (SVGElement::get_filter() == Filter.get_commit()) return std::string("");
                Filter.commit();
                if (Filter.get() == STR_NULL) return std::string("reset filter");
                else return std::string("modify filter \"" + Filter.get() + "\"");
            },
            [this](){
                if (SVGElement::get_flood_color() == FloodColor.get_commit()) return std::string("");
                FloodColor.commit();
                if (FloodColor.get() == STR_NULL) return std::string("reset flood-color");
                else return std::string("modify flood-color \"" + FloodColor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_flood_opacity() == FloodOpacity.get_commit()) return std::string("");
                FloodOpacity.commit();
                if (FloodOpacity.get() == STR_NULL) return std::string("reset flood-opacity");
                else return std::string("modify flood-opacity \"" + FloodOpacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_family() == FontFamily.get_commit()) return std::string("");
                FontFamily.commit();
                if (FontFamily.get() == STR_NULL) return std::string("reset font-family");
                else return std::string("modify font-family \"" + FontFamily.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_size() == FontSize.get_commit()) return std::string("");
                FontSize.commit();
                if (FontSize.get() == STR_NULL) return std::string("reset font-size");
                else return std::string("modify font-size \"" + FontSize.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_size_adjust() == FontSizeAdjust.get_commit()) return std::string("");
                FontSizeAdjust.commit();
                if (FontSizeAdjust.get() == STR_NULL) return std::string("reset font-size-adjust");
                else return std::string("modify font-size-adjust \"" + FontSizeAdjust.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_stretch() == FontStretch.get_commit()) return std::string("");
                FontStretch.commit();
                if (FontStretch.get() == STR_NULL) return std::string("reset font-stretch");
                else return std::string("modify font-stretch \"" + FontStretch.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_style() == FontStyle.get_commit()) return std::string("");
                FontStyle.commit();
                if (FontStyle.get() == STR_NULL) return std::string("reset font-style");
                else return std::string("modify font-style \"" + FontStyle.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_variant() == FontVariant.get_commit()) return std::string("");
                FontVariant.commit();
                if (FontVariant.get() == STR_NULL) return std::string("reset font-variant");
                else return std::string("modify font-variant \"" + FontVariant.get() + "\"");
            },
            [this](){
                if (SVGElement::get_font_weight() == FontWeight.get_commit()) return std::string("");
                FontWeight.commit();
                if (FontWeight.get() == STR_NULL) return std::string("reset font-weight");
                else return std::string("modify font-weight \"" + FontWeight.get() + "\"");
            },
            [this](){
                if (SVGElement::get_glyph_orientation_horizontal() == GlyphOrientationHorizontal.get_commit()) return std::string("");
                GlyphOrientationHorizontal.commit();
                if (GlyphOrientationHorizontal.get() == STR_NULL) return std::string("reset glyph-orientation-horizontal");
                else return std::string("modify glyph-orientation-horizontal \"" + GlyphOrientationHorizontal.get() + "\"");
            },
            [this](){
                if (SVGElement::get_glyph_orientation_vertical() == GlyphOrientationVertical.get_commit()) return std::string("");
                GlyphOrientationVertical.commit();
                if (GlyphOrientationVertical.get() == STR_NULL) return std::string("reset glyph-orientation-vertical");
                else return std::string("modify glyph-orientation-vertical \"" + GlyphOrientationVertical.get() + "\"");
            },
            [this](){
                if (SVGElement::get_image_rendering() == ImageRendering.get_commit()) return std::string("");
                ImageRendering.commit();
                if (ImageRendering.get() == STR_NULL) return std::string("reset image-rendering");
                else return std::string("modify image-rendering \"" + ImageRendering.get() + "\"");
            },
            [this](){
                if (SVGElement::get_kerning() == Kerning.get_commit()) return std::string("");
                Kerning.commit();
                if (Kerning.get() == STR_NULL) return std::string("reset kerning");
                else return std::string("modify kerning \"" + Kerning.get() + "\"");
            },
            [this](){
                if (SVGElement::get_letter_spacing() == LetterSpacing.get_commit()) return std::string("");
                LetterSpacing.commit();
                if (LetterSpacing.get() == STR_NULL) return std::string("reset letter-spacing");
                else return std::string("modify letter-spacing \"" + LetterSpacing.get() + "\"");
            },
            [this](){
                if (SVGElement::get_lighting_color() == LightingColor.get_commit()) return std::string("");
                LightingColor.commit();
                if (LightingColor.get() == STR_NULL) return std::string("reset lighting-color");
                else return std::string("modify lighting-color \"" + LightingColor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_marker_end() == MarkerEnd.get_commit()) return std::string("");
                MarkerEnd.commit();
                if (MarkerEnd.get() == STR_NULL) return std::string("reset marker-end");
                else return std::string("modify marker-end \"" + MarkerEnd.get() + "\"");
            },
            [this](){
                if (SVGElement::get_marker_mid() == MarkerMid.get_commit()) return std::string("");
                MarkerMid.commit();
                if (MarkerMid.get() == STR_NULL) return std::string("reset marker-mid");
                else return std::string("modify marker-mid \"" + MarkerMid.get() + "\"");
            },
            [this](){
                if (SVGElement::get_marker_start() == MarkerStart.get_commit()) return std::string("");
                MarkerStart.commit();
                if (MarkerStart.get() == STR_NULL) return std::string("reset marker-start");
                else return std::string("modify marker-start \"" + MarkerStart.get() + "\"");
            },
            [this](){
                if (SVGElement::get_mask() == Mask.get_commit()) return std::string("");
                Mask.commit();
                if (Mask.get() == STR_NULL) return std::string("reset mask");
                else return std::string("modify mask \"" + Mask.get() + "\"");
            },
            [this](){
                if (SVGElement::get_opacity() == Opacity.get_commit()) return std::string("");
                Opacity.commit();
                if (Opacity.get() == STR_NULL) return std::string("reset opacity");
                else return std::string("modify opacity \"" + Opacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_overflow() == Overflow.get_commit()) return std::string("");
                Overflow.commit();
                if (Overflow.get() == STR_NULL) return std::string("reset overflow");
                else return std::string("modify overflow \"" + Overflow.get() + "\"");
            },
            [this](){
                if (SVGElement::get_pointer_events() == PointerEvents.get_commit()) return std::string("");
                PointerEvents.commit();
                if (PointerEvents.get() == STR_NULL) return std::string("reset pointer-events");
                else return std::string("modify pointer-events \"" + PointerEvents.get() + "\"");
            },
            [this](){
                if (SVGElement::get_shape_rendering() == ShapeRendering.get_commit()) return std::string("");
                ShapeRendering.commit();
                if (ShapeRendering.get() == STR_NULL) return std::string("reset shape-rendering");
                else return std::string("modify shape-rendering \"" + ShapeRendering.get() + "\"");
            },
            [this](){
                if (SVGElement::get_solid_color() == SolidColor.get_commit()) return std::string("");
                SolidColor.commit();
                if (SolidColor.get() == STR_NULL) return std::string("reset solid-color");
                else return std::string("modify solid-color \"" + SolidColor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_solid_opacity() == SolidOpacity.get_commit()) return std::string("");
                SolidOpacity.commit();
                if (SolidOpacity.get() == STR_NULL) return std::string("reset solid-opacity");
                else return std::string("modify solid-opacity \"" + SolidOpacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stop_color() == StopColor.get_commit()) return std::string("");
                StopColor.commit();
                if (StopColor.get() == STR_NULL) return std::string("reset stop-color");
                else return std::string("modify stop-color \"" + StopColor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stop_opacity() == StopOpacity.get_commit()) return std::string("");
                StopOpacity.commit();
                if (StopOpacity.get() == STR_NULL) return std::string("reset stop-opacity");
                else return std::string("modify stop-opacity \"" + StopOpacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke() == Stroke.get_commit()) return std::string("");
                Stroke.commit();
                if (Stroke.get() == STR_NULL) return std::string("reset stroke");
                else return std::string("modify stroke \"" + Stroke.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_dasharray() == StrokeDasharray.get_commit()) return std::string("");
                StrokeDasharray.commit();
                if (StrokeDasharray.get() == STR_NULL) return std::string("reset stroke-dasharray");
                else return std::string("modify stroke-dasharray \"" + StrokeDasharray.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_dashoffset() == StrokeDashoffset.get_commit()) return std::string("");
                StrokeDashoffset.commit();
                if (StrokeDashoffset.get() == STR_NULL) return std::string("reset stroke-dashoffset");
                else return std::string("modify stroke-dashoffset \"" + StrokeDashoffset.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_linecap() == StrokeLinecap.get_commit()) return std::string("");
                StrokeLinecap.commit();
                if (StrokeLinecap.get() == STR_NULL) return std::string("reset stroke-linecap");
                else return std::string("modify stroke-linecap \"" + StrokeLinecap.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_linejoin() == StrokeLinejoin.get_commit()) return std::string("");
                StrokeLinejoin.commit();
                if (StrokeLinejoin.get() == STR_NULL) return std::string("reset stroke-linejoin");
                else return std::string("modify stroke-linejoin \"" + StrokeLinejoin.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_miterlimit() == StrokeMiterlimit.get_commit()) return std::string("");
                StrokeMiterlimit.commit();
                if (StrokeMiterlimit.get() == STR_NULL) return std::string("reset stroke-miterlimit");
                else return std::string("modify stroke-miterlimit \"" + StrokeMiterlimit.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_opacity() == StrokeOpacity.get_commit()) return std::string("");
                StrokeOpacity.commit();
                if (StrokeOpacity.get() == STR_NULL) return std::string("reset stroke-opacity");
                else return std::string("modify stroke-opacity \"" + StrokeOpacity.get() + "\"");
            },
            [this](){
                if (SVGElement::get_stroke_width() == StrokeWidth.get_commit()) return std::string("");
                StrokeWidth.commit();
                if (StrokeWidth.get() == STR_NULL) return std::string("reset stroke-width");
                else return std::string("modify stroke-width \"" + StrokeWidth.get() + "\"");
            },
            [this](){
                if (SVGElement::get_text_anchor() == TextAnchor.get_commit()) return std::string("");
                TextAnchor.commit();
                if (TextAnchor.get() == STR_NULL) return std::string("reset text-anchor");
                else return std::string("modify text-anchor \"" + TextAnchor.get() + "\"");
            },
            [this](){
                if (SVGElement::get_text_decoration() == TextDecoration.get_commit()) return std::string("");
                TextDecoration.commit();
                if (TextDecoration.get() == STR_NULL) return std::string("reset text-decoration");
                else return std::string("modify text-decoration \"" + TextDecoration.get() + "\"");
            },
            [this](){
                if (SVGElement::get_text_rendering() == TextRendering.get_commit()) return std::string("");
                TextRendering.commit();
                if (TextRendering.get() == STR_NULL) return std::string("reset text-rendering");
                else return std::string("modify text-rendering \"" + TextRendering.get() + "\"");
            },
            [this](){
                if (SVGElement::get_transform() == Transform.get_commit()) return std::string("");
                Transform.commit();
                if (Transform.get() == STR_NULL) return std::string("reset transform");
                else return std::string("modify transform \"" + Transform.get() + "\"");
            },
            [this](){
                if (SVGElement::get_unicode_bidi() == UnicodeBidi.get_commit()) return std::string("");
                UnicodeBidi.commit();
                if (UnicodeBidi.get() == STR_NULL) return std::string("reset unicode-bidi");
                else return std::string("modify unicode-bidi \"" + UnicodeBidi.get() + "\"");
            },
            [this](){
                if (SVGElement::get_vector_effect() == VectorEffect.get_commit()) return std::string("");
                VectorEffect.commit();
                if (VectorEffect.get() == STR_NULL) return std::string("reset vector-effect");
                else return std::string("modify vector-effect \"" + VectorEffect.get() + "\"");
            },
            [this](){
                if (SVGElement::get_visibility() == Visibility.get_commit()) return std::string("");
                Visibility.commit();
                if (Visibility.get() == STR_NULL) return std::string("reset visibility");
                else return std::string("modify visibility \"" + Visibility.get() + "\"");
            },
            [this](){
                if (SVGElement::get_word_spacing() == WordSpacing.get_commit()) return std::string("");
                WordSpacing.commit();
                if (WordSpacing.get() == STR_NULL) return std::string("reset word-spacing");
                else return std::string("modify word-spacing \"" + WordSpacing.get() + "\"");
            },
            [this](){
                if (SVGElement::get_writing_mode() == WritingMode.get_commit()) return std::string("");
                WritingMode.commit();
                if (WritingMode.get() == STR_NULL) return std::string("reset writing-mode");
                else return std::string("modify writing-mode \"" + WritingMode.get() + "\"");
            },
        };

    private:
        using SVGElement::inner_SVG;
        using SVGElement::set_raw_HTML;
        using SVGElement::get_raw_HTML;
        using SVGElement::add_inner_element;
        using SVGElement::remove_inner_element;
        using SVGElement::get_inner_element;
        using SVGElement::get_inner_elements;
        using SVGElement::set_inner_elements;
        using SVGElement::get_attribute_hash;
        using SVGElement::get_inner_hash;
        using SVGElement::get_outer_hash;
    private:
        using SVGElement::get_id;
        using SVGElement::set_id;
        using SVGElement::get_lang;
        using SVGElement::set_lang;
        using SVGElement::get_tabindex;
        using SVGElement::set_tabindex;
        using SVGElement::get_xmlZbase;
        using SVGElement::set_xmlZbase;
        using SVGElement::get_xmlZlang;
        using SVGElement::set_xmlZlang;
        using SVGElement::get_xmlZspace;
        using SVGElement::set_xmlZspace;
        using SVGElement::get_class;
        using SVGElement::set_class;
        using SVGElement::get_style;
        using SVGElement::set_style;
        using SVGElement::get_onbegin;
        using SVGElement::set_onbegin;
        using SVGElement::get_onend;
        using SVGElement::set_onend;
        using SVGElement::get_onrepeat;
        using SVGElement::set_onrepeat;
        using SVGElement::get_onabort;
        using SVGElement::set_onabort;
        using SVGElement::get_onerror;
        using SVGElement::set_onerror;
        using SVGElement::get_onresize;
        using SVGElement::set_onresize;
        using SVGElement::get_onscroll;
        using SVGElement::set_onscroll;
        using SVGElement::get_onunload;
        using SVGElement::set_onunload;
        using SVGElement::get_oncopy;
        using SVGElement::set_oncopy;
        using SVGElement::get_oncut;
        using SVGElement::set_oncut;
        using SVGElement::get_onpaste;
        using SVGElement::set_onpaste;
        using SVGElement::get_oncancel;
        using SVGElement::set_oncancel;
        using SVGElement::get_oncanplay;
        using SVGElement::set_oncanplay;
        using SVGElement::get_oncanplaythrough;
        using SVGElement::set_oncanplaythrough;
        using SVGElement::get_onchange;
        using SVGElement::set_onchange;
        using SVGElement::get_onclick;
        using SVGElement::set_onclick;
        using SVGElement::get_onclose;
        using SVGElement::set_onclose;
        using SVGElement::get_oncuechange;
        using SVGElement::set_oncuechange;
        using SVGElement::get_ondblclick;
        using SVGElement::set_ondblclick;
        using SVGElement::get_ondrag;
        using SVGElement::set_ondrag;
        using SVGElement::get_ondragend;
        using SVGElement::set_ondragend;
        using SVGElement::get_ondragenter;
        using SVGElement::set_ondragenter;
        using SVGElement::get_ondragleave;
        using SVGElement::set_ondragleave;
        using SVGElement::get_ondragover;
        using SVGElement::set_ondragover;
        using SVGElement::get_ondragstart;
        using SVGElement::set_ondragstart;
        using SVGElement::get_ondrop;
        using SVGElement::set_ondrop;
        using SVGElement::get_ondurationchange;
        using SVGElement::set_ondurationchange;
        using SVGElement::get_onemptied;
        using SVGElement::set_onemptied;
        using SVGElement::get_onended;
        using SVGElement::set_onended;
        using SVGElement::get_onfocus;
        using SVGElement::set_onfocus;
        using SVGElement::get_oninput;
        using SVGElement::set_oninput;
        using SVGElement::get_oninvalid;
        using SVGElement::set_oninvalid;
        using SVGElement::get_onkeydown;
        using SVGElement::set_onkeydown;
        using SVGElement::get_onkeypress;
        using SVGElement::set_onkeypress;
        using SVGElement::get_onkeyup;
        using SVGElement::set_onkeyup;
        using SVGElement::get_onload;
        using SVGElement::set_onload;
        using SVGElement::get_onloadeddata;
        using SVGElement::set_onloadeddata;
        using SVGElement::get_onloadedmetadata;
        using SVGElement::set_onloadedmetadata;
        using SVGElement::get_onloadstart;
        using SVGElement::set_onloadstart;
        using SVGElement::get_onmousedown;
        using SVGElement::set_onmousedown;
        using SVGElement::get_onmouseenter;
        using SVGElement::set_onmouseenter;
        using SVGElement::get_onmouseleave;
        using SVGElement::set_onmouseleave;
        using SVGElement::get_onmousemove;
        using SVGElement::set_onmousemove;
        using SVGElement::get_onmouseout;
        using SVGElement::set_onmouseout;
        using SVGElement::get_onmouseover;
        using SVGElement::set_onmouseover;
        using SVGElement::get_onmouseup;
        using SVGElement::set_onmouseup;
        using SVGElement::get_onmousewheel;
        using SVGElement::set_onmousewheel;
        using SVGElement::get_onpause;
        using SVGElement::set_onpause;
        using SVGElement::get_onplay;
        using SVGElement::set_onplay;
        using SVGElement::get_onplaying;
        using SVGElement::set_onplaying;
        using SVGElement::get_onprogress;
        using SVGElement::set_onprogress;
        using SVGElement::get_onratechange;
        using SVGElement::set_onratechange;
        using SVGElement::get_onreset;
        using SVGElement::set_onreset;
        using SVGElement::get_onseeked;
        using SVGElement::set_onseeked;
        using SVGElement::get_onseeking;
        using SVGElement::set_onseeking;
        using SVGElement::get_onselect;
        using SVGElement::set_onselect;
        using SVGElement::get_onshow;
        using SVGElement::set_onshow;
        using SVGElement::get_onstalled;
        using SVGElement::set_onstalled;
        using SVGElement::get_onsubmit;
        using SVGElement::set_onsubmit;
        using SVGElement::get_onsuspend;
        using SVGElement::set_onsuspend;
        using SVGElement::get_ontimeupdate;
        using SVGElement::set_ontimeupdate;
        using SVGElement::get_ontoggle;
        using SVGElement::set_ontoggle;
        using SVGElement::get_onvolumechange;
        using SVGElement::set_onvolumechange;
        using SVGElement::get_onwaiting;
        using SVGElement::set_onwaiting;
        using SVGElement::get_onactivate;
        using SVGElement::set_onactivate;
        using SVGElement::get_onfocusin;
        using SVGElement::set_onfocusin;
        using SVGElement::get_onfocusout;
        using SVGElement::set_onfocusout;
        using SVGElement::get_alignment_baseline;
        using SVGElement::set_alignment_baseline;
        using SVGElement::get_baseline_shift;
        using SVGElement::set_baseline_shift;
        using SVGElement::get_clip_path;
        using SVGElement::set_clip_path;
        using SVGElement::get_clip_rule;
        using SVGElement::set_clip_rule;
        using SVGElement::get_color;
        using SVGElement::set_color;
        using SVGElement::get_color_interpolation;
        using SVGElement::set_color_interpolation;
        using SVGElement::get_color_interpolation_filters;
        using SVGElement::set_color_interpolation_filters;
        using SVGElement::get_color_profile;
        using SVGElement::set_color_profile;
        using SVGElement::get_color_rendering;
        using SVGElement::set_color_rendering;
        using SVGElement::get_cursor;
        using SVGElement::set_cursor;
        using SVGElement::get_d;
        using SVGElement::set_d;
        using SVGElement::get_direction;
        using SVGElement::set_direction;
        using SVGElement::get_display;
        using SVGElement::set_display;
        using SVGElement::get_dominant_baseline;
        using SVGElement::set_dominant_baseline;
        using SVGElement::get_enable_background;
        using SVGElement::set_enable_background;
        using SVGElement::get_fill;
        using SVGElement::set_fill;
        using SVGElement::get_fill_opacity;
        using SVGElement::set_fill_opacity;
        using SVGElement::get_fill_rule;
        using SVGElement::set_fill_rule;
        using SVGElement::get_filter;
        using SVGElement::set_filter;
        using SVGElement::get_flood_color;
        using SVGElement::set_flood_color;
        using SVGElement::get_flood_opacity;
        using SVGElement::set_flood_opacity;
        using SVGElement::get_font_family;
        using SVGElement::set_font_family;
        using SVGElement::get_font_size;
        using SVGElement::set_font_size;
        using SVGElement::get_font_size_adjust;
        using SVGElement::set_font_size_adjust;
        using SVGElement::get_font_stretch;
        using SVGElement::set_font_stretch;
        using SVGElement::get_font_style;
        using SVGElement::set_font_style;
        using SVGElement::get_font_variant;
        using SVGElement::set_font_variant;
        using SVGElement::get_font_weight;
        using SVGElement::set_font_weight;
        using SVGElement::get_glyph_orientation_horizontal;
        using SVGElement::set_glyph_orientation_horizontal;
        using SVGElement::get_glyph_orientation_vertical;
        using SVGElement::set_glyph_orientation_vertical;
        using SVGElement::get_image_rendering;
        using SVGElement::set_image_rendering;
        using SVGElement::get_kerning;
        using SVGElement::set_kerning;
        using SVGElement::get_letter_spacing;
        using SVGElement::set_letter_spacing;
        using SVGElement::get_lighting_color;
        using SVGElement::set_lighting_color;
        using SVGElement::get_marker_end;
        using SVGElement::set_marker_end;
        using SVGElement::get_marker_mid;
        using SVGElement::set_marker_mid;
        using SVGElement::get_marker_start;
        using SVGElement::set_marker_start;
        using SVGElement::get_mask;
        using SVGElement::set_mask;
        using SVGElement::get_opacity;
        using SVGElement::set_opacity;
        using SVGElement::get_overflow;
        using SVGElement::set_overflow;
        using SVGElement::get_pointer_events;
        using SVGElement::set_pointer_events;
        using SVGElement::get_shape_rendering;
        using SVGElement::set_shape_rendering;
        using SVGElement::get_solid_color;
        using SVGElement::set_solid_color;
        using SVGElement::get_solid_opacity;
        using SVGElement::set_solid_opacity;
        using SVGElement::get_stop_color;
        using SVGElement::set_stop_color;
        using SVGElement::get_stop_opacity;
        using SVGElement::set_stop_opacity;
        using SVGElement::get_stroke;
        using SVGElement::set_stroke;
        using SVGElement::get_stroke_dasharray;
        using SVGElement::set_stroke_dasharray;
        using SVGElement::get_stroke_dashoffset;
        using SVGElement::set_stroke_dashoffset;
        using SVGElement::get_stroke_linecap;
        using SVGElement::set_stroke_linecap;
        using SVGElement::get_stroke_linejoin;
        using SVGElement::set_stroke_linejoin;
        using SVGElement::get_stroke_miterlimit;
        using SVGElement::set_stroke_miterlimit;
        using SVGElement::get_stroke_opacity;
        using SVGElement::set_stroke_opacity;
        using SVGElement::get_stroke_width;
        using SVGElement::set_stroke_width;
        using SVGElement::get_text_anchor;
        using SVGElement::set_text_anchor;
        using SVGElement::get_text_decoration;
        using SVGElement::set_text_decoration;
        using SVGElement::get_text_rendering;
        using SVGElement::set_text_rendering;
        using SVGElement::get_transform;
        using SVGElement::set_transform;
        using SVGElement::get_unicode_bidi;
        using SVGElement::set_unicode_bidi;
        using SVGElement::get_vector_effect;
        using SVGElement::set_vector_effect;
        using SVGElement::get_visibility;
        using SVGElement::set_visibility;
        using SVGElement::get_word_spacing;
        using SVGElement::set_word_spacing;
        using SVGElement::get_writing_mode;
        using SVGElement::set_writing_mode;
    
        /// Inner SVG
    protected:
        std::string _inner_text_commit;
        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_commit;
        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_last;
        std::weak_ptr<SVGIElement> _parent_element_commit;
    public:
        AttrAnything RawHTML;
    private:
        bool _updated_raw_html = false;
    protected:
        struct _i_el_idx {
            std::shared_ptr<SVGIElement> ptr;
            int idx;
            bool operator<(const _i_el_idx &b) const {
                if (ptr == b.ptr) return idx < b.idx;
                return ptr < b.ptr;
            }
        };
        /**
        * Compare inner elements before and after commitment.
        */
        void inner_differ_commit(std::vector<int> &removal,
            std::vector<int> &addition,
            std::vector<std::pair<int, int>> &unchanged) const;
    public:
        /**
        * Get inner SVG of this SVG element.
        *
        * @return inner SVG.
        */
        const std::string inner_SVG() const;
        /**
        * Add a sub element to this SVG element.
        *
        * @param element an inner element.
        * @param index the index to be insert. default -1 means tail.
        */
        void add(const std::shared_ptr<SVGIElement> &element, int index = -1);
        /**
        * Remove a child element or child elements from this SVG element, based on content.
        *
        * @param element an inner element.
        * @param remove_all if to remove all occurances.
        */
        void remove(const std::shared_ptr<SVGIElement> &element, bool remove_all = false);
        /**
        * Remove a child element or child elements from this SVG element, by index.
        *
        * @param index the index of inner element.
        */
        void remove(int index);
        /**
        * Get inner SVG element in this SVG element, by index.
        *
        * @return inner element.
        */
        std::shared_ptr<SVGIElement> child(int index) const;
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner element list, readonly.
        */
        const std::vector<std::shared_ptr<SVGIElement>> children() const;
        /**
        * Set inner SVG elements list in this SVG element.
        *
        * @param inner_elements inner elements list.
        */
        void children(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements);
    
        /// Outer SVG
    public:
        /**
        * Get SVG of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string outer_SVG() const;
        /**
        * Get hash of outer SVG.
        *
        * @return hash of outer SVG.
        */
        const HASH_CODE hash() const;

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string commit();
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        std::shared_ptr<SVGIElement> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIElement &operator=(const SVGIElement &element);
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGIElement
        */
        bool operator==(const SVGElement &element) const;
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGIElement
        */
        bool operator!=(const SVGElement &element) const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const;
    };
}

#include "svgi_el/svgi_radial_gradient.h"
#include "svgi_el/svgi_circle.h"
#include "svgi_el/svgi_ellipse.h"
#include "svgi_el/svgi_path.h"
#include "svgi_el/svgi_line.h"
#include "svgi_el/svgi_g.h"
#include "svgi_el/svgi_mask.h"
#include "svgi_el/svgi_rect.h"
#include "svgi_el/svgi_image.h"
#include "svgi_el/svgi_text.h"
#include "svgi_el/svgi_pattern.h"
#include "svgi_el/svgi_polyline.h"
#include "svgi_el/svgi_marker.h"
#include "svgi_el/svgi_polygon.h"
#include "svgi_el/svgi_defs.h"
#include "svgi_el/svgi_foreign_object.h"
#include "svgi_el/svgi_linear_gradient.h"
#include "svgi_el/svgi_svg.h"
#include "svgi_el/svgi_stop.h"
#include "svgi_el/svgi_use.h"
#endif
