//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTVKRN_H)
#define LTVKRN_H

#include "lttyp.h"

#define L_LVKRN_API LT_EXPORTED

#define L_HEADER_ENTRY
#include "ltpck.h"

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Definitions.                                                         []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/

#if !defined(FOR_WINDOWS) && !defined(FOR_UWP)
   typedef L_VOID* L_VECTOR_WND;

   // Pen Styles
#  define PS_SOLID            0
#  define PS_DASH             1
#  define PS_DOT              2
#  define PS_DASHDOT          3
#  define PS_DASHDOTDOT       4
#  define PS_NULL             5
#  define PS_INSIDEFRAME      6
#  define PS_USERSTYLE        7
#  define PS_ALTERNATE        8
#  define PS_COSMETIC         0x00000000
#  define PS_GEOMETRIC        0x00010000
#  define PS_STYLE_MASK       0x0000000F

   // Brush Styles
#  define BS_SOLID            0
#  define BS_NULL             1
#  define BS_HOLLOW           BS_NULL
#  define BS_HATCHED          2
#  define BS_PATTERN          3
//#  define BS_INDEXED          4
//#  define BS_DIBPATTERN       5
//#  define BS_DIBPATTERNPT     6
//#  define BS_PATTERN8X8       7
//#  define BS_DIBPATTERN8X8    8
//#  define BS_MONOPATTERN      9

   // Hatch Styles
#  define HS_HORIZONTAL       0
#  define HS_VERTICAL         1
#  define HS_FDIAGONAL        2
#  define HS_BDIAGONAL        3
#  define HS_CROSS            4
#  define HS_DIAGCROSS        5
//#  define HS_API_MAX          12

   // PolyDraw and GetPath point types
#  define PT_CLOSEFIGURE      0x01
#  define PT_LINETO           0x02
#  define PT_BEZIERTO         0x04
#  define PT_MOVETO           0x06

   // Binary raster ops
#  define R2_COPYPEN          13 

   // Ternary raster operations
#  define SRCCOPY             (L_UINT)0x00CC0020
#  define SRCPAINT            (L_UINT)0x00EE0086
#  define SRCAND              (L_UINT)0x008800C6
#  define SRCINVERT           (L_UINT)0x00660046
#  define SRCERASE            (L_UINT)0x00440328
#  define NOTSRCCOPY          (L_UINT)0x00330008
#  define NOTSRCERASE         (L_UINT)0x001100A6
#  define MERGECOPY           (L_UINT)0x00C000CA
#  define MERGEPAINT          (L_UINT)0x00BB0226
#  define PATCOPY             (L_UINT)0x00F00021
#  define PATPAINT            (L_UINT)0x00FB0A09
#  define PATINVERT           (L_UINT)0x005A0049
#  define DSTINVERT           (L_UINT)0x00550009
#  define BLACKNESS           (L_UINT)0x00000042
#  define WHITENESS           (L_UINT)0x00FF0062

#  define FW_DONTCARE         0
//#  define FW_THIN             100
//#  define FW_EXTRALIGHT       200
//#  define FW_LIGHT            300
//#  define FW_NORMAL           400
//#  define FW_MEDIUM           500
//#  define FW_SEMIBOLD         600
#  define FW_BOLD             700
//#  define FW_EXTRABOLD        800
//#  define FW_HEAVY            900

#else
   typedef L_HWND L_VECTOR_WND;
#endif // #if !defined(FOR_WINDOWS) && !defined(FOR_UWP)

// View mode.
#define VECTOR_VIEWMODE_FIT                  (0)
#define VECTOR_VIEWMODE_SNAP                 (1)


// Vertices bind mode.
#define VECTOR_BIND_VERTICES                 (0)         // Bind vertices.
#define VECTOR_UNBIND_VERTICES               (1)         // Unbind vertices.


// Engine flags.
#define VECTOR_ENGINE_DOUBLEBUFFER           (1)         // User double buffering.


#define VECTOR_MAX_NAME                      (64)        // Maximum size of a name string buffer.

#define VECTOR_PAINT_ERASEBKGND              (1)         // Paint flags

#define VECTOR_OBJECT_SELECTED               (1)
#define VECTOR_OBJECT_HIDDEN                 (2)
#define VECTOR_OBJECT_COMPOSITE              (4)
#define VECTOR_OBJECT_2STAGE_RENDERING       (8)         // This flag applies only to VECTORCIRCLE, VECTORELLIPSE,
                                                         // VECTORPIE, VECTORTEXT and VECTORPOLYDRAW
#define VECTOR_OBJECT_CLIP                   (16)        

// Polydraw flags 
#define VECTOR_POLYDRAW_FILL_WINDING          (0)
#define VECTOR_POLYDRAW_FILL_ALTERNATE        (32)

//Spline flags
#define VECTOR_SPLINE_FITPOINTS                (0)
#define VECTOR_SPLINE_CONTROLPOINTS            (32)

//Custom Hatch Flags
#define HATCH_BRUSH_CUSTOM_CLOSED              (0)
#define HATCH_BRUSH_CUSTOM_OPEN                (32)


// Object types.
#define VECTOR_OBJECT                        (0)
#define VECTOR_VERTEX                        (1)         // 3D vertex in space.
#define VECTOR_LINE                          (2)         // Line.
#define VECTOR_RECTANGLE                     (3)         // Rectangle.
#define VECTOR_POLYLINE                      (4)         // Polyline.
#define VECTOR_POLYBEZIER                    (5)         // Poly Bezier curve
#define VECTOR_POLYGON                       (6)         // Multi-sided polygon.
#define VECTOR_ELLIPSE                       (7)         // Ellipse.
#define VECTOR_CIRCLE                        (8)         // Circle.
#define VECTOR_ARC                           (9)         // Arc.
#define VECTOR_ELLIPTICALARC                 (10)        // Elliptical arc.
#define VECTOR_PIE                           (11)        // Pie.
#define VECTOR_CHORD                         (12)        // Chord.
#define VECTOR_POLYDRAW                      (13)        // Polydraw.
#define VECTOR_TEXT                          (14)        // Text.
#define VECTOR_RASTER                        (15)        // Raster.
#define VECTOR_STOCK                         (16)        // Stock object from a library.
#define VECTOR_CLONE                         (17)        // Group clone.
#define VECTOR_HPOLYBEZIER                   (18)        // Heterogeneous poly bezier
#define VECTOR_SPLINE                        (19)        // Spline Curve.


// Copy operation flags.
#define VECTOR_FLAGS_SELECTED_ONLY           (1)
#define VECTOR_FLAGS_REPLACE                 (2)
#define VECTOR_FLAGS_RENAME_DUPLICATES       (4)
#define VECTOR_FLAGS_COPY_INTO_ACTIVE_LAYER  (64)
#define VECTOR_FLAGS_COPY_LAYERS_ONLY        (128)
#define VECTOR_FLAGS_ADD_UNDO_NODE           (256)
#define VECTOR_FLAGS_TRANSFORMED             (512)
#define VECTOR_FLAGS_EXPLODE_TO_LINES        (1024)


// Polygon settings flags.
#define VECTOR_POLYGON_POINT                 (0)         // Draw as points..
#define VECTOR_POLYGON_LINE                  (1)         // Draw as wire frame.
#define VECTOR_POLYGON_FILL                  (2)         // Draw solid polygons.
#define VECTOR_POLYGON_FILL_RASTER_ALWAYS    (3)         // Solid polygons and always draw raster objects.


// Hit test options
#define VECTOR_HITTEST_CLOSEDFIGURES         (1)         // Check if hit test point is inside closed objects.
#define VECTOR_HITTEST_IGNORESELECTED        (2)         // Do not check for objects that are already selected.


// Marker options
#define VECTOR_MARKER_PEN_STYLE              (1)
#define VECTOR_MARKER_PEN_WIDTH              (2)
#define VECTOR_MARKER_PEN_COLOR              (4)
#define VECTOR_MARKER_BRUSH_STYLE            (8)
#define VECTOR_MARKER_BRUSH_COLOR            (16)


// Vector polygon fill modes
#define VECTOR_POLY_ALTERNATE                (ALTERNATE)
#define VECTOR_POLY_WINDING                  (WINDING)


// Text flags
#define VECTOR_TEXT_LEFT                     (0)
#define VECTOR_TEXT_RIGHT                    (1)
#define VECTOR_TEXT_HCENTER                  (2)
#define VECTOR_TEXT_TOP                      (0)
#define VECTOR_TEXT_BOTTOM                   (4)
#define VECTOR_TEXT_VCENTER                  (8)
#define VECTOR_TEXT_HITTESTRECT              (16)
#define VECTOR_TEXT_FORCECURVERENDERING      (32)
#define VECTOR_TEXT_MULTIBYTESTRING          (64)


// Polydraw types
#define VECTOR_PT_CLOSEFIGURE                (PT_CLOSEFIGURE)
#define VECTOR_PT_LINETO                     (PT_LINETO)
#define VECTOR_PT_BEZIERTO                   (PT_BEZIERTO)
#define VECTOR_PT_MOVETO                     (PT_MOVETO)

// Maximum object size.
#define VECTOR_OBJECT_BUFFER_SIZE            (sizeof(VECTORTEXT))//(sizeof(VECTORRASTER))

// raster object flags
#define VECTOR_OBJECT_ENABLE_TRANSPARENCY       (32) //currently works for png files 

// Clone flags
#define VECTOR_CLONE_USE_PEN                    (1)
#define VECTOR_CLONE_USE_BRUSH                  (2)
#define VECTOR_CLONE_USE_POINT_AS_ORIGIN        (4)
#define VECTOR_CLONE_USE_CHILDCLONE_ATTRIBUTES  (8)

// Clipping modes
#define VECTOR_CLIPMODE_COPY                 (RGN_COPY)
#define VECTOR_CLIPMODE_AND                  (RGN_AND)
#define VECTOR_CLIPMODE_DIFF                 (RGN_DIFF)
#define VECTOR_CLIPMODE_OR                   (RGN_OR)
#define VECTOR_CLIPMODE_XOR                  (RGN_XOR)

// Events
typedef enum
{
   VECTOR_EVENT_USER = 0,
   VECTOR_EVENT_RESERVED = 10000,

   VECTOR_EVENT_FREE,
   VECTOR_EVENT_EMPTY,
   VECTOR_EVENT_COPY,
   VECTOR_EVENT_VIEWPORT,
   VECTOR_EVENT_PAN,
   VECTOR_EVENT_LOCKED,
   VECTOR_EVENT_BACKGROUND,
   VECTOR_EVENT_PALETTE,
   VECTOR_EVENT_VIEWMODE,

   VECTOR_EVENT_TRANSLATION,
   VECTOR_EVENT_ROTATION,
   VECTOR_EVENT_SCALE,
   VECTOR_EVENT_ORIGIN,
   VECTOR_EVENT_APPLYTRANSFORMATION,
   VECTOR_EVENT_ZOOMRECT,

   VECTOR_EVENT_BINDVERTICESMODE,
   VECTOR_EVENT_PARALLELOGRAM,

   VECTOR_EVENT_CAMERA,

   VECTOR_EVENT_METAFILE,

   VECTOR_EVENT_ATTACHTOWINDOW,

   VECTOR_EVENT_MARKER,

   VECTOR_EVENT_UNIT,         /* Reserved for internal use */

   VECTOR_EVENT_HITTEST,

   VECTOR_EVENT_POLYGONMODE,

   VECTOR_EVENT_COPYFROMCLIPBOARD,

   VECTOR_EVENT_ADDLAYER,
   VECTOR_EVENT_DELETELAYER,
   VECTOR_EVENT_EMPTYLAYER,
   VECTOR_EVENT_COPYLAYER,
   VECTOR_EVENT_SETLAYER,
   VECTOR_EVENT_SETACTIVELAYER,

   VECTOR_EVENT_ADDGROUP,
   VECTOR_EVENT_DELETEGROUP,
   VECTOR_EVENT_DELETEGROUPCLONES,
   VECTOR_EVENT_EMPTYGROUP,
   VECTOR_EVENT_COPYGROUP,
   VECTOR_EVENT_SETGROUP,

   VECTOR_EVENT_ADDOBJECT,
   VECTOR_EVENT_DELETEOBJECT,
   VECTOR_EVENT_COPYOBJECT,
   VECTOR_EVENT_SETOBJECT,
   VECTOR_EVENT_EXPLODEOBJECT,
   VECTOR_EVENT_SELECTOBJECT,
   VECTOR_EVENT_HIDEOBJECT,
   VECTOR_EVENT_OBJECTATTRIBUTES,
   VECTOR_EVENT_ADDOBJECTTOGROUP,

   VECTOR_EVENT_DUMPLOADVECTOR,

   VECTOR_EVENT_LOADFILE, 

   VECTOR_EVENT_CREATENEWWINDOW,

   VECTOR_EVENT_INVERTCOLORS
}
VECTOR_EVENT, *pVECTOR_EVENT;


// Event status
typedef enum
{
   VECTOR_EVENT_STATUS_BEFORE,
   VECTOR_EVENT_STATUS_AFTER
}
VECTOR_EVENT_STATUS, *pVECTOR_EVENT_STATUS;

/* Reserved for internal use */
// Units
typedef enum
{
   VECTOR_UNIT_INCHES,
   VECTOR_UNIT_FEET,
   VECTOR_UNIT_YARDS,
   VECTOR_UNIT_MILES,
   VECTOR_UNIT_MICROMETERS,
   VECTOR_UNIT_MILIMETERS,
   VECTOR_UNIT_CENTIMETERS,
   VECTOR_UNIT_METERS,
   VECTOR_UNIT_KILOMETERS,
   VECTOR_UNIT_TWIPS,
   VECTOR_UNIT_POINTS,
   VECTOR_UNIT_PIXELS,
   VECTOR_UNIT_DUMMY = -1
}
VECTOR_UNIT;


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Data structures.                                                     []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/

// VECTORARRAY: Generic array.
typedef struct _VECTORARRAY
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_INT                   nCount;                    // Number of elements in the array (Including deleted items).
   L_INT                   nActualCount;              // Number of elements in the array (Not including deleted items).
   L_UINT                  uTotalCount;               // Total items count (actual + free).
   L_INT                   nLastDeletedItem;          // Last deleted item.
   L_UINT32                dwDeleted;                 // Deleted item signature.
   L_UINT                  uMaxItemSize;              // Maximum item size in bytes. The array can have different items, this holds the size of the maximum one.
   L_UINT                  uIncCount;                 // Increment count. Number of items to be allocated when the array is filled and a new item is to be added.
   L_CHAR                 *pBuffer;                   // Memory buffer for holding actual array items.
}
VECTORARRAY, *pVECTORARRAY;


// VECTORPOINT: Holds a 3D point in space.
typedef struct _VECTORPOINT
{
   L_DOUBLE                x;                         // x-component.
   L_DOUBLE                y;                         // y-component.
   L_DOUBLE                z;                         // z-component.
   L_INT32                 lTag;                      // User-defined data.
}
VECTORPOINT, *pVECTORPOINT;

// Text rendering options.
typedef enum _VECTOR_TEXTRENDER
{
   VECTOR_TEXTRENDER_ASTEXT = 0,                      // try always to render the text as text object 
   VECTOR_TEXTRENDER_ASCURVES                         // render the text always as curves and lines 

}VECTOR_TEXTRENDER, *pVECTOR_TEXTRENDER;

// Anti-aliasing.
typedef struct _VECTOR_ANTIALIASING
{
   L_UINT   uThreshold;                              // which pixels to smooth, pixels with value above this is smoothed
                                                     // set to zero to prevent Anti-aliasing.
   L_UINT   uDim;                                    // dimension of the anti-aliasing mask ... 3 means 3X3
   L_UINT   uFilter;                                 // type of anti-aliasing ... see L_AntiAliasBitmap for values.

}VECTOR_ANTIALIASING, *pVECTOR_ANTIALIASING;

// VECTOR Display options.
typedef struct _VECTOR_DISPLAY_OPTIONS
{
   VECTOR_TEXTRENDER   TextRender;                  // text rendering options.
   VECTOR_ANTIALIASING AntiAliasing;                // anti-aliasing settings
   L_INT               nClipMode;                   // Clipping mode.
   
   L_SIZE_T            dwReserved;                  // must be zero. 

}VECTOR_DISPLAY_OPTIONS, *pVECTOR_DISPLAY_OPTIONS;


// VECTORPEN: Pen.
typedef struct _VECTORPEN
{
   L_INT       nSize;                     // Size of this structure. Used for versioning.
   union
   {
      LOGPEN                  LogPen;                 // Windows LOGPEN structure defining the pen properties.
      EXTLOGPEN               ExtLogPen;              // Windows EXTLOGPEN structure defining the pen properties.

   }NewPen;
   DWORD       elpStyleEntry[7];
   L_BOOL      bExtPen;                  //If False LogPen 
   
}VECTORPEN, *pVECTORPEN;

typedef struct _VECTORPARALLELOGRAM
{
   L_UINT uStructSize;
   VECTORPOINT Min;
   VECTORPOINT Max;
   VECTOR_UNIT Unit;
}VECTORPARALLELOGRAM, *pVECTORPARALLELOGRAM;

typedef enum _VECTORVIEWMODE
{
   VECTORVIEWMODE_USE_BEST = 0,
   VECTORVIEWMODE_USE_WIDTH_HEIGHT,
   VECTORVIEWMODE_USE_WIDTH,
   VECTORVIEWMODE_USE_HEIGHT
} VECTORVIEWMODE, *pVECTORVIEWMODE;

typedef struct _VEC2DOPTIONS
{
   L_UINT uStructSize;
   L_INT nViewWidth;
   L_INT nViewHeight;
   VECTORVIEWMODE ViewMode;
} VEC2DOPTIONS, *pVEC2OPTIONS;



/////////////////////////////////////////////////////////////////////////

typedef enum _VECTORBRUSHSTYLE
{
   VECTORBRUSH_STANDARD=0,
   VECTORBRUSH_PATTERN,
   VECTORBRUSH_GRADIENT,
   VECTORBRUSH_HATCH,
}
VECTORBRUSHSTYLE, *pVECTORBRUSHSTYLE;

typedef enum _HATCHBRUSHSTYLE
{
   HATCH_NONE=0,
   HATCH_RECTANGLE,
   HATCH_CIRCLE,
   HATCH_TRIANGLE,
   HATCH_LINE,
   HATCH_CUSTOM
   
}
HATCHBRUSHSTYLE, *pHATCHBRUSHSTYLE;


typedef enum _GRADIENTBRUSHSTYLE
{
   // Linear   
   GRADIENT_LINE_L_TO_R=0,
   GRADIENT_LINE_R_TO_L,         
   GRADIENT_LINE_T_TO_B,         
   GRADIENT_LINE_B_TO_T,         
   GRADIENT_LINE_LT_TO_RB,       
   GRADIENT_LINE_LB_TO_RT,       
   GRADIENT_LINE_RT_TO_LB,       
   GRADIENT_LINE_RB_TO_LT,       
   GRADIENT_LINE2_L_AND_R_TO_C,  
   GRADIENT_LINE2_C_TO_L_AND_R,  
   GRADIENT_LINE2_T_AND_B_TO_C,  
   GRADIENT_LINE2_C_TO_T_AND_B,  
   GRADIENT_LINE2_LT_AND_RB_TO_C,
   GRADIENT_LINE2_C_TO_LT_AND_RB,
   GRADIENT_LINE2_RT_AND_LB_TO_C,
   GRADIENT_LINE2_C_TO_RT_AND_LB,
   GRADIENT_LINE_MAX,   
   
   // Angular      
   GRADIENT_ANGLE_TO_LT,         
   GRADIENT_ANGLE_TO_LB,         
   GRADIENT_ANGLE_TO_RT,         
   GRADIENT_ANGLE_TO_RB,         
   GRADIENT_ANGLE_FROM_LT,       
   GRADIENT_ANGLE_FROM_LB,       
   GRADIENT_ANGLE_FROM_RT,       
   GRADIENT_ANGLE_FROM_RB,    
   GRADIENT_ANGLE_MAX,
   
   
   // Rectangular      
   GRADIENT_RECTANGLE_TO_C,      
   GRADIENT_RECTANGLE_FROM_C,    
   GRADIENT_RECTANGLE_MAX,
   
   
   // Elliptical      
   GRADIENT_ELLIPSE_TO_C,        
   GRADIENT_ELLIPSE_FROM_C, 
   GRADIENT_ELLIPSE_MAX,
   
   
   // Conical      
   GRADIENT_CONE_FROM_L,         
   GRADIENT_CONE_FROM_R,         
   GRADIENT_CONE_FROM_T,         
   GRADIENT_CONE_FROM_B,         
   GRADIENT_CONE_FROM_LT,        
   GRADIENT_CONE_FROM_LB,        
   GRADIENT_CONE_FROM_RT,        
   GRADIENT_CONE_FROM_RB,
   GRADIENT_CONE_MAX,
}
GRADIENTBRUSHSTYLE, *pGRADIENTBRUSHSTYLE;


typedef struct _STANDARDBRUSH
{
   LOGBRUSH                LogBrush;                  // Windows LOGBRUSH structure defining the brush properties.
}
STANDARDBRUSH, *pSTANDARDBRUSH;


typedef struct _HATCHBRUSH
{
   HATCHBRUSHSTYLE         HatchBrushStyle;
   LOGPEN                  LogPen;                    // Windows LOGPEN structure defining the pen properties.
   LOGBRUSH                LogBrush;                  // Windows LOGBRUSH structure defining the brush properties.
   L_INT                   nStepSize;
   L_DOUBLE                dLineRotAngle; 
   L_UINT32                dwFlags;
   L_INT                   nPointCount;
   L_POINT*                pEntryPoints;
}
HATCHBRUSH, *pHATCHBRUSH;

typedef struct _PATTERNBRUSH
{
   BITMAPHANDLE PtrnBitmap;
}
PATTERNBRUSH, *pPATTERNBRUSH;

typedef struct _GRADIENTBRUSH
{
   L_COLORREF            crStartColor;
   L_COLORREF            crEndColor;
   L_INT                 uGradientSteps;
   GRADIENTBRUSHSTYLE    GradientStyle;
}
GRADIENTBRUSH, *pGRADIENTBRUSH;

typedef struct _VECTORBRUSH
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.  
   VECTORBRUSHSTYLE        VectorBrushStyle;
   union
   {
      STANDARDBRUSH           StandardBrush;
      HATCHBRUSH              HatchBrush;
      PATTERNBRUSH            PatternBrush;
      GRADIENTBRUSH           GradientBrush;
   }BrushType;
}
VECTORBRUSH, *pVECTORBRUSH;

// VECTORFONT: Font.
typedef struct _VECTORFONTA
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   LOGFONTA                LogFont;                   // Windows LOGFONT structure defining the font properties.
}
VECTORFONTA, *pVECTORFONTA;

#if defined(FOR_UNICODE)
typedef struct _VECTORFONT
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   LOGFONTW                LogFont;                   // Windows LOGFONT structure defining the font properties.
}
VECTORFONT, *pVECTORFONT;
#else
typedef VECTORFONTA VECTORFONT;
typedef pVECTORFONTA pVECTORFONT;
#endif //#if defined(FOR_UNICODE)


// VECTORBITMAP
typedef struct _VECTORBITMAP
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   BITMAPHANDLE            Bitmap;                    // LEAD bitmap handle.
}
VECTORBITMAP, *pVECTORBITMAP;

// VECTORATTRIBUTES: Stores objects, points, pens, brushes, fonts and bitmap in one location.
typedef struct _VECTORATTRIBUTES
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   VECTORPOINT             Min;                       // Minimum point.
   VECTORPOINT             Max;                       // Maximum point.
   VECTORPOINT             Origin;                    // Origin of current points.
   VECTORARRAY             aPoints;                   // Array of VECTORPOINT's.
   VECTORARRAY             aPens;                     // Array of VECTORPEN's.
   VECTORARRAY             aBrushes;                  // Array of VECTORBRUSH's.
   VECTORARRAY             aFonts;                    // Array of VECTORFONT's.
   VECTORARRAY             aBitmaps;                  // Array of VECTORBITMAP's.
}
VECTORATTRIBUTES, *pVECTORATTRIBUTES;


// VECTORTRANSFORMATION: A place to hold all transformation variables.
typedef struct _VECTORTRANSFORMATION
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   VECTORPOINT             Scale;                     // Scale factors. 1.0 = 100%.
   VECTORPOINT             Rotation;                  // Rotation angles. x, y and z represent the rotation angles around the axes in degrees.
   VECTORPOINT             Translation;               // Translation values. x, y and z represent the translation values along the axes in logical units.
}
VECTORTRANSFORMATION, *pVECTORTRANSFORMATION;


// VECTORCAMERA: Holds all data needed for a 3D-camera object.
typedef struct _VECTORCAMERA
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_DOUBLE                Theta;                     // Rotation angle around the Z-axis.
   L_DOUBLE                Phi;                       // Rotation angle off the Z-axis.
   VECTORPOINT             LookAt;                    // Look at.
   L_DOUBLE                Distance;                  // Distance.
   L_BOOL                  bPerspective;              // Use perspective projection?
}
VECTORCAMERA, *pVECTORCAMERA;


// VECTORMARKER: Holds all data needed for a marker.
typedef struct _VECTORMARKER
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_UINT32                dwFlags;
   VECTORPEN               Pen;
   VECTORBRUSH             Brush;
}
VECTORMARKER, *pVECTORMARKER;


/* Reserved for internal use */
// VECTORUNIT
typedef struct _VECTORUNIT
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   VECTOR_UNIT             Unit;                      // One of the VECTOR_UNIT_XXX types   
}
VECTORUNIT, *pVECTORUNIT;


// VECTORHITTEST: Holds all vector test settings.
typedef struct _VECTORHITTEST
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_INT                   nDistance;                 // Distance from left and right of point in pixels.
   L_UINT32                dwFlags;                   // Flags, see VECTOR_HITTEST_XXX
}
VECTORHITTEST, *pVECTORHITTEST;


// VECTORLAYER: Defines a layer.
typedef struct _VECTORLAYER
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_INT                   nId;                       // Layer Id.
}
VECTORLAYER, *pVECTORLAYER;

// VECTORLAYERDESC:
typedef struct _VECTORLAYERDESCA
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_CHAR                  szName[ VECTOR_MAX_NAME ]; // Layer name.
   L_BOOL                  bVisible;                  // Visibility.
   L_BOOL                  bLocked;                   // Locked.
   L_SIZE_T                dwTag;                     // User-defined tag.
}
VECTORLAYERDESCA, *pVECTORLAYERDESCA;

#if defined(FOR_UNICODE)
// VECTORLAYERDESC:
typedef struct _VECTORLAYERDESC
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_TCHAR                 szName[ VECTOR_MAX_NAME ]; // Layer name.
   L_BOOL                  bVisible;                  // Visibility.
   L_BOOL                  bLocked;                   // Locked.
   L_SIZE_T                dwTag;                     // User-defined tag.
}
VECTORLAYERDESC, *pVECTORLAYERDESC;
#else
typedef VECTORLAYERDESCA VECTORLAYERDESC;
typedef pVECTORLAYERDESCA pVECTORLAYERDESC;
#endif // #if defined(FOR_UNICODE)

// VECTORGROUP: Defines a group
typedef struct _VECTORGROUP
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_INT                   nId;                       // Group Id.
}
VECTORGROUP, *pVECTORGROUP;


// VECTORGROUPDESC:
typedef struct _VECTORGROUPDESCA
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_CHAR                  szName[ VECTOR_MAX_NAME ]; // Group name.
   L_SIZE_T                dwTag;                     // User-defined tag.
}
VECTORGROUPDESCA, *pVECTORGROUPDESCA;

#if defined(FOR_UNICODE)
// VECTORGROUPDESC:
typedef struct _VECTORGROUPDESC
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_TCHAR                 szName[ VECTOR_MAX_NAME ]; // Group name.
   L_SIZE_T                dwTag;                     // User-defined tag.
}
VECTORGROUPDESC, *pVECTORGROUPDESC;
#else
typedef VECTORGROUPDESCA VECTORGROUPDESC;
typedef pVECTORGROUPDESCA pVECTORGROUPDESC;
#endif // #if defined(FOR_UNICODE)


// VECTOROBJECT: Defines a single vector object.
typedef struct _VECTOROBJECT
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_INT                   nType;                     // Type of this object.
   L_INT                   nId;                       // Object ID.
   L_INT                   nLayerId;                  // Layer ID.
   L_INT                   nGroupId;                  // Group ID.
   L_INT                   nROP;                      // Object's ROP mode.
   DWORD                   dwFlags;                   // Flags
   DWORD                   dwTag;                     // User-defined tag.   
}
VECTOROBJECT, *pVECTOROBJECT;

// VECTORTOOLTIPDESC: specifies how the toolkit should display a tooltip 
typedef struct _VECTORTOOLTIPDESCA
{
   L_POINT      Point;
   LOGPEN       Pen;
   LOGBRUSH     Brush;
   LOGFONTA     Font;

}VECTORTOOLTIPDESCA, *pVECTORTOOLTIPDESCA;

#if defined(FOR_UNICODE)
typedef struct _VECTORTOOLTIPDESC
{
   L_POINT      Point;
   LOGPEN       Pen;
   LOGBRUSH     Brush;
   LOGFONTW     Font;

}VECTORTOOLTIPDESC, *pVECTORTOOLTIPDESC;
#else
typedef VECTORTOOLTIPDESCA VECTORTOOLTIPDESC;
typedef pVECTORTOOLTIPDESCA pVECTORTOOLTIPDESC;
#endif // #if defined(FOR_UNICODE)
// VECTORTOOLTIPDESC: specifies how the toolkit should handle a click on a link-object.
typedef enum _VECTORLINKHANDLING
{
   VECTORLINKHANDLING_CURRENTWINDOW = 0,          // open in new window
   VECTORLINKHANDLING_NEWWINDOW                   // open in the current window

}VECTORLINKHANDLING, *pVECTORLINKHANDLING;

// VECTORLINKFILEINFO: specifies the target file of an object with a hyperlink
typedef struct _VECTORLINKFILEINFOA
{
   L_CHAR szPath[ L_MAXPATH ];                    // path to the file
   
}VECTORLINKFILEINFOA, *pVECTORLINKFILEINFOA;

#if defined(FOR_UNICODE)
// VECTORLINKFILEINFO: specifies the target file of an object with a hyperlink
typedef struct _VECTORLINKFILEINFO
{
   L_TCHAR szPath[ L_MAXPATH ];                    // path to the file
   
}VECTORLINKFILEINFO, *pVECTORLINKFILEINFO;
#else
typedef VECTORLINKFILEINFOA VECTORLINKFILEINFO;
typedef pVECTORLINKFILEINFOA pVECTORLINKFILEINFO;
#endif // #if defined(FOR_UNICODE)

// VECTORLINKDESC: specifies the target of a hyperlink
typedef struct _VECTORLINKDESCA
{
   L_BOOL bObject;                               // L_TRUE means the link points to a vector object 

   union
   {
      struct 
      {
         VECTOROBJECT       target;               // the target object if bObject is L_TRUE
         VECTORLINKHANDLING handling;             // specifies how the toolkit will handle link activation         

      }vectorobject;

      struct 
      {
         VECTORLINKFILEINFOA target;               // information about the target file if bObject is L_FALSE
         L_VECTOR_WND hwndParent;                         // Parent window if ( handling ) is VECTORLINKHANDLING_NEWWINDOW or if target is a file
      }fileobject;

   }tar;

}VECTORLINKDESCA, *pVECTORLINKDESCA;

#if defined(FOR_UNICODE)
typedef struct _VECTORLINKDESC
{
   L_BOOL bObject;                               // L_TRUE means the link points to a vector object 

   union
   {
      struct 
      {
         VECTOROBJECT       target;               // the target object if bObject is L_TRUE
         VECTORLINKHANDLING handling;             // specifies how the toolkit will handle link activation         

      }vectorobject;

      struct 
      {
         VECTORLINKFILEINFO target;               // information about the target file if bObject is L_FALSE
         L_VECTOR_WND hwndParent;                         // Parent window if ( handling ) is VECTORLINKHANDLING_NEWWINDOW or if target is a file
      }fileobject;

   }tar;

}VECTORLINKDESC, *pVECTORLINKDESC;
#else
typedef VECTORLINKDESCA VECTORLINKDESC;
typedef pVECTORLINKDESCA pVECTORLINKDESC;
#endif // #if defined(FOR_UNICODE)
// VECTOREVENT
typedef struct _VECTOREVENTA
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_UINT                  uType;                     // Event type (One of VECTOR_EVENT_XXX)
   VECTOR_EVENT_STATUS     Status;                    // Status (before or after)
   L_INT                   nErrorCode;                // One of the Error Codes.
   pVECTOROBJECT           pObject;                   // The vector object
   L_VOID *                pObjectDesc;               // Object descriptor.
   pVECTORLAYER            pLayer;                    // The vector layer.
   pVECTORLAYERDESCA       pLayerDesc;                // Layer descriptor
   pVECTORGROUP            pGroup;                    // The vector group.
   pVECTORGROUPDESCA       pGroupDesc;                // Group descriptor.
   pVECTORPOINT            pPoint1;                   // General point 1
   pVECTORPOINT            pPoint2;                   // General point 2
   L_UINT32                dwFlags;                   // Flags
   L_VOID *                pUserData;                 // User data.
}
VECTOREVENTA, *pVECTOREVENTA;

#if defined(FOR_UNICODE)
// VECTOREVENT
typedef struct _VECTOREVENT
{
   L_INT                   nSize;                     // Size of this structure. Used for versioning.
   L_UINT                  uType;                     // Event type (One of VECTOR_EVENT_XXX)
   VECTOR_EVENT_STATUS     Status;                    // Status (before or after)
   L_INT                   nErrorCode;                // One of the Error Codes.
   pVECTOROBJECT           pObject;                   // The vector object
   L_VOID *                pObjectDesc;               // Object descriptor.
   pVECTORLAYER            pLayer;                    // The vector layer.
   pVECTORLAYERDESC        pLayerDesc;                // Layer descriptor
   pVECTORGROUP            pGroup;                    // The vector group.
   pVECTORGROUPDESC        pGroupDesc;                // Group descriptor.
   pVECTORPOINT            pPoint1;                   // General point 1
   pVECTORPOINT            pPoint2;                   // General point 2
   L_UINT32                dwFlags;                   // Flags
   L_VOID *                pUserData;                 // User data.
}
VECTOREVENT, *pVECTOREVENT;
#else
typedef VECTOREVENTA VECTOREVENT;
typedef pVECTOREVENTA pVECTOREVENT;
#endif // #if defined(FOR_UNICODE)

typedef struct _VECTORHANDLE *pVECTORHANDLE;

typedef L_INT ( pEXT_CALLBACK pVECTOREVENTPROCA)( pVECTORHANDLE pVector, L_UINT uLevel, pVECTOREVENTA pEvent, L_VOID *pUserData );
#if defined(FOR_UNICODE)
   typedef L_INT ( pEXT_CALLBACK pVECTOREVENTPROC )( pVECTORHANDLE pVector, L_UINT uLevel, pVECTOREVENT pEvent, L_VOID *pUserData );
#else
   typedef pVECTOREVENTPROCA pVECTOREVENTPROC;
#endif // #if defined(FOR_UNICODE)

typedef pVECTOREVENTPROC *ppVECTOREVENTPROC;
typedef pVECTOREVENTPROCA *ppVECTOREVENTPROCA;

//Font Substitution Callback
typedef L_INT (pEXT_CALLBACK pVECTORFONTMAPPERCALLBACKA)(pVECTORHANDLE pVector, LPLOGFONTA pLogFont, L_VOID* pUserData);

#if defined(FOR_UNICODE)
   typedef L_INT (pEXT_CALLBACK pVECTORFONTMAPPERCALLBACK)(pVECTORHANDLE pVector, LPLOGFONTW pLogFont, L_VOID* pUserData);
#else
   typedef pVECTORFONTMAPPERCALLBACKA pVECTORFONTMAPPERCALLBACK; 
#endif // #if defined(FOR_UNICODE)

// VECTORHANDLE: Vector handle.
typedef struct _VECTORHANDLE
{
   L_INT                       nSize;                     // Size of this structure. Used for versioning.
   L_UINT32                    dwInit;                    // Reserved for internal use.
   L_BOOL                      bLocked;                   // If L_TRUE vector handle cannot be edited.
   L_INT                       nBindVerticesMode;         // Bind vertices mode.
   L_RECT                      rcViewport;                // Current viewport.
   L_POINT                     ptPan;                     // Current physical pan value.
   L_COLORREF                  clrBackground;             // Background color.
   L_INT                       nActiveLayer;              // Current active layer.
   VECTORTRANSFORMATION        Transformation;            // Transformation values.
   VECTORCAMERA                Camera;                    // Camera settings.
   VECTORMARKER                Marker;                    // Marker settings.
   VECTORUNIT                  Unit;                      // Unit settings. Reserved for internal use
   VECTORHITTEST               HitTest;                   // Hit test settings.
   L_INT                       nPolygonMode;              // Polygon view mode.
   L_UINT                      uViewMode;                 // View mode.
   VECTOR_DISPLAY_OPTIONS      DisplayOptions;            // Display options
   L_HPALETTE                  hPalette;                  // Palette handle   
   VECTORATTRIBUTES            Attributes;                // Attributes of this vector handle.
   L_UINT32                    dwFlags;                   // Flags. Reserved for internal use.
   VECTORARRAY                 aLayers;                   // Layers inside this vector handle.
   VECTORARRAY                 aGroups;                   // Groups inside this vector handle.
   VECTORARRAY                 aObjectsToBeDeleted;       // Objects to be deleted.
   L_VOID *                    pEngine;                   // Rendering engine.
   L_VOID *                    pEngineFast;               // Fast engine.
   L_INT                       nEvent;                    // Reserved for internal use.   
   pVECTOREVENTPROC            pEventProc;                // Reserved for internal use.
   L_VOID *                    pEventProcUserData;        // Reserved for internal use.
   pVECTORFONTMAPPERCALLBACK   pfnVectorFontMapperCallback;
   L_VOID *                    pFontMapperUserData;
}
VECTORHANDLE /*, *pVECTORHANDLE*/;

// VECTORVERTEX: 3D vertex in space
typedef struct _VECTORVERTEX
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Location.
   VECTORPEN               Pen;                       // Pen.
}
VECTORVERTEX, *pVECTORVERTEX;


// VECTORLINE: Line.
typedef struct _VECTORLINE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point[ 2 ];                // Start and end position.
   VECTORPEN               Pen;                       // Pen.
}
VECTORLINE, *pVECTORLINE;


// VECTORRECTANGLE: Rectangle.
typedef struct _VECTORRECTANGLE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point[ 2 ];                // Top left and bottom right positions.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
}
VECTORRECTANGLE, *pVECTORRECTANGLE;



// VECTORCURVEOPENED: Opened curve (VECTOR_POLYLINE, VECTOR_POLYBEZIER).
typedef struct _VECTORCURVEOPENED
{
   VECTOROBJECT            Object;
   VECTORPOINT *           Point;                     // Points.
   L_INT                   nPointCount;               // Number of points in array.
   VECTORPEN               Pen;                       // Pen.
}
VECTORCURVEOPENED, *pVECTORCURVEOPENED,
VECTORPOLYLINE,    *pVECTORPOLYLINE,
VECTORPOLYBEZIER,  *pVECTORPOLYBEZIER;


typedef struct _VECTORHPOLYBEZIER
{
   VECTOROBJECT            Object;
   VECTORPOINT *           Point;                     // Points.
   L_INT                   nSecCount;                 // Number Bezier sections.
   VECTORPEN               Pen;                       // Pen.
   L_UINT *                puDegree;                  // Bezier degree
}
VECTORHPOLYBEZIER,  *pVECTORHPOLYBEZIER;



typedef struct _VECTORPOLYBEZIERSPLINE
{
   VECTOROBJECT            Object;
   VECTORPOINT *           Point;                     // Points.
   L_INT                   nPointCount;               // Number of points in array.
   VECTORPEN               Pen;                       // Pen.
   L_UINT32                dwFlags;
}
VECTORSPLINE, *pVECTORSPLINE;


// VECTORCURVECLOSED: Closed curve (VECTOR_POLYGON).
typedef struct _VECTORCURVECLOSED
{
   VECTOROBJECT            Object;
   VECTORPOINT *           Point;                     // Points.
   L_INT                   nPointCount;               // Number of points in array.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   L_INT                   nPolyFillMode;             // Polygon fill mode (VECTOR_POLY_ALTERNATE or VECTOR_POLY_WINDING).
}
VECTORCURVECLOSED, *pVECTORCURVECLOSED,
VECTORPOLYGON, *pVECTORPOLYGON;


// VECTORELLIPSE: Ellipse (VECTOR_ELLIPSE).
typedef struct _VECTORELLIPSE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Center.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   L_DOUBLE                xRadius;                   // x-Radius.
   L_DOUBLE                yRadius;                   // y-Radius;
}
VECTORELLIPSE, *pVECTORELLIPSE;


// VECTORCIRCLE: Circle (VECTOR_CIRCLE).
typedef struct _VECTORCIRCLE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Center.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   L_DOUBLE                Radius;                    // Radius.
}
VECTORCIRCLE, *pVECTORCIRCLE;


// VECTORARC: Arc (VECTOR_ARC).
typedef struct _VECTORARC
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Center.
   VECTORPEN               Pen;                       // Pen.
   L_DOUBLE                Radius;                    // Radius.
   L_DOUBLE                StartAngle;                // Start angle in degrees.
   L_DOUBLE                SweepAngle;                // Sweep angle in degrees.
}
VECTORARC, *pVECTORARC;


// VECTORTEXT: Text (VECTOR_TEXT).
typedef struct _VECTORTEXTA
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Insertion point.
   L_CHAR *                pszText;                   // The text itself.
   L_UINT32                dwFlags;                   // Flags.
   L_DOUBLE                CharHeight;                // Height.
   L_DOUBLE                CharWidth;                 // Width.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   VECTORFONTA             Font;                      // Font.
}
VECTORTEXTA, *pVECTORTEXTA;

#if defined(FOR_UNICODE)
// VECTORTEXT: Text (VECTOR_TEXT).
typedef struct _VECTORTEXT
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Insertion point.
   L_TCHAR *               pszText;                   // The text itself.
   L_UINT32                dwFlags;                   // Flags.
   L_DOUBLE                CharHeight;                // Height.
   L_DOUBLE                CharWidth;                 // Width.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   VECTORFONT              Font;                      // Font.
}
VECTORTEXT, *pVECTORTEXT;
#else
typedef VECTORTEXTA VECTORTEXT;
typedef pVECTORTEXTA pVECTORTEXT;
#endif // #if defined(FOR_UNICODE)


// VECTORPIE and VECTORCHORD: Pie and chord section (VECTOR_PIE, VECTOR_CHORD).
typedef struct _VECTORPIE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Center.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
   L_DOUBLE                Radius;                    // Radius.
   L_DOUBLE                StartAngle;                // Start angle in degrees.
   L_DOUBLE                SweepAngle;                // Sweep angle in degrees.
}
VECTORPIE, *pVECTORPIE,
VECTORCHORD, *pVECTORCHORD;


// VECTORPOLYDRAW: Polydraw (VECTOR_POLYDRAW).
typedef struct _VECTORPOLYDRAW
{
   VECTOROBJECT            Object;
   VECTORPOINT *           Point;                     // Points array.
   L_INT                   nPointCount;               // Number of points in array.
   L_UCHAR *               pbyType;                   // Types.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
}
VECTORPOLYDRAW, *pVECTORPOLYDRAW;


// VECTORRASTER: Raster (VECTOR_RASTER)
typedef struct _VECTORRASTER
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point[ 2 ];                // Top left and bottom right positions.
   VECTORBITMAP            Bitmap;                    // Bitmap.
}
VECTORRASTER, *pVECTORRASTER;


// VECTORSTOCK: Stock object (VECTOR_STOCK)
typedef struct _VECTORSTOCK
{
   VECTOROBJECT            Object;
   L_INT                   nId;                       // Stock object ID in its DLL.
   HINSTANCE               hInstDLL;                  // DLL's instance.
   L_CHAR *                pszDLLName;                // DLL's name.
   VECTORPOINT             Point[ 2 ];                // Bounding parallelogram.
   VECTORPEN               Pen;                       // Pen.
   VECTORBRUSH             Brush;                     // Brush.
}
VECTORSTOCK, *pVECTORSTOCK;


// VECTORCLONE: Clone object (VECTOR_CLONE)
typedef struct _VECTORCLONE
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;
   VECTORGROUP             Group;
   L_UINT32                dwFlags;
   VECTORPEN               Pen;
   VECTORBRUSH             Brush;
   VECTORPOINT             Scale;
   VECTORPOINT             Rotation;
}
VECTORCLONE, *pVECTORCLONE;


// VECTORELLIPTICALARC: Elliptical Arc (VECTOR_ELLIPTICALARC).
typedef struct _VECTORELLIPTICALARC
{
   VECTOROBJECT            Object;
   VECTORPOINT             Point;                     // Center.
   VECTORPEN               Pen;                       // Pen.
   L_DOUBLE                xRadius;                   // x-Radius.
   L_DOUBLE                yRadius;                   // y-Radius;
   L_DOUBLE                StartAngle;                // Start angle in degrees.
   L_DOUBLE                SweepAngle;                // Sweep angle in degrees.
}
VECTORELLIPTICALARC, *pVECTORELLIPTICALARC;

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Callbacks.                                                           []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/

typedef L_INT ( pEXT_CALLBACK pVECTORENUMVERTICESPROC )( pVECTORHANDLE pVector, pVECTORPOINT pPoint, L_VOID *pUserData );
typedef L_INT ( pEXT_CALLBACK pVECTORENUMLAYERSPROC )( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, L_VOID *pUserData );
typedef L_INT ( pEXT_CALLBACK pVECTORENUMGROUPSPROC )( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, L_VOID *pUserData );
typedef L_INT ( pEXT_CALLBACK pVECTORENUMOBJECTSPROC )( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_VOID *pUserData );

#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_VECTOR)

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Functions.                                                           []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  General functions.                                                   []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecInit( pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecFree( pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecEmpty( pVECTORHANDLE pVector );
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsEmpty( const pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecCopy( pVECTORHANDLE pDst, const pVECTORHANDLE pSrc, L_UINT32 dwFlags );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetDisplayOptions( pVECTORHANDLE pVector, const pVECTOR_DISPLAY_OPTIONS pOptions );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetDisplayOptions( pVECTORHANDLE pVector, pVECTOR_DISPLAY_OPTIONS pOptions );

L_LVKRN_API L_INT EXT_FUNCTION L_VecInvertColors( pVECTORHANDLE pVector );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetViewport( pVECTORHANDLE pVector, const L_RECT *pViewport );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetViewport( const pVECTORHANDLE pVector, L_RECT *pViewport );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetPan( pVECTORHANDLE pVector, const L_POINT *pPan);
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetPan( const pVECTORHANDLE pVector, L_POINT *pPan);

#if defined(FOR_WINDOWS)
L_LVKRN_API L_INT EXT_FUNCTION L_VecPaint(L_HDC hDC, const pVECTORHANDLE pVector, L_BOOL bEraseBkgnd);
L_LVKRN_API L_INT EXT_FUNCTION L_VecRealize( pBITMAPHANDLE pBitmap, const pVECTORHANDLE pVector, L_BOOL bEraseBkgnd );
L_LVKRN_API L_INT EXT_FUNCTION L_VecPaintDC(L_HDC hDC, const pVECTORHANDLE pVector, L_UINT uWidth, L_UINT uHeight, const L_RECT *pSrc, const L_RECT *pSrcClip, const L_RECT *pDest, const L_RECT *pDestClip, L_UINT32 dwFlags);
#endif // #if defined(FOR_WINDOWS)

L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIs3D( const pVECTORHANDLE pVector);

L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsLocked( const pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetLocked( pVECTORHANDLE pVector, L_BOOL bLock );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetBackgroundColor ( pVECTORHANDLE pVector, L_COLORREF Color );
L_LVKRN_API L_COLORREF EXT_FUNCTION L_VecGetBackgroundColor( const pVECTORHANDLE pVector );

L_LVKRN_API L_INT EXT_FUNCTION L_VecLogicalToPhysical( const pVECTORHANDLE pVector, L_POINT *pDst, const pVECTORPOINT pSrc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecPhysicalToLogical( const pVECTORHANDLE pVector, pVECTORPOINT pDst, const L_POINT *pSrc );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetPalette( pVECTORHANDLE pVector, L_HPALETTE hPalette );
L_LVKRN_API L_HPALETTE EXT_FUNCTION L_VecGetPalette( const pVECTORHANDLE pVector );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetViewMode( pVECTORHANDLE pVector, L_INT nMode );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetViewMode( const pVECTORHANDLE pVector );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Transformation function.                                             []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetTranslation( pVECTORHANDLE pVector, const pVECTORPOINT pTranslation, pVECTOROBJECT pObject, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetTranslation( const pVECTORHANDLE pVector, pVECTORPOINT pTranslation );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetRotation( pVECTORHANDLE pVector, const pVECTORPOINT pRotation, pVECTOROBJECT pObject, const pVECTORPOINT pOrigin, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetRotation( const pVECTORHANDLE pVector, pVECTORPOINT pRotation);

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetScale( pVECTORHANDLE pVector, const pVECTORPOINT pScale, pVECTOROBJECT pObject, const pVECTORPOINT pOrigin, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetScale( const pVECTORHANDLE pVector, pVECTORPOINT pScale );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetOrigin( pVECTORHANDLE pVector, const pVECTORPOINT pOrigin );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetOrigin( const pVECTORHANDLE pVector, pVECTORPOINT pOrigin );

L_LVKRN_API L_INT EXT_FUNCTION L_VecApplyTransformation( pVECTORHANDLE pVector );

L_LVKRN_API L_INT EXT_FUNCTION L_VecZoomRect( pVECTORHANDLE pVector, const L_RECT *pRect );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Attributes functions.                                                []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetBindVerticesMode( pVECTORHANDLE pVector, L_INT nMode );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetBindVerticesMode( const pVECTORHANDLE pVector );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetParallelogram( pVECTORHANDLE pVector, const pVECTORPOINT pMin, const pVECTORPOINT pMax );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetParallelogram( const pVECTORHANDLE pVector, pVECTORPOINT pMin, pVECTORPOINT pMax );

L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumVertices( pVECTORHANDLE pVector, pVECTORENUMVERTICESPROC pEnumProc, L_VOID *pUserData, L_UINT32 dwFlags );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Camera functions.                                                    []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetCamera( pVECTORHANDLE pVector, const pVECTORCAMERA pCamera );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetCamera( const pVECTORHANDLE pVector, pVECTORCAMERA pCamera );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Metafile functions.                                                  []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
#if defined(FOR_WINDOWS)
L_LVKRN_API L_HMETAFILE EXT_FUNCTION L_VecConvertToWMF( L_HDC hDC, const pVECTORHANDLE pVector, const L_RECT *pRect, L_UINT uDPI );
L_LVKRN_API L_INT EXT_FUNCTION L_VecConvertFromWMF( L_HDC hDC, pVECTORHANDLE pVector, L_HMETAFILE hWMF );

L_LVKRN_API L_HENHMETAFILE EXT_FUNCTION L_VecConvertToEMF( L_HDC hDC, const pVECTORHANDLE pVector, const L_RECT *pRect, L_UINT uDPI );
L_LVKRN_API L_INT EXT_FUNCTION L_VecConvertFromEMF( L_HDC hDC, pVECTORHANDLE pVector, L_HENHMETAFILE hEMF );
#endif // #if defined(FOR_WINDOWS)

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Engine functions.                                                    []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
#if defined(FOR_WINDOWS)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAttachToWindow( L_VECTOR_WND hWnd, pVECTORHANDLE pVector, L_UINT32 dwFlags );
#endif // #if defined(FOR_WINDOWS)


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Marker functions.                                                    []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetMarker( pVECTORHANDLE pVector, const pVECTORMARKER pMarker );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetMarker( const pVECTORHANDLE pVector, pVECTORMARKER pMarker );

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Unit functions.                                                      []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetUnit( pVECTORHANDLE pVector, const pVECTORUNIT pUnit );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetUnit( const pVECTORHANDLE pVector, pVECTORUNIT pUnit );
L_LVKRN_API L_INT EXT_FUNCTION L_VecConvertPointToUnit( const pVECTORHANDLE pVector, pVECTORPOINT pptDst, const pVECTORPOINT pptSrc, const pVECTORUNIT pUnitToUse );
L_LVKRN_API L_INT EXT_FUNCTION L_VecConvertPointFromUnit( const pVECTORHANDLE pVector, pVECTORPOINT pptDst, const pVECTORPOINT pptSrc, const pVECTORUNIT pUnitToUse );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Hit test functions.                                                  []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetHitTest( pVECTORHANDLE pVector, const pVECTORHITTEST pHitTest );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetHitTest( const pVECTORHANDLE pVector, pVECTORHITTEST pHitTest );
L_LVKRN_API L_INT EXT_FUNCTION L_VecHitTest( const pVECTORHANDLE pVector, const L_POINT *pPoint, pVECTOROBJECT pObject );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Polygon functions.                                                   []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetPolygonMode( pVECTORHANDLE pVector, L_INT nMode );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetPolygonMode( const pVECTORHANDLE pVector );

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Clipboard functions.                                                 []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
#if defined(FOR_WINDOWS)
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecClipboardReady(L_VOID);

L_LVKRN_API L_INT EXT_FUNCTION L_VecCopyToClipboard( L_VECTOR_WND hWnd, const pVECTORHANDLE pVector, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecCopyFromClipboard( L_VECTOR_WND hWnd, pVECTORHANDLE pVector, L_UINT32 dwFlags );
#endif // #if defined(FOR_WINDOWS)


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Layer functions.                                                     []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddLayerA( pVECTORHANDLE pVector, const pVECTORLAYERDESCA pLayerDesc, pVECTORLAYER pLayer, L_UINT32 dwFlags );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddLayer( pVECTORHANDLE pVector, const pVECTORLAYERDESC pLayerDesc, pVECTORLAYER pLayer, L_UINT32 dwFlags );
#else
#define L_VecAddLayer L_VecAddLayerA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecDeleteLayer( pVECTORHANDLE pVector, const pVECTORLAYER pLayer );
L_LVKRN_API L_INT EXT_FUNCTION L_VecEmptyLayer( pVECTORHANDLE pVector, const pVECTORLAYER pLayer );
L_LVKRN_API L_INT EXT_FUNCTION L_VecCopyLayer( pVECTORHANDLE pVectorDst, const pVECTORLAYER pLayerDst, const pVECTORHANDLE pVectorSrc, const pVECTORLAYER pLayerSrc, L_UINT32 dwFlags );

L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayerByNameA( const pVECTORHANDLE pVector, const L_CHAR *pszName, pVECTORLAYER pLayer );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayerByName( const pVECTORHANDLE pVector, const L_TCHAR *pszName, pVECTORLAYER pLayer );
#else
#define L_VecGetLayerByName L_VecGetLayerByNameA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayerCount( const pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayerByIndex( const pVECTORHANDLE pVector, L_INT nIndex, pVECTORLAYER pLayer );

L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayerA( const pVECTORHANDLE pVector, const pVECTORLAYER pLayer, pVECTORLAYERDESCA pLayerDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecFreeLayerA( pVECTORLAYERDESCA pLayerDesc);
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetLayerA( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, const pVECTORLAYERDESCA pLayerDesc );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetLayer( const pVECTORHANDLE pVector, const pVECTORLAYER pLayer, pVECTORLAYERDESC pLayerDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecFreeLayer( pVECTORLAYERDESC pLayerDesc);
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetLayer( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, const pVECTORLAYERDESC pLayerDesc );
#else
#define L_VecGetLayer L_VecGetLayerA
#define L_VecFreeLayer L_VecFreeLayerA
#define L_VecSetLayer L_VecSetLayerA
#endif //#if defined(FOR_UNICODE)

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetActiveLayer( pVECTORHANDLE pVector, const pVECTORLAYER pLayer );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetActiveLayer( const pVECTORHANDLE pVector, pVECTORLAYER pLayer );

L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumLayers( pVECTORHANDLE pVector, pVECTORENUMLAYERSPROC pEnumProc, L_VOID *pUserData );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Group functions.                                                     []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddGroupA( pVECTORHANDLE pVector, const pVECTORGROUPDESCA pGroupDesc, pVECTORGROUP pGroup, L_UINT32 dwFlags );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddGroup( pVECTORHANDLE pVector, const pVECTORGROUPDESC pGroupDesc, pVECTORGROUP pGroup, L_UINT32 dwFlags );
#else
#define L_VecAddGroup L_VecAddGroupA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecDeleteGroup( pVECTORHANDLE pVector, const pVECTORGROUP pGroup );
L_LVKRN_API L_INT EXT_FUNCTION L_VecDeleteGroupClones( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecEmptyGroup( pVECTORHANDLE pVector, const pVECTORGROUP pGroup );
L_LVKRN_API L_INT EXT_FUNCTION L_VecCopyGroup( pVECTORHANDLE pVectorDst, const pVECTORGROUP pGroupDst, const pVECTORHANDLE pVectorSrc, const pVECTORGROUP pGroupSrc, L_UINT32 dwFlags );

L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroupByNameA( const pVECTORHANDLE pVector, const L_CHAR *pszName, pVECTORGROUP pGroup );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroupByName( const pVECTORHANDLE pVector, const L_TCHAR *pszName, pVECTORGROUP pGroup );
#else
#define L_VecGetGroupByName L_VecGetGroupByNameA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroupCount( const pVECTORHANDLE pVector );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroupByIndex( const pVECTORHANDLE pVector, L_INT nIndex, pVECTORGROUP pGroup );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroupA( const pVECTORHANDLE pVector, const pVECTORGROUP pGroup, pVECTORGROUPDESCA pGroupDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecFreeGroupA( pVECTORGROUPDESCA pGroupDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetGroupA( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, const pVECTORGROUPDESCA pGroupDesc );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetGroup( const pVECTORHANDLE pVector, const pVECTORGROUP pGroup, pVECTORGROUPDESC pGroupDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecFreeGroup( pVECTORGROUPDESC pGroupDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetGroup( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, const pVECTORGROUPDESC pGroupDesc );
#else
#define L_VecGetGroup L_VecGetGroupA
#define L_VecFreeGroup L_VecFreeGroupA
#define L_VecSetGroup L_VecSetGroupA
#endif // #if defined(FOR_UNICODE)

L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumGroups( pVECTORHANDLE pVector, pVECTORENUMGROUPSPROC pEnumProc, L_VOID *pUserData );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Object functions.                                                    []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecInitObject( pVECTOROBJECT pObject );
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddObjectA( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, L_INT nType, const L_VOID *pObjectDesc, pVECTOROBJECT pNewObject );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectA( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_INT nType, L_VOID *pObjectDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectA( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_INT nType, const L_VOID *pObjectDesc );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddObject( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, L_INT nType, const L_VOID *pObjectDesc, pVECTOROBJECT pNewObject );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObject( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_INT nType, L_VOID *pObjectDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObject( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_INT nType, const L_VOID *pObjectDesc );
#else
#define L_VecAddObject L_VecAddObjectA
#define L_VecGetObject L_VecGetObjectA
#define L_VecSetObject L_VecSetObjectA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecDeleteObject( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecCopyObject( pVECTORHANDLE pVectorDst, const pVECTORLAYER pLayerDst, pVECTOROBJECT pObjectDst, const pVECTORHANDLE pVectorSrc, const pVECTOROBJECT pObjectSrc );

L_LVKRN_API L_INT EXT_FUNCTION L_VecFreeObject( L_INT nType, L_VOID *pObjectDesc );
L_LVKRN_API L_INT EXT_FUNCTION L_VecExplodeObject( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectParallelogram( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, pVECTORPOINT pMin, pVECTORPOINT pMax, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectRect( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_RECT *pRect, L_UINT32 dwFlags );
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsObjectInsideParallelogram( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, const pVECTORPOINT pMin, const pVECTORPOINT pMax, L_UINT32 dwFlags );
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsObjectInsideRect( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, const L_RECT *pRect, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSelectObject( const pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_BOOL bSelect );
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsObjectSelected( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject );
L_LVKRN_API L_INT EXT_FUNCTION L_VecHideObject( const pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_BOOL bHide );
L_LVKRN_API L_BOOL EXT_FUNCTION L_VecIsObjectHidden( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject );

L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumObjects( pVECTORHANDLE pVector, pVECTORENUMOBJECTSPROC pEnumProc, L_VOID *pUserData, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumObjectsInLayer( pVECTORHANDLE pVector, const pVECTORLAYER pLayer, pVECTORENUMOBJECTSPROC pEnumProc, L_VOID *pUserData, L_UINT32 dwFlags );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectAttributesA( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, const L_INT *pnROP, const pVECTORPEN pPen, const pVECTORBRUSH pBrush, const pVECTORFONTA pFont, L_UINT32 dwFlags );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectAttributesA( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_INT *pnROP, pVECTORPEN pPen, pVECTORBRUSH pBrush, pVECTORFONTA pFont );
#if defined(FOR_UNICODE)
   L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectAttributes( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, const L_INT *pnROP, const pVECTORPEN pPen, const pVECTORBRUSH pBrush, const pVECTORFONT pFont, L_UINT32 dwFlags );
   L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectAttributes( const pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_INT *pnROP, pVECTORPEN pPen, pVECTORBRUSH pBrush, pVECTORFONT pFont );
#else
#define L_VecSetObjectAttributes L_VecSetObjectAttributesA
#define L_VecGetObjectAttributes L_VecGetObjectAttributesA
#endif //#if defined(FOR_UNICODE)

L_LVKRN_API L_INT EXT_FUNCTION L_VecAddObjectToGroupA( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, L_INT nType, const L_VOID *pObjectDesc, pVECTOROBJECT pNewObject );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddObjectToGroup( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, L_INT nType, const L_VOID *pObjectDesc, pVECTOROBJECT pNewObject );
#else
#define L_VecAddObjectToGroup L_VecAddObjectToGroupA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecEnumObjectsInGroup( pVECTORHANDLE pVector, const pVECTORGROUP pGroup, pVECTORENUMOBJECTSPROC pEnumProc, L_VOID *pUserData, L_UINT32 dwFlags );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectTooltipA( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_CHAR *pszTooltip );
L_LVKRN_API L_UINT32 EXT_FUNCTION L_VecGetObjectTooltipA( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_CHAR *pBuffer, L_UINT32 uSize );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectTooltip( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_TCHAR *pszTooltip );
L_LVKRN_API L_UINT32 EXT_FUNCTION L_VecGetObjectTooltip( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_TCHAR *pBuffer, L_UINT32 uSize );
#else
#define L_VecSetObjectTooltip L_VecSetObjectTooltipA
#define L_VecGetObjectTooltip L_VecGetObjectTooltipA
#endif // #if defined(FOR_UNICODE)

L_LVKRN_API L_INT EXT_FUNCTION L_VecShowObjectTooltipA( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, pVECTORTOOLTIPDESCA pTooltipDesc );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecShowObjectTooltip( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, pVECTORTOOLTIPDESC pTooltipDesc );
#else
#define L_VecShowObjectTooltip L_VecShowObjectTooltipA
#endif // #if defined(FOR_UNICODE)

L_LVKRN_API L_INT EXT_FUNCTION L_VecHideObjectTooltip( pVECTORHANDLE pVector, const pVECTOROBJECT pObject );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectViewContext( pVECTORHANDLE pVector, pVECTOROBJECT pObject, const pVECTORPOINT pMin, const pVECTORPOINT pMax );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetObjectViewContext( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, pVECTORPOINT pMin, pVECTORPOINT pMax );
L_LVKRN_API L_INT EXT_FUNCTION L_VecRemoveObjectViewContext( pVECTORHANDLE pVector, pVECTOROBJECT pObject );

L_LVKRN_API L_INT EXT_FUNCTION L_VecAddHyperlinkA( pVECTORHANDLE pVector, pVECTOROBJECT pObject, pVECTORLINKDESCA pTarget );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetHyperlinkA( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_UINT32 uIndex, pVECTORLINKDESCA pTarget );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetHyperlinkA( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_UINT32 uIndex, pVECTORLINKDESCA pTarget );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecAddHyperlink( pVECTORHANDLE pVector, pVECTOROBJECT pObject, pVECTORLINKDESC pTarget );
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetHyperlink( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_UINT32 uIndex, pVECTORLINKDESC pTarget );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetHyperlink( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_UINT32 uIndex, pVECTORLINKDESC pTarget );
#else
#define L_VecAddHyperlink L_VecAddHyperlinkA
#define L_VecSetHyperlink L_VecSetHyperlinkA
#define L_VecGetHyperlink L_VecGetHyperlinkA
#endif // #if defined(FOR_UNICODE)
L_LVKRN_API L_UINT32 EXT_FUNCTION L_VecGetHyperlinkCount( pVECTORHANDLE pVector, const pVECTOROBJECT pObject );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGotoHyperlink( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_UINT32 uIndex );

L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectDescriptionA( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_CHAR *pszTarget );
L_LVKRN_API L_UINT32 EXT_FUNCTION L_VecGetObjectDescriptionA( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_CHAR *pBuffer, L_UINT32 uSize );
#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetObjectDescription( pVECTORHANDLE pVector, pVECTOROBJECT pObject, L_TCHAR *pszTarget );
L_LVKRN_API L_UINT32 EXT_FUNCTION L_VecGetObjectDescription( pVECTORHANDLE pVector, const pVECTOROBJECT pObject, L_TCHAR *pBuffer, L_UINT32 uSize );
#else
#define L_VecSetObjectDescription L_VecSetObjectDescriptionA
#define L_VecGetObjectDescription L_VecGetObjectDescriptionA
#endif // #if defined(FOR_UNICODE)

/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Event functions.                                                     []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetEventCallbackA( pVECTORHANDLE pVector, pVECTOREVENTPROCA pProc, L_VOID *pUserData, ppVECTOREVENTPROCA pOldProc, L_VOID **pOldUserData );

#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetEventCallback( pVECTORHANDLE pVector, pVECTOREVENTPROC pProc, L_VOID *pUserData, ppVECTOREVENTPROC pOldProc, L_VOID **pOldUserData );
#else
#define L_VecSetEventCallback L_VecSetEventCallbackA
#endif //#if defined(FOR_UNICODE)
L_LVKRN_API L_INT EXT_FUNCTION L_VecEvent( pVECTORHANDLE pVector, pVECTOREVENT pEvent );


/*[]-----------------------------------------------------------------------[]*/
/*[]                                                                       []*/
/*[]  Font Substitution functions.                                         []*/
/*[]                                                                       []*/
/*[]-----------------------------------------------------------------------[]*/
L_LVKRN_API L_INT EXT_FUNCTION L_VecSetFontMapperA( pVECTORHANDLE pVector, pVECTORFONTMAPPERCALLBACKA pFontMapper, L_VOID * pUserData );
L_LVKRN_API L_INT EXT_FUNCTION L_VecGetFontMapperA( pVECTORHANDLE pVector, pVECTORFONTMAPPERCALLBACKA * ppFontMapper );

#if defined(FOR_UNICODE)
   L_LVKRN_API L_INT EXT_FUNCTION L_VecSetFontMapper( pVECTORHANDLE pVector, pVECTORFONTMAPPERCALLBACK pFontMapper, L_VOID * pUserData );
   L_LVKRN_API L_INT EXT_FUNCTION L_VecGetFontMapper( pVECTORHANDLE pVector, pVECTORFONTMAPPERCALLBACK * ppFontMapper );
#else
#define L_VecSetFontMapper L_VecSetFontMapperA
#define L_VecGetFontMapper L_VecGetFontMapperA
#endif // #if defined(FOR_UNICODE)

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_VECTOR)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTVKRN_H)
