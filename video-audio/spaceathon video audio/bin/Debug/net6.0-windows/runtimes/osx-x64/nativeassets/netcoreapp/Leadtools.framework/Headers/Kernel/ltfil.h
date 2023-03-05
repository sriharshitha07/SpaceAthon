//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTFIL_H)
#define LTFIL_H

#if !defined(LEAD_DEFINES_ONLY)

#include "lttyp.h"
#define L_LTFIL_API LT_EXPORTED

#include "ltkrn.h"

#if defined(LT_COMP_VECTOR)
#include "ltvkrn.h"
#endif // #if defined(LT_COMP_VECTOR)

#if defined(LT_COMP_SVG)
#include "ltsvg.h"
#endif // #if defined(LT_COMP_SVG)

#define L_HEADER_ENTRY
#include "ltpck.h"

#endif // !defined(LEAD_DEFINES_ONLY)


/****************************************************************
   Enums/defines
****************************************************************/

// List of file types supported
#define FILE_UNKNOWN_FORMAT               0    // Unknown (or RAW Data).

#define FILE_PCX                          1    // ZSoft PCX
#define FILE_GIF                          2    // CompuServe GIF
#define FILE_TIF                          3    // Tagged Image File Format
#define FILE_TGA                          4    // Truevision TGA (TARGA)
#define FILE_CMP                          5    // LEAD Compressed (CMP)
#define FILE_BMP                          6    // Windows Bitmap (BMP)
#define FROM_BUFFER                       7    // Internal use
#define FILE_BITMAP                       9    // Internal use
#define FILE_JPEG                         10   // JPEG File Interchange Format (JFIF)
#define FILE_TIF_JPEG                     11   // TIFF with JPEG compression
#define FILE_BIN                          12   // Internal use
#define FILE_HANDLE                       13   // Internal use
#define FILE_OS2                          14   // OS/2 Bitmap (OS/2 BMP)
#define FILE_WMF                          15   // Windows Meta File (WMF)
#define FILE_EPS                          16   // PostScript Raster (Encapsulated PostScript)
#define FILE_TIFLZW                       17   // TIFF with LZW Compression
#define FILE_LEAD                         20   // Internal use
#define FILE_JPEG_411                     21   // JPEG File Interchange Format (4-1-1)
#define FILE_TIF_JPEG_411                 22   // TIFF with JPEG compression (4-1-1)
#define FILE_JPEG_422                     23   // JPEG File Interchange Format (4-2-2)
#define FILE_TIF_JPEG_422                 24   // TIFF with JPEG compression (4-2-2)
#define FILE_CCITT                        25   // TIFF CCITT
#define FILE_LEAD1BIT                     26   // LEAD 1-bit lossless format
#define FILE_CCITT_GROUP3_1DIM            27   // TIFF CCITT Group 3 (1 Dimensional)
#define FILE_CCITT_GROUP3_2DIM            28   // TIFF CCITT Group 3 (2 Dimensional)
#define FILE_CCITT_GROUP4                 29   // TIFF CCITT Group 4

#define FILE_LEAD1BITA                    31   // Old LEAD 1 bit, lossless compression
#define FILE_ABC                          32   // LEAD Advanced Bitonal Compression

#define FILE_CALS                         50   // CALS Raster (Type 1)
#define FILE_MAC                          51   // MacPaint (MAC)
#define FILE_IMG                          52   // GEM Image (IMG)
#define FILE_MSP                          53   // Microsoft Paint (MSP)
#define FILE_WPG                          54   // WordPerfect (WPG)
#define FILE_RAS                          55   // SUN Raster Format (RAS)
#define FILE_PCT                          56   // Macintosh PICT Format (PCT)
#define FILE_PCD                          57   // PhotoCD (PCD)
#define FILE_DXF                          58   // Drawing Interchange Format (DXF)

#define FILE_FLI                          61   // Flic Animation (FLI)
#define FILE_CGM                          62   // Computer Graphics Metafile (CGM)
#define FILE_EPSTIFF                      63   // EPS with TIFF Preview
#define FILE_EPSWMF                       64   // EPS with Metafile Preview
#define FILE_CMPNOLOSS                    65   // Internal use
#define FILE_FAX_G3_1D                    66   // FAX Group 3 (1 Dimensional)
#define FILE_FAX_G3_2D                    67   // FAX Group 3 (2 Dimensional)
#define FILE_FAX_G4                       68   // FAX Group 4
#define FILE_WFX_G3_1D                    69   // WinFax Group 3 (1 Dimensional)
#define FILE_WFX_G4                       70   // WinFax Group 4
#define FILE_ICA_G3_1D                    71   // IOCA (ICA) (1 Dimensional)
#define FILE_ICA_G3_2D                    72   // IOCA (ICA) (2 Dimensional)
#define FILE_ICA_G4                       73   // IOCA (ICA) (Group 4)
#define FILE_ICA_IBM_MMR                  117  // IOCA (ICA) (MMR Compressed)
#define FILE_ICA_UNCOMPRESSED             253  // IOCA (ICA) (uncompressed)
#define FILE_ICA_ABIC                     190  // IOCA (ICA) (ABIC compression)
#define FILE_OS2_2                        74   // OS/2 Bitmap (OS/2 BMP)
#define FILE_PNG                          75   // PNG (Portable Network Graphics)
#define FILE_PSD                          76   // Photoshop 3.0 (PSD)
#define FILE_RAWICA_G3_1D                 77   // Raw IOCA (ICA) Group 3 (1 Dimensional)
#define FILE_RAWICA_G3_2D                 78   // Raw IOCA (ICA) Group 3 (2 Dimensional)
#define FILE_RAWICA_G4                    79   // Raw IOCA (ICA) Group 4
#define FILE_RAWICA_IBM_MMR               118  // Raw IOCA (ICA) (MMR Compressed)
#define FILE_RAWICA_UNCOMPRESSED          254  // Raw IOCA (ICA) (uncompressed)
#define FILE_RAWICA_ABIC                  184  // Raw IOCA ABIC
#define FILE_FPX                          80   // FlashPix, no compression
#define FILE_FPX_SINGLE_COLOR             81   // FlashPix, compression 'single color' method
#define FILE_FPX_JPEG                     82   // FlashPix, compression JPEG
#define FILE_FPX_JPEG_QFACTOR             83   // FlashPix, compression JPEG, specify qFactor
#define FILE_BMP_RLE                      84   // Windows Bitmap (BMP) with RLE compression
#define FILE_TIF_CMYK                     85   // TIFF CMYK colorspace uncompressed
#define FILE_TIFLZW_CMYK                  86   // TIFF CMYK colorspace with LZW compression
#define FILE_TIF_PACKBITS                 87   // TIFF RGB colorspace with PackBits compression
#define FILE_TIF_PACKBITS_CMYK            88   // TIFF CMYK colorspace with PackBits compression
#define FILE_DICOM_GRAY                   89   // DICOM Format (DIC,DCM) grayscale uncompressed
#define FILE_DICOM_COLOR                  90   // DICOM Format (DIC,DCM) color uncompressed
#define FILE_WIN_ICO                      91   // Windows Icon (ICO)
#define FILE_WIN_CUR                      92   // Windows Cursor (CUR)
#define FILE_TIF_YCC                      93   // TIFF YCbCr colorspace uncompressed
#define FILE_TIFLZW_YCC                   94   // TIFF YCbCr colorspace with LZW compression
#define FILE_TIF_PACKBITS_YCC             95   // TIFF YCbCr colorspace with PackBits compression
#define FILE_EXIF                         96   // Exif RGB colorspace uncompressed
#define FILE_EXIF_YCC                     97   // Exif YCbCr colorspace uncompressed
#define FILE_EXIF_JPEG_422                98   // Exif with JPEG 4-2-2 compression
#define FILE_AWD                          99   // Microsoft Fax format
#define FILE_FASTEST                      100  // For ISIS only! Use the data as is, from the ISIS Scanner
#define FILE_EXIF_JPEG_411                101  // Exif with JPEG 4-1-1 compression

#define FILE_PBM_ASCII                    102  // PBM ASCII
#define FILE_PBM_BINARY                   103  // PBM Binary
#define FILE_PGM_ASCII                    104  // PGM ASCII
#define FILE_PGM_BINARY                   105  // PGM Binary
#define FILE_PPM_ASCII                    106  // PPM ASCII
#define FILE_PPM_BINARY                   107  // PPM Binary
#define FILE_CUT                          108  // Dr. Halo
#define FILE_XPM                          109  // XPM Window PixMap
#define FILE_XBM                          110  // XWindows BitMap (XBM)
#define FILE_IFF_ILBM                     111  // IFF (Amiga Interchange) (ILBM)
#define FILE_IFF_CAT                      112  // IFF (Amiga Interchange) (CAT)
#define FILE_XWD                          113  // X Window Dump (XWD)
#define FILE_CLP                          114  // Microsoft Windows Clipboard (CLP)
#define FILE_JBIG                         115  // JBIG (JBG)
#define FILE_EMF                          116  // Windows Enhanced Metafile (EMF)
#define FILE_ANI                          119  // Windows Animated Cursor (ANI)
#define FILE_LASERDATA                    121  // LaserView LaserData CCITT Group 4
#define FILE_INTERGRAPH_RLE               122  // IntergraphRLE (ITG) (RLE compressed)
#define FILE_INTERGRAPH_VECTOR            123  // Intergraph Vector DGN (DGN)
#define FILE_DWG                          124  // DWG Format (DWG)

#define FILE_DICOM_RLE_GRAY               125  // DICOM Format (DIC,DCM) grayscale with RLE compression
#define FILE_DICOM_RLE_COLOR              126  // DICOM Format (DIC,DCM) color with RLE compression
#define FILE_DICOM_JPEG_GRAY              127  // DICOM Format (DIC,DCM) grayscale with JPEG compression
#define FILE_DICOM_JPEG_COLOR             128  // DICOM Format (DIC,DCM) color with JPEG compression

#define FILE_CALS4                        129  // CALS Raster (Type 4)
#define FILE_CALS2                        130  // CALS Raster (Type 2)
#define FILE_CALS3                        131  // CALS Raster (Type 3)

#define FILE_XWD10                        132  // X Window Dump (XWD 10)
#define FILE_XWD11                        133  // X Window Dump (XWD 11)
#define FILE_FLC                          134  // Flic Animation (FLC)
#define FILE_KDC                          135  // Kodak Digital Camera Format (KDC)
#define FILE_DRW                          136  // DRaWing (DRW)
#define FILE_PLT                          137  // HPGL plotter file vector graphics PCL

#define FILE_TIF_CMP                      138  // TIFF (with LEAD CMP compression)
#define FILE_TIF_JBIG                     139  // TIFF (with JBIG compression)
#define FILE_TIF_DXF_R13                  140  // TIFF with embedded DXF R13
#define FILE_TIF_DXF_R12                  176  // TIFF with embedded DXF R12
#define FILE_TIF_UNKNOWN                  141  // TIFF (Unknown image data)

#define FILE_SGI                          142  // Silicon Graphics Image Format (SGI)
#define FILE_SGI_RLE                      143  // Silicon Graphics Image Format (SGI) (RLE)
#define FILE_VECTOR_DUMP                  144  // Vector Dump
#define FILE_DWF                          145  // DWF Format (DWF)

#define FILE_RAS_PDF                      146  // Adobe Portable Document Format (PDF) raster uncompressed
#define FILE_RAS_PDF_G3_1D                147  // Adobe Portable Document Format (PDF) raster group 3 (1-Dimensional) compressed
#define FILE_RAS_PDF_G3_2D                148  // Adobe Portable Document Format (PDF) raster group 3 (2-Dimensional) compressed
#define FILE_RAS_PDF_G4                   149  // Adobe Portable Document Format (PDF) raster group 4 compressed
#define FILE_RAS_PDF_JPEG                 150  // Adobe Portable Document Format (PDF) raster JPEG color 4:4:4 or grayscale 8-bit compressed
#define FILE_RAS_PDF_JPEG_422             151  // Adobe Portable Document Format (PDF) raster JPEG color 4-2-2 compressed
#define FILE_RAS_PDF_JPEG_411             152  // Adobe Portable Document Format (PDF) raster JPEG color 4-1-1 compressed
#define FILE_RAS_PDF_LZW                  179  // Adobe Portable Document Format (PDF) raster LZW compressed
#define FILE_RAS_PDF_JBIG2                188  // Adobe Portable Document Format (PDF) raster JBIG2 compressed

#define FILE_RAW                          153  // Raw Image Data. LEADTOOLS can load and save raw compressed or uncompressed data. 

#define FILE_RASTER_DUMP                  154  // Internal use
#define FILE_TIF_CUSTOM                   155  // Unsupported

#define FILE_RAW_RGB                      156  // Raw Image Data (RGB uncompressed) (Read-only).
#define FILE_RAW_RLE4                     157  // Raw Image Data (RLE 4-bit compressed). LEADTOOLS can load and save raw compressed or uncompressed data.
#define FILE_RAW_RLE8                     158  // Raw Image Data (RLE 8-bit compressed). LEADTOOLS can load and save raw compressed or uncompressed data.
#define FILE_RAW_BITFIELDS                159  // Raw Image Data (BitField compressed). LEADTOOLS can load and save raw compressed or uncompressed data.
#define FILE_RAW_PACKBITS                 160  // Raw Image Data (PackBits compressed). LEADTOOLS can load and save raw compressed or uncompressed data.
#define FILE_RAW_JPEG                     161  // Raw Image Data (JPEG compressed). For information only. LEADTOOLS will neither load or save this file format
#define FILE_FAX_G3_1D_NOEOL              162  // Raw Image Data (CCITT compressed, with no EOL). LEADTOOLS can load and save raw compressed or uncompressed data.
#define FILE_RAW_LZW                      178  // Raw Image Data (LZW compressed). (Save-only).

#define FILE_JP2                          163  // JPEG2000 file - lossy or lossless
#define FILE_J2K                          164  // JPEG2000 stream - lossy or lossless
#define FILE_CMW                          165  // LEAD Wavelet CMP

#define FILE_TIF_J2K                      166  // TIFF with JPEG2000 compression
#define FILE_TIF_CMW                      167  // TIFF with LEAD Wavelet CMP compression
#define FILE_MRC                          168  // Standard MRC T44 format
#define FILE_GERBER                       169  // Gerber Vector Format (GBR)
#define FILE_WBMP                         170  // Wireless Bitmap Format (WBMP)
#define FILE_JPEG_LAB                     171  // JPEG File Interchange Format (JFIF) CieLAB 4-4-4
#define FILE_JPEG_LAB_411                 172  // JPEG File Interchange Format (JFIF) CieLAB 4-1-1
#define FILE_JPEG_LAB_422                 173  // JPEG File Interchange Format (JFIF) CieLAB 4-2-2
#define FILE_GEOTIFF                      174  // TIFF (GeoTIFF)
#define FILE_TIF_LEAD1BIT                 175  // TIFF with LEAD 1-bit compression
#define FILE_TIF_MRC                      177  // TIFF with standard MRC compression
#define FILE_TIF_ABC                      180  // TIFF with LEAD ABC 1-bit compression
#define FILE_NAP                          181  // NAPLPS Format (NAP)
#define FILE_JPEG_RGB                     182  // JPEG File Interchange Format (JFIF) RGB 4-4-4
#define FILE_JBIG2                        183  // JBIG2 (JB2)
#define FILE_ABIC                         185  // Raw ABIC Format (ABIC)
#define FILE_TIF_ABIC                     186  // TIFF with ABIC compression
#define FILE_TIF_JBIG2                    187  // TIFF with JBIG2 compression
#define FILE_TIF_ZIP                      189  // TIFF (with ZIP compression)
/* Next available: 192 */

// File formats supported by the OCR module
#define FILE_AMI_PRO_20                   200  // Ami Pro 2.0
#define FILE_AMI_PRO_30                   201  // Ami Pro 3.0
#define FILE_ASCII_SMART                  202  // ASCII Smart
#define FILE_ASCII_STANDARD               203  // ASCII Standard
#define FILE_ASCII_STANDARD_DOS           204  // ASCII Standard (DOS)
#define FILE_ASCII_STRIPPED               205  // ASCII Stripped
#define FILE_DBASE_IV_10                  206  // dBase IV v1.0
#define FILE_DCA_RFT                      207  // DCA/RFT
#define FILE_DCA_RFT_DW_5                 208  // DisplayWrite 5
#define FILE_EXCEL_MAC                    209  // Excel for the Macintosh
#define FILE_EXCEL_30                     210  // Excel 3.0
#define FILE_EXCEL_40                     211  // Excel 4.0
#define FILE_EXCEL_50                     212  // Excel 5.0
#define FILE_EXCEL_OFFICE97               213  // Excel Office 97
#define FILE_FRAMEMAKER                   214  // FrameMaker
#define FILE_HTML_20                      215  // HTML (2.0 specification)
#define FILE_HTML_EDITOR_20               216  // HTML (SoftQuad Editor)
#define FILE_HTML_NETSCAPE_20             217  // HTML (Netscape additions)
#define FILE_INTERLEAF                    218  // Interleaf
#define FILE_LOTUS123                     219  // Lotus 1-2-3
#define FILE_LOTUS_WORD_PRO               220  // Lotus Word Pro
#define FILE_MULTIMATE_ADV_II             221  // MultiMate Advantage II
#define FILE_POSTSCRIPT                   222  // PostScript Document Format (PS)
#define FILE_PROFESSIONAL_WRITE_20        223  // Professional Write 2.0
#define FILE_PROFESSIONAL_WRITE_22        224  // Professional Write 2.2
#define FILE_QUATTRA_PRO                  225  // Quattra Pro
#define FILE_RTF                          226  // Rich Text Format
#define FILE_RTF_MAC                      227  // Rich Text Format (Macintosh)
#define FILE_RTF_WORD_60                  228  // Rich Text Format (Word 6.0)
#define FILE_WINDOWS_WRITE                229  // Windows Write
#define FILE_WORD_WINDOWS_2X              230  // Word for Windows 2.X
#define FILE_WORD_WINDOWS_60              231  // Word for Windows 6.0
#define FILE_WORD_OFFICE97                232  // Word Office 97
#define FILE_WORDPERFECT_DOS_42           233  // WordPerfect 4.2 (DOS)
#define FILE_WORDPERFECT_WINDOWS          234  // WordPerfect (Windows)
#define FILE_WORDPERFECT_WINDOWS_60       235  // WordPerfect 6.0 (Windows)
#define FILE_WORDPERFECT_WINDOWS_61       236  // WordPerfect 6.1 (Windows)
#define FILE_WORDPERFECT_WINDOWS_7X       237  // WordPerfect 7X (Windows)
#define FILE_WORDSTAR_WINDOWS_1X          238  // WordStar 1.X (Windows)
#define FILE_WORKS                        239  // Works
#define FILE_XDOC                         240  // Xerox XDOC

#define FILE_SVG                          247  // Scalable Vector Graphics Format (SVG)

#define FILE_NITF                         248  // NITF
#define FILE_PTOCA                        249  // PTOCA Format (PTOCA)
#define FILE_SCT                          250  // Scitex Continuous Tone Format (SCT)
#define FILE_PCL                          251  // Printer Command Language Format (PCL)
#define FILE_AFP                          252  // AFP Format (AFP)
#define FILE_SHP                          255  // ESRI Shape Format (SHP)
#define FILE_SMP                          256  // SMP Format (SMP)
#define FILE_SMP_G3_1D                    257  // SMP Format (SMP) CCITT Group 3 (1-dimensional)
#define FILE_SMP_G3_2D                    258  // SMP Format (SMP) CCITT Group 3 (2-dimensional)
#define FILE_SMP_G4                       259  // SMP Format (SMP) CCITT Group 4

#define FILE_VWPG                         260  // Vector WPG
#define FILE_VWPG1                        328  // Vector WPG
#define FILE_CMX                          261  // Corel Presentation Exchange Format (CMX)

#define FILE_TGA_RLE                      262  // Truevision TGA (TARGA) (RLE)

#define FILE_KDC_120                      263  // Kodak Digital Camera Format (KDC) (120)
#define FILE_KDC_40                       264  // Kodak Digital Camera Format (KDC) (40)
#define FILE_KDC_50                       265  // Kodak Digital Camera Format (KDC) (50)
#define FILE_DCS                          266  // Kodak Professional Digital Camera System Format (DCS)

#define FILE_PSP                          267  // Paint Shop Pro Format (PSP)
#define FILE_PSP_RLE                      268  // Paint Shop Pro Format (PSP) RLE compressed

#define FILE_TIFX_JBIG                    269  // Xerox Internet Fax File Format JBIG compressed (1 bit/pixel)
#define FILE_TIFX_JBIG_T43                270  // Xerox Internet Fax File Format JBIG compressed (3 bits/pixel)
#define FILE_TIFX_JBIG_T43_ITULAB         271  // Xerox Internet Fax File Format JBIG compressed (24 bits/pixel)
#define FILE_TIFX_JBIG_T43_GS             272  // Xerox Internet Fax File Format JBIG compressed
#define FILE_TIFX_FAX_G4                  273  // Xerox Internet Fax File Format CCITT Group 4 compressed
#define FILE_TIFX_FAX_G3_1D               274  // Xerox Internet Fax File Format CCITT Group 3 (1-dimensional) compressed
#define FILE_TIFX_FAX_G3_2D               275  // Xerox Internet Fax File Format CCITT Group 3 (2-dimensional) compressed
#define FILE_TIFX_JPEG                    276  // Xerox Internet Fax File Format JPEG compressed

#define FILE_ECW                          277  // Enhanced Compressed Wavelet
#define FILE_RAS_RLE                      288  // SUN Raster Format (RAS) (RLE)
#define FILE_SVG_EMBED_IMAGES             289  // Scalable Vector Graphics Format (SVG) with embedded images
#define FILE_DXF_R13                      290  // Drawing Interchange Format (DXF)
#define FILE_CLP_RLE                      291  // Microsoft Windows Clipboard (CLP)(RLE compressed)
#define FILE_DCR                          292  // Kodak Professional Digital Camera System Format (DCR)

#define FILE_DICOM_J2K_GRAY               293  // DICOM Format (DIC,DCM) grayscale with JPEG 2000 compression
#define FILE_DICOM_J2K_COLOR              294  // DICOM Format (DIC,DCM) color with JPEG 2000 compression

#define FILE_FIT                          295  // FITS Format (FIT)
#define FILE_CRW                          296  // AFP Format (AFP) IOCA MMR Compressed
#define FILE_DWF_TEXT_AS_POLYLINE         297  // DWF Format (DWF)
#define FILE_CIN                          298  // Cineon Format (CIN)
#define FILE_PCL_TEXT_AS_POLYLINE         299  // PCL6 vector format
#define FILE_EPSPOSTSCRIPT                300  // PostScript Raster (Encapsulated PostScript)
#define FILE_INTERGRAPH_CCITT_G4          301  // IntergraphRLE (ITG) (CCITT Group 4 compressed)

#define FILE_SFF                          302  // Structured Fax File Format (SFF)
#define FILE_IFF_ILBM_UNCOMPRESSED        303  // IFF (Amiga Interchange) (ILBM uncompressed)
#define FILE_IFF_CAT_UNCOMPRESSED         304  // IFF (Amiga Interchange) (CAT uncompressed)
#define FILE_RTF_RASTER                   305  // Rich Text Format (RTF)
#define FILE_WMZ                          307  // Compressed Windows Metafile Format (WMZ)

#define FILE_AFPICA_G3_1D                 309  // MO:DCA IOCA files with AFP prefix and Fax G3 1D compression
#define FILE_AFPICA_G3_2D                 310  // MO:DCA IOCA files with AFP prefix and Fax G3 2D compression
#define FILE_AFPICA_G4                    311  // MO:DCA IOCA files with AFP prefix and Fax G4 compression
#define FILE_AFPICA_UNCOMPRESSED          312  // MO:DCA IOCA files with AFP prefix and uncompressed data
#define FILE_AFPICA_IBM_MMR               313  // MO:DCA IOCA files with AFP prefix and Fax G3 1D IBM MMR modified compression (no EOL)
#define FILE_AFPICA_ABIC                  191  // MO:DCA IOCA files with AFP prefix and ABIC compression

#define FILE_LEAD_MRC                     314  // LEAD MRC format
#define FILE_TIF_LEAD_MRC                 315  // TIFF with LEAD MRC compression

#define FILE_TXT                          316  // Text Format. LEADTOOLS can load ASCII and Unicode text files as raster or SVG images.

#define FILE_PDF_LEAD_MRC                 317  // PDF format with image segmentation using LEAD MRC

#define FILE_HDP                          318  // JPEG XR / Microsoft HD Photo File Format
#define FILE_HDP_GRAY                     319  // JPEG XR / Microsoft HD Photo File Format
#define FILE_HDP_CMYK                     320  // JPEG XR / Microsoft HD Photo File Format

#define FILE_PNG_ICO                      321  // Windows Icon (ICO), PNG Compressed (Windows)
#define FILE_XPS                          322  // Microsoft XML Paper Specification (XPS)
#define FILE_JPX                          323  // JPEG2000 extension part 2 (JPX)

#define FILE_XPS_JPEG                     324  // XML Paper Specification (XPS) - with JPEG (4-4-4) Compression
#define FILE_XPS_JPEG_422                 325  // XML Paper Specification (XPS) - with JPEG (4-2-2) Compression
#define FILE_XPS_JPEG_411                 326  // XML Paper Specification (XPS) - with JPEG (4-1-1) Compression

#define FILE_MNG                          327  // Multiple Network Graphics (MNG)
#define FILE_MNG_GRAY                     329  // Multiple Network Graphics (MNG) - Gray
#define FILE_MNG_JNG                      330  // Multiple Network Graphics (MNG) - YUV 4-4-4
#define FILE_MNG_JNG_411                  331  // Multiple Network Graphics (MNG) - YUV 4-1-1
#define FILE_MNG_JNG_422                  332  // Multiple Network Graphics (MNG) - YUV 4-2-2

#define FILE_RAS_PDF_CMYK                 333  // Adobe Portable Document Format (PDF) (CMYK data) raster uncompressed
#define FILE_RAS_PDF_LZW_CMYK             334  // Adobe Portable Document Format (PDF) (CMYK data) LZW compressed

#define FILE_MIF                          335  // MapInfo Interchange File Format (MIF)
#define FILE_E00                          336  // ArcInfo Interchange File Format (E00)

#define FILE_TDB                          337  // Windows XP Thumbnail Cache
#define FILE_TDB_VISTA                    338  // Windows Vista Thumbnail Cache

#define FILE_SNP                          339  // MS Access Report Snapshots Format

#define FILE_AFP_IM1                      340  // AFP Format (AFP) IOCA MMR Compressed

#define FILE_XLS                          341  // Microsoft Excel 97-2003 file format (XLS)
#define FILE_DOC                          342  // Microsoft Word 97-2003 file format (DOC)

#define FILE_ANZ                          343  // Analyze file format

#define FILE_PPT                          344  // Microsoft Power Point 97-2003 file format (PPT)
#define FILE_PPT_JPEG                     345  // Microsoft Power Point 97-2003 file format with JPEG compression
#define FILE_PPT_PNG                      346  // Microsoft Power Point 97-2003 file format with PNG compression

#define FILE_JPM                          347  // JPEG2000 JPM file format

#define FILE_VFF                          348  // Sun TAAC Bitmap file format
#define FILE_PCLXL                        349  // PCL6 vector format (PCLXL)

#define FILE_DOCX                         350  // Microsoft Office Word file format (DOCX)
#define FILE_XLSX                         351  // Microsoft Office Excel file format (XLSX)
#define FILE_PPTX                         352  // Microsoft Office PowerPoint file format (PPTX)

#define FILE_JXR                          353  // JPEG XR / Microsoft HD Photo File Format
#define FILE_JXR_GRAY                     354  // JPEG XR / Microsoft HD Photo File Format - Grayscale
#define FILE_JXR_CMYK                     355  // JPEG XR / Microsoft HD Photo File Format - CMYK

#define FILE_JLS                          356  // JPEG LS file format

#define FILE_JXR_422                      357  // JPEG XR / Microsoft HD Photo File Format - YUV 4-2-2
#define FILE_JXR_420                      358  // JPEG XR / Microsoft HD Photo File Format - YUV 4-2-0

#define FILE_DCF_ARW                      359  // Sony Digital Camera Format (DCF)
#define FILE_DCF_RAF                      360  // Fujifilm Digital Camera Format (DCF)
#define FILE_DCF_ORF                      361  // Olympus Digital Camera Format (DCF)
#define FILE_DCF_CR2                      362  // Canon Digital Camera Format (DCF)
#define FILE_DCF_NEF                      363  // Nikon Digital Camera Format (DCF)
#define FILE_DCF_RW2                      364  // Panasonic Digital Camera Format (DCF)
#define FILE_DCF_CASIO                    365  // Casio Digital Camera Format (DCF)
#define FILE_DCF_PENTAX                   366  // Pentax Digital Camera Format (DCF)

#define FILE_JLS_LINE                     367  // JPEG LS Line interleaved file format
#define FILE_JLS_SAMPLE                   368  // JPEG LS Sample interleaved file format

#define FILE_HTM                          369  // HyperText Markup Language

#define FILE_MOB                          370  // MOBI format for e-book readers such as the Kindle

#define FILE_PUB                          371  // ePub format

#define FILE_ING                          372  // INGR file format COT, Uncompressed (color or gray)
#define FILE_ING_RLE                      373  // INGR file format (RLE compression - 1 or 8 BPP)
#define FILE_ING_ADRLE                    374  // INGR file format (Adaptive RLE - 24 or 8 BPP)
#define FILE_ING_CG4                      375  // INGR file format (CCITT Group 4 - 1 BPP)

#define FILE_DWFX                         376  // DWF XPS Document (DWFX)

#define FILE_ICA_JPEG                     377  // IOCA, compressed using JPEG, with MO:DCA wrapper (multipage)
#define FILE_ICA_JPEG_411                 378  // IOCA, compressed using JPEG 4-1-1, with MO:DCA wrapper (multipage)
#define FILE_ICA_JPEG_422                 379  // IOCA, compressed using JPEG 4-2-2, with MO:DCA wrapper (multipage).

#define FILE_DCF_DNG                      380  // File Formats: Digital File Format (DCF, ARW, SR2, SRF, DNG, CR2, RAF, NEF, NRW, ORF, RW2, RAW)

#define FILE_RAW_FLATE                    381  // Flate-compressed raw Image Data.
#define FILE_RAW_RLE                      382  // RLE-compressed raw Image Data. 

#define FILE_DICOM_JPEG_LS_GRAY           383  // DICOM Format (DIC,DCM) grayscale with JPEG-LS compression
#define FILE_DICOM_JPEG_LS_COLOR          384  // DICOM Format (DIC,DCM) color with JPEG-LS compression

#define FILE_PST                          385  // Outlook PST Format
#define FILE_MSG                          386  // Outlook MSG Format
#define FILE_EML                          387  // Internet Message Format (EML)

#define FILE_RAS_PDF_JPX                  388  // Portable Document Format (PDF) (JPX)

#define FILE_DICOM_JPX_GRAY               389  // DICOM Format (DIC,DCM) grayscale with JPEG2000 part 2 (JPX) compression
#define FILE_DICOM_JPX_COLOR              390  // DICOM Format (DIC,DCM) color with JPEG2000 part 2 (JPX) compression

// File formats defines that are not unique
// Here for backward compatibility
#define FILE_JFIF                         FILE_JPEG
#define FILE_JTIF                         FILE_TIF_JPEG
#define FILE_LEAD1JFIF                    FILE_JPEG_411
#define FILE_LEAD1JTIF                    FILE_TIF_JPEG_411
#define FILE_LEAD2JFIF                    FILE_JPEG_422
#define FILE_LEAD2JTIF                    FILE_TIF_JPEG_422
#define FILE_DXF_R12                      FILE_DXF
#define FILE_EXIF_JPEG                    FILE_EXIF_JPEG_422
#define FILE_TIF_DXF                      FILE_TIF_DXF_R13
#define FILE_RAW_CCITT                    FILE_FAX_G3_1D_NOEOL
#define FILE_JFIF_LAB                     FILE_JPEG_LAB
#define FILE_LEAD1JFIF_LAB                FILE_JPEG_LAB_411
#define FILE_LEAD2JFIF_LAB                FILE_JPEG_LAB_422

#define FILE_JPEG_CMYK                    391   // JPEG File Interchange Format (CMYK) 4-4-4
#define FILE_JPEG_CMYK_411                392   // JPEG File Interchange Format (CMYK) 4-1-1
#define FILE_JPEG_CMYK_422                393   // JPEG File Interchange Format (CMYK) 4-2-2
#define FILE_TIF_JPEG_CMYK                394   // TIFF with JPEG compression (CMYK) 4-4-4
#define FILE_TIF_JPEG_CMYK_411            395   // TIFF with JPEG compression (CMYK) 4-1-1
#define FILE_TIF_JPEG_CMYK_422            396   // TIFF with JPEG compression (CMYK) 4-2-4
#define FILE_SVGZ                         397   // GZIP compressed Scalable Vector Graphics Format (SVG)
#define FILE_X9F                          398   // Image Cash Letter (X9)
#define FILE_THREEJS                      399   // Three.js 3D model JSON Geometry Format (3JS)
#define FILE_STL                          400   // STereoLithography Format (STL)
#define FILE_CSV                          401   // CSV Format LEADTOOLS can load CSV files as raster or SVG images.
#define FILE_HEIC                         402   // HEIF file format with HEVC(H265) image compression

#define FILE_XLSB                         403   // Microsoft Office Excel Binary file format (XLSX Binary)
#define FILE_WEBP                         404   // WebP single page file format
#define FILE_WEBP_ANI                     405   // WebP animated file format

// compression type
#define LEAD                  0  // LEAD  Proprietary
#define JFIF                  1  // JPEG  4:4:4
#define JTIF                  2  // JPEG  4:4:4
#define LEAD1JFIF             3  // JPEG  4:1:1
#define LEAD1JTIF             4  // JPEG  4:1:1
#define LEAD2JFIF             5  // JPEG  4:2:2
#define LEAD2JTIF             6  // JPEG  4:2:2
#define LEADJ2K               7  // j2k
#define LEADJP2               8  // jp2


#define LEAD_0                0  // LEAD 1 bit, lossless compression
#define LEAD_1                1  // LEAD 1 bit, excellent compression

#define TIFF_CCITT            3  // TIFF  CCITT
#define TIFF_CCITTG3_FAX1D    4  // CCITT Group3 one dimensional
#define TIFF_CCITTG3_FAX2D    5  // CCITT Group3 two dimensional
#define TIFF_CCITTG4_FAX      6  // CCITT Group4 two dimensional

// flags for L_*Comment
// the following indicate the associated strings are null terminated
#define CMNT_SZARTIST                                    0     // Person who created image
#define CMNT_SZCOPYRIGHT                                 1     // Copyright notice
#define CMNT_SZDATETIME                                  2     // "YYYY:MM:DD HH:MM:SS" format
#define CMNT_SZDESC                                      3     // Description of image
#define CMNT_SZHOSTCOMP                                  4     // Computer/OP System in use
#define CMNT_SZMAKE                                      5     // Manufacturer of Equip. used generate the image
#define CMNT_SZMODEL                                     6     // Model Name/Number of Equipment
#define CMNT_SZNAMEOFDOC                                 7     // Doc name image was scanned from
#define CMNT_SZNAMEOFPAGE                                8     // Page name image was scanned from
#define CMNT_SZSOFTWARE                                  9     // Name & Version of Software Package used to gen the image
#define CMNT_SZPATIENTNAME                               10    // Patient name (DICOM)
#define CMNT_SZPATIENTID                                 11    // Patient ID (DICOM)
#define CMNT_SZPATIENTBIRTHDATE                          12    // Patient birth date (DICOM)
#define CMNT_SZPATIENTSEX                                13    // Patient sex (DICOM)
#define CMNT_SZSTUDYINSTANCE                             14    // Study instance ID (DICOM)
#define CMNT_SZSTUDYDATE                                 15    // Study date (DICOM)
#define CMNT_SZSTUDYTIME                                 16    // Study time (DICOM)
#define CMNT_SZSTUDYREFERRINGPHYSICIAN                   17    // Referring physician (DICOM)
#define CMNT_SZSERIESMODALITY                            18    // Series modality (DICOM)
#define CMNT_SZSERIESID                                  19    // Series ID (DICOM)
#define CMNT_SZSERIESNUMBER                              20    // Series number (DICOM)

// Exif 1.0 and 1.1 comments
#define CMNT_EXIFVERSION                                 21    // Exif version
#define CMNT_SZDATETIMEORIGINAL                          22    // Date and time the original image is captured (Exif)
#define CMNT_SZDATETIMEDIGITIZED                         23    // Date and time the file is generated (Exif)
#define CMNT_SHUTTERSPEEDVALUE                           24    // Shutter speed (Exif)
#define CMNT_APERTURE                                    25    // Aperture value (Exif)
#define CMNT_BRIGHTNESS                                  26    // Brightness value (Exif)
#define CMNT_EXPOSUREBIAS                                27    // Exposure bias (Exif)
#define CMNT_MAXAPERTURE                                 28    // Minimum lens f-number (Exif)
#define CMNT_SUBJECTDISTANCE                             29    // Distance from lens to subject (m) (Exif)
#define CMNT_METERINGMODE                                30    // Photometry mode (Exif)
#define CMNT_LIGHTSOURCE                                 31    // Light source (Exif)
#define CMNT_FLASH                                       32    // Flash On/Off (Exif)
#define CMNT_FOCALLENGTH                                 33    // Focal length (Exif)
#define CMNT_EXPOSURETIME                                34    // Exposure  (Exif)
#define CMNT_FNUMBER                                     35    // F-number (Exif)
#define CMNT_MAKERNOTE                                   36    // Maker note (Exif)
#define CMNT_USERCOMMENT                                 37    // User comment (Exif)
#define CMNT_SZSUBSECTIME                                38    // Date Time subsec (Exif)
#define CMNT_SZSUBSECTIMEORIGINAL                        39    // Date Time original subsec (Exif)
#define CMNT_SZSUBSECTIMEDIGITIZED                       40    // Date Time digitized subsec (Exif)

// Exif 2.0 comments - comments introduced since Exif 1.1
#define CMNT_SUPPORTEDFLASHPIXVERSION                    158   // Supported FlashPix version (Exif)
#define CMNT_COLORSPACE                                  159   // Color space (Exif)
#define CMNT_EXPOSUREPROGRAM                             160   // Exposure program (Exif)
#define CMNT_SZSPECTRALSENSITIVITY                       161   // Spectral sensitivity (Exif)
#define CMNT_ISOSPEEDRATINGS                             162   // ISO speed ratings (Exif)
#define CMNT_OPTOELECTRICCOEFFICIENT                     163   // Optoelectronic coefficient (Exif)
#define CMNT_SZRELATEDSOUNDFILE                          164   // Related audio file (Exif)
#define CMNT_FLASHENERGY                                 165   // Flash energy (Exif)
#define CMNT_SPATIALFREQUENCYRESPONSE                    166   // Spatial frequency response (Exif)
#define CMNT_FOCALPLANEXRESOLUTION                       167   // Focal plane X Resolution (Exif)
#define CMNT_FOCALPLANEYRESOLUTION                       168   // Focal plane Y Resolution (Exif)
#define CMNT_FOCALPLANERESOLUTIONUNIT                    245   // Focal plane Resolution Unit (Exif)
#define CMNT_SUBJECTLOCATION                             169   // Subject location (Exif)
#define CMNT_EXPOSUREINDEX                               170   // Exposure index (Exif)
#define CMNT_SENSINGMETHOD                               171   // Sensing method (Exif)
#define CMNT_FILESOURCE                                  172   // File source (Exif)
#define CMNT_SCENETYPE                                   173   // Scene type (Exif)
#define CMNT_CFAPATTERN                                  174   // CFA Pattern (Exif)

// Exif 2.2 comments - comments introduced since Exif 2.0
#define CMNT_SUBJECTAREA                                 227
#define CMNT_CUSTOMRENDERED                              228
#define CMNT_EXPOSUREMODE                                229
#define CMNT_WHITEBALANCE                                230
#define CMNT_DIGITALZOOMRATIO                            231
#define CMNT_FOCALLENGTHIN35MMFILM                       232
#define CMNT_SCENECAPTURETYPE                            233
#define CMNT_GAINCONTROL                                 234
#define CMNT_CONTRAST                                    235
#define CMNT_SATURATION                                  236
#define CMNT_SHARPNESS                                   237
#define CMNT_DEVICESETTINGDESCRIPTION                    238
#define CMNT_SUBJECTDISTANCERANGE                        239
#define CMNT_SZIMAGEUNIQUEID                             240

/* Exif 2.21 comments - comments introduced since Exif 2.2 */
#define CMNT_GAMMA                                       246

/* Exif 2.32 comments - comments introduced since Exif 2.21 */
#define CMNT_SZOFFSETOFDATETIME                          247
#define CMNT_SZOFFSETOFDATETIMEORIGINAL                  248
#define CMNT_SZOFFSETOFDATETIMEDIGITIZED                 249
#define CMNT_SZDATETIMESUBSECONDS                        250
#define CMNT_SZDATETIMEORIGINALSUBSECONDS                251
#define CMNT_SZDATETIMEDIGITIZEDSUBSECONDS               252
#define CMNT_SZOWNERNAME                                 253
#define CMNT_SZBODYSERIALNUMBER                          254
#define CMNT_LENSSPECIFICATION                           255
#define CMNT_SZLENSMAKE                                  256
#define CMNT_SZLENSMODEL                                 257
#define CMNT_SZLENSSERIALNUMBER                          258
#define CMNT_COMPOSITEIMAGE                              259
#define CMNT_SOURCEIMAGENUMBEROFCOMPOSITEIMAGE           260
#define CMNT_SOURCEEXPOSURETIMESOFCOMPOSITEIMAGE         261

// Exif 1.1 GPS comments
#define CMNT_GPSVERSIONID                                41
#define CMNT_GPSLATITUDEREF                              42
#define CMNT_GPSLATITUDE                                 43
#define CMNT_GPSLONGITUDEREF                             44
#define CMNT_GPSLONGITUDE                                45
#define CMNT_GPSALTITUDEREF                              46
#define CMNT_GPSALTITUDE                                 47
#define CMNT_GPSTIMESTAMP                                48
#define CMNT_GPSSATELLITES                               49
#define CMNT_GPSSTATUS                                   50
#define CMNT_GPSMEASUREMODE                              51
#define CMNT_GPSDOP                                      52
#define CMNT_GPSSPEEDREF                                 53
#define CMNT_GPSSPEED                                    54
#define CMNT_GPSTRACKREF                                 55
#define CMNT_GPSTRACK                                    56
#define CMNT_GPSIMGDIRECTIONREF                          57
#define CMNT_GPSIMGDIRECTION                             58
#define CMNT_GPSMAPDATUM                                 59
#define CMNT_GPSDESTLATITUDEREF                          60
#define CMNT_GPSDESTLATITUDE                             61
#define CMNT_GPSDESTLONGITUDEREF                         62
#define CMNT_GPSDESTLONGITUDE                            63
#define CMNT_GPSDESTBEARINGREF                           64
#define CMNT_GPSDESTBEARING                              65
#define CMNT_GPSDESTDISTANCEREF                          66
#define CMNT_GPSDESTDISTANCE                             67

// Exif 2.2 comments - comments introduced since Exif 2.0
#define CMNT_GPSPROCESSINGMETHOD                         241
#define CMNT_GPSAREAINFORMATION                          242
#define CMNT_GPSDATESTAMP                                243
#define CMNT_GPSDIFFERENTIAL                             244

// Exif 2.32 tags - comments introduced since Exif 2.2
#define CMNT_GPSHORIZPOSITIONINGERROR                    262

#define CMNT_FPXSUMMARYINFORMATION                       0x8001
#define CMNT_FPXTITLE                                    68
#define CMNT_FPXSUBJECT                                  69
#define CMNT_FPXAUTHOR                                   70
#define CMNT_FPXKEYWORDS                                 71
#define CMNT_FPXCOMMENTS                                 72
#define CMNT_FPXOLETEMPLATE                              73
#define CMNT_FPXLASTAUTHOR                               74
#define CMNT_FPXREVNUMBER                                75
#define CMNT_FPXEDITTIME                                 76
#define CMNT_FPXLASTPRINTED                              77
#define CMNT_FPXCREATEDTM                                78
#define CMNT_FPXLASTSAVEDTM                              79
#define CMNT_FPXPAGECOUNT                                80
#define CMNT_FPXWORDCOUNT                                81
#define CMNT_FPXCHARCOUNT                                82
#define CMNT_FPXTHUMBNAIL                                83
#define CMNT_FPXAPPNAME                                  84
#define CMNT_FPXSECURITY                                 85
#define CMNT_FPXSUMMARYINFORMATION1                      CMNT_FPXTITLE
#define CMNT_FPXSUMMARYINFORMATION2                      CMNT_FPXSECURITY

#define CMNT_FPXFILESOURCEGROUP                          0x8002
#define CMNT_FPXFILESOURCE                               86
#define CMNT_FPXSCENETYPE                                87
#define CMNT_FPXCREATIONPATH                             88
#define CMNT_FPXNAMEMANRELEASE                           89
#define CMNT_FPXUSERDEFINEDID                            90
#define CMNT_FPXORIGINALSHARPNESSAPPROXIMATION           91
#define CMNT_FPXFILESOURCEGROUP1                         CMNT_FPXFILESOURCE
#define CMNT_FPXFILESOURCEGROUP2                         CMNT_FPXORIGINALSHARPNESSAPPROXIMATION

#define CMNT_FPXINTELLECTUALPROPERTYGROUP                0x8004
#define CMNT_FPXCOPYRIGHT                                92
#define CMNT_FPXLEGALBROKERFORORIGIMAGE                  93
#define CMNT_FPXLEGALBROKERFORDIGITALIMAGE               94
#define CMNT_FPXAUTHORSHIP                               95
#define CMNT_FPXINTELLECTUALPROPNOTES                    96
#define CMNT_FPXINTELLECTUALPROPERTYGROUP1               CMNT_FPXCOPYRIGHT
#define CMNT_FPXINTELLECTUALPROPERTYGROUP2               CMNT_FPXINTELLECTUALPROPNOTES

#define CMNT_FPXCONTENTDESCRIPTIONGROUP                  0x8008
#define CMNT_FPXTESTTARGETINTHEIMAGE                     97
#define CMNT_FPXGROUPCAPTION                             98
#define CMNT_FPXCAPTIONTEXT                              99
#define CMNT_FPXPEOPLEINTHEIMAGE                         100
#define CMNT_FPXTHINGSINIMAGE                            101
#define CMNT_FPXDATEOFORIGINALIMAGE                      102
#define CMNT_FPXEVENTSINTHEIMAGE                         103
#define CMNT_FPXPLACESINTHEIMAGE                         104
#define CMNT_FPXCONTENTDESCRIPTIONNOTES                  105
#define CMNT_FPXCONTENTDESCRIPTIONGROUP1                 CMNT_FPXTESTTARGETINTHEIMAGE
#define CMNT_FPXCONTENTDESCRIPTIONGROUP2                 CMNT_FPXCONTENTDESCRIPTIONNOTES

#define CMNT_FPXCAMERAINFORMATIONGROUP                   0x8010
#define CMNT_FPXCAMERAMANUFACTURERNAME                   106
#define CMNT_FPXCAMERAMODELNAME                          107
#define CMNT_FPXCAMERASERIALNUMBER                       108
#define CMNT_FPXCAMERAINFORMATIONGROUP1                  CMNT_FPXCAMERAMANUFACTURERNAME
#define CMNT_FPXCAMERAINFORMATIONGROUP2                  CMNT_FPXCAMERASERIALNUMBER

#define CMNT_FPXPERPICTURECAMERASETTINGSGROUP            0x8020
#define CMNT_FPXCAPTUREDATE                              109
#define CMNT_FPXEXPOSURETIME                             110
#define CMNT_FPXFNUMBER                                  111
#define CMNT_FPXEXPOSUREPROGRAM                          112
#define CMNT_FPXBRIGHTNESSVALUE                          113
#define CMNT_FPXEXPOSUREBIASVALUE                        114
#define CMNT_FPXSUBJECTDISTANCE                          115
#define CMNT_FPXMETERINGMODE                             116
#define CMNT_FPXSCENEILLUMINANT                          117
#define CMNT_FPXFOCALLENGTH                              118
#define CMNT_FPXMAXIMUMAPERATUREVALUE                    119
#define CMNT_FPXFLASH                                    120
#define CMNT_FPXFLASHENERGY                              121
#define CMNT_FPXFLASHRETURN                              122
#define CMNT_FPXBACKLIGHT                                123
#define CMNT_FPXSUBJECTLOCATION                          124
#define CMNT_FPXEXPOSUREINDEX                            125
#define CMNT_FPXSPECIALEFFECTSOPTICALFILTER              126
#define CMNT_FPXPERPICTURENOTES                          127
#define CMNT_FPXPERPICTURECAMERASETTINGSGROUP1           CMNT_FPXCAPTUREDATE
#define CMNT_FPXPERPICTURECAMERASETTINGSGROUP2           CMNT_FPXPERPICTURENOTES

#define CMNT_FPXDIGITALCAMERACHARACTERIZATIONGROUP       0x8040
#define CMNT_FPXSENSINGMETHOD                            128
#define CMNT_FPXFOCALPLANEXRESOLUTION                    129
#define CMNT_FPXFOCALPLANEYRESOLUTION                    130
#define CMNT_FPXFOCALPLANERESOLUTIONUNIT                 131
#define CMNT_FPXSPACIALFREQUENCY                         132
#define CMNT_FPXCFAPATTERN                               133
#define CMNT_FPXSPECTRALSENSITIVITY                      134
#define CMNT_FPXISOSPEEDRATINGS                          135
#define CMNT_FPXOECF                                     136
#define CMNT_FPXDIGITALCAMERACHARACTERIZATIONGROUP1      CMNT_FPXSENSINGMETHOD
#define CMNT_FPXDIGITALCAMERACHARACTERIZATIONGROUP2      CMNT_FPXOECF

#define CMNT_FPXFILMDESCRIPTIONGROUP                     0x8080
#define CMNT_FPXFILMBRAND                                137
#define CMNT_FPXFILMCATEGORY                             138
#define CMNT_FPXFILMSIZEX                                139
#define CMNT_FPXFILMSIZEY                                140
#define CMNT_FPXFILMSIZEUNIT                             141
#define CMNT_FPXFILMROLLNUMBER                           142
#define CMNT_FPXFILMFRAMENUMBER                          143
#define CMNT_FPXFILMDESCRIPTIONGROUP1                    CMNT_FPXFILMBRAND
#define CMNT_FPXFILMDESCRIPTIONGROUP2                    CMNT_FPXFILMFRAMENUMBER

#define CMNT_FPXORIGINALDOCUMENTSCANDESCRIPTIONGROUP     0x8100
#define CMNT_FPXORIGINALSCANNEDIMAGESIZE                 144
#define CMNT_FPXORIGINALDOCUMENTSIZE                     145
#define CMNT_FPXORIGINALMEDIUM                           146
#define CMNT_FPXTYPEOFREFLECTIONORIGINAL                 147
#define CMNT_FPXORIGINALDOCUMENTSCANDESCRIPTIONGROUP1    CMNT_FPXORIGINALSCANNEDIMAGESIZE
#define CMNT_FPXORIGINALDOCUMENTSCANDESCRIPTIONGROUP2    CMNT_FPXTYPEOFREFLECTIONORIGINAL

#define CMNT_FPXSCANDEVICEPROPERTYGROUP                  0x8200
#define CMNT_FPXSCANNERMANUFACTURERNAME                  148
#define CMNT_FPXSCANNERMODELNAME                         149
#define CMNT_FPXSCANNERSERIALNUMBER                      150
#define CMNT_FPXSCANSOFTWARE                             151
#define CMNT_FPXSCANSOFTWAREREVISIONDATE                 152
#define CMNT_FPXSERVICEBUREAUORGNAME                     153
#define CMNT_FPXSCANOPERATORID                           154
#define CMNT_FPXSCANDATE                                 155
#define CMNT_FPXLASTMODIFIEDDATE                         156
#define CMNT_FPXSCANNERPIXELSIZE                         157
#define CMNT_FPXSCANDEVICEPROPERTYGROUP1                 CMNT_FPXSCANNERMANUFACTURERNAME
#define CMNT_FPXSCANDEVICEPROPERTYGROUP2                 CMNT_FPXSCANNERPIXELSIZE

#define CMNT_SZTITLE                                     175   // Title or caption for image
#define CMNT_SZDISCLAIMER                                176   // Legal Disclaimer
#define CMNT_SZWARNING                                   177   // Warning of nature of content
#define CMNT_MISC                                        178   // Miscellaneous comment
#define CMNT_J2K_BINARY                                  179   // Jpeg 2000 binary comment
#define CMNT_J2K_LATIN                                   180   // Jpeg 2000 Latin comment

// IPTC comments
#define IPTC_SEPARATOR                                   1     // '\001' is a separator used for repeatable comments

#define CMNT_IPTC_FIRST                                  181   // The first IPTC comment
#define CMNT_IPTC_VERSION                                181   // The version of IPTC comments (read-only)
#define CMNT_IPTC_OBJECTTYPEREFERENCE                    182
#define CMNT_IPTC_OBJECTATTRIBUTEREFERENCE               183
#define CMNT_IPTC_OBJECTNAME                             184
#define CMNT_IPTC_EDITSTATUS                             185
#define CMNT_IPTC_EDITORIALUPDATE                        186
#define CMNT_IPTC_URGENCY                                187
#define CMNT_IPTC_SUBJECTREFERENCE                       188
#define CMNT_IPTC_CATEGORY                               189
#define CMNT_IPTC_SUPPLEMENTALCATEGORY                   190
#define CMNT_IPTC_FIXTUREIDENTIFIER                      191
#define CMNT_IPTC_KEYWORDS                               192
#define CMNT_IPTC_CONTENTLOCATIONCODE                    193
#define CMNT_IPTC_CONTENTLOCATIONNAME                    194
#define CMNT_IPTC_RELEASEDATE                            195
#define CMNT_IPTC_RELEASETIME                            196
#define CMNT_IPTC_EXPIRATIONDATE                         197
#define CMNT_IPTC_EXPIRATIONTIME                         198
#define CMNT_IPTC_SPECIALINSTRUCTIONS                    199
#define CMNT_IPTC_ACTIONADVISED                          200
#define CMNT_IPTC_REFERENCESERVICE                       201
#define CMNT_IPTC_REFERENCEDATE                          202
#define CMNT_IPTC_REFERENCENUMBER                        203
#define CMNT_IPTC_DATECREATED                            204
#define CMNT_IPTC_TIMECREATED                            205
#define CMNT_IPTC_DIGITALCREATIONDATE                    206
#define CMNT_IPTC_DIGITALCREATIONTIME                    207
#define CMNT_IPTC_ORIGINATINGPROGRAM                     208
#define CMNT_IPTC_PROGRAMVERSION                         209
#define CMNT_IPTC_OBJECTCYCLE                            210
#define CMNT_IPTC_BYLINE                                 211
#define CMNT_IPTC_BYLINETITLE                            212
#define CMNT_IPTC_CITY                                   213
#define CMNT_IPTC_SUBLOCATION                            214
#define CMNT_IPTC_PROVINCE_STATE                         215
#define CMNT_IPTC_PRIMARYLOCATIONCODE                    216
#define CMNT_IPTC_PRIMARYLOCATIONNAME                    217
#define CMNT_IPTC_ORIGINALTRANSMISSIONREFERENCE          218
#define CMNT_IPTC_HEADLINE                               219
#define CMNT_IPTC_CREDIT                                 220
#define CMNT_IPTC_SOURCE                                 221
#define CMNT_IPTC_COPYRIGHT                              222
#define CMNT_IPTC_CONTACT                                223
#define CMNT_IPTC_CAPTION                                224
#define CMNT_IPTC_AUTHOR                                 225
#define CMNT_IPTC_LANGUAGEIDENTIFIER                     226
#define CMNT_IPTC_LAST                                   226   // The last IPTC comment

#define CMNT_SUBJECT                                     263
#define CMNT_KEYWORDS                                    264   // Keywords, separated by comma of semicolon. Equal to 'Keywords' entry in the PDF Info dictionary
#define CMNT_CREATOR                                     265   // The name of the application that created the original file. Equal to the 'Creator' entry in PDF Info dictionary
#define CMNT_CREATIONDATE                                266   // Date and time the file was originally created
#define CMNT_MODIFICATIONDATE                            267   // Date and time the file was last modified

#define CMNT_LAST                                        267   // Last defined number for comments

#define CMNT_ALL                                         0xFFFF


// Tags
#define TAG_BYTE        1
#define TAG_ASCII       2
#define TAG_SBYTE       6
#define TAG_UNDEFINED   7
#define TAG_SHORT       3
#define TAG_SSHORT      8
#define TAG_LONG        4
#define TAG_SLONG       9
#define TAG_FLOAT       11
#define TAG_RATIONAL    5
#define TAG_SRATIONAL   10
#define TAG_DOUBLE      12
#define TAG_IFD         13
#define TAG_LONG8       16 // BigTIFF only
#define TAG_SLONG8      17 // BigTIFF only
#define TAG_IFD8        18 // BigTIFF only

// Flags that make up EXTENSIONLIST.uFlags
#define EXTENSION_STAMP    0x0001   // contains a stamp. Most likely suitable for LCD displays
#define EXTENSION_AUDIO    0x0002   // contains audio data

// Markers type
#define MARKER_SOS   0xDA
#define MARKER_APP0  0xE0
#define MARKER_APP1  0xE1
#define MARKER_APP2  0xE2
#define MARKER_COM   0xFE

#define MARKER_RST0  0xD0
#define MARKER_RST7  0xD7

#define MARKER_SOI   0xD8
#define MARKER_EOI   0xD9

// Flags for L_WriteMetaData
#define METADATA_COMMENTS  0x0001   // Write comments
#define METADATA_TAGS      0x0002   // Write tags
#define METADATA_MARKERS   0x0004   // Write markers
#define METADATA_GEOKEYS   0x0008   // Write GeoKeys
#define METADATA_ALL       0xFFFF   // Write all metadata

// Flags for L_LoadFile
#define LOADFILE_ALLOCATE           0x00000001  // Allocate image memory
#define LOADFILE_STORE              0x00000002  // Auto-store image lines
#define LOADFILE_FIXEDPALETTE       0x00000004  // Allow fixed palettes only
#define LOADFILE_NOINTERLACE        0x00000008  // Don't send interlaced lines
#define LOADFILE_ALLPAGES           0x00000010  // Load all file pages
#define LOADFILE_NOINITBITMAP       0x00000020  // Don't initialize the bitmap handle
#define LOADFILE_COMPRESSED         0x00000040  // Allow compressed 1 bit images
#define LOADFILE_SUPERCOMPRESSED    0x00000080  // Load 1-bit or 24-bit images supercompressed
#define LOADFILE_TILED              0x00000200  // Create tiled bitmap first
#define LOADFILE_NOTILED            0x00000400  // Do not use tiled bitmaps
#define LOADFILE_DISK               0x00000800  // Use Disk (if possible)
#define LOADFILE_NODISK             0x00001000  // Do not use disk
#define LOADFILE_MULTITHREADED      0x00002000  // Use Multithreaded load (equivalent to ELO2_MULTITHREADED)
#define LOADFILE_CALLINANYTHREAD    0x00004000  // You can call the FILEREADCALLBACK from any thread

// Flags for L_SaveFile
#define SAVEFILE_FIXEDPALETTE       0x00000001  // Save with Fixed Palette
#define SAVEFILE_OPTIMIZEDPALETTE   0x00000002  // Save with Bitmap's Palette
#define SAVEFILE_MULTIPAGE          0x00000004  // Save as multipage
#define SAVEFILE_GRAYOUTPUT         0x00000008  // Save output bitmap as grayscale

// Preset Q factors (for LEAD CMP only)
#define PQ1    -1    // Perfect quality option 1
#define PQ2    -2    // Perfect quality option 2
#define QFS    -3    // Quality far more important than size
#define QMS    -4    // Quality more important than size
#define QS     -5    // Quality and size are equally important
#define SQS    -6    // Size more important than quality -Sharp
#define SQT    -7    // Size more important than quality - Less Tilling
#define MCQ    -8    // Max Compression, keeping quality as good as possible
#define MC     -9    // Max compression
#define CMP_CUSTOM_QUALITY_FACTOR (MC - 1)

// FILE_ABC and FILE_TIF_ABC quality factor
#define ABCQ_LOSSLESS         0  // Lossless compression. This option compresses a 1-bit file and
                                 // maintains image data unchanged
                                 // Highest quality
#define ABCQ_VIRTUALLOSSLESS  1  // Lossy compression. This option removes image noisy pixels and
                                 // compresses it at a smaller file size than ABCQ_LOSSLESS
#define ABCQ_REMOVEBORDER     2  // Lossy compression. This option removes image border if it exists
                                 // and compresses it at a smaller file size than ABCQ_VIRTUALLOSSLESS
#define ABCQ_ENHANCE          3  // Lossy compression
                                 // This option cleans up the image, removes its border if it exists and
                                 // compresses it at a smaller file size than ABCQ_REMOVEBORDER
#define ABCQ_MODIFIED1        4  // Lossy compression. This option cleans up the image, removes its
                                 // border if it exists and compresses it at a smaller file size than ABCQ_ENHANCE
                                 // However, it may distort some text or straight lines
#define ABCQ_MODIFIED1_FAST   5  // Same as ABCQ_MODIFIED1 without the border remove or image clean processes
#define ABCQ_MODIFIED2        6  // Lossy compression. This option cleans up the image, removes its border
                                 // if it exists and compresses it at a smaller file size than ABCQ_MODIFIED1
                                 // However, it may distort some text or straight lines
#define ABCQ_MODIFIED2_FAST   7  // Same as ABCQ_MODIFIED2 without the border remove or image clean processes
#define ABCQ_MODIFIED3        8  // Lossy compression. Provides faster encode and decode speed than ABCQ_MODIFIED1
                                 // or ABCQ_MODIFIED2. Provides the maximum compression
#define ABCQ_MODIFIED3_FAST   9  // Same as ABCQ_MODIFIED3 without the border remove or image clean processes
#define ABCQ_LOSSLESS_FAST    10 // Faster lossless compression than ABCQ_LOSSLESS. This option compresses a 1-bit
                                 // file and maintains image data unchanged.  Highest quality.  Does not produce
                                 // compression ratios as high as ABCQ_LOSSLESS
#define ABCQ_LOSSY_FAST       11 // Lossy compression.  This is the fastest ABC lossy compression option.  Does
                                 // not produce compression ratios as high as the other lossy options

// Flags for LOADINFO.Flags
#define LOADINFO_TOPLEFT         0x00000001  // Image has TOP_LEFT View Perspective
#define LOADINFO_ORDERRGB        0x00000002  // Image has ORDERRGB Color Order
#define LOADINFO_WHITEONBLACK    0x00000004  // Image is white-on-black
#define LOADINFO_LSB             0x00000008  // Image is Least Significant Bit first fill order
#define LOADINFO_TOPLEFT90       0x00000010  // Image has TOP_LEFT90 View Perspective
#define LOADINFO_TOPLEFT270      0x00000020  // Image has TOP_LEFT270 View Perspective
#define LOADINFO_REVERSE         0x00000040  // Reverse (mirror) each line

#define LOADINFO_TOPLEFT180      0x00000080  // Image has TOP_LEFT180 View Perspective
#define LOADINFO_BOTTOMLEFT90    0x00000100  // Image has BOTTOM_LEFT90 View Perspective
#define LOADINFO_BOTTOMLEFT180   0x00000200  // Image has BOTTOM_LEFT180 View Perspective
#define LOADINFO_BOTTOMLEFT270   0x00000400  // Image has BOTTOM_LEFT270 View Perspective
#define LOADINFO_PAD4            0x00000800  // Each line is padded to a multiple of 4 bytes (raw data only)

#define LOADINFO_PALETTE         0x00001000  // For RAW data of 8 bpp or less, a palette is supplied in rgbQuad of LOADINF

#define LOADINFO_BITFIELDS       0x00002000  // For RAW BITFIELDS -- 3 color masks are specified in rgbColorMask of LOADINFO
#define LOADINFO_ORDERGRAY       0x00004000  // Image is grayscale
#define LOADINFO_MOTOROLAORDER   0x00008000  // Image bytes are in Motorola byte order (valid only for 16, 48 and 64-bit)
#define LOADINFO_ORDERROMM       0x00010000  // Image is ROMM
#define LOADINFO_SIGNED          0x00020000  // unsigned raw data
#define LOADINFO_ORDERRGB565     0x00040000  // Image has ORDERRGB 565 Color Order

// Flags that make up FILEINFO.Flags
#define FILEINFO_INTERLACED            0x00000001
#define FILEINFO_PROGRESSIVE           0x00000002  // progressive JPEG file
#define FILEINFO_HAS_STAMP             0x00000004
#define FILEINFO_HAS_GLOBALBACKGROUND  0x00000008
#define FILEINFO_HAS_GLOBALPALETTE     0x00000010
#define FILEINFO_HAS_GLOBALLOOP        0x00000020
#define FILEINFO_COMPRESSED            0x00000040  // the image can be loaded compressed
#define FILEINFO_NOPALETTE             0x00000080  // Grayscale TIF without a palette
#define FILEINFO_ROTATED               0x00000100  // Image with an extended ViewPerspective
#define FILEINFO_SIGNED                0x00000200  // Image with signed integer values for pixels
#define FILEINFO_LOSSLESSJPEG          0x00000400  // Internal flag, indicating that the JPEG file uses the lossless compression
                                                   // This flag will probably be removed in future versions
#define FILEINFO_HAS_ALPHA             0x00000800  // The file has alpha channel information
#define FILEINFO_FORMATVALID           0x00001000  // Only the format type is valid
#define FILEINFO_INFOVALID             0x00002000  // The whole FILEINFO structure is valid
#define FILEINFO_LINK                  0x00004000  // The file is a Windows 9x/NT link
#define FILEINFO_IFDVALID              0x00008000  // The IFD field is valid
#define FILEINFO_USELOADINFO           0x00010000  // Internal--do not use
#define FILEINFO_NO_RESOLUTION         0x00020000  // The file does not contain resolution information
#define FILEINFO_BIGTIFF               0x00040000  // The file is in BigTIFF format, which allows files to grow over 4GB
#define FILEINFO_NAMEVALID             0x00080000  // The name is valid
#define FILEINFO_CORRECTED_RESOLUTION  0x00100000  // The resolution was automatically corrected by the L_AutoFixBitmapResolutionOptions settings
#define FILEINFO_MULTILOADRES_PALETTE  0x00200000  // This file has a palette and multiple resolutions (most likely J2K compression). 
// The lower resolutions might be drastically different (grayscale) than the highest resolution (color).
#define FILEINFO_GRAY8_ALPHA           0x00400000  // This file contains 8-bit grayscale data + alpha
#define FILEINFO_PALETTE8_ALPHA        0x00800000  // This file contains 8-bit color palette data + alpha
#define FILEINFO_PORTFOLIO             0x01000000  // This file is portfolio (such as a PDF with collection schema)
#define FILEINFO_HAS_BOM               0x02000000  // This source file has a BOM
#define FILEINFO_HAS_ICC               0x04000000  // The file contains an embedded ICC profile
#define FILEINFO_FLOAT                 0x08000000  // Image with floating values for pixels

// Values for FILEINFO.ColorSpace
#define COLORSPACE_BGR     0
#define COLORSPACE_YUV     1  // same as YCbCr
#define COLORSPACE_CMYK    2
#define COLORSPACE_CIELAB  3

// Flags for L_FileInfo (not to make up FILEINFO.Flags!)
#define FILEINFO_TOTALPAGES      0x00000001  // fill in FILEINFO.TotalPages
#define FILEINFO_USEFILTERDATA   0x00000002  // The user wants to use filter data information to speed up the load

// Flags for the overlay callback functions
#define OVERLAY_LOADCALL   0x0001   // First try loading the overlay. call overlay callback if the load failed
#define OVERLAY_CALLLOAD   0x0002   // First call the overlay callback. Try loading the overlay file from disk
                                    // if the callback did not supply an overlay bitmap
#define OVERLAY_CALLONLY   0x0003   // Call the overlay callback. If there is no callback, there is no overlay
#define OVERLAY_LOADONLY   0x0004   // Attempt to load the overlay bitmap from disk. If the call fails, there is no overlay

// STARTDECOMPRESSDATA flags
#define DECOMPRESS_LSB              LOADINFO_LSB
#define DECOMPRESS_PAD4             LOADINFO_PAD4
#define DECOMPRESS_PALETTE          LOADINFO_PALETTE

#define DECOMPRESS_STRIPS           0  //compressed strip contains complete rows
#define DECOMPRESS_TILES            2

// Flags to indicate if beginning, end of a strip
#define DECOMPRESS_CHUNK_START      1
#define DECOMPRESS_CHUNK_END        2
#define DECOMPRESS_CHUNK_COMPLETE   (DECOMPRESS_CHUNK_START | DECOMPRESS_CHUNK_END)

// Flags for the LOADFILEOPTION structure
#define ELO_REVERSEBITS                0x00000001
#define ELO_GLOBALBACKGROUND           0x00000002
#define ELO_GLOBALPALETTE              0x00000004
#define ELO_GLOBALLOOP                 0x00000008
#define ELO_ROTATED                    0x00000010   // Load files with extended ViewPerspective - do not rotate them
#define ELO_IGNOREVIEWTRANSFORMS       0x00000020   // Load the image without the viewing transformations
#define ELO_IGNORECOLORTRANSFORMS      0x00000040   // Load the image without the color transformations
#define ELO_SIGNED                     0x00000080   // Load images with signed pixels without conversion
#define ELO_DISABLEMMX                 0x00000100   // (JPEG only) Do not use MMX optimized code
#define ELO_DISABLEP3                  0x00000200   // (JPEG only) Do not use P3-specific optimized code
#define ELO_USEIFD                     0x00000400   // (TIFF only) Use the IFD offset
#define ELO_FORCECIELAB                0x00000800   // (JPEG only) The file has CIELAB colorspace
#define ELO_USEBADJPEGPREDICTOR        0x00001000   // (JPEG only) Load lossless JPEG file using an incorrect predictor
#define ELO_IGNOREPHOTOMETRICINTERP    0x00002000   // (TIFF only) Use a default colorspace for the compression and ignore
                                                   // the value of the PhotometricInterpretation tag:
                                                   // For TIFF JPEG files:
                                                   // Use YUV colorspace for 1-3 samples per pixel, CMYK for 4 samples per pixel
                                                   // All other TIFF files:
                                                   //    Use RGB colorspace. Use this to disable the color conversion to RGB during the load process
#define ELO_FORCERGBFILE               0x00004000   // (JPEG only) The file has RGB colorspace.
#define ELO_MULTISPECTRALSCAN          0x00008000   // Use uXXXScan values info when loading NITF files
#define ELO_LOADCORRUPTED              0x00010000   // Attempt to load corrupted files
#define ELO_FORCE_EPS_THUMBNAIL        0x00020000   // (EPS only) Force loading of raster thumbnail data from postscript files
#define ELO_NITF_USE_MAX               0x00040000   // (NITF only) Use the maximum width and height
#define ELO_NITF_USE_MONODARK          0x00080000   // (NITF only) Use the mono dark process (to brightness the result image)
#define ELO_NITF_SHOW_OBJECT           0x00100000   // (NITF only) Make the object CGM available if exists
#define ELO_IGNOREVIEWPERSPECTIVE      0x00200000   // (TIF and Exif only) Ignore the view perspective stored in the file
#define ELO_USEFASTCONVERSION          0x00400000   // (TIF and CMP only) Use fast color conversion for CMYK and CieLAB
#define ELO_FAST                       0x00800000   // Use fast load. used by ABS filter
#define ELO_ALPHAINIT                  0x01000000   // Fill the alpha channel with 1's (0xFF)
#define ELO_COLOR_COMPONENT_ONLY       0x02000000   // (JPX only) When loading a frame, load only the color component
#define ELO_IGNORE_ADOBE_COLOR_TRANSFORM 0x04000000   // Ignore the Adobe marker containing color transformations (APPE)
#define ELO_ALLOW13BITLZWCODE          0x08000000   // Try to decode buggy LZW TIF files that contain 13-bit LZW codes
#define ELO_VECTOR_CONVERTED_UNITS     0x10000000   // Use converted units, instead of the input file's default
#define ELO_LOADOLDJBIG2FILES          0x20000000   // Used to load old JBIG2 files generated by LEAD JBIG2 filter. Some of these files generated incorrectly and this
                                                    // flag used to workaround the incorrect behavior and load it in correct way. This flag is not documented.
#define ELO_PREMULTIPLY_ALPHA          0x40000000   // When loading images with alpha channel, premultiply the alpha and apply it to the image data.

#define ELO2_MULTITHREADED             0x00000001   // Load using multithreaded code (used only for CMP/JPEG at the moment)
#define ELO2_USEFILTERDATA             0x00000004   // Use FILTERDATA information to speed up the load
#define ELO2_PREFERVECTOR              0x00000008   // Use vector processing, if supported
#define ELO2_AUTOFIXBITMAPRESOLUTION   0x00000010  // Use the options set in L_SetAutoFixBitmapResolutionOptions
#define ELO2_IGNORE_EMBEDDED_ICC_PROFILE 0x00000020  // Ignore the ICC profile embedded in the file (if any) - useful mainly for loading TIFF/JPEG CMYK/LAB files
#define ELO2_NO_IMAGE_DATA_CONVERSION  0x000000040 // Do not convert float or signed image data. Useful for getting the original floating point values store in the source file

// Flags for the SAVEFILEOPTION structure
#define ESO_REVERSEBITS                      0x00000001
#define ESO_NOSUBFILETYPE                    0x00000002
#define ESO_GLOBALBACKGROUND                 0x00000004
#define ESO_GLOBALPALETTE                    0x00000008
#define ESO_INTERLACED                       0x00000010
#define ESO_GLOBALLOOP                       0x00000020
#define ESO_NOPALETTE                        0x00000040  // save grayscale TIF without a palette
#define ESO_SAVEWITHSTAMP                    0x00000080  // save a stamp if format supports it
#define ESO_FIXEDPALETTESTAMP                0x00000100  // save fixed palette stamps
#define ESO_YCCSTAMP                         0x00000200  // save YCbCr stamps
#define ESO_REPLACEPAGE                      0x00000400  // Replace the page specified by PageNumber
#define ESO_INSERTPAGE                       0x00000800  // Insert image before the page specified by PageNumber
#define ESO_JPEGSTAMP                        0x00001000  // save JPEG compressed stamps
#define ESO_DISABLEMMX                       0x00002000  // Do not use MMX optimized code
#define ESO_SAVEOLDJTIF                      0x00004000  // Write old style JTIF files
#define ESO_NOPAGENUMBER                     0x00008000  // Do not save/update the PageNumber tag
#define ESO_DISABLEP3                        0x00010000  // Do not use P3-specific optimized code
#define ESO_USEIFD                           0x00020000  // Use the IFD offset
#define ESO_MOTOROLAORDER                    0x00040000  // When possible, save files in Motorola byte order
#define ESO_WITHOUTTIMESTAMP                 0x00080000  // save without time stamp*/

#define ESO_PDF_TEXT_ENCODING_NONE           0x00000000  // PDF, no text encoding
#define ESO_PDF_TEXT_ENCODING_ASCII_BASE85   0x00100000  // PDF, ASCII BASE85 text encoding
#define ESO_PDF_TEXT_ENCODING_ASCII_HEX      0x00200000  // PDF, ASCII HEX text encoding

#define ESO_PDF_TEXT_ENCODING_MASK           0x00300000  // mask of the flags used for PDF text encoding
#define ESO_PAD4                             0x00400000  // Each line is padded to a multiple of 4 bytes (raw data only)
#define ESO_PLT_BEZIER_CURVES                0x00800000  // PLT filter should save bezier curves
#define ESO_PDF_SAVE_USE_BITMAP_DPI          0x01000000  // Use bitmap  DPI in calculating page dimensions when saving a PDF file
#define ESO_PHOTOMETRICINTERPRETATIONVALID   0x02000000
#define ESO_TILEINFOVALID                    0x04000000  // Use TileWidth and TileHeight when saving TIFF files
#define ESO_USEDITHERINGMETHOD               0x08000000  // Use the DitheringMethod in the BITMAPHANDLE
#define ESO_PRESERVEPALETTE                  0x10000000  // Preserve the palette when saving TIFF CCITT files (might decrease compression ratio)
#define ESO_PDF_SAVE_LOW_MEMORY_USAGE        0x20000000  // Try to use less memory when creating a PDF file with JPEG or Fax compression
#define ESO_GENERATEGLOBALPALETTE            0x40000000  // Generate global palette when saving GIF files
#define ESO_USEPREDICTOR                     0x80000000  // Use a predictor when saving LZW data

// Flags making up SAVEFILEOPTION.Flags2
#define ESO2_NITF                            0x00000001  // Save the images compatible with NITF requirements
#define ESO2_SAVEPLANAR                      0x00000002  // Save the TIF CMYK images as planar (instead of chunky)
#define ESO2_NOLZWAUTOCLEAR                  0x00000004  // Do not automatically insert CLEAR codes during LZW compression
#define ESO2_ALPHAINIT                       0x00000010  // Fill the alpha channel with 1's (0xFF)
#define ESO2_ANNDOTNETPROPS                  0x00000020  // For internal use only
#define ESO2_J2K_DISABLE_8BITS               0x00000040  // For internal use only
#define ESO2_XPS_SAVE_USE_BITMAP_DPI         0x00000080  // Use the bitmap's DPI when saving to XPS
#define ESO2_PDFA_PROFILE                    0x00000100  // When saving as PDF, save PDF files as PDF/A
#define ESO2_PDF_V14                         0x00000200  // When saving as PDF, save PDF files as PDF 1.4
#define ESO2_PDF_V15                         0x00000400  // When saving as PDF, save PDF files as PDF 1.5
#define ESO2_ENDWITH3EOL                     0x00000800  // End Fax G3 (1D/2D) files with 3 EOLs (00 01 00 01 00 01) instead of EOL EOFB (00 01 00 10 01)
#define ESO2_OPTIMIZEDHUFFMAN                0x00001000  // Save JPEG files with optimized Huffman tables
#define ESO2_PDF_V16                         0x00002000  // When saving as PDF, save PDF files as PDF 1.6
#define ESO2_PDF_V13                         0x00004000  // When saving as PDF, save PDF files as PDF 1.3
#define ESO2_PDF_V17                         0x00008000  // When saving as PDF, save PDF files as PDF 1.7
#define ESO2_NOGRAYCONVERT                   0x00010000  // When saving as JPX, Save 12/16 bit grayscale data and can handle LowBit, HighBit, etc
#define ESO2_BIGTIFF                         0x00020000  // Save TIF files using the BigTiff format, which allows TIFF files to exceed 4GB
#define ESO2_PDF_LINEARIZED                  0x00080000  // Save linearized PDF files (web-optimized)
#define ESO2_ADJUST_STAMP_SIZE               0x00100000  // Decrease stamp size so it fits inside the StampWidth x StampHeight rectangle

// Values that can be used for LOADFILEOPTION.Passes. These values will
// generate default Progressive JPEG/CMP files (usually 10 passes/file) on
// save and specifies how many passes to generate while decoding
// Progressive JPEG/CMP files.
#define CALLBACK_ONCE               0  // callback just once at the end
#define CALLBACK_WHEN_MEANINGFUL   -1 // callback with only significant scans
#define CALLBACK_ALWAYS            -2 // callback with all scans

// Flags for the FILEREADCALLBACK function
#define FILEREAD_FIRSTPASS    0x0001
#define FILEREAD_LASTPASS     0x0002
#define FILEREAD_FIRSTROW     0x0004
#define FILEREAD_LASTROW      0x0008
#define FILEREAD_COMPRESSED   0x0010
#define FILEREAD_CLIPVERT     0x0020   // internal flag - data contains only the requested lines
#define FILEREAD_CLIPHORZ     0x0040   // internal flag - data contains only the requested columns
#define FILEREAD_UPDATELUT    0x0080

#define LOADCUSTOMFILEOPTION_FLIPTILES    0x0001

// J2K/new CMW Options
// Limitations imposed by the standard
#define J2K_MAX_COMPONENTS_NUM                     3
#define J2K_MAX_DECOMP_LEVEL                       20

// Progressions Order
#define J2K_LAYER_RESOLUTION_COMPONENT_POSITION    0
#define J2K_RESOLUTION_LAYER_COMPONENT_POSITION    1
#define J2K_RESOLUTION_POSITION_COMPONENT_LAYER    2
#define J2K_POSITION_COMPONENT_RESOLUTION_LAYER    3
#define J2K_COMPONENT_POSITION_RESOLUTION_LAYER    4

// Photo CD
#define L_PCD_BASE_OVER_64    0  // 64 x   96
#define L_PCD_BASE_OVER_16    1  // 128 x  192
#define L_PCD_BASE_OVER_4     2  // 256 x  384
#define L_PCD_BASE            3  // 512 x  768
#define L_PCD_4BASE           4  // 1024 x 1536
#define L_PCD_16BASE          5  // 2048 x 3072

// L_2DSetViewMode flags
#define L2D_USE_BEST          0
#define L2D_USE_WIDTH_HEIGHT  1
#define L2D_USE_WIDTH         2
#define L2D_USE_HEIGHT        3

// Lossless rotate functions and defines
#define FILE_TRANSFORM_FLIP         0x0001
#define FILE_TRANSFORM_REVERSE      0x0002

#define FILE_TRANSFORM_ROTATE90     0x0004
#define FILE_TRANSFORM_ROTATE180    0x0008
#define FILE_TRANSFORM_ROTATE270    0x000C
#define FILE_TRANSFORM_ROTATEMASK   0x000C

// PDF Options Flags for FILEPDFOPTIONS.uFlags
#define PDF_DISABLE_CROPPING        0x00000001
#define PDF_DETECT_TEXT_DECORATION  0x00000002  // Analyze all lines in the file and convert them to underline/strikethrough text decorations whenever appropriate
#define PDF_ENHANCE_THIN_LINES      0x00000004  // If set, enhance thin lines (this is the default). If not set, thin lines are not enhanced
#define PDF_USE_FIXED_SIZE          0x00000008  // (EPS files only) If set, load EPS files with Postscript information using a fixed A4 size (8.5" x 11"). This might result in cropping
                                                // If not set, EPS files are loaded using information from the bounding box
#define PDF_DISABLE_CIECOLORS       0x00000010
#define PDF_ENABLE_INTERPOLATE      0x00000100
#define PDF_USE_PDFENGINE           0x00001000

// Deprecated flags - do not use
#define PDF_HIDE_NOAP_ANNOTATIONS   0x00010000 // Deprecated - Hide annotation objects that have no appearance stream
#define PDF_HIDE_ALL_ANNOTATIONS    0x00100000 // Deprecated use PDF_HIDE_ANNOTATIONS instead - hide all annotation objects

// Controls showing/hiding the annotations/form fields/digital signature when loading a PDF as a bitmap or SVG
#define PDF_HIDE_ANNOTATIONS        0x00100000 // Hide annotation objects
#define PDF_HIDE_FORMFIELDS_AND_DIGITALSIGNATURES 0x00200000 // (deprecated) Hide form fields and digital signatures
#define PDF_HIDE_FORMFIELDS         0x00400000 // Hide form fields
#define PDF_HIDE_DIGITALSIGNATURES  0x00800000 // Hide digital signatures

#define PDF_DROP_IMAGEOVERTEXT      0x01000000 // If the PDF file is ImageOverText then the image will be dropped
#define PDF_LOAD_CORRUPTED          0x02000000 // Enable loading PDF files with corrupted image data without throwing errors

// FILTERINFO flags
#define FILTERINFO_IGNORED             0x0001
#define FILTERINFO_FIXED               0x0002
#define FILTERINFO_DYNAMIC             0x0000
#define FILTERINFO_LOADMASK            0x0003

#define FILTERINFO_PRESENT             0x0004
#define FILTERINFO_CHECKEDBYFILEINFO   0x0008
#define FILTERINFO_SLOWFILEINFO        0x0010

#define FILTERINFO_FREEALL             0x0020

#define JBIG2_REMOVE_MARKER               0x0001
#define JBIG2_REMOVE_HEADER_SEGMENT       0x0002
#define JBIG2_REMOVE_EOP_SEGMENT          0x0004
#define JBIG2_REMOVE_EOF_SEGMENT          0x0008
#define JBIG2_IMAGE_TPON                  0x0010
#define JBIG2_ENABLE_DICTIONARY           0x0100
#define JBIG2_TEXT_REMOVEUNREPEATEDSYM    0x1000
#define JBIG2_TEXT_KEEPALLSYM             0x2000

#define FLAG_JBIG2_REMOVE_MARKER          JBIG2_REMOVE_MARKER
#define FLAG_JBIG2_REMOVE_HEADER_SEGMENT  JBIG2_REMOVE_HEADER_SEGMENT
#define FLAG_JBIG2_REMOVE_EOP_SEGMENT     JBIG2_REMOVE_EOP_SEGMENT
#define FLAG_JBIG2_REMOVE_EOF_SEGMENT     JBIG2_REMOVE_EOF_SEGMENT
#define FLAG_JBIG2_TPON                   JBIG2_IMAGE_TPON

#if !defined(LEAD_DEFINES_ONLY)

typedef enum
{
   PME_MINISWHITE = 0,  // min value is white
   PME_MINISBLACK = 1,  // min value is black
   PME_RGB        = 2,  // RGB color model
   PME_PALETTE    = 3,  // color map indexed
   PME_MASK       = 4,  // $holdout mask
   PME_SEPARATED  = 5,  // !color separations
   PME_YCBCR      = 6,  // !CCIR 601
   PME_CIELAB     = 8,  // !1976 CIE L*a*b*
}
PHOTMTRICINTERP, *pPHOTMTRICINTERP;

#define FILEPDFOPTIONS_MAX_PASSWORD_LEN   64

// Flags for PDF Encryption
// Printing
#define PDF_SECURITYFLAGS_REV2_PRINTDOCUMENT          0x00000004
#define PDF_SECURITYFLAGS_REV3_PRINTFAITHFUL          0x00000800  // 128 bit only

// Editing
#define PDF_SECURITYFLAGS_REV2_MODIFYDOCUMENT         0x00000008

// Copying
#define PDF_SECURITYFLAGS_REV2_EXTRACTTEXT            0x00000010
#define PDF_SECURITYFLAGS_REV3_EXTRACTTEXTGRAPHICS    0x00000200  // 128 bit only

// Annotation
#define PDF_SECURITYFLAGS_REV2_MODIFYANNOTATION       0x00000020

// Form filling
#define PDF_SECURITYFLAGS_REV3_FILLFORM               0x00000100

// Assembly:
#define PDF_SECURITYFLAGS_REV3_ASSEMBLEDOCUMENT       0x00000400  // 128 bit only

// Ways of controlling JPEG2000 the compression
typedef enum _J2KCOMPRESSIONCONTROL
{
   J2K_COMPRESSION_LOSSLESS   = 0,  // lossless compression
   J2K_COMPRESSION_RATIO      = 1,  // use fCompressionRatio
   J2K_COMPRESSION_TARGETSIZE = 2,  // use uTargetFileSize
   J2K_COMPRESSION_QFACTOR    = 3,  // use qFactor
}
J2KCOMPRESSIONCONTROL, *pJ2KCOMPRESSIONCONTROL;

// Ways of how to set the JPEG2000 Region Of Interest
typedef enum _J2KREGIONOFINTEREST
{
   J2K_USE_LEAD_REGION  = 0,  // Use LEAD bitmap region
   J2K_USE_OPTION_RECT  = 1,  // Use rcROI member of FILEJ2KOPTIONS
}
J2KREGIONOFINTEREST, *pJ2KREGIONOFINTEREST;

typedef enum
{
   J2KPRECINCTSIZE_FULL             =  0,
   J2KPRECINCTSIZE_UNIFORM_64       =  1,
   J2KPRECINCTSIZE_UNIFORM_128      =  2,
   J2KPRECINCTSIZE_UNIFORM_256      =  3,
   J2KPRECINCTSIZE_UNIFORM_512      =  4,
   J2KPRECINCTSIZE_UNIFORM_1024     =  5,
   J2KPRECINCTSIZE_UNIFORM_2048     =  6,
   J2KPRECINCTSIZE_HIERARCHICAL1_64  =  7,
   J2KPRECINCTSIZE_HIERARCHICAL1_128 =  8,
   J2KPRECINCTSIZE_HIERARCHICAL1_256 =  9,
   J2KPRECINCTSIZE_HIERARCHICAL1_512 = 10,
   J2KPRECINCTSIZE_HIERARCHICAL2_64  = 11,
   J2KPRECINCTSIZE_HIERARCHICAL2_128 = 12,
   J2KPRECINCTSIZE_HIERARCHICAL2_256 = 13,
   J2KPRECINCTSIZE_HIERARCHICAL2_512 = 14,
}
J2KPRECINCTSIZE, *pJ2KJ2KPRECINCTSIZE;


#if defined(LT_COMP_VECTOR)
#define AUTOCADFILES_COLORSCHEME_BLACKONWHITE   0
#define AUTOCADFILES_COLORSCHEME_WHITEONBLACK   1
#endif // #if defined(LT_COMP_VECTOR)

typedef enum _CHANNELTYPE
{
   ALPHA_CHANNEL = 0,
   RED_CHANNEL,
   GREEN_CHANNEL,
   BLUE_CHANNEL,
   CYAN_CHANNEL,
   MAGENTA_CHANNEL,
   YELLOW_CHANNEL,
   KEY_CHANNEL,
   GRAY_CHANNEL,
   BITMAP_CHANNEL,
   LIGHTNESS_CHANNEL,
   A_CHANNEL,
   B_CHANNEL
} CHANNELTYPE;

typedef enum
{
   // Default mode, use original size
   RASTERIZEDOC_SIZEMODE_NONE,
   // Fit in page width and height keeping the aspect ratio
   RASTERIZEDOC_SIZEMODE_FIT,
   // Like FIT and if the original size is smaller, make it bigger
    RASTERIZEDOC_SIZEMODE_FIT_ALWAYS,
   // Make the image width page width and calculate height using aspect ratio
   RASTERIZEDOC_SIZEMODE_FIT_WIDTH,
   // Stretch the image to be exactly page width and height
   RASTERIZEDOC_SIZEMODE_STRETCH
}
RASTERIZEDOC_SIZEMODE;

// Use paper dimensions obtained from user to draw the worksheet as following if the
// sheet dimension is larger than the paper dimensions obtained from user then the
// sheet will be divided to multiple pages each of which has the same page dimension
// obtained form user (the sheet will be rendered as multiple of sheets). If the sheet
// size is less than page dimensions obtained from user then it will be drawn on
// single page.
// If this flag is not set, then use paper dimensions obtained from user to draw the
// worksheet at if the size of paper dimension is less than the sheet size then the sheet is cropped.
#define EXCEL_FLAGS_MULTIPAGE_SHEET          0x00000001
// If this flag is set, the rendered page width/height chosen by the user will be approximated to
// nearest cell width/height to avoid clipping excel document cell. This means the resultant page
// width/height will be either equal or more the specified page width/height depending on cell
// dimension. This flag has no effect if EXCEL_FLAGS_MULTIPAGE_SHEET is not set.
#define EXCEL_FLAGS_DISABLE_CELL_CLIPPING    0x00000002
#define EXCEL_FLAGS_SHOW_HIDDEN_SHEETS       0x00000004
// If this flag is set, then the sheet will be rasterized or converted based on full sheet width, which
// means, it will not consider the width value which is in RASTERIZEDOCOPTIONS, but the actual sheet width,
// only height value will be considered.
// This flag is V20.0 flag.
// This flag is effective only if EXCEL_FLAGS_MULTIPAGE_SHEET is set.
// It should be set as default for converter.
#define EXCEL_FLAGS_MULTIPAGE_USESHEETWIDTH  0x00000008
// If this flag is set then the sheet will be cut into multiple pages moving up to down first then left to
// right, if it is not set then the sheet will be cut into pages left to right first then go down.This flag
// is effective only if EXCEL_FLAGS_MULTIPAGE_SHEET is set.
#define EXCEL_FLAGS_PAGEORDER_DOWNTHENOVER   0x00000010
// If this flag is set, then consider margins value which are set in RASTERIZEDOCOPTIONS. Currently this flag
// is effective only in Xlsx.
#define EXCEL_FLAGS_MULTIPAGE_ENABLEMARGINS  0x00000020
// If this flag is set, then the sheet's grid lines will be rendered.
#define EXCEL_FLAGS_SHOWGRIDLINES            0x00000040

// deprecated flags
#define XLS_FLAGS_MULTIPAGE_SHEET            EXCEL_FLAGS_MULTIPAGE_SHEET
#define XLS_FLAGS_DISABLE_CELL_CLIPPING      EXCEL_FLAGS_DISABLE_CELL_CLIPPING
#define XLS_FLAGS_SHOW_HIDDEN_SHEET          EXCEL_FLAGS_SHOW_HIDDEN_SHEETS
#define XLS_FLAGS_MULTIPAGE_USESHEETWIDTH    EXCEL_FLAGS_MULTIPAGE_USESHEETWIDTH
#define XLS_FLAGS_PAGEORDER_DOWNTHENOVER     EXCEL_FLAGS_PAGEORDER_DOWNTHENOVER
#define XLS_FLAGS_MULTIPAGE_ENABLEMARGINS    EXCEL_FLAGS_MULTIPAGE_ENABLEMARGINS
#define XLS_FLAGS_SHOWGRIDLINES              EXCEL_FLAGS_SHOWGRIDLINES

// If this flags, slides marked as hidden will still be visible (this is on by default)
#define POWERPOINT_FLAGS_SHOW_HIDDEN_SLIDES  0x00000001

// Flags for L_ReadFileTags, L_ReadFileGeoKeys and L_ReadFileComments
#define READFILEMETADATA_NOMEMORY   0x01

// Flags for LAYERINFO.uLayerFlags. These are output only
#define LAYERINFO_TRANSPARENCYPROTECTED   0x01
#define LAYERINFO_VISIBLE                 0x02
#define LAYERINFO_OBSOLETE                0x04
#define LAYERINFO_PSD5ORLATER             0x08

typedef enum
{
   RASTERPDFVERSION_V12,
   RASTERPDFVERSION_V14,
   RASTERPDFVERSION_PDFA,
   RASTERPDFVERSION_V15,
   RASTERPDFVERSION_V16,
   RASTERPDFVERSION_V13,
   RASTERPDFVERSION_V17
}
RASTERPDFVERSION;

typedef enum
{
   VFF_VIEW_UPTODOWN,         //X-axis
   VFF_VIEW_DOWNTOUP,         //X-axis
   VFF_VIEW_LEFTTORIGHT,      //Y-axis
   VFF_VIEW_RIGHTTOLEFT,      //Y-axis
   VFF_VIEW_FRONTTOREAR,      //Z-axis
   VFF_VIEW_REARTOFRONT       //Z-axis
}
VFF_VIEW;

typedef struct _FILEVFFOPTIONS
{
   L_UINT uStructSize;
   VFF_VIEW View;
   L_UINT32 uFlags;
}
FILEVFFOPTIONS, *pFILEVFFOPTIONS;

// Flags for FILEPSTOPTIONS.uFlags.
#define PST_FLAGS_MESSAGE_PLAINTEXT       0x01

#if defined(LT_COMP_VECTOR)
typedef struct _VECTOROPTIONS
{
   L_UINT uStructSize;
   VEC2DOPTIONS Vec2DOptions; // viewport mode and dimensions
   L_INT nBitsPerPixel;
   L_BOOL bForceBackgroundColor;
   L_COLORREF BackgroundColor;
} VECTOROPTIONS, *pVECTOROPTIONS;
#endif // #if defined(LT_COMP_VECTOR)

#if defined(LT_COMP_SVG)
#define L_LOADSVGOPTIONS_NONE                0x00  // the created svg file may have text as real text spans or paths depending on the input document, the file still may have images or other shapes
#define L_LOADSVGOPTIONS_ALLOWPOLYLINETEXT   0x01  // the created svg file may have text represented as polyline or text. This flag should not be used.
#define L_LOADSVGOPTIONS_DROPSHAPES          0x02  // the created svg will drop all the shapes
#define L_LOADSVGOPTIONS_DROPIMAGES          0x04  // the created svg will drop all the images
#define L_LOADSVGOPTIONS_DROPTEXT            0x08  // the created svg will drop all the text
#define L_LOADSVGOPTIONS_FORCONVERSION       0x10  // the created svg will be optimized for conversion. The text elements are not massaged for view optimization
#define L_LOADSVGOPTIONS_IGNOREXMLPARSINGERRORS 0x20 // try to load SVG documents that contain incorrect XML data
#define L_LOADSVGOPTIONS_FORCETEXTPATH       0x01  // the created svg will have the text as paths. Default is the output file may have text as both text spans and path objects depending on the input document. Currently supported by PDF documents only
#define L_LOADSVGOPTIONS_FORCEREALTEXT       0x40  // the created svg will have the text as real text spans. Default is the output file may have text as both text spans and path objects depending on the input document. Currently supported by PDF documents only

typedef struct _LOADSVGOPTIONS
{
   L_UINT uStructSize;
   L_UINT32 uFlags;           // L_LOADSVGOPTIONS_XXX
   L_SvgNodeHandle SvgHandle; // Load into this SVG
   L_UINT32 uMaximumElements; // Maximum number of elements, if the SVG has more than this value then load will fail with error ERROR_USER_ABORT
}
LOADSVGOPTIONS, *pLOADSVGOPTIONS;
#endif // #if defined(LT_COMP_SVG)

#define L_FILEMETADATAKEY_TITLE           L_TEXT("title")
#define L_FILEMETADATAKEY_SUBJECT         L_TEXT("subject")
#define L_FILEMETADATAKEY_AUTHOR          L_TEXT("author")
#define L_FILEMETADATAKEY_KEYWORDS        L_TEXT("keywords")
#define L_FILEMETADATAKEY_CREATE_DATE     L_TEXT("create_date")
#define L_FILEMETADATAKEY_MODIFIED_DATE   L_TEXT("modified_date")
#define L_FILEMETADATAKEY_REVISION_NUMBER L_TEXT("revision_number")
#define L_FILEMETADATAKEY_LAST_SAVED_BY   L_TEXT("last_saved_by")

#define FILEHTMLLOADOPTIONS_DOMAINWHITELISTSIZE 2024

typedef enum _L_HTMLENGINE
{
   L_HTMLENGINE_AUTO,
   L_HTMLENGINE_IE,
   L_HTMLENGINE_WEBKIT
}
L_HTMLENGINE;

typedef struct _FILEHTMLLOADOPTIONSA
{
   L_UINT uStructSize;
   L_CHAR szDomainWhitelist[FILEHTMLLOADOPTIONS_DOMAINWHITELISTSIZE];
   L_BOOL  bEnableJS;
   L_HTMLENGINE HtmlEngine;
#if defined(LEADTOOLS_V22_OR_LATER)
   L_UINT uFlags;    // Reserved for future use. Set to 0 for now
#endif // #if defined(LEADTOOLS_V22_OR_LATER)
} FILEHTMLLOADOPTIONSA, *pFILEHTMLLOADOPTIONSA;

#if defined(FOR_UNICODE)
typedef struct _FILEHTMLLOADOPTIONS
{
   L_UINT uStructSize;
   L_TCHAR szDomainWhitelist[FILEHTMLLOADOPTIONS_DOMAINWHITELISTSIZE];
   L_BOOL  bEnableJS;
   L_HTMLENGINE HtmlEngine;
#if defined(LEADTOOLS_V22_OR_LATER)
   L_UINT uFlags;    // Reserved for future use. Set to 0 for now
#endif // #if defined(LEADTOOLS_V22_OR_LATER)
} FILEHTMLLOADOPTIONS, *pFILEHTMLLOADOPTIONS;
#else
typedef FILEHTMLLOADOPTIONSA FILEHTMLLOADOPTIONS;
typedef pFILEHTMLLOADOPTIONSA pFILEHTMLLOADOPTIONS;
#endif

// Flags for L_EnumFileTags2
#define ENUM_TAGDATA    0x0001      // If this flag is set, the tag data will be passed to the ENUMTAGS2CALLBACK callback

/****************************************************************
   Macros
****************************************************************/

#define GET_TAG_SIZE(pTagSize, uType, ulCount) \
   switch(uType)                    \
   {                                \
   case TAG_BYTE:                   \
   case TAG_ASCII:                  \
   case TAG_SBYTE:                  \
   case TAG_UNDEFINED:              \
      *(pTagSize) = 1 * (ulCount);  \
      break;                        \
   case TAG_SHORT:                  \
   case TAG_SSHORT:                 \
      *(pTagSize) = 2 * (ulCount);  \
      break;                        \
   case TAG_LONG:                   \
   case TAG_SLONG:                  \
   case TAG_FLOAT:                  \
   case TAG_IFD:                    \
      *(pTagSize) = 4 * (ulCount);  \
      break;                        \
   case TAG_RATIONAL:               \
   case TAG_SRATIONAL:              \
   case TAG_DOUBLE:                 \
   case TAG_LONG8:                  \
   case TAG_SLONG8:                 \
   case TAG_IFD8:                   \
      *(pTagSize) = 8 * (ulCount);  \
      break;                        \
   default:                         \
      *(pTagSize) = 0;              \
      break;                        \
   }

// Helper macros for dealing with rotated bitmap info view perspectives
#define INFOROTATED(pInfo) ((pInfo)->ViewPerspective == TOP_LEFT90 || (pInfo)->ViewPerspective == TOP_LEFT270 || (pInfo)->ViewPerspective == BOTTOM_LEFT90 || (pInfo)->ViewPerspective == BOTTOM_LEFT270)
#define INFOBASIC(pInfo) ((pInfo)->ViewPerspective == TOP_LEFT || (pInfo)->ViewPerspective == BOTTOM_LEFT)
#define INFOWIDTH(pInfo) (INFOROTATED(pInfo)?(pInfo)->Height:(pInfo)->Width)
#define INFOHEIGHT(pInfo) (INFOROTATED(pInfo)?(pInfo)->Width:(pInfo)->Height)

// helper macro for copying filter data from one structure to another
#define COPY_FILTER_DATA(pDST, pSRC)                     \
{                                                        \
   (pDST)->pFilterData = (pSRC)->pFilterData;            \
   (pDST)->uFilterDataSize = (pSRC)->uFilterDataSize;    \
   (pDST)->nFilter = (pSRC)->nFilter;                    \
}

/****************************************************************
   Forward declarations
****************************************************************/
typedef struct _J2KVIDEOINFO *pJ2KVIDEOINFO;
typedef struct _LOADINFO *pLOADINFO;
typedef struct _FILEINFOA *pFILEINFOA;
#if defined(FOR_UNICODE)
typedef struct _FILEINFO *pFILEINFO;
#endif // #if defined(FOR_UNICODE)
typedef struct _CUSTOMTILEINFO *pCUSTOMTILEINFO;
typedef struct _FILEOVERLAYCALLBACKDATAA *pFILEOVERLAYCALLBACKDATAA;
#if defined(FOR_UNICODE)
typedef struct _FILEOVERLAYCALLBACKDATA *pFILEOVERLAYCALLBACKDATA;
#endif // #if defined(FOR_UNICODE)

/****************************************************************
   Callback prototypes
****************************************************************/
typedef L_INT (pEXT_CALLBACK FLTJ2KDECOMPRESSFRAME)(L_UCHAR* pInData , L_UCHAR* pOutData, pJ2KVIDEOINFO pJ2KInfo);

typedef L_INT (pEXT_CALLBACK COMPBUFFCALLBACK)(
   pBITMAPHANDLE pBitmap,
   L_UCHAR* pBuffer,
   L_SIZE_T uBytes,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK LOADINFOCALLBACK)(
   L_HFILE hFile,
   pLOADINFO pInfo,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK FILEREADCALLBACKA)(
   pFILEINFOA pFileInfo,
   pBITMAPHANDLE pBitmap,
   L_UCHAR* pBuffer,
   L_UINT uFlags,
   L_INT nRow,
   L_INT nLines,
   L_VOID* pUserData);
#if defined(FOR_UNICODE)
typedef L_INT (pEXT_CALLBACK FILEREADCALLBACK)(
   pFILEINFO pFileInfo,
   pBITMAPHANDLE pBitmap,
   L_UCHAR* pBuffer,
   L_UINT uFlags,
   L_INT nRow,
   L_INT nLines,
   L_VOID* pUserData);
#else
typedef FILEREADCALLBACKA FILEREADCALLBACK;
#endif // #if defined(FOR_UNICODE)

typedef L_INT (pEXT_CALLBACK FILESAVECALLBACK)(
   pBITMAPHANDLE pBitmap,
   L_UCHAR* pBuffer,
   L_UINT uRow,
   L_UINT uLines,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK SAVECUSTOMFILECALLBACK)(
   pCUSTOMTILEINFO pTileInfo,
   L_UCHAR* pUncompressedBuffer,
   L_SIZE_T UncompressedBufferSize,
   L_UCHAR* pCompressedBuffer,
   L_SIZE_T CompressedBufferSize ,
   L_SIZE_T* puActualBytesCompressed,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK LEADMARKERCALLBACK)(
   L_UINT uMarker,
   L_UINT uMarkerSize,
   L_UCHAR* pMarkerData,
   L_VOID* pLEADUserData);

typedef L_INT (pEXT_CALLBACK TRANSFORMFILECALLBACK)(
   L_UINT uMarker,
   L_UINT uMarkerSize,
   L_UCHAR* pMarkerData,
   L_VOID* pUserData,
   L_UINT uTransform,
   LEADMARKERCALLBACK pfnLEADCallback,
   L_VOID* pLEADUserData);

typedef L_INT (pEXT_CALLBACK LOADCUSTOMFILECALLBACK)(
   L_UCHAR* pCompressedTileBuffer,
   L_SIZE_T uCompressedBufferSize,
   L_UCHAR* pDeCompressedTileBuffer,
   L_SIZE_T uDeCompressedBufferSize,
   pCUSTOMTILEINFO pTileInfo,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK SAVEBUFFERCALLBACK)(
   L_SIZE_T uRequiredSize,
   L_UCHAR** ppBuffer,
   L_SIZE_T* pdwBufferSize,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK ENUMMARKERSCALLBACK)(
   L_UINT uMarker,
   L_UINT uMarkerSize,
   L_UCHAR* pMarkerData,
   L_VOID* pUserData,
   LEADMARKERCALLBACK pfnLEADCallback,
   L_VOID* pLEADUserData);

typedef L_INT (pEXT_CALLBACK ENUMTAGSCALLBACK)(
   L_UINT16 uTag,
   L_UINT16 uType,
   L_UINT uCount,
   L_VOID* pUserData);

typedef L_INT(pEXT_CALLBACK ENUMTAGS2CALLBACK)(
   L_UINT16 uTag,
   L_UINT16 uType,
   L_UINT uCount,
   L_VOID *pTagData,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK ENUMGEOKEYSCALLBACK)(
   L_UINT16 uTag,
   L_UINT16 uType,
   L_UINT uCount,
   L_VOID* pData,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK FILEDECRYPTCALLBACK)(
   const L_TCHAR *pszFileName, /* pointer to the name of the encrypted file */
   L_TCHAR **ppPassword,       /* pointer to a pointer to a buffer that contains the password. It should NULL-terminated and in UTF8 Unicode format.
                                  The callback should allocate this buffer using L_AllocBuffer. */
   L_VOID* pUserData); 

typedef L_INT (pEXT_FUNCTION FLTLOADBUFFER)(
   L_UCHAR* pInput,
   L_SIZE_T nLength,
   L_UCHAR* pOutput,
   L_INT nFormat,
   L_INT32 nWidth,
   L_INT32 nHeight,
   L_UINT nBitsPerPixel,
   L_VOID* pLeadHdr,
   L_UINT uFlags);

typedef L_INT (pEXT_FUNCTION FLTSAVEBUFFER)(
   L_UCHAR* pInput,
   L_BITMAPINFOHEADER* pbiInput,
   L_UCHAR* pOutput,
   L_SIZE_T* pdwSize,
   L_INT nQFactor,
   L_UINT uFlags,
   L_UINT nFormat,
   L_UCHAR* pTopBuffer,
   L_INT nTopBufferHeight);

typedef L_INT (pEXT_CALLBACK BITMAPLOADCALLBACK)(
   L_UCHAR* pBuffer,
   L_SIZE_T uSize,
   L_VOID* pUserData);

#if defined(LT_COMP_VECTOR)
typedef L_INT (pEXT_CALLBACK VECTORFONTMAPPERCALLBACKA)(
   pVECTORHANDLE pVector,
   LPLOGFONTA pLogFont,
   L_VOID* pUserData);
#if defined(FOR_UNICODE)
typedef L_INT (pEXT_CALLBACK VECTORFONTMAPPERCALLBACK)(
   pVECTORHANDLE pVector,
   LPLOGFONTW pLogFont,
   L_VOID* pUserData);
#else
typedef VECTORFONTMAPPERCALLBACKA VECTORFONTMAPPERCALLBACK;
#endif // #if defined(FOR_UNICODE)
#endif // #if defined(LT_COMP_VECTOR)

typedef L_INT (pEXT_CALLBACK OVERLAYCALLBACKA)(
   pFILEOVERLAYCALLBACKDATAA pOverlayCallbackData,
   L_VOID* pUserData);
#if defined(FOR_UNICODE)
typedef L_INT (pEXT_CALLBACK OVERLAYCALLBACK)(
   pFILEOVERLAYCALLBACKDATA pOverlayCallbackData,
   L_VOID* pUserData);
#else
typedef OVERLAYCALLBACKA OVERLAYCALLBACK;
#endif // #if defined(FOR_UNICODE)

/****************************************************************
   Classes/structures
****************************************************************/

#define L_IFDTYPE L_UINT64

// LOADINFO structure
typedef struct _LOADINFO
{
   L_UINT uStructSize;        // use sizeof(LOADINFO)
   L_INT Format;              // File format: FILE_PCX, ...
   L_INT Width;               // Image width
   L_INT Height;              // Image height
   L_INT BitsPerPixel;        // Bits per pixel
   L_INT XResolution;         // X resolution (DPI)
   L_INT YResolution;         // Y resolution (DPI)
   L_OFFSET Offset;           // Data offset
   L_UINT Flags;              // Special flags. One or more of the LOADINFO_XXX flags

   // for RAW file filter
   L_RGBQUAD rgbQuad[256];

   // for RAW BITFIELDS - contains R,G,B color masks
   L_UINT rgbColorMask[3];

   // for RAW_PACKBITS
   L_UINT32 uStripSize;       // size of strip after compression
   L_INT nPhotoInt;           // TIFF tag  0-6  TIFF tag
   L_INT nPlanarConfig;       // TIFF tag  1 = Chunky,  2 = Planar format
}
LOADINFO /*, *pLOADINFO*/;

typedef struct _FILEINFOA
{
   L_UINT uStructSize;           // use sizeof(FILEINFO)
   L_INT Format;                 // File format: FILE_PCX, ...
   L_CHAR Name[_MAX_FNAME+_MAX_EXT];// File name, including the Ext
   L_INT Width;                  // Image width
   L_INT Height;                 // Image height
   L_INT BitsPerPixel;           // Bits per pixel
   L_OFFSET SizeDisk;            // Size of file on disk
   L_OFFSET SizeMem;             // Size of image in memory
   L_CHAR Compression[20];       // Compression method name
   L_INT ViewPerspective;        // Image view perspective
   L_INT Order;                  // RGB order
   L_INT PageNumber;             // Page number
   L_INT TotalPages;             // Total number of pages present in the file
   L_INT XResolution;
   L_INT YResolution;
   L_UINT Flags;                 // identifies file subtypes: progressive, interlaced
   L_UINT GlobalLoop;            // Global animation loop count 0 = infinity
   L_INT GlobalWidth;            // Global width
   L_INT GlobalHeight;           // Global height
   L_COLORREF GlobalBackground;  // Global background color (see Flags)
   L_RGBQUAD GlobalPalette[256]; // Global palette (see Flags)
   L_IFDTYPE IFD;                // IFD offset (for TIF files only)
   L_INT Layers;                 // The number of layers in the file
   L_INT ColorSpace;             // The colorspace (RGB, CMYK, CIELAB, etc). See the COLORSPACE_XXX values
   L_INT Channels;               // The number of channels in the file
   L_BOOL bIsDocFile;            // Is this a DOC file?
   L_DOUBLE dDocPageWidth;       // Only valid for DOC files, the width in unit
   L_DOUBLE dDocPageHeight;      // Only valid for DOC files, the height in unit
   RASTERIZEDOC_UNIT uDocUnit;   // Only valid for DOC files, dDocPageWidth and dDocPageHeight unit
#if defined(LT_COMP_VECTOR)
   L_BOOL bIsVectorFile;         // Is this a Vector file?
   VECTORPARALLELOGRAM VectorParallelogram;
#endif // #if defined(LT_COMP_VECTOR)
   L_INT MessageCount;           // Total number of messages (for PST files only)
   L_INT nHorzTiles;
   L_INT nVertTiles;
#if !defined(LEADTOOLS_V22_OR_LATER)
   L_UINT64 IFD64;
#endif // #if !defined(LEADTOOLS_V22_OR_LATER)
   L_VOID   *pFilterData;        // filter data (filled only when FILEINFO_USEFILTERDATA is passed to L_FileInfo)
   L_SIZE_T uFilterDataSize;     // if non-zero, the filter data is flat (an array of bytes that can be saved to disk and reused in other exes)
                                 // if zero, the filter data uses handles and pointers that are valid only for the current executable
   L_INT    nFilter;             // indicates which filter allocated the filter data
   L_INT nAttachmentCount;       // If non-zero, the file has attachments (or PDF portfolio items)
}
FILEINFOA /*, *pFILEINFOA */;

#if defined(FOR_UNICODE)
typedef struct _FILEINFO
{
   L_UINT uStructSize;           // use sizeof(FILEINFO)
   L_INT Format;                 // File format: FILE_PCX, ...
   L_TCHAR Name[_MAX_FNAME+_MAX_EXT];// File name, including the Ext
   L_INT Width;                  // Image width
   L_INT Height;                 // Image height
   L_INT BitsPerPixel;           // Bits per pixel
   L_OFFSET SizeDisk;            // Size of file on disk
   L_OFFSET SizeMem;             // Size of image in memory
   L_TCHAR Compression[20];      // Compression method name
   L_INT ViewPerspective;        // Image view perspective
   L_INT Order;                  // RGB order
   L_INT PageNumber;             // Page number
   L_INT TotalPages;             // Total number of pages present in the file
   L_INT XResolution;
   L_INT YResolution;
   L_UINT Flags;                 // identifies file subtypes: progressive, interlaced
   L_UINT GlobalLoop;            // Global animation loop count 0 = infinity
   L_INT GlobalWidth;            // Global width
   L_INT GlobalHeight;           // Global height
   L_COLORREF GlobalBackground;  // Global background color (see Flags)
   L_RGBQUAD GlobalPalette[256]; // Global palette (see Flags)
   L_IFDTYPE IFD;                // IFD offset (for TIF files only)
   L_INT Layers;                 // The number of layers in the file
   L_INT ColorSpace;             // The colorspace (RGB, CMYK, CIELAB, etc)
   L_INT Channels;               // The number of channels in the file
   L_BOOL bIsDocFile;            // Is this a DOC file?
   L_DOUBLE dDocPageWidth;       // Only valid for DOC files, the width in unit
   L_DOUBLE dDocPageHeight;      // Only valid for DOC files, the height in unit
   RASTERIZEDOC_UNIT uDocUnit;   // Only valid for DOC files, the width in unit
#if defined(LT_COMP_VECTOR)
   L_BOOL bIsVectorFile;         // Is this a Vector file?
   VECTORPARALLELOGRAM VectorParallelogram;
#endif // #if defined(LT_COMP_VECTOR)
   L_INT MessageCount;           // Total number of messages (for PST files only)
   L_INT nHorzTiles;
   L_INT nVertTiles;
#if !defined(LEADTOOLS_V22_OR_LATER)
   L_UINT64 IFD64;
#endif // #if !defined(LEADTOOLS_V22_OR_LATER)
   L_VOID   *pFilterData;        // filter data (filled only when FILEINFO_USEFILTERDATA is passed to L_FileInfo)
   L_SIZE_T uFilterDataSize;     // if non-zero, the filter data is flat (an array of bytes that can be saved to disk and reused in other exes)
                                 // if zero, the filter data uses handles or pointers that are valid only for the current executable
   L_INT    nFilter;             // indicates which filter allocated the filter data
   L_INT nAttachmentCount;       // If non-zero, the file has attachments (or PDF portfolio items)
}
FILEINFO /*, *pFILEINFO */;
#else
typedef FILEINFOA FILEINFO;
typedef pFILEINFOA pFILEINFO;
#endif // #if defined(FOR_UNICODE)

typedef struct _PCDINFO
{
   L_INT resolution[6];
}
PCDINFO, *pPCDINFO;

// Structure for L_CreateThumbnailFromFile
typedef struct _THUMBOPTIONS
{
   L_UINT uStructSize;  // use sizeof(THUMBOPTIONS)
   L_INT nWidth;
   L_INT nHeight;
   L_INT nBits;
   L_UINT uCRFlags;
   L_BOOL bMaintainAspect;
   L_BOOL bForceSize;
   L_COLORREF crBackColor;
   L_BOOL bLoadStamp;
   L_BOOL bResample;
}
THUMBOPTIONS, *pTHUMBOPTIONS;

typedef struct _LOADFILEOPTION
{
   L_UINT uStructSize;  // the size of the LOADFILEOPTION - use sizeof(LOADFILEOPTION)
   L_INT XResolution;
   L_INT YResolution;
   L_UINT Flags;
   L_INT Passes;
   L_INT PageNumber;
   L_UINT GlobalLoop;
   L_IFDTYPE IFD;
   L_UINT uRedScan;     // the scan index of the red channel (NITF files only)
   L_UINT uGreenScan;   // the scan index of the green channel (NITF files only)
   L_UINT uBlueScan;    // the scan index of the blue channel (NITF files only)
#if defined(LT_COMP_BITMAPDATACALLBACKS)
   // Bitmap data callbacks
   pBITMAPHANDLEDATACALLBACKS pDataCallbacks;
#endif // #if defined(LT_COMP_BITMAPDATACALLBACKS)
   L_UINT Flags2;             // ELO2_XXX flags
   L_VOID   *pFilterData;        // filter data (used only when Flags2 contains the ELO2_USEFILTERDATA flag)
   L_SIZE_T uFilterDataSize;     // if non-zero, the filter data is flat (an array of bytes that can be saved to disk and reused in other exes)
                                 // if zero, the filter data uses handles or pointers that are valid only for the current executable
   L_INT    nFilter;             // indicates which filter allocated the filter data
   L_INT nAttachment;            // If non-zero, load the attachment number 'nAttachment' (1-based value)
}
LOADFILEOPTION, *pLOADFILEOPTION;

typedef struct _SAVEFILEOPTIONA
{
   L_UINT uStructSize;   // the size of the SAVEFILEOPTION - use sizeof(SAVEFILEOPTION)
   L_INT Reserved1;
   L_INT Reserved2;
   L_UINT Flags;
   L_INT Passes;
   L_INT PageNumber;
   L_INT GlobalWidth;
   L_INT GlobalHeight;
   L_UINT GlobalLoop;
   L_COLORREF GlobalBackground;
   L_RGBQUAD GlobalPalette[256];
   L_UINT StampWidth;
   L_UINT StampHeight;
   L_UINT StampBits;
   L_IFDTYPE IFD;
   L_CHAR szPassword[255];   // password for saving encrypted files
   PHOTMTRICINTERP PhotometricInterpretation;
   L_UINT TileWidth;
   L_UINT TileHeight;
   L_UINT Flags2;             // ESO2_XXX flags
}
SAVEFILEOPTIONA, *pSAVEFILEOPTIONA;
#if defined(FOR_UNICODE)
typedef struct _SAVEFILEOPTION
{
   L_UINT uStructSize;   // the size of the SAVEFILEOPTION - use sizeof(SAVEFILEOPTION)
   L_INT Reserved1;
   L_INT Reserved2;
   L_UINT Flags;
   L_INT Passes;
   L_INT PageNumber;
   L_INT GlobalWidth;
   L_INT GlobalHeight;
   L_UINT GlobalLoop;
   L_COLORREF GlobalBackground;
   L_RGBQUAD GlobalPalette[256];
   L_UINT StampWidth;
   L_UINT StampHeight;
   L_UINT StampBits;
   L_IFDTYPE IFD;
   L_TCHAR szPassword[255];   // password for saving encrypted files
   PHOTMTRICINTERP PhotometricInterpretation;
   L_UINT TileWidth;
   L_UINT TileHeight;
   L_UINT Flags2;             // ESO2_XXX flags
}
SAVEFILEOPTION, *pSAVEFILEOPTION;
#else
typedef SAVEFILEOPTIONA SAVEFILEOPTION;
typedef pSAVEFILEOPTIONA pSAVEFILEOPTION;
#endif // #if defined(FOR_UNICODE)

typedef struct _SAVECUSTOMFILEOPTION
{
   L_UINT uStructSize;                 // Size of the SAVECUSTOMFILEOPTION
   L_UINT uFlags;                      // Custom save options flags
   L_INT nTileWidth;                   // Width of a tile
   L_INT nTileHeight;                  // Height of a tile
   L_INT nCompressionTag;              // Compression Tag
   L_INT nPlanarConfiguration;         // Planar Configuration
   L_INT nPhotoMetricInterpretation;   // Photo Metric Interpretation
}
SAVECUSTOMFILEOPTION, * pSAVECUSTOMFILEOPTION;

typedef struct _LOADCUSTOMFILEOPTION
{
   L_UINT uStructSize;  // Size of Structure
   L_UINT uFlags;       // Custom load options flags
}
LOADCUSTOMFILEOPTION, *pLOADCUSTOMFILEOPTION;

typedef struct _CUSTOMTILEINFO
{
   L_UINT uStructSize;  // Size of Structure
   L_INT nWidth;        // Width of tile to be compressed
   L_INT nHeight;       // Height of tile to be compressed
   L_INT nBitsPerPixel; // Number of bits per pixel
}
CUSTOMTILEINFO /*, *pCUSTOMTILEINFO */;

typedef struct _FILECOMMENTS
{
   L_INT count;
   L_UCHAR** pointer;
   L_UINT* size;
}
FILECOMMENTS, *pFILECOMMENTS;

typedef struct _DIMENSION
{
   L_UINT nWidth;
   L_UINT nHeight;
}
DIMENSION, *pDIMENSION;

typedef struct _FILETRANSFORMS
{
   // AffineMatrix
   L_FLOAT a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
   // ColorTwistMatrix
   L_FLOAT byy, byc1, byc2, bc1y, bc1c1, bc1c2, bc2y, bc2c1, bc2c2;
   // ContrastAdjustment
   L_FLOAT fContrastAdjustment;
   // FilteringValue (Sharpness Adjustment)
   L_FLOAT fFilteringValue;
}
FILETRANSFORMS, *pFILETRANSFORMS;

// PLT Options
typedef struct _FILEPLTOPTIONS
{
   L_UINT uStructSize;
   L_INT PenWidth[8];
   L_COLORREF PenColor[8];
   L_BOOL bPenColorOverride;
}
FILEPLTOPTIONS, *pFILEPLTOPTIONS;

// The flags making up FILERTFOPTIONS.uFlags
#define RTF_USE_MULTIPLATFORM 0x0001   // If set, use the Multiplatform RTF engine
// If not set, use the Legacy Windows-only RTF engine

// RTF Options
typedef struct _FILERTFOPTIONS
{
   L_UINT uStructSize;     // The size of this structure
   L_COLORREF crBackColor;
   L_UINT uFlags;                      // One or more of the RTF_XXX flags (ex: RTF_USE_MULTIPLATFORM)
}
FILERTFOPTIONS, *pFILERTFOPTIONS;

typedef enum _L_TEXT_ENCODING
{
   L_TEXT_ENCODING_AUTO,
   L_TEXT_ENCODING_ANSI,
   L_TEXT_ENCODING_UTF7,
   L_TEXT_ENCODING_UTF8,
   L_TEXT_ENCODING_UTF16_LE,
   L_TEXT_ENCODING_UTF16_BE,
} L_TEXT_ENCODING;

typedef enum _L_TEXT_ANTI_ALIASING
{
   L_TEXT_ANTI_ALIASING_AUTO, // Let LEADTOOLS pick when to use anti-aliasing
   L_TEXT_ANTI_ALIASING_ON,   // Anti-aliasing is always on
   L_TEXT_ANTI_ALIASING_OFF,  // Anti-aliasing is always off
} L_TEXT_ANTI_ALIASING;

// TXT Options
typedef struct _FILETXTOPTIONSA
{
   L_UINT uStructSize;
   L_BOOL bEnabled;
   L_COLORREF crFontColor;
   L_COLORREF crHighlight;
   L_INT nFontSize;
   L_CHAR szFaceName[LF_FACESIZE];
   L_BOOL bBold;
   L_BOOL bItalic;
   L_BOOL bUnderLine;
   L_BOOL bStrikeThrough;
   L_TEXT_ENCODING defaultEncoding; // The text encoding for files without BOM (AutoDetect, UTF8, ANSI, etc)
   L_COLORREF crBackColor;
#if defined(LEADTOOLS_V22_OR_LATER)
   L_TEXT_ANTI_ALIASING antiAliasing;
   L_BOOL bWrap;                 // L_TRUE to wrap long text lines (default). L_FALSE to disable text wrapping (long lines will be truncated in this case).
#endif // #if defined(LEADTOOLS_V22_OR_LATER)
}
FILETXTOPTIONSA, *pFILETXTOPTIONSA;
#if defined(FOR_UNICODE)
typedef struct _FILETXTOPTIONS
{
   L_UINT uStructSize;
   L_BOOL bEnabled;
   L_COLORREF crFontColor;
   L_COLORREF crHighlight;
   L_INT nFontSize;
   L_TCHAR szFaceName[LF_FACESIZE];
   L_BOOL bBold;
   L_BOOL bItalic;
   L_BOOL bUnderLine;
   L_BOOL bStrikeThrough;
   L_TEXT_ENCODING defaultEncoding; // The text encoding for files without BOM (AutoDetect, UTF8, ANSI, etc)
   L_COLORREF crBackColor;
#if defined(LEADTOOLS_V22_OR_LATER)
   L_TEXT_ANTI_ALIASING antiAliasing;
   L_BOOL bWrap;                 // L_TRUE to wrap long text lines (default). L_FALSE to disable text wrapping (long lines will be truncated in this case).
#endif // #if defined(LEADTOOLS_V22_OR_LATER)
}
FILETXTOPTIONS, *pFILETXTOPTIONS;
#else
typedef FILETXTOPTIONSA FILETXTOPTIONS;
typedef pFILETXTOPTIONSA pFILETXTOPTIONS;
#endif // #if defined(FOR_UNICODE)

typedef enum
{
   // Default mode, use alternating colors per row (crFirstBackColor, crSecondBackColor)
   FILECSVOPTIONS_COLORMODE_DEFAULT,
   // Header (first row) uses crFirstBackColor, Rows use crSecondBackColor
   FILECSVOPTIONS_COLORMODE_HEADER_AND_BODY,
   // use alternating colors per column (crFirstBackColor, crSecondBackColor)
   FILECSVOPTIONS_COLORMODE_COLUMNS
}
FILECSVOPTIONS_COLORMODE;

typedef enum
{
   FILECSVOPTIONS_HORIZONTALCELLALIGNMENT_LEFT,
   FILECSVOPTIONS_HORIZONTALCELLALIGNMENT_CENTER,
   FILECSVOPTIONS_HORIZONTALCELLALIGNMENT_RIGHT
}
FILECSVOPTIONS_HORIZONTALCELLALIGNMENT;

typedef enum
{
   FILECSVOPTIONS_VERTICALCELLALIGNMENT_TOP,
   FILECSVOPTIONS_VERTICALCELLALIGNMENT_CENTER,
   FILECSVOPTIONS_VERTICALCELLALIGNMENT_BOTTOM
}
FILECSVOPTIONS_VERTICALCELLALIGNMENT;

// CSV Options
typedef struct _FILECSVOPTIONSA
{
   L_UINT uStructSize;
   L_CHAR szHeaderFontName[LF_FACESIZE];
   L_BOOL bHeaderFontBold;
   L_BOOL bHeaderFontItalic;
   L_BOOL bHeaderFontUnderLine;
   L_INT nHeaderFontSize;
   L_COLORREF crHeaderFontColor;
   L_CHAR szBodyFontName[LF_FACESIZE];
   L_BOOL bBodyFontBold;
   L_BOOL bBodyFontItalic;
   L_BOOL bBodyFontUnderLine;
   L_INT nBodyFontSize;
   L_COLORREF crBodyFontColor;
   L_COLORREF crFirstBackColor;
   L_COLORREF crSecondBackColor;
   L_UINT uColorMode;
   L_INT nTableCellWidth;
   L_COLORREF crTableBorderColor;
   L_INT nTableBorderWidth;
   L_UINT uHorizontalCellAlignment;
   L_UINT uVerticalCellAlignment;
}
FILECSVOPTIONSA, *pFILECSVOPTIONSA;
#if defined(FOR_UNICODE)
typedef struct _FILECSVOPTIONS
{
   L_UINT uStructSize;
   L_TCHAR szHeaderFontName[LF_FACESIZE];
   L_BOOL bHeaderFontBold;
   L_BOOL bHeaderFontItalic;
   L_BOOL bHeaderFontUnderLine;
   L_INT nHeaderFontSize;
   L_COLORREF crHeaderFontColor;
   L_TCHAR szBodyFontName[LF_FACESIZE];
   L_BOOL bBodyFontBold;
   L_BOOL bBodyFontItalic;
   L_BOOL bBodyFontUnderLine;
   L_INT nBodyFontSize;
   L_COLORREF crBodyFontColor;
   L_COLORREF crFirstBackColor;
   L_COLORREF crSecondBackColor;
   L_UINT uColorMode;
   L_INT nTableCellWidth;
   L_COLORREF crTableBorderColor;
   L_INT nTableBorderWidth;
   L_UINT uHorizontalCellAlignment;
   L_UINT uVerticalCellAlignment;
}
FILECSVOPTIONS, *pFILECSVOPTIONS;
#else
typedef FILECSVOPTIONSA FILECSVOPTIONS;
typedef pFILECSVOPTIONSA pFILECSVOPTIONS;
#endif // #if defined(FOR_UNICODE)


// PDF Options
typedef struct _FILEPDFOPTIONSA
{
   L_UINT uStructSize;                                   // The size of this structure
   L_BOOL bUseLibFonts;                                  // Specifies whether to use the library installed fonts or system fonts, default is TRUE. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_INT nDisplayDepth;                                  // Bits per pixel for resulting bitmap, takes 0,1,4,8,24 default is 24
   L_INT nTextAlpha;                                     // Font Anti-Aliasing,takes 1(no anti-aliasing), 2 and 4 .Default is 1. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_INT nGraphicsAlpha;                                 // Graphics Anti-Aliasing takes 1,2,4.Default is 1. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_UCHAR szPassword[FILEPDFOPTIONS_MAX_PASSWORD_LEN];  // Password to be used with encrypted PDF files
   L_UINT uFlags;                                        // one of the PDF_XXX flags (ex: PDF_DISABLE_CROPPING)
   L_BOOL bCallbackEnabled;
   BITMAPLOADCALLBACK pfnLoadCallback;
   L_VOID* pCallbackUserData;
   L_CHAR szOutputFullPath[L_MAXPATH];
   L_BOOL bUseImageData;
}
FILEPDFOPTIONSA, *pFILEPDFOPTIONSA;
#if defined(FOR_UNICODE)
typedef struct _FILEPDFOPTIONS
{
   L_UINT uStructSize;                                   // The size of this structure
   L_BOOL bUseLibFonts;                                  // Specifies whether to use the library installed fonts or system fonts, default is TRUE. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_INT nDisplayDepth;                                  // Bits per pixel for resulting bitmap, takes 0,1,4,8,24 default is 24
   L_INT nTextAlpha;                                     // Font Anti-Aliasing,takes 1(no anti-aliasing), 2 and 4 .Default is 1. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_INT nGraphicsAlpha;                                 // Graphics Anti-Aliasing takes 1,2,4.Default is 1. This member is ignored if PDF_USE_PDFENGINE is not set in uFlags
   L_UCHAR szPassword[FILEPDFOPTIONS_MAX_PASSWORD_LEN];  // Password to be used with encrypted PDF files
   L_UINT uFlags;                                        // one of the PDF_XXX flags (ex: PDF_DISABLE_CROPPING)
   L_BOOL bCallbackEnabled;
   BITMAPLOADCALLBACK pfnLoadCallback;
   L_VOID* pCallbackUserData;
   L_TCHAR szOutputFullPath[L_MAXPATH];
   L_BOOL bUseImageData;
}
FILEPDFOPTIONS, *pFILEPDFOPTIONS;
#else
typedef FILEPDFOPTIONSA FILEPDFOPTIONS;
typedef pFILEPDFOPTIONSA pFILEPDFOPTIONS;
#endif // #if defined(FOR_UNICODE)

typedef struct _FILEPDFSAVEOPTIONS
{
   L_UINT uStructSize;  // Size of the structure
   // Encryption
   L_UCHAR szUserPassword[255];
   L_UCHAR szOwnerPassword[255];
   L_BOOL b128bit;
   L_UINT dwEncryptFlags;
}
FILEPDFSAVEOPTIONS, *pFILEPDFSAVEOPTIONS;

// PTK Options
typedef struct _FILEPTKOPTIONS
{
   L_UINT uStructSize;     // The size of this structure
   L_INT nPTKResolution;   // Display resolution default is 96
}
FILEPTKOPTIONS, *pFILEPTKOPTIONS;

// JBIG2 Options
typedef struct _FILEJBIG2OPTIONS
{
   L_UINT uStructSize;

   //image
   L_UINT uImageFlags;
   L_UCHAR ucImageTemplateType;
   L_CHAR ImageGBATX1;
   L_CHAR ImageGBATY1;
   L_CHAR ImageGBATX2;
   L_CHAR ImageGBATY2;
   L_CHAR ImageGBATX3;
   L_CHAR ImageGBATY3;
   L_CHAR ImageGBATX4;
   L_CHAR ImageGBATY4;
   L_UINT uImageQFactor;

   //text
   L_UINT uTextFlags;
   L_UCHAR ucTextTemplateType;
   L_CHAR TextGBATX1;
   L_CHAR TextGBATY1;
   L_CHAR TextGBATX2;
   L_CHAR TextGBATY2;
   L_CHAR TextGBATX3;
   L_CHAR TextGBATY3;
   L_CHAR TextGBATX4;
   L_CHAR TextGBATY4;
   L_UINT uTextMinSymArea;
   L_UINT uTextMinSymWidth;
   L_UINT uTextMinSymHeight;
   L_UINT uTextMaxSymArea;
   L_UINT uTextMaxSymWidth;
   L_UINT uTextMaxSymHeight;
   L_UINT uTextDifThreshold;
   L_UINT uTextQFactor;

   L_UINT uXResolution;
   L_UINT uYResolution;
   L_UINT uFlags;
}
FILEJBIG2OPTIONS, *pFILEJBIG2OPTIONS;

// Bit values for the code blocks
typedef struct _CodBlockStyle
{
   L_UINT bSelectiveACBypass:1;
   L_UINT bResetContextOnBoundaries:1;
   L_UINT bTerminationOnEachPass:1;
   L_UINT bVerticallyCausalContext:1;
   L_UINT bPredictableTermination:1;
   L_UINT bErrorResilienceSymbol:1;
   L_UINT bReserved6:26;
}
CodBlockStyle;

typedef struct _FILEJ2KOPTIONS
{
   L_UINT uStructSize;  // the size of this structure

   // <----------------------
   L_BOOL bUseColorTransform;
   L_BOOL bDerivedQuantization;
   J2KCOMPRESSIONCONTROL uCompressionControl;
   L_FLOAT  fCompressionRatio;
   L_OFFSET uTargetFileSize;

   // <------------------------ SIZ_MARKER
   L_UINT uXOsiz;                          // Horizontal offset from the origin of the reference grid to the left side of the image area.
   L_UINT uYOsiz;                          // Vertical offset from the origin of the reference grid to the top side of the image area.
   L_UINT uXTsiz;                          // Width of one reference tile with respect to the reference grid.
   L_UINT uYTsiz;                          // Height of one reference tile with respect to the reference grid.
   L_UINT uXTOsiz;                         // Horizontal offset from the origin of the reference grid to the left side of the first tile.
   L_UINT uYTOsiz;                         // Vertical offset from the origin of the reference grid to the top side of the first tile.
   L_UINT uXRsiz[J2K_MAX_COMPONENTS_NUM];  // Horizontal Sub_sampling Value
   L_UINT uYRsiz[J2K_MAX_COMPONENTS_NUM];  // Vertical Sub_sampling Value

   // <------------------------ COD_MARKER
   L_UINT uDecompLevel;    // Number of decomposition levels, dyadic decomposition (Zero Implies no transform)
   L_UINT uProgressOrder;  // Progressing Order

   // <------------------------ Additional Markers
   L_BOOL bUseSOPMarker;
   L_BOOL bUseEPHMarker;

   // <------------------------ ROI
   J2KREGIONOFINTEREST uROIControl;
   L_BOOL bUseROI;
   L_FLOAT fROIWeight;
   L_RECT rcROI;

   // <---- Alpha Channel Custom Compression
   L_BOOL  bAlphaChannelLossless;
   L_UINT  uAlphaChannelActiveBits;

   // <---- Precinct Size
   J2KPRECINCTSIZE uPrecinctSize;
}
FILEJ2KOPTIONS, *pFILEJ2KOPTIONS;

typedef struct _J2KVIDEOINFO
{
   L_UINT nSize;
   L_INT nVersion;
   L_BOOL bReversible;
   L_BOOL bUseColorTransform;
   L_INT nMaxBytes;
   L_INT nBytePerLine;
   L_INT nBits;
   L_INT nColorSubSampling;   // Type of the color component subsampling
   L_INT nQuality;
   L_UINT uFrameWidth;        // Frame Width
   L_UINT uFrameHeight;       // Frame Height
   L_UINT uDecompLevel;       // Number of decomposition levels, dyadic decomposition (Zero Implies no transform)
   L_INT nTransform;          // Wavelet Transform used ( Type of wavelet filter ex. 9x7 or 5x3 );
   L_INT nViewSize;
   L_INT nSIMD;
}
J2KVIDEOINFO /*, *pJ2KVIDEOINFO */;

// XPS Options
typedef struct _FILEXPSOPTIONS
{
   L_UINT uStructSize;
}
FILEXPSOPTIONS, *pFILEXPSOPTIONS;

typedef struct _FILEEXCELOPTIONS
{
   L_UINT      uStructSize;
   L_UINT32    uFlags;              // one of the EXCEL_FLAGS_XXX flags
} FILEEXCELOPTIONS, *pFILEEXCELOPTIONS;

typedef struct _FILEXLSOPTIONS
{
   L_UINT      uStructSize;
   L_UINT32    uFlags;              // one of the XLS_FLAGS_XXX flags
} FILEXLSOPTIONS, *pFILEXLSOPTIONS;

typedef struct _FILEPOWERPOINTOPTIONS
{
   L_UINT uStructSize;
   L_UINT32 uFlags;  // one or more of POWERPOINT_FLAGS_XXX flags
}
FILEPOWERPOINTOPTIONS, *pFILEPOWERPOINTOPTIONS;

typedef struct _FILEDOCOPTIONS
{
   L_UINT      uStructSize;
   L_INT       nBitsPerPixel;
   L_UINT32    uFlags;
} FILEDOCOPTIONS, *pFILEDOCOPTIONS;

typedef enum _ANZ_VIEW
{
   ANZ_VIEW_TRANSVERSE,   // View is from underneath
   ANZ_VIEW_SAGITTAL,   // View is from right side
   ANZ_VIEW_CORONAL   // View is from front
} ANZ_VIEW, *pANZ_VIEW;

typedef struct _FILEANZOPTIONS
{
   L_UINT      uStructSize;
   ANZ_VIEW    View;
   L_UINT32    uFlags;
} FILEANZOPTIONS,*pFILEANZOPTIONS;

typedef struct _FILEDECRYPTOPTIONS
{
   L_UINT   uStructSize;
   L_UINT   uFlags;
   L_TCHAR  *pszPassword;
   FILEDECRYPTCALLBACK pfnCallback;
   L_VOID   *pUserData;
} FILEDECRYPTOPTIONS, *pFILEDECRYPTOPTIONS;

#if defined(LT_COMP_EMAILFORMATS)
// PST Options
typedef struct _FILEPSTOPTIONS
{
   L_UINT      uStructSize;
   L_UINT      uMessageNumber;
   L_UINT      uFlags;
} FILEPSTOPTIONS, *pFILEPSTOPTIONS;
#endif // #if defined(LT_COMP_EMAILFORMATS)

// Load/rasterize options for the following formats:
// Raster Pdf: FILE_RAS_PDF
// Postscript and Enhanced Postscript: FILE_EPS, FILE_POSTSCRIPT, FILE_EPSPOSTSCRIPT
// XPS: FILE_XPS
// Text: FILE_TXT
// RTF: FILE_RTF_RASTER
// XLS: FILE_XLS
// XlSX: FILE_XLSX, FILE_XLSB
// DOC: FILE_DOC
// DOCX: FILE_DOXC
// PPT: FILE_PPX
// PPTX: FILE_PPTX
typedef struct _RASTERIZEDOCOPTIONS
{
   L_UINT uStructSize;
   // Suggested page width in unit, default is 8.5
   L_DOUBLE dPageWidth;
   // Suggested page height in unit, default is 11.0
   L_DOUBLE dPageHeight;
   // Margins, default is 0.0
   // Margins are only valid for FILE_TXT and FILE_RTF_RASTER
   L_DOUBLE dLeftMargin;
   L_DOUBLE dTopMargin;
   L_DOUBLE dRightMargin;
   L_DOUBLE dBottomMargin;
   // Page width, page height and margins unit, default is Inch
   RASTERIZEDOC_UNIT uUnit;
   // Resolution, default is 0 = use screen resolution
   L_UINT uXResolution;
   L_UINT uYResolution;
   // Size mode, default is None
   RASTERIZEDOC_SIZEMODE uSizeMode;
}
RASTERIZEDOCOPTIONS, *pRASTERIZEDOCOPTIONS;

typedef struct _STARTDECOMPRESSDATAA
{
   L_UINT uStructSize;                 // for versioning-- use sizeof(STARTDECOMPRESSDATA)
   pBITMAPHANDLE pBitmap;              // Pointer to the bitmap handle to load the image to
   L_UINT uBitmapStructSize;           // size of the structure pointed to by pBitmap, uses sizeof(BITMAPHANDLE)
   L_UINT uStripsOrTiles;              // DECOMPRESS_STRIPS -- indicates that we are decompressing strips of data
                                       // DECOMPRESS_TILES  -- indicates that we are decompressing tiles of data
                                       // The main difference is that strips have a width equal to the bitmap width
                                       // but tiles can have a width that is less than the bitmap width
                                       // Note that the pfnReadCallback (described below) is not fired for DECOMPRESS_TILES
   L_UINT uFormat;                     // One of the following formats:
                                       //      FILE_JFIF
                                       //      FILE_RAW_RLE4
                                       //      FILE_RAW_RLE8
                                       //      FILE_RAW_BITFIELDS
                                       //      FILE_RAW_PACKBITS
                                       //      FILE_RAW_CCITT
                                       //      FILE_FAX_G3_1D
                                       //      FILE_FAX_G3_2D
                                       //      FILE_FAX_G4
   L_INT nWidth;                       // Bitmap width
   L_INT nHeight;                      // Bitmap Height
   L_INT nBitsPerPixel;                // Bits per pixel of raw data

   L_INT nViewPerspective;             // View perspective of raw data--one of the following constants:
                                       //      TOP_LEFT
                                       //      TOP_LEFT90
                                       //      TOP_LEFT180
                                       //      TOP_LEFT270
                                       //      BOTTOM_LEFT
                                       //      BOTTOM_LEFT90
                                       //      BOTTOM_LEFT180
                                       //      BOTTOM_LEFT270

   L_INT nRawOrder;                    // Color order of 24-bit raw data (ORDER_RGB, ORDER_BGR)
                                       // Ignored if palettized
   L_INT nLoadOrder;                   // Desired color order after 24-bit image is loaded (Ignored if palettized)

   L_INT nXResolution;                 // Horizontal resolution, in dots per inch.
   L_INT nYResolution;                 // Vertical resolution, in dots per inch.

   FILEREADCALLBACKA pfnReadCallback;   // Optional callback function for additional processing.
                                       // If you do not provide a callback function, use NULL as the value of this parameter.
                                       // If you do provide a callback function, use the function pointer as the value of this parameter.
                                       // The callback function must adhere to the function prototype described in FILEREADCALLBACK Function.

   L_RGBQUAD Palette[256];             // Palette for uncompressed data that is 8 bits per pixel or less.
                                       // Fill in the first 2^BitsPerPixel entries in this palette and include DECOMPRESS_PALETTE in the uFlags field.
   L_UINT uFlags;                      // Any combination of the following flags:
                                       // DECOMPRESS_LSB          -- The least significant bit is filled first.
                                       // DECOMPRESS_PAD4         -- Each line is padded to a multiple of 4 bytes
                                       // DECOMPRESS_PALETTE      -- A palette is supplied in the rgbQuad field
   L_VOID* pUserData;

   L_UINT rgbColorMask[3];             // Valid for FILE_RAW_BITFIELDS only - contains R,G,B color masks
                                       // rgbColorMask[0] is the red mask
                                       // rgbColorMask[1] is the green mask
                                       // rgbColorMask[2] is the blue mask
                                       // For example, with 16-bit data arranged like (RRR RRGG GGGB BBBB), the masks would be
                                       //     rgbColorMask[0] = 0x7C00
                                       //     rgbColorMask[1] = 0x0E30
                                       //     rgbColorMask[2] = 0x001F
                                       // For 32-bit data, the only valid data is (RRRR RRRR GGGG GGGG BBBB BBBB)
                                       //     rgbColorMask[0] = 0xFF0000
                                       //     rgbColorMask[1] = 0x00FF00
                                       //     rgbColorMask[2] = 0x0000FF

   L_INT nPhotoInt;                    // For:
                                       //      FILE_RAW_CCITT, FILE_FAX_G3_1D, FILE_FAX_G3_2D, FILE_FAX_G4
                                       //         0 = WhiteIsZero
                                       //         1 = BlackIsZero
                                       //
                                       //      FILE_RAW_PACKBITS
                                       //         0 = WhiteIsZero
                                       //         1 = BlackIsZero
                                       //         2 = There is no ColorMap (RGB)
                                       //         5 = Separated - CMYK
                                       //         6 = YC b C r color space
                                       //         8 = 1976 CIE L*a*b*

   L_INT nPlanarConfig;                // For FILE_RAW_PACKBITS only
                                       //      1 = Chunky
                                       //      2 = Planar format

   L_UINT uReserved1;                  // Reserved for future use
}
STARTDECOMPRESSDATAA, *pSTARTDECOMPRESSDATAA;
#if defined(FOR_UNICODE)
typedef struct _STARTDECOMPRESSDATA
{
   L_UINT uStructSize;                 // for versioning-- use sizeof(STARTDECOMPRESSDATA)
   pBITMAPHANDLE pBitmap;              // Pointer to the bitmap handle to load the image to
   L_UINT uBitmapStructSize;           // size of the structure pointed to by pBitmap, uses sizeof(BITMAPHANDLE)
   L_UINT uStripsOrTiles;              // DECOMPRESS_STRIPS -- indicates that we are decompressing strips of data
                                       // DECOMPRESS_TILES  -- indicates that we are decompressing tiles of data
                                       // The main difference is that strips have a width equal to the bitmap width
                                       // but tiles can have a width that is less than the bitmap width
                                       // Note that the pfnReadCallback (described below) is not fired for DECOMPRESS_TILES
   L_UINT uFormat;                     // One of the following formats:
                                       //      FILE_JFIF
                                       //      FILE_RAW_RLE4
                                       //      FILE_RAW_RLE8
                                       //      FILE_RAW_BITFIELDS
                                       //      FILE_RAW_PACKBITS
                                       //      FILE_RAW_CCITT
                                       //      FILE_FAX_G3_1D
                                       //      FILE_FAX_G3_2D
                                       //      FILE_FAX_G4
   L_INT nWidth;                       // Bitmap width
   L_INT nHeight;                      // Bitmap Height
   L_INT nBitsPerPixel;                // Bits per pixel of raw data

   L_INT nViewPerspective;             // View perspective of raw data--one of the following constants:
                                       //      TOP_LEFT
                                       //      TOP_LEFT90
                                       //      TOP_LEFT180
                                       //      TOP_LEFT270
                                       //      BOTTOM_LEFT
                                       //      BOTTOM_LEFT90
                                       //      BOTTOM_LEFT180
                                       //      BOTTOM_LEFT270

   L_INT nRawOrder;                    // Color order of 24-bit raw data (ORDER_RGB, ORDER_BGR)
                                       // Ignored if palettized
   L_INT nLoadOrder;                   // Desired color order after 24-bit image is loaded (Ignored if palettized)

   L_INT nXResolution;                 // Horizontal resolution, in dots per inch.
   L_INT nYResolution;                 // Vertical resolution, in dots per inch.

   FILEREADCALLBACK pfnReadCallback;   // Optional callback function for additional processing.
                                       // If you do not provide a callback function, use NULL as the value of this parameter.
                                       // If you do provide a callback function, use the function pointer as the value of this parameter.
                                       // The callback function must adhere to the function prototype described in FILEREADCALLBACK Function.

   L_RGBQUAD Palette[256];             // Palette for uncompressed data that is 8 bits per pixel or less.
                                       // Fill in the first 2^BitsPerPixel entries in this palette and include DECOMPRESS_PALETTE in the uFlags field.
   L_UINT uFlags;                      // Any combination of the following flags:
                                       // DECOMPRESS_LSB          -- The least significant bit is filled first.
                                       // DECOMPRESS_PAD4         -- Each line is padded to a multiple of 4 bytes
                                       // DECOMPRESS_PALETTE      -- A palette is supplied in the rgbQuad field
   L_VOID* pUserData;

   L_UINT rgbColorMask[3];             // Valid for FILE_RAW_BITFIELDS only - contains R,G,B color masks
                                       // rgbColorMask[0] is the red mask
                                       // rgbColorMask[1] is the green mask
                                       // rgbColorMask[2] is the blue mask
                                       // For example, with 16-bit data arranged like (RRR RRGG GGGB BBBB), the masks would be
                                       //     rgbColorMask[0] = 0x7C00
                                       //     rgbColorMask[1] = 0x0E30
                                       //     rgbColorMask[2] = 0x001F
                                       // For 32-bit data, the only valid data is (RRRR RRRR GGGG GGGG BBBB BBBB)
                                       //     rgbColorMask[0] = 0xFF0000
                                       //     rgbColorMask[1] = 0x00FF00
                                       //     rgbColorMask[2] = 0x0000FF

   L_INT nPhotoInt;                    // For:
                                       //      FILE_RAW_CCITT, FILE_FAX_G3_1D, FILE_FAX_G3_2D, FILE_FAX_G4
                                       //         0 = WhiteIsZero
                                       //         1 = BlackIsZero
                                       //
                                       //      FILE_RAW_PACKBITS
                                       //         0 = WhiteIsZero
                                       //         1 = BlackIsZero
                                       //         2 = There is no ColorMap (RGB)
                                       //         5 = Separated - CMYK
                                       //         6 = YC b C r color space
                                       //         8 = 1976 CIE L*a*b*

   L_INT nPlanarConfig;                // For FILE_RAW_PACKBITS only
                                       //      1 = Chunky
                                       //      2 = Planar format

   L_UINT uReserved1;                  // Reserved for future use
}
STARTDECOMPRESSDATA, *pSTARTDECOMPRESSDATA;
#else
typedef STARTDECOMPRESSDATAA STARTDECOMPRESSDATA;
typedef pSTARTDECOMPRESSDATAA pSTARTDECOMPRESSDATA;
#endif // #if defined(FOR_UNICODE)

typedef struct _DECOMPRESSDATA
{
   L_UINT uStructSize;     // for versioning-- use sizeof(STARTDECOMPRESSDATA)
   L_UCHAR* pBuffer;       // pointer to raw compressed data
                           //
   L_INT nWidth;           // width of uncompressed strip/tile in bytes
                           //    For strips, this is the width of the image
                           //    For tiles, this is usually a fraction of the image width
   L_INT nHeight;          // height of uncompressed strip/tile in bytes
                           //    If the image consists of one single compressed strip (as with TWAIN),
                           //    this is the height of the image
                           //
   L_SIZE_T uOffset;       // offset of strip relative to buffer -- usually zero
   L_UINT32 nBufferSize;   // size of strip after compression
                           //    For TWAIN, this is the buffer size determined by DAT_SETUPMEMXFER
                           //
   L_INT nRow;             // Row offset of tile or strip
   L_INT nCol;             // Column offset of tile
                           //    For strips, this value is ignored
   L_UINT uFlags;          // Flags used for tiles or strips
                           //    DECOMPRESS_STRIP_START
                           //    DECOMPRESS_STRIP_END
                           //    DECOMPRESS_STRIP_COMPLETE (note: this is DECOMPRESS_STRIP_START | DECOMPRESS_STRIP_END)
                           // If pBuffer does not point to a full strip or tile you set uFlags to DECOMPRESS_STRIP_START
                           //    when the strip/tile begins and DECOMPRESS_STRIP_END when the strip/tile ends
                           // If pBuffer points to a complete strip/tile, then set this to DECOMPRESS_CHUNK_COMPLETE
   L_INT nReserved1;       // Reserved for future use
}
DECOMPRESSDATA, *pDECOMPRESSDATA;

// Typedefs and defines used with extensions functions
typedef struct _LTEXTENSION
{
   L_WCHAR* pName;      // the extension name (as Unicode)
   L_SIZE_T uDataSize;  // the size of the extension data (0xFFFFFFFF if the extension is a stream)
   L_UCHAR* pData;      // extension data. NULL for streams (if uDataSize is 0xFFFFFFFF)
   CLSID* pClsid;       // CLSID describing the extension. Only valid if uDataSize is 0xFFFFFFFF
   L_UCHAR ucDefault;   // internal use
}
LTEXTENSION, *pEXTENSION;

typedef struct _EXTENSIONLIST
{
   L_UINT uStructSize;     // size of the whole extension list
   L_UINT uFlags;          // describes the type data contained in the extensions
   L_UINT uCount;          // the number of extensions present in aList
   LTEXTENSION aList[1];   // the list of extensions
}
EXTENSIONLIST, *pEXTENSIONLIST;

typedef struct _FILTERINFO
{
   L_UINT uStructSize;        // Structure size
   L_WCHAR szName[8];         // Filter name.
   L_SIZE_T uSize;            // Size of szName in words
   L_WCHAR* pszExtensionList; // The extension list of files of this type. This speeds up the detection of the file format.
   L_UINT uFlags;             // FILTERINFO_XXX flags
}
FILTERINFO, *pFILTERINFO;

typedef struct _LEADFILETAG
{
   L_UINT16 uTag;
   L_UINT16 uType;
   L_UINT uCount;
   L_UINT uDataSize;
   L_SIZE_T uDataOffset;
}
LEADFILETAG, *pLEADFILETAG;

typedef struct _LEADFILECOMMENT
{
   L_UINT uType;
   L_UINT uDataSize;
   L_SIZE_T uDataOffset;
}
LEADFILECOMMENT, *pLEADFILECOMMENT;

//* PSD layers functions and defines
typedef struct _LAYERINFOA
{
   L_UINT uStructSize;  // the size of LAYERINFO - use sizeof(LAYERINFO)
   L_INT nLayerLeft;
   L_INT nLayerTop;
   L_UCHAR uOpacity;
   L_UCHAR uClipping;
   L_UCHAR szBlendModeKey[4];
   pBITMAPHANDLE pMaskBitmap;
   L_CHAR szName[MAX_PATH];
   L_UINT uLayerFlags;  // Filled by L_LoadLayer
}
LAYERINFOA, *pLAYERINFOA;
#if defined(FOR_UNICODE)
typedef struct _LAYERINFO
{
   L_UINT uStructSize;  // the size of LAYERINFO - use sizeof(LAYERINFO)
   L_INT nLayerLeft;
   L_INT nLayerTop;
   L_UCHAR uOpacity;
   L_UCHAR uClipping;
   L_UCHAR szBlendModeKey[4];
   pBITMAPHANDLE pMaskBitmap;
   L_TCHAR szName[MAX_PATH];
   L_UINT uLayerFlags;  // Filled by L_LoadLayer
}
LAYERINFO, *pLAYERINFO;
#else
typedef LAYERINFOA LAYERINFO;
typedef pLAYERINFOA pLAYERINFO;
#endif // #if defined(FOR_UNICODE)

// AutoCAD DXF Layouts
#define ACAD_MAX_STRING 1024
typedef struct _LAYOUTINFOA
{
   L_UINT uStructSize;  // the size of LAYOUTINFO - use sizeof(LAYOUTINFO)
   L_CHAR szLayoutName[ ACAD_MAX_STRING ];
} LAYOUTINFOA, *pLAYOUTINFOA;
#if defined(FOR_UNICODE)
typedef struct _LAYOUTINFO
{
   L_UINT uStructSize;  // the size of LAYOUTINFO - use sizeof(LAYOUTINFO)
   L_TCHAR szLayoutName[ ACAD_MAX_STRING ];
} LAYOUTINFO, *pLAYOUTINFO;
#else
typedef LAYOUTINFOA LAYOUTINFO;
typedef pLAYOUTINFOA pLAYOUTINFO;
#endif // #if defined(FOR_UNICODE)

// The overlay callback is called to provide the overlay bitmap
typedef struct _FILEOVERLAYCALLBACKDATAA
{
   L_UINT uStructSize;
   L_CHAR* pszFilename;
   L_INT nPageNumber;
   L_BOOL bInfo;
   L_INT nInfoWidth;
   L_INT nInfoHeight;
   L_INT nInfoXResolution;
   L_INT nInfoYResolution;
   pBITMAPHANDLE pLoadBitmap;
}
FILEOVERLAYCALLBACKDATAA /*, *pFILEOVERLAYCALLBACKDATAA */;
#if defined(FOR_UNICODE)
typedef struct _FILEOVERLAYCALLBACKDATA
{
   L_UINT uStructSize;
   L_TCHAR* pszFilename;
   L_INT nPageNumber;
   L_BOOL bInfo;
   L_INT nInfoWidth;
   L_INT nInfoHeight;
   L_INT nInfoXResolution;
   L_INT nInfoYResolution;
   pBITMAPHANDLE pLoadBitmap;
}
FILEOVERLAYCALLBACKDATA /*, *pFILEOVERLAYCALLBACKDATA */;
#else
typedef FILEOVERLAYCALLBACKDATAA FILEOVERLAYCALLBACKDATA;
typedef pFILEOVERLAYCALLBACKDATAA pFILEOVERLAYCALLBACKDATA;
#endif // #if defined(FOR_UNICODE)

typedef struct _CHANNELINFOA
{
   L_UINT      uStructSize;
   L_CHAR      szName[64];
   CHANNELTYPE ChannelType;
}CHANNELINFOA, *pCHANNELINFOA;
#if defined(FOR_UNICODE)
typedef struct _CHANNELINFO
{
   L_UINT      uStructSize;
   L_TCHAR     szName[64];
   CHANNELTYPE ChannelType;
}CHANNELINFO, *pCHANNELINFO;
#else
typedef CHANNELINFOA CHANNELINFO;
typedef pCHANNELINFOA pCHANNELINFO;
#endif // #if defined(FOR_UNICODE)

typedef struct _RASTERPDFINFO
{
   L_UINT uStructSize;
   L_BOOL bIsLeadPdf;         // This PDF was created by LEADTOOLS. If this is TRUE, the other members of this
                              // structure are guaranteed to work. Also L_DeletePage will work
                              // on this file as well
   L_INT nBitsPerPixel;       // The bits/pixel of the first image
   L_INT Format;              // The format of first image (FILE_RAS_PDF_G3_1D, etc)
   L_INT nWidth;              // Width in pixels of the page, not just the image item
   L_INT nHeight;             // Height in pixels of the page, not just the image item
   L_INT XResolution;         // Horizontal resolution of the first image.
   L_INT YResolution;         // Vertical resolution of the first image.
   RASTERPDFVERSION Version;  // RASTERPDFVERSION_XXX
}
RASTERPDFINFO, *pRASTERPDFINFO;



#define L_FILEMETADATAITEM_STRING_LENGTH 128

typedef struct _L_FILEMETADATAITEMA
{
   L_CHAR Key[L_FILEMETADATAITEM_STRING_LENGTH];
   L_CHAR Value[L_FILEMETADATAITEM_STRING_LENGTH];
}
L_FILEMETADATAITEMA, *pL_FILEMETADATAITEMA;

#if defined(FOR_UNICODE)
typedef struct _L_FILEMETADATAITEM
{
   L_TCHAR Key[L_FILEMETADATAITEM_STRING_LENGTH];
   L_TCHAR Value[L_FILEMETADATAITEM_STRING_LENGTH];
}
L_FILEMETADATAITEM, *pL_FILEMETADATAITEM;
#else
typedef L_FILEMETADATAITEMA L_FILEMETADATAITEM;
typedef pL_FILEMETADATAITEMA pL_FILEMETADATAITEM;
#endif // #if defined(FOR_UNICODE)

typedef struct _L_FILEMETADATAITEMSA
{
   L_UINT uStructSize;
   L_UINT uFlags; // Future use
   L_UINT uCount; // Number of items in Keys and Values
   L_FILEMETADATAITEMA* pItems;
}
L_FILEMETADATAITEMSA, *pL_FILEMETADATAITEMSA;

#if defined(FOR_UNICODE)
typedef struct _L_FILEMETADATAITEMS
{
   L_UINT uStructSize;
   L_UINT uFlags; // Future use
   L_UINT uCount; // Number of items in Keys and Values
   L_FILEMETADATAITEM* pItems;
}
L_FILEMETADATAITEMS, *pL_FILEMETADATAITEMS;
#else
typedef L_FILEMETADATAITEMSA L_FILEMETADATAITEMS;
typedef pL_FILEMETADATAITEMSA pL_FILEMETADATAITEMS;
#endif // #if defined(FOR_UNICODE)


typedef  enum _DOCWRTFORMAT
{
   DOCUMENTFORMAT_USER = -1,
   DOCUMENTFORMAT_LTD = 0,
   DOCUMENTFORMAT_PDF = 1,
   DOCUMENTFORMAT_DOC,
   DOCUMENTFORMAT_RTF,
   DOCUMENTFORMAT_HTM,
   DOCUMENTFORMAT_TXT,
   DOCUMENTFORMAT_EMF,
   DOCUMENTFORMAT_XPS,
   DOCUMENTFORMAT_DOCX,
   DOCUMENTFORMAT_XLS,
   DOCUMENTFORMAT_EPUB,
   DOCUMENTFORMAT_MOBI,
   DOCUMENTFORMAT_SVG,
   DOCUMENTFORMAT_ALTOXML,
}
DOCWRTFORMAT, *pDOCWRTFORMAT;

#if defined(FOR_UNICODE)
typedef struct _DOCUMENTCREATEFILEOPTIONS
{
   L_UINT               uStructSize;
   L_TCHAR              *pszFileName;
   DOCWRTFORMAT         Format;
   L_VOID               *pOptions;
   L_SIZED              Size;
   L_DOUBLE             DpiX;
   L_DOUBLE             DpiY;
   L_UINT               Flags;
   L_INT                FirstPageNumber;
   L_INT                LastPageNumber;
} DOCUMENTCREATEFILEOPTIONS, *pDOCUMENTCREATEFILEOPTIONS;
#else
#define DOCUMENTCREATEFILEOPTIONS DOCUMENTCREATEFILEOPTIONSA
#define pDOCUMENTCREATEFILEOPTIONS pDOCUMENTCREATEFILEOPTIONSA
#endif // #if defined(FOR_UNICODE)

typedef struct _DOCUMENTCREATEFILEOPTIONSA
{
   L_UINT               uStructSize;
   L_CHAR               *pszFileName;
   DOCWRTFORMAT         Format;
   L_VOID               *pOptions;
   L_SIZED              Size;
   L_DOUBLE             DpiX;
   L_DOUBLE             DpiY;
   L_UINT               Flags;
   L_INT                FirstPageNumber;
   L_INT                LastPageNumber;
} DOCUMENTCREATEFILEOPTIONSA, *pDOCUMENTCREATEFILEOPTIONSA;

typedef L_INT(pEXT_CALLBACK FILTERHEARTBEATCALLBACK)(L_VOID* pData, L_VOID* pUserData);

typedef struct _FILTERTIMEOUTOPTIONS
{
   L_UINT uStructSize;
   L_UINT uTimeoutMilliseconds; // 0 means no timeout
}
FILTERTIMEOUTOPTIONS, *pFILTERTIMEOUTOPTIONS;

typedef struct _L_FILEATTACHMENT
{
   L_UINT64 uAttachmentNumber;      // 1-based number of this attachment in the document
   L_TCHAR* pszFileName;            // Attachment file name
   L_TCHAR* pszDisplayName;         // Friendly name of the attachment. (Might be the same as pszFileName)
   L_TCHAR* pszDescription;         // (Optional) Description of the attachment
   L_UINT64 uFileLength;            // (Optional) Size of the attachment file in bytes. Could be 0.
   L_INT64 nTimeCreated;            // (Optional) File create date in UNIX time
   L_INT64 nTimeModified;           // (Optional) File modified date in UNIX time
   L_SIZE_T uMetadataCount;         // (Optional) number of items in the pMetadataItems array
   L_FILEMETADATAITEM* pMetadata;   // pointer to the array of metadata items (could be NULL, but might contain information like "MimeType")
   L_SIZE_T pReserved1;             // Reserved
   L_VOID* pReserved2;              // Reserved
} L_FILEATTACHMENT;

typedef struct _L_FILEATTACHMENTS
{
   L_UINT uStructSize;     // size of the structure (should be sizeof(L_FILEATTACHMENTS))
   L_INT  OriginalFormat; // file format of the original document containing all the attachments (FILE_RAS_PDF for now)
   L_UINT uFlags;          // reserved for future use (0 for now)
   L_UINT uItemStructSize; // size of each L_FILEATTACHMENT structure pointed by pItems member (should be sizeof(L_FILEATTACHMENT))
   L_SIZE_T uItemCount;    // number of attachments described in pItems array
   L_FILEATTACHMENT* pItems; // pointer to the individual items. Note that this is 0-based, while LOADFILEOPTION.nAttachment is 1-based
} L_FILEATTACHMENTS;


/****************************************************************
   Function prototypes
****************************************************************/
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_CODEC)
// functions1
L_LTFIL_API L_INT EXT_FUNCTION L_CompressBuffer(
   L_UCHAR* pBuffer);

L_LTFIL_API L_INT EXT_FUNCTION L_EndCompressBuffer(L_VOID);

/*
   The source file of this function is either 
      * on disk (indicated by pszSrcFileName)
      * in memory (indicated by pSrcBuffer & uSrcBufferSize)
   The output is either:
      * on disk (indicated by pszDstFileName)
      * in memory (indicated by ppDstBuffer and puDstBufferSize)
   If the output is in memory, the function will allocate a buffer and store it in *ppDstBuffer. The output size will be set in *puDstBufferSize.
   In this case, you should free the output buffer when you are done with it by calling L_FreeBuffer(*ppDstBuffer)
   Only one of the input/output options should be passed. In other words, if pszSrcFileName != NULL, then pSrcBuffer should be NULL.
   Same for output: if pszDstFileName != NULL, then ppDstBuffer and puDstBufferSize should be NULL.
*/
L_LTFIL_API L_INT EXT_FUNCTION L_ExtractAttachment(L_TCHAR *pszSrcFileName, 
   L_UCHAR *pSrcBuffer, L_SIZE_T uSrcBufferSize, 
   pLOADFILEOPTION pFileOptions, 
   pFILEINFO pFileInfo, 
   L_UINT uFlags, 
   L_TCHAR *pszDstFileName, 
   L_UCHAR **ppDstBuffer, L_SIZE_T *puDstBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileAttachments(L_TCHAR *pszFile, L_FILEATTACHMENTS **ppAttachments, LOADFILEOPTION *pLoadOptions, FILEINFO *pInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeAttachments(L_FILEATTACHMENTS *pAttachments);

L_LTFIL_API L_INT EXT_FUNCTION L_GetComment(
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength);

L_LTFIL_API L_INT EXT_FUNCTION L_GetLoadResolution(
   L_INT nFormat,
   L_UINT* pWidth,
   L_UINT* pHeight,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetTag(
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentMemory(
   L_UCHAR* pBuffer,
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTagMemory(
   L_UCHAR* pBuffer,
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SetComment(
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength);

L_LTFIL_API LOADINFOCALLBACK EXT_FUNCTION L_SetLoadInfoCallback(
   LOADINFOCALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTFIL_API L_VOID* EXT_FUNCTION L_GetLoadInfoCallbackData(L_VOID);

L_LTFIL_API L_INT EXT_FUNCTION L_SetLoadResolution(
   L_INT nFormat,
   L_UINT nWidth,
   L_UINT nHeight);

L_LTFIL_API L_INT EXT_FUNCTION L_SetTag(
   L_UINT16 uTag,
   L_UINT16 uType,
   L_UINT uCount,
   L_VOID* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_SetSaveResolution(
   L_UINT uCount,
   pDIMENSION pResolutions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetSaveResolution(
   L_UINT* puCount,
   pDIMENSION pResolutions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDefaultLoadFileOption(
   pLOADFILEOPTION pLoadOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_GetJ2KOptions(
   pFILEJ2KOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDefaultJ2KOptions(
   pFILEJ2KOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetJ2KOptions(
   pFILEJ2KOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_MarkerCallbackProxy(
   LEADMARKERCALLBACK pfnCallback,
   L_UINT uMarker,
   L_UINT uMarkerSize,
   L_UCHAR* pMarkerData,
   L_VOID* pLEADUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeExtensions(
   pEXTENSIONLIST pExtensionList);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadExtensionStamp(
   pEXTENSIONLIST pExtensionList,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_GetExtensionAudio(
   pEXTENSIONLIST pExtensionList,
   L_INT nStream,
   L_UCHAR** ppBuffer,
   L_SIZE_T* puSize);

L_LTFIL_API L_INT EXT_FUNCTION L_StopDecompressBuffer(
   L_HGLOBAL hDecompress);

L_LTFIL_API L_INT EXT_FUNCTION L_DecompressBuffer(
   L_HGLOBAL hDecompress,
   pDECOMPRESSDATA pDecompressData);

L_LTFIL_API L_INT EXT_FUNCTION L_GetJBIG2Options(
   pFILEJBIG2OPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetJBIG2Options(
   pFILEJBIG2OPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_CreateMarkers(
   L_HANDLE* phMarkers);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeMarkers(
   L_VOID* hMarkers);

L_LTFIL_API L_INT EXT_FUNCTION L_SetMarkers(
   L_VOID* hMarkers,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_GetMarkers(
   L_VOID** phMarkers,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumMarkers(
   L_VOID* hMarkers,
   L_UINT uFlags,
   ENUMMARKERSCALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteMarker(
   L_VOID* hMarkers,
   L_UINT uMarker,
   L_INT nCount);

L_LTFIL_API L_INT EXT_FUNCTION L_InsertMarker(
   L_VOID* hMarkers,
   L_UINT uIndex,
   L_UINT uMarker,
   L_UINT uMarkerSize,
   L_UCHAR* pMarkerData);

L_LTFIL_API L_INT EXT_FUNCTION L_CopyMarkers(
   L_VOID** phMarkersDst,
   L_HANDLE hMarkersSrc);

L_LTFIL_API L_INT EXT_FUNCTION L_GetMarkerCount(
   L_VOID* hMarkers,
   L_UINT* puCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetMarker(
   L_VOID* hMarkers,
   L_UINT uIndex,
   L_UINT* puMarker,
   L_UINT* puMarkerSize,
   L_UCHAR* pMarkerData);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteMarkerIndex(
   L_VOID* hMarkers,
   L_UINT uIndex);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveData(
   L_VOID* pStruct,
   L_UCHAR* pDataBuffer,
   L_SIZE_T ulBytes);

L_LTFIL_API L_INT EXT_FUNCTION L_StopSaveData(
   L_VOID* pStruct);

L_LTFIL_API L_INT EXT_FUNCTION L_SetGeoKey(
   L_UINT16 uTag,
   L_UINT uType,
   L_UINT uCount,
   L_VOID* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_GetGeoKey(
   L_UINT16 uTag,
   L_UINT* puType,
   L_UINT* puCount,
   L_VOID* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentOffset(
   L_HFILE fd,
   L_OFFSET nOffsetBegin,
   L_OFFSET nBytesToLoad,
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetLoadStatus(L_VOID);

L_LTFIL_API L_INT EXT_FUNCTION L_DecodeABIC(
   L_UCHAR *pInputData,
   L_SSIZE_T nLength,
   L_UCHAR **ppOutputData,
   L_INT nAlign,
   L_INT nWidth,
   L_INT nHeight,
   L_BOOL bBiLevel);

L_LTFIL_API L_INT EXT_FUNCTION L_EncodeABIC(
   L_UCHAR* pInputData,
   L_INT nAlign,
   L_INT nWidth,
   L_INT nHeight,
   L_UCHAR** ppOutputData,
   L_SSIZE_T* pnLength,
   L_BOOL bBiLevel);

L_LTFIL_API L_INT EXT_FUNCTION L_ExtractXMPMetadata(
   L_TCHAR* pszSrc,
   L_TCHAR* pszDst);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveXMPMetadata(
   L_TCHAR* pszXmlSrc,
   L_TCHAR* pszDst);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPNGTRNS( L_UCHAR * pData, L_UINT uSize );
L_LTFIL_API L_UINT EXT_FUNCTION L_GetPNGTRNS( L_UCHAR * pData );

L_LTFIL_API L_INT EXT_FUNCTION L_GetFilterListInfo(
   pFILTERINFO* ppFilterList,
   L_UINT* pFilterCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFilterInfo(
   L_TCHAR* pFilterName,
   pFILTERINFO pFilterInfo,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeFilterInfo(
   pFILTERINFO pFilterInfo,
   L_UINT uFilterCount,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_SetFilterInfo(
   pFILTERINFO pFilterInfo,
   L_UINT uFilterCount,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeFilterData(L_INT nFilter, L_VOID *pFilterData, L_SIZE_T uFilterDataSize, L_BOOL bLoad);

L_LTFIL_API L_INT EXT_FUNCTION L_DeletePageA(
   L_CHAR* pszFile,
   L_INT nPage,
   L_UINT uFlags,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadLoadResolutionsA(
   L_CHAR* pszFile,
   pDIMENSION pDimensions,
   L_INT* pDimensionCount,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FileConvertA(
   L_CHAR* pszFileSrc,
   L_CHAR* pszFileDst,
   L_INT nType,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   pLOADFILEOPTION pLoadOptions,
   pSAVEFILEOPTIONA pSaveOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_FileInfoA(
   L_CHAR* pszFile,
   pFILEINFOA pFileInfo,
   L_UINT uStructSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FileInfoMemoryA(
   L_UCHAR* pBuffer,
   pFILEINFOA pFileInfo,
   L_UINT uStructSize,
   L_SSIZE_T nBufferSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFileCommentSizeA(
   L_CHAR* pszFile,
   L_UINT uType,
   L_UINT* uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapListA(
   L_CHAR*lpszFile,
   pHBITMAPLIST phList,
   L_INT nBitsTo,
   L_INT nColorOrder,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapMemoryA(
   L_UCHAR* pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileTileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nCol,
   L_INT nRow,
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMemoryTileA(
   L_UCHAR*   pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nCol,
   L_INT nRow,
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileOffsetA(
   L_HFILE fd,
   L_OFFSET nOffsetBegin,
   L_OFFSET nBytesToLoad,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMemoryA(
   L_UCHAR* pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentA(
   L_CHAR* pszFile,
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentExtA(
   L_CHAR* pszFile,
   L_UINT uType,
   pFILECOMMENTS pComments,
   L_UCHAR* pBuffer,
   L_UINT* uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTagA(
   L_CHAR* pFile,
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTag2A(
   L_CHAR* pFile,
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileStampA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileStamp2A(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapBufferA(
   L_UCHAR* pBuffer,
   L_SIZE_T uInitialBufferSize,
   L_SIZE_T* puFinalFileSize,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   SAVEBUFFERCALLBACK pfnSaveBufferCB,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapListA(
   L_CHAR* lpszFile,
   HBITMAPLIST hList,
   L_INT nFormat,
   L_INT nBits,
   L_INT nQFactor,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapMemoryA(
   L_HGLOBAL* phHandle,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_SIZE_T* puSize,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileBufferA(
   L_UCHAR* pBuffer,
   L_SIZE_T uInitialBufferSize,
   L_SIZE_T* puFinalFileSize,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnFileSaveCB,
   SAVEBUFFERCALLBACK pfnSaveBufferCB,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileMemoryA(
   L_HANDLE* hHandle,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pFunction,
   L_VOID* lpUserData,
   L_SIZE_T* uSize,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileTileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nCol,
   L_INT nRow,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileOffsetA(
   L_HFILE fd,
   L_OFFSET nOffsetBegin,
   L_OFFSET* nSizeWritten,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartCompressBufferA(
   pBITMAPHANDLE pBitmap,
   COMPBUFFCALLBACK pfnCallback,
   L_SIZE_T uInputBytes,
   L_SIZE_T uOutputBytes,
   L_UCHAR* pOutputBuffer,
   L_INT nOutputType,
   L_INT nQFactor,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartFeedLoadA(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   L_HGLOBAL* phLoad,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_FeedLoadA(
   L_HGLOBAL hLoad,
   L_UCHAR* pBuffer,
   L_SIZE_T dwBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_StopFeedLoadA(
   L_HGLOBAL hLoad);

L_LTFIL_API L_INT EXT_FUNCTION L_StartFeedInfoA(
   L_HGLOBAL* phInfo,
   pFILEINFOA pFileInfo,
   L_UINT uStructSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FeedInfoA(
   L_HGLOBAL hInfo,
   L_UCHAR* pBuffer,
   L_SIZE_T dwBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFeedInfoA(
   L_HGLOBAL hInfo,
   pFILEINFOA pFileInfo,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_StopFeedInfoA(L_HGLOBAL hInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_StartFeedInfo(
   L_HGLOBAL* phInfo,
   pFILEINFO pFileInfo,
   L_UINT uStructSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FeedInfo(
   L_HGLOBAL hInfo,
   L_UCHAR* pBuffer,
   L_SIZE_T dwBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_StopFeedInfo(L_HGLOBAL hInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileCommentExtA(
   L_CHAR*pszFile,
   L_UINT uType,
   pFILECOMMENTS pComments,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileStampA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDefaultSaveFileOptionA(
   pSAVEFILEOPTIONA pSaveOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileTagA(
   L_CHAR* pszFile,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileCommentA(
   L_CHAR* pszFile,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_CreateThumbnailFromFileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pTHUMBOPTIONS pThumbOptions,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_TransformFileA(
   L_CHAR* pszFileSrc,
   L_CHAR* pszFileDst,
   L_UINT uTransform,
   TRANSFORMFILECALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileExtensionsA(
   L_CHAR* pszFile,
   pEXTENSIONLIST* ppExtensionList,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartDecompressBufferA(
   L_HGLOBAL *phDecompress,
   pSTARTDECOMPRESSDATAA pStartDecompressData);

L_LTFIL_API L_INT EXT_FUNCTION L_IgnoreFiltersA(
   L_CHAR* pszFilters);

L_LTFIL_API L_INT EXT_FUNCTION L_PreLoadFiltersA(
   L_INT nFixedFilters,
   L_INT nCachedFilters,
   L_CHAR* pszFilters);

L_LTFIL_API L_SSIZE_T EXT_FUNCTION L_GetIgnoreFiltersA(
   L_CHAR* pszFilters,
   L_SIZE_T uSize);

L_LTFIL_API L_SSIZE_T EXT_FUNCTION L_GetPreLoadFiltersA(
   L_CHAR* pszFilters,
   L_SIZE_T uSize,
   L_INT* pnFixedFilters,
   L_INT* pnCachedFilters);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMarkersA(
   L_CHAR* pszFilename,
   L_VOID** phMarkers,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileMetaDataA(
   L_CHAR* pFile,
   L_UINT uFlags,
   pSAVEFILEOPTIONA pSaveFileOption);

L_LTFIL_API L_INT EXT_FUNCTION L_StartSaveDataA(
   L_VOID** ppStruct,
   L_CHAR* pszFileName,
   L_INT nCompression,
   L_INT nPlanarConfig,
   L_INT nOrder,           // ORDER_BGR or ORDER_RGB
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_RGBQUAD* pPalette,
   L_UINT uPaletteEntries,
   L_INT XResolution,
   L_INT YResolution,
   L_BOOL bSaveMulti,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetTXTOptionsA(
   pFILETXTOPTIONSA pTxtOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetTXTOptionsA(
   pFILETXTOPTIONSA pTxtOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetCSVOptionsA(
   pFILECSVOPTIONSA pCsvOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetCSVOptionsA(
   pFILECSVOPTIONSA pCsvOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ExtractXMPMetadataA(
   L_CHAR* pszSrc,
   L_CHAR* pszDst);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveXMPMetadataA(
   L_CHAR* pszXmlSrc,
   L_CHAR* pszDst);

L_LTFIL_API L_INT EXT_FUNCTION L_CompactFileA(
   L_CHAR* pszSrcFile,
   L_CHAR* pszDstFile,
   L_UINT uPages,
   pLOADFILEOPTION pLoadFileOption,
   pSAVEFILEOPTIONA pSaveFileOption);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileCMYKArrayA(
   L_CHAR* pszFile,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uArrayCount,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadFileOption,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileCMYKArrayA(
   L_CHAR* pszFile,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uBitmapArrayCount,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileTagsA(
   L_CHAR* pszFile,
   L_UINT uFlags,
   ENUMTAGSCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileTags2A(
   L_CHAR* pszFile,
   L_UINT uFlags,
   ENUMTAGS2CALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteCommentA(
   L_CHAR* pszFile,
   L_UINT uType,
   L_UINT uFlags,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteTagA(
   L_CHAR* pszFile,
   L_INT nPage,
   L_UINT uTag,
   L_UINT uFlags,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileGeoKeyA(
   L_CHAR* pszFile,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileGeoKeyA(
   L_CHAR* pszFile,
   L_UINT16 uTag,
   L_UINT* puType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileGeoKeysA(
   L_CHAR* pszFile,
   L_UINT uFlags,
   ENUMGEOKEYSCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

#if defined(LT_COMP_VECTOR)
L_LTFIL_API L_INT EXT_FUNCTION L_VecAddFontMapperA(
   VECTORFONTMAPPERCALLBACKA pMapper,
   L_VOID* pUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_VecRemoveFontMapperA(
   VECTORFONTMAPPERCALLBACKA pMapper);
#endif // #if defined(LT_COMP_VECTOR)

L_LTFIL_API L_INT EXT_FUNCTION L_SetOverlayCallbackA(
   OVERLAYCALLBACKA pfnCallback,
   L_VOID* pUserData,
   L_UINT uFlags
);

L_LTFIL_API L_INT EXT_FUNCTION L_GetOverlayCallbackA(
   OVERLAYCALLBACKA *ppfnCallback,
   L_VOID** ppUserData,
   L_UINT* puFlags
);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTagsA(
   L_CHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puTagCount,
   pLEADFILETAG* ppTags,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileGeoKeysA(
   L_CHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puTagCount,
   pLEADFILETAG* ppTags,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentsA(
   L_CHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puCommentCount,
   pLEADFILECOMMENT* ppComments,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFormatMimeTypeA(
   L_INT nFormat,
   L_CHAR* pszMimeType,
   L_UINT uMimeTypeCount);

L_LTFIL_API L_BOOL EXT_FUNCTION L_FormatSupportsMultipageSave(
   L_INT nFormat);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFormatFileExtensionA(
   L_INT nFormat,
   L_CHAR* pszExtension,
   L_UINT uExtensionCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetMimeTypeExtensionA(
   const L_CHAR* pszMimeType,
   L_CHAR* pszExtension,
   L_UINT uExtensionCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetExtensionMimeTypeA(
   const L_CHAR* pszExtension,
   L_CHAR* pszMimeType,
   L_UINT uMimeTypeCount);

L_LTFIL_API L_BOOL EXT_FUNCTION L_EnableFastFileInfo(L_BOOL bEnable);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileTagMemory(L_HANDLE* phHandle,
   L_SIZE_T* puSize,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileMetaDataItemsA(
   L_CHAR* pszFile,
   pL_FILEMETADATAITEMSA pMetaData,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_VOID EXT_FUNCTION L_FreeFileMetaDataItemsA(
   pL_FILEMETADATAITEMSA pMetaData);

L_LTFIL_API L_BOOL EXT_FUNCTION L_IsTiffFormat(
   L_INT nFormat);

L_LTFIL_API L_BOOL EXT_FUNCTION L_IsPdfFormat(
   L_INT nFormat);

#if defined(FOR_UNICODE) || !defined(LT_COMP_ANSILIBRARY)
L_LTFIL_API L_INT EXT_FUNCTION L_DeletePage(
   L_TCHAR* pszFile,
   L_INT nPage,
   L_UINT uFlags,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadLoadResolutions(
   L_TCHAR* pszFile,
   pDIMENSION pDimensions,
   L_INT* pDimensionCount,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FileConvert(
   L_TCHAR* pszFileSrc,
   L_TCHAR* pszFileDst,
   L_INT nType,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   pLOADFILEOPTION pLoadOptions,
   pSAVEFILEOPTION pSaveOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_FileInfo(
   L_TCHAR* pszFile,
   pFILEINFO pFileInfo,
   L_UINT uStructSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_FileInfoMemory(
   L_UCHAR* pBuffer,
   pFILEINFO pFileInfo,
   L_UINT uStructSize,
   L_SSIZE_T nBufferSize,
   L_UINT uFlags,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFileCommentSize(
   L_TCHAR* pszFile,
   L_UINT uType,
   L_UINT* uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmap(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapList(
   L_TCHAR*lpszFile,
   pHBITMAPLIST phList,
   L_INT nBitsTo,
   L_INT nColorOrder,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapMemory(
   L_UCHAR* pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileTile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nCol,
   L_INT nRow,
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMemoryTile(
   L_UCHAR*   pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nCol,
   L_INT nRow,
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileOffset(
   L_HFILE fd,
   L_OFFSET nOffsetBegin,
   L_OFFSET nBytesToLoad,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMemory(
   L_UCHAR* pBuffer,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileComment(
   L_TCHAR* pszFile,
   L_UINT uType,
   L_UCHAR* pComment,
   L_UINT uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileCommentExt(
   L_TCHAR* pszFile,
   L_UINT uType,
   pFILECOMMENTS pComments,
   L_UCHAR* pBuffer,
   L_UINT* uLength,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTag(
   L_TCHAR* pFile,
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTag2(
   L_TCHAR* pFile,
   L_UINT16 uTag,
   L_UINT16* pType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileStamp(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileStamp2(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmap(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapBuffer(
   L_UCHAR* pBuffer,
   L_SIZE_T uInitialBufferSize,
   L_SIZE_T* puFinalFileSize,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   SAVEBUFFERCALLBACK pfnSaveBufferCB,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapList(
   L_TCHAR* lpszFile,
   HBITMAPLIST hList,
   L_INT nFormat,
   L_INT nBits,
   L_INT nQFactor,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapMemory(
   L_HGLOBAL* phHandle,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_SIZE_T* puSize,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileBuffer(
   L_UCHAR* pBuffer,
   L_SIZE_T uInitialBufferSize,
   L_SIZE_T* puFinalFileSize,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnFileSaveCB,
   SAVEBUFFERCALLBACK pfnSaveBufferCB,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileMemory(
   L_HANDLE* hHandle,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pFunction,
   L_VOID* lpUserData,
   L_SIZE_T* uSize,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileTile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nCol,
   L_INT nRow,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileOffset(
   L_HFILE fd,
   L_OFFSET nOffsetBegin,
   L_OFFSET* nSizeWritten,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartCompressBuffer(
   pBITMAPHANDLE pBitmap,
   COMPBUFFCALLBACK pfnCallback,
   L_SIZE_T uInputBytes,
   L_SIZE_T uOutputBytes,
   L_UCHAR* pOutputBuffer,
   L_INT nOutputType,
   L_INT nQFactor,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartFeedLoad(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   L_HGLOBAL* phLoad,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_FeedLoad(
   L_HGLOBAL hLoad,
   L_UCHAR* pBuffer,
   L_SIZE_T dwBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_StopFeedLoad(
   L_HGLOBAL hLoad);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileCommentExt(
   L_TCHAR*pszFile,
   L_UINT uType,
   pFILECOMMENTS pComments,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileStamp(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDefaultSaveFileOption(
   pSAVEFILEOPTION pSaveOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileTag(
   L_TCHAR* pszFile,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileComment(
   L_TCHAR* pszFile,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_CreateThumbnailFromFile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   pTHUMBOPTIONS pThumbOptions,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_TransformFile(
   L_TCHAR* pszFileSrc,
   L_TCHAR* pszFileDst,
   L_UINT uTransform,
   TRANSFORMFILECALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileExtensions(
   L_TCHAR* pszFile,
   pEXTENSIONLIST* ppExtensionList,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_StartDecompressBuffer(
   L_HGLOBAL *phDecompress,
   pSTARTDECOMPRESSDATA pStartDecompressData);

L_LTFIL_API L_INT EXT_FUNCTION L_IgnoreFilters(
   L_TCHAR* pszFilters);

L_LTFIL_API L_INT EXT_FUNCTION L_PreLoadFilters(
   L_INT nFixedFilters,
   L_INT nCachedFilters,
   L_TCHAR* pszFilters);

L_LTFIL_API L_SSIZE_T EXT_FUNCTION L_GetIgnoreFilters(
   L_TCHAR* pszFilters,
   L_SIZE_T uSize);

L_LTFIL_API L_SSIZE_T EXT_FUNCTION L_GetPreLoadFilters(
   L_TCHAR* pszFilters,
   L_SIZE_T uSize,
   L_INT* pnFixedFilters,
   L_INT* pnCachedFilters);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadMarkers(
   L_TCHAR* pszFilename,
   L_VOID** phMarkers,
   L_UINT uFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileMetaData(
   L_TCHAR* pFile,
   L_UINT uFlags,
   pSAVEFILEOPTION pSaveFileOption);

L_LTFIL_API L_INT EXT_FUNCTION L_StartSaveData(
   L_VOID** ppStruct,
   L_TCHAR* pszFileName,
   L_INT nCompression,
   L_INT nPlanarConfig,
   L_INT nOrder,           // ORDER_BGR or ORDER_RGB
   L_UINT uWidth,
   L_UINT uHeight,
   L_INT nBitsPerPixel,
   L_RGBQUAD* pPalette,
   L_UINT uPaletteEntries,
   L_INT XResolution,
   L_INT YResolution,
   L_BOOL bSaveMulti,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetTXTOptions(
   pFILETXTOPTIONS pTxtOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetTXTOptions(
   pFILETXTOPTIONS pTxtOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetCSVOptions(
   pFILECSVOPTIONS pCsvOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetCSVOptions(
   pFILECSVOPTIONS pCsvOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_CompactFile(
   L_TCHAR* pszSrcFile,
   L_TCHAR* pszDstFile,
   L_UINT uPages,
   pLOADFILEOPTION pLoadFileOption,
   pSAVEFILEOPTION pSaveFileOption);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadFileCMYKArray(
   L_TCHAR* pszFile,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uArrayCount,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_UINT uFlags,
   FILEREADCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadFileOption,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveFileCMYKArray(
   L_TCHAR* pszFile,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uBitmapArrayCount,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileTags(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   ENUMTAGSCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileTags2(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   ENUMTAGS2CALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteComment(
   L_TCHAR* pszFile,
   L_UINT uType,
   L_UINT uFlags,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_DeleteTag(
   L_TCHAR* pszFile,
   L_INT nPage,
   L_UINT uTag,
   L_UINT uFlags,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileGeoKey(
   L_TCHAR* pszFile,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileGeoKey(
   L_TCHAR* pszFile,
   L_UINT16 uTag,
   L_UINT* puType,
   L_UINT* pCount,
   L_VOID* pData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_EnumFileGeoKeys(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   ENUMGEOKEYSCALLBACK pfnCallback,
   L_VOID* pUserData,
   pLOADFILEOPTION pLoadOptions);

#if defined(LT_COMP_VECTOR)
L_LTFIL_API L_INT EXT_FUNCTION L_VecAddFontMapper(
   VECTORFONTMAPPERCALLBACK pMapper,
   L_VOID* pUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_VecRemoveFontMapper(
   VECTORFONTMAPPERCALLBACK pMapper);
#endif // #if defined(LT_COMP_VECTOR)

L_LTFIL_API L_INT EXT_FUNCTION L_SetOverlayCallback(
   OVERLAYCALLBACK pfnCallback,
   L_VOID* pUserData,
   L_UINT uFlags
);

L_LTFIL_API L_INT EXT_FUNCTION L_GetOverlayCallback(
   OVERLAYCALLBACK *ppfnCallback,
   L_VOID** ppUserData,
   L_UINT* puFlags
);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTags(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puTagCount,
   pLEADFILETAG* ppTags,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileGeoKeys(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puTagCount,
   pLEADFILETAG* ppTags,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileComments(
   L_TCHAR* pszFile,
   L_UINT uFlags,
   L_UINT* puCommentCount,
   pLEADFILECOMMENT* ppComments,
   L_SIZE_T* puDataSize,
   L_UCHAR** ppData,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFormatMimeType(
   L_INT nFormat,
   L_TCHAR* pszMimeType,
   L_UINT uMimeTypeCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetFormatFileExtension(
   L_INT nFormat,
   L_TCHAR* pszExtension,
   L_UINT uExtensionCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetMimeTypeExtension(
   const L_TCHAR* pszMimeType,
   L_TCHAR* pszExtension,
   L_UINT uExtensionCount);

L_LTFIL_API L_INT EXT_FUNCTION L_GetExtensionMimeType(
   const L_TCHAR* pszExtension,
   L_TCHAR* pszMimeType,
   L_UINT uMimeTypeCount);

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileMetaDataItems(
   L_TCHAR* pszFile,
   pL_FILEMETADATAITEMS pMetaData,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_VOID EXT_FUNCTION L_FreeFileMetaDataItems(
   pL_FILEMETADATAITEMS pMetaData);

#else
#define L_DeletePage L_DeletePageA
#define L_ReadLoadResolutions L_ReadLoadResolutionsA
#define L_FileConvert L_FileConvertA
#define L_FileInfo L_FileInfoA
#define L_FileInfoMemory L_FileInfoMemoryA
#define L_GetFileCommentSize L_GetFileCommentSizeA
#define L_LoadBitmap L_LoadBitmapA
#define L_LoadBitmapList L_LoadBitmapListA
#define L_LoadBitmapMemory L_LoadBitmapMemoryA
#define L_LoadFile L_LoadFileA
#define L_LoadFileTile L_LoadFileTileA
#define L_LoadMemoryTile L_LoadMemoryTileA
#define L_LoadFileOffset L_LoadFileOffsetA
#define L_LoadMemory L_LoadMemoryA
#define L_ReadFileComment L_ReadFileCommentA
#define L_ReadFileCommentExt L_ReadFileCommentExtA
#define L_ReadFileTag L_ReadFileTagA
#define L_ReadFileTag2 L_ReadFileTag2A
#define L_ReadFileStamp L_ReadFileStampA
#define L_ReadFileStamp2 L_ReadFileStamp2A
#define L_SaveBitmap L_SaveBitmapA
#define L_SaveBitmapBuffer L_SaveBitmapBufferA
#define L_SaveBitmapList L_SaveBitmapListA
#define L_SaveBitmapMemory L_SaveBitmapMemoryA
#define L_SaveFile L_SaveFileA
#define L_SaveFileBuffer L_SaveFileBufferA
#define L_SaveFileMemory L_SaveFileMemoryA
#define L_SaveFileTile L_SaveFileTileA
#define L_SaveFileOffset L_SaveFileOffsetA
#define L_StartCompressBuffer L_StartCompressBufferA
#define L_StartFeedLoad L_StartFeedLoadA
#define L_FeedLoad L_FeedLoadA
#define L_StopFeedLoad L_StopFeedLoadA
#define L_StartFeedInfo L_StartFeedInfoA
#define L_GetFeedInfo L_GetFeedInfoA
#define L_FeedInfo L_FeedInfoA
#define L_StopFeedInfo L_StopFeedInfoA
#define L_WriteFileCommentExt L_WriteFileCommentExtA
#define L_WriteFileStamp L_WriteFileStampA
#define L_GetDefaultSaveFileOption L_GetDefaultSaveFileOptionA
#define L_WriteFileTag L_WriteFileTagA
#define L_WriteFileComment L_WriteFileCommentA
#define L_CreateThumbnailFromFile L_CreateThumbnailFromFileA
#define L_TransformFile L_TransformFileA
#define L_ReadFileExtensions L_ReadFileExtensionsA
#define L_StartDecompressBuffer L_StartDecompressBufferA
#define L_IgnoreFilters L_IgnoreFiltersA
#define L_PreLoadFilters L_PreLoadFiltersA
#define L_GetIgnoreFilters L_GetIgnoreFiltersA
#define L_GetPreLoadFilters L_GetPreLoadFiltersA
#define L_LoadMarkers L_LoadMarkersA
#define L_WriteFileMetaData L_WriteFileMetaDataA
#define L_StartSaveData L_StartSaveDataA
// There are no ANSI versions of these functions available
//#if defined LT_COMP_UNICODE
//#define L_GetFilterListInfo L_GetFilterListInfoA
//#define L_GetFilterInfo L_GetFilterInfoA
//#define L_FreeFilterInfo L_FreeFilterInfoA
//#define L_SetFilterInfo L_SetFilterInfoA
//#endif // #if defined LT_COMP_UNICODE
#define L_ExtractXMPMetadata L_ExtractXMPMetadataA
#define L_SaveXMPMetadata L_SaveXMPMetadataA
#define L_GetTXTOptions L_GetTXTOptionsA
#define L_SetTXTOptions L_SetTXTOptionsA
#define L_GetCSVOptions L_GetCSVOptionsA
#define L_SetCSVOptions L_SetCSVOptionsA
#define L_CompactFile L_CompactFileA
#define L_LoadFileCMYKArray L_LoadFileCMYKArrayA
#define L_SaveFileCMYKArray L_SaveFileCMYKArrayA
#define L_EnumFileTags L_EnumFileTagsA
#define L_EnumFileTags2 L_EnumFileTags2A
#define L_DeleteComment L_DeleteCommentA
#define L_DeleteTag L_DeleteTagA
#define L_WriteFileGeoKey L_WriteFileGeoKeyA
#define L_ReadFileGeoKey L_ReadFileGeoKeyA
#define L_EnumFileGeoKeys L_EnumFileGeoKeysA
#if defined(LT_COMP_VECTOR)
#define L_VecAddFontMapper L_VecAddFontMapperA
#define L_VecRemoveFontMapper L_VecRemoveFontMapperA
#endif // #if defined(LT_COMP_VECTOR)
#define L_SetOverlayCallback L_SetOverlayCallbackA
#define L_GetOverlayCallback L_GetOverlayCallbackA
#define L_ReadFileTags L_ReadFileTagsA
#define L_ReadFileGeoKeys L_ReadFileGeoKeysA
#define L_ReadFileComments L_ReadFileCommentsA
#define L_GetFormatMimeType L_GetFormatMimeTypeA
#define L_GetFormatFileExtension L_GetFormatFileExtensionA
#define L_GetMimeTypeExtension L_GetMimeTypeExtensionA
#define L_GetExtensionMimeType L_GetExtensionMimeTypeA
#define L_ReadFileMetaDataItems L_ReadFileMetaDataItemsA
#define L_FreeFileMetaDataItems L_FreeFileMetaDataItemsA
#endif // #if defined(FOR_UNICODE) || !defined(LT_COMP_ANSILIBRARY)

// These functions not ported to Windows CE
// functions2
L_LTFIL_API L_INT EXT_FUNCTION L_GetWMFResolution(
   L_INT* lpXResolution,
   L_INT* lpYResolution);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPCDResolution(
   L_INT nResolution);

L_LTFIL_API L_INT EXT_FUNCTION L_SetWMFResolution(
   L_INT nXResolution,
   L_INT nYResolution);

L_LTFIL_API L_INT EXT_FUNCTION L_2DSetViewport(
   L_INT nWidth,
   L_INT nHeight);

L_LTFIL_API L_INT EXT_FUNCTION L_2DGetViewport(
   L_INT* pnWidth,
   L_INT* pnHeight);

L_LTFIL_API L_INT EXT_FUNCTION L_2DSetViewMode(
   L_INT nViewMode);

L_LTFIL_API L_INT EXT_FUNCTION L_2DGetViewMode(L_VOID);

L_LTFIL_API L_INT EXT_FUNCTION L_VecFeedLoad(
   L_HANDLE hLoad,
   L_UCHAR* pInBuffer,
   L_SIZE_T dwBufferSize);

L_LTFIL_API L_INT EXT_FUNCTION L_VecStopFeedLoad(
   L_HANDLE hLoad);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPLTOptions(
   pFILEPLTOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPLTOptions(
   pFILEPLTOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetRTFOptions(
   pFILERTFOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetRTFOptions(
   pFILERTFOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPTKOptions(
   pFILEPTKOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPTKOptions(
   pFILEPTKOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPDFSaveOptions(
   pFILEPDFSAVEOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPDFSaveOptions(
   pFILEPDFSAVEOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetXPSOptions(
   pFILEXPSOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetXPSOptions(
   pFILEXPSOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetExcelOptions(
   pFILEEXCELOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetExcelOptions(
   pFILEEXCELOPTIONS pOptions);

// This function is deprecated. You should use L_GetExcelOptions instead
L_LTFIL_API L_INT EXT_FUNCTION L_GetXLSOptions(
   pFILEXLSOPTIONS pOptions,
   L_UINT uStructSize);

// This function is deprecated. You should use L_SetExcelOptions instead
L_LTFIL_API L_INT EXT_FUNCTION L_SetXLSOptions(
   pFILEXLSOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDOCOptions(
   pFILEDOCOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetDOCOptions(
   pFILEDOCOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetDecryptOptions(pFILEDECRYPTOPTIONS pOptions, L_UINT uStructSize);
L_LTFIL_API L_INT EXT_FUNCTION L_SetDecryptOptions(pFILEDECRYPTOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetANZOptions(
   pFILEANZOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetANZOptions(
   pFILEANZOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPowerPointOptions(
   pFILEPOWERPOINTOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPowerPointOptions(
   pFILEPOWERPOINTOPTIONS pOptions);

#if defined(LT_COMP_EMAILFORMATS)
L_LTFIL_API L_INT EXT_FUNCTION L_GetPSTOptions(
   pFILEPSTOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPSTOptions(
   pFILEPSTOPTIONS pOptions);
#endif // #if defined(LT_COMP_EMAILFORMATS)

#if defined(LT_COMP_SVG)
#if defined(FOR_UNICODE)
// Load SVG support
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvg(
   L_TCHAR* pszFile,
   pLOADSVGOPTIONS pOptions,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvg2(
   L_TCHAR* pszFile,
   pLOADSVGOPTIONS pOptions,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvgMemory(
   L_UCHAR* pBuffer,
   pLOADSVGOPTIONS pOptions,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvg(
   L_TCHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvg2(
   L_TCHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvgMemory(
   L_UCHAR* pBuffer,
   L_BOOL* pbSupported,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_IsSvgFile(
   L_TCHAR* pszFile,
   L_BOOL* pbIsSvg,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);
#else
#define L_LoadSvg L_LoadSvgA
#define L_LoadSvg2 L_LoadSvg2A
#define L_LoadSvgMemory L_LoadSvgMemoryA
#define L_CanLoadSvg L_CanLoadSvgA
#define L_CanLoadSvg2 L_CanLoadSvg2A
#define L_CanLoadSvgMemory L_CanLoadSvgMemoryA
#define L_IsSvgFile L_IsSvgFileA
#endif // #if defined(FOR_UNICODE)
#endif // #if defined(LT_COMP_SVG)

L_LTFIL_API L_INT EXT_FUNCTION L_GetRasterizeDocOptions(
   pRASTERIZEDOCOPTIONS pRasterizeDocOptions,
   L_UINT uStructSize);
L_LTFIL_API L_INT EXT_FUNCTION L_SetRasterizeDocOptions(
   pRASTERIZEDOCOPTIONS pRasterizeDocOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetAutoCADFilesColorScheme(
   L_UINT* dwFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_SetAutoCADFilesColorScheme(
   L_UINT dwFlags);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapResizeA(
   L_CHAR* pszFile,             // name of the file to load
   pBITMAPHANDLE pSmallBitmap,   // pointer to the target bitmap handle
   L_UINT uStructSize,
   L_INT nDestWidth,             // new width of the image
   L_INT nDestHeight,            // new height of the image
   L_INT nDestBits,              // new bits per pixel for the image
   L_UINT uFlags,                // SIZE_NORMAL, SIZE_RESAMPLE SIZE_BICUBIC
   L_INT nOrder,                 // color order for 16-, 24-, 32-, 48, and 64-bit bitmaps
   pLOADFILEOPTION pLoadOptions, // pointer to optional extended load options
   pFILEINFOA pFileInfo);         // pointer to a structure

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTransformsA(
   L_CHAR* pszFile,
   pFILETRANSFORMS pTransforms,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileTransformsA(
   L_CHAR* pszFile,
   pFILETRANSFORMS pTransforms,
   L_INT nFlags,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPCDResolutionA(
   L_CHAR* pszFile,
   pPCDINFO pPCDInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveCustomFileA(
   L_CHAR* pszFilename,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   pSAVEFILEOPTIONA pSaveOptions,
   pSAVECUSTOMFILEOPTION pSaveCustomFileOption,
   SAVECUSTOMFILECALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadCustomFileA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACKA pfnFileReadCallback,
   L_VOID* pFileReadCallbackUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo,
   pLOADCUSTOMFILEOPTION pLoadCustomFileOption,
   LOADCUSTOMFILECALLBACK pfnLoadCustomFileCallback,
   L_VOID* pCustomCallbackUserData);

#if defined(LT_COMP_VECTOR)
L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadFileA(
   L_CHAR* pszFile,
   pVECTORHANDLE pVector,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadMemoryA(
   L_UCHAR* pBuffer,
   pVECTORHANDLE pVector,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecStartFeedLoadA(
   pVECTORHANDLE pVector,
   L_HANDLE*phLoad,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecSaveFileA(
   L_CHAR* pszFile,
   pVECTORHANDLE pVector,
   L_INT nFormat,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_VecSaveMemoryA(
   L_HANDLE*hHandle,
   pVECTORHANDLE pVector,
   L_INT nFormat,
   L_SIZE_T* uSize,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadLayoutA(
   L_CHAR* pszFile,
   pVECTORHANDLE pVector,
   L_INT nLayoutIndex,
   pLAYOUTINFOA pLayoutInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecGetLayoutCountA(
   L_CHAR* pszFile,
   L_INT *pnLayouts);

L_LTFIL_API L_INT EXT_FUNCTION L_VecFreeHandle(pVECTORHANDLE pVector);
#endif // #if defined(LT_COMP_VECTOR)

L_LTFIL_API L_INT EXT_FUNCTION L_GetPDFInitDirA(
   L_CHAR* pszInitDir,
   L_SIZE_T uBufSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPDFInitDirA(
   L_CHAR* pszInitDir);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPDFOptionsA(
   pFILEPDFOPTIONSA pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPDFOptionsA(
   pFILEPDFOPTIONSA pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadLayerA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_INT nLayer,
   pLAYERINFOA pLayerInfo,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapWithLayersA(
   L_CHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   HBITMAPLIST hLayers,
   pLAYERINFOA pLayerInfo,
   L_INT nLayers,
   pSAVEFILEOPTIONA pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadChannelA(L_CHAR* pszFile,            /* name of a file */
                                              pBITMAPHANDLE pBitmap,      /* pointer to the target bitmap handle */
                                              L_UINT uStructSize,         /* size in bytes, of the structure pointed to by pBitmap */
                                              L_INT nBitsPerPixel,
                                              L_INT nOrder,
                                              L_INT nChannel,             /* index of the channel to load */
                                              pCHANNELINFOA pChannelInfo, /* pointer to CHANNELINFO structure */
                                              pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_GetRasterPdfInfoA(L_CHAR* pszPdfFileName, L_INT nPageNumber, pRASTERPDFINFO pRasterPdfInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_GetEmfHandleFromRtfA(
   L_CHAR* pRtfFileName,
   L_INT nPageNumber,
   pFILERTFOPTIONS pRtfOptions,
   pRASTERIZEDOCOPTIONS pRasterizeDocOptions,
   HENHMETAFILE *hEmfHandle);

L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadDocA(
   L_CHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadDocA(
   L_CHAR* pszFile,
   pDOCUMENTCREATEFILEOPTIONSA pOptions,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);

#if defined(LT_COMP_SVG)
// Load SVG support
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvgA(
   L_CHAR* pszFile,
   pLOADSVGOPTIONS pOptions,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvg2A(
   L_CHAR* pszFile,
   pLOADSVGOPTIONS pOptions,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_LoadSvgMemoryA(
   L_UCHAR* pBuffer,
   pLOADSVGOPTIONS pOptions,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvgA(
   L_CHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvg2A(
   L_CHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadSvgMemoryA(
   L_UCHAR* pBuffer,
   L_BOOL* pbSupported,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_IsSvgFileA(
   L_CHAR* pszFile,
   L_BOOL* pbIsSvg,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFOA pFileInfo);
L_LTFIL_API L_INT EXT_FUNCTION L_FreeSvg(L_SvgNodeHandle svgHandle);
#endif // #if defined(LT_COMP_SVG)

L_LTFIL_API L_BOOL EXT_FUNCTION L_TagsSupported(
   L_INT nFormat);

L_LTFIL_API L_BOOL EXT_FUNCTION L_GeoKeysSupported(
   L_INT nFormat);

L_LTFIL_API L_BOOL EXT_FUNCTION L_CommentsSupported(
   L_INT nFormat);

L_LTFIL_API L_BOOL EXT_FUNCTION L_MarkersSupported(
   L_INT nFormat);

L_LTFIL_API L_BOOL EXT_FUNCTION L_FileMetaDataItemsSupported(
   L_INT nFormat);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeFileTags(
   L_UINT uTagCount,
   pLEADFILETAG pTags,
   L_SIZE_T uDataSize,
   L_UCHAR* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_FreeFileComments(
   L_UINT uCommentCount,
   pLEADFILECOMMENT pComments,
   L_SIZE_T uDataSize,
   L_UCHAR* pData);

L_LTFIL_API L_INT EXT_FUNCTION L_SetVFFOptions(pFILEVFFOPTIONS pOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_GetVFFOptions(pFILEVFFOPTIONS pOptions, L_UINT uStructSize);

#if defined(LT_COMP_VECTOR)
L_LTFIL_API L_INT EXT_FUNCTION L_GetVectorOptions(
   pVECTOROPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetVectorOptions(
   pVECTOROPTIONS pOptions);
#endif // #if defined(LT_COMP_VECTOR)

L_LTFIL_API L_INT EXT_FUNCTION L_GetHtmlLoadOptionsA(
   pFILEHTMLLOADOPTIONSA pOptions,
   L_UINT uStructSize);
L_LTFIL_API L_INT EXT_FUNCTION L_SetHtmlLoadOptionsA(
   pFILEHTMLLOADOPTIONSA pOptions);

L_LTFIL_API L_INT EXT_CALLBACK L_GetFilterHeartbeatCallback(FILTERHEARTBEATCALLBACK* ppCallback, L_VOID** ppUserData);
L_LTFIL_API L_INT EXT_CALLBACK L_SetFilterHeartbeatCallback(FILTERHEARTBEATCALLBACK pCallback, L_VOID* pUserData);
L_LTFIL_API L_INT EXT_CALLBACK L_GetFilterTimeout(pFILTERTIMEOUTOPTIONS pOptions, L_UINT uStructSize);
L_LTFIL_API L_INT EXT_CALLBACK L_SetFilterTimeout(const pFILTERTIMEOUTOPTIONS pOptions);

#if defined(FOR_UNICODE)
L_LTFIL_API L_INT EXT_FUNCTION L_LoadBitmapResize(
   L_TCHAR* pszFile,             // name of the file to load
   pBITMAPHANDLE pSmallBitmap,   // pointer to the target bitmap handle
   L_UINT uStructSize,
   L_INT nDestWidth,             // new width of the image
   L_INT nDestHeight,            // new height of the image
   L_INT nDestBits,              // new bits per pixel for the image
   L_UINT uFlags,                // SIZE_NORMAL, SIZE_RESAMPLE SIZE_BICUBIC
   L_INT nOrder,                 // color order for 16-, 24-, 32-, 48, and 64-bit bitmaps
   pLOADFILEOPTION pLoadOptions, // pointer to optional extended load options
   pFILEINFO pFileInfo);         // pointer to a structure

L_LTFIL_API L_INT EXT_FUNCTION L_ReadFileTransforms(
   L_TCHAR* pszFile,
   pFILETRANSFORMS pTransforms,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_WriteFileTransforms(
   L_TCHAR* pszFile,
   pFILETRANSFORMS pTransforms,
   L_INT nFlags,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPCDResolution(
   L_TCHAR* pszFile,
   pPCDINFO pPCDInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveCustomFile(
   L_TCHAR* pszFilename,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   pSAVEFILEOPTION pSaveOptions,
   pSAVECUSTOMFILEOPTION pSaveCustomFileOption,
   SAVECUSTOMFILECALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadCustomFile(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_UINT uFlags,
   FILEREADCALLBACK pfnFileReadCallback,
   L_VOID* pFileReadCallbackUserData,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo,
   pLOADCUSTOMFILEOPTION pLoadCustomFileOption,
   LOADCUSTOMFILECALLBACK pfnLoadCustomFileCallback,
   L_VOID* pCustomCallbackUserData);

#if defined(LT_COMP_VECTOR)
L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadFile(
   L_TCHAR* pszFile,
   pVECTORHANDLE pVector,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadMemory(
   L_UCHAR* pBuffer,
   pVECTORHANDLE pVector,
   L_SSIZE_T nBufferSize,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecStartFeedLoad(
   pVECTORHANDLE pVector,
   L_HANDLE*phLoad,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecSaveFile(
   L_TCHAR* pszFile,
   pVECTORHANDLE pVector,
   L_INT nFormat,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_VecSaveMemory(
   L_HANDLE*hHandle,
   pVECTORHANDLE pVector,
   L_INT nFormat,
   L_SIZE_T* uSize,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_VecLoadLayout(
   L_TCHAR* pszFile,
   pVECTORHANDLE pVector,
   L_INT nLayoutIndex,
   pLAYOUTINFO pLayoutInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_VecGetLayoutCount(
   L_TCHAR* pszFile,
   L_INT *pnLayouts);
#endif // #if defined(LT_COMP_VECTOR)

L_LTFIL_API L_INT EXT_FUNCTION L_GetPDFInitDir(
   L_TCHAR* pszInitDir,
   L_SIZE_T uBufSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPDFInitDir(
   L_TCHAR* pszInitDir);

L_LTFIL_API L_INT EXT_FUNCTION L_GetPDFOptions(
   pFILEPDFOPTIONS pOptions,
   L_UINT uStructSize);

L_LTFIL_API L_INT EXT_FUNCTION L_SetPDFOptions(
   pFILEPDFOPTIONS pOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadLayer(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nBitsPerPixel,
   L_INT nOrder,
   L_INT nLayer,
   pLAYERINFO pLayerInfo,
   pLOADFILEOPTION pLoadOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_SaveBitmapWithLayers(
   L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   HBITMAPLIST hLayers,
   pLAYERINFO pLayerInfo,
   L_INT nLayers,
   pSAVEFILEOPTION pSaveOptions);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadChannel(L_TCHAR* pszFile,           /* name of a file */
                                             pBITMAPHANDLE pBitmap,      /* pointer to the target bitmap handle */
                                             L_UINT uStructSize,         /* size in bytes, of the structure pointed to by pBitmap */
                                             L_INT nBitsPerPixel,
                                             L_INT nOrder,
                                             L_INT nChannel,             /* index of the channel to load */
                                             pCHANNELINFO pChannelInfo,  /* pointer to CHANNELINFO structure */
                                             pLOADFILEOPTION pLoadOptions);
L_LTFIL_API L_INT EXT_FUNCTION L_GetRasterPdfInfo(L_TCHAR* pszPdfFileName, L_INT nPageNumber, pRASTERPDFINFO pRasterPdfInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_GetEmfHandleFromRtf(
   L_TCHAR* pRtfFileName,
   L_INT nPageNumber,
   pFILERTFOPTIONS pRtfOptions,
   pRASTERIZEDOCOPTIONS pRasterizeDocOptions,
   HENHMETAFILE *hEmfHandle);

L_LTFIL_API L_INT EXT_FUNCTION L_CanLoadDoc(
   L_TCHAR* pszFile,
   L_BOOL* pbSupported,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_LoadDoc(
   L_TCHAR* pszFile,
   pDOCUMENTCREATEFILEOPTIONS pOptions,
   pLOADFILEOPTION pLoadOptions,
   pFILEINFO pFileInfo);

L_LTFIL_API L_INT EXT_FUNCTION L_GetHtmlLoadOptions(
   pFILEHTMLLOADOPTIONS pOptions,
   L_UINT uStructSize);
L_LTFIL_API L_INT EXT_FUNCTION L_SetHtmlLoadOptions(
   pFILEHTMLLOADOPTIONS pOptions);


#else
#define L_LoadBitmapResize L_LoadBitmapResizeA
#define L_ReadFileTransforms L_ReadFileTransformsA
#define L_WriteFileTransforms L_WriteFileTransformsA
#define L_GetPCDResolution L_GetPCDResolutionA
#define L_SaveCustomFile L_SaveCustomFileA
#define L_LoadCustomFile L_LoadCustomFileA
#define L_VecLoadFile L_VecLoadFileA
#define L_VecLoadMemory L_VecLoadMemoryA
#define L_VecStartFeedLoad L_VecStartFeedLoadA
#define L_VecSaveFile L_VecSaveFileA
#define L_VecSaveMemory L_VecSaveMemoryA
#define L_GetPDFInitDir L_GetPDFInitDirA
#define L_SetPDFInitDir L_SetPDFInitDirA
#define L_GetPDFOptions L_GetPDFOptionsA
#define L_SetPDFOptions L_SetPDFOptionsA
#define L_LoadLayer L_LoadLayerA
#define L_SaveBitmapWithLayers L_SaveBitmapWithLayersA
#define L_LoadChannel L_LoadChannelA
#define L_GetRasterPdfInfo L_GetRasterPdfInfoA
#define L_GetEmfHandleFromRtf L_GetEmfHandleFromRtfA
#define L_VecLoadLayout L_VecLoadLayoutA
#define L_VecGetLayoutCount L_VecGetLayoutCountA
#define L_GetHtmlLoadOptions L_GetHtmlLoadOptionsA
#define L_SetHtmlLoadOptions L_SetHtmlLoadOptionsA
#define L_CanLoadDoc L_CanLoadDocA
#define L_LoadDoc L_LoadDocA
#endif // #if defined(FOR_UNICODE)

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_CODEC)

#if defined(FOR_JUSTLIB)
   #if defined(__cplusplus)
      #define USE_FILTER(name)                     \
      extern "C" L_INT fltInfo##name(L_VOID*ptr);  \
      void USE_FILTER_##name()                     \
      {                                            \
         fltInfo##name(NULL);                      \
      }
   #else
      #define USE_FILTER(name)                     \
      extern L_INT fltInfo##name(L_VOID*ptr);      \
      void USE_FILTER_##name()                     \
      {                                            \
         fltInfo##name(NULL);                      \
      }
   #endif // #if defined(__cplusplus)
#endif // #if defined(FOR_JUSTLIB)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LEAD_DEFINES_ONLY)

#endif // #if !defined(LTFIL_H)
