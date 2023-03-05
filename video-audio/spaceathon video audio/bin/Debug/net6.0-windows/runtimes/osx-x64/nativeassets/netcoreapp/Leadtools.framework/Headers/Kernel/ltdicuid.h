// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************

//------------- UID -----------------------------------
//============= CLASS ==========================================================
//
#define UID_MAX_SIZE   64

// ANSI defines
#define UID_VERIFICATION_CLASS_A                                                    "1.2.840.10008.1.1"                               // V15      
#define UID_IMPLICIT_VR_LITTLE_ENDIAN_A                                             "1.2.840.10008.1.2"                               // V15      
#define UID_EXPLICIT_VR_LITTLE_ENDIAN_A                                             "1.2.840.10008.1.2.1"                             // V15      
#define UID_DEFLATED_EXPLICIT_VR_LITTLE_ENDIAN_A                                    "1.2.840.10008.1.2.1.99"                          // V15      
#define UID_EXPLICIT_VR_BIG_ENDIAN_A                                                "1.2.840.10008.1.2.2"                             // V15      Retired
#define UID_JPEG_BASELINE_1_A                                                       "1.2.840.10008.1.2.4.50"                          // V15      
#define UID_JPEG_EXTENDED_2_4_A                                                     "1.2.840.10008.1.2.4.51"                          // V15      
#define UID_JPEG_EXTENDED_3_5_A                                                     "1.2.840.10008.1.2.4.52"                          // V15      Retired
#define UID_JPEG_SPECTRAL_NONHIER_6_8_A                                             "1.2.840.10008.1.2.4.53"                          // V15      Retired
#define UID_JPEG_SPECTRAL_NONHIER_7_9_A                                             "1.2.840.10008.1.2.4.54"                          // V15      Retired
#define UID_JPEG_FULL_NONHIER_10_12_A                                               "1.2.840.10008.1.2.4.55"                          // V15      Retired
#define UID_JPEG_FULL_NONHIER_11_13_A                                               "1.2.840.10008.1.2.4.56"                          // V15      Retired
#define UID_JPEG_LOSSLESS_NONHIER_14_A                                              "1.2.840.10008.1.2.4.57"                          // V15      
#define UID_JPEG_LOSSLESS_NONHIER_15_A                                              "1.2.840.10008.1.2.4.58"                          // V15      Retired
#define UID_JPEG_EXTENDED_HIER_16_18_A                                              "1.2.840.10008.1.2.4.59"                          // V15      Retired
#define UID_JPEG_EXTENDED_HIER_17_19_A                                              "1.2.840.10008.1.2.4.60"                          // V15      Retired
#define UID_JPEG_SPECTRAL_HIER_20_22_A                                              "1.2.840.10008.1.2.4.61"                          // V15      Retired
#define UID_JPEG_SPECTRAL_HIER_21_23_A                                              "1.2.840.10008.1.2.4.62"                          // V15      Retired
#define UID_JPEG_FULL_HIER_24_26_A                                                  "1.2.840.10008.1.2.4.63"                          // V15      Retired
#define UID_JPEG_FULL_HIER_25_27_A                                                  "1.2.840.10008.1.2.4.64"                          // V15      Retired
#define UID_JPEG_LOSSLESS_HIER_PROCESS_28_A                                         "1.2.840.10008.1.2.4.65"                          // V15      Retired
#define UID_JPEG_LOSSLESS_HIER_PROCESS_29_A                                         "1.2.840.10008.1.2.4.66"                          // V15      Retired
#define UID_JPEG_LOSSLESS_NONHIER_14B_A                                             "1.2.840.10008.1.2.4.70"                          // V15      
#define UID_JPEG_LS_LOSSLESS_A                                                      "1.2.840.10008.1.2.4.80"                          // V15      
#define UID_JPEG_LS_LOSSY_A                                                         "1.2.840.10008.1.2.4.81"                          // V15      
#define UID_JPEG2000_LOSSLESS_ONLY_A                                                "1.2.840.10008.1.2.4.90"                          // V15      
#define UID_JPEG2000_A                                                              "1.2.840.10008.1.2.4.91"                          // V15      
#define UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_LOSSLESS_ONLY_A      "1.2.840.10008.1.2.4.92"                          //          
#define UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_A                    "1.2.840.10008.1.2.4.93"                          //          
#define UID_JPIP_REFERENCED_A                                                       "1.2.840.10008.1.2.4.94"                          //          
#define UID_JPIP_REFERENCED_DEFLATE_A                                               "1.2.840.10008.1.2.4.95"                          //          
#define UID_MPEG2_MAIN_PROFILE_MAIN_LEVEL_A                                         "1.2.840.10008.1.2.4.100"                         // V15      
#define UID_MPEG2_MAIN_PROFILE_HIGH_LEVEL_A                                         "1.2.840.10008.1.2.4.101"                         //          
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_1_A                               "1.2.840.10008.1.2.4.102"                         //          
#define UID_MPEG_4_AVC_H_264_BD_COMPATIBLE_HIGH_PROFILE_LEVEL_4_1_A                 "1.2.840.10008.1.2.4.103"                         //          
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_2D_VIDEO_A                  "1.2.840.10008.1.2.4.104"                         // 2015      
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_3D_VIDEO_A                  "1.2.840.10008.1.2.4.105"                         // 2015      
#define UID_MPEG_4_AVC_H_264_STEREO_HIGH_PROFILE_LEVEL_4_2_A                        "1.2.840.10008.1.2.4.106"                         // 2015      
#define UID_HEVC_H_265_MAIN_PROFILE_LEVEL_5_1_A                                     "1.2.840.10008.1.2.4.107"                         // 2020      
#define UID_HEVC_H_265_MAIN_10_PROFILE_LEVEL_5_1_A                                  "1.2.840.10008.1.2.4.108"                         // 2020      
#define UID_RLE_LOSSLESS_A                                                          "1.2.840.10008.1.2.5"                             // V15      
#define UID_RFC_2557_MIME_ENCAPSULATION_A                                           "1.2.840.10008.1.2.6.1"                           //          Retired
#define UID_XML_ENCODING_A                                                          "1.2.840.10008.1.2.6.2"                           //          Retired
#define UID_SMPTE_ST_2110_20_UNCOMPRESSED_PROGRESSIVE_ACTIVE_VIDEO_A                "1.2.840.10008.1.2.7.1"                           // 2021      
#define UID_SMPTE_ST_2110_20_UNCOMPRESSED_INTERLACED_ACTIVE_VIDEO_A                 "1.2.840.10008.1.2.7.2"                           // 2021      
#define UID_SMPTE_ST_2110_30_PCM_DIGITAL_AUDIO_A                                    "1.2.840.10008.1.2.7.3"                           // 2021      
#define UID_MEDIA_STORAGE_DIRECTORY_A                                               "1.2.840.10008.1.3.10"                            // V15      
#define UID_TALAIRACH_BRAIN_ATLAS_FRAME_OF_REFERENCE_A                              "1.2.840.10008.1.4.1.1"                           //          
#define UID_SPM2_T1_FRAME_OF_REFERENCE_A                                            "1.2.840.10008.1.4.1.2"                           //          
#define UID_SPM2_T2_FRAME_OF_REFERENCE_A                                            "1.2.840.10008.1.4.1.3"                           //          
#define UID_SPM2_PD_FRAME_OF_REFERENCE_A                                            "1.2.840.10008.1.4.1.4"                           //          
#define UID_SPM2_EPI_FRAME_OF_REFERENCE_A                                           "1.2.840.10008.1.4.1.5"                           //          
#define UID_SPM2_FIL_T1_FRAME_OF_REFERENCE_A                                        "1.2.840.10008.1.4.1.6"                           //          
#define UID_SPM2_PET_FRAME_OF_REFERENCE_A                                           "1.2.840.10008.1.4.1.7"                           //          
#define UID_SPM2_TRANSM_FRAME_OF_REFERENCE_A                                        "1.2.840.10008.1.4.1.8"                           //          
#define UID_SPM2_SPECT_FRAME_OF_REFERENCE_A                                         "1.2.840.10008.1.4.1.9"                           //          
#define UID_SPM2_GRAY_FRAME_OF_REFERENCE_A                                          "1.2.840.10008.1.4.1.10"                          //          
#define UID_SPM2_WHITE_FRAME_OF_REFERENCE_A                                         "1.2.840.10008.1.4.1.11"                          //          
#define UID_SPM2_CSF_FRAME_OF_REFERENCE_A                                           "1.2.840.10008.1.4.1.12"                          //          
#define UID_SPM2_BRAINMASK_FRAME_OF_REFERENCE_A                                     "1.2.840.10008.1.4.1.13"                          //          
#define UID_SPM2_AVG305T1_FRAME_OF_REFERENCE_A                                      "1.2.840.10008.1.4.1.14"                          //          
#define UID_SPM2_AVG152T1_FRAME_OF_REFERENCE_A                                      "1.2.840.10008.1.4.1.15"                          //          
#define UID_SPM2_AVG152T2_FRAME_OF_REFERENCE_A                                      "1.2.840.10008.1.4.1.16"                          //          
#define UID_SPM2_AVG152PD_FRAME_OF_REFERENCE_A                                      "1.2.840.10008.1.4.1.17"                          //          
#define UID_SPM2_SINGLESUBJT1_FRAME_OF_REFERENCE_A                                  "1.2.840.10008.1.4.1.18"                          //          
#define UID_ICBM_452_T1_FRAME_OF_REFERENCE_A                                        "1.2.840.10008.1.4.2.1"                           //          
#define UID_ICBM_SINGLE_SUBJECT_MRI_FRAME_OF_REFERENCE_A                            "1.2.840.10008.1.4.2.2"                           //          
#define UID_IEC_61217_FIXED_COORDINATE_SYSTEM_FRAME_OF_REFERENCE_A                  "1.2.840.10008.1.4.3.1"                           // 2021      
#define UID_STANDARD_ROBOTIC_ARM_COORDINATE_SYSTEM_FRAME_OF_REFERENCE_A             "1.2.840.10008.1.4.3.2"                           // 2021      
#define UID_SRI24_FRAME_OF_REFERENCE_A                                              "1.2.840.10008.1.4.4.1"                           // 2021      
#define UID_COLIN27_FRAME_OF_REFERENCE_A                                            "1.2.840.10008.1.4.5.1"                           // 2021      
#define UID_LPBA40_AIR_FRAME_OF_REFERENCE_A                                         "1.2.840.10008.1.4.6.1"                           // 2021      
#define UID_LPBA40_FLIRT_FRAME_OF_REFERENCE_A                                       "1.2.840.10008.1.4.6.2"                           // 2021      
#define UID_LPBA40_SPM5_FRAME_OF_REFERENCE_A                                        "1.2.840.10008.1.4.6.3"                           // 2021      
#define UID_HOT_IRON_COLOR_PALETTE_SOP_INSTANCE_A                                   "1.2.840.10008.1.5.1"                             //          
#define UID_PET_COLOR_PALETTE_SOP_INSTANCE_A                                        "1.2.840.10008.1.5.2"                             //          
#define UID_HOT_METAL_BLUE_COLOR_PALETTE_SOP_INSTANCE_A                             "1.2.840.10008.1.5.3"                             //          
#define UID_PET_20_STEP_COLOR_PALETTE_SOP_INSTANCE_A                                "1.2.840.10008.1.5.4"                             //          
#define UID_SPRING_COLOR_PALETTE_SOP_INSTANCE_A                                     "1.2.840.10008.1.5.5"                             // 2021      
#define UID_SUMMER_COLOR_PALETTE_SOP_INSTANCE_A                                     "1.2.840.10008.1.5.6"                             // 2021      
#define UID_FALL_COLOR_PALETTE_SOP_INSTANCE_A                                       "1.2.840.10008.1.5.7"                             // 2021      
#define UID_WINTER_COLOR_PALETTE_SOP_INSTANCE_A                                     "1.2.840.10008.1.5.8"                             // 2021      
#define UID_BASIC_STUDY_NOTIFICATION_CLASS_A                                        "1.2.840.10008.1.9"                               // V15      Retired
#define UID_PAPYRUS_3_IMPLICIT_VR_LITTLE_ENDIAN_A                                   "1.2.840.10008.1.20"                              // V15      Retired
#define UID_STORAGE_COMMITMENT_PUSH_MODEL_CLASS_A                                   "1.2.840.10008.1.20.1"                            // V15      
#define UID_STORAGE_COMMITMENT_PUSH_MODEL_INSTANCE_A                                "1.2.840.10008.1.20.1.1"                          // V15      
#define UID_STORAGE_COMMITMENT_PULL_MODEL_CLASS_A                                   "1.2.840.10008.1.20.2"                            // V15      Retired
#define UID_STORAGE_COMMITMENT_PULL_MODEL_INSTANCE_A                                "1.2.840.10008.1.20.2.1"                          // V15      Retired
#define UID_PROCEDURAL_EVENT_LOGGING_A                                              "1.2.840.10008.1.40"                              //          
#define UID_PROCEDURAL_EVENT_LOGGING_SOP_INSTANCE_A                                 "1.2.840.10008.1.40.1"                            //          
#define UID_SUBSTANCE_ADMINISTRATION_LOGGING_A                                      "1.2.840.10008.1.42"                              //          
#define UID_SUBSTANCE_ADMINISTRATION_LOGGING_SOP_INSTANCE_A                         "1.2.840.10008.1.42.1"                            //          
#define UID_DICOM_REGISTRY_A                                                        "1.2.840.10008.2.6.1"                             //          
#define UID_DICOM_CONTROLLED_TERMINOLOGY_A                                          "1.2.840.10008.2.16.4"                            // V15      
#define UID_ADULT_MOUSE_ANATOMY_ONTOLOGY_A                                          "1.2.840.10008.2.16.5"                            // 2021      
#define UID_UBERON_ONTOLOGY_A                                                       "1.2.840.10008.2.16.6"                            // 2021      
#define UID_INTEGRATED_TAXONOMIC_INFORMATION_SYSTEM_TAXONOMIC_SERIAL_NUMBER_A       "1.2.840.10008.2.16.7"                            // 2021      
#define UID_MOUSE_GENOME_INITIATIVE_MGI_A                                           "1.2.840.10008.2.16.8"                            // 2021      
#define UID_PUBCHEM_COMPOUND_CID_A                                                  "1.2.840.10008.2.16.9"                            // 2021      
#define UID_DUBLIN_CORE_A                                                           "1.2.840.10008.2.16.10"                           // 2021      
#define UID_NEW_YORK_UNIVERSITY_MELANOMA_CLINICAL_COOPERATIVE_GROUP_A               "1.2.840.10008.2.16.11"                           // 2021      
#define UID_MAYO_CLINIC_NON_RADIOLOGICAL_IMAGES_SPECIFIC_BODY_STRUCTURE_ANATOMICAL_SURFACE_REGION_GUIDE_A "1.2.840.10008.2.16.12"                           // 2021      
#define UID_IMAGE_BIOMARKER_STANDARDISATION_INITIATIVE_A                            "1.2.840.10008.2.16.13"                           // 2021      
#define UID_RADIOMICS_ONTOLOGY_A                                                    "1.2.840.10008.2.16.14"                           // 2021      
#define UID_RADELEMENT_A                                                            "1.2.840.10008.2.16.15"                           // 2021      
#define UID_ICD_11_A                                                                "1.2.840.10008.2.16.16"                           // 2021      
#define UID_APPLICATION_CONTEXT_NAME_A                                              "1.2.840.10008.3.1.1.1"                           // V15      
#define UID_DETACHED_PATIENT_CLASS_A                                                "1.2.840.10008.3.1.2.1.1"                         // V15      Retired
#define UID_DETACHED_PATIENT_META_CLASS_A                                           "1.2.840.10008.3.1.2.1.4"                         // V15      Retired
#define UID_DETACHED_VISIT_CLASS_A                                                  "1.2.840.10008.3.1.2.2.1"                         // V15      Retired
#define UID_DETACHED_STUDY_CLASS_A                                                  "1.2.840.10008.3.1.2.3.1"                         // V15      Retired
#define UID_STUDY_COMPONENT_CLASS_A                                                 "1.2.840.10008.3.1.2.3.2"                         // V15      Retired
#define UID_MODALITY_PERFORMED_CLASS_A                                              "1.2.840.10008.3.1.2.3.3"                         // V15      
#define UID_MODALITY_PERFORMED_RETRIEVE_CLASS_A                                     "1.2.840.10008.3.1.2.3.4"                         // V15      
#define UID_MODALITY_PERFORMED_NOTIFICATION_CLASS_A                                 "1.2.840.10008.3.1.2.3.5"                         // V15      
#define UID_DETACHED_RESULTS_CLASS_A                                                "1.2.840.10008.3.1.2.5.1"                         // V15      Retired
#define UID_DETACHED_RESULTS_META_CLASS_A                                           "1.2.840.10008.3.1.2.5.4"                         // V15      Retired
#define UID_DETACHED_STUDY_META_CLASS_A                                             "1.2.840.10008.3.1.2.5.5"                         // V15      Retired
#define UID_DETACHED_INTERPRETATION_CLASS_A                                         "1.2.840.10008.3.1.2.6.1"                         // V15      Retired
#define UID_STORAGE_SERVICE_CLASS_A                                                 "1.2.840.10008.4.2"                               //          
#define UID_BASIC_FILM_SESSION_CLASS_A                                              "1.2.840.10008.5.1.1.1"                           // V15      
#define UID_BASIC_FILM_BOX_CLASS_A                                                  "1.2.840.10008.5.1.1.2"                           // V15      
#define UID_BASIC_GRAYSCALE_IMAGE_BOX_CLASS_A                                       "1.2.840.10008.5.1.1.4"                           // V15      
#define UID_BASIC_COLOR_IMAGE_BOX_CLASS_A                                           "1.2.840.10008.5.1.1.4.1"                         // V15      
#define UID_REFERENCED_IMAGE_BOX_CLASS_RETIRED_A                                    "1.2.840.10008.5.1.1.4.2"                         // V15      Retired
#define UID_BASIC_GRAYSCALE_PRINT_META_CLASS_A                                      "1.2.840.10008.5.1.1.9"                           // V15      
#define UID_REFERENCED_GRAYSCALE_PRINT_META_CLASS_RETIRED_A                         "1.2.840.10008.5.1.1.9.1"                         // V15      Retired
#define UID_PRINT_JOB_CLASS_A                                                       "1.2.840.10008.5.1.1.14"                          // V15      
#define UID_BASIC_ANNOTATION_BOX_CLASS_A                                            "1.2.840.10008.5.1.1.15"                          // V15      
#define UID_PRINTER_CLASS_A                                                         "1.2.840.10008.5.1.1.16"                          // V15      
#define UID_PRINTER_CONFIGURATION_RETRIEVAL_CLASS_A                                 "1.2.840.10008.5.1.1.16.376"                      // V15      
#define UID_PRINTER_INSTANCE_A                                                      "1.2.840.10008.5.1.1.17"                          // V15      
#define UID_PRINTER_CONFIGURATION_RETRIEVAL_INSTANCE_A                              "1.2.840.10008.5.1.1.17.376"                      // V15      
#define UID_BASIC_COLOR_PRINT_META_CLASS_A                                          "1.2.840.10008.5.1.1.18"                          // V15      
#define UID_REFERENCED_COLOR_PRINT_META_CLASS_RETIRED_A                             "1.2.840.10008.5.1.1.18.1"                        // V15      Retired
#define UID_VOI_LUT_BOX_CLASS_RETIRED_A                                             "1.2.840.10008.5.1.1.22"                          // V15      
#define UID_PRESENTATION_LUT_CLASS_A                                                "1.2.840.10008.5.1.1.23"                          // V15      
#define UID_IMAGE_OVERLAY_BOX_CLASS_RETIRED_A                                       "1.2.840.10008.5.1.1.24"                          // V15      Retired
#define UID_BASIC_PRINT_IMAGE_OVERLAY_BOX_CLASS_A                                   "1.2.840.10008.5.1.1.24.1"                        // V15      Retired
#define UID_PRINT_QUEUE_INSTANCE_A                                                  "1.2.840.10008.5.1.1.25"                          // V15      Retired
#define UID_PRINT_QUEUE_CLASS_A                                                     "1.2.840.10008.5.1.1.26"                          // V15      Retired
#define UID_STORED_PRINT_STORAGE_CLASS_A                                            "1.2.840.10008.5.1.1.27"                          // V15      Retired
#define UID_HARDCOPY_GRAYSCALE_IMAGE_STORAGE_CLASS_A                                "1.2.840.10008.5.1.1.29"                          // V15      Retired
#define UID_HARDCOPY_COLOR_IMAGE_STORAGE_CLASS_A                                    "1.2.840.10008.5.1.1.30"                          // V15      Retired
#define UID_PULL_PRINT_REQUEST_CLASS_A                                              "1.2.840.10008.5.1.1.31"                          // V15      Retired
#define UID_PULL_STORED_PRINT_META_CLASS_A                                          "1.2.840.10008.5.1.1.32"                          // V15      Retired
#define UID_MEDIA_CREATION_MANAGEMENT_A                                             "1.2.840.10008.5.1.1.33"                          //          
#define UID_DISPLAY_SYSTEM_A                                                        "1.2.840.10008.5.1.1.40"                          // 2014      
#define UID_DISPLAY_SYSTEM_SOP_INSTANCE_A                                           "1.2.840.10008.5.1.1.40.1"                        // 2014      
#define UID_CR_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.1"                       // V15      
#define UID_DX_IMAGE_STORAGE_PRESENTATION_A                                         "1.2.840.10008.5.1.4.1.1.1.1"                     // V15      
#define UID_DX_IMAGE_STORAGE_PROCESSING_A                                           "1.2.840.10008.5.1.4.1.1.1.1.1"                   // V15      
#define UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PRESENTATION_A                             "1.2.840.10008.5.1.4.1.1.1.2"                     // V15      
#define UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PROCESSING_A                               "1.2.840.10008.5.1.4.1.1.1.2.1"                   // V15      
#define UID_DX_INTRAORAL_IMAGE_STORAGE_PRESENTATION_A                               "1.2.840.10008.5.1.4.1.1.1.3"                     // V15      
#define UID_DX_INTRAORAL_IMAGE_STORAGE_PROCESSING_A                                 "1.2.840.10008.5.1.4.1.1.1.3.1"                   // V15      
#define UID_CT_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.2"                       // V15      
#define UID_ENHANCED_CT_IMAGE_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.2.1"                     //          
#define UID_LEGACY_CONVERTED_ENHANCED_CT_IMAGE_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.2.2"                     // 2014      
#define UID_US_MULTIFRAME_IMAGE_STORAGE_RETIRED_A                                   "1.2.840.10008.5.1.4.1.1.3"                       // V15      Retired
#define UID_US_MULTIFRAME_IMAGE_STORAGE_A                                           "1.2.840.10008.5.1.4.1.1.3.1"                     // V15      
#define UID_MR_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.4"                       // V15      
#define UID_ENHANCED_MR_IMAGE_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.4.1"                     // V15      
#define UID_MR_SPECTROSCOPY_STORAGE_A                                               "1.2.840.10008.5.1.4.1.1.4.2"                     // V15      
#define UID_ENHANCED_MR_COLOR_IMAGE_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.4.3"                     //          
#define UID_LEGACY_CONVERTED_ENHANCED_MR_IMAGE_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.4.4"                     // 2014      
#define UID_NM_IMAGE_STORAGE_RETIRED_A                                              "1.2.840.10008.5.1.4.1.1.5"                       // V15      Retired
#define UID_US_IMAGE_STORAGE_RETIRED_A                                              "1.2.840.10008.5.1.4.1.1.6"                       // V15      Retired
#define UID_US_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.6.1"                     // V15      
#define UID_ENHANCED_US_VOLUME_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.6.2"                     //          
#define UID_SC_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.7"                       // V15      
#define UID_SC_MULTI_FRAME_SINGLE_BIT_IMAGE_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.7.1"                     // V15      
#define UID_SC_MULTI_FRAME_GRAYSCALE_BYTE_IMAGE_STORAGE_A                           "1.2.840.10008.5.1.4.1.1.7.2"                     // V15      
#define UID_SC_MULTI_FRAME_GRAYSCALE_WORD_IMAGE_STORAGE_A                           "1.2.840.10008.5.1.4.1.1.7.3"                     // V15      
#define UID_SC_MULTI_FRAME_TRUE_COLOR_IMAGE_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.7.4"                     // V15      
#define UID_STANDALONE_OVERLAY_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.8"                       // V15      Retired
#define UID_STANDALONE_CURVE_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.9"                       // V15      Retired
#define UID_WAVEFORM_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.9.1"                     // V15      Retired
#define UID_12_LEAD_ECG_WAVEFORM_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.9.1.1"                   // V15      
#define UID_GENERAL_ECG_WAVEFORM_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.9.1.2"                   // V15      
#define UID_AMBULATORY_ECG_WAVEFORM_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.9.1.3"                   // V15      
#define UID_HEMODYNAMIC_WAVEFORM_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.9.2.1"                   // V15      
#define UID_CARDIAC_ELECTROPHYSIOLOGY_WAVEFORM_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.9.3.1"                   // V15      
#define UID_BASIC_VOICE_AUDIO_WAVEFORM_STORAGE_A                                    "1.2.840.10008.5.1.4.1.1.9.4.1"                   // V15      
#define UID_GENERAL_AUDIO_WAVEFORM_STORAGE_A                                        "1.2.840.10008.5.1.4.1.1.9.4.2"                   //          
#define UID_ARTERIAL_PULSE_WAVEFORM_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.9.5.1"                   //          
#define UID_RESPIRATORY_WAVEFORM_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.9.6.1"                   //          
#define UID_MULTI_CHANNEL_RESPIRATORY_WAVEFORM_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.9.6.2"                   // 2021      
#define UID_ROUTINE_SCALP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE_A                   "1.2.840.10008.5.1.4.1.1.9.7.1"                   // 2021      
#define UID_ELECTROMYOGRAM_WAVEFORM_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.9.7.2"                   // 2021      
#define UID_ELECTROOCULOGRAM_WAVEFORM_STORAGE_A                                     "1.2.840.10008.5.1.4.1.1.9.7.3"                   // 2021      
#define UID_SLEEP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE_A                           "1.2.840.10008.5.1.4.1.1.9.7.4"                   // 2021      
#define UID_BODY_POSITION_WAVEFORM_STORAGE_A                                        "1.2.840.10008.5.1.4.1.1.9.8.1"                   // 2021      
#define UID_STANDALONE_MODALITY_LUT_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.10"                      // V15      Retired
#define UID_STANDALONE_VOI_LUT_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.11"                      // V15      Retired
#define UID_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE_A                         "1.2.840.10008.5.1.4.1.1.11.1"                    // V15      
#define UID_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE_A                             "1.2.840.10008.5.1.4.1.1.11.2"                    //          
#define UID_PSEUDO_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE_A                      "1.2.840.10008.5.1.4.1.1.11.3"                    //          
#define UID_BLENDING_SOFTCOPY_PRESENTATION_STATE_STORAGE_A                          "1.2.840.10008.5.1.4.1.1.11.4"                    //          
#define UID_XA_XRF_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE_A                  "1.2.840.10008.5.1.4.1.1.11.5"                    //          
#define UID_GRAYSCALE_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A            "1.2.840.10008.5.1.4.1.1.11.6"                    // 2021      
#define UID_COMPOSITING_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A          "1.2.840.10008.5.1.4.1.1.11.7"                    // 2021      
#define UID_ADVANCED_BLENDING_PRESENTATION_STATE_STORAGE_A                          "1.2.840.10008.5.1.4.1.1.11.8"                    // 2021      
#define UID_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A                "1.2.840.10008.5.1.4.1.1.11.9"                    // 2021      
#define UID_SEGMENTED_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A      "1.2.840.10008.5.1.4.1.1.11.10"                   // 2021      
#define UID_MULTIPLE_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A       "1.2.840.10008.5.1.4.1.1.11.11"                   // 2021      
#define UID_XA_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.12.1"                    // V15      
#define UID_ENHANCED_XA_IMAGE_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.12.1.1"                  //          
#define UID_XRF_IMAGE_STORAGE_A                                                     "1.2.840.10008.5.1.4.1.1.12.2"                    // V15      
#define UID_ENHANCED_XRF_IMAGE_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.12.2.1"                  //          
#define UID_XA_BIPLANE_IMAGE_STORAGE_RETIRED_A                                      "1.2.840.10008.5.1.4.1.1.12.3"                    // V15      Retired
#define UID_X_RAY_3D_ANGIOGRAPHIC_IMAGE_STORAGE_A                                   "1.2.840.10008.5.1.4.1.1.13.1.1"                  //          
#define UID_X_RAY_3D_CRANIOFACIAL_IMAGE_STORAGE_A                                   "1.2.840.10008.5.1.4.1.1.13.1.2"                  //          
#define UID_BREAST_TOMOSYNTHESIS_IMAGE_STORAGE_A                                    "1.2.840.10008.5.1.4.1.1.13.1.3"                  //          
#define UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PRESENTATION_A                    "1.2.840.10008.5.1.4.1.1.13.1.4"                  // 2014      
#define UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PROCESSING_A                      "1.2.840.10008.5.1.4.1.1.13.1.5"                  // 2014      
#define UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PRESENTATION_A                          "1.2.840.10008.5.1.4.1.1.14.1"                    //          
#define UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PROCESSING_A                            "1.2.840.10008.5.1.4.1.1.14.2"                    //          
#define UID_NM_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.20"                      // V15      
#define UID_PARAMETRIC_MAP_STORAGE_A                                                "1.2.840.10008.5.1.4.1.1.30"                      // 2015      
#define UID_RAW_DATA_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.66"                      // V15      
#define UID_SPATIAL_REGISTRATION_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.66.1"                    //          
#define UID_SPATIAL_FIDUCIALS_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.66.2"                    //          
#define UID_DEFORMABLE_SPATIAL_REGISTRATION_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.66.3"                    //          
#define UID_SEGMENTATION_STORAGE_A                                                  "1.2.840.10008.5.1.4.1.1.66.4"                    //          
#define UID_SURFACE_SEGMENTATION_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.66.5"                    //          
#define UID_TRACTOGRAPHY_RESULTS_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.66.6"                    // 2021      
#define UID_REAL_WORLD_VALUE_MAPPING_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.67"                      //          
#define UID_SURFACE_SCAN_MESH_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.68.1"                    // 2014      
#define UID_SURFACE_SCAN_POINT_CLOUD_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.68.2"                    // 2014      
#define UID_VL_IMAGE_STORAGE_RETIRED_A                                              "1.2.840.10008.5.1.4.1.1.77.1"                    // V15      Retired
#define UID_VL_ENDOSCOPIC_IMAGE_STORAGE_CLASS_A                                     "1.2.840.10008.5.1.4.1.1.77.1.1"                  // V15      
#define UID_VIDEO_ENDOSCOPIC_IMAGE_STORAGE_A                                        "1.2.840.10008.5.1.4.1.1.77.1.1.1"                // V15      
#define UID_VL_MICROSCOPIC_IMAGE_STORAGE_CLASS_A                                    "1.2.840.10008.5.1.4.1.1.77.1.2"                  // V15      
#define UID_VIDEO_MICROSCOPIC_IMAGE_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.77.1.2.1"                // V15      
#define UID_VL_SLIDE_COORDINATES_MICROSCOPIC_IMAGE_STORAGE_CLASS_A                  "1.2.840.10008.5.1.4.1.1.77.1.3"                  // V15      
#define UID_VL_PHOTOGRAPHIC_IMAGE_STORAGE_CLASS_A                                   "1.2.840.10008.5.1.4.1.1.77.1.4"                  // V15      
#define UID_VIDEO_PHOTOGRAPHIC_IMAGE_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.77.1.4.1"                // V15      
#define UID_OPHTHALMIC_8_BIT_PHOTOGRAPHY_IMAGE_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.77.1.5.1"                // V15      
#define UID_OPHTHALMIC_16_BIT_PHOTOGRAPHY_IMAGE_STORAGE_A                           "1.2.840.10008.5.1.4.1.1.77.1.5.2"                // V15      
#define UID_STEREOMETRIC_RELATIONSHIP_STORAGE_A                                     "1.2.840.10008.5.1.4.1.1.77.1.5.3"                // V15      
#define UID_OPHTHALMIC_TOMOGRAPHY_IMAGE_STORAGE_A                                   "1.2.840.10008.5.1.4.1.1.77.1.5.4"                //          
#define UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_STEREOGRAPHIC_PROJECTION_IMAGE_STORAGE_A "1.2.840.10008.5.1.4.1.1.77.1.5.5"                // 2015      
#define UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_3D_COORDINATES_IMAGE_STORAGE_A        "1.2.840.10008.5.1.4.1.1.77.1.5.6"                // 2015      
#define UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE_STORAGE_A         "1.2.840.10008.5.1.4.1.1.77.1.5.7"                // 2021      
#define UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_STORAGE_A "1.2.840.10008.5.1.4.1.1.77.1.5.8"                // 2021      
#define UID_VL_WHOLE_SLIDE_MICROSCOPY_IMAGE_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.77.1.6"                  //          
#define UID_DERMOSCOPIC_PHOTOGRAPHY_IMAGE_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.77.1.7"                  // 2021      
#define UID_VL_MULTIFRAME_IMAGE_STORAGE_RETIRED_A                                   "1.2.840.10008.5.1.4.1.1.77.2"                    // V15      Retired
#define UID_LENSOMETRY_MEASUREMENTS_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.78.1"                    //          
#define UID_AUTOREFRACTION_MEASUREMENTS_STORAGE_A                                   "1.2.840.10008.5.1.4.1.1.78.2"                    //          
#define UID_KERATOMETRY_MEASUREMENTS_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.78.3"                    //          
#define UID_SUBJECTIVE_REFRACTION_MEASUREMENTS_STORAGE_A                            "1.2.840.10008.5.1.4.1.1.78.4"                    //          
#define UID_VISUAL_ACUITY_MEASUREMENTS_STORAGE_A                                    "1.2.840.10008.5.1.4.1.1.78.5"                    //          
#define UID_SPECTACLE_PRESCRIPTION_REPORT_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.78.6"                    //          
#define UID_OPHTHALMIC_AXIAL_MEASUREMENTS_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.78.7"                    //          
#define UID_INTRAOCULAR_LENS_CALCULATIONS_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.78.8"                    //          
#define UID_MACULAR_GRID_THICKNESS_AND_VOLUME_REPORT_STORAGE_A                      "1.2.840.10008.5.1.4.1.1.79.1"                    //          
#define UID_OPHTHALMIC_VISUAL_FIELD_STATIC_PERIMETRY_MEASUREMENTS_STORAGE_A         "1.2.840.10008.5.1.4.1.1.80.1"                    //          
#define UID_OPHTHALMIC_THICKNESS_MAP_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.81.1"                    //          
#define UID_CORNEAL_TOPOGRAPHY_MAP_STORAGE_A                                        "1.2.840.10008.5.1.4.1.1.82.1"                    // 2014      
#define UID_TEXT_SR_STORAGE_TRIAL_RETIRED_A                                         "1.2.840.10008.5.1.4.1.1.88.1"                    //          Retired
#define UID_AUDIO_SR_STORAGE_TRIAL_RETIRED_A                                        "1.2.840.10008.5.1.4.1.1.88.2"                    //          Retired
#define UID_DETAIL_SR_STORAGE_TRIAL_RETIRED_A                                       "1.2.840.10008.5.1.4.1.1.88.3"                    //          Retired
#define UID_COMPREHENSIVE_SR_STORAGE_TRIAL_RETIRED_A                                "1.2.840.10008.5.1.4.1.1.88.4"                    //          Retired
#define UID_BASIC_TEXT_SR_A                                                         "1.2.840.10008.5.1.4.1.1.88.11"                   // V15      
#define UID_ENHANCED_SR_A                                                           "1.2.840.10008.5.1.4.1.1.88.22"                   // V15      
#define UID_COMPREHENSIVE_SR_A                                                      "1.2.840.10008.5.1.4.1.1.88.33"                   // V15      
#define UID_COMPREHENSIVE_3D_SR_STORAGE_A                                           "1.2.840.10008.5.1.4.1.1.88.34"                   // 2014      
#define UID_EXTENSIBLE_SR_STORAGE_A                                                 "1.2.840.10008.5.1.4.1.1.88.35"                   // 2015      
#define UID_PROCEDURE_LOG_STORAGE_A                                                 "1.2.840.10008.5.1.4.1.1.88.40"                   //          
#define UID_MAMMOGRAPHY_CAD_SR_A                                                    "1.2.840.10008.5.1.4.1.1.88.50"                   // V15      
#define UID_KEY_OBJECT_SELECTION_DOCUMENT_A                                         "1.2.840.10008.5.1.4.1.1.88.59"                   // V15      
#define UID_CHEST_CAD_SR_A                                                          "1.2.840.10008.5.1.4.1.1.88.65"                   // V15      
#define UID_X_RAY_RADIATION_DOSE_SR_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.88.67"                   //          
#define UID_RADIOPHARMACEUTICAL_RADIATION_DOSE_SR_STORAGE_A                         "1.2.840.10008.5.1.4.1.1.88.68"                   // 2014      
#define UID_COLON_CAD_SR_STORAGE_A                                                  "1.2.840.10008.5.1.4.1.1.88.69"                   //          
#define UID_IMPLANTATION_PLAN_SR_DOCUMENT_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.88.70"                   //          
#define UID_ACQUISITION_CONTEXT_SR_STORAGE_A                                        "1.2.840.10008.5.1.4.1.1.88.71"                   // 2021      
#define UID_SIMPLIFIED_ADULT_ECHO_SR_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.88.72"                   // 2021      
#define UID_PATIENT_RADIATION_DOSE_SR_STORAGE_A                                     "1.2.840.10008.5.1.4.1.1.88.73"                   // 2021      
#define UID_PLANNED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE_A                       "1.2.840.10008.5.1.4.1.1.88.74"                   // 2021      
#define UID_PERFORMED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE_A                     "1.2.840.10008.5.1.4.1.1.88.75"                   // 2021      
#define UID_ENHANCED_X_RAY_RADIATION_DOSE_SR_STORAGE_A                              "1.2.840.10008.5.1.4.1.1.88.76"                   // 2021b    
#define UID_CONTENT_ASSESSMENT_RESULTS_STORAGE_A                                    "1.2.840.10008.5.1.4.1.1.90.1"                    // 2021      
#define UID_ENCAPSULATED_PDF_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.104.1"                   //          
#define UID_ENCAPSULATED_CDA_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.104.2"                   //          
#define UID_ENCAPSULATED_STL_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.104.3"                   // 2021      
#define UID_ENCAPSULATED_OBJ_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.104.4"                   // 2021      
#define UID_ENCAPSULATED_MTL_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.104.5"                   // 2021      
#define UID_PET_IMAGE_STORAGE_A                                                     "1.2.840.10008.5.1.4.1.1.128"                     // V15      
#define UID_LEGACY_CONVERTED_ENHANCED_PET_IMAGE_STORAGE_A                           "1.2.840.10008.5.1.4.1.1.128.1"                   // 2014      
#define UID_STANDALONE_PET_CURVE_STORAGE_A                                          "1.2.840.10008.5.1.4.1.1.129"                     // V15      Retired
#define UID_ENHANCED_PET_IMAGE_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.130"                     //          
#define UID_BASIC_STRUCTURED_DISPLAY_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.131"                     //          
#define UID_CT_DEFINED_PROCEDURE_PROTOCOL_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.200.1"                   // 2021      
#define UID_CT_PERFORMED_PROCEDURE_PROTOCOL_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.200.2"                   // 2021      
#define UID_PROTOCOL_APPROVAL_STORAGE_A                                             "1.2.840.10008.5.1.4.1.1.200.3"                   // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_FIND_A                              "1.2.840.10008.5.1.4.1.1.200.4"                   // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_MOVE_A                              "1.2.840.10008.5.1.4.1.1.200.5"                   // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_GET_A                               "1.2.840.10008.5.1.4.1.1.200.6"                   // 2021      
#define UID_XA_DEFINED_PROCEDURE_PROTOCOL_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.200.7"                   // 2021      
#define UID_XA_PERFORMED_PROCEDURE_PROTOCOL_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.200.8"                   // 2021      
#define UID_RT_IMAGE_STORAGE_A                                                      "1.2.840.10008.5.1.4.1.1.481.1"                   // V15      
#define UID_RT_DOSE_STORAGE_A                                                       "1.2.840.10008.5.1.4.1.1.481.2"                   // V15      
#define UID_RT_STRUCTURE_STORAGE_A                                                  "1.2.840.10008.5.1.4.1.1.481.3"                   // V15      
#define UID_RT_BEAMS_TREATMENT_RECORD_STORAGE_CLASS_A                               "1.2.840.10008.5.1.4.1.1.481.4"                   // V15      
#define UID_RT_PLAN_STORAGE_A                                                       "1.2.840.10008.5.1.4.1.1.481.5"                   // V15      
#define UID_RT_BRACHY_TREATMENT_RECORD_STORAGE_CLASS_A                              "1.2.840.10008.5.1.4.1.1.481.6"                   // V15      
#define UID_RT_TREATMENT_SUMMARY_RECORD_STORAGE_CLASS_A                             "1.2.840.10008.5.1.4.1.1.481.7"                   // V15      
#define UID_RT_ION_PLAN_STORAGE_A                                                   "1.2.840.10008.5.1.4.1.1.481.8"                   //          
#define UID_RT_ION_BEAMS_TREATMENT_RECORD_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.481.9"                   //          
#define UID_RT_PHYSICIAN_INTENT_STORAGE_A                                           "1.2.840.10008.5.1.4.1.1.481.10"                  // 2021      
#define UID_RT_SEGMENT_ANNOTATION_STORAGE_A                                         "1.2.840.10008.5.1.4.1.1.481.11"                  // 2021      
#define UID_RT_RADIATION_SET_STORAGE_A                                              "1.2.840.10008.5.1.4.1.1.481.12"                  // 2021      
#define UID_C_ARM_PHOTON_ELECTRON_RADIATION_STORAGE_A                               "1.2.840.10008.5.1.4.1.1.481.13"                  // 2021      
#define UID_TOMOTHERAPEUTIC_RADIATION_STORAGE_A                                     "1.2.840.10008.5.1.4.1.1.481.14"                  // 2021      
#define UID_ROBOTIC_ARM_RADIATION_STORAGE_A                                         "1.2.840.10008.5.1.4.1.1.481.15"                  // 2021      
#define UID_RT_RADIATION_RECORD_SET_STORAGE_A                                       "1.2.840.10008.5.1.4.1.1.481.16"                  // 2021      
#define UID_RT_RADIATION_SALVAGE_RECORD_STORAGE_A                                   "1.2.840.10008.5.1.4.1.1.481.17"                  // 2021      
#define UID_TOMOTHERAPEUTIC_RADIATION_RECORD_STORAGE_A                              "1.2.840.10008.5.1.4.1.1.481.18"                  // 2021      
#define UID_C_ARM_PHOTON_ELECTRON_RADIATION_RECORD_STORAGE_A                        "1.2.840.10008.5.1.4.1.1.481.19"                  // 2021      
#define UID_ROBOTIC_RADIATION_RECORD_STORAGE_A                                      "1.2.840.10008.5.1.4.1.1.481.20"                  // 2021      
#define UID_DICOS_CT_IMAGE_STORAGE_A                                                "1.2.840.10008.5.1.4.1.1.501.1"                   //          
#define UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PRESENTATION_A                    "1.2.840.10008.5.1.4.1.1.501.2.1"                 //          
#define UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PROCESSING_A                      "1.2.840.10008.5.1.4.1.1.501.2.2"                 //          
#define UID_DICOS_THREAT_DETECTION_REPORT_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.501.3"                   //          
#define UID_DICOS_2D_AIT_STORAGE_A                                                  "1.2.840.10008.5.1.4.1.1.501.4"                   // 2014      
#define UID_DICOS_3D_AIT_STORAGE_A                                                  "1.2.840.10008.5.1.4.1.1.501.5"                   // 2014      
#define UID_DICOS_QUADRUPOLE_RESONANCE_QR_STORAGE_A                                 "1.2.840.10008.5.1.4.1.1.501.6"                   // 2014      
#define UID_EDDY_CURRENT_IMAGE_STORAGE_A                                            "1.2.840.10008.5.1.4.1.1.601.1"                   //          
#define UID_EDDY_CURRENT_MULTI_FRAME_IMAGE_STORAGE_A                                "1.2.840.10008.5.1.4.1.1.601.2"                   //          
#define UID_PATIENT_ROOT_QUERY_FIND_A                                               "1.2.840.10008.5.1.4.1.2.1.1"                     // V15      
#define UID_PATIENT_ROOT_QUERY_MOVE_A                                               "1.2.840.10008.5.1.4.1.2.1.2"                     // V15      
#define UID_PATIENT_ROOT_QUERY_GET_A                                                "1.2.840.10008.5.1.4.1.2.1.3"                     // V15      
#define UID_STUDY_ROOT_QUERY_FIND_A                                                 "1.2.840.10008.5.1.4.1.2.2.1"                     // V15      
#define UID_STUDY_ROOT_QUERY_MOVE_A                                                 "1.2.840.10008.5.1.4.1.2.2.2"                     // V15      
#define UID_STUDY_ROOT_QUERY_GET_A                                                  "1.2.840.10008.5.1.4.1.2.2.3"                     // V15      
#define UID_PATIENT_STUDY_QUERY_FIND_A                                              "1.2.840.10008.5.1.4.1.2.3.1"                     // V15      Retired
#define UID_PATIENT_STUDY_QUERY_MOVE_A                                              "1.2.840.10008.5.1.4.1.2.3.2"                     // V15      Retired
#define UID_PATIENT_STUDY_QUERY_GET_A                                               "1.2.840.10008.5.1.4.1.2.3.3"                     // V15      Retired
#define UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_MOVE_A                                 "1.2.840.10008.5.1.4.1.2.4.2"                     //          
#define UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_GET_A                                  "1.2.840.10008.5.1.4.1.2.4.3"                     //          
#define UID_COMPOSITE_INSTANCE_RETRIEVE_WITHOUT_BULK_DATA_GET_A                     "1.2.840.10008.5.1.4.1.2.5.3"                     //          
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_FIND_A                     "1.2.840.10008.5.1.4.20.1"                        // 2021      
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_MOVE_A                     "1.2.840.10008.5.1.4.20.2"                        // 2021      
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_GET_A                      "1.2.840.10008.5.1.4.20.3"                        // 2021      
#define UID_MODALITY_WORKLIST_FIND_A                                                "1.2.840.10008.5.1.4.31"                          // V15      
#define UID_GENERAL_PURPOSE_WORKLIST_MANAGEMENT_META_SOP_CLASS_A                    "1.2.840.10008.5.1.4.32"                          // V15      Retired
#define UID_GENERAL_PURPOSE_WORKLIST_FIND_A                                         "1.2.840.10008.5.1.4.32.1"                        // V15      Retired
#define UID_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_SOP_CLASS_A                    "1.2.840.10008.5.1.4.32.2"                        // V15      Retired
#define UID_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_SOP_CLASS_A                    "1.2.840.10008.5.1.4.32.3"                        // V15      Retired
#define UID_INSTANCE_AVAILABILITY_NOTIFICATION_A                                    "1.2.840.10008.5.1.4.33"                          //          
#define UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE_TRIAL_RETIRED_A                   "1.2.840.10008.5.1.4.34.1"                        //          Retired
#define UID_RT_CONVENTIONAL_MACHINE_VERIFICATION_TRIAL_RETIRED_A                    "1.2.840.10008.5.1.4.34.2"                        //          Retired
#define UID_RT_ION_MACHINE_VERIFICATION_TRIAL_RETIRED_A                             "1.2.840.10008.5.1.4.34.3"                        //          Retired
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS_TRIAL_RETIRED_A       "1.2.840.10008.5.1.4.34.4"                        //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_PUSH_TRIAL_RETIRED_A                             "1.2.840.10008.5.1.4.34.4.1"                      //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_WATCH_TRIAL_RETIRED_A                            "1.2.840.10008.5.1.4.34.4.2"                      //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_PULL_TRIAL_RETIRED_A                             "1.2.840.10008.5.1.4.34.4.3"                      //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_EVENT_TRIAL_RETIRED_A                            "1.2.840.10008.5.1.4.34.4.4"                      //          Retired
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SOP_INSTANCE_A                      "1.2.840.10008.5.1.4.34.5"                        //          
#define UID_UPS_FILTERED_GLOBAL_SUBSCRIPTION_SOP_INSTANCE_A                         "1.2.840.10008.5.1.4.34.5.1"                      // 2015      
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS_A                     "1.2.840.10008.5.1.4.34.6"                        //          
#define UID_UNIFIED_PROCEDURE_STEP_PUSH_A                                           "1.2.840.10008.5.1.4.34.6.1"                      //          
#define UID_UNIFIED_PROCEDURE_STEP_WATCH_A                                          "1.2.840.10008.5.1.4.34.6.2"                      //          
#define UID_UNIFIED_PROCEDURE_STEP_PULL_A                                           "1.2.840.10008.5.1.4.34.6.3"                      //          
#define UID_UNIFIED_PROCEDURE_STEP_EVENT_A                                          "1.2.840.10008.5.1.4.34.6.4"                      //          
#define UID_UNIFIED_PROCEDURE_STEP_QUERY_A                                          "1.2.840.10008.5.1.4.34.6.5"                      // 2021      
#define UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE_A                                 "1.2.840.10008.5.1.4.34.7"                        //          
#define UID_RT_CONVENTIONAL_MACHINE_VERIFICATION_A                                  "1.2.840.10008.5.1.4.34.8"                        //          
#define UID_RT_ION_MACHINE_VERIFICATION_A                                           "1.2.840.10008.5.1.4.34.9"                        //          
#define UID_RT_BRACHY_APPLICATION_SETUP_DELIVERY_INSTRUCTION_STORAGE_A              "1.2.840.10008.5.1.4.34.10"                       // 2021      
#define UID_GENERAL_RELEVANT_PATIENT_INFORMATION_QUERY_A                            "1.2.840.10008.5.1.4.37.1"                        //          
#define UID_BREAST_IMAGING_RELEVANT_PATIENT_INFORMATION_QUERY_A                     "1.2.840.10008.5.1.4.37.2"                        //          
#define UID_CARDIAC_RELEVANT_PATIENT_INFORMATION_QUERY_A                            "1.2.840.10008.5.1.4.37.3"                        //          
#define UID_HANGING_PROTOCOL_STORAGE_A                                              "1.2.840.10008.5.1.4.38.1"                        //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_FIND_A                               "1.2.840.10008.5.1.4.38.2"                        //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_MOVE_A                               "1.2.840.10008.5.1.4.38.3"                        //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_GET_A                                "1.2.840.10008.5.1.4.38.4"                        //          
#define UID_COLOR_PALETTE_STORAGE_A                                                 "1.2.840.10008.5.1.4.39.1"                        //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_FIND_A                                  "1.2.840.10008.5.1.4.39.2"                        //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_MOVE_A                                  "1.2.840.10008.5.1.4.39.3"                        //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_GET_A                                   "1.2.840.10008.5.1.4.39.4"                        //          
#define UID_PRODUCT_CHARACTERISTICS_QUERY_A                                         "1.2.840.10008.5.1.4.41"                          //          
#define UID_SUBSTANCE_APPROVAL_QUERY_A                                              "1.2.840.10008.5.1.4.42"                          //          
#define UID_GENERIC_IMPLANT_TEMPLATE_STORAGE_A                                      "1.2.840.10008.5.1.4.43.1"                        //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_FIND_A                       "1.2.840.10008.5.1.4.43.2"                        //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_MOVE_A                       "1.2.840.10008.5.1.4.43.3"                        //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_GET_A                        "1.2.840.10008.5.1.4.43.4"                        //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_STORAGE_A                                     "1.2.840.10008.5.1.4.44.1"                        //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_FIND_A                      "1.2.840.10008.5.1.4.44.2"                        //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_MOVE_A                      "1.2.840.10008.5.1.4.44.3"                        //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_GET_A                       "1.2.840.10008.5.1.4.44.4"                        //          
#define UID_IMPLANT_TEMPLATE_GROUP_STORAGE_A                                        "1.2.840.10008.5.1.4.45.1"                        //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_FIND_A                         "1.2.840.10008.5.1.4.45.2"                        //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_MOVE_A                         "1.2.840.10008.5.1.4.45.3"                        //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_GET_A                          "1.2.840.10008.5.1.4.45.4"                        //          
#define UID_NATIVE_DICOM_MODEL_A                                                    "1.2.840.10008.7.1.1"                             //          
#define UID_ABSTRACT_MULTI_DIMENSIONAL_IMAGE_MODEL_A                                "1.2.840.10008.7.1.2"                             //          
#define UID_DICOM_CONTENT_MAPPING_RESOURCE_A                                        "1.2.840.10008.8.1.1"                             // 2015      
#define UID_VIDEO_ENDOSCOPIC_IMAGE_REAL_TIME_COMMUNICATION_A                        "1.2.840.10008.10.1"                              // 2021      
#define UID_VIDEO_PHOTOGRAPHIC_IMAGE_REAL_TIME_COMMUNICATION_A                      "1.2.840.10008.10.2"                              // 2021      
#define UID_AUDIO_WAVEFORM_REAL_TIME_COMMUNICATION_A                                "1.2.840.10008.10.3"                              // 2021      
#define UID_RENDITION_SELECTION_DOCUMENT_REAL_TIME_COMMUNICATION_A                  "1.2.840.10008.10.4"                              // 2021      
#define UID_DICOM_DEVICE_NAME_A                                                     "1.2.840.10008.15.0.3.1"                          //          
#define UID_DICOM_DESCRIPTION_A                                                     "1.2.840.10008.15.0.3.2"                          //          
#define UID_DICOM_MANUFACTURER_A                                                    "1.2.840.10008.15.0.3.3"                          //          
#define UID_DICOM_MANUFACTURER_MODEL_NAME_A                                         "1.2.840.10008.15.0.3.4"                          //          
#define UID_DICOM_SOFTWARE_VERSION_A                                                "1.2.840.10008.15.0.3.5"                          //          
#define UID_DICOM_VENDOR_DATA_A                                                     "1.2.840.10008.15.0.3.6"                          //          
#define UID_DICOM_AE_TITLE_A                                                        "1.2.840.10008.15.0.3.7"                          //          
#define UID_DICOM_NETWORK_CONNECTION_REFERENCE_A                                    "1.2.840.10008.15.0.3.8"                          //          
#define UID_DICOM_APPLICATION_CLUSTER_A                                             "1.2.840.10008.15.0.3.9"                          //          
#define UID_DICOM_ASSOCIATION_INITIATOR_A                                           "1.2.840.10008.15.0.3.10"                         //          
#define UID_DICOM_ASSOCIATION_ACCEPTOR_A                                            "1.2.840.10008.15.0.3.11"                         //          
#define UID_DICOM_HOSTNAME_A                                                        "1.2.840.10008.15.0.3.12"                         //          
#define UID_DICOM_PORT_A                                                            "1.2.840.10008.15.0.3.13"                         //          
#define UID_DICOM_A                                                                 "1.2.840.10008.15.0.3.14"                         //          
#define UID_DICOM_TRANSFER_ROLE_A                                                   "1.2.840.10008.15.0.3.15"                         //          
#define UID_DICOM_TRANSFER_SYNTAX_A                                                 "1.2.840.10008.15.0.3.16"                         //          
#define UID_DICOM_PRIMARY_DEVICE_TYPE_A                                             "1.2.840.10008.15.0.3.17"                         //          
#define UID_DICOM_RELATED_DEVICE_REFERENCE_A                                        "1.2.840.10008.15.0.3.18"                         //          
#define UID_DICOM_PREFERRED_CALLED_AE_TITLE_A                                       "1.2.840.10008.15.0.3.19"                         //          
#define UID_DICOM_TLS_CYPHERSUITE_A                                                 "1.2.840.10008.15.0.3.20"                         //          
#define UID_DICOM_AUTHORIZED_NODE_CERTIFICATE_REFERENCE_A                           "1.2.840.10008.15.0.3.21"                         //          
#define UID_DICOM_THIS_NODE_CERTIFICATE_REFERENCE_A                                 "1.2.840.10008.15.0.3.22"                         //          
#define UID_DICOM_INSTALLED_A                                                       "1.2.840.10008.15.0.3.23"                         //          
#define UID_DICOM_STATION_NAME_A                                                    "1.2.840.10008.15.0.3.24"                         //          
#define UID_DICOM_DEVICE_SERIAL_NUMBER_A                                            "1.2.840.10008.15.0.3.25"                         //          
#define UID_DICOM_INSTITUTION_NAME_A                                                "1.2.840.10008.15.0.3.26"                         //          
#define UID_DICOM_INSTITUTION_ADDRESS_A                                             "1.2.840.10008.15.0.3.27"                         //          
#define UID_DICOM_INSTITUTION_DEPARTMENT_NAME_A                                     "1.2.840.10008.15.0.3.28"                         //          
#define UID_DICOM_ISSUER_OF_PATIENT_ID_A                                            "1.2.840.10008.15.0.3.29"                         //          
#define UID_DICOM_PREFERRED_CALLING_AE_TITLE_A                                      "1.2.840.10008.15.0.3.30"                         //          
#define UID_DICOM_SUPPORTED_CHARACTER_SET_A                                         "1.2.840.10008.15.0.3.31"                         //          
#define UID_DICOM_CONFIGURATION_ROOT_A                                              "1.2.840.10008.15.0.4.1"                          //          
#define UID_DICOM_DEVICES_ROOT_A                                                    "1.2.840.10008.15.0.4.2"                          //          
#define UID_DICOM_UNIQUE_AE_TITLES_REGISTRY_ROOT_A                                  "1.2.840.10008.15.0.4.3"                          //          
#define UID_DICOM_DEVICE_A                                                          "1.2.840.10008.15.0.4.4"                          //          
#define UID_DICOM_NETWORK_AE_A                                                      "1.2.840.10008.15.0.4.5"                          //          
#define UID_DICOM_NETWORK_CONNECTION_A                                              "1.2.840.10008.15.0.4.6"                          //          
#define UID_DICOM_UNIQUE_AE_TITLE_A                                                 "1.2.840.10008.15.0.4.7"                          //          
#define UID_DICOM_TRANSFER_CAPABILITY_A                                             "1.2.840.10008.15.0.4.8"                          //          
#define UID_UNIVERSAL_COORDINATED_TIME_A                                            "1.2.840.10008.15.1.1"                            //          
#define UID_GE_MR_IMAGE_A                                                           "1.2.840.113619.4.2"                              // V15      
#define UID_GE_CT_IMAGE_A                                                           "1.2.840.113619.4.3"                              // V15      
#define UID_GE_DISPLAY_IMAGERMATION_A                                               "1.2.840.113619.4.4"                              // V15      
#define UID_GE_ARM_MIGRATION_A                                                      "1.2.840.113619.4.10"                             // V15      
#define UID_GE_ARM_MIGRATION_INSTANCE_A                                             "1.2.840.113619.7.2"                              // V15      

// UNICODE defines
#define UID_VERIFICATION_CLASS                                                      L_TEXT(UID_VERIFICATION_CLASS_A)                                                // V15      
#define UID_IMPLICIT_VR_LITTLE_ENDIAN                                               L_TEXT(UID_IMPLICIT_VR_LITTLE_ENDIAN_A)                                         // V15      
#define UID_EXPLICIT_VR_LITTLE_ENDIAN                                               L_TEXT(UID_EXPLICIT_VR_LITTLE_ENDIAN_A)                                         // V15      
#define UID_DEFLATED_EXPLICIT_VR_LITTLE_ENDIAN                                      L_TEXT(UID_DEFLATED_EXPLICIT_VR_LITTLE_ENDIAN_A)                                // V15      
#define UID_EXPLICIT_VR_BIG_ENDIAN                                                  L_TEXT(UID_EXPLICIT_VR_BIG_ENDIAN_A)                                            // V15      Retired
#define UID_JPEG_BASELINE_1                                                         L_TEXT(UID_JPEG_BASELINE_1_A)                                                   // V15      
#define UID_JPEG_EXTENDED_2_4                                                       L_TEXT(UID_JPEG_EXTENDED_2_4_A)                                                 // V15      
#define UID_JPEG_EXTENDED_3_5                                                       L_TEXT(UID_JPEG_EXTENDED_3_5_A)                                                 // V15      Retired
#define UID_JPEG_SPECTRAL_NONHIER_6_8                                               L_TEXT(UID_JPEG_SPECTRAL_NONHIER_6_8_A)                                         // V15      Retired
#define UID_JPEG_SPECTRAL_NONHIER_7_9                                               L_TEXT(UID_JPEG_SPECTRAL_NONHIER_7_9_A)                                         // V15      Retired
#define UID_JPEG_FULL_NONHIER_10_12                                                 L_TEXT(UID_JPEG_FULL_NONHIER_10_12_A)                                           // V15      Retired
#define UID_JPEG_FULL_NONHIER_11_13                                                 L_TEXT(UID_JPEG_FULL_NONHIER_11_13_A)                                           // V15      Retired
#define UID_JPEG_LOSSLESS_NONHIER_14                                                L_TEXT(UID_JPEG_LOSSLESS_NONHIER_14_A)                                          // V15      
#define UID_JPEG_LOSSLESS_NONHIER_15                                                L_TEXT(UID_JPEG_LOSSLESS_NONHIER_15_A)                                          // V15      Retired
#define UID_JPEG_EXTENDED_HIER_16_18                                                L_TEXT(UID_JPEG_EXTENDED_HIER_16_18_A)                                          // V15      Retired
#define UID_JPEG_EXTENDED_HIER_17_19                                                L_TEXT(UID_JPEG_EXTENDED_HIER_17_19_A)                                          // V15      Retired
#define UID_JPEG_SPECTRAL_HIER_20_22                                                L_TEXT(UID_JPEG_SPECTRAL_HIER_20_22_A)                                          // V15      Retired
#define UID_JPEG_SPECTRAL_HIER_21_23                                                L_TEXT(UID_JPEG_SPECTRAL_HIER_21_23_A)                                          // V15      Retired
#define UID_JPEG_FULL_HIER_24_26                                                    L_TEXT(UID_JPEG_FULL_HIER_24_26_A)                                              // V15      Retired
#define UID_JPEG_FULL_HIER_25_27                                                    L_TEXT(UID_JPEG_FULL_HIER_25_27_A)                                              // V15      Retired
#define UID_JPEG_LOSSLESS_HIER_PROCESS_28                                           L_TEXT(UID_JPEG_LOSSLESS_HIER_PROCESS_28_A)                                     // V15      Retired
#define UID_JPEG_LOSSLESS_HIER_PROCESS_29                                           L_TEXT(UID_JPEG_LOSSLESS_HIER_PROCESS_29_A)                                     // V15      Retired
#define UID_JPEG_LOSSLESS_NONHIER_14B                                               L_TEXT(UID_JPEG_LOSSLESS_NONHIER_14B_A)                                         // V15      
#define UID_JPEG_LS_LOSSLESS                                                        L_TEXT(UID_JPEG_LS_LOSSLESS_A)                                                  // V15      
#define UID_JPEG_LS_LOSSY                                                           L_TEXT(UID_JPEG_LS_LOSSY_A)                                                     // V15      
#define UID_JPEG2000_LOSSLESS_ONLY                                                  L_TEXT(UID_JPEG2000_LOSSLESS_ONLY_A)                                            // V15      
#define UID_JPEG2000                                                                L_TEXT(UID_JPEG2000_A)                                                          // V15      
#define UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_LOSSLESS_ONLY        L_TEXT(UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_LOSSLESS_ONLY_A)  //          
#define UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION                      L_TEXT(UID_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_A)                //          
#define UID_JPIP_REFERENCED                                                         L_TEXT(UID_JPIP_REFERENCED_A)                                                   //          
#define UID_JPIP_REFERENCED_DEFLATE                                                 L_TEXT(UID_JPIP_REFERENCED_DEFLATE_A)                                           //          
#define UID_MPEG2_MAIN_PROFILE_MAIN_LEVEL                                           L_TEXT(UID_MPEG2_MAIN_PROFILE_MAIN_LEVEL_A)                                     // V15      
#define UID_MPEG2_MAIN_PROFILE_HIGH_LEVEL                                           L_TEXT(UID_MPEG2_MAIN_PROFILE_HIGH_LEVEL_A)                                     //          
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_1                                 L_TEXT(UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_1_A)                           //          
#define UID_MPEG_4_AVC_H_264_BD_COMPATIBLE_HIGH_PROFILE_LEVEL_4_1                   L_TEXT(UID_MPEG_4_AVC_H_264_BD_COMPATIBLE_HIGH_PROFILE_LEVEL_4_1_A)             //          
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_2D_VIDEO                    L_TEXT(UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_2D_VIDEO_A)              // 2015      
#define UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_3D_VIDEO                    L_TEXT(UID_MPEG_4_AVC_H_264_HIGH_PROFILE_LEVEL_4_2_FOR_3D_VIDEO_A)              // 2015      
#define UID_MPEG_4_AVC_H_264_STEREO_HIGH_PROFILE_LEVEL_4_2                          L_TEXT(UID_MPEG_4_AVC_H_264_STEREO_HIGH_PROFILE_LEVEL_4_2_A)                    // 2015      
#define UID_HEVC_H_265_MAIN_PROFILE_LEVEL_5_1                                       L_TEXT(UID_HEVC_H_265_MAIN_PROFILE_LEVEL_5_1_A)                                 // 2020      
#define UID_HEVC_H_265_MAIN_10_PROFILE_LEVEL_5_1                                    L_TEXT(UID_HEVC_H_265_MAIN_10_PROFILE_LEVEL_5_1_A)                              // 2020      
#define UID_RLE_LOSSLESS                                                            L_TEXT(UID_RLE_LOSSLESS_A)                                                      // V15      
#define UID_RFC_2557_MIME_ENCAPSULATION                                             L_TEXT(UID_RFC_2557_MIME_ENCAPSULATION_A)                                       //          Retired
#define UID_XML_ENCODING                                                            L_TEXT(UID_XML_ENCODING_A)                                                      //          Retired
#define UID_SMPTE_ST_2110_20_UNCOMPRESSED_PROGRESSIVE_ACTIVE_VIDEO                  L_TEXT(UID_SMPTE_ST_2110_20_UNCOMPRESSED_PROGRESSIVE_ACTIVE_VIDEO_A)            // 2021      
#define UID_SMPTE_ST_2110_20_UNCOMPRESSED_INTERLACED_ACTIVE_VIDEO                   L_TEXT(UID_SMPTE_ST_2110_20_UNCOMPRESSED_INTERLACED_ACTIVE_VIDEO_A)             // 2021      
#define UID_SMPTE_ST_2110_30_PCM_DIGITAL_AUDIO                                      L_TEXT(UID_SMPTE_ST_2110_30_PCM_DIGITAL_AUDIO_A)                                // 2021      
#define UID_MEDIA_STORAGE_DIRECTORY                                                 L_TEXT(UID_MEDIA_STORAGE_DIRECTORY_A)                                           // V15      
#define UID_TALAIRACH_BRAIN_ATLAS_FRAME_OF_REFERENCE                                L_TEXT(UID_TALAIRACH_BRAIN_ATLAS_FRAME_OF_REFERENCE_A)                          //          
#define UID_SPM2_T1_FRAME_OF_REFERENCE                                              L_TEXT(UID_SPM2_T1_FRAME_OF_REFERENCE_A)                                        //          
#define UID_SPM2_T2_FRAME_OF_REFERENCE                                              L_TEXT(UID_SPM2_T2_FRAME_OF_REFERENCE_A)                                        //          
#define UID_SPM2_PD_FRAME_OF_REFERENCE                                              L_TEXT(UID_SPM2_PD_FRAME_OF_REFERENCE_A)                                        //          
#define UID_SPM2_EPI_FRAME_OF_REFERENCE                                             L_TEXT(UID_SPM2_EPI_FRAME_OF_REFERENCE_A)                                       //          
#define UID_SPM2_FIL_T1_FRAME_OF_REFERENCE                                          L_TEXT(UID_SPM2_FIL_T1_FRAME_OF_REFERENCE_A)                                    //          
#define UID_SPM2_PET_FRAME_OF_REFERENCE                                             L_TEXT(UID_SPM2_PET_FRAME_OF_REFERENCE_A)                                       //          
#define UID_SPM2_TRANSM_FRAME_OF_REFERENCE                                          L_TEXT(UID_SPM2_TRANSM_FRAME_OF_REFERENCE_A)                                    //          
#define UID_SPM2_SPECT_FRAME_OF_REFERENCE                                           L_TEXT(UID_SPM2_SPECT_FRAME_OF_REFERENCE_A)                                     //          
#define UID_SPM2_GRAY_FRAME_OF_REFERENCE                                            L_TEXT(UID_SPM2_GRAY_FRAME_OF_REFERENCE_A)                                      //          
#define UID_SPM2_WHITE_FRAME_OF_REFERENCE                                           L_TEXT(UID_SPM2_WHITE_FRAME_OF_REFERENCE_A)                                     //          
#define UID_SPM2_CSF_FRAME_OF_REFERENCE                                             L_TEXT(UID_SPM2_CSF_FRAME_OF_REFERENCE_A)                                       //          
#define UID_SPM2_BRAINMASK_FRAME_OF_REFERENCE                                       L_TEXT(UID_SPM2_BRAINMASK_FRAME_OF_REFERENCE_A)                                 //          
#define UID_SPM2_AVG305T1_FRAME_OF_REFERENCE                                        L_TEXT(UID_SPM2_AVG305T1_FRAME_OF_REFERENCE_A)                                  //          
#define UID_SPM2_AVG152T1_FRAME_OF_REFERENCE                                        L_TEXT(UID_SPM2_AVG152T1_FRAME_OF_REFERENCE_A)                                  //          
#define UID_SPM2_AVG152T2_FRAME_OF_REFERENCE                                        L_TEXT(UID_SPM2_AVG152T2_FRAME_OF_REFERENCE_A)                                  //          
#define UID_SPM2_AVG152PD_FRAME_OF_REFERENCE                                        L_TEXT(UID_SPM2_AVG152PD_FRAME_OF_REFERENCE_A)                                  //          
#define UID_SPM2_SINGLESUBJT1_FRAME_OF_REFERENCE                                    L_TEXT(UID_SPM2_SINGLESUBJT1_FRAME_OF_REFERENCE_A)                              //          
#define UID_ICBM_452_T1_FRAME_OF_REFERENCE                                          L_TEXT(UID_ICBM_452_T1_FRAME_OF_REFERENCE_A)                                    //          
#define UID_ICBM_SINGLE_SUBJECT_MRI_FRAME_OF_REFERENCE                              L_TEXT(UID_ICBM_SINGLE_SUBJECT_MRI_FRAME_OF_REFERENCE_A)                        //          
#define UID_IEC_61217_FIXED_COORDINATE_SYSTEM_FRAME_OF_REFERENCE                    L_TEXT(UID_IEC_61217_FIXED_COORDINATE_SYSTEM_FRAME_OF_REFERENCE_A)              // 2021      
#define UID_STANDARD_ROBOTIC_ARM_COORDINATE_SYSTEM_FRAME_OF_REFERENCE               L_TEXT(UID_STANDARD_ROBOTIC_ARM_COORDINATE_SYSTEM_FRAME_OF_REFERENCE_A)         // 2021      
#define UID_SRI24_FRAME_OF_REFERENCE                                                L_TEXT(UID_SRI24_FRAME_OF_REFERENCE_A)                                          // 2021      
#define UID_COLIN27_FRAME_OF_REFERENCE                                              L_TEXT(UID_COLIN27_FRAME_OF_REFERENCE_A)                                        // 2021      
#define UID_LPBA40_AIR_FRAME_OF_REFERENCE                                           L_TEXT(UID_LPBA40_AIR_FRAME_OF_REFERENCE_A)                                     // 2021      
#define UID_LPBA40_FLIRT_FRAME_OF_REFERENCE                                         L_TEXT(UID_LPBA40_FLIRT_FRAME_OF_REFERENCE_A)                                   // 2021      
#define UID_LPBA40_SPM5_FRAME_OF_REFERENCE                                          L_TEXT(UID_LPBA40_SPM5_FRAME_OF_REFERENCE_A)                                    // 2021      
#define UID_HOT_IRON_COLOR_PALETTE_SOP_INSTANCE                                     L_TEXT(UID_HOT_IRON_COLOR_PALETTE_SOP_INSTANCE_A)                               //          
#define UID_PET_COLOR_PALETTE_SOP_INSTANCE                                          L_TEXT(UID_PET_COLOR_PALETTE_SOP_INSTANCE_A)                                    //          
#define UID_HOT_METAL_BLUE_COLOR_PALETTE_SOP_INSTANCE                               L_TEXT(UID_HOT_METAL_BLUE_COLOR_PALETTE_SOP_INSTANCE_A)                         //          
#define UID_PET_20_STEP_COLOR_PALETTE_SOP_INSTANCE                                  L_TEXT(UID_PET_20_STEP_COLOR_PALETTE_SOP_INSTANCE_A)                            //          
#define UID_SPRING_COLOR_PALETTE_SOP_INSTANCE                                       L_TEXT(UID_SPRING_COLOR_PALETTE_SOP_INSTANCE_A)                                 // 2021      
#define UID_SUMMER_COLOR_PALETTE_SOP_INSTANCE                                       L_TEXT(UID_SUMMER_COLOR_PALETTE_SOP_INSTANCE_A)                                 // 2021      
#define UID_FALL_COLOR_PALETTE_SOP_INSTANCE                                         L_TEXT(UID_FALL_COLOR_PALETTE_SOP_INSTANCE_A)                                   // 2021      
#define UID_WINTER_COLOR_PALETTE_SOP_INSTANCE                                       L_TEXT(UID_WINTER_COLOR_PALETTE_SOP_INSTANCE_A)                                 // 2021      
#define UID_BASIC_STUDY_NOTIFICATION_CLASS                                          L_TEXT(UID_BASIC_STUDY_NOTIFICATION_CLASS_A)                                    // V15      Retired
#define UID_PAPYRUS_3_IMPLICIT_VR_LITTLE_ENDIAN                                     L_TEXT(UID_PAPYRUS_3_IMPLICIT_VR_LITTLE_ENDIAN_A)                               // V15      Retired
#define UID_STORAGE_COMMITMENT_PUSH_MODEL_CLASS                                     L_TEXT(UID_STORAGE_COMMITMENT_PUSH_MODEL_CLASS_A)                               // V15      
#define UID_STORAGE_COMMITMENT_PUSH_MODEL_INSTANCE                                  L_TEXT(UID_STORAGE_COMMITMENT_PUSH_MODEL_INSTANCE_A)                            // V15      
#define UID_STORAGE_COMMITMENT_PULL_MODEL_CLASS                                     L_TEXT(UID_STORAGE_COMMITMENT_PULL_MODEL_CLASS_A)                               // V15      Retired
#define UID_STORAGE_COMMITMENT_PULL_MODEL_INSTANCE                                  L_TEXT(UID_STORAGE_COMMITMENT_PULL_MODEL_INSTANCE_A)                            // V15      Retired
#define UID_PROCEDURAL_EVENT_LOGGING                                                L_TEXT(UID_PROCEDURAL_EVENT_LOGGING_A)                                          //          
#define UID_PROCEDURAL_EVENT_LOGGING_SOP_INSTANCE                                   L_TEXT(UID_PROCEDURAL_EVENT_LOGGING_SOP_INSTANCE_A)                             //          
#define UID_SUBSTANCE_ADMINISTRATION_LOGGING                                        L_TEXT(UID_SUBSTANCE_ADMINISTRATION_LOGGING_A)                                  //          
#define UID_SUBSTANCE_ADMINISTRATION_LOGGING_SOP_INSTANCE                           L_TEXT(UID_SUBSTANCE_ADMINISTRATION_LOGGING_SOP_INSTANCE_A)                     //          
#define UID_DICOM_REGISTRY                                                          L_TEXT(UID_DICOM_REGISTRY_A)                                                    //          
#define UID_DICOM_CONTROLLED_TERMINOLOGY                                            L_TEXT(UID_DICOM_CONTROLLED_TERMINOLOGY_A)                                      // V15      
#define UID_ADULT_MOUSE_ANATOMY_ONTOLOGY                                            L_TEXT(UID_ADULT_MOUSE_ANATOMY_ONTOLOGY_A)                                      // 2021      
#define UID_UBERON_ONTOLOGY                                                         L_TEXT(UID_UBERON_ONTOLOGY_A)                                                   // 2021      
#define UID_INTEGRATED_TAXONOMIC_INFORMATION_SYSTEM_TAXONOMIC_SERIAL_NUMBER         L_TEXT(UID_INTEGRATED_TAXONOMIC_INFORMATION_SYSTEM_TAXONOMIC_SERIAL_NUMBER_A)   // 2021      
#define UID_MOUSE_GENOME_INITIATIVE_MGI                                             L_TEXT(UID_MOUSE_GENOME_INITIATIVE_MGI_A)                                       // 2021      
#define UID_PUBCHEM_COMPOUND_CID                                                    L_TEXT(UID_PUBCHEM_COMPOUND_CID_A)                                              // 2021      
#define UID_DUBLIN_CORE                                                             L_TEXT(UID_DUBLIN_CORE_A)                                                       // 2021      
#define UID_NEW_YORK_UNIVERSITY_MELANOMA_CLINICAL_COOPERATIVE_GROUP                 L_TEXT(UID_NEW_YORK_UNIVERSITY_MELANOMA_CLINICAL_COOPERATIVE_GROUP_A)           // 2021      
#define UID_MAYO_CLINIC_NON_RADIOLOGICAL_IMAGES_SPECIFIC_BODY_STRUCTURE_ANATOMICAL_SURFACE_REGION_GUIDE L_TEXT(UID_MAYO_CLINIC_NON_RADIOLOGICAL_IMAGES_SPECIFIC_BODY_STRUCTURE_ANATOMICAL_SURFACE_REGION_GUIDE_A)// 2021      
#define UID_IMAGE_BIOMARKER_STANDARDISATION_INITIATIVE                              L_TEXT(UID_IMAGE_BIOMARKER_STANDARDISATION_INITIATIVE_A)                        // 2021      
#define UID_RADIOMICS_ONTOLOGY                                                      L_TEXT(UID_RADIOMICS_ONTOLOGY_A)                                                // 2021      
#define UID_RADELEMENT                                                              L_TEXT(UID_RADELEMENT_A)                                                        // 2021      
#define UID_ICD_11                                                                  L_TEXT(UID_ICD_11_A)                                                            // 2021      
#define UID_APPLICATION_CONTEXT_NAME                                                L_TEXT(UID_APPLICATION_CONTEXT_NAME_A)                                          // V15      
#define UID_DETACHED_PATIENT_CLASS                                                  L_TEXT(UID_DETACHED_PATIENT_CLASS_A)                                            // V15      Retired
#define UID_DETACHED_PATIENT_META_CLASS                                             L_TEXT(UID_DETACHED_PATIENT_META_CLASS_A)                                       // V15      Retired
#define UID_DETACHED_VISIT_CLASS                                                    L_TEXT(UID_DETACHED_VISIT_CLASS_A)                                              // V15      Retired
#define UID_DETACHED_STUDY_CLASS                                                    L_TEXT(UID_DETACHED_STUDY_CLASS_A)                                              // V15      Retired
#define UID_STUDY_COMPONENT_CLASS                                                   L_TEXT(UID_STUDY_COMPONENT_CLASS_A)                                             // V15      Retired
#define UID_MODALITY_PERFORMED_CLASS                                                L_TEXT(UID_MODALITY_PERFORMED_CLASS_A)                                          // V15      
#define UID_MODALITY_PERFORMED_RETRIEVE_CLASS                                       L_TEXT(UID_MODALITY_PERFORMED_RETRIEVE_CLASS_A)                                 // V15      
#define UID_MODALITY_PERFORMED_NOTIFICATION_CLASS                                   L_TEXT(UID_MODALITY_PERFORMED_NOTIFICATION_CLASS_A)                             // V15      
#define UID_DETACHED_RESULTS_CLASS                                                  L_TEXT(UID_DETACHED_RESULTS_CLASS_A)                                            // V15      Retired
#define UID_DETACHED_RESULTS_META_CLASS                                             L_TEXT(UID_DETACHED_RESULTS_META_CLASS_A)                                       // V15      Retired
#define UID_DETACHED_STUDY_META_CLASS                                               L_TEXT(UID_DETACHED_STUDY_META_CLASS_A)                                         // V15      Retired
#define UID_DETACHED_INTERPRETATION_CLASS                                           L_TEXT(UID_DETACHED_INTERPRETATION_CLASS_A)                                     // V15      Retired
#define UID_STORAGE_SERVICE_CLASS                                                   L_TEXT(UID_STORAGE_SERVICE_CLASS_A)                                             //          
#define UID_BASIC_FILM_SESSION_CLASS                                                L_TEXT(UID_BASIC_FILM_SESSION_CLASS_A)                                          // V15      
#define UID_BASIC_FILM_BOX_CLASS                                                    L_TEXT(UID_BASIC_FILM_BOX_CLASS_A)                                              // V15      
#define UID_BASIC_GRAYSCALE_IMAGE_BOX_CLASS                                         L_TEXT(UID_BASIC_GRAYSCALE_IMAGE_BOX_CLASS_A)                                   // V15      
#define UID_BASIC_COLOR_IMAGE_BOX_CLASS                                             L_TEXT(UID_BASIC_COLOR_IMAGE_BOX_CLASS_A)                                       // V15      
#define UID_REFERENCED_IMAGE_BOX_CLASS_RETIRED                                      L_TEXT(UID_REFERENCED_IMAGE_BOX_CLASS_RETIRED_A)                                // V15      Retired
#define UID_BASIC_GRAYSCALE_PRINT_META_CLASS                                        L_TEXT(UID_BASIC_GRAYSCALE_PRINT_META_CLASS_A)                                  // V15      
#define UID_REFERENCED_GRAYSCALE_PRINT_META_CLASS_RETIRED                           L_TEXT(UID_REFERENCED_GRAYSCALE_PRINT_META_CLASS_RETIRED_A)                     // V15      Retired
#define UID_PRINT_JOB_CLASS                                                         L_TEXT(UID_PRINT_JOB_CLASS_A)                                                   // V15      
#define UID_BASIC_ANNOTATION_BOX_CLASS                                              L_TEXT(UID_BASIC_ANNOTATION_BOX_CLASS_A)                                        // V15      
#define UID_PRINTER_CLASS                                                           L_TEXT(UID_PRINTER_CLASS_A)                                                     // V15      
#define UID_PRINTER_CONFIGURATION_RETRIEVAL_CLASS                                   L_TEXT(UID_PRINTER_CONFIGURATION_RETRIEVAL_CLASS_A)                             // V15      
#define UID_PRINTER_INSTANCE                                                        L_TEXT(UID_PRINTER_INSTANCE_A)                                                  // V15      
#define UID_PRINTER_CONFIGURATION_RETRIEVAL_INSTANCE                                L_TEXT(UID_PRINTER_CONFIGURATION_RETRIEVAL_INSTANCE_A)                          // V15      
#define UID_BASIC_COLOR_PRINT_META_CLASS                                            L_TEXT(UID_BASIC_COLOR_PRINT_META_CLASS_A)                                      // V15      
#define UID_REFERENCED_COLOR_PRINT_META_CLASS_RETIRED                               L_TEXT(UID_REFERENCED_COLOR_PRINT_META_CLASS_RETIRED_A)                         // V15      Retired
#define UID_VOI_LUT_BOX_CLASS_RETIRED                                               L_TEXT(UID_VOI_LUT_BOX_CLASS_RETIRED_A)                                         // V15      
#define UID_PRESENTATION_LUT_CLASS                                                  L_TEXT(UID_PRESENTATION_LUT_CLASS_A)                                            // V15      
#define UID_IMAGE_OVERLAY_BOX_CLASS_RETIRED                                         L_TEXT(UID_IMAGE_OVERLAY_BOX_CLASS_RETIRED_A)                                   // V15      Retired
#define UID_BASIC_PRINT_IMAGE_OVERLAY_BOX_CLASS                                     L_TEXT(UID_BASIC_PRINT_IMAGE_OVERLAY_BOX_CLASS_A)                               // V15      Retired
#define UID_PRINT_QUEUE_INSTANCE                                                    L_TEXT(UID_PRINT_QUEUE_INSTANCE_A)                                              // V15      Retired
#define UID_PRINT_QUEUE_CLASS                                                       L_TEXT(UID_PRINT_QUEUE_CLASS_A)                                                 // V15      Retired
#define UID_STORED_PRINT_STORAGE_CLASS                                              L_TEXT(UID_STORED_PRINT_STORAGE_CLASS_A)                                        // V15      Retired
#define UID_HARDCOPY_GRAYSCALE_IMAGE_STORAGE_CLASS                                  L_TEXT(UID_HARDCOPY_GRAYSCALE_IMAGE_STORAGE_CLASS_A)                            // V15      Retired
#define UID_HARDCOPY_COLOR_IMAGE_STORAGE_CLASS                                      L_TEXT(UID_HARDCOPY_COLOR_IMAGE_STORAGE_CLASS_A)                                // V15      Retired
#define UID_PULL_PRINT_REQUEST_CLASS                                                L_TEXT(UID_PULL_PRINT_REQUEST_CLASS_A)                                          // V15      Retired
#define UID_PULL_STORED_PRINT_META_CLASS                                            L_TEXT(UID_PULL_STORED_PRINT_META_CLASS_A)                                      // V15      Retired
#define UID_MEDIA_CREATION_MANAGEMENT                                               L_TEXT(UID_MEDIA_CREATION_MANAGEMENT_A)                                         //          
#define UID_DISPLAY_SYSTEM                                                          L_TEXT(UID_DISPLAY_SYSTEM_A)                                                    // 2014      
#define UID_DISPLAY_SYSTEM_SOP_INSTANCE                                             L_TEXT(UID_DISPLAY_SYSTEM_SOP_INSTANCE_A)                                       // 2014      
#define UID_CR_IMAGE_STORAGE                                                        L_TEXT(UID_CR_IMAGE_STORAGE_A)                                                  // V15      
#define UID_DX_IMAGE_STORAGE_PRESENTATION                                           L_TEXT(UID_DX_IMAGE_STORAGE_PRESENTATION_A)                                     // V15      
#define UID_DX_IMAGE_STORAGE_PROCESSING                                             L_TEXT(UID_DX_IMAGE_STORAGE_PROCESSING_A)                                       // V15      
#define UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PRESENTATION                               L_TEXT(UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PRESENTATION_A)                         // V15      
#define UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PROCESSING                                 L_TEXT(UID_DX_MAMMOGRAPHY_IMAGE_STORAGE_PROCESSING_A)                           // V15      
#define UID_DX_INTRAORAL_IMAGE_STORAGE_PRESENTATION                                 L_TEXT(UID_DX_INTRAORAL_IMAGE_STORAGE_PRESENTATION_A)                           // V15      
#define UID_DX_INTRAORAL_IMAGE_STORAGE_PROCESSING                                   L_TEXT(UID_DX_INTRAORAL_IMAGE_STORAGE_PROCESSING_A)                             // V15      
#define UID_CT_IMAGE_STORAGE                                                        L_TEXT(UID_CT_IMAGE_STORAGE_A)                                                  // V15      
#define UID_ENHANCED_CT_IMAGE_STORAGE                                               L_TEXT(UID_ENHANCED_CT_IMAGE_STORAGE_A)                                         //          
#define UID_LEGACY_CONVERTED_ENHANCED_CT_IMAGE_STORAGE                              L_TEXT(UID_LEGACY_CONVERTED_ENHANCED_CT_IMAGE_STORAGE_A)                        // 2014      
#define UID_US_MULTIFRAME_IMAGE_STORAGE_RETIRED                                     L_TEXT(UID_US_MULTIFRAME_IMAGE_STORAGE_RETIRED_A)                               // V15      Retired
#define UID_US_MULTIFRAME_IMAGE_STORAGE                                             L_TEXT(UID_US_MULTIFRAME_IMAGE_STORAGE_A)                                       // V15      
#define UID_MR_IMAGE_STORAGE                                                        L_TEXT(UID_MR_IMAGE_STORAGE_A)                                                  // V15      
#define UID_ENHANCED_MR_IMAGE_STORAGE                                               L_TEXT(UID_ENHANCED_MR_IMAGE_STORAGE_A)                                         // V15      
#define UID_MR_SPECTROSCOPY_STORAGE                                                 L_TEXT(UID_MR_SPECTROSCOPY_STORAGE_A)                                           // V15      
#define UID_ENHANCED_MR_COLOR_IMAGE_STORAGE                                         L_TEXT(UID_ENHANCED_MR_COLOR_IMAGE_STORAGE_A)                                   //          
#define UID_LEGACY_CONVERTED_ENHANCED_MR_IMAGE_STORAGE                              L_TEXT(UID_LEGACY_CONVERTED_ENHANCED_MR_IMAGE_STORAGE_A)                        // 2014      
#define UID_NM_IMAGE_STORAGE_RETIRED                                                L_TEXT(UID_NM_IMAGE_STORAGE_RETIRED_A)                                          // V15      Retired
#define UID_US_IMAGE_STORAGE_RETIRED                                                L_TEXT(UID_US_IMAGE_STORAGE_RETIRED_A)                                          // V15      Retired
#define UID_US_IMAGE_STORAGE                                                        L_TEXT(UID_US_IMAGE_STORAGE_A)                                                  // V15      
#define UID_ENHANCED_US_VOLUME_STORAGE                                              L_TEXT(UID_ENHANCED_US_VOLUME_STORAGE_A)                                        //          
#define UID_SC_IMAGE_STORAGE                                                        L_TEXT(UID_SC_IMAGE_STORAGE_A)                                                  // V15      
#define UID_SC_MULTI_FRAME_SINGLE_BIT_IMAGE_STORAGE                                 L_TEXT(UID_SC_MULTI_FRAME_SINGLE_BIT_IMAGE_STORAGE_A)                           // V15      
#define UID_SC_MULTI_FRAME_GRAYSCALE_BYTE_IMAGE_STORAGE                             L_TEXT(UID_SC_MULTI_FRAME_GRAYSCALE_BYTE_IMAGE_STORAGE_A)                       // V15      
#define UID_SC_MULTI_FRAME_GRAYSCALE_WORD_IMAGE_STORAGE                             L_TEXT(UID_SC_MULTI_FRAME_GRAYSCALE_WORD_IMAGE_STORAGE_A)                       // V15      
#define UID_SC_MULTI_FRAME_TRUE_COLOR_IMAGE_STORAGE                                 L_TEXT(UID_SC_MULTI_FRAME_TRUE_COLOR_IMAGE_STORAGE_A)                           // V15      
#define UID_STANDALONE_OVERLAY_STORAGE                                              L_TEXT(UID_STANDALONE_OVERLAY_STORAGE_A)                                        // V15      Retired
#define UID_STANDALONE_CURVE_STORAGE                                                L_TEXT(UID_STANDALONE_CURVE_STORAGE_A)                                          // V15      Retired
#define UID_WAVEFORM_STORAGE                                                        L_TEXT(UID_WAVEFORM_STORAGE_A)                                                  // V15      Retired
#define UID_12_LEAD_ECG_WAVEFORM_STORAGE                                            L_TEXT(UID_12_LEAD_ECG_WAVEFORM_STORAGE_A)                                      // V15      
#define UID_GENERAL_ECG_WAVEFORM_STORAGE                                            L_TEXT(UID_GENERAL_ECG_WAVEFORM_STORAGE_A)                                      // V15      
#define UID_AMBULATORY_ECG_WAVEFORM_STORAGE                                         L_TEXT(UID_AMBULATORY_ECG_WAVEFORM_STORAGE_A)                                   // V15      
#define UID_HEMODYNAMIC_WAVEFORM_STORAGE                                            L_TEXT(UID_HEMODYNAMIC_WAVEFORM_STORAGE_A)                                      // V15      
#define UID_CARDIAC_ELECTROPHYSIOLOGY_WAVEFORM_STORAGE                              L_TEXT(UID_CARDIAC_ELECTROPHYSIOLOGY_WAVEFORM_STORAGE_A)                        // V15      
#define UID_BASIC_VOICE_AUDIO_WAVEFORM_STORAGE                                      L_TEXT(UID_BASIC_VOICE_AUDIO_WAVEFORM_STORAGE_A)                                // V15      
#define UID_GENERAL_AUDIO_WAVEFORM_STORAGE                                          L_TEXT(UID_GENERAL_AUDIO_WAVEFORM_STORAGE_A)                                    //          
#define UID_ARTERIAL_PULSE_WAVEFORM_STORAGE                                         L_TEXT(UID_ARTERIAL_PULSE_WAVEFORM_STORAGE_A)                                   //          
#define UID_RESPIRATORY_WAVEFORM_STORAGE                                            L_TEXT(UID_RESPIRATORY_WAVEFORM_STORAGE_A)                                      //          
#define UID_MULTI_CHANNEL_RESPIRATORY_WAVEFORM_STORAGE                              L_TEXT(UID_MULTI_CHANNEL_RESPIRATORY_WAVEFORM_STORAGE_A)                        // 2021      
#define UID_ROUTINE_SCALP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE                     L_TEXT(UID_ROUTINE_SCALP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE_A)               // 2021      
#define UID_ELECTROMYOGRAM_WAVEFORM_STORAGE                                         L_TEXT(UID_ELECTROMYOGRAM_WAVEFORM_STORAGE_A)                                   // 2021      
#define UID_ELECTROOCULOGRAM_WAVEFORM_STORAGE                                       L_TEXT(UID_ELECTROOCULOGRAM_WAVEFORM_STORAGE_A)                                 // 2021      
#define UID_SLEEP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE                             L_TEXT(UID_SLEEP_ELECTROENCEPHALOGRAM_WAVEFORM_STORAGE_A)                       // 2021      
#define UID_BODY_POSITION_WAVEFORM_STORAGE                                          L_TEXT(UID_BODY_POSITION_WAVEFORM_STORAGE_A)                                    // 2021      
#define UID_STANDALONE_MODALITY_LUT_STORAGE                                         L_TEXT(UID_STANDALONE_MODALITY_LUT_STORAGE_A)                                   // V15      Retired
#define UID_STANDALONE_VOI_LUT_STORAGE                                              L_TEXT(UID_STANDALONE_VOI_LUT_STORAGE_A)                                        // V15      Retired
#define UID_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE                           L_TEXT(UID_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE_A)                     // V15      
#define UID_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE                               L_TEXT(UID_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE_A)                         //          
#define UID_PSEUDO_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE                        L_TEXT(UID_PSEUDO_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE_A)                  //          
#define UID_BLENDING_SOFTCOPY_PRESENTATION_STATE_STORAGE                            L_TEXT(UID_BLENDING_SOFTCOPY_PRESENTATION_STATE_STORAGE_A)                      //          
#define UID_XA_XRF_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE                    L_TEXT(UID_XA_XRF_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE_A)              //          
#define UID_GRAYSCALE_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE              L_TEXT(UID_GRAYSCALE_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A)        // 2021      
#define UID_COMPOSITING_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE            L_TEXT(UID_COMPOSITING_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A)      // 2021      
#define UID_ADVANCED_BLENDING_PRESENTATION_STATE_STORAGE                            L_TEXT(UID_ADVANCED_BLENDING_PRESENTATION_STATE_STORAGE_A)                      // 2021      
#define UID_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE                  L_TEXT(UID_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A)            // 2021      
#define UID_SEGMENTED_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE        L_TEXT(UID_SEGMENTED_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A)  // 2021      
#define UID_MULTIPLE_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE         L_TEXT(UID_MULTIPLE_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE_A)   // 2021      
#define UID_XA_IMAGE_STORAGE                                                        L_TEXT(UID_XA_IMAGE_STORAGE_A)                                                  // V15      
#define UID_ENHANCED_XA_IMAGE_STORAGE                                               L_TEXT(UID_ENHANCED_XA_IMAGE_STORAGE_A)                                         //          
#define UID_XRF_IMAGE_STORAGE                                                       L_TEXT(UID_XRF_IMAGE_STORAGE_A)                                                 // V15      
#define UID_ENHANCED_XRF_IMAGE_STORAGE                                              L_TEXT(UID_ENHANCED_XRF_IMAGE_STORAGE_A)                                        //          
#define UID_XA_BIPLANE_IMAGE_STORAGE_RETIRED                                        L_TEXT(UID_XA_BIPLANE_IMAGE_STORAGE_RETIRED_A)                                  // V15      Retired
#define UID_X_RAY_3D_ANGIOGRAPHIC_IMAGE_STORAGE                                     L_TEXT(UID_X_RAY_3D_ANGIOGRAPHIC_IMAGE_STORAGE_A)                               //          
#define UID_X_RAY_3D_CRANIOFACIAL_IMAGE_STORAGE                                     L_TEXT(UID_X_RAY_3D_CRANIOFACIAL_IMAGE_STORAGE_A)                               //          
#define UID_BREAST_TOMOSYNTHESIS_IMAGE_STORAGE                                      L_TEXT(UID_BREAST_TOMOSYNTHESIS_IMAGE_STORAGE_A)                                //          
#define UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PRESENTATION                      L_TEXT(UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PRESENTATION_A)                // 2014      
#define UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PROCESSING                        L_TEXT(UID_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PROCESSING_A)                  // 2014      
#define UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PRESENTATION                            L_TEXT(UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PRESENTATION_A)                      //          
#define UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PROCESSING                              L_TEXT(UID_INTRAVASCULAR_OCT_IMAGE_STORAGE_PROCESSING_A)                        //          
#define UID_NM_IMAGE_STORAGE                                                        L_TEXT(UID_NM_IMAGE_STORAGE_A)                                                  // V15      
#define UID_PARAMETRIC_MAP_STORAGE                                                  L_TEXT(UID_PARAMETRIC_MAP_STORAGE_A)                                            // 2015      
#define UID_RAW_DATA_STORAGE                                                        L_TEXT(UID_RAW_DATA_STORAGE_A)                                                  // V15      
#define UID_SPATIAL_REGISTRATION_STORAGE                                            L_TEXT(UID_SPATIAL_REGISTRATION_STORAGE_A)                                      //          
#define UID_SPATIAL_FIDUCIALS_STORAGE                                               L_TEXT(UID_SPATIAL_FIDUCIALS_STORAGE_A)                                         //          
#define UID_DEFORMABLE_SPATIAL_REGISTRATION_STORAGE                                 L_TEXT(UID_DEFORMABLE_SPATIAL_REGISTRATION_STORAGE_A)                           //          
#define UID_SEGMENTATION_STORAGE                                                    L_TEXT(UID_SEGMENTATION_STORAGE_A)                                              //          
#define UID_SURFACE_SEGMENTATION_STORAGE                                            L_TEXT(UID_SURFACE_SEGMENTATION_STORAGE_A)                                      //          
#define UID_TRACTOGRAPHY_RESULTS_STORAGE                                            L_TEXT(UID_TRACTOGRAPHY_RESULTS_STORAGE_A)                                      // 2021      
#define UID_REAL_WORLD_VALUE_MAPPING_STORAGE                                        L_TEXT(UID_REAL_WORLD_VALUE_MAPPING_STORAGE_A)                                  //          
#define UID_SURFACE_SCAN_MESH_STORAGE                                               L_TEXT(UID_SURFACE_SCAN_MESH_STORAGE_A)                                         // 2014      
#define UID_SURFACE_SCAN_POINT_CLOUD_STORAGE                                        L_TEXT(UID_SURFACE_SCAN_POINT_CLOUD_STORAGE_A)                                  // 2014      
#define UID_VL_IMAGE_STORAGE_RETIRED                                                L_TEXT(UID_VL_IMAGE_STORAGE_RETIRED_A)                                          // V15      Retired
#define UID_VL_ENDOSCOPIC_IMAGE_STORAGE_CLASS                                       L_TEXT(UID_VL_ENDOSCOPIC_IMAGE_STORAGE_CLASS_A)                                 // V15      
#define UID_VIDEO_ENDOSCOPIC_IMAGE_STORAGE                                          L_TEXT(UID_VIDEO_ENDOSCOPIC_IMAGE_STORAGE_A)                                    // V15      
#define UID_VL_MICROSCOPIC_IMAGE_STORAGE_CLASS                                      L_TEXT(UID_VL_MICROSCOPIC_IMAGE_STORAGE_CLASS_A)                                // V15      
#define UID_VIDEO_MICROSCOPIC_IMAGE_STORAGE                                         L_TEXT(UID_VIDEO_MICROSCOPIC_IMAGE_STORAGE_A)                                   // V15      
#define UID_VL_SLIDE_COORDINATES_MICROSCOPIC_IMAGE_STORAGE_CLASS                    L_TEXT(UID_VL_SLIDE_COORDINATES_MICROSCOPIC_IMAGE_STORAGE_CLASS_A)              // V15      
#define UID_VL_PHOTOGRAPHIC_IMAGE_STORAGE_CLASS                                     L_TEXT(UID_VL_PHOTOGRAPHIC_IMAGE_STORAGE_CLASS_A)                               // V15      
#define UID_VIDEO_PHOTOGRAPHIC_IMAGE_STORAGE                                        L_TEXT(UID_VIDEO_PHOTOGRAPHIC_IMAGE_STORAGE_A)                                  // V15      
#define UID_OPHTHALMIC_8_BIT_PHOTOGRAPHY_IMAGE_STORAGE                              L_TEXT(UID_OPHTHALMIC_8_BIT_PHOTOGRAPHY_IMAGE_STORAGE_A)                        // V15      
#define UID_OPHTHALMIC_16_BIT_PHOTOGRAPHY_IMAGE_STORAGE                             L_TEXT(UID_OPHTHALMIC_16_BIT_PHOTOGRAPHY_IMAGE_STORAGE_A)                       // V15      
#define UID_STEREOMETRIC_RELATIONSHIP_STORAGE                                       L_TEXT(UID_STEREOMETRIC_RELATIONSHIP_STORAGE_A)                                 // V15      
#define UID_OPHTHALMIC_TOMOGRAPHY_IMAGE_STORAGE                                     L_TEXT(UID_OPHTHALMIC_TOMOGRAPHY_IMAGE_STORAGE_A)                               //          
#define UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_STEREOGRAPHIC_PROJECTION_IMAGE_STORAGE L_TEXT(UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_STEREOGRAPHIC_PROJECTION_IMAGE_STORAGE_A)// 2015      
#define UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_3D_COORDINATES_IMAGE_STORAGE          L_TEXT(UID_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_3D_COORDINATES_IMAGE_STORAGE_A)    // 2015      
#define UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE_STORAGE           L_TEXT(UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE_STORAGE_A)     // 2021      
#define UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_STORAGE  L_TEXT(UID_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_STORAGE_A)// 2021      
#define UID_VL_WHOLE_SLIDE_MICROSCOPY_IMAGE_STORAGE                                 L_TEXT(UID_VL_WHOLE_SLIDE_MICROSCOPY_IMAGE_STORAGE_A)                           //          
#define UID_DERMOSCOPIC_PHOTOGRAPHY_IMAGE_STORAGE                                   L_TEXT(UID_DERMOSCOPIC_PHOTOGRAPHY_IMAGE_STORAGE_A)                             // 2021      
#define UID_VL_MULTIFRAME_IMAGE_STORAGE_RETIRED                                     L_TEXT(UID_VL_MULTIFRAME_IMAGE_STORAGE_RETIRED_A)                               // V15      Retired
#define UID_LENSOMETRY_MEASUREMENTS_STORAGE                                         L_TEXT(UID_LENSOMETRY_MEASUREMENTS_STORAGE_A)                                   //          
#define UID_AUTOREFRACTION_MEASUREMENTS_STORAGE                                     L_TEXT(UID_AUTOREFRACTION_MEASUREMENTS_STORAGE_A)                               //          
#define UID_KERATOMETRY_MEASUREMENTS_STORAGE                                        L_TEXT(UID_KERATOMETRY_MEASUREMENTS_STORAGE_A)                                  //          
#define UID_SUBJECTIVE_REFRACTION_MEASUREMENTS_STORAGE                              L_TEXT(UID_SUBJECTIVE_REFRACTION_MEASUREMENTS_STORAGE_A)                        //          
#define UID_VISUAL_ACUITY_MEASUREMENTS_STORAGE                                      L_TEXT(UID_VISUAL_ACUITY_MEASUREMENTS_STORAGE_A)                                //          
#define UID_SPECTACLE_PRESCRIPTION_REPORT_STORAGE                                   L_TEXT(UID_SPECTACLE_PRESCRIPTION_REPORT_STORAGE_A)                             //          
#define UID_OPHTHALMIC_AXIAL_MEASUREMENTS_STORAGE                                   L_TEXT(UID_OPHTHALMIC_AXIAL_MEASUREMENTS_STORAGE_A)                             //          
#define UID_INTRAOCULAR_LENS_CALCULATIONS_STORAGE                                   L_TEXT(UID_INTRAOCULAR_LENS_CALCULATIONS_STORAGE_A)                             //          
#define UID_MACULAR_GRID_THICKNESS_AND_VOLUME_REPORT_STORAGE                        L_TEXT(UID_MACULAR_GRID_THICKNESS_AND_VOLUME_REPORT_STORAGE_A)                  //          
#define UID_OPHTHALMIC_VISUAL_FIELD_STATIC_PERIMETRY_MEASUREMENTS_STORAGE           L_TEXT(UID_OPHTHALMIC_VISUAL_FIELD_STATIC_PERIMETRY_MEASUREMENTS_STORAGE_A)     //          
#define UID_OPHTHALMIC_THICKNESS_MAP_STORAGE                                        L_TEXT(UID_OPHTHALMIC_THICKNESS_MAP_STORAGE_A)                                  //          
#define UID_CORNEAL_TOPOGRAPHY_MAP_STORAGE                                          L_TEXT(UID_CORNEAL_TOPOGRAPHY_MAP_STORAGE_A)                                    // 2014      
#define UID_TEXT_SR_STORAGE_TRIAL_RETIRED                                           L_TEXT(UID_TEXT_SR_STORAGE_TRIAL_RETIRED_A)                                     //          Retired
#define UID_AUDIO_SR_STORAGE_TRIAL_RETIRED                                          L_TEXT(UID_AUDIO_SR_STORAGE_TRIAL_RETIRED_A)                                    //          Retired
#define UID_DETAIL_SR_STORAGE_TRIAL_RETIRED                                         L_TEXT(UID_DETAIL_SR_STORAGE_TRIAL_RETIRED_A)                                   //          Retired
#define UID_COMPREHENSIVE_SR_STORAGE_TRIAL_RETIRED                                  L_TEXT(UID_COMPREHENSIVE_SR_STORAGE_TRIAL_RETIRED_A)                            //          Retired
#define UID_BASIC_TEXT_SR                                                           L_TEXT(UID_BASIC_TEXT_SR_A)                                                     // V15      
#define UID_ENHANCED_SR                                                             L_TEXT(UID_ENHANCED_SR_A)                                                       // V15      
#define UID_COMPREHENSIVE_SR                                                        L_TEXT(UID_COMPREHENSIVE_SR_A)                                                  // V15      
#define UID_COMPREHENSIVE_3D_SR_STORAGE                                             L_TEXT(UID_COMPREHENSIVE_3D_SR_STORAGE_A)                                       // 2014      
#define UID_EXTENSIBLE_SR_STORAGE                                                   L_TEXT(UID_EXTENSIBLE_SR_STORAGE_A)                                             // 2015      
#define UID_PROCEDURE_LOG_STORAGE                                                   L_TEXT(UID_PROCEDURE_LOG_STORAGE_A)                                             //          
#define UID_MAMMOGRAPHY_CAD_SR                                                      L_TEXT(UID_MAMMOGRAPHY_CAD_SR_A)                                                // V15      
#define UID_KEY_OBJECT_SELECTION_DOCUMENT                                           L_TEXT(UID_KEY_OBJECT_SELECTION_DOCUMENT_A)                                     // V15      
#define UID_CHEST_CAD_SR                                                            L_TEXT(UID_CHEST_CAD_SR_A)                                                      // V15      
#define UID_X_RAY_RADIATION_DOSE_SR_STORAGE                                         L_TEXT(UID_X_RAY_RADIATION_DOSE_SR_STORAGE_A)                                   //          
#define UID_RADIOPHARMACEUTICAL_RADIATION_DOSE_SR_STORAGE                           L_TEXT(UID_RADIOPHARMACEUTICAL_RADIATION_DOSE_SR_STORAGE_A)                     // 2014      
#define UID_COLON_CAD_SR_STORAGE                                                    L_TEXT(UID_COLON_CAD_SR_STORAGE_A)                                              //          
#define UID_IMPLANTATION_PLAN_SR_DOCUMENT_STORAGE                                   L_TEXT(UID_IMPLANTATION_PLAN_SR_DOCUMENT_STORAGE_A)                             //          
#define UID_ACQUISITION_CONTEXT_SR_STORAGE                                          L_TEXT(UID_ACQUISITION_CONTEXT_SR_STORAGE_A)                                    // 2021      
#define UID_SIMPLIFIED_ADULT_ECHO_SR_STORAGE                                        L_TEXT(UID_SIMPLIFIED_ADULT_ECHO_SR_STORAGE_A)                                  // 2021      
#define UID_PATIENT_RADIATION_DOSE_SR_STORAGE                                       L_TEXT(UID_PATIENT_RADIATION_DOSE_SR_STORAGE_A)                                 // 2021      
#define UID_PLANNED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE                         L_TEXT(UID_PLANNED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE_A)                   // 2021      
#define UID_PERFORMED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE                       L_TEXT(UID_PERFORMED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE_A)                 // 2021      
#define UID_ENHANCED_X_RAY_RADIATION_DOSE_SR_STORAGE                                L_TEXT(UID_ENHANCED_X_RAY_RADIATION_DOSE_SR_STORAGE_A)                          // 2021b    
#define UID_CONTENT_ASSESSMENT_RESULTS_STORAGE                                      L_TEXT(UID_CONTENT_ASSESSMENT_RESULTS_STORAGE_A)                                // 2021      
#define UID_ENCAPSULATED_PDF_STORAGE                                                L_TEXT(UID_ENCAPSULATED_PDF_STORAGE_A)                                          //          
#define UID_ENCAPSULATED_CDA_STORAGE                                                L_TEXT(UID_ENCAPSULATED_CDA_STORAGE_A)                                          //          
#define UID_ENCAPSULATED_STL_STORAGE                                                L_TEXT(UID_ENCAPSULATED_STL_STORAGE_A)                                          // 2021      
#define UID_ENCAPSULATED_OBJ_STORAGE                                                L_TEXT(UID_ENCAPSULATED_OBJ_STORAGE_A)                                          // 2021      
#define UID_ENCAPSULATED_MTL_STORAGE                                                L_TEXT(UID_ENCAPSULATED_MTL_STORAGE_A)                                          // 2021      
#define UID_PET_IMAGE_STORAGE                                                       L_TEXT(UID_PET_IMAGE_STORAGE_A)                                                 // V15      
#define UID_LEGACY_CONVERTED_ENHANCED_PET_IMAGE_STORAGE                             L_TEXT(UID_LEGACY_CONVERTED_ENHANCED_PET_IMAGE_STORAGE_A)                       // 2014      
#define UID_STANDALONE_PET_CURVE_STORAGE                                            L_TEXT(UID_STANDALONE_PET_CURVE_STORAGE_A)                                      // V15      Retired
#define UID_ENHANCED_PET_IMAGE_STORAGE                                              L_TEXT(UID_ENHANCED_PET_IMAGE_STORAGE_A)                                        //          
#define UID_BASIC_STRUCTURED_DISPLAY_STORAGE                                        L_TEXT(UID_BASIC_STRUCTURED_DISPLAY_STORAGE_A)                                  //          
#define UID_CT_DEFINED_PROCEDURE_PROTOCOL_STORAGE                                   L_TEXT(UID_CT_DEFINED_PROCEDURE_PROTOCOL_STORAGE_A)                             // 2021      
#define UID_CT_PERFORMED_PROCEDURE_PROTOCOL_STORAGE                                 L_TEXT(UID_CT_PERFORMED_PROCEDURE_PROTOCOL_STORAGE_A)                           // 2021      
#define UID_PROTOCOL_APPROVAL_STORAGE                                               L_TEXT(UID_PROTOCOL_APPROVAL_STORAGE_A)                                         // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_FIND                                L_TEXT(UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_FIND_A)                          // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_MOVE                                L_TEXT(UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_MOVE_A)                          // 2021      
#define UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_GET                                 L_TEXT(UID_PROTOCOL_APPROVAL_INFORMATION_MODEL_GET_A)                           // 2021      
#define UID_XA_DEFINED_PROCEDURE_PROTOCOL_STORAGE                                   L_TEXT(UID_XA_DEFINED_PROCEDURE_PROTOCOL_STORAGE_A)                             // 2021      
#define UID_XA_PERFORMED_PROCEDURE_PROTOCOL_STORAGE                                 L_TEXT(UID_XA_PERFORMED_PROCEDURE_PROTOCOL_STORAGE_A)                           // 2021      
#define UID_RT_IMAGE_STORAGE                                                        L_TEXT(UID_RT_IMAGE_STORAGE_A)                                                  // V15      
#define UID_RT_DOSE_STORAGE                                                         L_TEXT(UID_RT_DOSE_STORAGE_A)                                                   // V15      
#define UID_RT_STRUCTURE_STORAGE                                                    L_TEXT(UID_RT_STRUCTURE_STORAGE_A)                                              // V15      
#define UID_RT_BEAMS_TREATMENT_RECORD_STORAGE_CLASS                                 L_TEXT(UID_RT_BEAMS_TREATMENT_RECORD_STORAGE_CLASS_A)                           // V15      
#define UID_RT_PLAN_STORAGE                                                         L_TEXT(UID_RT_PLAN_STORAGE_A)                                                   // V15      
#define UID_RT_BRACHY_TREATMENT_RECORD_STORAGE_CLASS                                L_TEXT(UID_RT_BRACHY_TREATMENT_RECORD_STORAGE_CLASS_A)                          // V15      
#define UID_RT_TREATMENT_SUMMARY_RECORD_STORAGE_CLASS                               L_TEXT(UID_RT_TREATMENT_SUMMARY_RECORD_STORAGE_CLASS_A)                         // V15      
#define UID_RT_ION_PLAN_STORAGE                                                     L_TEXT(UID_RT_ION_PLAN_STORAGE_A)                                               //          
#define UID_RT_ION_BEAMS_TREATMENT_RECORD_STORAGE                                   L_TEXT(UID_RT_ION_BEAMS_TREATMENT_RECORD_STORAGE_A)                             //          
#define UID_RT_PHYSICIAN_INTENT_STORAGE                                             L_TEXT(UID_RT_PHYSICIAN_INTENT_STORAGE_A)                                       // 2021      
#define UID_RT_SEGMENT_ANNOTATION_STORAGE                                           L_TEXT(UID_RT_SEGMENT_ANNOTATION_STORAGE_A)                                     // 2021      
#define UID_RT_RADIATION_SET_STORAGE                                                L_TEXT(UID_RT_RADIATION_SET_STORAGE_A)                                          // 2021      
#define UID_C_ARM_PHOTON_ELECTRON_RADIATION_STORAGE                                 L_TEXT(UID_C_ARM_PHOTON_ELECTRON_RADIATION_STORAGE_A)                           // 2021      
#define UID_TOMOTHERAPEUTIC_RADIATION_STORAGE                                       L_TEXT(UID_TOMOTHERAPEUTIC_RADIATION_STORAGE_A)                                 // 2021      
#define UID_ROBOTIC_ARM_RADIATION_STORAGE                                           L_TEXT(UID_ROBOTIC_ARM_RADIATION_STORAGE_A)                                     // 2021      
#define UID_RT_RADIATION_RECORD_SET_STORAGE                                         L_TEXT(UID_RT_RADIATION_RECORD_SET_STORAGE_A)                                   // 2021      
#define UID_RT_RADIATION_SALVAGE_RECORD_STORAGE                                     L_TEXT(UID_RT_RADIATION_SALVAGE_RECORD_STORAGE_A)                               // 2021      
#define UID_TOMOTHERAPEUTIC_RADIATION_RECORD_STORAGE                                L_TEXT(UID_TOMOTHERAPEUTIC_RADIATION_RECORD_STORAGE_A)                          // 2021      
#define UID_C_ARM_PHOTON_ELECTRON_RADIATION_RECORD_STORAGE                          L_TEXT(UID_C_ARM_PHOTON_ELECTRON_RADIATION_RECORD_STORAGE_A)                    // 2021      
#define UID_ROBOTIC_RADIATION_RECORD_STORAGE                                        L_TEXT(UID_ROBOTIC_RADIATION_RECORD_STORAGE_A)                                  // 2021      
#define UID_DICOS_CT_IMAGE_STORAGE                                                  L_TEXT(UID_DICOS_CT_IMAGE_STORAGE_A)                                            //          
#define UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PRESENTATION                      L_TEXT(UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PRESENTATION_A)                //          
#define UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PROCESSING                        L_TEXT(UID_DICOS_DIGITAL_X_RAY_IMAGE_STORAGE_FOR_PROCESSING_A)                  //          
#define UID_DICOS_THREAT_DETECTION_REPORT_STORAGE                                   L_TEXT(UID_DICOS_THREAT_DETECTION_REPORT_STORAGE_A)                             //          
#define UID_DICOS_2D_AIT_STORAGE                                                    L_TEXT(UID_DICOS_2D_AIT_STORAGE_A)                                              // 2014      
#define UID_DICOS_3D_AIT_STORAGE                                                    L_TEXT(UID_DICOS_3D_AIT_STORAGE_A)                                              // 2014      
#define UID_DICOS_QUADRUPOLE_RESONANCE_QR_STORAGE                                   L_TEXT(UID_DICOS_QUADRUPOLE_RESONANCE_QR_STORAGE_A)                             // 2014      
#define UID_EDDY_CURRENT_IMAGE_STORAGE                                              L_TEXT(UID_EDDY_CURRENT_IMAGE_STORAGE_A)                                        //          
#define UID_EDDY_CURRENT_MULTI_FRAME_IMAGE_STORAGE                                  L_TEXT(UID_EDDY_CURRENT_MULTI_FRAME_IMAGE_STORAGE_A)                            //          
#define UID_PATIENT_ROOT_QUERY_FIND                                                 L_TEXT(UID_PATIENT_ROOT_QUERY_FIND_A)                                           // V15      
#define UID_PATIENT_ROOT_QUERY_MOVE                                                 L_TEXT(UID_PATIENT_ROOT_QUERY_MOVE_A)                                           // V15      
#define UID_PATIENT_ROOT_QUERY_GET                                                  L_TEXT(UID_PATIENT_ROOT_QUERY_GET_A)                                            // V15      
#define UID_STUDY_ROOT_QUERY_FIND                                                   L_TEXT(UID_STUDY_ROOT_QUERY_FIND_A)                                             // V15      
#define UID_STUDY_ROOT_QUERY_MOVE                                                   L_TEXT(UID_STUDY_ROOT_QUERY_MOVE_A)                                             // V15      
#define UID_STUDY_ROOT_QUERY_GET                                                    L_TEXT(UID_STUDY_ROOT_QUERY_GET_A)                                              // V15      
#define UID_PATIENT_STUDY_QUERY_FIND                                                L_TEXT(UID_PATIENT_STUDY_QUERY_FIND_A)                                          // V15      Retired
#define UID_PATIENT_STUDY_QUERY_MOVE                                                L_TEXT(UID_PATIENT_STUDY_QUERY_MOVE_A)                                          // V15      Retired
#define UID_PATIENT_STUDY_QUERY_GET                                                 L_TEXT(UID_PATIENT_STUDY_QUERY_GET_A)                                           // V15      Retired
#define UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_MOVE                                   L_TEXT(UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_MOVE_A)                             //          
#define UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_GET                                    L_TEXT(UID_COMPOSITE_INSTANCE_ROOT_RETRIEVE_GET_A)                              //          
#define UID_COMPOSITE_INSTANCE_RETRIEVE_WITHOUT_BULK_DATA_GET                       L_TEXT(UID_COMPOSITE_INSTANCE_RETRIEVE_WITHOUT_BULK_DATA_GET_A)                 //          
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_FIND                       L_TEXT(UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_FIND_A)                 // 2021      
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_MOVE                       L_TEXT(UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_MOVE_A)                 // 2021      
#define UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_GET                        L_TEXT(UID_DEFINED_PROCEDURE_PROTOCOL_INFORMATION_MODEL_GET_A)                  // 2021      
#define UID_MODALITY_WORKLIST_FIND                                                  L_TEXT(UID_MODALITY_WORKLIST_FIND_A)                                            // V15      
#define UID_GENERAL_PURPOSE_WORKLIST_MANAGEMENT_META_SOP_CLASS                      L_TEXT(UID_GENERAL_PURPOSE_WORKLIST_MANAGEMENT_META_SOP_CLASS_A)                // V15      Retired
#define UID_GENERAL_PURPOSE_WORKLIST_FIND                                           L_TEXT(UID_GENERAL_PURPOSE_WORKLIST_FIND_A)                                     // V15      Retired
#define UID_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_SOP_CLASS                      L_TEXT(UID_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_SOP_CLASS_A)                // V15      Retired
#define UID_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_SOP_CLASS                      L_TEXT(UID_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_SOP_CLASS_A)                // V15      Retired
#define UID_INSTANCE_AVAILABILITY_NOTIFICATION                                      L_TEXT(UID_INSTANCE_AVAILABILITY_NOTIFICATION_A)                                //          
#define UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE_TRIAL_RETIRED                     L_TEXT(UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE_TRIAL_RETIRED_A)               //          Retired
#define UID_RT_CONVENTIONAL_MACHINE_VERIFICATION_TRIAL_RETIRED                      L_TEXT(UID_RT_CONVENTIONAL_MACHINE_VERIFICATION_TRIAL_RETIRED_A)                //          Retired
#define UID_RT_ION_MACHINE_VERIFICATION_TRIAL_RETIRED                               L_TEXT(UID_RT_ION_MACHINE_VERIFICATION_TRIAL_RETIRED_A)                         //          Retired
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS_TRIAL_RETIRED         L_TEXT(UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS_TRIAL_RETIRED_A)   //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_PUSH_TRIAL_RETIRED                               L_TEXT(UID_UNIFIED_PROCEDURE_STEP_PUSH_TRIAL_RETIRED_A)                         //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_WATCH_TRIAL_RETIRED                              L_TEXT(UID_UNIFIED_PROCEDURE_STEP_WATCH_TRIAL_RETIRED_A)                        //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_PULL_TRIAL_RETIRED                               L_TEXT(UID_UNIFIED_PROCEDURE_STEP_PULL_TRIAL_RETIRED_A)                         //          Retired
#define UID_UNIFIED_PROCEDURE_STEP_EVENT_TRIAL_RETIRED                              L_TEXT(UID_UNIFIED_PROCEDURE_STEP_EVENT_TRIAL_RETIRED_A)                        //          Retired
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SOP_INSTANCE                        L_TEXT(UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SOP_INSTANCE_A)                  //          
#define UID_UPS_FILTERED_GLOBAL_SUBSCRIPTION_SOP_INSTANCE                           L_TEXT(UID_UPS_FILTERED_GLOBAL_SUBSCRIPTION_SOP_INSTANCE_A)                     // 2015      
#define UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS                       L_TEXT(UID_UNIFIED_WORKLIST_AND_PROCEDURE_STEP_SERVICE_CLASS_A)                 //          
#define UID_UNIFIED_PROCEDURE_STEP_PUSH                                             L_TEXT(UID_UNIFIED_PROCEDURE_STEP_PUSH_A)                                       //          
#define UID_UNIFIED_PROCEDURE_STEP_WATCH                                            L_TEXT(UID_UNIFIED_PROCEDURE_STEP_WATCH_A)                                      //          
#define UID_UNIFIED_PROCEDURE_STEP_PULL                                             L_TEXT(UID_UNIFIED_PROCEDURE_STEP_PULL_A)                                       //          
#define UID_UNIFIED_PROCEDURE_STEP_EVENT                                            L_TEXT(UID_UNIFIED_PROCEDURE_STEP_EVENT_A)                                      //          
#define UID_UNIFIED_PROCEDURE_STEP_QUERY                                            L_TEXT(UID_UNIFIED_PROCEDURE_STEP_QUERY_A)                                      // 2021      
#define UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE                                   L_TEXT(UID_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE_A)                             //          
#define UID_RT_CONVENTIONAL_MACHINE_VERIFICATION                                    L_TEXT(UID_RT_CONVENTIONAL_MACHINE_VERIFICATION_A)                              //          
#define UID_RT_ION_MACHINE_VERIFICATION                                             L_TEXT(UID_RT_ION_MACHINE_VERIFICATION_A)                                       //          
#define UID_RT_BRACHY_APPLICATION_SETUP_DELIVERY_INSTRUCTION_STORAGE                L_TEXT(UID_RT_BRACHY_APPLICATION_SETUP_DELIVERY_INSTRUCTION_STORAGE_A)          // 2021      
#define UID_GENERAL_RELEVANT_PATIENT_INFORMATION_QUERY                              L_TEXT(UID_GENERAL_RELEVANT_PATIENT_INFORMATION_QUERY_A)                        //          
#define UID_BREAST_IMAGING_RELEVANT_PATIENT_INFORMATION_QUERY                       L_TEXT(UID_BREAST_IMAGING_RELEVANT_PATIENT_INFORMATION_QUERY_A)                 //          
#define UID_CARDIAC_RELEVANT_PATIENT_INFORMATION_QUERY                              L_TEXT(UID_CARDIAC_RELEVANT_PATIENT_INFORMATION_QUERY_A)                        //          
#define UID_HANGING_PROTOCOL_STORAGE                                                L_TEXT(UID_HANGING_PROTOCOL_STORAGE_A)                                          //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_FIND                                 L_TEXT(UID_HANGING_PROTOCOL_INFORMATION_MODEL_FIND_A)                           //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_MOVE                                 L_TEXT(UID_HANGING_PROTOCOL_INFORMATION_MODEL_MOVE_A)                           //          
#define UID_HANGING_PROTOCOL_INFORMATION_MODEL_GET                                  L_TEXT(UID_HANGING_PROTOCOL_INFORMATION_MODEL_GET_A)                            //          
#define UID_COLOR_PALETTE_STORAGE                                                   L_TEXT(UID_COLOR_PALETTE_STORAGE_A)                                             //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_FIND                                    L_TEXT(UID_COLOR_PALETTE_INFORMATION_MODEL_FIND_A)                              //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_MOVE                                    L_TEXT(UID_COLOR_PALETTE_INFORMATION_MODEL_MOVE_A)                              //          
#define UID_COLOR_PALETTE_INFORMATION_MODEL_GET                                     L_TEXT(UID_COLOR_PALETTE_INFORMATION_MODEL_GET_A)                               //          
#define UID_PRODUCT_CHARACTERISTICS_QUERY                                           L_TEXT(UID_PRODUCT_CHARACTERISTICS_QUERY_A)                                     //          
#define UID_SUBSTANCE_APPROVAL_QUERY                                                L_TEXT(UID_SUBSTANCE_APPROVAL_QUERY_A)                                          //          
#define UID_GENERIC_IMPLANT_TEMPLATE_STORAGE                                        L_TEXT(UID_GENERIC_IMPLANT_TEMPLATE_STORAGE_A)                                  //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_FIND                         L_TEXT(UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_FIND_A)                   //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_MOVE                         L_TEXT(UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_MOVE_A)                   //          
#define UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_GET                          L_TEXT(UID_GENERIC_IMPLANT_TEMPLATE_INFORMATION_MODEL_GET_A)                    //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_STORAGE                                       L_TEXT(UID_IMPLANT_ASSEMBLY_TEMPLATE_STORAGE_A)                                 //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_FIND                        L_TEXT(UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_FIND_A)                  //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_MOVE                        L_TEXT(UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_MOVE_A)                  //          
#define UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_GET                         L_TEXT(UID_IMPLANT_ASSEMBLY_TEMPLATE_INFORMATION_MODEL_GET_A)                   //          
#define UID_IMPLANT_TEMPLATE_GROUP_STORAGE                                          L_TEXT(UID_IMPLANT_TEMPLATE_GROUP_STORAGE_A)                                    //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_FIND                           L_TEXT(UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_FIND_A)                     //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_MOVE                           L_TEXT(UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_MOVE_A)                     //          
#define UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_GET                            L_TEXT(UID_IMPLANT_TEMPLATE_GROUP_INFORMATION_MODEL_GET_A)                      //          
#define UID_NATIVE_DICOM_MODEL                                                      L_TEXT(UID_NATIVE_DICOM_MODEL_A)                                                //          
#define UID_ABSTRACT_MULTI_DIMENSIONAL_IMAGE_MODEL                                  L_TEXT(UID_ABSTRACT_MULTI_DIMENSIONAL_IMAGE_MODEL_A)                            //          
#define UID_DICOM_CONTENT_MAPPING_RESOURCE                                          L_TEXT(UID_DICOM_CONTENT_MAPPING_RESOURCE_A)                                    // 2015      
#define UID_VIDEO_ENDOSCOPIC_IMAGE_REAL_TIME_COMMUNICATION                          L_TEXT(UID_VIDEO_ENDOSCOPIC_IMAGE_REAL_TIME_COMMUNICATION_A)                    // 2021      
#define UID_VIDEO_PHOTOGRAPHIC_IMAGE_REAL_TIME_COMMUNICATION                        L_TEXT(UID_VIDEO_PHOTOGRAPHIC_IMAGE_REAL_TIME_COMMUNICATION_A)                  // 2021      
#define UID_AUDIO_WAVEFORM_REAL_TIME_COMMUNICATION                                  L_TEXT(UID_AUDIO_WAVEFORM_REAL_TIME_COMMUNICATION_A)                            // 2021      
#define UID_RENDITION_SELECTION_DOCUMENT_REAL_TIME_COMMUNICATION                    L_TEXT(UID_RENDITION_SELECTION_DOCUMENT_REAL_TIME_COMMUNICATION_A)              // 2021      
#define UID_DICOM_DEVICE_NAME                                                       L_TEXT(UID_DICOM_DEVICE_NAME_A)                                                 //          
#define UID_DICOM_DESCRIPTION                                                       L_TEXT(UID_DICOM_DESCRIPTION_A)                                                 //          
#define UID_DICOM_MANUFACTURER                                                      L_TEXT(UID_DICOM_MANUFACTURER_A)                                                //          
#define UID_DICOM_MANUFACTURER_MODEL_NAME                                           L_TEXT(UID_DICOM_MANUFACTURER_MODEL_NAME_A)                                     //          
#define UID_DICOM_SOFTWARE_VERSION                                                  L_TEXT(UID_DICOM_SOFTWARE_VERSION_A)                                            //          
#define UID_DICOM_VENDOR_DATA                                                       L_TEXT(UID_DICOM_VENDOR_DATA_A)                                                 //          
#define UID_DICOM_AE_TITLE                                                          L_TEXT(UID_DICOM_AE_TITLE_A)                                                    //          
#define UID_DICOM_NETWORK_CONNECTION_REFERENCE                                      L_TEXT(UID_DICOM_NETWORK_CONNECTION_REFERENCE_A)                                //          
#define UID_DICOM_APPLICATION_CLUSTER                                               L_TEXT(UID_DICOM_APPLICATION_CLUSTER_A)                                         //          
#define UID_DICOM_ASSOCIATION_INITIATOR                                             L_TEXT(UID_DICOM_ASSOCIATION_INITIATOR_A)                                       //          
#define UID_DICOM_ASSOCIATION_ACCEPTOR                                              L_TEXT(UID_DICOM_ASSOCIATION_ACCEPTOR_A)                                        //          
#define UID_DICOM_HOSTNAME                                                          L_TEXT(UID_DICOM_HOSTNAME_A)                                                    //          
#define UID_DICOM_PORT                                                              L_TEXT(UID_DICOM_PORT_A)                                                        //          
#define UID_DICOM                                                                   L_TEXT(UID_DICOM_A)                                                             //          
#define UID_DICOM_TRANSFER_ROLE                                                     L_TEXT(UID_DICOM_TRANSFER_ROLE_A)                                               //          
#define UID_DICOM_TRANSFER_SYNTAX                                                   L_TEXT(UID_DICOM_TRANSFER_SYNTAX_A)                                             //          
#define UID_DICOM_PRIMARY_DEVICE_TYPE                                               L_TEXT(UID_DICOM_PRIMARY_DEVICE_TYPE_A)                                         //          
#define UID_DICOM_RELATED_DEVICE_REFERENCE                                          L_TEXT(UID_DICOM_RELATED_DEVICE_REFERENCE_A)                                    //          
#define UID_DICOM_PREFERRED_CALLED_AE_TITLE                                         L_TEXT(UID_DICOM_PREFERRED_CALLED_AE_TITLE_A)                                   //          
#define UID_DICOM_TLS_CYPHERSUITE                                                   L_TEXT(UID_DICOM_TLS_CYPHERSUITE_A)                                             //          
#define UID_DICOM_AUTHORIZED_NODE_CERTIFICATE_REFERENCE                             L_TEXT(UID_DICOM_AUTHORIZED_NODE_CERTIFICATE_REFERENCE_A)                       //          
#define UID_DICOM_THIS_NODE_CERTIFICATE_REFERENCE                                   L_TEXT(UID_DICOM_THIS_NODE_CERTIFICATE_REFERENCE_A)                             //          
#define UID_DICOM_INSTALLED                                                         L_TEXT(UID_DICOM_INSTALLED_A)                                                   //          
#define UID_DICOM_STATION_NAME                                                      L_TEXT(UID_DICOM_STATION_NAME_A)                                                //          
#define UID_DICOM_DEVICE_SERIAL_NUMBER                                              L_TEXT(UID_DICOM_DEVICE_SERIAL_NUMBER_A)                                        //          
#define UID_DICOM_INSTITUTION_NAME                                                  L_TEXT(UID_DICOM_INSTITUTION_NAME_A)                                            //          
#define UID_DICOM_INSTITUTION_ADDRESS                                               L_TEXT(UID_DICOM_INSTITUTION_ADDRESS_A)                                         //          
#define UID_DICOM_INSTITUTION_DEPARTMENT_NAME                                       L_TEXT(UID_DICOM_INSTITUTION_DEPARTMENT_NAME_A)                                 //          
#define UID_DICOM_ISSUER_OF_PATIENT_ID                                              L_TEXT(UID_DICOM_ISSUER_OF_PATIENT_ID_A)                                        //          
#define UID_DICOM_PREFERRED_CALLING_AE_TITLE                                        L_TEXT(UID_DICOM_PREFERRED_CALLING_AE_TITLE_A)                                  //          
#define UID_DICOM_SUPPORTED_CHARACTER_SET                                           L_TEXT(UID_DICOM_SUPPORTED_CHARACTER_SET_A)                                     //          
#define UID_DICOM_CONFIGURATION_ROOT                                                L_TEXT(UID_DICOM_CONFIGURATION_ROOT_A)                                          //          
#define UID_DICOM_DEVICES_ROOT                                                      L_TEXT(UID_DICOM_DEVICES_ROOT_A)                                                //          
#define UID_DICOM_UNIQUE_AE_TITLES_REGISTRY_ROOT                                    L_TEXT(UID_DICOM_UNIQUE_AE_TITLES_REGISTRY_ROOT_A)                              //          
#define UID_DICOM_DEVICE                                                            L_TEXT(UID_DICOM_DEVICE_A)                                                      //          
#define UID_DICOM_NETWORK_AE                                                        L_TEXT(UID_DICOM_NETWORK_AE_A)                                                  //          
#define UID_DICOM_NETWORK_CONNECTION                                                L_TEXT(UID_DICOM_NETWORK_CONNECTION_A)                                          //          
#define UID_DICOM_UNIQUE_AE_TITLE                                                   L_TEXT(UID_DICOM_UNIQUE_AE_TITLE_A)                                             //          
#define UID_DICOM_TRANSFER_CAPABILITY                                               L_TEXT(UID_DICOM_TRANSFER_CAPABILITY_A)                                         //          
#define UID_UNIVERSAL_COORDINATED_TIME                                              L_TEXT(UID_UNIVERSAL_COORDINATED_TIME_A)                                        //          
#define UID_GE_MR_IMAGE                                                             L_TEXT(UID_GE_MR_IMAGE_A)                                                       // V15      
#define UID_GE_CT_IMAGE                                                             L_TEXT(UID_GE_CT_IMAGE_A)                                                       // V15      
#define UID_GE_DISPLAY_IMAGERMATION                                                 L_TEXT(UID_GE_DISPLAY_IMAGERMATION_A)                                           // V15      
#define UID_GE_ARM_MIGRATION                                                        L_TEXT(UID_GE_ARM_MIGRATION_A)                                                  // V15      
#define UID_GE_ARM_MIGRATION_INSTANCE                                               L_TEXT(UID_GE_ARM_MIGRATION_INSTANCE_A)                                         // V15      
