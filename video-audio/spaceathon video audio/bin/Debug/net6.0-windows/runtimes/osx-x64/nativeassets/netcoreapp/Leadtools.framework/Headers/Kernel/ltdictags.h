//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

// Contains defines for all the DICOM data elements and command elements


// *****************************************************************************************************************************
// *** 0000
// *****************************************************************************************************************************
#define TAG_COMMAND_GROUP_LENGTH                                                                  0x00000000UL   
#define TAG_COMMAND_LENGTH_TO_END                                                                 0x00000001UL   // Retired
#define TAG_AFFECTED_SOP_CLASS_UID                                                                0x00000002UL   
#define TAG_REQUESTED_SOP_CLASS_UID                                                               0x00000003UL   
#define TAG_COMMAND_RECOGNITION_CODE                                                              0x00000010UL   // Retired
#define TAG_COMMAND_FIELD                                                                         0x00000100UL   
#define TAG_MESSAGE_ID                                                                            0x00000110UL   
#define TAG_MESSAGE_ID_BEING_RESPONDED_TO                                                         0x00000120UL   
#define TAG_INITIATOR                                                                             0x00000200UL   // Retired
#define TAG_RECEIVER                                                                              0x00000300UL   // Retired
#define TAG_FIND_LOCATION                                                                         0x00000400UL   // Retired
#define TAG_MOVE_DESTINATION                                                                      0x00000600UL   
#define TAG_PRIORITY                                                                              0x00000700UL   
#define TAG_COMMAND_DATA_SET_TYPE                                                                 0x00000800UL   
#define TAG_NUMBER_OF_MATCHES                                                                     0x00000850UL   // Retired
#define TAG_RESPONSE_SEQUENCE_NUMBER                                                              0x00000860UL   // Retired
#define TAG_STATUS                                                                                0x00000900UL   
#define TAG_OFFENDING_ELEMENT                                                                     0x00000901UL   
#define TAG_ERROR_COMMENT                                                                         0x00000902UL   
#define TAG_ERROR_ID                                                                              0x00000903UL   
#define TAG_AFFECTED_SOP_INSTANCE_UID                                                             0x00001000UL   
#define TAG_REQUESTED_SOP_INSTANCE_UID                                                            0x00001001UL   
#define TAG_EVENT_TYPE_ID                                                                         0x00001002UL   
#define TAG_ATTRIBUTE_IDENTIFIER_LIST                                                             0x00001005UL   
#define TAG_ACTION_TYPE_ID                                                                        0x00001008UL   
#define TAG_NUMBER_OF_REMAINING_SUB_OPERATIONS                                                    0x00001020UL   
#define TAG_NUMBER_OF_COMPLETED_SUB_OPERATIONS                                                    0x00001021UL   
#define TAG_NUMBER_OF_FAILED_SUB_OPERATIONS                                                       0x00001022UL   
#define TAG_NUMBER_OF_WARNING_SUB_OPERATIONS                                                      0x00001023UL   
#define TAG_MOVE_ORIGINATOR_APPLICATION_ENTITY_TITLE                                              0x00001030UL   
#define TAG_MOVE_ORIGINATOR_MESSAGE_ID                                                            0x00001031UL   
#define TAG_DIALOG_RECEIVER                                                                       0x00004000UL   // Retired
#define TAG_TERMINAL_TYPE                                                                         0x00004010UL   // Retired
#define TAG_MESSAGE_SET_ID                                                                        0x00005010UL   // Retired
#define TAG_END_MESSAGE_ID                                                                        0x00005020UL   // Retired
#define TAG_DISPLAY_FORMAT                                                                        0x00005110UL   // Retired
#define TAG_PAGE_POSITION_ID                                                                      0x00005120UL   // Retired
#define TAG_TEXT_FORMAT_ID                                                                        0x00005130UL   // Retired
#define TAG_NORMAL_REVERSE                                                                        0x00005140UL   // Retired
#define TAG_ADD_GRAY_SCALE                                                                        0x00005150UL   // Retired
#define TAG_BORDERS                                                                               0x00005160UL   // Retired
#define TAG_COPIES                                                                                0x00005170UL   // Retired
#define TAG_COMMAND_MAGNIFICATION_TYPE                                                            0x00005180UL   // Retired
#define TAG_ERASE                                                                                 0x00005190UL   // Retired
#define TAG_PRINT                                                                                 0x000051A0UL   // Retired
#define TAG_OVERLAYS                                                                              0x000051B0UL   // Retired

// *****************************************************************************************************************************
// *** 0002
// *****************************************************************************************************************************
#define TAG_FILE_META_INFORMATION_GROUP_LENGTH                                                    0x00020000UL   
#define TAG_FILE_META_INFORMATION_VERSION                                                         0x00020001UL   
#define TAG_MEDIA_STORAGE_SOP_CLASS_UID                                                           0x00020002UL   
#define TAG_MEDIA_STORAGE_SOP_INSTANCE_UID                                                        0x00020003UL   
#define TAG_TRANSFER_SYNTAX_UID                                                                   0x00020010UL   
#define TAG_IMPLEMENTATION_CLASS_UID                                                              0x00020012UL   
#define TAG_IMPLEMENTATION_VERSION_NAME                                                           0x00020013UL   
#define TAG_SOURCE_APPLICATION_ENTITY_TITLE                                                       0x00020016UL   
#define TAG_SENDING_APPLICATION_ENTITY_TITLE                                                      0x00020017UL   
#define TAG_RECEIVING_APPLICATION_ENTITY_TITLE                                                    0x00020018UL   
#define TAG_SOURCE_PRESENTATION_ADDRESS                                                           0x00020026UL   
#define TAG_SENDING_PRESENTATION_ADDRESS                                                          0x00020027UL   
#define TAG_RECEIVING_PRESENTATION_ADDRESS                                                        0x00020028UL   
#define TAG_RTV_META_INFORMATION_VERSION                                                          0x00020031UL   
#define TAG_RTV_COMMUNICATION_SOP_CLASS_UID                                                       0x00020032UL   
#define TAG_RTV_COMMUNICATION_SOP_INSTANCE_UID                                                    0x00020033UL   
#define TAG_RTV_SOURCE_IDENTIFIER                                                                 0x00020035UL   
#define TAG_RTV_FLOW_IDENTIFIER                                                                   0x00020036UL   
#define TAG_RTV_FLOW_RTP_SAMPLING_RATE                                                            0x00020037UL   
#define TAG_RTV_FLOW_ACTUAL_FRAME_DURATION                                                        0x00020038UL   
#define TAG_PRIVATE_INFORMATION_CREATOR_UID                                                       0x00020100UL   
#define TAG_PRIVATE_INFORMATION                                                                   0x00020102UL   

// *****************************************************************************************************************************
// *** 0004
// *****************************************************************************************************************************
#define TAG_FILE_SET_ID                                                                           0x00041130UL   
#define TAG_FILE_SET_DESCRIPTOR_FILE_ID                                                           0x00041141UL   
#define TAG_SPECIFIC_CHARACTER_SET_OF_FILE_SET_DESCRIPTOR_FILE                                    0x00041142UL   
#define TAG_OFFSET_FIRST_ROOT_DIRECTORY                                                           0x00041200UL   
#define TAG_OFFSET_LAST_ROOT_DIRECTORY                                                            0x00041202UL   
#define TAG_FILE_SET_CONSISTENCY_FLAG                                                             0x00041212UL   
#define TAG_DIRECTORY_RECORD_SEQUENCE                                                             0x00041220UL   
#define TAG_OFFSET_NEXT_DIRECTORY                                                                 0x00041400UL   
#define TAG_RECORD_IN_USE_FLAG                                                                    0x00041410UL   
#define TAG_OFFSET_CHILD_DIRECTORY                                                                0x00041420UL   
#define TAG_DIRECTORY_RECORD_TYPE                                                                 0x00041430UL   
#define TAG_PRIVATE_RECORD_UID                                                                    0x00041432UL   
#define TAG_REFERENCED_FILE_ID                                                                    0x00041500UL   
#define TAG_MRDR_DIRECTORY_RECORD_OFFSET                                                          0x00041504UL   // Retired
#define TAG_REFERENCED_SOP_CLASS_UID_IN_FILE                                                      0x00041510UL   
#define TAG_REFERENCED_SOP_INSTANCE_UID_IN_FILE                                                   0x00041511UL   
#define TAG_REFERENCED_TRANSFER_SYNTAX_UID_IN_FILE                                                0x00041512UL   
#define TAG_REFERENCED_RELATED_GENERAL_SOP_CLASS_UID_IN_FILE                                      0x0004151AUL   
#define TAG_NUMBER_OF_REFERENCES                                                                  0x00041600UL   // Retired

// *****************************************************************************************************************************
// *** 0008
// *****************************************************************************************************************************
#define TAG_LENGTH_TO_END                                                                         0x00080001UL   // Retired
#define TAG_SPECIFIC_CHARACTER_SET                                                                0x00080005UL   
#define TAG_LANGUAGE_CODE_SEQUENCE                                                                0x00080006UL   
#define TAG_IMAGE_TYPE                                                                            0x00080008UL   
#define TAG_RECOGNITION_CODE                                                                      0x00080010UL   // Retired
#define TAG_INSTANCE_CREATION_DATE                                                                0x00080012UL   
#define TAG_INSTANCE_CREATION_TIME                                                                0x00080013UL   
#define TAG_INSTANCE_CREATOR_UID                                                                  0x00080014UL   
#define TAG_INSTANCE_COERCION_DATETIME                                                            0x00080015UL   
#define TAG_SOP_CLASS_UID                                                                         0x00080016UL   
#define TAG_SOP_INSTANCE_UID                                                                      0x00080018UL   
#define TAG_RELATED_GENERAL_SOP_CLASS_UID                                                         0x0008001AUL   
#define TAG_ORIGINAL_SPECIALIZED_SOP_CLASS_UID                                                    0x0008001BUL   
#define TAG_STUDY_DATE                                                                            0x00080020UL   
#define TAG_SERIES_DATE                                                                           0x00080021UL   
#define TAG_ACQUISITION_DATE                                                                      0x00080022UL   
#define TAG_CONTENT_DATE                                                                          0x00080023UL   
#define TAG_OVERLAY_DATE                                                                          0x00080024UL   // Retired
#define TAG_CURVE_DATE                                                                            0x00080025UL   // Retired
#define TAG_ACQUISITION_DATETIME                                                                  0x0008002AUL   
#define TAG_STUDY_TIME                                                                            0x00080030UL   
#define TAG_SERIES_TIME                                                                           0x00080031UL   
#define TAG_ACQUISITION_TIME                                                                      0x00080032UL   
#define TAG_CONTENT_TIME                                                                          0x00080033UL   
#define TAG_OVERLAY_TIME                                                                          0x00080034UL   // Retired
#define TAG_CURVE_TIME                                                                            0x00080035UL   // Retired
#define TAG_DATA_SET_TYPE                                                                         0x00080040UL   // Retired
#define TAG_DATA_SET_SUBTYPE                                                                      0x00080041UL   // Retired
#define TAG_NUCLEAR_MEDICINE_SERIES_TYPE                                                          0x00080042UL   // Retired
#define TAG_ACCESSION_NUMBER                                                                      0x00080050UL   
#define TAG_ISSUER_OF_ACCESSION_NUMBER_SEQUENCE                                                   0x00080051UL   
#define TAG_QUERY_RETRIEVE_LEVEL                                                                  0x00080052UL   
#define TAG_QUERY_RETRIEVE_VIEW                                                                   0x00080053UL   
#define TAG_RETRIEVE_AE_TITLE                                                                     0x00080054UL   
#define TAG_STATION_AE_TITLE                                                                      0x00080055UL   
#define TAG_INSTANCE_AVAILABILITY                                                                 0x00080056UL   
#define TAG_FAILED_SOP_INSTANCE_UID_LIST                                                          0x00080058UL   
#define TAG_MODALITY                                                                              0x00080060UL   
#define TAG_MODALITIES_IN_STUDY                                                                   0x00080061UL   
#define TAG_SOP_CLASSES_IN_STUDY                                                                  0x00080062UL   
#define TAG_ANATOMIC_REGIONS_IN_STUDY_CODE_SEQUENCE                                               0x00080063UL   
#define TAG_CONVERSION_TYPE                                                                       0x00080064UL   
#define TAG_PRESENTATION_INTENT_TYPE                                                              0x00080068UL   
#define TAG_MANUFACTURER                                                                          0x00080070UL   
#define TAG_INSTITUTION_NAME                                                                      0x00080080UL   
#define TAG_INSTITUTION_ADDRESS                                                                   0x00080081UL   
#define TAG_INSTITUTION_CODE_SEQUENCE                                                             0x00080082UL   
#define TAG_REFERRING_PHYSICIAN_NAME                                                              0x00080090UL   
#define TAG_REFERRING_PHYSICIAN_ADDRESS                                                           0x00080092UL   
#define TAG_REFERRING_PHYSICIAN_TELEPHONE_NUMBERS                                                 0x00080094UL   
#define TAG_REFERRING_PHYSICIAN_IDENTIFICATION_SEQUENCE                                           0x00080096UL   
#define TAG_CONSULTING_PHYSICIAN_NAME                                                             0x0008009CUL   
#define TAG_CONSULTING_PHYSICIAN_IDENTIFICATION_SEQUENCE                                          0x0008009DUL   
#define TAG_CODE_VALUE                                                                            0x00080100UL   
#define TAG_EXTENDED_CODE_VALUE                                                                   0x00080101UL   
#define TAG_CODING_SCHEME_DESIGNATOR                                                              0x00080102UL   
#define TAG_CODING_SCHEME_VERSION                                                                 0x00080103UL   
#define TAG_CODE_MEANING                                                                          0x00080104UL   
#define TAG_MAPPING_RESOURCE                                                                      0x00080105UL   
#define TAG_CONTEXT_GROUP_VERSION                                                                 0x00080106UL   
#define TAG_CONTEXT_GROUP_LOCAL_VERSION                                                           0x00080107UL   
#define TAG_EXTENDED_CODE_MEANING                                                                 0x00080108UL   
#define TAG_CODING_SCHEME_RESOURCES_SEQUENCE                                                      0x00080109UL   
#define TAG_CODING_SCHEME_URL_TYPE                                                                0x0008010AUL   
#define TAG_CONTEXT_GROUP_EXTENSION_FLAG                                                          0x0008010BUL   
#define TAG_CODING_SCHEME_UID                                                                     0x0008010CUL   
#define TAG_CONTEXT_GROUP_EXTENSION_CREATOR_UID                                                   0x0008010DUL   
#define TAG_CODING_SCHEME_URL                                                                     0x0008010EUL   
#define TAG_CONTEXT_IDENTIFIER                                                                    0x0008010FUL   
#define TAG_CODING_SCHEME_IDENTIFICATION_SEQUENCE                                                 0x00080110UL   
#define TAG_CODING_SCHEME_REGISTRY                                                                0x00080112UL   
#define TAG_CODING_SCHEME_EXTERNAL_ID                                                             0x00080114UL   
#define TAG_CODING_SCHEME_NAME                                                                    0x00080115UL   
#define TAG_CODING_SCHEME_RESPONSIBLE_ORGANIZATION                                                0x00080116UL   
#define TAG_CONTEXT_UID                                                                           0x00080117UL   
#define TAG_MAPPING_RESOURCE_UID                                                                  0x00080118UL   
#define TAG_LONG_CODE_VALUE                                                                       0x00080119UL   
#define TAG_URN_CODE_VALUE                                                                        0x00080120UL   
#define TAG_EQUIVALENT_CODE_SEQUENCE                                                              0x00080121UL   
#define TAG_MAPPING_RESOURCE_NAME                                                                 0x00080122UL   
#define TAG_CONTEXT_GROUP_IDENTIFICATION_SEQUENCE                                                 0x00080123UL   
#define TAG_MAPPING_RESOURCE_IDENTIFICATION_SEQUENCE                                              0x00080124UL   
#define TAG_TIMEZONE_OFFSET_FROM_UTC                                                              0x00080201UL   
#define TAG_RESPONSIBLE_GROUP_CODE_SEQUENCE                                                       0x00080220UL   
#define TAG_EQUIPMENT_MODALITY                                                                    0x00080221UL   
#define TAG_MANUFACTURER_RELATED_MODEL_GROUP                                                      0x00080222UL   
#define TAG_PRIVATE_DATA_ELEMENT_CHARACTERISTICS_SEQUENCE                                         0x00080300UL   
#define TAG_PRIVATE_GROUP_REFERENCE                                                               0x00080301UL   
#define TAG_PRIVATE_CREATOR_REFERENCE                                                             0x00080302UL   
#define TAG_BLOCK_IDENTIFYING_INFORMATION_STATUS                                                  0x00080303UL   
#define TAG_NONIDENTIFYING_PRIVATE_ELEMENTS                                                       0x00080304UL   
#define TAG_DEIDENTIFICATION_ACTION_SEQUENCE                                                      0x00080305UL   
#define TAG_IDENTIFYING_PRIVATE_ELEMENTS                                                          0x00080306UL   
#define TAG_DEIDENTIFICATION_ACTION                                                               0x00080307UL   
#define TAG_PRIVATE_DATA_ELEMENT                                                                  0x00080308UL   
#define TAG_PRIVATE_DATA_ELEMENT_VALUE_MULTIPLICITY                                               0x00080309UL   
#define TAG_PRIVATE_DATA_ELEMENT_VALUE_REPRESENTATION                                             0x0008030AUL   
#define TAG_PRIVATE_DATA_ELEMENT_NUMBER_OF_ITEMS                                                  0x0008030BUL   
#define TAG_PRIVATE_DATA_ELEMENT_NAME                                                             0x0008030CUL   
#define TAG_PRIVATE_DATA_ELEMENT_KEYWORD                                                          0x0008030DUL   
#define TAG_PRIVATE_DATA_ELEMENT_DESCRIPTION                                                      0x0008030EUL   
#define TAG_PRIVATE_DATA_ELEMENT_ENCODING                                                         0x0008030FUL   
#define TAG_PRIVATE_DATA_ELEMENT_DEFINITION_SEQUENCE                                              0x00080310UL   
#define TAG_NETWORK_ID                                                                            0x00081000UL   // Retired
#define TAG_STATION_NAME                                                                          0x00081010UL   
#define TAG_STUDY_DESCRIPTION                                                                     0x00081030UL   
#define TAG_PROCEDURE_CODE_SEQUENCE                                                               0x00081032UL   
#define TAG_SERIES_DESCRIPTION                                                                    0x0008103EUL   
#define TAG_SERIES_DESCRIPTION_CODE_SEQUENCE                                                      0x0008103FUL   
#define TAG_INSTITUTIONAL_DEPARTMENT_NAME                                                         0x00081040UL   
#define TAG_INSTITUTIONAL_DEPARTMENT_TYPE_CODE_SEQUENCE                                           0x00081041UL   
#define TAG_PHYSICIAN_OF_RECORD                                                                   0x00081048UL   
#define TAG_PHYSICIAN_OF_RECORD_IDENTIFICATION_SEQUENCE                                           0x00081049UL   
#define TAG_PERFORMING_PHYSICIAN_NAME                                                             0x00081050UL   
#define TAG_PERFORMING_PHYSICIAN_IDENTIFICATION_SEQUENCE                                          0x00081052UL   
#define TAG_NAME_OF_PHYSICIAN_READING_STUDY                                                       0x00081060UL   
#define TAG_PHYSICIAN_READING_STUDY_IDENTIFICATION_SEQUENCE                                       0x00081062UL   
#define TAG_OPERATORS_NAME                                                                        0x00081070UL   
#define TAG_OPERATOR_IDENTIFICATION_SEQUENCE                                                      0x00081072UL   
#define TAG_ADMITTING_DIAGNOSES_DESCRIPTION                                                       0x00081080UL   
#define TAG_ADMITTING_DIAGNOSES_CODE_SEQUENCE                                                     0x00081084UL   
#define TAG_MANUFACTURER_MODEL_NAME                                                               0x00081090UL   
#define TAG_REFERENCED_RESULTS_SEQUENCE                                                           0x00081100UL   // Retired
#define TAG_REFERENCED_STUDY_SEQUENCE                                                             0x00081110UL   
#define TAG_REFERENCED_PERFORMED_PROCEDURE_STEP_SEQUENCE                                          0x00081111UL   
#define TAG_REFERENCED_SERIES_SEQUENCE                                                            0x00081115UL   
#define TAG_REFERENCED_PATIENT_SEQUENCE                                                           0x00081120UL   
#define TAG_REFERENCED_VISIT_SEQUENCE                                                             0x00081125UL   
#define TAG_REFERENCED_OVERLAY_SEQUENCE                                                           0x00081130UL   // Retired
#define TAG_REFERENCED_STEREOMETRIC_INSTANCE_SEQUENCE                                             0x00081134UL   
#define TAG_REFERENCED_WAVEFORM_SEQUENCE                                                          0x0008113AUL   
#define TAG_REFERENCED_IMAGE_SEQUENCE                                                             0x00081140UL   
#define TAG_REFERENCED_CURVE_SEQUENCE                                                             0x00081145UL   // Retired
#define TAG_REFERENCED_INSTANCE_SEQUENCE                                                          0x0008114AUL   
#define TAG_REFERENCED_REAL_WORLD_VALUE_MAPPING_INSTANCE_SEQUENCE                                 0x0008114BUL   
#define TAG_REFERENCED_SOP_CLASS_UID                                                              0x00081150UL   
#define TAG_REFERENCED_SOP_INSTANCE_UID                                                           0x00081155UL   
#define TAG_DEFINITION_SOURCE_SEQUENCE                                                            0x00081156UL   
#define TAG_SOP_CLASSES_SUPPORTED                                                                 0x0008115AUL   
#define TAG_REFERENCED_FRAME_NUMBER                                                               0x00081160UL   
#define TAG_SIMPLE_FRAME_LIST                                                                     0x00081161UL   
#define TAG_CALCULATED_FRAME_LIST                                                                 0x00081162UL   
#define TAG_TIME_RANGE                                                                            0x00081163UL   
#define TAG_FRAME_EXTRACTION_SEQUENCE                                                             0x00081164UL   
#define TAG_MULTI_FRAME_SOURCE_SOP_INSTANCE_UID                                                   0x00081167UL   
#define TAG_RETRIEVE_URL                                                                          0x00081190UL   
#define TAG_TRANSACTION_UID                                                                       0x00081195UL   
#define TAG_WARNING_REASON                                                                        0x00081196UL   
#define TAG_FAILURE_REASON                                                                        0x00081197UL   
#define TAG_FAILED_SOP_SEQUENCE                                                                   0x00081198UL   
#define TAG_REFERENCED_SOP_SEQUENCE                                                               0x00081199UL   
#define TAG_OTHER_FAILURES_SEQUENCE                                                               0x0008119AUL   
#define TAG_STUDIES_CONTAINING_OTHER_REFERENCED_INSTANCES_SEQUENCE                                0x00081200UL   
#define TAG_RELATED_SERIES_SEQUENCE                                                               0x00081250UL   
#define TAG_LOSSY_IMAGE_COMPRESSION_RETIRED                                                       0x00082110UL   // Retired
#define TAG_DERIVATION_DESCRIPTION                                                                0x00082111UL   
#define TAG_SOURCE_IMAGE_SEQUENCE                                                                 0x00082112UL   
#define TAG_STAGE_NAME                                                                            0x00082120UL   
#define TAG_STAGE_NUMBER                                                                          0x00082122UL   
#define TAG_NUMBER_OF_STAGES                                                                      0x00082124UL   
#define TAG_VIEW_NAME                                                                             0x00082127UL   
#define TAG_VIEW_NUMBER                                                                           0x00082128UL   
#define TAG_NUMBER_OF_EVENT_TIMERS                                                                0x00082129UL   
#define TAG_NUMBER_OF_VIEWS_IN_STAGE                                                              0x0008212AUL   
#define TAG_EVENT_ELAPSED_TIME                                                                    0x00082130UL   
#define TAG_EVENT_TIMER_NAME                                                                      0x00082132UL   
#define TAG_EVENT_TIMER_SEQUENCE                                                                  0x00082133UL   
#define TAG_EVENT_TIME_OFFSET                                                                     0x00082134UL   
#define TAG_EVENT_CODE_SEQUENCE                                                                   0x00082135UL   
#define TAG_START_TRIM                                                                            0x00082142UL   
#define TAG_STOP_TRIM                                                                             0x00082143UL   
#define TAG_RECOMMENDED_DISPLAY_FRAME_RATE                                                        0x00082144UL   
#define TAG_TRANSDUCER_POSITION                                                                   0x00082200UL   // Retired
#define TAG_TRANSDUCER_ORIENTATION                                                                0x00082204UL   // Retired
#define TAG_ANATOMIC_STRUCTURE                                                                    0x00082208UL   // Retired
#define TAG_ANATOMIC_REGION_SEQUENCE                                                              0x00082218UL   
#define TAG_ANATOMIC_REGION_MODIFIER_SEQUENCE                                                     0x00082220UL   
#define TAG_PRIMARY_ANATOMIC_STRUCTURE_SEQUENCE                                                   0x00082228UL   
#define TAG_ANATOMIC_STRUCTURE_SPACE_OR_REGION_SEQUENCE                                           0x00082229UL   // Retired
#define TAG_PRIMARY_ANATOMIC_STRUCTURE_MODIFIER_SEQUENCE                                          0x00082230UL   
#define TAG_TRANSDUCER_POSITION_SEQUENCE                                                          0x00082240UL   // Retired
#define TAG_TRANSDUCER_POSITION_MODIFIER_SEQUENCE                                                 0x00082242UL   // Retired
#define TAG_TRANSDUCER_ORIENTATION_SEQUENCE                                                       0x00082244UL   // Retired
#define TAG_TRANSDUCER_ORIENTATION_MODIFIER_SEQUENCE                                              0x00082246UL   // Retired
#define TAG_ANATOMIC_STRUCTURE_SPACE_OR_REGION_CODE_SEQUENCE_TRIAL                                0x00082251UL   // Retired
#define TAG_ANATOMIC_PORTAL_OF_ENTRANCE_CODE_SEQUENCE_TRIAL                                       0x00082253UL   // Retired
#define TAG_ANATOMIC_APPROACH_DIRECTION_CODE_SEQUENCE_TRIAL                                       0x00082255UL   // Retired
#define TAG_ANATOMIC_PERSPECTIVE_DESCRIPTION_TRIAL                                                0x00082256UL   // Retired
#define TAG_ANATOMIC_PERSPECTIVE_CODE_SEQUENCE_TRIAL                                              0x00082257UL   // Retired
#define TAG_ANATOMIC_LOCATION_OF_EXAMINING_INSTRUMENT_DESCRIPTION_TRIAL                           0x00082258UL   // Retired
#define TAG_ANATOMIC_LOCATION_OF_EXAMINING_INSTRUMENT_CODE_SEQUENCE_TRIAL                         0x00082259UL   // Retired
#define TAG_ANATOMIC_STRUCTURE_SPACE_OR_REGION_MODIFIER_CODE_SEQUENCE_TRIAL                       0x0008225AUL   // Retired
#define TAG_ON_AXIS_BACKGROUND_ANATOMIC_STRUCTURE_CODE_SEQUENCE_TRIAL                             0x0008225CUL   // Retired
#define TAG_ALTERNATE_REPRESENTATION_SEQUENCE                                                     0x00083001UL   
#define TAG_AVAILABLE_TRANSFER_SYNTAX_UID                                                         0x00083002UL   
#define TAG_IRRADIATION_EVENT_UID                                                                 0x00083010UL   
#define TAG_SOURCE_IRRADIATION_EVENT_SEQUENCE                                                     0x00083011UL   
#define TAG_RADIOPHARMACEUTICAL_ADMINISTRATION_EVENT_UID                                          0x00083012UL   
#define TAG_IDENTIFYING_COMMENTS                                                                  0x00084000UL   // Retired
#define TAG_FRAME_TYPE                                                                            0x00089007UL   
#define TAG_REFERENCED_IMAGE_EVIDENCE_SEQUENCE                                                    0x00089092UL   
#define TAG_REFERENCED_RAW_DATA_SEQUENCE                                                          0x00089121UL   
#define TAG_CREATOR_VERSION_UID                                                                   0x00089123UL   
#define TAG_DERIVATION_IMAGE_SEQUENCE                                                             0x00089124UL   
#define TAG_SOURCE_IMAGE_EVIDENCE_SEQUENCE                                                        0x00089154UL   
#define TAG_PIXEL_PRESENTATION                                                                    0x00089205UL   
#define TAG_VOLUMETRIC_PROPERTIES                                                                 0x00089206UL   
#define TAG_VOLUME_BASED_CALCULATION_TECHNIQUE                                                    0x00089207UL   
#define TAG_COMPLEX_IMAGE_COMPONENT                                                               0x00089208UL   
#define TAG_ACQUISITION_CONTRAST                                                                  0x00089209UL   
#define TAG_DERIVATION_CODE_SEQUENCE                                                              0x00089215UL   
#define TAG_REFERENCED_PRESENTATION_STATE_SEQUENCE                                                0x00089237UL   
#define TAG_REFERENCED_OTHER_PLANE_SEQUENCE                                                       0x00089410UL   
#define TAG_FRAME_DISPLAY_SEQUENCE                                                                0x00089458UL   
#define TAG_RECOMMENDED_DISPLAY_FRAME_RATE_IN_FLOAT                                               0x00089459UL   
#define TAG_SKIP_FRAME_RANGE_FLAG                                                                 0x00089460UL   

// *****************************************************************************************************************************
// *** 0010
// *****************************************************************************************************************************
#define TAG_PATIENT_NAME                                                                          0x00100010UL   
#define TAG_PATIENT_ID                                                                            0x00100020UL   
#define TAG_ISSUER_OF_PATIENT_ID                                                                  0x00100021UL   
#define TAG_TYPE_OF_PATIENT_ID                                                                    0x00100022UL   
#define TAG_ISSUER_OF_PATIENT_ID_QUALIFIERS_SEQUENCE                                              0x00100024UL   
#define TAG_SOURCE_PATIENT_GROUP_IDENTIFICATION_SEQUENCE                                          0x00100026UL   
#define TAG_GROUP_OF_PATIENTS_IDENTIFICATION_SEQUENCE                                             0x00100027UL   
#define TAG_SUBJECT_RELATIVE_POSITION_IN_IMAGE                                                    0x00100028UL   
#define TAG_PATIENT_BIRTH_DATE                                                                    0x00100030UL   
#define TAG_PATIENT_BIRTH_TIME                                                                    0x00100032UL   
#define TAG_PATIENT_BIRTH_DATE_IN_ALTERNATIVE_CALENDAR                                            0x00100033UL   
#define TAG_PATIENT_DEATH_DATE_IN_ALTERNATIVE_CALENDAR                                            0x00100034UL   
#define TAG_PATIENT_ALTERNATIVE_CALENDAR                                                          0x00100035UL   
#define TAG_PATIENT_SEX                                                                           0x00100040UL   
#define TAG_PATIENT_INSURANCE_PLAN_CODE_SEQUENCE                                                  0x00100050UL   
#define TAG_PATIENT_PRIMARY_LANGUAGE_CODE_SEQUENCE                                                0x00100101UL   
#define TAG_PATIENT_PRIMARY_LANGUAGE_MODIFIER_CODE_SEQUENCE                                       0x00100102UL   
#define TAG_QUALITY_CONTROL_SUBJECT                                                               0x00100200UL   
#define TAG_QUALITY_CONTROL_SUBJECT_TYPE_CODE_SEQUENCE                                            0x00100201UL   
#define TAG_STRAIN_DESCRIPTION                                                                    0x00100212UL   
#define TAG_STRAIN_NOMENCLATURE                                                                   0x00100213UL   
#define TAG_STRAIN_STOCK_NUMBER                                                                   0x00100214UL   
#define TAG_STRAIN_SOURCE_REGISTRY_CODE_SEQUENCE                                                  0x00100215UL   
#define TAG_STRAIN_STOCK_SEQUENCE                                                                 0x00100216UL   
#define TAG_STRAIN_SOURCE                                                                         0x00100217UL   
#define TAG_STRAIN_ADDITIONAL_INFORMATION                                                         0x00100218UL   
#define TAG_STRAIN_CODE_SEQUENCE                                                                  0x00100219UL   
#define TAG_GENETIC_MODIFICATIONS_SEQUENCE                                                        0x00100221UL   
#define TAG_GENETIC_MODIFICATIONS_DESCRIPTION                                                     0x00100222UL   
#define TAG_GENETIC_MODIFICATIONS_NOMENCLATURE                                                    0x00100223UL   
#define TAG_GENETIC_MODIFICATIONS_CODE_SEQUENCE                                                   0x00100229UL   
#define TAG_OTHER_PATIENT_IDS                                                                     0x00101000UL   // Retired
#define TAG_OTHER_PATIENT_NAMES                                                                   0x00101001UL   
#define TAG_OTHER_PATIENT_IDS_SEQUENCE                                                            0x00101002UL   
#define TAG_PATIENT_BIRTH_NAME                                                                    0x00101005UL   
#define TAG_PATIENT_AGE                                                                           0x00101010UL   
#define TAG_PATIENT_SIZE                                                                          0x00101020UL   
#define TAG_PATIENT_SIZE_CODE_SEQUENCE                                                            0x00101021UL   
#define TAG_PATIENT_BODY_MASS_INDEX                                                               0x00101022UL   
#define TAG_MEASURED_AP_DIMENSION                                                                 0x00101023UL   
#define TAG_MEASURED_LATERAL_DIMENSION                                                            0x00101024UL   
#define TAG_PATIENT_WEIGHT                                                                        0x00101030UL   
#define TAG_PATIENT_ADDRESS                                                                       0x00101040UL   
#define TAG_INSURANCE_PLAN_IDENTIFICATION                                                         0x00101050UL   // Retired
#define TAG_PATIENT_MOTHER_BIRTH_NAME                                                             0x00101060UL   
#define TAG_MILITARY_RANK                                                                         0x00101080UL   
#define TAG_BRANCH_OF_SERVICE                                                                     0x00101081UL   
#define TAG_MEDICAL_RECORD_LOCATOR                                                                0x00101090UL   // Retired
#define TAG_REFERENCED_PATIENT_PHOTO_SEQUENCE                                                     0x00101100UL   
#define TAG_MEDICAL_ALERTS                                                                        0x00102000UL   
#define TAG_ALLERGIES                                                                             0x00102110UL   
#define TAG_COUNTRY_OF_RESIDENCE                                                                  0x00102150UL   
#define TAG_REGION_OF_RESIDENCE                                                                   0x00102152UL   
#define TAG_PATIENT_TELEPHONE_NUMBERS                                                             0x00102154UL   
#define TAG_PATIENT_TELECOM_INFORMATION                                                           0x00102155UL   
#define TAG_ETHNIC_GROUP                                                                          0x00102160UL   
#define TAG_OCCUPATION                                                                            0x00102180UL   
#define TAG_SMOKING_STATUS                                                                        0x001021A0UL   
#define TAG_ADDITIONAL_PATIENT_HISTORY                                                            0x001021B0UL   
#define TAG_PREGNANCY_STATUS                                                                      0x001021C0UL   
#define TAG_LAST_MENSTRUAL_DATE                                                                   0x001021D0UL   
#define TAG_PATIENT_RELIGIOUS_PREFERENCE                                                          0x001021F0UL   
#define TAG_PATIENT_SPECIES_DESCRIPTION                                                           0x00102201UL   
#define TAG_PATIENT_SPECIES_CODE_SEQUENCE                                                         0x00102202UL   
#define TAG_PATIENT_SEX_NEUTERED                                                                  0x00102203UL   
#define TAG_ANATOMICAL_ORIENTATION_TYPE                                                           0x00102210UL   
#define TAG_PATIENT_BREED_DESCRIPTION                                                             0x00102292UL   
#define TAG_PATIENT_BREED_CODE_SEQUENCE                                                           0x00102293UL   
#define TAG_BREED_REGISTRATION_SEQUENCE                                                           0x00102294UL   
#define TAG_BREED_REGISTRATION_NUMBER                                                             0x00102295UL   
#define TAG_BREED_REGISTRY_CODE_SEQUENCE                                                          0x00102296UL   
#define TAG_RESPONSIBLE_PERSON                                                                    0x00102297UL   
#define TAG_RESPONSIBLE_PERSON_ROLE                                                               0x00102298UL   
#define TAG_RESPONSIBLE_ORGANIZATION                                                              0x00102299UL   
#define TAG_PATIENT_COMMENTS                                                                      0x00104000UL   
#define TAG_EXAMINED_BODY_THICKNESS                                                               0x00109431UL   

// *****************************************************************************************************************************
// *** 0012
// *****************************************************************************************************************************
#define TAG_CLINICAL_TRIAL_SPONSOR_NAME                                                           0x00120010UL   
#define TAG_CLINICAL_TRIAL_PROTOCOL_ID                                                            0x00120020UL   
#define TAG_CLINICAL_TRIAL_PROTOCOL_NAME                                                          0x00120021UL   
#define TAG_CLINICAL_TRIAL_SITE_ID                                                                0x00120030UL   
#define TAG_CLINICAL_TRIAL_SITE_NAME                                                              0x00120031UL   
#define TAG_CLINICAL_TRIAL_SUBJECT_ID                                                             0x00120040UL   
#define TAG_CLINICAL_TRIAL_SUBJECT_READING_ID                                                     0x00120042UL   
#define TAG_CLINICAL_TRIAL_TIME_POINT_ID                                                          0x00120050UL   
#define TAG_CLINICAL_TRIAL_TIME_POINT_DESCRIPTION                                                 0x00120051UL   
#define TAG_LONGITUDINAL_TEMPORAL_OFFSET_FROM_EVENT                                               0x00120052UL   
#define TAG_LONGITUDINAL_TEMPORAL_EVENT_TYPE                                                      0x00120053UL   
#define TAG_CLINICAL_TRIAL_COORDINATING_CENTER_NAME                                               0x00120060UL   
#define TAG_PATIENT_IDENTITY_REMOVED                                                              0x00120062UL   
#define TAG_DE_IDENTIFICATION_METHOD                                                              0x00120063UL   
#define TAG_DE_IDENTIFICATION_METHOD_CODE_SEQUENCE                                                0x00120064UL   
#define TAG_CLINICAL_TRIAL_SERIES_ID                                                              0x00120071UL   
#define TAG_CLINICAL_TRIAL_SERIES_DESCRIPTION                                                     0x00120072UL   
#define TAG_CLINICAL_TRIAL_PROTOCOL_ETHICS_COMMITTEE_NAME                                         0x00120081UL   
#define TAG_CLINICAL_TRIAL_PROTOCOL_ETHICS_COMMITTEE_APPROVAL_NUMBER                              0x00120082UL   
#define TAG_CONSENT_FOR_CLINICAL_TRIAL_USE_SEQUENCE                                               0x00120083UL   
#define TAG_DISTRIBUTION_TYPE                                                                     0x00120084UL   
#define TAG_CONSENT_FOR_DISTRIBUTION_FLAG                                                         0x00120085UL   
#define TAG_ETHICS_COMMITTEE_APPROVAL_EFFECTIVENESS_START_DATE                                    0x00120086UL   
#define TAG_ETHICS_COMMITTEE_APPROVAL_EFFECTIVENESS_END_DATE                                      0x00120087UL   

// *****************************************************************************************************************************
// *** 0014
// *****************************************************************************************************************************
#define TAG_CAD_FILE_FORMAT                                                                       0x00140023UL   // Retired
#define TAG_COMPONENT_REFERENCE_SYSTEM                                                            0x00140024UL   // Retired
#define TAG_COMPONENT_MANUFACTURING_PROCEDURE                                                     0x00140025UL   
#define TAG_COMPONENT_MANUFACTURER                                                                0x00140028UL   
#define TAG_MATERIAL_THICKNESS                                                                    0x00140030UL   
#define TAG_MATERIAL_PIPE_DIAMETER                                                                0x00140032UL   
#define TAG_MATERIAL_ISOLATION_DIAMETER                                                           0x00140034UL   
#define TAG_MATERIAL_GRADE                                                                        0x00140042UL   
#define TAG_MATERIAL_PROPERTIES_DESCRIPTION                                                       0x00140044UL   
#define TAG_MATERIAL_PROPERTIES_FILE_FORMAT                                                       0x00140045UL   // Retired
#define TAG_MATERIAL_NOTES                                                                        0x00140046UL   
#define TAG_COMPONENT_SHAPE                                                                       0x00140050UL   
#define TAG_CURVATURE_TYPE                                                                        0x00140052UL   
#define TAG_OUTER_DIAMETER                                                                        0x00140054UL   
#define TAG_INNER_DIAMETER                                                                        0x00140056UL   
#define TAG_COMPONENT_WELDER_IDS                                                                  0x00140100UL   
#define TAG_SECONDARY_APPROVAL_STATUS                                                             0x00140101UL   
#define TAG_SECONDARY_REVIEW_DATE                                                                 0x00140102UL   
#define TAG_SECONDARY_REVIEW_TIME                                                                 0x00140103UL   
#define TAG_SECONDARY_REVIEWER_NAME                                                               0x00140104UL   
#define TAG_REPAIR_ID                                                                             0x00140105UL   
#define TAG_MULTIPLE_COMPONENT_APPROVAL_SEQUENCE                                                  0x00140106UL   
#define TAG_OTHER_APPROVAL_STATUS                                                                 0x00140107UL   
#define TAG_OTHER_SECONDARY_APPROVAL_STATUS                                                       0x00140108UL   
#define TAG_ACTUAL_ENVIRONMENTAL_CONDITIONS                                                       0x00141010UL   
#define TAG_EXPIRY_DATE                                                                           0x00141020UL   
#define TAG_ENVIRONMENTAL_CONDITIONS                                                              0x00141040UL   
#define TAG_EVALUATOR_SEQUENCE                                                                    0x00142002UL   
#define TAG_EVALUATOR_NUMBER                                                                      0x00142004UL   
#define TAG_EVALUATOR_NAME                                                                        0x00142006UL   
#define TAG_EVALUATION_ATTEMPT                                                                    0x00142008UL   
#define TAG_INDICATION_SEQUENCE                                                                   0x00142012UL   
#define TAG_INDICATION_NUMBER                                                                     0x00142014UL   
#define TAG_INDICATION_LABEL                                                                      0x00142016UL   
#define TAG_INDICATION_DESCRIPTION                                                                0x00142018UL   
#define TAG_INDICATION_TYPE                                                                       0x0014201AUL   
#define TAG_INDICATION_DISPOSITION                                                                0x0014201CUL   
#define TAG_INDICATION_ROI_SEQUENCE                                                               0x0014201EUL   
#define TAG_INDICATION_PHYSICAL_PROPERTY_SEQUENCE                                                 0x00142030UL   
#define TAG_PROPERTY_LABEL                                                                        0x00142032UL   
#define TAG_COORDINATE_SYSTEM_NUMBER_OF_AXES                                                      0x00142202UL   
#define TAG_COORDINATE_SYSTEM_AXES_SEQUENCE                                                       0x00142204UL   
#define TAG_COORDINATE_SYSTEM_AXIS_DESCRIPTION                                                    0x00142206UL   
#define TAG_COORDINATE_SYSTEM_DATA_SET_MAPPING                                                    0x00142208UL   
#define TAG_COORDINATE_SYSTEM_AXIS_NUMBER                                                         0x0014220AUL   
#define TAG_COORDINATE_SYSTEM_AXIS_TYPE                                                           0x0014220CUL   
#define TAG_COORDINATE_SYSTEM_AXIS_UNITS                                                          0x0014220EUL   
#define TAG_COORDINATE_SYSTEM_AXIS_VALUES                                                         0x00142210UL   
#define TAG_COORDINATE_SYSTEM_TRANSFORM_SEQUENCE                                                  0x00142220UL   
#define TAG_TRANSFORM_DESCRIPTION                                                                 0x00142222UL   
#define TAG_TRANSFORM_NUMBER_OF_AXES                                                              0x00142224UL   
#define TAG_TRANSFORM_ORDER_OF_AXES                                                               0x00142226UL   
#define TAG_TRANSFORMED_AXIS_UNITS                                                                0x00142228UL   
#define TAG_COORDINATE_SYSTEM_TRANSFORM_ROTATION_AND_SCALE_MATRIX                                 0x0014222AUL   
#define TAG_COORDINATE_SYSTEM_TRANSFORM_TRANSLATION_MATRIX                                        0x0014222CUL   
#define TAG_INTERNAL_DETECTOR_FRAME_TIME                                                          0x00143011UL   
#define TAG_NUMBER_OF_FRAMES_INTEGRATED                                                           0x00143012UL   
#define TAG_DETECTOR_TEMPERATURE_SEQUENCE                                                         0x00143020UL   
#define TAG_SENSOR_NAME                                                                           0x00143022UL   
#define TAG_HORIZONTAL_OFFSET_OF_SENSOR                                                           0x00143024UL   
#define TAG_VERTICAL_OFFSET_OF_SENSOR                                                             0x00143026UL   
#define TAG_SENSOR_TEMPERATURE                                                                    0x00143028UL   
#define TAG_DARK_CURRENT_SEQUENCE                                                                 0x00143040UL   
#define TAG_DARK_CURRENT_COUNTS                                                                   0x00143050UL   
#define TAG_GAIN_CORRECTION_REFERENCE_SEQUENCE                                                    0x00143060UL   
#define TAG_AIR_COUNTS                                                                            0x00143070UL   
#define TAG_KV_USED_IN_GAIN_CALIBRATION                                                           0x00143071UL   
#define TAG_MA_USED_IN_GAIN_CALIBRATION                                                           0x00143072UL   
#define TAG_NUMBER_OF_FRAMES_USED_FOR_INTEGRATION                                                 0x00143073UL   
#define TAG_FILTER_MATERIAL_USED_IN_GAIN_CALIBRATION                                              0x00143074UL   
#define TAG_FILTER_THICKNESS_USED_IN_GAIN_CALIBRATION                                             0x00143075UL   
#define TAG_DATE_OF_GAIN_CALIBRATION                                                              0x00143076UL   
#define TAG_TIME_OF_GAIN_CALIBRATION                                                              0x00143077UL   
#define TAG_BAD_PIXEL_IMAGE                                                                       0x00143080UL   
#define TAG_CALIBRATION_NOTES                                                                     0x00143099UL   
#define TAG_PULSER_EQUIPMENT_SEQUENCE                                                             0x00144002UL   
#define TAG_PULSER_TYPE                                                                           0x00144004UL   
#define TAG_PULSER_NOTES                                                                          0x00144006UL   
#define TAG_RECEIVER_EQUIPMENT_SEQUENCE                                                           0x00144008UL   
#define TAG_AMPLIFIER_TYPE                                                                        0x0014400AUL   
#define TAG_RECEIVER_NOTES                                                                        0x0014400CUL   
#define TAG_PRE_AMPLIFIER_EQUIPMENT_SEQUENCE                                                      0x0014400EUL   
#define TAG_PRE_AMPLIFIER_NOTES                                                                   0x0014400FUL   
#define TAG_TRANSMIT_TRANSDUCER_SEQUENCE                                                          0x00144010UL   
#define TAG_RECEIVE_TRANSDUCER_SEQUENCE                                                           0x00144011UL   
#define TAG_NUMBER_OF_ELEMENTS                                                                    0x00144012UL   
#define TAG_ELEMENT_SHAPE                                                                         0x00144013UL   
#define TAG_ELEMENT_DIMENSION_A                                                                   0x00144014UL   
#define TAG_ELEMENT_DIMENSION_B                                                                   0x00144015UL   
#define TAG_ELEMENT_PITCH_A                                                                       0x00144016UL   
#define TAG_MEASURED_BEAM_DIMENSION_A                                                             0x00144017UL   
#define TAG_MEASURED_BEAM_DIMENSION_B                                                             0x00144018UL   
#define TAG_LOCATION_OF_MEASURED_BEAM_DIAMETER                                                    0x00144019UL   
#define TAG_NOMINAL_FREQUENCY                                                                     0x0014401AUL   
#define TAG_MEASURED_CENTER_FREQUENCY                                                             0x0014401BUL   
#define TAG_MEASURED_BANDWIDTH                                                                    0x0014401CUL   
#define TAG_ELEMENT_PITCH_B                                                                       0x0014401DUL   
#define TAG_PULSER_SETTINGS_SEQUENCE                                                              0x00144020UL   
#define TAG_PULSE_WIDTH                                                                           0x00144022UL   
#define TAG_EXCITATION_FREQUENCY                                                                  0x00144024UL   
#define TAG_MODULATION_TYPE                                                                       0x00144026UL   
#define TAG_DAMPING                                                                               0x00144028UL   
#define TAG_RECEIVER_SETTINGS_SEQUENCE                                                            0x00144030UL   
#define TAG_ACQUIRED_SOUNDPATH_LENGTH                                                             0x00144031UL   
#define TAG_ACQUISITION_COMPRESSION_TYPE                                                          0x00144032UL   
#define TAG_ACQUISITION_SAMPLE_SIZE                                                               0x00144033UL   
#define TAG_RECTIFIER_SMOOTHING                                                                   0x00144034UL   
#define TAG_DAC_SEQUENCE                                                                          0x00144035UL   
#define TAG_DAC_TYPE                                                                              0x00144036UL   
#define TAG_DAC_GAIN_POINTS                                                                       0x00144038UL   
#define TAG_DAC_TIME_POINTS                                                                       0x0014403AUL   
#define TAG_DAC_AMPLITUDE                                                                         0x0014403CUL   
#define TAG_PRE_AMPLIFIER_SETTINGS_SEQUENCE                                                       0x00144040UL   
#define TAG_TRANSMIT_TRANSDUCER_SETTINGS_SEQUENCE                                                 0x00144050UL   
#define TAG_RECEIVE_TRANSDUCER_SETTINGS_SEQUENCE                                                  0x00144051UL   
#define TAG_INCIDENT_ANGLE                                                                        0x00144052UL   
#define TAG_COUPLING_TECHNIQUE                                                                    0x00144054UL   
#define TAG_COUPLING_MEDIUM                                                                       0x00144056UL   
#define TAG_COUPLING_VELOCITY                                                                     0x00144057UL   
#define TAG_PROBE_CENTER_LOCATION_X                                                               0x00144058UL   
#define TAG_PROBE_CENTER_LOCATION_Z                                                               0x00144059UL   
#define TAG_SOUND_PATH_LENGTH                                                                     0x0014405AUL   
#define TAG_DELAY_LAW_IDENTIFIER                                                                  0x0014405CUL   
#define TAG_GATE_SETTINGS_SEQUENCE                                                                0x00144060UL   
#define TAG_GATE_THRESHOLD                                                                        0x00144062UL   
#define TAG_VELOCITY_OF_SOUND                                                                     0x00144064UL   
#define TAG_CALIBRATION_SETTINGS_SEQUENCE                                                         0x00144070UL   
#define TAG_CALIBRATION_PROCEDURE                                                                 0x00144072UL   
#define TAG_PROCEDURE_VERSION                                                                     0x00144074UL   
#define TAG_PROCEDURE_CREATION_DATE                                                               0x00144076UL   
#define TAG_PROCEDURE_EXPIRATION_DATE                                                             0x00144078UL   
#define TAG_PROCEDURE_LAST_MODIFIED_DATE                                                          0x0014407AUL   
#define TAG_CALIBRATION_TIME                                                                      0x0014407CUL   
#define TAG_CALIBRATION_DATE                                                                      0x0014407EUL   
#define TAG_PROBE_DRIVE_EQUIPMENT_SEQUENCE                                                        0x00144080UL   
#define TAG_DRIVE_TYPE                                                                            0x00144081UL   
#define TAG_PROBE_DRIVE_NOTES                                                                     0x00144082UL   
#define TAG_DRIVE_PROBE_SEQUENCE                                                                  0x00144083UL   
#define TAG_PROBE_INDUCTANCE                                                                      0x00144084UL   
#define TAG_PROBE_RESISTANCE                                                                      0x00144085UL   
#define TAG_RECEIVE_PROBE_SEQUENCE                                                                0x00144086UL   
#define TAG_PROBE_DRIVE_SETTINGS_SEQUENCE                                                         0x00144087UL   
#define TAG_BRIDGE_RESISTORS                                                                      0x00144088UL   
#define TAG_PROBE_ORIENTATION_ANGLE                                                               0x00144089UL   
#define TAG_USER_SELECTED_GAIN_Y                                                                  0x0014408BUL   
#define TAG_USER_SELECTED_PHASE                                                                   0x0014408CUL   
#define TAG_USER_SELECTED_OFFSET_X                                                                0x0014408DUL   
#define TAG_USER_SELECTED_OFFSET_Y                                                                0x0014408EUL   
#define TAG_CHANNEL_SETTINGS_SEQUENCE                                                             0x00144091UL   
#define TAG_CHANNEL_THRESHOLD                                                                     0x00144092UL   
#define TAG_SCANNER_SETTINGS_SEQUENCE                                                             0x0014409AUL   
#define TAG_SCAN_PROCEDURE                                                                        0x0014409BUL   
#define TAG_TRANSLATION_RATE_X                                                                    0x0014409CUL   
#define TAG_TRANSLATION_RATE_Y                                                                    0x0014409DUL   
#define TAG_CHANNEL_OVERLAP                                                                       0x0014409FUL   
#define TAG_IMAGE_QUALITY_INDICATOR_TYPE                                                          0x001440A0UL   
#define TAG_IMAGE_QUALITY_INDICATOR_MATERIAL                                                      0x001440A1UL   
#define TAG_IMAGE_QUALITY_INDICATOR_SIZE                                                          0x001440A2UL   
#define TAG_LINAC_ENERGY                                                                          0x00145002UL   
#define TAG_LINAC_OUTPUT                                                                          0x00145004UL   
#define TAG_ACTIVE_APERTURE                                                                       0x00145100UL   
#define TAG_TOTAL_APERTURE                                                                        0x00145101UL   
#define TAG_APERTURE_ELEVATION                                                                    0x00145102UL   
#define TAG_MAIN_LOBE_ANGLE                                                                       0x00145103UL   
#define TAG_MAIN_ROOF_ANGLE                                                                       0x00145104UL   
#define TAG_CONNECTOR_TYPE                                                                        0x00145105UL   
#define TAG_WEDGE_MODEL_NUMBER                                                                    0x00145106UL   
#define TAG_WEDGE_ANGLE_FLOAT                                                                     0x00145107UL   
#define TAG_WEDGE_ROOF_ANGLE                                                                      0x00145108UL   
#define TAG_WEDGE_ELEMENT_1_POSITION                                                              0x00145109UL   
#define TAG_WEDGE_MATERIAL_VELOCITY                                                               0x0014510AUL   
#define TAG_WEDGE_MATERIAL                                                                        0x0014510BUL   
#define TAG_WEDGE_OFFSET_Z                                                                        0x0014510CUL   
#define TAG_WEDGE_ORIGIN_OFFSET_X                                                                 0x0014510DUL   
#define TAG_WEDGE_TIME_DELAY                                                                      0x0014510EUL   
#define TAG_WEDGE_NAME                                                                            0x0014510FUL   
#define TAG_WEDGE_MANUFACTURER_NAME                                                               0x00145110UL   
#define TAG_WEDGE_DESCRIPTION                                                                     0x00145111UL   
#define TAG_NOMINAL_BEAM_ANGLE                                                                    0x00145112UL   
#define TAG_WEDGE_OFFSET_X                                                                        0x00145113UL   
#define TAG_WEDGE_OFFSET_Y                                                                        0x00145114UL   
#define TAG_WEDGE_TOTAL_LENGTH                                                                    0x00145115UL   
#define TAG_WEDGE_IN_CONTACT_LENGTH                                                               0x00145116UL   
#define TAG_WEDGE_FRONT_GAP                                                                       0x00145117UL   
#define TAG_WEDGE_TOTAL_HEIGHT                                                                    0x00145118UL   
#define TAG_WEDGE_FRONT_HEIGHT                                                                    0x00145119UL   
#define TAG_WEDGE_REAR_HEIGHT                                                                     0x0014511AUL   
#define TAG_WEDGE_TOTAL_WIDTH                                                                     0x0014511BUL   
#define TAG_WEDGE_IN_CONTACT_WIDTH                                                                0x0014511CUL   
#define TAG_WEDGE_CHAMFER_HEIGHT                                                                  0x0014511DUL   
#define TAG_WEDGE_CURVE                                                                           0x0014511EUL   
#define TAG_RADIUS_ALONG_THE_WEDGE                                                                0x0014511FUL   

// *****************************************************************************************************************************
// *** 0016
// *****************************************************************************************************************************
#define TAG_WHITE_POINT                                                                           0x00160001UL   
#define TAG_PRIMARY_CHROMATICITIES                                                                0x00160002UL   
#define TAG_BATTERY_LEVEL                                                                         0x00160003UL   
#define TAG_EXPOSURE_TIME_IN_SECONDS                                                              0x00160004UL   
#define TAG_F_NUMBER                                                                              0x00160005UL   
#define TAG_OECF_ROWS                                                                             0x00160006UL   
#define TAG_OECF_COLUMNS                                                                          0x00160007UL   
#define TAG_OECF_COLUMN_NAMES                                                                     0x00160008UL   
#define TAG_OECF_VALUES                                                                           0x00160009UL   
#define TAG_SPATIAL_FREQUENCY_RESPONSE_ROWS                                                       0x0016000AUL   
#define TAG_SPATIAL_FREQUENCY_RESPONSE_COLUMNS                                                    0x0016000BUL   
#define TAG_SPATIAL_FREQUENCY_RESPONSE_COLUMN_NAMES                                               0x0016000CUL   
#define TAG_SPATIAL_FREQUENCY_RESPONSE_VALUES                                                     0x0016000DUL   
#define TAG_COLOR_FILTER_ARRAY_PATTERN_ROWS                                                       0x0016000EUL   
#define TAG_COLOR_FILTER_ARRAY_PATTERN_COLUMNS                                                    0x0016000FUL   
#define TAG_COLOR_FILTER_ARRAY_PATTERN_VALUES                                                     0x00160010UL   
#define TAG_FLASH_FIRING_STATUS                                                                   0x00160011UL   
#define TAG_FLASH_RETURN_STATUS                                                                   0x00160012UL   
#define TAG_FLASH_MODE                                                                            0x00160013UL   
#define TAG_FLASH_FUNCTION_PRESENT                                                                0x00160014UL   
#define TAG_FLASH_RED_EYE_MODE                                                                    0x00160015UL   
#define TAG_EXPOSURE_PROGRAM                                                                      0x00160016UL   
#define TAG_SPECTRAL_SENSITIVITY                                                                  0x00160017UL   
#define TAG_PHOTOGRAPHIC_SENSITIVITY                                                              0x00160018UL   
#define TAG_SELF_TIMER_MODE                                                                       0x00160019UL   
#define TAG_SENSITIVITY_TYPE                                                                      0x0016001AUL   
#define TAG_STANDARD_OUTPUT_SENSITIVITY                                                           0x0016001BUL   
#define TAG_RECOMMENDED_EXPOSURE_INDEX                                                            0x0016001CUL   
#define TAG_ISO_SPEED                                                                             0x0016001DUL   
#define TAG_ISO_SPEED_LATITUDE_YYY                                                                0x0016001EUL   
#define TAG_ISO_SPEED_LATITUDE_ZZZ                                                                0x0016001FUL   
#define TAG_EXIF_VERSION                                                                          0x00160020UL   
#define TAG_SHUTTER_SPEED_VALUE                                                                   0x00160021UL   
#define TAG_APERTURE_VALUE                                                                        0x00160022UL   
#define TAG_BRIGHTNESS_VALUE                                                                      0x00160023UL   
#define TAG_EXPOSURE_BIAS_VALUE                                                                   0x00160024UL   
#define TAG_MAX_APERTURE_VALUE                                                                    0x00160025UL   
#define TAG_SUBJECT_DISTANCE                                                                      0x00160026UL   
#define TAG_METERING_MODE                                                                         0x00160027UL   
#define TAG_LIGHT_SOURCE                                                                          0x00160028UL   
#define TAG_FOCAL_LENGTH                                                                          0x00160029UL   
#define TAG_SUBJECT_AREA                                                                          0x0016002AUL   
#define TAG_MAKER_NOTE                                                                            0x0016002BUL   
#define TAG_TEMPERATURE                                                                           0x00160030UL   
#define TAG_HUMIDITY                                                                              0x00160031UL   
#define TAG_PRESSURE                                                                              0x00160032UL   
#define TAG_WATER_DEPTH                                                                           0x00160033UL   
#define TAG_ACCELERATION                                                                          0x00160034UL   
#define TAG_CAMERA_ELEVATION_ANGLE                                                                0x00160035UL   
#define TAG_FLASH_ENERGY                                                                          0x00160036UL   
#define TAG_SUBJECT_LOCATION                                                                      0x00160037UL   
#define TAG_PHOTOGRAPHIC_EXPOSURE_INDEX                                                           0x00160038UL   
#define TAG_SENSING_METHOD                                                                        0x00160039UL   
#define TAG_FILE_SOURCE                                                                           0x0016003AUL   
#define TAG_SCENE_TYPE                                                                            0x0016003BUL   
#define TAG_CUSTOM_RENDERED                                                                       0x00160041UL   
#define TAG_EXPOSURE_MODE                                                                         0x00160042UL   
#define TAG_WHITE_BALANCE                                                                         0x00160043UL   
#define TAG_DIGITAL_ZOOM_RATIO                                                                    0x00160044UL   
#define TAG_FOCAL_LENGTH_IN_35MM_FILM                                                             0x00160045UL   
#define TAG_SCENE_CAPTURE_TYPE                                                                    0x00160046UL   
#define TAG_GAIN_CONTROL                                                                          0x00160047UL   
#define TAG_CONTRAST                                                                              0x00160048UL   
#define TAG_SATURATION                                                                            0x00160049UL   
#define TAG_SHARPNESS                                                                             0x0016004AUL   
#define TAG_DEVICE_SETTING_DESCRIPTION                                                            0x0016004BUL   
#define TAG_SUBJECT_DISTANCE_RANGE                                                                0x0016004CUL   
#define TAG_CAMERA_OWNER_NAME                                                                     0x0016004DUL   
#define TAG_LENS_SPECIFICATION                                                                    0x0016004EUL   
#define TAG_LENS_MAKE                                                                             0x0016004FUL   
#define TAG_LENS_MODEL                                                                            0x00160050UL   
#define TAG_LENS_SERIAL_NUMBER                                                                    0x00160051UL   
#define TAG_INTEROPERABILITY_INDEX                                                                0x00160061UL   
#define TAG_INTEROPERABILITY_VERSION                                                              0x00160062UL   
#define TAG_GPS_VERSION_ID                                                                        0x00160070UL   
#define TAG_GPS_LATITUDE_REF                                                                      0x00160071UL   
#define TAG_GPS_LATITUDE                                                                          0x00160072UL   
#define TAG_GPS_LONGITUDE_REF                                                                     0x00160073UL   
#define TAG_GPS_LONGITUDE                                                                         0x00160074UL   
#define TAG_GPS_ALTITUDE_REF                                                                      0x00160075UL   
#define TAG_GPS_ALTITUDE                                                                          0x00160076UL   
#define TAG_GPS_TIME_STAMP                                                                        0x00160077UL   
#define TAG_GPS_SATELLITES                                                                        0x00160078UL   
#define TAG_GPS_STATUS                                                                            0x00160079UL   
#define TAG_GPS_MEASURE_MODE                                                                      0x0016007AUL   
#define TAG_GPS_DOP                                                                               0x0016007BUL   
#define TAG_GPS_SPEED_REF                                                                         0x0016007CUL   
#define TAG_GPS_SPEED                                                                             0x0016007DUL   
#define TAG_GPS_TRACK_REF                                                                         0x0016007EUL   
#define TAG_GPS_TRACK                                                                             0x0016007FUL   
#define TAG_GPS_IMG_DIRECTION_REF                                                                 0x00160080UL   
#define TAG_GPS_IMG_DIRECTION                                                                     0x00160081UL   
#define TAG_GPS_MAP_DATUM                                                                         0x00160082UL   
#define TAG_GPS_DEST_LATITUDE_REF                                                                 0x00160083UL   
#define TAG_GPS_DEST_LATITUDE                                                                     0x00160084UL   
#define TAG_GPS_DEST_LONGITUDE_REF                                                                0x00160085UL   
#define TAG_GPS_DEST_LONGITUDE                                                                    0x00160086UL   
#define TAG_GPS_DEST_BEARING_REF                                                                  0x00160087UL   
#define TAG_GPS_DEST_BEARING                                                                      0x00160088UL   
#define TAG_GPS_DEST_DISTANCE_REF                                                                 0x00160089UL   
#define TAG_GPS_DEST_DISTANCE                                                                     0x0016008AUL   
#define TAG_GPS_PROCESSING_METHOD                                                                 0x0016008BUL   
#define TAG_GPS_AREA_INFORMATION                                                                  0x0016008CUL   
#define TAG_GPS_DATE_STAMP                                                                        0x0016008DUL   
#define TAG_GPS_DIFFERENTIAL                                                                      0x0016008EUL   
#define TAG_LIGHT_SOURCE_POLARIZATION                                                             0x00161001UL   
#define TAG_EMITTER_COLOR_TEMPERATURE                                                             0x00161002UL   
#define TAG_CONTACT_METHOD                                                                        0x00161003UL   
#define TAG_IMMERSION_MEDIA                                                                       0x00161004UL   
#define TAG_OPTICAL_MAGNIFICATION_FACTOR                                                          0x00161005UL   

// *****************************************************************************************************************************
// *** 0018
// *****************************************************************************************************************************
#define TAG_CONTRAST_BOLUS_AGENT                                                                  0x00180010UL   
#define TAG_CONTRAST_BOLUS_AGENT_SEQUENCE                                                         0x00180012UL   
#define TAG_CONTRAST_BOLUS_T1_RELAXIVITY                                                          0x00180013UL   
#define TAG_CONTRAST_BOLUS_ADMINISTRATION_ROUTE_SEQUENCE                                          0x00180014UL   
#define TAG_BODY_PART_EXAMINED                                                                    0x00180015UL   
#define TAG_SCANNING_SEQUENCE                                                                     0x00180020UL   
#define TAG_SEQUENCE_VARIANT                                                                      0x00180021UL   
#define TAG_SCAN_OPTIONS                                                                          0x00180022UL   
#define TAG_MR_ACQUISITION_TYPE                                                                   0x00180023UL   
#define TAG_SEQUENCE_NAME                                                                         0x00180024UL   
#define TAG_ANGIO_FLAG                                                                            0x00180025UL   
#define TAG_INTERVENTION_DRUG_INFORMATION_SEQUENCE                                                0x00180026UL   
#define TAG_INTERVENTION_DRUG_STOP_TIME                                                           0x00180027UL   
#define TAG_INTERVENTION_DRUG_DOSE                                                                0x00180028UL   
#define TAG_INTERVENTION_DRUG_CODE_SEQUENCE                                                       0x00180029UL   
#define TAG_ADDITIONAL_DRUG_SEQUENCE                                                              0x0018002AUL   
#define TAG_RADIONUCLIDE                                                                          0x00180030UL   // Retired
#define TAG_RADIOPHARMACEUTICAL                                                                   0x00180031UL   
#define TAG_ENERGY_WINDOW_CENTERLINE                                                              0x00180032UL   // Retired
#define TAG_ENERGY_WINDOW_TOTAL_WIDTH                                                             0x00180033UL   // Retired
#define TAG_INTERVENTION_DRUG_NAME                                                                0x00180034UL   
#define TAG_INTERVENTION_DRUG_START_TIME                                                          0x00180035UL   
#define TAG_INTERVENTION_SEQUENCE                                                                 0x00180036UL   
#define TAG_THERAPY_TYPE                                                                          0x00180037UL   // Retired
#define TAG_INTERVENTION_STATUS                                                                   0x00180038UL   
#define TAG_THERAPY_DESCRIPTION                                                                   0x00180039UL   // Retired
#define TAG_INTERVENTION_DESCRIPTION                                                              0x0018003AUL   
#define TAG_CINE_RATE                                                                             0x00180040UL   
#define TAG_INITIAL_CINE_RUN_STATE                                                                0x00180042UL   
#define TAG_SLICE_THICKNESS                                                                       0x00180050UL   
#define TAG_KVP                                                                                   0x00180060UL   
#define TAG_COUNTS_ACCUMULATED                                                                    0x00180070UL   
#define TAG_ACQUISITION_TERMINATION_CONDITION                                                     0x00180071UL   
#define TAG_EFFECTIVE_DURATION                                                                    0x00180072UL   
#define TAG_ACQUISITION_START_CONDITION                                                           0x00180073UL   
#define TAG_ACQUISITION_START_CONDITION_DATA                                                      0x00180074UL   
#define TAG_ACQUISITION_TERMINATION_CONDITION_DATA                                                0x00180075UL   
#define TAG_REPETITION_TIME                                                                       0x00180080UL   
#define TAG_ECHO_TIME                                                                             0x00180081UL   
#define TAG_INVERSION_TIME                                                                        0x00180082UL   
#define TAG_NUMBER_OF_AVERAGES                                                                    0x00180083UL   
#define TAG_IMAGING_FREQUENCY                                                                     0x00180084UL   
#define TAG_IMAGED_NUCLEUS                                                                        0x00180085UL   
#define TAG_ECHO_NUMBER                                                                           0x00180086UL   
#define TAG_MAGNETIC_FIELD_STRENGTH                                                               0x00180087UL   
#define TAG_SPACING_BETWEEN_SLICES                                                                0x00180088UL   
#define TAG_NUMBER_OF_PHASE_ENCODING_STEPS                                                        0x00180089UL   
#define TAG_DATA_COLLECTION_DIAMETER                                                              0x00180090UL   
#define TAG_ECHO_TRAIN_LENGTH                                                                     0x00180091UL   
#define TAG_PERCENT_SAMPLING                                                                      0x00180093UL   
#define TAG_PERCENT_PHASE_FIELD_OF_VIEW                                                           0x00180094UL   
#define TAG_PIXEL_BANDWIDTH                                                                       0x00180095UL   
#define TAG_DEVICE_SERIAL_NUMBER                                                                  0x00181000UL   
#define TAG_DEVICE_UID                                                                            0x00181002UL   
#define TAG_DEVICE_ID                                                                             0x00181003UL   
#define TAG_PLATE_ID                                                                              0x00181004UL   
#define TAG_GENERATOR_ID                                                                          0x00181005UL   
#define TAG_GRID_ID                                                                               0x00181006UL   
#define TAG_CASSETTE_ID                                                                           0x00181007UL   
#define TAG_GANTRY_ID                                                                             0x00181008UL   
#define TAG_UNIQUE_DEVICE_IDENTIFIER                                                              0x00181009UL   
#define TAG_UDI_SEQUENCE                                                                          0x0018100AUL   
#define TAG_MANUFACTURER_DEVICE_CLASS_UID                                                         0x0018100BUL   
#define TAG_SECONDARY_CAPTURE_DEVICE_ID                                                           0x00181010UL   
#define TAG_HARDCOPY_CREATION_DEVICE_ID                                                           0x00181011UL   // Retired
#define TAG_DATE_OF_SECONDARY_CAPTURE                                                             0x00181012UL   
#define TAG_TIME_OF_SECONDARY_CAPTURE                                                             0x00181014UL   
#define TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURER                                                 0x00181016UL   
#define TAG_HARDCOPY_DEVICE_MANUFACTURER                                                          0x00181017UL   // Retired
#define TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURER_MODEL_NAME                                      0x00181018UL   
#define TAG_SECONDARY_CAPTURE_DEVICE_SOFTWARE_VERSIONS                                            0x00181019UL   
#define TAG_HARDCOPY_DEVICE_SOFTWARE_VERSION                                                      0x0018101AUL   // Retired
#define TAG_HARDCOPY_DEVICE_MANUFACTURER_MODEL_NAME                                               0x0018101BUL   // Retired
#define TAG_SOFTWARE_VERSIONS                                                                     0x00181020UL   
#define TAG_VIDEO_IMAGE_FORMAT_ACQUIRED                                                           0x00181022UL   
#define TAG_DIGITAL_IMAGE_FORMAT_ACQUIRED                                                         0x00181023UL   
#define TAG_PROTOCOL_NAME                                                                         0x00181030UL   
#define TAG_CONTRAST_BOLUS_ROUTE                                                                  0x00181040UL   
#define TAG_CONTRAST_BOLUS_VOLUME                                                                 0x00181041UL   
#define TAG_CONTRAST_BOLUS_START_TIME                                                             0x00181042UL   
#define TAG_CONTRAST_BOLUS_STOP_TIME                                                              0x00181043UL   
#define TAG_CONTRAST_BOLUS_TOTAL_DOSE                                                             0x00181044UL   
#define TAG_SYRINGE_COUNTS                                                                        0x00181045UL   
#define TAG_CONTRAST_FLOW_RATE                                                                    0x00181046UL   
#define TAG_CONTRAST_FLOW_DURATION                                                                0x00181047UL   
#define TAG_CONTRAST_BOLUS_INGREDIENT                                                             0x00181048UL   
#define TAG_CONTRAST_BOLUS_INGREDIENT_CONCENTRATION                                               0x00181049UL   
#define TAG_SPATIAL_RESOLUTION                                                                    0x00181050UL   
#define TAG_TRIGGER_TIME                                                                          0x00181060UL   
#define TAG_TRIGGER_SOURCE_OR_TYPE                                                                0x00181061UL   
#define TAG_NOMINAL_INTERVAL                                                                      0x00181062UL   
#define TAG_FRAME_TIME                                                                            0x00181063UL   
#define TAG_CARDIAC_FRAMING_TYPE                                                                  0x00181064UL   
#define TAG_FRAME_TIME_VECTOR                                                                     0x00181065UL   
#define TAG_FRAME_DELAY                                                                           0x00181066UL   
#define TAG_IMAGE_TRIGGER_DELAY                                                                   0x00181067UL   
#define TAG_MULTIPLEX_GROUP_TIME_OFFSET                                                           0x00181068UL   
#define TAG_TRIGGER_TIME_OFFSET                                                                   0x00181069UL   
#define TAG_SYNCHRONIZATION_TRIGGER                                                               0x0018106AUL   
#define TAG_SYNCHRONIZATION_CHANNEL                                                               0x0018106CUL   
#define TAG_TRIGGER_SAMPLE_POSITION                                                               0x0018106EUL   
#define TAG_RADIOPHARMACEUTICAL_ROUTE                                                             0x00181070UL   
#define TAG_RADIOPHARMACEUTICAL_VOLUME                                                            0x00181071UL   
#define TAG_RADIOPHARMACEUTICAL_START_TIME                                                        0x00181072UL   
#define TAG_RADIOPHARMACEUTICAL_STOP_TIME                                                         0x00181073UL   
#define TAG_RADIONUCLIDE_TOTAL_DOSE                                                               0x00181074UL   
#define TAG_RADIONUCLIDE_HALF_LIFE                                                                0x00181075UL   
#define TAG_RADIONUCLIDE_POSITRON_FRACTION                                                        0x00181076UL   
#define TAG_RADIOPHARMACEUTICAL_SPECIFIC_ACTIVITY                                                 0x00181077UL   
#define TAG_RADIOPHARMACEUTICAL_START_DATETIME                                                    0x00181078UL   
#define TAG_RADIOPHARMACEUTICAL_STOP_DATETIME                                                     0x00181079UL   
#define TAG_BEAT_REJECTION_FLAG                                                                   0x00181080UL   
#define TAG_LOW_R_R_VALUE                                                                         0x00181081UL   
#define TAG_HIGH_R_R_VALUE                                                                        0x00181082UL   
#define TAG_INTERVALS_ACQUIRED                                                                    0x00181083UL   
#define TAG_INTERVALS_REJECTED                                                                    0x00181084UL   
#define TAG_PVC_REJECTION                                                                         0x00181085UL   
#define TAG_SKIP_BEATS                                                                            0x00181086UL   
#define TAG_HEART_RATE                                                                            0x00181088UL   
#define TAG_CARDIAC_NUMBER_OF_IMAGES                                                              0x00181090UL   
#define TAG_TRIGGER_WINDOW                                                                        0x00181094UL   
#define TAG_RECONSTRUCTION_DIAMETER                                                               0x00181100UL   
#define TAG_DISTANCE_SOURCE_TO_DETECTOR                                                           0x00181110UL   
#define TAG_DISTANCE_SOURCE_TO_PATIENT                                                            0x00181111UL   
#define TAG_ESTIMATED_RADIOGRAPHIC_MAGNIFICATION_FACTOR                                           0x00181114UL   
#define TAG_GANTRY_DETECTOR_TILT                                                                  0x00181120UL   
#define TAG_GANTRY_DETECTOR_SLEW                                                                  0x00181121UL   
#define TAG_TABLE_HEIGHT                                                                          0x00181130UL   
#define TAG_TABLE_TRAVERSE                                                                        0x00181131UL   
#define TAG_TABLE_MOTION                                                                          0x00181134UL   
#define TAG_TABLE_VERTICAL_INCREMENT                                                              0x00181135UL   
#define TAG_TABLE_LATERAL_INCREMENT                                                               0x00181136UL   
#define TAG_TABLE_LONGITUDINAL_INCREMENT                                                          0x00181137UL   
#define TAG_TABLE_ANGLE                                                                           0x00181138UL   
#define TAG_TABLE_TYPE                                                                            0x0018113AUL   
#define TAG_ROTATION_DIRECTION                                                                    0x00181140UL   
#define TAG_ANGULAR_POSITION                                                                      0x00181141UL   // Retired
#define TAG_RADIAL_POSITION                                                                       0x00181142UL   
#define TAG_SCAN_ARC                                                                              0x00181143UL   
#define TAG_ANGULAR_STEP                                                                          0x00181144UL   
#define TAG_CENTER_OF_ROTATION_OFFSET                                                             0x00181145UL   
#define TAG_ROTATION_OFFSET                                                                       0x00181146UL   // Retired
#define TAG_FIELD_OF_VIEW_SHAPE                                                                   0x00181147UL   
#define TAG_FIELD_OF_VIEW_DIMENSION                                                               0x00181149UL   
#define TAG_EXPOSURE_TIME                                                                         0x00181150UL   
#define TAG_X_RAY_TUBE_CURRENT                                                                    0x00181151UL   
#define TAG_EXPOSURE                                                                              0x00181152UL   
#define TAG_EXPOSURE_IN_UAS                                                                       0x00181153UL   
#define TAG_AVERAGE_PULSE_WIDTH                                                                   0x00181154UL   
#define TAG_RADIATION_SETTING                                                                     0x00181155UL   
#define TAG_RECTIFICATION_TYPE                                                                    0x00181156UL   
#define TAG_RADIATION_MODE                                                                        0x0018115AUL   
#define TAG_IMAGE_AND_FLUOROSCOPY_AREA_DOSE_PRODUCT                                               0x0018115EUL   
#define TAG_FILTER_TYPE                                                                           0x00181160UL   
#define TAG_TYPE_OF_FILTERS                                                                       0x00181161UL   
#define TAG_INTENSIFIER_SIZE                                                                      0x00181162UL   
#define TAG_IMAGER_PIXEL_SPACING                                                                  0x00181164UL   
#define TAG_GRID                                                                                  0x00181166UL   
#define TAG_GENERATOR_POWER                                                                       0x00181170UL   
#define TAG_COLLIMATOR_GRID_NAME                                                                  0x00181180UL   
#define TAG_COLLIMATOR_TYPE                                                                       0x00181181UL   
#define TAG_FOCAL_DISTANCE                                                                        0x00181182UL   
#define TAG_X_FOCUS_CENTER                                                                        0x00181183UL   
#define TAG_Y_FOCUS_CENTER                                                                        0x00181184UL   
#define TAG_FOCAL_SPOT                                                                            0x00181190UL   
#define TAG_ANODE_TARGET_MATERIAL                                                                 0x00181191UL   
#define TAG_BODY_PART_THICKNESS                                                                   0x001811A0UL   
#define TAG_COMPRESSION_FORCE                                                                     0x001811A2UL   
#define TAG_COMPRESSION_PRESSURE                                                                  0x001811A3UL   
#define TAG_PADDLE_DESCRIPTION                                                                    0x001811A4UL   
#define TAG_COMPRESSION_CONTACT_AREA                                                              0x001811A5UL   
#define TAG_ACQUISITION_MODE                                                                      0x001811B0UL   
#define TAG_DOSE_MODE_NAME                                                                        0x001811B1UL   
#define TAG_ACQUIRED_SUBTRACTION_MASK_FLAG                                                        0x001811B2UL   
#define TAG_FLUOROSCOPY_PERSISTENCE_FLAG                                                          0x001811B3UL   
#define TAG_FLUOROSCOPY_LAST_IMAGE_HOLD_PERSISTENCE_FLAG                                          0x001811B4UL   
#define TAG_UPPER_LIMIT_NUMBER_OF_PERSISTENT_FLUOROSCOPY_FRAMES                                   0x001811B5UL   
#define TAG_CONTRAST_BOLUS_AUTO_INJECTION_TRIGGER_FLAG                                            0x001811B6UL   
#define TAG_CONTRAST_BOLUS_INJECTION_DELAY                                                        0x001811B7UL   
#define TAG_XA_ACQUISITION_PHASE_DETAILS_SEQUENCE                                                 0x001811B8UL   
#define TAG_XA_ACQUISITION_FRAME_RATE                                                             0x001811B9UL   
#define TAG_XA_PLANE_DETAILS_SEQUENCE                                                             0x001811BAUL   
#define TAG_ACQUISITION_FIELD_OF_VIEW_LABEL                                                       0x001811BBUL   
#define TAG_X_RAY_FILTER_DETAILS_SEQUENCE                                                         0x001811BCUL   
#define TAG_XA_ACQUISITION_DURATION                                                               0x001811BDUL   
#define TAG_RECONSTRUCTION_PIPELINE_TYPE                                                          0x001811BEUL   
#define TAG_IMAGE_FILTER_DETAILS_SEQUENCE                                                         0x001811BFUL   
#define TAG_APPLIED_MASK_SUBTRACTION_FLAG                                                         0x001811C0UL   
#define TAG_REQUESTED_SERIES_DESCRIPTION_CODE_SEQUENCE                                            0x001811C1UL   
#define TAG_DATE_OF_LAST_CALIBRATION                                                              0x00181200UL   
#define TAG_TIME_OF_LAST_CALIBRATION                                                              0x00181201UL   
#define TAG_DATETIME_OF_LAST_CALIBRATION                                                          0x00181202UL   
#define TAG_CONVOLUTION_KERNEL                                                                    0x00181210UL   
#define TAG_UPPER_LOWER_PIXEL_VALUES                                                              0x00181240UL   // Retired
#define TAG_ACTUAL_FRAME_DURATION                                                                 0x00181242UL   
#define TAG_COUNT_RATE                                                                            0x00181243UL   
#define TAG_PREFERRED_PLAYBACK_SEQUENCING                                                         0x00181244UL   
#define TAG_RECEIVE_COIL_NAME                                                                     0x00181250UL   
#define TAG_TRANSMIT_COIL_NAME                                                                    0x00181251UL   
#define TAG_PLATE_TYPE                                                                            0x00181260UL   
#define TAG_PHOSPHOR_TYPE                                                                         0x00181261UL   
#define TAG_WATER_EQUIVALENT_DIAMETER                                                             0x00181271UL   
#define TAG_WATER_EQUIVALENT_DIAMETER_CALCULATION_METHOD_CODE_SEQUENCE                            0x00181272UL   
#define TAG_SCAN_VELOCITY                                                                         0x00181300UL   
#define TAG_WHOLE_BODY_TECHNIQUE                                                                  0x00181301UL   
#define TAG_SCAN_LENGTH                                                                           0x00181302UL   
#define TAG_ACQUISITION_MATRIX                                                                    0x00181310UL   
#define TAG_IN_PLANE_PHASE_ENCODING_DIRECTION                                                     0x00181312UL   
#define TAG_FLIP_ANGLE                                                                            0x00181314UL   
#define TAG_VARIABLE_FLIP_ANGLE_FLAG                                                              0x00181315UL   
#define TAG_SAR                                                                                   0x00181316UL   
#define TAG_DB_DT                                                                                 0x00181318UL   
#define TAG_B1RMS                                                                                 0x00181320UL   
#define TAG_ACQUISITION_DEVICE_PROCESSING_DESCRIPTION                                             0x00181400UL   
#define TAG_ACQUISITION_DEVICE_PROCESSING_CODE                                                    0x00181401UL   
#define TAG_CASSETTE_ORIENTATION                                                                  0x00181402UL   
#define TAG_CASSETTE_SIZE                                                                         0x00181403UL   
#define TAG_EXPOSURES_ON_PLATE                                                                    0x00181404UL   
#define TAG_RELATIVE_X_RAY_EXPOSURE                                                               0x00181405UL   
#define TAG_EXPOSURE_INDEX                                                                        0x00181411UL   
#define TAG_TARGET_EXPOSURE_INDEX                                                                 0x00181412UL   
#define TAG_DEVIATION_INDEX                                                                       0x00181413UL   
#define TAG_COLUMN_ANGULATION                                                                     0x00181450UL   
#define TAG_TOMO_LAYER_HEIGHT                                                                     0x00181460UL   
#define TAG_TOMO_ANGLE                                                                            0x00181470UL   
#define TAG_TOMO_TIME                                                                             0x00181480UL   
#define TAG_TOMO_TYPE                                                                             0x00181490UL   
#define TAG_TOMO_CLASS                                                                            0x00181491UL   
#define TAG_NUMBER_OF_TOMOSYNTHESIS_SOURCE_IMAGES                                                 0x00181495UL   
#define TAG_POSITIONER_MOTION                                                                     0x00181500UL   
#define TAG_POSITIONER_TYPE                                                                       0x00181508UL   
#define TAG_POSITIONER_PRIMARY_ANGLE                                                              0x00181510UL   
#define TAG_POSITIONER_SECONDARY_ANGLE                                                            0x00181511UL   
#define TAG_POSITIONER_PRIMARY_ANGLE_INCREMENT                                                    0x00181520UL   
#define TAG_POSITIONER_SECONDARY_ANGLE_INCREMENT                                                  0x00181521UL   
#define TAG_DETECTOR_PRIMARY_ANGLE                                                                0x00181530UL   
#define TAG_DETECTOR_SECONDARY_ANGLE                                                              0x00181531UL   
#define TAG_SHUTTER_SHAPE                                                                         0x00181600UL   
#define TAG_SHUTTER_LEFT_VERTICAL_EDGE                                                            0x00181602UL   
#define TAG_SHUTTER_RIGHT_VERTICAL_EDGE                                                           0x00181604UL   
#define TAG_SHUTTER_UPPER_HORIZONTAL_EDGE                                                         0x00181606UL   
#define TAG_SHUTTER_LOWER_HORIZONTAL_EDGE                                                         0x00181608UL   
#define TAG_CENTER_OF_CIRCULAR_SHUTTER                                                            0x00181610UL   
#define TAG_RADIUS_OF_CIRCULAR_SHUTTER                                                            0x00181612UL   
#define TAG_VERTICES_OF_THE_POLYGONAL_SHUTTER                                                     0x00181620UL   
#define TAG_SHUTTER_PRESENTATION_VALUE                                                            0x00181622UL   
#define TAG_SHUTTER_OVERLAY_GROUP                                                                 0x00181623UL   
#define TAG_SHUTTER_PRESENTATION_COLOR_CIELAB_VALUE                                               0x00181624UL   
#define TAG_OUTLINE_SHAPE_TYPE                                                                    0x00181630UL   
#define TAG_OUTLINE_LEFT_VERTICAL_EDGE                                                            0x00181631UL   
#define TAG_OUTLINE_RIGHT_VERTICAL_EDGE                                                           0x00181632UL   
#define TAG_OUTLINE_UPPER_HORIZONTAL_EDGE                                                         0x00181633UL   
#define TAG_OUTLINE_LOWER_HORIZONTAL_EDGE                                                         0x00181634UL   
#define TAG_CENTER_OF_CIRCULAR_OUTLINE                                                            0x00181635UL   
#define TAG_DIAMETER_OF_CIRCULAR_OUTLINE                                                          0x00181636UL   
#define TAG_NUMBER_OF_POLYGONAL_VERTICES                                                          0x00181637UL   
#define TAG_VERTICES_OF_THE_POLYGONAL_OUTLINE                                                     0x00181638UL   
#define TAG_COLLIMATOR_SHAPE                                                                      0x00181700UL   
#define TAG_COLLIMATOR_LEFT_VERTICAL_EDGE                                                         0x00181702UL   
#define TAG_COLLIMATOR_RIGHT_VERTICAL_EDGE                                                        0x00181704UL   
#define TAG_COLLIMATOR_UPPER_HORIZONTAL_EDGE                                                      0x00181706UL   
#define TAG_COLLIMATOR_LOWER_HORIZONTAL_EDGE                                                      0x00181708UL   
#define TAG_CENTER_OF_CIRCULAR_COLLIMATOR                                                         0x00181710UL   
#define TAG_RADIUS_OF_CIRCULAR_COLLIMATOR                                                         0x00181712UL   
#define TAG_VERTICES_OF_THE_POLYGONAL_COLLIMATOR                                                  0x00181720UL   
#define TAG_ACQUISITION_TIME_SYNCHRONIZED                                                         0x00181800UL   
#define TAG_TIME_SOURCE                                                                           0x00181801UL   
#define TAG_TIME_DISTRIBUTION_PROTOCOL                                                            0x00181802UL   
#define TAG_NTP_SOURCE_ADDRESS                                                                    0x00181803UL   
#define TAG_PAGE_NUMBER_VECTOR                                                                    0x00182001UL   
#define TAG_FRAME_LABEL_VECTOR                                                                    0x00182002UL   
#define TAG_FRAME_PRIMARY_ANGLE_VECTOR                                                            0x00182003UL   
#define TAG_FRAME_SECONDARY_ANGLE_VECTOR                                                          0x00182004UL   
#define TAG_SLICE_LOCATION_VECTOR                                                                 0x00182005UL   
#define TAG_DISPLAY_WINDOW_LABEL_VECTOR                                                           0x00182006UL   
#define TAG_NOMINAL_SCANNED_PIXEL_SPACING                                                         0x00182010UL   
#define TAG_DIGITIZING_DEVICE_TRANSPORT_DIRECTION                                                 0x00182020UL   
#define TAG_ROTATION_OF_SCANNED_FILM                                                              0x00182030UL   
#define TAG_BIOPSY_TARGET_SEQUENCE                                                                0x00182041UL   
#define TAG_TARGET_UID                                                                            0x00182042UL   
#define TAG_LOCALIZING_CURSOR_POSITION                                                            0x00182043UL   
#define TAG_CALCULATED_TARGET_POSITION                                                            0x00182044UL   
#define TAG_TARGET_LABEL                                                                          0x00182045UL   
#define TAG_DISPLAYED_Z_VALUE                                                                     0x00182046UL   
#define TAG_IVUS_ACQUISITION                                                                      0x00183100UL   
#define TAG_IVUS_PULLBACK_RATE                                                                    0x00183101UL   
#define TAG_IVUS_GATED_RATE                                                                       0x00183102UL   
#define TAG_IVUS_PULLBACK_START_FRAME_NUMBER                                                      0x00183103UL   
#define TAG_IVUS_PULLBACK_STOP_FRAME_NUMBER                                                       0x00183104UL   
#define TAG_LESION_NUMBER                                                                         0x00183105UL   
#define TAG_ACQUISITION_COMMENTS                                                                  0x00184000UL   // Retired
#define TAG_OUTPUT_POWER                                                                          0x00185000UL   
#define TAG_TRANSDUCER_DATA                                                                       0x00185010UL   
#define TAG_TRANSDUCER_IDENTIFICATION_SEQUENCE                                                    0x00185011UL   
#define TAG_FOCUS_DEPTH                                                                           0x00185012UL   
#define TAG_PROCESSING_FUNCTION                                                                   0x00185020UL   
#define TAG_POSTPROCESSING_FUNCTION                                                               0x00185021UL   // Retired
#define TAG_MECHANICAL_INDEX                                                                      0x00185022UL   
#define TAG_BONE_THERMAL_INDEX                                                                    0x00185024UL   
#define TAG_CRANIAL_THERMAL_INDEX                                                                 0x00185026UL   
#define TAG_SOFT_TISSUE_THERMAL_INDEX                                                             0x00185027UL   
#define TAG_SOFT_TISSUE_FOCUS_THERMAL_INDEX                                                       0x00185028UL   
#define TAG_SOFT_TISSUE_SURFACE_THERMAL_INDEX                                                     0x00185029UL   
#define TAG_DYNAMIC_RANGE                                                                         0x00185030UL   // Retired
#define TAG_TOTAL_GAIN                                                                            0x00185040UL   // Retired
#define TAG_DEPTH_OF_SCAN_FIELD                                                                   0x00185050UL   
#define TAG_PATIENT_POSITION                                                                      0x00185100UL   
#define TAG_VIEW_POSITION                                                                         0x00185101UL   
#define TAG_PROJECTION_EPONYMOUS_NAME_CODE_SEQUENCE                                               0x00185104UL   
#define TAG_IMAGE_TRANSFORMATION_MATRIX                                                           0x00185210UL   // Retired
#define TAG_IMAGE_TRANSLATION_VECTOR                                                              0x00185212UL   // Retired
#define TAG_SENSITIVITY                                                                           0x00186000UL   
#define TAG_SEQUENCE_OF_ULTRASOUND_REGIONS                                                        0x00186011UL   
#define TAG_REGION_SPATIAL_FORMAT                                                                 0x00186012UL   
#define TAG_REGION_DATA_TYPE                                                                      0x00186014UL   
#define TAG_REGION_FLAGS                                                                          0x00186016UL   
#define TAG_REGION_LOCATION_MIN_X0                                                                0x00186018UL   
#define TAG_REGION_LOCATION_MIN_Y0                                                                0x0018601AUL   
#define TAG_REGION_LOCATION_MAX_X1                                                                0x0018601CUL   
#define TAG_REGION_LOCATION_MAX_Y1                                                                0x0018601EUL   
#define TAG_REFERENCE_PIXEL_X0                                                                    0x00186020UL   
#define TAG_REFERENCE_PIXEL_Y0                                                                    0x00186022UL   
#define TAG_PHYSICAL_UNITS_X_DIRECTION                                                            0x00186024UL   
#define TAG_PHYSICAL_UNITS_Y_DIRECTION                                                            0x00186026UL   
#define TAG_REFERENCE_PIXEL_PHYSICAL_VALUE_X                                                      0x00186028UL   
#define TAG_REFERENCE_PIXEL_PHYSICAL_VALUE_Y                                                      0x0018602AUL   
#define TAG_PHYSICAL_DELTA_X                                                                      0x0018602CUL   
#define TAG_PHYSICAL_DELTA_Y                                                                      0x0018602EUL   
#define TAG_TRANSDUCER_FREQUENCY                                                                  0x00186030UL   
#define TAG_TRANSDUCER_TYPE                                                                       0x00186031UL   
#define TAG_PULSE_REPETITION_FREQUENCY                                                            0x00186032UL   
#define TAG_DOPPLER_CORRECTION_ANGLE                                                              0x00186034UL   
#define TAG_STEERING_ANGLE                                                                        0x00186036UL   
#define TAG_DOPPLER_SAMPLE_VOLUME_X_POSITION_RETIRED                                              0x00186038UL   // Retired
#define TAG_DOPPLER_SAMPLE_VOLUME_X_POSITION                                                      0x00186039UL   
#define TAG_DOPPLER_SAMPLE_VOLUME_Y_POSITION_RETIRED                                              0x0018603AUL   // Retired
#define TAG_DOPPLER_SAMPLE_VOLUME_Y_POSITION                                                      0x0018603BUL   
#define TAG_TM_LINE_POSITION_X0_RETIRED                                                           0x0018603CUL   // Retired
#define TAG_TM_LINE_POSITION_X0                                                                   0x0018603DUL   
#define TAG_TM_LINE_POSITION_Y0_RETIRED                                                           0x0018603EUL   // Retired
#define TAG_TM_LINE_POSITION_Y0                                                                   0x0018603FUL   
#define TAG_TM_LINE_POSITION_X1_RETIRED                                                           0x00186040UL   // Retired
#define TAG_TM_LINE_POSITION_X1                                                                   0x00186041UL   
#define TAG_TM_LINE_POSITION_Y1_RETIRED                                                           0x00186042UL   // Retired
#define TAG_TM_LINE_POSITION_Y1                                                                   0x00186043UL   
#define TAG_PIXEL_COMPONENT_ORGANIZATION                                                          0x00186044UL   
#define TAG_PIXEL_COMPONENT_MASK                                                                  0x00186046UL   
#define TAG_PIXEL_COMPONENT_RANGE_START                                                           0x00186048UL   
#define TAG_PIXEL_COMPONENT_RANGE_STOP                                                            0x0018604AUL   
#define TAG_PIXEL_COMPONENT_PHYSICAL_UNITS                                                        0x0018604CUL   
#define TAG_PIXEL_COMPONENT_DATA_TYPE                                                             0x0018604EUL   
#define TAG_NUMBER_OF_TABLE_BREAK_POINTS                                                          0x00186050UL   
#define TAG_TABLE_OF_X_BREAK_POINTS                                                               0x00186052UL   
#define TAG_TABLE_OF_Y_BREAK_POINTS                                                               0x00186054UL   
#define TAG_NUMBER_OF_TABLE_ENTRIES                                                               0x00186056UL   
#define TAG_TABLE_OF_PIXEL_VALUES                                                                 0x00186058UL   
#define TAG_TABLE_OF_PARAMETER_VALUES                                                             0x0018605AUL   
#define TAG_R_WAVE_TIME_VECTOR                                                                    0x00186060UL   
#define TAG_ACTIVE_IMAGE_AREA_OVERLAY_GROUP                                                       0x00186070UL   
#define TAG_DETECTOR_CONDITIONS_NOMINAL_FLAG                                                      0x00187000UL   
#define TAG_DETECTOR_TEMPERATURE                                                                  0x00187001UL   
#define TAG_DETECTOR_TYPE                                                                         0x00187004UL   
#define TAG_DETECTOR_CONFIGURATION                                                                0x00187005UL   
#define TAG_DETECTOR_DESCRIPTION                                                                  0x00187006UL   
#define TAG_DETECTOR_MODE                                                                         0x00187008UL   
#define TAG_DETECTOR_ID                                                                           0x0018700AUL   
#define TAG_DATE_OF_LAST_DETECTOR_CALIBRATION                                                     0x0018700CUL   
#define TAG_TIME_OF_LAST_DETECTOR_CALIBRATION                                                     0x0018700EUL   
#define TAG_EXPOSURES_ON_DETECTOR_SINCE_LAST_CALIBRATION                                          0x00187010UL   
#define TAG_EXPOSURES_ON_DETECTOR_SINCE_MANUFACTURED                                              0x00187011UL   
#define TAG_DETECTOR_TIME_SINCE_LAST_EXPOSURE                                                     0x00187012UL   
#define TAG_DETECTOR_ACTIVE_TIME                                                                  0x00187014UL   
#define TAG_DETECTOR_ACTIVATION_OFFSET_FROM_EXPOSURE                                              0x00187016UL   
#define TAG_DETECTOR_BINNING                                                                      0x0018701AUL   
#define TAG_DETECTOR_ELEMENT_PHYSICAL_SIZE                                                        0x00187020UL   
#define TAG_DETECTOR_ELEMENT_SPACING                                                              0x00187022UL   
#define TAG_DETECTOR_ACTIVE_SHAPE                                                                 0x00187024UL   
#define TAG_DETECTOR_ACTIVE_DIMENSION                                                             0x00187026UL   
#define TAG_DETECTOR_ACTIVE_ORIGIN                                                                0x00187028UL   
#define TAG_DETECTOR_MANUFACTURER_NAME                                                            0x0018702AUL   
#define TAG_DETECTOR_MANUFACTURER_MODEL_NAME                                                      0x0018702BUL   
#define TAG_FIELD_OF_VIEW_ORIGIN                                                                  0x00187030UL   
#define TAG_FIELD_OF_VIEW_ROTATION                                                                0x00187032UL   
#define TAG_FIELD_OF_VIEW_HORIZONTAL_FLIP                                                         0x00187034UL   
#define TAG_PIXEL_DATA_AREA_ORIGIN_RELATIVE_TO_FOV                                                0x00187036UL   
#define TAG_PIXEL_DATA_AREA_ROTATION_ANGLE_RELATIVE_TO_FOV                                        0x00187038UL   
#define TAG_GRID_ABSORBING_MATERIAL                                                               0x00187040UL   
#define TAG_GRID_SPACING_MATERIAL                                                                 0x00187041UL   
#define TAG_GRID_THICKNESS                                                                        0x00187042UL   
#define TAG_GRID_PITCH                                                                            0x00187044UL   
#define TAG_GRID_ASPECT_RATIO                                                                     0x00187046UL   
#define TAG_GRID_PERIOD                                                                           0x00187048UL   
#define TAG_GRID_FOCAL_DISTANCE                                                                   0x0018704CUL   
#define TAG_FILTER_MATERIAL                                                                       0x00187050UL   
#define TAG_FILTER_THICKNESS_MINIMUM                                                              0x00187052UL   
#define TAG_FILTER_THICKNESS_MAXIMUM                                                              0x00187054UL   
#define TAG_FILTER_BEAM_PATH_LENGTH_MINIMUM                                                       0x00187056UL   
#define TAG_FILTER_BEAM_PATH_LENGTH_MAXIMUM                                                       0x00187058UL   
#define TAG_EXPOSURE_CONTROL_MODE                                                                 0x00187060UL   
#define TAG_EXPOSURE_CONTROL_MODE_DESCRIPTION                                                     0x00187062UL   
#define TAG_EXPOSURE_STATUS                                                                       0x00187064UL   
#define TAG_PHOTOTIMER_SETTING                                                                    0x00187065UL   
#define TAG_EXPOSURE_TIME_IN_US                                                                   0x00188150UL   
#define TAG_X_RAY_TUBE_CURRENT_IN_UA                                                              0x00188151UL   
#define TAG_CONTENT_QUALIFICATION                                                                 0x00189004UL   
#define TAG_PULSE_SEQUENCE_NAME                                                                   0x00189005UL   
#define TAG_MR_IMAGING_MODIFIER_SEQUENCE                                                          0x00189006UL   
#define TAG_ECHO_PULSE_SEQUENCE                                                                   0x00189008UL   
#define TAG_INVERSION_RECOVERY                                                                    0x00189009UL   
#define TAG_FLOW_COMPENSATION                                                                     0x00189010UL   
#define TAG_MULTIPLE_SPIN_ECHO                                                                    0x00189011UL   
#define TAG_MULTI_PLANAR_EXCITATION                                                               0x00189012UL   
#define TAG_PHASE_CONTRAST                                                                        0x00189014UL   
#define TAG_TIME_OF_FLIGHT_CONTRAST                                                               0x00189015UL   
#define TAG_SPOILING                                                                              0x00189016UL   
#define TAG_STEADY_STATE_PULSE_SEQUENCE                                                           0x00189017UL   
#define TAG_ECHO_PLANAR_PULSE_SEQUENCE                                                            0x00189018UL   
#define TAG_TAG_ANGLE_FIRST_AXIS                                                                  0x00189019UL   
#define TAG_MAGNETIZATION_TRANSFER                                                                0x00189020UL   
#define TAG_T2_PREPARATION                                                                        0x00189021UL   
#define TAG_BLOOD_SIGNAL_NULLING                                                                  0x00189022UL   
#define TAG_SATURATION_RECOVERY                                                                   0x00189024UL   
#define TAG_SPECTRALLY_SELECTED_SUPPRESSION                                                       0x00189025UL   
#define TAG_SPECTRALLY_SELECTED_EXCITATION                                                        0x00189026UL   
#define TAG_SPATIAL_PRE_SATURATION                                                                0x00189027UL   
#define TAG_TAGGING                                                                               0x00189028UL   
#define TAG_OVERSAMPLING_PHASE                                                                    0x00189029UL   
#define TAG_TAG_SPACING_FIRST_DIMENSION                                                           0x00189030UL   
#define TAG_GEOMETRY_OF_K_SPACE_TRAVERSAL                                                         0x00189032UL   
#define TAG_SEGMENTED_K_SPACE_TRAVERSAL                                                           0x00189033UL   
#define TAG_RECTILINEAR_PHASE_ENCODE_REORDERING                                                   0x00189034UL   
#define TAG_TAG_THICKNESS                                                                         0x00189035UL   
#define TAG_PARTIAL_FOURIER_DIRECTION                                                             0x00189036UL   
#define TAG_CARDIAC_SYNCHRONIZATION_TECHNIQUE                                                     0x00189037UL   
#define TAG_RECEIVE_COIL_MANUFACTURER_NAME                                                        0x00189041UL   
#define TAG_MR_RECEIVE_COIL_SEQUENCE                                                              0x00189042UL   
#define TAG_RECEIVE_COIL_TYPE                                                                     0x00189043UL   
#define TAG_QUADRATURE_RECEIVE_COIL                                                               0x00189044UL   
#define TAG_MULTI_COIL_DEFINITION_SEQUENCE                                                        0x00189045UL   
#define TAG_MULTI_COIL_CONFIGURATION                                                              0x00189046UL   
#define TAG_MULTI_COIL_ELEMENT_NAME                                                               0x00189047UL   
#define TAG_MULTI_COIL_ELEMENT_USED                                                               0x00189048UL   
#define TAG_MR_TRANSMIT_COIL_SEQUENCE                                                             0x00189049UL   
#define TAG_TRANSMIT_COIL_MANUFACTURER_NAME                                                       0x00189050UL   
#define TAG_TRANSMIT_COIL_TYPE                                                                    0x00189051UL   
#define TAG_SPECTRAL_WIDTH                                                                        0x00189052UL   
#define TAG_CHEMICAL_SHIFT_REFERENCE                                                              0x00189053UL   
#define TAG_VOLUME_LOCALIZATION_TECHNIQUE                                                         0x00189054UL   
#define TAG_MR_ACQUISITION_FREQUENCY_ENCODING_STEPS                                               0x00189058UL   
#define TAG_DE_COUPLING                                                                           0x00189059UL   
#define TAG_DE_COUPLED_NUCLEUS                                                                    0x00189060UL   
#define TAG_DE_COUPLING_FREQUENCY                                                                 0x00189061UL   
#define TAG_DE_COUPLING_METHOD                                                                    0x00189062UL   
#define TAG_DE_COUPLING_CHEMICAL_SHIFT_REFERENCE                                                  0x00189063UL   
#define TAG_K_SPACE_FILTERING                                                                     0x00189064UL   
#define TAG_TIME_DOMAIN_FILTERING                                                                 0x00189065UL   
#define TAG_NUMBER_OF_ZERO_FILLS                                                                  0x00189066UL   
#define TAG_BASELINE_CORRECTION                                                                   0x00189067UL   
#define TAG_PARALLEL_REDUCTION_FACTOR_IN_PLANE                                                    0x00189069UL   
#define TAG_CARDIAC_R_R_INTERVAL_SPECIFIED                                                        0x00189070UL   
#define TAG_ACQUISITION_DURATION                                                                  0x00189073UL   
#define TAG_FRAME_ACQUISITION_DATETIME                                                            0x00189074UL   
#define TAG_DIFFUSION_DIRECTIONALITY                                                              0x00189075UL   
#define TAG_DIFFUSION_GRADIENT_DIRECTION_SEQUENCE                                                 0x00189076UL   
#define TAG_PARALLEL_ACQUISITION                                                                  0x00189077UL   
#define TAG_PARALLEL_ACQUISITION_TECHNIQUE                                                        0x00189078UL   
#define TAG_INVERSION_TIMES                                                                       0x00189079UL   
#define TAG_METABOLITE_MAP_DESCRIPTION                                                            0x00189080UL   
#define TAG_PARTIAL_FOURIER                                                                       0x00189081UL   
#define TAG_EFFECTIVE_ECHO_TIME                                                                   0x00189082UL   
#define TAG_METABOLITE_MAP_CODE_SEQUENCE                                                          0x00189083UL   
#define TAG_CHEMICAL_SHIFT_SEQUENCE                                                               0x00189084UL   
#define TAG_CARDIAC_SIGNAL_SOURCE                                                                 0x00189085UL   
#define TAG_DIFFUSION_B_VALUE                                                                     0x00189087UL   
#define TAG_DIFFUSION_GRADIENT_ORIENTATION                                                        0x00189089UL   
#define TAG_VELOCITY_ENCODING_DIRECTION                                                           0x00189090UL   
#define TAG_VELOCITY_ENCODING_MINIMUM_VALUE                                                       0x00189091UL   
#define TAG_VELOCITY_ENCODING_ACQUISITION_SEQUENCE                                                0x00189092UL   
#define TAG_NUMBER_OF_K_SPACE_TRAJECTORIES                                                        0x00189093UL   
#define TAG_COVERAGE_OF_K_SPACE                                                                   0x00189094UL   
#define TAG_SPECTROSCOPY_ACQUISITION_PHASE_ROWS                                                   0x00189095UL   
#define TAG_PARALLEL_REDUCTION_FACTOR_IN_PLANE_RETIRED                                            0x00189096UL   // Retired
#define TAG_TRANSMITTER_FREQUENCY                                                                 0x00189098UL   
#define TAG_RESONANT_NUCLEUS                                                                      0x00189100UL   
#define TAG_FREQUENCY_CORRECTION                                                                  0x00189101UL   
#define TAG_MR_SPECTROSCOPY_FOV_GEOMETRY_SEQUENCE                                                 0x00189103UL   
#define TAG_SLAB_THICKNESS                                                                        0x00189104UL   
#define TAG_SLAB_ORIENTATION                                                                      0x00189105UL   
#define TAG_MID_SLAB_POSITION                                                                     0x00189106UL   
#define TAG_MR_SPATIAL_SATURATION_SEQUENCE                                                        0x00189107UL   
#define TAG_MR_TIMING_AND_RELATED_PARAMETERS_SEQUENCE                                             0x00189112UL   
#define TAG_MR_ECHO_SEQUENCE                                                                      0x00189114UL   
#define TAG_MR_MODIFIER_SEQUENCE                                                                  0x00189115UL   
#define TAG_MR_DIFFUSION_SEQUENCE                                                                 0x00189117UL   
#define TAG_CARDIAC_SYNCHRONIZATION_SEQUENCE                                                      0x00189118UL   
#define TAG_MR_AVERAGES_SEQUENCE                                                                  0x00189119UL   
#define TAG_MR_FOV_GEOMETRY_SEQUENCE                                                              0x00189125UL   
#define TAG_VOLUME_LOCALIZATION_SEQUENCE                                                          0x00189126UL   
#define TAG_SPECTROSCOPY_ACQUISITION_DATA_COLUMNS                                                 0x00189127UL   
#define TAG_DIFFUSION_ANISOTROPY_TYPE                                                             0x00189147UL   
#define TAG_FRAME_REFERENCE_DATETIME                                                              0x00189151UL   
#define TAG_MR_METABOLITE_MAP_SEQUENCE                                                            0x00189152UL   
#define TAG_PARALLEL_REDUCTION_FACTOR_OUT_OF_PLANE                                                0x00189155UL   
#define TAG_SPECTROSCOPY_ACQUISITION_OUT_OF_PLANE_PHASE_STEPS                                     0x00189159UL   
#define TAG_BULK_MOTION_STATUS                                                                    0x00189166UL   // Retired
#define TAG_PARALLEL_REDUCTION_FACTOR_SECOND_IN_PLANE                                             0x00189168UL   
#define TAG_CARDIAC_BEAT_REJECTION_TECHNIQUE                                                      0x00189169UL   
#define TAG_RESPIRATORY_MOTION_COMPENSATION_TECHNIQUE                                             0x00189170UL   
#define TAG_RESPIRATORY_SIGNAL_SOURCE                                                             0x00189171UL   
#define TAG_BULK_MOTION_COMPENSATION_TECHNIQUE                                                    0x00189172UL   
#define TAG_BULK_MOTION_SIGNAL_SOURCE                                                             0x00189173UL   
#define TAG_APPLICABLE_SAFETY_STANDARD_AGENCY                                                     0x00189174UL   
#define TAG_APPLICABLE_SAFETY_STANDARD_DESCRIPTION                                                0x00189175UL   
#define TAG_OPERATING_MODE_SEQUENCE                                                               0x00189176UL   
#define TAG_OPERATING_MODE_TYPE                                                                   0x00189177UL   
#define TAG_OPERATING_MODE                                                                        0x00189178UL   
#define TAG_SPECIFIC_ABSORPTION_RATE_DEFINITION                                                   0x00189179UL   
#define TAG_GRADIENT_OUTPUT_TYPE                                                                  0x00189180UL   
#define TAG_SPECIFIC_ABSORPTION_RATE_VALUE                                                        0x00189181UL   
#define TAG_GRADIENT_OUTPUT                                                                       0x00189182UL   
#define TAG_FLOW_COMPENSATION_DIRECTION                                                           0x00189183UL   
#define TAG_TAGGING_DELAY                                                                         0x00189184UL   
#define TAG_RESPIRATORY_MOTION_COMPENSATION_TECHNIQUE_DESCRIPTION                                 0x00189185UL   
#define TAG_RESPIRATORY_SIGNAL_SOURCE_ID                                                          0x00189186UL   
#define TAG_CHEMICAL_SHIFT_MINIMUM_INTEGRATION_LIMIT_IN_HZ                                        0x00189195UL   // Retired
#define TAG_CHEMICAL_SHIFT_MAXIMUM_INTEGRATION_LIMIT_IN_HZ                                        0x00189196UL   // Retired
#define TAG_MR_VELOCITY_ENCODING_SEQUENCE                                                         0x00189197UL   
#define TAG_FIRST_ORDER_PHASE_CORRECTION                                                          0x00189198UL   
#define TAG_WATER_REFERENCED_PHASE_CORRECTION                                                     0x00189199UL   
#define TAG_MR_SPECTROSCOPY_ACQUISITION_TYPE                                                      0x00189200UL   
#define TAG_RESPIRATORY_CYCLE_POSITION                                                            0x00189214UL   
#define TAG_VELOCITY_ENCODING_MAXIMUM_VALUE                                                       0x00189217UL   
#define TAG_TAG_SPACING_SECOND_DIMENSION                                                          0x00189218UL   
#define TAG_TAG_ANGLE_SECOND_AXIS                                                                 0x00189219UL   
#define TAG_FRAME_ACQUISITION_DURATION                                                            0x00189220UL   
#define TAG_MR_IMAGE_FRAME_TYPE_SEQUENCE                                                          0x00189226UL   
#define TAG_MR_SPECTROSCOPY_FRAME_TYPE_SEQUENCE                                                   0x00189227UL   
#define TAG_MR_ACQUISITION_PHASE_ENCODING_STEPS_IN_PLANE                                          0x00189231UL   
#define TAG_MR_ACQUISITION_PHASE_ENCODING_STEPS_OUT_OF_PLANE                                      0x00189232UL   
#define TAG_SPECTROSCOPY_ACQUISITION_PHASE_COLUMNS                                                0x00189234UL   
#define TAG_CARDIAC_CYCLE_POSITION                                                                0x00189236UL   
#define TAG_SPECIFIC_ABSORPTION_RATE_SEQUENCE                                                     0x00189239UL   
#define TAG_RF_ECHO_TRAIN_LENGTH                                                                  0x00189240UL   
#define TAG_GRADIENT_ECHO_TRAIN_LENGTH                                                            0x00189241UL   
#define TAG_ARTERIAL_SPIN_LABELING_CONTRAST                                                       0x00189250UL   
#define TAG_MR_ARTERIAL_SPIN_LABELING_SEQUENCE                                                    0x00189251UL   
#define TAG_ASL_TECHNIQUE_DESCRIPTION                                                             0x00189252UL   
#define TAG_ASL_SLAB_NUMBER                                                                       0x00189253UL   
#define TAG_ASL_SLAB_THICKNESS                                                                    0x00189254UL   
#define TAG_ASL_SLAB_ORIENTATION                                                                  0x00189255UL   
#define TAG_ASL_MID_SLAB_POSITION                                                                 0x00189256UL   
#define TAG_ASL_CONTEXT                                                                           0x00189257UL   
#define TAG_ASL_PULSE_TRAIN_DURATION                                                              0x00189258UL   
#define TAG_ASL_CRUSHER_FLAG                                                                      0x00189259UL   
#define TAG_ASL_CRUSHER_FLOW_LIMIT                                                                0x0018925AUL   
#define TAG_ASL_CRUSHER_DESCRIPTION                                                               0x0018925BUL   
#define TAG_ASL_BOLUS_CUT_OFF_FLAG                                                                0x0018925CUL   
#define TAG_ASL_BOLUS_CUT_OFF_TIMING_SEQUENCE                                                     0x0018925DUL   
#define TAG_ASL_BOLUS_CUT_OFF_TECHNIQUE                                                           0x0018925EUL   
#define TAG_ASL_BOLUS_CUT_OFF_DELAY_TIME                                                          0x0018925FUL   
#define TAG_ASL_SLAB_SEQUENCE                                                                     0x00189260UL   
#define TAG_CHEMICAL_SHIFT_MINIMUM_INTEGRATION_LIMIT_IN_PPM                                       0x00189295UL   
#define TAG_CHEMICAL_SHIFT_MAXIMUM_INTEGRATION_LIMIT_IN_PPM                                       0x00189296UL   
#define TAG_WATER_REFERENCE_ACQUISITION                                                           0x00189297UL   
#define TAG_ECHO_PEAK_POSITION                                                                    0x00189298UL   
#define TAG_CT_ACQUISITION_TYPE_SEQUENCE                                                          0x00189301UL   
#define TAG_ACQUISITION_TYPE                                                                      0x00189302UL   
#define TAG_TUBE_ANGLE                                                                            0x00189303UL   
#define TAG_CT_ACQUISITION_DETAILS_SEQUENCE                                                       0x00189304UL   
#define TAG_REVOLUTION_TIME                                                                       0x00189305UL   
#define TAG_SINGLE_COLLIMATION_WIDTH                                                              0x00189306UL   
#define TAG_TOTAL_COLLIMATION_WIDTH                                                               0x00189307UL   
#define TAG_CT_TABLE_DYNAMICS_SEQUENCE                                                            0x00189308UL   
#define TAG_TABLE_SPEED                                                                           0x00189309UL   
#define TAG_TABLE_FEED_PER_ROTATION                                                               0x00189310UL   
#define TAG_SPIRAL_PITCH_FACTOR                                                                   0x00189311UL   
#define TAG_CT_GEOMETRY_SEQUENCE                                                                  0x00189312UL   
#define TAG_DATA_COLLECTION_CENTER_PATIENT                                                        0x00189313UL   
#define TAG_CT_RECONSTRUCTION_SEQUENCE                                                            0x00189314UL   
#define TAG_RECONSTRUCTION_ALGORITHM                                                              0x00189315UL   
#define TAG_CONVOLUTION_KERNEL_GROUP                                                              0x00189316UL   
#define TAG_RECONSTRUCTION_FIELD_OF_VIEW                                                          0x00189317UL   
#define TAG_RECONSTRUCTION_TARGET_CENTER_PATIENT                                                  0x00189318UL   
#define TAG_RECONSTRUCTION_ANGLE                                                                  0x00189319UL   
#define TAG_IMAGE_FILTER                                                                          0x00189320UL   
#define TAG_CT_EXPOSURE_SEQUENCE                                                                  0x00189321UL   
#define TAG_RECONSTRUCTION_PIXEL_SPACING                                                          0x00189322UL   
#define TAG_EXPOSURE_MODULATION_TYPE                                                              0x00189323UL   
#define TAG_ESTIMATED_DOSE_SAVING                                                                 0x00189324UL   // Retired
#define TAG_CT_X_RAY_DETAILS_SEQUENCE                                                             0x00189325UL   
#define TAG_CT_POSITION_SEQUENCE                                                                  0x00189326UL   
#define TAG_TABLE_POSITION                                                                        0x00189327UL   
#define TAG_EXPOSURE_TIME_IN_MS                                                                   0x00189328UL   
#define TAG_CT_IMAGE_FRAME_TYPE_SEQUENCE                                                          0x00189329UL   
#define TAG_X_RAY_TUBE_CURRENT_IN_MA                                                              0x00189330UL   
#define TAG_EXPOSURE_IN_MAS                                                                       0x00189332UL   
#define TAG_CONSTANT_VOLUME_FLAG                                                                  0x00189333UL   
#define TAG_FLUOROSCOPY_FLAG                                                                      0x00189334UL   
#define TAG_DISTANCE_SOURCE_TO_DATA_COLLECTION_CENTER                                             0x00189335UL   
#define TAG_CONTRAST_BOLUS_AGENT_NUMBER                                                           0x00189337UL   
#define TAG_CONTRAST_BOLUS_INGREDIENT_CODE_SEQUENCE                                               0x00189338UL   
#define TAG_CONTRAST_ADMINISTRATION_PROFILE_SEQUENCE                                              0x00189340UL   
#define TAG_CONTRAST_BOLUS_USAGE_SEQUENCE                                                         0x00189341UL   
#define TAG_CONTRAST_BOLUS_AGENT_ADMINISTERED                                                     0x00189342UL   
#define TAG_CONTRAST_BOLUS_AGENT_DETECTED                                                         0x00189343UL   
#define TAG_CONTRAST_BOLUS_AGENT_PHASE                                                            0x00189344UL   
#define TAG_CTDIVOL                                                                               0x00189345UL   
#define TAG_CTDI_PHANTOM_TYPE_CODE_SEQUENCE                                                       0x00189346UL   
#define TAG_CALCIUM_SCORING_MASS_FACTOR_PATIENT                                                   0x00189351UL   
#define TAG_CALCIUM_SCORING_MASS_FACTOR_DEVICE                                                    0x00189352UL   
#define TAG_ENERGY_WEIGHTING_FACTOR                                                               0x00189353UL   
#define TAG_CT_ADDITIONAL_X_RAY_SOURCE_SEQUENCE                                                   0x00189360UL   
#define TAG_MULTI_ENERGY_CT_ACQUISITION                                                           0x00189361UL   
#define TAG_MULTI_ENERGY_CT_ACQUISITION_SEQUENCE                                                  0x00189362UL   
#define TAG_MULTI_ENERGY_CT_PROCESSING_SEQUENCE                                                   0x00189363UL   
#define TAG_MULTI_ENERGY_CT_CHARACTERISTICS_SEQUENCE                                              0x00189364UL   
#define TAG_MULTI_ENERGY_CT_X_RAY_SOURCE_SEQUENCE                                                 0x00189365UL   
#define TAG_X_RAY_SOURCE_INDEX                                                                    0x00189366UL   
#define TAG_X_RAY_SOURCE_ID                                                                       0x00189367UL   
#define TAG_MULTI_ENERGY_SOURCE_TECHNIQUE                                                         0x00189368UL   
#define TAG_SOURCE_START_DATETIME                                                                 0x00189369UL   
#define TAG_SOURCE_END_DATETIME                                                                   0x0018936AUL   
#define TAG_SWITCHING_PHASE_NUMBER                                                                0x0018936BUL   
#define TAG_SWITCHING_PHASE_NOMINAL_DURATION                                                      0x0018936CUL   
#define TAG_SWITCHING_PHASE_TRANSITION_DURATION                                                   0x0018936DUL   
#define TAG_EFFECTIVE_BIN_ENERGY                                                                  0x0018936EUL   
#define TAG_MULTI_ENERGY_CT_X_RAY_DETECTOR_SEQUENCE                                               0x0018936FUL   
#define TAG_X_RAY_DETECTOR_INDEX                                                                  0x00189370UL   
#define TAG_X_RAY_DETECTOR_ID                                                                     0x00189371UL   
#define TAG_MULTI_ENERGY_DETECTOR_TYPE                                                            0x00189372UL   
#define TAG_X_RAY_DETECTOR_LABEL                                                                  0x00189373UL   
#define TAG_NOMINAL_MAX_ENERGY                                                                    0x00189374UL   
#define TAG_NOMINAL_MIN_ENERGY                                                                    0x00189375UL   
#define TAG_REFERENCED_X_RAY_DETECTOR_INDEX                                                       0x00189376UL   
#define TAG_REFERENCED_X_RAY_SOURCE_INDEX                                                         0x00189377UL   
#define TAG_REFERENCED_PATH_INDEX                                                                 0x00189378UL   
#define TAG_MULTI_ENERGY_CT_PATH_SEQUENCE                                                         0x00189379UL   
#define TAG_MULTI_ENERGY_CT_PATH_INDEX                                                            0x0018937AUL   
#define TAG_MULTI_ENERGY_ACQUISITION_DESCRIPTION                                                  0x0018937BUL   
#define TAG_MONOENERGETIC_ENERGY_EQUIVALENT                                                       0x0018937CUL   
#define TAG_MATERIAL_CODE_SEQUENCE                                                                0x0018937DUL   
#define TAG_DECOMPOSITION_METHOD                                                                  0x0018937EUL   
#define TAG_DECOMPOSITION_DESCRIPTION                                                             0x0018937FUL   
#define TAG_DECOMPOSITION_ALGORITHM_IDENTIFICATION_SEQUENCE                                       0x00189380UL   
#define TAG_DECOMPOSITION_MATERIAL_SEQUENCE                                                       0x00189381UL   
#define TAG_MATERIAL_ATTENUATION_SEQUENCE                                                         0x00189382UL   
#define TAG_PHOTON_ENERGY                                                                         0x00189383UL   
#define TAG_X_RAY_MASS_ATTENUATION_COEFFICIENT                                                    0x00189384UL   
#define TAG_PROJECTION_PIXEL_CALIBRATION_SEQUENCE                                                 0x00189401UL   
#define TAG_DISTANCE_SOURCE_TO_ISOCENTER                                                          0x00189402UL   
#define TAG_DISTANCE_OBJECT_TO_TABLE_TOP                                                          0x00189403UL   
#define TAG_OBJECT_PIXEL_SPACING_IN_CENTER_OF_BEAM                                                0x00189404UL   
#define TAG_POSITIONER_POSITION_SEQUENCE                                                          0x00189405UL   
#define TAG_TABLE_POSITION_SEQUENCE                                                               0x00189406UL   
#define TAG_COLLIMATOR_SHAPE_SEQUENCE                                                             0x00189407UL   
#define TAG_PLANES_IN_ACQUISITION                                                                 0x00189410UL   
#define TAG_XA_XRF_FRAME_CHARACTERISTICS_SEQUENCE                                                 0x00189412UL   
#define TAG_FRAME_ACQUISITION_SEQUENCE                                                            0x00189417UL   
#define TAG_X_RAY_RECEPTOR_TYPE                                                                   0x00189420UL   
#define TAG_ACQUISITION_PROTOCOL_NAME                                                             0x00189423UL   
#define TAG_ACQUISITION_PROTOCOL_DESCRIPTION                                                      0x00189424UL   
#define TAG_CONTRAST_BOLUS_INGREDIENT_OPAQUE                                                      0x00189425UL   
#define TAG_DISTANCE_RECEPTOR_PLANE_TO_DETECTOR_HOUSING                                           0x00189426UL   
#define TAG_INTENSIFIER_ACTIVE_SHAPE                                                              0x00189427UL   
#define TAG_INTENSIFIER_ACTIVE_DIMENSION                                                          0x00189428UL   
#define TAG_PHYSICAL_DETECTOR_SIZE                                                                0x00189429UL   
#define TAG_POSITION_OF_ISOCENTER_PROJECTION                                                      0x00189430UL   
#define TAG_FIELD_OF_VIEW_SEQUENCE                                                                0x00189432UL   
#define TAG_FIELD_OF_VIEW_DESCRIPTION                                                             0x00189433UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGIONS_SEQUENCE                                             0x00189434UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGION_SHAPE                                                 0x00189435UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGION_LEFT_VERTICAL_EDGE                                    0x00189436UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGION_RIGHT_VERTICAL_EDGE                                   0x00189437UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGION_UPPER_HORIZONTAL_EDGE                                 0x00189438UL   
#define TAG_EXPOSURE_CONTROL_SENSING_REGION_LOWER_HORIZONTAL_EDGE                                 0x00189439UL   
#define TAG_CENTER_OF_CIRCULAR_EXPOSURE_CONTROL_SENSING_REGION                                    0x00189440UL   
#define TAG_RADIUS_OF_CIRCULAR_EXPOSURE_CONTROL_SENSING_REGION                                    0x00189441UL   
#define TAG_VERTICES_OF_THE_POLYGONAL_EXPOSURE_CONTROL_SENSING_REGION                             0x00189442UL   
#define TAG_COLUMN_ANGULATION_PATIENT                                                             0x00189447UL   
#define TAG_BEAM_ANGLE                                                                            0x00189449UL   
#define TAG_FRAME_DETECTOR_PARAMETERS_SEQUENCE                                                    0x00189451UL   
#define TAG_CALCULATED_ANATOMY_THICKNESS                                                          0x00189452UL   
#define TAG_CALIBRATION_SEQUENCE                                                                  0x00189455UL   
#define TAG_OBJECT_THICKNESS_SEQUENCE                                                             0x00189456UL   
#define TAG_PLANE_IDENTIFICATION                                                                  0x00189457UL   
#define TAG_FIELD_OF_VIEW_DIMENSION_IN_FLOAT                                                      0x00189461UL   
#define TAG_ISOCENTER_REFERENCE_SYSTEM_SEQUENCE                                                   0x00189462UL   
#define TAG_POSITIONER_ISOCENTER_PRIMARY_ANGLE                                                    0x00189463UL   
#define TAG_POSITIONER_ISOCENTER_SECONDARY_ANGLE                                                  0x00189464UL   
#define TAG_POSITIONER_ISOCENTER_DETECTOR_ROTATION_ANGLE                                          0x00189465UL   
#define TAG_TABLE_X_POSITION_TO_ISOCENTER                                                         0x00189466UL   
#define TAG_TABLE_Y_POSITION_TO_ISOCENTER                                                         0x00189467UL   
#define TAG_TABLE_Z_POSITION_TO_ISOCENTER                                                         0x00189468UL   
#define TAG_TABLE_HORIZONTAL_ROTATION_ANGLE                                                       0x00189469UL   
#define TAG_TABLE_HEAD_TILT_ANGLE                                                                 0x00189470UL   
#define TAG_TABLE_CRADLE_TILT_ANGLE                                                               0x00189471UL   
#define TAG_FRAME_DISPLAY_SHUTTER_SEQUENCE                                                        0x00189472UL   
#define TAG_ACQUIRED_IMAGE_AREA_DOSE_PRODUCT                                                      0x00189473UL   
#define TAG_C_ARM_POSITIONER_TABLETOP_RELATIONSHIP                                                0x00189474UL   
#define TAG_X_RAY_GEOMETRY_SEQUENCE                                                               0x00189476UL   
#define TAG_IRRADIATION_EVENT_IDENTIFICATION_SEQUENCE                                             0x00189477UL   
#define TAG_X_RAY_3D_FRAME_TYPE_SEQUENCE                                                          0x00189504UL   
#define TAG_CONTRIBUTING_SOURCES_SEQUENCE                                                         0x00189506UL   
#define TAG_X_RAY_3D_ACQUISITION_SEQUENCE                                                         0x00189507UL   
#define TAG_PRIMARY_POSITIONER_SCAN_ARC                                                           0x00189508UL   
#define TAG_SECONDARY_POSITIONER_SCAN_ARC                                                         0x00189509UL   
#define TAG_PRIMARY_POSITIONER_SCAN_START_ANGLE                                                   0x00189510UL   
#define TAG_SECONDARY_POSITIONER_SCAN_START_ANGLE                                                 0x00189511UL   
#define TAG_PRIMARY_POSITIONER_INCREMENT                                                          0x00189514UL   
#define TAG_SECONDARY_POSITIONER_INCREMENT                                                        0x00189515UL   
#define TAG_START_ACQUISITION_DATETIME                                                            0x00189516UL   
#define TAG_END_ACQUISITION_DATETIME                                                              0x00189517UL   
#define TAG_PRIMARY_POSITIONER_INCREMENT_SIGN                                                     0x00189518UL   
#define TAG_SECONDARY_POSITIONER_INCREMENT_SIGN                                                   0x00189519UL   
#define TAG_APPLICATION_NAME                                                                      0x00189524UL   
#define TAG_APPLICATION_VERSION                                                                   0x00189525UL   
#define TAG_APPLICATION_MANUFACTURER                                                              0x00189526UL   
#define TAG_ALGORITHM_TYPE                                                                        0x00189527UL   
#define TAG_ALGORITHM_DESCRIPTION                                                                 0x00189528UL   
#define TAG_X_RAY_3D_RECONSTRUCTION_SEQUENCE                                                      0x00189530UL   
#define TAG_RECONSTRUCTION_DESCRIPTION                                                            0x00189531UL   
#define TAG_PER_PROJECTION_ACQUISITION_SEQUENCE                                                   0x00189538UL   
#define TAG_DETECTOR_POSITION_SEQUENCE                                                            0x00189541UL   
#define TAG_X_RAY_ACQUISITION_DOSE_SEQUENCE                                                       0x00189542UL   
#define TAG_X_RAY_SOURCE_ISOCENTER_PRIMARY_ANGLE                                                  0x00189543UL   
#define TAG_X_RAY_SOURCE_ISOCENTER_SECONDARY_ANGLE                                                0x00189544UL   
#define TAG_BREAST_SUPPORT_ISOCENTER_PRIMARY_ANGLE                                                0x00189545UL   
#define TAG_BREAST_SUPPORT_ISOCENTER_SECONDARY_ANGLE                                              0x00189546UL   
#define TAG_BREAST_SUPPORT_X_POSITION_TO_ISOCENTER                                                0x00189547UL   
#define TAG_BREAST_SUPPORT_Y_POSITION_TO_ISOCENTER                                                0x00189548UL   
#define TAG_BREAST_SUPPORT_Z_POSITION_TO_ISOCENTER                                                0x00189549UL   
#define TAG_DETECTOR_ISOCENTER_PRIMARY_ANGLE                                                      0x00189550UL   
#define TAG_DETECTOR_ISOCENTER_SECONDARY_ANGLE                                                    0x00189551UL   
#define TAG_DETECTOR_X_POSITION_TO_ISOCENTER                                                      0x00189552UL   
#define TAG_DETECTOR_Y_POSITION_TO_ISOCENTER                                                      0x00189553UL   
#define TAG_DETECTOR_Z_POSITION_TO_ISOCENTER                                                      0x00189554UL   
#define TAG_X_RAY_GRID_SEQUENCE                                                                   0x00189555UL   
#define TAG_X_RAY_FILTER_SEQUENCE                                                                 0x00189556UL   
#define TAG_DETECTOR_ACTIVE_AREA_TLHC_POSITION                                                    0x00189557UL   
#define TAG_DETECTOR_ACTIVE_AREA_ORIENTATION                                                      0x00189558UL   
#define TAG_POSITIONER_PRIMARY_ANGLE_DIRECTION                                                    0x00189559UL   
#define TAG_DIFFUSION_B_MATRIX_SEQUENCE                                                           0x00189601UL   
#define TAG_DIFFUSION_B_VALUE_XX                                                                  0x00189602UL   
#define TAG_DIFFUSION_B_VALUE_XY                                                                  0x00189603UL   
#define TAG_DIFFUSION_B_VALUE_XZ                                                                  0x00189604UL   
#define TAG_DIFFUSION_B_VALUE_YY                                                                  0x00189605UL   
#define TAG_DIFFUSION_B_VALUE_YZ                                                                  0x00189606UL   
#define TAG_DIFFUSION_B_VALUE_ZZ                                                                  0x00189607UL   
#define TAG_FUNCTIONAL_MR_SEQUENCE                                                                0x00189621UL   
#define TAG_FUNCTIONAL_SETTLING_PHASE_FRAMES_PRESENT                                              0x00189622UL   
#define TAG_FUNCTIONAL_SYNC_PULSE                                                                 0x00189623UL   
#define TAG_SETTLING_PHASE_FRAME                                                                  0x00189624UL   
#define TAG_DECAY_CORRECTION_DATETIME                                                             0x00189701UL   
#define TAG_START_DENSITY_THRESHOLD                                                               0x00189715UL   
#define TAG_START_RELATIVE_DENSITY_DIFFERENCE_THRESHOLD                                           0x00189716UL   
#define TAG_START_CARDIAC_TRIGGER_COUNT_THRESHOLD                                                 0x00189717UL   
#define TAG_START_RESPIRATORY_TRIGGER_COUNT_THRESHOLD                                             0x00189718UL   
#define TAG_TERMINATION_COUNTS_THRESHOLD                                                          0x00189719UL   
#define TAG_TERMINATION_DENSITY_THRESHOLD                                                         0x00189720UL   
#define TAG_TERMINATION_RELATIVE_DENSITY_THRESHOLD                                                0x00189721UL   
#define TAG_TERMINATION_TIME_THRESHOLD                                                            0x00189722UL   
#define TAG_TERMINATION_CARDIAC_TRIGGER_COUNT_THRESHOLD                                           0x00189723UL   
#define TAG_TERMINATION_RESPIRATORY_TRIGGER_COUNT_THRESHOLD                                       0x00189724UL   
#define TAG_DETECTOR_GEOMETRY                                                                     0x00189725UL   
#define TAG_TRANSVERSE_DETECTOR_SEPARATION                                                        0x00189726UL   
#define TAG_AXIAL_DETECTOR_DIMENSION                                                              0x00189727UL   
#define TAG_RADIOPHARMACEUTICAL_AGENT_NUMBER                                                      0x00189729UL   
#define TAG_PET_FRAME_ACQUISITION_SEQUENCE                                                        0x00189732UL   
#define TAG_PET_DETECTOR_MOTION_DETAILS_SEQUENCE                                                  0x00189733UL   
#define TAG_PET_TABLE_DYNAMICS_SEQUENCE                                                           0x00189734UL   
#define TAG_PET_POSITION_SEQUENCE                                                                 0x00189735UL   
#define TAG_PET_FRAME_CORRECTION_FACTORS_SEQUENCE                                                 0x00189736UL   
#define TAG_RADIOPHARMACEUTICAL_USAGE_SEQUENCE                                                    0x00189737UL   
#define TAG_ATTENUATION_CORRECTION_SOURCE                                                         0x00189738UL   
#define TAG_NUMBER_OF_ITERATIONS                                                                  0x00189739UL   
#define TAG_NUMBER_OF_SUBSETS                                                                     0x00189740UL   
#define TAG_PET_RECONSTRUCTION_SEQUENCE                                                           0x00189749UL   
#define TAG_PET_FRAME_TYPE_SEQUENCE                                                               0x00189751UL   
#define TAG_TIME_OF_FLIGHT_INFORMATION_USED                                                       0x00189755UL   
#define TAG_RECONSTRUCTION_TYPE                                                                   0x00189756UL   
#define TAG_DECAY_CORRECTED                                                                       0x00189758UL   
#define TAG_ATTENUATION_CORRECTED                                                                 0x00189759UL   
#define TAG_SCATTER_CORRECTED                                                                     0x00189760UL   
#define TAG_DEAD_TIME_CORRECTED                                                                   0x00189761UL   
#define TAG_GANTRY_MOTION_CORRECTED                                                               0x00189762UL   
#define TAG_PATIENT_MOTION_CORRECTED                                                              0x00189763UL   
#define TAG_COUNT_LOSS_NORMALIZATION_CORRECTED                                                    0x00189764UL   
#define TAG_RANDOMS_CORRECTED                                                                     0x00189765UL   
#define TAG_NON_UNIFORM_RADIAL_SAMPLING_CORRECTED                                                 0x00189766UL   
#define TAG_SENSITIVITY_CALIBRATED                                                                0x00189767UL   
#define TAG_DETECTOR_NORMALIZATION_CORRECTION                                                     0x00189768UL   
#define TAG_ITERATIVE_RECONSTRUCTION_METHOD                                                       0x00189769UL   
#define TAG_ATTENUATION_CORRECTION_TEMPORAL_RELATIONSHIP                                          0x00189770UL   
#define TAG_PATIENT_PHYSIOLOGICAL_STATE_SEQUENCE                                                  0x00189771UL   
#define TAG_PATIENT_PHYSIOLOGICAL_STATE_CODE_SEQUENCE                                             0x00189772UL   
#define TAG_DEPTH_OF_FOCUS                                                                        0x00189801UL   
#define TAG_EXCLUDED_INTERVALS_SEQUENCE                                                           0x00189803UL   
#define TAG_EXCLUSION_START_DATETIME                                                              0x00189804UL   
#define TAG_EXCLUSION_DURATION                                                                    0x00189805UL   
#define TAG_US_IMAGE_DESCRIPTION_SEQUENCE                                                         0x00189806UL   
#define TAG_IMAGE_DATA_TYPE_SEQUENCE                                                              0x00189807UL   
#define TAG_DATA_TYPE                                                                             0x00189808UL   
#define TAG_TRANSDUCER_SCAN_PATTERN_CODE_SEQUENCE                                                 0x00189809UL   
#define TAG_ALIASED_DATA_TYPE                                                                     0x0018980BUL   
#define TAG_POSITION_MEASURING_DEVICE_USED                                                        0x0018980CUL   
#define TAG_TRANSDUCER_GEOMETRY_CODE_SEQUENCE                                                     0x0018980DUL   
#define TAG_TRANSDUCER_BEAM_STEERING_CODE_SEQUENCE                                                0x0018980EUL   
#define TAG_TRANSDUCER_APPLICATION_CODE_SEQUENCE                                                  0x0018980FUL   
#define TAG_ZERO_VELOCITY_PIXEL_VALUE                                                             0x00189810UL   
#define TAG_REFERENCE_LOCATION_LABEL                                                              0x00189900UL   
#define TAG_REFERENCE_LOCATION_DESCRIPTION                                                        0x00189901UL   
#define TAG_REFERENCE_BASIS_CODE_SEQUENCE                                                         0x00189902UL   
#define TAG_REFERENCE_GEOMETRY_CODE_SEQUENCE                                                      0x00189903UL   
#define TAG_OFFSET_DISTANCE                                                                       0x00189904UL   
#define TAG_OFFSET_DIRECTION                                                                      0x00189905UL   
#define TAG_POTENTIAL_SCHEDULED_PROTOCOL_CODE_SEQUENCE                                            0x00189906UL   
#define TAG_POTENTIAL_REQUESTED_PROCEDURE_CODE_SEQUENCE                                           0x00189907UL   
#define TAG_POTENTIAL_REASONS_FOR_PROCEDURE                                                       0x00189908UL   
#define TAG_POTENTIAL_REASONS_FOR_PROCEDURE_CODE_SEQUENCE                                         0x00189909UL   
#define TAG_POTENTIAL_DIAGNOSTIC_TASKS                                                            0x0018990AUL   
#define TAG_CONTRAINDICATIONS_CODE_SEQUENCE                                                       0x0018990BUL   
#define TAG_REFERENCED_DEFINED_PROTOCOL_SEQUENCE                                                  0x0018990CUL   
#define TAG_REFERENCED_PERFORMED_PROTOCOL_SEQUENCE                                                0x0018990DUL   
#define TAG_PREDECESSOR_PROTOCOL_SEQUENCE                                                         0x0018990EUL   
#define TAG_PROTOCOL_PLANNING_INFORMATION                                                         0x0018990FUL   
#define TAG_PROTOCOL_DESIGN_RATIONALE                                                             0x00189910UL   
#define TAG_PATIENT_SPECIFICATION_SEQUENCE                                                        0x00189911UL   
#define TAG_MODEL_SPECIFICATION_SEQUENCE                                                          0x00189912UL   
#define TAG_PARAMETERS_SPECIFICATION_SEQUENCE                                                     0x00189913UL   
#define TAG_INSTRUCTION_SEQUENCE                                                                  0x00189914UL   
#define TAG_INSTRUCTION_INDEX                                                                     0x00189915UL   
#define TAG_INSTRUCTION_TEXT                                                                      0x00189916UL   
#define TAG_INSTRUCTION_DESCRIPTION                                                               0x00189917UL   
#define TAG_INSTRUCTION_PERFORMED_FLAG                                                            0x00189918UL   
#define TAG_INSTRUCTION_PERFORMED_DATETIME                                                        0x00189919UL   
#define TAG_INSTRUCTION_PERFORMANCE_COMMENT                                                       0x0018991AUL   
#define TAG_PATIENT_POSITIONING_INSTRUCTION_SEQUENCE                                              0x0018991BUL   
#define TAG_POSITIONING_METHOD_CODE_SEQUENCE                                                      0x0018991CUL   
#define TAG_POSITIONING_LANDMARK_SEQUENCE                                                         0x0018991DUL   
#define TAG_TARGET_FRAME_OF_REFERENCE_UID                                                         0x0018991EUL   
#define TAG_ACQUISITION_PROTOCOL_ELEMENT_SPECIFICATION_SEQUENCE                                   0x0018991FUL   
#define TAG_ACQUISITION_PROTOCOL_ELEMENT_SEQUENCE                                                 0x00189920UL   
#define TAG_PROTOCOL_ELEMENT_NUMBER                                                               0x00189921UL   
#define TAG_PROTOCOL_ELEMENT_NAME                                                                 0x00189922UL   
#define TAG_PROTOCOL_ELEMENT_CHARACTERISTICS_SUMMARY                                              0x00189923UL   
#define TAG_PROTOCOL_ELEMENT_PURPOSE                                                              0x00189924UL   
#define TAG_ACQUISITION_MOTION                                                                    0x00189930UL   
#define TAG_ACQUISITION_START_LOCATION_SEQUENCE                                                   0x00189931UL   
#define TAG_ACQUISITION_END_LOCATION_SEQUENCE                                                     0x00189932UL   
#define TAG_RECONSTRUCTION_PROTOCOL_ELEMENT_SPECIFICATION_SEQUENCE                                0x00189933UL   
#define TAG_RECONSTRUCTION_PROTOCOL_ELEMENT_SEQUENCE                                              0x00189934UL   
#define TAG_STORAGE_PROTOCOL_ELEMENT_SPECIFICATION_SEQUENCE                                       0x00189935UL   
#define TAG_STORAGE_PROTOCOL_ELEMENT_SEQUENCE                                                     0x00189936UL   
#define TAG_REQUESTED_SERIES_DESCRIPTION                                                          0x00189937UL   
#define TAG_SOURCE_ACQUISITION_PROTOCOL_ELEMENT_NUMBER                                            0x00189938UL   
#define TAG_SOURCE_ACQUISITION_BEAM_NUMBER                                                        0x00189939UL   
#define TAG_SOURCE_RECONSTRUCTION_PROTOCOL_ELEMENT_NUMBER                                         0x0018993AUL   
#define TAG_RECONSTRUCTION_START_LOCATION_SEQUENCE                                                0x0018993BUL   
#define TAG_RECONSTRUCTION_END_LOCATION_SEQUENCE                                                  0x0018993CUL   
#define TAG_RECONSTRUCTION_ALGORITHM_SEQUENCE                                                     0x0018993DUL   
#define TAG_RECONSTRUCTION_TARGET_CENTER_LOCATION_SEQUENCE                                        0x0018993EUL   
#define TAG_IMAGE_FILTER_DESCRIPTION                                                              0x00189941UL   
#define TAG_CTDIVOL_NOTIFICATION_TRIGGER                                                          0x00189942UL   
#define TAG_DLP_NOTIFICATION_TRIGGER                                                              0x00189943UL   
#define TAG_AUTO_KVP_SELECTION_TYPE                                                               0x00189944UL   
#define TAG_AUTO_KVP_UPPER_BOUND                                                                  0x00189945UL   
#define TAG_AUTO_KVP_LOWER_BOUND                                                                  0x00189946UL   
#define TAG_PROTOCOL_DEFINED_PATIENT_POSITION                                                     0x00189947UL   
#define TAG_CONTRIBUTING_EQUIPMENT_SEQUENCE                                                       0x0018A001UL   
#define TAG_CONTRIBUTION_DATETIME                                                                 0x0018A002UL   
#define TAG_CONTRIBUTION_DESCRIPTION                                                              0x0018A003UL   

// *****************************************************************************************************************************
// *** 0020
// *****************************************************************************************************************************
#define TAG_STUDY_INSTANCE_UID                                                                    0x0020000DUL   
#define TAG_SERIES_INSTANCE_UID                                                                   0x0020000EUL   
#define TAG_STUDY_ID                                                                              0x00200010UL   
#define TAG_SERIES_NUMBER                                                                         0x00200011UL   
#define TAG_ACQUISITION_NUMBER                                                                    0x00200012UL   
#define TAG_INSTANCE_NUMBER                                                                       0x00200013UL   
#define TAG_ISOTOPE_NUMBER                                                                        0x00200014UL   // Retired
#define TAG_PHASE_NUMBER                                                                          0x00200015UL   // Retired
#define TAG_INTERVAL_NUMBER                                                                       0x00200016UL   // Retired
#define TAG_TIME_SLOT_NUMBER                                                                      0x00200017UL   // Retired
#define TAG_ANGLE_NUMBER                                                                          0x00200018UL   // Retired
#define TAG_ITEM_NUMBER                                                                           0x00200019UL   
#define TAG_PATIENT_ORIENTATION                                                                   0x00200020UL   
#define TAG_OVERLAY_NUMBER                                                                        0x00200022UL   // Retired
#define TAG_CURVE_NUMBER                                                                          0x00200024UL   // Retired
#define TAG_LUT_NUMBER                                                                            0x00200026UL   // Retired
#define TAG_IMAGE_POSITION                                                                        0x00200030UL   // Retired
#define TAG_IMAGE_POSITION_PATIENT                                                                0x00200032UL   
#define TAG_IMAGE_ORIENTATION                                                                     0x00200035UL   // Retired
#define TAG_IMAGE_ORIENTATION_PATIENT                                                             0x00200037UL   
#define TAG_LOCATION                                                                              0x00200050UL   // Retired
#define TAG_FRAME_OF_REFERENCE_UID                                                                0x00200052UL   
#define TAG_LATERALITY                                                                            0x00200060UL   
#define TAG_IMAGE_LATERALITY                                                                      0x00200062UL   
#define TAG_IMAGE_GEOMETRY_TYPE                                                                   0x00200070UL   // Retired
#define TAG_MASKING_IMAGE                                                                         0x00200080UL   // Retired
#define TAG_REPORT_NUMBER                                                                         0x002000AAUL   // Retired
#define TAG_TEMPORAL_POSITION_IDENTIFIER                                                          0x00200100UL   
#define TAG_NUMBER_OF_TEMPORAL_POSITIONS                                                          0x00200105UL   
#define TAG_TEMPORAL_RESOLUTION                                                                   0x00200110UL   
#define TAG_SYNCHRONIZATION_FRAME_OF_REFERENCE_UID                                                0x00200200UL   
#define TAG_SOP_INSTANCE_UID_OF_CONCATENATION_SOURCE                                              0x00200242UL   
#define TAG_SERIES_IN_STUDY                                                                       0x00201000UL   // Retired
#define TAG_ACQUISITIONS_IN_SERIES                                                                0x00201001UL   // Retired
#define TAG_IMAGES_IN_ACQUISITION                                                                 0x00201002UL   
#define TAG_IMAGES_IN_SERIES                                                                      0x00201003UL   // Retired
#define TAG_ACQUISITIONS_IN_STUDY                                                                 0x00201004UL   // Retired
#define TAG_IMAGES_IN_STUDY                                                                       0x00201005UL   // Retired
#define TAG_REFERENCE                                                                             0x00201020UL   // Retired
#define TAG_TARGET_POSITION_REFERENCE_INDICATOR                                                   0x0020103FUL   
#define TAG_POSITION_REFERENCE_INDICATOR                                                          0x00201040UL   
#define TAG_SLICE_LOCATION                                                                        0x00201041UL   
#define TAG_OTHER_STUDY_NUMBERS                                                                   0x00201070UL   // Retired
#define TAG_NUMBER_OF_PATIENT_RELATED_STUDIES                                                     0x00201200UL   
#define TAG_NUMBER_OF_PATIENT_RELATED_SERIES                                                      0x00201202UL   
#define TAG_NUMBER_OF_PATIENT_RELATED_INSTANCES                                                   0x00201204UL   
#define TAG_NUMBER_OF_STUDY_RELATED_SERIES                                                        0x00201206UL   
#define TAG_NUMBER_OF_STUDY_RELATED_INSTANCES                                                     0x00201208UL   
#define TAG_NUMBER_OF_SERIES_RELATED_INSTANCES                                                    0x00201209UL   
#define TAG_SOURCE_IMAGE_IDS                                                                      0x00203100UL   // Retired
#define TAG_MODIFYING_DEVICE_ID                                                                   0x00203401UL   // Retired
#define TAG_MODIFIED_IMAGE_ID                                                                     0x00203402UL   // Retired
#define TAG_MODIFIED_IMAGE_DATE                                                                   0x00203403UL   // Retired
#define TAG_MODIFYING_DEVICE_MANUFACTURER                                                         0x00203404UL   // Retired
#define TAG_MODIFIED_IMAGE_TIME                                                                   0x00203405UL   // Retired
#define TAG_MODIFIED_IMAGE_DESCRIPTION                                                            0x00203406UL   // Retired
#define TAG_IMAGE_COMMENTS                                                                        0x00204000UL   
#define TAG_ORIGINAL_IMAGE_IDENTIFICATION                                                         0x00205000UL   // Retired
#define TAG_ORIGINAL_IMAGE_IDENTIFICATION_NOMENCLATURE                                            0x00205002UL   // Retired
#define TAG_STACK_ID                                                                              0x00209056UL   
#define TAG_IN_STACK_POSITION_NUMBER                                                              0x00209057UL   
#define TAG_FRAME_ANATOMY_SEQUENCE                                                                0x00209071UL   
#define TAG_FRAME_LATERALITY                                                                      0x00209072UL   
#define TAG_FRAME_CONTENT_SEQUENCE                                                                0x00209111UL   
#define TAG_PLANE_POSITION_SEQUENCE                                                               0x00209113UL   
#define TAG_PLANE_ORIENTATION_SEQUENCE                                                            0x00209116UL   
#define TAG_TEMPORAL_POSITION_INDEX                                                               0x00209128UL   
#define TAG_NOMINAL_CARDIAC_TRIGGER_DELAY_TIME                                                    0x00209153UL   
#define TAG_NOMINAL_CARDIAC_TRIGGER_TIME_PRIOR_TO_R_PEAK                                          0x00209154UL   
#define TAG_ACTUAL_CARDIAC_TRIGGER_TIME_PRIOR_TO_R_PEAK                                           0x00209155UL   
#define TAG_FRAME_ACQUISITION_NUMBER                                                              0x00209156UL   
#define TAG_DIMENSION_INDEX_VALUES                                                                0x00209157UL   
#define TAG_FRAME_COMMENTS                                                                        0x00209158UL   
#define TAG_CONCATENATION_UID                                                                     0x00209161UL   
#define TAG_IN_CONCATENATION_NUMBER                                                               0x00209162UL   
#define TAG_IN_CONCATENATION_TOTAL_NUMBER                                                         0x00209163UL   
#define TAG_DIMENSION_ORGANIZATION_UID                                                            0x00209164UL   
#define TAG_DIMENSION_INDEX_POINTER                                                               0x00209165UL   
#define TAG_FUNCTIONAL_GROUP_POINTER                                                              0x00209167UL   
#define TAG_UNASSIGNED_SHARED_CONVERTED_ATTRIBUTES_SEQUENCE                                       0x00209170UL   
#define TAG_UNASSIGNED_PER_FRAME_CONVERTED_ATTRIBUTES_SEQUENCE                                    0x00209171UL   
#define TAG_CONVERSION_SOURCE_ATTRIBUTES_SEQUENCE                                                 0x00209172UL   
#define TAG_DIMENSION_INDEX_PRIVATE_CREATOR                                                       0x00209213UL   
#define TAG_DIMENSION_ORGANIZATION_SEQUENCE                                                       0x00209221UL   
#define TAG_DIMENSION_INDEX_SEQUENCE                                                              0x00209222UL   
#define TAG_CONCATENATION_FRAME_OFFSET_NUMBER                                                     0x00209228UL   
#define TAG_FUNCTIONAL_GROUP_PRIVATE_CREATOR                                                      0x00209238UL   
#define TAG_NOMINAL_PERCENTAGE_OF_CARDIAC_PHASE                                                   0x00209241UL   
#define TAG_NOMINAL_PERCENTAGE_OF_RESPIRATORY_PHASE                                               0x00209245UL   
#define TAG_STARTING_RESPIRATORY_AMPLITUDE                                                        0x00209246UL   
#define TAG_STARTING_RESPIRATORY_PHASE                                                            0x00209247UL   
#define TAG_ENDING_RESPIRATORY_AMPLITUDE                                                          0x00209248UL   
#define TAG_ENDING_RESPIRATORY_PHASE                                                              0x00209249UL   
#define TAG_RESPIRATORY_TRIGGER_TYPE                                                              0x00209250UL   
#define TAG_R_R_INTERVAL_TIME_NOMINAL                                                             0x00209251UL   
#define TAG_ACTUAL_CARDIAC_TRIGGER_DELAY_TIME                                                     0x00209252UL   
#define TAG_RESPIRATORY_SYNCHRONIZATION_SEQUENCE                                                  0x00209253UL   
#define TAG_RESPIRATORY_INTERVAL_TIME                                                             0x00209254UL   
#define TAG_NOMINAL_RESPIRATORY_TRIGGER_DELAY_TIME                                                0x00209255UL   
#define TAG_RESPIRATORY_TRIGGER_DELAY_THRESHOLD                                                   0x00209256UL   
#define TAG_ACTUAL_RESPIRATORY_TRIGGER_DELAY_TIME                                                 0x00209257UL   
#define TAG_IMAGE_POSITION_VOLUME                                                                 0x00209301UL   
#define TAG_IMAGE_ORIENTATION_VOLUME                                                              0x00209302UL   
#define TAG_ULTRASOUND_ACQUISITION_GEOMETRY                                                       0x00209307UL   
#define TAG_APEX_POSITION                                                                         0x00209308UL   
#define TAG_VOLUME_TO_TRANSDUCER_MAPPING_MATRIX                                                   0x00209309UL   
#define TAG_VOLUME_TO_TABLE_MAPPING_MATRIX                                                        0x0020930AUL   
#define TAG_VOLUME_TO_TRANSDUCER_RELATIONSHIP                                                     0x0020930BUL   
#define TAG_PATIENT_FRAME_OF_REFERENCE_SOURCE                                                     0x0020930CUL   
#define TAG_TEMPORAL_POSITION_TIME_OFFSET                                                         0x0020930DUL   
#define TAG_PLANE_POSITION_VOLUME_SEQUENCE                                                        0x0020930EUL   
#define TAG_PLANE_ORIENTATION_VOLUME_SEQUENCE                                                     0x0020930FUL   
#define TAG_TEMPORAL_POSITION_SEQUENCE                                                            0x00209310UL   
#define TAG_DIMENSION_ORGANIZATION_TYPE                                                           0x00209311UL   
#define TAG_VOLUME_FRAME_OF_REFERENCE_UID                                                         0x00209312UL   
#define TAG_TABLE_FRAME_OF_REFERENCE_UID                                                          0x00209313UL   
#define TAG_DIMENSION_DESCRIPTION_LABEL                                                           0x00209421UL   
#define TAG_PATIENT_ORIENTATION_IN_FRAME_SEQUENCE                                                 0x00209450UL   
#define TAG_FRAME_LABEL                                                                           0x00209453UL   
#define TAG_ACQUISITION_INDEX                                                                     0x00209518UL   
#define TAG_CONTRIBUTING_SOP_INSTANCES_REFERENCE_SEQUENCE                                         0x00209529UL   
#define TAG_RECONSTRUCTION_INDEX                                                                  0x00209536UL   

// *****************************************************************************************************************************
// *** 0022
// *****************************************************************************************************************************
#define TAG_LIGHT_PATH_FILTER_PASS_THROUGH_WAVELENGTH                                             0x00220001UL   
#define TAG_LIGHT_PATH_FILTER_PASS_BAND                                                           0x00220002UL   
#define TAG_IMAGE_PATH_FILTER_PASS_THROUGH_WAVELENGTH                                             0x00220003UL   
#define TAG_IMAGE_PATH_FILTER_PASS_BAND                                                           0x00220004UL   
#define TAG_PATIENT_EYE_MOVEMENT_COMMANDED                                                        0x00220005UL   
#define TAG_PATIENT_EYE_MOVEMENT_COMMAND_CODE_SEQUENCE                                            0x00220006UL   
#define TAG_SPHERICAL_LENS_POWER                                                                  0x00220007UL   
#define TAG_CYLINDER_LENS_POWER                                                                   0x00220008UL   
#define TAG_CYLINDER_AXIS                                                                         0x00220009UL   
#define TAG_EMMETROPIC_MAGNIFICATION                                                              0x0022000AUL   
#define TAG_INTRA_OCULAR_PRESSURE                                                                 0x0022000BUL   
#define TAG_HORIZONTAL_FIELD_OF_VIEW                                                              0x0022000CUL   
#define TAG_PUPIL_DILATED                                                                         0x0022000DUL   
#define TAG_DEGREE_OF_DILATION                                                                    0x0022000EUL   
#define TAG_STEREO_BASELINE_ANGLE                                                                 0x00220010UL   
#define TAG_STEREO_BASELINE_DISPLACEMENT                                                          0x00220011UL   
#define TAG_STEREO_HORIZONTAL_PIXEL_OFFSET                                                        0x00220012UL   
#define TAG_STEREO_VERTICAL_PIXEL_OFFSET                                                          0x00220013UL   
#define TAG_STEREO_ROTATION                                                                       0x00220014UL   
#define TAG_ACQUISITION_DEVICE_TYPE_CODE_SEQUENCE                                                 0x00220015UL   
#define TAG_ILLUMINATION_TYPE_CODE_SEQUENCE                                                       0x00220016UL   
#define TAG_LIGHT_PATH_FILTER_TYPE_STACK_CODE_SEQUENCE                                            0x00220017UL   
#define TAG_IMAGE_PATH_FILTER_TYPE_STACK_CODE_SEQUENCE                                            0x00220018UL   
#define TAG_LENSES_CODE_SEQUENCE                                                                  0x00220019UL   
#define TAG_CHANNEL_DESCRIPTION_CODE_SEQUENCE                                                     0x0022001AUL   
#define TAG_REFRACTIVE_STATE_SEQUENCE                                                             0x0022001BUL   
#define TAG_MYDRIATIC_AGENT_CODE_SEQUENCE                                                         0x0022001CUL   
#define TAG_RELATIVE_IMAGE_POSITION_CODE_SEQUENCE                                                 0x0022001DUL   
#define TAG_CAMERA_ANGLE_OF_VIEW                                                                  0x0022001EUL   
#define TAG_STEREO_PAIRS_SEQUENCE                                                                 0x00220020UL   
#define TAG_LEFT_IMAGE_SEQUENCE                                                                   0x00220021UL   
#define TAG_RIGHT_IMAGE_SEQUENCE                                                                  0x00220022UL   
#define TAG_STEREO_PAIRS_PRESENT                                                                  0x00220028UL   
#define TAG_AXIAL_LENGTH_OF_THE_EYE                                                               0x00220030UL   
#define TAG_OPHTHALMIC_FRAME_LOCATION_SEQUENCE                                                    0x00220031UL   
#define TAG_REFERENCE_COORDINATES                                                                 0x00220032UL   
#define TAG_DEPTH_SPATIAL_RESOLUTION                                                              0x00220035UL   
#define TAG_MAXIMUM_DEPTH_DISTORTION                                                              0x00220036UL   
#define TAG_ALONG_SCAN_SPATIAL_RESOLUTION                                                         0x00220037UL   
#define TAG_MAXIMUM_ALONG_SCAN_DISTORTION                                                         0x00220038UL   
#define TAG_OPHTHALMIC_IMAGE_ORIENTATION                                                          0x00220039UL   
#define TAG_DEPTH_OF_TRANSVERSE_IMAGE                                                             0x00220041UL   
#define TAG_MYDRIATIC_AGENT_CONCENTRATION_UNITS_SEQUENCE                                          0x00220042UL   
#define TAG_ACROSS_SCAN_SPATIAL_RESOLUTION                                                        0x00220048UL   
#define TAG_MAXIMUM_ACROSS_SCAN_DISTORTION                                                        0x00220049UL   
#define TAG_MYDRIATIC_AGENT_CONCENTRATION                                                         0x0022004EUL   
#define TAG_ILLUMINATION_WAVE_LENGTH                                                              0x00220055UL   
#define TAG_ILLUMINATION_POWER                                                                    0x00220056UL   
#define TAG_ILLUMINATION_BANDWIDTH                                                                0x00220057UL   
#define TAG_MYDRIATIC_AGENT_SEQUENCE                                                              0x00220058UL   
#define TAG_OPHTHALMIC_AXIAL_MEASUREMENTS_RIGHT_EYE_SEQUENCE                                      0x00221007UL   
#define TAG_OPHTHALMIC_AXIAL_MEASUREMENTS_LEFT_EYE_SEQUENCE                                       0x00221008UL   
#define TAG_OPHTHALMIC_AXIAL_MEASUREMENTS_DEVICE_TYPE                                             0x00221009UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_TYPE                                             0x00221010UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_SEQUENCE                                                      0x00221012UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH                                                               0x00221019UL   
#define TAG_LENS_STATUS_CODE_SEQUENCE                                                             0x00221024UL   
#define TAG_VITREOUS_STATUS_CODE_SEQUENCE                                                         0x00221025UL   
#define TAG_IOL_FORMULA_CODE_SEQUENCE                                                             0x00221028UL   
#define TAG_IOL_FORMULA_DETAIL                                                                    0x00221029UL   
#define TAG_KERATOMETER_INDEX                                                                     0x00221033UL   
#define TAG_SOURCE_OF_OPHTHALMIC_AXIAL_LENGTH_CODE_SEQUENCE                                       0x00221035UL   
#define TAG_SOURCE_OF_CORNEAL_SIZE_DATA_CODE_SEQUENCE                                             0x00221036UL   
#define TAG_TARGET_REFRACTION                                                                     0x00221037UL   
#define TAG_REFRACTIVE_PROCEDURE_OCCURRED                                                         0x00221039UL   
#define TAG_REFRACTIVE_SURGERY_TYPE_CODE_SEQUENCE                                                 0x00221040UL   
#define TAG_OPHTHALMIC_ULTRASOUND_METHOD_CODE_SEQUENCE                                            0x00221044UL   
#define TAG_SURGICALLY_INDUCED_ASTIGMATISM_SEQUENCE                                               0x00221045UL   
#define TAG_TYPE_OF_OPTICAL_CORRECTION                                                            0x00221046UL   
#define TAG_TORIC_IOL_POWER_SEQUENCE                                                              0x00221047UL   
#define TAG_PREDICTED_TORIC_ERROR_SEQUENCE                                                        0x00221048UL   
#define TAG_PRE_SELECTED_FOR_IMPLANTATION                                                         0x00221049UL   
#define TAG_TORIC_IOL_POWER_FOR_EXACT_EMMETROPIA_SEQUENCE                                         0x0022104AUL   
#define TAG_TORIC_IOL_POWER_FOR_EXACT_TARGET_REFRACTION_SEQUENCE                                  0x0022104BUL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_SEQUENCE                                         0x00221050UL   
#define TAG_IOL_POWER                                                                             0x00221053UL   
#define TAG_PREDICTED_REFRACTIVE_ERROR                                                            0x00221054UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_VELOCITY                                                      0x00221059UL   
#define TAG_LENS_STATUS_DESCRIPTION                                                               0x00221065UL   
#define TAG_VITREOUS_STATUS_DESCRIPTION                                                           0x00221066UL   
#define TAG_IOL_POWER_SEQUENCE                                                                    0x00221090UL   
#define TAG_LENS_CONSTANT_SEQUENCE                                                                0x00221092UL   
#define TAG_IOL_MANUFACTURER                                                                      0x00221093UL   
#define TAG_LENS_CONSTANT_DESCRIPTION                                                             0x00221094UL   // Retired
#define TAG_IMPLANT_NAME                                                                          0x00221095UL   
#define TAG_KERATOMETRY_MEASUREMENT_TYPE_CODE_SEQUENCE                                            0x00221096UL   
#define TAG_IMPLANT_PART_NUMBER                                                                   0x00221097UL   
#define TAG_REFERENCED_OPHTHALMIC_AXIAL_MEASUREMENTS_SEQUENCE                                     0x00221100UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_SEGMENT_NAME_CODE_SEQUENCE                       0x00221101UL   
#define TAG_REFRACTIVE_ERROR_BEFORE_REFRACTIVE_SURGERY_CODE_SEQUENCE                              0x00221103UL   
#define TAG_IOL_POWER_FOR_EXACT_EMMETROPIA                                                        0x00221121UL   
#define TAG_IOL_POWER_FOR_EXACT_TARGET_REFRACTION                                                 0x00221122UL   
#define TAG_ANTERIOR_CHAMBER_DEPTH_DEFINITION_CODE_SEQUENCE                                       0x00221125UL   
#define TAG_LENS_THICKNESS_SEQUENCE                                                               0x00221127UL   
#define TAG_ANTERIOR_CHAMBER_DEPTH_SEQUENCE                                                       0x00221128UL   
#define TAG_CALCULATION_COMMENT_SEQUENCE                                                          0x0022112AUL   
#define TAG_CALCULATION_COMMENT_TYPE                                                              0x0022112BUL   
#define TAG_CALCULATION_COMMENT                                                                   0x0022112CUL   
#define TAG_LENS_THICKNESS                                                                        0x00221130UL   
#define TAG_ANTERIOR_CHAMBER_DEPTH                                                                0x00221131UL   
#define TAG_SOURCE_OF_LENS_THICKNESS_DATA_CODE_SEQUENCE                                           0x00221132UL   
#define TAG_SOURCE_OF_ANTERIOR_CHAMBER_DEPTH_DATA_CODE_SEQUENCE                                   0x00221133UL   
#define TAG_SOURCE_OF_REFRACTIVE_MEASUREMENTS_SEQUENCE                                            0x00221134UL   
#define TAG_SOURCE_OF_REFRACTIVE_MEASUREMENTS_CODE_SEQUENCE                                       0x00221135UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENT_MODIFIED                                          0x00221140UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_DATA_SOURCE_CODE_SEQUENCE                                     0x00221150UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_ACQUISITION_METHOD_CODE_SEQUENCE                              0x00221153UL   // Retired
#define TAG_SIGNAL_TO_NOISE_RATIO                                                                 0x00221155UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_DATA_SOURCE_DESCRIPTION                                       0x00221159UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_TOTAL_LENGTH_SEQUENCE                            0x00221210UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_SEGMENTAL_LENGTH_SEQUENCE                        0x00221211UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_LENGTH_SUMMATION_SEQUENCE                        0x00221212UL   
#define TAG_ULTRASOUND_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_SEQUENCE                              0x00221220UL   
#define TAG_OPTICAL_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENTS_SEQUENCE                                 0x00221225UL   
#define TAG_ULTRASOUND_SELECTED_OPHTHALMIC_AXIAL_LENGTH_SEQUENCE                                  0x00221230UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_SELECTION_METHOD_CODE_SEQUENCE                                0x00221250UL   
#define TAG_OPTICAL_SELECTED_OPHTHALMIC_AXIAL_LENGTH_SEQUENCE                                     0x00221255UL   
#define TAG_SELECTED_SEGMENTAL_OPHTHALMIC_AXIAL_LENGTH_SEQUENCE                                   0x00221257UL   
#define TAG_SELECTED_TOTAL_OPHTHALMIC_AXIAL_LENGTH_SEQUENCE                                       0x00221260UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_QUALITY_METRIC_SEQUENCE                                       0x00221262UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_QUALITY_METRIC_TYPE_CODE_SEQUENCE                             0x00221265UL   // Retired
#define TAG_OPHTHALMIC_AXIAL_LENGTH_QUALITY_METRIC_TYPE_DESCRIPTION                               0x00221273UL   // Retired
#define TAG_INTRAOCULAR_LENS_CALCULATIONS_RIGHT_EYE_SEQUENCE                                      0x00221300UL   
#define TAG_INTRAOCULAR_LENS_CALCULATIONS_LEFT_EYE_SEQUENCE                                       0x00221310UL   
#define TAG_REFERENCED_OPHTHALMIC_AXIAL_LENGTH_MEASUREMENT_QC_IMAGE_SEQUENCE                      0x00221330UL   
#define TAG_OPHTHALMIC_MAPPING_DEVICE_TYPE                                                        0x00221415UL   
#define TAG_ACQUISITION_METHOD_CODE_SEQUENCE                                                      0x00221420UL   
#define TAG_ACQUISITION_METHOD_ALGORITHM_SEQUENCE                                                 0x00221423UL   
#define TAG_OPHTHALMIC_THICKNESS_MAP_TYPE_CODE_SEQUENCE                                           0x00221436UL   
#define TAG_OPHTHALMIC_THICKNESS_MAPPING_NORMALS_SEQUENCE                                         0x00221443UL   
#define TAG_RETINAL_THICKNESS_DEFINITION_CODE_SEQUENCE                                            0x00221445UL   
#define TAG_PIXEL_VALUE_MAPPING_TO_CODED_CONCEPT_SEQUENCE                                         0x00221450UL   
#define TAG_MAPPED_PIXEL_VALUE                                                                    0x00221452UL   
#define TAG_PIXEL_VALUE_MAPPING_EXPLANATION                                                       0x00221454UL   
#define TAG_OPHTHALMIC_THICKNESS_MAP_QUALITY_THRESHOLD_SEQUENCE                                   0x00221458UL   
#define TAG_OPHTHALMIC_THICKNESS_MAP_THRESHOLD_QUALITY_RATING                                     0x00221460UL   
#define TAG_ANATOMIC_STRUCTURE_REFERENCE_POINT                                                    0x00221463UL   
#define TAG_REGISTRATION_TO_LOCALIZER_SEQUENCE                                                    0x00221465UL   
#define TAG_REGISTERED_LOCALIZER_UNITS                                                            0x00221466UL   
#define TAG_REGISTERED_LOCALIZER_TOP_LEFT_HAND_CORNER                                             0x00221467UL   
#define TAG_REGISTERED_LOCALIZER_BOTTOM_RIGHT_HAND_CORNER                                         0x00221468UL   
#define TAG_OPHTHALMIC_THICKNESS_MAP_QUALITY_RATING_SEQUENCE                                      0x00221470UL   
#define TAG_RELEVANT_OPT_ATTRIBUTES_SEQUENCE                                                      0x00221472UL   
#define TAG_TRANSFORMATION_METHOD_CODE_SEQUENCE                                                   0x00221512UL   
#define TAG_TRANSFORMATION_ALGORITHM_SEQUENCE                                                     0x00221513UL   
#define TAG_OPHTHALMIC_AXIAL_LENGTH_METHOD                                                        0x00221515UL   
#define TAG_OPHTHALMIC_FOV                                                                        0x00221517UL   
#define TAG_TWO_DIMENSIONAL_TO_THREE_DIMENSIONAL_MAP_SEQUENCE                                     0x00221518UL   
#define TAG_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_QUALITY_RATING_SEQUENCE                             0x00221525UL   
#define TAG_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_QUALITY_THRESHOLD_SEQUENCE                          0x00221526UL   
#define TAG_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_THRESHOLD_QUALITY_RATING                            0x00221527UL   
#define TAG_X_COORDINATES_CENTER_PIXEL_VIEW_ANGLE                                                 0x00221528UL   
#define TAG_Y_COORDINATES_CENTER_PIXEL_VIEW_ANGLE                                                 0x00221529UL   
#define TAG_NUMBER_OF_MAP_POINTS                                                                  0x00221530UL   
#define TAG_TWO_DIMENSIONAL_TO_THREE_DIMENSIONAL_MAP_DATA                                         0x00221531UL   
#define TAG_DERIVATION_ALGORITHM_SEQUENCE                                                         0x00221612UL   
#define TAG_OPHTHALMIC_IMAGE_TYPE_CODE_SEQUENCE                                                   0x00221615UL   
#define TAG_OPHTHALMIC_IMAGE_TYPE_DESCRIPTION                                                     0x00221616UL   
#define TAG_SCAN_PATTERN_TYPE_CODE_SEQUENCE                                                       0x00221618UL   
#define TAG_REFERENCED_SURFACE_MESH_IDENTIFICATION_SEQUENCE                                       0x00221620UL   
#define TAG_OPHTHALMIC_VOLUMETRIC_PROPERTIES_FLAG                                                 0x00221622UL   
#define TAG_OPHTHALMIC_ANATOMIC_REFERENCE_POINT_X_COORDINATE                                      0x00221624UL   
#define TAG_OPHTHALMIC_ANATOMIC_REFERENCE_POINT_Y_COORDINATE                                      0x00221626UL   
#define TAG_OPHTHALMIC_EN_FACE_IMAGE_QUALITY_RATING_SEQUENCE                                      0x00221628UL   
#define TAG_QUALITY_THRESHOLD                                                                     0x00221630UL   
#define TAG_OCT_B_SCAN_ANALYSIS_ACQUISITION_PARAMETERS_SEQUENCE                                   0x00221640UL   
#define TAG_NUMBER_OF_B_SCANS_PER_FRAME                                                           0x00221642UL   
#define TAG_B_SCAN_SLAB_THICKNESS                                                                 0x00221643UL   
#define TAG_DISTANCE_BETWEEN_B_SCAN_SLABS                                                         0x00221644UL   
#define TAG_B_SCAN_CYCLE_TIME                                                                     0x00221645UL   
#define TAG_B_SCAN_CYCLE_TIME_VECTOR                                                              0x00221646UL   
#define TAG_A_SCAN_RATE                                                                           0x00221649UL   
#define TAG_B_SCAN_RATE                                                                           0x00221650UL   
#define TAG_SURFACE_MESH_Z_PIXEL_OFFSET                                                           0x00221658UL   

// *****************************************************************************************************************************
// *** 0024
// *****************************************************************************************************************************
#define TAG_VISUAL_FIELD_HORIZONTAL_EXTENT                                                        0x00240010UL   
#define TAG_VISUAL_FIELD_VERTICAL_EXTENT                                                          0x00240011UL   
#define TAG_VISUAL_FIELD_SHAPE                                                                    0x00240012UL   
#define TAG_SCREENING_TEST_MODE_CODE_SEQUENCE                                                     0x00240016UL   
#define TAG_MAXIMUM_STIMULUS_LUMINANCE                                                            0x00240018UL   
#define TAG_BACKGROUND_LUMINANCE                                                                  0x00240020UL   
#define TAG_STIMULUS_COLOR_CODE_SEQUENCE                                                          0x00240021UL   
#define TAG_BACKGROUND_ILLUMINATION_COLOR_CODE_SEQUENCE                                           0x00240024UL   
#define TAG_STIMULUS_AREA                                                                         0x00240025UL   
#define TAG_STIMULUS_PRESENTATION_TIME                                                            0x00240028UL   
#define TAG_FIXATION_SEQUENCE                                                                     0x00240032UL   
#define TAG_FIXATION_MONITORING_CODE_SEQUENCE                                                     0x00240033UL   
#define TAG_VISUAL_FIELD_CATCH_TRIAL_SEQUENCE                                                     0x00240034UL   
#define TAG_FIXATION_CHECKED_QUANTITY                                                             0x00240035UL   
#define TAG_PATIENT_NOT_PROPERLY_FIXATED_QUANTITY                                                 0x00240036UL   
#define TAG_PRESENTED_VISUAL_STIMULI_DATA_FLAG                                                    0x00240037UL   
#define TAG_NUMBER_OF_VISUAL_STIMULI                                                              0x00240038UL   
#define TAG_EXCESSIVE_FIXATION_LOSSES_DATA_FLAG                                                   0x00240039UL   
#define TAG_EXCESSIVE_FIXATION_LOSSES                                                             0x00240040UL   
#define TAG_STIMULI_RETESTING_QUANTITY                                                            0x00240042UL   
#define TAG_COMMENTS_ON_PATIENT_PERFORMANCE_OF_VISUAL_FIELD                                       0x00240044UL   
#define TAG_FALSE_NEGATIVES_ESTIMATE_FLAG                                                         0x00240045UL   
#define TAG_FALSE_NEGATIVES_ESTIMATE                                                              0x00240046UL   
#define TAG_NEGATIVE_CATCH_TRIALS_QUANTITY                                                        0x00240048UL   
#define TAG_FALSE_NEGATIVES_QUANTITY                                                              0x00240050UL   
#define TAG_EXCESSIVE_FALSE_NEGATIVES_DATA_FLAG                                                   0x00240051UL   
#define TAG_EXCESSIVE_FALSE_NEGATIVES                                                             0x00240052UL   
#define TAG_FALSE_POSITIVES_ESTIMATE_FLAG                                                         0x00240053UL   
#define TAG_FALSE_POSITIVES_ESTIMATE                                                              0x00240054UL   
#define TAG_CATCH_TRIALS_DATA_FLAG                                                                0x00240055UL   
#define TAG_POSITIVE_CATCH_TRIALS_QUANTITY                                                        0x00240056UL   
#define TAG_TEST_POINT_NORMALS_DATA_FLAG                                                          0x00240057UL   
#define TAG_TEST_POINT_NORMALS_SEQUENCE                                                           0x00240058UL   
#define TAG_GLOBAL_DEVIATION_PROBABILITY_NORMALS_FLAG                                             0x00240059UL   
#define TAG_FALSE_POSITIVES_QUANTITY                                                              0x00240060UL   
#define TAG_EXCESSIVE_FALSE_POSITIVES_DATA_FLAG                                                   0x00240061UL   
#define TAG_EXCESSIVE_FALSE_POSITIVES                                                             0x00240062UL   
#define TAG_VISUAL_FIELD_TEST_NORMALS_FLAG                                                        0x00240063UL   
#define TAG_RESULTS_NORMALS_SEQUENCE                                                              0x00240064UL   
#define TAG_AGE_CORRECTED_SENSITIVITY_DEVIATION_ALGORITHM_SEQUENCE                                0x00240065UL   
#define TAG_GLOBAL_DEVIATION_FROM_NORMAL                                                          0x00240066UL   
#define TAG_GENERALIZED_DEFECT_SENSITIVITY_DEVIATION_ALGORITHM_SEQUENCE                           0x00240067UL   
#define TAG_LOCALIZED_DEVIATION_FROM_NORMAL                                                       0x00240068UL   
#define TAG_PATIENT_RELIABILITY_INDICATOR                                                         0x00240069UL   
#define TAG_VISUAL_FIELD_MEAN_SENSITIVITY                                                         0x00240070UL   
#define TAG_GLOBAL_DEVIATION_PROBABILITY                                                          0x00240071UL   
#define TAG_LOCAL_DEVIATION_PROBABILITY_NORMALS_FLAG                                              0x00240072UL   
#define TAG_LOCALIZED_DEVIATION_PROBABILITY                                                       0x00240073UL   
#define TAG_SHORT_TERM_FLUCTUATION_CALCULATED                                                     0x00240074UL   
#define TAG_SHORT_TERM_FLUCTUATION                                                                0x00240075UL   
#define TAG_SHORT_TERM_FLUCTUATION_PROBABILITY_CALCULATED                                         0x00240076UL   
#define TAG_SHORT_TERM_FLUCTUATION_PROBABILITY                                                    0x00240077UL   
#define TAG_CORRECTED_LOCALIZED_DEVIATION_FROM_NORMAL_CALCULATED                                  0x00240078UL   
#define TAG_CORRECTED_LOCALIZED_DEVIATION_FROM_NORMAL                                             0x00240079UL   
#define TAG_CORRECTED_LOCALIZED_DEVIATION_FROM_NORMAL_PROBABILITY_CALCULATED                      0x00240080UL   
#define TAG_CORRECTED_LOCALIZED_DEVIATION_FROM_NORMAL_PROBABILITY                                 0x00240081UL   
#define TAG_GLOBAL_DEVIATION_PROBABILITY_SEQUENCE                                                 0x00240083UL   
#define TAG_LOCALIZED_DEVIATION_PROBABILITY_SEQUENCE                                              0x00240085UL   
#define TAG_FOVEAL_SENSITIVITY_MEASURED                                                           0x00240086UL   
#define TAG_FOVEAL_SENSITIVITY                                                                    0x00240087UL   
#define TAG_VISUAL_FIELD_TEST_DURATION                                                            0x00240088UL   
#define TAG_VISUAL_FIELD_TEST_POINT_SEQUENCE                                                      0x00240089UL   
#define TAG_VISUAL_FIELD_TEST_POINT_X_COORDINATE                                                  0x00240090UL   
#define TAG_VISUAL_FIELD_TEST_POINT_Y_COORDINATE                                                  0x00240091UL   
#define TAG_AGE_CORRECTED_SENSITIVITY_DEVIATION_VALUE                                             0x00240092UL   
#define TAG_STIMULUS_RESULTS                                                                      0x00240093UL   
#define TAG_SENSITIVITY_VALUE                                                                     0x00240094UL   
#define TAG_RETEST_STIMULUS_SEEN                                                                  0x00240095UL   
#define TAG_RETEST_SENSITIVITY_VALUE                                                              0x00240096UL   
#define TAG_VISUAL_FIELD_TEST_POINT_NORMALS_SEQUENCE                                              0x00240097UL   
#define TAG_QUANTIFIED_DEFECT                                                                     0x00240098UL   
#define TAG_AGE_CORRECTED_SENSITIVITY_DEVIATION_PROBABILITY_VALUE                                 0x00240100UL   
#define TAG_GENERALIZED_DEFECT_CORRECTED_SENSITIVITY_DEVIATION_FLAG                               0x00240102UL   
#define TAG_GENERALIZED_DEFECT_CORRECTED_SENSITIVITY_DEVIATION_VALUE                              0x00240103UL   
#define TAG_GENERALIZED_DEFECT_CORRECTED_SENSITIVITY_DEVIATION_PROBABILITY_VALUE                  0x00240104UL   
#define TAG_MINIMUM_SENSITIVITY_VALUE                                                             0x00240105UL   
#define TAG_BLIND_SPOT_LOCALIZED                                                                  0x00240106UL   
#define TAG_BLIND_SPOT_X_COORDINATE                                                               0x00240107UL   
#define TAG_BLIND_SPOT_Y_COORDINATE                                                               0x00240108UL   
#define TAG_VISUAL_ACUITY_MEASUREMENT_SEQUENCE                                                    0x00240110UL   
#define TAG_REFRACTIVE_PARAMETERS_USED_ON_PATIENT_SEQUENCE                                        0x00240112UL   
#define TAG_MEASUREMENT_LATERALITY                                                                0x00240113UL   
#define TAG_OPHTHALMIC_PATIENT_CLINICAL_INFORMATION_LEFT_EYE_SEQUENCE                             0x00240114UL   
#define TAG_OPHTHALMIC_PATIENT_CLINICAL_INFORMATION_RIGHT_EYE_SEQUENCE                            0x00240115UL   
#define TAG_FOVEAL_POINT_NORMATIVE_DATA_FLAG                                                      0x00240117UL   
#define TAG_FOVEAL_POINT_PROBABILITY_VALUE                                                        0x00240118UL   
#define TAG_SCREENING_BASELINE_MEASURED                                                           0x00240120UL   
#define TAG_SCREENING_BASELINE_MEASURED_SEQUENCE                                                  0x00240122UL   
#define TAG_SCREENING_BASELINE_TYPE                                                               0x00240124UL   
#define TAG_SCREENING_BASELINE_VALUE                                                              0x00240126UL   
#define TAG_ALGORITHM_SOURCE                                                                      0x00240202UL   
#define TAG_DATA_SET_NAME                                                                         0x00240306UL   
#define TAG_DATA_SET_VERSION                                                                      0x00240307UL   
#define TAG_DATA_SET_SOURCE                                                                       0x00240308UL   
#define TAG_DATA_SET_DESCRIPTION                                                                  0x00240309UL   
#define TAG_VISUAL_FIELD_TEST_RELIABILITY_GLOBAL_INDEX_SEQUENCE                                   0x00240317UL   
#define TAG_VISUAL_FIELD_GLOBAL_RESULTS_INDEX_SEQUENCE                                            0x00240320UL   
#define TAG_DATA_OBSERVATION_SEQUENCE                                                             0x00240325UL   
#define TAG_INDEX_NORMALS_FLAG                                                                    0x00240338UL   
#define TAG_INDEX_PROBABILITY                                                                     0x00240341UL   
#define TAG_INDEX_PROBABILITY_SEQUENCE                                                            0x00240344UL   

// *****************************************************************************************************************************
// *** 0028
// *****************************************************************************************************************************
#define TAG_SAMPLES_PER_PIXEL                                                                     0x00280002UL   
#define TAG_SAMPLES_PER_PIXEL_USED                                                                0x00280003UL   
#define TAG_PHOTOMETRIC_INTERPRETATION                                                            0x00280004UL   
#define TAG_IMAGE_DIMENSIONS                                                                      0x00280005UL   // Retired
#define TAG_PLANAR_CONFIGURATION                                                                  0x00280006UL   
#define TAG_NUMBER_OF_FRAMES                                                                      0x00280008UL   
#define TAG_FRAME_INCREMENT_POINTER                                                               0x00280009UL   
#define TAG_FRAME_DIMENSION_POINTER                                                               0x0028000AUL   
#define TAG_ROWS                                                                                  0x00280010UL   
#define TAG_COLUMNS                                                                               0x00280011UL   
#define TAG_PLANES                                                                                0x00280012UL   // Retired
#define TAG_ULTRASOUND_COLOR_DATA_PRESENT                                                         0x00280014UL   
#define TAG_PIXEL_SPACING                                                                         0x00280030UL   
#define TAG_ZOOM_FACTOR                                                                           0x00280031UL   
#define TAG_ZOOM_CENTER                                                                           0x00280032UL   
#define TAG_PIXEL_ASPECT_RATIO                                                                    0x00280034UL   
#define TAG_IMAGE_FORMAT                                                                          0x00280040UL   // Retired
#define TAG_MANIPULATED_IMAGE                                                                     0x00280050UL   // Retired
#define TAG_CORRECTED_IMAGE                                                                       0x00280051UL   
#define TAG_COMPRESSION_RECOGNITION_CODE                                                          0x0028005FUL   // Retired
#define TAG_COMPRESSION_CODE                                                                      0x00280060UL   // Retired
#define TAG_COMPRESSION_ORIGINATOR                                                                0x00280061UL   // Retired
#define TAG_COMPRESSION_LABEL                                                                     0x00280062UL   // Retired
#define TAG_COMPRESSION_DESCRIPTION                                                               0x00280063UL   // Retired
#define TAG_COMPRESSION_SEQUENCE                                                                  0x00280065UL   // Retired
#define TAG_COMPRESSION_STEP_POINTERS                                                             0x00280066UL   // Retired
#define TAG_REPEAT_INTERVAL                                                                       0x00280068UL   // Retired
#define TAG_BITS_GROUPED                                                                          0x00280069UL   // Retired
#define TAG_PERIMETER_TABLE                                                                       0x00280070UL   // Retired
#define TAG_PERIMETER_VALUE                                                                       0x00280071UL   // Retired
#define TAG_PREDICTOR_ROWS                                                                        0x00280080UL   // Retired
#define TAG_PREDICTOR_COLUMNS                                                                     0x00280081UL   // Retired
#define TAG_PREDICTOR_CONSTANTS                                                                   0x00280082UL   // Retired
#define TAG_BLOCKED_PIXELS                                                                        0x00280090UL   // Retired
#define TAG_BLOCK_ROWS                                                                            0x00280091UL   // Retired
#define TAG_BLOCK_COLUMNS                                                                         0x00280092UL   // Retired
#define TAG_ROW_OVERLAP                                                                           0x00280093UL   // Retired
#define TAG_COLUMN_OVERLAP                                                                        0x00280094UL   // Retired
#define TAG_BITS_ALLOCATED                                                                        0x00280100UL   
#define TAG_BITS_STORED                                                                           0x00280101UL   
#define TAG_HIGH_BIT                                                                              0x00280102UL   
#define TAG_PIXEL_REPRESENTATION                                                                  0x00280103UL   
#define TAG_SMALLEST_VALID_PIXEL_VALUE                                                            0x00280104UL   // Retired
#define TAG_LARGEST_VALID_PIXEL_VALUE                                                             0x00280105UL   // Retired
#define TAG_SMALLEST_IMAGE_PIXEL_VALUE                                                            0x00280106UL   
#define TAG_LARGEST_IMAGE_PIXEL_VALUE                                                             0x00280107UL   
#define TAG_SMALLEST_PIXEL_VALUE_IN_SERIES                                                        0x00280108UL   
#define TAG_LARGEST_PIXEL_VALUE_IN_SERIES                                                         0x00280109UL   
#define TAG_SMALLEST_IMAGE_PIXEL_VALUE_IN_PLANE                                                   0x00280110UL   // Retired
#define TAG_LARGEST_IMAGE_PIXEL_VALUE_IN_PLANE                                                    0x00280111UL   // Retired
#define TAG_PIXEL_PADDING_VALUE                                                                   0x00280120UL   
#define TAG_PIXEL_PADDING_RANGE_LIMIT                                                             0x00280121UL   
#define TAG_FLOAT_PIXEL_PADDING_VALUE                                                             0x00280122UL   
#define TAG_DOUBLE_FLOAT_PIXEL_PADDING_VALUE                                                      0x00280123UL   
#define TAG_FLOAT_PIXEL_PADDING_RANGE_LIMIT                                                       0x00280124UL   
#define TAG_DOUBLE_FLOAT_PIXEL_PADDING_RANGE_LIMIT                                                0x00280125UL   
#define TAG_IMAGE_LOCATION                                                                        0x00280200UL   // Retired
#define TAG_QUALITY_CONTROL_IMAGE                                                                 0x00280300UL   
#define TAG_BURNED_IN_ANNOTATION                                                                  0x00280301UL   
#define TAG_RECOGNIZABLE_VISUAL_FEATURES                                                          0x00280302UL   
#define TAG_LONGITUDINAL_TEMPORAL_INFORMATION_MODIFIED                                            0x00280303UL   
#define TAG_REFERENCED_COLOR_PALETTE_INSTANCE_UID                                                 0x00280304UL   
#define TAG_TRANSFORM_LABEL                                                                       0x00280400UL   // Retired
#define TAG_TRANSFORM_VERSION_NUMBER                                                              0x00280401UL   // Retired
#define TAG_NUMBER_OF_TRANSFORM_STEPS                                                             0x00280402UL   // Retired
#define TAG_SEQUENCE_OF_COMPRESSED_DATA                                                           0x00280403UL   // Retired
#define TAG_DETAILS_OF_COEFFICIENTS                                                               0x00280404UL   // Retired
#define TAG_ROWS_FOR_NTH_ORDER_COEFFICIENTS                                                       0x00280400UL   // Retired
#define TAG_COLUMNS_FOR_NTH_ORDER_COEFFICIENTS                                                    0x00280401UL   // Retired
#define TAG_COEFFICIENT_CODING                                                                    0x00280402UL   // Retired
#define TAG_COEFFICIENT_CODING_POINTERS                                                           0x00280403UL   // Retired
#define TAG_DCT_LABEL                                                                             0x00280700UL   // Retired
#define TAG_DATA_BLOCK_DESCRIPTION                                                                0x00280701UL   // Retired
#define TAG_DATA_BLOCK                                                                            0x00280702UL   // Retired
#define TAG_NORMALIZATION_FACTOR_FORMAT                                                           0x00280710UL   // Retired
#define TAG_ZONAL_MAP_NUMBER_FORMAT                                                               0x00280720UL   // Retired
#define TAG_ZONAL_MAP_LOCATION                                                                    0x00280721UL   // Retired
#define TAG_ZONAL_MAP_FORMAT                                                                      0x00280722UL   // Retired
#define TAG_ADAPTIVE_MAP_FORMAT                                                                   0x00280730UL   // Retired
#define TAG_CODE_NUMBER_FORMAT                                                                    0x00280740UL   // Retired
#define TAG_CODE_LABEL                                                                            0x00280800UL   // Retired
#define TAG_NUMBER_OF_TABLES                                                                      0x00280802UL   // Retired
#define TAG_CODE_TABLE_LOCATION                                                                   0x00280803UL   // Retired
#define TAG_BITS_FOR_CODE_WORD                                                                    0x00280804UL   // Retired
#define TAG_IMAGE_DATA_LOCATION                                                                   0x00280808UL   // Retired
#define TAG_PIXEL_SPACING_CALIBRATION_TYPE                                                        0x00280A02UL   
#define TAG_PIXEL_SPACING_CALIBRATION_DESCRIPTION                                                 0x00280A04UL   
#define TAG_PIXEL_INTENSITY_RELATIONSHIP                                                          0x00281040UL   
#define TAG_PIXEL_INTENSITY_RELATIONSHIP_SIGN                                                     0x00281041UL   
#define TAG_WINDOW_CENTER                                                                         0x00281050UL   
#define TAG_WINDOW_WIDTH                                                                          0x00281051UL   
#define TAG_RESCALE_INTERCEPT                                                                     0x00281052UL   
#define TAG_RESCALE_SLOPE                                                                         0x00281053UL   
#define TAG_RESCALE_TYPE                                                                          0x00281054UL   
#define TAG_WINDOW_CENTER_WIDTH_EXPLANATION                                                       0x00281055UL   
#define TAG_VOI_LUT_FUNCTION                                                                      0x00281056UL   
#define TAG_GRAY_SCALE                                                                            0x00281080UL   // Retired
#define TAG_RECOMMENDED_VIEWING_MODE                                                              0x00281090UL   
#define TAG_GRAY_LOOKUP_TABLE_DESCRIPTOR                                                          0x00281100UL   // Retired
#define TAG_RED_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                             0x00281101UL   
#define TAG_GREEN_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                           0x00281102UL   
#define TAG_BLUE_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                            0x00281103UL   
#define TAG_ALPHA_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                           0x00281104UL   
#define TAG_LARGE_RED_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                       0x00281111UL   // Retired
#define TAG_LARGE_GREEN_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                     0x00281112UL   // Retired
#define TAG_LARGE_BLUE_PALETTE_COLOR_LOOKUP_TABLE_DESCRIPTOR                                      0x00281113UL   // Retired
#define TAG_PALETTE_COLOR_LOOKUP_TABLE_UID                                                        0x00281199UL   
#define TAG_GRAY_LOOKUP_TABLE_DATA                                                                0x00281200UL   // Retired
#define TAG_RED_PALETTE_COLOR_LOOKUP_TABLE_DATA                                                   0x00281201UL   
#define TAG_GREEN_PALETTE_COLOR_LOOKUP_TABLE_DATA                                                 0x00281202UL   
#define TAG_BLUE_PALETTE_COLOR_LOOKUP_TABLE_DATA                                                  0x00281203UL   
#define TAG_ALPHA_PALETTE_COLOR_LOOKUP_TABLE_DATA                                                 0x00281204UL   
#define TAG_LARGE_RED_PALETTE_COLOR_LOOKUP_TABLE_DATA                                             0x00281211UL   // Retired
#define TAG_LARGE_GREEN_PALETTE_COLOR_LOOKUP_TABLE_DATA                                           0x00281212UL   // Retired
#define TAG_LARGE_BLUE_PALETTE_COLOR_LOOKUP_TABLE_DATA                                            0x00281213UL   // Retired
#define TAG_LARGE_PALETTE_COLOR_LOOKUP_TABLE_UID                                                  0x00281214UL   // Retired
#define TAG_SEGMENTED_RED_PALETTE_COLOR_LOOKUP_TABLE_DATA                                         0x00281221UL   
#define TAG_SEGMENTED_GREEN_PALETTE_COLOR_LOOKUP_TABLE_DATA                                       0x00281222UL   
#define TAG_SEGMENTED_BLUE_PALETTE_COLOR_LOOKUP_TABLE_DATA                                        0x00281223UL   
#define TAG_SEGMENTED_ALPHA_PALETTE_COLOR_LOOKUP_TABLE_DATA                                       0x00281224UL   
#define TAG_STORED_VALUE_COLOR_RANGE_SEQUENCE                                                     0x00281230UL   
#define TAG_MINIMUM_STORED_VALUE_MAPPED                                                           0x00281231UL   
#define TAG_MAXIMUM_STORED_VALUE_MAPPED                                                           0x00281232UL   
#define TAG_BREAST_IMPLANT_PRESENT                                                                0x00281300UL   
#define TAG_PARTIAL_VIEW                                                                          0x00281350UL   
#define TAG_PARTIAL_VIEW_DESCRIPTION                                                              0x00281351UL   
#define TAG_PARTIAL_VIEW_CODE_SEQUENCE                                                            0x00281352UL   
#define TAG_SPATIAL_LOCATIONS_PRESERVED                                                           0x0028135AUL   
#define TAG_DATA_FRAME_ASSIGNMENT_SEQUENCE                                                        0x00281401UL   
#define TAG_DATA_PATH_ASSIGNMENT                                                                  0x00281402UL   
#define TAG_BITS_MAPPED_TO_COLOR_LOOKUP_TABLE                                                     0x00281403UL   
#define TAG_BLENDING_LUT_1_SEQUENCE                                                               0x00281404UL   
#define TAG_BLENDING_LUT_1_TRANSFER_FUNCTION                                                      0x00281405UL   
#define TAG_BLENDING_WEIGHT_CONSTANT                                                              0x00281406UL   
#define TAG_BLENDING_LOOKUP_TABLE_DESCRIPTOR                                                      0x00281407UL   
#define TAG_BLENDING_LOOKUP_TABLE_DATA                                                            0x00281408UL   
#define TAG_ENHANCED_PALETTE_COLOR_LOOKUP_TABLE_SEQUENCE                                          0x0028140BUL   
#define TAG_BLENDING_LUT_2_SEQUENCE                                                               0x0028140CUL   
#define TAG_BLENDING_LUT_2_TRANSFER_FUNCTION                                                      0x0028140DUL   
#define TAG_DATA_PATH_ID                                                                          0x0028140EUL   
#define TAG_RGB_LUT_TRANSFER_FUNCTION                                                             0x0028140FUL   
#define TAG_ALPHA_LUT_TRANSFER_FUNCTION                                                           0x00281410UL   
#define TAG_ICC_PROFILE                                                                           0x00282000UL   
#define TAG_COLOR_SPACE                                                                           0x00282002UL   
#define TAG_LOSSY_IMAGE_COMPRESSION                                                               0x00282110UL   
#define TAG_LOSSY_IMAGE_COMPRESSION_RATIO                                                         0x00282112UL   
#define TAG_LOSSY_IMAGE_COMPRESSION_METHOD                                                        0x00282114UL   
#define TAG_MODALITY_LUT_SEQUENCE                                                                 0x00283000UL   
#define TAG_LUT_DESCRIPTOR                                                                        0x00283002UL   
#define TAG_LUT_EXPLANATION                                                                       0x00283003UL   
#define TAG_MODALITY_LUT_TYPE                                                                     0x00283004UL   
#define TAG_LUT_DATA                                                                              0x00283006UL   
#define TAG_VOI_LUT_SEQUENCE                                                                      0x00283010UL   
#define TAG_SOFTCOPY_VOI_LUT_SEQUENCE                                                             0x00283110UL   
#define TAG_IMAGE_PRESENTATION_COMMENTS                                                           0x00284000UL   // Retired
#define TAG_BI_PLANE_ACQUISITION_SEQUENCE                                                         0x00285000UL   // Retired
#define TAG_REPRESENTATIVE_FRAME_NUMBER                                                           0x00286010UL   
#define TAG_FRAME_NUMBERS_OF_INTEREST_FOI                                                         0x00286020UL   
#define TAG_FRAME_OF_INTEREST_DESCRIPTION                                                         0x00286022UL   
#define TAG_FRAME_OF_INTEREST_TYPE                                                                0x00286023UL   
#define TAG_MASK_POINTER                                                                          0x00286030UL   // Retired
#define TAG_R_WAVE_POINTER                                                                        0x00286040UL   
#define TAG_MASK_SUBTRACTION_SEQUENCE                                                             0x00286100UL   
#define TAG_MASK_OPERATION                                                                        0x00286101UL   
#define TAG_APPLICABLE_FRAME_RANGE                                                                0x00286102UL   
#define TAG_MASK_FRAME_NUMBERS                                                                    0x00286110UL   
#define TAG_CONTRAST_FRAME_AVERAGING                                                              0x00286112UL   
#define TAG_MASK_SUB_PIXEL_SHIFT                                                                  0x00286114UL   
#define TAG_TID_OFFSET                                                                            0x00286120UL   
#define TAG_MASK_OPERATION_EXPLANATION                                                            0x00286190UL   
#define TAG_EQUIPMENT_ADMINISTRATOR_SEQUENCE                                                      0x00287000UL   
#define TAG_NUMBER_OF_DISPLAY_SUBSYSTEMS                                                          0x00287001UL   
#define TAG_CURRENT_CONFIGURATION_ID                                                              0x00287002UL   
#define TAG_DISPLAY_SUBSYSTEM_ID                                                                  0x00287003UL   
#define TAG_DISPLAY_SUBSYSTEM_NAME                                                                0x00287004UL   
#define TAG_DISPLAY_SUBSYSTEM_DESCRIPTION                                                         0x00287005UL   
#define TAG_SYSTEM_STATUS                                                                         0x00287006UL   
#define TAG_SYSTEM_STATUS_COMMENT                                                                 0x00287007UL   
#define TAG_TARGET_LUMINANCE_CHARACTERISTICS_SEQUENCE                                             0x00287008UL   
#define TAG_LUMINANCE_CHARACTERISTICS_ID                                                          0x00287009UL   
#define TAG_DISPLAY_SUBSYSTEM_CONFIGURATION_SEQUENCE                                              0x0028700AUL   
#define TAG_CONFIGURATION_ID                                                                      0x0028700BUL   
#define TAG_CONFIGURATION_NAME                                                                    0x0028700CUL   
#define TAG_CONFIGURATION_DESCRIPTION                                                             0x0028700DUL   
#define TAG_REFERENCED_TARGET_LUMINANCE_CHARACTERISTICS_ID                                        0x0028700EUL   
#define TAG_QA_RESULTS_SEQUENCE                                                                   0x0028700FUL   
#define TAG_DISPLAY_SUBSYSTEM_QA_RESULTS_SEQUENCE                                                 0x00287010UL   
#define TAG_CONFIGURATION_QA_RESULTS_SEQUENCE                                                     0x00287011UL   
#define TAG_MEASUREMENT_EQUIPMENT_SEQUENCE                                                        0x00287012UL   
#define TAG_MEASUREMENT_FUNCTIONS                                                                 0x00287013UL   
#define TAG_MEASUREMENT_EQUIPMENT_TYPE                                                            0x00287014UL   
#define TAG_VISUAL_EVALUATION_RESULT_SEQUENCE                                                     0x00287015UL   
#define TAG_DISPLAY_CALIBRATION_RESULT_SEQUENCE                                                   0x00287016UL   
#define TAG_DDL_VALUE                                                                             0x00287017UL   
#define TAG_CIEXY_WHITE_POINT                                                                     0x00287018UL   
#define TAG_DISPLAY_FUNCTION_TYPE                                                                 0x00287019UL   
#define TAG_GAMMA_VALUE                                                                           0x0028701AUL   
#define TAG_NUMBER_OF_LUMINANCE_POINTS                                                            0x0028701BUL   
#define TAG_LUMINANCE_RESPONSE_SEQUENCE                                                           0x0028701CUL   
#define TAG_TARGET_MINIMUM_LUMINANCE                                                              0x0028701DUL   
#define TAG_TARGET_MAXIMUM_LUMINANCE                                                              0x0028701EUL   
#define TAG_LUMINANCE_VALUE                                                                       0x0028701FUL   
#define TAG_LUMINANCE_RESPONSE_DESCRIPTION                                                        0x00287020UL   
#define TAG_WHITE_POINT_FLAG                                                                      0x00287021UL   
#define TAG_DISPLAY_DEVICE_TYPE_CODE_SEQUENCE                                                     0x00287022UL   
#define TAG_DISPLAY_SUBSYSTEM_SEQUENCE                                                            0x00287023UL   
#define TAG_LUMINANCE_RESULT_SEQUENCE                                                             0x00287024UL   
#define TAG_AMBIENT_LIGHT_VALUE_SOURCE                                                            0x00287025UL   
#define TAG_MEASURED_CHARACTERISTICS                                                              0x00287026UL   
#define TAG_LUMINANCE_UNIFORMITY_RESULT_SEQUENCE                                                  0x00287027UL   
#define TAG_VISUAL_EVALUATION_TEST_SEQUENCE                                                       0x00287028UL   
#define TAG_TEST_RESULT                                                                           0x00287029UL   
#define TAG_TEST_RESULT_COMMENT                                                                   0x0028702AUL   
#define TAG_TEST_IMAGE_VALIDATION                                                                 0x0028702BUL   
#define TAG_TEST_PATTERN_CODE_SEQUENCE                                                            0x0028702CUL   
#define TAG_MEASUREMENT_PATTERN_CODE_SEQUENCE                                                     0x0028702DUL   
#define TAG_VISUAL_EVALUATION_METHOD_CODE_SEQUENCE                                                0x0028702EUL   
#define TAG_PIXEL_DATA_PROVIDER_URL                                                               0x00287FE0UL   
#define TAG_DATA_POINT_ROWS                                                                       0x00289001UL   
#define TAG_DATA_POINT_COLUMNS                                                                    0x00289002UL   
#define TAG_SIGNAL_DOMAIN_COLUMNS                                                                 0x00289003UL   
#define TAG_LARGEST_MONOCHROME_PIXEL_VALUE                                                        0x00289099UL   // Retired
#define TAG_DATA_REPRESENTATION                                                                   0x00289108UL   
#define TAG_PIXEL_MEASURES_SEQUENCE                                                               0x00289110UL   
#define TAG_FRAME_VOI_LUT_SEQUENCE                                                                0x00289132UL   
#define TAG_PIXEL_VALUE_TRANSFORMATION_SEQUENCE                                                   0x00289145UL   
#define TAG_SIGNAL_DOMAIN_ROWS                                                                    0x00289235UL   
#define TAG_DISPLAY_FILTER_PERCENTAGE                                                             0x00289411UL   
#define TAG_FRAME_PIXEL_SHIFT_SEQUENCE                                                            0x00289415UL   
#define TAG_SUBTRACTION_ITEM_ID                                                                   0x00289416UL   
#define TAG_PIXEL_INTENSITY_RELATIONSHIP_LUT_SEQUENCE                                             0x00289422UL   
#define TAG_FRAME_PIXEL_DATA_PROPERTIES_SEQUENCE                                                  0x00289443UL   
#define TAG_GEOMETRICAL_PROPERTIES                                                                0x00289444UL   
#define TAG_GEOMETRIC_MAXIMUM_DISTORTION                                                          0x00289445UL   
#define TAG_IMAGE_PROCESSING_APPLIED                                                              0x00289446UL   
#define TAG_MASK_SELECTION_MODE                                                                   0x00289454UL   
#define TAG_LUT_FUNCTION                                                                          0x00289474UL   
#define TAG_MASK_VISIBILITY_PERCENTAGE                                                            0x00289478UL   
#define TAG_PIXEL_SHIFT_SEQUENCE                                                                  0x00289501UL   
#define TAG_REGION_PIXEL_SHIFT_SEQUENCE                                                           0x00289502UL   
#define TAG_VERTICES_OF_THE_REGION                                                                0x00289503UL   
#define TAG_MULTI_FRAME_PRESENTATION_SEQUENCE                                                     0x00289505UL   
#define TAG_PIXEL_SHIFT_FRAME_RANGE                                                               0x00289506UL   
#define TAG_LUT_FRAME_RANGE                                                                       0x00289507UL   
#define TAG_IMAGE_TO_EQUIPMENT_MAPPING_MATRIX                                                     0x00289520UL   
#define TAG_EQUIPMENT_COORDINATE_SYSTEM_IDENTIFICATION                                            0x00289537UL   

// *****************************************************************************************************************************
// *** 0032
// *****************************************************************************************************************************
#define TAG_STUDY_STATUS_ID                                                                       0x0032000AUL   // Retired
#define TAG_STUDY_PRIORITY_ID                                                                     0x0032000CUL   // Retired
#define TAG_STUDY_ID_ISSUER                                                                       0x00320012UL   // Retired
#define TAG_STUDY_VERIFIED_DATE                                                                   0x00320032UL   // Retired
#define TAG_STUDY_VERIFIED_TIME                                                                   0x00320033UL   // Retired
#define TAG_STUDY_READ_DATE                                                                       0x00320034UL   // Retired
#define TAG_STUDY_READ_TIME                                                                       0x00320035UL   // Retired
#define TAG_SCHEDULED_STUDY_START_DATE                                                            0x00321000UL   // Retired
#define TAG_SCHEDULED_STUDY_START_TIME                                                            0x00321001UL   // Retired
#define TAG_SCHEDULED_STUDY_STOP_DATE                                                             0x00321010UL   // Retired
#define TAG_SCHEDULED_STUDY_STOP_TIME                                                             0x00321011UL   // Retired
#define TAG_SCHEDULED_STUDY_LOCATION                                                              0x00321020UL   // Retired
#define TAG_SCHEDULED_STUDY_LOCATION_AE_TITLE                                                     0x00321021UL   // Retired
#define TAG_REASON_FOR_STUDY                                                                      0x00321030UL   // Retired
#define TAG_REQUESTING_PHYSICIAN_IDENTIFICATION_SEQUENCE                                          0x00321031UL   
#define TAG_REQUESTING_PHYSICIAN                                                                  0x00321032UL   
#define TAG_REQUESTING_SERVICE                                                                    0x00321033UL   
#define TAG_REQUESTING_SERVICE_CODE_SEQUENCE                                                      0x00321034UL   
#define TAG_STUDY_ARRIVAL_DATE                                                                    0x00321040UL   // Retired
#define TAG_STUDY_ARRIVAL_TIME                                                                    0x00321041UL   // Retired
#define TAG_STUDY_COMPLETION_DATE                                                                 0x00321050UL   // Retired
#define TAG_STUDY_COMPLETION_TIME                                                                 0x00321051UL   // Retired
#define TAG_STUDY_COMPONENT_STATUS_ID                                                             0x00321055UL   // Retired
#define TAG_REQUESTED_PROCEDURE_DESCRIPTION                                                       0x00321060UL   
#define TAG_REQUESTED_PROCEDURE_CODE_SEQUENCE                                                     0x00321064UL   
#define TAG_REASON_FOR_VISIT                                                                      0x00321066UL   
#define TAG_REASON_FOR_VISIT_CODE_SEQUENCE                                                        0x00321067UL   
#define TAG_REQUESTED_CONTRAST_AGENT                                                              0x00321070UL   
#define TAG_STUDY_COMMENTS                                                                        0x00324000UL   // Retired

// *****************************************************************************************************************************
// *** 0034
// *****************************************************************************************************************************
#define TAG_FLOW_IDENTIFIER_SEQUENCE                                                              0x00340001UL   
#define TAG_FLOW_IDENTIFIER                                                                       0x00340002UL   
#define TAG_FLOW_TRANSFER_SYNTAX_UID                                                              0x00340003UL   
#define TAG_FLOW_RTP_SAMPLING_RATE                                                                0x00340004UL   
#define TAG_SOURCE_IDENTIFIER                                                                     0x00340005UL   
#define TAG_FRAME_ORIGIN_TIMESTAMP                                                                0x00340007UL   
#define TAG_INCLUDES_IMAGING_SUBJECT                                                              0x00340008UL   
#define TAG_FRAME_USEFULNESS_GROUP_SEQUENCE                                                       0x00340009UL   
#define TAG_REAL_TIME_BULK_DATA_FLOW_SEQUENCE                                                     0x0034000AUL   
#define TAG_CAMERA_POSITION_GROUP_SEQUENCE                                                        0x0034000BUL   
#define TAG_INCLUDES_INFORMATION                                                                  0x0034000CUL   
#define TAG_TIME_OF_FRAME_GROUP_SEQUENCE                                                          0x0034000DUL   

// *****************************************************************************************************************************
// *** 0038
// *****************************************************************************************************************************
#define TAG_REFERENCED_PATIENT_ALIAS_SEQUENCE                                                     0x00380004UL   
#define TAG_VISIT_STATUS_ID                                                                       0x00380008UL   
#define TAG_ADMISSION_ID                                                                          0x00380010UL   
#define TAG_ISSUER_OF_ADMISSION_ID                                                                0x00380011UL   // Retired
#define TAG_ISSUER_OF_ADMISSION_ID_SEQUENCE                                                       0x00380014UL   
#define TAG_ROUTE_OF_ADMISSIONS                                                                   0x00380016UL   
#define TAG_SCHEDULED_ADMISSION_DATE                                                              0x0038001AUL   // Retired
#define TAG_SCHEDULED_ADMISSION_TIME                                                              0x0038001BUL   // Retired
#define TAG_SCHEDULED_DISCHARGE_DATE                                                              0x0038001CUL   // Retired
#define TAG_SCHEDULED_DISCHARGE_TIME                                                              0x0038001DUL   // Retired
#define TAG_SCHEDULED_PATIENT_INSTITUTION_RESIDENCE                                               0x0038001EUL   // Retired
#define TAG_ADMITTING_DATE                                                                        0x00380020UL   
#define TAG_ADMITTING_TIME                                                                        0x00380021UL   
#define TAG_DISCHARGE_DATE                                                                        0x00380030UL   // Retired
#define TAG_DISCHARGE_TIME                                                                        0x00380032UL   // Retired
#define TAG_DISCHARGE_DIAGNOSIS_DESCRIPTION                                                       0x00380040UL   // Retired
#define TAG_DISCHARGE_DIAGNOSIS_CODE_SEQUENCE                                                     0x00380044UL   // Retired
#define TAG_SPECIAL_NEEDS                                                                         0x00380050UL   
#define TAG_SERVICE_EPISODE_ID                                                                    0x00380060UL   
#define TAG_ISSUER_OF_SERVICE_EPISODE_ID                                                          0x00380061UL   // Retired
#define TAG_SERVICE_EPISODE_DESCRIPTION                                                           0x00380062UL   
#define TAG_ISSUER_OF_SERVICE_EPISODE_ID_SEQUENCE                                                 0x00380064UL   
#define TAG_PERTINENT_DOCUMENTS_SEQUENCE                                                          0x00380100UL   
#define TAG_PERTINENT_RESOURCES_SEQUENCE                                                          0x00380101UL   
#define TAG_RESOURCE_DESCRIPTION                                                                  0x00380102UL   
#define TAG_CURRENT_PATIENT_LOCATION                                                              0x00380300UL   
#define TAG_PATIENT_INSTITUTION_RESIDENCE                                                         0x00380400UL   
#define TAG_PATIENT_STATE                                                                         0x00380500UL   
#define TAG_PATIENT_CLINICAL_TRIAL_PARTICIPATION_SEQUENCE                                         0x00380502UL   
#define TAG_VISIT_COMMENTS                                                                        0x00384000UL   

// *****************************************************************************************************************************
// *** 003A
// *****************************************************************************************************************************
#define TAG_WAVEFORM_ORIGINALITY                                                                  0x003A0004UL   
#define TAG_NUMBER_OF_WAVEFORM_CHANNELS                                                           0x003A0005UL   
#define TAG_NUMBER_OF_WAVEFORM_SAMPLES                                                            0x003A0010UL   
#define TAG_SAMPLING_FREQUENCY                                                                    0x003A001AUL   
#define TAG_MULTIPLEX_GROUP_LABEL                                                                 0x003A0020UL   
#define TAG_CHANNEL_DEFINITION_SEQUENCE                                                           0x003A0200UL   
#define TAG_WAVEFORM_CHANNEL_NUMBER                                                               0x003A0202UL   
#define TAG_CHANNEL_LABEL                                                                         0x003A0203UL   
#define TAG_CHANNEL_STATUS                                                                        0x003A0205UL   
#define TAG_CHANNEL_SOURCE_SEQUENCE                                                               0x003A0208UL   
#define TAG_CHANNEL_SOURCE_MODIFIERS_SEQUENCE                                                     0x003A0209UL   
#define TAG_SOURCE_WAVEFORM_SEQUENCE                                                              0x003A020AUL   
#define TAG_CHANNEL_DERIVATION_DESCRIPTION                                                        0x003A020CUL   
#define TAG_CHANNEL_SENSITIVITY                                                                   0x003A0210UL   
#define TAG_CHANNEL_SENSITIVITY_UNITS_SEQUENCE                                                    0x003A0211UL   
#define TAG_CHANNEL_SENSITIVITY_CORRECTION_FACTOR                                                 0x003A0212UL   
#define TAG_CHANNEL_BASELINE                                                                      0x003A0213UL   
#define TAG_CHANNEL_TIME_SKEW                                                                     0x003A0214UL   
#define TAG_CHANNEL_SAMPLE_SKEW                                                                   0x003A0215UL   
#define TAG_CHANNEL_OFFSET                                                                        0x003A0218UL   
#define TAG_WAVEFORM_BITS_STORED                                                                  0x003A021AUL   
#define TAG_FILTER_LOW_FREQUENCY                                                                  0x003A0220UL   
#define TAG_FILTER_HIGH_FREQUENCY                                                                 0x003A0221UL   
#define TAG_NOTCH_FILTER_FREQUENCY                                                                0x003A0222UL   
#define TAG_NOTCH_FILTER_BANDWIDTH                                                                0x003A0223UL   
#define TAG_WAVEFORM_DATA_DISPLAY_SCALE                                                           0x003A0230UL   
#define TAG_WAVEFORM_DISPLAY_BACKGROUND_CIELAB_VALUE                                              0x003A0231UL   
#define TAG_WAVEFORM_PRESENTATION_GROUP_SEQUENCE                                                  0x003A0240UL   
#define TAG_PRESENTATION_GROUP_NUMBER                                                             0x003A0241UL   
#define TAG_CHANNEL_DISPLAY_SEQUENCE                                                              0x003A0242UL   
#define TAG_CHANNEL_RECOMMENDED_DISPLAY_CIELAB_VALUE                                              0x003A0244UL   
#define TAG_CHANNEL_POSITION                                                                      0x003A0245UL   
#define TAG_DISPLAY_SHADING_FLAG                                                                  0x003A0246UL   
#define TAG_FRACTIONAL_CHANNEL_DISPLAY_SCALE                                                      0x003A0247UL   
#define TAG_ABSOLUTE_CHANNEL_DISPLAY_SCALE                                                        0x003A0248UL   
#define TAG_MULTIPLEXED_AUDIO_CHANNELS_DESCRIPTION_CODE_SEQUENCE                                  0x003A0300UL   
#define TAG_CHANNEL_IDENTIFICATION_CODE                                                           0x003A0301UL   
#define TAG_CHANNEL_MODE                                                                          0x003A0302UL   
#define TAG_MULTIPLEX_GROUP_UID                                                                   0x003A0310UL   
#define TAG_POWERLINE_FREQUENCY                                                                   0x003A0311UL   
#define TAG_CHANNEL_IMPEDANCE_SEQUENCE                                                            0x003A0312UL   
#define TAG_IMPEDANCE_VALUE                                                                       0x003A0313UL   
#define TAG_IMPEDANCE_MEASUREMENT_DATETIME                                                        0x003A0314UL   
#define TAG_IMPEDANCE_MEASUREMENT_FREQUENCY                                                       0x003A0315UL   
#define TAG_IMPEDANCE_MEASUREMENT_CURRENT_TYPE                                                    0x003A0316UL   

// *****************************************************************************************************************************
// *** 0040
// *****************************************************************************************************************************
#define TAG_SCHEDULED_STATION_AE_TITLE                                                            0x00400001UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_START_DATE                                                   0x00400002UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_START_TIME                                                   0x00400003UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_END_DATE                                                     0x00400004UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_END_TIME                                                     0x00400005UL   
#define TAG_SCHEDULED_PERFORMING_PHYSICIAN_NAME                                                   0x00400006UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_DESCRIPTION                                                  0x00400007UL   
#define TAG_SCHEDULED_PROTOCOL_CODE_SEQUENCE                                                      0x00400008UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_ID                                                           0x00400009UL   
#define TAG_STAGE_CODE_SEQUENCE                                                                   0x0040000AUL   
#define TAG_SCHEDULED_PERFORMING_PHYSICIAN_IDENTIFICATION_SEQUENCE                                0x0040000BUL   
#define TAG_SCHEDULED_STATION_NAME                                                                0x00400010UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_LOCATION                                                     0x00400011UL   
#define TAG_PRE_MEDICATION                                                                        0x00400012UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_STATUS                                                       0x00400020UL   
#define TAG_ORDER_PLACER_IDENTIFIER_SEQUENCE                                                      0x00400026UL   
#define TAG_ORDER_FILLER_IDENTIFIER_SEQUENCE                                                      0x00400027UL   
#define TAG_LOCAL_NAMESPACE_ENTITY_ID                                                             0x00400031UL   
#define TAG_UNIVERSAL_ENTITY_ID                                                                   0x00400032UL   
#define TAG_UNIVERSAL_ENTITY_ID_TYPE                                                              0x00400033UL   
#define TAG_IDENTIFIER_TYPE_CODE                                                                  0x00400035UL   
#define TAG_ASSIGNING_FACILITY_SEQUENCE                                                           0x00400036UL   
#define TAG_ASSIGNING_JURISDICTION_CODE_SEQUENCE                                                  0x00400039UL   
#define TAG_ASSIGNING_AGENCY_OR_DEPARTMENT_CODE_SEQUENCE                                          0x0040003AUL   
#define TAG_SCHEDULED_PROCEDURE_STEP_SEQUENCE                                                     0x00400100UL   
#define TAG_REFERENCED_NON_IMAGE_COMPOSITE_SOP_INSTANCE_SEQUENCE                                  0x00400220UL   
#define TAG_PERFORMED_STATION_AE_TITLE                                                            0x00400241UL   
#define TAG_PERFORMED_STATION_NAME                                                                0x00400242UL   
#define TAG_PERFORMED_LOCATION                                                                    0x00400243UL   
#define TAG_PERFORMED_PROCEDURE_STEP_START_DATE                                                   0x00400244UL   
#define TAG_PERFORMED_PROCEDURE_STEP_START_TIME                                                   0x00400245UL   
#define TAG_PERFORMED_PROCEDURE_STEP_END_DATE                                                     0x00400250UL   
#define TAG_PERFORMED_PROCEDURE_STEP_END_TIME                                                     0x00400251UL   
#define TAG_PERFORMED_PROCEDURE_STEP_STATUS                                                       0x00400252UL   
#define TAG_PERFORMED_PROCEDURE_STEP_ID                                                           0x00400253UL   
#define TAG_PERFORMED_PROCEDURE_STEP_DESCRIPTION                                                  0x00400254UL   
#define TAG_PERFORMED_PROCEDURE_TYPE_DESCRIPTION                                                  0x00400255UL   
#define TAG_PERFORMED_PROTOCOL_CODE_SEQUENCE                                                      0x00400260UL   
#define TAG_PERFORMED_PROTOCOL_TYPE                                                               0x00400261UL   
#define TAG_SCHEDULED_STEP_ATTRIBUTES_SEQUENCE                                                    0x00400270UL   
#define TAG_REQUEST_ATTRIBUTES_SEQUENCE                                                           0x00400275UL   
#define TAG_COMMENTS_ON_THE_PERFORMED_PROCEDURE_STEP                                              0x00400280UL   
#define TAG_PERFORMED_PROCEDURE_STEP_DISCONTINUATION_REASON_CODE_SEQUENCE                         0x00400281UL   
#define TAG_QUANTITY_SEQUENCE                                                                     0x00400293UL   
#define TAG_QUANTITY                                                                              0x00400294UL   
#define TAG_MEASURING_UNITS_SEQUENCE                                                              0x00400295UL   
#define TAG_BILLING_ITEM_SEQUENCE                                                                 0x00400296UL   
#define TAG_TOTAL_TIME_OF_FLUOROSCOPY                                                             0x00400300UL   // Retired
#define TAG_TOTAL_NUMBER_OF_EXPOSURES                                                             0x00400301UL   // Retired
#define TAG_ENTRANCE_DOSE                                                                         0x00400302UL   
#define TAG_EXPOSED_AREA                                                                          0x00400303UL   
#define TAG_DISTANCE_SOURCE_TO_ENTRANCE                                                           0x00400306UL   
#define TAG_DISTANCE_SOURCE_TO_SUPPORT                                                            0x00400307UL   // Retired
#define TAG_EXPOSURE_DOSE_SEQUENCE                                                                0x0040030EUL   // Retired
#define TAG_COMMENTS_ON_RADIATION_DOSE                                                            0x00400310UL   
#define TAG_X_RAY_OUTPUT                                                                          0x00400312UL   
#define TAG_HALF_VALUE_LAYER                                                                      0x00400314UL   
#define TAG_ORGAN_DOSE                                                                            0x00400316UL   
#define TAG_ORGAN_EXPOSED                                                                         0x00400318UL   
#define TAG_BILLING_PROCEDURE_STEP_SEQUENCE                                                       0x00400320UL   
#define TAG_FILM_CONSUMPTION_SEQUENCE                                                             0x00400321UL   
#define TAG_BILLING_SUPPLIES_AND_DEVICES_SEQUENCE                                                 0x00400324UL   
#define TAG_REFERENCED_PROCEDURE_STEP_SEQUENCE                                                    0x00400330UL   // Retired
#define TAG_PERFORMED_SERIES_SEQUENCE                                                             0x00400340UL   
#define TAG_COMMENTS_ON_THE_SCHEDULED_PROCEDURE_STEP                                              0x00400400UL   
#define TAG_PROTOCOL_CONTEXT_SEQUENCE                                                             0x00400440UL   
#define TAG_CONTENT_ITEM_MODIFIER_SEQUENCE                                                        0x00400441UL   
#define TAG_SCHEDULED_SPECIMEN_SEQUENCE                                                           0x00400500UL   
#define TAG_SPECIMEN_ACCESSION_NUMBER                                                             0x0040050AUL   // Retired
#define TAG_CONTAINER_IDENTIFIER                                                                  0x00400512UL   
#define TAG_ISSUER_OF_THE_CONTAINER_IDENTIFIER_SEQUENCE                                           0x00400513UL   
#define TAG_ALTERNATE_CONTAINER_IDENTIFIER_SEQUENCE                                               0x00400515UL   
#define TAG_CONTAINER_TYPE_CODE_SEQUENCE                                                          0x00400518UL   
#define TAG_CONTAINER_DESCRIPTION                                                                 0x0040051AUL   
#define TAG_CONTAINER_COMPONENT_SEQUENCE                                                          0x00400520UL   
#define TAG_SPECIMEN_SEQUENCE                                                                     0x00400550UL   // Retired
#define TAG_SPECIMEN_IDENTIFIER                                                                   0x00400551UL   
#define TAG_SPECIMEN_DESCRIPTION_SEQUENCE_TRIAL                                                   0x00400552UL   // Retired
#define TAG_SPECIMEN_DESCRIPTION_TRIAL                                                            0x00400553UL   // Retired
#define TAG_SPECIMEN_UID                                                                          0x00400554UL   
#define TAG_ACQUISITION_CONTEXT_SEQUENCE                                                          0x00400555UL   
#define TAG_ACQUISITION_CONTEXT_DESCRIPTION                                                       0x00400556UL   
#define TAG_SPECIMEN_DESCRIPTION_SEQUENCE                                                         0x00400560UL   
#define TAG_ISSUER_OF_THE_SPECIMEN_IDENTIFIER_SEQUENCE                                            0x00400562UL   
#define TAG_SPECIMEN_TYPE_CODE_SEQUENCE                                                           0x0040059AUL   
#define TAG_SPECIMEN_SHORT_DESCRIPTION                                                            0x00400600UL   
#define TAG_SPECIMEN_DETAILED_DESCRIPTION                                                         0x00400602UL   
#define TAG_SPECIMEN_PREPARATION_SEQUENCE                                                         0x00400610UL   
#define TAG_SPECIMEN_PREPARATION_STEP_CONTENT_ITEM_SEQUENCE                                       0x00400612UL   
#define TAG_SPECIMEN_LOCALIZATION_CONTENT_ITEM_SEQUENCE                                           0x00400620UL   
#define TAG_SLIDE_IDENTIFIER                                                                      0x004006FAUL   // Retired
#define TAG_WHOLE_SLIDE_MICROSCOPY_IMAGE_FRAME_TYPE_SEQUENCE                                      0x00400710UL   
#define TAG_IMAGE_CENTER_POINT_COORDINATES_SEQUENCE                                               0x0040071AUL   
#define TAG_X_OFFSET_IN_SLIDE_COORDINATE_SYSTEM                                                   0x0040072AUL   
#define TAG_Y_OFFSET_IN_SLIDE_COORDINATE_SYSTEM                                                   0x0040073AUL   
#define TAG_Z_OFFSET_IN_SLIDE_COORDINATE_SYSTEM                                                   0x0040074AUL   
#define TAG_PIXEL_SPACING_SEQUENCE                                                                0x004008D8UL   // Retired
#define TAG_COORDINATE_SYSTEM_AXIS_CODE_SEQUENCE                                                  0x004008DAUL   // Retired
#define TAG_MEASUREMENT_UNITS_CODE_SEQUENCE                                                       0x004008EAUL   
#define TAG_VITAL_STAIN_CODE_SEQUENCE_TRIAL                                                       0x004009F8UL   // Retired
#define TAG_REQUESTED_PROCEDURE_ID                                                                0x00401001UL   
#define TAG_REASON_FOR_THE_REQUESTED_PROCEDURE                                                    0x00401002UL   
#define TAG_REQUESTED_PROCEDURE_PRIORITY                                                          0x00401003UL   
#define TAG_PATIENT_TRANSPORT_ARRANGEMENTS                                                        0x00401004UL   
#define TAG_REQUESTED_PROCEDURE_LOCATION                                                          0x00401005UL   
#define TAG_PLACER_ORDER_NUMBER_PROCEDURE                                                         0x00401006UL   // Retired
#define TAG_FILLER_ORDER_NUMBER_PROCEDURE                                                         0x00401007UL   // Retired
#define TAG_CONFIDENTIALITY_CODE                                                                  0x00401008UL   
#define TAG_REPORTING_PRIORITY                                                                    0x00401009UL   
#define TAG_REASON_FOR_REQUESTED_PROCEDURE_CODE_SEQUENCE                                          0x0040100AUL   
#define TAG_NAMES_OF_INTENDED_RECIPIENTS_OF_RESULTS                                               0x00401010UL   
#define TAG_INTENDED_RECIPIENTS_OF_RESULTS_IDENTIFICATION_SEQUENCE                                0x00401011UL   
#define TAG_REASON_FOR_PERFORMED_PROCEDURE_CODE_SEQUENCE                                          0x00401012UL   
#define TAG_REQUESTED_PROCEDURE_DESCRIPTION_TRIAL                                                 0x00401060UL   // Retired
#define TAG_PERSON_IDENTIFICATION_CODE_SEQUENCE                                                   0x00401101UL   
#define TAG_PERSON_ADDRESS                                                                        0x00401102UL   
#define TAG_PERSON_TELEPHONE_NUMBERS                                                              0x00401103UL   
#define TAG_PERSON_TELECOM_INFORMATION                                                            0x00401104UL   
#define TAG_REQUESTED_PROCEDURE_COMMENTS                                                          0x00401400UL   
#define TAG_REASON_FOR_THE_IMAGING_SERVICE_REQUEST                                                0x00402001UL   // Retired
#define TAG_ISSUE_DATE_OF_IMAGING_SERVICE_REQUEST                                                 0x00402004UL   
#define TAG_ISSUE_TIME_OF_IMAGING_SERVICE_REQUEST                                                 0x00402005UL   
#define TAG_PLACER_ORDER_NUMBER_IMAGING_SERVICE_REQUEST_RETIRED                                   0x00402006UL   // Retired
#define TAG_FILLER_ORDER_NUMBER_IMAGING_SERVICE_REQUEST_RETIRED                                   0x00402007UL   // Retired
#define TAG_ORDER_ENTERED_BY                                                                      0x00402008UL   
#define TAG_ORDER_ENTERER_LOCATION                                                                0x00402009UL   
#define TAG_ORDER_CALLBACK_PHONE_NUMBER                                                           0x00402010UL   
#define TAG_ORDER_CALLBACK_TELECOM_INFORMATION                                                    0x00402011UL   
#define TAG_PLACER_ORDER_NUMBER_IMAGING_SERVICE_REQUEST                                           0x00402016UL   
#define TAG_FILLER_ORDER_NUMBER_IMAGING_SERVICE_REQUEST                                           0x00402017UL   
#define TAG_IMAGING_SERVICE_REQUEST_COMMENTS                                                      0x00402400UL   
#define TAG_CONFIDENTIALITY_CONSTRAINT_ON_PATIENT_DATA_DESCRIPTION                                0x00403001UL   
#define TAG_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_STATUS                                       0x00404001UL   // Retired
#define TAG_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_STATUS                                       0x00404002UL   // Retired
#define TAG_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_PRIORITY                                     0x00404003UL   // Retired
#define TAG_SCHEDULED_PROCESSING_APPLICATIONS_CODE_SEQUENCE                                       0x00404004UL   // Retired
#define TAG_SCHEDULED_PROCEDURE_STEP_START_DATETIME                                               0x00404005UL   
#define TAG_MULTIPLE_COPIES_FLAG                                                                  0x00404006UL   // Retired
#define TAG_PERFORMED_PROCESSING_APPLICATIONS_CODE_SEQUENCE                                       0x00404007UL   // Retired
#define TAG_SCHEDULED_PROCEDURE_STEP_EXPIRATION_DATETIME                                          0x00404008UL   
#define TAG_HUMAN_PERFORMER_CODE_SEQUENCE                                                         0x00404009UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_MODIFICATION_DATETIME                                        0x00404010UL   
#define TAG_EXPECTED_COMPLETION_DATETIME                                                          0x00404011UL   
#define TAG_RESULTING_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEPS_SEQUENCE                          0x00404015UL   // Retired
#define TAG_REFERENCED_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_SEQUENCE                          0x00404016UL   // Retired
#define TAG_SCHEDULED_WORKITEM_CODE_SEQUENCE                                                      0x00404018UL   
#define TAG_PERFORMED_WORKITEM_CODE_SEQUENCE                                                      0x00404019UL   
#define TAG_INPUT_AVAILABILITY_FLAG                                                               0x00404020UL   // Retired
#define TAG_INPUT_INFORMATION_SEQUENCE                                                            0x00404021UL   
#define TAG_RELEVANT_INFORMATION_SEQUENCE                                                         0x00404022UL   // Retired
#define TAG_REFERENCED_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_TRANSACTION_UID                   0x00404023UL   // Retired
#define TAG_SCHEDULED_STATION_NAME_CODE_SEQUENCE                                                  0x00404025UL   
#define TAG_SCHEDULED_STATION_CLASS_CODE_SEQUENCE                                                 0x00404026UL   
#define TAG_SCHEDULED_STATION_GEOGRAPHIC_LOCATION_CODE_SEQUENCE                                   0x00404027UL   
#define TAG_PERFORMED_STATION_NAME_CODE_SEQUENCE                                                  0x00404028UL   
#define TAG_PERFORMED_STATION_CLASS_CODE_SEQUENCE                                                 0x00404029UL   
#define TAG_PERFORMED_STATION_GEOGRAPHIC_LOCATION_CODE_SEQUENCE                                   0x00404030UL   
#define TAG_REQUESTED_SUBSEQUENT_WORKITEM_CODE_SEQUENCE                                           0x00404031UL   // Retired
#define TAG_NON_DICOM_OUTPUT_CODE_SEQUENCE                                                        0x00404032UL   // Retired
#define TAG_OUTPUT_INFORMATION_SEQUENCE                                                           0x00404033UL   
#define TAG_SCHEDULED_HUMAN_PERFORMERS_SEQUENCE                                                   0x00404034UL   
#define TAG_ACTUAL_HUMAN_PERFORMERS_SEQUENCE                                                      0x00404035UL   
#define TAG_HUMAN_PERFORMER_ORGANIZATION                                                          0x00404036UL   
#define TAG_HUMAN_PERFORMER_NAME                                                                  0x00404037UL   
#define TAG_RAW_DATA_HANDLING                                                                     0x00404040UL   
#define TAG_INPUT_READINESS_STATE                                                                 0x00404041UL   
#define TAG_PERFORMED_PROCEDURE_STEP_START_DATETIME                                               0x00404050UL   
#define TAG_PERFORMED_PROCEDURE_STEP_END_DATETIME                                                 0x00404051UL   
#define TAG_PROCEDURE_STEP_CANCELLATION_DATETIME                                                  0x00404052UL   
#define TAG_OUTPUT_DESTINATION_SEQUENCE                                                           0x00404070UL   
#define TAG_DICOM_STORAGE_SEQUENCE                                                                0x00404071UL   
#define TAG_STOW_RS_STORAGE_SEQUENCE                                                              0x00404072UL   
#define TAG_STORAGE_URL                                                                           0x00404073UL   
#define TAG_XDS_STORAGE_SEQUENCE                                                                  0x00404074UL   
#define TAG_ENTRANCE_DOSE_IN_MGY                                                                  0x00408302UL   
#define TAG_ENTRANCE_DOSE_DERIVATION                                                              0x00408303UL   
#define TAG_PARAMETRIC_MAP_FRAME_TYPE_SEQUENCE                                                    0x00409092UL   
#define TAG_REFERENCED_IMAGE_REAL_WORLD_VALUE_MAPPING_SEQUENCE                                    0x00409094UL   
#define TAG_REAL_WORLD_VALUE_MAPPING_SEQUENCE                                                     0x00409096UL   
#define TAG_PIXEL_VALUE_MAPPING_CODE_SEQUENCE                                                     0x00409098UL   
#define TAG_LUT_LABEL                                                                             0x00409210UL   
#define TAG_REAL_WORLD_VALUE_LAST_VALUE_MAPPED                                                    0x00409211UL   
#define TAG_REAL_WORLD_VALUE_LUT_DATA                                                             0x00409212UL   
#define TAG_DOUBLE_FLOAT_REAL_WORLD_VALUE_LAST_VALUE_MAPPED                                       0x00409213UL   
#define TAG_DOUBLE_FLOAT_REAL_WORLD_VALUE_FIRST_VALUE_MAPPED                                      0x00409214UL   
#define TAG_REAL_WORLD_VALUE_FIRST_VALUE_MAPPED                                                   0x00409216UL   
#define TAG_QUANTITY_DEFINITION_SEQUENCE                                                          0x00409220UL   
#define TAG_REAL_WORLD_VALUE_INTERCEPT                                                            0x00409224UL   
#define TAG_REAL_WORLD_VALUE_SLOPE                                                                0x00409225UL   
#define TAG_FINDINGS_FLAG_TRIAL                                                                   0x0040A007UL   // Retired
#define TAG_RELATIONSHIP_TYPE                                                                     0x0040A010UL   
#define TAG_FINDINGS_SEQUENCE_TRIAL                                                               0x0040A020UL   // Retired
#define TAG_FINDINGS_GROUP_UID_TRIAL                                                              0x0040A021UL   // Retired
#define TAG_REFERENCED_FINDINGS_GROUP_UID_TRIAL                                                   0x0040A022UL   // Retired
#define TAG_FINDINGS_GROUP_RECORDING_DATE_TRIAL                                                   0x0040A023UL   // Retired
#define TAG_FINDINGS_GROUP_RECORDING_TIME_TRIAL                                                   0x0040A024UL   // Retired
#define TAG_FINDINGS_SOURCE_CATEGORY_CODE_SEQUENCE_TRIAL                                          0x0040A026UL   // Retired
#define TAG_VERIFYING_ORGANIZATION                                                                0x0040A027UL   
#define TAG_DOCUMENTING_ORGANIZATION_IDENTIFIER_CODE_SEQUENCE_TRIAL                               0x0040A028UL   // Retired
#define TAG_VERIFICATION_DATETIME                                                                 0x0040A030UL   
#define TAG_OBSERVATION_DATETIME                                                                  0x0040A032UL   
#define TAG_OBSERVATION_START_DATETIME                                                            0x0040A033UL   
#define TAG_VALUE_TYPE                                                                            0x0040A040UL   
#define TAG_CONCEPT_NAME_CODE_SEQUENCE                                                            0x0040A043UL   
#define TAG_MEASUREMENT_PRECISION_DESCRIPTION_TRIAL                                               0x0040A047UL   // Retired
#define TAG_CONTINUITY_OF_CONTENT                                                                 0x0040A050UL   
#define TAG_URGENCY_OR_PRIORITY_ALERTS_TRIAL                                                      0x0040A057UL   // Retired
#define TAG_SEQUENCING_INDICATOR_TRIAL                                                            0x0040A060UL   // Retired
#define TAG_DOCUMENT_IDENTIFIER_CODE_SEQUENCE_TRIAL                                               0x0040A066UL   // Retired
#define TAG_DOCUMENT_AUTHOR_TRIAL                                                                 0x0040A067UL   // Retired
#define TAG_DOCUMENT_AUTHOR_IDENTIFIER_CODE_SEQUENCE_TRIAL                                        0x0040A068UL   // Retired
#define TAG_IDENTIFIER_CODE_SEQUENCE_TRIAL                                                        0x0040A070UL   // Retired
#define TAG_VERIFYING_OBSERVER_SEQUENCE                                                           0x0040A073UL   
#define TAG_OBJECT_BINARY_IDENTIFIER_TRIAL                                                        0x0040A074UL   // Retired
#define TAG_VERIFYING_OBSERVER_NAME                                                               0x0040A075UL   
#define TAG_DOCUMENTING_OBSERVER_IDENTIFIER_CODE_SEQUENCE_TRIAL                                   0x0040A076UL   // Retired
#define TAG_AUTHOR_OBSERVER_SEQUENCE                                                              0x0040A078UL   
#define TAG_PARTICIPANT_SEQUENCE                                                                  0x0040A07AUL   
#define TAG_CUSTODIAL_ORGANIZATION_SEQUENCE                                                       0x0040A07CUL   
#define TAG_PARTICIPATION_TYPE                                                                    0x0040A080UL   
#define TAG_PARTICIPATION_DATETIME                                                                0x0040A082UL   
#define TAG_OBSERVER_TYPE                                                                         0x0040A084UL   
#define TAG_PROCEDURE_IDENTIFIER_CODE_SEQUENCE_TRIAL                                              0x0040A085UL   // Retired
#define TAG_VERIFYING_OBSERVER_IDENTIFICATION_CODE_SEQUENCE                                       0x0040A088UL   
#define TAG_OBJECT_DIRECTORY_BINARY_IDENTIFIER_TRIAL                                              0x0040A089UL   // Retired
#define TAG_EQUIVALENT_CDA_DOCUMENT_SEQUENCE                                                      0x0040A090UL   // Retired
#define TAG_REFERENCED_WAVEFORM_CHANNELS                                                          0x0040A0B0UL   
#define TAG_DATE_OF_DOCUMENT_OR_VERBAL_TRANSACTION_TRIAL                                          0x0040A110UL   // Retired
#define TAG_TIME_OF_DOCUMENT_CREATION_OR_VERBAL_TRANSACTION_TRIAL                                 0x0040A112UL   // Retired
#define TAG_DATETIME                                                                              0x0040A120UL   
#define TAG_DATE                                                                                  0x0040A121UL   
#define TAG_TIME                                                                                  0x0040A122UL   
#define TAG_PERSON_NAME                                                                           0x0040A123UL   
#define TAG_UID                                                                                   0x0040A124UL   
#define TAG_REPORT_STATUS_ID_TRIAL                                                                0x0040A125UL   // Retired
#define TAG_TEMPORAL_RANGE_TYPE                                                                   0x0040A130UL   
#define TAG_REFERENCED_SAMPLE_POSITIONS                                                           0x0040A132UL   
#define TAG_REFERENCED_FRAME_NUMBERS                                                              0x0040A136UL   // Retired
#define TAG_REFERENCED_TIME_OFFSETS                                                               0x0040A138UL   
#define TAG_REFERENCED_DATETIME                                                                   0x0040A13AUL   
#define TAG_TEXT_VALUE                                                                            0x0040A160UL   
#define TAG_FLOATING_POINT_VALUE                                                                  0x0040A161UL   
#define TAG_RATIONAL_NUMERATOR_VALUE                                                              0x0040A162UL   
#define TAG_RATIONAL_DENOMINATOR_VALUE                                                            0x0040A163UL   
#define TAG_OBSERVATION_CATEGORY_CODE_SEQUENCE_TRIAL                                              0x0040A167UL   // Retired
#define TAG_CONCEPT_CODE_SEQUENCE                                                                 0x0040A168UL   
#define TAG_BIBLIOGRAPHIC_CITATION_TRIAL                                                          0x0040A16AUL   // Retired
#define TAG_PURPOSE_OF_REFERENCE_CODE_SEQUENCE                                                    0x0040A170UL   
#define TAG_OBSERVATION_UID                                                                       0x0040A171UL   
#define TAG_REFERENCED_OBSERVATION_UID_TRIAL                                                      0x0040A172UL   // Retired
#define TAG_REFERENCED_OBSERVATION_CLASS_TRIAL                                                    0x0040A173UL   // Retired
#define TAG_REFERENCED_OBJECT_OBSERVATION_CLASS_TRIAL                                             0x0040A174UL   // Retired
#define TAG_ANNOTATION_GROUP_NUMBER                                                               0x0040A180UL   
#define TAG_OBSERVATION_DATE_TRIAL                                                                0x0040A192UL   // Retired
#define TAG_OBSERVATION_TIME_TRIAL                                                                0x0040A193UL   // Retired
#define TAG_MEASUREMENT_AUTOMATION_TRIAL                                                          0x0040A194UL   // Retired
#define TAG_MODIFIER_CODE_SEQUENCE                                                                0x0040A195UL   
#define TAG_IDENTIFICATION_DESCRIPTION_TRIAL                                                      0x0040A224UL   // Retired
#define TAG_COORDINATES_SET_GEOMETRIC_TYPE_TRIAL                                                  0x0040A290UL   // Retired
#define TAG_ALGORITHM_CODE_SEQUENCE_TRIAL                                                         0x0040A296UL   // Retired
#define TAG_ALGORITHM_DESCRIPTION_TRIAL                                                           0x0040A297UL   // Retired
#define TAG_PIXEL_COORDINATES_SET_TRIAL                                                           0x0040A29AUL   // Retired
#define TAG_MEASURED_VALUE_SEQUENCE                                                               0x0040A300UL   
#define TAG_NUMERIC_VALUE_QUALIFIER_CODE_SEQUENCE                                                 0x0040A301UL   
#define TAG_CURRENT_OBSERVER_TRIAL                                                                0x0040A307UL   // Retired
#define TAG_NUMERIC_VALUE                                                                         0x0040A30AUL   
#define TAG_REFERENCED_ACCESSION_SEQUENCE_TRIAL                                                   0x0040A313UL   // Retired
#define TAG_REPORT_STATUS_COMMENT_TRIAL                                                           0x0040A33AUL   // Retired
#define TAG_PROCEDURE_CONTEXT_SEQUENCE_TRIAL                                                      0x0040A340UL   // Retired
#define TAG_VERBAL_SOURCE_TRIAL                                                                   0x0040A352UL   // Retired
#define TAG_ADDRESS_TRIAL                                                                         0x0040A353UL   // Retired
#define TAG_TELEPHONE_NUMBER_TRIAL                                                                0x0040A354UL   // Retired
#define TAG_VERBAL_SOURCE_IDENTIFIER_CODE_SEQUENCE_TRIAL                                          0x0040A358UL   // Retired
#define TAG_PREDECESSOR_DOCUMENTS_SEQUENCE                                                        0x0040A360UL   
#define TAG_REFERENCED_REQUEST_SEQUENCE                                                           0x0040A370UL   
#define TAG_PERFORMED_PROCEDURE_CODE_SEQUENCE                                                     0x0040A372UL   
#define TAG_CURRENT_REQUESTED_PROCEDURE_EVIDENCE_SEQUENCE                                         0x0040A375UL   
#define TAG_REPORT_DETAIL_SEQUENCE_TRIAL                                                          0x0040A380UL   // Retired
#define TAG_PERTINENT_OTHER_EVIDENCE_SEQUENCE                                                     0x0040A385UL   
#define TAG_HL7_STRUCTURED_DOCUMENT_REFERENCE_SEQUENCE                                            0x0040A390UL   
#define TAG_OBSERVATION_SUBJECT_UID_TRIAL                                                         0x0040A402UL   // Retired
#define TAG_OBSERVATION_SUBJECT_CLASS_TRIAL                                                       0x0040A403UL   // Retired
#define TAG_OBSERVATION_SUBJECT_TYPE_CODE_SEQUENCE_TRIAL                                          0x0040A404UL   // Retired
#define TAG_COMPLETION_FLAG                                                                       0x0040A491UL   
#define TAG_COMPLETION_FLAG_DESCRIPTION                                                           0x0040A492UL   
#define TAG_VERIFICATION_FLAG                                                                     0x0040A493UL   
#define TAG_ARCHIVE_REQUESTED                                                                     0x0040A494UL   
#define TAG_PRELIMINARY_FLAG                                                                      0x0040A496UL   
#define TAG_CONTENT_TEMPLATE_SEQUENCE                                                             0x0040A504UL   
#define TAG_IDENTICAL_DOCUMENTS_SEQUENCE                                                          0x0040A525UL   
#define TAG_OBSERVATION_SUBJECT_CONTEXT_FLAG_TRIAL                                                0x0040A600UL   // Retired
#define TAG_OBSERVER_CONTEXT_FLAG_TRIAL                                                           0x0040A601UL   // Retired
#define TAG_PROCEDURE_CONTEXT_FLAG_TRIAL                                                          0x0040A603UL   // Retired
#define TAG_CONTENT_SEQUENCE                                                                      0x0040A730UL   
#define TAG_RELATIONSHIP_SEQUENCE_TRIAL                                                           0x0040A731UL   // Retired
#define TAG_RELATIONSHIP_TYPE_CODE_SEQUENCE_TRIAL                                                 0x0040A732UL   // Retired
#define TAG_LANGUAGE_CODE_SEQUENCE_TRIAL                                                          0x0040A744UL   // Retired
#define TAG_TABULATED_VALUES_SEQUENCE                                                             0x0040A801UL   
#define TAG_NUMBER_OF_TABLE_ROWS                                                                  0x0040A802UL   
#define TAG_NUMBER_OF_TABLE_COLUMNS                                                               0x0040A803UL   
#define TAG_TABLE_ROW_NUMBER                                                                      0x0040A804UL   
#define TAG_TABLE_COLUMN_NUMBER                                                                   0x0040A805UL   
#define TAG_TABLE_ROW_DEFINITION_SEQUENCE                                                         0x0040A806UL   
#define TAG_TABLE_COLUMN_DEFINITION_SEQUENCE                                                      0x0040A807UL   
#define TAG_CELL_VALUES_SEQUENCE                                                                  0x0040A808UL   
#define TAG_UNIFORM_RESOURCE_LOCATOR_TRIAL                                                        0x0040A992UL   // Retired
#define TAG_WAVEFORM_ANNOTATION_SEQUENCE                                                          0x0040B020UL   
#define TAG_TEMPLATE_IDENTIFIER                                                                   0x0040DB00UL   
#define TAG_TEMPLATE_VERSION                                                                      0x0040DB06UL   // Retired
#define TAG_TEMPLATE_LOCAL_VERSION                                                                0x0040DB07UL   // Retired
#define TAG_TEMPLATE_EXTENSION_FLAG                                                               0x0040DB0BUL   // Retired
#define TAG_TEMPLATE_EXTENSION_ORGANIZATION_UID                                                   0x0040DB0CUL   // Retired
#define TAG_TEMPLATE_EXTENSION_CREATOR_UID                                                        0x0040DB0DUL   // Retired
#define TAG_REFERENCED_CONTENT_ITEM_IDENTIFIER                                                    0x0040DB73UL   
#define TAG_HL7_INSTANCE_IDENTIFIER                                                               0x0040E001UL   
#define TAG_HL7_DOCUMENT_EFFECTIVE_TIME                                                           0x0040E004UL   
#define TAG_HL7_DOCUMENT_TYPE_CODE_SEQUENCE                                                       0x0040E006UL   
#define TAG_DOCUMENT_CLASS_CODE_SEQUENCE                                                          0x0040E008UL   
#define TAG_RETRIEVE_URI                                                                          0x0040E010UL   
#define TAG_RETRIEVE_LOCATION_UID                                                                 0x0040E011UL   
#define TAG_TYPE_OF_INSTANCES                                                                     0x0040E020UL   
#define TAG_DICOM_RETRIEVAL_SEQUENCE                                                              0x0040E021UL   
#define TAG_DICOM_MEDIA_RETRIEVAL_SEQUENCE                                                        0x0040E022UL   
#define TAG_WADO_RETRIEVAL_SEQUENCE                                                               0x0040E023UL   
#define TAG_XDS_RETRIEVAL_SEQUENCE                                                                0x0040E024UL   
#define TAG_WADO_RS_RETRIEVAL_SEQUENCE                                                            0x0040E025UL   
#define TAG_REPOSITORY_UNIQUE_ID                                                                  0x0040E030UL   
#define TAG_HOME_COMMUNITY_ID                                                                     0x0040E031UL   

// *****************************************************************************************************************************
// *** 0042
// *****************************************************************************************************************************
#define TAG_DOCUMENT_TITLE                                                                        0x00420010UL   
#define TAG_ENCAPSULATED_DOCUMENT                                                                 0x00420011UL   
#define TAG_MIME_TYPE_OF_ENCAPSULATED_DOCUMENT                                                    0x00420012UL   
#define TAG_SOURCE_INSTANCE_SEQUENCE                                                              0x00420013UL   
#define TAG_LIST_OF_MIME_TYPES                                                                    0x00420014UL   
#define TAG_ENCAPSULATED_DOCUMENT_LENGTH                                                          0x00420015UL   

// *****************************************************************************************************************************
// *** 0044
// *****************************************************************************************************************************
#define TAG_PRODUCT_PACKAGE_IDENTIFIER                                                            0x00440001UL   
#define TAG_SUBSTANCE_ADMINISTRATION_APPROVAL                                                     0x00440002UL   
#define TAG_APPROVAL_STATUS_FURTHER_DESCRIPTION                                                   0x00440003UL   
#define TAG_APPROVAL_STATUS_DATETIME                                                              0x00440004UL   
#define TAG_PRODUCT_TYPE_CODE_SEQUENCE                                                            0x00440007UL   
#define TAG_PRODUCT_NAME                                                                          0x00440008UL   
#define TAG_PRODUCT_DESCRIPTION                                                                   0x00440009UL   
#define TAG_PRODUCT_LOT_IDENTIFIER                                                                0x0044000AUL   
#define TAG_PRODUCT_EXPIRATION_DATETIME                                                           0x0044000BUL   
#define TAG_SUBSTANCE_ADMINISTRATION_DATETIME                                                     0x00440010UL   
#define TAG_SUBSTANCE_ADMINISTRATION_NOTES                                                        0x00440011UL   
#define TAG_SUBSTANCE_ADMINISTRATION_DEVICE_ID                                                    0x00440012UL   
#define TAG_PRODUCT_PARAMETER_SEQUENCE                                                            0x00440013UL   
#define TAG_SUBSTANCE_ADMINISTRATION_PARAMETER_SEQUENCE                                           0x00440019UL   
#define TAG_APPROVAL_SEQUENCE                                                                     0x00440100UL   
#define TAG_ASSERTION_CODE_SEQUENCE                                                               0x00440101UL   
#define TAG_ASSERTION_UID                                                                         0x00440102UL   
#define TAG_ASSERTER_IDENTIFICATION_SEQUENCE                                                      0x00440103UL   
#define TAG_ASSERTION_DATETIME                                                                    0x00440104UL   
#define TAG_ASSERTION_EXPIRATION_DATETIME                                                         0x00440105UL   
#define TAG_ASSERTION_COMMENTS                                                                    0x00440106UL   
#define TAG_RELATED_ASSERTION_SEQUENCE                                                            0x00440107UL   
#define TAG_REFERENCED_ASSERTION_UID                                                              0x00440108UL   
#define TAG_APPROVAL_SUBJECT_SEQUENCE                                                             0x00440109UL   
#define TAG_ORGANIZATIONAL_ROLE_CODE_SEQUENCE                                                     0x0044010AUL   

// *****************************************************************************************************************************
// *** 0046
// *****************************************************************************************************************************
#define TAG_LENS_DESCRIPTION                                                                      0x00460012UL   
#define TAG_RIGHT_LENS_SEQUENCE                                                                   0x00460014UL   
#define TAG_LEFT_LENS_SEQUENCE                                                                    0x00460015UL   
#define TAG_UNSPECIFIED_LATERALITY_LENS_SEQUENCE                                                  0x00460016UL   
#define TAG_CYLINDER_SEQUENCE                                                                     0x00460018UL   
#define TAG_PRISM_SEQUENCE                                                                        0x00460028UL   
#define TAG_HORIZONTAL_PRISM_POWER                                                                0x00460030UL   
#define TAG_HORIZONTAL_PRISM_BASE                                                                 0x00460032UL   
#define TAG_VERTICAL_PRISM_POWER                                                                  0x00460034UL   
#define TAG_VERTICAL_PRISM_BASE                                                                   0x00460036UL   
#define TAG_LENS_SEGMENT_TYPE                                                                     0x00460038UL   
#define TAG_OPTICAL_TRANSMITTANCE                                                                 0x00460040UL   
#define TAG_CHANNEL_WIDTH                                                                         0x00460042UL   
#define TAG_PUPIL_SIZE                                                                            0x00460044UL   
#define TAG_CORNEAL_SIZE                                                                          0x00460046UL   
#define TAG_CORNEAL_SIZE_SEQUENCE                                                                 0x00460047UL   
#define TAG_AUTOREFRACTION_RIGHT_EYE_SEQUENCE                                                     0x00460050UL   
#define TAG_AUTOREFRACTION_LEFT_EYE_SEQUENCE                                                      0x00460052UL   
#define TAG_DISTANCE_PUPILLARY_DISTANCE                                                           0x00460060UL   
#define TAG_NEAR_PUPILLARY_DISTANCE                                                               0x00460062UL   
#define TAG_INTERMEDIATE_PUPILLARY_DISTANCE                                                       0x00460063UL   
#define TAG_OTHER_PUPILLARY_DISTANCE                                                              0x00460064UL   
#define TAG_KERATOMETRY_RIGHT_EYE_SEQUENCE                                                        0x00460070UL   
#define TAG_KERATOMETRY_LEFT_EYE_SEQUENCE                                                         0x00460071UL   
#define TAG_STEEP_KERATOMETRIC_AXIS_SEQUENCE                                                      0x00460074UL   
#define TAG_RADIUS_OF_CURVATURE                                                                   0x00460075UL   
#define TAG_KERATOMETRIC_POWER                                                                    0x00460076UL   
#define TAG_KERATOMETRIC_AXIS                                                                     0x00460077UL   
#define TAG_FLAT_KERATOMETRIC_AXIS_SEQUENCE                                                       0x00460080UL   
#define TAG_BACKGROUND_COLOR                                                                      0x00460092UL   
#define TAG_OPTOTYPE                                                                              0x00460094UL   
#define TAG_OPTOTYPE_PRESENTATION                                                                 0x00460095UL   
#define TAG_SUBJECTIVE_REFRACTION_RIGHT_EYE_SEQUENCE                                              0x00460097UL   
#define TAG_SUBJECTIVE_REFRACTION_LEFT_EYE_SEQUENCE                                               0x00460098UL   
#define TAG_ADD_NEAR_SEQUENCE                                                                     0x00460100UL   
#define TAG_ADD_INTERMEDIATE_SEQUENCE                                                             0x00460101UL   
#define TAG_ADD_OTHER_SEQUENCE                                                                    0x00460102UL   
#define TAG_ADD_POWER                                                                             0x00460104UL   
#define TAG_VIEWING_DISTANCE                                                                      0x00460106UL   
#define TAG_CORNEA_MEASUREMENTS_SEQUENCE                                                          0x00460110UL   
#define TAG_SOURCE_OF_CORNEA_MEASUREMENT_DATA_CODE_SEQUENCE                                       0x00460111UL   
#define TAG_STEEP_CORNEAL_AXIS_SEQUENCE                                                           0x00460112UL   
#define TAG_FLAT_CORNEAL_AXIS_SEQUENCE                                                            0x00460113UL   
#define TAG_CORNEAL_POWER                                                                         0x00460114UL   
#define TAG_CORNEAL_AXIS                                                                          0x00460115UL   
#define TAG_CORNEA_MEASUREMENT_METHOD_CODE_SEQUENCE                                               0x00460116UL   
#define TAG_REFRACTIVE_INDEX_OF_CORNEA                                                            0x00460117UL   
#define TAG_REFRACTIVE_INDEX_OF_AQUEOUS_HUMOR                                                     0x00460118UL   
#define TAG_VISUAL_ACUITY_TYPE_CODE_SEQUENCE                                                      0x00460121UL   
#define TAG_VISUAL_ACUITY_RIGHT_EYE_SEQUENCE                                                      0x00460122UL   
#define TAG_VISUAL_ACUITY_LEFT_EYE_SEQUENCE                                                       0x00460123UL   
#define TAG_VISUAL_ACUITY_BOTH_EYES_OPEN_SEQUENCE                                                 0x00460124UL   
#define TAG_VIEWING_DISTANCE_TYPE                                                                 0x00460125UL   
#define TAG_VISUAL_ACUITY_MODIFIERS                                                               0x00460135UL   
#define TAG_DECIMAL_VISUAL_ACUITY                                                                 0x00460137UL   
#define TAG_OPTOTYPE_DETAILED_DEFINITION                                                          0x00460139UL   
#define TAG_REFERENCED_REFRACTIVE_MEASUREMENTS_SEQUENCE                                           0x00460145UL   
#define TAG_SPHERE_POWER                                                                          0x00460146UL   
#define TAG_CYLINDER_POWER                                                                        0x00460147UL   
#define TAG_CORNEAL_TOPOGRAPHY_SURFACE                                                            0x00460201UL   
#define TAG_CORNEAL_VERTEX_LOCATION                                                               0x00460202UL   
#define TAG_PUPIL_CENTROID_X_COORDINATE                                                           0x00460203UL   
#define TAG_PUPIL_CENTROID_Y_COORDINATE                                                           0x00460204UL   
#define TAG_EQUIVALENT_PUPIL_RADIUS                                                               0x00460205UL   
#define TAG_CORNEAL_TOPOGRAPHY_MAP_TYPE_CODE_SEQUENCE                                             0x00460207UL   
#define TAG_VERTICES_OF_THE_OUTLINE_OF_PUPIL                                                      0x00460208UL   
#define TAG_CORNEAL_TOPOGRAPHY_MAPPING_NORMALS_SEQUENCE                                           0x00460210UL   
#define TAG_MAXIMUM_CORNEAL_CURVATURE_SEQUENCE                                                    0x00460211UL   
#define TAG_MAXIMUM_CORNEAL_CURVATURE                                                             0x00460212UL   
#define TAG_MAXIMUM_CORNEAL_CURVATURE_LOCATION                                                    0x00460213UL   
#define TAG_MINIMUM_KERATOMETRIC_SEQUENCE                                                         0x00460215UL   
#define TAG_SIMULATED_KERATOMETRIC_CYLINDER_SEQUENCE                                              0x00460218UL   
#define TAG_AVERAGE_CORNEAL_POWER                                                                 0x00460220UL   
#define TAG_CORNEAL_I_S_VALUE                                                                     0x00460224UL   
#define TAG_ANALYZED_AREA                                                                         0x00460227UL   
#define TAG_SURFACE_REGULARITY_INDEX                                                              0x00460230UL   
#define TAG_SURFACE_ASYMMETRY_INDEX                                                               0x00460232UL   
#define TAG_CORNEAL_ECCENTRICITY_INDEX                                                            0x00460234UL   
#define TAG_KERATOCONUS_PREDICTION_INDEX                                                          0x00460236UL   
#define TAG_DECIMAL_POTENTIAL_VISUAL_ACUITY                                                       0x00460238UL   
#define TAG_CORNEAL_TOPOGRAPHY_MAP_QUALITY_EVALUATION                                             0x00460242UL   
#define TAG_SOURCE_IMAGE_CORNEAL_PROCESSED_DATA_SEQUENCE                                          0x00460244UL   
#define TAG_CORNEAL_POINT_LOCATION                                                                0x00460247UL   
#define TAG_CORNEAL_POINT_ESTIMATED                                                               0x00460248UL   
#define TAG_AXIAL_POWER                                                                           0x00460249UL   
#define TAG_TANGENTIAL_POWER                                                                      0x00460250UL   
#define TAG_REFRACTIVE_POWER                                                                      0x00460251UL   
#define TAG_RELATIVE_ELEVATION                                                                    0x00460252UL   
#define TAG_CORNEAL_WAVEFRONT                                                                     0x00460253UL   

// *****************************************************************************************************************************
// *** 0048
// *****************************************************************************************************************************
#define TAG_IMAGED_VOLUME_WIDTH                                                                   0x00480001UL   
#define TAG_IMAGED_VOLUME_HEIGHT                                                                  0x00480002UL   
#define TAG_IMAGED_VOLUME_DEPTH                                                                   0x00480003UL   
#define TAG_TOTAL_PIXEL_MATRIX_COLUMNS                                                            0x00480006UL   
#define TAG_TOTAL_PIXEL_MATRIX_ROWS                                                               0x00480007UL   
#define TAG_TOTAL_PIXEL_MATRIX_ORIGIN_SEQUENCE                                                    0x00480008UL   
#define TAG_SPECIMEN_LABEL_IN_IMAGE                                                               0x00480010UL   
#define TAG_FOCUS_METHOD                                                                          0x00480011UL   
#define TAG_EXTENDED_DEPTH_OF_FIELD                                                               0x00480012UL   
#define TAG_NUMBER_OF_FOCAL_PLANES                                                                0x00480013UL   
#define TAG_DISTANCE_BETWEEN_FOCAL_PLANES                                                         0x00480014UL   
#define TAG_RECOMMENDED_ABSENT_PIXEL_CIELAB_VALUE                                                 0x00480015UL   
#define TAG_ILLUMINATOR_TYPE_CODE_SEQUENCE                                                        0x00480100UL   
#define TAG_IMAGE_ORIENTATION_SLIDE                                                               0x00480102UL   
#define TAG_OPTICAL_PATH_SEQUENCE                                                                 0x00480105UL   
#define TAG_OPTICAL_PATH_IDENTIFIER                                                               0x00480106UL   
#define TAG_OPTICAL_PATH_DESCRIPTION                                                              0x00480107UL   
#define TAG_ILLUMINATION_COLOR_CODE_SEQUENCE                                                      0x00480108UL   
#define TAG_SPECIMEN_REFERENCE_SEQUENCE                                                           0x00480110UL   
#define TAG_CONDENSER_LENS_POWER                                                                  0x00480111UL   
#define TAG_OBJECTIVE_LENS_POWER                                                                  0x00480112UL   
#define TAG_OBJECTIVE_LENS_NUMERICAL_APERTURE                                                     0x00480113UL   
#define TAG_PALETTE_COLOR_LOOKUP_TABLE_SEQUENCE                                                   0x00480120UL   
#define TAG_REFERENCED_IMAGE_NAVIGATION_SEQUENCE                                                  0x00480200UL   
#define TAG_TOP_LEFT_HAND_CORNER_OF_LOCALIZER_AREA                                                0x00480201UL   
#define TAG_BOTTOM_RIGHT_HAND_CORNER_OF_LOCALIZER_AREA                                            0x00480202UL   
#define TAG_OPTICAL_PATH_IDENTIFICATION_SEQUENCE                                                  0x00480207UL   
#define TAG_PLANE_POSITION_SLIDE_SEQUENCE                                                         0x0048021AUL   
#define TAG_COLUMN_POSITION_IN_TOTAL_IMAGE_PIXEL_MATRIX                                           0x0048021EUL   
#define TAG_ROW_POSITION_IN_TOTAL_IMAGE_PIXEL_MATRIX                                              0x0048021FUL   
#define TAG_PIXEL_ORIGIN_INTERPRETATION                                                           0x00480301UL   
#define TAG_NUMBER_OF_OPTICAL_PATHS                                                               0x00480302UL   
#define TAG_TOTAL_PIXEL_MATRIX_FOCAL_PLANES                                                       0x00480303UL   

// *****************************************************************************************************************************
// *** 0050
// *****************************************************************************************************************************
#define TAG_CALIBRATION_IMAGE                                                                     0x00500004UL   
#define TAG_DEVICE_SEQUENCE                                                                       0x00500010UL   
#define TAG_CONTAINER_COMPONENT_TYPE_CODE_SEQUENCE                                                0x00500012UL   
#define TAG_CONTAINER_COMPONENT_THICKNESS                                                         0x00500013UL   
#define TAG_DEVICE_LENGTH                                                                         0x00500014UL   
#define TAG_CONTAINER_COMPONENT_WIDTH                                                             0x00500015UL   
#define TAG_DEVICE_DIAMETER                                                                       0x00500016UL   
#define TAG_DEVICE_DIAMETER_UNITS                                                                 0x00500017UL   
#define TAG_DEVICE_VOLUME                                                                         0x00500018UL   
#define TAG_INTER_MARKER_DISTANCE                                                                 0x00500019UL   
#define TAG_CONTAINER_COMPONENT_MATERIAL                                                          0x0050001AUL   
#define TAG_CONTAINER_COMPONENT_ID                                                                0x0050001BUL   
#define TAG_CONTAINER_COMPONENT_LENGTH                                                            0x0050001CUL   
#define TAG_CONTAINER_COMPONENT_DIAMETER                                                          0x0050001DUL   
#define TAG_CONTAINER_COMPONENT_DESCRIPTION                                                       0x0050001EUL   
#define TAG_DEVICE_DESCRIPTION                                                                    0x00500020UL   
#define TAG_LONG_DEVICE_DESCRIPTION                                                               0x00500021UL   

// *****************************************************************************************************************************
// *** 0052
// *****************************************************************************************************************************
#define TAG_CONTRAST_BOLUS_INGREDIENT_PERCENT_BY_VOLUME                                           0x00520001UL   
#define TAG_OCT_FOCAL_DISTANCE                                                                    0x00520002UL   
#define TAG_BEAM_SPOT_SIZE                                                                        0x00520003UL   
#define TAG_EFFECTIVE_REFRACTIVE_INDEX                                                            0x00520004UL   
#define TAG_OCT_ACQUISITION_DOMAIN                                                                0x00520006UL   
#define TAG_OCT_OPTICAL_CENTER_WAVELENGTH                                                         0x00520007UL   
#define TAG_AXIAL_RESOLUTION                                                                      0x00520008UL   
#define TAG_RANGING_DEPTH                                                                         0x00520009UL   
#define TAG_A_LINE_RATE                                                                           0x00520011UL   
#define TAG_A_LINES_PER_FRAME                                                                     0x00520012UL   
#define TAG_CATHETER_ROTATIONAL_RATE                                                              0x00520013UL   
#define TAG_A_LINE_PIXEL_SPACING                                                                  0x00520014UL   
#define TAG_MODE_OF_PERCUTANEOUS_ACCESS_SEQUENCE                                                  0x00520016UL   
#define TAG_INTRAVASCULAR_OCT_FRAME_TYPE_SEQUENCE                                                 0x00520025UL   
#define TAG_OCT_Z_OFFSET_APPLIED                                                                  0x00520026UL   
#define TAG_INTRAVASCULAR_FRAME_CONTENT_SEQUENCE                                                  0x00520027UL   
#define TAG_INTRAVASCULAR_LONGITUDINAL_DISTANCE                                                   0x00520028UL   
#define TAG_INTRAVASCULAR_OCT_FRAME_CONTENT_SEQUENCE                                              0x00520029UL   
#define TAG_OCT_Z_OFFSET_CORRECTION                                                               0x00520030UL   
#define TAG_CATHETER_DIRECTION_OF_ROTATION                                                        0x00520031UL   
#define TAG_SEAM_LINE_LOCATION                                                                    0x00520033UL   
#define TAG_FIRST_A_LINE_LOCATION                                                                 0x00520034UL   
#define TAG_SEAM_LINE_INDEX                                                                       0x00520036UL   
#define TAG_NUMBER_OF_PADDED_A_LINES                                                              0x00520038UL   
#define TAG_INTERPOLATION_TYPE                                                                    0x00520039UL   
#define TAG_REFRACTIVE_INDEX_APPLIED                                                              0x0052003AUL   

// *****************************************************************************************************************************
// *** 0054
// *****************************************************************************************************************************
#define TAG_ENERGY_WINDOW_VECTOR                                                                  0x00540010UL   
#define TAG_NUMBER_OF_ENERGY_WINDOWS                                                              0x00540011UL   
#define TAG_ENERGY_WINDOW_INFORMATION_SEQUENCE                                                    0x00540012UL   
#define TAG_ENERGY_WINDOW_RANGE_SEQUENCE                                                          0x00540013UL   
#define TAG_ENERGY_WINDOW_LOWER_LIMIT                                                             0x00540014UL   
#define TAG_ENERGY_WINDOW_UPPER_LIMIT                                                             0x00540015UL   
#define TAG_RADIOPHARMACEUTICAL_INFORMATION_SEQUENCE                                              0x00540016UL   
#define TAG_RESIDUAL_SYRINGE_COUNTS                                                               0x00540017UL   
#define TAG_ENERGY_WINDOW_NAME                                                                    0x00540018UL   
#define TAG_DETECTOR_VECTOR                                                                       0x00540020UL   
#define TAG_NUMBER_OF_DETECTORS                                                                   0x00540021UL   
#define TAG_DETECTOR_INFORMATION_SEQUENCE                                                         0x00540022UL   
#define TAG_PHASE_VECTOR                                                                          0x00540030UL   
#define TAG_NUMBER_OF_PHASES                                                                      0x00540031UL   
#define TAG_PHASE_INFORMATION_SEQUENCE                                                            0x00540032UL   
#define TAG_NUMBER_OF_FRAMES_IN_PHASE                                                             0x00540033UL   
#define TAG_PHASE_DELAY                                                                           0x00540036UL   
#define TAG_PAUSE_BETWEEN_FRAMES                                                                  0x00540038UL   
#define TAG_PHASE_DESCRIPTION                                                                     0x00540039UL   
#define TAG_ROTATION_VECTOR                                                                       0x00540050UL   
#define TAG_NUMBER_OF_ROTATIONS                                                                   0x00540051UL   
#define TAG_ROTATION_INFORMATION_SEQUENCE                                                         0x00540052UL   
#define TAG_NUMBER_OF_FRAMES_IN_ROTATION                                                          0x00540053UL   
#define TAG_R_R_INTERVAL_VECTOR                                                                   0x00540060UL   
#define TAG_NUMBER_OF_R_R_INTERVALS                                                               0x00540061UL   
#define TAG_GATED_INFORMATION_SEQUENCE                                                            0x00540062UL   
#define TAG_DATA_INFORMATION_SEQUENCE                                                             0x00540063UL   
#define TAG_TIME_SLOT_VECTOR                                                                      0x00540070UL   
#define TAG_NUMBER_OF_TIME_SLOTS                                                                  0x00540071UL   
#define TAG_TIME_SLOT_INFORMATION_SEQUENCE                                                        0x00540072UL   
#define TAG_TIME_SLOT_TIME                                                                        0x00540073UL   
#define TAG_SLICE_VECTOR                                                                          0x00540080UL   
#define TAG_NUMBER_OF_SLICES                                                                      0x00540081UL   
#define TAG_ANGULAR_VIEW_VECTOR                                                                   0x00540090UL   
#define TAG_TIME_SLICE_VECTOR                                                                     0x00540100UL   
#define TAG_NUMBER_OF_TIME_SLICES                                                                 0x00540101UL   
#define TAG_START_ANGLE                                                                           0x00540200UL   
#define TAG_TYPE_OF_DETECTOR_MOTION                                                               0x00540202UL   
#define TAG_TRIGGER_VECTOR                                                                        0x00540210UL   
#define TAG_NUMBER_OF_TRIGGERS_IN_PHASE                                                           0x00540211UL   
#define TAG_VIEW_CODE_SEQUENCE                                                                    0x00540220UL   
#define TAG_VIEW_MODIFIER_CODE_SEQUENCE                                                           0x00540222UL   
#define TAG_RADIONUCLIDE_CODE_SEQUENCE                                                            0x00540300UL   
#define TAG_ADMINISTRATION_ROUTE_CODE_SEQUENCE                                                    0x00540302UL   
#define TAG_RADIOPHARMACEUTICAL_CODE_SEQUENCE                                                     0x00540304UL   
#define TAG_CALIBRATION_DATA_SEQUENCE                                                             0x00540306UL   
#define TAG_ENERGY_WINDOW_NUMBER                                                                  0x00540308UL   
#define TAG_IMAGE_ID                                                                              0x00540400UL   
#define TAG_PATIENT_ORIENTATION_CODE_SEQUENCE                                                     0x00540410UL   
#define TAG_PATIENT_ORIENTATION_MODIFIER_CODE_SEQUENCE                                            0x00540412UL   
#define TAG_PATIENT_GANTRY_RELATIONSHIP_CODE_SEQUENCE                                             0x00540414UL   
#define TAG_SLICE_PROGRESSION_DIRECTION                                                           0x00540500UL   
#define TAG_SCAN_PROGRESSION_DIRECTION                                                            0x00540501UL   
#define TAG_SERIES_TYPE                                                                           0x00541000UL   
#define TAG_UNITS                                                                                 0x00541001UL   
#define TAG_COUNTS_SOURCE                                                                         0x00541002UL   
#define TAG_REPROJECTION_METHOD                                                                   0x00541004UL   
#define TAG_SUV_TYPE                                                                              0x00541006UL   
#define TAG_RANDOMS_CORRECTION_METHOD                                                             0x00541100UL   
#define TAG_ATTENUATION_CORRECTION_METHOD                                                         0x00541101UL   
#define TAG_DECAY_CORRECTION                                                                      0x00541102UL   
#define TAG_RECONSTRUCTION_METHOD                                                                 0x00541103UL   
#define TAG_DETECTOR_LINES_OF_RESPONSE_USED                                                       0x00541104UL   
#define TAG_SCATTER_CORRECTION_METHOD                                                             0x00541105UL   
#define TAG_AXIAL_ACCEPTANCE                                                                      0x00541200UL   
#define TAG_AXIAL_MASH                                                                            0x00541201UL   
#define TAG_TRANSVERSE_MASH                                                                       0x00541202UL   
#define TAG_DETECTOR_ELEMENT_SIZE                                                                 0x00541203UL   
#define TAG_COINCIDENCE_WINDOW_WIDTH                                                              0x00541210UL   
#define TAG_SECONDARY_COUNTS_TYPE                                                                 0x00541220UL   
#define TAG_FRAME_REFERENCE_TIME                                                                  0x00541300UL   
#define TAG_PRIMARY_PROMPTS_COUNTS_ACCUMULATED                                                    0x00541310UL   
#define TAG_SECONDARY_COUNTS_ACCUMULATED                                                          0x00541311UL   
#define TAG_SLICE_SENSITIVITY_FACTOR                                                              0x00541320UL   
#define TAG_DECAY_FACTOR                                                                          0x00541321UL   
#define TAG_DOSE_CALIBRATION_FACTOR                                                               0x00541322UL   
#define TAG_SCATTER_FRACTION_FACTOR                                                               0x00541323UL   
#define TAG_DEAD_TIME_FACTOR                                                                      0x00541324UL   
#define TAG_IMAGE_INDEX                                                                           0x00541330UL   
#define TAG_COUNTS_INCLUDED                                                                       0x00541400UL   // Retired
#define TAG_DEAD_TIME_CORRECTION_FLAG                                                             0x00541401UL   // Retired

// *****************************************************************************************************************************
// *** 0060
// *****************************************************************************************************************************
#define TAG_HISTOGRAM_SEQUENCE                                                                    0x00603000UL   
#define TAG_HISTOGRAM_NUMBER_OF_BINS                                                              0x00603002UL   
#define TAG_HISTOGRAM_FIRST_BIN_VALUE                                                             0x00603004UL   
#define TAG_HISTOGRAM_LAST_BIN_VALUE                                                              0x00603006UL   
#define TAG_HISTOGRAM_BIN_WIDTH                                                                   0x00603008UL   
#define TAG_HISTOGRAM_EXPLANATION                                                                 0x00603010UL   
#define TAG_HISTOGRAM_DATA                                                                        0x00603020UL   

// *****************************************************************************************************************************
// *** 0062
// *****************************************************************************************************************************
#define TAG_SEGMENTATION_TYPE                                                                     0x00620001UL   
#define TAG_SEGMENT_SEQUENCE                                                                      0x00620002UL   
#define TAG_SEGMENTED_PROPERTY_CATEGORY_CODE_SEQUENCE                                             0x00620003UL   
#define TAG_SEGMENT_NUMBER                                                                        0x00620004UL   
#define TAG_SEGMENT_LABEL                                                                         0x00620005UL   
#define TAG_SEGMENT_DESCRIPTION                                                                   0x00620006UL   
#define TAG_SEGMENTATION_ALGORITHM_IDENTIFICATION_SEQUENCE                                        0x00620007UL   
#define TAG_SEGMENT_ALGORITHM_TYPE                                                                0x00620008UL   
#define TAG_SEGMENT_ALGORITHM_NAME                                                                0x00620009UL   
#define TAG_SEGMENT_IDENTIFICATION_SEQUENCE                                                       0x0062000AUL   
#define TAG_REFERENCED_SEGMENT_NUMBER                                                             0x0062000BUL   
#define TAG_RECOMMENDED_DISPLAY_GRAYSCALE_VALUE                                                   0x0062000CUL   
#define TAG_RECOMMENDED_DISPLAY_CIELAB_VALUE                                                      0x0062000DUL   
#define TAG_MAXIMUM_FRACTIONAL_VALUE                                                              0x0062000EUL   
#define TAG_SEGMENTED_PROPERTY_TYPE_CODE_SEQUENCE                                                 0x0062000FUL   
#define TAG_SEGMENTATION_FRACTIONAL_TYPE                                                          0x00620010UL   
#define TAG_SEGMENTED_PROPERTY_TYPE_MODIFIER_CODE_SEQUENCE                                        0x00620011UL   
#define TAG_USED_SEGMENTS_SEQUENCE                                                                0x00620012UL   
#define TAG_SEGMENTS_OVERLAP                                                                      0x00620013UL   
#define TAG_TRACKING_ID                                                                           0x00620020UL   
#define TAG_TRACKING_UID                                                                          0x00620021UL   

// *****************************************************************************************************************************
// *** 0064
// *****************************************************************************************************************************
#define TAG_DEFORMABLE_REGISTRATION_SEQUENCE                                                      0x00640002UL   
#define TAG_SOURCE_FRAME_OF_REFERENCE_UID                                                         0x00640003UL   
#define TAG_DEFORMABLE_REGISTRATION_GRID_SEQUENCE                                                 0x00640005UL   
#define TAG_GRID_DIMENSIONS                                                                       0x00640007UL   
#define TAG_GRID_RESOLUTION                                                                       0x00640008UL   
#define TAG_VECTOR_GRID_DATA                                                                      0x00640009UL   
#define TAG_PRE_DEFORMATION_MATRIX_REGISTRATION_SEQUENCE                                          0x0064000FUL   
#define TAG_POST_DEFORMATION_MATRIX_REGISTRATION_SEQUENCE                                         0x00640010UL   

// *****************************************************************************************************************************
// *** 0066
// *****************************************************************************************************************************
#define TAG_NUMBER_OF_SURFACES                                                                    0x00660001UL   
#define TAG_SURFACE_SEQUENCE                                                                      0x00660002UL   
#define TAG_SURFACE_NUMBER                                                                        0x00660003UL   
#define TAG_SURFACE_COMMENTS                                                                      0x00660004UL   
#define TAG_SURFACE_PROCESSING                                                                    0x00660009UL   
#define TAG_SURFACE_PROCESSING_RATIO                                                              0x0066000AUL   
#define TAG_SURFACE_PROCESSING_DESCRIPTION                                                        0x0066000BUL   
#define TAG_RECOMMENDED_PRESENTATION_OPACITY                                                      0x0066000CUL   
#define TAG_RECOMMENDED_PRESENTATION_TYPE                                                         0x0066000DUL   
#define TAG_FINITE_VOLUME                                                                         0x0066000EUL   
#define TAG_MANIFOLD                                                                              0x00660010UL   
#define TAG_SURFACE_POINTS_SEQUENCE                                                               0x00660011UL   
#define TAG_SURFACE_POINTS_NORMALS_SEQUENCE                                                       0x00660012UL   
#define TAG_SURFACE_MESH_PRIMITIVES_SEQUENCE                                                      0x00660013UL   
#define TAG_NUMBER_OF_SURFACE_POINTS                                                              0x00660015UL   
#define TAG_POINT_COORDINATES_DATA                                                                0x00660016UL   
#define TAG_POINT_POSITION_ACCURACY                                                               0x00660017UL   
#define TAG_MEAN_POINT_DISTANCE                                                                   0x00660018UL   
#define TAG_MAXIMUM_POINT_DISTANCE                                                                0x00660019UL   
#define TAG_POINTS_BOUNDING_BOX_COORDINATES                                                       0x0066001AUL   
#define TAG_AXIS_OF_ROTATION                                                                      0x0066001BUL   
#define TAG_CENTER_OF_ROTATION                                                                    0x0066001CUL   
#define TAG_NUMBER_OF_VECTORS                                                                     0x0066001EUL   
#define TAG_VECTOR_DIMENSIONALITY                                                                 0x0066001FUL   
#define TAG_VECTOR_ACCURACY                                                                       0x00660020UL   
#define TAG_VECTOR_COORDINATE_DATA                                                                0x00660021UL   
#define TAG_TRIANGLE_POINT_INDEX_LIST                                                             0x00660023UL   // Retired
#define TAG_EDGE_POINT_INDEX_LIST                                                                 0x00660024UL   // Retired
#define TAG_VERTEX_POINT_INDEX_LIST                                                               0x00660025UL   // Retired
#define TAG_TRIANGLE_STRIP_SEQUENCE                                                               0x00660026UL   
#define TAG_TRIANGLE_FAN_SEQUENCE                                                                 0x00660027UL   
#define TAG_LINE_SEQUENCE                                                                         0x00660028UL   
#define TAG_PRIMITIVE_POINT_INDEX_LIST                                                            0x00660029UL   // Retired
#define TAG_SURFACE_COUNT                                                                         0x0066002AUL   
#define TAG_REFERENCED_SURFACE_SEQUENCE                                                           0x0066002BUL   
#define TAG_REFERENCED_SURFACE_NUMBER                                                             0x0066002CUL   
#define TAG_SEGMENT_SURFACE_GENERATION_ALGORITHM_IDENTIFICATION_SEQUENCE                          0x0066002DUL   
#define TAG_SEGMENT_SURFACE_SOURCE_INSTANCE_SEQUENCE                                              0x0066002EUL   
#define TAG_ALGORITHM_FAMILY_CODE_SEQUENCE                                                        0x0066002FUL   
#define TAG_ALGORITHM_NAME_CODE_SEQUENCE                                                          0x00660030UL   
#define TAG_ALGORITHM_VERSION                                                                     0x00660031UL   
#define TAG_ALGORITHM_PARAMETERS                                                                  0x00660032UL   
#define TAG_FACET_SEQUENCE                                                                        0x00660034UL   
#define TAG_SURFACE_PROCESSING_ALGORITHM_IDENTIFICATION_SEQUENCE                                  0x00660035UL   
#define TAG_ALGORITHM_NAME                                                                        0x00660036UL   
#define TAG_RECOMMENDED_POINT_RADIUS                                                              0x00660037UL   
#define TAG_RECOMMENDED_LINE_THICKNESS                                                            0x00660038UL   
#define TAG_LONG_PRIMITIVE_POINT_INDEX_LIST                                                       0x00660040UL   
#define TAG_LONG_TRIANGLE_POINT_INDEX_LIST                                                        0x00660041UL   
#define TAG_LONG_EDGE_POINT_INDEX_LIST                                                            0x00660042UL   
#define TAG_LONG_VERTEX_POINT_INDEX_LIST                                                          0x00660043UL   
#define TAG_TRACK_SET_SEQUENCE                                                                    0x00660101UL   
#define TAG_TRACK_SEQUENCE                                                                        0x00660102UL   
#define TAG_RECOMMENDED_DISPLAY_CIELAB_VALUE_LIST                                                 0x00660103UL   
#define TAG_TRACKING_ALGORITHM_IDENTIFICATION_SEQUENCE                                            0x00660104UL   
#define TAG_TRACK_SET_NUMBER                                                                      0x00660105UL   
#define TAG_TRACK_SET_LABEL                                                                       0x00660106UL   
#define TAG_TRACK_SET_DESCRIPTION                                                                 0x00660107UL   
#define TAG_TRACK_SET_ANATOMICAL_TYPE_CODE_SEQUENCE                                               0x00660108UL   
#define TAG_MEASUREMENTS_SEQUENCE                                                                 0x00660121UL   
#define TAG_TRACK_SET_STATISTICS_SEQUENCE                                                         0x00660124UL   
#define TAG_FLOATING_POINT_VALUES                                                                 0x00660125UL   
#define TAG_TRACK_POINT_INDEX_LIST                                                                0x00660129UL   
#define TAG_TRACK_STATISTICS_SEQUENCE                                                             0x00660130UL   
#define TAG_MEASUREMENT_VALUES_SEQUENCE                                                           0x00660132UL   
#define TAG_DIFFUSION_ACQUISITION_CODE_SEQUENCE                                                   0x00660133UL   
#define TAG_DIFFUSION_MODEL_CODE_SEQUENCE                                                         0x00660134UL   

// *****************************************************************************************************************************
// *** 0068
// *****************************************************************************************************************************
#define TAG_IMPLANT_SIZE                                                                          0x00686210UL   
#define TAG_IMPLANT_TEMPLATE_VERSION                                                              0x00686221UL   
#define TAG_REPLACED_IMPLANT_TEMPLATE_SEQUENCE                                                    0x00686222UL   
#define TAG_IMPLANT_TYPE                                                                          0x00686223UL   
#define TAG_DERIVATION_IMPLANT_TEMPLATE_SEQUENCE                                                  0x00686224UL   
#define TAG_ORIGINAL_IMPLANT_TEMPLATE_SEQUENCE                                                    0x00686225UL   
#define TAG_EFFECTIVE_DATETIME                                                                    0x00686226UL   
#define TAG_IMPLANT_TARGET_ANATOMY_SEQUENCE                                                       0x00686230UL   
#define TAG_INFORMATION_FROM_MANUFACTURER_SEQUENCE                                                0x00686260UL   
#define TAG_NOTIFICATION_FROM_MANUFACTURER_SEQUENCE                                               0x00686265UL   
#define TAG_INFORMATION_ISSUE_DATETIME                                                            0x00686270UL   
#define TAG_INFORMATION_SUMMARY                                                                   0x00686280UL   
#define TAG_IMPLANT_REGULATORY_DISAPPROVAL_CODE_SEQUENCE                                          0x006862A0UL   
#define TAG_OVERALL_TEMPLATE_SPATIAL_TOLERANCE                                                    0x006862A5UL   
#define TAG_HPGL_DOCUMENT_SEQUENCE                                                                0x006862C0UL   
#define TAG_HPGL_DOCUMENT_ID                                                                      0x006862D0UL   
#define TAG_HPGL_DOCUMENT_LABEL                                                                   0x006862D5UL   
#define TAG_VIEW_ORIENTATION_CODE_SEQUENCE                                                        0x006862E0UL   
#define TAG_VIEW_ORIENTATION_MODIFIER_CODE_SEQUENCE                                               0x006862F0UL   
#define TAG_HPGL_DOCUMENT_SCALING                                                                 0x006862F2UL   
#define TAG_HPGL_DOCUMENT                                                                         0x00686300UL   
#define TAG_HPGL_CONTOUR_PEN_NUMBER                                                               0x00686310UL   
#define TAG_HPGL_PEN_SEQUENCE                                                                     0x00686320UL   
#define TAG_HPGL_PEN_NUMBER                                                                       0x00686330UL   
#define TAG_HPGL_PEN_LABEL                                                                        0x00686340UL   
#define TAG_HPGL_PEN_DESCRIPTION                                                                  0x00686345UL   
#define TAG_RECOMMENDED_ROTATION_POINT                                                            0x00686346UL   
#define TAG_BOUNDING_RECTANGLE                                                                    0x00686347UL   
#define TAG_IMPLANT_TEMPLATE_3D_MODEL_SURFACE_NUMBER                                              0x00686350UL   
#define TAG_SURFACE_MODEL_DESCRIPTION_SEQUENCE                                                    0x00686360UL   
#define TAG_SURFACE_MODEL_LABEL                                                                   0x00686380UL   
#define TAG_SURFACE_MODEL_SCALING_FACTOR                                                          0x00686390UL   
#define TAG_MATERIALS_CODE_SEQUENCE                                                               0x006863A0UL   
#define TAG_COATING_MATERIALS_CODE_SEQUENCE                                                       0x006863A4UL   
#define TAG_IMPLANT_TYPE_CODE_SEQUENCE                                                            0x006863A8UL   
#define TAG_FIXATION_METHOD_CODE_SEQUENCE                                                         0x006863ACUL   
#define TAG_MATING_FEATURE_SETS_SEQUENCE                                                          0x006863B0UL   
#define TAG_MATING_FEATURE_SET_ID                                                                 0x006863C0UL   
#define TAG_MATING_FEATURE_SET_LABEL                                                              0x006863D0UL   
#define TAG_MATING_FEATURE_SEQUENCE                                                               0x006863E0UL   
#define TAG_MATING_FEATURE_ID                                                                     0x006863F0UL   
#define TAG_MATING_FEATURE_DEGREE_OF_FREEDOM_SEQUENCE                                             0x00686400UL   
#define TAG_DEGREE_OF_FREEDOM_ID                                                                  0x00686410UL   
#define TAG_DEGREE_OF_FREEDOM_TYPE                                                                0x00686420UL   
#define TAG_2D_MATING_FEATURE_COORDINATES_SEQUENCE                                                0x00686430UL   
#define TAG_REFERENCED_HPGL_DOCUMENT_ID                                                           0x00686440UL   
#define TAG_2D_MATING_POINT                                                                       0x00686450UL   
#define TAG_2D_MATING_AXES                                                                        0x00686460UL   
#define TAG_2D_DEGREE_OF_FREEDOM_SEQUENCE                                                         0x00686470UL   
#define TAG_3D_DEGREE_OF_FREEDOM_AXIS                                                             0x00686490UL   
#define TAG_RANGE_OF_FREEDOM                                                                      0x006864A0UL   
#define TAG_3D_MATING_POINT                                                                       0x006864C0UL   
#define TAG_3D_MATING_AXES                                                                        0x006864D0UL   
#define TAG_2D_DEGREE_OF_FREEDOM_AXIS                                                             0x006864F0UL   
#define TAG_PLANNING_LANDMARK_POINT_SEQUENCE                                                      0x00686500UL   
#define TAG_PLANNING_LANDMARK_LINE_SEQUENCE                                                       0x00686510UL   
#define TAG_PLANNING_LANDMARK_PLANE_SEQUENCE                                                      0x00686520UL   
#define TAG_PLANNING_LANDMARK_ID                                                                  0x00686530UL   
#define TAG_PLANNING_LANDMARK_DESCRIPTION                                                         0x00686540UL   
#define TAG_PLANNING_LANDMARK_IDENTIFICATION_CODE_SEQUENCE                                        0x00686545UL   
#define TAG_2D_POINT_COORDINATES_SEQUENCE                                                         0x00686550UL   
#define TAG_2D_POINT_COORDINATES                                                                  0x00686560UL   
#define TAG_3D_POINT_COORDINATES                                                                  0x00686590UL   
#define TAG_2D_LINE_COORDINATES_SEQUENCE                                                          0x006865A0UL   
#define TAG_2D_LINE_COORDINATES                                                                   0x006865B0UL   
#define TAG_3D_LINE_COORDINATES                                                                   0x006865D0UL   
#define TAG_2D_PLANE_COORDINATES_SEQUENCE                                                         0x006865E0UL   
#define TAG_2D_PLANE_INTERSECTION                                                                 0x006865F0UL   
#define TAG_3D_PLANE_ORIGIN                                                                       0x00686610UL   
#define TAG_3D_PLANE_NORMAL                                                                       0x00686620UL   
#define TAG_MODEL_MODIFICATION                                                                    0x00687001UL   
#define TAG_MODEL_MIRRORING                                                                       0x00687002UL   
#define TAG_MODEL_USAGE_CODE_SEQUENCE                                                             0x00687003UL   
#define TAG_MODEL_GROUP_UID                                                                       0x00687004UL   
#define TAG_RELATIVE_URI_REFERENCE_WITHIN_ENCAPSULATED_DOCUMENT                                   0x00687005UL   

// *****************************************************************************************************************************
// *** 0070
// *****************************************************************************************************************************
#define TAG_GRAPHIC_ANNOTATION_SEQUENCE                                                           0x00700001UL   
#define TAG_GRAPHIC_LAYER                                                                         0x00700002UL   
#define TAG_BOUNDING_BOX_ANNOTATION_UNITS                                                         0x00700003UL   
#define TAG_ANCHOR_POINT_ANNOTATION_UNITS                                                         0x00700004UL   
#define TAG_GRAPHIC_ANNOTATION_UNITS                                                              0x00700005UL   
#define TAG_UNFORMATTED_TEXT_VALUE                                                                0x00700006UL   
#define TAG_TEXT_OBJECT_SEQUENCE                                                                  0x00700008UL   
#define TAG_GRAPHIC_OBJECT_SEQUENCE                                                               0x00700009UL   
#define TAG_BOUNDING_BOX_TOP_LEFT_HAND_CORNER                                                     0x00700010UL   
#define TAG_BOUNDING_BOX_BOTTOM_RIGHT_HAND_CORNER                                                 0x00700011UL   
#define TAG_BOUNDING_BOX_TEXT_HORIZONTAL_JUSTIFICATION                                            0x00700012UL   
#define TAG_ANCHOR_POINT                                                                          0x00700014UL   
#define TAG_ANCHOR_POINT_VISIBILITY                                                               0x00700015UL   
#define TAG_GRAPHIC_DIMENSIONS                                                                    0x00700020UL   
#define TAG_NUMBER_OF_GRAPHIC_POINTS                                                              0x00700021UL   
#define TAG_GRAPHIC_DATA                                                                          0x00700022UL   
#define TAG_GRAPHIC_TYPE                                                                          0x00700023UL   
#define TAG_GRAPHIC_FILLED                                                                        0x00700024UL   
#define TAG_IMAGE_ROTATION_RETIRED                                                                0x00700040UL   // Retired
#define TAG_IMAGE_HORIZONTAL_FLIP                                                                 0x00700041UL   
#define TAG_IMAGE_ROTATION                                                                        0x00700042UL   
#define TAG_DISPLAYED_AREA_TOP_LEFT_HAND_CORNER_TRIAL                                             0x00700050UL   // Retired
#define TAG_DISPLAYED_AREA_BOTTOM_RIGHT_HAND_CORNER_TRIAL                                         0x00700051UL   // Retired
#define TAG_DISPLAYED_AREA_TOP_LEFT_HAND_CORNER                                                   0x00700052UL   
#define TAG_DISPLAYED_AREA_BOTTOM_RIGHT_HAND_CORNER                                               0x00700053UL   
#define TAG_DISPLAYED_AREA_SELECTION_SEQUENCE                                                     0x0070005AUL   
#define TAG_GRAPHIC_LAYER_SEQUENCE                                                                0x00700060UL   
#define TAG_GRAPHIC_LAYER_ORDER                                                                   0x00700062UL   
#define TAG_GRAPHIC_LAYER_RECOMMENDED_DISPLAY_GRAYSCALE_VALUE                                     0x00700066UL   
#define TAG_GRAPHIC_LAYER_RECOMMENDED_DISPLAY_RGB_VALUE                                           0x00700067UL   // Retired
#define TAG_GRAPHIC_LAYER_DESCRIPTION                                                             0x00700068UL   
#define TAG_CONTENT_LABEL                                                                         0x00700080UL   
#define TAG_CONTENT_DESCRIPTION                                                                   0x00700081UL   
#define TAG_PRESENTATION_CREATION_DATE                                                            0x00700082UL   
#define TAG_PRESENTATION_CREATION_TIME                                                            0x00700083UL   
#define TAG_CONTENT_CREATOR_NAME                                                                  0x00700084UL   
#define TAG_CONTENT_CREATOR_IDENTIFICATION_CODE_SEQUENCE                                          0x00700086UL   
#define TAG_ALTERNATE_CONTENT_DESCRIPTION_SEQUENCE                                                0x00700087UL   
#define TAG_PRESENTATION_SIZE_MODE                                                                0x00700100UL   
#define TAG_PRESENTATION_PIXEL_SPACING                                                            0x00700101UL   
#define TAG_PRESENTATION_PIXEL_ASPECT_RATIO                                                       0x00700102UL   
#define TAG_PRESENTATION_PIXEL_MAGNIFICATION_RATIO                                                0x00700103UL   
#define TAG_GRAPHIC_GROUP_LABEL                                                                   0x00700207UL   
#define TAG_GRAPHIC_GROUP_DESCRIPTION                                                             0x00700208UL   
#define TAG_COMPOUND_GRAPHIC_SEQUENCE                                                             0x00700209UL   
#define TAG_COMPOUND_GRAPHIC_INSTANCE_ID                                                          0x00700226UL   
#define TAG_FONT_NAME                                                                             0x00700227UL   
#define TAG_FONT_NAME_TYPE                                                                        0x00700228UL   
#define TAG_CSS_FONT_NAME                                                                         0x00700229UL   
#define TAG_ROTATION_ANGLE                                                                        0x00700230UL   
#define TAG_TEXT_STYLE_SEQUENCE                                                                   0x00700231UL   
#define TAG_LINE_STYLE_SEQUENCE                                                                   0x00700232UL   
#define TAG_FILL_STYLE_SEQUENCE                                                                   0x00700233UL   
#define TAG_GRAPHIC_GROUP_SEQUENCE                                                                0x00700234UL   
#define TAG_TEXT_COLOR_CIELAB_VALUE                                                               0x00700241UL   
#define TAG_HORIZONTAL_ALIGNMENT                                                                  0x00700242UL   
#define TAG_VERTICAL_ALIGNMENT                                                                    0x00700243UL   
#define TAG_SHADOW_STYLE                                                                          0x00700244UL   
#define TAG_SHADOW_OFFSET_X                                                                       0x00700245UL   
#define TAG_SHADOW_OFFSET_Y                                                                       0x00700246UL   
#define TAG_SHADOW_COLOR_CIELAB_VALUE                                                             0x00700247UL   
#define TAG_UNDERLINED                                                                            0x00700248UL   
#define TAG_BOLD                                                                                  0x00700249UL   
#define TAG_ITALIC                                                                                0x00700250UL   
#define TAG_PATTERN_ON_COLOR_CIELAB_VALUE                                                         0x00700251UL   
#define TAG_PATTERN_OFF_COLOR_CIELAB_VALUE                                                        0x00700252UL   
#define TAG_LINE_THICKNESS                                                                        0x00700253UL   
#define TAG_LINE_DASHING_STYLE                                                                    0x00700254UL   
#define TAG_LINE_PATTERN                                                                          0x00700255UL   
#define TAG_FILL_PATTERN                                                                          0x00700256UL   
#define TAG_FILL_MODE                                                                             0x00700257UL   
#define TAG_SHADOW_OPACITY                                                                        0x00700258UL   
#define TAG_GAP_LENGTH                                                                            0x00700261UL   
#define TAG_DIAMETER_OF_VISIBILITY                                                                0x00700262UL   
#define TAG_ROTATION_POINT                                                                        0x00700273UL   
#define TAG_TICK_ALIGNMENT                                                                        0x00700274UL   
#define TAG_SHOW_TICK_LABEL                                                                       0x00700278UL   
#define TAG_TICK_LABEL_ALIGNMENT                                                                  0x00700279UL   
#define TAG_COMPOUND_GRAPHIC_UNITS                                                                0x00700282UL   
#define TAG_PATTERN_ON_OPACITY                                                                    0x00700284UL   
#define TAG_PATTERN_OFF_OPACITY                                                                   0x00700285UL   
#define TAG_MAJOR_TICKS_SEQUENCE                                                                  0x00700287UL   
#define TAG_TICK_POSITION                                                                         0x00700288UL   
#define TAG_TICK_LABEL                                                                            0x00700289UL   
#define TAG_COMPOUND_GRAPHIC_TYPE                                                                 0x00700294UL   
#define TAG_GRAPHIC_GROUP_ID                                                                      0x00700295UL   
#define TAG_SHAPE_TYPE                                                                            0x00700306UL   
#define TAG_REGISTRATION_SEQUENCE                                                                 0x00700308UL   
#define TAG_MATRIX_REGISTRATION_SEQUENCE                                                          0x00700309UL   
#define TAG_MATRIX_SEQUENCE                                                                       0x0070030AUL   
#define TAG_FRAME_OF_REFERENCE_TO_DISPLAYED_COORDINATE_SYSTEM_TRANSFORMATION_MATRIX               0x0070030BUL   
#define TAG_FRAME_OF_REFERENCE_TRANSFORMATION_MATRIX_TYPE                                         0x0070030CUL   
#define TAG_REGISTRATION_TYPE_CODE_SEQUENCE                                                       0x0070030DUL   
#define TAG_FIDUCIAL_DESCRIPTION                                                                  0x0070030FUL   
#define TAG_FIDUCIAL_IDENTIFIER                                                                   0x00700310UL   
#define TAG_FIDUCIAL_IDENTIFIER_CODE_SEQUENCE                                                     0x00700311UL   
#define TAG_CONTOUR_UNCERTAINTY_RADIUS                                                            0x00700312UL   
#define TAG_USED_FIDUCIALS_SEQUENCE                                                               0x00700314UL   
#define TAG_GRAPHIC_COORDINATES_DATA_SEQUENCE                                                     0x00700318UL   
#define TAG_FIDUCIAL_UID                                                                          0x0070031AUL   
#define TAG_REFERENCED_FIDUCIAL_UID                                                               0x0070031BUL   
#define TAG_FIDUCIAL_SET_SEQUENCE                                                                 0x0070031CUL   
#define TAG_FIDUCIAL_SEQUENCE                                                                     0x0070031EUL   
#define TAG_FIDUCIALS_PROPERTY_CATEGORY_CODE_SEQUENCE                                             0x0070031FUL   
#define TAG_GRAPHIC_LAYER_RECOMMENDED_DISPLAY_CIELAB_VALUE                                        0x00700401UL   
#define TAG_BLENDING_SEQUENCE                                                                     0x00700402UL   
#define TAG_RELATIVE_OPACITY                                                                      0x00700403UL   
#define TAG_REFERENCED_SPATIAL_REGISTRATION_SEQUENCE                                              0x00700404UL   
#define TAG_BLENDING_POSITION                                                                     0x00700405UL   
#define TAG_PRESENTATION_DISPLAY_COLLECTION_UID                                                   0x00701101UL   
#define TAG_PRESENTATION_SEQUENCE_COLLECTION_UID                                                  0x00701102UL   
#define TAG_PRESENTATION_SEQUENCE_POSITION_INDEX                                                  0x00701103UL   
#define TAG_RENDERED_IMAGE_REFERENCE_SEQUENCE                                                     0x00701104UL   
#define TAG_VOLUMETRIC_PRESENTATION_STATE_INPUT_SEQUENCE                                          0x00701201UL   
#define TAG_PRESENTATION_INPUT_TYPE                                                               0x00701202UL   
#define TAG_INPUT_SEQUENCE_POSITION_INDEX                                                         0x00701203UL   
#define TAG_CROP                                                                                  0x00701204UL   
#define TAG_CROPPING_SPECIFICATION_INDEX                                                          0x00701205UL   
#define TAG_COMPOSITING_METHOD                                                                    0x00701206UL   // Retired
#define TAG_VOLUMETRIC_PRESENTATION_INPUT_NUMBER                                                  0x00701207UL   
#define TAG_IMAGE_VOLUME_GEOMETRY                                                                 0x00701208UL   
#define TAG_VOLUMETRIC_PRESENTATION_INPUT_SET_UID                                                 0x00701209UL   
#define TAG_VOLUMETRIC_PRESENTATION_INPUT_SET_SEQUENCE                                            0x0070120AUL   
#define TAG_GLOBAL_CROP                                                                           0x0070120BUL   
#define TAG_GLOBAL_CROPPING_SPECIFICATION_INDEX                                                   0x0070120CUL   
#define TAG_RENDERING_METHOD                                                                      0x0070120DUL   
#define TAG_VOLUME_CROPPING_SEQUENCE                                                              0x00701301UL   
#define TAG_VOLUME_CROPPING_METHOD                                                                0x00701302UL   
#define TAG_BOUNDING_BOX_CROP                                                                     0x00701303UL   
#define TAG_OBLIQUE_CROPPING_PLANE_SEQUENCE                                                       0x00701304UL   
#define TAG_PLANE                                                                                 0x00701305UL   
#define TAG_PLANE_NORMAL                                                                          0x00701306UL   
#define TAG_CROPPING_SPECIFICATION_NUMBER                                                         0x00701309UL   
#define TAG_MULTI_PLANAR_RECONSTRUCTION_STYLE                                                     0x00701501UL   
#define TAG_MPR_THICKNESS_TYPE                                                                    0x00701502UL   
#define TAG_MPR_SLAB_THICKNESS                                                                    0x00701503UL   
#define TAG_MPR_TOP_LEFT_HAND_CORNER                                                              0x00701505UL   
#define TAG_MPR_VIEW_WIDTH_DIRECTION                                                              0x00701507UL   
#define TAG_MPR_VIEW_WIDTH                                                                        0x00701508UL   
#define TAG_NUMBER_OF_VOLUMETRIC_CURVE_POINTS                                                     0x0070150CUL   
#define TAG_VOLUMETRIC_CURVE_POINTS                                                               0x0070150DUL   
#define TAG_MPR_VIEW_HEIGHT_DIRECTION                                                             0x00701511UL   
#define TAG_MPR_VIEW_HEIGHT                                                                       0x00701512UL   
#define TAG_RENDER_PROJECTION                                                                     0x00701602UL   
#define TAG_VIEWPOINT_POSITION                                                                    0x00701603UL   
#define TAG_VIEWPOINT_LOOKAT_POINT                                                                0x00701604UL   
#define TAG_VIEWPOINT_UP_DIRECTION                                                                0x00701605UL   
#define TAG_RENDER_FIELD_OF_VIEW                                                                  0x00701606UL   
#define TAG_SAMPLING_STEP_SIZE                                                                    0x00701607UL   
#define TAG_SHADING_STYLE                                                                         0x00701701UL   
#define TAG_AMBIENT_REFLECTION_INTENSITY                                                          0x00701702UL   
#define TAG_LIGHT_DIRECTION                                                                       0x00701703UL   
#define TAG_DIFFUSE_REFLECTION_INTENSITY                                                          0x00701704UL   
#define TAG_SPECULAR_REFLECTION_INTENSITY                                                         0x00701705UL   
#define TAG_SHININESS                                                                             0x00701706UL   
#define TAG_PRESENTATION_STATE_CLASSIFICATION_COMPONENT_SEQUENCE                                  0x00701801UL   
#define TAG_COMPONENT_TYPE                                                                        0x00701802UL   
#define TAG_COMPONENT_INPUT_SEQUENCE                                                              0x00701803UL   
#define TAG_VOLUMETRIC_PRESENTATION_INPUT_INDEX                                                   0x00701804UL   
#define TAG_PRESENTATION_STATE_COMPOSITOR_COMPONENT_SEQUENCE                                      0x00701805UL   
#define TAG_WEIGHTING_TRANSFER_FUNCTION_SEQUENCE                                                  0x00701806UL   
#define TAG_WEIGHTING_LOOKUP_TABLE_DESCRIPTOR                                                     0x00701807UL   
#define TAG_WEIGHTING_LOOKUP_TABLE_DATA                                                           0x00701808UL   
#define TAG_VOLUMETRIC_ANNOTATION_SEQUENCE                                                        0x00701901UL   
#define TAG_REFERENCED_STRUCTURED_CONTEXT_SEQUENCE                                                0x00701903UL   
#define TAG_REFERENCED_CONTENT_ITEM                                                               0x00701904UL   
#define TAG_VOLUMETRIC_PRESENTATION_INPUT_ANNOTATION_SEQUENCE                                     0x00701905UL   
#define TAG_ANNOTATION_CLIPPING                                                                   0x00701907UL   
#define TAG_PRESENTATION_ANIMATION_STYLE                                                          0x00701A01UL   
#define TAG_RECOMMENDED_ANIMATION_RATE                                                            0x00701A03UL   
#define TAG_ANIMATION_CURVE_SEQUENCE                                                              0x00701A04UL   
#define TAG_ANIMATION_STEP_SIZE                                                                   0x00701A05UL   
#define TAG_SWIVEL_RANGE                                                                          0x00701A06UL   
#define TAG_VOLUMETRIC_CURVE_UP_DIRECTIONS                                                        0x00701A07UL   
#define TAG_VOLUME_STREAM_SEQUENCE                                                                0x00701A08UL   
#define TAG_RGBA_TRANSFER_FUNCTION_DESCRIPTION                                                    0x00701A09UL   
#define TAG_ADVANCED_BLENDING_SEQUENCE                                                            0x00701B01UL   
#define TAG_BLENDING_INPUT_NUMBER                                                                 0x00701B02UL   
#define TAG_BLENDING_DISPLAY_INPUT_SEQUENCE                                                       0x00701B03UL   
#define TAG_BLENDING_DISPLAY_SEQUENCE                                                             0x00701B04UL   
#define TAG_BLENDING_MODE                                                                         0x00701B06UL   
#define TAG_TIME_SERIES_BLENDING                                                                  0x00701B07UL   
#define TAG_GEOMETRY_FOR_DISPLAY                                                                  0x00701B08UL   
#define TAG_THRESHOLD_SEQUENCE                                                                    0x00701B11UL   
#define TAG_THRESHOLD_VALUE_SEQUENCE                                                              0x00701B12UL   
#define TAG_THRESHOLD_TYPE                                                                        0x00701B13UL   
#define TAG_THRESHOLD_VALUE                                                                       0x00701B14UL   

// *****************************************************************************************************************************
// *** 0072
// *****************************************************************************************************************************
#define TAG_HANGING_PROTOCOL_NAME                                                                 0x00720002UL   
#define TAG_HANGING_PROTOCOL_DESCRIPTION                                                          0x00720004UL   
#define TAG_HANGING_PROTOCOL_LEVEL                                                                0x00720006UL   
#define TAG_HANGING_PROTOCOL_CREATOR                                                              0x00720008UL   
#define TAG_HANGING_PROTOCOL_CREATION_DATETIME                                                    0x0072000AUL   
#define TAG_HANGING_PROTOCOL_DEFINITION_SEQUENCE                                                  0x0072000CUL   
#define TAG_HANGING_PROTOCOL_USER_IDENTIFICATION_CODE_SEQUENCE                                    0x0072000EUL   
#define TAG_HANGING_PROTOCOL_USER_GROUP_NAME                                                      0x00720010UL   
#define TAG_SOURCE_HANGING_PROTOCOL_SEQUENCE                                                      0x00720012UL   
#define TAG_NUMBER_OF_PRIORS_REFERENCED                                                           0x00720014UL   
#define TAG_IMAGE_SETS_SEQUENCE                                                                   0x00720020UL   
#define TAG_IMAGE_SET_SELECTOR_SEQUENCE                                                           0x00720022UL   
#define TAG_IMAGE_SET_SELECTOR_USAGE_FLAG                                                         0x00720024UL   
#define TAG_SELECTOR_ATTRIBUTE                                                                    0x00720026UL   
#define TAG_SELECTOR_VALUE_NUMBER                                                                 0x00720028UL   
#define TAG_TIME_BASED_IMAGE_SETS_SEQUENCE                                                        0x00720030UL   
#define TAG_IMAGE_SET_NUMBER                                                                      0x00720032UL   
#define TAG_IMAGE_SET_SELECTOR_CATEGORY                                                           0x00720034UL   
#define TAG_RELATIVE_TIME                                                                         0x00720038UL   
#define TAG_RELATIVE_TIME_UNITS                                                                   0x0072003AUL   
#define TAG_ABSTRACT_PRIOR_VALUE                                                                  0x0072003CUL   
#define TAG_ABSTRACT_PRIOR_CODE_SEQUENCE                                                          0x0072003EUL   
#define TAG_IMAGE_SET_LABEL                                                                       0x00720040UL   
#define TAG_SELECTOR_ATTRIBUTE_VR                                                                 0x00720050UL   
#define TAG_SELECTOR_SEQUENCE_POINTER                                                             0x00720052UL   
#define TAG_SELECTOR_SEQUENCE_POINTER_PRIVATE_CREATOR                                             0x00720054UL   
#define TAG_SELECTOR_ATTRIBUTE_PRIVATE_CREATOR                                                    0x00720056UL   
#define TAG_SELECTOR_AE_VALUE                                                                     0x0072005EUL   
#define TAG_SELECTOR_AS_VALUE                                                                     0x0072005FUL   
#define TAG_SELECTOR_AT_VALUE                                                                     0x00720060UL   
#define TAG_SELECTOR_DA_VALUE                                                                     0x00720061UL   
#define TAG_SELECTOR_CS_VALUE                                                                     0x00720062UL   
#define TAG_SELECTOR_DT_VALUE                                                                     0x00720063UL   
#define TAG_SELECTOR_IS_VALUE                                                                     0x00720064UL   
#define TAG_SELECTOR_OB_VALUE                                                                     0x00720065UL   
#define TAG_SELECTOR_LO_VALUE                                                                     0x00720066UL   
#define TAG_SELECTOR_OF_VALUE                                                                     0x00720067UL   
#define TAG_SELECTOR_LT_VALUE                                                                     0x00720068UL   
#define TAG_SELECTOR_OW_VALUE                                                                     0x00720069UL   
#define TAG_SELECTOR_PN_VALUE                                                                     0x0072006AUL   
#define TAG_SELECTOR_TM_VALUE                                                                     0x0072006BUL   
#define TAG_SELECTOR_SH_VALUE                                                                     0x0072006CUL   
#define TAG_SELECTOR_UN_VALUE                                                                     0x0072006DUL   
#define TAG_SELECTOR_ST_VALUE                                                                     0x0072006EUL   
#define TAG_SELECTOR_UC_VALUE                                                                     0x0072006FUL   
#define TAG_SELECTOR_UT_VALUE                                                                     0x00720070UL   
#define TAG_SELECTOR_UR_VALUE                                                                     0x00720071UL   
#define TAG_SELECTOR_DS_VALUE                                                                     0x00720072UL   
#define TAG_SELECTOR_OD_VALUE                                                                     0x00720073UL   
#define TAG_SELECTOR_FD_VALUE                                                                     0x00720074UL   
#define TAG_SELECTOR_OL_VALUE                                                                     0x00720075UL   
#define TAG_SELECTOR_FL_VALUE                                                                     0x00720076UL   
#define TAG_SELECTOR_UL_VALUE                                                                     0x00720078UL   
#define TAG_SELECTOR_US_VALUE                                                                     0x0072007AUL   
#define TAG_SELECTOR_SL_VALUE                                                                     0x0072007CUL   
#define TAG_SELECTOR_SS_VALUE                                                                     0x0072007EUL   
#define TAG_SELECTOR_UI_VALUE                                                                     0x0072007FUL   
#define TAG_SELECTOR_CODE_SEQUENCE_VALUE                                                          0x00720080UL   
#define TAG_SELECTOR_OV_VALUE                                                                     0x00720081UL   
#define TAG_SELECTOR_SV_VALUE                                                                     0x00720082UL   
#define TAG_SELECTOR_UV_VALUE                                                                     0x00720083UL   
#define TAG_NUMBER_OF_SCREENS                                                                     0x00720100UL   
#define TAG_NOMINAL_SCREEN_DEFINITION_SEQUENCE                                                    0x00720102UL   
#define TAG_NUMBER_OF_VERTICAL_PIXELS                                                             0x00720104UL   
#define TAG_NUMBER_OF_HORIZONTAL_PIXELS                                                           0x00720106UL   
#define TAG_DISPLAY_ENVIRONMENT_SPATIAL_POSITION                                                  0x00720108UL   
#define TAG_SCREEN_MINIMUM_GRAYSCALE_BIT_DEPTH                                                    0x0072010AUL   
#define TAG_SCREEN_MINIMUM_COLOR_BIT_DEPTH                                                        0x0072010CUL   
#define TAG_APPLICATION_MAXIMUM_REPAINT_TIME                                                      0x0072010EUL   
#define TAG_DISPLAY_SETS_SEQUENCE                                                                 0x00720200UL   
#define TAG_DISPLAY_SET_NUMBER                                                                    0x00720202UL   
#define TAG_DISPLAY_SET_LABEL                                                                     0x00720203UL   
#define TAG_DISPLAY_SET_PRESENTATION_GROUP                                                        0x00720204UL   
#define TAG_DISPLAY_SET_PRESENTATION_GROUP_DESCRIPTION                                            0x00720206UL   
#define TAG_PARTIAL_DATA_DISPLAY_HANDLING                                                         0x00720208UL   
#define TAG_SYNCHRONIZED_SCROLLING_SEQUENCE                                                       0x00720210UL   
#define TAG_DISPLAY_SET_SCROLLING_GROUP                                                           0x00720212UL   
#define TAG_NAVIGATION_INDICATOR_SEQUENCE                                                         0x00720214UL   
#define TAG_NAVIGATION_DISPLAY_SET                                                                0x00720216UL   
#define TAG_REFERENCE_DISPLAY_SETS                                                                0x00720218UL   
#define TAG_IMAGE_BOXES_SEQUENCE                                                                  0x00720300UL   
#define TAG_IMAGE_BOX_NUMBER                                                                      0x00720302UL   
#define TAG_IMAGE_BOX_LAYOUT_TYPE                                                                 0x00720304UL   
#define TAG_IMAGE_BOX_TILE_HORIZONTAL_DIMENSION                                                   0x00720306UL   
#define TAG_IMAGE_BOX_TILE_VERTICAL_DIMENSION                                                     0x00720308UL   
#define TAG_IMAGE_BOX_SCROLL_DIRECTION                                                            0x00720310UL   
#define TAG_IMAGE_BOX_SMALL_SCROLL_TYPE                                                           0x00720312UL   
#define TAG_IMAGE_BOX_SMALL_SCROLL_AMOUNT                                                         0x00720314UL   
#define TAG_IMAGE_BOX_LARGE_SCROLL_TYPE                                                           0x00720316UL   
#define TAG_IMAGE_BOX_LARGE_SCROLL_AMOUNT                                                         0x00720318UL   
#define TAG_IMAGE_BOX_OVERLAP_PRIORITY                                                            0x00720320UL   
#define TAG_CINE_RELATIVE_TO_REAL_TIME                                                            0x00720330UL   
#define TAG_FILTER_OPERATIONS_SEQUENCE                                                            0x00720400UL   
#define TAG_FILTER_BY_CATEGORY                                                                    0x00720402UL   
#define TAG_FILTER_BY_ATTRIBUTE_PRESENCE                                                          0x00720404UL   
#define TAG_FILTER_BY_OPERATOR                                                                    0x00720406UL   
#define TAG_STRUCTURED_DISPLAY_BACKGROUND_CIELAB_VALUE                                            0x00720420UL   
#define TAG_EMPTY_IMAGE_BOX_CIELAB_VALUE                                                          0x00720421UL   
#define TAG_STRUCTURED_DISPLAY_IMAGE_BOX_SEQUENCE                                                 0x00720422UL   
#define TAG_STRUCTURED_DISPLAY_TEXT_BOX_SEQUENCE                                                  0x00720424UL   
#define TAG_REFERENCED_FIRST_FRAME_SEQUENCE                                                       0x00720427UL   
#define TAG_IMAGE_BOX_SYNCHRONIZATION_SEQUENCE                                                    0x00720430UL   
#define TAG_SYNCHRONIZED_IMAGE_BOX_LIST                                                           0x00720432UL   
#define TAG_TYPE_OF_SYNCHRONIZATION                                                               0x00720434UL   
#define TAG_BLENDING_OPERATION_TYPE                                                               0x00720500UL   
#define TAG_REFORMATTING_OPERATION_TYPE                                                           0x00720510UL   
#define TAG_REFORMATTING_THICKNESS                                                                0x00720512UL   
#define TAG_REFORMATTING_INTERVAL                                                                 0x00720514UL   
#define TAG_REFORMATTING_OPERATION_INITIAL_VIEW_DIRECTION                                         0x00720516UL   
#define TAG_3D_RENDERING_TYPE                                                                     0x00720520UL   
#define TAG_SORTING_OPERATIONS_SEQUENCE                                                           0x00720600UL   
#define TAG_SORT_BY_CATEGORY                                                                      0x00720602UL   
#define TAG_SORTING_DIRECTION                                                                     0x00720604UL   
#define TAG_DISPLAY_SET_PATIENT_ORIENTATION                                                       0x00720700UL   
#define TAG_VOI_TYPE                                                                              0x00720702UL   
#define TAG_PSEUDO_COLOR_TYPE                                                                     0x00720704UL   
#define TAG_PSEUDO_COLOR_PALETTE_INSTANCE_REFERENCE_SEQUENCE                                      0x00720705UL   
#define TAG_SHOW_GRAYSCALE_INVERTED                                                               0x00720706UL   
#define TAG_SHOW_IMAGE_TRUE_SIZE_FLAG                                                             0x00720710UL   
#define TAG_SHOW_GRAPHIC_ANNOTATION_FLAG                                                          0x00720712UL   
#define TAG_SHOW_PATIENT_DEMOGRAPHICS_FLAG                                                        0x00720714UL   
#define TAG_SHOW_ACQUISITION_TECHNIQUES_FLAG                                                      0x00720716UL   
#define TAG_DISPLAY_SET_HORIZONTAL_JUSTIFICATION                                                  0x00720717UL   
#define TAG_DISPLAY_SET_VERTICAL_JUSTIFICATION                                                    0x00720718UL   

// *****************************************************************************************************************************
// *** 0074
// *****************************************************************************************************************************
#define TAG_CONTINUATION_START_METERSET                                                           0x00740120UL   
#define TAG_CONTINUATION_END_METERSET                                                             0x00740121UL   
#define TAG_PROCEDURE_STEP_STATE                                                                  0x00741000UL   
#define TAG_PROCEDURE_STEP_PROGRESS_INFORMATION_SEQUENCE                                          0x00741002UL   
#define TAG_PROCEDURE_STEP_PROGRESS                                                               0x00741004UL   
#define TAG_PROCEDURE_STEP_PROGRESS_DESCRIPTION                                                   0x00741006UL   
#define TAG_PROCEDURE_STEP_PROGRESS_PARAMETERS_SEQUENCE                                           0x00741007UL   
#define TAG_PROCEDURE_STEP_COMMUNICATIONS_URI_SEQUENCE                                            0x00741008UL   
#define TAG_CONTACT_URI                                                                           0x0074100AUL   
#define TAG_CONTACT_DISPLAY_NAME                                                                  0x0074100CUL   
#define TAG_PROCEDURE_STEP_DISCONTINUATION_REASON_CODE_SEQUENCE                                   0x0074100EUL   
#define TAG_BEAM_TASK_SEQUENCE                                                                    0x00741020UL   
#define TAG_BEAM_TASK_TYPE                                                                        0x00741022UL   
#define TAG_BEAM_ORDER_INDEX_TRIAL                                                                0x00741024UL   // Retired
#define TAG_AUTOSEQUENCE_FLAG                                                                     0x00741025UL   
#define TAG_TABLE_TOP_VERTICAL_ADJUSTED_POSITION                                                  0x00741026UL   
#define TAG_TABLE_TOP_LONGITUDINAL_ADJUSTED_POSITION                                              0x00741027UL   
#define TAG_TABLE_TOP_LATERAL_ADJUSTED_POSITION                                                   0x00741028UL   
#define TAG_PATIENT_SUPPORT_ADJUSTED_ANGLE                                                        0x0074102AUL   
#define TAG_TABLE_TOP_ECCENTRIC_ADJUSTED_ANGLE                                                    0x0074102BUL   
#define TAG_TABLE_TOP_PITCH_ADJUSTED_ANGLE                                                        0x0074102CUL   
#define TAG_TABLE_TOP_ROLL_ADJUSTED_ANGLE                                                         0x0074102DUL   
#define TAG_DELIVERY_VERIFICATION_IMAGE_SEQUENCE                                                  0x00741030UL   
#define TAG_VERIFICATION_IMAGE_TIMING                                                             0x00741032UL   
#define TAG_DOUBLE_EXPOSURE_FLAG                                                                  0x00741034UL   
#define TAG_DOUBLE_EXPOSURE_ORDERING                                                              0x00741036UL   
#define TAG_DOUBLE_EXPOSURE_METERSET_TRIAL                                                        0x00741038UL   // Retired
#define TAG_DOUBLE_EXPOSURE_FIELD_DELTA_TRIAL                                                     0x0074103AUL   // Retired
#define TAG_RELATED_REFERENCE_RT_IMAGE_SEQUENCE                                                   0x00741040UL   
#define TAG_GENERAL_MACHINE_VERIFICATION_SEQUENCE                                                 0x00741042UL   
#define TAG_CONVENTIONAL_MACHINE_VERIFICATION_SEQUENCE                                            0x00741044UL   
#define TAG_ION_MACHINE_VERIFICATION_SEQUENCE                                                     0x00741046UL   
#define TAG_FAILED_ATTRIBUTES_SEQUENCE                                                            0x00741048UL   
#define TAG_OVERRIDDEN_ATTRIBUTES_SEQUENCE                                                        0x0074104AUL   
#define TAG_CONVENTIONAL_CONTROL_POINT_VERIFICATION_SEQUENCE                                      0x0074104CUL   
#define TAG_ION_CONTROL_POINT_VERIFICATION_SEQUENCE                                               0x0074104EUL   
#define TAG_ATTRIBUTE_OCCURRENCE_SEQUENCE                                                         0x00741050UL   
#define TAG_ATTRIBUTE_OCCURRENCE_POINTER                                                          0x00741052UL   
#define TAG_ATTRIBUTE_ITEM_SELECTOR                                                               0x00741054UL   
#define TAG_ATTRIBUTE_OCCURRENCE_PRIVATE_CREATOR                                                  0x00741056UL   
#define TAG_SELECTOR_SEQUENCE_POINTER_ITEMS                                                       0x00741057UL   
#define TAG_SCHEDULED_PROCEDURE_STEP_PRIORITY                                                     0x00741200UL   
#define TAG_WORKLIST_LABEL                                                                        0x00741202UL   
#define TAG_PROCEDURE_STEP_LABEL                                                                  0x00741204UL   
#define TAG_SCHEDULED_PROCESSING_PARAMETERS_SEQUENCE                                              0x00741210UL   
#define TAG_PERFORMED_PROCESSING_PARAMETERS_SEQUENCE                                              0x00741212UL   
#define TAG_UNIFIED_PROCEDURE_STEP_PERFORMED_PROCEDURE_SEQUENCE                                   0x00741216UL   
#define TAG_RELATED_PROCEDURE_STEP_SEQUENCE                                                       0x00741220UL   // Retired
#define TAG_PROCEDURE_STEP_RELATIONSHIP_TYPE                                                      0x00741222UL   // Retired
#define TAG_REPLACED_PROCEDURE_STEP_SEQUENCE                                                      0x00741224UL   
#define TAG_DELETION_LOCK                                                                         0x00741230UL   
#define TAG_RECEIVING_AE                                                                          0x00741234UL   
#define TAG_REQUESTING_AE                                                                         0x00741236UL   
#define TAG_REASON_FOR_CANCELLATION                                                               0x00741238UL   
#define TAG_SCP_STATUS                                                                            0x00741242UL   
#define TAG_SUBSCRIPTION_LIST_STATUS                                                              0x00741244UL   
#define TAG_UNIFIED_PROCEDURE_STEP_LIST_STATUS                                                    0x00741246UL   
#define TAG_BEAM_ORDER_INDEX                                                                      0x00741324UL   
#define TAG_DOUBLE_EXPOSURE_METERSET                                                              0x00741338UL   
#define TAG_DOUBLE_EXPOSURE_FIELD_DELTA                                                           0x0074133AUL   
#define TAG_BRACHY_TASK_SEQUENCE                                                                  0x00741401UL   
#define TAG_CONTINUATION_START_TOTAL_REFERENCE_AIR_KERMA                                          0x00741402UL   
#define TAG_CONTINUATION_END_TOTAL_REFERENCE_AIR_KERMA                                            0x00741403UL   
#define TAG_CONTINUATION_PULSE_NUMBER                                                             0x00741404UL   
#define TAG_CHANNEL_DELIVERY_ORDER_SEQUENCE                                                       0x00741405UL   
#define TAG_REFERENCED_CHANNEL_NUMBER                                                             0x00741406UL   
#define TAG_START_CUMULATIVE_TIME_WEIGHT                                                          0x00741407UL   
#define TAG_END_CUMULATIVE_TIME_WEIGHT                                                            0x00741408UL   
#define TAG_OMITTED_CHANNEL_SEQUENCE                                                              0x00741409UL   
#define TAG_REASON_FOR_CHANNEL_OMISSION                                                           0x0074140AUL   
#define TAG_REASON_FOR_CHANNEL_OMISSION_DESCRIPTION                                               0x0074140BUL   
#define TAG_CHANNEL_DELIVERY_ORDER_INDEX                                                          0x0074140CUL   
#define TAG_CHANNEL_DELIVERY_CONTINUATION_SEQUENCE                                                0x0074140DUL   
#define TAG_OMITTED_APPLICATION_SETUP_SEQUENCE                                                    0x0074140EUL   

// *****************************************************************************************************************************
// *** 0076
// *****************************************************************************************************************************
#define TAG_IMPLANT_ASSEMBLY_TEMPLATE_NAME                                                        0x00760001UL   
#define TAG_IMPLANT_ASSEMBLY_TEMPLATE_ISSUER                                                      0x00760003UL   
#define TAG_IMPLANT_ASSEMBLY_TEMPLATE_VERSION                                                     0x00760006UL   
#define TAG_REPLACED_IMPLANT_ASSEMBLY_TEMPLATE_SEQUENCE                                           0x00760008UL   
#define TAG_IMPLANT_ASSEMBLY_TEMPLATE_TYPE                                                        0x0076000AUL   
#define TAG_ORIGINAL_IMPLANT_ASSEMBLY_TEMPLATE_SEQUENCE                                           0x0076000CUL   
#define TAG_DERIVATION_IMPLANT_ASSEMBLY_TEMPLATE_SEQUENCE                                         0x0076000EUL   
#define TAG_IMPLANT_ASSEMBLY_TEMPLATE_TARGET_ANATOMY_SEQUENCE                                     0x00760010UL   
#define TAG_PROCEDURE_TYPE_CODE_SEQUENCE                                                          0x00760020UL   
#define TAG_SURGICAL_TECHNIQUE                                                                    0x00760030UL   
#define TAG_COMPONENT_TYPES_SEQUENCE                                                              0x00760032UL   
#define TAG_COMPONENT_TYPE_CODE_SEQUENCE                                                          0x00760034UL   
#define TAG_EXCLUSIVE_COMPONENT_TYPE                                                              0x00760036UL   
#define TAG_MANDATORY_COMPONENT_TYPE                                                              0x00760038UL   
#define TAG_COMPONENT_SEQUENCE                                                                    0x00760040UL   
#define TAG_COMPONENT_ID                                                                          0x00760055UL   
#define TAG_COMPONENT_ASSEMBLY_SEQUENCE                                                           0x00760060UL   
#define TAG_COMPONENT_1_REFERENCED_ID                                                             0x00760070UL   
#define TAG_COMPONENT_1_REFERENCED_MATING_FEATURE_SET_ID                                          0x00760080UL   
#define TAG_COMPONENT_1_REFERENCED_MATING_FEATURE_ID                                              0x00760090UL   
#define TAG_COMPONENT_2_REFERENCED_ID                                                             0x007600A0UL   
#define TAG_COMPONENT_2_REFERENCED_MATING_FEATURE_SET_ID                                          0x007600B0UL   
#define TAG_COMPONENT_2_REFERENCED_MATING_FEATURE_ID                                              0x007600C0UL   

// *****************************************************************************************************************************
// *** 0078
// *****************************************************************************************************************************
#define TAG_IMPLANT_TEMPLATE_GROUP_NAME                                                           0x00780001UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_DESCRIPTION                                                    0x00780010UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_ISSUER                                                         0x00780020UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_VERSION                                                        0x00780024UL   
#define TAG_REPLACED_IMPLANT_TEMPLATE_GROUP_SEQUENCE                                              0x00780026UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_TARGET_ANATOMY_SEQUENCE                                        0x00780028UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_MEMBERS_SEQUENCE                                               0x0078002AUL   
#define TAG_IMPLANT_TEMPLATE_GROUP_MEMBER_ID                                                      0x0078002EUL   
#define TAG_3D_IMPLANT_TEMPLATE_GROUP_MEMBER_MATCHING_POINT                                       0x00780050UL   
#define TAG_3D_IMPLANT_TEMPLATE_GROUP_MEMBER_MATCHING_AXES                                        0x00780060UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_MEMBER_MATCHING_2D_COORDINATES_SEQUENCE                        0x00780070UL   
#define TAG_2D_IMPLANT_TEMPLATE_GROUP_MEMBER_MATCHING_POINT                                       0x00780090UL   
#define TAG_2D_IMPLANT_TEMPLATE_GROUP_MEMBER_MATCHING_AXES                                        0x007800A0UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_VARIATION_DIMENSION_SEQUENCE                                   0x007800B0UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_VARIATION_DIMENSION_NAME                                       0x007800B2UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_VARIATION_DIMENSION_RANK_SEQUENCE                              0x007800B4UL   
#define TAG_REFERENCED_IMPLANT_TEMPLATE_GROUP_MEMBER_ID                                           0x007800B6UL   
#define TAG_IMPLANT_TEMPLATE_GROUP_VARIATION_DIMENSION_RANK                                       0x007800B8UL   

// *****************************************************************************************************************************
// *** 0080
// *****************************************************************************************************************************
#define TAG_SURFACE_SCAN_ACQUISITION_TYPE_CODE_SEQUENCE                                           0x00800001UL   
#define TAG_SURFACE_SCAN_MODE_CODE_SEQUENCE                                                       0x00800002UL   
#define TAG_REGISTRATION_METHOD_CODE_SEQUENCE                                                     0x00800003UL   
#define TAG_SHOT_DURATION_TIME                                                                    0x00800004UL   
#define TAG_SHOT_OFFSET_TIME                                                                      0x00800005UL   
#define TAG_SURFACE_POINT_PRESENTATION_VALUE_DATA                                                 0x00800006UL   
#define TAG_SURFACE_POINT_COLOR_CIELAB_VALUE_DATA                                                 0x00800007UL   
#define TAG_UV_MAPPING_SEQUENCE                                                                   0x00800008UL   
#define TAG_TEXTURE_LABEL                                                                         0x00800009UL   
#define TAG_U_VALUE_DATA                                                                          0x00800010UL   
#define TAG_V_VALUE_DATA                                                                          0x00800011UL   
#define TAG_REFERENCED_TEXTURE_SEQUENCE                                                           0x00800012UL   
#define TAG_REFERENCED_SURFACE_DATA_SEQUENCE                                                      0x00800013UL   

// *****************************************************************************************************************************
// *** 0082
// *****************************************************************************************************************************
#define TAG_ASSESSMENT_SUMMARY                                                                    0x00820001UL   
#define TAG_ASSESSMENT_SUMMARY_DESCRIPTION                                                        0x00820003UL   
#define TAG_ASSESSED_SOP_INSTANCE_SEQUENCE                                                        0x00820004UL   
#define TAG_REFERENCED_COMPARISON_SOP_INSTANCE_SEQUENCE                                           0x00820005UL   
#define TAG_NUMBER_OF_ASSESSMENT_OBSERVATIONS                                                     0x00820006UL   
#define TAG_ASSESSMENT_OBSERVATIONS_SEQUENCE                                                      0x00820007UL   
#define TAG_OBSERVATION_SIGNIFICANCE                                                              0x00820008UL   
#define TAG_OBSERVATION_DESCRIPTION                                                               0x0082000AUL   
#define TAG_STRUCTURED_CONSTRAINT_OBSERVATION_SEQUENCE                                            0x0082000CUL   
#define TAG_ASSESSED_ATTRIBUTE_VALUE_SEQUENCE                                                     0x00820010UL   
#define TAG_ASSESSMENT_SET_ID                                                                     0x00820016UL   
#define TAG_ASSESSMENT_REQUESTER_SEQUENCE                                                         0x00820017UL   
#define TAG_SELECTOR_ATTRIBUTE_NAME                                                               0x00820018UL   
#define TAG_SELECTOR_ATTRIBUTE_KEYWORD                                                            0x00820019UL   
#define TAG_ASSESSMENT_TYPE_CODE_SEQUENCE                                                         0x00820021UL   
#define TAG_OBSERVATION_BASIS_CODE_SEQUENCE                                                       0x00820022UL   
#define TAG_ASSESSMENT_LABEL                                                                      0x00820023UL   
#define TAG_CONSTRAINT_TYPE                                                                       0x00820032UL   
#define TAG_SPECIFICATION_SELECTION_GUIDANCE                                                      0x00820033UL   
#define TAG_CONSTRAINT_VALUE_SEQUENCE                                                             0x00820034UL   
#define TAG_RECOMMENDED_DEFAULT_VALUE_SEQUENCE                                                    0x00820035UL   
#define TAG_CONSTRAINT_VIOLATION_SIGNIFICANCE                                                     0x00820036UL   
#define TAG_CONSTRAINT_VIOLATION_CONDITION                                                        0x00820037UL   
#define TAG_MODIFIABLE_CONSTRAINT_FLAG                                                            0x00820038UL   

// *****************************************************************************************************************************
// *** 0088
// *****************************************************************************************************************************
#define TAG_STORAGE_MEDIA_FILE_SET_ID                                                             0x00880130UL   
#define TAG_STORAGE_MEDIA_FILE_SET_UID                                                            0x00880140UL   
#define TAG_ICON_IMAGE_SEQUENCE                                                                   0x00880200UL   
#define TAG_TOPIC_TITLE                                                                           0x00880904UL   // Retired
#define TAG_TOPIC_SUBJECT                                                                         0x00880906UL   // Retired
#define TAG_TOPIC_AUTHOR                                                                          0x00880910UL   // Retired
#define TAG_TOPIC_KEYWORDS                                                                        0x00880912UL   // Retired

// *****************************************************************************************************************************
// *** 0100
// *****************************************************************************************************************************
#define TAG_SOP_INSTANCE_STATUS                                                                   0x01000410UL   
#define TAG_SOP_AUTHORIZATION_DATETIME                                                            0x01000420UL   
#define TAG_SOP_AUTHORIZATION_COMMENT                                                             0x01000424UL   
#define TAG_AUTHORIZATION_EQUIPMENT_CERTIFICATION_NUMBER                                          0x01000426UL   

// *****************************************************************************************************************************
// *** 0400
// *****************************************************************************************************************************
#define TAG_MAC_ID_NUMBER                                                                         0x04000005UL   
#define TAG_MAC_CALCULATION_TRANSFER_SYNTAX_UID                                                   0x04000010UL   
#define TAG_MAC_ALGORITHM                                                                         0x04000015UL   
#define TAG_DATA_ELEMENTS_SIGNED                                                                  0x04000020UL   
#define TAG_DIGITAL_SIGNATURE_UID                                                                 0x04000100UL   
#define TAG_DIGITAL_SIGNATURE_DATETIME                                                            0x04000105UL   
#define TAG_CERTIFICATE_TYPE                                                                      0x04000110UL   
#define TAG_CERTIFICATE_OF_SIGNER                                                                 0x04000115UL   
#define TAG_SIGNATURE                                                                             0x04000120UL   
#define TAG_CERTIFIED_TIMESTAMP_TYPE                                                              0x04000305UL   
#define TAG_CERTIFIED_TIMESTAMP                                                                   0x04000310UL   
#define TAG_DIGITAL_SIGNATURE_PURPOSE_CODE_SEQUENCE                                               0x04000401UL   
#define TAG_REFERENCED_DIGITAL_SIGNATURE_SEQUENCE                                                 0x04000402UL   
#define TAG_REFERENCED_SOP_INSTANCE_MAC_SEQUENCE                                                  0x04000403UL   
#define TAG_MAC                                                                                   0x04000404UL   
#define TAG_ENCRYPTED_ATTRIBUTES_SEQUENCE                                                         0x04000500UL   
#define TAG_ENCRYPTED_CONTENT_TRANSFER_SYNTAX_UID                                                 0x04000510UL   
#define TAG_ENCRYPTED_CONTENT                                                                     0x04000520UL   
#define TAG_MODIFIED_ATTRIBUTES_SEQUENCE                                                          0x04000550UL   
#define TAG_NONCONFORMING_MODIFIED_ATTRIBUTES_SEQUENCE                                            0x04000551UL   
#define TAG_NONCONFORMING_DATA_ELEMENT_VALUE                                                      0x04000552UL   
#define TAG_ORIGINAL_ATTRIBUTES_SEQUENCE                                                          0x04000561UL   
#define TAG_ATTRIBUTE_MODIFICATION_DATETIME                                                       0x04000562UL   
#define TAG_MODIFYING_SYSTEM                                                                      0x04000563UL   
#define TAG_SOURCE_OF_PREVIOUS_VALUES                                                             0x04000564UL   
#define TAG_REASON_FOR_THE_ATTRIBUTE_MODIFICATION                                                 0x04000565UL   
#define TAG_INSTANCE_ORIGIN_STATUS                                                                0x04000600UL   

// *****************************************************************************************************************************
// *** 1000
// *****************************************************************************************************************************
#define TAG_ESCAPE_TRIPLET                                                                        0x10000000UL   // Retired
#define TAG_RUN_LENGTH_TRIPLET                                                                    0x10000001UL   // Retired
#define TAG_HUFFMAN_TABLE_SIZE                                                                    0x10000002UL   // Retired
#define TAG_HUFFMAN_TABLE_TRIPLET                                                                 0x10000003UL   // Retired
#define TAG_SHIFT_TABLE_SIZE                                                                      0x10000004UL   // Retired
#define TAG_SHIFT_TABLE_TRIPLET                                                                   0x10000005UL   // Retired

// *****************************************************************************************************************************
// *** 1010
// *****************************************************************************************************************************
#define TAG_ZONAL_MAP                                                                             0x10100000UL   // Retired

// *****************************************************************************************************************************
// *** 2000
// *****************************************************************************************************************************
#define TAG_NUMBER_OF_COPIES                                                                      0x20000010UL   
#define TAG_PRINTER_CONFIGURATION_SEQUENCE                                                        0x2000001EUL   
#define TAG_PRINT_PRIORITY                                                                        0x20000020UL   
#define TAG_MEDIUM_TYPE                                                                           0x20000030UL   
#define TAG_FILM_DESTINATION                                                                      0x20000040UL   
#define TAG_FILM_SESSION_LABEL                                                                    0x20000050UL   
#define TAG_MEMORY_ALLOCATION                                                                     0x20000060UL   
#define TAG_MAXIMUM_MEMORY_ALLOCATION                                                             0x20000061UL   
#define TAG_COLOR_IMAGE_PRINTING_FLAG                                                             0x20000062UL   // Retired
#define TAG_COLLATION_FLAG                                                                        0x20000063UL   // Retired
#define TAG_ANNOTATION_FLAG                                                                       0x20000065UL   // Retired
#define TAG_IMAGE_OVERLAY_FLAG                                                                    0x20000067UL   // Retired
#define TAG_PRESENTATION_LUT_FLAG                                                                 0x20000069UL   // Retired
#define TAG_IMAGE_BOX_PRESENTATION_LUT_FLAG                                                       0x2000006AUL   // Retired
#define TAG_MEMORY_BIT_DEPTH                                                                      0x200000A0UL   
#define TAG_PRINTING_BIT_DEPTH                                                                    0x200000A1UL   
#define TAG_MEDIA_INSTALLED_SEQUENCE                                                              0x200000A2UL   
#define TAG_OTHER_MEDIA_AVAILABLE_SEQUENCE                                                        0x200000A4UL   
#define TAG_SUPPORTED_IMAGE_DISPLAY_FORMATS_SEQUENCE                                              0x200000A8UL   
#define TAG_REFERENCED_FILM_BOX_SEQUENCE                                                          0x20000500UL   
#define TAG_REFERENCED_STORED_PRINT_SEQUENCE                                                      0x20000510UL   // Retired

// *****************************************************************************************************************************
// *** 2010
// *****************************************************************************************************************************
#define TAG_IMAGE_DISPLAY_FORMAT                                                                  0x20100010UL   
#define TAG_ANNOTATION_DISPLAY_FORMAT_ID                                                          0x20100030UL   
#define TAG_FILM_ORIENTATION                                                                      0x20100040UL   
#define TAG_FILM_SIZE_ID                                                                          0x20100050UL   
#define TAG_PRINTER_RESOLUTION_ID                                                                 0x20100052UL   
#define TAG_DEFAULT_PRINTER_RESOLUTION_ID                                                         0x20100054UL   
#define TAG_MAGNIFICATION_TYPE                                                                    0x20100060UL   
#define TAG_SMOOTHING_TYPE                                                                        0x20100080UL   
#define TAG_DEFAULT_MAGNIFICATION_TYPE                                                            0x201000A6UL   
#define TAG_OTHER_MAGNIFICATION_TYPES_AVAILABLE                                                   0x201000A7UL   
#define TAG_DEFAULT_SMOOTHING_TYPE                                                                0x201000A8UL   
#define TAG_OTHER_SMOOTHING_TYPES_AVAILABLE                                                       0x201000A9UL   
#define TAG_BORDER_DENSITY                                                                        0x20100100UL   
#define TAG_EMPTY_IMAGE_DENSITY                                                                   0x20100110UL   
#define TAG_MIN_DENSITY                                                                           0x20100120UL   
#define TAG_MAX_DENSITY                                                                           0x20100130UL   
#define TAG_TRIM                                                                                  0x20100140UL   
#define TAG_CONFIGURATION_INFORMATION                                                             0x20100150UL   
#define TAG_CONFIGURATION_INFORMATION_DESCRIPTION                                                 0x20100152UL   
#define TAG_MAXIMUM_COLLATED_FILMS                                                                0x20100154UL   
#define TAG_ILLUMINATION                                                                          0x2010015EUL   
#define TAG_REFLECTED_AMBIENT_LIGHT                                                               0x20100160UL   
#define TAG_PRINTER_PIXEL_SPACING                                                                 0x20100376UL   
#define TAG_REFERENCED_FILM_SESSION_SEQUENCE                                                      0x20100500UL   
#define TAG_REFERENCED_IMAGE_BOX_SEQUENCE                                                         0x20100510UL   
#define TAG_REFERENCED_BASIC_ANNOTATION_BOX_SEQUENCE                                              0x20100520UL   

// *****************************************************************************************************************************
// *** 2020
// *****************************************************************************************************************************
#define TAG_IMAGE_BOX_POSITION                                                                    0x20200010UL   
#define TAG_POLARITY                                                                              0x20200020UL   
#define TAG_REQUESTED_IMAGE_SIZE                                                                  0x20200030UL   
#define TAG_REQUESTED_DECIMATE_CROP_BEHAVIOR                                                      0x20200040UL   
#define TAG_REQUESTED_RESOLUTION_ID                                                               0x20200050UL   
#define TAG_REQUESTED_IMAGE_SIZE_FLAG                                                             0x202000A0UL   
#define TAG_DECIMATE_CROP_RESULT                                                                  0x202000A2UL   
#define TAG_BASIC_GRAYSCALE_IMAGE_SEQUENCE                                                        0x20200110UL   
#define TAG_BASIC_COLOR_IMAGE_SEQUENCE                                                            0x20200111UL   
#define TAG_REFERENCED_IMAGE_OVERLAY_BOX_SEQUENCE                                                 0x20200130UL   // Retired
#define TAG_REFERENCED_VOI_LUT_BOX_SEQUENCE                                                       0x20200140UL   // Retired

// *****************************************************************************************************************************
// *** 2030
// *****************************************************************************************************************************
#define TAG_ANNOTATION_POSITION                                                                   0x20300010UL   
#define TAG_TEXT_STRING                                                                           0x20300020UL   

// *****************************************************************************************************************************
// *** 2040
// *****************************************************************************************************************************
#define TAG_REFERENCED_OVERLAY_PLANE_SEQUENCE                                                     0x20400010UL   // Retired
#define TAG_REFERENCED_OVERLAY_PLANE_GROUPS                                                       0x20400011UL   // Retired
#define TAG_OVERLAY_PIXEL_DATA_SEQUENCE                                                           0x20400020UL   // Retired
#define TAG_OVERLAY_MAGNIFICATION_TYPE                                                            0x20400060UL   // Retired
#define TAG_OVERLAY_SMOOTHING_TYPE                                                                0x20400070UL   // Retired
#define TAG_OVERLAY_OR_IMAGE_MAGNIFICATION                                                        0x20400072UL   // Retired
#define TAG_MAGNIFY_TO_NUMBER_OF_COLUMNS                                                          0x20400074UL   // Retired
#define TAG_OVERLAY_FOREGROUND_DENSITY                                                            0x20400080UL   // Retired
#define TAG_OVERLAY_BACKGROUND_DENSITY                                                            0x20400082UL   // Retired
#define TAG_OVERLAY_MODE                                                                          0x20400090UL   // Retired
#define TAG_THRESHOLD_DENSITY                                                                     0x20400100UL   // Retired
#define TAG_REFERENCED_IMAGE_BOX_SEQUENCE_RETIRED                                                 0x20400500UL   // Retired

// *****************************************************************************************************************************
// *** 2050
// *****************************************************************************************************************************
#define TAG_PRESENTATION_LUT_SEQUENCE                                                             0x20500010UL   
#define TAG_PRESENTATION_LUT_SHAPE                                                                0x20500020UL   
#define TAG_REFERENCED_PRESENTATION_LUT_SEQUENCE                                                  0x20500500UL   

// *****************************************************************************************************************************
// *** 2100
// *****************************************************************************************************************************
#define TAG_PRINT_JOB_ID                                                                          0x21000010UL   // Retired
#define TAG_EXECUTION_STATUS                                                                      0x21000020UL   
#define TAG_EXECUTION_STATUS_INFO                                                                 0x21000030UL   
#define TAG_CREATION_DATE                                                                         0x21000040UL   
#define TAG_CREATION_TIME                                                                         0x21000050UL   
#define TAG_ORIGINATOR                                                                            0x21000070UL   
#define TAG_DESTINATION_AE                                                                        0x21000140UL   
#define TAG_OWNER_ID                                                                              0x21000160UL   
#define TAG_NUMBER_OF_FILMS                                                                       0x21000170UL   
#define TAG_REFERENCED_PRINT_JOB_SEQUENCE_PULL_STORED_PRINT                                       0x21000500UL   // Retired

// *****************************************************************************************************************************
// *** 2110
// *****************************************************************************************************************************
#define TAG_PRINTER_STATUS                                                                        0x21100010UL   
#define TAG_PRINTER_STATUS_INFO                                                                   0x21100020UL   
#define TAG_PRINTER_NAME                                                                          0x21100030UL   
#define TAG_PRINT_QUEUE_ID                                                                        0x21100099UL   // Retired

// *****************************************************************************************************************************
// *** 2120
// *****************************************************************************************************************************
#define TAG_QUEUE_STATUS                                                                          0x21200010UL   // Retired
#define TAG_PRINT_JOB_DESCRIPTION_SEQUENCE                                                        0x21200050UL   // Retired
#define TAG_REFERENCED_PRINT_JOB_SEQUENCE                                                         0x21200070UL   // Retired

// *****************************************************************************************************************************
// *** 2130
// *****************************************************************************************************************************
#define TAG_PRINT_MANAGEMENT_CAPABILITIES_SEQUENCE                                                0x21300010UL   // Retired
#define TAG_PRINTER_CHARACTERISTICS_SEQUENCE                                                      0x21300015UL   // Retired
#define TAG_FILM_BOX_CONTENT_SEQUENCE                                                             0x21300030UL   // Retired
#define TAG_IMAGE_BOX_CONTENT_SEQUENCE                                                            0x21300040UL   // Retired
#define TAG_ANNOTATION_CONTENT_SEQUENCE                                                           0x21300050UL   // Retired
#define TAG_IMAGE_OVERLAY_BOX_CONTENT_SEQUENCE                                                    0x21300060UL   // Retired
#define TAG_PRESENTATION_LUT_CONTENT_SEQUENCE                                                     0x21300080UL   // Retired
#define TAG_PROPOSED_STUDY_SEQUENCE                                                               0x213000A0UL   // Retired
#define TAG_ORIGINAL_IMAGE_SEQUENCE                                                               0x213000C0UL   // Retired

// *****************************************************************************************************************************
// *** 2200
// *****************************************************************************************************************************
#define TAG_LABEL_USING_INFORMATION_EXTRACTED_FROM_INSTANCES                                      0x22000001UL   
#define TAG_LABEL_TEXT                                                                            0x22000002UL   
#define TAG_LABEL_STYLE_SELECTION                                                                 0x22000003UL   
#define TAG_MEDIA_DISPOSITION                                                                     0x22000004UL   
#define TAG_BARCODE_VALUE                                                                         0x22000005UL   
#define TAG_BARCODE_SYMBOLOGY                                                                     0x22000006UL   
#define TAG_ALLOW_MEDIA_SPLITTING                                                                 0x22000007UL   
#define TAG_INCLUDE_NON_DICOM_OBJECTS                                                             0x22000008UL   
#define TAG_INCLUDE_DISPLAY_APPLICATION                                                           0x22000009UL   
#define TAG_PRESERVE_COMPOSITE_INSTANCES_AFTER_MEDIA_CREATION                                     0x2200000AUL   
#define TAG_TOTAL_NUMBER_OF_PIECES_OF_MEDIA_CREATED                                               0x2200000BUL   
#define TAG_REQUESTED_MEDIA_APPLICATION_PROFILE                                                   0x2200000CUL   
#define TAG_REFERENCED_STORAGE_MEDIA_SEQUENCE                                                     0x2200000DUL   
#define TAG_FAILURE_ATTRIBUTES                                                                    0x2200000EUL   
#define TAG_ALLOW_LOSSY_COMPRESSION                                                               0x2200000FUL   
#define TAG_REQUEST_PRIORITY                                                                      0x22000020UL   

// *****************************************************************************************************************************
// *** 3002
// *****************************************************************************************************************************
#define TAG_RT_IMAGE_LABEL                                                                        0x30020002UL   
#define TAG_RT_IMAGE_NAME                                                                         0x30020003UL   
#define TAG_RT_IMAGE_DESCRIPTION                                                                  0x30020004UL   
#define TAG_REPORTED_VALUES_ORIGIN                                                                0x3002000AUL   
#define TAG_RT_IMAGE_PLANE                                                                        0x3002000CUL   
#define TAG_X_RAY_IMAGE_RECEPTOR_TRANSLATION                                                      0x3002000DUL   
#define TAG_X_RAY_IMAGE_RECEPTOR_ANGLE                                                            0x3002000EUL   
#define TAG_RT_IMAGE_ORIENTATION                                                                  0x30020010UL   
#define TAG_IMAGE_PLANE_PIXEL_SPACING                                                             0x30020011UL   
#define TAG_RT_IMAGE_POSITION                                                                     0x30020012UL   
#define TAG_RADIATION_MACHINE_NAME                                                                0x30020020UL   
#define TAG_RADIATION_MACHINE_SAD                                                                 0x30020022UL   
#define TAG_RADIATION_MACHINE_SSD                                                                 0x30020024UL   
#define TAG_RT_IMAGE_SID                                                                          0x30020026UL   
#define TAG_SOURCE_TO_REFERENCE_OBJECT_DISTANCE                                                   0x30020028UL   
#define TAG_FRACTION_NUMBER                                                                       0x30020029UL   
#define TAG_EXPOSURE_SEQUENCE                                                                     0x30020030UL   
#define TAG_METERSET_EXPOSURE                                                                     0x30020032UL   
#define TAG_DIAPHRAGM_POSITION                                                                    0x30020034UL   
#define TAG_FLUENCE_MAP_SEQUENCE                                                                  0x30020040UL   
#define TAG_FLUENCE_DATA_SOURCE                                                                   0x30020041UL   
#define TAG_FLUENCE_DATA_SCALE                                                                    0x30020042UL   
#define TAG_PRIMARY_FLUENCE_MODE_SEQUENCE                                                         0x30020050UL   
#define TAG_FLUENCE_MODE                                                                          0x30020051UL   
#define TAG_FLUENCE_MODE_ID                                                                       0x30020052UL   

// *****************************************************************************************************************************
// *** 3004
// *****************************************************************************************************************************
#define TAG_DVH_TYPE                                                                              0x30040001UL   
#define TAG_DOSE_UNITS                                                                            0x30040002UL   
#define TAG_DOSE_TYPE                                                                             0x30040004UL   
#define TAG_SPATIAL_TRANSFORM_OF_DOSE                                                             0x30040005UL   
#define TAG_DOSE_COMMENT                                                                          0x30040006UL   
#define TAG_NORMALIZATION_POINT                                                                   0x30040008UL   
#define TAG_DOSE_SUMMATION_TYPE                                                                   0x3004000AUL   
#define TAG_GRID_FRAME_OFFSET_VECTOR                                                              0x3004000CUL   
#define TAG_DOSE_GRID_SCALING                                                                     0x3004000EUL   
#define TAG_RT_DOSE_ROI_SEQUENCE                                                                  0x30040010UL   
#define TAG_DOSE_VALUE                                                                            0x30040012UL   
#define TAG_TISSUE_HETEROGENEITY_CORRECTION                                                       0x30040014UL   
#define TAG_DVH_NORMALIZATION_POINT                                                               0x30040040UL   
#define TAG_DVH_NORMALIZATION_DOSE_VALUE                                                          0x30040042UL   
#define TAG_DVH_SEQUENCE                                                                          0x30040050UL   
#define TAG_DVH_DOSE_SCALING                                                                      0x30040052UL   
#define TAG_DVH_VOLUME_UNITS                                                                      0x30040054UL   
#define TAG_DVH_NUMBER_OF_BINS                                                                    0x30040056UL   
#define TAG_DVH_DATA                                                                              0x30040058UL   
#define TAG_DVH_REFERENCED_ROI_SEQUENCE                                                           0x30040060UL   
#define TAG_DVH_ROI_CONTRIBUTION_TYPE                                                             0x30040062UL   
#define TAG_DVH_MINIMUM_DOSE                                                                      0x30040070UL   
#define TAG_DVH_MAXIMUM_DOSE                                                                      0x30040072UL   
#define TAG_DVH_MEAN_DOSE                                                                         0x30040074UL   

// *****************************************************************************************************************************
// *** 3006
// *****************************************************************************************************************************
#define TAG_STRUCTURE_SET_LABEL                                                                   0x30060002UL   
#define TAG_STRUCTURE_SET_NAME                                                                    0x30060004UL   
#define TAG_STRUCTURE_SET_DESCRIPTION                                                             0x30060006UL   
#define TAG_STRUCTURE_SET_DATE                                                                    0x30060008UL   
#define TAG_STRUCTURE_SET_TIME                                                                    0x30060009UL   
#define TAG_REFERENCED_FRAME_OF_REFERENCE_SEQUENCE                                                0x30060010UL   
#define TAG_RT_REFERENCED_STUDY_SEQUENCE                                                          0x30060012UL   
#define TAG_RT_REFERENCED_SERIES_SEQUENCE                                                         0x30060014UL   
#define TAG_CONTOUR_IMAGE_SEQUENCE                                                                0x30060016UL   
#define TAG_PREDECESSOR_STRUCTURE_SET_SEQUENCE                                                    0x30060018UL   
#define TAG_STRUCTURE_SET_ROI_SEQUENCE                                                            0x30060020UL   
#define TAG_ROI_NUMBER                                                                            0x30060022UL   
#define TAG_REFERENCED_FRAME_OF_REFERENCE_UID                                                     0x30060024UL   
#define TAG_ROI_NAME                                                                              0x30060026UL   
#define TAG_ROI_DESCRIPTION                                                                       0x30060028UL   
#define TAG_ROI_DISPLAY_COLOR                                                                     0x3006002AUL   
#define TAG_ROI_VOLUME                                                                            0x3006002CUL   
#define TAG_RT_RELATED_ROI_SEQUENCE                                                               0x30060030UL   
#define TAG_RT_ROI_RELATIONSHIP                                                                   0x30060033UL   
#define TAG_ROI_GENERATION_ALGORITHM                                                              0x30060036UL   
#define TAG_ROI_DERIVATION_ALGORITHM_IDENTIFICATION_SEQUENCE                                      0x30060037UL   
#define TAG_ROI_GENERATION_DESCRIPTION                                                            0x30060038UL   
#define TAG_ROI_CONTOUR_SEQUENCE                                                                  0x30060039UL   
#define TAG_CONTOUR_SEQUENCE                                                                      0x30060040UL   
#define TAG_CONTOUR_GEOMETRIC_TYPE                                                                0x30060042UL   
#define TAG_CONTOUR_SLAB_THICKNESS                                                                0x30060044UL   // Retired
#define TAG_CONTOUR_OFFSET_VECTOR                                                                 0x30060045UL   // Retired
#define TAG_NUMBER_OF_CONTOUR_POINTS                                                              0x30060046UL   
#define TAG_CONTOUR_NUMBER                                                                        0x30060048UL   
#define TAG_ATTACHED_CONTOURS                                                                     0x30060049UL   // Retired
#define TAG_SOURCE_PIXEL_PLANES_CHARACTERISTICS_SEQUENCE                                          0x3006004AUL   
#define TAG_CONTOUR_DATA                                                                          0x30060050UL   
#define TAG_RT_ROI_OBSERVATIONS_SEQUENCE                                                          0x30060080UL   
#define TAG_OBSERVATION_NUMBER                                                                    0x30060082UL   
#define TAG_REFERENCED_ROI_NUMBER                                                                 0x30060084UL   
#define TAG_ROI_OBSERVATION_LABEL                                                                 0x30060085UL   
#define TAG_RT_ROI_IDENTIFICATION_CODE_SEQUENCE                                                   0x30060086UL   
#define TAG_ROI_OBSERVATION_DESCRIPTION                                                           0x30060088UL   
#define TAG_RELATED_RT_ROI_OBSERVATIONS_SEQUENCE                                                  0x300600A0UL   
#define TAG_RT_ROI_INTERPRETED_TYPE                                                               0x300600A4UL   
#define TAG_ROI_INTERPRETER                                                                       0x300600A6UL   
#define TAG_ROI_PHYSICAL_PROPERTIES_SEQUENCE                                                      0x300600B0UL   
#define TAG_ROI_PHYSICAL_PROPERTY                                                                 0x300600B2UL   
#define TAG_ROI_PHYSICAL_PROPERTY_VALUE                                                           0x300600B4UL   
#define TAG_ROI_ELEMENTAL_COMPOSITION_SEQUENCE                                                    0x300600B6UL   
#define TAG_ROI_ELEMENTAL_COMPOSITION_ATOMIC_NUMBER                                               0x300600B7UL   
#define TAG_ROI_ELEMENTAL_COMPOSITION_ATOMIC_MASS_FRACTION                                        0x300600B8UL   
#define TAG_ADDITIONAL_RT_ROI_IDENTIFICATION_CODE_SEQUENCE                                        0x300600B9UL   // Retired
#define TAG_FRAME_OF_REFERENCE_RELATIONSHIP_SEQUENCE                                              0x300600C0UL   // Retired
#define TAG_RELATED_FRAME_OF_REFERENCE_UID                                                        0x300600C2UL   // Retired
#define TAG_FRAME_OF_REFERENCE_TRANSFORMATION_TYPE                                                0x300600C4UL   // Retired
#define TAG_FRAME_OF_REFERENCE_TRANSFORMATION_MATRIX                                              0x300600C6UL   
#define TAG_FRAME_OF_REFERENCE_TRANSFORMATION_COMMENT                                             0x300600C8UL   
#define TAG_PATIENT_LOCATION_COORDINATES_SEQUENCE                                                 0x300600C9UL   
#define TAG_PATIENT_LOCATION_COORDINATES_CODE_SEQUENCE                                            0x300600CAUL   
#define TAG_PATIENT_SUPPORT_POSITION_SEQUENCE                                                     0x300600CBUL   

// *****************************************************************************************************************************
// *** 3008
// *****************************************************************************************************************************
#define TAG_MEASURED_DOSE_REFERENCE_SEQUENCE                                                      0x30080010UL   
#define TAG_MEASURED_DOSE_DESCRIPTION                                                             0x30080012UL   
#define TAG_MEASURED_DOSE_TYPE                                                                    0x30080014UL   
#define TAG_MEASURED_DOSE_VALUE                                                                   0x30080016UL   
#define TAG_TREATMENT_SESSION_BEAM_SEQUENCE                                                       0x30080020UL   
#define TAG_TREATMENT_SESSION_ION_BEAM_SEQUENCE                                                   0x30080021UL   
#define TAG_CURRENT_FRACTION_NUMBER                                                               0x30080022UL   
#define TAG_TREATMENT_CONTROL_POINT_DATE                                                          0x30080024UL   
#define TAG_TREATMENT_CONTROL_POINT_TIME                                                          0x30080025UL   
#define TAG_TREATMENT_TERMINATION_STATUS                                                          0x3008002AUL   
#define TAG_TREATMENT_TERMINATION_CODE                                                            0x3008002BUL   
#define TAG_TREATMENT_VERIFICATION_STATUS                                                         0x3008002CUL   
#define TAG_REFERENCED_TREATMENT_RECORD_SEQUENCE                                                  0x30080030UL   
#define TAG_SPECIFIED_PRIMARY_METERSET                                                            0x30080032UL   
#define TAG_SPECIFIED_SECONDARY_METERSET                                                          0x30080033UL   
#define TAG_DELIVERED_PRIMARY_METERSET                                                            0x30080036UL   
#define TAG_DELIVERED_SECONDARY_METERSET                                                          0x30080037UL   
#define TAG_SPECIFIED_TREATMENT_TIME                                                              0x3008003AUL   
#define TAG_DELIVERED_TREATMENT_TIME                                                              0x3008003BUL   
#define TAG_CONTROL_POINT_DELIVERY_SEQUENCE                                                       0x30080040UL   
#define TAG_ION_CONTROL_POINT_DELIVERY_SEQUENCE                                                   0x30080041UL   
#define TAG_SPECIFIED_METERSET                                                                    0x30080042UL   
#define TAG_DELIVERED_METERSET                                                                    0x30080044UL   
#define TAG_METERSET_RATE_SET                                                                     0x30080045UL   
#define TAG_METERSET_RATE_DELIVERED                                                               0x30080046UL   
#define TAG_SCAN_SPOT_METERSETS_DELIVERED                                                         0x30080047UL   
#define TAG_DOSE_RATE_DELIVERED                                                                   0x30080048UL   
#define TAG_TREATMENT_SUMMARY_CALCULATED_DOSE_REFERENCE_SEQUENCE                                  0x30080050UL   
#define TAG_CUMULATIVE_DOSE_TO_DOSE_REFERENCE                                                     0x30080052UL   
#define TAG_FIRST_TREATMENT_DATE                                                                  0x30080054UL   
#define TAG_MOST_RECENT_TREATMENT_DATE                                                            0x30080056UL   
#define TAG_NUMBER_OF_FRACTIONS_DELIVERED                                                         0x3008005AUL   
#define TAG_OVERRIDE_SEQUENCE                                                                     0x30080060UL   
#define TAG_PARAMETER_SEQUENCE_POINTER                                                            0x30080061UL   
#define TAG_OVERRIDE_PARAMETER_POINTER                                                            0x30080062UL   
#define TAG_PARAMETER_ITEM_INDEX                                                                  0x30080063UL   
#define TAG_MEASURED_DOSE_REFERENCE_NUMBER                                                        0x30080064UL   
#define TAG_PARAMETER_POINTER                                                                     0x30080065UL   
#define TAG_OVERRIDE_REASON                                                                       0x30080066UL   
#define TAG_PARAMETER_VALUE_NUMBER                                                                0x30080067UL   
#define TAG_CORRECTED_PARAMETER_SEQUENCE                                                          0x30080068UL   
#define TAG_CORRECTION_VALUE                                                                      0x3008006AUL   
#define TAG_CALCULATED_DOSE_REFERENCE_SEQUENCE                                                    0x30080070UL   
#define TAG_CALCULATED_DOSE_REFERENCE_NUMBER                                                      0x30080072UL   
#define TAG_CALCULATED_DOSE_REFERENCE_DESCRIPTION                                                 0x30080074UL   
#define TAG_CALCULATED_DOSE_REFERENCE_DOSE_VALUE                                                  0x30080076UL   
#define TAG_START_METERSET                                                                        0x30080078UL   
#define TAG_END_METERSET                                                                          0x3008007AUL   
#define TAG_REFERENCED_MEASURED_DOSE_REFERENCE_SEQUENCE                                           0x30080080UL   
#define TAG_REFERENCED_MEASURED_DOSE_REFERENCE_NUMBER                                             0x30080082UL   
#define TAG_REFERENCED_CALCULATED_DOSE_REFERENCE_SEQUENCE                                         0x30080090UL   
#define TAG_REFERENCED_CALCULATED_DOSE_REFERENCE_NUMBER                                           0x30080092UL   
#define TAG_BEAM_LIMITING_DEVICE_LEAF_PAIRS_SEQUENCE                                              0x300800A0UL   
#define TAG_RECORDED_WEDGE_SEQUENCE                                                               0x300800B0UL   
#define TAG_RECORDED_COMPENSATOR_SEQUENCE                                                         0x300800C0UL   
#define TAG_RECORDED_BLOCK_SEQUENCE                                                               0x300800D0UL   
#define TAG_TREATMENT_SUMMARY_MEASURED_DOSE_REFERENCE_SEQUENCE                                    0x300800E0UL   
#define TAG_RECORDED_SNOUT_SEQUENCE                                                               0x300800F0UL   
#define TAG_RECORDED_RANGE_SHIFTER_SEQUENCE                                                       0x300800F2UL   
#define TAG_RECORDED_LATERAL_SPREADING_DEVICE_SEQUENCE                                            0x300800F4UL   
#define TAG_RECORDED_RANGE_MODULATOR_SEQUENCE                                                     0x300800F6UL   
#define TAG_RECORDED_SOURCE_SEQUENCE                                                              0x30080100UL   
#define TAG_SOURCE_SERIAL_NUMBER                                                                  0x30080105UL   
#define TAG_TREATMENT_SESSION_APPLICATION_SETUP_SEQUENCE                                          0x30080110UL   
#define TAG_APPLICATION_SETUP_CHECK                                                               0x30080116UL   
#define TAG_RECORDED_BRACHY_ACCESSORY_DEVICE_SEQUENCE                                             0x30080120UL   
#define TAG_REFERENCED_BRACHY_ACCESSORY_DEVICE_NUMBER                                             0x30080122UL   
#define TAG_RECORDED_CHANNEL_SEQUENCE                                                             0x30080130UL   
#define TAG_SPECIFIED_CHANNEL_TOTAL_TIME                                                          0x30080132UL   
#define TAG_DELIVERED_CHANNEL_TOTAL_TIME                                                          0x30080134UL   
#define TAG_SPECIFIED_NUMBER_OF_PULSES                                                            0x30080136UL   
#define TAG_DELIVERED_NUMBER_OF_PULSES                                                            0x30080138UL   
#define TAG_SPECIFIED_PULSE_REPETITION_INTERVAL                                                   0x3008013AUL   
#define TAG_DELIVERED_PULSE_REPETITION_INTERVAL                                                   0x3008013CUL   
#define TAG_RECORDED_SOURCE_APPLICATOR_SEQUENCE                                                   0x30080140UL   
#define TAG_REFERENCED_SOURCE_APPLICATOR_NUMBER                                                   0x30080142UL   
#define TAG_RECORDED_CHANNEL_SHIELD_SEQUENCE                                                      0x30080150UL   
#define TAG_REFERENCED_CHANNEL_SHIELD_NUMBER                                                      0x30080152UL   
#define TAG_BRACHY_CONTROL_POINT_DELIVERED_SEQUENCE                                               0x30080160UL   
#define TAG_SAFE_POSITION_EXIT_DATE                                                               0x30080162UL   
#define TAG_SAFE_POSITION_EXIT_TIME                                                               0x30080164UL   
#define TAG_SAFE_POSITION_RETURN_DATE                                                             0x30080166UL   
#define TAG_SAFE_POSITION_RETURN_TIME                                                             0x30080168UL   
#define TAG_PULSE_SPECIFIC_BRACHY_CONTROL_POINT_DELIVERED_SEQUENCE                                0x30080171UL   
#define TAG_PULSE_NUMBER                                                                          0x30080172UL   
#define TAG_BRACHY_PULSE_CONTROL_POINT_DELIVERED_SEQUENCE                                         0x30080173UL   
#define TAG_CURRENT_TREATMENT_STATUS                                                              0x30080200UL   
#define TAG_TREATMENT_STATUS_COMMENT                                                              0x30080202UL   
#define TAG_FRACTION_GROUP_SUMMARY_SEQUENCE                                                       0x30080220UL   
#define TAG_REFERENCED_FRACTION_NUMBER                                                            0x30080223UL   
#define TAG_FRACTION_GROUP_TYPE                                                                   0x30080224UL   
#define TAG_BEAM_STOPPER_POSITION                                                                 0x30080230UL   
#define TAG_FRACTION_STATUS_SUMMARY_SEQUENCE                                                      0x30080240UL   
#define TAG_TREATMENT_DATE                                                                        0x30080250UL   
#define TAG_TREATMENT_TIME                                                                        0x30080251UL   

// *****************************************************************************************************************************
// *** 300A
// *****************************************************************************************************************************
#define TAG_RT_PLAN_LABEL                                                                         0x300A0002UL   
#define TAG_RT_PLAN_NAME                                                                          0x300A0003UL   
#define TAG_RT_PLAN_DESCRIPTION                                                                   0x300A0004UL   
#define TAG_RT_PLAN_DATE                                                                          0x300A0006UL   
#define TAG_RT_PLAN_TIME                                                                          0x300A0007UL   
#define TAG_TREATMENT_PROTOCOLS                                                                   0x300A0009UL   
#define TAG_PLAN_INTENT                                                                           0x300A000AUL   
#define TAG_TREATMENT_SITES                                                                       0x300A000BUL   
#define TAG_RT_PLAN_GEOMETRY                                                                      0x300A000CUL   
#define TAG_PRESCRIPTION_DESCRIPTION                                                              0x300A000EUL   
#define TAG_DOSE_REFERENCE_SEQUENCE                                                               0x300A0010UL   
#define TAG_DOSE_REFERENCE_NUMBER                                                                 0x300A0012UL   
#define TAG_DOSE_REFERENCE_UID                                                                    0x300A0013UL   
#define TAG_DOSE_REFERENCE_STRUCTURE_TYPE                                                         0x300A0014UL   
#define TAG_NOMINAL_BEAM_ENERGY_UNIT                                                              0x300A0015UL   
#define TAG_DOSE_REFERENCE_DESCRIPTION                                                            0x300A0016UL   
#define TAG_DOSE_REFERENCE_POINT_COORDINATES                                                      0x300A0018UL   
#define TAG_NOMINAL_PRIOR_DOSE                                                                    0x300A001AUL   
#define TAG_DOSE_REFERENCE_TYPE                                                                   0x300A0020UL   
#define TAG_CONSTRAINT_WEIGHT                                                                     0x300A0021UL   
#define TAG_DELIVERY_WARNING_DOSE                                                                 0x300A0022UL   
#define TAG_DELIVERY_MAXIMUM_DOSE                                                                 0x300A0023UL   
#define TAG_TARGET_MINIMUM_DOSE                                                                   0x300A0025UL   
#define TAG_TARGET_PRESCRIPTION_DOSE                                                              0x300A0026UL   
#define TAG_TARGET_MAXIMUM_DOSE                                                                   0x300A0027UL   
#define TAG_TARGET_UNDERDOSE_VOLUME_FRACTION                                                      0x300A0028UL   
#define TAG_ORGAN_AT_RISK_FULL_VOLUME_DOSE                                                        0x300A002AUL   
#define TAG_ORGAN_AT_RISK_LIMIT_DOSE                                                              0x300A002BUL   
#define TAG_ORGAN_AT_RISK_MAXIMUM_DOSE                                                            0x300A002CUL   
#define TAG_ORGAN_AT_RISK_OVERDOSE_VOLUME_FRACTION                                                0x300A002DUL   
#define TAG_TOLERANCE_TABLE_SEQUENCE                                                              0x300A0040UL   
#define TAG_TOLERANCE_TABLE_NUMBER                                                                0x300A0042UL   
#define TAG_TOLERANCE_TABLE_LABEL                                                                 0x300A0043UL   
#define TAG_GANTRY_ANGLE_TOLERANCE                                                                0x300A0044UL   
#define TAG_BEAM_LIMITING_DEVICE_ANGLE_TOLERANCE                                                  0x300A0046UL   
#define TAG_BEAM_LIMITING_DEVICE_TOLERANCE_SEQUENCE                                               0x300A0048UL   
#define TAG_BEAM_LIMITING_DEVICE_POSITION_TOLERANCE                                               0x300A004AUL   
#define TAG_SNOUT_POSITION_TOLERANCE                                                              0x300A004BUL   
#define TAG_PATIENT_SUPPORT_ANGLE_TOLERANCE                                                       0x300A004CUL   
#define TAG_TABLE_TOP_ECCENTRIC_ANGLE_TOLERANCE                                                   0x300A004EUL   
#define TAG_TABLE_TOP_PITCH_ANGLE_TOLERANCE                                                       0x300A004FUL   
#define TAG_TABLE_TOP_ROLL_ANGLE_TOLERANCE                                                        0x300A0050UL   
#define TAG_TABLE_TOP_VERTICAL_POSITION_TOLERANCE                                                 0x300A0051UL   
#define TAG_TABLE_TOP_LONGITUDINAL_POSITION_TOLERANCE                                             0x300A0052UL   
#define TAG_TABLE_TOP_LATERAL_POSITION_TOLERANCE                                                  0x300A0053UL   
#define TAG_RT_PLAN_RELATIONSHIP                                                                  0x300A0055UL   
#define TAG_FRACTION_GROUP_SEQUENCE                                                               0x300A0070UL   
#define TAG_FRACTION_GROUP_NUMBER                                                                 0x300A0071UL   
#define TAG_FRACTION_GROUP_DESCRIPTION                                                            0x300A0072UL   
#define TAG_NUMBER_OF_FRACTIONS_PLANNED                                                           0x300A0078UL   
#define TAG_NUMBER_OF_FRACTION_PATTERN_DIGITS_PER_DAY                                             0x300A0079UL   
#define TAG_REPEAT_FRACTION_CYCLE_LENGTH                                                          0x300A007AUL   
#define TAG_FRACTION_PATTERN                                                                      0x300A007BUL   
#define TAG_NUMBER_OF_BEAMS                                                                       0x300A0080UL   
#define TAG_BEAM_DOSE_SPECIFICATION_POINT                                                         0x300A0082UL   // Retired
#define TAG_REFERENCED_DOSE_REFERENCE_UID                                                         0x300A0083UL   
#define TAG_BEAM_DOSE                                                                             0x300A0084UL   
#define TAG_BEAM_METERSET                                                                         0x300A0086UL   
#define TAG_BEAM_DOSE_POINT_DEPTH                                                                 0x300A0088UL   
#define TAG_BEAM_DOSE_POINT_EQUIVALENT_DEPTH                                                      0x300A0089UL   
#define TAG_BEAM_DOSE_POINT_SSD                                                                   0x300A008AUL   
#define TAG_BEAM_DOSE_MEANING                                                                     0x300A008BUL   
#define TAG_BEAM_DOSE_VERIFICATION_CONTROL_POINT_SEQUENCE                                         0x300A008CUL   
#define TAG_AVERAGE_BEAM_DOSE_POINT_DEPTH                                                         0x300A008DUL   // Retired
#define TAG_AVERAGE_BEAM_DOSE_POINT_EQUIVALENT_DEPTH                                              0x300A008EUL   // Retired
#define TAG_AVERAGE_BEAM_DOSE_POINT_SSD                                                           0x300A008FUL   // Retired
#define TAG_BEAM_DOSE_TYPE                                                                        0x300A0090UL   
#define TAG_ALTERNATE_BEAM_DOSE                                                                   0x300A0091UL   
#define TAG_ALTERNATE_BEAM_DOSE_TYPE                                                              0x300A0092UL   
#define TAG_DEPTH_VALUE_AVERAGING_FLAG                                                            0x300A0093UL   
#define TAG_BEAM_DOSE_POINT_SOURCE_TO_EXTERNAL_CONTOUR_DISTANCE                                   0x300A0094UL   
#define TAG_NUMBER_OF_BRACHY_APPLICATION_SETUPS                                                   0x300A00A0UL   
#define TAG_BRACHY_APPLICATION_SETUP_DOSE_SPECIFICATION_POINT                                     0x300A00A2UL   
#define TAG_BRACHY_APPLICATION_SETUP_DOSE                                                         0x300A00A4UL   
#define TAG_BEAM_SEQUENCE                                                                         0x300A00B0UL   
#define TAG_TREATMENT_MACHINE_NAME                                                                0x300A00B2UL   
#define TAG_PRIMARY_DOSIMETER_UNIT                                                                0x300A00B3UL   
#define TAG_SOURCE_AXIS_DISTANCE                                                                  0x300A00B4UL   
#define TAG_BEAM_LIMITING_DEVICE_SEQUENCE                                                         0x300A00B6UL   
#define TAG_RT_BEAM_LIMITING_DEVICE_TYPE                                                          0x300A00B8UL   
#define TAG_SOURCE_TO_BEAM_LIMITING_DEVICE_DISTANCE                                               0x300A00BAUL   
#define TAG_ISOCENTER_TO_BEAM_LIMITING_DEVICE_DISTANCE                                            0x300A00BBUL   
#define TAG_NUMBER_OF_LEAF_JAW_PAIRS                                                              0x300A00BCUL   
#define TAG_LEAF_POSITION_BOUNDARIES                                                              0x300A00BEUL   
#define TAG_BEAM_NUMBER                                                                           0x300A00C0UL   
#define TAG_BEAM_NAME                                                                             0x300A00C2UL   
#define TAG_BEAM_DESCRIPTION                                                                      0x300A00C3UL   
#define TAG_BEAM_TYPE                                                                             0x300A00C4UL   
#define TAG_BEAM_DELIVERY_DURATION_LIMIT                                                          0x300A00C5UL   
#define TAG_RADIATION_TYPE                                                                        0x300A00C6UL   
#define TAG_HIGH_DOSE_TECHNIQUE_TYPE                                                              0x300A00C7UL   
#define TAG_REFERENCE_IMAGE_NUMBER                                                                0x300A00C8UL   
#define TAG_PLANNED_VERIFICATION_IMAGE_SEQUENCE                                                   0x300A00CAUL   
#define TAG_IMAGING_DEVICE_SPECIFIC_ACQUISITION_PARAMETERS                                        0x300A00CCUL   
#define TAG_TREATMENT_DELIVERY_TYPE                                                               0x300A00CEUL   
#define TAG_NUMBER_OF_WEDGES                                                                      0x300A00D0UL   
#define TAG_WEDGE_SEQUENCE                                                                        0x300A00D1UL   
#define TAG_WEDGE_NUMBER                                                                          0x300A00D2UL   
#define TAG_WEDGE_TYPE                                                                            0x300A00D3UL   
#define TAG_WEDGE_ID                                                                              0x300A00D4UL   
#define TAG_WEDGE_ANGLE                                                                           0x300A00D5UL   
#define TAG_WEDGE_FACTOR                                                                          0x300A00D6UL   
#define TAG_TOTAL_WEDGE_TRAY_WATER_EQUIVALENT_THICKNESS                                           0x300A00D7UL   
#define TAG_WEDGE_ORIENTATION                                                                     0x300A00D8UL   
#define TAG_ISOCENTER_TO_WEDGE_TRAY_DISTANCE                                                      0x300A00D9UL   
#define TAG_SOURCE_TO_WEDGE_TRAY_DISTANCE                                                         0x300A00DAUL   
#define TAG_WEDGE_THIN_EDGE_POSITION                                                              0x300A00DBUL   
#define TAG_BOLUS_ID                                                                              0x300A00DCUL   
#define TAG_BOLUS_DESCRIPTION                                                                     0x300A00DDUL   
#define TAG_EFFECTIVE_WEDGE_ANGLE                                                                 0x300A00DEUL   
#define TAG_NUMBER_OF_COMPENSATORS                                                                0x300A00E0UL   
#define TAG_MATERIAL_ID                                                                           0x300A00E1UL   
#define TAG_TOTAL_COMPENSATOR_TRAY_FACTOR                                                         0x300A00E2UL   
#define TAG_COMPENSATOR_SEQUENCE                                                                  0x300A00E3UL   
#define TAG_COMPENSATOR_NUMBER                                                                    0x300A00E4UL   
#define TAG_COMPENSATOR_ID                                                                        0x300A00E5UL   
#define TAG_SOURCE_TO_COMPENSATOR_TRAY_DISTANCE                                                   0x300A00E6UL   
#define TAG_COMPENSATOR_ROWS                                                                      0x300A00E7UL   
#define TAG_COMPENSATOR_COLUMNS                                                                   0x300A00E8UL   
#define TAG_COMPENSATOR_PIXEL_SPACING                                                             0x300A00E9UL   
#define TAG_COMPENSATOR_POSITION                                                                  0x300A00EAUL   
#define TAG_COMPENSATOR_TRANSMISSION_DATA                                                         0x300A00EBUL   
#define TAG_COMPENSATOR_THICKNESS_DATA                                                            0x300A00ECUL   
#define TAG_NUMBER_OF_BOLI                                                                        0x300A00EDUL   
#define TAG_COMPENSATOR_TYPE                                                                      0x300A00EEUL   
#define TAG_COMPENSATOR_TRAY_ID                                                                   0x300A00EFUL   
#define TAG_NUMBER_OF_BLOCKS                                                                      0x300A00F0UL   
#define TAG_TOTAL_BLOCK_TRAY_FACTOR                                                               0x300A00F2UL   
#define TAG_TOTAL_BLOCK_TRAY_WATER_EQUIVALENT_THICKNESS                                           0x300A00F3UL   
#define TAG_BLOCK_SEQUENCE                                                                        0x300A00F4UL   
#define TAG_BLOCK_TRAY_ID                                                                         0x300A00F5UL   
#define TAG_SOURCE_TO_BLOCK_TRAY_DISTANCE                                                         0x300A00F6UL   
#define TAG_ISOCENTER_TO_BLOCK_TRAY_DISTANCE                                                      0x300A00F7UL   
#define TAG_BLOCK_TYPE                                                                            0x300A00F8UL   
#define TAG_ACCESSORY_CODE                                                                        0x300A00F9UL   
#define TAG_BLOCK_DIVERGENCE                                                                      0x300A00FAUL   
#define TAG_BLOCK_MOUNTING_POSITION                                                               0x300A00FBUL   
#define TAG_BLOCK_NUMBER                                                                          0x300A00FCUL   
#define TAG_BLOCK_NAME                                                                            0x300A00FEUL   
#define TAG_BLOCK_THICKNESS                                                                       0x300A0100UL   
#define TAG_BLOCK_TRANSMISSION                                                                    0x300A0102UL   
#define TAG_BLOCK_NUMBER_OF_POINTS                                                                0x300A0104UL   
#define TAG_BLOCK_DATA                                                                            0x300A0106UL   
#define TAG_APPLICATOR_SEQUENCE                                                                   0x300A0107UL   
#define TAG_APPLICATOR_ID                                                                         0x300A0108UL   
#define TAG_APPLICATOR_TYPE                                                                       0x300A0109UL   
#define TAG_APPLICATOR_DESCRIPTION                                                                0x300A010AUL   
#define TAG_CUMULATIVE_DOSE_REFERENCE_COEFFICIENT                                                 0x300A010CUL   
#define TAG_FINAL_CUMULATIVE_METERSET_WEIGHT                                                      0x300A010EUL   
#define TAG_NUMBER_OF_CONTROL_POINTS                                                              0x300A0110UL   
#define TAG_CONTROL_POINT_SEQUENCE                                                                0x300A0111UL   
#define TAG_CONTROL_POINT_INDEX                                                                   0x300A0112UL   
#define TAG_NOMINAL_BEAM_ENERGY                                                                   0x300A0114UL   
#define TAG_DOSE_RATE_SET                                                                         0x300A0115UL   
#define TAG_WEDGE_POSITION_SEQUENCE                                                               0x300A0116UL   
#define TAG_WEDGE_POSITION                                                                        0x300A0118UL   
#define TAG_BEAM_LIMITING_DEVICE_POSITION_SEQUENCE                                                0x300A011AUL   
#define TAG_LEAF_JAW_POSITIONS                                                                    0x300A011CUL   
#define TAG_GANTRY_ANGLE                                                                          0x300A011EUL   
#define TAG_GANTRY_ROTATION_DIRECTION                                                             0x300A011FUL   
#define TAG_BEAM_LIMITING_DEVICE_ANGLE                                                            0x300A0120UL   
#define TAG_BEAM_LIMITING_DEVICE_ROTATION_DIRECTION                                               0x300A0121UL   
#define TAG_PATIENT_SUPPORT_ANGLE                                                                 0x300A0122UL   
#define TAG_PATIENT_SUPPORT_ROTATION_DIRECTION                                                    0x300A0123UL   
#define TAG_TABLE_TOP_ECCENTRIC_AXIS_DISTANCE                                                     0x300A0124UL   
#define TAG_TABLE_TOP_ECCENTRIC_ANGLE                                                             0x300A0125UL   
#define TAG_TABLE_TOP_ECCENTRIC_ROTATION_DIRECTION                                                0x300A0126UL   
#define TAG_TABLE_TOP_VERTICAL_POSITION                                                           0x300A0128UL   
#define TAG_TABLE_TOP_LONGITUDINAL_POSITION                                                       0x300A0129UL   
#define TAG_TABLE_TOP_LATERAL_POSITION                                                            0x300A012AUL   
#define TAG_ISOCENTER_POSITION                                                                    0x300A012CUL   
#define TAG_SURFACE_ENTRY_POINT                                                                   0x300A012EUL   
#define TAG_SOURCE_TO_SURFACE_DISTANCE                                                            0x300A0130UL   
#define TAG_AVERAGE_BEAM_DOSE_POINT_SOURCE_TO_EXTERNAL_CONTOUR_DISTANCE                           0x300A0131UL   
#define TAG_SOURCE_TO_EXTERNAL_CONTOUR_DISTANCE                                                   0x300A0132UL   
#define TAG_EXTERNAL_CONTOUR_ENTRY_POINT                                                          0x300A0133UL   
#define TAG_CUMULATIVE_METERSET_WEIGHT                                                            0x300A0134UL   
#define TAG_TABLE_TOP_PITCH_ANGLE                                                                 0x300A0140UL   
#define TAG_TABLE_TOP_PITCH_ROTATION_DIRECTION                                                    0x300A0142UL   
#define TAG_TABLE_TOP_ROLL_ANGLE                                                                  0x300A0144UL   
#define TAG_TABLE_TOP_ROLL_ROTATION_DIRECTION                                                     0x300A0146UL   
#define TAG_HEAD_FIXATION_ANGLE                                                                   0x300A0148UL   
#define TAG_GANTRY_PITCH_ANGLE                                                                    0x300A014AUL   
#define TAG_GANTRY_PITCH_ROTATION_DIRECTION                                                       0x300A014CUL   
#define TAG_GANTRY_PITCH_ANGLE_TOLERANCE                                                          0x300A014EUL   
#define TAG_FIXATION_EYE                                                                          0x300A0150UL   
#define TAG_CHAIR_HEAD_FRAME_POSITION                                                             0x300A0151UL   
#define TAG_HEAD_FIXATION_ANGLE_TOLERANCE                                                         0x300A0152UL   
#define TAG_CHAIR_HEAD_FRAME_POSITION_TOLERANCE                                                   0x300A0153UL   
#define TAG_FIXATION_LIGHT_AZIMUTHAL_ANGLE_TOLERANCE                                              0x300A0154UL   
#define TAG_FIXATION_LIGHT_POLAR_ANGLE_TOLERANCE                                                  0x300A0155UL   
#define TAG_PATIENT_SETUP_SEQUENCE                                                                0x300A0180UL   
#define TAG_PATIENT_SETUP_NUMBER                                                                  0x300A0182UL   
#define TAG_PATIENT_SETUP_LABEL                                                                   0x300A0183UL   
#define TAG_PATIENT_ADDITIONAL_POSITION                                                           0x300A0184UL   
#define TAG_FIXATION_DEVICE_SEQUENCE                                                              0x300A0190UL   
#define TAG_FIXATION_DEVICE_TYPE                                                                  0x300A0192UL   
#define TAG_FIXATION_DEVICE_LABEL                                                                 0x300A0194UL   
#define TAG_FIXATION_DEVICE_DESCRIPTION                                                           0x300A0196UL   
#define TAG_FIXATION_DEVICE_POSITION                                                              0x300A0198UL   
#define TAG_FIXATION_DEVICE_PITCH_ANGLE                                                           0x300A0199UL   
#define TAG_FIXATION_DEVICE_ROLL_ANGLE                                                            0x300A019AUL   
#define TAG_SHIELDING_DEVICE_SEQUENCE                                                             0x300A01A0UL   
#define TAG_SHIELDING_DEVICE_TYPE                                                                 0x300A01A2UL   
#define TAG_SHIELDING_DEVICE_LABEL                                                                0x300A01A4UL   
#define TAG_SHIELDING_DEVICE_DESCRIPTION                                                          0x300A01A6UL   
#define TAG_SHIELDING_DEVICE_POSITION                                                             0x300A01A8UL   
#define TAG_SETUP_TECHNIQUE                                                                       0x300A01B0UL   
#define TAG_SETUP_TECHNIQUE_DESCRIPTION                                                           0x300A01B2UL   
#define TAG_SETUP_DEVICE_SEQUENCE                                                                 0x300A01B4UL   
#define TAG_SETUP_DEVICE_TYPE                                                                     0x300A01B6UL   
#define TAG_SETUP_DEVICE_LABEL                                                                    0x300A01B8UL   
#define TAG_SETUP_DEVICE_DESCRIPTION                                                              0x300A01BAUL   
#define TAG_SETUP_DEVICE_PARAMETER                                                                0x300A01BCUL   
#define TAG_SETUP_REFERENCE_DESCRIPTION                                                           0x300A01D0UL   
#define TAG_TABLE_TOP_VERTICAL_SETUP_DISPLACEMENT                                                 0x300A01D2UL   
#define TAG_TABLE_TOP_LONGITUDINAL_SETUP_DISPLACEMENT                                             0x300A01D4UL   
#define TAG_TABLE_TOP_LATERAL_SETUP_DISPLACEMENT                                                  0x300A01D6UL   
#define TAG_BRACHY_TREATMENT_TECHNIQUE                                                            0x300A0200UL   
#define TAG_BRACHY_TREATMENT_TYPE                                                                 0x300A0202UL   
#define TAG_TREATMENT_MACHINE_SEQUENCE                                                            0x300A0206UL   
#define TAG_SOURCE_SEQUENCE                                                                       0x300A0210UL   
#define TAG_SOURCE_NUMBER                                                                         0x300A0212UL   
#define TAG_SOURCE_TYPE                                                                           0x300A0214UL   
#define TAG_SOURCE_MANUFACTURER                                                                   0x300A0216UL   
#define TAG_ACTIVE_SOURCE_DIAMETER                                                                0x300A0218UL   
#define TAG_ACTIVE_SOURCE_LENGTH                                                                  0x300A021AUL   
#define TAG_SOURCE_MODEL_ID                                                                       0x300A021BUL   
#define TAG_SOURCE_DESCRIPTION                                                                    0x300A021CUL   
#define TAG_SOURCE_ENCAPSULATION_NOMINAL_THICKNESS                                                0x300A0222UL   
#define TAG_SOURCE_ENCAPSULATION_NOMINAL_TRANSMISSION                                             0x300A0224UL   
#define TAG_SOURCE_ISOTOPE_NAME                                                                   0x300A0226UL   
#define TAG_SOURCE_ISOTOPE_HALF_LIFE                                                              0x300A0228UL   
#define TAG_SOURCE_STRENGTH_UNITS                                                                 0x300A0229UL   
#define TAG_REFERENCE_AIR_KERMA_RATE                                                              0x300A022AUL   
#define TAG_SOURCE_STRENGTH                                                                       0x300A022BUL   
#define TAG_SOURCE_STRENGTH_REFERENCE_DATE                                                        0x300A022CUL   
#define TAG_SOURCE_STRENGTH_REFERENCE_TIME                                                        0x300A022EUL   
#define TAG_APPLICATION_SETUP_SEQUENCE                                                            0x300A0230UL   
#define TAG_APPLICATION_SETUP_TYPE                                                                0x300A0232UL   
#define TAG_APPLICATION_SETUP_NUMBER                                                              0x300A0234UL   
#define TAG_APPLICATION_SETUP_NAME                                                                0x300A0236UL   
#define TAG_APPLICATION_SETUP_MANUFACTURER                                                        0x300A0238UL   
#define TAG_TEMPLATE_NUMBER                                                                       0x300A0240UL   
#define TAG_TEMPLATE_TYPE                                                                         0x300A0242UL   
#define TAG_TEMPLATE_NAME                                                                         0x300A0244UL   
#define TAG_TOTAL_REFERENCE_AIR_KERMA                                                             0x300A0250UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_SEQUENCE                                                      0x300A0260UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_NUMBER                                                        0x300A0262UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_ID                                                            0x300A0263UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_TYPE                                                          0x300A0264UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_NAME                                                          0x300A0266UL   
#define TAG_BRACHY_ACCESSORY_DEVICE_NOMINAL_THICKNESS                                             0x300A026AUL   
#define TAG_BRACHY_ACCESSORY_DEVICE_NOMINAL_TRANSMISSION                                          0x300A026CUL   
#define TAG_CHANNEL_EFFECTIVE_LENGTH                                                              0x300A0271UL   
#define TAG_CHANNEL_INNER_LENGTH                                                                  0x300A0272UL   
#define TAG_AFTERLOADER_CHANNEL_ID                                                                0x300A0273UL   
#define TAG_SOURCE_APPLICATOR_TIP_LENGTH                                                          0x300A0274UL   
#define TAG_CHANNEL_SEQUENCE                                                                      0x300A0280UL   
#define TAG_CHANNEL_NUMBER                                                                        0x300A0282UL   
#define TAG_CHANNEL_LENGTH                                                                        0x300A0284UL   
#define TAG_CHANNEL_TOTAL_TIME                                                                    0x300A0286UL   
#define TAG_SOURCE_MOVEMENT_TYPE                                                                  0x300A0288UL   
#define TAG_NUMBER_OF_PULSES                                                                      0x300A028AUL   
#define TAG_PULSE_REPETITION_INTERVAL                                                             0x300A028CUL   
#define TAG_SOURCE_APPLICATOR_NUMBER                                                              0x300A0290UL   
#define TAG_SOURCE_APPLICATOR_ID                                                                  0x300A0291UL   
#define TAG_SOURCE_APPLICATOR_TYPE                                                                0x300A0292UL   
#define TAG_SOURCE_APPLICATOR_NAME                                                                0x300A0294UL   
#define TAG_SOURCE_APPLICATOR_LENGTH                                                              0x300A0296UL   
#define TAG_SOURCE_APPLICATOR_MANUFACTURER                                                        0x300A0298UL   
#define TAG_SOURCE_APPLICATOR_WALL_NOMINAL_THICKNESS                                              0x300A029CUL   
#define TAG_SOURCE_APPLICATOR_WALL_NOMINAL_TRANSMISSION                                           0x300A029EUL   
#define TAG_SOURCE_APPLICATOR_STEP_SIZE                                                           0x300A02A0UL   
#define TAG_TRANSFER_TUBE_NUMBER                                                                  0x300A02A2UL   
#define TAG_TRANSFER_TUBE_LENGTH                                                                  0x300A02A4UL   
#define TAG_CHANNEL_SHIELD_SEQUENCE                                                               0x300A02B0UL   
#define TAG_CHANNEL_SHIELD_NUMBER                                                                 0x300A02B2UL   
#define TAG_CHANNEL_SHIELD_ID                                                                     0x300A02B3UL   
#define TAG_CHANNEL_SHIELD_NAME                                                                   0x300A02B4UL   
#define TAG_CHANNEL_SHIELD_NOMINAL_THICKNESS                                                      0x300A02B8UL   
#define TAG_CHANNEL_SHIELD_NOMINAL_TRANSMISSION                                                   0x300A02BAUL   
#define TAG_FINAL_CUMULATIVE_TIME_WEIGHT                                                          0x300A02C8UL   
#define TAG_BRACHY_CONTROL_POINT_SEQUENCE                                                         0x300A02D0UL   
#define TAG_CONTROL_POINT_RELATIVE_POSITION                                                       0x300A02D2UL   
#define TAG_CONTROL_POINT_3D_POSITION                                                             0x300A02D4UL   
#define TAG_CUMULATIVE_TIME_WEIGHT                                                                0x300A02D6UL   
#define TAG_COMPENSATOR_DIVERGENCE                                                                0x300A02E0UL   
#define TAG_COMPENSATOR_MOUNTING_POSITION                                                         0x300A02E1UL   
#define TAG_SOURCE_TO_COMPENSATOR_DISTANCE                                                        0x300A02E2UL   
#define TAG_TOTAL_COMPENSATOR_TRAY_WATER_EQUIVALENT_THICKNESS                                     0x300A02E3UL   
#define TAG_ISOCENTER_TO_COMPENSATOR_TRAY_DISTANCE                                                0x300A02E4UL   
#define TAG_COMPENSATOR_COLUMN_OFFSET                                                             0x300A02E5UL   
#define TAG_ISOCENTER_TO_COMPENSATOR_DISTANCES                                                    0x300A02E6UL   
#define TAG_COMPENSATOR_RELATIVE_STOPPING_POWER_RATIO                                             0x300A02E7UL   
#define TAG_COMPENSATOR_MILLING_TOOL_DIAMETER                                                     0x300A02E8UL   
#define TAG_ION_RANGE_COMPENSATOR_SEQUENCE                                                        0x300A02EAUL   
#define TAG_COMPENSATOR_DESCRIPTION                                                               0x300A02EBUL   
#define TAG_RADIATION_MASS_NUMBER                                                                 0x300A0302UL   
#define TAG_RADIATION_ATOMIC_NUMBER                                                               0x300A0304UL   
#define TAG_RADIATION_CHARGE_STATE                                                                0x300A0306UL   
#define TAG_SCAN_MODE                                                                             0x300A0308UL   
#define TAG_MODULATED_SCAN_MODE_TYPE                                                              0x300A0309UL   
#define TAG_VIRTUAL_SOURCE_AXIS_DISTANCES                                                         0x300A030AUL   
#define TAG_SNOUT_SEQUENCE                                                                        0x300A030CUL   
#define TAG_SNOUT_POSITION                                                                        0x300A030DUL   
#define TAG_SNOUT_ID                                                                              0x300A030FUL   
#define TAG_NUMBER_OF_RANGE_SHIFTERS                                                              0x300A0312UL   
#define TAG_RANGE_SHIFTER_SEQUENCE                                                                0x300A0314UL   
#define TAG_RANGE_SHIFTER_NUMBER                                                                  0x300A0316UL   
#define TAG_RANGE_SHIFTER_ID                                                                      0x300A0318UL   
#define TAG_RANGE_SHIFTER_TYPE                                                                    0x300A0320UL   
#define TAG_RANGE_SHIFTER_DESCRIPTION                                                             0x300A0322UL   
#define TAG_NUMBER_OF_LATERAL_SPREADING_DEVICES                                                   0x300A0330UL   
#define TAG_LATERAL_SPREADING_DEVICE_SEQUENCE                                                     0x300A0332UL   
#define TAG_LATERAL_SPREADING_DEVICE_NUMBER                                                       0x300A0334UL   
#define TAG_LATERAL_SPREADING_DEVICE_ID                                                           0x300A0336UL   
#define TAG_LATERAL_SPREADING_DEVICE_TYPE                                                         0x300A0338UL   
#define TAG_LATERAL_SPREADING_DEVICE_DESCRIPTION                                                  0x300A033AUL   
#define TAG_LATERAL_SPREADING_DEVICE_WATER_EQUIVALENT_THICKNESS                                   0x300A033CUL   
#define TAG_NUMBER_OF_RANGE_MODULATORS                                                            0x300A0340UL   
#define TAG_RANGE_MODULATOR_SEQUENCE                                                              0x300A0342UL   
#define TAG_RANGE_MODULATOR_NUMBER                                                                0x300A0344UL   
#define TAG_RANGE_MODULATOR_ID                                                                    0x300A0346UL   
#define TAG_RANGE_MODULATOR_TYPE                                                                  0x300A0348UL   
#define TAG_RANGE_MODULATOR_DESCRIPTION                                                           0x300A034AUL   
#define TAG_BEAM_CURRENT_MODULATION_ID                                                            0x300A034CUL   
#define TAG_PATIENT_SUPPORT_TYPE                                                                  0x300A0350UL   
#define TAG_PATIENT_SUPPORT_ID                                                                    0x300A0352UL   
#define TAG_PATIENT_SUPPORT_ACCESSORY_CODE                                                        0x300A0354UL   
#define TAG_TRAY_ACCESSORY_CODE                                                                   0x300A0355UL   
#define TAG_FIXATION_LIGHT_AZIMUTHAL_ANGLE                                                        0x300A0356UL   
#define TAG_FIXATION_LIGHT_POLAR_ANGLE                                                            0x300A0358UL   
#define TAG_METERSET_RATE                                                                         0x300A035AUL   
#define TAG_RANGE_SHIFTER_SETTINGS_SEQUENCE                                                       0x300A0360UL   
#define TAG_RANGE_SHIFTER_SETTING                                                                 0x300A0362UL   
#define TAG_ISOCENTER_TO_RANGE_SHIFTER_DISTANCE                                                   0x300A0364UL   
#define TAG_RANGE_SHIFTER_WATER_EQUIVALENT_THICKNESS                                              0x300A0366UL   
#define TAG_LATERAL_SPREADING_DEVICE_SETTINGS_SEQUENCE                                            0x300A0370UL   
#define TAG_LATERAL_SPREADING_DEVICE_SETTING                                                      0x300A0372UL   
#define TAG_ISOCENTER_TO_LATERAL_SPREADING_DEVICE_DISTANCE                                        0x300A0374UL   
#define TAG_RANGE_MODULATOR_SETTINGS_SEQUENCE                                                     0x300A0380UL   
#define TAG_RANGE_MODULATOR_GATING_START_VALUE                                                    0x300A0382UL   
#define TAG_RANGE_MODULATOR_GATING_STOP_VALUE                                                     0x300A0384UL   
#define TAG_RANGE_MODULATOR_GATING_START_WATER_EQUIVALENT_THICKNESS                               0x300A0386UL   
#define TAG_RANGE_MODULATOR_GATING_STOP_WATER_EQUIVALENT_THICKNESS                                0x300A0388UL   
#define TAG_ISOCENTER_TO_RANGE_MODULATOR_DISTANCE                                                 0x300A038AUL   
#define TAG_SCAN_SPOT_TIME_OFFSET                                                                 0x300A038FUL   
#define TAG_SCAN_SPOT_TUNE_ID                                                                     0x300A0390UL   
#define TAG_SCAN_SPOT_PRESCRIBED_INDICES                                                          0x300A0391UL   
#define TAG_NUMBER_OF_SCAN_SPOT_POSITIONS                                                         0x300A0392UL   
#define TAG_SCAN_SPOT_REORDERED                                                                   0x300A0393UL   
#define TAG_SCAN_SPOT_POSITION_MAP                                                                0x300A0394UL   
#define TAG_SCAN_SPOT_REORDERING_ALLOWED                                                          0x300A0395UL   
#define TAG_SCAN_SPOT_METERSET_WEIGHTS                                                            0x300A0396UL   
#define TAG_SCANNING_SPOT_SIZE                                                                    0x300A0398UL   
#define TAG_SCAN_SPOT_SIZES_DELIVERED                                                             0x300A0399UL   
#define TAG_NUMBER_OF_PAINTINGS                                                                   0x300A039AUL   
#define TAG_ION_TOLERANCE_TABLE_SEQUENCE                                                          0x300A03A0UL   
#define TAG_ION_BEAM_SEQUENCE                                                                     0x300A03A2UL   
#define TAG_ION_BEAM_LIMITING_DEVICE_SEQUENCE                                                     0x300A03A4UL   
#define TAG_ION_BLOCK_SEQUENCE                                                                    0x300A03A6UL   
#define TAG_ION_CONTROL_POINT_SEQUENCE                                                            0x300A03A8UL   
#define TAG_ION_WEDGE_SEQUENCE                                                                    0x300A03AAUL   
#define TAG_ION_WEDGE_POSITION_SEQUENCE                                                           0x300A03ACUL   
#define TAG_REFERENCED_SETUP_IMAGE_SEQUENCE                                                       0x300A0401UL   
#define TAG_SETUP_IMAGE_COMMENT                                                                   0x300A0402UL   
#define TAG_MOTION_SYNCHRONIZATION_SEQUENCE                                                       0x300A0410UL   
#define TAG_CONTROL_POINT_ORIENTATION                                                             0x300A0412UL   
#define TAG_GENERAL_ACCESSORY_SEQUENCE                                                            0x300A0420UL   
#define TAG_GENERAL_ACCESSORY_ID                                                                  0x300A0421UL   
#define TAG_GENERAL_ACCESSORY_DESCRIPTION                                                         0x300A0422UL   
#define TAG_GENERAL_ACCESSORY_TYPE                                                                0x300A0423UL   
#define TAG_GENERAL_ACCESSORY_NUMBER                                                              0x300A0424UL   
#define TAG_SOURCE_TO_GENERAL_ACCESSORY_DISTANCE                                                  0x300A0425UL   
#define TAG_ISOCENTER_TO_GENERAL_ACCESSORY_DISTANCE                                               0x300A0426UL   
#define TAG_APPLICATOR_GEOMETRY_SEQUENCE                                                          0x300A0431UL   
#define TAG_APPLICATOR_APERTURE_SHAPE                                                             0x300A0432UL   
#define TAG_APPLICATOR_OPENING                                                                    0x300A0433UL   
#define TAG_APPLICATOR_OPENING_X                                                                  0x300A0434UL   
#define TAG_APPLICATOR_OPENING_Y                                                                  0x300A0435UL   
#define TAG_SOURCE_TO_APPLICATOR_MOUNTING_POSITION_DISTANCE                                       0x300A0436UL   
#define TAG_NUMBER_OF_BLOCK_SLAB_ITEMS                                                            0x300A0440UL   
#define TAG_BLOCK_SLAB_SEQUENCE                                                                   0x300A0441UL   
#define TAG_BLOCK_SLAB_THICKNESS                                                                  0x300A0442UL   
#define TAG_BLOCK_SLAB_NUMBER                                                                     0x300A0443UL   
#define TAG_DEVICE_MOTION_CONTROL_SEQUENCE                                                        0x300A0450UL   
#define TAG_DEVICE_MOTION_EXECUTION_MODE                                                          0x300A0451UL   
#define TAG_DEVICE_MOTION_OBSERVATION_MODE                                                        0x300A0452UL   
#define TAG_DEVICE_MOTION_PARAMETER_CODE_SEQUENCE                                                 0x300A0453UL   
#define TAG_DISTAL_DEPTH_FRACTION                                                                 0x300A0501UL   
#define TAG_DISTAL_DEPTH                                                                          0x300A0502UL   
#define TAG_NOMINAL_RANGE_MODULATION_FRACTIONS                                                    0x300A0503UL   
#define TAG_NOMINAL_RANGE_MODULATED_REGION_DEPTHS                                                 0x300A0504UL   
#define TAG_DEPTH_DOSE_PARAMETERS_SEQUENCE                                                        0x300A0505UL   
#define TAG_DELIVERED_DEPTH_DOSE_PARAMETERS_SEQUENCE                                              0x300A0506UL   
#define TAG_DELIVERED_DISTAL_DEPTH_FRACTION                                                       0x300A0507UL   
#define TAG_DELIVERED_DISTAL_DEPTH                                                                0x300A0508UL   
#define TAG_DELIVERED_NOMINAL_RANGE_MODULATION_FRACTIONS                                          0x300A0509UL   
#define TAG_DELIVERED_NOMINAL_RANGE_MODULATED_REGION_DEPTHS                                       0x300A0510UL   
#define TAG_DELIVERED_REFERENCE_DOSE_DEFINITION                                                   0x300A0511UL   
#define TAG_REFERENCE_DOSE_DEFINITION                                                             0x300A0512UL   
#define TAG_RT_CONTROL_POINT_INDEX                                                                0x300A0600UL   
#define TAG_RADIATION_GENERATION_MODE_INDEX                                                       0x300A0601UL   
#define TAG_REFERENCED_DEFINED_DEVICE_INDEX                                                       0x300A0602UL   
#define TAG_RADIATION_DOSE_IDENTIFICATION_INDEX                                                   0x300A0603UL   
#define TAG_NUMBER_OF_RT_CONTROL_POINTS                                                           0x300A0604UL   
#define TAG_REFERENCED_RADIATION_GENERATION_MODE_INDEX                                            0x300A0605UL   
#define TAG_TREATMENT_POSITION_INDEX                                                              0x300A0606UL   
#define TAG_REFERENCED_DEVICE_INDEX                                                               0x300A0607UL   
#define TAG_TREATMENT_POSITION_GROUP_LABEL                                                        0x300A0608UL   
#define TAG_TREATMENT_POSITION_GROUP_UID                                                          0x300A0609UL   
#define TAG_TREATMENT_POSITION_GROUP_SEQUENCE                                                     0x300A060AUL   
#define TAG_REFERENCED_TREATMENT_POSITION_INDEX                                                   0x300A060BUL   
#define TAG_REFERENCED_RADIATION_DOSE_IDENTIFICATION_INDEX                                        0x300A060CUL   
#define TAG_RT_ACCESSORY_HOLDER_WATER_EQUIVALENT_THICKNESS                                        0x300A060DUL   
#define TAG_REFERENCED_RT_ACCESSORY_HOLDER_DEVICE_INDEX                                           0x300A060EUL   
#define TAG_RT_ACCESSORY_HOLDER_SLOT_EXISTENCE_FLAG                                               0x300A060FUL   
#define TAG_RT_ACCESSORY_HOLDER_SLOT_SEQUENCE                                                     0x300A0610UL   
#define TAG_RT_ACCESSORY_HOLDER_SLOT_ID                                                           0x300A0611UL   
#define TAG_RT_ACCESSORY_HOLDER_SLOT_DISTANCE                                                     0x300A0612UL   
#define TAG_RT_ACCESSORY_SLOT_DISTANCE                                                            0x300A0613UL   
#define TAG_RT_ACCESSORY_HOLDER_DEFINITION_SEQUENCE                                               0x300A0614UL   
#define TAG_RT_ACCESSORY_DEVICE_SLOT_ID                                                           0x300A0615UL   
#define TAG_RT_RADIATION_SEQUENCE                                                                 0x300A0616UL   
#define TAG_RADIATION_DOSE_SEQUENCE                                                               0x300A0617UL   
#define TAG_RADIATION_DOSE_IDENTIFICATION_SEQUENCE                                                0x300A0618UL   
#define TAG_RADIATION_DOSE_IDENTIFICATION_LABEL                                                   0x300A0619UL   
#define TAG_REFERENCE_DOSE_TYPE                                                                   0x300A061AUL   
#define TAG_PRIMARY_DOSE_VALUE_INDICATOR                                                          0x300A061BUL   
#define TAG_DOSE_VALUES_SEQUENCE                                                                  0x300A061CUL   
#define TAG_DOSE_VALUE_PURPOSE                                                                    0x300A061DUL   
#define TAG_REFERENCE_DOSE_POINT_COORDINATES                                                      0x300A061EUL   
#define TAG_RADIATION_DOSE_VALUES_PARAMETERS_SEQUENCE                                             0x300A061FUL   
#define TAG_METERSET_TO_DOSE_MAPPING_SEQUENCE                                                     0x300A0620UL   
#define TAG_EXPECTED_IN_VIVO_MEASUREMENT_VALUES_SEQUENCE                                          0x300A0621UL   
#define TAG_EXPECTED_IN_VIVO_MEASUREMENT_VALUE_INDEX                                              0x300A0622UL   
#define TAG_RADIATION_DOSE_IN_VIVO_MEASUREMENT_LABEL                                              0x300A0623UL   
#define TAG_RADIATION_DOSE_CENTRAL_AXIS_DISPLACEMENT                                              0x300A0624UL   
#define TAG_RADIATION_DOSE_VALUE                                                                  0x300A0625UL   
#define TAG_RADIATION_DOSE_SOURCE_TO_SKIN_DISTANCE                                                0x300A0626UL   
#define TAG_RADIATION_DOSE_MEASUREMENT_POINT_COORDINATES                                          0x300A0627UL   
#define TAG_RADIATION_DOSE_SOURCE_TO_EXTERNAL_CONTOUR_DISTANCE                                    0x300A0628UL   
#define TAG_RT_TOLERANCE_SET_SEQUENCE                                                             0x300A0629UL   
#define TAG_RT_TOLERANCE_SET_LABEL                                                                0x300A062AUL   
#define TAG_ATTRIBUTE_TOLERANCE_VALUES_SEQUENCE                                                   0x300A062BUL   
#define TAG_TOLERANCE_VALUE                                                                       0x300A062CUL   
#define TAG_PATIENT_SUPPORT_POSITION_TOLERANCE_SEQUENCE                                           0x300A062DUL   
#define TAG_TREATMENT_TIME_LIMIT                                                                  0x300A062EUL   
#define TAG_C_ARM_PHOTON_ELECTRON_CONTROL_POINT_SEQUENCE                                          0x300A062FUL   
#define TAG_REFERENCED_RT_RADIATION_SEQUENCE                                                      0x300A0630UL   
#define TAG_REFERENCED_RT_INSTANCE_SEQUENCE                                                       0x300A0631UL   
#define TAG_REFERENCED_RT_PATIENT_SETUP_SEQUENCE                                                  0x300A0632UL   
#define TAG_SOURCE_TO_PATIENT_SURFACE_DISTANCE                                                    0x300A0634UL   
#define TAG_TREATMENT_MACHINE_SPECIAL_MODE_CODE_SEQUENCE                                          0x300A0635UL   
#define TAG_INTENDED_NUMBER_OF_FRACTIONS                                                          0x300A0636UL   
#define TAG_RT_RADIATION_SET_INTENT                                                               0x300A0637UL   
#define TAG_RT_RADIATION_PHYSICAL_AND_GEOMETRIC_CONTENT_DETAIL_FLAG                               0x300A0638UL   
#define TAG_RT_RECORD_FLAG                                                                        0x300A0639UL   
#define TAG_TREATMENT_DEVICE_IDENTIFICATION_SEQUENCE                                              0x300A063AUL   
#define TAG_REFERENCED_RT_PHYSICIAN_INTENT_SEQUENCE                                               0x300A063BUL   
#define TAG_CUMULATIVE_METERSET                                                                   0x300A063CUL   
#define TAG_DELIVERY_RATE                                                                         0x300A063DUL   
#define TAG_DELIVERY_RATE_UNIT_SEQUENCE                                                           0x300A063EUL   
#define TAG_TREATMENT_POSITION_SEQUENCE                                                           0x300A063FUL   
#define TAG_RADIATION_SOURCE_AXIS_DISTANCE                                                        0x300A0640UL   
#define TAG_NUMBER_OF_RT_BEAM_LIMITING_DEVICES                                                    0x300A0641UL   
#define TAG_RT_BEAM_LIMITING_DEVICE_PROXIMAL_DISTANCE                                             0x300A0642UL   
#define TAG_RT_BEAM_LIMITING_DEVICE_DISTAL_DISTANCE                                               0x300A0643UL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_DEVICE_ORIENTATION_LABEL_CODE_SEQUENCE                     0x300A0644UL   
#define TAG_BEAM_MODIFIER_ORIENTATION_ANGLE                                                       0x300A0645UL   
#define TAG_FIXED_RT_BEAM_DELIMITER_DEVICE_SEQUENCE                                               0x300A0646UL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_DEVICE_SEQUENCE                                            0x300A0647UL   
#define TAG_NUMBER_OF_PARALLEL_RT_BEAM_DELIMITERS                                                 0x300A0648UL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_BOUNDARIES                                                 0x300A0649UL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_POSITIONS                                                  0x300A064AUL   
#define TAG_RT_BEAM_LIMITING_DEVICE_OFFSET                                                        0x300A064BUL   
#define TAG_RT_BEAM_DELIMITER_GEOMETRY_SEQUENCE                                                   0x300A064CUL   
#define TAG_RT_BEAM_LIMITING_DEVICE_DEFINITION_SEQUENCE                                           0x300A064DUL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_OPENING_MODE                                               0x300A064EUL   
#define TAG_PARALLEL_RT_BEAM_DELIMITER_LEAF_MOUNTING_SIDE                                         0x300A064FUL   
#define TAG_PATIENT_SETUP_UID                                                                     0x300A0650UL   
#define TAG_WEDGE_DEFINITION_SEQUENCE                                                             0x300A0651UL   
#define TAG_RADIATION_BEAM_WEDGE_ANGLE                                                            0x300A0652UL   
#define TAG_RADIATION_BEAM_WEDGE_THIN_EDGE_DISTANCE                                               0x300A0653UL   
#define TAG_RADIATION_BEAM_EFFECTIVE_WEDGE_ANGLE                                                  0x300A0654UL   
#define TAG_NUMBER_OF_WEDGE_POSITIONS                                                             0x300A0655UL   
#define TAG_RT_BEAM_LIMITING_DEVICE_OPENING_SEQUENCE                                              0x300A0656UL   
#define TAG_NUMBER_OF_RT_BEAM_LIMITING_DEVICE_OPENINGS                                            0x300A0657UL   
#define TAG_RADIATION_DOSIMETER_UNIT_SEQUENCE                                                     0x300A0658UL   
#define TAG_RT_DEVICE_DISTANCE_REFERENCE_LOCATION_CODE_SEQUENCE                                   0x300A0659UL   
#define TAG_RADIATION_DEVICE_CONFIGURATION_AND_COMMISSIONING_KEY_SEQUENCE                         0x300A065AUL   
#define TAG_PATIENT_SUPPORT_POSITION_PARAMETER_SEQUENCE                                           0x300A065BUL   
#define TAG_PATIENT_SUPPORT_POSITION_SPECIFICATION_METHOD                                         0x300A065CUL   
#define TAG_PATIENT_SUPPORT_POSITION_DEVICE_PARAMETER_SEQUENCE                                    0x300A065DUL   
#define TAG_DEVICE_ORDER_INDEX                                                                    0x300A065EUL   
#define TAG_PATIENT_SUPPORT_POSITION_PARAMETER_ORDER_INDEX                                        0x300A065FUL   
#define TAG_PATIENT_SUPPORT_POSITION_DEVICE_TOLERANCE_SEQUENCE                                    0x300A0660UL   
#define TAG_PATIENT_SUPPORT_POSITION_TOLERANCE_ORDER_INDEX                                        0x300A0661UL   
#define TAG_COMPENSATOR_DEFINITION_SEQUENCE                                                       0x300A0662UL   
#define TAG_COMPENSATOR_MAP_ORIENTATION                                                           0x300A0663UL   
#define TAG_COMPENSATOR_PROXIMAL_THICKNESS_MAP                                                    0x300A0664UL   
#define TAG_COMPENSATOR_DISTAL_THICKNESS_MAP                                                      0x300A0665UL   
#define TAG_COMPENSATOR_BASE_PLANE_OFFSET                                                         0x300A0666UL   
#define TAG_COMPENSATOR_SHAPE_FABRICATION_CODE_SEQUENCE                                           0x300A0667UL   
#define TAG_COMPENSATOR_SHAPE_SEQUENCE                                                            0x300A0668UL   
#define TAG_RADIATION_BEAM_COMPENSATOR_MILLING_TOOL_DIAMETER                                      0x300A0669UL   
#define TAG_BLOCK_DEFINITION_SEQUENCE                                                             0x300A066AUL   
#define TAG_BLOCK_EDGE_DATA                                                                       0x300A066BUL   
#define TAG_BLOCK_ORIENTATION                                                                     0x300A066CUL   
#define TAG_RADIATION_BEAM_BLOCK_THICKNESS                                                        0x300A066DUL   
#define TAG_RADIATION_BEAM_BLOCK_SLAB_THICKNESS                                                   0x300A066EUL   
#define TAG_BLOCK_EDGE_DATA_SEQUENCE                                                              0x300A066FUL   
#define TAG_NUMBER_OF_RT_ACCESSORY_HOLDERS                                                        0x300A0670UL   
#define TAG_GENERAL_ACCESSORY_DEFINITION_SEQUENCE                                                 0x300A0671UL   
#define TAG_NUMBER_OF_GENERAL_ACCESSORIES                                                         0x300A0672UL   
#define TAG_BOLUS_DEFINITION_SEQUENCE                                                             0x300A0673UL   
#define TAG_NUMBER_OF_BOLUSES                                                                     0x300A0674UL   
#define TAG_EQUIPMENT_FRAME_OF_REFERENCE_UID                                                      0x300A0675UL   
#define TAG_EQUIPMENT_FRAME_OF_REFERENCE_DESCRIPTION                                              0x300A0676UL   
#define TAG_EQUIPMENT_REFERENCE_POINT_COORDINATES_SEQUENCE                                        0x300A0677UL   
#define TAG_EQUIPMENT_REFERENCE_POINT_CODE_SEQUENCE                                               0x300A0678UL   
#define TAG_RT_BEAM_LIMITING_DEVICE_ANGLE                                                         0x300A0679UL   
#define TAG_SOURCE_ROLL_ANGLE                                                                     0x300A067AUL   
#define TAG_RADIATION_GENERATIONMODE_SEQUENCE                                                     0x300A067BUL   
#define TAG_RADIATION_GENERATIONMODE_LABEL                                                        0x300A067CUL   
#define TAG_RADIATION_GENERATIONMODE_DESCRIPTION                                                  0x300A067DUL   
#define TAG_RADIATION_GENERATIONMODE_MACHINE_CODE_SEQUENCE                                        0x300A067EUL   
#define TAG_RADIATION_TYPE_CODE_SEQUENCE                                                          0x300A067FUL   
#define TAG_NOMINAL_ENERGY                                                                        0x300A0680UL   
#define TAG_MINIMUM_NOMINAL_ENERGY                                                                0x300A0681UL   
#define TAG_MAXIMUM_NOMINAL_ENERGY                                                                0x300A0682UL   
#define TAG_RADIATION_FLUENCE_MODIFIER_CODE_SEQUENCE                                              0x300A0683UL   
#define TAG_ENERGY_UNIT_CODE_SEQUENCE                                                             0x300A0684UL   
#define TAG_NUMBER_OF_RADIATION_GENERATIONMODES                                                   0x300A0685UL   
#define TAG_PATIENT_SUPPORT_DEVICES_SEQUENCE                                                      0x300A0686UL   
#define TAG_NUMBER_OF_PATIENT_SUPPORT_DEVICES                                                     0x300A0687UL   
#define TAG_RT_BEAM_MODIFIER_DEFINITION_DISTANCE                                                  0x300A0688UL   
#define TAG_BEAM_AREA_LIMIT_SEQUENCE                                                              0x300A0689UL   
#define TAG_REFERENCED_RT_PRESCRIPTION_SEQUENCE                                                   0x300A068AUL   
#define TAG_TREATMENT_SESSION_UID                                                                 0x300A0700UL   
#define TAG_RT_RADIATION_USAGE                                                                    0x300A0701UL   
#define TAG_REFERENCED_RT_RADIATION_SET_SEQUENCE                                                  0x300A0702UL   
#define TAG_REFERENCED_RT_RADIATION_RECORD_SEQUENCE                                               0x300A0703UL   
#define TAG_RT_RADIATION_SET_DELIVERY_NUMBER                                                      0x300A0704UL   
#define TAG_CLINICAL_FRACTION_NUMBER                                                              0x300A0705UL   
#define TAG_RT_TREATMENT_FRACTION_COMPLETION_STATUS                                               0x300A0706UL   
#define TAG_RT_RADIATION_SET_USAGE                                                                0x300A0707UL   
#define TAG_TREATMENT_DELIVERY_CONTINUATION_FLAG                                                  0x300A0708UL   
#define TAG_TREATMENT_RECORD_CONTENT_ORIGIN                                                       0x300A0709UL   
#define TAG_RT_TREATMENT_TERMINATION_STATUS                                                       0x300A0714UL   
#define TAG_RT_TREATMENT_TERMINATION_REASON_CODE_SEQUENCE                                         0x300A0715UL   
#define TAG_MACHINE_SPECIFIC_TREATMENT_TERMINATION_CODE_SEQUENCE                                  0x300A0716UL   
#define TAG_RT_RADIATION_SALVAGE_RECORD_CONTROL_POINT_SEQUENCE                                    0x300A0722UL   
#define TAG_STARTING_METERSET_VALUE_KNOWN_FLAG                                                    0x300A0723UL   
#define TAG_TREATMENT_TERMINATION_DESCRIPTION                                                     0x300A0730UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_SEQUENCE                                                0x300A0731UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_CATEGORY                                                0x300A0732UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_ATTRIBUTE_SEQUENCE                                      0x300A0733UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_DESCRIPTION                                             0x300A0734UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_IDENTIFICATION                                          0x300A0735UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_DATETIME                                                0x300A0736UL   
#define TAG_RECORDED_RT_CONTROL_POINT_DATETIME                                                    0x300A073AUL   
#define TAG_REFERENCED_RADIATION_RT_CONTROL_POINT_INDEX                                           0x300A073BUL   
#define TAG_ALTERNATE_VALUE_SEQUENCE                                                              0x300A073EUL   
#define TAG_CONFIRMATION_SEQUENCE                                                                 0x300A073FUL   
#define TAG_INTERLOCK_SEQUENCE                                                                    0x300A0740UL   
#define TAG_INTERLOCK_DATETIME                                                                    0x300A0741UL   
#define TAG_INTERLOCK_DESCRIPTION                                                                 0x300A0742UL   
#define TAG_INTERLOCK_ORIGINATING_DEVICE_SEQUENCE                                                 0x300A0743UL   
#define TAG_INTERLOCK_CODE_SEQUENCE                                                               0x300A0744UL   
#define TAG_INTERLOCK_RESOLUTION_CODE_SEQUENCE                                                    0x300A0745UL   
#define TAG_INTERLOCK_RESOLUTION_USER_SEQUENCE                                                    0x300A0746UL   
#define TAG_OVERRIDE_DATETIME                                                                     0x300A0760UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_TYPE_CODE_SEQUENCE                                      0x300A0761UL   
#define TAG_TREATMENT_TOLERANCE_VIOLATION_CAUSE_CODE_SEQUENCE                                     0x300A0762UL   
#define TAG_MEASURED_METERSET_TO_DOSE_MAPPING_SEQUENCE                                            0x300A0772UL   
#define TAG_REFERENCED_EXPECTED_IN_VIVO_MEASUREMENT_VALUE_INDEX                                   0x300A0773UL   
#define TAG_DOSE_MEASUREMENT_DEVICE_CODE_SEQUENCE                                                 0x300A0774UL   
#define TAG_ADDITIONAL_PARAMETER_RECORDING_INSTANCE_SEQUENCE                                      0x300A0780UL   
#define TAG_INTERLOCK_ORIGIN_DESCRIPTION                                                          0x300A0783UL   

// *****************************************************************************************************************************
// *** 300C
// *****************************************************************************************************************************
#define TAG_REFERENCED_RT_PLAN_SEQUENCE                                                           0x300C0002UL   
#define TAG_REFERENCED_BEAM_SEQUENCE                                                              0x300C0004UL   
#define TAG_REFERENCED_BEAM_NUMBER                                                                0x300C0006UL   
#define TAG_REFERENCED_REFERENCE_IMAGE_NUMBER                                                     0x300C0007UL   
#define TAG_START_CUMULATIVE_METERSET_WEIGHT                                                      0x300C0008UL   
#define TAG_END_CUMULATIVE_METERSET_WEIGHT                                                        0x300C0009UL   
#define TAG_REFERENCED_BRACHY_APPLICATION_SETUP_SEQUENCE                                          0x300C000AUL   
#define TAG_REFERENCED_BRACHY_APPLICATION_SETUP_NUMBER                                            0x300C000CUL   
#define TAG_REFERENCED_SOURCE_NUMBER                                                              0x300C000EUL   
#define TAG_REFERENCED_FRACTION_GROUP_SEQUENCE                                                    0x300C0020UL   
#define TAG_REFERENCED_FRACTION_GROUP_NUMBER                                                      0x300C0022UL   
#define TAG_REFERENCED_VERIFICATION_IMAGE_SEQUENCE                                                0x300C0040UL   
#define TAG_REFERENCED_REFERENCE_IMAGE_SEQUENCE                                                   0x300C0042UL   
#define TAG_REFERENCED_DOSE_REFERENCE_SEQUENCE                                                    0x300C0050UL   
#define TAG_REFERENCED_DOSE_REFERENCE_NUMBER                                                      0x300C0051UL   
#define TAG_BRACHY_REFERENCED_DOSE_REFERENCE_SEQUENCE                                             0x300C0055UL   
#define TAG_REFERENCED_STRUCTURE_SET_SEQUENCE                                                     0x300C0060UL   
#define TAG_REFERENCED_PATIENT_SETUP_NUMBER                                                       0x300C006AUL   
#define TAG_REFERENCED_DOSE_SEQUENCE                                                              0x300C0080UL   
#define TAG_REFERENCED_TOLERANCE_TABLE_NUMBER                                                     0x300C00A0UL   
#define TAG_REFERENCED_BOLUS_SEQUENCE                                                             0x300C00B0UL   
#define TAG_REFERENCED_WEDGE_NUMBER                                                               0x300C00C0UL   
#define TAG_REFERENCED_COMPENSATOR_NUMBER                                                         0x300C00D0UL   
#define TAG_REFERENCED_BLOCK_NUMBER                                                               0x300C00E0UL   
#define TAG_REFERENCED_CONTROL_POINT_INDEX                                                        0x300C00F0UL   
#define TAG_REFERENCED_CONTROL_POINT_SEQUENCE                                                     0x300C00F2UL   
#define TAG_REFERENCED_START_CONTROL_POINT_INDEX                                                  0x300C00F4UL   
#define TAG_REFERENCED_STOP_CONTROL_POINT_INDEX                                                   0x300C00F6UL   
#define TAG_REFERENCED_RANGE_SHIFTER_NUMBER                                                       0x300C0100UL   
#define TAG_REFERENCED_LATERAL_SPREADING_DEVICE_NUMBER                                            0x300C0102UL   
#define TAG_REFERENCED_RANGE_MODULATOR_NUMBER                                                     0x300C0104UL   
#define TAG_OMITTED_BEAM_TASK_SEQUENCE                                                            0x300C0111UL   
#define TAG_REASON_FOR_OMISSION                                                                   0x300C0112UL   
#define TAG_REASON_FOR_OMISSION_DESCRIPTION                                                       0x300C0113UL   

// *****************************************************************************************************************************
// *** 300E
// *****************************************************************************************************************************
#define TAG_APPROVAL_STATUS                                                                       0x300E0002UL   
#define TAG_REVIEW_DATE                                                                           0x300E0004UL   
#define TAG_REVIEW_TIME                                                                           0x300E0005UL   
#define TAG_REVIEWER_NAME                                                                         0x300E0008UL   

// *****************************************************************************************************************************
// *** 3010
// *****************************************************************************************************************************
#define TAG_RADIOBIOLOGICAL_DOSE_EFFECT_SEQUENCE                                                  0x30100001UL   
#define TAG_RADIOBIOLOGICAL_DOSE_EFFECT_FLAG                                                      0x30100002UL   
#define TAG_EFFECTIVE_DOSE_CALCULATION_METHOD_CATEGORY_CODE_SEQUENCE                              0x30100003UL   
#define TAG_EFFECTIVE_DOSE_CALCULATION_METHOD_CODE_SEQUENCE                                       0x30100004UL   
#define TAG_EFFECTIVE_DOSE_CALCULATION_METHOD_DESCRIPTION                                         0x30100005UL   
#define TAG_CONCEPTUAL_VOLUME_UID                                                                 0x30100006UL   
#define TAG_ORIGINATING_SOP_INSTANCE_REFERENCE_SEQUENCE                                           0x30100007UL   
#define TAG_CONCEPTUAL_VOLUME_CONSTITUENT_SEQUENCE                                                0x30100008UL   
#define TAG_EQUIVALENT_CONCEPTUAL_VOLUME_INSTANCE_REFERENCE_SEQUENCE                              0x30100009UL   
#define TAG_EQUIVALENT_CONCEPTUAL_VOLUMES_SEQUENCE                                                0x3010000AUL   
#define TAG_REFERENCED_CONCEPTUAL_VOLUME_UID                                                      0x3010000BUL   
#define TAG_CONCEPTUAL_VOLUME_COMBINATION_EXPRESSION                                              0x3010000CUL   
#define TAG_CONCEPTUAL_VOLUME_CONSTITUENT_INDEX                                                   0x3010000DUL   
#define TAG_CONCEPTUAL_VOLUME_COMBINATION_FLAG                                                    0x3010000EUL   
#define TAG_CONCEPTUAL_VOLUME_COMBINATION_DESCRIPTION                                             0x3010000FUL   
#define TAG_CONCEPTUAL_VOLUME_SEGMENTATION_DEFINED_FLAG                                           0x30100010UL   
#define TAG_CONCEPTUAL_VOLUME_SEGMENTATION_REFERENCE_SEQUENCE                                     0x30100011UL   
#define TAG_CONCEPTUAL_VOLUME_CONSTITUENT_SEGMENTATION_REFERENCE_SEQUENCE                         0x30100012UL   
#define TAG_CONSTITUENT_CONCEPTUAL_VOLUME_UID                                                     0x30100013UL   
#define TAG_DERIVATION_CONCEPTUAL_VOLUME_SEQUENCE                                                 0x30100014UL   
#define TAG_SOURCE_CONCEPTUAL_VOLUME_UID                                                          0x30100015UL   
#define TAG_CONCEPTUAL_VOLUME_DERIVATION_ALGORITHM_SEQUENCE                                       0x30100016UL   
#define TAG_CONCEPTUAL_VOLUME_DESCRIPTION                                                         0x30100017UL   
#define TAG_SOURCE_CONCEPTUAL_VOLUME_SEQUENCE                                                     0x30100018UL   
#define TAG_AUTHOR_IDENTIFICATION_SEQUENCE                                                        0x30100019UL   
#define TAG_MANUFACTURER_MODEL_VERSION                                                            0x3010001AUL   
#define TAG_DEVICE_ALTERNATE_IDENTIFIER                                                           0x3010001BUL   
#define TAG_DEVICE_ALTERNATE_IDENTIFIER_TYPE                                                      0x3010001CUL   
#define TAG_DEVICE_ALTERNATE_IDENTIFIER_FORMAT                                                    0x3010001DUL   
#define TAG_SEGMENTATION_CREATION_TEMPLATE_LABEL                                                  0x3010001EUL   
#define TAG_SEGMENTATION_TEMPLATE_UID                                                             0x3010001FUL   
#define TAG_REFERENCED_SEGMENT_REFERENCE_INDEX                                                    0x30100020UL   
#define TAG_SEGMENT_REFERENCE_SEQUENCE                                                            0x30100021UL   
#define TAG_SEGMENT_REFERENCE_INDEX                                                               0x30100022UL   
#define TAG_DIRECT_SEGMENT_REFERENCE_SEQUENCE                                                     0x30100023UL   
#define TAG_COMBINATION_SEGMENT_REFERENCE_SEQUENCE                                                0x30100024UL   
#define TAG_CONCEPTUAL_VOLUME_SEQUENCE                                                            0x30100025UL   
#define TAG_SEGMENTED_RT_ACCESSORY_DEVICE_SEQUENCE                                                0x30100026UL   
#define TAG_SEGMENT_CHARACTERISTICS_SEQUENCE                                                      0x30100027UL   
#define TAG_RELATED_SEGMENT_CHARACTERISTICS_SEQUENCE                                              0x30100028UL   
#define TAG_SEGMENT_CHARACTERISTICS_PRECEDENCE                                                    0x30100029UL   
#define TAG_RT_SEGMENT_ANNOTATION_SEQUENCE                                                        0x3010002AUL   
#define TAG_SEGMENT_ANNOTATION_CATEGORY_CODE_SEQUENCE                                             0x3010002BUL   
#define TAG_SEGMENT_ANNOTATION_TYPE_CODE_SEQUENCE                                                 0x3010002CUL   
#define TAG_DEVICE_LABEL                                                                          0x3010002DUL   
#define TAG_DEVICE_TYPE_CODE_SEQUENCE                                                             0x3010002EUL   
#define TAG_SEGMENT_ANNOTATION_TYPE_MODIFIER_CODE_SEQUENCE                                        0x3010002FUL   
#define TAG_PATIENT_EQUIPMENT_RELATIONSHIP_CODE_SEQUENCE                                          0x30100030UL   
#define TAG_REFERENCED_FIDUCIALS_UID                                                              0x30100031UL   
#define TAG_PATIENT_TREATMENT_ORIENTATION_SEQUENCE                                                0x30100032UL   
#define TAG_USER_CONTENT_LABEL                                                                    0x30100033UL   
#define TAG_USER_CONTENT_LONG_LABEL                                                               0x30100034UL   
#define TAG_ENTITY_LABEL                                                                          0x30100035UL   
#define TAG_ENTITY_NAME                                                                           0x30100036UL   
#define TAG_ENTITY_DESCRIPTION                                                                    0x30100037UL   
#define TAG_ENTITY_LONG_LABEL                                                                     0x30100038UL   
#define TAG_DEVICE_INDEX                                                                          0x30100039UL   
#define TAG_RT_TREATMENT_PHASE_INDEX                                                              0x3010003AUL   
#define TAG_RT_TREATMENT_PHASE_UID                                                                0x3010003BUL   
#define TAG_RT_PRESCRIPTION_INDEX                                                                 0x3010003CUL   
#define TAG_RT_SEGMENT_ANNOTATION_INDEX                                                           0x3010003DUL   
#define TAG_BASIS_RT_TREATMENT_PHASE_INDEX                                                        0x3010003EUL   
#define TAG_RELATED_RT_TREATMENT_PHASE_INDEX                                                      0x3010003FUL   
#define TAG_REFERENCED_RT_TREATMENT_PHASE_INDEX                                                   0x30100040UL   
#define TAG_REFERENCED_RT_PRESCRIPTION_INDEX                                                      0x30100041UL   
#define TAG_REFERENCED_PARENT_RT_PRESCRIPTION_INDEX                                               0x30100042UL   
#define TAG_MANUFACTURER_DEVICE_IDENTIFIER                                                        0x30100043UL   
#define TAG_INSTANCE_LEVEL_REFERENCED_PERFORMED_PROCEDURE_STEP_SEQUENCE                           0x30100044UL   
#define TAG_RT_TREATMENT_PHASE_INTENT_PRESENCE_FLAG                                               0x30100045UL   
#define TAG_RADIOTHERAPY_TREATMENT_TYPE                                                           0x30100046UL   
#define TAG_TELETHERAPY_RADIATION_TYPE                                                            0x30100047UL   
#define TAG_BRACHYTHERAPY_SOURCE_TYPE                                                             0x30100048UL   
#define TAG_REFERENCED_RT_TREATMENT_PHASE_SEQUENCE                                                0x30100049UL   
#define TAG_REFERENCED_DIRECT_SEGMENT_INSTANCE_SEQUENCE                                           0x3010004AUL   
#define TAG_INTENDED_RT_TREATMENT_PHASE_SEQUENCE                                                  0x3010004BUL   
#define TAG_INTENDED_PHASE_START_DATE                                                             0x3010004CUL   
#define TAG_INTENDED_PHASE_END_DATE                                                               0x3010004DUL   
#define TAG_RT_TREATMENT_PHASE_INTERVAL_SEQUENCE                                                  0x3010004EUL   
#define TAG_TEMPORAL_RELATIONSHIP_INTERVAL_ANCHOR                                                 0x3010004FUL   
#define TAG_MINIMUM_NUMBER_OF_INTERVAL_DAYS                                                       0x30100050UL   
#define TAG_MAXIMUM_NUMBER_OF_INTERVAL_DAYS                                                       0x30100051UL   
#define TAG_PERTINENT_SOP_CLASSES_IN_STUDY                                                        0x30100052UL   
#define TAG_PERTINENT_SOP_CLASSES_IN_SERIES                                                       0x30100053UL   
#define TAG_RT_PRESCRIPTION_LABEL                                                                 0x30100054UL   
#define TAG_RT_PHYSICIAN_INTENT_PREDECESSOR_SEQUENCE                                              0x30100055UL   
#define TAG_RT_TREATMENT_APPROACH_LABEL                                                           0x30100056UL   
#define TAG_RT_PHYSICIAN_INTENT_SEQUENCE                                                          0x30100057UL   
#define TAG_RT_PHYSICIAN_INTENT_INDEX                                                             0x30100058UL   
#define TAG_RT_TREATMENT_INTENT_TYPE                                                              0x30100059UL   
#define TAG_RT_PHYSICIAN_INTENT_NARRATIVE                                                         0x3010005AUL   
#define TAG_RT_PROTOCOL_CODE_SEQUENCE                                                             0x3010005BUL   
#define TAG_REASON_FOR_SUPERSEDING                                                                0x3010005CUL   
#define TAG_RT_DIAGNOSIS_CODE_SEQUENCE                                                            0x3010005DUL   
#define TAG_REFERENCED_RT_PHYSICIAN_INTENT_INDEX                                                  0x3010005EUL   
#define TAG_RT_PHYSICIAN_INTENT_INPUT_INSTANCE_SEQUENCE                                           0x3010005FUL   
#define TAG_RT_ANATOMIC_PRESCRIPTION_SEQUENCE                                                     0x30100060UL   
#define TAG_PRIOR_TREATMENT_DOSE_DESCRIPTION                                                      0x30100061UL   
#define TAG_PRIOR_TREATMENT_REFERENCE_SEQUENCE                                                    0x30100062UL   
#define TAG_DOSIMETRIC_OBJECTIVE_EVALUATION_SCOPE                                                 0x30100063UL   
#define TAG_THERAPEUTIC_ROLE_CATEGORY_CODE_SEQUENCE                                               0x30100064UL   
#define TAG_THERAPEUTIC_ROLE_TYPE_CODE_SEQUENCE                                                   0x30100065UL   
#define TAG_CONCEPTUAL_VOLUME_OPTIMIZATION_PRECEDENCE                                             0x30100066UL   
#define TAG_CONCEPTUAL_VOLUME_CATEGORY_CODE_SEQUENCE                                              0x30100067UL   
#define TAG_CONCEPTUAL_VOLUME_BLOCKING_CONSTRAINT                                                 0x30100068UL   
#define TAG_CONCEPTUAL_VOLUME_TYPE_CODE_SEQUENCE                                                  0x30100069UL   
#define TAG_CONCEPTUAL_VOLUME_TYPE_MODIFIER_CODE_SEQUENCE                                         0x3010006AUL   
#define TAG_RT_PRESCRIPTION_SEQUENCE                                                              0x3010006BUL   
#define TAG_DOSIMETRIC_OBJECTIVE_SEQUENCE                                                         0x3010006CUL   
#define TAG_DOSIMETRIC_OBJECTIVE_TYPE_CODE_SEQUENCE                                               0x3010006DUL   
#define TAG_DOSIMETRIC_OBJECTIVE_UID                                                              0x3010006EUL   
#define TAG_REFERENCED_DOSIMETRIC_OBJECTIVE_UID                                                   0x3010006FUL   
#define TAG_DOSIMETRIC_OBJECTIVE_PARAMETER_SEQUENCE                                               0x30100070UL   
#define TAG_REFERENCED_DOSIMETRIC_OBJECTIVES_SEQUENCE                                             0x30100071UL   
#define TAG_ABSOLUTE_DOSIMETRIC_OBJECTIVE_FLAG                                                    0x30100073UL   
#define TAG_DOSIMETRIC_OBJECTIVE_WEIGHT                                                           0x30100074UL   
#define TAG_DOSIMETRIC_OBJECTIVE_PURPOSE                                                          0x30100075UL   
#define TAG_PLANNING_INPUT_INFORMATION_SEQUENCE                                                   0x30100076UL   
#define TAG_TREATMENT_SITE                                                                        0x30100077UL   
#define TAG_TREATMENT_SITE_CODE_SEQUENCE                                                          0x30100078UL   
#define TAG_FRACTION_PATTERN_SEQUENCE                                                             0x30100079UL   
#define TAG_TREATMENT_TECHNIQUE_NOTES                                                             0x3010007AUL   
#define TAG_PRESCRIPTION_NOTES                                                                    0x3010007BUL   
#define TAG_NUMBER_OF_INTERVAL_FRACTIONS                                                          0x3010007CUL   
#define TAG_NUMBER_OF_FRACTIONS                                                                   0x3010007DUL   
#define TAG_INTENDED_DELIVERY_DURATION                                                            0x3010007EUL   
#define TAG_FRACTIONATION_NOTES                                                                   0x3010007FUL   
#define TAG_RT_TREATMENT_TECHNIQUE_CODE_SEQUENCE                                                  0x30100080UL   
#define TAG_PRESCRIPTION_NOTES_SEQUENCE                                                           0x30100081UL   
#define TAG_FRACTION_BASED_RELATIONSHIP_SEQUENCE                                                  0x30100082UL   
#define TAG_FRACTION_BASED_RELATIONSHIP_INTERVAL_ANCHOR                                           0x30100083UL   
#define TAG_MINIMUM_HOURS_BETWEEN_FRACTIONS                                                       0x30100084UL   
#define TAG_INTENDED_FRACTION_START_TIME                                                          0x30100085UL   
#define TAG_INTENDED_START_DAY_OF_WEEK                                                            0x30100086UL   
#define TAG_WEEKDAY_FRACTION_PATTERN_SEQUENCE                                                     0x30100087UL   
#define TAG_DELIVERY_TIME_STRUCTURE_CODE_SEQUENCE                                                 0x30100088UL   
#define TAG_TREATMENT_SITE_MODIFIER_CODE_SEQUENCE                                                 0x30100089UL   
#define TAG_ROBOTIC_BASE_LOCATION_INDICATOR                                                       0x30100090UL   
#define TAG_ROBOTIC_PATH_NODE_SET_CODE_SEQUENCE                                                   0x30100091UL   
#define TAG_ROBOTIC_NODE_IDENTIFIER                                                               0x30100092UL   
#define TAG_RT_TREATMENT_SOURCE_COORDINATES                                                       0x30100093UL   
#define TAG_RADIATION_SOURCE_COORDINATE_SYSTEMYAW_ANGLE                                           0x30100094UL   
#define TAG_RADIATION_SOURCE_COORDINATE_SYSTEMROLL_ANGLE                                          0x30100095UL   
#define TAG_RADIATION_SOURCE_COORDINATE_SYSTEM_PITCH_ANGLE                                        0x30100096UL   
#define TAG_ROBOTIC_PATH_CONTROL_POINT_SEQUENCE                                                   0x30100097UL   
#define TAG_TOMOTHERAPEUTIC_CONTROL_POINT_SEQUENCE                                                0x30100098UL   
#define TAG_TOMOTHERAPEUTIC_LEAF_OPEN_DURATIONS                                                   0x30100099UL   
#define TAG_TOMOTHERAPEUTIC_LEAF_INITIAL_CLOSED_DURATIONS                                         0x3010009AUL   

// *****************************************************************************************************************************
// *** 4000
// *****************************************************************************************************************************
#define TAG_ARBITRARY                                                                             0x40000010UL   // Retired
#define TAG_TEXT_COMMENTS                                                                         0x40004000UL   // Retired

// *****************************************************************************************************************************
// *** 4008
// *****************************************************************************************************************************
#define TAG_RESULTS_ID                                                                            0x40080040UL   // Retired
#define TAG_RESULTS_ID_ISSUER                                                                     0x40080042UL   // Retired
#define TAG_REFERENCED_INTERPRETATION_SEQUENCE                                                    0x40080050UL   // Retired
#define TAG_REPORT_PRODUCTION_STATUS_TRIAL                                                        0x400800FFUL   // Retired
#define TAG_INTERPRETATION_RECORDED_DATE                                                          0x40080100UL   // Retired
#define TAG_INTERPRETATION_RECORDED_TIME                                                          0x40080101UL   // Retired
#define TAG_INTERPRETATION_RECORDER                                                               0x40080102UL   // Retired
#define TAG_REFERENCE_TO_RECORDED_SOUND                                                           0x40080103UL   // Retired
#define TAG_INTERPRETATION_TRANSCRIPTION_DATE                                                     0x40080108UL   // Retired
#define TAG_INTERPRETATION_TRANSCRIPTION_TIME                                                     0x40080109UL   // Retired
#define TAG_INTERPRETATION_TRANSCRIBER                                                            0x4008010AUL   // Retired
#define TAG_INTERPRETATION_TEXT                                                                   0x4008010BUL   // Retired
#define TAG_INTERPRETATION_AUTHOR                                                                 0x4008010CUL   // Retired
#define TAG_INTERPRETATION_APPROVER_SEQUENCE                                                      0x40080111UL   // Retired
#define TAG_INTERPRETATION_APPROVAL_DATE                                                          0x40080112UL   // Retired
#define TAG_INTERPRETATION_APPROVAL_TIME                                                          0x40080113UL   // Retired
#define TAG_PHYSICIAN_APPROVING_INTERPRETATION                                                    0x40080114UL   // Retired
#define TAG_INTERPRETATION_DIAGNOSIS_DESCRIPTION                                                  0x40080115UL   // Retired
#define TAG_INTERPRETATION_DIAGNOSIS_CODE_SEQUENCE                                                0x40080117UL   // Retired
#define TAG_RESULTS_DISTRIBUTION_LIST_SEQUENCE                                                    0x40080118UL   // Retired
#define TAG_DISTRIBUTION_NAME                                                                     0x40080119UL   // Retired
#define TAG_DISTRIBUTION_ADDRESS                                                                  0x4008011AUL   // Retired
#define TAG_INTERPRETATION_ID                                                                     0x40080200UL   // Retired
#define TAG_INTERPRETATION_ID_ISSUER                                                              0x40080202UL   // Retired
#define TAG_INTERPRETATION_TYPE_ID                                                                0x40080210UL   // Retired
#define TAG_INTERPRETATION_STATUS_ID                                                              0x40080212UL   // Retired
#define TAG_IMPRESSIONS                                                                           0x40080300UL   // Retired
#define TAG_RESULTS_COMMENTS                                                                      0x40084000UL   // Retired

// *****************************************************************************************************************************
// *** 4010
// *****************************************************************************************************************************
#define TAG_LOW_ENERGY_DETECTORS                                                                  0x40100001UL   
#define TAG_HIGH_ENERGY_DETECTORS                                                                 0x40100002UL   
#define TAG_DETECTOR_GEOMETRY_SEQUENCE                                                            0x40100004UL   
#define TAG_THREAT_ROI_VOXEL_SEQUENCE                                                             0x40101001UL   
#define TAG_THREAT_ROI_BASE                                                                       0x40101004UL   
#define TAG_THREAT_ROI_EXTENTS                                                                    0x40101005UL   
#define TAG_THREAT_ROI_BITMAP                                                                     0x40101006UL   
#define TAG_ROUTE_SEGMENT_ID                                                                      0x40101007UL   
#define TAG_GANTRY_TYPE                                                                           0x40101008UL   
#define TAG_OOI_OWNER_TYPE                                                                        0x40101009UL   
#define TAG_ROUTE_SEGMENT_SEQUENCE                                                                0x4010100AUL   
#define TAG_POTENTIAL_THREAT_OBJECT_ID                                                            0x40101010UL   
#define TAG_THREAT_SEQUENCE                                                                       0x40101011UL   
#define TAG_THREAT_CATEGORY                                                                       0x40101012UL   
#define TAG_THREAT_CATEGORY_DESCRIPTION                                                           0x40101013UL   
#define TAG_ATD_ABILITY_ASSESSMENT                                                                0x40101014UL   
#define TAG_ATD_ASSESSMENT_FLAG                                                                   0x40101015UL   
#define TAG_ATD_ASSESSMENT_PROBABILITY                                                            0x40101016UL   
#define TAG_MASS                                                                                  0x40101017UL   
#define TAG_DENSITY                                                                               0x40101018UL   
#define TAG_Z_EFFECTIVE                                                                           0x40101019UL   
#define TAG_BOARDING_PASS_ID                                                                      0x4010101AUL   
#define TAG_CENTER_OF_MASS                                                                        0x4010101BUL   
#define TAG_CENTER_OF_PTO                                                                         0x4010101CUL   
#define TAG_BOUNDING_POLYGON                                                                      0x4010101DUL   
#define TAG_ROUTE_SEGMENT_START_LOCATION_ID                                                       0x4010101EUL   
#define TAG_ROUTE_SEGMENT_END_LOCATION_ID                                                         0x4010101FUL   
#define TAG_ROUTE_SEGMENT_LOCATION_ID_TYPE                                                        0x40101020UL   
#define TAG_ABORT_REASON                                                                          0x40101021UL   
#define TAG_VOLUME_OF_PTO                                                                         0x40101023UL   
#define TAG_ABORT_FLAG                                                                            0x40101024UL   
#define TAG_ROUTE_SEGMENT_START_TIME                                                              0x40101025UL   
#define TAG_ROUTE_SEGMENT_END_TIME                                                                0x40101026UL   
#define TAG_TDR_TYPE                                                                              0x40101027UL   
#define TAG_INTERNATIONAL_ROUTE_SEGMENT                                                           0x40101028UL   
#define TAG_THREAT_DETECTION_ALGORITHM_AND_VERSION                                                0x40101029UL   
#define TAG_ASSIGNED_LOCATION                                                                     0x4010102AUL   
#define TAG_ALARM_DECISION_TIME                                                                   0x4010102BUL   
#define TAG_ALARM_DECISION                                                                        0x40101031UL   
#define TAG_NUMBER_OF_TOTAL_OBJECTS                                                               0x40101033UL   
#define TAG_NUMBER_OF_ALARM_OBJECTS                                                               0x40101034UL   
#define TAG_PTO_REPRESENTATION_SEQUENCE                                                           0x40101037UL   
#define TAG_ATD_ASSESSMENT_SEQUENCE                                                               0x40101038UL   
#define TAG_TIP_TYPE                                                                              0x40101039UL   
#define TAG_DICOS_VERSION                                                                         0x4010103AUL   
#define TAG_OOI_OWNER_CREATION_TIME                                                               0x40101041UL   
#define TAG_OOI_TYPE                                                                              0x40101042UL   
#define TAG_OOI_SIZE                                                                              0x40101043UL   
#define TAG_ACQUISITION_STATUS                                                                    0x40101044UL   
#define TAG_BASIS_MATERIALS_CODE_SEQUENCE                                                         0x40101045UL   
#define TAG_PHANTOM_TYPE                                                                          0x40101046UL   
#define TAG_OOI_OWNER_SEQUENCE                                                                    0x40101047UL   
#define TAG_SCAN_TYPE                                                                             0x40101048UL   
#define TAG_ITINERARY_ID                                                                          0x40101051UL   
#define TAG_ITINERARY_ID_TYPE                                                                     0x40101052UL   
#define TAG_ITINERARY_ID_ASSIGNING_AUTHORITY                                                      0x40101053UL   
#define TAG_ROUTE_ID                                                                              0x40101054UL   
#define TAG_ROUTE_ID_ASSIGNING_AUTHORITY                                                          0x40101055UL   
#define TAG_INBOUND_ARRIVAL_TYPE                                                                  0x40101056UL   
#define TAG_CARRIER_ID                                                                            0x40101058UL   
#define TAG_CARRIER_ID_ASSIGNING_AUTHORITY                                                        0x40101059UL   
#define TAG_SOURCE_ORIENTATION                                                                    0x40101060UL   
#define TAG_SOURCE_POSITION                                                                       0x40101061UL   
#define TAG_BELT_HEIGHT                                                                           0x40101062UL   
#define TAG_ALGORITHM_ROUTING_CODE_SEQUENCE                                                       0x40101064UL   
#define TAG_TRANSPORT_CLASSIFICATION                                                              0x40101067UL   
#define TAG_OOI_TYPE_DESCRIPTOR                                                                   0x40101068UL   
#define TAG_TOTAL_PROCESSING_TIME                                                                 0x40101069UL   
#define TAG_DETECTOR_CALIBRATION_DATA                                                             0x4010106CUL   
#define TAG_ADDITIONAL_SCREENING_PERFORMED                                                        0x4010106DUL   
#define TAG_ADDITIONAL_INSPECTION_SELECTION_CRITERIA                                              0x4010106EUL   
#define TAG_ADDITIONAL_INSPECTION_METHOD_SEQUENCE                                                 0x4010106FUL   
#define TAG_AIT_DEVICE_TYPE                                                                       0x40101070UL   
#define TAG_QR_MEASUREMENTS_SEQUENCE                                                              0x40101071UL   
#define TAG_TARGET_MATERIAL_SEQUENCE                                                              0x40101072UL   
#define TAG_SNR_THRESHOLD                                                                         0x40101073UL   
#define TAG_IMAGE_SCALE_REPRESENTATION                                                            0x40101075UL   
#define TAG_REFERENCED_PTO_SEQUENCE                                                               0x40101076UL   
#define TAG_REFERENCED_TDR_INSTANCE_SEQUENCE                                                      0x40101077UL   
#define TAG_PTO_LOCATION_DESCRIPTION                                                              0x40101078UL   
#define TAG_ANOMALY_LOCATOR_INDICATOR_SEQUENCE                                                    0x40101079UL   
#define TAG_ANOMALY_LOCATOR_INDICATOR                                                             0x4010107AUL   
#define TAG_PTO_REGION_SEQUENCE                                                                   0x4010107BUL   
#define TAG_INSPECTION_SELECTION_CRITERIA                                                         0x4010107CUL   
#define TAG_SECONDARY_INSPECTION_METHOD_SEQUENCE                                                  0x4010107DUL   
#define TAG_PRCS_TO_RCS_ORIENTATION                                                               0x4010107EUL   

// *****************************************************************************************************************************
// *** 4FFE
// *****************************************************************************************************************************
#define TAG_MAC_PARAMETERS_SEQUENCE                                                               0x4FFE0001UL   

// *****************************************************************************************************************************
// *** 50xx
// *****************************************************************************************************************************
#define TAG_CURVE_DIMENSIONS                                                                      0x50000005UL   // Retired
#define TAG_NUMBER_OF_POINTS                                                                      0x50000010UL   // Retired
#define TAG_TYPE_OF_DATA                                                                          0x50000020UL   // Retired
#define TAG_CURVE_DESCRIPTION                                                                     0x50000022UL   // Retired
#define TAG_AXIS_UNITS                                                                            0x50000030UL   // Retired
#define TAG_AXIS_LABELS                                                                           0x50000040UL   // Retired
#define TAG_DATA_VALUE_REPRESENTATION                                                             0x50000103UL   // Retired
#define TAG_MINIMUM_COORDINATE_VALUE                                                              0x50000104UL   // Retired
#define TAG_MAXIMUM_COORDINATE_VALUE                                                              0x50000105UL   // Retired
#define TAG_CURVE_RANGE                                                                           0x50000106UL   // Retired
#define TAG_CURVE_DATA_DESCRIPTOR                                                                 0x50000110UL   // Retired
#define TAG_COORDINATE_START_VALUE                                                                0x50000112UL   // Retired
#define TAG_COORDINATE_STEP_VALUE                                                                 0x50000114UL   // Retired
#define TAG_CURVE_ACTIVATION_LAYER                                                                0x50001001UL   // Retired
#define TAG_AUDIO_TYPE                                                                            0x50002000UL   // Retired
#define TAG_AUDIO_SAMPLE_FORMAT                                                                   0x50002002UL   // Retired
#define TAG_NUMBER_OF_CHANNELS                                                                    0x50002004UL   // Retired
#define TAG_NUMBER_OF_SAMPLES                                                                     0x50002006UL   // Retired
#define TAG_SAMPLE_RATE                                                                           0x50002008UL   // Retired
#define TAG_TOTAL_TIME                                                                            0x5000200AUL   // Retired
#define TAG_AUDIO_SAMPLE_DATA                                                                     0x5000200CUL   // Retired
#define TAG_AUDIO_COMMENTS                                                                        0x5000200EUL   // Retired
#define TAG_CURVE_LABEL                                                                           0x50002500UL   // Retired
#define TAG_CURVE_REFERENCED_OVERLAY_SEQUENCE                                                     0x50002600UL   // Retired
#define TAG_CURVE_REFERENCED_OVERLAY_GROUP                                                        0x50002610UL   // Retired
#define TAG_CURVE_DATA                                                                            0x50003000UL   // Retired

// *****************************************************************************************************************************
// *** 5200
// *****************************************************************************************************************************
#define TAG_SHARED_FUNCTIONAL_GROUPS_SEQUENCE                                                     0x52009229UL   
#define TAG_PER_FRAME_FUNCTIONAL_GROUPS_SEQUENCE                                                  0x52009230UL   

// *****************************************************************************************************************************
// *** 5400
// *****************************************************************************************************************************
#define TAG_WAVEFORM_SEQUENCE                                                                     0x54000100UL   
#define TAG_CHANNEL_MINIMUM_VALUE                                                                 0x54000110UL   
#define TAG_CHANNEL_MAXIMUM_VALUE                                                                 0x54000112UL   
#define TAG_WAVEFORM_BITS_ALLOCATED                                                               0x54001004UL   
#define TAG_WAVEFORM_SAMPLE_INTERPRETATION                                                        0x54001006UL   
#define TAG_WAVEFORM_PADDING_VALUE                                                                0x5400100AUL   
#define TAG_WAVEFORM_DATA                                                                         0x54001010UL   

// *****************************************************************************************************************************
// *** 5600
// *****************************************************************************************************************************
#define TAG_FIRST_ORDER_PHASE_CORRECTION_ANGLE                                                    0x56000010UL   
#define TAG_SPECTROSCOPY_DATA                                                                     0x56000020UL   

// *****************************************************************************************************************************
// *** 60xx
// *****************************************************************************************************************************
#define TAG_OVERLAY_ROWS                                                                          0x60000010UL   
#define TAG_OVERLAY_COLUMNS                                                                       0x60000011UL   
#define TAG_OVERLAY_PLANES                                                                        0x60000012UL   // Retired
#define TAG_NUMBER_OF_FRAMES_IN_OVERLAY                                                           0x60000015UL   
#define TAG_OVERLAY_DESCRIPTION                                                                   0x60000022UL   
#define TAG_OVERLAY_TYPE                                                                          0x60000040UL   
#define TAG_OVERLAY_SUBTYPE                                                                       0x60000045UL   
#define TAG_OVERLAY_ORIGIN                                                                        0x60000050UL   
#define TAG_IMAGE_FRAME_ORIGIN                                                                    0x60000051UL   
#define TAG_OVERLAY_PLANE_ORIGIN                                                                  0x60000052UL   // Retired
#define TAG_OVERLAY_COMPRESSION_CODE                                                              0x60000060UL   // Retired
#define TAG_OVERLAY_COMPRESSION_ORIGINATOR                                                        0x60000061UL   // Retired
#define TAG_OVERLAY_COMPRESSION_LABEL                                                             0x60000062UL   // Retired
#define TAG_OVERLAY_COMPRESSION_DESCRIPTION                                                       0x60000063UL   // Retired
#define TAG_OVERLAY_COMPRESSION_STEP_POINTERS                                                     0x60000066UL   // Retired
#define TAG_OVERLAY_REPEAT_INTERVAL                                                               0x60000068UL   // Retired
#define TAG_OVERLAY_BITS_GROUPED                                                                  0x60000069UL   // Retired
#define TAG_OVERLAY_BITS_ALLOCATED                                                                0x60000100UL   
#define TAG_OVERLAY_BIT_POSITION                                                                  0x60000102UL   
#define TAG_OVERLAY_FORMAT                                                                        0x60000110UL   // Retired
#define TAG_OVERLAY_LOCATION                                                                      0x60000200UL   // Retired
#define TAG_OVERLAY_CODE_LABEL                                                                    0x60000800UL   // Retired
#define TAG_OVERLAY_NUMBER_OF_TABLES                                                              0x60000802UL   // Retired
#define TAG_OVERLAY_CODE_TABLE_LOCATION                                                           0x60000803UL   // Retired
#define TAG_OVERLAY_BITS_FOR_CODE_WORD                                                            0x60000804UL   // Retired
#define TAG_OVERLAY_ACTIVATION_LAYER                                                              0x60001001UL   
#define TAG_OVERLAY_DESCRIPTOR_GRAY                                                               0x60001100UL   // Retired
#define TAG_OVERLAY_DESCRIPTOR_RED                                                                0x60001101UL   // Retired
#define TAG_OVERLAY_DESCRIPTOR_GREEN                                                              0x60001102UL   // Retired
#define TAG_OVERLAY_DESCRIPTOR_BLUE                                                               0x60001103UL   // Retired
#define TAG_OVERLAYS_GRAY                                                                         0x60001200UL   // Retired
#define TAG_OVERLAYS_RED                                                                          0x60001201UL   // Retired
#define TAG_OVERLAYS_GREEN                                                                        0x60001202UL   // Retired
#define TAG_OVERLAYS_BLUE                                                                         0x60001203UL   // Retired
#define TAG_ROI_AREA                                                                              0x60001301UL   
#define TAG_ROI_MEAN                                                                              0x60001302UL   
#define TAG_ROI_STANDARD_DEVIATION                                                                0x60001303UL   
#define TAG_OVERLAY_LABEL                                                                         0x60001500UL   
#define TAG_OVERLAY_DATA                                                                          0x60003000UL   
#define TAG_OVERLAY_COMMENTS                                                                      0x60004000UL   // Retired

// *****************************************************************************************************************************
// *** 7FE0
// *****************************************************************************************************************************
#define TAG_EXTENDED_OFFSET_TABLE                                                                 0x7FE00001UL   
#define TAG_EXTENDED_OFFSET_TABLE_LENGTHS                                                         0x7FE00002UL   
#define TAG_FLOAT_PIXEL_DATA                                                                      0x7FE00008UL   
#define TAG_DOUBLE_FLOAT_PIXEL_DATA                                                               0x7FE00009UL   
#define TAG_PIXEL_DATA                                                                            0x7FE00010UL   
#define TAG_COEFFICIENTS_SDVN                                                                     0x7FE00020UL   // Retired
#define TAG_COEFFICIENTS_SDHN                                                                     0x7FE00030UL   // Retired
#define TAG_COEFFICIENTS_SDDN                                                                     0x7FE00040UL   // Retired

// *****************************************************************************************************************************
// *** 7Fxx
// *****************************************************************************************************************************
#define TAG_VARIABLE_PIXEL_DATA                                                                   0x7F000010UL   // Retired
#define TAG_VARIABLE_NEXT_DATA_GROUP                                                              0x7F000011UL   // Retired
#define TAG_VARIABLE_COEFFICIENTS_SDVN                                                            0x7F000020UL   // Retired
#define TAG_VARIABLE_COEFFICIENTS_SDHN                                                            0x7F000030UL   // Retired
#define TAG_VARIABLE_COEFFICIENTS_SDDN                                                            0x7F000040UL   // Retired

// *****************************************************************************************************************************
// *** FFFA
// *****************************************************************************************************************************
#define TAG_DIGITAL_SIGNATURES_SEQUENCE                                                           0xFFFAFFFAUL   

// *****************************************************************************************************************************
// *** FFFC
// *****************************************************************************************************************************
#define TAG_DATA_SET_TRAILING_PADDING                                                             0xFFFCFFFCUL   

// *****************************************************************************************************************************
// *** FFFE
// *****************************************************************************************************************************
#define TAG_ITEM                                                                                  0xFFFEE000UL   
#define TAG_ITEM_DELIMITATION_ITEM                                                                0xFFFEE00DUL   
#define TAG_SEQUENCE_DELIMITATION_ITEM                                                            0xFFFEE0DDUL   

                                                                             
// *****************************************************************************************************************************
// *** Defines for Backward  Compatibility                                                                                      
// *****************************************************************************************************************************
#define TAG_SPECIFIC_CHARACTER_SET_OF_FILE                                                        TAG_SPECIFIC_CHARACTER_SET_OF_FILE_SET_DESCRIPTOR_FILE
#define TAG_OFFSET_MRDR_DIRECTORY                                                                 TAG_MRDR_DIRECTORY_RECORD_OFFSET
#define TAG_NUMBER_OF_REMAINING_SUBOPERATIONS                                                     TAG_NUMBER_OF_REMAINING_SUB_OPERATIONS
#define TAG_NUMBER_OF_COMPLETED_SUBOPERATIONS                                                     TAG_NUMBER_OF_COMPLETED_SUB_OPERATIONS
#define TAG_NUMBER_OF_FAILED_SUBOPERATIONS                                                        TAG_NUMBER_OF_FAILED_SUB_OPERATIONS
#define TAG_NUMBER_OF_WARNING_SUBOPERATIONS                                                       TAG_NUMBER_OF_WARNING_SUB_OPERATIONS
#define TAG_OVERLAY_DESCRIPTOR_GRAY_RETIRED                                                       TAG_OVERLAY_DESCRIPTOR_GRAY
#define TAG_OVERLAY_DESCRIPTOR_RED_RETIRED                                                        TAG_OVERLAY_DESCRIPTOR_RED
#define TAG_OVERLAY_DESCRIPTOR_GREEN_RETIRED                                                      TAG_OVERLAY_DESCRIPTOR_GREEN
#define TAG_OVERLAY_DESCRIPTOR_BLUE_RETIRED                                                       TAG_OVERLAY_DESCRIPTOR_BLUE
#define TAG_OVERLAYS_GRAY_RETIRED                                                                 TAG_OVERLAYS_GRAY
#define TAG_OVERLAYS_RED_RETIRED                                                                  TAG_OVERLAYS_RED
#define TAG_OVERLAYS_GREEN_RETIRED                                                                TAG_OVERLAYS_GREEN
#define TAG_OVERLAYS_BLUE_RETIRED                                                                 TAG_OVERLAYS_BLUE
#define TAG_PRESENTATION_LABEL                                                                    TAG_CONTENT_LABEL
#define TAG_PRESENTATION_DESCRIPTION                                                              TAG_CONTENT_DESCRIPTION
#define TAG_PRESENTATION_CREATTION_DATE                                                           TAG_PRESENTATION_CREATION_DATE
#define TAG_PRESENTATION_CREATTION_TIME                                                           TAG_PRESENTATION_CREATION_TIME
#define TAG_PRESENTATION_CREATOR_NAME                                                             TAG_CONTENT_CREATOR_NAME
#define TAG_REFERENCED_IMAGE_OVERLAY_BOX_SEQUENCE_RETIRED                                         TAG_REFERENCED_IMAGE_OVERLAY_BOX_SEQUENCE
#define TAG_REFERENCED_PRINT_JOB_SEQUENCE_2100                                                    TAG_REFERENCED_PRINT_JOB_SEQUENCE_PULL_STORED_PRINT
#define TAG_ANNOTATION_SEQUENCE                                                                   TAG_WAVEFORM_ANNOTATION_SEQUENCE
                                                                             
// *****************************************************************************************************************************
// *** Defines for v19 to v18 backward Compatibility                                                                                      
// *****************************************************************************************************************************
#define TAG_NOR_REV                                                                               TAG_NORMAL_REVERSE
#define TAG_ONAXIS_BACKGROUND_ANATOMIC_STRUCTURE_CODE_SEQUENCE_TRIAL                              TAG_ON_AXIS_BACKGROUND_ANATOMIC_STRUCTURE_CODE_SEQUENCE_TRIAL
#define TAG_REFERENCED_GRAYSCALE_PRESENTATION_STATE_SEQUENCE                                      TAG_REFERENCED_PRESENTATION_STATE_SEQUENCE
#define TAG_PATIENT_PRIMARY_LANGUAGE_CODE_MODIFIER_SEQUENCE                                       TAG_PATIENT_PRIMARY_LANGUAGE_MODIFIER_CODE_SEQUENCE
#define TAG_MATERIAL_PROPERTIES_FILE_ID                                                           TAG_MATERIAL_PROPERTIES_DESCRIPTION
#define TAG_ELEMENT_PITCH                                                                         TAG_ELEMENT_PITCH_A
#define TAG_CRYSTAL_CENTER_LOCATION_X                                                             TAG_PROBE_CENTER_LOCATION_X
#define TAG_CRYSTAL_CENTER_LOCATION_Z                                                             TAG_PROBE_CENTER_LOCATION_Z
#define TAG_INTERVENTION_DRUG_SEQUENCE                                                            TAG_INTERVENTION_DRUG_CODE_SEQUENCE
#define TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURERS                                                TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURER
#define TAG_SECONDARY_CAPTURE_DEVICE_SOFTWARE_VERSION                                             TAG_SECONDARY_CAPTURE_DEVICE_SOFTWARE_VERSIONS
#define TAG_CHEMICAL_SHIFTS_MINIMUM_INTEGRATION_LIMIT_IN_HZ                                       TAG_CHEMICAL_SHIFT_MINIMUM_INTEGRATION_LIMIT_IN_HZ
#define TAG_CHEMICAL_SHIFTS_MAXIMUM_INTEGRATION_LIMIT_IN_HZ                                       TAG_CHEMICAL_SHIFT_MAXIMUM_INTEGRATION_LIMIT_IN_HZ
#define TAG_ASL_CRUSHER_FLOW                                                                      TAG_ASL_CRUSHER_FLOW_LIMIT
#define TAG_CHEMICAL_SHIFTS_MINIMUM_INTEGRATION_LIMIT_IN_PPM                                      TAG_CHEMICAL_SHIFT_MINIMUM_INTEGRATION_LIMIT_IN_PPM
#define TAG_CHEMICAL_SHIFTS_MAXIMUM_INTEGRATION_LIMIT_IN_PPM                                      TAG_CHEMICAL_SHIFT_MAXIMUM_INTEGRATION_LIMIT_IN_PPM
#define TAG_DYNAMIC_FLAG                                                                          0x00189757UL   
#define TAG_CONTRIBUTION_DATE_TIME                                                                TAG_CONTRIBUTION_DATETIME
#define TAG_LOOKUP_TABLE_NUMBER                                                                   TAG_LUT_NUMBER 
#define TAG_OPHTHALMIC_ULTRASOUND_AXIAL_MEASUREMENTS_TYPE_CODE_SEQUENCE                           TAG_OPHTHALMIC_ULTRASOUND_METHOD_CODE_SEQUENCE
#define TAG_SOURCE_OF_REFRACTIVE_ERROR_DATA_CODE_SEQUENCE                                         TAG_SOURCE_OF_REFRACTIVE_MEASUREMENTS_CODE_SEQUENCE
#define TAG_NUMBER_OF_TABLE                                                                       TAG_NUMBER_OF_TABLES
#define TAG_SCHEDULED_PROCEDURE_STEP_START_DATE_AND_TIME                                          TAG_SCHEDULED_PROCEDURE_STEP_START_DATETIME
#define TAG_SCHEDULED_PROCEDURE_STEP_MODIFICATION_DATE_AND_TIME                                   TAG_SCHEDULED_PROCEDURE_STEP_MODIFICATION_DATETIME
#define TAG_EXPECTED_COMPLETION_DATE_AND_TIME                                                     TAG_EXPECTED_COMPLETION_DATETIME
#define TAG_VERIFICATION_DATE_TIME                                                                TAG_VERIFICATION_DATETIME
#define TAG_OBSERVATION_DATE_TIME                                                                 TAG_OBSERVATION_DATETIME
#define TAG_OBSERVATION_UID_TRIAL                                                                 TAG_OBSERVATION_UID
#define TAG_INTERMARKER_DISTANCE                                                                  TAG_INTER_MARKER_DISTANCE
#define TAG_ALINE_RATE                                                                            TAG_A_LINE_RATE
#define TAG_ALINES_PER_FRAME                                                                      TAG_A_LINES_PER_FRAME
#define TAG_ALINE_PIXEL_SPACING                                                                   TAG_A_LINE_PIXEL_SPACING
#define TAG_FIRST_ALINE_LOCATION                                                                  TAG_FIRST_A_LINE_LOCATION
#define TAG_NUMBER_OF_PADDED_ALINES                                                               TAG_NUMBER_OF_PADDED_A_LINES
#define TAG_NUMBER_OF_POINTS_SURFACE_SEGMENTATION                                                 TAG_NUMBER_OF_SURFACE_POINTS
#define TAG_UNIFIED_PROCEDURE_STEP_STATE                                                          TAG_PROCEDURE_STEP_STATE
#define TAG_UPS_PROGRESS_INFORMATION_SEQUENCE                                                     TAG_PROCEDURE_STEP_PROGRESS_INFORMATION_SEQUENCE
#define TAG_UNIFIED_PROCEDURE_STEP_PROGRESS                                                       TAG_PROCEDURE_STEP_PROGRESS
#define TAG_UNIFIED_PROCEDURE_STEP_PROGRESS_DESCRIPTION                                           TAG_PROCEDURE_STEP_PROGRESS_DESCRIPTION
#define TAG_UNIFIED_PROCEDURE_STEP_COMMUNICATIONS_URI_SEQUENCE                                    TAG_PROCEDURE_STEP_COMMUNICATIONS_URI_SEQUENCE
#define TAG_UNIFIED_PROCEDURE_STEP_DISCONTINUATION_REASON_CODE_SEQUENCE                           TAG_PROCEDURE_STEP_DISCONTINUATION_REASON_CODE_SEQUENCE
#define TAG_UPS_PERFORMED_PROCEDURE_SEQUENCE                                                      TAG_UNIFIED_PROCEDURE_STEP_PERFORMED_PROCEDURE_SEQUENCE
#define TAG_UPS_LIST_STATUS                                                                       TAG_UNIFIED_PROCEDURE_STEP_LIST_STATUS
#define TAG_SOP_AUTHORIZATION_DATE_AND_TIME                                                       TAG_SOP_AUTHORIZATION_DATETIME
                                                                             
// *****************************************************************************************************************************
// *** Defines for V21 to v20, V19 backward Compatibility                                                                                      
// *****************************************************************************************************************************
#define TAG_SOFTWARE_VERSION                                                                      TAG_SOFTWARE_VERSIONS
#define TAG_VIEW_ORIENTATION_MODIFIER                                                             TAG_VIEW_ORIENTATION_MODIFIER_CODE_SEQUENCE
#define TAG_AVERAGE_BEAM_DOSE_POINT_SOURCE_TO_EXTERNAL_CONTOUR_SURFACE_DISTANCE                   TAG_AVERAGE_BEAM_DOSE_POINT_SOURCE_TO_EXTERNAL_CONTOUR_DISTANCE
