//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTCLK_H)
   #define LTCLK_H

// DO NOT FORGET to update the wrappers, for example Xcode LTRasterSupport.h!

   #if defined(LEADTOOLS_V20_OR_LATER)
      #define L_SUPPORT_DOCUMENT                            0        // Support for LEADTOOLS Document features (ABC, ABIC, JPEG 2000, JBIG2, NITF, CMW, Document Cleanup, Annotations, JPIP and more). Also includes support for 12 bit grayscale, 16-bit grayscale, 48-bit color and 64-bit images. A LEADTOOLS Document license is required.
      #define L_SUPPORT_BARCODES_1D                         1        // Support for reading and writing Linear bar codes. This is available in the LEADTOOLS Barcode 1D Module.
      #define L_SUPPORT_BARCODES_2D                         2        // Support for reading and writing 2D bar codes. This is available in the LEADTOOLS Barcode 2D Module.
      #define L_SUPPORT_RASTER_PDF_READ                     3        // Support for loading PDF, PS and EPS file formats as raster images. Available in selected LEADTOOLS products. If this support is locked, the PDF, PS and EPS files will not be loaded.
      #define L_SUPPORT_RASTER_PDF_SAVE                     4        // Support for saving raster images as a PDF file. Available in selected LEADTOOLS products. Includes support for MRC PDF compression and JBIG2 support.
      #define L_SUPPORT_PDF_ADVANCED                        5        // Support for advanced PDF features.
      #define L_SUPPORT_JBIG2                               6        // Support for the JBIG2 file format.
      #define L_SUPPORT_OCR_LEAD                            7        // Support for the OCR features provided by the LEADTOOLS OCR Module - LEAD Engine. OCR add-on to Document and Medical Imaging toolkits.
      #define L_SUPPORT_OCR_PLUS                            8        // (Deprecated) Support for the OCR features provided by the OCR Plus engine. OCR add-on to Document and Medical Imaging toolkits.
      #define L_SUPPORT_OCR_OMNIPAGE                        9        // Support for the OCR features provided by the LEADTOOLS OCR Module - OmniPage Engine. OCR add-on to Document and Medical Imaging toolkits.
      #define L_SUPPORT_OCR_OMNIPAGE_ASIAN                  10       // Support for the LEADTOOLS OCR Module - OmniPage Engine to recognize Asian text. Available in selected LEADTOOLS products.
      #define L_SUPPORT_OCR_OMNIPAGE_ARABIC                 11       // Support for Arabic OCR.
      #define L_SUPPORT_OCR_LEAD_PDF_OUTPUT                 12       // Support for saving OCR results from the LEADTOOLS OCR Module - LEAD Engine as a PDF file. This license is in addition to the cost of the OCR Plugin or Document Imaging.
      #define L_SUPPORT_OCR_PLUS_PDF_OUTPUT                 13       // (Deprecated) Support for saving OCR results from the OCR Plus engine as a PDF file. This license is in addition to the cost of the OCR Plugin or Document Imaging.
      #define L_SUPPORT_OCR_OMNIPAGE_PDF_OUTPUT             14       // Support for saving OCR results from the LEADTOOLS OCR Module - OmniPage Engine and Professional Asian engines as a PDF file. This license is in addition to the cost of the OCR Plugin or Document Imaging.
      #define L_SUPPORT_OCR_OMNIPAGE_ARABIC_PDF_OUTPUT      15       // Support for saving OCR results from the LEADTOOLS OCR Module - OmniPage Engine with Additional Languages as a PDF file. This license is in addition to the cost of the OCR Plugin or Document Imaging.
      #define L_SUPPORT_OMR                                 16       // Support for the LEADTOOLS OMR Module. This supports the recognition of check boxes. Available in selected LEADTOOLS products.
      #define L_SUPPORT_ICR_PLUS                            17       // (Deprecated) Support for the ICR Module within the OCR Plus engine. This supports the recognition of handwritten text. Available in selected LEADTOOLS products.
      #define L_SUPPORT_ICR_OMNIPAGE                        18       // Support for the ICR Module within the LEADTOOLS OCR Module - OmniPage Engine. This supports the recognition of handwritten text. Available in selected LEADTOOLS products.
      #define L_SUPPORT_DOCUMENT_WRITERS                    19       // Support for LEADTOOLS Document Writer functionality.
      #define L_SUPPORT_DOCUMENT_WRITERS_PDF                20       // Support for PDF output when using the LEADTOOLS Document Writer functionality.
      #define L_SUPPORT_PRINT_DRIVER                        21       // Support for LEADTOOLS Virtual Printer Driver functionality.
      #define L_SUPPORT_PRINT_DRIVER_SERVER                 22       // Support for LEADTOOLS Virtual Printer Driver functionality on Windows Server.
      #define L_SUPPORT_PRINT_DRIVER_NETWORK                23       // Support for LEADTOOLS Virtual Network Printer Driver functionality.
      #define L_SUPPORT_FORMS                               24       // Support for Forms Recognition and Processing functionality. Available in selected LEADTOOLS products.
      #define L_SUPPORT_MEDIA_WRITER                        25       // Support for Data DVD Writing. Available in selected LEADTOOLS products.
      #define L_SUPPORT_MEDICAL                             26       // Support for the DICOM file format, Document, and all Medical features excluding DICOM Communication. Also includes support for 12 bit grayscale, 16-bit grayscale, 48-bit color and 64-bit images.
      #define L_SUPPORT_MEDICAL_3D                          27       // Support for Medical 3D features.
      #define L_SUPPORT_DICOM_COMMUNICATION                 28       // Support for everything unlocked by Medical, plus support for DICOM Network Communication.
      #define L_SUPPORT_CCOW                                29       // Support for CCOW features.
      #define L_SUPPORT_VECTOR                              30       // Support for the Vector Features and Vector file formats. Available in selected LEADTOOLS products.
      #define L_SUPPORT_CLOUD                               31       // Support for LEADTOOLS Distributed Computing SDK.
      #define L_SUPPORT_APP_STORE                           32       // Support for using LEADTOOLS in an App Store application (Windows Store, Apple Store, Android Store). A LEADTOOLS App Store license is required.
      #define L_SUPPORT_BASIC                               33       // Support for LEADTOOLS Basic features.
      #define L_SUPPORT_HL7                                 34       // Support for Health Level 7.
      #define L_SUPPORT_MEDIA_STREAMING                     35       // Support for the Multimedia Media Streaming features.
      #define L_SUPPORT_SPECIAL_EFFECTS                     36       // Support for the Special Effects features.
      #define L_SUPPORT_MM                                  37       // Support for the Multimedia features.
      #define L_SUPPORT_MM_STREAMING                        38       // Support for the Multimedia Video Streaming features.
      #define L_SUPPORT_MM_MPEG_2                           39       // Support for the Multimedia MPEG-2 Transport features.
      #define L_SUPPORT_ANNOTATIONS                         40       // Support for the Annotations features.
      #define L_SUPPORT_SVG                                 41       // Support for the SVG features.
      #define L_SUPPORT_DOCUMENT_EDITING                    42       // Support for the Document Editing features.
      #define L_SUPPORT_MAX                                 42

   #define ISBARCODELOCKED() \
      L_IsSupportLocked(L_SUPPORT_BARCODES_1D)                 && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_2D)


   #elif defined(LEADTOOLS_V175_OR_LATER)
      #define L_SUPPORT_DOCUMENT                            0
      #define L_SUPPORT_BARCODES_1D                         1
      #define L_SUPPORT_BARCODES_2D                         2
      #define L_SUPPORT_RASTER_PDF_READ                     3
      #define L_SUPPORT_RASTER_PDF_SAVE                     4
      #define L_SUPPORT_PDF_ADVANCED                        5
      #define L_SUPPORT_JBIG2                               6
      #define L_SUPPORT_OCR_ADVANTAGE                       7
      #define L_SUPPORT_OCR_PLUS                            8
      #define L_SUPPORT_OCR_PROFESSIONAL                    9
      #define L_SUPPORT_OCR_PROFESSIONAL_ASIAN              10
      #define L_SUPPORT_OCR_ARABIC                          11
      #define L_SUPPORT_OCR_ADVANTAGE_PDF_OUTPUT            12
      #define L_SUPPORT_OCR_PLUS_PDF_OUTPUT                 13
      #define L_SUPPORT_OCR_PROFESSIONAL_PDF_OUTPUT         14
      #define L_SUPPORT_OCR_ARABIC_PDF_OUTPUT               15
      #define L_SUPPORT_OMR                                 16
      #define L_SUPPORT_ICR_PLUS                            17
      #define L_SUPPORT_ICR_PROFESSIONAL                    18
      #define L_SUPPORT_DOCUMENT_WRITERS                    19
      #define L_SUPPORT_DOCUMENT_WRITERS_PDF                20
      #define L_SUPPORT_PRINT_DRIVER                        21
      #define L_SUPPORT_PRINT_DRIVER_SERVER                 22
      #define L_SUPPORT_PRINT_DRIVER_NETWORK                23
      #define L_SUPPORT_FORMS                               24
      #define L_SUPPORT_MEDIA_WRITER                        25
      #define L_SUPPORT_MEDICAL                             26
      #define L_SUPPORT_MEDICAL_3D                          27
      #define L_SUPPORT_DICOM_COMMUNICATION                 28
      #define L_SUPPORT_CCOW                                29
      #define L_SUPPORT_VECTOR                              30
      #define L_SUPPORT_CLOUD                               31
      #define L_SUPPORT_APP_STORE                           32
      #define L_SUPPORT_BASIC                               33
      #define L_SUPPORT_HL7                                 34
      #define L_SUPPORT_MEDIA_STREAMING                     35
      #define L_SUPPORT_MAX                                 35

   #define ISBARCODELOCKED() \
      L_IsSupportLocked(L_SUPPORT_BARCODES_1D)                 && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_2D)

   #else
      #define L_SUPPORT_DOCUMENT                      0
      #define L_SUPPORT_RESERVED1                     1
      #define L_SUPPORT_RESERVED2                     2
      #define L_SUPPORT_OCR                           3
      #define L_SUPPORT_MEDICAL                       4
      #define L_SUPPORT_VECTOR                        5
      #define L_SUPPORT_MEDICAL_NET                   6
      #define L_SUPPORT_BARCODES_1D                   7
      #define L_SUPPORT_BARCODES_2D_READ              8
      #define L_SUPPORT_BARCODES_2D_WRITE             9
      #define L_SUPPORT_BARCODES_PDF_READ             10
      #define L_SUPPORT_BARCODES_PDF_WRITE            11
      #define L_SUPPORT_PDF                           12
      #define L_SUPPORT_J2K                           13
      #define L_SUPPORT_CMW                           14
      #define L_SUPPORT_DICOM                         15
      #define L_SUPPORT_EXTGRAY                       16
      #define L_SUPPORT_BITONAL                       17
      #define L_SUPPORT_PDF_SAVE                      18
      #define L_SUPPORT_OCR_PDF_OUTPUT                19
      #define L_SUPPORT_BARCODES_DATAMATRIX_READ      20
      #define L_SUPPORT_BARCODES_DATAMATRIX_WRITE     21
      #define L_SUPPORT_LTPRO                         22
      #define L_SUPPORT_OCR_ASIAN                     23
      #define L_SUPPORT_ICR                           24
      #define L_SUPPORT_LEAD_OMR                      51  // for v16
      #if defined(LTV15_CONFIG)
         #define L_SUPPORT_OMR                        25
      #else
         #define L_SUPPORT_OMR                        L_SUPPORT_LEAD_OMR
      #endif // #if defined(LTV15_CONFIG)
      #define L_SUPPORT_ABC                           26
      #define L_SUPPORT_BARCODES_QR_READ              27
      #define L_SUPPORT_BARCODES_QR_WRITE             28
      #define L_SUPPORT_BARCODES_1D_SILVER            29
      #define L_SUPPORT_MOBILE                        30
      #define L_SUPPORT_JBIG2                         31
      #define L_SUPPORT_ABIC_READ                     32
      #define L_SUPPORT_ABIC_SAVE                     33
      #define L_SUPPORT_PDF_READ                      34
      #define L_SUPPORT_PDF_ADVANCED                  35
      #define L_SUPPORT_NITF                          36
      #define L_SUPPORT_OCR_ARABIC                    37
      // unlocks for v16
      #define L_SUPPORT_START_V16_OR_LATER                  38
      #define L_SUPPORT_JPIP                                38
      #define L_SUPPORT_OCR_PLUS                            L_SUPPORT_OCR
      #define L_SUPPORT_OCR_PLUS_PDF_OUTPUT                 L_SUPPORT_OCR_PDF_OUTPUT
      #define L_SUPPORT_ICR_PLUS                            L_SUPPORT_ICR
      #define L_SUPPORT_OMR_PLUS                            L_SUPPORT_OMR
      #define L_SUPPORT_OCR_PLUS_PDF_LEAD_OUTPUT            39
      #define L_SUPPORT_OCR_PROFESSIONAL                    40
      #define L_SUPPORT_OCR_PROFESSIONAL_PDF_OUTPUT         41
      #define L_SUPPORT_ICR_PROFESSIONAL                    42
      #define L_SUPPORT_OMR_PROFESSIONAL                    L_SUPPORT_LEAD_OMR
      #define L_SUPPORT_OCR_PROFESSIONAL_PDF_LEAD_OUTPUT    44
      #define L_SUPPORT_OCR_PROFESSIONAL_ASIAN              L_SUPPORT_OCR_ASIAN
      #define L_SUPPORT_OCR_ADVANTAGE                       45
      #define L_SUPPORT_OCR_ADVANTAGE_PDF_LEAD_OUTPUT       46
      #define L_SUPPORT_FORMS                               47
      #define L_SUPPORT_MEDICAL_SERVER                      48
      #define L_SUPPORT_PRINT_DRIVER                        49
      #define L_SUPPORT_DOCUMENT_WRITERS                    50
      #define L_SUPPORT_MEDIA_WRITER                        52
      #define L_SUPPORT_DOCUMENT_WRITERS_PDF                53
      #define L_SUPPORT_MEDICAL_3D                          54
      #define L_SUPPORT_OCR_ARABIC_PDF_LEAD_OUTPUT          55
      #define L_SUPPORT_PRINT_DRIVER_SERVER                 56
      // unlocks for v17
      #define L_SUPPORT_CCOW                                57
      #define L_SUPPORT_BARCODES_2D                         58
      #define L_SUPPORT_PRINT_DRIVER_NETWORK                59
      // unlocks for v175
      #define L_SUPPORT_CLOUD                               60
      #define L_SUPPORT_MAX                                 60

   #define ISBARCODELOCKED() \
      L_IsSupportLocked(L_SUPPORT_BARCODES_1D)                 && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_2D_READ)            && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_2D_WRITE)           && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_PDF_READ)           && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_PDF_WRITE)          && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_DATAMATRIX_READ)    && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_DATAMATRIX_WRITE)   && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_QR_READ)            && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_QR_WRITE)           && \
      L_IsSupportLocked(L_SUPPORT_BARCODES_1D_SILVER)

   #endif // #if defined(LEADTOOLS_V175_OR_LATER)

#endif // #if !defined(LTCLK_H)
