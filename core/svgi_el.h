#ifndef __LZ_SVGI_ELEMENT__
#define __LZ_SVGI_ELEMENT__
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
                Id.commit();
                if (Id.get() == STR_NULL) return std::string("reset Id");
                else return std::string("modify Id \"" + Id.get() + "\"");
            },
            [this](){
                Lang.commit();
                if (Lang.get() == STR_NULL) return std::string("reset Lang");
                else return std::string("modify Lang \"" + Lang.get() + "\"");
            },
            [this](){
                Tabindex.commit();
                if (Tabindex.get() == STR_NULL) return std::string("reset Tabindex");
                else return std::string("modify Tabindex \"" + Tabindex.get() + "\"");
            },
            [this](){
                XmlBase.commit();
                if (XmlBase.get() == STR_NULL) return std::string("reset XmlBase");
                else return std::string("modify XmlBase \"" + XmlBase.get() + "\"");
            },
            [this](){
                XmlLang.commit();
                if (XmlLang.get() == STR_NULL) return std::string("reset XmlLang");
                else return std::string("modify XmlLang \"" + XmlLang.get() + "\"");
            },
            [this](){
                XmlSpace.commit();
                if (XmlSpace.get() == STR_NULL) return std::string("reset XmlSpace");
                else return std::string("modify XmlSpace \"" + XmlSpace.get() + "\"");
            },
            [this](){
                Class.commit();
                if (Class.get() == STR_NULL) return std::string("reset Class");
                else return std::string("modify Class \"" + Class.get() + "\"");
            },
            [this](){
                Style.commit();
                if (Style.get() == STR_NULL) return std::string("reset Style");
                else return std::string("modify Style \"" + Style.get() + "\"");
            },
            [this](){
                Onbegin.commit();
                if (Onbegin.get() == STR_NULL) return std::string("reset Onbegin");
                else return std::string("modify Onbegin \"" + Onbegin.get() + "\"");
            },
            [this](){
                Onend.commit();
                if (Onend.get() == STR_NULL) return std::string("reset Onend");
                else return std::string("modify Onend \"" + Onend.get() + "\"");
            },
            [this](){
                Onrepeat.commit();
                if (Onrepeat.get() == STR_NULL) return std::string("reset Onrepeat");
                else return std::string("modify Onrepeat \"" + Onrepeat.get() + "\"");
            },
            [this](){
                Onabort.commit();
                if (Onabort.get() == STR_NULL) return std::string("reset Onabort");
                else return std::string("modify Onabort \"" + Onabort.get() + "\"");
            },
            [this](){
                Onerror.commit();
                if (Onerror.get() == STR_NULL) return std::string("reset Onerror");
                else return std::string("modify Onerror \"" + Onerror.get() + "\"");
            },
            [this](){
                Onresize.commit();
                if (Onresize.get() == STR_NULL) return std::string("reset Onresize");
                else return std::string("modify Onresize \"" + Onresize.get() + "\"");
            },
            [this](){
                Onscroll.commit();
                if (Onscroll.get() == STR_NULL) return std::string("reset Onscroll");
                else return std::string("modify Onscroll \"" + Onscroll.get() + "\"");
            },
            [this](){
                Onunload.commit();
                if (Onunload.get() == STR_NULL) return std::string("reset Onunload");
                else return std::string("modify Onunload \"" + Onunload.get() + "\"");
            },
            [this](){
                Oncopy.commit();
                if (Oncopy.get() == STR_NULL) return std::string("reset Oncopy");
                else return std::string("modify Oncopy \"" + Oncopy.get() + "\"");
            },
            [this](){
                Oncut.commit();
                if (Oncut.get() == STR_NULL) return std::string("reset Oncut");
                else return std::string("modify Oncut \"" + Oncut.get() + "\"");
            },
            [this](){
                Onpaste.commit();
                if (Onpaste.get() == STR_NULL) return std::string("reset Onpaste");
                else return std::string("modify Onpaste \"" + Onpaste.get() + "\"");
            },
            [this](){
                Oncancel.commit();
                if (Oncancel.get() == STR_NULL) return std::string("reset Oncancel");
                else return std::string("modify Oncancel \"" + Oncancel.get() + "\"");
            },
            [this](){
                Oncanplay.commit();
                if (Oncanplay.get() == STR_NULL) return std::string("reset Oncanplay");
                else return std::string("modify Oncanplay \"" + Oncanplay.get() + "\"");
            },
            [this](){
                Oncanplaythrough.commit();
                if (Oncanplaythrough.get() == STR_NULL) return std::string("reset Oncanplaythrough");
                else return std::string("modify Oncanplaythrough \"" + Oncanplaythrough.get() + "\"");
            },
            [this](){
                Onchange.commit();
                if (Onchange.get() == STR_NULL) return std::string("reset Onchange");
                else return std::string("modify Onchange \"" + Onchange.get() + "\"");
            },
            [this](){
                Onclick.commit();
                if (Onclick.get() == STR_NULL) return std::string("reset Onclick");
                else return std::string("modify Onclick \"" + Onclick.get() + "\"");
            },
            [this](){
                Onclose.commit();
                if (Onclose.get() == STR_NULL) return std::string("reset Onclose");
                else return std::string("modify Onclose \"" + Onclose.get() + "\"");
            },
            [this](){
                Oncuechange.commit();
                if (Oncuechange.get() == STR_NULL) return std::string("reset Oncuechange");
                else return std::string("modify Oncuechange \"" + Oncuechange.get() + "\"");
            },
            [this](){
                Ondblclick.commit();
                if (Ondblclick.get() == STR_NULL) return std::string("reset Ondblclick");
                else return std::string("modify Ondblclick \"" + Ondblclick.get() + "\"");
            },
            [this](){
                Ondrag.commit();
                if (Ondrag.get() == STR_NULL) return std::string("reset Ondrag");
                else return std::string("modify Ondrag \"" + Ondrag.get() + "\"");
            },
            [this](){
                Ondragend.commit();
                if (Ondragend.get() == STR_NULL) return std::string("reset Ondragend");
                else return std::string("modify Ondragend \"" + Ondragend.get() + "\"");
            },
            [this](){
                Ondragenter.commit();
                if (Ondragenter.get() == STR_NULL) return std::string("reset Ondragenter");
                else return std::string("modify Ondragenter \"" + Ondragenter.get() + "\"");
            },
            [this](){
                Ondragleave.commit();
                if (Ondragleave.get() == STR_NULL) return std::string("reset Ondragleave");
                else return std::string("modify Ondragleave \"" + Ondragleave.get() + "\"");
            },
            [this](){
                Ondragover.commit();
                if (Ondragover.get() == STR_NULL) return std::string("reset Ondragover");
                else return std::string("modify Ondragover \"" + Ondragover.get() + "\"");
            },
            [this](){
                Ondragstart.commit();
                if (Ondragstart.get() == STR_NULL) return std::string("reset Ondragstart");
                else return std::string("modify Ondragstart \"" + Ondragstart.get() + "\"");
            },
            [this](){
                Ondrop.commit();
                if (Ondrop.get() == STR_NULL) return std::string("reset Ondrop");
                else return std::string("modify Ondrop \"" + Ondrop.get() + "\"");
            },
            [this](){
                Ondurationchange.commit();
                if (Ondurationchange.get() == STR_NULL) return std::string("reset Ondurationchange");
                else return std::string("modify Ondurationchange \"" + Ondurationchange.get() + "\"");
            },
            [this](){
                Onemptied.commit();
                if (Onemptied.get() == STR_NULL) return std::string("reset Onemptied");
                else return std::string("modify Onemptied \"" + Onemptied.get() + "\"");
            },
            [this](){
                Onended.commit();
                if (Onended.get() == STR_NULL) return std::string("reset Onended");
                else return std::string("modify Onended \"" + Onended.get() + "\"");
            },
            [this](){
                Onfocus.commit();
                if (Onfocus.get() == STR_NULL) return std::string("reset Onfocus");
                else return std::string("modify Onfocus \"" + Onfocus.get() + "\"");
            },
            [this](){
                Oninput.commit();
                if (Oninput.get() == STR_NULL) return std::string("reset Oninput");
                else return std::string("modify Oninput \"" + Oninput.get() + "\"");
            },
            [this](){
                Oninvalid.commit();
                if (Oninvalid.get() == STR_NULL) return std::string("reset Oninvalid");
                else return std::string("modify Oninvalid \"" + Oninvalid.get() + "\"");
            },
            [this](){
                Onkeydown.commit();
                if (Onkeydown.get() == STR_NULL) return std::string("reset Onkeydown");
                else return std::string("modify Onkeydown \"" + Onkeydown.get() + "\"");
            },
            [this](){
                Onkeypress.commit();
                if (Onkeypress.get() == STR_NULL) return std::string("reset Onkeypress");
                else return std::string("modify Onkeypress \"" + Onkeypress.get() + "\"");
            },
            [this](){
                Onkeyup.commit();
                if (Onkeyup.get() == STR_NULL) return std::string("reset Onkeyup");
                else return std::string("modify Onkeyup \"" + Onkeyup.get() + "\"");
            },
            [this](){
                Onload.commit();
                if (Onload.get() == STR_NULL) return std::string("reset Onload");
                else return std::string("modify Onload \"" + Onload.get() + "\"");
            },
            [this](){
                Onloadeddata.commit();
                if (Onloadeddata.get() == STR_NULL) return std::string("reset Onloadeddata");
                else return std::string("modify Onloadeddata \"" + Onloadeddata.get() + "\"");
            },
            [this](){
                Onloadedmetadata.commit();
                if (Onloadedmetadata.get() == STR_NULL) return std::string("reset Onloadedmetadata");
                else return std::string("modify Onloadedmetadata \"" + Onloadedmetadata.get() + "\"");
            },
            [this](){
                Onloadstart.commit();
                if (Onloadstart.get() == STR_NULL) return std::string("reset Onloadstart");
                else return std::string("modify Onloadstart \"" + Onloadstart.get() + "\"");
            },
            [this](){
                Onmousedown.commit();
                if (Onmousedown.get() == STR_NULL) return std::string("reset Onmousedown");
                else return std::string("modify Onmousedown \"" + Onmousedown.get() + "\"");
            },
            [this](){
                Onmouseenter.commit();
                if (Onmouseenter.get() == STR_NULL) return std::string("reset Onmouseenter");
                else return std::string("modify Onmouseenter \"" + Onmouseenter.get() + "\"");
            },
            [this](){
                Onmouseleave.commit();
                if (Onmouseleave.get() == STR_NULL) return std::string("reset Onmouseleave");
                else return std::string("modify Onmouseleave \"" + Onmouseleave.get() + "\"");
            },
            [this](){
                Onmousemove.commit();
                if (Onmousemove.get() == STR_NULL) return std::string("reset Onmousemove");
                else return std::string("modify Onmousemove \"" + Onmousemove.get() + "\"");
            },
            [this](){
                Onmouseout.commit();
                if (Onmouseout.get() == STR_NULL) return std::string("reset Onmouseout");
                else return std::string("modify Onmouseout \"" + Onmouseout.get() + "\"");
            },
            [this](){
                Onmouseover.commit();
                if (Onmouseover.get() == STR_NULL) return std::string("reset Onmouseover");
                else return std::string("modify Onmouseover \"" + Onmouseover.get() + "\"");
            },
            [this](){
                Onmouseup.commit();
                if (Onmouseup.get() == STR_NULL) return std::string("reset Onmouseup");
                else return std::string("modify Onmouseup \"" + Onmouseup.get() + "\"");
            },
            [this](){
                Onmousewheel.commit();
                if (Onmousewheel.get() == STR_NULL) return std::string("reset Onmousewheel");
                else return std::string("modify Onmousewheel \"" + Onmousewheel.get() + "\"");
            },
            [this](){
                Onpause.commit();
                if (Onpause.get() == STR_NULL) return std::string("reset Onpause");
                else return std::string("modify Onpause \"" + Onpause.get() + "\"");
            },
            [this](){
                Onplay.commit();
                if (Onplay.get() == STR_NULL) return std::string("reset Onplay");
                else return std::string("modify Onplay \"" + Onplay.get() + "\"");
            },
            [this](){
                Onplaying.commit();
                if (Onplaying.get() == STR_NULL) return std::string("reset Onplaying");
                else return std::string("modify Onplaying \"" + Onplaying.get() + "\"");
            },
            [this](){
                Onprogress.commit();
                if (Onprogress.get() == STR_NULL) return std::string("reset Onprogress");
                else return std::string("modify Onprogress \"" + Onprogress.get() + "\"");
            },
            [this](){
                Onratechange.commit();
                if (Onratechange.get() == STR_NULL) return std::string("reset Onratechange");
                else return std::string("modify Onratechange \"" + Onratechange.get() + "\"");
            },
            [this](){
                Onreset.commit();
                if (Onreset.get() == STR_NULL) return std::string("reset Onreset");
                else return std::string("modify Onreset \"" + Onreset.get() + "\"");
            },
            [this](){
                Onseeked.commit();
                if (Onseeked.get() == STR_NULL) return std::string("reset Onseeked");
                else return std::string("modify Onseeked \"" + Onseeked.get() + "\"");
            },
            [this](){
                Onseeking.commit();
                if (Onseeking.get() == STR_NULL) return std::string("reset Onseeking");
                else return std::string("modify Onseeking \"" + Onseeking.get() + "\"");
            },
            [this](){
                Onselect.commit();
                if (Onselect.get() == STR_NULL) return std::string("reset Onselect");
                else return std::string("modify Onselect \"" + Onselect.get() + "\"");
            },
            [this](){
                Onshow.commit();
                if (Onshow.get() == STR_NULL) return std::string("reset Onshow");
                else return std::string("modify Onshow \"" + Onshow.get() + "\"");
            },
            [this](){
                Onstalled.commit();
                if (Onstalled.get() == STR_NULL) return std::string("reset Onstalled");
                else return std::string("modify Onstalled \"" + Onstalled.get() + "\"");
            },
            [this](){
                Onsubmit.commit();
                if (Onsubmit.get() == STR_NULL) return std::string("reset Onsubmit");
                else return std::string("modify Onsubmit \"" + Onsubmit.get() + "\"");
            },
            [this](){
                Onsuspend.commit();
                if (Onsuspend.get() == STR_NULL) return std::string("reset Onsuspend");
                else return std::string("modify Onsuspend \"" + Onsuspend.get() + "\"");
            },
            [this](){
                Ontimeupdate.commit();
                if (Ontimeupdate.get() == STR_NULL) return std::string("reset Ontimeupdate");
                else return std::string("modify Ontimeupdate \"" + Ontimeupdate.get() + "\"");
            },
            [this](){
                Ontoggle.commit();
                if (Ontoggle.get() == STR_NULL) return std::string("reset Ontoggle");
                else return std::string("modify Ontoggle \"" + Ontoggle.get() + "\"");
            },
            [this](){
                Onvolumechange.commit();
                if (Onvolumechange.get() == STR_NULL) return std::string("reset Onvolumechange");
                else return std::string("modify Onvolumechange \"" + Onvolumechange.get() + "\"");
            },
            [this](){
                Onwaiting.commit();
                if (Onwaiting.get() == STR_NULL) return std::string("reset Onwaiting");
                else return std::string("modify Onwaiting \"" + Onwaiting.get() + "\"");
            },
            [this](){
                Onactivate.commit();
                if (Onactivate.get() == STR_NULL) return std::string("reset Onactivate");
                else return std::string("modify Onactivate \"" + Onactivate.get() + "\"");
            },
            [this](){
                Onfocusin.commit();
                if (Onfocusin.get() == STR_NULL) return std::string("reset Onfocusin");
                else return std::string("modify Onfocusin \"" + Onfocusin.get() + "\"");
            },
            [this](){
                Onfocusout.commit();
                if (Onfocusout.get() == STR_NULL) return std::string("reset Onfocusout");
                else return std::string("modify Onfocusout \"" + Onfocusout.get() + "\"");
            },
            [this](){
                AlignmentBaseline.commit();
                if (AlignmentBaseline.get() == STR_NULL) return std::string("reset AlignmentBaseline");
                else return std::string("modify AlignmentBaseline \"" + AlignmentBaseline.get() + "\"");
            },
            [this](){
                BaselineShift.commit();
                if (BaselineShift.get() == STR_NULL) return std::string("reset BaselineShift");
                else return std::string("modify BaselineShift \"" + BaselineShift.get() + "\"");
            },
            [this](){
                ClipPath.commit();
                if (ClipPath.get() == STR_NULL) return std::string("reset ClipPath");
                else return std::string("modify ClipPath \"" + ClipPath.get() + "\"");
            },
            [this](){
                ClipRule.commit();
                if (ClipRule.get() == STR_NULL) return std::string("reset ClipRule");
                else return std::string("modify ClipRule \"" + ClipRule.get() + "\"");
            },
            [this](){
                Color.commit();
                if (Color.get() == STR_NULL) return std::string("reset Color");
                else return std::string("modify Color \"" + Color.get() + "\"");
            },
            [this](){
                ColorInterpolation.commit();
                if (ColorInterpolation.get() == STR_NULL) return std::string("reset ColorInterpolation");
                else return std::string("modify ColorInterpolation \"" + ColorInterpolation.get() + "\"");
            },
            [this](){
                ColorInterpolationFilters.commit();
                if (ColorInterpolationFilters.get() == STR_NULL) return std::string("reset ColorInterpolationFilters");
                else return std::string("modify ColorInterpolationFilters \"" + ColorInterpolationFilters.get() + "\"");
            },
            [this](){
                ColorProfile.commit();
                if (ColorProfile.get() == STR_NULL) return std::string("reset ColorProfile");
                else return std::string("modify ColorProfile \"" + ColorProfile.get() + "\"");
            },
            [this](){
                ColorRendering.commit();
                if (ColorRendering.get() == STR_NULL) return std::string("reset ColorRendering");
                else return std::string("modify ColorRendering \"" + ColorRendering.get() + "\"");
            },
            [this](){
                Cursor.commit();
                if (Cursor.get() == STR_NULL) return std::string("reset Cursor");
                else return std::string("modify Cursor \"" + Cursor.get() + "\"");
            },
            [this](){
                D.commit();
                if (D.get() == STR_NULL) return std::string("reset D");
                else return std::string("modify D \"" + D.get() + "\"");
            },
            [this](){
                Direction.commit();
                if (Direction.get() == STR_NULL) return std::string("reset Direction");
                else return std::string("modify Direction \"" + Direction.get() + "\"");
            },
            [this](){
                Display.commit();
                if (Display.get() == STR_NULL) return std::string("reset Display");
                else return std::string("modify Display \"" + Display.get() + "\"");
            },
            [this](){
                DominantBaseline.commit();
                if (DominantBaseline.get() == STR_NULL) return std::string("reset DominantBaseline");
                else return std::string("modify DominantBaseline \"" + DominantBaseline.get() + "\"");
            },
            [this](){
                EnableBackground.commit();
                if (EnableBackground.get() == STR_NULL) return std::string("reset EnableBackground");
                else return std::string("modify EnableBackground \"" + EnableBackground.get() + "\"");
            },
            [this](){
                Fill.commit();
                if (Fill.get() == STR_NULL) return std::string("reset Fill");
                else return std::string("modify Fill \"" + Fill.get() + "\"");
            },
            [this](){
                FillOpacity.commit();
                if (FillOpacity.get() == STR_NULL) return std::string("reset FillOpacity");
                else return std::string("modify FillOpacity \"" + FillOpacity.get() + "\"");
            },
            [this](){
                FillRule.commit();
                if (FillRule.get() == STR_NULL) return std::string("reset FillRule");
                else return std::string("modify FillRule \"" + FillRule.get() + "\"");
            },
            [this](){
                Filter.commit();
                if (Filter.get() == STR_NULL) return std::string("reset Filter");
                else return std::string("modify Filter \"" + Filter.get() + "\"");
            },
            [this](){
                FloodColor.commit();
                if (FloodColor.get() == STR_NULL) return std::string("reset FloodColor");
                else return std::string("modify FloodColor \"" + FloodColor.get() + "\"");
            },
            [this](){
                FloodOpacity.commit();
                if (FloodOpacity.get() == STR_NULL) return std::string("reset FloodOpacity");
                else return std::string("modify FloodOpacity \"" + FloodOpacity.get() + "\"");
            },
            [this](){
                FontFamily.commit();
                if (FontFamily.get() == STR_NULL) return std::string("reset FontFamily");
                else return std::string("modify FontFamily \"" + FontFamily.get() + "\"");
            },
            [this](){
                FontSize.commit();
                if (FontSize.get() == STR_NULL) return std::string("reset FontSize");
                else return std::string("modify FontSize \"" + FontSize.get() + "\"");
            },
            [this](){
                FontSizeAdjust.commit();
                if (FontSizeAdjust.get() == STR_NULL) return std::string("reset FontSizeAdjust");
                else return std::string("modify FontSizeAdjust \"" + FontSizeAdjust.get() + "\"");
            },
            [this](){
                FontStretch.commit();
                if (FontStretch.get() == STR_NULL) return std::string("reset FontStretch");
                else return std::string("modify FontStretch \"" + FontStretch.get() + "\"");
            },
            [this](){
                FontStyle.commit();
                if (FontStyle.get() == STR_NULL) return std::string("reset FontStyle");
                else return std::string("modify FontStyle \"" + FontStyle.get() + "\"");
            },
            [this](){
                FontVariant.commit();
                if (FontVariant.get() == STR_NULL) return std::string("reset FontVariant");
                else return std::string("modify FontVariant \"" + FontVariant.get() + "\"");
            },
            [this](){
                FontWeight.commit();
                if (FontWeight.get() == STR_NULL) return std::string("reset FontWeight");
                else return std::string("modify FontWeight \"" + FontWeight.get() + "\"");
            },
            [this](){
                GlyphOrientationHorizontal.commit();
                if (GlyphOrientationHorizontal.get() == STR_NULL) return std::string("reset GlyphOrientationHorizontal");
                else return std::string("modify GlyphOrientationHorizontal \"" + GlyphOrientationHorizontal.get() + "\"");
            },
            [this](){
                GlyphOrientationVertical.commit();
                if (GlyphOrientationVertical.get() == STR_NULL) return std::string("reset GlyphOrientationVertical");
                else return std::string("modify GlyphOrientationVertical \"" + GlyphOrientationVertical.get() + "\"");
            },
            [this](){
                ImageRendering.commit();
                if (ImageRendering.get() == STR_NULL) return std::string("reset ImageRendering");
                else return std::string("modify ImageRendering \"" + ImageRendering.get() + "\"");
            },
            [this](){
                Kerning.commit();
                if (Kerning.get() == STR_NULL) return std::string("reset Kerning");
                else return std::string("modify Kerning \"" + Kerning.get() + "\"");
            },
            [this](){
                LetterSpacing.commit();
                if (LetterSpacing.get() == STR_NULL) return std::string("reset LetterSpacing");
                else return std::string("modify LetterSpacing \"" + LetterSpacing.get() + "\"");
            },
            [this](){
                LightingColor.commit();
                if (LightingColor.get() == STR_NULL) return std::string("reset LightingColor");
                else return std::string("modify LightingColor \"" + LightingColor.get() + "\"");
            },
            [this](){
                MarkerEnd.commit();
                if (MarkerEnd.get() == STR_NULL) return std::string("reset MarkerEnd");
                else return std::string("modify MarkerEnd \"" + MarkerEnd.get() + "\"");
            },
            [this](){
                MarkerMid.commit();
                if (MarkerMid.get() == STR_NULL) return std::string("reset MarkerMid");
                else return std::string("modify MarkerMid \"" + MarkerMid.get() + "\"");
            },
            [this](){
                MarkerStart.commit();
                if (MarkerStart.get() == STR_NULL) return std::string("reset MarkerStart");
                else return std::string("modify MarkerStart \"" + MarkerStart.get() + "\"");
            },
            [this](){
                Mask.commit();
                if (Mask.get() == STR_NULL) return std::string("reset Mask");
                else return std::string("modify Mask \"" + Mask.get() + "\"");
            },
            [this](){
                Opacity.commit();
                if (Opacity.get() == STR_NULL) return std::string("reset Opacity");
                else return std::string("modify Opacity \"" + Opacity.get() + "\"");
            },
            [this](){
                Overflow.commit();
                if (Overflow.get() == STR_NULL) return std::string("reset Overflow");
                else return std::string("modify Overflow \"" + Overflow.get() + "\"");
            },
            [this](){
                PointerEvents.commit();
                if (PointerEvents.get() == STR_NULL) return std::string("reset PointerEvents");
                else return std::string("modify PointerEvents \"" + PointerEvents.get() + "\"");
            },
            [this](){
                ShapeRendering.commit();
                if (ShapeRendering.get() == STR_NULL) return std::string("reset ShapeRendering");
                else return std::string("modify ShapeRendering \"" + ShapeRendering.get() + "\"");
            },
            [this](){
                SolidColor.commit();
                if (SolidColor.get() == STR_NULL) return std::string("reset SolidColor");
                else return std::string("modify SolidColor \"" + SolidColor.get() + "\"");
            },
            [this](){
                SolidOpacity.commit();
                if (SolidOpacity.get() == STR_NULL) return std::string("reset SolidOpacity");
                else return std::string("modify SolidOpacity \"" + SolidOpacity.get() + "\"");
            },
            [this](){
                StopColor.commit();
                if (StopColor.get() == STR_NULL) return std::string("reset StopColor");
                else return std::string("modify StopColor \"" + StopColor.get() + "\"");
            },
            [this](){
                StopOpacity.commit();
                if (StopOpacity.get() == STR_NULL) return std::string("reset StopOpacity");
                else return std::string("modify StopOpacity \"" + StopOpacity.get() + "\"");
            },
            [this](){
                Stroke.commit();
                if (Stroke.get() == STR_NULL) return std::string("reset Stroke");
                else return std::string("modify Stroke \"" + Stroke.get() + "\"");
            },
            [this](){
                StrokeDasharray.commit();
                if (StrokeDasharray.get() == STR_NULL) return std::string("reset StrokeDasharray");
                else return std::string("modify StrokeDasharray \"" + StrokeDasharray.get() + "\"");
            },
            [this](){
                StrokeDashoffset.commit();
                if (StrokeDashoffset.get() == STR_NULL) return std::string("reset StrokeDashoffset");
                else return std::string("modify StrokeDashoffset \"" + StrokeDashoffset.get() + "\"");
            },
            [this](){
                StrokeLinecap.commit();
                if (StrokeLinecap.get() == STR_NULL) return std::string("reset StrokeLinecap");
                else return std::string("modify StrokeLinecap \"" + StrokeLinecap.get() + "\"");
            },
            [this](){
                StrokeLinejoin.commit();
                if (StrokeLinejoin.get() == STR_NULL) return std::string("reset StrokeLinejoin");
                else return std::string("modify StrokeLinejoin \"" + StrokeLinejoin.get() + "\"");
            },
            [this](){
                StrokeMiterlimit.commit();
                if (StrokeMiterlimit.get() == STR_NULL) return std::string("reset StrokeMiterlimit");
                else return std::string("modify StrokeMiterlimit \"" + StrokeMiterlimit.get() + "\"");
            },
            [this](){
                StrokeOpacity.commit();
                if (StrokeOpacity.get() == STR_NULL) return std::string("reset StrokeOpacity");
                else return std::string("modify StrokeOpacity \"" + StrokeOpacity.get() + "\"");
            },
            [this](){
                StrokeWidth.commit();
                if (StrokeWidth.get() == STR_NULL) return std::string("reset StrokeWidth");
                else return std::string("modify StrokeWidth \"" + StrokeWidth.get() + "\"");
            },
            [this](){
                TextAnchor.commit();
                if (TextAnchor.get() == STR_NULL) return std::string("reset TextAnchor");
                else return std::string("modify TextAnchor \"" + TextAnchor.get() + "\"");
            },
            [this](){
                TextDecoration.commit();
                if (TextDecoration.get() == STR_NULL) return std::string("reset TextDecoration");
                else return std::string("modify TextDecoration \"" + TextDecoration.get() + "\"");
            },
            [this](){
                TextRendering.commit();
                if (TextRendering.get() == STR_NULL) return std::string("reset TextRendering");
                else return std::string("modify TextRendering \"" + TextRendering.get() + "\"");
            },
            [this](){
                Transform.commit();
                if (Transform.get() == STR_NULL) return std::string("reset Transform");
                else return std::string("modify Transform \"" + Transform.get() + "\"");
            },
            [this](){
                UnicodeBidi.commit();
                if (UnicodeBidi.get() == STR_NULL) return std::string("reset UnicodeBidi");
                else return std::string("modify UnicodeBidi \"" + UnicodeBidi.get() + "\"");
            },
            [this](){
                VectorEffect.commit();
                if (VectorEffect.get() == STR_NULL) return std::string("reset VectorEffect");
                else return std::string("modify VectorEffect \"" + VectorEffect.get() + "\"");
            },
            [this](){
                Visibility.commit();
                if (Visibility.get() == STR_NULL) return std::string("reset Visibility");
                else return std::string("modify Visibility \"" + Visibility.get() + "\"");
            },
            [this](){
                WordSpacing.commit();
                if (WordSpacing.get() == STR_NULL) return std::string("reset WordSpacing");
                else return std::string("modify WordSpacing \"" + WordSpacing.get() + "\"");
            },
            [this](){
                WritingMode.commit();
                if (WritingMode.get() == STR_NULL) return std::string("reset WritingMode");
                else return std::string("modify WritingMode \"" + WritingMode.get() + "\"");
            },
        };
    
        /// Inner SVG
    protected:
        std::string _inner_text_commit;
        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_commit;
        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_last;
        std::weak_ptr<SVGIElement> _parent_element_commit;
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
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        void set_inner_text(const std::string &text);
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        const std::string get_inner_text() const;
        /**
        * Add a sub element to this SVG element.
        *
        * @param element an inner element.
        */
        void add_inner_element(const std::shared_ptr<SVGIElement> &element);
        /**
        * Remove a child element or child elements from this SVG element, based on content.
        *
        * @param element an inner element.
        * @param remove_all if to remove all occurances.
        */
        void remove_inner_element(const std::shared_ptr<SVGIElement> &element, bool remove_all = false);
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner elements, readonly.
        */
        const std::vector<std::shared_ptr<SVGIElement>> get_inner_elements() const;
        /**
        * Set inner SVG elements list in this SVG element.
        *
        * @param inner_elements inner elements list.
        */
        void set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements);
    
        /// Outer SVG
    public:
        /**
        * Get SVG of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string outer_SVG() const;

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
#include "svgi_el/svgi_stop.h"
#include "svgi_el/svgi_use.h"
#endif
