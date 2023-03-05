//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#define DICOM_SUCCESS                                                  0   // Operation is successful
#define DICOM_ERROR_ISCL_OK                                            0   // Operation is successful
#define DICOM_ERROR_TLS_OK                                             0   // Operation is successful

#define DICOM_ERROR_LOCKED                                             1   // Support is locked. You must unlock the Medical or MedicalNet Support
#define DICOM_ERROR_MEMORY                                             2   // Insufficient memory
#define DICOM_ERROR_OPEN                                               3   // Error opening the file
#define DICOM_ERROR_READ                                               4   // Error reading the file
#define DICOM_ERROR_WRITE                                              5   // Error writing to a file
#define DICOM_ERROR_SEEK                                               6   // Error during search
#define DICOM_ERROR_END                                                7   // Error - end of file
#define DICOM_ERROR_FORMAT                                             8   // Improper file format
#define DICOM_ERROR_PARAMETER                                          9   // Incorrect parameter
#define DICOM_ERROR_IMAGE                                             10   // Improper image
#define DICOM_ERROR_COMPRESSION                                       11   // Improper compression
#define DICOM_ERROR_PHOTOMETRIC                                       12   // Improper photometric type
#define DICOM_ERROR_CONVERSION                                        13   // Error converting the file
#define DICOM_ERROR_RANGE                                             14   // Out of range
#define DICOM_ERROR_BITSPERPIXEL                                      15   // Improper bits per pixel
#define DICOM_ERROR_QFACTOR                                           16   // Improper quality factor
#define DICOM_ERROR_PDU_TYPE                                          17   // Improper PDU type
#define DICOM_ERROR_PDU_LENGTH                                        18   // Improper PDU length
#define DICOM_ERROR_PDU_ID                                            19   // Improper PDU ID
#define DICOM_ERROR_BITSPERPIXEL_MISMATCH                             20   // DICOM Bits Allocated Tag and actual BPP of encoded data (i.e. JPEG) do not match

#define DICOM_ERROR_NET_FAILURE                                       29   // Network failure
#define DICOM_ERROR_NET_ACCESS                                        30   // The address is a broadcast address
#define DICOM_ERROR_NET_ADDRESS_IN_USE                                31   // The address is already in use
#define DICOM_ERROR_NET_ADDRESS_NOT_AVAILABLE                         32   // The address is not available from the local computer
#define DICOM_ERROR_NET_ADDRESS_NOT_SUPPORTED                         33   // The address family is not supported
#define DICOM_ERROR_NET_CONNECTION_ABORTED                            34   // The virtual circuit was aborted
#define DICOM_ERROR_NET_CONNECTION_REFUSED                            35   // The attempt to connect was forcefully rejected
#define DICOM_ERROR_NET_CONNECTION_RESET                              36   // The virtual circuit was reset by the remote side
#define DICOM_ERROR_NET_DESTINATION_REQUIRED                          37   // A destination address is required
#define DICOM_ERROR_NET_ARGUMENT_INCORRECT                            38   // The namelen argument is incorrect
#define DICOM_ERROR_NET_IN_PROGRESS                                   39   // A blocking operation is in progress
#define DICOM_ERROR_NET_BLOCKING_CANCELED                             40   // The blocking call was canceled
#define DICOM_ERROR_NET_INVALID                                       41   // The socket has not been bound with bind
#define DICOM_ERROR_NET_IS_CONNECTED                                  42   // The socket is already connected
#define DICOM_ERROR_NET_NO_MORE_FILE                                  43   // No more file descriptors are available
#define DICOM_ERROR_NET_MESSAGE_SIZE                                  44   // The datagram is larger than the maximum supported
#define DICOM_ERROR_NET_DOWN                                          45   // The network subsystem has failed
#define DICOM_ERROR_NET_RESET                                         46   // The connection must be reset
#define DICOM_ERROR_NET_UN_REACH                                      47   // The network can't be reached from this host at this time
#define DICOM_ERROR_NET_NO_BUFFERS                                    48   // No buffer space is available
#define DICOM_ERROR_NET_NOT_CONNECTED                                 49   // The socket is not connected
#define DICOM_ERROR_NET_NOT_SOCKET                                    50   // The descriptor is not a socket
#define DICOM_ERROR_NET_OPERATION_NOT_SUPPORTED                       51   // The type does not support connection-oriented service
#define DICOM_ERROR_NET_PROTOCOL_NOT_SUPPORTED                        52   // The specified protocol is not supported
#define DICOM_ERROR_NET_PROTOCOL_TYPE                                 53   // The specified protocol is the wrong type
#define DICOM_ERROR_NET_SHUTDOWN                                      54   // The socket has been shut down
#define DICOM_ERROR_NET_SOCKET_NOT_SUPPORTED                          55   // The type is not supported in this address family
#define DICOM_ERROR_NET_TIME_OUT                                      56   // Attempt to connect timed out without establishing a connection
#define DICOM_ERROR_NET_WOULD_BLOCK                                   57   // The socket is marked as nonblocking and the requested operation would block
#define DICOM_ERROR_NET_HOST_NOT_FOUND                                58   // Authoritative Answer Host not found
#define DICOM_ERROR_NET_NO_DATA                                       59   // Valid name, no data record of requested type
#define DICOM_ERROR_NET_NO_RECOVERY                                   60   // Nonrecoverable errors
#define DICOM_ERROR_NET_NOT_INITIALISED                               61   // The system was not initialized
#define DICOM_ERROR_NET_SYSTEM_NOT_READY                              62   // Not ready for network communication
#define DICOM_ERROR_NET_TRY_AGAIN                                     63   // Non-Authoritative Host not found, or server failed
#define DICOM_ERROR_NET_VERSION_NOT_SUPPORTED                         64   // The version requested is not provided by this implementation
#define DICOM_ERROR_NET_SECURITY_BREACH                               65   // There is a cryptographic error
                                                                           // Call LDicomNet::GetStatusISCL or LDicomNet::GetStatusTLS for the description of internal status
                                                                           // Before error, and LDicomNet::GetErrorSecure for the description of the error

#define DICOM_ERROR_TLS                                               66   // TLS internal error
#define DICOM_ERROR_SECURITY_LOCKED                                   67   // DICOM Security Features are locked
#define DICOM_ERROR_TLS_DLL_NOT_LOADED                                68   // TLS and/or CRY DLL not loaded
#define DICOM_ERROR_BAD_SECURE_MODE                                   69   // ISCL operation attempted on TLS object
#define DICOM_ERROR_ANN                                               70   // Annotation error
#define DICOM_ERROR_ANN_LOCKED                                        71   // Annotation support is locked
#define DICOM_ERROR_ANN_MISSING                                       72   // Annotation dll is missing
#define DICOM_ERROR_TAG_ALREADY_EXISTS                                73   // LEAD private creator element already exists
#define DICOM_ERROR_ANN_NO_EXIST                                      74   // Requested annotation file or page does not exist

#define DICOM_ERROR_ELEMENT_LENGTH_ODD                               100   // Option not expected or unknown. This define is redundant and remains for backward compatibility.

#define DICOM_ERROR_ISCL_BAD_OPTION                                  100   // Option not expected or unknown
#define DICOM_ERROR_ISCL_BAD_LENGTH                                  101   // The length of the message differs from the expected length
#define DICOM_ERROR_ISCL_LOCAL_ICCARD                                102   // Local error on Id card
#define DICOM_ERROR_ISCL_REMOTE_ICCARD                               103   // Error on Id card level at peer
#define DICOM_ERROR_ISCL_BAD_MSGID                                   104   // Message id not expected or unknown
#define DICOM_ERROR_ISCL_BAD_VERSION                                 105   // Bad version number - not MEDIS-ISCL V1.00
#define DICOM_ERROR_ISCL_BAD_MUTUAL_AUTH_METHOD                      106   // Bad mutual authentication mode - mutual auth not 3pass 4way
#define DICOM_ERROR_ISCL_BAD_COMMBLOCK_LENGTH                        107   // Bad communication block length - the comm block length is too big
#define DICOM_ERROR_ISCL_RECEIVED_NAK                                108   // Received a 'Not Acknowledged' message - when the peer sent option = NAK in general cases, there are some special cases
#define DICOM_ERROR_ISCL_MSG_TRANSMISSION                            109   // Bad encryption method or MAC method
#define DICOM_ERROR_ISCL_PEER_SMALL_LENGTH                           110   // Message length of the peer is too small
#define DICOM_ERROR_ISCL_LOCAL_SMALL_LENGTH                          111   // Peer want to send a message bigger than local MaxMessageLength
#define DICOM_ERROR_ISCL_DECRYPT                                     112   // Error during decryption - decryption generate bad result
#define DICOM_ERROR_ISCL_BAD_MAC                                     113   // Wrong message authentication code
#define DICOM_ERROR_ISCL_RND_NO_FOR_SESSION_KEY_EXPECTED             114   // Only when the receiver expect to receive a 'Random number for session key' request. The sender must be set to "SetSecurity(DICOM_ISCL_UNIQUE_SESSION_KEYS)"
#define DICOM_ERROR_ISCL_PEER_REFUSE_CLOSE                           115   // When the peer does not accept the closing of connection


#define DICOM_ERROR_TLS_CERTIFICATE_VERIFY_FAILED                    127   // Certificate verify failed
#define DICOM_ERROR_TLS_CLOSE_NOTIFY                                 128   // Error in close notification
#define DICOM_ERROR_TLS_UNEXPECTED_MESSAGE                           129   // Unexpected message
#define DICOM_ERROR_TLS_BAD_RECORD_MAC                               130   // Bad record message authentication code
#define DICOM_ERROR_TLS_DECRYPT_FAILED                               131   // Decryption failed
#define DICOM_ERROR_TLS_RECORD_OVERFLOW                              132   // Record overflow
#define DICOM_ERROR_TLS_DECOMPRESSION_FAILURE                        133   // Decompression failed
#define DICOM_ERROR_TLS_HANDSHAKE_FAILURE                            134   // Handshake failed
#define DICOM_ERROR_TLS_BAD_CERTIFICATE                              135   // Bad certificate
#define DICOM_ERROR_TLS_UNSUPPORTED_CERTIFICATE                      136   // Unsupported certificate
#define DICOM_ERROR_TLS_CERTIFICATE_REVOKED                          137   // Certificate revoked
#define DICOM_ERROR_TLS_CERTIFICATE_EXPIRED                          138   // Certificate Expired
#define DICOM_ERROR_TLS_CERTIFICATE_UNKNOWN                          139   // Certificate unknown
#define DICOM_ERROR_TLS_ILLEGAL_PARAMETER                            140   // Illegal parameter
#define DICOM_ERROR_TLS_UNKNOWN_CA                                   141   // Unknown certificate authenticator
#define DICOM_ERROR_TLS_ACCESS_DENIED                                142   // Access denied
#define DICOM_ERROR_TLS_DECODE_ERROR                                 143   // Error decoding
#define DICOM_ERROR_TLS_DECRYPT_ERROR                                144   // Decryption error
#define DICOM_ERROR_TLS_EXPORT_RESTRICTION                           145   // Export restriction
#define DICOM_ERROR_TLS_PROTOCOL_VERSION                             146   // Wrong protocol version
#define DICOM_ERROR_TLS_INSUFFICIENT_SECURITY                        147   // Insufficient security
#define DICOM_ERROR_TLS_INTERNAL_ERROR                               148   // Internal error Call LEAD
#define DICOM_ERROR_TLS_USER_CANCELED                                149   // User cancelled
#define DICOM_ERROR_TLS_NO_RENEGOTIATION                             150   // No renegotiation
#define DICOM_ERROR_TLS_NO_KEEPALIVE                                 151   // Windows Sockets provider does not support the use of keep-alives
#define DICOM_ERROR_TLS_CLOSED_CONTROLLED                            152   // An error occurred and the connection was closed gracefully
                                                           
#define DICOM_ERROR_TLS_UNABLE_TO_GET_ISSUER_CERT                    160   // Unable to get issuer certificate
#define DICOM_ERROR_TLS_UNABLE_TO_GET_CRL                            161   // Unable to get CRL
#define DICOM_ERROR_TLS_UNABLE_TO_DECRYPT_CERT_SIGNATURE             162   // Unable to decrypt certificate signature
#define DICOM_ERROR_TLS_UNABLE_TO_DECRYPT_CRL_SIGNATURE              163   // Unable to decrypt CRL signature
#define DICOM_ERROR_TLS_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY           164   // Unable to decode issuer public key
#define DICOM_ERROR_TLS_CERT_SIGNATURE_FAILURE                       165   // Certificate signature failure
#define DICOM_ERROR_TLS_CRL_SIGNATURE_FAILURE                        166   // Error TLS CRL Signature Failure
#define DICOM_ERROR_TLS_CERT_NOT_YET_VALID                           167   // Error TLS Certificate Not Yet Valid
#define DICOM_ERROR_TLS_CERT_HAS_EXPIRED                             168   // Error TLS Certificate Has Expired
#define DICOM_ERROR_TLS_CRL_NOT_YET_VALID                            169   // Error TLS CRL Not Yet Valid
#define DICOM_ERROR_TLS_CRL_HAS_EXPIRED                              170   // Error TLS CRL Has Expired
#define DICOM_ERROR_TLS_ERROR_IN_CERT_NOT_BEFORE_FIELD               171   // Error TLS Error In Certificate Not Before Field
#define DICOM_ERROR_TLS_ERROR_IN_CERT_NOT_AFTER_FIELD                172   // Error TLS Error In Certificate Not After Field
#define DICOM_ERROR_TLS_ERROR_IN_CRL_LAST_UPDATE_FIELD               173   // Error TLS Error In CRL Last Update Field
#define DICOM_ERROR_TLS_ERROR_IN_CRL_NEXT_UPDATE_FIELD               174   // Error TLS Error In CRL Next Update Field
#define DICOM_ERROR_TLS_OUT_OF_MEM                                   175   // Error TLS Out Of Memory
#define DICOM_ERROR_TLS_DEPTH_ZERO_SELF_SIGNED_CERT                  176   // Error TLS Depth Zero Self Signed Certificate
#define DICOM_ERROR_TLS_SELF_SIGNED_CERT_IN_CHAIN                    177   // Error TLS Self Signed Certificate In Chain
#define DICOM_ERROR_TLS_UNABLE_TO_GET_ISSUER_CERT_LOCALLY            178   // Error TLS Unable To Get Issuer Certificate Locally
#define DICOM_ERROR_TLS_UNABLE_TO_VERIFY_LEAF_SIGNATURE              179   // Error TLS Unable To Verify Leaf Signature
#define DICOM_ERROR_TLS_CERT_CHAIN_TOO_LONG                          180   // Error TLS Certificate Chain Too Long
#define DICOM_ERROR_TLS_CERT_REVOKED                                 181   // Error TLS Certificate Revoked
#define DICOM_ERROR_TLS_INVALID_CA                                   182   // Error TLS Invalid CA
#define DICOM_ERROR_TLS_PATH_LENGTH_EXCEEDED                         183   // Error TLS Path Length Exceeded
#define DICOM_ERROR_TLS_INVALID_PURPOSE                              184   // Error TLS Invalid Purpose
#define DICOM_ERROR_TLS_CERT_UNTRUSTED                               185   // Error TLS Certificate Untrusted
#define DICOM_ERROR_TLS_CERT_REJECTED                                186   // Error TLS Certificate Rejected
#define DICOM_ERROR_TLS_SUBJECT_ISSUER_MISMATCH                      187   // Error TLS Subject Issuer Mismatch
#define DICOM_ERROR_TLS_AKID_SKID_MISMATCH                           188   // Error TLS AKID SKID Mismatch
#define DICOM_ERROR_TLS_AKID_ISSUER_SERIAL_MISMATCH                  189   // Error TLS AKID Issuer Serial Mismatch
#define DICOM_ERROR_TLS_KEYUSAGE_NO_CERTSIGN                         190   // Error TLS Keyusage No Certsign
#define DICOM_ERROR_TLS_APPLICATION_VERIFICATION                     191   // Error TLS Application Verification
#define DICOM_ERROR_TLS_INVALID_CTX                                  192   // Error TLS Invalid SSL Context
#define DICOM_ERROR_TLS_INVALID_CTX_VERIFY_DEPTH                     193   // Error TLS Invalid SSL Context Verify Depth
#define DICOM_ERROR_TLS_INVALID_CTX_VERIFY_MODE                      194   // Error TLS Invalid SSL Context Verify Mode
#define DICOM_ERROR_TLS_INVALID_CTX_CAFILE                           195   // Error TLS Invalid SSL Context CA File
#define DICOM_ERROR_TLS_INVALID_CTX_OPTIONS                          196   // Error TLS Invalid SSL Context Options
                                                           
#define DICOM_ERROR_DICOMDIR_FOLDER                                  200   // The destination folder of the DICOMDIR File is not specified, or the specified folder does not exist
#define DICOM_ERROR_FILE                                             201   // The file does not reside in the destination folder of the DICOMDIR File or in a sub folder of it, or the file does not exist
#define DICOM_ERROR_FILEID                                           202   // The File ID of the specified file is invalid. Refer to the RejectInvalidFileID property for more information
#define DICOM_ERROR_J2K_LOCKED                                       203   // J2K support is locked
#define DICOM_ERROR_LUT_DESCRIPTOR_MISSING                           204   // LUT descriptor is missing
#define DICOM_ERROR_MODALITY_LUT_MISSING                             205   // Modality LUT is missing
#define DICOM_ERROR_BAD_PIXEL_REPRESENTATION                         206   // Bad pixel representation
#define DICOM_ERROR_PALETTECOLORLUTDATAMISSING                       207   // Palette color LUT is missing
#define DICOM_ERROR_FEATURE_NOT_SUPPORTED                            208   // Feature not supported
#define DICOM_ERROR_VOI_LUT_MISSING                                  209   // VOI LUT is missing
#define DICOM_ERROR_OVERLAY_ATTRIBUTES_MISSING                       210   // Overlay attributes are missing
#define DICOM_ERROR_OVERLAY_ACTIVATIONLAYER_MISSING                  211   // Overlay activation layer element is missing
#define DICOM_ERROR_OVERLAY_DATA_MISSING                             212   // Overlay data element is missing
#define DICOM_ERROR_INVALID_STRUCT_SIZE                              213   // Invalid structure size
#define DICOM_ERROR_NULL_PTR                                         214   // NULL pointer
#define DICOM_ERROR_LTIMG_MISSING                                    215   // LTIMG DLL is missing
#define DICOM_ERROR_CRYPTO_LIB_LOAD_FAILED                           216   // Failed to load the underlying cryptographic library
#define DICOM_ERROR_INVALID_MAC_TRANSFER_SYNTAX                      217   // Unable to change to the MAC Calculation Transfer Syntax
#define DICOM_ERROR_PRIVATE_KEY_LOAD_FAILED                          218   // Failed to load the private key from the specified file
#define DICOM_ERROR_CERTIFICATE_LOAD_FAILED                          219   // Failed to load the digital certificate from the specified file
#define DICOM_ERROR_CERTIFICATE_READ_FAILED                          220   // Failed to read the digital certificate from the Data Set
#define DICOM_ERROR_KEYS_MISMATCH                                    221   // The specified private key does not match the public key in the specified digital certificate
#define DICOM_ERROR_INVALID_MAC_ALGORITHM                            222   // The specified Digital Signature Security Profile does not allow the use of the specified MAC Algorithm
#define DICOM_ERROR_INVALID_ENCRYPTION_ALGORITHM                     223   // The specified Digital Signature Security Profile does not allow the use of the encryption algorithm implied by the specified keys
#define DICOM_ERROR_MAC_ID_NUMBER_ALLOCATE_FAILED                    224   // All possible values for the MAC ID Number are already used in the associated MAC Parameters Sequence
#define DICOM_ERROR_CRYPTO_LIB_FAILURE                               225   // The underlying cryptographic library failed
#define DICOM_ERROR_MAC_PARAMETER_MISSING                            226   // Failed to verify the Digital Signature because one or more of the MAC Parameters are missing
#define DICOM_ERROR_MAC_ID_NUMBER_MISSING                            227   // Failed to verify the Digital Signature because no MAC Parameters Sequence Item is referenced
#define DICOM_ERROR_UNKNOWN_MAC_ALGORITHM                            228   // Failed to verify the Digital Signature because the specified MAC Algorithm is unknown
#define DICOM_ERROR_SIGNATURE_MISSING                                229   // Failed to verify the Digital Signature because the Signature is missing
#define DICOM_ERROR_INVALID_SIGNATURE                                230   // The Digital Signature is invalid or at least one of the Digital Signatures in the Data Set is invalid
#define DICOM_ERROR_CMP_FILTER_MISSING                               231   // LFCMP DLL is missing
#define DICOM_ERROR_J2K_FILTER_MISSING                               232   // LFJ2K DLL is missing
#define DICOM_ERROR_CANT_REPLACE_EXISTING_CHARACTER_SET              233   // Cannot replace existing character set
#define DICOM_ERROR_DIR_STOP_INSERT_FILE                             234   // Unable to insert data set into DICOMDIR

// V16 errors
#define DICOM_ERROR_PRIVATE_CREATOR_GROUP_INVALID                    235   // Private creator group number is invalid
#define DICOM_ERROR_PRIVATE_CREATOR_DATA_ELEMENT_ALREADY_EXISTS      236   // Private creator data element already exists
#define DICOM_ERROR_PRIVATE_CREATOR_DATA_ELEMENT_MISSING             237   // Private creator data element is missing
#define DICOM_ERROR_PRIVATE_CREATOR_ELEMENTS_ALL_ALLOCATED           238   // All private creator elements have been allocated for this group
#define DICOM_ERROR_PRIVATE_CREATOR_ELEMENT_INVALID                  239   // Private creator group number is invalid

#define DICOM_ERROR_ENCAPSULATED_DOCUMENT_MISSING                    240   // Encapsulated document is missing
#define DICOM_ERROR_INVALID_ELEMENT_LENGTH                           241   // Element length is invalid
#define DICOM_ERROR_ENCAPSULATED_DOCUMENT_FAILURE                    242   // Failed to extract the encapsulated document
#define DICOM_ERROR_ENCAPSULATED_DOCUMENT_INVALID_TYPE               243   // Type must be ENCAPSULATED_DOCUMENT_PDF or ENCAPSULATED_DOCUMENT_CDA

#define DICOM_ERROR_PRINTSCU_CLASS_NOT_SUPPORTED                     301   // The required SOP/Meta SOP Class is not supported on the Association (refer to the method itself)
#define DICOM_ERROR_PRINTSCU_TIME_OUT                                302   // Timed out (refer to the Timeout property)
#define DICOM_ERROR_PRINTSCU_ASSOCIATE_RQ_REJECTED                   303   // The Association request was rejected by the Print SCP (refer to the Associate method)
#define DICOM_ERROR_PRINTSCU_FAILURE_STATUS                          304   // The response of the Print SCP specifies a Failure status code (the operation was not performed)
#define DICOM_ERROR_SOP_INSTANCE_UID_ALREADY_EXISTS                  305   // SOP Instance UID already present

// V17 Errors
#define DICOM_ERROR_INCOMPATIBLE_LIST_OF_IMAGES                      306   // When inserting images into a DICOM dataset, the bbp, width, height must all be the same for each image
#define DICOM_IPV4_IPV6_CONFLICT                                     307   // Both IPv4 and IPv6 addresses have been passed to the same function
#define DICOM_ERROR_JLS_FILTER_MISSING                               308   // LFJLS DLL is missing

// V17.5 Errors
#define DICOM_ERROR_XML_INVALID_FORMAT                               400   // LeadDicomTables XML file contains invalid XML 
#define DICOM_ERROR_XML_MODULE_LIST_MISSING                          401   // LeadDicomTables XML file missing the moduleList section
#define DICOM_ERROR_XML_INVALID_IOD_LIST                             402   // LeadDicomTables XML iodList section is invalid
#define DICOM_ERROR_XML_INVALID_IOD_MODULE_ITEM                      403   // LeadDicomTables XML file IOD entry contains an invalid module
#define DICOM_ERROR_XML_MODULE_NOT_FOUND                             404   // LeadDicomTables XML file IOD entry references an module that is not defined in the moduleList
#define DICOM_ERROR_XML_INVALID_MODULE_ELEMENT                       405   // LeadDicomTables XML file moduleList contains an invalid element
#define DICOM_ERROR_XML_INVALID_MODULE_LIST                          406   // LeadDicomTables XML moduleList section is invalid
#define DICOM_ERROR_XML_INVALID_MODULELIST_MODULE_ATTRIBUTE          407   // LeadDicomTables XML moduleList 'Module' contains an invalid attribute
#define DICOM_ERROR_XML_INVALID_IODLIST_MODULE_ATTRIBUTE             408   // LeadDicomTables XML moduleList 'Module' contains an invalid attribute
#define DICOM_ERROR_XML_INVALID_IODLIST_IOD_ATTRIBUTE                409   // Invalid IOD List IOD Attribute
#define DICOM_ERROR_XML_INVALID_ELEMENTLIST                          410   // Invalid Element List
#define DICOM_ERROR_XML_INVALID_ELEMENTLIST_ITEM_ATTRIBUTE           411   // Invalid Element List Item Attribute
#define DICOM_ERROR_XML_INVALID_UIDLIST_ITEM_ATTRIBUTE               412   // Invalid UID List Item Attribute

#define DICOM_ERROR_XML_INVALID_CONCEPT_GROUP_LIST                   413   // LeadDicomTables XML context group section is invalid
#define DICOM_ERROR_XML_INVALID_CONTEXT_GROUP_ATTRIBUTE              414   // Invalid Context Group Attribute
#define DICOM_ERROR_XML_INVALID_CODEDCONCEPT_ATTRIBUTE               415   // Invalid Code Concept Attribute

#define DICOM_ERROR_ELEMENT_ALREADY_EXISTS                           416   // DICOM element already exists

#define DICOM_ERROR_TRANSFER_SYNTAX_NOT_SUPPORTED                    417   // Transfer Syntax not supported

#define DICOM_ERROR_CANCELED                                         418   // Process was canceled

// v18 errors
#define DICOM_ERROR_CLASS_NOT_FOUND                                  419   // Class not found

// v19 errors
#define DICOM_ERROR_JP2_FILTER_MISSING                               420   // LTJP2 DLL is missing
#define DICOM_ERROR_TOO_MANY_OPEN_FILES                              421   // Too many open file handles
#define DICOM_ERROR_DISK_FULL                                        422   // Not enough space on disk
#define DICOM_ERROR_NET_HOST_UN_REACH                                423   // Remote host is not reachable from this host

#define DICOM_ERROR_LTFIL_MISSING                                    424   // LTFIL DLL is missing

#define DICOM_ERROR_CLASS_NOT_SUPPORTED                              425   // Class not supported -- used with C-GET

// Be sure to update this when you add new DICOM Error Codes.
#define DICOM_ERROR_LAST                                             425
