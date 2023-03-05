//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTSVG_H)
#define LTSVG_H

#include "lttyp.h"
#define L_LTSVG_API LT_EXPORTED

#include "ltkrn.h"
#include "ltprimitives.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

#define SVG_BOOL_TRUE             L_TRUE
#define SVG_BOOL_FALSE            L_FALSE
#define SVG_BOOL_UNSPECIFIED     -1

#define SVG_DOUBLE_UNSPECIFIED   LT_NaN

typedef L_HANDLE L_SvgNodeHandle;

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]                            Enumerations                               []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/

enum L_SvgAspectRatioAlign
{
   L_SvgAspectRatioAlign_Unspecified,
   L_SvgAspectRatioAlign_None,
   L_SvgAspectRatioAlign_XMIN_YMIN,
   L_SvgAspectRatioAlign_XMID_YMIN,
   L_SvgAspectRatioAlign_XMAX_YMIN,
   L_SvgAspectRatioAlign_XMIN_YMID,
   L_SvgAspectRatioAlign_XMID_YMID,
   L_SvgAspectRatioAlign_XMAX_YMID,
   L_SvgAspectRatioAlign_XMIN_YMAX,
   L_SvgAspectRatioAlign_XMID_YMAX,
   L_SvgAspectRatioAlign_XMAX_YMAX,
};
typedef enum L_SvgAspectRatioAlign L_SvgAspectRatioAlign;

enum L_SvgAspectRatioMeetOrSlice
{
   L_SvgAspectRatioMeetOrSlice_Unspecified,
   L_SvgAspectRatioMeetOrSlice_Meet,
   L_SvgAspectRatioMeetOrSlice_Slice,
};
typedef enum L_SvgAspectRatioMeetOrSlice L_SvgAspectRatioMeetOrSlice;

enum L_SvgLangID
{
   L_SvgLangID_Unspecified,
   L_SvgLangID_EN,
   L_SvgLangID_EN_GB,
   L_SvgLangID_EN_US,
};
typedef enum L_SvgLangID L_SvgLangID;

enum L_SvgSpace
{
   L_SvgSpace_Unspecified,
   L_SvgSpace_Default,
   L_SvgSpace_Preserve,
};
typedef enum L_SvgSpace L_SvgSpace;

enum L_SvgZoomAndPan
{
   L_SvgZoomAndPan_Unspecified,
   L_SvgZoomAndPan_Disable,
   L_SvgZoomAndPan_Magnify,
   L_SvgZoomAndPan_Zoom,
};
typedef enum L_SvgZoomAndPan L_SvgZoomAndPan;

enum L_SvgStyleType
{
   L_SvgStyleType_Unspecified,
   L_SvgStyleType_TEXT_CSS,
};
typedef enum L_SvgStyleType L_SvgStyleType;

enum L_SvgScriptType
{
   L_SvgScriptType_Unspecified,
   L_SvgScriptType_Text_ECMAScript,
};
typedef enum L_SvgScriptType L_SvgScriptType;

enum L_SvgElementType
{
   L_SvgElementType_Unknown,
   L_SvgElementType_Doc,
   L_SvgElementType_Svg,
   L_SvgElementType_G,
   L_SvgElementType_Defs,
   L_SvgElementType_Desc,
   L_SvgElementType_Title,
   L_SvgElementType_Symbol,
   L_SvgElementType_Use,
   L_SvgElementType_Image,
   L_SvgElementType_Switch,
   L_SvgElementType_Style,
   L_SvgElementType_Path,
   L_SvgElementType_Rect,
   L_SvgElementType_Circle,
   L_SvgElementType_Ellipse,
   L_SvgElementType_Line,
   L_SvgElementType_Polyline,
   L_SvgElementType_Polygon,
   L_SvgElementType_Text,
   L_SvgElementType_TSpan,
   L_SvgElementType_TRef,
   L_SvgElementType_TextPath,
   L_SvgElementType_AltGlyph,
   L_SvgElementType_AltGlyphDef,
   L_SvgElementType_AltGlyphItem,
   L_SvgElementType_GlyphRef,
   L_SvgElementType_Marker,
   L_SvgElementType_ColorProfile,
   L_SvgElementType_LinearGradient,
   L_SvgElementType_RadialGradient,
   L_SvgElementType_Stop,
   L_SvgElementType_Pattern,
   L_SvgElementType_ClipPath,
   L_SvgElementType_Font,
   L_SvgElementType_Glyph,
   L_SvgElementType_MissingGlyph,
   L_SvgElementType_HKern,
   L_SvgElementType_VKern,
   L_SvgElementType_FontFace,
   L_SvgElementType_FontFaceSrc,
   L_SvgElementType_FontFaceUri,
   L_SvgElementType_FontFaceFormat,
   L_SvgElementType_FontFaceName,
   L_SvgElementType_DefinitionSrc,
   L_SvgElementType_Anchor, 
   L_SvgElementType_Mask
};
typedef enum L_SvgElementType L_SvgElementType;

enum L_SvgCommandObjectType
{
   L_SvgCommandObjectType_Move,
   L_SvgCommandObjectType_Close,
   L_SvgCommandObjectType_Line,
   // All of the following are curve commands
   L_SvgCommandObjectType_CubicBezier,
   L_SvgCommandObjectType_QuadraticBezier,
   L_SvgCommandObjectType_EllipticalArc,
};
typedef enum L_SvgCommandObjectType L_SvgCommandObjectType;

enum L_SvgUnit
{
   L_SvgUnit_None, //Number
   L_SvgUnit_IN,
   L_SvgUnit_EM,
   L_SvgUnit_EX,
   L_SvgUnit_PX,
   L_SvgUnit_PC,
   L_SvgUnit_PT,
   L_SvgUnit_CM,
   L_SvgUnit_MM
};
typedef enum L_SvgUnit L_SvgUnit;

enum L_SvgValueType
{
   L_SvgValueType_Number,
   L_SvgValueType_Percentage,
};
typedef enum L_SvgValueType L_SvgValueType;

enum L_SvgPaintType
{
   L_SvgPaintType_Unspecified,
   L_SvgPaintType_None,
   L_SvgPaintType_CurrentColor,
   L_SvgPaintType_Color,
   L_SvgPaintType_Uri,
};
typedef enum L_SvgPaintType L_SvgPaintType;

enum L_SvgStopColorType
{
   L_SvgStopColorType_Unspecified,
   L_SvgStopColorType_CurrentColor,
   L_SvgStopColorType_Color,
};
typedef enum L_SvgStopColorType L_SvgStopColorType;

enum L_SvgStrokeDashArrayType
{
   L_SvgStrokeDashArrayType_Unspecified,
   L_SvgStrokeDashArrayType_None,
   L_SvgStrokeDashArrayType_Array,
};
typedef enum L_SvgStrokeDashArrayType L_SvgStrokeDashArrayType;

enum L_SvgMarkerType
{
   L_SvgMarkerType_Unspecified,
   L_SvgMarkerType_None,
   L_SvgMarkerType_Uri,
};
typedef enum L_SvgMarkerType L_SvgMarkerType;

enum L_SvgFillRule
{
   L_SvgFillRule_Unspecified,
   L_SvgFillRule_NonZero,
   L_SvgFillRule_EvenOdd,
};
typedef enum L_SvgFillRule L_SvgFillRule;

enum L_SvgStrokeLineCap
{
   L_SvgStrokeLineCap_Unspecified,
   L_SvgStrokeLineCap_Butt,
   L_SvgStrokeLineCap_Round,
   L_SvgStrokeLineCap_Square,
};
typedef enum L_SvgStrokeLineCap L_SvgStrokeLineCap;

enum L_SvgStrokeLineJoin
{
   L_SvgStrokeLineJoin_Unspecified,
   L_SvgStrokeLineJoin_Miter,
   L_SvgStrokeLineJoin_Round,
   L_SvgStrokeLineJoin_Bevel,
};
typedef enum L_SvgStrokeLineJoin L_SvgStrokeLineJoin;

enum L_SvgDisplay
{
   L_SvgDisplay_Unspecified,
   L_SvgDisplay_None,
   L_SvgDisplay_Inline,
   L_SvgDisplay_Block,
   L_SvgDisplay_ListItem,
   L_SvgDisplay_RunIn,
   L_SvgDisplay_Compact,
   L_SvgDisplay_Marker,
   L_SvgDisplay_Table,
   L_SvgDisplay_InlineTable,
   L_SvgDisplay_TableRowGroup,
   L_SvgDisplay_TableHeaderGroup,
   L_SvgDisplay_TableFooterGroup,
   L_SvgDisplay_TableRow,
   L_SvgDisplay_TableColumnGroup,
   L_SvgDisplay_TableColumn,
   L_SvgDisplay_TableCell,
   L_SvgDisplay_TableCaption,
};
typedef enum L_SvgDisplay L_SvgDisplay;

enum L_SvgVisibility
{
   L_SvgVisibility_Unspecified,
   L_SvgVisibility_Visible,
   L_SvgVisibility_Hidden,
   L_SvgVisibility_Collapse,
};
typedef enum L_SvgVisibility L_SvgVisibility;

enum L_SvgColorInterpolation
{
   L_SvgColorInterpolation_Unspecified,
   L_SvgColorInterpolation_Auto,
   L_SvgColorInterpolation_SRGB,
   L_SvgColorInterpolation_LinearRGB,
};
typedef enum L_SvgColorInterpolation L_SvgColorInterpolation;

enum L_SvgColorInterpolationFilters
{
   L_SvgColorInterpolationFilters_Unspecified,
   L_SvgColorInterpolationFilters_Auto,
   L_SvgColorInterpolationFilters_SRGB,
   L_SvgColorInterpolationFilters_LinearRGB,
};
typedef enum L_SvgColorInterpolationFilters L_SvgColorInterpolationFilters;

enum L_SvgColorRendering
{
   L_SvgColorRendering_Unspecified,
   L_SvgColorRendering_Auto,
   L_SvgColorRendering_OptimizeSpeed,
   L_SvgColorRendering_OptimizeQuality,
};
typedef enum L_SvgColorRendering L_SvgColorRendering;

enum L_SvgShapeRendering
{
   L_SvgShapeRendering_Unspecified,
   L_SvgShapeRendering_Auto,
   L_SvgShapeRendering_OptimizeSpeed,
   L_SvgShapeRendering_CrispEdges,
   L_SvgShapeRendering_GeometricPrecision,
};
typedef enum L_SvgShapeRendering L_SvgShapeRendering;

enum L_SvgTextRendering
{
   L_SvgTextRendering_Unspecified,
   L_SvgTextRendering_Auto,
   L_SvgTextRendering_OptimizeSpeed,
   L_SvgTextRendering_OptimizeLegibility,
   L_SvgTextRendering_GeometricPrecision,
};
typedef enum L_SvgTextRendering L_SvgTextRendering;

enum L_SvgImageRendering
{
   L_SvgImageRendering_Unspecified,
   L_SvgImageRendering_Auto,
   L_SvgImageRendering_OptimizeSpeed,
   L_SvgImageRendering_OptimizeQuality,
};
typedef enum L_SvgImageRendering L_SvgImageRendering;

enum L_SvgRenderingIntent
{
   L_SvgRenderingIntent_Unspecified,
   L_SvgRenderingIntent_Auto,
   L_SvgRenderingIntent_Perceptual,
   L_SvgRenderingIntent_Saturation,
   L_SvgRenderingIntent_RelativeColorimetric,
   L_SvgRenderingIntent_AbsoluteColorimetric,
};
typedef enum L_SvgRenderingIntent L_SvgRenderingIntent;

enum L_SvgOrientation
{
   L_SvgOrientation_Unspecified,
   L_SvgOrientation_Horizontal,
   L_SvgOrientation_Vertical,
};
typedef enum L_SvgOrientation L_SvgOrientation;

enum L_SvgArabicForm
{
   L_SvgArabicForm_Unspecified,
   L_SvgArabicForm_Initial,
   L_SvgArabicForm_Medial,
   L_SvgArabicForm_Terminal,
   L_SvgArabicForm_Isolated,
};
typedef enum L_SvgArabicForm L_SvgArabicForm;

enum L_SvgFontStyle
{
   L_SvgFontStyle_Unspecified,
   L_SvgFontStyle_Normal,
   L_SvgFontStyle_Italic,
   L_SvgFontStyle_Oblique,
};
typedef enum L_SvgFontStyle L_SvgFontStyle;

enum L_SvgFontVariant
{
   L_SvgFontVariant_Unspecified,
   L_SvgFontVariant_Normal,
   L_SvgFontVariant_SmallCaps,
};
typedef enum L_SvgFontVariant L_SvgFontVariant;

enum L_SvgFontWeight
{
   L_SvgFontWeight_Unspecified,
   L_SvgFontWeight_Normal,
   L_SvgFontWeight_Bold,
   L_SvgFontWeight_Bolder,
   L_SvgFontWeight_Lighter,
   L_SvgFontWeight_100,
   L_SvgFontWeight_200,
   L_SvgFontWeight_300,
   L_SvgFontWeight_400,
   L_SvgFontWeight_500,
   L_SvgFontWeight_600,
   L_SvgFontWeight_700,
   L_SvgFontWeight_800,
   L_SvgFontWeight_900,
};
typedef enum L_SvgFontWeight L_SvgFontWeight;

enum L_SvgKerningType
{
   L_SvgKerningType_Unspecified,
   L_SvgKerningType_Auto,
   L_SvgKerningType_Length,
};
typedef enum L_SvgKerningType L_SvgKerningType;

enum L_SvgLetterSpacingType
{
   L_SvgLetterSpacingType_Unspecified,
   L_SvgLetterSpacingType_Normal,
   L_SvgLetterSpacingType_Length,
};
typedef enum L_SvgLetterSpacingType L_SvgLetterSpacingType;

enum L_SvgWordSpacingType
{
   L_SvgWordSpacingType_Unspecified,
   L_SvgWordSpacingType_Normal,
   L_SvgWordSpacingType_Length,
};
typedef enum L_SvgWordSpacingType L_SvgWordSpacingType;

enum
{
   L_SvgTextDecoration_Unspecified = 0,
   L_SvgTextDecoration_None = 1 << 0,
   L_SvgTextDecoration_Underline = 1 << 1,
   L_SvgTextDecoration_Overline = 1 << 2,
   L_SvgTextDecoration_LineThrough = 1 << 3,
   L_SvgTextDecoration_Blink = 1 << 4,
};
typedef L_UINT L_SvgTextDecoration;

enum L_SvgWritingMode
{
   L_SvgWritingMode_Unspecified,
   L_SvgWritingMode_LR_TB,
   L_SvgWritingMode_RL_TB,
   L_SvgWritingMode_TB_RL,
   L_SvgWritingMode_LR,
   L_SvgWritingMode_RL,
   L_SvgWritingMode_TB,
};
typedef enum L_SvgWritingMode L_SvgWritingMode;

enum L_SvgGlyphOrientationVerticalType
{
   L_SvgGlyphOrientationVerticalType_Unspecified,
   L_SvgGlyphOrientationVerticalType_Auto,
   L_SvgGlyphOrientationVerticalType_Angle,
};
typedef enum L_SvgGlyphOrientationVerticalType L_SvgGlyphOrientationVerticalType;

enum L_SvgDirection
{
   L_SvgDirection_Unspecified,
   L_SvgDirection_LTR,
   L_SvgDirection_RTL,
};
typedef enum L_SvgDirection L_SvgDirection;

enum L_SvgUnicodeBidi
{
   L_SvgUnicodeBidi_Unspecified,
   L_SvgUnicodeBidi_Normal,
   L_SvgUnicodeBidi_Embed,
   L_SvgUnicodeBidi_BidiOverride,
};
typedef enum L_SvgUnicodeBidi L_SvgUnicodeBidi;

enum L_SvgTextAnchor
{
   L_SvgTextAnchor_Unspecified,
   L_SvgTextAnchor_Start,
   L_SvgTextAnchor_Middle,
   L_SvgTextAnchor_End,
};
typedef enum L_SvgTextAnchor L_SvgTextAnchor;

enum L_SvgDominantBaseline
{
   L_SvgDominantBaseline_Unspecified,
   L_SvgDominantBaseline_Auto,
   L_SvgDominantBaseline_AutosenseScript,
   L_SvgDominantBaseline_TextTop,
   L_SvgDominantBaseline_TextBottom,
   L_SvgDominantBaseline_NoChange,
   L_SvgDominantBaseline_ResetSize,
   L_SvgDominantBaseline_Ideographic,
   L_SvgDominantBaseline_Alphabetic,
   L_SvgDominantBaseline_Hanging,
   L_SvgDominantBaseline_Mathematical,
   L_SvgDominantBaseline_UseScript,
   L_SvgDominantBaseline_Central,
   L_SvgDominantBaseline_Middle,
   L_SvgDominantBaseline_TextAfterEdge,
   L_SvgDominantBaseline_TextBeforeEdge,
};
typedef enum L_SvgDominantBaseline L_SvgDominantBaseline;

enum L_SvgAlignmentBaseline
{
   L_SvgAlignmentBaseline_Unspecified,
   L_SvgAlignmentBaseline_Auto,
   L_SvgAlignmentBaseline_Baseline,
   L_SvgAlignmentBaseline_BeforeEdge,
   L_SvgAlignmentBaseline_TextBeforeEdge,
   L_SvgAlignmentBaseline_Middle,
   L_SvgAlignmentBaseline_AfterEdge,
   L_SvgAlignmentBaseline_TextAfterEdge,
   L_SvgAlignmentBaseline_Ideographic,
   L_SvgAlignmentBaseline_Alphabetic,
   L_SvgAlignmentBaseline_Hanging,
   L_SvgAlignmentBaseline_Mathematical,
   L_SvgAlignmentBaseline_Central,
};
typedef enum L_SvgAlignmentBaseline L_SvgAlignmentBaseline;

enum L_SvgBaselineShiftType
{
   L_SvgBaselineShiftType_Unspecified,
   L_SvgBaselineShiftType_Baseline,
   L_SvgBaselineShiftType_Sub,
   L_SvgBaselineShiftType_Super,
   L_SvgBaselineShiftType_Percentage,
   L_SvgBaselineShiftType_Length,
};
typedef enum L_SvgBaselineShiftType L_SvgBaselineShiftType;

enum L_SvgColorProfileType
{
   L_SvgColorProfileType_Unspecified,
   L_SvgColorProfileType_Auto,
   L_SvgColorProfileType_SRGB,
   L_SvgColorProfileType_Uri,
   L_SvgColorProfileType_Local,
};
typedef enum L_SvgColorProfileType L_SvgColorProfileType;

enum L_SvgLengthAdjust
{
   L_SvgLengthAdjust_Unspecified,
   L_SvgLengthAdjust_Spacing,
   L_SvgLengthAdjust_SpacingAndGlyphs,
};
typedef enum L_SvgLengthAdjust L_SvgLengthAdjust;

enum L_SvgMethod
{
   L_SvgMethod_Unspecified,
   L_SvgMethod_Align,
   L_SvgMethod_Stretch,
};
typedef enum L_SvgMethod L_SvgMethod;

enum L_SvgSpacing
{
   L_SvgSpacing_Unspecified,
   L_SvgSpacing_Auto,
   L_SvgSpacing_Exact,
};
typedef enum L_SvgSpacing L_SvgSpacing;

enum L_SvgGradientUnits
{
   L_SvgGradientUnits_Unspecified,
   L_SvgGradientUnits_UserSpaceOnUse,
   L_SvgGradientUnits_ObjectBoundingBox,
};
typedef enum L_SvgGradientUnits L_SvgGradientUnits;

enum L_SvgSpreadMethod
{
   L_SvgSpreadMethod_Unspecified,
   L_SvgSpreadMethod_Pad,
   L_SvgSpreadMethod_Reflect,
   L_SvgSpreadMethod_Repeat,
};
typedef enum L_SvgSpreadMethod L_SvgSpreadMethod;

enum L_SvgXLinkType
{
   L_SvgXLinkType_Unspecified,
   L_SvgXLinkType_Simple,
   L_SvgXLinkType_Extended,
   L_SvgXLinkType_Locator,
   L_SvgXLinkType_Arc,
};
typedef enum L_SvgXLinkType L_SvgXLinkType;

enum L_SvgXLinkShow
{
   L_SvgXLinkShow_Unspecified,
   L_SvgXLinkShow_New,
   L_SvgXLinkShow_Replace,
   L_SvgXLinkShow_Embed,
   L_SvgXLinkShow_Other,
   L_SvgXLinkShow_None,
};
typedef enum L_SvgXLinkShow L_SvgXLinkShow;

enum L_SvgXLinkActuate
{
   L_SvgXLinkActuate_Unspecified,
   L_SvgXLinkActuate_OnRequest,
   L_SvgXLinkActuate_OnLoad,
};
typedef enum L_SvgXLinkActuate L_SvgXLinkActuate;

enum
{
   L_SvgRequiredFeature_Unspecified = 0,
   L_SvgRequiredFeature_Svg = 1 << 0,                    // "org.w3c.svg"
   L_SvgRequiredFeature_SvgLang = 1 << 1,                // "org.w3c.svg.lang"
   L_SvgRequiredFeature_SvgStatic = 1 << 2,              // "org.w3c.svg.static"
   L_SvgRequiredFeature_SvgDynamic = 1 << 3,             // "org.w3c.svg.dynamic"
   L_SvgRequiredFeature_SvgAnimation = 1 << 4,           // "org.w3c.svg.animation"
   L_SvgRequiredFeature_DomSvg = 1 << 5,                 // "org.w3c.dom.svg"
   L_SvgRequiredFeature_DomSvgStatic = 1 << 6,           // "org.w3c.dom.svg.static"
   L_SvgRequiredFeature_DomSvgDynamic = 1 << 7,          // "org.w3c.dom.svg.dynamic"
   L_SvgRequiredFeature_DomSvgAnimation = 1 << 8,        // "org.w3c.dom.svg.animation"
   L_SvgRequiredFeature_SvgAll = 
      L_SvgRequiredFeature_Svg |
      L_SvgRequiredFeature_SvgLang |
      L_SvgRequiredFeature_SvgStatic |
      L_SvgRequiredFeature_SvgDynamic |
      L_SvgRequiredFeature_SvgAnimation,                 // "org.w3c.svg.all"
   L_SvgRequiredFeature_DomSvgAll = 
      L_SvgRequiredFeature_DomSvg |
      L_SvgRequiredFeature_DomSvgStatic |
      L_SvgRequiredFeature_DomSvgDynamic |
      L_SvgRequiredFeature_DomSvgAnimation, // "org.w3c.dom.svg.all"
};
typedef L_UINT L_SvgRequiredFeature;

enum L_SvgPatternUnits
{
   L_SvgPatternUnits_Unspecified,
   L_SvgPatternUnits_UserSpaceOnUse,
   L_SvgPatternUnits_ObjectBoundingBox,
};
typedef enum L_SvgPatternUnits L_SvgPatternUnits;

enum L_SvgPatternContentUnits
{
   L_SvgPatternContentUnits_Unspecified,
   L_SvgPatternContentUnits_UserSpaceOnUse,
   L_SvgPatternContentUnits_ObjectBoundingBox,
};
typedef enum L_SvgPatternContentUnits L_SvgPatternContentUnits;

enum L_SvgMarkerUnits
{
   L_SvgMarkerUnits_Unspecified,
   L_SvgMarkerUnits_StrokeWidth,
   L_SvgMarkerUnits_UserSpaceOnUse,
};
typedef enum L_SvgMarkerUnits L_SvgMarkerUnits;

enum L_SvgAngleType
{
   L_SvgAngleType_Unspecified,
   L_SvgAngleType_Deg,
   L_SvgAngleType_Grad,
   L_SvgAngleType_Rad,
};
typedef enum L_SvgAngleType L_SvgAngleType;

enum L_SvgOrientType
{
   L_SvgOrientType_Unspecified,
   L_SvgOrientType_Auto,
   L_SvgOrientType_Angle,
};
typedef enum L_SvgOrientType L_SvgOrientType;

enum L_SvgTransformType
{
   L_SvgTransformType_None,
   L_SvgTransformType_Translate,
   L_SvgTransformType_Scale,
   L_SvgTransformType_Rotate,
   L_SvgTransformType_SkewX,
   L_SvgTransformType_SkewY,
   L_SvgTransformType_Matrix,
};
typedef enum L_SvgTransformType L_SvgTransformType;

enum L_SvgCoordinateType
{
   L_SvgCoordinateType_Unspecified,
   L_SvgCoordinateType_Auto,
   L_SvgCoordinateType_Length,
};
typedef enum L_SvgCoordinateType L_SvgCoordinateType;

enum L_SvgClipPathUnits
{
   L_SvgClipPathUnits_Unspecified,
   L_SvgClipPathUnits_UserSpaceOnUse,
   L_SvgClipPathUnits_ObjectBoundingBox,
};
typedef enum L_SvgClipPathUnits L_SvgClipPathUnits;

enum L_SvgClipPathType
{
   L_SvgClipPathType_Unspecified,
   L_SvgClipPathType_None,
   L_SvgClipPathType_Uri,
};
typedef enum L_SvgClipPathType L_SvgClipPathType;

enum L_SvgFontType
{
   L_SvgFontType_FontFamily,
   L_SvgFontType_Caption,
   L_SvgFontType_Icon,
   L_SvgFontType_Menu,
   L_SvgFontType_MessageBox,
   L_SvgFontType_SmallCaption,
   L_SvgFontType_StatusBar,
};
typedef enum L_SvgFontType L_SvgFontType;

enum L_SvgFontSizeAdjustType
{
   L_SvgFontSizeAdjustType_Unspecified,
   L_SvgFontSizeAdjustType_None,
   L_SvgFontSizeAdjustType_Number,
};
typedef enum L_SvgFontSizeAdjustType L_SvgFontSizeAdjustType;

enum L_SvgFontStretch
{
   L_SvgFontStretch_Unspecified,
   L_SvgFontStretch_Normal,
   L_SvgFontStretch_Wider,
   L_SvgFontStretch_Narrower,
   L_SvgFontStretch_UltraCondensed,
   L_SvgFontStretch_ExtraCondensed,
   L_SvgFontStretch_Condensed,
   L_SvgFontStretch_SemiCondensed,
   L_SvgFontStretch_SemiExpanded,
   L_SvgFontStretch_Expanded,
   L_SvgFontStretch_ExtraExpanded,
   L_SvgFontStretch_UltraExpanded,
};
typedef enum L_SvgFontStretch L_SvgFontStretch;

enum L_SvgColorType
{
   L_SvgColorType_Name,
   L_SvgColorType_Hexadecimal,
   L_SvgColorType_RGB,
};
typedef enum L_SvgColorType L_SvgColorType;

enum L_SvgVersion
{
   L_SvgVersion_Unspecified,
   L_SvgVersion_1_0,
   L_SvgVersion_1_1,
};
typedef enum L_SvgVersion L_SvgVersion;

enum
{
   L_SvgMediaType_Unspecified = 0,
   L_SvgMediaType_Aural = 1 << 0,
   L_SvgMediaType_Braille = 1 << 1,
   L_SvgMediaType_Embossed = 1 << 2,
   L_SvgMediaType_Handheld = 1 << 3,
   L_SvgMediaType_Print = 1 << 4,
   L_SvgMediaType_Projection = 1 << 5,
   L_SvgMediaType_Screen = 1 << 6,
   L_SvgMediaType_TTY = 1 << 7,
   L_SvgMediaType_TV = 1 << 8,
   L_SvgMediaType_All =
      L_SvgMediaType_Aural |
      L_SvgMediaType_Braille |
      L_SvgMediaType_Embossed |
      L_SvgMediaType_Handheld |
      L_SvgMediaType_Print |
      L_SvgMediaType_Projection |
      L_SvgMediaType_Screen |
      L_SvgMediaType_TTY |
      L_SvgMediaType_TV,
};
typedef L_UINT L_SvgMediaType;

enum L_SvgEnumerateDirection
{
   L_SvgEnumerateDirection_Top,
   L_SvgEnumerateDirection_TopToBottom,
   L_SvgEnumerateDirection_BottomToTop,
};
typedef enum L_SvgEnumerateDirection L_SvgEnumerateDirection;

enum L_SvgInsertElementType
{
   L_SvgInsertElementType_Before,
   L_SvgInsertElementType_After,
   L_SvgInsertElementType_Child,
};
typedef enum L_SvgInsertElementType L_SvgInsertElementType;

enum L_SvgEncoding
{
   L_SvgEncoding_UTF8,
   L_SvgEncoding_UTF16
};
typedef enum L_SvgEncoding L_SvgEncoding;

enum
{
   L_SvgTextCharacterFlags_None = 0,
   L_SvgTextCharacterFlags_EndOfWord = 1 << 0,
   L_SvgTextCharacterFlags_EndOfLine = 1 << 1,
   L_SvgTextCharacterFlags_LineBreak = 1 << 2,
   L_SvgTextCharacterFlags_FromOcr = 1 << 3,
};
typedef L_UINT L_SvgTextCharacterFlags;

enum
{
   L_SvgSortFlags_Default = 0,
   L_SvgSortFlags_LeftToRight = 0,
   L_SvgSortFlags_RightToLeft = 1 << 0,
   L_SvgSortFlags_TopToBottom = 0,
   L_SvgSortFlags_BottomToTop = 1 << 1,
};
typedef L_UINT L_SvgSortFlags;

enum
{
   L_SvgExtractText_Character = 0,
   L_SvgExtractText_Word = 1 << 0,
   L_SvgExtractText_Line = 1 << 1,
   L_SvgExtractText_ExactBounds = 1 << 2,
};
typedef L_UINT L_SvgExtractText;

enum
{
   L_SvgFlatFlags_Default = 0,
   L_SvgFlatFlags_TextOnly = 1 << 0,
};
typedef L_UINT L_SvgFlatFlags;

enum L_SvgCharacterDirection
{
   L_SvgCharacterDirection_LeftToRight,
   L_SvgCharacterDirection_RightToLeft,
};
typedef enum L_SvgCharacterDirection L_SvgCharacterDirection;

enum
{
   L_SvgLoadFlags_Default = 0,
   L_SvgLoadFlags_DropShapes = 1 << 0,
   L_SvgLoadFlags_DropImages = 1 << 1,
   L_SvgLoadFlags_DropText = 1 << 2,
   L_SvgLoadFlags_IgnoreXmlParsingErrors = 1 << 3,
};
typedef L_UINT L_SvgLoadFlags;

enum L_SvgFormat
{
   L_SvgFormat_Svg,
   L_SvgFormat_Svgz
};
typedef enum L_SvgFormat L_SvgFormat;

enum
{
   L_SvgRenderFlags_Default = 0,
   L_SvgRenderFlags_EnhanceThinLines = 1 << 0,
};
typedef L_UINT L_SvgRenderFlags;

/* --------------------------------------------------------------------------*/


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]                             Structures                                []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
struct L_SvgRenderOptions
{
   L_UINT             StructSize;
   L_BOOL             UseBackgroundColor; // Use the background color. 
   L_COLORREF         BackgroundColor;  // Color to fill the background of the SVG. Only used when UseBackgroundColor is true and Bounds is not empty or has zero width or height
   L_RECTD            Bounds; // Bounds of the SVG. Only used when UseBackgroundColor is true. Use the same value from L_SvgGetBounds
   L_RECTD            ClipBounds;
   L_MATRIX           Transform;
   L_SvgRenderFlags   RenderFlags;
};
typedef struct L_SvgRenderOptions L_SvgRenderOptions;

struct L_SvgLoadOptions
{
   L_UINT          StructSize;
   L_SvgLoadFlags  LoadFlags;
   L_UINT          MaximumElements;
};
typedef struct L_SvgLoadOptions L_SvgLoadOptions;

struct L_SvgSaveOptionsA
{
   L_UINT         StructSize;
   L_BOOL         Formatted;
   L_CHAR         Indent[10];
   L_SvgEncoding  Encoding;
   L_SvgFormat    Format;
};
typedef struct L_SvgSaveOptionsA L_SvgSaveOptionsA;
#if defined(FOR_UNICODE)
struct L_SvgSaveOptions
{
   L_UINT         StructSize;
   L_BOOL         Formatted;
   L_TCHAR        Indent[10];
   L_SvgEncoding  Encoding;
   L_SvgFormat    Format;
};
typedef struct L_SvgSaveOptions L_SvgSaveOptions;
#else
typedef struct L_SvgSaveOptionsA L_SvgSaveOptions;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFlatOptions
{
   L_UINT          StructSize;
   L_SIZED         Size;
   L_SvgFlatFlags  Flags;
};
typedef struct L_SvgFlatOptions L_SvgFlatOptions;

struct L_SvgBounds
{
   L_UINT   StructSize;
   L_BOOL   IsValid;
   L_BOOL   IsTrimmed;
   L_SIZED  Resolution;
   L_RECTD  Bounds;
};
typedef struct L_SvgBounds L_SvgBounds;


struct L_SvgXLinkRefAttrsA
{
   L_UINT             StructSize;
   L_CHAR *           Role;
   L_CHAR *           Title;
   L_CHAR *           XLink;
   L_CHAR *           ArcRole;
   L_SvgXLinkType     Type;
   L_SvgXLinkShow     Show;
   L_SvgXLinkActuate  Actuate;
};
typedef struct L_SvgXLinkRefAttrsA L_SvgXLinkRefAttrsA;
#if defined(FOR_UNICODE)
struct L_SvgXLinkRefAttrs
{
   L_UINT             StructSize;
   L_TCHAR *          Role;
   L_TCHAR *          Title;
   L_TCHAR *          XLink;
   L_TCHAR *          ArcRole;
   L_SvgXLinkType     Type;
   L_SvgXLinkShow     Show;
   L_SvgXLinkActuate  Actuate;
};
typedef struct L_SvgXLinkRefAttrs L_SvgXLinkRefAttrs;
#else
typedef struct L_SvgXLinkRefAttrsA L_SvgXLinkRefAttrs;
#endif // #if defined(FOR_UNICODE)


struct L_SvgTestAttrsA
{
   L_UINT                StructSize;
   L_SvgRequiredFeature  RequiredFeatures;
   L_CHAR *              SystemLanguage;
   L_CHAR *              RequiredExtensions;
};
typedef struct L_SvgTestAttrsA L_SvgTestAttrsA;
#if defined(FOR_UNICODE)
struct L_SvgTestAttrs
{
   L_UINT                StructSize;
   L_SvgRequiredFeature  RequiredFeatures;
   L_TCHAR *             SystemLanguage;
   L_TCHAR *             RequiredExtensions;
};
typedef struct L_SvgTestAttrs L_SvgTestAttrs;
#else
typedef struct L_SvgTestAttrsA L_SvgTestAttrs;
#endif // #if defined(FOR_UNICODE)

struct L_SvgCoreAttrsA
{
   L_UINT       StructSize;
   L_CHAR *     Base;
   L_CHAR *     Id;
   L_SvgLangID  LangId;
   L_SvgSpace   Space;
};
typedef struct L_SvgCoreAttrsA L_SvgCoreAttrsA;
#if defined(FOR_UNICODE)
struct L_SvgCoreAttrs
{
   L_UINT       StructSize;
   L_TCHAR *    Base;
   L_TCHAR *    Id;
   L_SvgLangID  LangId;
   L_SvgSpace   Space;
};
typedef struct L_SvgCoreAttrs L_SvgCoreAttrs;
#else
typedef struct L_SvgCoreAttrsA L_SvgCoreAttrs;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPreserveAspectratio
{
   L_UINT                       StructSize;
   L_SvgAspectRatioAlign        Align;
   L_SvgAspectRatioMeetOrSlice  MeetOrSlice;
};
typedef struct L_SvgPreserveAspectratio L_SvgPreserveAspectratio;

struct L_SvgFontFamilyA
{
   L_UINT    StructSize;
   L_CHAR * Family;
};
typedef struct L_SvgFontFamilyA L_SvgFontFamilyA;
#if defined(FOR_UNICODE)
struct L_SvgFontFamily
{
   L_UINT    StructSize;
   L_TCHAR * Family;
};
typedef struct L_SvgFontFamily L_SvgFontFamily;
#else
typedef struct L_SvgFontFamilyA L_SvgFontFamily;
#endif // #if defined(FOR_UNICODE)

struct L_SvgValue
{
   L_UINT          StructSize;
   L_DOUBLE        Value;
   L_SvgValueType  ValueType;
};
typedef struct L_SvgValue L_SvgValue;

struct L_SvgLength
{
   L_UINT          StructSize;
   L_DOUBLE        Value;
   L_SvgUnit       Unit;
   L_SvgValueType  ValueType;
};
typedef struct L_SvgLength L_SvgLength;

struct L_SvgColorA
{
   L_UINT          StructSize;
   L_CHAR *        Color;
   L_SvgValue      R;
   L_SvgValue      G;
   L_SvgValue      B;
   L_SvgColorType  ColorType;
};
typedef struct L_SvgColorA L_SvgColorA;
#if defined(FOR_UNICODE)
struct L_SvgColor
{
   L_UINT          StructSize;
   L_TCHAR *       Color;
   L_SvgValue      R;
   L_SvgValue      G;
   L_SvgValue      B;
   L_SvgColorType  ColorType;
};
typedef struct L_SvgColor L_SvgColor;
#else
typedef struct L_SvgColorA L_SvgColor;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPaintA
{
   L_UINT          StructSize;
   L_SvgColorA     Color;
   L_SvgPaintType  PaintType;
};
typedef struct L_SvgPaintA L_SvgPaintA;
#if defined(FOR_UNICODE)
struct L_SvgPaint
{
   L_UINT          StructSize;
   L_SvgColor      Color;
   L_SvgPaintType  PaintType;
};
typedef struct L_SvgPaint L_SvgPaint;
#else
typedef struct L_SvgPaintA L_SvgPaint;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStopColorA
{
   L_UINT              StructSize;
   L_SvgColorA         Color;
   L_SvgStopColorType  StopColorType;
};
typedef struct L_SvgStopColorA L_SvgStopColorA;
#if defined(FOR_UNICODE)
struct L_SvgStopColor
{
   L_UINT              StructSize;
   L_SvgColor          Color;
   L_SvgStopColorType  StopColorType;
};
typedef struct L_SvgStopColor L_SvgStopColor;
#else
typedef struct L_SvgStopColorA L_SvgStopColor;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStrokeDashArray
{
   L_UINT                    StructSize;
   L_INT                     Count;
   L_SvgLength*              Length;
   L_SvgStrokeDashArrayType  StrokeDashArrayType;
};
typedef struct L_SvgStrokeDashArray L_SvgStrokeDashArray;

struct L_SvgMarkerA
{
   L_UINT           StructSize;
   L_CHAR *         Uri;
   L_SvgMarkerType  MarkerType;
};
typedef struct L_SvgMarkerA L_SvgMarkerA;
#if defined(FOR_UNICODE)
struct L_SvgMarker
{
   L_UINT           StructSize;
   L_TCHAR *        Uri;
   L_SvgMarkerType  MarkerType;
};
typedef struct L_SvgMarker L_SvgMarker;
#else
typedef struct L_SvgMarkerA L_SvgMarker;
#endif // #if defined(FOR_UNICODE)

struct L_SvgGradientsPropA
{
   L_UINT           StructSize;
   L_DOUBLE         StopOpacity;
   L_SvgStopColorA  StopColor;
};
typedef struct L_SvgGradientsPropA L_SvgGradientsPropA;
#if defined(FOR_UNICODE)
struct L_SvgGradientsProp
{
   L_UINT          StructSize;
   L_DOUBLE        StopOpacity;
   L_SvgStopColor  StopColor;
};
typedef struct L_SvgGradientsProp L_SvgGradientsProp;
#else
typedef struct L_SvgGradientsPropA L_SvgGradientsProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFillPropA
{
   L_UINT         StructSize;
   L_DOUBLE       FillOpacity;
   L_SvgPaintA    Fill;
   L_SvgFillRule  FillRule;
};
typedef struct L_SvgFillPropA L_SvgFillPropA;
#if defined(FOR_UNICODE)
struct L_SvgFillProp
{
   L_UINT         StructSize;
   L_DOUBLE       FillOpacity;
   L_SvgPaint     Fill;
   L_SvgFillRule  FillRule;
};
typedef struct L_SvgFillProp L_SvgFillProp;
#else
typedef struct L_SvgFillPropA L_SvgFillProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStrokePropA
{
   L_UINT                StructSize;
   L_DOUBLE              StrokeOpacity;
   L_DOUBLE              StrokeMiterLimit;
   L_SvgPaintA           Stroke;
   L_SvgLength           StrokeWidth;
   L_SvgLength           StrokeDashOffset;
   L_SvgStrokeLineCap    StrokeLineCap;
   L_SvgStrokeLineJoin   StrokeLineJoin;
   L_SvgStrokeDashArray  StrokeDashArray;
};
typedef struct L_SvgStrokePropA L_SvgStrokePropA;
#if defined(FOR_UNICODE)
struct L_SvgStrokeProp
{
   L_UINT                StructSize;
   L_DOUBLE              StrokeOpacity;
   L_DOUBLE              StrokeMiterLimit;
   L_SvgPaint            Stroke;
   L_SvgLength           StrokeWidth;
   L_SvgLength           StrokeDashOffset;
   L_SvgStrokeLineCap    StrokeLineCap;
   L_SvgStrokeLineJoin   StrokeLineJoin;
   L_SvgStrokeDashArray  StrokeDashArray;
};
typedef struct L_SvgStrokeProp L_SvgStrokeProp;
#else
typedef struct L_SvgStrokePropA L_SvgStrokeProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgVisibilityProp
{
   L_UINT           StructSize;
   L_SvgDisplay     Display;
   L_SvgVisibility  Visibility;
};
typedef struct L_SvgVisibilityProp L_SvgVisibilityProp;

struct L_SvgMarkersPropA
{
   L_UINT        StructSize;
   L_SvgMarkerA  Marker;
   L_SvgMarkerA  MarkerStart;
   L_SvgMarkerA  MarkerMid;
   L_SvgMarkerA  MarkerEnd;
};
typedef struct L_SvgMarkersPropA L_SvgMarkersPropA;
#if defined(FOR_UNICODE)
struct L_SvgMarkersProp
{
   L_UINT       StructSize;
   L_SvgMarker  Marker;
   L_SvgMarker  MarkerStart;
   L_SvgMarker  MarkerMid;
   L_SvgMarker  MarkerEnd;
};
typedef struct L_SvgMarkersProp L_SvgMarkersProp;
#else
typedef struct L_SvgMarkersPropA L_SvgMarkersProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgRenderingProp
{
   L_UINT                          StructSize;
   L_SvgTextRendering              TextRendering;
   L_SvgColorRendering             ColorRendering;
   L_SvgShapeRendering             ShapeRendering;
   L_SvgImageRendering             ImageRendering;
   L_SvgColorInterpolation         ColorInterpolation;
   L_SvgColorInterpolationFilters  ColorInterpolationFilters;
};
typedef struct L_SvgRenderingProp L_SvgRenderingProp;

struct L_SvgAngle
{
   L_UINT          StructSize;
   L_DOUBLE        Angle;
   L_SvgAngleType  AngleType;
};
typedef struct L_SvgAngle L_SvgAngle;

struct L_SvgGlyphOrientationVertical
{
   L_UINT                             StructSize;
   L_SvgAngle                         Angle;
   L_SvgGlyphOrientationVerticalType  GlyphOrientVertType;
};
typedef struct L_SvgGlyphOrientationVertical L_SvgGlyphOrientationVertical;

struct L_SvgGlyphOrientationHorizontal
{
   L_UINT      StructSize;
   L_SvgAngle  Angle;
};
typedef struct L_SvgGlyphOrientationHorizontal L_SvgGlyphOrientationHorizontal;

struct L_SvgGlyphOrientationProp
{
   L_UINT                           StructSize;
   L_SvgGlyphOrientationVertical    VertOrient;
   L_SvgGlyphOrientationHorizontal  HorizOrient;
};
typedef struct L_SvgGlyphOrientationProp L_SvgGlyphOrientationProp;

struct L_SvgKerning
{
   L_UINT            StructSize;
   L_SvgLength       Length;
   L_SvgKerningType  KerningType;
};
typedef struct L_SvgKerning L_SvgKerning;

struct L_SvgLetterSpacing
{
   L_UINT                  StructSize;
   L_SvgLength             Length;
   L_SvgLetterSpacingType  LetterSpacingType;
};
typedef struct L_SvgLetterSpacing L_SvgLetterSpacing;

struct L_SvgWordSpacing
{
   L_UINT                StructSize;
   L_SvgLength           Length;
   L_SvgWordSpacingType  WordSpacingType;
};
typedef struct L_SvgWordSpacing L_SvgWordSpacing;

struct L_SvgTextAlignmentProp
{
   L_UINT           StructSize;
   L_SvgTextAnchor  TextAnchor;
};
typedef struct L_SvgTextAlignmentProp L_SvgTextAlignmentProp;

struct L_SvgBaselineShift
{
   L_UINT                  StructSize;
   L_SvgValue              Percentage;
   L_SvgLength             Length;
   L_SvgBaselineShiftType  BaselineShift;
};
typedef struct L_SvgBaselineShift L_SvgBaselineShift;

struct L_SvgBaselineAlignmentProp
{
   L_UINT                  StructSize;
   L_SvgBaselineShift      BaselineShift;
   L_SvgDominantBaseline   DominantBaseline;
   L_SvgAlignmentBaseline  AlignmentBaseline;
};
typedef struct L_SvgBaselineAlignmentProp L_SvgBaselineAlignmentProp;

struct L_SvgAlignmentProp
{
   L_UINT                      StructSize;
   L_SvgTextAlignmentProp      TextAlignmentProp;
   L_SvgBaselineAlignmentProp  BaselineAlignmentProp;
};
typedef struct L_SvgAlignmentProp L_SvgAlignmentProp;

struct L_SvgFontSize
{
   L_UINT       StructSize;
   L_SvgLength  Length;
};
typedef struct L_SvgFontSize L_SvgFontSize;

struct L_SvgFontSizeAdjust
{
   L_UINT                   StructSize;
   L_DOUBLE                 AdjustValue;
   L_SvgFontSizeAdjustType  FontSizeAdjustType;
};
typedef struct L_SvgFontSizeAdjust L_SvgFontSizeAdjust;

struct L_SvgSpacingProp
{
   L_UINT              StructSize;
   L_SvgKerning        Kerning;
   L_SvgWordSpacing    WordSpacing;
   L_SvgLetterSpacing  LetterSpacing;
};
typedef struct L_SvgSpacingProp L_SvgSpacingProp;

struct L_SvgDirectionProp
{
   L_UINT            StructSize;
   L_SvgDirection    Direction;
   L_SvgUnicodeBidi  UniCodeBidi;
};
typedef struct L_SvgDirectionProp L_SvgDirectionProp;

struct L_SvgFontA
{
   L_UINT         StructSize;
   L_CHAR *       FontFamily;
   L_SvgFontType  FontType;
};
typedef struct L_SvgFontA L_SvgFontA;
#if defined(FOR_UNICODE)
struct L_SvgFont
{
   L_UINT         StructSize;
   L_TCHAR *      FontFamily;
   L_SvgFontType  FontType;
};
typedef struct L_SvgFont L_SvgFont;
#else
typedef struct L_SvgFontA L_SvgFont;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontSelectionPropA
{
   L_UINT               StructSize;
   L_SvgFontStyle       FontStyle;
   L_SvgFontWeight      FontWeight;
   L_SvgFontVariant     FontVariant;
   L_SvgFontStretch     FontStretch;
   L_SvgFontA           Font;
   L_SvgFontSize        FontSize;
   L_SvgFontFamilyA     FontFamily;
   L_SvgFontSizeAdjust  FontSizeAdjust;
};
typedef struct L_SvgFontSelectionPropA L_SvgFontSelectionPropA;
#if defined(FOR_UNICODE)
struct L_SvgFontSelectionProp
{
   L_UINT               StructSize;
   L_SvgFontStyle       FontStyle;
   L_SvgFontWeight      FontWeight;
   L_SvgFontVariant     FontVariant;
   L_SvgFontStretch     FontStretch;
   L_SvgFont            Font;
   L_SvgFontSize        FontSize;
   L_SvgFontFamily      FontFamily;
   L_SvgFontSizeAdjust  FontSizeAdjust;
};
typedef struct L_SvgFontSelectionProp L_SvgFontSelectionProp;
#else
typedef struct L_SvgFontSelectionPropA L_SvgFontSelectionProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgColorProfileA
{
   L_UINT                 StructSize;
   L_CHAR *               Uri;
   L_CHAR *               Local;
   L_SvgColorProfileType  ColorProfileType;
};
typedef struct L_SvgColorProfileA L_SvgColorProfileA;
#if defined(FOR_UNICODE)
struct L_SvgColorProfile
{
   L_UINT                 StructSize;
   L_TCHAR *              Uri;
   L_TCHAR *              Local;
   L_SvgColorProfileType  ColorProfileType;
};
typedef struct L_SvgColorProfile L_SvgColorProfile;
#else
typedef struct L_SvgColorProfileA L_SvgColorProfile;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTextPropA
{
   L_UINT                     StructSize;
   L_SvgTextDecoration        TextDecoration;
   L_SvgWritingMode           WritingMode;
   L_SvgSpacingProp           SpacingProp;
   L_SvgDirectionProp         DirectionProp;
   L_SvgAlignmentProp         AlignmentProp;
   L_SvgGlyphOrientationProp  GlyphOrientProp;
   L_SvgFontSelectionPropA    FontSelectionProp;
};
typedef struct L_SvgTextPropA L_SvgTextPropA;
#if defined(FOR_UNICODE)
struct L_SvgTextProp
{
   L_UINT                     StructSize;
   L_SvgTextDecoration        TextDecoration;
   L_SvgWritingMode           WritingMode;
   L_SvgSpacingProp           SpacingProp;
   L_SvgDirectionProp         DirectionProp;
   L_SvgAlignmentProp         AlignmentProp;
   L_SvgGlyphOrientationProp  GlyphOrientProp;
   L_SvgFontSelectionProp     FontSelectionProp;
};
typedef struct L_SvgTextProp L_SvgTextProp;
#else
typedef struct L_SvgTextPropA L_SvgTextProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPaintingPropA
{
   L_UINT               StructSize;
   L_SvgFillPropA       FillProp;
   L_SvgStrokePropA     StrokeProp;
   L_SvgMarkersPropA    MarkersProp;
   L_SvgRenderingProp   RenderingProp;
   L_SvgVisibilityProp  VisibilityProp;
};
typedef struct L_SvgPaintingPropA L_SvgPaintingPropA;
#if defined(FOR_UNICODE)
struct L_SvgPaintingProp
{
   L_UINT               StructSize;
   L_SvgFillProp        FillProp;
   L_SvgStrokeProp      StrokeProp;
   L_SvgMarkersProp     MarkersProp;
   L_SvgRenderingProp   RenderingProp;
   L_SvgVisibilityProp  VisibilityProp;
};
typedef struct L_SvgPaintingProp L_SvgPaintingProp;
#else
typedef struct L_SvgPaintingPropA L_SvgPaintingProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgClipPathA
{
   L_UINT             StructSize;
   L_CHAR *           Uri;
   L_SvgClipPathType  ClipPathType;
};
typedef struct L_SvgClipPathA L_SvgClipPathA;
#if defined(FOR_UNICODE)
struct L_SvgClipPath
{
   L_UINT             StructSize;
   L_TCHAR *          Uri;
   L_SvgClipPathType  ClipPathType;
};
typedef struct L_SvgClipPath L_SvgClipPath;
#else
typedef struct L_SvgClipPathA L_SvgClipPath;
#endif // #if defined(FOR_UNICODE)

struct L_SvgClippingPropA
{
   L_UINT          StructSize;
   L_SvgClipPathA  ClipPath;
};
typedef struct L_SvgClippingPropA L_SvgClippingPropA;
#if defined(FOR_UNICODE)
struct L_SvgClippingProp
{
   L_UINT         StructSize;
   L_SvgClipPath  ClipPath;
};
typedef struct L_SvgClippingProp L_SvgClippingProp;
#else
typedef struct L_SvgClippingPropA L_SvgClippingProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgCoordinate
{
   L_UINT               StructSize;
   L_SvgLength          Length;
   L_SvgCoordinateType  CoordinateType;
};
typedef struct L_SvgCoordinate L_SvgCoordinate;

struct L_SvgCoordinateProp
{
   L_UINT           StructSize;
   L_SvgCoordinate  Top;
   L_SvgCoordinate  Right;
   L_SvgCoordinate  Bottom;
   L_SvgCoordinate  Left;
};
typedef struct L_SvgCoordinateProp L_SvgCoordinateProp;

struct L_SvgColorPropA
{
   L_UINT              StructSize;
   L_SvgColorA         Color;
   L_SvgColorProfileA  ColorProfile;
};
typedef struct L_SvgColorPropA L_SvgColorPropA;
#if defined(FOR_UNICODE)
struct L_SvgColorProp
{
   L_UINT             StructSize;
   L_SvgColor         Color;
   L_SvgColorProfile  ColorProfile;
};
typedef struct L_SvgColorProp L_SvgColorProp;
#else
typedef struct L_SvgColorPropA L_SvgColorProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStylePropA
{
   L_UINT               StructSize;
   L_DOUBLE             Opacity;
   L_SvgTextPropA       TextProp;
   L_SvgColorPropA      ColorProp;
   L_SvgClippingPropA   ClippingProp;
   L_SvgPaintingPropA   PaintingProp;
   L_SvgGradientsPropA  GradientsProp;
   L_SvgCoordinateProp  CoordinateProp;
};
typedef struct L_SvgStylePropA L_SvgStylePropA;
#if defined(FOR_UNICODE)
struct L_SvgStyleProp
{
   L_UINT               StructSize;
   L_DOUBLE             Opacity;
   L_SvgTextProp        TextProp;
   L_SvgColorProp       ColorProp;
   L_SvgClippingProp    ClippingProp;
   L_SvgPaintingProp    PaintingProp;
   L_SvgGradientsProp   GradientsProp;
   L_SvgCoordinateProp  CoordinateProp;
};
typedef struct L_SvgStyleProp L_SvgStyleProp;
#else
typedef struct L_SvgStylePropA L_SvgStyleProp;
#endif // #if defined(FOR_UNICODE)

struct L_SvgViewBox
{
   L_UINT    StructSize;
   L_DOUBLE  MinX;
   L_DOUBLE  MinY;
   L_DOUBLE  Width;
   L_DOUBLE  Height;
};
typedef struct L_SvgViewBox L_SvgViewBox;

struct L_SvgTransformTranslate
{
   L_UINT    StructSize;
   L_DOUBLE  Tx;
   L_DOUBLE  Ty;
};
typedef struct L_SvgTransformTranslate L_SvgTransformTranslate;

struct L_SvgTransformScale
{
   L_UINT    StructSize;
   L_DOUBLE  Sx;
   L_DOUBLE  Sy;
};
typedef struct L_SvgTransformScale L_SvgTransformScale;

struct L_SvgTransformRotate
{
   L_UINT    StructSize;
   L_DOUBLE  Angle;
   L_DOUBLE  Cx;
   L_DOUBLE  Cy;
};
typedef struct L_SvgTransformRotate L_SvgTransformRotate;

struct L_SvgTransformSkewX
{
   L_UINT    StructSize;
   L_DOUBLE  X;
};
typedef struct L_SvgTransformSkewX L_SvgTransformSkewX;

struct L_SvgTransformSkewY
{
   L_UINT    StructSize;
   L_DOUBLE  Y;
};
typedef struct L_SvgTransformSkewY L_SvgTransformSkewY;

struct L_SvgTransformMatrix
{
   L_UINT    StructSize;
   L_DOUBLE  Matrix[6];
};
typedef struct L_SvgTransformMatrix L_SvgTransformMatrix;

struct L_SvgTransformData
{
   L_UINT              StructSize;
   L_SvgTransformType  TransformType;
   union
   {
      L_SvgTransformScale      Scale;
      L_SvgTransformRotate     Rotate;
      L_SvgTransformSkewX      SkewX;
      L_SvgTransformSkewY      SkewY;
      L_SvgTransformMatrix     Matrix;
      L_SvgTransformTranslate  Translate;
   }
   Transform;
};
typedef struct L_SvgTransformData L_SvgTransformData;

struct L_SvgTransform
{
   L_UINT                   StructSize;
   L_INT                    TransformCount;
   L_SvgTransformData*      TransformData;
};
typedef struct L_SvgTransform L_SvgTransform;

struct L_SvgOrient
{
   L_UINT           StructSize;
   L_SvgAngle       Angle;
   L_SvgOrientType  OrientType;
};
typedef struct L_SvgOrient L_SvgOrient;

struct L_SvgMoveCommand
{
   L_UINT    StructSize;
   L_DOUBLE  X;
   L_DOUBLE  Y;
};
typedef struct L_SvgMoveCommand L_SvgMoveCommand;

struct L_SvgLineCommand
{
   L_UINT    StructSize;
   L_BOOL    Vertical;
   L_BOOL    Horizontal;
   L_DOUBLE  X;
   L_DOUBLE  Y;
};
typedef struct L_SvgLineCommand L_SvgLineCommand;

struct L_SvgCubicBezierCommand
{
   L_UINT    StructSize;
   L_BOOL    Smooth;
   L_DOUBLE  X;
   L_DOUBLE  Y;
   L_DOUBLE  X1;
   L_DOUBLE  Y1;
   L_DOUBLE  X2;
   L_DOUBLE  Y2;
};
typedef struct L_SvgCubicBezierCommand L_SvgCubicBezierCommand;

struct L_SvgQuadraticBezierCommand
{
   L_UINT    StructSize;
   L_BOOL    Smooth;
   L_DOUBLE  X;
   L_DOUBLE  Y;
   L_DOUBLE  X1;
   L_DOUBLE  Y1;
};
typedef struct L_SvgQuadraticBezierCommand L_SvgQuadraticBezierCommand;

struct L_SvgEllipticalArcCommand
{
   L_UINT    StructSize;
   L_BOOL    Sweep;
   L_BOOL    LargeArc;
   L_DOUBLE  X;
   L_DOUBLE  Y;
   L_DOUBLE  Rx;
   L_DOUBLE  Ry;
   L_DOUBLE  XRotation;
};
typedef struct L_SvgEllipticalArcCommand L_SvgEllipticalArcCommand;

struct L_SvgCommandObject
{
   L_UINT                  StructSize;
   L_BOOL                  Relative;
   L_SvgCommandObjectType  CommandObjectType;
   union
   {
      L_SvgMoveCommand             Move;
      L_SvgLineCommand             Line;
      L_SvgCubicBezierCommand      CubicBezier;
      L_SvgEllipticalArcCommand    EllipticalArc;
      L_SvgQuadraticBezierCommand  QuadraticBezier;
   }
   Command;
};
typedef struct L_SvgCommandObject L_SvgCommandObject;

struct L_SvgPathData
{
   L_UINT               StructSize;
   L_INT                CommandsCount;
   L_SvgCommandObject*  Commands;
};
typedef struct L_SvgPathData L_SvgPathData;

struct L_SvgTextPositioningAttrs
{
   L_UINT             StructSize;
   L_INT              RotateCount;
   L_DOUBLE*          Rotate;
   L_INT              DxCount;
   L_SvgLength*       Dx;
   L_INT              DyCount;
   L_SvgLength*       Dy;
   L_INT              XCount;
   L_SvgLength*       X;
   L_INT              YCount;
   L_SvgLength*       Y;
};
typedef struct L_SvgTextPositioningAttrs L_SvgTextPositioningAttrs;

// Elements

struct L_SvgElementA
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgViewBox              ViewBox;
   L_SvgStyleType            StyleType;
   L_SvgScriptType           ScriptType;
   L_SvgZoomAndPan           ZoomAndPan;
   L_SvgCoreAttrsA           CoreAttrs;
   L_SvgTestAttrsA           TestAttrs;
   L_SvgStylePropA           StyleProp;
   L_SvgXLinkRefAttrsA       XLinkRefAttrs;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgTransform            Transform;
};
typedef struct L_SvgElementA L_SvgElementA;
#if defined(FOR_UNICODE)
struct L_SvgElement
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgViewBox              ViewBox;
   L_SvgStyleType            StyleType;
   L_SvgScriptType           ScriptType;
   L_SvgZoomAndPan           ZoomAndPan;
   L_SvgCoreAttrs            CoreAttrs;
   L_SvgTestAttrs            TestAttrs;
   L_SvgStyleProp            StyleProp;
   L_SvgXLinkRefAttrs        XLinkRefAttrs;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgTransform            Transform;
};
typedef struct L_SvgElement L_SvgElement;
#else
typedef struct L_SvgElementA L_SvgElement;
#endif // #if defined(FOR_UNICODE)


struct L_SvgGElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgGElementA L_SvgGElementA;
#if defined(FOR_UNICODE)
struct L_SvgGElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgGElement L_SvgGElement;
#else
typedef struct L_SvgGElementA L_SvgGElement;
#endif // #if defined(FOR_UNICODE)


struct L_SvgMaskElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
   L_SvgLength      X;
   L_SvgLength      Y;
   L_SvgLength      Width;
   L_SvgLength      Height;
};
typedef struct L_SvgMaskElementA L_SvgMaskElementA;
#if defined(FOR_UNICODE)
struct L_SvgMaskElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
   L_SvgLength     X;
   L_SvgLength     Y;
   L_SvgLength     Width;
   L_SvgLength     Height;
};
typedef struct L_SvgMaskElement L_SvgMaskElement;
#else
typedef struct L_SvgMaskElementA L_SvgMaskElement;
#endif // #if defined(FOR_UNICODE)


struct L_SvgAnchorElementA
{
   L_UINT               StructSize;
   L_BOOL               ExternalResource;
   L_CHAR *             Href;
   L_SvgTransform       Transform;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgTestAttrsA      TestAttrs;
   L_SvgStylePropA      StyleProp;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgAnchorElementA L_SvgAnchorElementA;
#if defined(FOR_UNICODE)
struct L_SvgAnchorElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_TCHAR *           Href;
   L_SvgTransform      Transform;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgTestAttrs      TestAttrs;
   L_SvgStyleProp      StyleProp;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgAnchorElement L_SvgAnchorElement;
#else
typedef struct L_SvgAnchorElementA L_SvgAnchorElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgDefsElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgDefsElementA L_SvgDefsElementA;
#if defined(FOR_UNICODE)
struct L_SvgDefsElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgDefsElement L_SvgDefsElement;
#else
typedef struct L_SvgDefsElementA L_SvgDefsElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgDescElementA
{
   L_UINT           StructSize;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgDescElementA L_SvgDescElementA;
#if defined(FOR_UNICODE)
struct L_SvgDescElement
{
   L_UINT          StructSize;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgDescElement L_SvgDescElement;
#else
typedef struct L_SvgDescElementA L_SvgDescElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTitleElementA
{
   L_UINT           StructSize;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgTitleElementA L_SvgTitleElementA;
#if defined(FOR_UNICODE)
struct L_SvgTitleElement
{
   L_UINT          StructSize;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgTitleElement L_SvgTitleElement;
#else
typedef struct L_SvgTitleElementA L_SvgTitleElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgSymbolElementA
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgViewBox              ViewBox;
   L_SvgCoreAttrsA           CoreAttrs;
   L_SvgStylePropA           StyleProp;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
};
typedef struct L_SvgSymbolElementA L_SvgSymbolElementA;
#if defined(FOR_UNICODE)
struct L_SvgSymbolElement
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgViewBox              ViewBox;
   L_SvgCoreAttrs            CoreAttrs;
   L_SvgStyleProp            StyleProp;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
};
typedef struct L_SvgSymbolElement L_SvgSymbolElement;
#else
typedef struct L_SvgSymbolElementA L_SvgSymbolElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgUseElementA
{
   L_UINT               StructSize;
   L_BOOL               ExternalResource;
   L_CHAR *             Href;
   L_SvgLength          X;
   L_SvgLength          Y;
   L_SvgLength          Width;
   L_SvgLength          Height;
   L_SvgTransform       Transform;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgStylePropA      StyleProp;
   L_SvgTestAttrsA      TestAttrs;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgUseElementA L_SvgUseElementA;
#if defined(FOR_UNICODE)
struct L_SvgUseElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_TCHAR *           Href;
   L_SvgLength         X;
   L_SvgLength         Y;
   L_SvgLength         Width;
   L_SvgLength         Height;
   L_SvgTransform      Transform;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgStyleProp      StyleProp;
   L_SvgTestAttrs      TestAttrs;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgUseElement L_SvgUseElement;
#else
typedef struct L_SvgUseElementA L_SvgUseElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgImageElementA
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_CHAR *                  Href;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgTransform            Transform;
   L_SvgStylePropA           StyleProp;
   L_SvgCoreAttrsA           CoreAttrs;
   L_SvgTestAttrsA           TestAttrs;
   L_SvgXLinkRefAttrsA       XLinkRefAttrs;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
};
typedef struct L_SvgImageElementA L_SvgImageElementA;
#if defined(FOR_UNICODE)
struct L_SvgImageElement
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_TCHAR *                 Href;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgTransform            Transform;
   L_SvgStyleProp            StyleProp;
   L_SvgCoreAttrs            CoreAttrs;
   L_SvgTestAttrs            TestAttrs;
   L_SvgXLinkRefAttrs        XLinkRefAttrs;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
};
typedef struct L_SvgImageElement L_SvgImageElement;
#else
typedef struct L_SvgImageElementA L_SvgImageElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgSwitchElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgSwitchElementA L_SvgSwitchElementA;
#if defined(FOR_UNICODE)
struct L_SvgSwitchElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgSwitchElement L_SvgSwitchElement;
#else
typedef struct L_SvgSwitchElementA L_SvgSwitchElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStyleElementA
{
   L_UINT           StructSize;
   L_CHAR *         ElementText;
   L_CHAR *         Title;
   L_SvgMediaType   Media;
   L_SvgStyleType   StyleType;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgStyleElementA L_SvgStyleElementA;
#if defined(FOR_UNICODE)
struct L_SvgStyleElement
{
   L_UINT          StructSize;
   L_TCHAR *       ElementText;
   L_TCHAR *       Title;
   L_SvgMediaType  Media;
   L_SvgStyleType  StyleType;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgStyleElement L_SvgStyleElement;
#else
typedef struct L_SvgStyleElementA L_SvgStyleElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPathElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgValue       PathLength;
   L_SvgPathData    Data;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgPathElementA L_SvgPathElementA;
#if defined(FOR_UNICODE)
struct L_SvgPathElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgValue      PathLength;
   L_SvgPathData   Data;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgPathElement L_SvgPathElement;
#else
typedef struct L_SvgPathElementA L_SvgPathElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgRectElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgLength      X;
   L_SvgLength      Y;
   L_SvgLength      Width;
   L_SvgLength      Height;
   L_SvgLength      Rx;
   L_SvgLength      Ry;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgRectElementA L_SvgRectElementA;
#if defined(FOR_UNICODE)
struct L_SvgRectElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgLength     X;
   L_SvgLength     Y;
   L_SvgLength     Width;
   L_SvgLength     Height;
   L_SvgLength     Rx;
   L_SvgLength     Ry;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgRectElement L_SvgRectElement;
#else
typedef struct L_SvgRectElementA L_SvgRectElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgCircleElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgLength      R;
   L_SvgLength      Cx;
   L_SvgLength      Cy;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgCircleElementA L_SvgCircleElementA;
#if defined(FOR_UNICODE)
struct L_SvgCircleElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgLength     R;
   L_SvgLength     Cx;
   L_SvgLength     Cy;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgCircleElement L_SvgCircleElement;
#else
typedef struct L_SvgCircleElementA L_SvgCircleElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgEllipseElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgLength      Rx;
   L_SvgLength      Ry;
   L_SvgLength      Cx;
   L_SvgLength      Cy;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgEllipseElementA L_SvgEllipseElementA;
#if defined(FOR_UNICODE)
struct L_SvgEllipseElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgLength     Rx;
   L_SvgLength     Ry;
   L_SvgLength     Cx;
   L_SvgLength     Cy;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgEllipseElement L_SvgEllipseElement;
#else
typedef struct L_SvgEllipseElementA L_SvgEllipseElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgLineElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_SvgLength      X1;
   L_SvgLength      Y1;
   L_SvgLength      X2;
   L_SvgLength      Y2;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgLineElementA L_SvgLineElementA;
#if defined(FOR_UNICODE)
struct L_SvgLineElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_SvgLength     X1;
   L_SvgLength     Y1;
   L_SvgLength     X2;
   L_SvgLength     Y2;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgLineElement L_SvgLineElement;
#else
typedef struct L_SvgLineElementA L_SvgLineElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPolylineElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_INT            PointsCount;
   L_POINTD*        Points;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgPolylineElementA L_SvgPolylineElementA;
#if defined(FOR_UNICODE)
struct L_SvgPolylineElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_INT           PointsCount;
   L_POINTD*       Points;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgPolylineElement L_SvgPolylineElement;
#else
typedef struct L_SvgPolylineElementA L_SvgPolylineElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPolygonElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_INT            PointsCount;
   L_POINTD*        Points;
   L_SvgTransform   Transform;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgTestAttrsA  TestAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgPolygonElementA L_SvgPolygonElementA;
#if defined(FOR_UNICODE)
struct L_SvgPolygonElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_INT           PointsCount;
   L_POINTD*       Points;
   L_SvgTransform  Transform;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgTestAttrs  TestAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgPolygonElement L_SvgPolygonElement;
#else
typedef struct L_SvgPolygonElementA L_SvgPolygonElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTextElementA
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_CHAR *                  ElementText;
   L_UINT                     ElementTextSize;
   L_SvgLength                TextLength;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgTransform             Transform;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgStylePropA            StyleProp;
   L_SvgCoreAttrsA            CoreAttrs;
   L_SvgTestAttrsA            TestAttrs;
};
typedef struct L_SvgTextElementA L_SvgTextElementA;
#if defined(FOR_UNICODE)
struct L_SvgTextElement
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_TCHAR *                  ElementText;
   L_UINT                     ElementTextSize;
   L_SvgLength                TextLength;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgTransform             Transform;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgStyleProp             StyleProp;
   L_SvgCoreAttrs             CoreAttrs;
   L_SvgTestAttrs             TestAttrs;
};
typedef struct L_SvgTextElement L_SvgTextElement;
#else
typedef struct L_SvgTextElementA L_SvgTextElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTSpanElementA
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_CHAR *                   ElementText;
   L_UINT                     ElementTextSize;
   L_SvgLength                TextLength;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgStylePropA            StyleProp;
   L_SvgCoreAttrsA            CoreAttrs;
   L_SvgTestAttrsA            TestAttrs;
};
typedef struct L_SvgTSpanElementA L_SvgTSpanElementA;
#if defined(FOR_UNICODE)
struct L_SvgTSpanElement
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_TCHAR *                  ElementText;
   L_UINT                     ElementTextSize;
   L_SvgLength                TextLength;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgStyleProp             StyleProp;
   L_SvgCoreAttrs             CoreAttrs;
   L_SvgTestAttrs             TestAttrs;
};
typedef struct L_SvgTSpanElement L_SvgTSpanElement;
#else
typedef struct L_SvgTSpanElementA L_SvgTSpanElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTRefElementA
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_CHAR *                   Href;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgLength                TextLength;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgCoreAttrsA            CoreAttrs;
   L_SvgTestAttrsA            TestAttrs;
   L_SvgStylePropA            StyleProp;
   L_SvgXLinkRefAttrsA        XLinkRefAttrs;
};
typedef struct L_SvgTRefElementA L_SvgTRefElementA;
#if defined(FOR_UNICODE)
struct L_SvgTRefElement
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_TCHAR *                  Href;
   L_SvgLengthAdjust          LengthAdjust;
   L_SvgLength                TextLength;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgCoreAttrs             CoreAttrs;
   L_SvgTestAttrs             TestAttrs;
   L_SvgStyleProp             StyleProp;
   L_SvgXLinkRefAttrs         XLinkRefAttrs;
};
typedef struct L_SvgTRefElement L_SvgTRefElement;
#else
typedef struct L_SvgTRefElementA L_SvgTRefElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgTextPathElementA
{
   L_UINT               StructSize;
   L_BOOL               ExternalResource;
   L_CHAR *             Href;
   L_CHAR *             ElementText;
   L_SvgMethod          Method;
   L_SvgSpacing         Spacing;
   L_SvgLengthAdjust    LengthAdjust;
   L_SvgLength          StartOffset;
   L_SvgLength          TextLength;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgTestAttrsA      TestAttrs;
   L_SvgStylePropA      StyleProp;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgTextPathElementA L_SvgTextPathElementA;
#if defined(FOR_UNICODE)
struct L_SvgTextPathElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_TCHAR *           Href;
   L_TCHAR *           ElementText;
   L_SvgMethod         Method;
   L_SvgSpacing        Spacing;
   L_SvgLengthAdjust   LengthAdjust;
   L_SvgLength         StartOffset;
   L_SvgLength         TextLength;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgTestAttrs      TestAttrs;
   L_SvgStyleProp      StyleProp;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgTextPathElement L_SvgTextPathElement;
#else
typedef struct L_SvgTextPathElementA L_SvgTextPathElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgAltGlyphElementA
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_CHAR *                   Href;
   L_CHAR *                   GlyphRef;
   L_CHAR *                   Format;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgCoreAttrsA            CoreAttrs;
   L_SvgTestAttrsA            TestAttrs;
   L_SvgStylePropA            StyleProp;
   L_SvgXLinkRefAttrsA        XLinkRefAttrs;
};
typedef struct L_SvgAltGlyphElementA L_SvgAltGlyphElementA;
#if defined(FOR_UNICODE)
struct L_SvgAltGlyphElement
{
   L_UINT                     StructSize;
   L_BOOL                     ExternalResource;
   L_TCHAR *                  Href;
   L_TCHAR *                  GlyphRef;
   L_TCHAR *                  Format;
   L_SvgTextPositioningAttrs  PositioningAttrs;
   L_SvgCoreAttrs             CoreAttrs;
   L_SvgTestAttrs             TestAttrs;
   L_SvgStyleProp             StyleProp;
   L_SvgXLinkRefAttrs         XLinkRefAttrs;
};
typedef struct L_SvgAltGlyphElement L_SvgAltGlyphElement;
#else
typedef struct L_SvgAltGlyphElementA L_SvgAltGlyphElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgAltGlyphDefElementA
{
   L_UINT           StructSize;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgAltGlyphDefElementA L_SvgAltGlyphDefElementA;
#if defined(FOR_UNICODE)
struct L_SvgAltGlyphDefElement
{
   L_UINT          StructSize;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgAltGlyphDefElement L_SvgAltGlyphDefElement;
#else
typedef struct L_SvgAltGlyphDefElementA L_SvgAltGlyphDefElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgAltGlyphItemElementA
{
   L_UINT           StructSize;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgAltGlyphItemElementA L_SvgAltGlyphItemElementA;
#if defined(FOR_UNICODE)
struct L_SvgAltGlyphItemElement
{
   L_UINT          StructSize;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgAltGlyphItemElement L_SvgAltGlyphItemElement;
#else
typedef struct L_SvgAltGlyphItemElementA L_SvgAltGlyphItemElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgGlyphRefElementA
{
   L_UINT               StructSize;
   L_CHAR *             Href;
   L_CHAR *             GlyphRef;
   L_CHAR *             Format;
   L_DOUBLE             X;
   L_DOUBLE             Y;
   L_SvgLength          Dx;
   L_SvgLength          Dy;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgStylePropA      StyleProp;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgGlyphRefElementA L_SvgGlyphRefElementA;
#if defined(FOR_UNICODE)
struct L_SvgGlyphRefElement
{
   L_UINT              StructSize;
   L_TCHAR *           Href;
   L_TCHAR *           GlyphRef;
   L_TCHAR *           Format;
   L_DOUBLE            X;
   L_DOUBLE            Y;
   L_SvgLength         Dx;
   L_SvgLength         Dy;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgStyleProp      StyleProp;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgGlyphRefElement L_SvgGlyphRefElement;
#else
typedef struct L_SvgGlyphRefElementA L_SvgGlyphRefElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgMarkerElementA
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgMarkerUnits          MarkerUnits;
   L_SvgLength               RefX;
   L_SvgLength               RefY;
   L_SvgLength               MarkerWidth;
   L_SvgLength               MarkerHeight;
   L_SvgOrient               Orient;
   L_SvgViewBox              ViewBox;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgCoreAttrsA           CoreAttrs;
   L_SvgStylePropA           StyleProp;
};
typedef struct L_SvgMarkerElementA L_SvgMarkerElementA;
#if defined(FOR_UNICODE)
struct L_SvgMarkerElement
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_SvgMarkerUnits          MarkerUnits;
   L_SvgLength               RefX;
   L_SvgLength               RefY;
   L_SvgLength               MarkerWidth;
   L_SvgLength               MarkerHeight;
   L_SvgOrient               Orient;
   L_SvgViewBox              ViewBox;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgCoreAttrs            CoreAttrs;
   L_SvgStyleProp            StyleProp;
};
typedef struct L_SvgMarkerElement L_SvgMarkerElement;
#else
typedef struct L_SvgMarkerElementA L_SvgMarkerElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgColorProfileElementA
{
   L_UINT                StructSize;
   L_CHAR *              Href;
   L_CHAR *              Name;
   L_CHAR *              Local;
   L_SvgRenderingIntent  RenderingIntent;
   L_SvgCoreAttrsA       CoreAttrs;
   L_SvgXLinkRefAttrsA   XLinkRefAttrs;
};
typedef struct L_SvgColorProfileElementA L_SvgColorProfileElementA;
#if defined(FOR_UNICODE)
struct L_SvgColorProfileElement
{
   L_UINT                StructSize;
   L_TCHAR *             Href;
   L_TCHAR *             Name;
   L_TCHAR *             Local;
   L_SvgRenderingIntent  RenderingIntent;
   L_SvgCoreAttrs        CoreAttrs;
   L_SvgXLinkRefAttrs    XLinkRefAttrs;
};
typedef struct L_SvgColorProfileElement L_SvgColorProfileElement;
#else
typedef struct L_SvgColorProfileElementA L_SvgColorProfileElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgLinearGradientElementA
{
   L_UINT               StructSize;
   L_BOOL               ExternalResource;
   L_CHAR *             Href;
   L_SvgSpreadMethod    SpreadMethod;
   L_SvgGradientUnits   GradientUnits;
   L_SvgLength          X1;
   L_SvgLength          Y1;
   L_SvgLength          X2;
   L_SvgLength          Y2;
   L_SvgTransform       Transform;
   L_SvgStylePropA      StyleProp;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgLinearGradientElementA L_SvgLinearGradientElementA;
#if defined(FOR_UNICODE)
struct L_SvgLinearGradientElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_TCHAR *           Href;
   L_SvgSpreadMethod   SpreadMethod;
   L_SvgGradientUnits  GradientUnits;
   L_SvgLength         X1;
   L_SvgLength         Y1;
   L_SvgLength         X2;
   L_SvgLength         Y2;
   L_SvgTransform      Transform;
   L_SvgStyleProp      StyleProp;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgLinearGradientElement L_SvgLinearGradientElement;
#else
typedef struct L_SvgLinearGradientElementA L_SvgLinearGradientElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgRadialGradientElementA
{
   L_UINT               StructSize;
   L_BOOL               ExternalResource;
   L_CHAR *             Href;
   L_SvgSpreadMethod    SpreadMethod;
   L_SvgGradientUnits   GradientUnits;
   L_SvgLength          Cx;
   L_SvgLength          Cy;
   L_SvgLength          Fx;
   L_SvgLength          Fy;
   L_SvgLength          R;
   L_SvgTransform       Transform;
   L_SvgStylePropA      StyleProp;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgRadialGradientElementA L_SvgRadialGradientElementA;
#if defined(FOR_UNICODE)
struct L_SvgRadialGradientElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_TCHAR *           Href;
   L_SvgSpreadMethod   SpreadMethod;
   L_SvgGradientUnits  GradientUnits;
   L_SvgLength         Cx;
   L_SvgLength         Cy;
   L_SvgLength         Fx;
   L_SvgLength         Fy;
   L_SvgLength         R;
   L_SvgTransform      Transform;
   L_SvgStyleProp      StyleProp;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgRadialGradientElement L_SvgRadialGradientElement;
#else
typedef struct L_SvgRadialGradientElementA L_SvgRadialGradientElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgStopElementA
{
   L_UINT           StructSize;
   L_SvgLength      Offset;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgStopElementA L_SvgStopElementA;
#if defined(FOR_UNICODE)
struct L_SvgStopElement
{
   L_UINT          StructSize;
   L_SvgLength     Offset;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgStopElement L_SvgStopElement;
#else
typedef struct L_SvgStopElementA L_SvgStopElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgPatternElementA
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_CHAR *                  Href;
   L_SvgPatternUnits         PatternUnits;
   L_SvgPatternContentUnits  PatternContentUnits;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgViewBox              ViewBox;
   L_SvgTransform            Transform;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgStylePropA           StyleProp;
   L_SvgCoreAttrsA           CoreAttrs;
   L_SvgTestAttrsA           TestAttrs;
   L_SvgXLinkRefAttrsA       XLinkRefAttrs;
};
typedef struct L_SvgPatternElementA L_SvgPatternElementA;
#if defined(FOR_UNICODE)
struct L_SvgPatternElement
{
   L_UINT                    StructSize;
   L_BOOL                    ExternalResource;
   L_TCHAR *                 Href;
   L_SvgPatternUnits         PatternUnits;
   L_SvgPatternContentUnits  PatternContentUnits;
   L_SvgLength               X;
   L_SvgLength               Y;
   L_SvgLength               Width;
   L_SvgLength               Height;
   L_SvgViewBox              ViewBox;
   L_SvgTransform            Transform;
   L_SvgPreserveAspectratio  PreserveAspectRatio;
   L_SvgStyleProp            StyleProp;
   L_SvgCoreAttrs            CoreAttrs;
   L_SvgTestAttrs            TestAttrs;
   L_SvgXLinkRefAttrs        XLinkRefAttrs;
};
typedef struct L_SvgPatternElement L_SvgPatternElement;
#else
typedef struct L_SvgPatternElementA L_SvgPatternElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgClipPathElementA
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_SvgClipPathUnits  ClipPathUnits;
   L_SvgTransform      Transform;
   L_SvgCoreAttrsA     CoreAttrs;
   L_SvgTestAttrsA     TestAttrs;
   L_SvgStylePropA     StyleProp;
};
typedef struct L_SvgClipPathElementA L_SvgClipPathElementA;
#if defined(FOR_UNICODE)
struct L_SvgClipPathElement
{
   L_UINT              StructSize;
   L_BOOL              ExternalResource;
   L_SvgClipPathUnits  ClipPathUnits;
   L_SvgTransform      Transform;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgTestAttrs      TestAttrs;
   L_SvgStyleProp      StyleProp;
};
typedef struct L_SvgClipPathElement L_SvgClipPathElement;
#else
typedef struct L_SvgClipPathElementA L_SvgClipPathElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontElementA
{
   L_UINT           StructSize;
   L_BOOL           ExternalResource;
   L_DOUBLE         HorizOriginX;
   L_DOUBLE         HorizOriginY;
   L_DOUBLE         HorizAdvX;
   L_DOUBLE         VertOriginX;
   L_DOUBLE         VertOriginY;
   L_DOUBLE         VertAdvY;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgFontElementA L_SvgFontElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontElement
{
   L_UINT          StructSize;
   L_BOOL          ExternalResource;
   L_DOUBLE        HorizOriginX;
   L_DOUBLE        HorizOriginY;
   L_DOUBLE        HorizAdvX;
   L_DOUBLE        VertOriginX;
   L_DOUBLE        VertOriginY;
   L_DOUBLE        VertAdvY;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgFontElement L_SvgFontElement;
#else
typedef struct L_SvgFontElementA L_SvgFontElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgGlyphElementA
{
   L_UINT            StructSize;
   L_CHAR *          Lang;
   L_CHAR *          Unicode;
   L_CHAR *          GlyphName;
   L_DOUBLE          HorizAdvX;
   L_DOUBLE          VertOriginX;
   L_DOUBLE          VertOriginY;
   L_DOUBLE          VertAdvY;
   L_SvgArabicForm   ArabicForm;
   L_SvgOrientation  Orientation;
   L_SvgPathData     Data;
   L_SvgCoreAttrsA   CoreAttrs;
   L_SvgStylePropA   StyleProp;
};
typedef struct L_SvgGlyphElementA L_SvgGlyphElementA;
#if defined(FOR_UNICODE)
struct L_SvgGlyphElement
{
   L_UINT            StructSize;
   L_TCHAR *         Lang;
   L_TCHAR *         Unicode;
   L_TCHAR *         GlyphName;
   L_DOUBLE          HorizAdvX;
   L_DOUBLE          VertOriginX;
   L_DOUBLE          VertOriginY;
   L_DOUBLE          VertAdvY;
   L_SvgArabicForm   ArabicForm;
   L_SvgOrientation  Orientation;
   L_SvgPathData     Data;
   L_SvgCoreAttrs    CoreAttrs;
   L_SvgStyleProp    StyleProp;
};
typedef struct L_SvgGlyphElement L_SvgGlyphElement;
#else
typedef struct L_SvgGlyphElementA L_SvgGlyphElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgMissingGlyphElementA
{
   L_UINT           StructSize;
   L_DOUBLE         HorizAdvX;
   L_DOUBLE         VertAdvY;
   L_DOUBLE         VertOriginX;
   L_DOUBLE         VertOriginY;
   L_SvgPathData    Data;
   L_SvgCoreAttrsA  CoreAttrs;
   L_SvgStylePropA  StyleProp;
};
typedef struct L_SvgMissingGlyphElementA L_SvgMissingGlyphElementA;
#if defined(FOR_UNICODE)
struct L_SvgMissingGlyphElement
{
   L_UINT          StructSize;
   L_DOUBLE        HorizAdvX;
   L_DOUBLE        VertAdvY;
   L_DOUBLE        VertOriginX;
   L_DOUBLE        VertOriginY;
   L_SvgPathData   Data;
   L_SvgCoreAttrs  CoreAttrs;
   L_SvgStyleProp  StyleProp;
};
typedef struct L_SvgMissingGlyphElement L_SvgMissingGlyphElement;
#else
typedef struct L_SvgMissingGlyphElementA L_SvgMissingGlyphElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgHKernElementA
{
   L_UINT           StructSize;
   L_DOUBLE         K;
   L_CHAR *         U1;
   L_CHAR *         G1;
   L_CHAR *         U2;
   L_CHAR *         G2;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgHKernElementA L_SvgHKernElementA;
#if defined(FOR_UNICODE)
struct L_SvgHKernElement
{
   L_UINT          StructSize;
   L_DOUBLE        K;
   L_TCHAR *       U1;
   L_TCHAR *       G1;
   L_TCHAR *       U2;
   L_TCHAR *       G2;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgHKernElement L_SvgHKernElement;
#else
typedef struct L_SvgHKernElementA L_SvgHKernElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgVKernElementA
{
   L_UINT           StructSize;
   L_DOUBLE         K;
   L_CHAR *         U1;
   L_CHAR *         G1;
   L_CHAR *         U2;
   L_CHAR *         G2;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgVKernElementA L_SvgVKernElementA;
#if defined(FOR_UNICODE)
struct L_SvgVKernElement
{
   L_UINT          StructSize;
   L_DOUBLE        K;
   L_TCHAR *       U1;
   L_TCHAR *       G1;
   L_TCHAR *       U2;
   L_TCHAR *       G2;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgVKernElement L_SvgVKernElement;
#else
typedef struct L_SvgVKernElementA L_SvgVKernElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontFaceElementA
{
   L_UINT             StructSize;
   L_CHAR *           UnicodeRange;
   L_CHAR *           Panose;
   L_CHAR *           Widths;
   L_CHAR *           Bbox;
   L_DOUBLE           StemV;
   L_DOUBLE           StemH;
   L_DOUBLE           Slope;
   L_DOUBLE           Ascent;
   L_DOUBLE           Descent;
   L_DOUBLE           XHeight;
   L_DOUBLE           Hanging;
   L_DOUBLE           Alphabetic;
   L_DOUBLE           CapHeight;
   L_DOUBLE           UnitsPerEm;
   L_DOUBLE           Ideographic;
   L_DOUBLE           VHanging;
   L_DOUBLE           VAlphabetic;
   L_DOUBLE           VIdeographic;
   L_DOUBLE           VMathematical;
   L_DOUBLE           AccentHeight;
   L_DOUBLE           Mathematical;
   L_DOUBLE           OverlinePosition;
   L_DOUBLE           OverlineThickness;
   L_DOUBLE           UnderlinePosition;
   L_DOUBLE           UnderlineThickness;
   L_DOUBLE           StrickthroughPosition;
   L_DOUBLE           StrickthroughThickness;
   L_SvgFontStyle     FontStyle;
   L_SvgFontWeight    FontWeight;
   L_SvgFontVariant   FontVariant;
   L_SvgFontStretch   FontStretch;
   L_SvgFontSize      FontSize;
   L_SvgFontFamilyA   FontFamily;
   L_SvgCoreAttrsA    CoreAttrs;
};
typedef struct L_SvgFontFaceElementA L_SvgFontFaceElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontFaceElement
{
   L_UINT             StructSize;
   L_TCHAR *          UnicodeRange;
   L_TCHAR *          Panose;
   L_TCHAR *          Widths;
   L_TCHAR *          Bbox;
   L_DOUBLE           StemV;
   L_DOUBLE           StemH;
   L_DOUBLE           Slope;
   L_DOUBLE           Ascent;
   L_DOUBLE           Descent;
   L_DOUBLE           XHeight;
   L_DOUBLE           Hanging;
   L_DOUBLE           Alphabetic;
   L_DOUBLE           CapHeight;
   L_DOUBLE           UnitsPerEm;
   L_DOUBLE           Ideographic;
   L_DOUBLE           VHanging;
   L_DOUBLE           VAlphabetic;
   L_DOUBLE           VIdeographic;
   L_DOUBLE           VMathematical;
   L_DOUBLE           AccentHeight;
   L_DOUBLE           Mathematical;
   L_DOUBLE           OverlinePosition;
   L_DOUBLE           OverlineThickness;
   L_DOUBLE           UnderlinePosition;
   L_DOUBLE           UnderlineThickness;
   L_DOUBLE           StrickthroughPosition;
   L_DOUBLE           StrickthroughThickness;
   L_SvgFontStyle     FontStyle;
   L_SvgFontWeight    FontWeight;
   L_SvgFontVariant   FontVariant;
   L_SvgFontStretch   FontStretch;
   L_SvgFontSize      FontSize;
   L_SvgFontFamily    FontFamily;
   L_SvgCoreAttrs     CoreAttrs;
};
typedef struct L_SvgFontFaceElement L_SvgFontFaceElement;
#else
typedef struct L_SvgFontFaceElementA L_SvgFontFaceElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontFaceSrcElementA
{
   L_UINT           StructSize;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgFontFaceSrcElementA L_SvgFontFaceSrcElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontFaceSrcElement
{
   L_UINT          StructSize;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgFontFaceSrcElement L_SvgFontFaceSrcElement;
#else
typedef struct L_SvgFontFaceSrcElementA L_SvgFontFaceSrcElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontFaceUriElementA
{
   L_UINT               StructSize;
   L_CHAR *             Href;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgFontFaceUriElementA L_SvgFontFaceUriElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontFaceUriElement
{
   L_UINT              StructSize;
   L_TCHAR *           Href;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgFontFaceUriElement L_SvgFontFaceUriElement;
#else
typedef struct L_SvgFontFaceUriElementA L_SvgFontFaceUriElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontFaceFormatElementA
{
   L_UINT           StructSize;
   L_CHAR *         String;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgFontFaceFormatElementA L_SvgFontFaceFormatElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontFaceFormatElement
{
   L_UINT          StructSize;
   L_TCHAR *       String;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgFontFaceFormatElement L_SvgFontFaceFormatElement;
#else
typedef struct L_SvgFontFaceFormatElementA L_SvgFontFaceFormatElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFontFaceNameElementA
{
   L_UINT           StructSize;
   L_CHAR *         Name;
   L_SvgCoreAttrsA  CoreAttrs;
};
typedef struct L_SvgFontFaceNameElementA L_SvgFontFaceNameElementA;
#if defined(FOR_UNICODE)
struct L_SvgFontFaceNameElement
{
   L_UINT          StructSize;
   L_TCHAR *       Name;
   L_SvgCoreAttrs  CoreAttrs;
};
typedef struct L_SvgFontFaceNameElement L_SvgFontFaceNameElement;
#else
typedef struct L_SvgFontFaceNameElementA L_SvgFontFaceNameElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgDefinitionSrcElementA
{
   L_UINT               StructSize;
   L_CHAR *             Href;
   L_SvgCoreAttrsA      CoreAttrs;
   L_SvgXLinkRefAttrsA  XLinkRefAttrs;
};
typedef struct L_SvgDefinitionSrcElementA L_SvgDefinitionSrcElementA;
#if defined(FOR_UNICODE)
struct L_SvgDefinitionSrcElement
{
   L_UINT              StructSize;
   L_TCHAR *           Href;
   L_SvgCoreAttrs      CoreAttrs;
   L_SvgXLinkRefAttrs  XLinkRefAttrs;
};
typedef struct L_SvgDefinitionSrcElement L_SvgDefinitionSrcElement;
#else
typedef struct L_SvgDefinitionSrcElementA L_SvgDefinitionSrcElement;
#endif // #if defined(FOR_UNICODE)

struct L_SvgElementsIterator
{
   L_UINT            StructSize;
   L_INT             Count;
   L_SvgNodeHandle * Nodes;
};
typedef struct L_SvgElementsIterator L_SvgElementsIterator;

struct L_SvgTextDataA
{
   L_UINT                    StructSize;
   L_UINT                    Length;
   L_CHAR*                   Text;
   L_RECTD*                  Bounds;
   L_SvgTextCharacterFlags*  CharacterFlags;
   L_SvgCharacterDirection*  Directions;
   L_INT                     OcrZoneIndex;
   L_INT                     OcrCharacterIndex;
};
typedef struct L_SvgTextDataA L_SvgTextDataA;
#if defined(FOR_UNICODE)
struct L_SvgTextData
{
   L_UINT                    StructSize;
   L_UINT                    Length;
   L_TCHAR*                  Text;
   L_RECTD*                  Bounds;
   L_SvgTextCharacterFlags*  CharacterFlags;
   L_SvgCharacterDirection*  Directions;
   L_INT                     OcrZoneIndex;
   L_INT                     OcrCharacterIndex;
};
typedef struct L_SvgTextData L_SvgTextData;
#else
typedef struct L_SvgTextDataA L_SvgTextData;
#endif // #if defined(FOR_UNICODE)

struct L_SvgElementInfoA
{
   L_UINT            StructSize;
   L_SvgElementType  Type;
   L_RECTD           Bounds;
   L_SvgTextDataA    TextData;
};
typedef struct L_SvgElementInfoA L_SvgElementInfoA;
#if defined(FOR_UNICODE)
struct L_SvgElementInfo
{
   L_UINT            StructSize;
   L_SvgElementType  Type;
   L_RECTD           Bounds;
   L_SvgTextData     TextData;
};
typedef struct L_SvgElementInfo L_SvgElementInfo;
#else
typedef struct L_SvgElementInfoA L_SvgElementInfo;
#endif // #if defined(FOR_UNICODE)

struct L_SvgFilterElementInfo
{
   L_UINT            StructSize;
   L_SvgElementType  Type;
   L_SvgNodeHandle   Node;
};
typedef struct L_SvgFilterElementInfo L_SvgFilterElementInfo;

typedef L_INT (pEXT_CALLBACK L_SvgFilterElementsCallback)(const L_SvgFilterElementInfo* info, L_BOOL* skipElement, L_VOID* userData);

struct L_SvgSortOptions
{
   L_UINT                       StructSize;
   L_SvgSortFlags               SortFlags;
   L_SvgExtractText             ExtractText;
};
typedef struct L_SvgSortOptions L_SvgSortOptions;

struct L_SvgDataUriA
{
   L_UINT         StructSize;
   L_BOOL         IsDataUri;
   const L_CHAR*  Href;
   L_UINT         MediaOffset;
   L_UINT         MediaLength;
   L_UINT         CharSetOffset;
   L_UINT         CharSetLength;
   L_BOOL         IsBase64;
   L_UINT         ValueOffset;
   L_UINT         ValueLength;
   L_INT          ImageFormat;
   L_CHAR         Extension[8];
};
typedef struct L_SvgDataUriA L_SvgDataUriA;
#if defined(FOR_UNICODE)
struct L_SvgDataUri
{
   L_UINT         StructSize;
   L_BOOL         IsDataUri;
   const L_TCHAR* Href;
   L_UINT         MediaOffset;
   L_UINT         MediaLength;
   L_UINT         CharSetOffset;
   L_UINT         CharSetLength;
   L_BOOL         IsBase64;
   L_UINT         ValueOffset;
   L_UINT         ValueLength;
   L_INT          ImageFormat;
   L_TCHAR        Extension[8];
};
typedef struct L_SvgDataUri L_SvgDataUri;
#else
typedef struct L_SvgDataUriA L_SvgDataUri;
#endif // #if defined(FOR_UNICODE)

typedef L_INT (pEXT_CALLBACK L_SvgEnumerateCallback)(L_SvgNodeHandle node, L_VOID* userData);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgFreeMemory(L_VOID* buffer);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgFreeNode(L_SvgNodeHandle node);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgFreeElement(L_VOID* element, L_SvgElementType elementType); // Free 'element' members allocated by L_SvgGetElement
L_LTSVG_API L_INT EXT_FUNCTION L_SvgFreeIterator(L_SvgElementsIterator* elementsIterator);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgInitElement(L_VOID* element, L_SvgElementType elementType, L_UINT elementStructSize);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementType(const L_SvgNodeHandle node, L_SvgElementType* elementType);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementA(const L_SvgNodeHandle node, L_VOID* element, L_UINT elementStructSize); // 'element' members must be freed using L_SvgFreeElement
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElementA(L_SvgNodeHandle node, const L_VOID* element);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementNameA(const L_SvgNodeHandle node, L_CHAR** name);// 'name' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementValueA(const L_SvgNodeHandle node, L_CHAR** value);// 'value' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElementValueA(L_SvgNodeHandle node, const L_CHAR* value);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementAttributeValueA(const L_SvgNodeHandle node, const L_CHAR* attrName, L_CHAR** attrValue);// 'attrValue' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElementAttributeValueA(L_SvgNodeHandle node, const L_CHAR* attrName, L_CHAR* attrValue);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgRemoveElementAttributeA(L_SvgNodeHandle node, const L_CHAR* attrName);
#if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElement(const L_SvgNodeHandle node, L_VOID* element, L_UINT elementStructSize); // 'element' members must be freed using L_SvgFreeElement
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElement(L_SvgNodeHandle node, const L_VOID* element);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementName(const L_SvgNodeHandle node, L_TCHAR** name);// 'name' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementValue(const L_SvgNodeHandle node, L_TCHAR** value);// 'value' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElementValue(L_SvgNodeHandle node, const L_TCHAR* value);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetElementAttributeValue(const L_SvgNodeHandle node, const L_TCHAR* attrName, L_TCHAR** attrValue);// 'attrValue' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetElementAttributeValue(L_SvgNodeHandle node, const L_TCHAR* attrName, L_TCHAR* attrValue);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgRemoveElementAttribute(L_SvgNodeHandle node, const L_TCHAR* attrName);
#else
#define L_SvgGetElement L_SvgGetElementA
#define L_SvgSetElement L_SvgSetElementA
#define L_SvgGetElementName L_SvgGetElementNameA
#define L_SvgGetElementValue L_SvgGetElementValueA
#define L_SvgSetElementValue L_SvgSetElementValueA
#define L_SvgGetElementAttributeValue L_SvgGetElementAttributeValueA
#define L_SvgSetElementAttributeValue L_SvgSetElementAttributeValueA
#define L_SvgRemoveElementAttribute L_SvgRemoveElementAttributeA
#endif // #if defined(FOR_UNICODE)

L_LTSVG_API L_INT EXT_FUNCTION L_SvgCreateDocument(L_SvgNodeHandle* docHandle, L_SvgVersion version);// 'docHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetMaximumElements(L_SvgNodeHandle docHandle, L_UINT value);
L_LTSVG_API L_UINT EXT_FUNCTION L_SvgGetMaximumElements(L_SvgNodeHandle docHandle);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgCopyDocument(const L_SvgNodeHandle srcDocHandle, L_SvgNodeHandle* dstDocHandle);// 'dstDocHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgLoadDocumentA(const L_CHAR* fileName, L_SvgNodeHandle* docHandle, const L_SvgLoadOptions* options); // 'docHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSaveDocumentA(const L_CHAR* fileName, const L_SvgNodeHandle docHandle, const L_SvgSaveOptionsA* options);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSaveDocumentMemoryA(const L_SvgNodeHandle docHandle, L_UCHAR** buffer, L_UINT* bufferSize, const L_SvgSaveOptionsA* options);// '*buffer' must be freed using L_SvgFreeMemory
#if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgLoadDocument(const L_TCHAR* fileName, L_SvgNodeHandle* docHandle, const L_SvgLoadOptions* options); // 'docHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSaveDocument(const L_TCHAR* fileName, const L_SvgNodeHandle docHandle, const L_SvgSaveOptions* options);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSaveDocumentMemory(const L_SvgNodeHandle docHandle, L_UCHAR** buffer, L_UINT* bufferSize, const L_SvgSaveOptions* options);// '*buffer' must be freed using L_SvgFreeMemory
#else
#define L_SvgLoadDocument L_SvgLoadDocumentA
#define L_SvgSaveDocument L_SvgSaveDocumentA
#define L_SvgSaveDocumentMemory L_SvgSaveDocumentMemoryA
#endif // #if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgLoadDocumentMemory(const L_UCHAR* buffer, L_UINT bufferSize, L_SvgNodeHandle* docHandle, const L_SvgLoadOptions* options); // 'docHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgFlatDocument(const L_SvgNodeHandle docHandle, L_SvgNodeHandle* flatDocHandle, const L_SvgFlatOptions* options); // 'flatDocHandle' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgIsFlatDocument(const L_SvgNodeHandle docHandle, L_BOOL* isFlat);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetFlatDocument(L_SvgNodeHandle docHandle, L_BOOL flatDoc);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetDocumentVersion(const L_SvgNodeHandle docHandle, L_SvgVersion* version);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetDocumentVersion(L_SvgNodeHandle docHandle, L_SvgVersion version);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgAddElementIDs(L_SvgNodeHandle docHandle);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgCalculateBounds(L_SvgNodeHandle flatDocHandle, L_BOOL trimmed);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetBounds(const L_SvgNodeHandle flatDocHandle, L_SvgBounds* bounds, L_UINT structSize);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetBounds(L_SvgNodeHandle flatDocHandle, const L_SvgBounds* bounds);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgResizeDocument(L_SvgNodeHandle flatDocHandle, L_DOUBLE scaleFactor);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgBeginUpdateDocument(L_SvgNodeHandle docHandle);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEndUpdateDocument(L_SvgNodeHandle docHandle);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgSetFilterElementsCallback(L_SvgNodeHandle docHandle, L_SvgFilterElementsCallback callback, L_VOID* userData);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgInsertElementA(L_SvgNodeHandle node, const L_VOID* element, L_SvgElementType elementType, L_SvgInsertElementType insertType, L_SvgNodeHandle* insertedNode); // 'insertedNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgInsertUserElementA(L_SvgNodeHandle node, const L_CHAR* elementName, L_SvgInsertElementType insertType, L_SvgNodeHandle* insertedNode); // 'insertedNode' must be freed using L_SvgFreeNode
#if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgInsertElement(L_SvgNodeHandle node, const L_VOID* element, L_SvgElementType elementType, L_SvgInsertElementType insertType, L_SvgNodeHandle* insertedNode); // 'insertedNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgInsertUserElement(L_SvgNodeHandle node, const L_TCHAR* elementName, L_SvgInsertElementType insertType, L_SvgNodeHandle* insertedNode); // 'insertedNode' must be freed using L_SvgFreeNode
#else
#define L_SvgInsertElement L_SvgInsertElementA
#define L_SvgInsertUserElement L_SvgInsertUserElementA
#endif // #if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgRemoveElement(L_SvgNodeHandle node);

// XML Functions

L_LTSVG_API L_INT EXT_FUNCTION L_SvgSelectSingleNodeA(const L_SvgNodeHandle node, const L_CHAR* xpath, L_SvgNodeHandle* selectedNode); // 'selectedNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSelectNodesA(const L_SvgNodeHandle node, const L_CHAR* xpath, L_SvgElementsIterator* elementsIterator); // 'elementsIterator' must be freed using L_SvgFreeIterator
#if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSelectSingleNode(const L_SvgNodeHandle node, const L_TCHAR* xpath, L_SvgNodeHandle* selectedNode); // 'selectedNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSelectNodes(const L_SvgNodeHandle node, const L_TCHAR* xpath, L_SvgElementsIterator* elementsIterator); // 'elementsIterator' must be freed using L_SvgFreeIterator
#else
#define L_SvgSelectSingleNode L_SvgSelectSingleNodeA
#define L_SvgSelectNodes L_SvgSelectNodesA
#endif // #if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetParentNode(const L_SvgNodeHandle node, L_SvgNodeHandle* parentNode); // 'parentNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetFirstChildNode(const L_SvgNodeHandle node, L_SvgNodeHandle* childNode); // 'childNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetLastChildNode(const L_SvgNodeHandle node, L_SvgNodeHandle* childNode); // 'childNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetNextSiblingNode(const L_SvgNodeHandle node, L_SvgNodeHandle* siblingNode); // 'siblingNode' must be freed using L_SvgFreeNode
L_LTSVG_API L_INT EXT_FUNCTION L_SvgGetPreviousSiblingNode(const L_SvgNodeHandle node, L_SvgNodeHandle* siblingNode); // 'siblingNode' must be freed using L_SvgFreeNode

L_LTSVG_API L_INT EXT_FUNCTION L_SvgEnumerateElements(const L_SvgNodeHandle node, L_SvgEnumerateDirection direction, L_SvgEnumerateCallback callback, L_VOID* userData);

// Data URI
L_LTSVG_API L_INT EXT_FUNCTION L_SvgParseDataUriA(const L_CHAR* href, L_SvgDataUriA* dataUri, L_UINT structSize);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgDecodeDataUriToMemoryA(const L_SvgDataUriA* dataUri, L_UCHAR** buffer, L_UINT* bufferSize); // 'buffer' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgDecodeDataUriToFileA(const L_SvgDataUriA* dataUri, const L_CHAR* fileName);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEncodeDataUriFromMemoryA(const L_UCHAR* buffer, L_UINT bufferSize, L_CHAR** href, L_UINT* hrefSize); // 'href' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEncodeDataUriFromFileA(const L_CHAR* fileName, L_CHAR** href, L_UINT* hrefSize); // 'href' must be freed using L_SvgFreeMemory

#if defined(FOR_UNICODE)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgParseDataUri(const L_TCHAR* href, L_SvgDataUri* dataUri, L_UINT structSize);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgDecodeDataUriToMemory(const L_SvgDataUri* dataUri, L_UCHAR** buffer, L_UINT* bufferSize); // 'buffer' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgDecodeDataUriToFile(const L_SvgDataUri* dataUri, const L_TCHAR* fileName);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEncodeDataUriFromMemory(const L_UCHAR* buffer, L_UINT bufferSize, L_TCHAR** href, L_UINT* hrefSize); // 'href' must be freed using L_SvgFreeMemory
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEncodeDataUriFromFile(const L_TCHAR* fileName, L_TCHAR** href, L_UINT* hrefSize); // 'href' must be freed using L_SvgFreeMemory
#else
#define L_SvgParseDataUri L_SvgParseDataUriA
#define L_SvgDecodeDataUriToMemory L_SvgDecodeDataUriToMemoryA
#define L_SvgDecodeDataUriToFile L_SvgDecodeDataUriToFileA
#define L_SvgEncodeDataUriFromMemory L_SvgEncodeDataUriFromMemoryA
#define L_SvgEncodeDataUriFromFile L_SvgEncodeDataUriFromFileA
#endif

#if defined(FOR_WINDOWS)
L_LTSVG_API L_INT EXT_FUNCTION L_SvgRenderDocument(L_HDC hdc, const L_SvgNodeHandle flatDocHandle, const L_SvgRenderOptions* options);
#endif // #if defined(FOR_WINDOWS)

L_LTSVG_API L_INT EXT_FUNCTION L_SvgRasterizeDocument(BITMAPHANDLE* bitmapHandle, const L_SvgNodeHandle flatDocHandle, const L_SvgRenderOptions* options);

L_LTSVG_API L_INT EXT_FUNCTION L_SvgBeginRenderOptimizeDocument(L_SvgNodeHandle flatDocHandle);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgEndRenderOptimizeDocument(L_SvgNodeHandle flatDocHandle);
L_LTSVG_API L_BOOL EXT_FUNCTION L_SvgIsRenderOptimizedDocument(const L_SvgNodeHandle flatDocHandle);

// Sort
typedef L_INT (pEXT_CALLBACK L_SvgSortElementsCallbackA)(const L_SvgNodeHandle flatDocHandle, const L_SvgElementInfoA* info, L_VOID* userData);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSortElementsA(const L_SvgNodeHandle flatDocHandle, const L_SvgSortOptions* options, L_SvgSortElementsCallbackA callback, L_VOID* userData);
#if defined(FOR_UNICODE)
typedef L_INT (pEXT_CALLBACK L_SvgSortElementsCallback)(const L_SvgNodeHandle flatDocHandle, const L_SvgElementInfo* info, L_VOID* userData);
L_LTSVG_API L_INT EXT_FUNCTION L_SvgSortElements(const L_SvgNodeHandle flatDocHandle, const L_SvgSortOptions* options, L_SvgSortElementsCallback callback, L_VOID* userData);
#else
#define L_SvgSortElementsCallback L_SvgSortElementsCallbackA
#define L_SvgSortElements L_SvgSortElementsA
#endif // #if defined(FOR_UNICODE)

L_LTSVG_API L_INT EXT_FUNCTION L_SvgApplyViewPerspective(L_SvgNodeHandle* flatDocHandle, L_INT viewPerspective, L_BOOL apply);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTSVG_H)
