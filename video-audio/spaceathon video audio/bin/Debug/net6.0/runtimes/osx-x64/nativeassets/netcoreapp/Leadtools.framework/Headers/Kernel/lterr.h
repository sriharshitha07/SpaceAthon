//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTERR_H)
#define LTERR_H

/*
   Next available error code: ERROR_LEADTOOLS_NEXT
   Use this value for the next error code.
   Change this value every time you create a new error code!
   Change ERROR_LEADTOOLS_LAST_USED when you add new error code!
   DO NOT FORGET to update the wrappers, for example Xcode LTErrorCode.h!
*/

#define ERROR_LEADTOOLS_LAST_USED   -1930
#define ERROR_LEADTOOLS_NEXT        -1931


//=================================================================
// Ltkrn
//=================================================================

// General errors (logical)
typedef enum
{
   SUCCESS                          = 1,     // Function successful
   FAILURE                          = 0,     // Function not successful
   SUCCESS_DELETE                   = 3,     // Function successful. Delete file before quitting
   SUCCESS_RETRY                    = 4,     // Function successful. Retry the failed operation
   SUCCESS_PARTIAL_FAILURE          = 8,     // Function called recursively. A least one call was successful, but some failed

   ERROR_KERNEL_EXPIRED             = -1591, // LEADTOOLS Kernel has expired
   ERROR_INV_PARAMETER              = -13,   // Invalid parameter passed
   ERROR_INVALID_STRUCT_SIZE        = -789,  // The structure size is invalid
   ERROR_BITPERPIXEL                = -27,   // Invalid bits per pixel
   ERROR_INV_RANGE                  = -11,   // Invalid width or height
   ERROR_INCORRECT_WIDTH_ADJUSTED   = -1753, // The width seems to be incorrect and has been automatically adjusted
   ERROR_NO_BITMAP                  = -2,    // Invalid bitmap handle
   ERROR_NULL_PTR                   = -814,  // A NULL pointer was passed
   ERROR_NOT_INITIALIZED            = -30,   // Internal error - call LEAD
   ERROR_FLOAT_DATA_NOT_SUPPORTED   = -1926, // Float image data not supported
   ERROR_SIGNED_DATA_NOT_SUPPORTED  = -1360, // Signed image data not supported
   ERROR_BUFFER_TOO_SMALL           = -290,  // The buffer size is too small
   ERROR_EXCEPTION                  = -149,  // An unspecified exception occurred - could be memory access violations
   ERROR_NOTHING_TO_DO              = -351,  // There is nothing to do.  No items were found
   ERROR_IMAGE_EMPTY                = -144,  // Image is empty
   ERROR_INTERNAL                   = -74,   // Internal error
   ERROR_QFACTOR                    = -21,   // Invalid QFactor specified
   ERROR_INV_HANDLE                 = -261,  // Invalid handle
   ERROR_BAD_POINTER                = -60,   // Internal error - call LEAD
   ERROR_GRAY32_UNSUPPORTED         = -1364, // 32-bit grayscale bitmaps are not supported
   ERROR_INVALID_LUT_LENGTH         = -1486, // The LUT length is invalid. LUTLength should be 1 << (HighBit - LowBit + 1)
   ERROR_INVALID_DIB                = -1491, // The DIB is invalid
   ERROR_GDIPLUS_NOT_FOUND          = -1499, // Cannot load GDI+
   ERROR_GDIPLUS_ERROR              = -1500, // Generic GDI+ error
   ERROR_BITMAP_FORMAT_UNSUPPORTED  = -1541, // The bitmap format is not supported
   ERROR_INVALID_YUV_FORMAT         = -1782, // The YUV format is not supported
   ERROR_INVALID_YUV_SIZE           = -1783, // The size of the YUV buffer is incorrect
   ERROR_INV_UNICODE_STRING         = -1851, // The Unicode string could not be converted to ANSI because it contains characters not supported by the current ANSI page
   ERROR_INV_FILE_HANDLE            = -1852, // (Internal error) Invalid file handle
   ERROR_TEMP_FILE_DISK_DISABLED    = -1853, // Feature requires physical disk temporary files (The feature is disabled because the ability to create temporary files on disk is disabled)
   ERROR_INV_INDEX                  = -1860, // Invalid index
   ERROR_GDI_ERROR                  = -1861, // Generic GDI error
   ERROR_BITMAP_TOO_BIG             = -1906, // The bitmap is too big. Try loading it at a lower resolution
} L_ERROR_GENERAL;

// License errors
typedef enum
{
   ERROR_NO_LICENSE                    = -1790, // No runtime license was set
   ERROR_INV_LICENSE                   = -1754, // Invalid runtime license
   ERROR_SERVER_LICENSE                = -1755, // Invalid runtime server license
   ERROR_SERVER_LICENSE_USER           = -1756, // Specified user for server license was not registered
   ERROR_SERVER_LICENSE_APP            = -1757, // Specified app for server license was not registered
   ERROR_SERVER_LICENSE_CONNECT        = -1758, // Connection to license server failed
   ERROR_SERVER_LICENSE_NOT_ACTIVATED  = -1759, // Server runtime license has not been activated or machine has changed
   ERROR_INV_LICENSE_VERSION           = -1785, // Invalid runtime license version
} L_ERROR_LICENSE;

// Operation abortion errors (runtime)
typedef enum
{
   SUCCESS_ABORT        = 2,     // Function successful. You can quit now
   ERROR_USER_ABORT     = -100,  // User has aborted operation
   ERROR_NORMAL_ABORT   = -29,   // Escape key pressed - or user aborted operation
   ERROR_EXTERNAL_PROCESS_TERMINATED   = -1865, // The external process was terminated abnormally
} L_ERROR_ABORTION;

// Memory errors (runtime)
typedef enum
{
   ERROR_NO_MEMORY      = -1, // Not enough memory available
   ERROR_MEMORY_TOO_LOW = -3, // Not enough memory available
   ERROR_MEMORY_LIMIT   = -1905, // You have exceeded the amount of memory allowed for allocations in this application
} L_ERROR_MEMORY;

// Support locked errors (logical)
typedef enum
{
   ERROR_FEATURE_NOT_SUPPORTED   = -16,   // Feature not supported
   ERROR_FEATURE_NOT_SUPPORTED_ON_THIS_PLATFORM = -1858, // Feature not supported on this platform
   ERROR_FEATURE_NOT_SUPPORTED_ON_THIS_OPERATING_SYSTEM = -1907, // Feature not supported on this operating system
   ERROR_FEATURE_NOT_SUPPORTED_FOR_THIS_FORMAT = -1904,  // Feature not supported for this format
   ERROR_DOCUMENT_NOT_ENABLED    = -143,  // Document capability is required to use this function
   ERROR_MEDICAL_NOT_ENABLED     = -314,  // Medical capability is required to use this function
   ERROR_LTPRO_NOT_ENABLED       = -930,  // LEADTOOLS Pro Features are not enabled
   ERROR_LZW_LOCKED              = -146,  // The LZW capabilities are locked
   ERROR_JBIG_NOT_ENABLED        = -315,  // JBIG capability is required to use this function
   ERROR_JBIG2_LOCKED            = -1362, // JBIG2 file format is locked
   ERROR_J2K_LOCKED              = -542,  // J2K support is locked
   ERROR_PDF_NOT_ENABLED         = -408,  // PDF support is locked
   ERROR_CMW_LOCKED              = -354,  // The CMW support is locked
   ERROR_ABC_LOCKED              = -1361, // ABC file format is locked
   ERROR_MEDICAL_NET_NOT_ENABLED = -318,  // Medical Network capability is required to use this function
   ERROR_NITF_LOCKED             = -1363, // NITF support is locked
   ERROR_JPIP_LOCKED             = -1477, // JPIP support is locked
   ERROR_FORMS_LOCKED            = -1478, // FORMS support is locked
   ERROR_DOCUMENT_WRITERS_NOT_ENABLED        = -1493, // Document Writers capability is required to use this function
   ERROR_MEDIA_WRITER_NOT_ENABLED            = -1494, // Media writer capability is required to use this function
   ERROR_DOCUMENT_WRITERS_PDF_NOT_ENABLED    = -1495, // Document Writer PDF support is locked
   ERROR_LEADPRINTER_NOT_ENABLED             = -1535, // LEADTOOLS Printer Driver is required to use this function
   ERROR_LEADPRINTER_SERVER_NOT_ENABLED      = -1536, // LEADTOOLS Printer Driver Server is required to use this function
   ERROR_LEADPRINTER_NETWORK_NOT_ENABLED     = -1628,  // LEADTOOLS Printer Driver Network is required to use this function
   ERROR_APP_STORE_NOT_ENABLED   = -1750, // LEADTOOLS App Store license is required to use this function
   ERROR_BASIC_NOT_ENABLED       = -1751, // LEADTOOLS Basic license is required to use this function
   ERROR_NO_SERVER_LICENSE       = -1752, // Requires a LEADTOOLS server license
   ERROR_MEDIA_STREAMING_NOT_ENABLED      = -1775, // LEADTOOLS Media Streaming is required to use this function
   ERROR_SVG_NOT_ENABLED = -1873, // LEADTOOLS SVG is required to use this function
   ERROR_ANNOTATIONS_NOT_ENABLED = -1874, // LEADTOOLS Annotations is required to use this function
   ERROR_DOCUMENT_EDITING_NOT_ENABLED = -1897, // LEADTOOLS Document Editing is required to use this function
} L_ERROR_SUPPORT_GENERAL;

// File I/O errors (runtime)
typedef enum
{
   ERROR_FILENOTFOUND   = -10,   // File not found
   ERROR_FILE_OPEN      = -14,   // Not able to open file
   ERROR_FILE_WRITE     = -5,    // Error writing file
   ERROR_FILE_GONE      = -6,    // File not present - abort
   ERROR_FILE_READ      = -7,    // Error reading file
   ERROR_FILE_LSEEK     = -4,    // Error seeking to position
   ERROR_DISK_ISFULL    = -295,  // Not enough disk space
   ERROR_FILE_READONLY  = -805,  // File is read-only. Cannot open file with write access
   ERROR_FILE_WRITEONLY = -1854, // File is write-only. Cannot open file with read access
   ERROR_FILE_READ_DENIED = -1855, // Read access was denied. The operation needs to be able to read from the file.
   ERROR_FILE_WRITE_DENIED = -1856, // Write access was denied. The operation needs to be able to write to the file.
   ERROR_FILE_FORMAT    = -9,    // Invalid file format
   ERROR_INV_FILENAME   = -8,    // Invalid filename specified
   ERROR_FILE_CREATE    = -1490, // Error creating file
   ERROR_MAX_OPEN_FILES = -1786, // Too many open files
   ERROR_FILE_ACCESS_DENIED = -1846, // Access denied
   ERROR_FILE_DELETE    = -1847, // Error deleting file
   ERROR_FOLDER_CREATE  = -1849, // Error creating folder
   ERROR_FILENAME_ALREADY_REGISTERED = -1850, // (Internal) Filename already registered
   ERROR_TOO_MANY_TEMP_FILES = -1894,  // There are too many files in the temp folder
   ERROR_TEMP_FILE_CREATE_ACCESS_DENIED = -1902, // An access denied error occurred trying to create a temporary file. Check the access rights for the temp folder
   ERROR_TEMP_FILE_CREATE = -1903, // An unknown error occurred trying to create a temporary file. Make sure you can create files in the temp folder
   ERROR_FILE_TRUNCATED = -1920, // The file is probably truncated. More data was needed to correctly decode the file
} L_ERROR_FILE_IO;

// DLL missing errors (runtime)
typedef enum
{
   ERROR_FILTER_IGNORED             = -1841, // The file filter needed to support this format has been marked as ignored
   ERROR_DXF_FILTER_MISSING         = -309,  // DXF DLL is missing
   ERROR_JBIG_FILTER_MISSING        = -319,  // JBG DLL is missing
   ERROR_WMF_FILTER_MISSING         = -349,  // WMF DLL is missing
   ERROR_CMW_FILTER_MISSING         = -355,  // CMW DLL is missing
   ERROR_CMP_FILTER_MISSING         = -356,  // CMP DLL is missing
   ERROR_FAX_FILTER_MISSING         = -357,  // FAX DLL is missing
   ERROR_PDF_FILTER_MISSING         = -358,  // PDF DLL is missing
   ERROR_TIF_FILTER_MISSING         = -359,  // TIF DLL is missing
   ERROR_DCR_FILTER_MISSING         = -819,  // DCR DLL is missing
   ERROR_KDC_FILTER_MISSING         = -820,  // KDC DLL is missing
   ERROR_DCS_FILTER_MISSING         = -821,  // DCS DLL is missing
   ERROR_ABC_FILTER_MISSING         = -822,  // ABC DLL is missing
   ERROR_ABI_FILTER_MISSING         = -823,  // ABI DLL is missing
   ERROR_JB2_FILTER_MISSING         = -824,  // JB2 DLL is missing
   ERROR_J2K_FILTER_MISSING         = -541,  // J2K DLL is missing
   ERROR_PNG_FILTER_MISSING         = -825,  // PNG DLL is missing
   ERROR_LTCLR_MISSING              = -807,  // LTCLR DLL is missing
   ERROR_LTVKRN_MISSING             = -353,  // LTVKRN DLL is missing
   ERROR_LTSGM_MISSING              = -818,  // LTSGM DLL is missing
   ERROR_LTANN_MISSING              = -1479, // LTANN DLL is missing
   ERROR_LTIMG_MISSING              = -1480, // LTIMG DLL is missing
   ERROR_LTKRN_MISSING              = -1482, // LTKRN DLL is missing
   ERROR_LTFIL_MISSING              = -1483, // LTFIL DLL is missing
   ERROR_LTDIS_MISSING              = -1484, // LTDIS DLL is missing
   ERROR_LTDIC_MISSING              = -1485, // LTDIC DLL is missing
   ERROR_LTDOCWRT_MISSING           = -1788, // LTDOCWRT DLL is missing
   ERROR_LTDOCWRTALTO_MISSING       = -1862, // LTDocWrtAlto DLL is missing
   ERROR_LTDOCWRTDOCX_MISSING       = -1898, // LTDOCWRTDOCX DLL is missing
   ERROR_LTDOCWRTRTF_MISSING        = -1899, // LTDOCWRTRTF DLL is missing
   ERROR_LTDOCWRTTXT_MISSING        = -1900, // LTDOCWRTTXT DLL is missing
   ERROR_LTDRW_MISSING              = -1784, // LTDRW DLL is missing
   ERROR_LTDRWMP_MISSING            = -1826, // LTDRWMP DLL is missing
   ERROR_LTEFX_MISSING              = -1791, // LTEFX DLL is missing
   ERROR_LTMRC_MISSING              = -1793, // LTMRC DLL is missing
   ERROR_LTPDFCOMP_MISSING          = -1794, // LTPDFCOMP DLL is missing
   ERROR_LTCC_MISSING               = -1795, // LTCC DLL is missing
   ERROR_LTPDF_MISSING              = -1796, // LTPDF DLL is missing
   ERROR_BMP_FILTER_MISSING         = -1496, // LFBMP DLL is missing
   ERROR_RAW_FILTER_MISSING         = -1497, // LFRAW DLL is missing
   ERROR_RTF_FILTER_MISSING         = -1537, // LFRTF DLL is missing
   ERROR_PDF_UTL_MISSING            = -1540, // LTPDFUTL DLL is missing
   ERROR_PDF_ENGINE_MISSING         = -1540, // LTPDFEngine DLL is missing. Deprecated in v20 and later.
   ERROR_CGM_FILTER_MISSING         = -1543, // CGM DLL is missing
   ERROR_CLP_FILTER_MISSING         = -1544, // CLP DLL is missing
   ERROR_CRW_FILTER_MISSING         = -1545, // CRW DLL is missing
   ERROR_DJV_FILTER_MISSING         = -1546, // DJV DLL is missing
   ERROR_DRW_FILTER_MISSING         = -1547, // DRW DLL is missing
   ERROR_DWF_FILTER_MISSING         = -1548, // DWF DLL is missing
   ERROR_DWG_FILTER_MISSING         = -1549, // DWG DLL is missing
   ERROR_EPS_FILTER_MISSING         = -1550, // EPS DLL is missing
   ERROR_FIT_FILTER_MISSING         = -1551, // FIT DLL is missing
   ERROR_FLC_FILTER_MISSING         = -1552, // FLC DLL is missing
   ERROR_GIF_FILTER_MISSING         = -1553, // GIF DLL is missing
   ERROR_HDP_FILTER_MISSING         = -1554, // HDP DLL is missing
   ERROR_IFF_FILTER_MISSING         = -1555, // IFF DLL is missing
   ERROR_JP2_FILTER_MISSING         = -1556, // JP2 DLL is missing
   ERROR_JPM_FILTER_MISSING         = -1557, // JPM DLL is missing
   ERROR_CIN_FILTER_MISSING         = -1558, // CIN DLL is missing
   ERROR_LMB_FILTER_MISSING         = -1559, // LMB DLL is missing
   ERROR_MIF_FILTER_MISSING         = -1560, // MIF DLL is missing
   ERROR_MNG_FILTER_MISSING         = -1561, // MNG DLL is missing
   ERROR_MSP_FILTER_MISSING         = -1562, // MSP DLL is missing
   ERROR_NTF_FILTER_MISSING         = -1563, // NTF DLL is missing
   ERROR_PCD_FILTER_MISSING         = -1564, // PCD DLL is missing
   ERROR_PCX_FILTER_MISSING         = -1565, // PCX DLL is missing
   ERROR_PSD_FILTER_MISSING         = -1566, // PSD DLL is missing
   ERROR_PSP_FILTER_MISSING         = -1567, // PSP DLL is missing
   ERROR_RAS_FILTER_MISSING         = -1568, // RAS DLL is missing
   ERROR_SFF_FILTER_MISSING         = -1569, // SFF DLL is missing
   ERROR_SGI_FILTER_MISSING         = -1570, // SGI DLL is missing
   ERROR_SGM_FILTER_MISSING         = -1571, // SGM DLL is missing
   ERROR_SHP_FILTER_MISSING         = -1572, // SHP DLL is missing
   ERROR_SID_FILTER_MISSING         = -1573, // SID DLL is missing
   ERROR_SNP_FILTER_MISSING         = -1574, // SNP DLL is missing
   ERROR_SVG_FILTER_MISSING         = -1575, // SVG DLL is missing
   ERROR_TDB_FILTER_MISSING         = -1576, // TDB DLL is missing
   ERROR_TGA_FILTER_MISSING         = -1577, // TGA DLL is missing
   ERROR_VEC_FILTER_MISSING         = -1578, // VEC DLL is missing
   ERROR_VPG_FILTER_MISSING         = -1579, // VPG DLL is missing
   ERROR_WFX_FILTER_MISSING         = -1580, // WFX DLL is missing
   ERROR_WMZ_FILTER_MISSING         = -1581, // WMZ DLL is missing
   ERROR_WPG_FILTER_MISSING         = -1582, // WPG DLL is missing
   ERROR_XPS_FILTER_MISSING         = -1583, // XPS DLL is missing
   ERROR_XWD_FILTER_MISSING         = -1584, // XWD DLL is missing
   ERROR_ITG_FILTER_MISSING         = -1585, // ITG DLL is missing
   ERROR_VFF_FILTER_MISSING         = -1586, // VFF DLL is missing
   ERROR_JXR_FILTER_MISSING         = -1587, // JXR DLL is missing
   ERROR_JLS_FILTER_MISSING         = -1588, // JLS DLL is missing
   ERROR_DCF_FILTER_MISSING         = -1589, // DCF DLL is missing
   ERROR_HTM_FILTER_MISSING         = -1595, // HTM DLL is missing
   ERROR_MOB_FILTER_MISSING         = -1596, // MOB DLL is missing
   ERROR_PUB_FILTER_MISSING         = -1597, // PUB DLL is missing
   ERROR_ING_FILTER_MISSING         = -1598, // ING DLL is missing
   ERROR_PST_FILTER_MISSING         = -1773, // PST DLL is missing
   ERROR_XMP_FILTER_MISSING         = -1776, // XMP DLL is missing
   ERROR_X9F_FILTER_MISSING         = -1777, // X9F DLL is missing
   ERROR_THREEJS_FILTER_MISSING     = -1789, // 3JS DLL is missing
   ERROR_STL_FILTER_MISSING         = -1835, // STL DLL is missing
   ERROR_TXT_FILTER_MISSING         = -1792, // TXT DLL is missing
   ERROR_CMX_FILTER_MISSING         = -1797, // CMX DLL is missing
   ERROR_DGN_FILTER_MISSING         = -1798, // DGN DLL is missing
   ERROR_E00_FILTER_MISSING         = -1799, // E00 DLL is missing
   ERROR_GBR_FILTER_MISSING         = -1827, // GBR DLL is missing
   ERROR_NAP_FILTER_MISSING         = -1828, // NAP DLL is missing
   ERROR_PCL_FILTER_MISSING         = -1829, // PCL DLL is missing
   ERROR_PCT_FILTER_MISSING         = -1830, // PCT DLL is missing
   ERROR_AFP_FILTER_MISSING         = -1831, // AFP DLL is missing
   ERROR_CAL_FILTER_MISSING         = -1832, // CAL DLL is missing
   ERROR_ICA_FILTER_MISSING         = -1833, // ICA DLL is missing
   ERROR_LMA_FILTER_MISSING         = -1834, // LMA DLL is missing
   ERROR_PTK_FILTER_MISSING         = -1808, // PTK DLL is missing
   ERROR_DOC_FILTER_MISSING         = -1809, // DOC DLL is missing
   ERROR_DOX_FILTER_MISSING         = -1810, // DOX DLL is missing
   ERROR_PPT_FILTER_MISSING         = -1811, // PPT DLL is missing
   ERROR_PPX_FILTER_MISSING         = -1812, // PPX DLL is missing
   ERROR_XLS_FILTER_MISSING         = -1813, // XLS DLL is missing
   ERROR_XLX_FILTER_MISSING         = -1814, // XLX DLL is missing
   ERROR_PNM_FILTER_MISSING         = -1815, // PNM DLL is missing
   ERROR_WMP_FILTER_MISSING         = -1816, // WMP DLL is missing
   ERROR_CUT_FILTER_MISSING         = -1817, // CUT DLL is missing
   ERROR_IMG_FILTER_MISSING         = -1818, // IMG DLL is missing
   ERROR_MAC_FILTER_MISSING         = -1819, // MAC DLL is missing
   ERROR_SMP_FILTER_MISSING         = -1820, // SMP DLL is missing
   ERROR_XPM_FILTER_MISSING         = -1821, // XPM DLL is missing
   ERROR_ANZ_FILTER_MISSING         = -1822, // ANZ DLL is missing
   ERROR_SCT_FILTER_MISSING         = -1823, // SCT DLL is missing
   ERROR_TFX_FILTER_MISSING         = -1824, // TFX DLL is missing
   ERROR_ANI_FILTER_MISSING         = -1825, // ANI DLL is missing
   ERROR_ECW_FILTER_MISSING         = -1842, // ECW DLL is missing
   ERROR_FPX_FILTER_MISSING         = -1843, // FPX DLL is missing
   ERROR_AWD_FILTER_MISSING         = -1844, // AWD DLL is missing
   ERROR_XBM_FILTER_MISSING         = -1845, // XBM DLL is missing
   ERROR_WEBP_FILTER_MISSING        = -1922, // WEBP DLL is missing
   ERROR_BARCODE1DWRITE_MISSING           = -1836, // Barcode 1D Write DLL is missing
   ERROR_BARCODEPDFWRITE_MISSING          = -1837, // Barcode PDF Write DLL is missing
   ERROR_BARCODEDATAMATRIXWRITE_MISSING   = -1838, // Barcode DATAMATRIX Write DLL is missing
   ERROR_BARCODEQRWRITE_MISSING           = -1839, // Barcode QR Write DLL is missing
   ERROR_BARCODE2DWRITE_MISSING           = -1840, // Barcode 2D Write DLL is missing
   ERROR_LTWEBKITENGINE_MISSING           = -1857, // LTWebKitEngine DLL is missing
   ERROR_OPENSSL_DLL_MISSING              = -1864, // OpenSSL DLL is missing
   ERROR_ICR_MISSING                      = -1875, // ICR DLL is missing
   ERROR_ML_MISSING                       = -1878, // ML DLL is missing
   ERROR_HEIF_FILTER_MISSING              = -1883, // HEIF DLL is missing
   ERROR_DOCCORE_MISSING                  = -1895, // DocCore DLL is missing
   ERROR_TWN_MISSING                      = -1908, // TWN DLL is missing
   ERROR_WIA_MISSING                      = -1909, // WIA DLL is missing
   ERROR_DLGFILE_MISSING                  = -1912, // File Dialogs DLL is missing
   ERROR_SCR_MISSING                      = -1913, // Screen Capture DLL is missing
   ERROR_EFX_MISSING                      = -1914, // Special Effects DLL is missing
   ERROR_PRINTER_MISSING                  = -1915, // Printer DLL is missing
   ERROR_DLGKRN_MISSING                   = -1916, // Kernel Dialogs DLL is missing
   ERROR_DLGUTL_MISSING                   = -1917, // Dialogs Utilities DLL is missing
   ERROR_DLGCOM_MISSING                   = -1918, // Common Dialogs is missing
   ERROR_DLGCTRL_MISSING                  = -1919, // Dialogs Controls is missing
   ERROR_ASR_MISSING                      = -1921, // ASR DLL is missing
   ERROR_JPIPSP_MISSING                   = -1929, // JPIPSP DLL is missing
   ERROR_JPIPCD_MISSING                   = -1930, // JPIPCD DLL is missing
} L_ERROR_MISSING;

// Overlay errors (logical)
typedef enum
{
   ERROR_NO_OVERLAY     = -815,  // The overlay does not exist
   ERROR_OVERLAY_INDEX  = -816,  // Something is wrong with the overlay index
} L_ERROR_OVERLAY;

//=================================================================
// Ltfil
//=================================================================

// Ltfil general errors (logical)
typedef enum
{
   ERROR_ALL_PAGES_OUT_RANGE = -1896, // All the specified pages are out of document page range
   ERROR_WINDOWSIZE        = -28,   // Invalid window size
   ERROR_INV_FILTERNAME    = -1353, // Invalid filter name
   ERROR_PAGE_NOT_FOUND    = -310,  // Page not found
   ERROR_DELETE_LAST_PAGE  = -311,  // You cannot delete a page from a file containing only one page
   ERROR_IMAGE_TYPE        = -12,   // Image format recognized, but sub-type not supported
   ERROR_BAD_DECODE_STATE  = -77,   // Premature end-of-line code
   ERROR_LAYER_MISSING     = -800,  // The PSD Layer is missing
   ERROR_OUTPUTTYPE        = -23,   // Invalid compression format
   ERROR_VERSION_NUMBER    = -78,   // Bad version number
   ERROR_NO_THUMBNAIL      = -520,  // Thumbnail not found
   ERROR_CHANNEL_MISSING   = -1492, // The PSD Channel is missing
   ERROR_FILE_SIZE_TOO_BIG = -1778, // The file size is too big for selected format (eg: trying to create a TIFF file > 4GB)
   ERROR_FORMAT_MISMATCH   = -1779, // File format mismatch (eg: trying to save a TIFF page into a BigTIFF file)
   ERROR_FILEINFO_UPDATED  = -1780, // The FILEINFO structure has been updated. The file can be reloaded
   ERROR_INV_PAGE_NUMBERS  = -1787, // The first or last page number is incorrect
   ERROR_NO_PAGES          = -1848, // The document has no pages
   ERROR_FILE_CORRUPTED    = -1859, // The file format is recognized, but is corrupted
   ERROR_FORMAT_RECOGNIZED_BUT_OPERATION_FAILED = -1863, // The file format is recognized, but the operation failed
   ERROR_ATTACHMENT_NOT_FOUND = -1869, // The requested attachment was not found
   ERROR_NO_ATTACHMENTS    = -1870,    // The file has no attachments
   ERROR_ENCRYPTED         = -1876, // The source file is encrypted and no password was provided
   ERROR_REDIRECT_TO_FILTER = -1877, // Internal error - redirect to another filter
   ERROR_NO_EXIF_METADATA  = -1893, // The Exif metadata is missing
   ERROR_INV_RASTERIZEDOCOPTIONS = -1910, // The RASTERIZEDOCOPTIONS are invalid
   ERROR_ENCODER_FAILURE   = -1923, // Generic error encoding the data
   ERROR_FLOAT_DATA_CONVERSION_NOT_SUPPORTED = -1927, // Conversion of floating data is not supported
} L_ERROR_LTFIL;

// J2K errors (logical)
typedef enum
{
   ERROR_JP2_FAILURE             = -530,  // Error in JP2 Box values
   ERROR_JP2_SIGNATURE           = -531,  // The header does not match the JP2 signature - not a JP2 file
   ERROR_JP2_UNSUPPORTED         = -532,  // JP2 file has a feature that is unsupported
   ERROR_J2K_FAILURE             = -533,  // Invalid save options were specified to the encoder
   ERROR_J2K_NO_SOC              = -534,  // File header does not contain SOC marker
   ERROR_J2K_NO_SOT              = -535,  // File contains complete header but no compressed image data
   ERROR_J2K_INFORMATION_SET     = -536,  // Invalid save options were specified or file includes invalid encoded values
   ERROR_J2K_LOW_TARGET_SIZE     = -537,  // Compression ratio, target file size, or tile size was too small for encoder
   ERROR_J2K_DECOMPOSITION_LEVEL = -538,  // Specified Wavelet decomposition level was too high
   ERROR_J2K_MARKER_VALUE        = -539,  // Decoder could not translate J2K marker - file is corrupt or invalid
   ERROR_J2K_UNSUPPORTED         = -540,  // J2K file has image with more than 30 bits per component
   ERROR_J2K_BOX_NOT_AVAILABLE   = -1501, // The required box is not available
} L_ERROR_J2K;

// Stamp errors (logical)
typedef enum
{
   ERROR_NO_STAMP             = -65,   // Stamp not found
   ERROR_INVALID_STAMP_SIZE   = -141,  // Stamp size is too big or invalid bits per pixel, etc
   ERROR_BAD_STAMP            = -142,  // Stamp is present but data is corrupted
} L_ERROR_STAMP;

// Marker callback status (runtime)
typedef enum
{
   SUCCESS_IGNORETHISCOPYALL  = 7,  // Function successful. Ignore this marker but copy all remaining markers
   SUCCESS_IGNOREALLMARKERS   = 6,  // Function successful. Ignore this marker and all remaining markers
   SUCCESS_IGNOREMARKER       = 5,  // Function successful. Ignore this marker
} L_ERROR_MARKER_STATUS;

// Marker errors (logical)
typedef enum
{
   ERROR_BAD_MARKER           = -801,  // Bad JPEG marker
   ERROR_BAD_RESYNC_MARKER    = -806,  // Bad JPEG Resync marker
   ERROR_MARKER_SIZE_TOO_BIG  = -808,  // The size of the JPEG marker cannot exceed 64K
   ERROR_MARKER_MISSING       = -809,  // The required JPEG marker is missing
   ERROR_MARKER_INDEX         = -811,  // The marker index is invalid (too big)
} L_ERROR_MARKER;

// Extension errors (logical)
typedef enum
{
   ERROR_AUDIO_MISSING           = -802,  // The audio data is not present
   ERROR_EXTENSIONS_MISSING      = -810,  // This file does not contain EXIF extensions
} L_ERROR_EXTENSION;

//=================================================================
// Ltclr
//=================================================================

// Ltclr general errors (logical)
typedef enum
{
   ERROR_INV_COLORSPACE                               = -918,  // Invalid colorspace
   ERROR_INVALID_FORMAT                               = -785,  // Invalid format
   ERROR_UNSUPPORTED_METHOD                           = -786,  // Method not supported
   ERROR_OPENING_PROFILE                              = -787,  // Error opening profile
   ERROR_INVALID_COLOR_PROFILE                        = -788,  // Invalid color profile
   ERROR_U_V_NOT_MULTIPLES                            = -791,  // U and V are not multiples
   ERROR_NO_NONPLANAR_VERTICAL_SUBSAMPLING_SUPPORTED  = -792,  // Non planar vertical sub sampling not supported
   ERROR_PLANAR_ALIGNMENT_NOT_SUPPORTED               = -793,  // Planar alignment not supported
   ERROR_UNSUPPORTED_CONVERSION                       = -794,  // Unsupported conversion
   ERROR_TRUNCATE_HEIGHT                              = -795,  // Truncate height
   ERROR_TRUNCATE_WIDTH                               = -796,  // Truncate width
   ERROR_TRUNCATE_WIDTH_AND_HEIGHT                    = -797,  // Truncate width and height
   ERROR_LTCLR_INVALID                                = -1871, // LTCLR dll is invalid or corrupted
   ERROR_NOT_TIFF_FILE                                = -1872, // The file passed to this function is not a TIFF file.
   ERROR_COLOR_CONVERSION                             = -1911, // Generic color conversion error
} L_ERROR_LTCLR;

// Ltclr ICC errors (logical)
typedef enum
{
   ERROR_ICC_UNKNOWN_TAG            = -1150, // Unknown ICC profile Tag
   ERROR_ICC_UNKNOWN_TYPE           = -1151, // Unknown ICC profile Type
   ERROR_ICC_UNKNOWN_TAG_AND_TYPE   = -1152, // Unknown ICC profile Tag and Type
   ERROR_INVALID_ICC_PROFILE        = -1153, // Invalid ICC profile
   ERROR_ICC_IMAGE_NOT_SUPPORTED    = -1154, // Invalid ICC profile
   ERROR_NO_PROFILE                 = -812,  // The ICC profile was not found
   ERROR_CORRUPT_PROFILE            = -817,  // The ICC profile was invalid
   ERROR_DECODING_PROFILE           = -813,  // An error has occurred while decoding the profile
} L_ERROR_ICC;

//=================================================================
// Ltdis
//=================================================================

// Pan window errors (logical)
typedef enum
{
   ERROR_PANWINDOW_NOT_CREATED   = -91,   // PanWindow creation failed
} L_ERROR_PANWIN;

//=================================================================
// Lttmb
//=================================================================

// Browser errors
typedef enum
{
   ERROR_BROWSE_FAILED  = -350,  // browser operation failed
} L_ERRORL_LTTMB;

//=================================================================
// Ltdic
//=================================================================
typedef enum
{
   ERROR_DICOM_NOT_ENABLED = -803,  // DICOM support is required to use this function
} L_ERROR_SUPPORT_DICOM;

//=================================================================
// Pdf
//=================================================================
typedef enum
{
   ERROR_PDF_FILE_ENCRYPTED               = -721,  // The Pdf file is encrypted and the Password was not set (no password).
   ERROR_PDF_INVALID_PASSWORD             = -722,  // Invalid password specified
   ERROR_PDF_FAX_NOT_ENABLED              = -723,  // FAX filter is required for this function
   ERROR_PDF_JPEG_NOT_ENABLED             = -724,  // CMP and JPEG filter is required for this function
   ERROR_PDF_INV_DOC_STRUCTURING_COMMENTS = -725,  // Invalid Document Structuring comments (PS and EPS)
   ERROR_PDF_FONTS_DIRECTORY_NOT_FOUND    = -726,  // Could not find Fonts directory
   ERROR_PDF_CANNOT_EDIT_FILE             = -727,  // Cannot insert, delete, append or replace pages
   ERROR_PDF_BAD_CONTENT                  = -728,  // File is corrupted
   ERROR_PDF_BAD_INITIALIZATION_FILES     = -729,  // Either the files required for initializing the PDF engine were not found or they were found but they are incorrect
   ERROR_PDF_BAD_INTERPAGELINKS           = -1599, // PDF has internal links which refer to other pages that do not exist
   ERROR_PDF_UTL_INVALID                  = -1868, // LTPDFUTL is invalid or out of date
} L_ERROR_RASTERPDF;

//=================================================================
// Ltimg
//=================================================================
typedef enum
{
   ERROR_NO_CHANGE                  = -145,  // The image has not changed
   ERROR_IMAGE_SIZE                 = -910,  // Image size not sufficient
   ERROR_NO_MESSAGE                 = -911,  // There is no message
   ERROR_INV_PASSWORD               = -912,  // Invalid password
   ERROR_NOT_ENOUGH_IMAGES          = -92,   // There are not enough images to complete the task
   ERROR_IMAGE_READ_ONLY            = -1901, // (Internal) Image processing is not allowed on this image because it is part of a RasterImage allocated with NoFreeDataOnDispose
} L_ERROR_IMG;

//=================================================================
// Ltimgopt
//=================================================================
typedef enum
{
   ERROR_OPT_ABORT                     = -1100, // Abort the optimization operation
   ERROR_OPT_SKIPIMAGE                 = -1101, // Skip optimizing current image
   ERROR_OPT_INVALID_INPUT_PATH        = -1102, // Invalid input path
   ERROR_OPT_INVALID_OUTPUT_PATH       = -1103, // Invalid output path
   ERROR_OPT_CANNOT_CREATE_OUTPUTPATH  = -1104, // Cannot Create Output Directory
} L_ERROR_IMGOPT;

//=================================================================
// Ltnet
//=================================================================
typedef enum
{
   ERROR_HOST_RESOLVE      = -270,  // Can't resolve hostname
   ERROR_CANT_INITIALIZE   = -271,  // Can't initialize network
   ERROR_NO_CONNECTION     = -272,  // No open network connections
   ERROR_HOST_NOT_FOUND    = -273,  // Hostname not found
   ERROR_NOT_SERVER        = -274,  // Computer is not a server
   ERROR_NO_CONNECTIONS    = -275,  // No connection requests waiting
   ERROR_CONNECT_REFUSED   = -276,  // Connection was refused
   ERROR_IS_CONNECTED      = -277,  // Computer is already connected
   ERROR_NET_UNREACH       = -278,  // Network is unreachable from host
   ERROR_TIME_OUT          = -279,  // Connect attempt time out without connecting
   ERROR_NET_DOWN          = -280,  // Network subsystem is down
   ERROR_NO_BUFFERS        = -281,  // No buffer space is available, too many connections
   ERROR_NO_FILE_DESCR     = -282,  // No more file handle available
   ERROR_DATA_QUEUED       = -283,  // Data has been queued to send later
   ERROR_UNKNOWN           = -284,  // Unknown network error has occurred
   ERROR_CONNECT_RESET     = -285,  // Connection was reset - socket might be unusable
   ERROR_TRANSFER_ABORTED  = -286,  // Transfer was aborted
   ERROR_DSHOW_FAILURE     = -287,  // DirectShow isn't installed correctly
   ERROR_REGISTRY_READ     = -288,  // Error reading from the registry
} L_ERROR_NET;

//=================================================================
// Ltdlg
//=================================================================
typedef enum
{
   SUCCESS_DLG_OK             = 100,   // The OK button was pressed, and the dialog exited successfully
   SUCCESS_DLG_CANCEL         = 101,   // The Cancel button was pressed, and the dialog exited successfully
   SUCCESS_DLG_CLOSE          = 102,   // The Close button was pressed, and the dialog exited successfully
   SUCCESS_DLG_EXIT           = 103,   // The dialog exits successfully after selecting exit option from menu or by closing the window
   SUCCESS_DLG_EXPORTANDEXIT  = 104,   // The dialog exits successfully after selecting exit and export option, dialog parameters will have the resulting bitmap allocated
} L_ERROR_DLG_SUCCESS;

typedef enum
{
   ERROR_DLG_FAILED                 = -150,  // An error occurred during creation of the common dialog
   ERROR_DLG_ALREADYINITIATED       = -151,  // You have already initialized the dialogs
   ERROR_DLG_NOTINITIATED           = -152,  // You did not initialize the dialogs
   ERROR_DLG_COLORNOTINITIALIZED    = -153,  // You did not initialize the dialogs with DLG_INIT_COLOR
   ERROR_DLG_COLORDLL_UNABLETOLOAD  = -154,  // The dialogs could not load the LTCLR dll
   ERROR_DLG_RESDLL_UNABLETOLOAD    = -155,  // The dialogs could not load the LTDLGRES dll
   ERROR_LTCLR_DLL_NOTLOADED        = -900,  // The LTCLR DLL is not loaded
   ERROR_LTDLGRES_DLL_NOTLOADED     = -901,  // The LDLGRES DLL is not loaded
   ERROR_LTDLG_COLOR_NOTINITIALIZE  = -902,  // You must initialize LTDLG using L_DlgInit
} L_ERROR_DLG;

//=================================================================
// Ltann
//=================================================================
typedef enum
{
   ERROR_LTANN_NOT_LOADED        = -202,  // Annotation DLL not loaded
   ERROR_LTDIS_NOT_LOADED        = -200,  // LTDIS DLL not loaded
   ERROR_LTFIL_NOT_LOADED        = -201,  // LTFIL DLL not loaded
   ERROR_NO_VIDEO_MODULE         = -258,  // No video module present on machine
   ERROR_UNDO_STACK_EMPTY        = -316,  // Undo stack is empty - too many undos
   ERROR_NO_UNDO_STACK           = -406,  // There is no undo stack
   ERROR_UNDO_DISABLED           = -407,  // The undo is disabled
   ERROR_ANN_LOCKED              = -148,  // One or more annotation objects are still locked
   ERROR_ANN_OPTION_NOT_ENABLED  = -1498, // Annotation option is not enabled. Call L_AnnSetOptions to enable this option
} L_ERROR_ANN;

//=================================================================
// Lftif
//=================================================================
typedef enum
{
   ERROR_UNKNOWN_COMP                  = -15,   // Unknown compression format
   ERROR_COMPACT_ABORTED               = -917,  // The compact function finished without copying all the pages
   ERROR_BAD_TAG                       = -140,  // Bad TIFF tag
   ERROR_TAG_MISSING                   = -404,  // Tag not found
   ERROR_CANNOT_INCREASE_IFD_SIZE      = -1365, // Cannot add tags to a IFD selected using SAVEFILEOPTION.IFD
   ERROR_TIFF_COMMAND_NOT_ALLOWED      = -913,  // The specified TIFF command is not allowed
   ERROR_BAD_TIFF_TAG_VALUE            = -914,  // Bad TIFF Tag value
   ERROR_NOT_MULTIPAGE_TIFF_FILE       = -915,  // Not Multi-Page TIFF file
   ERROR_DELETE_TIFF_FILE_NOT_ALLOWED  = -916,  // Not allowed to delete the TIFF file
   ERROR_INVALID_IFD                   = -1592, // Invalid IFD
   ERROR_TAG_VALUE_TOO_BIG             = -1781, // The LONG/SLONG tag value exceeded the 32-bit range (this can occur in CompactTIFF when converting a BigTIFF file to the regular TIFF format)
} L_ERROR_TIF;

//=================================================================
// Lfcmp
//=================================================================
typedef enum
{
   ERROR_CU_BUSY                 = -31,   // Internal error - call LEAD
   ERROR_INVALID_TABLE_TYPE      = -32,   // Internal error - call LEAD
   ERROR_INVALID_BUFFER          = -34,   // Internal error - call LEAD
   ERROR_MISSING_TILE_DATA       = -35,   // Internal error - call LEAD
   ERROR_INVALID_QVALUE          = -36,   // Internal error - call LEAD
   ERROR_INVALIDDATA             = -37,   // Internal error - call LEAD
   ERROR_INVALID_COMPRESSED_TYPE = -38,   // Internal error - call LEAD
   ERROR_INVALID_COMPONENT_NUM   = -39,   // Internal error - call LEAD
   ERROR_INVALID_PIXEL_TYPE      = -40,   // Internal error - call LEAD
   ERROR_INVALID_PIXEL_SAMPLING  = -41,   // Internal error - call LEAD
   ERROR_INVALID_IMAGE_DIMS      = -44,   // Internal error - call LEAD
   ERROR_INVALID_TILE_DIMS       = -45,   // Internal error - call LEAD
   ERROR_INVALID_PIX_BUFF_DIMS   = -46,   // Internal error - call LEAD
   ERROR_SEGMENT_OVERFLOW        = -47,   // Internal error - call LEAD
   ERROR_INVALID_SUBSAMPLING     = -48,   // Internal error - call LEAD
   ERROR_INVALID_Q_VIS_TABLE     = -49,   // Internal error - call LEAD
   ERROR_INVALID_DC_CODE_TABLE   = -50,   // Internal error - call LEAD
   ERROR_INVALID_AC_CODE_TABLE   = -51,   // Internal error - call LEAD
   ERROR_INSUFFICIENT_DATA       = -52,   // Internal error - call LEAD
   ERROR_MISSING_FUNC_POINTER    = -53,   // Internal error - call LEAD
   ERROR_TOO_MANY_DC_CODE_TABLES = -54,   // Internal error - call LEAD
   ERROR_TOO_MANY_AC_CODE_TABLES = -55,   // Internal error - call LEAD
   ERROR_INVALID_SUBIMAGE        = -56,   // Internal error - call LEAD
   ERROR_INVALID_ABORTION        = -57,   // Internal error - call LEAD
   ERROR_CU_NO_SUPPORT           = -58,   // Internal error - call LEAD
   ERROR_CU_FAILURE              = -59,   // Internal error - call LEAD
   ERROR_COMPRESSED_DATA_FAILURE = -62,   // The compressed data is corrupted
} L_ERROR_CMP;

//=================================================================
// Ltdoc
//=================================================================
typedef enum
{
   ERROR_DOC_DLL_NOT_LOADED                  = -1200, // ScanSoft DLLs are not loaded
   ERROR_DOC_INV_PAGE_INDEX                  = -1201, // Specified index is not correct
   ERROR_DOC_INV_FILLMETHOD                  = -1202, // Invalid fill method
   ERROR_DOC_INV_RECOG_MODULE                = -1203, // Invalid recognition module
   ERROR_DOC_INV_CHAR_FILTER                 = -1204, // Invalid character filter
   ERROR_DOC_INV_ZONE_TYPE                   = -1205, // Invalid zone type
   ERROR_DOC_INV_LANGID                      = -1206, // Invalid language Id
   ERROR_DOC_INV_SPELL_LANGUAGE              = -1207, // Invalid spell language
   ERROR_DOC_INV_SECTION_ENUMERATION         = -1208, // Invalid enumeration section
   ERROR_DOC_INV_PAGE_COUNT                  = -1209, // Invalid page count
   ERROR_DOC_ILLEGAL_CODE                    = -1210, // Illegal internal code as a parameter
   ERROR_DOC_INV_PARAMETER                   = -1211, // Set parameter is not acceptable
   ERROR_DOC_END_LIST_CODE_PAGES             = -1212, // End of list of the available Code Pages
   ERROR_DOC_LOAD_CODE_PAGE_FILE             = -1213, // Error while loading the Code Page Definition file
   ERROR_DOC_INV_BUFFER_SIZE                 = -1214, // The length of the exported code exceeds the buffer size
   ERROR_DOC_INV_CHARACTER_CONVERSION        = -1215, // Character conversion is not available for the given character
   ERROR_DOC_INV_CHARACTER_LANGUAGE          = -1216, // Conflict: The selected Code Page does not support some characters in the selected languages. There is no exact code in the Code Page for them
   ERROR_DOC_INITIALIZE_CODE_PAGE            = -1217, // Character Set and Code Pages module initialization error
   ERROR_DOC_INITIALIZE_ENGINE               = -1218, // OCR engine initialization error, or there is no appropriate license
   ERROR_DOC_TERMINATE_ENGINE                = -1219, // OCR engine termination error
   ERROR_DOC_INITIALIZE_WARNING              = -1220, // Module initialization warning
   ERROR_DOC_PROCESS_USER_ABORT              = -1221, // Application has aborted the current process
   ERROR_DOC_FINISH_PROCESS                  = -1222, // Application has terminated the current recognition process without losing the recognized text
   ERROR_DOC_MODULE_MISSING                  = -1223, // Module is not present
   ERROR_DOC_MODULE_LOAD                     = -1224, // OS could not load a module
   ERROR_DOC_MODULE_MISSING_ENTRY            = -1225, // Missing entry in a module
   ERROR_DOC_MODULE_INVALID                  = -1226, // Invalid module
   ERROR_DOC_MODULE_INITIALIZE               = -1227, // Module initialization error
   ERROR_DOC_FEATURE_NOT_SUPPORTED           = -1228, // The requested function is not available, or there is no appropriate license
   ERROR_DOC_GENERAL                         = -1229, // General error in the engine
   ERROR_DOC_GPF                             = -1230, // General Protection Fault in the engine
   ERROR_DOC_NOT_SUPPORT_OS                  = -1231, // Not supported operational system
   ERROR_DOC_INV_SETTING_FILE                = -1232, // Syntax error in the specified engine Settings file
   ERROR_DOC_INV_SETTING                     = -1233, // Invalid setting
   ERROR_DOC_ENGINE_BUSY                     = -1234, // The engine is busy
   ERROR_DOC_RECOGNITION_TIME_OUT            = -1235, // Recognition process Time Out
   ERROR_DOC_INV_IMAGE_MODULE_SETTING        = -1236, // Internal error in image module
   ERROR_DOC_NO_MEMORY                       = -1237, // Not enough memory during image processing
   ERROR_DOC_INV_IMAGE_DIMENSIONS            = -1238, // Invalid rectangle dimensions
   ERROR_DOC_INV_IMAGE_RESOLUTION            = -1239, // Non-supported resolution
   ERROR_DOC_CANNOT_COMPRESS_IMAGE           = -1240, // Cannot process compressed image
   ERROR_DOC_BAD_BITMAP                      = -1241, // Invalid bitmap address
   ERROR_DOC_NOT_SUPPORT_BPP                 = -1242, // Unsupported BitsPerPixel value
   ERROR_DOC_INV_IMAGE_MODULE                = -1243, // Internal error in image module
   ERROR_DOC_INV_IMAGE_HANDLE                = -1244, // Invalid image handle
   ERROR_DOC_BUFFER_OVERFLOW                 = -1245, // Buffer overflow during processing the image
   ERROR_DOC_ACCESS_DENIED                   = -1246, // Image operation denied
   ERROR_DOC_NO_MORE_LINES                   = -1247, // No more lines in defined image area
   ERROR_DOC_BAD_IMAGE_SIZE                  = -1248, // Non-supported image size
   ERROR_DOC_BAD_ENGINE_MANAGER_MODULE       = -1249, // Engine manager module error
   ERROR_DOC_NO_RECOGNIZED_TEXT_AVAILABLE    = -1250, // No recognized text available, either because the zone is empty or the required recognition module has not been initialized properly
   ERROR_DOC_NO_SELECTED_RECOGNITION_MODULE  = -1251, // There is no selected recognition module
   ERROR_DOC_NO_ZONE                         = -1252, // There is no zone in the zone list
   ERROR_DOC_INV_ZONE_INDEX                  = -1253, // Invalid zone index
   ERROR_DOC_INV_ZONE_COORDINATES            = -1254, // Invalid zone coordinates
   ERROR_DOC_MOR_INITIALIZE_MODULE           = -1255, // MOR recognition module initialization error
   ERROR_DOC_MOR_BASE_FILE_NOT_FOUND         = -1256, // MOR recognition module's knowledge base file not found
   ERROR_DOC_MOR_BASE_FILE_CORRUPTED         = -1257, // MOR recognition module's knowledge base file corrupted
   ERROR_DOC_MOR_BASE_FILE_VERSION           = -1258, // Incorrect knowledge base file version
   ERROR_DOC_MOR_IMAGE_SIZE                  = -1259, // Size of image is too large
   ERROR_DOC_MOR_FILE_CORRUPTED              = -1260, // File is corrupted
   ERROR_DOC_MOR_BAD_RECOG_MODULE            = -1261, // Internal error in the MOR recognition module
   ERROR_DOC_MOR_GPF_MODULE                  = -1262, // General Protection Fault in the MOR recognition module
   ERROR_DOC_DOT_RECOGNITION                 = -1263, // Dot-matrix recognition error
   ERROR_DOC_OMR_CHECKMARK_RECOGNITION       = -1264, // Checkmark recognition error
   ERROR_DOC_HNR_BASE_FILE__CORRUPTED        = -1265, // HNR module's knowledge base file is corrupted
   ERROR_DOC_HNR_PARAM_OUT_RANGE             = -1266, // Parameter is out of valid range
   ERROR_DOC_RER_MODULE                      = -1267, // Internal error in the RER module
   ERROR_DOC_RER_BASE_FILE_NOT_FOUND         = -1268, // RER module's knowledge base file not found
   ERROR_DOC_RER_CHAR_SET_EMPTY              = -1269, // Character Set is empty for the RER module
   ERROR_DOC_RER_CHAR_SET_NOT_SUPPORTED      = -1270, // The specified Character Set not fully supported by the RER recognition module
   ERROR_DOC_RER_MODULE_NOT_FOUND            = -1271, // RER specific file not found
   ERROR_DOC_SPELL_NO_MEMORY                 = -1272, // Not enough memory for the SPL module
   ERROR_DOC_SPELL_UNINITIALIZED             = -1273, // Uninitialized spell object
   ERROR_DOC_SPELL_FILE_OPEN                 = -1274, // Spell file open error
   ERROR_DOC_SPELL_FILE_READ                 = -1275, // Spell file read error
   ERROR_DOC_SPELL_USER_DICTIONARY_WRITE     = -1276, // User dictionary write error
   ERROR_DOC_SPELL_INV_FILE_FORMAT           = -1277, // Invalid file format
   ERROR_DOC_SPELL_INITIALIZE_MODULE         = -1278, // Module initialization error
   ERROR_DOC_SPELL_USER_DICTIONARY_CLOSE     = -1279, // User dictionary close error
   ERROR_DOC_SPELL_ILLEGAL_LANGUAGE_SETTING  = -1280, // Illegal language setting
   ERROR_DOC_SPELL_NO_MORE_ITEMS             = -1281, // No more suggestions/items available
   ERROR_DOC_SPELL_CHECK_ERROR               = -1282, // Internal checking error
   ERROR_DOC_SPELL_ITEM_ALREADY_EXIST        = -1283, // Item already exists in the User dictionary
   ERROR_DOC_SPELL_ITEM_NOT_EXIST            = -1284, // Item does not exist in the User dictionary
   ERROR_DOC_SPELL_ITEM_NOT_INSERTED         = -1285, // Item was not inserted into the User dictionary
   ERROR_DOC_SPELL_SECTION_NOT_EXIST         = -1286, // Section does not exist in the User dictionary
   ERROR_DOC_SPELL_BAD_SYNTEX                = -1287, // Regular expression syntax error
   ERROR_DOC_OUTPUT_NOT_INITIALIZED          = -1288, // Output format conversion subsystem was not initialized
   ERROR_DOC_OUTPUT_CONVERT_NOT_EXIST        = -1289, // No more converters available
   ERROR_DOC_OUTPUT_CONVERT_DLL_NOT_EXIST    = -1290, // There is no converter DLL file
   ERROR_DOC_OUTPUT_BAD_PARAMETER            = -1291, // Wrong parameter or parameter not found
   ERROR_DOC_OUTPUT_FILE_CORRUPTED           = -1292, // TMP file is corrupted
   ERROR_DOC_OUTPUT_FILE_NOT_FOUND           = -1293, // TMP file not found
   ERROR_DOC_OUTPUT_CREATE_FILE              = -1294, // Cannot create TMP file
   ERROR_DOC_OUTPUT_SEEK_FILE                = -1295, // Cannot seek in TMP file
   ERROR_DOC_OUTPUT_READ_FILE                = -1296, // TMP file read error
   ERROR_DOC_OUTPUT_WRITE_FILE               = -1297, // TMP file write error
   ERROR_DOC_OUTPUT_CLOSE_FILE               = -1298, // Cannot close TMP file
   ERROR_DOC_OUTPUT_LOAD_DLL                 = -1299, // Cannot load the DLL file
   ERROR_DOC_OUTPUT_END_OF_FILE              = -1300, // Internal error in ATMTXT module. (End-Of-File detected)
   ERROR_DOC_OUTPUT_NO_MEMORY                = -1301, // Not enough memory for ATMTXT/TMP module
   ERROR_DOC_OUTPUT_IMAGE_NOT_AVAILABLE      = -1302, // Image is not available for inserting into the output
   ERROR_DOC_OUTPUT_NOT_REGISTER_INFO_ITEM   = -1303, // Not enough memory to register an info item
   ERROR_DOC_TXT_FILE_OPEN                   = -1304, // Output file open error
   ERROR_DOC_TXT_FILE_READ                   = -1305, // Output file read error
   ERROR_DOC_TXT_FILE_NOT_FOUND              = -1306, // Output file not found
   ERROR_DOC_TXT_FILE_WRITE                  = -1307, // Output file write error
   ERROR_DOC_TXT_INV_COMMAND_SEQUENCE        = -1308, // Invalid command sequence in the ICF file
   ERROR_DOC_TXT_CREATE_FILE                 = -1309, // Cannot create the output file
   ERROR_DOC_TXT_NO_MEMORY                   = -1310, // Not enough memory for ATMTXT/TXT module
   ERROR_DOC_TXT_INV_DOCUMENT                = -1311, // Invalid document type
   ERROR_DOC_TXT_FILE_TOO_LARGE              = -1312, // File too large
   ERROR_DOC_TXT_WARNING_OUTPUT_FILE         = -1313, // There was a WARNING during the output file conversion
   ERROR_DOC_TXT_OPERATION_CANCELLED         = -1314, // Operation canceled
   ERROR_DOC_TXT_ILLEGAL_OPTION              = -1315, // Illegal option specified
   ERROR_DOC_TXT_ENCRYPTED_SOURCE            = -1316, // Encrypted source
   ERROR_DOC_TXT_SEEK_ERROR                  = -1317, // Output file seek error
   ERROR_DOC_BRAILLE_BAD_INITIALIZATION      = -1318, // Braille recognition module initialization error
   ERROR_DOC_MATRIX_BAD_INITIALIZATION       = -1319, // Matrix matching recognition module initialization error
   ERROR_DOC_MTX_BAD_INITIALIZATION          = -1320, // M/TEXT recognition module initialization error
   ERROR_DOC_NON_IMPLEMENTED_FEATURE         = -1321, // Non-implemented feature
   ERROR_DOC_NOT_FOUND_ZONE                  = -1322, // Couldn't find specific zone
   ERROR_DOC_NO_SELECTED_ZONE                = -1323, // No available selected zone
   ERROR_DOC_EXPORT_PAGE                     = -1324, // Cannot export the specified page
   ERROR_DOC_LOCK_PAGE                       = -1325, // Cannot lock the specified page
   ERROR_DOC_ACTIVE_PAGE                     = -1326, // Cannot set the specified page to be activated
   ERROR_DOC_LOCKED                          = -1327, // The OCR document engine is locked
   ERROR_DOC_OUTPUT_PDF_LOCKED               = -1328, // Output PDF engine is locked
   ERROR_DOC_OMR_LOCKED                      = -1329, // OMR Options are locked
   ERROR_DOC_ICR_LOCKED                      = -1330, // ICR Options are locked

   // Error codes added for Arabic OCR Engine...
   ERROR_DOC_ARABIC_LOCKED                   = -1331, // The Arabic OCR document engine is locked
   ERROR_DOC_TOO_MANY_REGION                 = -1332, // Too many regions result when layout analysis
   ERROR_DOC_NO_HORIZONTAL_BOUNDARY          = -1333, // Top or bottom horizontal line not found
   ERROR_DOC_SLOPE_LINE_TOO_LARGE            = -1334, // The slope of the line is too large
   ERROR_DOC_FRAME_NOT_DETECTED              = -1335, // Frame has not been detected, cannot add virtual line
   ERROR_DOC_TOO_MANY_LINES                  = -1336, // Too many lines
   ERROR_DOC_TOO_MANY_PAGES                  = -1337, // Too many pages in batch processing list
   ERROR_DOC_NO_TABLE                        = -1338, // This region is not a table region
   ERROR_DOC_INVALID_TABLE_DATA              = -1339, // This region is a table region but contains no data
   ERROR_DOC_INVALID_FRAME_LINE              = -1340, // This line is not valid (neither horizontal nor vertical or type match)
   ERROR_DOC_TOO_LARGE_ANGLE                 = -1341, // Angle is too large, cannot rotate image
   ERROR_DOC_ORIENT                          = -1342, // Unable to determine orientation

   ERROR_DOC_INV_RDF_FILENAME                = -1343, // Invalid RDF file name
   ERROR_DOC_LTPDF_DLL_NOT_LOADED            = -1344, // LEAD PDF DLLs are not loaded
   ERROR_DOC_OCR_PDF_LEAD_OUTPUT_LOCKED      = -1345, // OCR PDF LEAD Output is locked

   ERROR_DOC_ICR_MISSING                     = -1346, // ICR Module is missing
   ERROR_DOC_OMR_MISSING                     = -1347, // OMR Module is missing
   ERROR_DOC_LANGUAGE_MISSING                = -1348, // Languages files are missing

   ERROR_DOC2_INITIALIZE_ENGINE              = -1349, // OCR Module - OmniPage Engine initialization error, or there is no appropriate license
   ERROR_DOC2_ICR_MISSING                    = -1350, // ICR Module is missing for OCR Module - OmniPage Engine
   ERROR_DOC2_OMR_MISSING                    = -1351, // OMR Module is missing for OCR Module - OmniPage Engine
   ERROR_DOC2_LANGUAGE_MISSING               = -1352, // Languages files are missing for OCR Module - OmniPage Engine
   ERROR_DOC2_DOTNET30_OR_LATER_MISSING      = -1354, // .NET Framework v3.0 or later is required
   ERROR_DOC2_ASIAN_LOCKED                   = -1542, // Asian module is locked

} L_ERROR_SUPPORT_DOC;

//=================================================================
// Lttwn
//=================================================================
typedef enum
{
   ERROR_TWAIN_BUMMER                     = -80,  // TWAIN Failure due to unknown causes
   ERROR_TWAIN_LOWMEMORY                  = -81,  // TWAIN Not enough memory to perform operation
   ERROR_TWAIN_NODS                       = -82,  // TWAIN No Data Source
   ERROR_TWAIN_MAXCONNECTIONS             = -83,  // TWAIN DS is connected to max possible apps
   ERROR_TWAIN_OPERATIONERROR             = -84,  // TWAIN DS or DSM reported error, app shouldn't (no need for your app to report the error)
   ERROR_TWAIN_BADPROTOCOL                = -86,  // TWAIN Unrecognized MSG DG DAT combination
   ERROR_TWAIN_CANCEL                     = -90,  // TWAIN Operation was canceled

   ERROR_TWAIN_NO_LIBRARY                  = -560,  // No TWAIN Library
   ERROR_TWAIN_INVALID_DLL                 = -561,  // Invalid DLL
   ERROR_TWAIN_NOT_INITIALIZED             = -562,  // TWAIN is not initialized

   ERROR_TWAIN_CHECK_STATUS                = -564,  // Check status
   ERROR_TWAIN_END_OF_LIST                 = -565,  // End of list
   ERROR_TWAIN_CAP_NOT_SUPPORTED           = -566,  // Cap is not supported
   ERROR_TWAIN_SOURCE_NOT_OPEN             = -567,  // Source is not open
   ERROR_TWAIN_BAD_VALUE                   = -568,  // Bad value
   ERROR_TWAIN_INVALID_STATE               = -569,  // Invalid state
   ERROR_TWAIN_CAPS_NEG_NOT_ENDED          = -570,  // Caps neg not ended
   ERROR_TWAIN_OPEN_FILE                   = -571,  // Open file
   ERROR_TWAIN_INV_HANDLE                  = -572,  // Invalid handle
   ERROR_TWAIN_WRITE_TO_FILE               = -573,  // Write to file
   ERROR_TWAIN_INV_VERSION_NUM             = -574,  // Invalid version number
   ERROR_TWAIN_READ_FROM_FILE              = -575,  // Read from file
   ERROR_TWAIN_NOT_VALID_FILE              = -576,  // File is not valid
   ERROR_TWAIN_INV_ACCESS_RIGHT            = -577,  // Invalid access right
   ERROR_TWAIN_CUSTOMBASE                  = -578,  // Custom base
   ERROR_TWAIN_DENIED                      = -579,  // Denied
   ERROR_TWAIN_FILEEXISTS                  = -580,  // File exists
   ERROR_TWAIN_FILENOTFOUND                = -581,  // File not found
   ERROR_TWAIN_NOTEMPTY                    = -582,  // Not empty
   ERROR_TWAIN_PAPERJAM                    = -583,  // Paper jam
   ERROR_TWAIN_PAPERDOUBLEFEED             = -584,  // Paper double feed
   ERROR_TWAIN_FILEWRITEERROR              = -585,  // File write error
   ERROR_TWAIN_CHECKDEVICEONLINE           = -586,  // Check device is on line

   ERROR_TWAIN_STOP_ENUMERATION            = SUCCESS_ABORT,  // Stop enumeration
   ERROR_TWAIN_STOP_SCAN                   = -587,  // Stop scan
   ERROR_TWAIN_CAPBADOPERATION             = -588,  // Operation not supported by capability
   ERROR_TWAIN_CAPSEQERROR                 = -589   // Capability has dependency on other capability
} L_ERROR_TWAIN;

//=================================================================
// Ltbar
//=================================================================
typedef enum
{
   ERROR_BARCODE_DIGIT_CHECK              = -410,  // Invalid error check digit
   ERROR_BARCODE_INVALID_TYPE             = -411,  // Invalid barcode type
   ERROR_BARCODE_TEXTOUT                  = -412,  // Invalid barcode text out option
   ERROR_BARCODE_WIDTH                    = -413,  // Invalid barcode width
   ERROR_BARCODE_HEIGHT                   = -414,  // Invalid barcode height
   ERROR_BARCODE_TOSMALL                  = -415,  // Barcode string is too small
   ERROR_BARCODE_STRING                   = -416,  // Invalid barcode string for a specified barcode type
   ERROR_BARCODE_NOTFOUND                 = -417,  // No barcode recognition
   ERROR_BARCODE_UNITS                    = -418,  // Invalid barcode measurement unit
   ERROR_BARCODE_MULTIPLEMAXCOUNT         = -419,  // Invalid multiple max count
   ERROR_BARCODE_GROUP                    = -420,  // Invalid barcode group
   ERROR_BARCODE_NO_DATA                  = -421,  // Invalid BARCODEDATA structure
   ERROR_BARCODE_NOTFOUND_DUPLICATED      = -422,  // No duplicated barcode
   ERROR_BARCODE_LAST_DUPLICATED          = -423,  // Reached the last duplicated barcode
   ERROR_BARCODE_STRING_LENGTH            = -424,  // Invalid barcode data string length
   ERROR_BARCODE_LOCATION                 = -425,  // Invalid barcode area location
   ERROR_BARCODE_1D_LOCKED                = -426,  // Barcode 1D is locked
   ERROR_BARCODE_2D_READ_LOCKED           = -427,  // Barcode Read 2D (CodeOne) is locked
   ERROR_BARCODE_2D_WRITE_LOCKED          = -428,  // Barcode Write 2D (CodeOne) is locked
   ERROR_BARCODE_PDF_READ_LOCKED          = -429,  // Barcode Read PDF is locked
   ERROR_BARCODE_PDF_WRITE_LOCKED         = -430,  // Barcode Write PDF is locked
   ERROR_BARCODE_FOUNDCORRUPT             = -431,  // Barcode PDF417 symbol is found but cannot read successfully
   ERROR_BARCODE_DATAMATRIX_READ_LOCKED   = -432,  // Barcode Read DataMatrix is locked
   ERROR_BARCODE_DATAMATRIX_WRITE_LOCKED  = -433,  // Barcode Write DataMatrix is locked
   ERROR_BARCODE_QR_READ_LOCKED           = -1380, // Barcode Read QR is locked
   ERROR_BARCODE_QR_WRITE_LOCKED          = -1381, // Barcode Write QR is locked
   ERROR_BARCODE_AZTEC_READ_LOCKED        = -1370, // Barcode Read AZTEC is locked
   ERROR_BARCODE_AZTEC_WRITE_LOCKED       = -1371, // Barcode Write AZTEC is locked
   ERROR_BARCODE_MAXI_READ_LOCKED         = -1372, // Barcode Read MAXI is locked
   ERROR_BARCODE_MAXI_WRITE_LOCKED        = -1373, // Barcode Write MAXI is locked
   ERROR_BARCODE_MICROQR_READ_LOCKED      = -1374, // Barcode Read MICROQR is locked
   ERROR_BARCODE_MICROQR_WRITE_LOCKED     = -1375, // Barcode Write MICROQR is locked
   ERROR_BARCODE_DLL_NOT_FOUND            = -1382, // Barcode Engine DLL not found
   ERROR_BARCODE_XMODULE                  = -1481, // Incorrect module value it should be >= 0
} L_ERROR_BARCODE;

//=================================================================
// Ltvkrn
//=================================================================
typedef enum
{
   ERROR_VECTOR_NOT_ENABLED            = -400,  // Vector capability is required to use this function
   ERROR_VECTOR_DXF_NOT_ENABLED        = -401,  // Vector DXF capability is required to use this function
   ERROR_VECTOR_DWG_NOT_ENABLED        = -402,  // Vector DWG capability is required to use this function
   ERROR_VECTOR_MISC_NOT_ENABLED       = -403,  // Vector Misc capability is required to use this function
   ERROR_VECTOR_DWF_NOT_ENABLED        = -405,  // Vector DWF capability is required to use this function
   ERROR_VECTOR_IS_LOCKED              = -500,  // Vector handle is locked
   ERROR_VECTOR_IS_EMPTY               = -501,  // Vector is empty
   ERROR_VECTOR_LAYER_NOT_FOUND        = -502,  // Layer is not found
   ERROR_VECTOR_LAYER_IS_LOCKED        = -503,  // Layer is locked
   ERROR_VECTOR_LAYER_ALREADY_EXISTS   = -504,  // Layer already exists
   ERROR_VECTOR_OBJECT_NOT_FOUND       = -505,  // Object is not found
   ERROR_VECTOR_INVALID_OBJECT_TYPE    = -506,  // Invalid object type
   ERROR_VECTOR_PEN_NOT_FOUND          = -507,  // Pen is not found
   ERROR_VECTOR_BRUSH_NOT_FOUND        = -508,  // Brush is not found
   ERROR_VECTOR_FONT_NOT_FOUND         = -509,  // Font is not found
   ERROR_VECTOR_BITMAP_NOT_FOUND       = -510,  // Bitmap is not found
   ERROR_VECTOR_POINT_NOT_FOUND        = -511,  // Point is not found
   ERROR_VECTOR_ENGINE_NOT_FOUND       = -512,  // Vector engine not found
   ERROR_VECTOR_INVALID_ENGINE         = -513,  // Invalid vector engine
   ERROR_VECTOR_CLIPBOARD              = -514,  // Clipboard error
   ERROR_VECTOR_CLIPBOARD_IS_EMPTY     = -515,  // Clipboard is empty
   ERROR_VECTOR_CANT_ADD_TEXT          = -516,  // Cannot add text
   ERROR_VECTOR_CANT_READ_WMF          = -517,  // Cannot read WMF
   ERROR_VECTOR_GROUP_NOT_FOUND        = -518,  // Group is not found
   ERROR_VECTOR_GROUP_ALREADY_EXISTS   = -519,  // Group already exists
} L_ERROR_VECTOR;

//=================================================================
// Ltaut
//=================================================================
typedef enum
{
   ERROR_AUTOMATION_INV_HANDLE   = -690,  // Invalid handle
   ERROR_AUTOMATION_INV_STATE    = -691,  // Invalid state
} L_ERROR_AUTOMATION;

//=================================================================
// Lttlb
//=================================================================
typedef enum
{
   ERROR_TOOLBAR_NO_RESOURCES = -660,  // No resources available
   ERROR_TOOLBAR_INV_STATE    = -661,  // Invalid state
   ERROR_TOOLBAR_INV_HANDLE   = -662,  // Invalid handle
} L_ERROR_TOOLBAR;

//=================================================================
// Ltpnt
//=================================================================
typedef enum
{
   ERROR_PAINT_INTERNAL       = -600,  // Internal error (Call LEAD)
   ERROR_PAINT_INV_DATA       = -601,  // Internal error (Call LEAD)
   ERROR_PAINT_NO_RESOURCES   = -602,  // Internal error (Call LEAD)
   ERROR_PAINT_NOT_ENABLED    = -603,  // DigitalPaint capability is required to use this function
} L_ERROR_PAINT;

//=================================================================
// Ltcon
//=================================================================
typedef enum
{
   ERROR_CONTAINER_INV_HANDLE    = -630,  // Invalid state
   ERROR_CONTAINER_INV_OPERATION = -631,  // Invalid operation
   ERROR_CONTAINER_NO_RESOURCES  = -632,  // No resources available
} L_ERROR_CONTAINER;

//=================================================================
// Ltscr
//=================================================================
typedef enum
{
   ERROR_CAPTURE_CANNOT_CREATE_HOTKEY_WINDOW       = -313,  // Error creating the hotkey window
   ERROR_CAPTURE_STILL_IN_PROCESS                  = -320,  // Capture is still in progress
   ERROR_CAPTURE_INVALID_DELAY                     = -321,  // Invalid delay specified
   ERROR_CAPTURE_INVALID_COUNT                     = -322,  // Invalid capture count specified
   ERROR_CAPTURE_INVALID_INTERVAL                  = -323,  // Invalid interval specified
   ERROR_CAPTURE_HOTKEY_CONFLICTS_WITH_CANCELKEY   = -324,  // 
   ERROR_CAPTURE_INVALID_AREA_TYPE                 = -325,  // Invalid Area Type specified
   ERROR_CAPTURE_NO_OPTION_STRUCTURE               = -326,  // Invalid or missing options structure
   ERROR_CAPTURE_INVALID_FILL_PATTERN              = -327,  // Invalid fill pattern
   ERROR_CAPTURE_INVALID_LINE_STYLE                = -328,  // Invalid line style
   ERROR_CAPTURE_INVALID_INFOWND_POS               = -329,  // Invalid info window position
   ERROR_CAPTURE_INVALID_INFOWND_SIZE              = -330,  // Invalid info window size
   ERROR_CAPTURE_ZERO_AREA_SIZE                    = -331,  // Zero Area Size for capture
   ERROR_CAPTURE_FILE_ACCESS_FAILED                = -332,  // The specified filename could not be read
   ERROR_CAPTURE_INVALID_32BIT_EXE_OR_DLL          = -333,  // The specified filename is not a valid 32bit EXE/DLL
   ERROR_CAPTURE_INVALID_RESOURCE_INDEX            = -335,  // The index resource is out of range
   ERROR_CAPTURE_NO_ACTIVE_WINDOW                  = -336,  // No active window for capture
   ERROR_CAPTURE_CANNOT_CAPTURE_WINDOW             = -337,  // Could not capture the window
   ERROR_CAPTURE_STRING_ID_NOT_DEFINED             = -338,  // String ID not defined
   ERROR_CAPTURE_DELAY_LESS_THAN_ZERO              = -339,  // Delay value cannot be less than zero
   ERROR_CAPTURE_NO_MENU                           = -340,  // No menu to capture
} L_ERROR_SCR;

//=================================================================
// Ltsvg
//=================================================================
typedef enum
{
   ERROR_SVG_FILE_SIZE_READ                = -770,  // SVG File size read error
   ERROR_SVG_ROOT_NOT_FOUND                = -771,  // Root element of XML data is not found or not SVG
   //ERROR_SVG_ROOT_NOT_SVG                  = -771,  // Deprecated, use ERROR_SVG_ROOT_NOT_FOUND
   ERROR_SVG_NOFOUND_ROOT_ELEMENT          = -772,  // Deprecated, use ERROR_SVG_ROOT_NOT_FOUND
   ERROR_SVG_INV_ELEMENT                   = -773,  // Invalid SVG element in the XML data
   ERROR_SVG_DUPLICATED_ATTRIBUTE          = -774,  // Duplicated SVG attribute in the XML data
   ERROR_SVG_INV_ATTRIBUTE                 = -775,  // Invalid SVG attribute in the XML data
   ERROR_SVG_INV_ATTRIBUTE_VALUE           = -776,  // Invalid SVG attribute value in the XML data
   ERROR_SVG_BAD_CSS_PROPERTY              = -777,  // Bad SVG CSS property in the XML data
   ERROR_SVG_MISSING_REQUIRED_ATTRIBUTE    = -778,  // Missing required SVG attribute in the XML data
   ERROR_SVG_DUPLICATED_ID                 = -779,  // Duplicated SVG element ID in the XML data
   ERROR_SVG_INV_COORDINATES_NUMBER        = -780,  // Invalid SVG coordinates number in the XML data
   ERROR_SVG_INV_STRING_COMMA              = -781,  // Invalid SVG string comma
   ERROR_SVG_ATTRIBUTE_NOT_FOUND           = -782,  // SVG Attribute not found in the XML data
   ERROR_SVG_FILE_NOT_FLAT                 = -783,  // This functionality requires a flat SVG document
} L_ERROR_SVG;

//=================================================================
// Lffpx
//=================================================================
typedef enum
{
   ERROR_FPX_INVALID_FORMAT_ERROR       = -101,  // Invalid FlashPix format
   ERROR_FPX_FILE_WRITE_ERROR           = -102,  // Error writing file
   ERROR_FPX_FILE_READ_ERROR            = -103,  // Error reading file
   ERROR_FPX_FILE_NOT_FOUND             = -104,  // File not found
   ERROR_FPX_COLOR_CONVERSION_ERROR     = -105,  // Color conversion error
   ERROR_FPX_SEVER_INIT_ERROR           = -106,  // Server initialize error
   ERROR_FPX_LOW_MEMORY_ERROR           = -107,  // Not enough memory available
   ERROR_FPX_IMAGE_TOO_BIG_ERROR        = -108,  // Image too big
   ERROR_FPX_INVALID_COMPRESSION_ERROR  = -109,  // Invalid compression
   ERROR_FPX_INVALID_RESOLUTION         = -110,  // Invalid resolution
   ERROR_FPX_INVALID_FPX_HANDLE         = -111,  // Invalid handle
   ERROR_FPX_TOO_MANY_LINES             = -112,  // Too many lines
   ERROR_FPX_BAD_COORDINATES            = -113,  // Invalid coordinates
   ERROR_FPX_FILE_SYSTEM_FULL           = -114,  // File system full
   ERROR_FPX_MISSING_TABLE              = -115,  // The table is missing
   ERROR_FPX_RETURN_PARAMETER_TOO_LARGE = -116,  // Parameter too large
   ERROR_FPX_NOT_A_VIEW                 = -117,  // Error view
   ERROR_FPX_VIEW_IS_TRANFORMLESS       = -118,  // The view is transformless
   ERROR_FPX_ERROR                      = -119,  // General error
   ERROR_FPX_UNIMPLEMENTED_FUNCTION     = -120,  // Unimplemented function
   ERROR_FPX_INVALID_IMAGE_DESC         = -121,  // Invalid image description
   ERROR_FPX_INVALID_JPEG_TABLE         = -122,  // Invalid jpeg table
   ERROR_FPX_ILLEGAL_JPEG_ID            = -123,  // Illegal jpeg identifier
   ERROR_FPX_MEMORY_ALLOCATION_FAILED   = -124,  // Memory allocation failed
   ERROR_FPX_NO_MEMORY_MANAGEMENT       = -125,  // No memory management
   ERROR_FPX_OBJECT_CREATION_FAILED     = -126,  // Object creation failed
   ERROR_FPX_EXTENSION_FAILED           = -127,  // Extension_failed
   ERROR_FPX_FREE_NULL_PTR              = -128,  // Free null pointer
   ERROR_FPX_INVALID_TILE               = -129,  // Invalid tile
   ERROR_FPX_FILE_IN_USE                = -130,  // File in use
   ERROR_FPX_FILE_CREATE_ERROR          = -131,  // Error creating file
   ERROR_FPX_FILE_NOT_OPEN_ERROR        = -132,  // File not open
   ERROR_FPX_USER_ABORT                 = -133,  // User abort
   ERROR_FPX_OLE_FILE_ERROR             = -134,  // OLE File I/O error
   ERROR_FPXEXTENSIONS_LOCKED           = -147   // The FlashPix extension capabilities are locked
} L_ERROR_FPX;

//=================================================================
// Ltwia
//=================================================================
typedef enum
{
   ERROR_WIA_GENERAL_ERROR                   = -1450, // An unknown error has occurred with the Microsoft Windows Image Acquisition (WIA) device
   ERROR_WIA_PAPER_JAM                       = -1451, // Paper is jammed in the scanner's document feeder
   ERROR_WIA_PAPER_EMPTY                     = -1452, // The user requested a scan and there are no documents left in the document feeder
   ERROR_WIA_PAPER_PROBLEM                   = -1453, // An unspecified problem occurred with the scanner's document feeder
   ERROR_WIA_OFFLINE                         = -1454, // The WIA device is not online
   ERROR_WIA_BUSY                            = -1455, // The WIA device is busy
   ERROR_WIA_WARMING_UP                      = -1456, // The WIA device is warming up
   ERROR_WIA_USER_INTERVENTION               = -1457, // An unspecified error has occurred with the WIA device that requires user intervention. The user should ensure that the device is turned on, online, and any cables are properly connected
   ERROR_WIA_ITEM_DELETED                    = -1458, // The WIA device was deleted. It can no longer be accessed
   ERROR_WIA_DEVICE_COMMUNICATION            = -1459, // An unspecified error occurred during an attempted communication with the WIA device
   ERROR_WIA_INVALID_COMMAND                 = -1460, // The device does not support this command
   ERROR_WIA_INCORRECT_HARDWARE_SETTING      = -1461, // There is an incorrect setting on the WIA device
   ERROR_WIA_DEVICE_LOCKED                   = -1462, // The scanner head is locked
   ERROR_WIA_EXCEPTION_IN_DRIVER             = -1463, // The device driver threw an exception
   ERROR_WIA_INVALID_DRIVER_RESPONSE         = -1464, // The response from the driver is invalid
   ERROR_WIA_COVER_OPEN                      = -1465, // No Description available
   ERROR_WIA_LAMP_OFF                        = -1466, // No Description available
   ERROR_WIA_DESTINATION                     = -1467, // No Description available
   ERROR_WIA_NETWORK_RESERVATION_FAILED      = -1468, // No Description available
   ERROR_WIA_NO_DEVICE_AVAILABLE             = -1469, // There are no WIA hardware devices that match the given specifications
   ERROR_WIA_NO_DEVICE_SELECTED              = -1470, // There is no device currently selected
   ERROR_WIA_INVALID_STREAMING_VIDEO_DEVICE  = -1471, // Selected device does not support streaming video
   ERROR_WIA_VIDEO_STREAM_NOT_INITIALIZED    = -1472, // WIA video stream No initialized
   ERROR_WIA_ACCESS_DENIED                   = -1473, // Access denied
   ERROR_WIA_NO_ITEMS_AVAILABLE              = -1474, // No child items available
   ERROR_WIA_UNKNOWN                         = -1475, // Unknown WIA error occurred
   ERROR_WIA_INVALID_VERSION                 = -1476, // Invalid WIA version
} L_ERROR_WIA;

//=================================================================
// ActiveX
//=================================================================
typedef enum
{
   ERROR_NO_TOOLBAR                          = -317,  // The toolbar window was not created
   ERROR_INV_VARIANT_TYPE                    = -1487, // Invalid Variant type
   ERROR_INV_STRING                          = -1488, // Invalid string value
   ERROR_INV_DISPATCH                        = -1489, // Invalid dispatch
} L_ERROR_ACTIVEX;

//=================================================================
// LEADTOOLS Printer Driver 
//=================================================================
typedef enum
{
   ERROR_PRNDRV_LOCKED                    = -1600, // LEADTOOLS Printer is locked
   ERROR_PRNDRV_MORE_DATA                 = -1601, // Not enough memory to retrieve the required data
   ERROR_PRNDRV_NO_OPTIONS                = -1602, // No previously options set
   ERROR_PRNDRV_NOT_LEADTOOLS_PRINTER     = -1603, // Not a LEADTOOLS Printer
   ERROR_PRNDRV_PRINTER_DATA              = -1604, // Invalid printer data
   ERROR_PRNDRV_SET_PRINTER_DATA          = -1605, // Cannot set printer data
   ERROR_PRNDRV_CREATE_REG_KEY            = -1606, // Cannot create registry key
   ERROR_PRNDRV_SET_REG_VALUE             = -1607, // Cannot set registry key value
   ERROR_PRNDRV_ADD_PRINTER               = -1608, // Cannot add printer
   ERROR_PRNDRV_PRINTER_NOTFOUND          = -1609, // Printer not found
   ERROR_PRNDRV_ROOTDIR_NOTFOUND          = -1610, // Root directory not found
   ERROR_PRNDRV_CONNECTION_EXE_NOTFOUND   = -1611, // Connection file not found
   ERROR_PRNDRV_SPOOL_FOLDER_NOTFOUND     = -1612, // Spool folder not found
   ERROR_PRNDRV_INVALID_PRINTER_TYPE      = -1613, // Invalid printer type
   ERROR_PRNDRV_INVALID_PRINTER           = -1614, // Invalid printer
   ERROR_PRNDRV_DOC_ALREADY_STARTED       = -1615, // Document already started
   ERROR_PRNDRV_CREATE_TEMP_FILE          = -1616, // Can not create temporary file
   ERROR_PRNDRV_LOAD_DLL                  = -1617, // Error loading DLL
   ERROR_PRNDRV_LOADFONT_DATA             = -1618, // Fixed palette data not found
   ERROR_PRNDRV_CANNOT_LOCK               = -1619, // Printer created without password
   ERROR_PRNDRV_ADMINSTRATOR_RIGHTS       = -1620, // User has no right to delete the printer
   ERROR_PRNDRV_PRINTER_LOCKED            = -1621, // Printer locked
   ERROR_PRNDRV_NETWORK_PRINTING_DISABLED = -1622, // Network printing disabled
   ERROR_PRNDRV_INSTALL_INVALID_PRINTER   = -1623, // Printer client installation printer does not exist
   ERROR_PRNDRV_INSTALL_CANCELLED         = -1624, // Printer installation cancelled by user
   ERROR_PRNDRV_INSTALL_KM_DRIVER_BLOCKED = -1625, // The printer driver is not compatible with a policy enabled on your computer
   ERROR_PRNDRV_INSTALL_REGISTRY_ACCESS   = -1626, // Installation cannot access registry
   ERROR_PRNDRV_INSTALL_FAILURE           = -1627  // Printer installation failed
} L_ERROR_PRINTERDRIVER;

//=================================================================
// LEADTOOLS PreProcessing
//=================================================================
typedef enum
{
   ERROR_PREPROC_BADSTATE                       = -1503,  // Preprocessing engine is in a bad state. Call LEAD
   ERROR_PREPROC_INIT                           = -1504,  // Preprocessing engine initialization error or no appropriate license. Call LEAD
   ERROR_PREPROC_CANTSCALEEDGESTEPS             = -1505,  // Preprocessing engine attempted to scale an edge steps format word. Call LEAD
   ERROR_PREPROC_WRONGWORD                      = -1506,  // Preprocessing engine word does not have blobs of that type. Call LEAD
   ERROR_PREPROC_CANTFINDPOINTBAND              = -1507,  // Preprocessing engine cannot find point band. Call LEAD
   ERROR_PREPROC_UNMATCHEDBLOCKRIGHT            = -1508,  // Preprocessing engine unmatched block right. Call LEAD
   ERROR_PREPROC_UNMATCHEDBLOCKLEFT             = -1509,  // Preprocessing engine unmatched block left. Call LEAD
   ERROR_PREPROC_UNMATCHEDBLOCKRIGHTREMAINING   = -1510,  // Preprocessing engine unmatched block right remaining. Call LEAD
   ERROR_PREPROC_CODESILLEGALSUM                = -1511,  // Preprocessing engine illegal sum of chain codes. Call LEAD
   ERROR_PREPROC_ILLEGALSAMPLESIZE              = -1512,  // Preprocessing engine illegal sample size. Call LEAD
   ERROR_PREPROC_ILLEGALCIRCULARSPEC            = -1513,  // Preprocessing engine illegal circular/linear specification. Call LEAD
   ERROR_PREPROC_ILLEGALESSENTIALSPEC           = -1514,  // Preprocessing engine illegal essential/non-essential specification. Call LEAD
   ERROR_PREPROC_ILLEGALMINMAXSPEC              = -1515,  // Preprocessing engine illegal min or max specification. Call LEAD
   ERROR_PREPROC_ILLEGALSAMPLECOUNT             = -1516,  // Preprocessing engine illegal sample count. Call LEAD
   ERROR_PREPROC_ILLEGALMEANSPEC                = -1517,  // Preprocessing engine illegal prototype mean. Call LEAD
   ERROR_PREPROC_ILLEGALVARIANCESPEC            = -1518,  // Preprocessing engine illegal prototype variance. Call LEAD
   ERROR_PREPROC_ILLEGALDISTRIBUTION            = -1519,  // Preprocessing engine illegal prototype distribution. Call LEAD
   ERROR_PREPROC_ILLEGALSIGNIFICANCESPEC        = -1520,  // Preprocessing engine illegal significance specification. Call LEAD
   ERROR_PREPROC_ILLEGALSTYLESPEC               = -1521,  // Preprocessing engine illegal prototype style specification. Call LEAD
   ERROR_PREPROC_ILLEGALFLOAT                   = -1522,  // Preprocessing engine illegal float specification. Call LEAD
   ERROR_PREPROC_ILLEGALNUMSETS                 = -1523,  // Preprocessing engine illegal number of feature sets. Call LEAD
   ERROR_PREPROC_ILLEGALSHORTNAME               = -1524,  // Preprocessing engine illegal short name for a feature. Call LEAD
   ERROR_PREPROC_ILLEGALFEATUREPARAM            = -1525,  // Preprocessing engine illegal feature parameter spec. Call LEAD
   ERROR_PREPROC_ILLEGALNUMFEATURES             = -1526,  // Preprocessing engine illegal number of features in set. Call LEAD
   ERROR_PREPROC_HEAPFULL                       = -1527,  // Preprocessing engine heap size exceeded. Call LEAD
   ERROR_PREPROC_ILLEGALAMBIGUITYSPECIFICATION  = -1528,  // Preprocessing engine illegal ambiguity specification. Call LEAD
   ERROR_PREPROC_INVALIDUNICODECHARSET          = -1529,  // Preprocessing engine invalid Unicode character set. Call LEAD
   ERROR_PREPROC_BADOKMODE                      = -1530,  // Preprocessing engine bad OK mode. Call LEAD
   ERROR_PREPROC_BADREJECTMODE                  = -1531,  // Preprocessing engine bad reject mode. Call LEAD
   ERROR_PREPROC_READINGTEMPLATEFILE            = -1532,  // Preprocessing engine error reading template file. Call LEAD
   ERROR_PREPROC_READINGEDGESFILE               = -1533,  // Preprocessing engine error while reading edges from file. Call LEAD
   ERROR_PREPROC_CANTOPENCHOICEFILE             = -1534,  // Preprocessing engine could not open choice file. Call LEAD
} L_ERROR_PREPROC;

//=================================================================
// Medical Viewer
//=================================================================
typedef enum
{
   ERROR_MEDICALVIEWER_ACTION_NOT_ADDED         = -1538,       // (V16 or earlier) The specified action is not added to the Image Viewer.
                                                               // (V17) The specified action is not added to the Image Viewer Cell.
   ERROR_MEDICALVIEWER_ACTION_ALREADY_ADDED     = -1539,       // (V16 or earlier) The specified action is already added to the Image Viewer.
                                                               // (V17) The specified action is already added to the Image Viewer Cell.
} L_ERROR_MEDICALVIEWER;

//=================================================================
// Android
//=================================================================
typedef enum
{
   ERROR_MISSING_CLASS        = -1593,    // Java class not found
   ERROR_MISSING_CLASS_FIELD  = -1594     // Java class field missing
} L_ERROR_ANDROID;

//=================================================================
// WinRT exceptions
// These exceptions have an associated message stored in TLS
//=================================================================
typedef enum
{
   ERROR_LEAD_EXCEPTION_FIRST                = -1700,       // First error
   ERROR_LEAD_EXCEPTION_ARGUMENTOUTOFRANGE   = -1700,       // ArgumentOutOfRangeException
   ERROR_LEAD_EXCEPTION_ARGUMENTNULL         = -1701,
   ERROR_LEAD_EXCEPTION_ARGUMENT             = -1702,
   ERROR_LEAD_EXCEPTION_INVALIDOPREATION     = -1703,
   ERROR_LEAD_EXCEPTION_OCRCOMPONENTMISSING  = -1704,
   ERROR_LEAD_EXCEPTION_LAST                 = -1704,
} L_ERROR_EXCEPTIONS;

//=================================================================
// LTOCR errors
//=================================================================
typedef enum
{
   ERROR_OCR_NOT_ENABLED                           = -1760,       // OCR not enabled
   ERROR_OCR_PDF_NOT_ENABLED                       = -1761,       // OCR PDF not enabled
   ERROR_OCR_OMR_NOT_ENABLED                       = -1762,       // OCR OMR not enabled
   ERROR_OCR_ENGINE_NOT_STARTED                    = -1763,       // OCR engine not started
   ERROR_OCR_LANGUAGE_NOT_SUPPORTED                = -1764,       // OCR language not supported
   ERROR_OCR_COMPONENT_MISSING                     = -1765,       // OCR component missing
   ERROR_OCR_INVALID_SETTING_NAME                  = -1766,       // Invalid OCR setting name
   ERROR_OCR_INVALID_SETTING_TYPE                  = -1767,       // Invalid OCR setting type
   ERROR_OCR_INVALID_SETTING_VALUE                 = -1768,       // Invalid OCR setting value
   ERROR_OCR_INVALID_ZONE_TYPE                     = -1769,       // Invalid OCR zone type
   ERROR_OCR_INIT                                  = -1770,       // OCR engine initialization error, or there is no appropriate license
   ERROR_OCR_ERROR                                 = -1771,       // OCR generic error
   ERROR_OCR_SPELLCHECKER_NOT_FOUND                = -1772,       // Error loading spell checker or one of its dependences
   ERROR_OCR_MULTIPLE_ASIAN_LANGUAGES_NOT_ALLOWED  = -1774,       // Enabling multiple Asian languages not allowed
   ERROR_OCR_ZONE_OUTSIDE_BITMAP                   = -1867,       // One or more zones is completely outside the bitmap (zones were probably created for a bigger bitmap)
} L_ERROR_OCR;

//=================================================================
// Ltsane
//=================================================================
typedef enum
{
   ERROR_SANE_CANCELLED      = SUCCESS_ABORT,       // Operation canceled
   ERROR_SANE_UNSUPPORTED    = -1800,       // Operation is not supported
   ERROR_SANE_DEVICE_BUSY    = -1801,       // Device is busy
   ERROR_SANE_INVAL          = -1802,       // Data or argument is invalid
   ERROR_SANE_JAMMED         = -1803,       // Document feeder jammed
   ERROR_SANE_NO_DOCS        = -1804,       // Document feeder out of documents
   ERROR_SANE_COVER_OPEN     = -1805,       // Scanner cover is open
   ERROR_SANE_IO_ERROR       = -1806,       // Error during device I/O
   ERROR_SANE_ACCESS_DENIED  = -1807,       // Access to resource has been denied
} L_ERROR_SANE;

//=================================================================
// Document Writer errors
//=================================================================

typedef enum
{
   ERROR_INVALID_ALTOXML_INDENTATION = -1866,            // The Alto XML indentation contains invalid (non-space) characters
} L_ERROR_DOCWRT;

//=================================================================
// Lfheif
//=================================================================

typedef enum
{
   ERROR_HEIF_GETTING_ITEM_DATA              = -1879,       // Error getting the item data
   ERROR_HEIF_TILES_DIFFERENT_SIZE           = -1880,       // Not all tiles have the same size
   ERROR_HEIF_INVALID_GRID_DATA              = -1881,       // The grid data is invalid
   ERROR_HEIF_INVALID_COMPRESSION_PARAMS     = -1882,       // Invalid compression parameters - call LEAD
   ERROR_HEIF_INVALID_BOX_SIZE               = -1884,       // Invalid box size
   ERROR_HEIF_COMPONENTS_HAVE_DIFFERENT_BIT_DEPTHS = -1885, // Luma & Chroma components have different bit depths
   ERROR_HEIF_INVALID_EXIF_METADATA          = -1886,       // The exif metadata format is invalid - call LEAD
   ERROR_HEIF_UNSUPPORTED_IMAGE_TYPE         = -1887,       // Unsupported image type - call LEAD
   ERROR_HEIF_REFERENCES_MISSING             = -1888,       // Some references are missing
   ERROR_HEIF_ENCODER_FAILURE                = -1889,       // Generic error encoding the data
   ERROR_HEIF_UNSUPPORTED_CHROMA_FORMAT      = -1890,       // Unsupported chroma format - call LEAD
   ERROR_HEIF_DECODER_FAILURE                = -1891,       // Generic error decoding the data - call LEAD
   ERROR_HEIF_COMPRESSED_DATA_HAS_NO_FRAME   = -1892,       // The compressed data stream contains no frame
} L_ERROR_HEIF;

//=================================================================
// Lfwebp
//=================================================================

typedef enum
{
   ERROR_WEBP_FRAMES_OF_DIFFERENT_SIZES_NOT_SUPPORTED = -1924, // All the animation frames must have the same width and height
   ERROR_WEBP_ENCODER_FAILURE = -1925,                         // There was a generic WEBP encoder failure
   ERROR_WEBP_INVALID_ANIMATION_WIDTH_OR_HEIGHT = -1928,       // The animation width or height is invalid
} L_ERROR_WEBP;

#endif // #if !defined(LTERR_H)

