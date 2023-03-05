//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTDIC_H)
#define LTDIC_H

#if defined(__cplusplus)
#  if defined(_LEAD_DICOM_NO_EXP_IMP)
#     define  DICOM_EXPORT
#  else
#     if defined(_LEAD_DICOM_)
#        define  DICOM_EXPORT __declspec(dllexport)
#     else
#        define  DICOM_EXPORT __declspec(dllimport)
#     endif   
#  endif // #if defined(_LEAD_DICOM_NO_EXP_IMP)
#endif // #if defined(__cplusplus)

#include "lttyp.h"
#if !defined(L_LTDIC_API)
#  define L_LTDIC_API LT_EXPORTED
#endif

#if !defined(L_LTDIC_CLASS)
#  define L_LTDIC_CLASS DICOM_EXPORT
#endif // #if !defined(L_LTDIC_CLASS)

#include "ltfil.h"
#include "ltann.h"

#define pWRPEXT_CALLBACK pEXT_FUNCTION

#include "ltdicerrors.h"

#pragma pack(8)

//For extended debug functionality
#define DEBUG_MODE_ONSEND_SHOW_EXTENDED_INFO    0x00000001
#define DEBUG_MODE_ONRECEIVE_SHOW_EXTENDED_INFO 0x00000002

#if defined(FOR_UNIX)
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <stdbool.h>
#endif

// Added for 64-bit types - or 8 bytes values, used in encryption, as keys etc
// and for TLS primitive data
typedef const L_CHAR* L_PCSTR;
typedef const L_TCHAR* L_PCTSTR;
struct ssl_st;
typedef struct ssl_st SSL;

struct ssl_ctx_st;
typedef struct ssl_ctx_st SSL_CTX;
typedef L_VOID *pSSL_CONF_CTX;

typedef SSL_CTX L_SSL_CTX;

#define L_DICOM_OFFSET L_INT64

#define L_SSL_OP_NO_SSLv2              0x01000000L
#define L_SSL_OP_NO_SSLv3              0x02000000L
#define L_SSL_OP_NO_TLSv1              0x04000000L


#define L_SSL_OP_NO_TLSv1_2                               0x08000000L
#define L_SSL_OP_NO_TLSv1_1                               0x10000000L
#define L_SSL_OP_NO_COMPRESSION                           0x00020000L


// This SSL_OP_ALL flag changed in later versions of OpenSSL (0.9.7)
// LEAD uses a later version in v19
#define L_SSL_OP_ALL                   0x80000BFFL

// flags
#define FLAG_SSL_CTX_PRECREATE_METHOD_TYPE   0x001
#define FLAG_SSL_CTX_PRECREATE_ALL           0x001

#define L_SSL_VERIFY_NONE                 0x00
#define L_SSL_VERIFY_PEER                 0x01
#define L_SSL_VERIFY_FAIL_IF_NO_PEER_CERT 0x02
#define L_SSL_VERIFY_CLIENT_ONCE          0x04
#define L_SSL_VERIFY_ALL                  0x07

#define FLAG_SSL_CTX_CREATE_METHOD_TYPE      0x001
#define FLAG_SSL_CTX_CREATE_VERIFY_DEPTH     0x002
#define FLAG_SSL_CTX_CREATE_VERIFY_MODE      0x004
#define FLAG_SSL_CTX_CREATE_CAFILE           0x008
#define FLAG_SSL_CTX_CREATE_OPTIONS          0x010
#define FLAG_SSL_CTX_CREATE_ALL              0x01F

// flags for Listen and Connect
#define DICOM_IPTYPE_NONE                      0x000    // 0
#define DICOM_IPTYPE_IPV4                      0x001    // only use IPV4 addresses
#define DICOM_IPTYPE_IPV6                      0x002    // only use IPV6 addresses
#define DICOM_IPTYPE_IPV4_OR_IPV6              0x003    // use IPV4 or IPV6 addresses

typedef struct tagSSL_CTX_CREATE
{
   L_UINT        uStructSize;
   L_UINT32      uFlags;
   L_INT         nMethodTypeSSL;  //TYPE_SSLV2_METHOD, TYPE_SSLV3_METHOD, TYPE_TLSV1_METHOD, TYPE_SSLV23_METHOD
   L_TCHAR       *pszCAfile;
   L_UINT        uVerifyMode;
   L_INT         nVerifyDepth;
   L_INT         nOptions;        //L_SSL_OP_NO_SSLv2, L_SSL_OP_NO_SSLv3, L_SSL_OP_NO_TLSv1
   L_INT         nSuccess;        // DICOM_SUCCESS, or reason for failure
   L_INT         nReserved1;
   L_INT         nReserved2;
} L_SSL_CTX_CREATE, *pL_SSL_CTX_CREATE;


struct x509_store_st;
typedef struct x509_store_ctx_st X509_STORE_CTX;
typedef int (*TLS_CERT_VERIFY_CALLBACK)(int ok,X509_STORE_CTX *ctx);


typedef struct tagDICOMOPENSSLVERSION
{
   L_UINT        uStructSize;
   L_UINT32      uFlags;
   L_TCHAR       szRequiredVersion[32];
   L_TCHAR       szInstalledVersion[32];
   L_BOOL        bIsAvailable;
   L_TCHAR       szDownloadMessage[512];
} DICOMOPENSSLVERSION, *pDICOMOPENSSLVERSION;


// end of added for 64bit types and TLS primitives


// added for secure extension

#define DICOM_SECURE_NONE  0xABCD0000
#define DICOM_SECURE_ISCL  0xABCD0001
#define DICOM_SECURE_TLS   0xABCD0002

// end of added for secure extension

// added for TLS compliance

#define MAX_CIPHERSUITE_COUNT (16)

enum _L_CIPHERSUITE
{
   L_TLS_DHE_RSA_WITH_DES_CBC_SHA        = 0x12, // EDH-RSA-DES-CBC-SHA
   L_TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA   = 0x13, // EDH-RSA-DES-CBC3-SHA -- mandatory standard
   L_TLS_DHE_RSA_AES256_SHA              = 0x14, // DHE-RSA-AES256-SHA

   // TLS 1.0
   L_TLS_RSA_WITH_AES_128_CBC_SHA        = 0x15,
   L_TLS_RSA_WITH_3DES_EDE_CBC_SHA       = 0x16,
      
   // TLS 1.2
   L_TLS_DHE_RSA_WITH_AES_128_GCM_SHA256        = 0x17,
   L_TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256      = 0x18,
   L_TLS_DHE_RSA_WITH_AES_256_GCM_SHA384        = 0x19,
   L_TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384      = 0x1A,
};

#if !defined(FOR_XCODE)
#   define TLS_DHE_RSA_WITH_DES_CBC_SHA L_TLS_DHE_RSA_WITH_DES_CBC_SHA
#   define TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA L_TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
#   define TLS_DHE_RSA_AES256_SHA L_TLS_DHE_RSA_AES256_SHA
#   define TLS_RSA_WITH_AES_128_CBC_SHA L_TLS_RSA_WITH_AES_128_CBC_SHA
#   define TLS_RSA_WITH_3DES_EDE_CBC_SHA L_TLS_RSA_WITH_3DES_EDE_CBC_SHA
#   define TLS_DHE_RSA_WITH_AES_128_GCM_SHA256 L_TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
#   define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256 L_TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
#   define TLS_DHE_RSA_WITH_AES_256_GCM_SHA384 L_TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
#   define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384 L_TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
#endif

typedef enum _L_CIPHERSUITE L_CIPHERSUITE;

enum _L_ENCRYPTION_METHOD
{
   L_CRYPT_NONE     = 0x00,
   L_CRYPT_DES      = 0x01,
   L_CRYPT_3DES     = 0x02,
   L_CRYPT_RC4      = 0x03,
   L_CRYPT_RC2      = 0x04,
   L_CRYPT_IDEA     = 0x05,
   L_CRYPT_FORTEZZA = 0x06,
   L_CRYPT_AES      = 0x07,
};

typedef enum _L_ENCRYPTION_METHOD L_ENCRYPTION_METHOD;

enum _L_MAC_METHOD
{
   L_MAC_NONE  = 0x00,
   L_MAC_SHA1  = 0x10,
   L_MAC_MD5   = 0x11,
};

typedef enum _L_MAC_METHOD L_MAC_METHOD;

enum _L_MUTUAL_AUTH_METHOD
{
   L_MUTUALAUTH_NONE = 0,
   L_MUTUALAUTH_RSA = 0x20,
   L_MUTUALAUTH_DSS = 0x21,
   L_MUTUALAUTH_DH  = 0x022,
};

typedef enum _L_MUTUAL_AUTH_METHOD L_MUTUAL_AUTH_METHOD;

enum _L_KEY_EXCHANGE_METHOD
{
   L_KEYEXCHANGE_NONE = 0x00,
   L_KEYEXCHANGE_RSA_SIGNED_DHE = 0x40,
   L_KEYEXCHANGE_RSA = 0x41,
   L_KEYEXCHANGE_DH = 0x42,
   L_KEYEXCHANGE_DH_DSS = 0x43,
   L_KEYEXCHANGE_FORTEZZA = 0x44,
};

typedef enum _L_KEY_EXCHANGE_METHOD L_KEY_EXCHANGE_METHOD;

enum _SSL_METHOD_TYPE 
{
   TYPE_SSLV2_METHOD    = 0x01, 
   TYPE_SSLV3_METHOD    = 0x02, 
   TYPE_TLSV1_METHOD    = 0x03, 
   TYPE_SSLV23_METHOD   = 0x04,
   TYPE_TLS_METHOD      = 0x05,     // Supports TLSv1.2
};

typedef enum _SSL_METHOD_TYPE SSL_METHOD_TYPE;

// Error Numbers for LDicomNet::OnVerify(L_INT ok, L_TCHAR *pszCertificateString, L_INT nError, L_TCHAR *pszErrorString);
#define         L_X509_V_OK                                       0
#define         L_X509_V_ERR_UNSPECIFIED                          1
#define         L_X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT            2
#define         L_X509_V_ERR_UNABLE_TO_GET_CRL                    3
#define         L_X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE     4
#define         L_X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE      5
#define         L_X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY   6
#define         L_X509_V_ERR_CERT_SIGNATURE_FAILURE               7
#define         L_X509_V_ERR_CRL_SIGNATURE_FAILURE                8
#define         L_X509_V_ERR_CERT_NOT_YET_VALID                   9
#define         L_X509_V_ERR_CERT_HAS_EXPIRED                     10
#define         L_X509_V_ERR_CRL_NOT_YET_VALID                    11
#define         L_X509_V_ERR_CRL_HAS_EXPIRED                      12
#define         L_X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD       13
#define         L_X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD        14
#define         L_X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD       15
#define         L_X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD       16
#define         L_X509_V_ERR_OUT_OF_MEM                           17
#define         L_X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT          18
#define         L_X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN            19
#define         L_X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY    20
#define         L_X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE      21
#define         L_X509_V_ERR_CERT_CHAIN_TOO_LONG                  22
#define         L_X509_V_ERR_CERT_REVOKED                         23
#define         L_X509_V_ERR_INVALID_CA                           24
#define         L_X509_V_ERR_PATH_LENGTH_EXCEEDED                 25
#define         L_X509_V_ERR_INVALID_PURPOSE                      26
#define         L_X509_V_ERR_CERT_UNTRUSTED                       27
#define         L_X509_V_ERR_CERT_REJECTED                        28
#define         L_X509_V_ERR_SUBJECT_ISSUER_MISMATCH              29
#define         L_X509_V_ERR_AKID_SKID_MISMATCH                   30
#define         L_X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH          31
#define         L_X509_V_ERR_KEYUSAGE_NO_CERTSIGN                 32
#define         L_X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER             33
#define         L_X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION         34
#define         L_X509_V_ERR_KEYUSAGE_NO_CRL_SIGN                 35
#define         L_X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION     36
#define         L_X509_V_ERR_INVALID_NON_CA                       37
#define         L_X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED           38
#define         L_X509_V_ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE        39
#define         L_X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED       40
#define         L_X509_V_ERR_INVALID_EXTENSION                    41
#define         L_X509_V_ERR_INVALID_POLICY_EXTENSION             42
#define         L_X509_V_ERR_NO_EXPLICIT_POLICY                   43
#define         L_X509_V_ERR_DIFFERENT_CRL_SCOPE                  44
#define         L_X509_V_ERR_UNSUPPORTED_EXTENSION_FEATURE        45
#define         L_X509_V_ERR_UNNESTED_RESOURCE                    46
#define         L_X509_V_ERR_PERMITTED_VIOLATION                  47
#define         L_X509_V_ERR_EXCLUDED_VIOLATION                   48
#define         L_X509_V_ERR_SUBTREE_MINMAX                       49
#define         L_X509_V_ERR_APPLICATION_VERIFICATION             50
#define         L_X509_V_ERR_UNSUPPORTED_CONSTRAINT_TYPE          51
#define         L_X509_V_ERR_UNSUPPORTED_CONSTRAINT_SYNTAX        52
#define         L_X509_V_ERR_UNSUPPORTED_NAME_SYNTAX              53
#define         L_X509_V_ERR_CRL_PATH_VALIDATION_ERROR            54
#define         L_X509_V_ERR_SUITE_B_INVALID_VERSION              56
#define         L_X509_V_ERR_SUITE_B_INVALID_ALGORITHM            57
#define         L_X509_V_ERR_SUITE_B_INVALID_CURVE                58
#define         L_X509_V_ERR_SUITE_B_INVALID_SIGNATURE_ALGORITHM  59
#define         L_X509_V_ERR_SUITE_B_LOS_NOT_ALLOWED              60
#define         L_X509_V_ERR_SUITE_B_CANNOT_SIGN_P_384_WITH_P_256 61
#define         L_X509_V_ERR_HOSTNAME_MISMATCH                    62
#define         L_X509_V_ERR_EMAIL_MISMATCH                       63
#define         L_X509_V_ERR_IP_ADDRESS_MISMATCH                  64
#define         L_X509_V_ERR_INVALID_CALL                         65
#define         L_X509_V_ERR_STORE_LOOKUP                         66
#define         L_X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION         67


#if !defined(FOR_BORLAND)
// typedef enum _DICOM_TLS_ERRORS DICOM_TLS_ERRORS;
#endif // #if !defined(FOR_BORLAND)

#define L_TLS_FILETYPE_PEM    1
#define L_TLS_FILETYPE_ASN1   2

// use either SSL_VERIFY_NONE or SSL_VERIFY_PEER, the last 2 options
// are 'ored' with SSL_VERIFY_PEER if they are desired
#define L_TLS_VERIFY_NONE        0x00
#define L_TLS_VERIFY_PEER        0x01
#define L_TLS_VERIFY_FAIL_IF_NO_PEER_CERT 0x02
#define L_TLS_VERIFY_CLIENT_ONCE    0x04

extern L_INT nVerifyCertDepth;
extern L_INT nVerifyCertError;
// end of added for TLS


// added for ISCL compliance 

#define DC_MSG_IN_QUEUE    0xDC00

#define DESCBC_CHAIN_IVEC_OVER_SIGNATURE  1
#define DESCBC_CHAIN_IVEC_OVER_MESSAGES   1


// Magical constants:


#define DICOM_ISCL_MAX_PACKET_SIZE        (8160)     // set with manual values
#define DICOM_ISCL_MAX_MESSAGE_SIZE       (1048576)   // set with manual values


      // values specified in ISCL standard
#define DICOM_ISCL_ACK                    0x00000000
#define DICOM_ISCL_NAK                    0xFFFFFFFF

#define DICOM_ISCL_MUTUAL_AUTH_3P4W       0x00000000  // three pass four way mutual auth

#define DICOM_ISCL_ENCRYPT_NONE           0x00000000
#define DICOM_ISCL_ENCRYPT_DESCBC         0x00001212

#define DICOM_ISCL_MAC_NONE               0x00000000
#define DICOM_ISCL_MAC_MD5                0x00001441
#define DICOM_ISCL_MAC_DESMAC             0x00004001

#define DICOM_ISCL_LINE_CONNECTION_CHECK_RQ     0x00110001  // RQ - request, RP - response
#define DICOM_ISCL_LINE_CONNECTION_CHECK_RP     0x00110003
#define DICOM_ISCL_MUTUAL_AUTH_RQ               0x00120001
#define DICOM_ISCL_MUTUAL_AUTH_RP               0x00120003
#define DICOM_ISCL_MUTUAL_AUTH_PASS1_NOTIF      0x00130002
#define DICOM_ISCL_MUTUAL_AUTH_PASS2_NOTIF      0x00140002
#define DICOM_ISCL_MUTUAL_AUTH_PASS3_NOTIF      0x00150002
#define DICOM_ISCL_MUTUAL_AUTH_COMPLETION_NOTIF 0x00160002
#define DICOM_ISCL_MESSAGE_TRANSMISSION_RQ      0x00200001
#define DICOM_ISCL_MESSAGE_TRANSMISSION_RP      0x00200003
#define DICOM_ISCL_RNDNO_FOR_SESSION_KEY_RQ     0x00210001
#define DICOM_ISCL_RNDNO_FOR_SESSION_KEY_RP     0x00210003
#define DICOM_ISCL_MESSAGE_TRANSMISSION_NOTIF   0x00200002
#define DICOM_ISCL_MAC_TRANSMISSION_NOTIF       0x00230002
#define DICOM_ISCL_THROUGH_MODE_TRANSMISSION_NOTIF 0x00260002
#define DICOM_ISCL_LINE_DISCONNECTION_RQ        0x00FF0001
#define DICOM_ISCL_LINE_DISCONNECTION_RP        0x00FF0003


enum DICOM_ISCLAuthKeyPair
{
   DICOM_ISCL_AUTH_KEY_PAIR1 = 0x00000001,
   DICOM_ISCL_AUTH_KEY_PAIR2 = 0x00000002,
   DICOM_ISCL_AUTH_KEY_PAIR3 = 0x00000003,
   DICOM_ISCL_AUTH_KEY_PAIR4 = 0x00000004,
   DICOM_ISCL_AUTH_KEY_PAIR5 = 0x00000005,
   DICOM_ISCL_AUTH_KEY_PAIR6 = 0x00000006,
   DICOM_ISCL_AUTH_KEY_PAIR7 = 0x00000007,
   DICOM_ISCL_AUTH_KEY_PAIR8 = 0x00000008
};

enum DICOM_ISCLCryptKeyPair
{
   DICOM_ISCL_CRYPT_KEY_PAIR1 = 0x00000001,
   DICOM_ISCL_CRYPT_KEY_PAIR2 = 0x00000002,
   DICOM_ISCL_CRYPT_KEY_PAIR3 = 0x00000003,
   DICOM_ISCL_CRYPT_KEY_PAIR4 = 0x00000004,
   DICOM_ISCL_CRYPT_KEY_PAIR5 = 0x00000005,
   DICOM_ISCL_CRYPT_KEY_PAIR6 = 0x00000006,
   DICOM_ISCL_CRYPT_KEY_PAIR7 = 0x00000007,
   DICOM_ISCL_CRYPT_KEY_PAIR8 = 0x00000008,
   DICOM_ISCL_UNIQUE_SESSION_KEYS = 0x00000010
};

      // header of ISCL messages
struct DICOM_ISCLMessageHeader
{
   L_UINT32 Indicator;    // not used
   L_UINT32 MessageId;    // type of message
   L_UINT32 nDataLength;  // number of bytes in message (excluding header)
   L_UINT32 Option;       // options belonging to the message block
   L_UINT32 timeStamp;    // not used
   L_UINT32 nErrNo;       // not used
   L_UINT32 stuff1, stuff2;  // to align msg header to 32 bytes, not used
};




// end of added for ISCL compliance


//============= TYPES ==========================================================

//============= VARIABLES ======================================================

//============= CLASS ==========================================================

#define DICOM_FILE_OPEN          0x0000
#define DICOM_FILE_CREATE        0x0001
#define DICOM_FILE_READ          0x0002
#define DICOM_FILE_WRITE         0x0004
#define DICOM_FILE_TEMPORARY     0x0008
#define DICOM_FILE_MEMORY        0x0010
#define DICOM_FILE_REDIRECT      0x0020
#define DICOM_FILE_CLOSE         0x0040
#define DICOM_FILE_DELETE        0x0080

#define DICOM_FILE_USER_MEMORY   0x1000 // Internal Use
#define DICOM_FILE_READ_ONLY     0x2000 // Internal Use




#define DICOM_FILE_BEGIN      0
#define DICOM_FILE_CURRENT    1
#define DICOM_FILE_END        2


#if !defined(EXCLUDE_DICOM_FUNCTIONS)
#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomFile
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   LDicomFile();
   ~LDicomFile();

   L_BOOL   Open      (L_TCHAR *pszName, L_UINT16 nMode);
   L_VOID   Close     (L_BOOL bComplete);
   L_BOOL   Read      (L_VOID *pBuffer, L_UINT32 nLength);
   L_BOOL   Write     (L_VOID *pBuffer, L_UINT32 nLength);
   L_BOOL   Seek      (L_OFFSET nOffset, L_UINT16 nWhere);
   L_OFFSET Tell      ();
   L_VOID   SetHandle (L_HFILE hFile, L_UINT16 nMode);
   L_BOOL   SetHandleCreateRedirected(L_HFILE hFile);
   L_BOOL   SetMemoryBuffer(L_UCHAR *pBuffer, L_SIZE_T uLength, L_BOOL bReadonly);
   L_UINT16 ChangeMode(L_UINT16 nMode);
   L_UINT16 GetMode();

   L_OFFSET GetRemainingBytes();

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
private:
   L_TCHAR   m_szName[_MAX_PATH];
   L_HFILE   m_hFile;
   L_UINT16  m_nMode;
   L_OFFSET  m_nLength;
   L_OFFSET  m_nOffset;
   L_UCHAR  *m_pBuffer;
public:
   L_HFILE GetHandle(){return m_hFile;}
};

#endif // #if defined(__cplusplus)

//============= CLASS ==========================================================

#define GENERICLINK  pDICOMLINK pParent;     \
                     pDICOMLINK pFirstChild; \
                     pDICOMLINK pLastChild;  \
                     pDICOMLINK pPrev;       \
                     pDICOMLINK pNext;       \

typedef struct _DICOMLINK *pDICOMLINK;

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomTree
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   LDicomTree();
   ~LDicomTree();

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   pDICOMLINK  Insert    (pDICOMLINK pNeighbor, L_UINT32 nSize, L_UINT16 nFlags);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   L_VOID      Delete    (pDICOMLINK pLink);

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   pDICOMLINK  GetRoot   (pDICOMLINK pLink);
   pDICOMLINK  GetParent (pDICOMLINK pLink);
   pDICOMLINK  GetChild  (pDICOMLINK pLink);
   pDICOMLINK  GetFirst  (pDICOMLINK pLink, L_BOOL bTree);
   pDICOMLINK  GetLast   (pDICOMLINK pLink, L_BOOL bTree);
   pDICOMLINK  GetPrev   (pDICOMLINK pLink, L_BOOL bTree);
   pDICOMLINK  GetNext   (pDICOMLINK pLink, L_BOOL bTree);
   L_UINT32    GetLevel  (pDICOMLINK pLink);
   L_UINT32    GetCount  (pDICOMLINK pLink, L_BOOL bTree);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   pDICOMLINK  FindIndex (pDICOMLINK pLink, L_BOOL bTree, L_UINT32 nIndex);
   L_BOOL      Exists    (pDICOMLINK pLink);
   pDICOMLINK  Verify    ();

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
protected:
   pDICOMLINK m_pFirstChild;
   pDICOMLINK m_pLastChild;
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
class L_LTDIC_CLASS LDicomTreeEx : public LDicomTree
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   LDicomTreeEx();
   ~LDicomTreeEx();
   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   pDICOMLINK  Insert    (pDICOMLINK pNeighbor, L_UINT32 nSize, L_UINT16 nFlags);
   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   L_VOID      Delete    (pDICOMLINK pLink);
};
#endif // #if defined(__cplusplus)

//============= CLASS ==========================================================
#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

//---------------------------------------------------------------------------
// Initializing Functions
// (Undocumented Functions and Internal use only)
//---------------------------------------------------------------------------
#define DICOM_ENGINE_STARTUP_NO_IOD_TABLE             0x0001U
#define DICOM_ENGINE_STARTUP_NO_CONTEXT_GROUP_TABLE   0x0002U
#define DICOM_ENGINE_STARTUP_FOR_MANAGED              0x0004U   // Internal use only

L_LTDIC_API L_VOID EXT_FUNCTION L_DicomEngineStartup(L_UINT16 uFlags);
L_LTDIC_API L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);

#if defined(__cplusplus)
}
#endif // #if defined(__cplusplus)

#endif //!defined(EXCLUDE_DICOM_FUNCTIONS)


#define VR_AE   0x4145U    // Application Entity
#define VR_AS   0x4153U    // Age String
#define VR_AT   0x4154U    // Attribute Tag
#define VR_CS   0x4353U    // Code String
#define VR_DA   0x4441U    // Date
#define VR_DS   0x4453U    // Decimal String
#define VR_DT   0x4454U    // Date Time
#define VR_FD   0x4644U    // Floating Point Double
#define VR_FL   0x464CU    // Floating Point Single
#define VR_IS   0x4953U    // Integer String
#define VR_LO   0x4C4FU    // Long String
#define VR_LT   0x4C54U    // Long Text
#define VR_OB   0x4F42U    // Other Byte String
#define VR_OL   0x4F4CU    // Other Long
#define VR_OW   0x4F57U    // Other Word String
#define VR_PN   0x504EU    // Person Name
#define VR_SH   0x5348U    // Short String
#define VR_SL   0x534CU    // Signed Long
#define VR_SQ   0x5351U    // Sequence of Items
#define VR_SS   0x5353U    // Signed Short
#define VR_ST   0x5354U    // Short Text
#define VR_TM   0x544DU    // Time
#define VR_UI   0x5549U    // Unique Identifier
#define VR_UL   0x554CU    // Unsigned Long
#define VR_UN   0x554EU    // Unknown
#define VR_US   0x5553U    // Unsigned Short
#define VR_UT   0x5554U    // Unlimited Text
#define VR_OF   0x4F46U    // Other Float String
#define VR_UR   0x5552U    // Universal Resource Identifier or Universal Resource Locator(URI/URL)

// DICOM 2015C
#define VR_UC   0x5543U    // Unlimited Characters
#define VR_OD   0x4F44U    // Other Double String

// DICOM 2021a
#define VR_OV   0x4F56U    // Other 64-bit Very Long
#define VR_SV   0x5356U    // Signed 64-bit Very Long (8 bytes fixed). Represents an integer n in the range:- 2^63 <= n <= 2^63 - 1
#define VR_UV   0x5556U    // Unsigned binary integer 64 bits long (8 bytes fixed). Represents an integer n in the range: 0 <= n < 2^64

enum
{
   VR_FIXED = 0,           // DICOMVR.nLength bytes fixed
   VR_MAXIMUM,             // DICOMVR.nLength bytes maximum
   VR_MAXIMUM_GROUP,       // DICOMVR.nLength maximum per component group
   VR_ANY,                 // DICOMVR.nLength any length valid for any of the other DICOM Value Representations
   VR_NOT_APPLICABLE,      // DICOMVR.nLength not applicable
   VR_MAX,
};

#define VR_BINARY  0x0100  // Binary value
#define VR_STRING  0x0200  // String value (The character '\' is used as the delimiter between values for multiple data elements)
#define VR_TEXT    0x0400  // Text value (Data Elements with this VR shall not be multi-valued)

//typedef struct _DICOMVR DICOMVR, *pDICOMVR;
#if !defined (EXCLUDE_DICOM_FUNCTIONS)
typedef struct _DICOMVR
{
   GENERICLINK             // Reserved - internally used only

   L_UINT16  nCode;        // Code (VR_AE, VR_AS, ...)
   L_TCHAR   *pszName;      // Name ("Application Entity", "Age String", ...)
   L_UINT32  nLength;      // Length
   L_UINT16  nRestrict;    // Restriction applied to the length
   L_UINT16  nUnitSize;    // The size for the smallest item
} DICOMVR, *pDICOMVR;

//DICOM Character Sets
enum 
{
   DICOM_CHARACTER_SET_DEFAULT               =0 ,
   DICOM_CHARACTER_SET_LATIN_ALPHABET_NO_1      ,
   DICOM_CHARACTER_SET_LATIN_ALPHABET_NO_2      ,
   DICOM_CHARACTER_SET_LATIN_ALPHABET_NO_3      ,
   DICOM_CHARACTER_SET_LATIN_ALPHABET_NO_4      ,
   DICOM_CHARACTER_SET_CYRILLIC                 ,
   DICOM_CHARACTER_SET_ARABIC                   ,
   DICOM_CHARACTER_SET_GREEK                    ,
   DICOM_CHARACTER_SET_HEBREW                   ,
   DICOM_CHARACTER_SET_LATIN_ALPHABET_NO_5      ,
   DICOM_CHARACTER_SET_JAPANESE_JIS_X_0201      ,
   DICOM_CHARACTER_SET_THAI                     ,
   DICOM_CHARACTER_SET_KOREAN                   ,
   DICOM_CHARACTER_SET_UNICODE_IN_UTF8          ,
   DICOM_CHARACTER_SET_GB18030                  ,
   DICOM_CHARACTER_SET_JAPANESE_JIS_X_0208      ,
   DICOM_CHARACTER_SET_JAPANESE_JIS_X_0212      
};

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomVR
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   static L_VOID   Default   ();

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   static pDICOMVR Insert    (L_UINT16 nCode, L_TCHAR *pszName, L_UINT32 nLength, L_UINT16 nRestrict, L_UINT16 nUnitSize);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   static pDICOMVR Delete    (pDICOMVR pVR);
   static L_VOID   Reset     ();

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   static pDICOMVR GetFirst  ();
   static pDICOMVR GetLast   ();
   static pDICOMVR GetPrev   (pDICOMVR pVR);
   static pDICOMVR GetNext   (pDICOMVR pVR);
   static L_UINT32 GetCount  ();
   static L_BOOL   Exists    (pDICOMVR pVR);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   static pDICOMVR Find      (L_UINT16 nCode);
   static pDICOMVR FindIndex (L_UINT32 nIndex);

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   static L_BOOL   SetName   (pDICOMVR pVR, L_TCHAR *pszName);

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
private:
#if 0
   static LDicomTreeEx m_InfoVR;
#else
   static LDicomTreeEx* m_pInfoVR;
   static LDicomTreeEx& GetInfoVR();
   friend L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);
   static L_BOOL HasFirst();
#endif // #if 0
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

//---------------------------------------------------------------------------
// Initializing Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomDefaultVR   (L_VOID);

//---------------------------------------------------------------------------
// Insertion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomInsertVR    (L_UINT16 nCode, L_TCHAR *pszName, L_UINT32 nLength, L_UINT16 nRestrict, L_UINT16 nUnitSize);

//---------------------------------------------------------------------------
// Deletion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomDeleteVR    (pDICOMVR pVR);
L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomResetVR     (L_VOID);

//---------------------------------------------------------------------------
// Iteration Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomGetFirstVR  (L_VOID);
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomGetLastVR   (L_VOID);
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomGetPrevVR   (pDICOMVR pVR);
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomGetNextVR   (pDICOMVR pVR);
L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetCountVR  (L_VOID);
L_LTDIC_API L_BOOL   EXT_FUNCTION L_DicomExistsVR    (pDICOMVR pVR);

//---------------------------------------------------------------------------
// Searching Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomFindVR      (L_UINT16 nCode);
L_LTDIC_API pDICOMVR EXT_FUNCTION L_DicomFindIndexVR (L_UINT32 nIndex);

//---------------------------------------------------------------------------
// Modification Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_BOOL   EXT_FUNCTION L_DicomSetNameVR   (pDICOMVR pVR, L_TCHAR *pszName);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)

//============= CLASS ==========================================================
#include "ltdicuid.h"

enum
{
   UID_TYPE_OTHER,         // Unknown
   UID_TYPE_TRANSFER1,     // Transfer Syntax - Uncompressed Image
   UID_TYPE_TRANSFER2,     // Transfer Syntax - Compressed Image
   UID_TYPE_CLASS,         // SOP Class
   UID_TYPE_META_CLASS,    // Meta SOP Class
   UID_TYPE_INSTANCE,      // SOP Instance
   UID_TYPE_APPLICATION,   // Application Context Name

   UID_TYPE_FRAME_OF_REFERENCE, // Frame of reference
   UID_TYPE_LDAP_OID,      //
};


#if !defined (EXCLUDE_DICOM_FUNCTIONS)
//typedef struct _DICOMUID DICOMUID, *pDICOMUID;
typedef struct _DICOMUID
{
   GENERICLINK          // Reserved - internally used only

   L_TCHAR  *pszCode;    // Code
   L_TCHAR  *pszName;    // Name
   L_INT    nType;      // Type
} DICOMUID, *pDICOMUID;

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomUID
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   static L_UINT16  LoadXml      (L_TCHAR *pszFile, L_UINT uFlags);
   static L_VOID    Default   ();

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   static pDICOMUID Insert    (L_TCHAR *pszCode, L_TCHAR *pszName, L_INT nType);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   static pDICOMUID Delete    (pDICOMUID pUID);
   static L_VOID    Reset     ();

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   static pDICOMUID GetFirst  ();
   static pDICOMUID GetLast   ();
   static pDICOMUID GetPrev   (pDICOMUID pUID);
   static pDICOMUID GetNext   (pDICOMUID pUID);
   static L_UINT32  GetCount  ();
   static L_BOOL    Exists    (pDICOMUID pUID);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   static pDICOMUID Find      (L_TCHAR *pszCode);
   static pDICOMUID FindIndex (L_UINT32 nIndex);

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   static L_BOOL    SetName   (pDICOMUID pUID, L_TCHAR *pszName);

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
private:
#if 0
   static LDicomTreeEx m_InfoUID;
#else
   static LDicomTreeEx* m_pInfoUID;
   static LDicomTreeEx& GetInfoUID();
   friend L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);
   static L_BOOL HasFirst();
#endif // #if 0
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

//---------------------------------------------------------------------------
// Initializing Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDefaultUID   (L_VOID);

//---------------------------------------------------------------------------
// Insertion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomInsertUID    (L_TCHAR *pszCode, L_TCHAR *pszName, L_INT nType);

//---------------------------------------------------------------------------
// Deletion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomDeleteUID    (pDICOMUID pUID);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomResetUID     (L_VOID);

L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomLoadXmlUID(L_TCHAR *pszFile, L_UINT uFlags);

//---------------------------------------------------------------------------
// Iteration Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomGetFirstUID  (L_VOID);
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomGetLastUID   (L_VOID);
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomGetPrevUID   (pDICOMUID pUID);
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomGetNextUID   (pDICOMUID pUID);
L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetCountUID  (L_VOID);
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomExistsUID    (pDICOMUID pUID);

//---------------------------------------------------------------------------
// Searching Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomFindUID      (L_TCHAR *pszCode);
L_LTDIC_API pDICOMUID EXT_FUNCTION L_DicomFindIndexUID (L_UINT32 nIndex);

//---------------------------------------------------------------------------
// Modification Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomSetNameUID   (pDICOMUID pUID, L_TCHAR *pszName);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

//============= CLASS ==========================================================

//typedef struct _DICOMTAG DICOMTAG, *pDICOMTAG;
typedef struct _DICOMTAG
{
   GENERICLINK          // Reserved - internally used only

   L_UINT32  nCode;     // Code
   L_UINT32  nMask;     // Mask (for multiple-elements specifies the same entry in the table)
   L_TCHAR   *pszName;   // Name
   L_UINT16  nVR;       // Value Representation
   L_UINT32  nMinVM;    // Minimum Value Multiplicity
   L_INT32   nMaxVM;    // Maximum Value Multiplicity
   L_UINT32  nDivideVM; // Value that should divide the Value Multiplicity
} DICOMTAG, *pDICOMTAG;

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomTag
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   static L_UINT16  LoadXml(L_TCHAR *pszFile, L_UINT uFlags);
   static L_VOID    Default   ();

   static L_VOID Default(L_BOOL bIgnorePrivateTags);

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   static pDICOMTAG Insert    (L_UINT32 nCode, L_UINT32 nMask, L_TCHAR *pszName, L_UINT16 nVR, L_UINT32 nMinVM, L_UINT32 nMaxVM, L_UINT32 nDivideVM);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   static pDICOMTAG Delete    (pDICOMTAG pTag);
   static L_VOID    Reset     ();

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   static pDICOMTAG GetFirst  ();
   static pDICOMTAG GetLast   ();
   static pDICOMTAG GetPrev   (pDICOMTAG pTag);
   static pDICOMTAG GetNext   (pDICOMTAG pTag);
   static L_UINT32  GetCount  ();
   static L_BOOL    Exists    (pDICOMTAG pTag);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   static pDICOMTAG Find      (L_UINT32 nCode);
   static pDICOMTAG FindIndex (L_UINT32 nIndex);

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   static L_BOOL    SetName   (pDICOMTAG pTag, L_TCHAR *pszName);

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
private:
#if 0
   static LDicomTreeEx m_InfoTag;
#else
   static LDicomTreeEx* m_pInfoTag;
   static LDicomTreeEx& GetInfoTag();
   friend L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);
   static L_BOOL HasFirst();
#endif // #if 0
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

//---------------------------------------------------------------------------
// Initializing Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDefaultTag   (L_VOID);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDefaultTagExt(L_BOOL bIgnorePrivateTags);

//---------------------------------------------------------------------------
// Insertion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomInsertTag    (L_UINT32 nCode, L_UINT32 nMask, L_TCHAR *pszName, L_UINT16 nVR, L_UINT32 nMinVM, L_UINT32 nMaxVM, L_UINT32 nDivideVM);

//---------------------------------------------------------------------------
// Deletion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomDeleteTag    (pDICOMTAG pTag);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomResetTag     (L_VOID);

L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomLoadXmlTag(L_TCHAR *pszFile, L_UINT uFlags);

//---------------------------------------------------------------------------
// Iteration Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomGetFirstTag  (L_VOID);
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomGetLastTag   (L_VOID);
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomGetPrevTag   (pDICOMTAG pTag);
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomGetNextTag   (pDICOMTAG pTag);
L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetCountTag  (L_VOID);
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomExistsTag    (pDICOMTAG pTag);

//---------------------------------------------------------------------------
// Searching Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomFindTag      (L_UINT32 nCode);
L_LTDIC_API pDICOMTAG EXT_FUNCTION L_DicomFindIndexTag (L_UINT32 nIndex);

//---------------------------------------------------------------------------
// Modification Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomSetNameTag   (pDICOMTAG pTag, L_TCHAR *pszName);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)


#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)

#include "ltdictags.h"

// For backward compatibility
#define TAG_UNDEFINED_TYPE                                  0x000000000L
//#define TAG_CONTRIBUTION_DATETIME                           TAG_CONTRIBUTION_DATE_TIME
#define TAG_END_MESSAGE_SET                                 TAG_END_MESSAGE_ID
//#define TAG_NORMAL_REVERSE                                  TAG_NOR_REV
#define TAG_OLD_MAGNIFICATION_TYPE                          TAG_COMMAND_MAGNIFICATION_TYPE
#define TAG_NUCLEAR_MEDICINE_SERIES_TYPE_RETIRED            TAG_NUCLEAR_MEDICINE_SERIES_TYPE
#define TAG_ADMITTING_DIAGNOSIS_CODE_SEQUENCE               TAG_ADMITTING_DIAGNOSES_CODE_SEQUENCE
#define TAG_REFERENCED_STUDY_COMPONENT_SEQUENCE             TAG_REFERENCED_PERFORMED_PROCEDURE_STEP_SEQUENCE
#define TAG_TRANSDUCER_POSITION_RETIRED                     TAG_TRANSDUCER_POSITION
#define TAG_TRANSDUCER_ORIENTATION_RETIRED                  TAG_TRANSDUCER_ORIENTATION
#define TAG_ANATOMIC_STRUCTURE_RETIRED                      TAG_ANATOMIC_STRUCTURE
#define TAG_CONTRAST_ALLERGIES                              TAG_ALLERGIES
//#define TAG_INTERVENTION_DRUG_CODE_SEQUENCE                 TAG_INTERVENTION_DRUG_SEQUENCE
#define TAG_RADIONUCLIDE_RETIRED                            TAG_RADIONUCLIDE
#define TAG_ENERGY_WINDOW_CENTERLINE_RETIRED                TAG_ENERGY_WINDOW_CENTERLINE
#define TAG_ENERGY_WINDOW_TOTAL_WIDTH_RETIRED               TAG_ENERGY_WINDOW_TOTAL_WIDTH
#define TAG_INTERVENTIONAL_THERAPY_SEQUENCE                 TAG_INTERVENTION_SEQUENCE
#define TAG_INTERVENTIONAL_STATUS                           TAG_INTERVENTION_STATUS
#define TAG_EFFECTIVE_SERIES_DURATION                       TAG_EFFECTIVE_DURATION
#define TAG_SYNCHRONIZATION_FRAME_OF_REFERENCE              0x0018106BUL
//#define TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURER           TAG_SECONDARY_CAPTURE_DEVICE_MANUFACTURERS
#define TAG_HARDCOPY_DEVICE_MANFUACTURER_MODEL_NAME         TAG_HARDCOPY_DEVICE_MANUFACTURER_MODEL_NAME
#define TAG_FRAMING_TYPE                                    TAG_CARDIAC_FRAMING_TYPE
#define TAG_ROTATION_OFFSET_RETIRED                         TAG_ROTATION_OFFSET
#define TAG_IMAGE_AREA_DOSE_PRODUCT                         TAG_IMAGE_AND_FLUOROSCOPY_AREA_DOSE_PRODUCT
#define TAG_RECEIVING_COIL                                  TAG_RECEIVE_COIL_NAME
#define TAG_TRANSMITTING_COIL                               TAG_TRANSMIT_COIL_NAME
#define TAG_PHASE_ENCODING_DIRECTION                        TAG_IN_PLANE_PHASE_ENCODING_DIRECTION
#define TAG_THERMAL_INDEX                                   TAG_BONE_THERMAL_INDEX
#define TAG_REGION_LOCATION_MIN_X_0                         TAG_REGION_LOCATION_MIN_X0
#define TAG_REGION_LOCATION_MIN_Y_0                         TAG_REGION_LOCATION_MIN_Y0
#define TAG_REGION_LOCATION_MAX_X_1                         TAG_REGION_LOCATION_MAX_X1
#define TAG_REGION_LOCATION_MAX_Y_1                         TAG_REGION_LOCATION_MAX_Y1
#define TAG_REFERENCE_PIXEL_X_0                             TAG_REFERENCE_PIXEL_X0
#define TAG_REFERENCE_PIXEL_Y_0                             TAG_REFERENCE_PIXEL_Y0
#define TAG_TM_LINE_POSITION_X_0                            TAG_TM_LINE_POSITION_X0
#define TAG_TM_LINE_POSITION_Y_0                            TAG_TM_LINE_POSITION_Y0
#define TAG_TM_LINE_POSITION_X_1                            TAG_TM_LINE_POSITION_X1
#define TAG_TM_LINE_POSITION_Y_1                            TAG_TM_LINE_POSITION_Y1
#define TAG_DETECTOR_ACTIVE_DIMENSIONS                      TAG_DETECTOR_ACTIVE_DIMENSION
#define TAG_EXPOSURE_TIME_IN_NANO_S                         TAG_EXPOSURE_TIME_IN_US
#define TAG_XRAY_TUBE_CURRENT_IN_NANO_A                     TAG_X_RAY_TUBE_CURRENT_IN_UA
#define TAG_CARDIAC_TRIGGER_SEQUENCE                        TAG_CARDIAC_SYNCHRONIZATION_SEQUENCE
#define TAG_CHEMICAL_SHIFTS_MINIMUM_INTEGRATION_LIMIT       TAG_CHEMICAL_SHIFTS_MINIMUM_INTEGRATION_LIMIT_IN_HZ
#define TAG_CHEMICAL_SHIFTS_MAXIMUM_INTEGRATION_LIMIT       TAG_CHEMICAL_SHIFTS_MAXIMUM_INTEGRATION_LIMIT_IN_HZ
#define TAG_ISOTOPE_NUMBER_RETIRED                          TAG_ISOTOPE_NUMBER
#define TAG_PHASE_NUMBER_RETIRED                            TAG_PHASE_NUMBER
#define TAG_INTERVAL_NUMBER_RETIRED                         TAG_INTERVAL_NUMBER
#define TAG_TIME_SLOT_NUMBER_RETIRED                        TAG_TIME_SLOT_NUMBER
#define TAG_ANGLE_NUMBER_RETIRED                            TAG_ANGLE_NUMBER
#define TAG_TRIGGER_DELAY_TIME                              TAG_NOMINAL_CARDIAC_TRIGGER_DELAY_TIME
#define TAG_BIPLANE_ACQUISITION_SEQUENCE                    TAG_BI_PLANE_ACQUISITION_SEQUENCE
#define TAG_MASK_POINTER_RETIRED                            TAG_MASK_POINTER
#define TAG_WAVEFORM_SAMPLE_VALUE_REPRESENTATION            0x003A0103UL
#define TAG_DIFFERENTIAL_CHANNEL_SOURCE_MODIFIERS           0x003A020BUL
#define TAG_SCHEDULED_ACTION_ITEM_CODE_SEQUENCE             TAG_SCHEDULED_PROTOCOL_CODE_SEQUENCE
#define TAG_REFERENCED_STANDALONE_SOP_INSTANCE_SEQUENCE     TAG_REFERENCED_NON_IMAGE_COMPOSITE_SOP_INSTANCE_SEQUENCE
#define TAG_PERFORMED_ACTION_ITEM_SEQUENCE                  TAG_PERFORMED_PROTOCOL_CODE_SEQUENCE
#define TAG_COMMENTS_ON_THE_PERFORMED_PROCEDURE_STEPS       TAG_COMMENTS_ON_THE_PERFORMED_PROCEDURE_STEP
#define TAG_BILLING_SUPPLIES_AND_DEVICES_SEQUENCE_RETIRED   TAG_BILLING_SUPPLIES_AND_DEVICES_SEQUENCE
#define TAG_PLACER_ORDER_NUMBER_PROCEDURE_RETIRED           TAG_PLACER_ORDER_NUMBER_PROCEDURE
#define TAG_FILLER_ORDER_NUMBER_PROCEDURE_RETIRED           TAG_FILLER_ORDER_NUMBER_PROCEDURE
#define TAG_PERSONS_ADDRESS                                 TAG_PERSON_ADDRESS
#define TAG_PERSONS_TELEPHONE_NUMBERS                       TAG_PERSON_TELEPHONE_NUMBERS
#define TAG_INPUT_INFORMATIONSEQUENCE                       TAG_INPUT_INFORMATION_SEQUENCE
//#define TAG_INTER_MARKER_DISTANCE                           TAG_INTERMARKER_DISTANCE
#define TAG_TOPIC_KEY_WORDS                                 TAG_TOPIC_KEYWORDS
#define TAG_REFERENCED_VOI_LUT_BOX_SEQUENCE_RETIRED         TAG_REFERENCED_VOI_LUT_BOX_SEQUENCE
#define TAG_OVERLAY_MODE_RETIRED                            TAG_OVERLAY_MODE
#define TAG_THRESHOLD_DENSITY_RETIRED                       TAG_THRESHOLD_DENSITY
#define TAG_REFERENCED_PRINT_JOB_SEQUENCE_2120              TAG_REFERENCED_PRINT_JOB_SEQUENCE
#define TAG_TREATMENT_INTENT                                TAG_PLAN_INTENT
#define TAG_NUMBER_OF_FRACTIONS_PER_DAY                     TAG_NUMBER_OF_FRACTION_PATTERN_DIGITS_PER_DAY
#define TAG_HIGHDOSE_TECHNIQUE_TYPE                         TAG_HIGH_DOSE_TECHNIQUE_TYPE
#define TAG_AIR_KERMA_RATE_REFERENCE_DATE                   TAG_SOURCE_STRENGTH_REFERENCE_DATE
#define TAG_AIR_KERMA_RATE_REFERENCE_TIME                   TAG_SOURCE_STRENGTH_REFERENCE_TIME
#define TAG_REFERENCED_OVERLAY_SEQUENCE_50XX                TAG_CURVE_REFERENCED_OVERLAY_SEQUENCE
#define TAG_LEAD_BITMAP                                     TAG_PIXEL_DATA

#define TAG_REFERENCED_OVERLAY_GROUP                        TAG_CURVE_REFERENCED_OVERLAY_GROUP




//============= CLASS ==========================================================

enum
{
   IOD_TYPE_CLASS=0,             // Class type
   IOD_TYPE_MODULE,              // Module type
   IOD_TYPE_ELEMENT,             // Element type
   IOD_TYPE_MAX,
};

enum
{
   IOD_USAGE_M    = 0,                  // Mandatory IOD   - M - (U - Unique for key)
   IOD_USAGE_C    = 1,                  // Conditional IOD - C - (R - Required for key)
   IOD_USAGE_U    = 2,                  // Optional IOD    - U - (O - Optional for key)
   IOD_USAGE_1    = 3,                  // Mandatory IOD   - 1  (type 1)
   IOD_USAGE_1C   = 4,                  // Conditional IOD - 1C (type 1)
   IOD_USAGE_2    = 5,                  // Mandatory IOD   - 2  (type 2)
   IOD_USAGE_2C   = 6,                  // Conditional IOD - 2C (type 2)
   IOD_USAGE_3    = 7,                  // Optional IOD    - 3  (type 3)
   IOD_USAGE_MAX  = 8,
};

#if !defined (EXCLUDE_DICOM_FUNCTIONS)
//typedef struct _DICOMIOD DICOMIOD, *pDICOMIOD;
typedef struct _DICOMIOD
{
   GENERICLINK                   // Reserved - internally used only

   L_UINT32  nCode;              // Code (CLASS_CR_IMAGE, MODULE_PATIENT, TAG_STUDY_TIME, ...)
   L_TCHAR   *pszName;           // Name
   L_UCHAR   nType;              // Type (IOD_TYPE_CLASS, IOD_TYPE_MODULE, IOD_TYPE_ELEMENT)
   L_UINT16  nUsage;             // Usage (IOD_USAGE_M, IOD_USAGE_C, ...) 
   L_TCHAR   *pszDescription;    // Description
} DICOMIOD, *pDICOMIOD;

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomIOD
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   static L_UINT16  LoadXml            (L_TCHAR *pszFile, L_UINT uFlags);
   static L_VOID    Default         ();

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   static pDICOMIOD Insert          (pDICOMIOD pNeighbor, L_BOOL bChild, L_UINT32 nCode, L_TCHAR  *pszName, L_UCHAR nType, L_UINT16 nUsage, L_TCHAR *pszDescription);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   static pDICOMIOD Delete          (pDICOMIOD pIOD);
   static L_VOID    Reset           ();

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   static pDICOMIOD GetRoot         (pDICOMIOD pIOD);
   static pDICOMIOD GetParent       (pDICOMIOD pIOD);
   static pDICOMIOD GetChild        (pDICOMIOD pIOD);
   static pDICOMIOD GetFirst        (pDICOMIOD pIOD, L_BOOL bTree);
   static pDICOMIOD GetLast         (pDICOMIOD pIOD, L_BOOL bTree);
   static pDICOMIOD GetPrev         (pDICOMIOD pIOD, L_BOOL bTree);
   static pDICOMIOD GetNext         (pDICOMIOD pIOD, L_BOOL bTree);
   static L_UINT32  GetCountModule  (L_UINT32 nClass);
   static L_BOOL    Exists          (pDICOMIOD pIOD);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   static pDICOMIOD Find            (pDICOMIOD pIOD, L_UINT32 nCode, L_UCHAR nType, L_BOOL bTree);
   static pDICOMIOD FindClass       (L_UINT32 nClass);
   static pDICOMIOD FindModule      (L_UINT32 nClass, L_UINT32 nModule);
   static pDICOMIOD FindIndexModule (L_UINT32 nClass, L_UINT32 nIndex);

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   static L_BOOL    SetName         (pDICOMIOD pIOD, L_TCHAR *pszName);
   static L_BOOL    SetDescription  (pDICOMIOD pIOD, L_TCHAR *pszDescription);

   //---------------------------------------------------------------------------
   // Private Functions
   //---------------------------------------------------------------------------
private:
#if 0
   static LDicomTreeEx m_InfoIOD;
#else
   static LDicomTreeEx* m_pInfoIOD;
   static LDicomTreeEx& GetInfoIOD();
   friend L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);
   static L_BOOL HasFirst();
#endif // #if 0

   static L_VOID    Default         (pDICOMIOD pIOD, L_VOID *pReference);
   static pDICOMIOD FindInClass     (pDICOMIOD pIOD, L_UINT32 nCode, L_UCHAR nType);

   static L_BOOL m_bInitialized;
public:
   static L_VOID SetInitialized(L_BOOL bValue);
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)


// For use with L_DicomSetMemoryAllocation
#define MEMORY_FAIL   (0)
#define MEMORY_FAR    (1)
#define MEMORY_GLOBAL (2)


//---------------------------------------------------------------------------
// Initializing Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDefaultIOD         (L_VOID);
L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomSetMemoryAllocation(L_UINT16 nType);

//---------------------------------------------------------------------------
// Insertion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomInsertIOD          (pDICOMIOD pNeighbor, L_BOOL bChild, L_UINT32 nCode, L_TCHAR  *pszName, L_UCHAR nType, L_UINT16 nUsage, L_TCHAR *pszDescription);

//---------------------------------------------------------------------------
// Deletion Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomDeleteIOD          (pDICOMIOD pIOD);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomResetIOD           (L_VOID);

L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomLoadXmlIOD(L_TCHAR *pszFile, L_UINT uFlags);

//---------------------------------------------------------------------------
// Iteration Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetRootIOD         (pDICOMIOD pIOD);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetParentIOD       (pDICOMIOD pIOD);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetChildIOD        (pDICOMIOD pIOD);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetFirstIOD        (pDICOMIOD pIOD, L_BOOL bTree);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetLastIOD         (pDICOMIOD pIOD, L_BOOL bTree);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetPrevIOD         (pDICOMIOD pIOD, L_BOOL bTree);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomGetNextIOD         (pDICOMIOD pIOD, L_BOOL bTree);
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomExistsIOD          (pDICOMIOD pIOD);
L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetCountModuleIOD  (L_UINT32 nClass);

//---------------------------------------------------------------------------
// Searching Functions
//---------------------------------------------------------------------------
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomFindIOD            (pDICOMIOD pIOD, L_UINT32 nCode, L_UCHAR nType, L_BOOL bTree);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomFindClassIOD       (L_UINT32 nClass);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomFindModuleIOD      (L_UINT32 nClass, L_UINT32 nModule);
L_LTDIC_API pDICOMIOD EXT_FUNCTION L_DicomFindIndexModuleIOD (L_UINT32 nClass, L_UINT32 nIndex);

//---------------------------------------------------------------------------
// Modification Functions
//---------------------------------------------------------------------------
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomSetNameIOD         (pDICOMIOD pIOD, L_TCHAR *pszName);
L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomSetDescriptionIOD  (pDICOMIOD pIOD, L_TCHAR *pszDescription);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)

// Start of class definitions
   enum
   {
   CLASS_CR_IMAGE_STORAGE                                                          =   0,   // Computed Radiography Image Storage
   CLASS_CT_IMAGE_STORAGE                                                          =   1,   // CT Image Storage
   CLASS_MR_IMAGE_STORAGE                                                          =   2,   // MR Image Storage
   CLASS_NM_IMAGE_STORAGE                                                          =   3,   // Nuclear Medicine Image Storage
   // CLASS_NM_IMAGE_STORAGE_RETIRED                                               =   4,   // (Retired)
   CLASS_US_IMAGE_STORAGE                                                          =   5,   // Ultrasound Image Storage
   // CLASS_US_IMAGE_STORAGE_RETIRED                                               =   6,   // (Retired)
   CLASS_US_MULTI_FRAME_IMAGE_STORAGE                                              =   7,   // Ultrasound Multi-Frame Image Storage
   // CLASS_US_MULTI_FRAME_IMAGE_STORAGE_RETIRED                                   =   8,   // (Retired)
   CLASS_SC_IMAGE_STORAGE                                                          =   9,   // Secondary Capture Image Storage
   // CLASS_STANDALONE_OVERLAY_STORAGE                                             =  10,   // (Retired)
   // CLASS_STANDALONE_CURVE_STORAGE                                               =  11,   // (Retired)
   // CLASS_BASIC_STUDY_DESCRIPTOR                                                 =  12,   // (Retired)
   // CLASS_STANDALONE_MODALITY_LUT_STORAGE                                        =  13,   // (Retired)
   // CLASS_STANDALONE_VOI_LUT_STORAGE                                             =  14,   // (Retired)
   CLASS_XA_IMAGE_STORAGE                                                          =  15,   // X-Ray Angiographic Image Storage
   // CLASS_XA_BIPLANE_IMAGE_STORAGE_RETIRED                                       =  16,   // (Retired)
   CLASS_XRF_IMAGE_STORAGE                                                         =  17,   // X-Ray Radiofluoroscopic Image Storage
   CLASS_RT_IMAGE_STORAGE                                                          =  18,   // RT Image Storage
   CLASS_RT_DOSE_STORAGE                                                           =  19,   // RT Dose Storage
   CLASS_RT_STRUCTURE_SET_STORAGE                                                  =  20,   // RT Structure Set Storage
   CLASS_RT_PLAN_STORAGE                                                           =  21,   // RT Plan Storage
   CLASS_PET_IMAGE_STORAGE                                                         =  22,   // Positron Emission Tomography Image Storage
   // CLASS_STANDALONE_PET_CURVE_STORAGE                                           =  23,   // (Retired)
   // CLASS_STORED_PRINT_STORAGE                                                   =  24,   // (Retired)
   // CLASS_HC_GRAYSCALE_IMAGE_STORAGE                                             =  25,   // (Retired)
   // CLASS_HC_COLOR_IMAGE_STORAGE                                                 =  26,   // (Retired)
   CLASS_DX_IMAGE_STORAGE_PRESENTATION                                             =  27,   // Digital X-Ray Image Storage - For Presentation
   CLASS_DX_IMAGE_STORAGE_PROCESSING                                               =  28,   // Digital X-Ray Image Storage - For Processing
   CLASS_DX_MAMMOGRAPHY_IMAGE_STORAGE_PRESENTATION                                 =  29,   // Digital Mammography X-Ray Image Storage - For Presentation
   CLASS_DX_MAMMOGRAPHY_IMAGE_STORAGE_PROCESSING                                   =  30,   // Digital Mammography X-Ray Image Storage - For Processing
   CLASS_DX_INTRA_ORAL_IMAGE_STORAGE_PRESENTATION                                  =  31,   // Digital Intra-Oral X-Ray Image Storage - For Presentation
   CLASS_DX_INTRA_ORAL_IMAGE_STORAGE_PROCESSING                                    =  32,   // Digital Intra-Oral X-Ray Image Storage - For Processing
   CLASS_RT_BEAMS_TREATMENT_RECORD_STORAGE                                         =  33,   // RT Beams Treatment Record Storage
   CLASS_RT_BRACHY_TREATMENT_RECORD_STORAGE                                        =  34,   // RT Brachy Treatment Record Storage
   CLASS_RT_TREATMENT_SUMMARY_RECORD_STORAGE                                       =  35,   // RT Treatment Summary Record Storage
   CLASS_VL_ENDOSCOPIC_IMAGE_STORAGE                                               =  36,   // VL Endoscopic Image Storage
   CLASS_VL_MICROSCOPIC_IMAGE_STORAGE                                              =  37,   // VL Microscopic Image Storage
   CLASS_VL_SLIDE_COORDINATES_MICROSCOPIC_IMAGE_STORAGE                            =  38,   // VL Slide-Coordinates Microscopic Image Storage
   CLASS_VL_PHOTOGRAPHIC_IMAGE_STORAGE                                             =  39,   // VL Photographic Image Storage
   
   // CLASS_PATIENT                                                                =  40,   // (Retired)
   // CLASS_VISIT                                                                  =  41,   // (Retired)
   // CLASS_STUDY                                                                  =  42,   // (Retired)
   // CLASS_STUDY_COMPONENT                                                        =  43,   // (Retired)
   // CLASS_RESULTS                                                                =  44,   // (Retired)
   // CLASS_INTERPRETATION                                                         =  45,   // (Retired)
   CLASS_BASIC_FILM_SESSION                                                        =  46,   // Basic Film Session
   CLASS_BASIC_FILM_BOX                                                            =  47,   // Basic Film Box
   CLASS_BASIC_GRAYSCALE_IMAGE_BOX                                                 =  48,   // Basic Grayscale Image Box
   CLASS_BASIC_COLOR_IMAGE_BOX                                                     =  49,   // Basic Color Image Box
   CLASS_BASIC_ANNOTATION_BOX                                                      =  50,   // Basic Annotation Box
   CLASS_PRINT_JOB                                                                 =  51,   // Print Job
   CLASS_PRINTER                                                                   =  52,   // Printer
   // CLASS_VOI_LUT_BOX_RETIRED                                                    =  53,   // (Retired)
   // CLASS_IMAGE_OVERLAY_BOX_RETIRED                                              =  54,   // (Retired)
   CLASS_STORAGE_COMMITMENT_PUSH_MODEL                                             =  55,   // Storage Commitment  Push Model
   CLASS_STORAGE_COMMITMENT_PULL_MODEL                                             =  56,   // Storage Commitment  Pull Model
   // CLASS_PRINT_QUEUE                                                            =  57,   // (Retired)
   CLASS_MODALITY_PERFORMED_PROCEDURE_STEP                                         =  58,   // Modality Performed Procedure Step
   CLASS_PRESENTATION_LUT                                                          =  59,   // Presentation LUT
   // CLASS_PULL_PRINT_REQUEST                                                     =  60,   // (Retired)
   // CLASS_PATIENT_META                                                           =  61,   // (Retired)
   // CLASS_STUDY_META                                                             =  62,   // (Retired)
   // CLASS_RESULTS_META                                                           =  63,   // (Retired)
   CLASS_BASIC_GRAYSCALE_PRINT_META                                                =  64,   // Basic Grayscale Print Meta
   CLASS_BASIC_COLOR_PRINT_META                                                    =  65,   // Basic Color Print Meta
   // CLASS_REFERENCED_GRAYSCALE_PRINT_META_RETIRED                                =  66,   // (Retired)
   // CLASS_REFERENCED_COLOR_PRINT_META_RETIRED                                    =  67,   // (Retired)
   // CLASS_PULL_STORED_PRINT_META                                                 =  68,   // (Retired)
   CLASS_PRINTER_CONFIGURATION                                                     =  69,   // Printer Configuration
   // CLASS_BASIC_PRINT_IMAGE_OVERLAY_BOX                                          =  70,   // (Retired)
   CLASS_BASIC_DIRECTORY                                                           =  71,   // Basic Directory
   CLASS_PATIENT_ROOT_QUERY_PATIENT                                                =  72,   // Patient level for the patient root query/retrieve model
   CLASS_PATIENT_ROOT_QUERY_STUDY                                                  =  73,   // Study level for the patient root query/retrieve model
   CLASS_PATIENT_ROOT_QUERY_SERIES                                                 =  74,   // Series level for the patient root query/retrieve model
   CLASS_PATIENT_ROOT_QUERY_IMAGE                                                  =  75,   // Image level for the patient root query/retrieve model
   CLASS_STUDY_ROOT_QUERY_STUDY                                                    =  76,   // Study level for the study root query/retrieve model
   CLASS_STUDY_ROOT_QUERY_SERIES                                                   =  77,   // Series level for the study root query/retrieve model
   CLASS_STUDY_ROOT_QUERY_IMAGE                                                    =  78,   // Image level for the study root query/retrieve model
   CLASS_PATIENT_STUDY_QUERY_PATIENT                                               =  79,   // Patient level  for the patient/study only query/retrieve model
   CLASS_PATIENT_STUDY_QUERY_STUDY                                                 =  80,   // Study level for the patient/study only query/retrieve model
   CLASS_BASIC_TEXT_SR_STORAGE                                                     =  81,   // Basic Text SR Storage
   CLASS_ENHANCED_SR_STORAGE                                                       =  82,   // Enhanced SR Storage
   CLASS_COMPREHENSIVE_SR_STORAGE                                                  =  83,   // Comprehensive SR Storage
   CLASS_MODALITY_WORKLIST                                                         =  84,   // Modality Worklist
   CLASS_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE                             =  85,   // Grayscale Softcopy Presentation State Storage
   CLASS_BASIC_VOICE_AUDIO_STORAGE                                                 =  86,   // Basic Voice Audio Waveform Storage
   CLASS_12_LEAD_ECG_STORAGE                                                       =  87,   // 12-Lead ECG Storage
   CLASS_GENERAL_ECG_STORAGE                                                       =  88,   // General ECG Storage
   CLASS_AMBULATORY_ECG_STORAGE                                                    =  89,   // Ambulatory ECG Storage
   CLASS_HEMODYNAMIC_STORAGE                                                       =  90,   // Hemodynamic Waveform Storage
   CLASS_BASIC_CARDIAC_EP_STORAGE                                                  =  91,   // Basic Cardiac Electrophysiology Waveform Storage
   CLASS_ENHANCED_MR_IMAGE_STORAGE                                                 =  92,   // Enhanced MR Image Storage
   CLASS_MR_SPECTROSCOPY_STORAGE                                                   =  93,   // MR Spectroscopy Storage
   CLASS_RAW_DATA_STORAGE                                                          =  94,   // RAW Data Storage
   CLASS_SC_MULTI_FRAME_SINGLE_BIT_IMAGE_STORAGE                                   =  95,   // Secondary Capture Multi-Frame Single Bit Image Storage
   CLASS_SC_MULTI_FRAME_GRAYSCALE_BYTE_IMAGE_STORAGE                               =  96,   // Secondary Capture Multi-Frame Grayscale Byte Image Storage
   CLASS_SC_MULTI_FRAME_GRAYSCALE_WORD_IMAGE_STORAGE                               =  97,   // Secondary Capture Multi-Frame Grayscale Word Image Storage
   CLASS_SC_MULTI_FRAME_TRUE_COLOR_IMAGE_STORAGE                                   =  98,   // Secondary Capture Multi-Frame True Color Image Storage
   // CLASS_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP                               =  99,   // (Retired)
   // CLASS_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP                               = 100,   // (Retired)
   // CLASS_GENERAL_PURPOSE_WORKLIST_MANAGEMENT_META                               = 101,   // (Retired)
   CLASS_KEY_OBJECT_SELECTION_DOCUMENT_STORAGE                                     = 102,   // Key Object Selection Document Storage
   CLASS_MAMMOGRAPHY_CAD_SR_STORAGE                                                = 103,   // Mammography CAD SR Storage
   CLASS_CHEST_CAD_SR_STORAGE                                                      = 104,   // Chest CAD SR Storage
   // CLASS_GENERAL_PURPOSE_WORKLIST                                               = 105,   // (Retired)
   CLASS_OPHTHALMIC_PHOTOGRAPHY_8_BIT_IMAGE_STORAGE                                = 106,   // Ophthalmic Photography 8 Bit Image Storage
   CLASS_OPHTHALMIC_PHOTOGRAPHY_16_BIT_IMAGE_STORAGE                               = 107,   // Ophthalmic Photography 16 Bit Image Storage
   CLASS_STEREOMETRIC_RELATIONSHIP_STORAGE                                         = 108,   // Stereometric Relationship Storage
   CLASS_VIDEO_ENDOSCOPIC_IMAGE_STORAGE                                            = 109,   // Video Endoscopic Image Storage
   CLASS_VIDEO_MICROSCOPIC_IMAGE_STORAGE                                           = 110,   // Video Microscopic Image Storage
   CLASS_VIDEO_PHOTOGRAPHIC_IMAGE_STORAGE                                          = 111,   // Video Photographic Image Storage
   CLASS_UNDEFINED                                                                 = 112,   // (.NET)
   
   CLASS_PSEUDO_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE                          = 113,   // Pseudo-Color Softcopy Presentation State Storage
   CLASS_BLENDING_SOFTCOPY_PRESENTATION_STATE_STORAGE                              = 114,   // Blending Softcopy Presentation State Storage
   
   CLASS_PROCEDURE_LOG_STORAGE                                                     = 115,   // Procedure Log Storage
   CLASS_X_RAY_RADIATION_DOSE_SR_STORAGE                                           = 116,   // X-Ray Radiation Dose SR Storage
   CLASS_ENHANCED_CT_IMAGE_STORAGE                                                 = 117,   // Enhanced Computed Tomography Image Storage
   CLASS_SPATIAL_REGISTRATION_STORAGE                                              = 118,   // Spatial Registration Storage
   CLASS_DEFORMABLE_SPATIAL_REGISTRATION_STORAGE                                   = 119,   // Deformable Spatial Registration Storage
   CLASS_SPATIAL_FIDUCIALS_STORAGE                                                 = 120,   // Spatial Fiducials Storage
   
   CLASS_HANGING_PROTOCOL_STORAGE                                                  = 121,   // Hanging Protocol Storage
   CLASS_ENCAPSULATED_PDF_STORAGE                                                  = 122,   // Encapsulated PDF Storage
   CLASS_ENCAPSULATED_CDA_STORAGE                                                  = 123,   // Encapsulated CDA Storage
   CLASS_REAL_WORLD_VALUE_MAPPING_STORAGE                                          = 124,   // Real World Value Mapping Storage
   CLASS_ENHANCED_XA_IMAGE_STORAGE                                                 = 125,   // Enhanced XA Image Storage
   CLASS_ENHANCED_XRF_IMAGE_STORAGE                                                = 126,   // Enhanced XRF Image Storage
   CLASS_RT_ION_PLAN_STORAGE                                                       = 127,   // RT Ion Plan Storage
   CLASS_RT_ION_BEAMS_TREATMENT_RECORD_STORAGE                                     = 128,   // RT Ion Beams Treatment Record Storage
   CLASS_SEGMENTATION_STORAGE                                                      = 129,   // Segmentation Storage
   CLASS_OPHTHALMIC_TOMOGRAPHY_IMAGE_STORAGE                                       = 130,   // Ophthalmic Tomography Image Storage
   CLASS_X_RAY_3D_ANGIOGRAPHIC_IMAGE_STORAGE                                       = 131,   // X-Ray 3D Angiographic Image Storage
   CLASS_X_RAY_3D_CRANIOFACIAL_IMAGE_STORAGE                                       = 132,   // X-Ray 3D Craniofacial Image Storage
   CLASS_BASIC_IMAGE_BOX                                                           = 133,   // Basic Image Box
   CLASS_INSTANCE_AVAILABILITY_NOTIFICATION                                        = 134,   // Instance Availability Notification
   CLASS_MEDIA_CREATION_MANAGEMENT                                                 = 135,   // Media Creation Management
   CLASS_ENHANCED_PET_IMAGE_STORAGE                                                = 136,   // Enhanced PET Image Storage
   
   CLASS_LENSOMETRY_MEASUREMENTS_STORAGE                                           = 137,   // Lensometry Measurements Storage
   CLASS_AUTOREFRACTION_MEASUREMENTS_STORAGE                                       = 138,   // Autorefraction Measurements Storage
   CLASS_KERATOMETRY_MEASUREMENTS_STORAGE                                          = 139,   // Keratometry Measurements Storage
   CLASS_SUBJECTIVE_REFRACTION_MEASUREMENTS_STORAGE                                = 140,   // Subjective Refraction Measurements Storage
   CLASS_VISUAL_ACUITY_MEASUREMENTS_STORAGE                                        = 141,   // Visual Acuity Measurements Storage
   CLASS_SPECTACLE_PRESCRIPTION_REPORT_STORAGE                                     = 142,   // Spectacle Prescription Report Storage
   
   // Part IV
   CLASS_SUBSTANCE_ADMINISTRATION_LOGGING                                          = 143,   // Substance Administration Logging
   CLASS_GENERAL_RELEVANT_PATIENT_INFORMATION_QUERY                                = 144,   // General Relevant Patient Information Query
   CLASS_HANGING_PROTOCOL_INFORMATION_MODEL_FIND                                   = 145,   // Hanging Protocol Information Model Find
   CLASS_PRODUCT_CHARACTERISTICS_QUERY                                             = 146,   // Product Characteristics Query
   CLASS_SUBSTANCE_APPROVAL_QUERY                                                  = 147,   // Substance Approval Query
   CLASS_BASIC_STRUCTURED_DISPLAY_STORAGE                                          = 148,   // Basic Structured Display Storage
   
   
   CLASS_ENHANCED_US_VOLUME_STORAGE                                                = 149,   // Enhanced Ultrasound Volume Storage
   CLASS_ARTERIAL_PULSE_WAVEFORM_STORAGE                                           = 150,   // Arterial Pulse Waveform Storage
   CLASS_RESPIRATORY_WAVEFORM_STORAGE                                              = 151,   // Respiratory Waveform Storage
   CLASS_GENERAL_AUDIO_WAVEFORM_STORAGE                                            = 152,   // General Audio Waveform Storage
   CLASS_BREAST_TOMOSYNTHESIS_IMAGE_STORAGE                                        = 153,   // Breast Tomosynthesis Image Storage
   CLASS_COLON_CAD_SR_STORAGE                                                      = 154,   // Colon CAD SR Storage
   CLASS_SURFACE_SEGMENTATION_STORAGE                                              = 155,   // Surface Segmentation Storage
   CLASS_COLOR_PALETTE_STORAGE                                                     = 156,   // Color Palette Storage
   CLASS_ENHANCED_MR_COLOR_IMAGE_STORAGE                                           = 157,   // Enhanced MR Color Image Storage
   
   // 2011 classes
   // Annex A
   CLASS_VL_WHOLE_SLIDE_MICROSCOPY_IMAGE_STORAGE                                   = 158,   // VL Whole Slide Microscopy Image Storage
   CLASS_XA_XRF_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE                      = 159,   // Xa/XRF Grayscale Softcopy Presentation State Storage
   CLASS_MACULAR_GRID_THICKNESS_AND_VOLUME_REPORT_STORAGE                          = 160,   // Macular Grid Thickness And Volume Report Storage
   CLASS_IMPLANTATION_PLAN_SR_DOCUMENT_STORAGE                                     = 161,   // Implantation Plan SR Document Storage
   
   CLASS_OPHTHALMIC_AXIAL_MEASUREMENTS_STORAGE                                     = 162,   // Ophthalmic Axial Measurements Storage
   CLASS_INTRAOCULAR_LENS_CALCULATIONS_STORAGE                                     = 163,   // Intraocular Lens Calculations Storage
   CLASS_GENERIC_IMPLANT_TEMPLATE_STORAGE                                          = 164,   // Generic Implant Template Storage
   CLASS_IMPLANT_ASSEMBLY_TEMPLATE_STORAGE                                         = 165,   // Implant Assembly Template Storage
   CLASS_IMPLANT_TEMPLATE_GROUP_STORAGE                                            = 166,   // Implant Template Group Storage
   CLASS_RT_BEAMS_DELIVERY_INSTRUCTION_STORAGE                                     = 167,   // RT Beams Delivery Instruction Storage
   CLASS_OPHTHALMIC_VISUAL_FIELD_STATIC_PERIMETRY_MEASUREMENTS_STORAGE             = 168,   // Ophthalmic Visual Field Static Perimetry Measurements Storage
   CLASS_INTRAVASCULAR_OCT_IMAGE_STORAGE_PRESENTATION                              = 169,   // Intravascular Optical Coherence Tomography Storage - For Presentation
   CLASS_INTRAVASCULAR_OCT_IMAGE_STORAGE_PROCESSING                                = 170,   // Intravascular Optical Coherence Tomography Storage - For Processing
   CLASS_OPHTHALMIC_THICKNESS_MAP_STORAGE                                          = 171,   // Ophthalmic Thickness Map Storage
   CLASS_UNIFIED_PROCEDURE_STEP_PUSH                                               = 172,   // Unified Procedure Step  Push
   CLASS_UNIFIED_PROCEDURE_STEP_PULL                                               = 173,   // Unified Procedure Step  Pull
   CLASS_UNIFIED_PROCEDURE_STEP_WATCH                                              = 174,   // Unified Procedure Step  Watch
   CLASS_UNIFIED_PROCEDURE_STEP_EVENT                                              = 175,   // Unified Procedure Step  Event
   CLASS_RT_CONVENTIONAL_MACHINE_VERIFICATION                                      = 176,   // RT Conventional Machine Verification
   CLASS_RT_ION_MACHINE_VERIFICATION                                               = 177,   // RT Ion Machine Verification
   CLASS_COLOR_SOFTCOPY_PRESENTATION_STATE_STORAGE                                 = 178,   // Color Softcopy Presentation State Storage
   
   CLASS_DISPLAY_SYSTEM                                                            = 179,   // Display System
   CLASS_COMPREHENSIVE_3D_SR_STORAGE                                               = 180,   // Comprehensive 3D SR Storage
   CLASS_RADIOPHARMACEUTICAL_RADIATION_DOSE_SR_STORAGE                             = 181,   // Radiopharmaceutical Radiation Dose SR Storage
   
   // CLASS_OPHTHALMIC_THICKNESS_MAP_STORAGE                                       = 182,   // (Not Used)
   CLASS_SURFACE_SCAN_MESH_STORAGE                                                 = 183,   // Surface Scan Mesh Storage
   CLASS_SURFACE_SCAN_POINT_CLOUD_STORAGE                                          = 184,   // Surface Scan Point Cloud Storage
   CLASS_LEGACY_CONVERTED_ENHANCED_CT_IMAGE_STORAGE                                = 185,   // Legacy Converted Enhanced CT Image Storage
   CLASS_LEGACY_CONVERTED_ENHANCED_MR_IMAGE_STORAGE                                = 186,   // Legacy Converted Enhanced MR Image Storage
   CLASS_LEGACY_CONVERTED_ENHANCED_PET_IMAGE_STORAGE                               = 187,   // Legacy Converted Enhanced PET Image Storage
   CLASS_CORNEAL_TOPOGRAPHY_MAP_STORAGE                                            = 188,   // Corneal Topography Map Storage
   CLASS_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PRESENTATION                        = 189,   // Breast Projection X-Ray Image Storage - For Presentation
   CLASS_BREAST_PROJECTION_X_RAY_IMAGE_STORAGE_PROCESSING                          = 190,   // Breast Projection X-Ray Image Storage - For Processing
   
   // 2015C
   CLASS_EXTENSIBLE_SR_STORAGE                                                     = 191,   // Extensible SR Storage
   CLASS_PARAMETRIC_MAP_STORAGE                                                    = 192,   // Parametric Map Storage
   CLASS_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_STEREOGRAPHIC_PROJECTION_IMAGE_STORAGE  = 193,   // Wide Field Ophthalmic Photography Stereographic Projection Image Storage
   CLASS_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_3D_COORDINATES_IMAGE_STORAGE            = 194,   // Wide Field Ophthalmic Photography 3D Coordinates Image Storage
   
   // 2021a Classes
   CLASS_REAL_TIME_VIDEO_ENDOSCOPIC_IMAGE_STORAGE                                  = 195,   // Real-Time Video Endoscopic Image Storage
   CLASS_REAL_TIME_VIDEO_PHOTOGRAPHIC_IMAGE_STORAGE                                = 196,   // Real-Time Video Photographic Image Storage
   CLASS_DERMOSCOPIC_PHOTOGRAPHY_IMAGE_STORAGE                                     = 197,   // Dermoscopic Photography Image Storage
   CLASS_ADVANCED_BLENDING_PRESENTATION_STATE_STORAGE                              = 198,   // Advanced Blending Presentation State Storage
   CLASS_REAL_TIME_AUDIO_WAVEFORM_STORAGE                                          = 199,   // Real-Time Audio Waveform Storage
   CLASS_ROUTINE_SCALP_ELECTROENCEPHALOGRAM_STORAGE                                = 200,   // Routine Scalp Electroencephalogram Storage
   CLASS_ELECTROMYOGRAM_WAVEFORM_STORAGE                                           = 201,   // Electromyogram Waveform Storage
   CLASS_ELECTROOCULOGRAM_WAVEFORM_STORAGE                                         = 202,   // Electrooculogram Waveform Storage
   CLASS_SLEEP_ELECTROENCEPHALOGRAM_STORAGE                                        = 203,   // Sleep Electroencephalogram Storage
   CLASS_MULTI_CHANNEL_RESPIRATORY_WAVEFORM_STORAGE                                = 204,   // Multi-Channel Respiratory Waveform Storage
   CLASS_BODY_POSITION_WAVEFORM_STORAGE                                            = 205,   // Body Position Waveform Storage
   CLASS_ACQUISITION_CONTEXT_SR_STORAGE                                            = 206,   // Acquisition Context SR Storage
   CLASS_SIMPLIFIED_ADULT_ECHO_SR_STORAGE                                          = 207,   // Simplified Adult Echo SR Storage
   CLASS_PATIENT_RADIATION_DOSE_SR_STORAGE                                         = 208,   // Patient Radiation Dose SR Storage
   CLASS_PLANNED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE                           = 209,   // Planned Imaging Agent Administration SR Storage
   CLASS_PERFORMED_IMAGING_AGENT_ADMINISTRATION_SR_STORAGE                         = 210,   // Performed Imaging Agent Administration SR Storage
   CLASS_RENDITION_SELECTION_DOCUMENT_STORAGE                                      = 211,   // Rendition Selection Document Storage
   CLASS_TRACTOGRAPHY_RESULTS_STORAGE                                              = 212,   // Tractography Results Storage
   CLASS_RT_BRACHY_APPLICATION_SETUP_DELIVERY_INSTRUCTION_STORAGE                  = 213,   // RT Brachy Application Setup Delivery Instruction Storage
   CLASS_GRAYSCALE_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE                = 214,   // Grayscale Planar MPR Volumetric Presentation State Storage
   CLASS_COMPOSITING_PLANAR_MPR_VOLUMETRIC_PRESENTATION_STATE_STORAGE              = 215,   // Compositing Planar MPR Volumetric Presentation State Storage
   CLASS_VOLUME_RENDERING_VOLUMETRIC_PRESENTATION_STATE_STORAGE                    = 216,   // Volume Rendering Volumetric Presentation State Storage
   CLASS_CONTENT_ASSESSMENT_RESULTS_STORAGE                                        = 217,   // Content Assessment Results Storage
   CLASS_CT_PERFORMED_PROCEDURE_PROTOCOL_STORAGE                                   = 218,   // CT Performed Procedure Protocol Storage
   CLASS_CT_DEFINED_PROCEDURE_PROTOCOL_STORAGE                                     = 219,   // CT Defined Procedure Protocol Storage
   CLASS_XA_PERFORMED_PROCEDURE_PROTOCOL_STORAGE                                   = 220,   // XA Performed Procedure Protocol Storage
   CLASS_XA_DEFINED_PROCEDURE_PROTOCOL_STORAGE                                     = 221,   // XA Defined Procedure Protocol Storage
   CLASS_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE_STORAGE             = 222,   // Ophthalmic Optical Coherence Tomography En Face Image Storage
   CLASS_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_STORAGE    = 223,   // Ophthalmic Optical Coherence Tomography B-Scan Volume Analysis Storage
   CLASS_ENCAPSULATED_STL_STORAGE                                                  = 224,   // Encapsulated STL Storage
   CLASS_ENCAPSULATED_OBJ_STORAGE                                                  = 225,   // Encapsulated OBJ Storage
   CLASS_ENCAPSULATED_MTL_STORAGE                                                  = 226,   // Encapsulated MTL Storage
   CLASS_UNIFIED_PROCEDURE_STEP_QUERY                                              = 227,   // Unified Procedure Step  Query
   CLASS_ENHANCED_X_RAY_RADIATION_DOSE_SR_STORAGE                                  = 228,   // Enhanced X-Ray Radiation Dose SR Storage
   CLASS_MAX                                                                       = 228,   //
   CLASS_UNKNOWN                                                                   = 65535,
   
   // Begin Deprecated
   CLASS_BASIC_CARDIAC_EP                                                          = CLASS_BASIC_CARDIAC_EP_STORAGE,
   CLASS_DX_INTRAORAL_IMAGE_STORAGE_PRESENTATION                                   = CLASS_DX_INTRA_ORAL_IMAGE_STORAGE_PRESENTATION,
   CLASS_DX_INTRAORAL_IMAGE_STORAGE_PROCESSING                                     = CLASS_DX_INTRA_ORAL_IMAGE_STORAGE_PROCESSING,
   CLASS_BASIC_TEXT_SR                                                             = CLASS_BASIC_TEXT_SR_STORAGE,
   CLASS_ENHANCED_SR                                                               = CLASS_ENHANCED_SR_STORAGE,
   CLASS_COMPREHENSIVE_SR                                                          = CLASS_COMPREHENSIVE_SR_STORAGE,
   CLASS_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE                                     = CLASS_GRAYSCALE_SOFTCOPY_PRESENTATION_STATE_STORAGE,
   CLASS_BASIC_VOICE_AUDIO                                                         = CLASS_BASIC_VOICE_AUDIO_STORAGE,
   CLASS_12_LEAD_ECG                                                               = CLASS_12_LEAD_ECG_STORAGE,
   CLASS_GENERAL_ECG                                                               = CLASS_GENERAL_ECG_STORAGE,
   CLASS_AMBULATORY_ECG                                                            = CLASS_AMBULATORY_ECG_STORAGE,
   CLASS_HEMODYNAMIC                                                               = CLASS_HEMODYNAMIC_STORAGE,
   CLASS_KEY_OBJECT_SELECTION_DOCUMENT                                             = CLASS_KEY_OBJECT_SELECTION_DOCUMENT_STORAGE,
   CLASS_MAMMOGRAPHY_CAD_SR                                                        = CLASS_MAMMOGRAPHY_CAD_SR_STORAGE,
   CLASS_CHEST_CAD_SR                                                              = CLASS_CHEST_CAD_SR_STORAGE,
   CLASS_OPHTHALMIC_8_BIT_PHOTOGRAPHY_IMAGE_STORAGE                                = CLASS_OPHTHALMIC_PHOTOGRAPHY_8_BIT_IMAGE_STORAGE,
   CLASS_OPHTHALMIC_16_BIT_PHOTOGRAPHY_IMAGE_STORAGE                               = CLASS_OPHTHALMIC_PHOTOGRAPHY_16_BIT_IMAGE_STORAGE
   // End Deprecated
   };
   
// End of class definitions


// Start of module definitions 
enum
{
   MODULE_PATIENT                                                               =   0,   // Table C.7-1                 Patient Module Attributes
   MODULE_GENERAL_STUDY                                                         =   1,   // Table C.7-3                 General Study Module Attributes
   MODULE_PATIENT_STUDY                                                         =   2,   // Table C.7-4a                Patient Study Module Attributes
   MODULE_GENERAL_SERIES                                                        =   3,   // Table C.7-5a                General Series Module Attributes
   MODULE_CR_SERIES                                                             =   4,   // Table C.8-1                 CR Series Module Attributes
   MODULE_GENERAL_EQUIPMENT                                                     =   5,   // Table C.7-8                 General Equipment Module Attributes
   MODULE_GENERAL_IMAGE                                                         =   6,   // Table C.7-9                 General Image Module Attributes
   MODULE_IMAGE_PIXEL                                                           =   7,   // Table C.7-11a               Image Pixel Module Attributes
   MODULE_CONTRAST_BOLUS                                                        =   8,   // Table C.7-12                Contrast/Bolus Module Attributes
   MODULE_CR_IMAGE                                                              =   9,   // Table C.8-2                 CR Image Module Attributes
   MODULE_OVERLAY_PLANE                                                         =  10,   // Table C.9-2                 Overlay Plane Module Attributes
   // MODULE_CURVE                                                              =  11,   // (Retired)
   MODULE_MODALITY_LUT                                                          =  12,   // Table C.11-1                Modality LUT Module Attributes
   MODULE_VOI_LUT                                                               =  13,   // Table C.11-2                VOI LUT Module Attributes
   MODULE_SOP_COMMON                                                            =  14,   // Table C.12-1                SOP Common Module Attributes
   MODULE_FRAME_OF_REFERENCE                                                    =  15,   // Table C.7-6                 Frame of Reference Module Attributes
   MODULE_IMAGE_PLANE                                                           =  16,   // Table C.7-10                Image Plane Module Attributes
   MODULE_CT_IMAGE                                                              =  17,   // Table C.8-3                 CT Image Module Attributes
   MODULE_MR_IMAGE                                                              =  18,   // Table C.8-4                 MR Image Module Attributes
   MODULE_NM_PET_PATIENT_ORIENTATION                                            =  19,   // Table C.8-5                 NM/PET Patient Orientation Module Attributes
   MODULE_NM_IMAGE_PIXEL                                                        =  20,   // Table C.8-6                 NM Image Pixel Module Attributes
   MODULE_MULTI_FRAME                                                           =  21,   // Table C.7-14                Multi-frame Module Attributes
   MODULE_NM_MULTI_FRAME                                                        =  22,   // Table C.8-7                 NM Multi-frame Module Attributes
   MODULE_NM_IMAGE                                                              =  23,   // Table C.8-9                 NM Image Module Attributes
   MODULE_NM_ISOTOPE                                                            =  24,   // Table C.8-10                NM Isotope Module Attributes
   MODULE_NM_DETECTOR                                                           =  25,   // Table C.8-11                NM Detector Module Attributes
   MODULE_NM_TOMO_ACQUISITION                                                   =  26,   // Table C.8-12                NM Tomo Acquisition Module Attributes
   MODULE_NM_MULTI_GATED_ACQUISITION                                            =  27,   // Table C.8-13                NM Multi-Gated Acquisition Module Attributes
   MODULE_NM_PHASE                                                              =  28,   // Table C.8-14                NM Phase Module Attributes
   MODULE_NM_RECONSTRUCTION                                                     =  29,   // Table C.8-15                NM Reconstruction Module Attributes
   MODULE_MULTI_FRAME_OVERLAY                                                   =  30,   // Table C.9-3                 Multi-frame Overlay Module Attributes
   // MODULE_US_FRAME_OF_REFERENCE                                              =  31,   // (Retired)
   MODULE_PALETTE_COLOR_LOOKUP_TABLE                                            =  32,   // Table C.7-22                Palette Color Lookup Table Module Attributes
   MODULE_US_REGION_CALIBRATION                                                 =  33,   // Table C.8-17                US Region Calibration Module Attributes
   MODULE_US_IMAGE                                                              =  34,   // Table C.8-18                US Image Module Attributes
   // MODULE_CURVE_IDENTIFICATION                                               =  35,   // (Retired)
   // MODULE_AUDIO                                                              =  36,   // (Retired)
   MODULE_CINE                                                                  =  37,   // Table C.7-13                Cine Module Attributes
   MODULE_SC_EQUIPMENT                                                          =  38,   // Table C.8-24                SC Equipment Module Attributes
   MODULE_SC_IMAGE                                                              =  39,   // Table C.8-25                SC Image Module Attributes
   // MODULE_OVERLAY_IDENTIFICATION                                             =  40,   // (Retired)
   // MODULE_PATIENT_SUMMARY                                                    =  41,   // (Retired)
   // MODULE_STUDY_CONTENT                                                      =  42,   // (Retired)
   // MODULE_LUT_IDENTIFICATION                                                 =  43,   // (Retired)
   MODULE_FRAME_POINTERS                                                        =  44,   // Table C.7-15                Frame Pointers Module Attributes
   MODULE_MASK                                                                  =  45,   // Table C.7-16                Mask Module Attributes
   MODULE_DISPLAY_SHUTTER                                                       =  46,   // Table C.7-17                Display Shutter Module Attributes
   MODULE_DEVICE                                                                =  47,   // Table C.7-18                Device Module Attributes
   MODULE_THERAPY                                                               =  48,   // Table C.7-19                Intervention Module Attributes
   MODULE_X_RAY_IMAGE                                                           =  49,   // Table C.8-26                X-Ray Image Module Attributes
   MODULE_X_RAY_ACQUISITION                                                     =  50,   // Table C.8-27                X-Ray Acquisition Module Attributes
   MODULE_X_RAY_COLLIMATOR                                                      =  51,   // Table C.8-28                X-Ray Collimator Module Attributes
   MODULE_X_RAY_TABLE                                                           =  52,   // Table C.8-29                X-Ray Table Module Attributes
   MODULE_XA_POSITIONER                                                         =  53,   // Table C.8-30                XA Positioner Module Attributes
   // MODULE_BIPLANE_SEQUENCE                                                   =  54,   // (Retired)
   // MODULE_BIPLANE_OVERLAY                                                    =  55,   // (Retired)
   // MODULE_BIPLANE_IMAGE                                                      =  56,   // (Retired)
   MODULE_XRF_POSITIONER                                                        =  57,   // Table C.8-31                XRF Positioner Module Attributes
   MODULE_X_RAY_TOMOGRAPHY_ACQUISITION                                          =  58,   // Table C.8-32                X-Ray Tomography Acquisition Module Attributes
   MODULE_RT_SERIES                                                             =  59,   // Table C.8-37                RT Series Module Attributes
   MODULE_RT_IMAGE                                                              =  60,   // Table C.8-38                RT Image Module Attributes
   MODULE_APPROVAL                                                              =  61,   // Table C.8-52                Approval Module Attributes
   MODULE_RT_DOSE                                                               =  62,   // Table C.8-39                RT Dose Module Attributes
   MODULE_RT_DVH                                                                =  63,   // Table C.8-40                RT DVH Module Attributes
   MODULE_STRUCTURE_SET                                                         =  64,   // Table C.8-41                Structure Set Module Attributes
   MODULE_ROI_CONTOUR                                                           =  65,   // Table C.8-42                ROI Contour Module Attributes
   MODULE_RT_DOSE_ROI                                                           =  66,   // Table C.8-43                RT Dose ROI Module Attributes
   MODULE_RT_ROI_OBSERVATIONS                                                   =  67,   // Table C.8-44                RT ROI Observations Module Attributes
   MODULE_RT_GENERAL_PLAN                                                       =  68,   // Table C.8-45                RT General Plan Module Attributes
   MODULE_RT_PRESCRIPTION                                                       =  69,   // Table C.8-46                RT Prescription Module Attributes
   MODULE_RT_TOLERANCE_TABLES                                                   =  70,   // Table C.8-47                RT Tolerance Tables Module Attributes
   MODULE_RT_PATIENT_SETUP                                                      =  71,   // Table C.8-48                RT Patient Setup Module Attributes
   MODULE_RT_FRACTION_SCHEME                                                    =  72,   // Table C.8-49                RT Fraction Scheme Module Attributes
   MODULE_RT_BEAMS                                                              =  73,   // Table C.8-50                RT Beams Module Attributes
   MODULE_RT_BRACHY_APPLICATION_SETUPS                                          =  74,   // Table C.8-51                RT Brachy Application Setups Module Attributes
   MODULE_PET_SERIES                                                            =  75,   // Table C.8-60                PET Series Module Attributes
   MODULE_PET_ISOTOPE                                                           =  76,   // Table C.8-61                PET Isotope Module Attributes
   MODULE_PET_MULTI_GATED_ACQUISITION                                           =  77,   // Table C.8-62                PET Multi-Gated Acquisition Module Attributes
   MODULE_PET_IMAGE                                                             =  78,   // Table C.8-63                PET Image Module Attributes
   // MODULE_PET_CURVE                                                          =  79,   // (Retired)
   // MODULE_PRINTER_CHARACTERISTICS                                            =  80,   // (Retired)
   // MODULE_FILM_BOX                                                           =  81,   // (Retired)
   // MODULE_IMAGE_BOX_LIST                                                     =  82,   // (Retired)
   // MODULE_ANNOTATION_LIST                                                    =  83,   // (Retired)
   // MODULE_IMAGE_OVERLAY_BOX_LIST                                             =  84,   // (Retired)
   // MODULE_PRESENTATION_LUT_LIST                                              =  85,   // (Retired)
   // MODULE_HC_EQUIPMENT                                                       =  86,   // (Retired)
   // MODULE_HC_GRAYSCALE_IMAGE                                                 =  87,   // (Retired)
   // MODULE_HC_COLOR_IMAGE                                                     =  88,   // (Retired)
   MODULE_PATIENT_RELATIONSHIP                                                  =  89,   // Table C.2-1                 Patient Relationship Module Attributes
   MODULE_PATIENT_IDENTIFICATION                                                =  90,   // Table C.2-2                 Patient Identification Module Attributes
   MODULE_PATIENT_DEMOGRAPHIC                                                   =  91,   // Table C.2-3                 Patient Demographic Module Attributes
   MODULE_PATIENT_MEDICAL                                                       =  92,   // Table C.2-4                 Patient Medical Module Attributes
   MODULE_VISIT_RELATIONSHIP                                                    =  93,   // Table C.3-1                 Visit Relationship Module Attributes
   MODULE_VISIT_IDENTIFICATION                                                  =  94,   // Table C.3-2                 Visit Identification Module Attributes
   MODULE_VISIT_ADMISSION                                                       =  95,   // Table C.3-4                 Visit Admission Module Attributes
   MODULE_VISIT_STATUS                                                          =  96,   // Table C.3-3                 Visit Status Module Attributes
   // MODULE_VISIT_DISCHARGE                                                    =  97,   // (Retired)
   // MODULE_VISIT_SCHEDULING                                                   =  98,   // (Retired)
   // MODULE_STUDY_RELATIONSHIP                                                 =  99,   // (Retired)
   // MODULE_STUDY_IDENTIFICATION                                               = 100,   // (Retired)
   // MODULE_STUDY_CLASSIFICATION                                               = 101,   // (Retired)
   // MODULE_STUDY_SCHEDULING                                                   = 102,   // (Retired)
   // MODULE_STUDY_ACQUISITION                                                  = 103,   // (Retired)
   // MODULE_STUDY_READ                                                         = 104,   // (Retired)
   // MODULE_STUDY_COMPONENT_RELATIONSHIP                                       = 105,   // (Retired)
   // MODULE_STUDY_COMPONENT_ACQUISITION                                        = 106,   // (Retired)
   // MODULE_STUDY_COMPONENT                                                    = 107,   // (Retired)
   // MODULE_RESULTS_RELATIONSHIP                                               = 108,   // (Retired)
   // MODULE_RESULTS_IDENTIFICATION                                             = 109,   // (Retired)
   // MODULE_RESULTS_IMPRESSIONS                                                = 110,   // (Retired)
   // MODULE_INTERPRETATION_RELATIONSHIP                                        = 111,   // (Retired)
   // MODULE_INTERPRETATION_IDENTIFICATION                                      = 112,   // (Retired)
   // MODULE_INTERPRETATION_STATE                                               = 113,   // (Retired)
   // MODULE_INTERPRETATION_RECORDING                                           = 114,   // (Retired)
   // MODULE_INTERPRETATION_TRANSCRIPTION                                       = 115,   // (Retired)
   // MODULE_INTERPRETATION_APPROVAL                                            = 116,   // (Retired)
   MODULE_BASIC_FILM_SESSION_PRESENTATION                                       = 117,   // Table C.13-1                Basic Film Session Presentation Module Attributes
   MODULE_BASIC_FILM_SESSION_RELATIONSHIP                                       = 118,   // Table C.13-2                Basic Film Session Relationship Module Attributes
   MODULE_BASIC_FILM_BOX_PRESENTATION                                           = 119,   // Table C.13-3                Basic Film Box Presentation Module Attributes
   MODULE_BASIC_FILM_BOX_RELATIONSHIP                                           = 120,   // Table C.13-4                Basic Film Box Relationship Module Attributes
   MODULE_IMAGE_BOX_PRESENTATION_GRAYSCALE                                      = 121,   // Table C.13-5                Image Box Pixel Presentation Module Attributes
   MODULE_IMAGE_BOX_PRESENTATION_COLOR                                          = 122,   // Table C.13-5                Image Box Pixel Presentation Module Attributes
   // MODULE_IMAGE_BOX_RELATIONSHIP                                             = 123,   // (Retired)
   MODULE_BASIC_ANNOTATION_PRESENTATION                                         = 124,   // Table C.13-7                Basic Annotation Presentation Module Attributes
   MODULE_PRINT_JOB                                                             = 125,   // Table C.13-8                Print Job Module Attributes
   MODULE_PRINTER                                                               = 126,   // Table C.13-9                Printer Module Attributes
   // MODULE_IMAGE_OVERLAY_BOX_PRESENTATION                                     = 127,   // (Retired)
   // MODULE_IMAGE_OVERLAY_BOX_RELATIONSHIP                                     = 128,   // (Retired)
   MODULE_STORAGE_COMMITMENT                                                    = 129,   // Table C.14-1                Storage Commitment Module Attributes
   // MODULE_GENERAL_QUEUE                                                      = 130,   // (Retired)
   // MODULE_PRINT_QUEUE                                                        = 131,   // (Retired)
   MODULE_PERFORMED_PROCEDURE_STEP_RELATIONSHIP                                 = 132,   // Table C.4-13                Performed Procedure Step Relationship Module Attributes
   MODULE_PERFORMED_PROCEDURE_STEP_INFORMATION                                  = 133,   // Table C.4-14                Performed Procedure Step Information Module Attributes
   MODULE_IMAGE_ACQUISITION_RESULTS                                             = 134,   // Table C.4-15                Image Acquisition Results Module Attributes
   // MODULE_RADIATION_DOSE                                                     = 135,   // (Retired)
   MODULE_BILLING_AND_MATERIAL_MANAGEMENT_CODES                                 = 136,   // Table C.4-17                Billing and Material Management Code Module Attributes
   MODULE_PRESENTATION_LUT                                                      = 137,   // Table C.11-4                Presentation LUT Module Attributes
   // MODULE_PRINT_REQUEST                                                      = 138,   // (Retired)
   // MODULE_PATIENT_RELATIONSHIP_META                                          = 139,   // (Retired)
   // MODULE_NM_SERIES_RETIRED                                                  = 140,   // (Retired)
   // MODULE_NM_EQUIPMENT_RETIRED                                               = 141,   // (Retired)
   // MODULE_NM_IMAGE_RETIRED                                                   = 142,   // (Retired)
   // MODULE_NM_SPECT_ACQUISITION_IMAGE_RETIRED                                 = 143,   // (Retired)
   // MODULE_NM_MULTI_GATED_ACQUISITION_IMAGE_RETIRED                           = 144,   // (Retired)
   // MODULE_US_FRAME_OF_REFERENCE_RETIRED                                      = 145,   // (Retired)
   // MODULE_US_REGION_CALIBRATION_RETIRED                                      = 146,   // (Retired)
   // MODULE_US_IMAGE_RETIRED                                                   = 147,   // (Retired)
   MODULE_FILESET_IDENTIFICATION                                                = 148,   // Table F.3-2                 File-Set Identification Module Attributes
   MODULE_DIRECTORY_INFORMATION                                                 = 149,   // Table F.3-3                 Directory Information Module Attributes
   MODULE_PATIENT_KEY                                                           = 150,   // Table F.5-1                 Patient Keys
   MODULE_STUDY_KEY                                                             = 151,   // Table F.5-2                 Study Keys
   MODULE_SERIES_KEY                                                            = 152,   // Table F.5-3                 Series Keys
   MODULE_IMAGE_KEY                                                             = 153,   // Table F.5-4                 Image Keys
   // MODULE_OVERLAY_KEY                                                        = 154,   // (Retired)
   // MODULE_MODALITY_LUT_KEY                                                   = 155,   // (Retired)
   // MODULE_VOI_LUT_KEY                                                        = 156,   // (Retired)
   // MODULE_CURVE_KEY                                                          = 157,   // (Retired)
   // MODULE_STORED_PRINT_KEY                                                   = 158,   // (Retired)
   MODULE_RT_DOSE_KEY                                                           = 159,   // Table F.5-19                RT Dose Keys
   MODULE_RT_STRUCTURE_SET_KEY                                                  = 160,   // Table F.5-20                RT Structure Set Keys
   MODULE_RT_PLAN_KEY                                                           = 161,   // Table F.5-21                RT Plan Keys
   MODULE_RT_TREATMENT_RECORD_KEY                                               = 162,   // Table F.5-22                RT Treatment Record Keys
   // MODULE_TOPIC_KEY                                                          = 163,   // (Retired)
   // MODULE_VISIT_KEY                                                          = 164,   // (Retired)
   // MODULE_RESULTS_KEY                                                        = 165,   // (Retired)
   // MODULE_INTERPRETATION_KEY                                                 = 166,   // (Retired)
   // MODULE_STUDY_COMPONENT_KEY                                                = 167,   // (Retired)
   MODULE_PRIVATE_KEY                                                           = 168,   // Table F.6.1                 Private Directory Record Definition
   // MODULE_SPECIMEN_IDENTIFICATION                                            = 169,   // (Retired)
   MODULE_DX_SERIES                                                             = 170,   // Table C.8-68                DX Series Module Attributes
   MODULE_DX_ANATOMY_IMAGED                                                     = 171,   // Table C.8-69                DX Anatomy Imaged Module Attributes
   MODULE_DX_IMAGE                                                              = 172,   // Table C.8-70                DX Image Module Attributes
   MODULE_DX_DETECTOR                                                           = 173,   // Table C.8-71                DX Detector Module Attributes
   MODULE_DX_POSITIONING                                                        = 174,   // Table C.8-72                DX Positioning Module Attributes
   MODULE_ACQUISITION_CONTEXT                                                   = 175,   // Table C.7.6.14-1            Acquisition Context Module Attributes
   MODULE_X_RAY_ACQUISITION_DOSE                                                = 176,   // Table C.8-33                X-Ray Acquisition Dose Module Attributes
   MODULE_X_RAY_GENERATION                                                      = 177,   // Table C.8-34                X-Ray Generation Module Attributes
   MODULE_X_RAY_FILTRATION                                                      = 178,   // Table C.8-35                X-Ray Filtration Module Attributes
   MODULE_X_RAY_GRID                                                            = 179,   // Table C.8-36                X-Ray Grid Module Attributes
   MODULE_IMAGE_HISTOGRAM                                                       = 180,   // Table C.11.5-1              Image Histogram Module Attributes
   MODULE_MAMMOGRAPHY_SERIES                                                    = 181,   // Table C.8-73                Mammography Series Module Attributes
   MODULE_MAMMOGRAPHY_IMAGE                                                     = 182,   // Table C.8-74                Mammography Image Module Attributes
   MODULE_INTRA_ORAL_SERIES                                                     = 183,   // Table C.8-75                Intra-Oral Series Module Attributes
   MODULE_INTRA_ORAL_IMAGE                                                      = 184,   // Table C.8-76                Intra-Oral Image Module Attributes
   MODULE_RT_GENERAL_TREATMENT_RECORD                                           = 185,   // Table C.8-53                RT General Treatment Record Module Attributes
   MODULE_RT_TREATMENT_MACHINE_RECORD                                           = 186,   // Table C.8-54                RT Treatment Machine Record Module Attributes
   MODULE_MEASURED_DOSE_REFERENCE_RECORD                                        = 187,   // Table C.8-55                Measured Dose Reference Record Module Attributes
   MODULE_CALCULATED_DOSE_REFERENCE_RECORD                                      = 188,   // Table C.8-56                Calculated Dose Reference Record Module Attributes
   MODULE_RT_BEAMS_SESSION_RECORD                                               = 189,   // Table C.8-57                RT Beams Session Record Module Attributes
   MODULE_RT_TREATMENT_SUMMARY_RECORD                                           = 190,   // Table C.8-59                RT Treatment Summary Record Module Attributes
   MODULE_RT_BRACHY_SESSION_RECORD                                              = 191,   // Table C.8-58                RT Brachy Session Record Module Attributes
   MODULE_VL_IMAGE                                                              = 192,   // Table C.8-77                VL Image Module Attributes
   MODULE_SLIDE_COORDINATES                                                     = 193,   // Table C.8-78                Slide Coordinates Module Attributes
   // MODULE_BASIC_PRINT_IMAGE_OVERLAY_BOX                                      = 194,   // (Retired)
   MODULE_PRINTER_CONFIGURATION                                                 = 195,   // Table C.13-13               Printer Configuration Module Attributes
   MODULE_SR_DOCUMENT_SERIES                                                    = 196,   // Table C.17-1                SR Document Series Module Attributes
   MODULE_SR_DOCUMENT_GENERAL                                                   = 197,   // Table C.17-2                SR Document General Module Attributes
   MODULE_SR_DOCUMENT_CONTENT                                                   = 198,   // Table C.17-4                SR Document Content Module Attributes
   MODULE_SR_DOCUMENT_KEY                                                       = 199,   // Table F.5-25                SR Document Keys
   MODULE_SCHEDULED_PROCEDURE_STEP                                              = 200,   // Table C.4-10                Scheduled Procedure Step Module Attributes
   MODULE_REQUESTED_PROCEDURE                                                   = 201,   // Table C.4-11                Requested Procedure Module Attributes
   MODULE_IMAGING_SERVICE_REQUEST                                               = 202,   // Table C.4-12                Imaging Service Request Module Attributes
   MODULE_PRESENTATION_SERIES                                                   = 203,   // Table C.11.9-1              Presentation Series Module Attributes
   MODULE_PRESENTATION_STATE_IDENTIFICATION                                     = 204,   // Table C.11.10-1             Presentation State Identification Module Attributes
   MODULE_BITMAP_DISPLAY_SHUTTER                                                = 205,   // Table C.7.6.15-1            Bitmap Display Shutter Module Attributes
   MODULE_OVERLAY_ACTIVATION                                                    = 206,   // Table C.11.7-1              Overlay Activation Module Attributes
   MODULE_DISPLAYED_AREA                                                        = 207,   // Table C.10-4                Displayed Area Module Attributes
   MODULE_GRAPHIC_ANNOTATION                                                    = 208,   // Table C.10-5                Graphic Annotation Module Attributes
   MODULE_SPATIAL_TRANSFORMATION                                                = 209,   // Table C.10-6                Spatial Transformation Module Attributes
   MODULE_GRAPHIC_LAYER                                                         = 210,   // Table C.10-7                Graphic Layer Module Attributes
   MODULE_SOFTCOPY_VOI_LUT                                                      = 211,   // Table C.11.8-1              Softcopy VOI LUT Module Attributes
   MODULE_SOFTCOPY_PRESENTATION_LUT                                             = 212,   // Table C.11.6-1              Softcopy Presentation LUT Module Attributes
   MODULE_SYNCHRONIZATION                                                       = 213,   // Table C.7-7                 Synchronization Module Attributes
   MODULE_WAVEFORM_IDENTIFICATION                                               = 214,   // Table C.10-8                Waveform Identification Module Attributes
   MODULE_WAVEFORM                                                              = 215,   // Table C.10-9                Waveform Module Attributes
   MODULE_WAVEFORM_ANNOTATION                                                   = 216,   // Table C.10-11               Waveform Annotation Module Attributes
   MODULE_PRESENTATION_KEY                                                      = 217,   // Table F.5-23                Presentation Keys
   MODULE_WAVEFORM_KEY                                                          = 218,   // Table F.5-24                Waveform Keys
   MODULE_CLINICAL_TRIAL_SUBJECT                                                = 219,   // Table C.7-2b                Clinical Trial Subject Module Attributes
   MODULE_CLINICAL_TRIAL_STUDY                                                  = 220,   // Table C.7-4b                Clinical Trial Study Module Attributes
   MODULE_CLINICAL_TRIAL_SERIES                                                 = 221,   // Table C.7-5b                Clinical Trial Series Module Attributes
   MODULE_MULTI_FRAME_FUNCTIONAL_GROUPS                                         = 222,   // Table C.7.6.16-1            Multi-frame Functional Groups Module Attributes
   MODULE_MULTI_FRAME_DIMENSION                                                 = 223,   // Table C.7.6.17-1            Multi-frame Dimension Module Attributes
   MODULE_CARDIAC_SYNCHRONIZATION                                               = 224,   // Table C.7.6.18-1            Cardiac Synchronization Module Attributes
   MODULE_RESPIRATORY_SYNCHRONIZATION                                           = 225,   // Table C.7.6.18-2            Respiratory Synchronization Module Attributes
   MODULE_BULK_MOTION_SYNCHRONIZATION                                           = 226,   // Table C.7.6.18-3            Bulk Motion Synchronization Module Attributes
   MODULE_SUPPLEMENTAL_PALETTE_COLOR_LOOKUP_TABLE                               = 227,   // Table C.7.6.19-1            Supplemental Palette Color Lookup Table Module Attributes
   MODULE_ENHANCED_MR_IMAGE                                                     = 228,   // Table C.8-79                Enhanced MR Image Module Attributes
   MODULE_MR_PULSE_SEQUENCE                                                     = 229,   // Table C.8-87                MR Pulse Sequence Module Attributes
   MODULE_MR_SPECTROSCOPY                                                       = 230,   // Table C.8-102               MR Spectroscopy Module Attributes
   MODULE_MR_SPECTROSCOPY_PULSE_SEQUENCE                                        = 231,   // Table C.8-103               MR Spectroscopy Pulse Sequence Module Attributes
   MODULE_MR_SPECTROSCOPY_DATA                                                  = 232,   // Table C.8-106               MR Spectroscopy Data Module Attributes
   MODULE_RAW_DATA                                                              = 233,   // Table C.19-1                Raw Data Module Attributes
   MODULE_SC_MULTI_FRAME_IMAGE                                                  = 234,   // Table C.8-25b               SC Multi-frame Image Module Attributes
   MODULE_SC_MULTI_FRAME_VECTOR                                                 = 235,   // Table C.8-25c               SC Multi-frame Vector Module Attributes
   MODULE_KEY_OBJECT_DOCUMENT_SERIES                                            = 236,   // Table C.17.6-1              Key Object Document Series Module Attributes
   MODULE_KEY_OBJECT_DOCUMENT                                                   = 237,   // Table C.17.6-2              Key Object Document Module Attributes
   // MODULE_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_RELATIONSHIP              = 238,   // (Retired)
   // MODULE_GENERAL_PURPOSE_SCHEDULED_PROCEDURE_STEP_INFORMATION               = 239,   // (Retired)
   // MODULE_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_RELATIONSHIP              = 240,   // (Retired)
   // MODULE_GENERAL_PURPOSE_PERFORMED_PROCEDURE_STEP_INFORMATION               = 241,   // (Retired)
   // MODULE_GENERAL_PURPOSE_RESULTS                                            = 242,   // (Retired)
   MODULE_KEY_OBJECT_DOCUMENT_KEY                                               = 243,   // Table F.5-26                Key Object Document Keys
   MODULE_OPHTHALMIC_PHOTOGRAPHY_SERIES                                         = 244,   // Table C.8.17.1-1            Ophthalmic Photography Series Module Attributes
   MODULE_OPHTHALMIC_PHOTOGRAPHY_IMAGE                                          = 245,   // Table C.8.17.2-1            Ophthalmic Photography Image Module Attributes
   MODULE_OPHTHALMIC_PHOTOGRAPHIC_PARAMETERS                                    = 246,   // Table C.8.17.3-1            Ophthalmic Photographic Parameters Module Attributes
   MODULE_OPHTHALMIC_PHOTOGRAPHY_ACQUISITION_PARAMETERS                         = 247,   // Table C.8.17.4-1            Ophthalmic Photography Acquisition Parameters Module Attributes
   MODULE_OCULAR_REGION_IMAGED                                                  = 248,   // Table C.8.17.5-1            Ocular Region Imaged Module Attributes
   MODULE_STEREOMETRIC_SERIES                                                   = 249,   // Table C.8.18.1-1            Stereometric Series Module Attributes
   MODULE_STEREOMETRIC_RELATIONSHIP                                             = 250,   // Table C.8.18.2-1            Stereometric Relationship Module Attributes
   MODULE_ENHANCED_CONTRAST_BOLUS                                               = 251,   // Table C.7-12b               Enhanced Contrast/Bolus Module Attributes
   MODULE_COMMON_INSTANCE_REFERENCE                                             = 252,   // Table C.12-8                Common Instance Reference Module Attributes
   MODULE_UNDEFINED                                                             = 253,   // (for .NET)

   MODULE_INTERVENTION                                                          = 254,   // Table C.7-19                Intervention Module Attributes
   MODULE_PRESENTATION_STATE_RELATIONSHIP                                       = 255,   // Table C.11.11-1             Presentation State Relationship Module Attributes
   MODULE_PRESENTATION_STATE_SHUTTER                                            = 256,   // Table C.11.12-1             Presentation State Shutter Module Attributes
   MODULE_PRESENTATION_STATE_MASK                                               = 257,   // Table C.11.13-1             Presentation State Mask Module Attributes
   MODULE_ICC_PROFILE                                                           = 258,   // Table C.11.15-1             ICC Profile Module Attributes
   MODULE_PRESENTATION_STATE_BLENDING                                           = 259,   // Table C.11.14-1             Presentation State Blending Module Attributes
   MODULE_MR_SERIES                                                             = 260,   // Table C.8-101               MR Series Module Attributes
   MODULE_ENHANCED_GENERAL_EQUIPMENT                                            = 261,   // Table C.7-8b                Enhanced General Equipment Module Attributes
   MODULE_CT_SERIES                                                             = 262,   // Table C.8-113               CT Series Module Attributes
   MODULE_ENHANCED_CT_IMAGE                                                     = 263,   // Table C.8-114               Enhanced CT Image Module Attributes
   MODULE_SPATIAL_REGISTRATION_SERIES                                           = 264,   // Table C.20.1-1              Spatial Registration Series Module Attributes
   MODULE_SPATIAL_REGISTRATION                                                  = 265,   // Table C.20.2-1              Spatial Registration Module Attributes
   MODULE_DEFORMABLE_SPATIAL_REGISTRATION                                       = 266,   // Table C.20.3-1              Deformable Spatial Registration Module Attributes
   MODULE_SPATIAL_FIDUCIALS_SERIES                                              = 267,   // Table C.21.1-1              Spatial Fiducials Series Module Attributes
   MODULE_SPATIAL_FIDUCIALS                                                     = 268,   // Table C.21.2-1              Spatial Fiducials Module Attributes
   MODULE_HANGING_PROTOCOL_DEFINITION                                           = 269,   // Table C.23.1-1              Hanging Protocol Definition Module Attributes
   MODULE_HANGING_PROTOCOL_ENVIRONMENT                                          = 270,   // Table C.23.2-1              Hanging Protocol Environment Module Attributes
   MODULE_HANGING_PROTOCOL_DISPLAY                                              = 271,   // Table C.23.3-1              Hanging Protocol Display Module Attributes
   MODULE_ENCAPSULATED_DOCUMENT_SERIES                                          = 272,   // Table C.24-1                Encapsulated Document Series Module Attributes
   MODULE_ENCAPSULATED_DOCUMENT                                                 = 273,   // Table C.24-2                Encapsulated Document Module Attributes
   MODULE_REAL_WORLD_VALUE_MAPPING_SERIES                                       = 274,   // Table C.25.1-1              Real World Value Mapping Series Module Attributes
   MODULE_REAL_WORLD_VALUE_MAPPING                                              = 275,   // Table C.25.2-1              Real World Value Mapping Module Attributes
   MODULE_XA_XRF_SERIES                                                         = 276,   // Table C.8.19.1-1            XA/XRF Series Module Attributes
   MODULE_ENHANCED_XA_XRF_IMAGE                                                 = 277,   // Table C.8.19.2-1            Enhanced XA/XRF Image Module Table
   MODULE_XA_XRF_ACQUISITION                                                    = 278,   // Table C.8.19.3-1            XA/XRF Acquisition Module Attributes
   MODULE_X_RAY_IMAGE_INTENSIFIER                                               = 279,   // Table C.8.19.4-1            X-Ray Image Intensifier Module Attributes
   MODULE_X_RAY_DETECTOR                                                        = 280,   // Table C.8.19.5-1            X-Ray Detector Module Attributes
   MODULE_XA_XRF_MULTI_FRAME_PRESENTATION                                       = 281,   // Table C.8.19.7-1            XA/XRF Multi-frame Presentation Module Attributes
   MODULE_RT_ION_TOLERANCE_TABLES                                               = 282,   // Table C.8.8.24-1            RT Ion Tolerance Tables Module Attributes
   MODULE_RT_ION_BEAMS                                                          = 283,   // Table C.8.8.25-1            RT Ion Beams Module Attributes
   MODULE_RT_ION_BEAMS_SESSION_RECORD                                           = 284,   // Table C.8.8.26-1            RT Ion Beams Session Record Module Attributes
   MODULE_SEGMENTATION_SERIES                                                   = 285,   // Table C.8.20-1              Segmentation Series Module Attributes
   MODULE_SEGMENTATION_IMAGE                                                    = 286,   // Table C.8.20-2              Segmentation Image Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_SERIES                                          = 287,   // Table C.8.17.6-1            Ophthalmic Tomography Series Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_IMAGE                                           = 288,   // Table C.8.17.7-1            Ophthalmic Tomography Image Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_ACQUISITION_PARAMETERS                          = 289,   // Table C.8.17.8-1            Ophthalmic Tomography Acquisition Parameters Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_PARAMETERS                                      = 290,   // Table C.8.17.9-1            Ophthalmic Tomography Parameters Module Attributes
   MODULE_ENHANCED_SERIES                                                       = 291,   // Table C.7-5c                Enhanced Series Module Attributes
   MODULE_PATIENT_ORIENTATION                                                   = 292,   // Table C.7.6.20-1            Patient Orientation Module Attributes
   MODULE_IMAGE_EQUIPMENT_COORDINATE_RELATIONSHIP                               = 293,   // Table C.7.6.21-1            Image - Equipment Coordinate Relationship Module Attributes
   MODULE_X_RAY_3D_IMAGE                                                        = 294,   // Table C.8.21.1-1            X-Ray 3D Image Module Attributes
   MODULE_X_RAY_3D_ANGIOGRAPHIC_IMAGE_CONTRIBUTING_SOURCES                      = 295,   // Table C.8.21.2.1-1          X-Ray 3D Angiographic Image Contributing Sources Module Attributes
   MODULE_X_RAY_3D_ANGIOGRAPHIC_ACQUISITION                                     = 296,   // Table C.8.21.3.2-1          X-Ray 3D Angiographic Acquisition Module Attributes
   MODULE_X_RAY_3D_RECONSTRUCTION                                               = 297,   // Table C.8.21.4-1            X-Ray 3D Reconstruction Module Attributes
   MODULE_X_RAY_3D_CRANIOFACIAL_IMAGE_CONTRIBUTING_SOURCES                      = 298,   // Table C.8.21.2.2-1          X-Ray 3D Craniofacial Image Contributing Sources Module Attributes
   MODULE_X_RAY_3D_CRANIOFACIAL_ACQUISITION                                     = 299,   // Table C.8.21.3.3-1          X-Ray 3D Craniofacial Acquisition Module Attributes
   MODULE_ENHANCED_PET_SERIES                                                   = 300,   // Table C.8.22-1              Enhanced PET Series Module Attributes
   MODULE_ENHANCED_PET_ISOTOPE                                                  = 301,   // Table C.8.22-9              Enhanced PET Isotope Module Attributes
   MODULE_ENHANCED_PET_ACQUISITION                                              = 302,   // Table C.8.22-2              Enhanced PET Acquisition Module Attributes
   MODULE_ENHANCED_PET_IMAGE                                                    = 303,   // Table C.8.22-3              Enhanced PET Image Module Attributes

   // sup117_ft.doc
   // sup130_ft.doc
   MODULE_LENSOMETRY_MEASUREMENTS_SERIES                                        = 304,   // Table C.8.25.1-1            Lensometry Measurements Series Module Attributes
   MODULE_GENERAL_OPHTHALMIC_REFRACTIVE_MEASUREMENTS                            = 305,   // Table C.8.25.7-1            General Ophthalmic Refractive Measurements Module Attributes
   MODULE_LENSOMETRY_MEASUREMENTS                                               = 306,   // Table C.8.25.8-1            Lensometry Measurements Module Attributes
   MODULE_AUTOREFRACTION_MEASUREMENTS_SERIES                                    = 307,   // Table C.8.25.2-1            Autorefraction Measurements Series Module Attributes
   MODULE_AUTOREFRACTION_MEASUREMENTS                                           = 308,   // Table C.8.25.9-1            Autorefraction Measurements Module Attributes
   MODULE_KERATOMETRY_MEASUREMENTS_SERIES                                       = 309,   // Table C.8.25.3-1            Keratometry Measurements Series Module Attributes
   MODULE_KERATOMETRY_MEASUREMENTS                                              = 310,   // Table C.8.25.10-1           Keratometry Measurements Module Attributes
   MODULE_SUBJECTIVE_REFRACTION_MEASUREMENTS_SERIES                             = 311,   // Table C.8.25.4-1            Subjective Refraction Measurements Series Module Attributes
   MODULE_SUBJECTIVE_REFRACTION_MEASUREMENTS                                    = 312,   // Table C.8.25.11-1           Subjective Refraction Measurements Module Attributes
   MODULE_VISUAL_ACUITY_MEASUREMENTS_SERIES                                     = 313,   // Table C.8.25.5-1            Visual Acuity Measurements Series Module Attributes
   MODULE_VISUAL_ACUITY_MEASUREMENTS                                            = 314,   // Table C.8.25.12-1           Visual Acuity Measurements Module Attributes

   // Part4
   MODULE_SUBSTANCE_ADMINISTRATION_LOGGING                                      = 315,   // Table C.26-4                Substance Administration Log Module Attributes
   MODULE_MODALITY_HANGING_PROTOCOL                                             = 316,   // Table K.6-1                 Attributes for the Modality Worklist Information Model
   MODULE_PRODUCT_CHARACTERISTICS                                               = 317,   // Table C.26-1                Product Characteristics Module Attributes
   MODULE_SUBSTANCE_APPROVAL_PATIENT                                            = 318,   // Table V.6-2                 Patient: Attributes for the Substance Approval Query Information Model
   MODULE_SUBSTANCE_APPROVAL_VISIT                                              = 319,   // Table V.6-2                 Visit: Attributes for the Substance Approval Query Information Model
   MODULE_SUBSTANCE_APPROVAL_PRODUCT                                            = 320,   // Table V.6-2                 Product: Attributes for the Substance Approval Query Information Model
   MODULE_SUBSTANCE_ADMINISTRATION                                              = 321,   // Table C.26-3                Substance Administration Module Attributes
   MODULE_SUBSTANCE_APPROVAL                                                    = 322,   // Table C.26-2                Substance Approval Module Attributes

      // New Modules begin here
   // MODULE_BASIC_FILM_BOX_PRESENTATION_MODULE                                 = 323,   // (Retired)
   MODULE_IMAGE_BOX_PRESENTATION_MODULE                                         = 324,   // Table C.13-5                Image Box Pixel Presentation Module Attributes
   MODULE_SOP_COMMON_INFORMATION                                                = 325,   // Table C.12-1                SOP Common Module Attributes
   MODULE_INSTANCE_AVAILABILITY_NOTIFICATION                                    = 326,   // Table C.4.23-1              Instance Availability Notification Module Attributes
   MODULE_MEDIA_CREATION_MANAGEMENT                                             = 327,   // Table C.22.1-1              Media Creation Management Module Attributes

   MODULE_SPECTROSCOPY_KEY                                                      = 328,   // Table F.5-27                Spectroscopy Keys
   MODULE_RAW_DATA_KEY                                                          = 329,   // Table F.5-28                Raw Data Keys
   MODULE_REGISTRATION_KEY                                                      = 330,   // Table F.5-29                Registration Keys
   MODULE_FIDUCIAL_KEY                                                          = 331,   // Table F.5-30                Fiducial Keys
   MODULE_HANGING_PROTOCOL_KEY                                                  = 332,   // Table F.5-31                Hanging Protocol Keys
   MODULE_ENCAPSULATED_DOCUMENT_KEY                                             = 333,   // Table F.5-32                Encapsulated Document Keys
   // MODULE_HL7_STRUCTURED_DOCUMENT_KEY                                        = 334,   // (Retired)
   MODULE_REAL_WORLD_VALUE_MAPPING_KEY                                          = 335,   // Table F.5-34                Real World Value Mapping Keys
   MODULE_STEREOMETRIC_RELATIONSHIP_KEY                                         = 336,   // Table F.5-35                Stereometric Relationship Keys


   MODULE_STRUCTURED_DISPLAY                                                    = 337,   // Table C.11.16-1             Structured Display Module Attributes
   MODULE_STRUCTURED_DISPLAY_IMAGE_BOX                                          = 338,   // Table C.11.17-1             Structured Display Image Box Module Attributes
   MODULE_STRUCTURED_DISPLAY_ANNOTATION                                         = 339,   // Table C.11.18-1             Structured Display Annotation Module Attributes

   // All 2008 supplements go here
   MODULE_ENHANCED_US_SERIES                                                    = 340,   // Table C.8.24.1-1            Enhanced US Series Module Attributes
   MODULE_ULTRASOUND_FRAME_OF_REFERENCE                                         = 341,   // Table C.8.24.2-1            Ultrasound Frame of Reference Module Attributes
   MODULE_ENHANCED_PALETTE_COLOR_LOOKUP_TABLE                                   = 342,   // Table C.7.6.23-1            Enhanced Palette Color Lookup Table Module Attributes
   MODULE_ENHANCED_US_IMAGE                                                     = 343,   // Table C.8.24.3-1            Enhanced US Image Module Attributes
   MODULE_IVUS_IMAGE                                                            = 344,   // Table C.8.24.4-1            IVUS Image Module Attributes
   MODULE_EXCLUDED_INTERVALS                                                    = 345,   // Table C.8.24.5-1            Excluded Intervals Module Attributes
   MODULE_SPECIMEN                                                              = 346,   // Table C.7.6.22-1            Specimen Module Attributes
   MODULE_ENHANCED_MAMMOGRAPHY_SERIES                                           = 347,   // Table C.8-76b               Enhanced Mammography Series Module Attributes
   MODULE_BREAST_TOMOSYNTHESIS_CONTRIBUTING_SOURCES                             = 348,   // Table C.8.21.2.3-1          Breast Tomosynthesis Contributing Sources Module Attributes
   MODULE_BREAST_TOMOSYNTHESIS_ACQUISITION                                      = 349,   // Table C.8.21.3.4-1          Breast Tomosynthesis Acquisition Module Attributes
   MODULE_BREAST_VIEW                                                           = 350,   // Table C.8.21.6-1            Breast View Module Attributes
   MODULE_SURFACE_SEGMENTATION                                                  = 351,   // Table C.8.23-1              Surface Segmentation Module Attributes
   MODULE_SURFACE_MESH                                                          = 352,   // Table C.27-1                Surface Mesh Module Attributes
   MODULE_COLOR_PALETTE_DEFINITION                                              = 353,   // Table C.28.1-1              Color Palette Definition Module Attributes

   // 2011
   MODULE_FRAME_EXTRACTION                                                      = 354,   // Table C.12-9                Frame Extraction Module Attributes
   MODULE_GENERIC_IMPLANT_TEMPLATE_2D_DRAWINGS                                  = 355,   // Table C.29.1.2-1            Generic Implant Template 2D Drawings Module Attributes
   MODULE_GENERIC_IMPLANT_TEMPLATE_3D_MODELS                                    = 356,   // Table C.29.1.3-1            Generic Implant Template 3D Models Module Attributes
   MODULE_GENERIC_IMPLANT_TEMPLATE_DESCRIPTION                                  = 357,   // Table C.29.1.1-1            Generic Implant Template Description Module Attributes
   MODULE_GENERIC_IMPLANT_TEMPLATE_MATING_FEATURES                              = 358,   // Table C.29.1.4-1            Generic Implant Template Mating Features Module Attributes
   MODULE_GENERIC_IMPLANT_TEMPLATE_PLANNING_LANDMARKS                           = 359,   // Table C.29.1.5-1            Generic Implant Template Planning Landmarks Module Attributes
   MODULE_GRAPHIC_GROUP                                                         = 360,   // Table C.10-12               Graphic Group Module Attributes
   MODULE_IMPLANT_ASSEMBLY_TEMPLATE                                             = 361,   // Table C.29.2-1              Implant Assembly Template Module Attributes
   MODULE_OPTICAL_PATH                                                          = 362,   // Table C.8.12.5-1            Optical Path Module Attributes
   MODULE_WHOLE_SLIDE_MICROSCOPY_SERIES                                         = 363,   // Table C.8.12.3-1            Whole Slide Microscopy Series Module Attributes
   MODULE_WHOLE_SLIDE_MICROSCOPY_IMAGE                                          = 364,   // Table C.8.12.4-1            Whole Slide Microscopy Image Module Attributes
   MODULE_MULTI_RESOLUTION_NAVIGATION                                           = 365,   // Table C.8.12.7-1            Multi-Resolution Navigation Module Attributes
   MODULE_SLIDE_LABEL                                                           = 366,   // Table C.8.12.8-1            Slide Label Module Attributes
   MODULE_XA_XRF_PRESENTATION_STATE_MASK                                        = 367,   // Table C.11.19-1             XA/XRF Presentation State Mask Module Attributes
   MODULE_XA_XRF_PRESENTATION_STATE_SHUTTER                                     = 368,   // Table C.11.20-1             XA/XRF Presentation State Shutter Module Attributes
   MODULE_XA_XRF_PRESENTATION_STATE_PRESENTATION                                = 369,   // Table C.11.21-1             XA/XRF Presentation State Presentation Module Attributes
   MODULE_OPHTHALMIC_AXIAL_MEASUREMENTS_SERIES                                  = 370,   // Table C.8.25.13-1           Ophthalmic Axial Measurements Series Module Attributes
   MODULE_OPHTHALMIC_AXIAL_MEASUREMENTS                                         = 371,   // Table C.8.25.14-1           Ophthalmic Axial Measurements Module Attributes
   MODULE_INTRAOCULAR_LENS_CALCULATIONS_SERIES                                  = 372,   // Table C.8.25.15-1           Intraocular Lens Calculations Series Module Attributes
   MODULE_INTRAOCULAR_LENS_CALCULATIONS                                         = 373,   // Table C.8.25.16-1           Intraocular Lens Calculations Module Attributes
   MODULE_IMPLANT_TEMPLATE_GROUP                                                = 374,   // Table C.29.3-1              Implant Template Group Module Attributes
   MODULE_RT_BEAMS_DELIVERY_INSTRUCTION                                         = 375,   // Table C.8.8.29-1            RT Beams Delivery Instruction Module Attributes
   MODULE_VISUAL_FIELD_STATIC_PERIMETRY_MEASUREMENTS_SERIES                     = 376,   // Table C.8.26.1-1            Visual Field Static Perimetry Measurements Series Module Attributes
   MODULE_VISUAL_FIELD_STATIC_PERIMETRY_TEST_PARAMETERS                         = 377,   // Table C.8.26.2-1            Visual Field Static Perimetry Test Parameters Module Attributes
   MODULE_VISUAL_FIELD_STATIC_PERIMETRY_TEST_RELIABILITY                        = 378,   // Table C.8.26.3-1            Visual Field Static Perimetry Test Reliability Module Attributes
   MODULE_VISUAL_FIELD_STATIC_PERIMETRY_TEST_MEASUREMENTS                       = 379,   // Table C.8.26.4-1            Visual Field Static Perimetry Test Measurements Module Attributes
   MODULE_VISUAL_FIELD_STATIC_PERIMETRY_TEST_RESULTS                            = 380,   // Table C.8.26.5-1            Visual Field Static Perimetry Test Results Module Attributes
   MODULE_OPHTHALMIC_PATIENT_CLINICAL_INFORMATION_AND_TEST_LENS_PARAMETERS      = 381,   // Table C.8.26.6-1            Ophthalmic Patient Clinical Information and Test Lens Parameters Module Attributes
   MODULE_INTRAVASCULAR_OCT_SERIES                                              = 382,   // Table C.8.27.1-1            Intravascular OCT Series Module Attributes
   MODULE_INTRAVASCULAR_OCT_IMAGE                                               = 383,   // Table C.8.27.2-1            Intravascular OCT Image Module Attributes
   MODULE_INTRAVASCULAR_OCT_ACQUISITION_PARAMETERS                              = 384,   // Table C.8.27.3-1            Intravascular OCT Acquisition Parameters Module Attributes
   MODULE_INTRAVASCULAR_OCT_PROCESSING_PARAMETERS                               = 385,   // Table C.8.27.4-1            Intravascular OCT Processing Parameters Module Attributes
   MODULE_INTRAVASCULAR_IMAGE_ACQUISITION_PARAMETERS                            = 386,   // Table C.8.27.5-1            Intravascular Image Acquisition Parameters Module Attributes
   MODULE_OPHTHALMIC_THICKNESS_MAP_SERIES                                       = 387,   // Table C.8.28.1-1            Ophthalmic Thickness Map Series Module Attributes
   MODULE_OPHTHALMIC_THICKNESS_MAP                                              = 388,   // Table C.8.28.2-1            Ophthalmic Thickness Map Module Attributes
   MODULE_OPHTHALMIC_THICKNESS_MAP_QUALITY_RATING                               = 389,   // Table C.8.28.3-1            Ophthalmic Thickness Map Quality Rating Module Attributes
   MODULE_UNIFIED_PROCEDURE_STEP_RELATIONSHIP                                   = 390,   // Table C.30.4-1              Unified Procedure Step Relationship Module Attributes
   MODULE_UNIFIED_PROCEDURE_STEP_SCHEDULED_PROCEDURE_INFORMATION                = 391,   // Table C.30.2-1              Unified Procedure Step Scheduled Procedure Information Module Attributes
   MODULE_UNIFIED_PROCEDURE_STEP_PROGRESS_INFORMATION                           = 392,   // Table C.30.1-1              Unified Procedure Step Progress Information Module Attributes
   MODULE_UNIFIED_PROCEDURE_STEP_PERFORMED_PROCEDURE_INFORMATION                = 393,   // Table C.30.3-1              Unified Procedure Step Performed Procedure Information Module Attributes
   MODULE_RT_GENERAL_MACHINE_VERIFICATION                                       = 394,   // Table C.31-1                RT General Machine Verification Module Attributes
   MODULE_RT_ION_MACHINE_VERIFICATION                                           = 395,   // Table C.31-3                RT Ion Machine Verification Module Attributes
   MODULE_RT_CONVENTIONAL_MACHINE_VERIFICATION                                  = 396,   // Table C.31-2                RT Conventional Machine Verification Module Attributes

   // 2014
   // MODULE_X_RAY_TOMO_ACQUISITION                                             = 397,   // (Not Used)
   // MODULE_RT_ROI_OBSERVATIONS                                                = 398,   // (Not Used)
   MODULE_ENHANCED_PET_CORRECTIONS                                              = 399,   // Table C.8.22-19             Enhanced PET Corrections Module Attributes
   MODULE_OPTICAL_SURFACE_SCANNER_SERIES                                        = 400,   // Table C.8.29-1              Optical Surface Scanner Series Module Attributes
   MODULE_UV_MAPPING                                                            = 401,   // Table C.27.6-1              UV Mapping Module Attributes
   MODULE_SCAN_PROCEDURE                                                        = 402,   // Table C.8.29-2              Scan Procedure Module Attributes
   MODULE_POINT_CLOUD                                                           = 403,   // Table C.27.5-1              Point Cloud Module Attributes
   MODULE_CORNEAL_TOPOGRAPHY_MAP_SERIES                                         = 404,   // Table C.8.30.1-1            Corneal Topography Map Series Module Attributes
   MODULE_CORNEAL_TOPOGRAPHY_MAP_IMAGE                                          = 405,   // Table C.8.30.2-1            Corneal Topography Map Image Module Attributes
   MODULE_CORNEAL_TOPOGRAPHY_MAP_ANALYSIS                                       = 406,   // Table C.8.30.3-1            Corneal Topography Map Analysis Module Attributes
   MODULE_ENHANCED_MAMMOGRAPHY_IMAGE                                            = 407,   // Table C.8.31-1              Enhanced Mammography Image Module Attributes

   MODULE_DISPLAY_SYSTEM                                                        = 408,   // Table C.32.1-1              Display System Module Attributes
   MODULE_TARGET_LUMINANCE_CHARACTERISTICS                                      = 409,   // Table C.32.2-1              Target Luminance Characteristics Module Attributes
   MODULE_QA_RESULTS                                                            = 410,   // Table C.32.3-1              QA Results Module Attributes

   // 2015C
   MODULE_PARAMETRIC_MAP_SERIES                                                 = 411,   // Table PS3.3_C.8.32-1        Parametric Map Series Module Attributes
   MODULE_FLOATING_POINT_IMAGE_PIXEL                                            = 412,   // Table PS3.3_C.7.6.24-1      Floating Point Image Pixel Module Attributes
   MODULE_DOUBLE_FLOATING_POINT_IMAGE_PIXEL                                     = 413,   // Table PS3.3_C.7.6.25-1      Double Floating Point Image Pixel Module Attributes
   MODULE_PARAMETRIC_MAP_IMAGE                                                  = 414,   // Table PS3.3_C.8.32-2        Parametric Map Image Module Attributes
   MODULE_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_STEREOGRAPHIC_PROJECTION            = 415,   // Table C.8.17.11-1           Wide Field Ophthalmic Photography Stereographic Projection Module Attributes
   MODULE_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_QUALITY_RATING                      = 416,   // Table C.8.17.13-1           Wide Field Ophthalmic Photography Quality Rating Module Attributes
   MODULE_WIDE_FIELD_OPHTHALMIC_PHOTOGRAPHY_3D_COORDINATES                      = 417,   // Table C.8.17.12-1           Wide Field Ophthalmic Photography 3D Coordinates Module Attributes

   // 2021a Modules
   MODULE_GENERAL_REFERENCE                                                     = 418,   // Table C.12-10               General Reference Module Attributes
   MODULE_MULTI_ENERGY_CT_IMAGE                                                 = 419,   // Table C.8.2.2-1             Multi-energy CT Image Module Attributes
   MODULE_VL_PHOTOGRAPHIC_EQUIPMENT                                             = 420,   // Table C.8.12.10-1           VL Photographic Equipment Module Attributes
   MODULE_VL_PHOTOGRAPHIC_ACQUISITION                                           = 421,   // Table C.8.12.11-1           VL Photographic Acquisition Module Attributes
   MODULE_VL_PHOTOGRAPHIC_GEOLOCATION                                           = 422,   // Table C.8.12.12-1           VL Photographic Geolocation Module Attributes
   MODULE_REAL_TIME_BULK_DATA_FLOW                                              = 423,   // Table C.7.6.26-1            Real-Time Bulk Data Flow Module Attributes
   MODULE_REAL_TIME_ACQUISITION                                                 = 424,   // Table C.7.6.28-1            Real-Time Acquisition Module Attributes
   MODULE_CURRENT_FRAME_FUNCTIONAL_GROUPS                                       = 425,   // Table C.7.6.27-1            Current Frame Functional Groups Module Attributes
   MODULE_DERMOSCOPIC_IMAGE                                                     = 426,   // Table C.8.12.13-1           Dermoscopic Image Module Attributes
   MODULE_ADVANCED_BLENDING_PRESENTATION_STATE                                  = 427,   // Table C.11.33-1             Advanced Blending Presentation State Module Attributes
   MODULE_ADVANCED_BLENDING_PRESENTATION_STATE_DISPLAY                          = 428,   // Table C.11.34.1-1           Advanced Blending Presentation State Display Module Attributes
   MODULE_TIMEZONE                                                              = 429,   // Table C.12.5-1              Timezone Module Attributes
   MODULE_ENHANCED_MULTI_ENERGY_CT_ACQUISITION                                  = 430,   // Table C.8.15.4-1            Enhanced Multi-energy CT Acquisition Module Attributes
   MODULE_TRACTOGRAPHY_RESULTS_SERIES                                           = 431,   // Table C.8.33-1              Tractography Results Series Module Attributes
   MODULE_TRACTOGRAPHY_RESULTS                                                  = 432,   // Table C.8.33-2              Tractography Results Module Attributes
   MODULE_RT_BRACHY_APPLICATION_SETUP_DELIVERY_INSTRUCTION                      = 433,   // Table C.8.8.30-1            RT Brachy Application Setup Delivery Instruction Module Attributes
   MODULE_VOLUMETRIC_PRESENTATION_STATE_IDENTIFICATION                          = 434,   // Table C.11.22-1             Volumetric Presentation State Identification Module Attributes
   MODULE_VOLUMETRIC_PRESENTATION_STATE_RELATIONSHIP                            = 435,   // Table C.11.23-1             Volumetric Presentation State Relationship Module Attributes
   MODULE_VOLUME_CROPPING                                                       = 436,   // Table C.11.24-1             Volume Cropping Module Attributes
   MODULE_PRESENTATION_VIEW_DESCRIPTION                                         = 437,   // Table C.11.25-1             Presentation View Description Module Attributes
   MODULE_MULTI_PLANAR_RECONSTRUCTION_GEOMETRY                                  = 438,   // Table C.11.26-1             Multi-Planar Reconstruction Geometry Module Attributes
   MODULE_MPR_VOLUMETRIC_PRESENTATION_STATE_DISPLAY                             = 439,   // Table C.11.27-1             MPR Volumetric Presentation State Display Module Attributes
   MODULE_VOLUMETRIC_GRAPHIC_ANNOTATION                                         = 440,   // Table C.11.28-1             Volumetric Graphic Annotation Module Attributes
   MODULE_PRESENTATION_ANIMATION                                                = 441,   // Table C.11.29-1             Presentation Animation Module Attributes
   MODULE_VOLUME_RENDER_GEOMETRY                                                = 442,   // Table C.11.30-1             Volume Render Geometry Module Attributes
   MODULE_RENDER_SHADING                                                        = 443,   // Table C.11.31-1             Render Shading Module Attributes
   MODULE_RENDER_DISPLAY                                                        = 444,   // Table C.11.32-1             Render Display Module Attributes
   MODULE_CONTENT_ASSESSMENT_RESULTS                                            = 445,   // Table C.33.1-1              Content Assessment Results Module Attributes
   MODULE_CT_PROTOCOL_SERIES                                                    = 446,   // Table C.34.1-1              CT Protocol Series Module Attributes
   MODULE_PROTOCOL_CONTEXT                                                      = 447,   // Table C.34.2-1              Protocol Context Module Attributes
   MODULE_PATIENT_PROTOCOL_CONTEXT                                              = 448,   // Table C.34.3-1              Patient Protocol Context Module Attributes
   MODULE_INSTRUCTIONS                                                          = 449,   // Table C.34.7-1              Instructions Module Attributes
   MODULE_PATIENT_POSITIONING                                                   = 450,   // Table C.34.8-1              Patient Positioning Module Attributes
   MODULE_PERFORMED_CT_ACQUISITION                                              = 451,   // Table C.34.10-1             Performed CT Acquisition Module Attributes
   MODULE_PERFORMED_CT_RECONSTRUCTION                                           = 452,   // Table C.34.12-1             Performed CT Reconstruction Module Attributes
   MODULE_PERFORMED_STORAGE                                                     = 453,   // Table C.34.14-1             Performed Storage Module Attributes
   MODULE_CLINICAL_TRIAL_CONTEXT                                                = 454,   // Table C.34.4-1              Clinical Trial Context Module Attributes
   MODULE_PATIENT_SPECIFICATION                                                 = 455,   // Table C.34.5-1              Patient Specification Module Attributes
   MODULE_EQUIPMENT_SPECIFICATION                                               = 456,   // Table C.34.6-1              Equipment Specification Module Attributes
   MODULE_GENERAL_DEFINED_ACQUISITION                                           = 457,   // Table C.34.9-1              General Defined Acquisition Module Attributes
   MODULE_GENERAL_DEFINED_RECONSTRUCTION                                        = 458,   // Table C.34.11-1             General Defined Reconstruction Module Attributes
   MODULE_DEFINED_STORAGE                                                       = 459,   // Table C.34.13-1             Defined Storage Module Attributes
   MODULE_XA_PROTOCOL_SERIES                                                    = 460,   // Table C.34.16-1             XA Protocol Series Module Attributes
   MODULE_PERFORMED_XA_ACQUISITION                                              = 461,   // Table C.34.17-1             Performed XA Acquisition Module Attributes
   MODULE_PERFORMED_XA_RECONSTRUCTION                                           = 462,   // Table C.34.18-1             Performed XA Reconstruction Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_EN_FACE_SERIES                                  = 463,   // Table C.8.17.17-1           Ophthalmic Tomography En Face Series Module Attributes
   MODULE_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE                 = 464,   // Table C.8.17.14-1           Ophthalmic Optical Coherence Tomography En Face Image Module Attributes
   MODULE_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_EN_FACE_IMAGE_QUALITY_RATING  = 465,   // Table C.8.17.15-1           Ophthalmic Optical Coherence Tomography En Face Image Quality Rating Module Attributes
   MODULE_OPHTHALMIC_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_SERIES                   = 466,   // Table C.8.17.18-1           Ophthalmic Tomography B-scan Volume Analysis Series Module Attributes
   MODULE_OPHTHALMIC_OPTICAL_COHERENCE_TOMOGRAPHY_B_SCAN_VOLUME_ANALYSIS_IMAGE  = 467,   // Table C.8.17.16-1           Ophthalmic Optical Coherence Tomography B-scan Volume Analysis Image Module Attributes
   MODULE_MANUFACTURING_3D_MODEL                                                = 468,   // Table C.35.1-1              Manufacturing 3D Model Module Attributes
   MODULE_IMAGE_BOX_PRESENTATION                                                = 469,   // Table C.13-5                Image Box Pixel Presentation Module Attributes
   MODULE_PALETTE_KEY                                                           = 470,   // Table F.5-36                Palette Keys
   MODULE_IMPLANT_KEY                                                           = 471,   // Table F.5-37                Implant Keys
   MODULE_IMPLANT_ASSEMBLY_KEY                                                  = 472,   // Table F.5-38                Implant Assembly Keys
   MODULE_IMPLANT_GROUP_KEY                                                     = 473,   // Table F.5-39                Implant Group Keys
   MODULE_PLAN_KEY                                                              = 474,   // Table F.5-40                Plan Keys
   MODULE_MEASUREMENT_KEY                                                       = 475,   // Table F.5-41                Measurement Keys
   MODULE_SURFACE_KEY                                                           = 476,   // Table F.5-42                Surface Keys
   MODULE_SURFACE_SCAN_KEY                                                      = 477,   // Table F.5-43                Surface Scan Keys
   MODULE_TRACTOGRAPHY_RESULTS_KEY                                              = 478,   // Table F.5-44                Tractography Results Keys
   MODULE_CONTENT_ASSESSMENT_RESULTS_DIRECTORY_RECORD_RESULTS_KEY               = 479,   // Table F.5-45                Content Assessment Results Directory Record Results Keys
   MODULE_RADIOTHERAPY_KEY                                                      = 480,   // Table F.5-46                Radiotherapy Keys
   MODULE_MAX                                                                   = 480,   //
};
// End of module definitions







//============= CLASS ==========================================================

#define MAKETAG(nGroup,nElement) ((L_UINT32)((((L_UINT32)nGroup) << 16) | nElement))
#define GETGROUP(nTag)           ((L_UINT16)(nTag >> 16))
#define GETELEMENT(nTag)         ((L_UINT16)(nTag & 0xFFFF))

#define DS_METAHEADER_PRESENT             0x0001U
#define DS_METAHEADER_ABSENT              0x0002U
#define DS_LITTLE_ENDIAN                  0x0004U
#define DS_BIG_ENDIAN                     0x0008U
#define DS_IMPLICIT_VR                    0x0010U
#define DS_EXPLICIT_VR                    0x0020U
#define DS_GROUP_LENGTHS                  0x0040U
#define DS_LENGTH_EXPLICIT                0x0080U
#define DS_EXCLUDE_METAHEADER_GROUP       0x0100U
#define DS_LOAD_CLOSE                     0x0200U
#define DS_KEEP_PIXEL_DATA_INTACT         0x0400U
#define DS_LOAD_STORE_OFFSETS             0x0800U
#define DS_ADD_MANDATORY_ELEMENTS_ONLY    0x1000U
#define DS_ADD_MANDATORY_MODULES_ONLY     0x2000U
#define DS_TEMPORARY                      0x4000U     // Internal Use

enum
{
   IMAGE_COMPRESSION_NONE,
   IMAGE_COMPRESSION_RLE,
   IMAGE_COMPRESSION_JPEG_LOSSLESS,
   IMAGE_COMPRESSION_JPEG_LOSSY,
   IMAGE_COMPRESSION_JPEG_LS_LOSSLESS,
   IMAGE_COMPRESSION_JPEG_LS_LOSSY,
   IMAGE_COMPRESSION_J2K_LOSSLESS,
   IMAGE_COMPRESSION_J2K_LOSSY,
   IMAGE_COMPRESSION_MPEG2,
   IMAGE_COMPRESSION_MPEG2_HD,
   IMAGE_COMPRESSION_H_265, 
   IMAGE_COMPRESSION_UNKNOWN,
   IMAGE_COMPRESSION_JPX_LOSSLESS,
   IMAGE_COMPRESSION_JPX_LOSSY,
};


enum
{
   IMAGE_PHOTOMETRIC_MONOCHROME1,
   IMAGE_PHOTOMETRIC_MONOCHROME2,
   IMAGE_PHOTOMETRIC_PALETTE_COLOR,
   IMAGE_PHOTOMETRIC_RGB,
   IMAGE_PHOTOMETRIC_ARGB,
   IMAGE_PHOTOMETRIC_CMYK,
   IMAGE_PHOTOMETRIC_YBR_FULL_422,
   IMAGE_PHOTOMETRIC_YBR_FULL,
   IMAGE_PHOTOMETRIC_YBR_RCT,
   IMAGE_PHOTOMETRIC_YBR_ICT,
   IMAGE_PHOTOMETRIC_YBR_PARTIAL_420
};



#define DS_PREAMBLE_LENGTH             128
#define DS_PREFIX_LENGTH               4
#define DS_PREFIX                      "DICM"

#define ELEMENT_LENGTH_MAX             0xFFFFFFFFUL
#define ELEMENT_INDEX_MAX              0xFFFFFFFFUL
//typedef struct _DICOMELEMENT DICOMELEMENT, *pDICOMELEMENT;
#if !defined (EXCLUDE_DICOM_FUNCTIONS)
typedef struct _DICOMELEMENT
{
   GENERICLINK           // Reserved - internally used only

   L_UINT32    nTag;      // Data Element Tag
   L_UINT16    nVR;       // Value Representation
   L_UINT32    nLength;
   
   L_UINT32    nVM;           // Reserved - internally used only
   L_UCHAR     *pValue;       // Reserved - internally used only

   L_DICOM_OFFSET nAttach;    // Reserved - internally used only
   L_DICOM_OFFSET *pOffset;   // Reserved - internally used only
   L_VOID      **pFile;       // Reserved - internally used only
   L_UINT32    *pSize;        // Reserved - internally used only
   L_UINT32    nCount;        // Reserved - internally used only
   L_TCHAR     *pStringValue; // Reserved - internally used only

   L_DICOM_OFFSET nElementOffset;       // Offset (in bytes) of the element (relative to beginning of file)
   L_DICOM_OFFSET nElementValueOffset;  // Offset (in bytes) of the element value (relative to beginning of file)
   L_UINT32    nElementValueLength;     // Length (in bytes) of the element value in bytes.  Note that this element is a sequence, the length includes all the items in the sequence.
} DICOMELEMENT, *pDICOMELEMENT;

typedef struct _DICOMELEMENTOFFSET
{
   GENERICLINK    // Reserved - internally used only
   pDICOMELEMENT  pElement;
   L_DICOM_OFFSET nOffset;   // Reserved - internally used only
} DICOMELEMENTOFFSET, *pDICOMELEMENTOFFSET;


//typedef struct _DICOMMODULE DICOMMODULE, *pDICOMMODULE;
typedef struct _DICOMMODULE
{
   L_UINT32      nModule;         // Module code
   L_UINT32      nCount;          // Number of elements
   pDICOMELEMENT pElement[1000];  // Pointers to elements
} DICOMMODULE, *pDICOMMODULE;

#define VALUE_AGE_DAYS   'D'
#define VALUE_AGE_WEEKS  'W'
#define VALUE_AGE_MONTHS 'M'
#define VALUE_AGE_YEARS  'Y'

typedef struct _VALUEAGE
{
   L_UINT16    nNumber;       // A value
   L_UCHAR     nReference;    // Reference of age (VALUE_AGE_DAYS, VALUE_AGE_WEEKS, ...)
} VALUEAGE, *  pVALUEAGE;

typedef struct _VALUEDATE
{
   L_UINT16 nYear;         // Year
   L_UINT16 nMonth;        // Month
   L_UINT16 nDay;          // Day
} VALUEDATE, *pVALUEDATE;

#define VALUE_RANGE_NONE   0 //only Date1 is valid, represents single date, not a range
#define VALUE_RANGE_LOWER  1 //only Date1 is valid, represents lower range, "1/1/01-"
#define VALUE_RANGE_UPPER  2 //only Date1 is valid, represents upper range, "-9/9/01"
#define VALUE_RANGE_BOTH   3 //Date1 & Date2 valid, represents full range,  "1/1/01-9/9/01"


typedef struct _VALUETIME
{
   L_UINT16 nHours;        // Hours
   L_UINT16 nMinutes;      // Minutes
   L_UINT16 nSeconds;      // Seconds
   L_UINT32 nFractions;    // Fractional Second
} VALUETIME, *pVALUETIME;

typedef struct _VALUEDATETIME
{
   L_UINT16 nYear;         // Year
   L_UINT16 nMonth;        // Month
   L_UINT16 nDay;          // Day
   L_UINT16 nHours;        // Hours
   L_UINT16 nMinutes;      // Minutes
   L_UINT16 nSeconds;      // Seconds
   L_UINT32 nFractions;    // Fractional Second
   L_INT32  nOffset;       // Optional suffix for plus/minus offset from Coordinated Universal Time
} VALUEDATETIME, *pVALUEDATETIME;

typedef struct _VALUEDATERANGE
{
   L_UINT32 nFlags;        // Flags
   VALUEDATE Date1;        // Date1
   VALUEDATE Date2;        // Date2
} VALUEDATERANGE, *pVALUEDATERANGE;

typedef struct _VALUETIMERANGE
{
   L_UINT32 nFlags;        // Flags
   VALUETIME Time1;        // Time1
   VALUETIME Time2;        // Time2
} VALUETIMERANGE, *pVALUETIMERANGE;

typedef struct _VALUEDATETIMERANGE
{
   L_UINT32 nFlags;         // Flags
   VALUEDATETIME DateTime1; // DateTime1
   VALUEDATETIME DateTime2; // DateTime2
} VALUEDATETIMERANGE, *pVALUEDATETIMERANGE;

typedef struct _DICOMIMAGE
{
   L_INT32  nCompression;
   L_TCHAR  szPhotometric[30];
   L_INT32  nPhotometric;
   L_UINT32 nSamplesPerPixel;
   L_INT32  nRows;
   L_INT32  nColumns;
   L_UINT32 nBitsAllocated;
   L_UINT32 nBitsStored;
   L_UINT32 nHighBit;
   L_INT32  nPixelRepresentation;
   L_INT32  nPlanarConfiguration;
   L_INT32  nResolutionX;
   L_INT32  nResolutionY;
   L_INT32  nSmallestImagePixelValue;
   L_BOOL   bSmallestImagePixelValue;
   L_INT32  nLargestImagePixelValue;
   L_BOOL   bLargestImagePixelValue;
   L_UINT32 nRedEntries;
   L_UINT32 nRedFirst;
   L_UINT32 nRedBits;
   L_UINT32 nGreenEntries;
   L_UINT32 nGreenFirst;
   L_UINT32 nGreenBits;
   L_UINT32 nBlueEntries;
   L_UINT32 nBlueFirst;
   L_UINT32 nBlueBits;
   L_UINT32 nPaletteEntries;
   L_UINT32 nPaletteFirst;
   L_INT32  nBitsPerPixel;
   L_BOOL   bGray;
   L_UINT32 nFrames;
} DICOMIMAGE, *pDICOMIMAGE;

typedef struct _IMAGEINFO IMAGEINFO, *pIMAGEINFO;

typedef struct _DICOMNETDEBUGINFOONSEND
{
   L_INT       nSize ;// The size of this structure
   L_INT       nError;// error code
   L_UCHAR     nType ;// type of message/data sent
   L_UINT32    nBytes;// number of bytes of data sent
   L_UCHAR     *pSentData;//Data itself
}DICOMNETDEBUGINFOONSEND, *pDICOMNETDEBUGINFOONSEND;

// An Item in a Code Sequence Attribute
typedef struct tagDICOMCODESEQUENCEITEM
{
   L_UINT uStructSize;
   
   // Basic Coded Entry Attributes
   L_TCHAR*       pszCodeValue;
   L_TCHAR*       pszCodingSchemeDesignator;
   L_TCHAR*       pszCodingSchemeVersion;
   L_TCHAR*       pszCodeMeaning;
   
   // Enhanced Encoding Mode Attributes
   L_TCHAR*       pszContextIdentifier;
   L_TCHAR*       pszMappingResource;
   pVALUEDATETIME pContextGroupVersion;
   pVALUEDATETIME pContextGroupLocalVersion;
   L_TCHAR*       pszContextGroupExtensionCreatorUID;

} DICOMCODESEQUENCEITEM, * pDICOMCODESEQUENCEITEM;

//---------------------------------------------------------------------------
// Encapsulated Document types
//---------------------------------------------------------------------------
enum 
{
   ENCAPSULATED_DOCUMENT_UNKNOWN = 0,
   ENCAPSULATED_DOCUMENT_PDF     = 1,
   ENCAPSULATED_DOCUMENT_CDA     = 2,
};

typedef struct _DICOMENCAPSULATEDDOCUMENT
{
   L_UINT                     uStructSize;
   L_UINT16                   uType;                                 // ENCAPSULATED_DOCUMENT_PDF or ENCAPSULATED_DOCUMENT_CDA
   L_INT32                    nInstanceNumber;                      // (0020,0013)    Type1    VR_IS    1  IntegerString
   pVALUEDATE                 pContentDate;                          // (0008,0023)    Type2    VR_DA    1  Date
   pVALUETIME                 pContentTime;                          // (0008,0033)    Type2    VR_TM    1  Time
   pVALUEDATETIME             pAcquisitionDateTime;                  // (0008,002A)    Type2    VR_DT    1  DateTime
   L_TCHAR                   *pszBurnedInAnnotation;                 // (0028,0301)    Type1    VR_CS    1 CodeString   "YES" or "NO"
   L_TCHAR                   *pszDocumentTitle;                      // (0042,0010)    Type2    VR_ST    1 ShortText
   L_TCHAR                   *pszVerificationFlag;                   // (0040,A493)    Type3  VR_CS    1 CodeStrin "UNVERIFIED" or "VERIFIED"
   L_TCHAR                   *pszHL7InstanceIdentifier;              // (0040,E001)    Type1C   VR_ST   1 ShortText
   L_TCHAR                   *pszMIMETypeOfEncapsulatedDocument;     // (0042,0012)    Type1    VR_LO   1 LongString
   L_TCHAR                   *pszListOfMIMETypes;                    // (0042,0014)    Type1C   VR_LO   1.FFFFF  LongString
   L_UINT32                   nListOfMIMETypesCount;                 // Number of NULL terminated strings in 'pszListOfMIMETypes'
} DICOMENCAPSULATEDDOCUMENT, *pDICOMENCAPSULATEDDOCUMENT;

typedef struct tagDICOMSOCKETOPTIONS
{
   L_UINT uStructSize;
   L_INT  nSendBufferSize;
   L_INT  nReceiveBufferSize;
   L_BOOL bNoDelay;
   L_UINT uReserved1;
   L_UINT uReserved2;
} DICOMSOCKETOPTIONS, *pDICOMSOCKETOPTIONS;

// Data Commands
#define COMMAND_C_STORE           0x0001
#define COMMAND_C_FIND            0x0020
#define COMMAND_C_GET             0x0010
#define COMMAND_C_MOVE            0x0021
#define COMMAND_C_CANCEL          0x0FFF
#define COMMAND_C_ECHO            0x0030
#define COMMAND_N_REPORT          0x0100
#define COMMAND_N_GET             0x0110
#define COMMAND_N_SET             0x0120
#define COMMAND_N_ACTION          0x0130
#define COMMAND_N_CREATE          0x0140
#define COMMAND_N_DELETE          0x0150

#define COMMAND_REQUEST           0x0000
#define COMMAND_RESPONSE          0x8000

// Values for the element TAG_DATA_SET_TYPE
#define COMMAND_DATASET_PRESENT    0x0000
#define COMMAND_DATASET_IDENTIFIER 0x0102
#define COMMAND_DATASET_ABSENT     0x0101

// Values for the element TAG_STATUS
#define COMMAND_STATUS_SUCCESS                           0x0000   // Success
#define COMMAND_STATUS_CANCEL                            0xFE00   // Cancel
#define COMMAND_STATUS_NO_SUCH_ATTRIBUTE                 0x0105   // No such attribute

#define COMMAND_STATUS_INVALID_ATTRIBUTE_VALUE           0x0106   // Invalid attribute value

#define COMMAND_STATUS_ATTRIBUTE_LIST_ERROR              0x0107   // Attribute list error
#define COMMAND_STATUS_PROCESSING_FAILURE                0x0110   // Processing failure
#define COMMAND_STATUS_DUPLICATE_INSTANCE                0x0111   // Duplicate instance
#define COMMAND_STATUS_NO_SUCH_OBJECT_INSTANCE           0x0112   // No such object instance
#define COMMAND_STATUS_NO_SUCH_EVENT_TYPE                0x0113   // No such event type
#define COMMAND_STATUS_NO_SUCH_ARGUMENT                  0x0114   // No such argument
#define COMMAND_STATUS_INVALID_ARGUMENT_VALUE            0x0115   // Invalid argument value

#define COMMAND_STATUS_ATTRIBUTE_OUT_OF_RANGE            0x0116   // Attribute Value Out of Range
#define COMMAND_STATUS_INVALID_OBJECT_INSTANCE           0x0117   // Invalid object instance
#define COMMAND_STATUS_NO_SUCH_CLASS                     0x0118   // No such class

#if defined(LEADTOOLS_V21_OR_LATER)
#define COMMAND_STATUS_CLASS_INSTANCE_CONFLICT           0x0119   // Class-instance conflict
#else
#define COMMAND_STATUS_CLASE_INSTANCE_CONFLICT           0x0119   // Class-instance conflict
#endif
#define COMMAND_STATUS_MISSING_ATTRIBUTE                 0x0120   // Missing attribute
#define COMMAND_STATUS_MISSING_ATTRIBUTE_VALUE           0x0121   // Missing attribute value
#define COMMAND_STATUS_CLASS_NOT_SUPPORTED               0x0122   // Class not supported
#define COMMAND_STATUS_NO_SUCH_ACTION_TYPE               0x0123   // No such Action Type
#define COMMAND_STATUS_REFUSED_NOT_AUTHORIZED            0x0124   // Refused: Not authorized

#define COMMAND_STATUS_DUPLICATE_TRANSACTION_UID         0x0131   // Duplicate transaction UID The Transaction UID of the Storage Commitment Request is already in use

#define COMMAND_STATUS_DUPLICATE_INVOCATION              0x0210   // Duplicate invocation
#define COMMAND_STATUS_UNRECOGNIZED_OPERATION            0x0211   // Unrecognized operation
#define COMMAND_STATUS_MISTYPED_ARGUMENT                 0x0212   // Mistyped argument
#define COMMAND_STATUS_RESOURCE_LIMITATION               0x0213   // Resource limitation

#define COMMAND_STATUS_REFUSED_OUT_OF_RESOURCES          0xA700   // Out of Resources
#define COMMAND_STATUS_REFUSED_UNABLE_CALCULATE_MATCHES  0xA701   // Out of Resources - unable to calculate number of matches
#define COMMAND_STATUS_REFUSED_UNABLE_PERFORM_SUB_OPS    0xA702   // Out of Resources - Unable to perform sub-operations
#define COMMAND_STATUS_REFUSED_MOVE_DESTINATION_UNKNOWN  0xA801   // Move Destination Unknown
#define COMMAND_STATUS_FAILURE                           0xC001   // Failure
#define COMMAND_STATUS_RESERVED2                         0xC002   // Reserved for future use
#define COMMAND_STATUS_RESERVED3                         0xC003   // Reserved for future use
#define COMMAND_STATUS_RESERVED4                         0xC004   // Reserved for future use
#define COMMAND_STATUS_WARNING                           0xB000   // Sub-operations Complete - One or more failures
#define COMMAND_STATUS_PENDING                           0xFF00   // Matches are continuing - Current Match is supplied and any Optional Keys were supported in the same manner as Required Keys.
#define COMMAND_STATUS_PENDING_WARNING                   0xFF01   // Matches are continuing - Warning that one or more Optional Keys were not supported for existence and/or matching for this Identifier.

// Values for the element TAG_PRIORITY
#define COMMAND_PRIORITY_LOW            0x0002
#define COMMAND_PRIORITY_MEDIUM         0x0000
#define COMMAND_PRIORITY_HIGH           0x0001


// Values for CONFORMANCECALLBACK
#define CALLBACK_ERROR_UNKNOWN_CLASS    0x0001
#define CALLBACK_ERROR_UNKNOWN_TAG      0x0002
#define CALLBACK_ERROR_UNKNOWN_VR       0x0004
#define CALLBACK_ERROR_WRONG_VR         0x0008
#define CALLBACK_ERROR_MIN_VM           0x0010
#define CALLBACK_ERROR_MAX_VM           0x0020
#define CALLBACK_ERROR_DIVIDE_VM        0x0040
#define CALLBACK_ERROR_IMAGE            0x0080
#define CALLBACK_ERROR_ELEMENT          0x0100
#define CALLBACK_ERROR_ELEMENT_EXISTS   0x0200
#define CALLBACK_ERROR_MEMORY           0x0400


#if !defined(HANNOBJECT_DEFINED)
   #define HANNOBJECT_DEFINED
   typedef HANDLE HANNOBJECT;
   typedef HANNOBJECT* pHANNOBJECT;
#endif // #if !defined(pHANNOBJECT)

typedef L_BOOL (pEXT_CALLBACK CONFORMANCECALLBACK) (pDICOMELEMENT pElement, L_UINT16 nFlags, L_VOID *pUserData);
typedef L_BOOL (pEXT_CALLBACK GETIMAGECALLBACK) (L_UINT32 nIndex, L_UINT32 nCount, L_VOID *pUserData);
typedef L_BOOL (pEXT_CALLBACK COPYDSCALLBACK) (pDICOMELEMENT pElement, L_UINT16 nFlags, L_VOID *pUserData);

typedef L_VOID *HDICOMDS;
typedef L_VOID *HDICOMWAVEFORMGROUP;
typedef L_VOID *HDICOMWAVEFORMCHANNEL;
typedef L_VOID *HDICOMDIR;

#if !defined(FOR_UWP)
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSAVEMEMORY )(HANNOBJECT hObject,
                                    L_UINT uFormat,
                                    L_BOOL fSelected,
                                    HGLOBAL *phMem,
                                    L_SIZE_T *puMemSize,
                                    pSAVEFILEOPTION pSaveOptions);

typedef L_INT ( pWRPEXT_CALLBACK pL_ANNLOADMEMORY )(L_UCHAR *pMem,
                                    L_SIZE_T uMemSize,
                                    pHANNOBJECT phObject,
                                    pLOADFILEOPTION pLoadOptions);

typedef L_INT ( pWRPEXT_CALLBACK pL_ANNDELETEPAGEMEMORY )(HGLOBAL hMem, L_SIZE_T *puMemSize, L_INT32 nPage);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETPOINTS )(HANNOBJECT hObject,
                                   pANNPOINT pPoints);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETPOINTCOUNT )(HANNOBJECT hObject,
                                       L_UINT *puCount);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETFILLMODE )(HANNOBJECT hObject,
                                     L_UINT *puFillMode,
                                     L_INT *pnAlpha);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETTEXTLEN )(HANNOBJECT hObject,
                                    L_SIZE_T *puLen);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETTEXT )(HANNOBJECT hObject,
                                 L_TCHAR *pText,
                                 L_SIZE_T *puLen);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETTEXTA )(HANNOBJECT hObject,
                                 L_CHAR *pText,
                                 L_SIZE_T *puLen);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETRECT )(HANNOBJECT hObject, 
                                 pANNRECT pRect, 
                                 pANNRECT pRectName);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNGETTYPE )(HANNOBJECT hObject,
                                 L_UINT *puObjectType);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNCREATE )(L_UINT uObjectType,
                                pHANNOBJECT phObject);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSETPOINTS )(HANNOBJECT hObject,
                                   pANNPOINT pPoints,
                                   L_UINT uCount);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNDEFINE )(HANNOBJECT hObject,
                                LPPOINT pPoint,
                                L_UINT uState);

typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSETRECT )(HANNOBJECT hObject,
                                 pANNRECT pRect);

typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSETFILLMODE )(HANNOBJECT hObject,
                                     L_UINT uFillMode,
                                     L_INT nAlpha,
                                     L_UINT uFlags);

typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSETTEXT )(HANNOBJECT hObject,
                                 L_TCHAR *pText,
                                 L_UINT uFlags);
typedef L_INT ( pWRPEXT_CALLBACK pL_ANNSETTEXTA )(HANNOBJECT hObject,
                                 L_CHAR *pText,
                                 L_UINT uFlags);

typedef  L_INT (pWRPEXT_CALLBACK pL_ANNSETTEXTALIGN)(HANNOBJECT hObject, 
                                 L_UINT uTextAlign, 
                                 L_UINT uFlags);
#endif // #if !defined(FOR_UWP)

typedef L_INT(pEXT_FUNCTION pDicomL_SaveFile)(L_TCHAR* pszFile,
   pBITMAPHANDLE pBitmap,
   L_INT nFormat,
   L_INT nBitsPerPixel,
   L_INT nQFactor,
   L_UINT uFlags,
   FILESAVECALLBACK pfnCallback,
   L_VOID* pUserData,
   pSAVEFILEOPTION pSaveOptions);

typedef L_INT (pEXT_FUNCTION pDicomL_ApplyModalityLUT)(pBITMAPHANDLE pBitmap,L_UINT16* pLUT,pDICOMLUTDESCRIPTOR pLUTDescriptor,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_ApplyLinearModalityLUT)(pBITMAPHANDLE pBitmap,L_DOUBLE fIntercept,L_DOUBLE fSlope,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_ApplyVOILUT)(pBITMAPHANDLE pBitmap,L_UINT16* pLUT,pDICOMLUTDESCRIPTOR  pLUTDescriptor,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_ApplyLinearVOILUT)(pBITMAPHANDLE  pBitmap,L_DOUBLE fCenter,L_DOUBLE fWidth,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_GetLinearVOILUT)(pBITMAPHANDLE pBitmap,L_DOUBLE *pCenter,L_DOUBLE *pWidth,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_CountLUTColors)(RGBQUAD* pLUT,L_UINT32 ulLLUTLen,L_UINT *pNumberOfEntries,L_INT *pFirstIndex,L_UINT uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_CountLUTColorsExt)(L_RGBQUAD16* pLUT,L_UINT32 ulLLUTLen,L_UINT *pNumberOfEntries,L_INT *pFirstIndex,L_UINT uFlags);

typedef L_INT (pEXT_FUNCTION pDicomL_GetMinMaxVal)(pBITMAPHANDLE pBitmap,L_INT* pMinVal,L_INT* pMaxVal,L_UINT32 uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_ShiftBitmapData)(pBITMAPHANDLE pDstBitmap, pBITMAPHANDLE pSrcBitmap, L_UINT uSrcLowBit, L_UINT uSrcHighBit, L_UINT uDstLowBit, L_UINT uDstBitsPerPixel, L_UINT32 uFlags);

typedef L_INT (pEXT_FUNCTION pDicomL_StartGetMinMaxVal)(L_VOID** ppHandle, pBITMAPHANDLE pBitmap, L_UINT32 uFlags);
typedef L_INT (pEXT_FUNCTION pDicomL_ProcessGetMinMaxVal)(L_VOID *pHandle, L_UCHAR *pScan, L_UINT *pScanData, L_UINT uScanDataCount);
typedef L_INT (pEXT_FUNCTION pDicomL_StopGetMinMaxVal)(L_VOID *pHandle, L_INT*pMinVal, L_INT*pMaxVal);

typedef enum tagDICOM_TRANSFER_SYNTAXES
{
   TRANSFER_SYNTAX_IMPLICIT_VR_LITTLE_ENDIAN ,//1.2.840.10008.1.2
   TRANSFER_SYNTAX_EXPLICIT_VR_LITTLE_ENDIAN ,//1.2.840.10008.1.2.1
   TRANSFER_SYNTAX_EXPLICIT_VR_BIG_ENDIAN    ,//1.2.840.10008.1.2.2
   TRANSFER_SYNTAX_RLE_LOSSLESS              ,//1.2.840.10008.1.2.5
   TRANSFER_SYNTAX_JPEG_BASELINE_1           ,//1.2.840.10008.1.2.4.50
   TRANSFER_SYNTAX_JPEG_EXTENDED_2_4         ,//1.2.840.10008.1.2.4.51
   TRANSFER_SYNTAX_JPEG_LOSSLESS_NONHIER_14  ,//1.2.840.10008.1.2.4.57
   TRANSFER_SYNTAX_JPEG_LOSSLESS_NONHIER_14B ,//1.2.840.10008.1.2.4.70
   TRANSFER_SYNTAX_JPEG_LS_LOSSLESS          ,//1.2.840.10008.1.2.4.80
   TRANSFER_SYNTAX_JPEG_LS_LOSSY             ,//1.2.840.10008.1.2.4.81
   TRANSFER_SYNTAX_JPEG2000_LOSSLESS_ONLY    ,//1.2.840.10008.1.2.4.90
   TRANSFER_SYNTAX_JPEG2000                  ,//1.2.840.10008.1.2.4.91
   TRANSFER_SYNTAX_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION_LOSSLESS_ONLY ,//1.2.840.10008.1.2.4.92
   TRANSFER_SYNTAX_JPEG_2000_PART_2_MULTI_COMPONENT_IMAGE_COMPRESSION               ,//1.2.840.10008.1.2.4.93
}
DICOM_TRANSFER_SYNTAXES, *pDICOM_TRANSFER_SYNTAXES;


typedef enum tagDICOMLUTDESCRIPTORTYPE
{
   DICOMLUTDESCRIPTORTYPE_MODALITY        ,
   DICOMLUTDESCRIPTORTYPE_VOI             ,
   DICOMLUTDESCRIPTORTYPE_PALETTECOLOR       
}
DICOMLUTDESCRIPTORTYPE, *pDICOMLUTDESCRIPTORTYPE;


typedef struct tagDICOMMLUTATTRIBS
{
   L_UINT                  uStructSize;
   L_BOOL                  bIsModalityLUTSequence;
   DICOMLUTDESCRIPTOR      LUTDescriptor;
   L_TCHAR                 pszLUTExplanation[DICOM_VR_LO_LENGTH+1];
   L_TCHAR                 szModalityLUTType[DICOM_VR_LO_LENGTH+1];
   L_BOOL                  bIsRescaleSlopeIntercept;
   L_DOUBLE                fRescaleIntercept;
   L_DOUBLE                fRescaleSlope;
   L_TCHAR                 szRescaleType[DICOM_VR_LO_LENGTH+1];   
}DICOMMLUTATTRIBS , * pDICOMMLUTATTRIBS;


/*Palette Color LUT related types*/


typedef struct tagDICOMPALCOLORLUTATTRIBS
{
   L_UINT               uStructSize;
   DICOMLUTDESCRIPTOR   RedLUTDescriptor;
   DICOMLUTDESCRIPTOR   GreenLUTDescriptor;
   DICOMLUTDESCRIPTOR   BlueLUTDescriptor;
   L_TCHAR              szUID[DICOM_VR_UI_LENGTH+1];
   L_BOOL               bIsSegmented;
}DICOMPALCOLORLUTATTRIBS , * pDICOMPALCOLORLUTATTRIBS;

typedef enum tagDICOMPALETTECOLORLUTTYPE
{
   DICOMPALETTECOLORLUTTYPE_RED    ,
   DICOMPALETTECOLORLUTTYPE_GREEN  ,
   DICOMPALETTECOLORLUTTYPE_BLUE   
} DICOMPALETTECOLORLUTTYPE, *pDICOMPALETTECOLORLUTTYPE;


/*VOI LUT related types*/

typedef struct tagDICOMWINDOWATTRIBS
{
   L_UINT      uStructSize;
   L_DOUBLE    fWindowCenter ; // Window Center
   L_DOUBLE    fWindowWidth  ; // Window Width
   L_TCHAR     pszWindowCWExplanation[DICOM_VR_LO_LENGTH+1];
      
}DICOMWINDOWATTRIBS , * pDICOMWINDOWATTRIBS;


typedef struct tagDICOMVOILUTATTRIBS
{
   L_UINT               uStructSize;
   DICOMLUTDESCRIPTOR   LUTDescriptor;
   L_TCHAR              pszLUTExplanation[DICOM_VR_LO_LENGTH+1];   
}DICOMVOILUTATTRIBS , * pDICOMVOILUTATTRIBS;


// Flags used with SetOverlayAttributes and L_DicomSetOverlayAttributes
#define SET_OVERLAY_ATTRIB_NO_OVERRIDE    0x0001


// Flags for GetImage and GetImageList 
#define DICOM_GETIMAGE_AUTO_LOAD_OVERLAYS                         0x00000001
#define DICOM_GETIMAGE_AUTO_APPLY_MODALITY_LUT                    0x00000002
#define DICOM_GETIMAGE_AUTO_APPLY_VOI_LUT                         0x00000004
#define DICOM_GETIMAGE_ALLOW_RANGE_EXPANSION                      0x00000008 //deprecated, do not use
#define DICOM_GETIMAGE_AUTO_SCALE_MODALITY_LUT                    0x00000010
#define DICOM_GETIMAGE_AUTO_SCALE_VOI_LUT                         0x00000020
#define DICOM_GETIMAGE_AUTODETECT_INVALID_RLE_COMPRESSION         0x00000040  // for RLE compressed, automatically detects if the MSB and LSB segments are written in the incorrect order
#define DICOM_GETIMAGE_RLE_SWAP_SEGMENTS                          0x00000080
#define DICOM_GETIMAGE_LOADCORRUPTED                              0x00000100 //allow loading of corrupt JPEG
#define DICOM_GETIMAGE_VOI_LUT_PAINT_ONLY                         0x00000200
#define DICOM_GETIMAGE_USE_DISK                                   0x00000400
#define DICOM_GETIMAGE_FROM_FLTLOAD                               0x00008000 // Internal Use only
#define DICOM_GETIMAGE_KEEP_COLOR_PALETTE                         0x00010000 // If Photometric Interpretation (0028,0004) is 'PALETTE COLOR' then GetImage() will not convert to RGB
#define DICOM_GETIMAGE_RESERVED1                                  0x00020000 // Internal Use Only

// Flags for SetImage
#define DICOM_SETIMAGE_AUTO_SAVE_OVERLAYS             0x00000001
#define DICOM_SETIMAGE_AUTO_SET_VOI_LUT               0x00000002
#define DICOM_SETIMAGE_MINIMIZE_JPEG_SIZE             0x00000004
#define DICOM_SETIMAGE_KEEP_LUTS_INTACT               0x20000000 // Internal flag

#define DICOM_SETIMAGE_MFG_OVERWRITE_SHARED           0x00000008
#define DICOM_SETIMAGE_MFG_VOI_LUT_PER_FRAME          0x00000010
#define DICOM_SETIMAGE_MFG_VOI_LUT_SHARED             0x00000020
#define DICOM_SETIMAGE_MFG_MODALITY_LUT_PER_FRAME     0x00000040
#define DICOM_SETIMAGE_MFG_MODALITY_LUT_SHARED        0x00000080

#define DICOM_SETIMAGE_YBR_FULL                       0x00000100

#define DICOM_SETIMAGE_OPTIMIZED_MEMORY               0x00000200

//Flags for ChangeTransferSyntax
#define DICOM_CHANGETRAN_MINIMIZE_JPEG_SIZE           0x00000001
#define DICOM_CHANGETRAN_RESCALE_MODALITY_LUT_WHEN_LOSSY_COMPRESSED 0x00000002
#define DICOM_CHANGETRAN_YBR_FULL                     0x00000100

// Flags for LDicomNet
#define DICOMNET_FLAGS_NONE                                              0x00000000
#define DICOMNET_FLAGS_SENDDATA_WITH_GROUP_LENGTH_STANDARD_DATA_ELEMENTS 0x00000001


// DICOM Annotation Types

#define DICANN_TYPE_POINT           1
#define DICANN_TYPE_POLYLINE        2
#define DICANN_TYPE_INTERPOLATED    3
#define DICANN_TYPE_CIRCLE          4
#define DICANN_TYPE_ELLIPSE         5

// Defines for Compound Graphic Sequence
#define DICANN_TYPE_MULTILINE       6
#define DICANN_TYPE_INFINITELINE    7
#define DICANN_TYPE_CUTLINE         8
#define DICANN_TYPE_RANGELINE       9
#define DICANN_TYPE_RULER           10
#define DICANN_TYPE_AXIS            11
#define DICANN_TYPE_CROSSHAIR       12
#define DICANN_TYPE_ARROW           13
#define DICANN_TYPE_RECTANGLE       14
// #define DICANN_TYPE_ELLIPSE

// DICOM Annotation Units Relativity
#define DICANN_UNIT_PIXEL           1
#define DICANN_UNIT_DISPLAY         2

// Text Annotation Justification
#define DICANN_TEXT_LEFT            0    // 'LEFT'
#define DICANN_TEXT_RIGHT           1    // 'RIGHT'
#define DICANN_TEXT_CENTER          2    // 'CENTER'

// Displayed Area Size Mode
#define DICANN_SIZEMODE_SCALETOFIT  0    // 'SCALE TO FIT'
#define DICANN_SIZEMODE_TRUESIZE    1    // 'TRUE SIZE'
#define DICANN_SIZEMODE_MAGNIFY     2    // 'MAGNIFY'

// Defines for Compound Graphic Sequence
// Horizontal Alignment
#define DICANN_HORIZONTAL_ALIGNMENT_NONE      0     // Not Present
#define DICANN_HORIZONTAL_ALIGNMENT_LEFT      1     // 'LEFT'
#define DICANN_HORIZONTAL_ALIGNMENT_CENTER    2     // 'CENTER'
#define DICANN_HORIZONTAL_ALIGNMENT_RIGHT     3     // 'RIGHT'

// Vertical Alignment
#define DICANN_VERTICAL_ALIGNMENT_NONE     0   // Not present
#define DICANN_VERTICAL_ALIGNMENT_TOP      1   // 'TOP'
#define DICANN_VERTICAL_ALIGNMENT_CENTER   2   // 'CENTER'
#define DICANN_VERTICAL_ALIGNMENT_BOTTOM   3   // 'BOTTOM'

// Shadow Style
#define DICANN_SHADOW_STYLE_OFF            0
#define DICANN_SHADOW_STYLE_NORMAL         1
#define DICANN_SHADOW_STYLE_OUTLINED       2

// Dashing Style
#define DICANN_LINE_DASH_STYLE_NONE       0
#define DICANN_LINE_DASH_STYLE_SOLID      1
#define DICANN_LINE_DASH_STYLE_DASHED     2

// Fill Mode
#define DICANN_FILL_MODE_NONE             0
#define DICANN_FILL_MODE_SOLID            1
#define DICANN_FILL_MODE_STIPPELED        2

// Tick Alignment
#define DICANN_TICK_ALIGNMENT_NONE           0   // Not present
#define DICANN_TICK_ALIGNMENT_TOP            1   // 'BOTTOM'
#define DICANN_TICK_ALIGNMENT_CENTER         2   // 'CENTER'
#define DICANN_TICK_ALIGNMENT_BOTTOM         3   // 'TOP'

// Tick Label Alignment
#define DICANN_TICK_LABEL_ALIGNMENT_NONE     0   // Not present
#define DICANN_TICK_LABEL_ALIGNMENT_TOP      1   // 'TOP'
#define DICANN_TICK_LABEL_ALIGNMENT_BOTTOM   3   // 'BOTTOM'


// flags for optional sequences (line, fill, text), and optional elements
#define DICANN_OPTIONS_NONE                            0x000    // 0
#define DICANN_OPTIONS_LINE_STYLE                      0x001    // Line style sequence is present
#define DICANN_OPTIONS_FILL_STYLE                      0x002    // Fill style sequence is present
#define DICANN_OPTIONS_TEXT_STYLE                      0x004    // Text style sequence is present
#define DICANN_OPTIONS_GRAPHIC_GROUP_ID                0x008    // TAG_GRAPHIC_GROUP_ID is present
#define DICANN_OPTIONS_COMPOUND_GRAPHIC_INSTANCE_ID    0x010    // TAG_GRAPHIC_GROUP_ID is present

// flags for optional items in DICOMLINESTYLE
#define DICANN_LINE_OPTIONS_NONE                               0x000
#define DICANN_LINE_OPTIONS_PATTERN_OFF_COLOR_CIELAB_VALUE     0x001
#define DICANN_LINE_OPTIONS_PATTERN_OFF_OPACITY                0x002

// flags for optional items in DICOMFILLSTYLE
#define DICANN_FILL_OPTIONS_NONE                               0x000
#define DICANN_FILL_OPTIONS_PATTERN_OFF_COLOR_CIELAB_VALUE     0x001
#define DICANN_FILL_OPTIONS_PATTERN_OFF_OPACITY                0x002

// flags for otional items in DICOMTEXTSTYLE
#define DICANN_TEXT_OPTIONS_NONE                               0x000
#define DICANN_TEXT_OPTIONS_FONT_NAME                          0x001


// Conversion Types
typedef enum tagLEADANNOBJCONVERSIONTYPE
{
   LEADANNOBJCONVERSIONTYPE_GRAPHIC ,
   LEADANNOBJCONVERSIONTYPE_TEXT    
} LEADANNOBJCONVERSIONTYPE, *pLEADANNOBJCONVERSIONTYPE;

// DICOM Annotation Point
typedef struct tagDICOMANNPOINT
{
   L_FLOAT fX;
   L_FLOAT fY;
} DICOMANNPOINT, *pDICOMANNPOINT;

// Presentation State Module structure
typedef struct tagDICOMPRESSTATEINFO
{
   L_UINT     uStructSize;
   L_INT32    nInstanceNumber;
   L_TCHAR    *pszPresLabel;
   L_TCHAR    *pszPresDescription;
   pVALUEDATE pPresCreationDate;
   pVALUETIME pPresCreationTime;
   L_TCHAR    *pszPresCreator;
} DICOMPRESSTATEINFO, *pDICOMPRESSTATEINFO;


// Graphic Layer Module structure
typedef struct tagDICOMGRAPHICLAYER
{
   L_UINT    uStructSize;
   L_TCHAR   *pszLayerName;
   L_INT32   nLayerOrder;
   L_INT16*  puGrayscale;
   L_INT16*  pRGBLayerColors;
   L_TCHAR   *pszLayerDescription;
} DICOMGRAPHICLAYER, *pDICOMGRAPHICLAYER;


typedef struct tagDICOMSHADOWSTYLE
{
   L_UINT   uStructSize;
   L_UINT   uShadowStyle;                 // M  TAG_SHADOW_STYLE                 CS
   L_FLOAT  fShadowOffsetX;               // M  TAG_SHADOW_OFFSET_X              FL
   L_FLOAT  fShadowOffsetY;               // M  TAG_SHADOW_OFFSET_Y              FL
   L_UINT16 uShadowColorCieLabValue[3];   // M  TAG_SHADOW_COLOR_CIELAB_VALUE    US - Unsigned Short -- mult(3)
   L_FLOAT  fShadowOpacity;               // M  TAG_SHADOW_OPACITY               FL
}DICOMSHADOWSTYLE, *pDICOMSHADOWSTYLE;

// #define CS_MAX_LEN (16 + 1)
#define LO_MAX_LEN (64 + 1) 
#define SH_MAX_LEN (16 + 1)

typedef struct tagDICOMTEXTSTYLE
{
   L_UINT            uStructSize;
   L_UINT            uTextOptions;                 //    
   L_TCHAR           szFontName[LO_MAX_LEN];       // O  TAG_FONT_NAME                    LO - Long String
   // L_TCHAR       *pszFontNameType;              // C  ISO_32000 required if FontName is present
   L_TCHAR           szCssFontName[LO_MAX_LEN];    // M  TAG_CSS_FONT_NAME                LO - Long String
   L_UINT16          uTextColorCieLabValue[3];     // M  TAG_TEXT_COLOR_CIELAB_VALUE      US - Unsigned Short -- mult(3)
   L_UINT            uHorizontalAlign;             // O  TAG_HORIZONTAL_ALIGNMENT         CS
   L_UINT            uVerticalAlign;               // O  TAG_VERTICAL_ALIGNMENT           CS
   DICOMSHADOWSTYLE  shadowStyle;                  // M  TAG_SHADOW_STYLE                 CS
   L_BOOL            bUnderlined;                  // M  TAG_UNDERLINED                   CS
   L_BOOL            bBold;                        // M  TAG_BOLD                         CS
   L_BOOL            bItalic;                      // M  TAG_ITALIC                       CS
} DICOMTEXTSTYLE, *pDICOMTEXTSTYLE;

typedef struct tagDICOMLINESTYLE
{
   L_UINT   uStructSize;
   L_UINT   uLineOptions;                       //    
   L_UINT16 uPatternOnColorCieLabValue[3];      // M  TAG_PATTERN_ON_COLOR_CIELAB_VALUE      US - Unsigned Short -- mult(3)
   L_UINT16 uPatternOffColorCieLabValue[3];     // O  TAG_PATTERN_OFF_COLOR_CIELAB_VALUE     US - Unsigned Short -- mult(3)
   L_FLOAT  fPatternOnOpacity;                  // M  TAG_PATTERN_ON_OPACITY                 FL
   L_FLOAT  fPatternOffOpacity;                 // O  TAG_PATTERN_OFF_OPACITY                FL
   L_FLOAT  fLineThickness;                     // M  TAG_LINE_THICKNESS                     FL
   L_UINT   uLineDashingStyle;                  // M  TAG_LINE_DASHING_STYLE                 CS    DICANN_LINE_DASH_STYLE_DASHED, DICANN_LINE_DASH_STYLE_SOLID
   L_UINT   uLinePattern;                       // C  TAG_LINE_PATTERN                       UL    Required if uLineDashingStyle is DICANN_LINE_DASH_STYLE_DASHED
   DICOMSHADOWSTYLE shadowStyle;                // M  TAG_SHADOW_STYLE
}  DICOMLINESTYLE, *pDICOMLINESTYLE;

typedef struct tagDICOMFILLSTYLE
{
   L_UINT   uStructSize;
   L_UINT   uFillOptions;                       //    
   L_UINT16 uPatternOnColorCieLabValue[3];      // M  TAG_PATTERN_ON_COLOR_CIELAB_VALUE      US - Unsigned Short -- mult(3)
   L_UINT16 uPatternOffColorCieLabValue[3];     // O  TAG_PATTERN_OFF_COLOR_CIELAB_VALUE     US - Unsigned Short -- mult(3)
   L_FLOAT  fPatternOnOpacity;                  // M  TAG_PATTERN_ON_OPACITY                 FL
   L_FLOAT  fPatternOffOpacity;                 // M  TAG_PATTERN_OFF_OPACITY                FL
   L_UINT   uFillMode;                          // M  TAG_FILL_MODE                          CS      DICANN_FILL_MODE_STIPPELED, DICANN_FILL_MODE_SOLID
   L_UCHAR  uFillPattern[128];                  // C  TAG_FILL_PATTERN                       OB   128 byte value    -- required if uFillMode is DICANN_FILL_MODE_STIPPELED
}  DICOMFILLSTYLE, *pDICOMFILLSTYLE;

// Graphic Annotation Object structure
typedef struct tagDICOMGRAPHICOBJECT
{
   L_UINT   uStructSize;
   L_TCHAR* pszLayerName;
   L_UINT   uType;
   L_UINT   uUnits;
   L_BOOL   bFilled;
   L_INT16  nPointCount;
   pDICOMANNPOINT  pAnnPoints;

   // *** New Fields for 2011
   L_VOID           *pReserved;                       // reserved for internal use -- pass 0
   L_UINT            uCompoundGraphicInstanceId;   // O TAG_COMPOUND_GRAPHIC_INSTANCE_ID
   L_UINT            uOptions;                     // DICANN_OPTIONS_NONE, DICANN_OPTIONS_LINE_STYLE, DICANN_OPTIONS_FILL_STYLE
   pDICOMLINESTYLE   pLineStyle;                   // TAG_LINE_STYLE_SEQUENCE
   pDICOMFILLSTYLE   pFillStyle;                   // TAG_FILL_STYLE_SEQUENCE
   L_UINT            uGraphicGroupId;              // TAG_GRAPHIC_GROUP_ID
} DICOMGRAPHICOBJECT, *pDICOMGRAPHICOBJECT;

typedef struct tagDICOMMAJORTICK
{
   L_UINT            uStructSize;
   L_FLOAT           fTickPosition;             // M  TAG_TICK_POSITION
   L_TCHAR           szTickLabel[SH_MAX_LEN];   // M  TAG_TICK_LABEL
} DICOMMAJORTICK, *pDICOMMAJORTICK;

// Compound Graphic Annotation Object structure
typedef struct tagDICOMCOMPOUNDGRAPHIC
{
   L_UINT                     uStructSize;
   L_VOID                    *pReserved;           // reserved for internal use -- pass 0
   L_TCHAR                   *pszLayerName;
   L_UINT                     uType;               // MULTILINE, INFINITELINE, CUTLINE, RANGELINE, RULER, AXIS, CROSSHAIR, ARROW, RECTANGLE, ELLIPSE
   L_UINT                     uUnits;              // PIXEL or DISPLAY
   L_BOOL                     bFilled;
   L_INT16                    nPointCount;
   pDICOMANNPOINT             pAnnPoints;

   L_UINT                     uCompoundGraphicInstanceId;   // M  TAG_COMPOUND_GRAPHIC_INSTANCE_ID
   L_UINT                     uOptions;                     //    DICANN_OPTIONS_NONE, DICANN_OPTIONS_LINE_STYLE, DICANN_OPTIONS_FILL_STYLE, DICANN_OPTIONS_TEXT_STYLE
   pDICOMLINESTYLE            pLineStyle;                   // O  TAG_LINE_STYLE_SEQUENCE
   pDICOMFILLSTYLE            pFillStyle;                   // O  TAG_FILL_STYLE_SEQUENCE
   L_UINT                     uGraphicGroupId;              // O  TAG_GRAPHIC_GROUP_ID

   L_DOUBLE                   dRotationAngle;               // O  TAG_ROTATION_ANGLE      (degrees, 0..360)
   pDICOMTEXTSTYLE            pTextStyle;                   // O  TAG_TEXT_STYLE_SEQUENCE
   L_FLOAT                    fGapLength;                   // C  TAG_GAP_LENGTH
   L_FLOAT                    fDiameterOfVisibility;        // C  TAG_DIAMETER_OF_VISIBILITY
   DICOMANNPOINT              ptRotationPoint;              // C  TAG_ROTATION_POINT
   L_UINT                     uTickAlignment;               // C  TAG_TICK_ALIGNMENT         (DICANN_TICK_ALIGNMENT_BOTTOM, DICANN_TICK_ALIGNMENT_CENTER, DICANN_TICK_ALIGNMENT_TOP)
   L_BOOL                     bShowTickLabel;               // C  TAG_SHOW_TICK_LABEL     
   L_UINT                     uTickLabelAlignment;          // C  TAG_TICK_LABEL_ALIGNMENT   (DICANN_TICK_LABEL_ALIGNMENT_BOTTOM, DICANN_TICK_LABEL_ALIGNMENT_TOP)
   L_INT16                    nMajorTickCount;              //
   pDICOMMAJORTICK            pMajorTicks;                  // C  TAG_MAJOR_TICKS_SEQUENCE
} DICOMCOMPOUNDGRAPHIC, *pDICOMCOMPOUNDGRAPHIC;

// Text Annotation Object structure
typedef struct tagDICOMTEXTOBJECT
{
   L_UINT      uStructSize;
   L_TCHAR*    pszLayerName;
   L_TCHAR*    pszTextValue;
   L_FLOAT*    pTLHCorner;
   L_FLOAT*    pBRHCorner;
   L_UINT      uBoundingBoxUnits;
   L_UINT      uTextJustification; 
   L_FLOAT*    pAnchorPoint;
   L_UINT      uAnchorPointUnits;
   L_BOOL      bAnchorPointVisible;

   // *** New Fields for 2011
   L_VOID           *pReserved;                       // reserved for internal use -- pass 0
   L_UINT            uCompoundGraphicInstanceId;      // TAG_COMPOUND_GRAPHIC_INSTANCE_ID
   L_UINT            uOptions;                        // DICANN_OPTIONS_NONE, DICANN_OPTIONS_TEXT_STYLE
   pDICOMTEXTSTYLE   pTextStyle;                      // TAG_TEXT_STYLE_SEQUENCE
   L_UINT            uGraphicGroupId;                 // TAG_GRAPHIC_GROUP_ID
} DICOMTEXTOBJECT, *pDICOMTEXTOBJECT;

typedef L_UINT16(pEXT_CALLBACK pCONVERTLEADANNOBJTODICOMANNPROC)( const pDICOMGRAPHICOBJECT pGraphicObject,
                                                                  const pDICOMTEXTOBJECT pTextObject,L_VOID *pUserData);


#define _MAX_DICOM_OVERLAYS 16


// MAC Algorithms
#define DICOM_MAC_ALGORITHM_RIPEMD160   0
#define DICOM_MAC_ALGORITHM_SHA1        1
#define DICOM_MAC_ALGORITHM_MD5         2

// Digital Signature Security Profiles
#define DICOM_SECURITY_PROFILE_NONE                0
#define DICOM_SECURITY_PROFILE_BASE_RSA            1
#define DICOM_SECURITY_PROFILE_CREATOR_RSA         2
#define DICOM_SECURITY_PROFILE_AUTHORIZATION_RSA   3

// Formats when saving a digital certificate
#define DICOM_CERTIFICATE_FORMAT_PEM   0
#define DICOM_CERTIFICATE_FORMAT_DER   1

#if defined(__cplusplus)

#if !defined(EXCLUDE_DICOM_NET)
class L_LTDIC_CLASS LDicomNet;
#endif // #if !defined(EXCLUDE_DICOM_NET)
class L_LTDIC_CLASS LDicomWaveformGroup;
class L_LTDIC_CLASS LDicomWaveformChannel;

#if defined(FOR_UNIX)

struct LINKEDLIST
{
   LDicomNet   *pNet;     
   struct LINKEDLIST *pNext;
};

#endif

class L_LTDIC_CLASS LDicomDS
{
public:
   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   LDicomDS(L_TCHAR *pszPath=NULL);
#if defined(LEADTOOLS_V21_OR_LATER) || defined(FOR_UNIX)
   virtual
#endif 
   ~LDicomDS();

   L_VOID          InitDS            (L_UINT32 nClass, L_UINT16 nFlags);
   L_VOID          GetInfoDS         (L_UINT32 *pnClass, L_UINT16 *pnFlags);

   L_VOID          InitCS            (L_UINT16 nCommand, L_BOOL bRequest);
   L_VOID          GetInfoCS         (L_UINT16 *pnCommand, L_BOOL *pbRequest);


   //---------------------------------------------------------------------------
   // Input and Output Functions
   //---------------------------------------------------------------------------
   L_UINT16        LoadDS            (L_TCHAR *pszName, L_UINT16 nFlags);
   L_UINT16        LoadDSMemory      (L_UCHAR *pBuffer, L_UINT32 uBufferSize, L_UINT16 nFlags);
   L_UINT16        SaveDS            (L_TCHAR *pszName, L_UINT16 nFlags);
   L_UINT16        CopyDS            (pDICOMELEMENT pDstParent, LDicomDS *pSrcDS, pDICOMELEMENT pSrcParent);
   L_UINT16        CopyDS            (pDICOMELEMENT pDstParent, LDicomDS *pSrcDS, pDICOMELEMENT pSrcParent, COPYDSCALLBACK pfnCallback, L_VOID *pUserData);


   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   pDICOMELEMENT   InsertElement     (pDICOMELEMENT pNeighbor, L_BOOL bChild, L_UINT32 nTag, L_UINT16 nVR, L_BOOL bSequence, L_UINT32 nIndex);
   pDICOMMODULE    InsertModule      (L_UINT32 nModule, L_BOOL bOptional);
   pDICOMELEMENT   InsertKey         (pDICOMELEMENT pParent, L_TCHAR *pszKey, L_BOOL bOptional);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   pDICOMELEMENT   DeleteElement     (pDICOMELEMENT pElement);
   L_VOID          DeleteModule      (L_UINT32 nModule);
   L_VOID          DeleteKey         (pDICOMELEMENT pElement);
   L_VOID          ResetDS           ();

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   pDICOMELEMENT   GetRootElement    (pDICOMELEMENT pElement);
   pDICOMELEMENT   GetParentElement  (pDICOMELEMENT pElement);
   pDICOMELEMENT   GetChildElement   (pDICOMELEMENT pElement, L_BOOL bVolatile);
   pDICOMELEMENT   GetFirstElement   (pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   pDICOMELEMENT   GetLastElement    (pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   pDICOMELEMENT   GetPrevElement    (pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   pDICOMELEMENT   GetNextElement    (pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   L_UINT32        GetLevelElement   (pDICOMELEMENT pElement);
   L_UINT32        GetCountModule    ();
   L_BOOL          ExistsElement     (pDICOMELEMENT pElement);
   L_BOOL          IsVolatileElement (pDICOMELEMENT pElement);
   L_BOOL          ConformanceDS     (CONFORMANCECALLBACK pfnCallback, L_VOID *pUserData);
   L_VOID          SetDebugDS        (CONFORMANCECALLBACK pfnCallback, L_VOID *pUserData);

   pDICOMELEMENT   GetRootKey        (pDICOMELEMENT pElement);
   pDICOMELEMENT   GetParentKey      (pDICOMELEMENT pElement);
   pDICOMELEMENT   GetChildKey       (pDICOMELEMENT pElement);
   pDICOMELEMENT   GetFirstKey       (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   GetLastKey        (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   GetPrevKey        (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   GetNextKey        (pDICOMELEMENT pElement, L_BOOL bTree);
   L_TCHAR         *GetValueKey       (pDICOMELEMENT pElement);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   pDICOMELEMENT   FindFirstElement  (pDICOMELEMENT pElement, L_UINT32 nTag, L_BOOL bTree);
   pDICOMELEMENT   FindLastElement   (pDICOMELEMENT pElement, L_UINT32 nTag, L_BOOL bTree);
   pDICOMELEMENT   FindPrevElement   (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   FindNextElement   (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   FindFirstDescendant    (pDICOMELEMENT pParent, L_UINT32 nTag, L_BOOL bNextLevelOnly);
   pDICOMELEMENT   FindNextDescendant     (pDICOMELEMENT pParent, pDICOMELEMENT pElement, L_BOOL bNextLevelOnly);
   pDICOMMODULE    FindModule        (L_UINT32 nModule);
   pDICOMMODULE    FindIndexModule   (L_UINT32 nIndex);

   pDICOMELEMENT   FindFirstKey      (pDICOMELEMENT pElement, L_TCHAR *pszKey, L_BOOL bTree);
   pDICOMELEMENT   FindLastKey       (pDICOMELEMENT pElement, L_TCHAR *pszKey, L_BOOL bTree);
   pDICOMELEMENT   FindPrevKey       (pDICOMELEMENT pElement, L_BOOL bTree);
   pDICOMELEMENT   FindNextKey       (pDICOMELEMENT pElement, L_BOOL bTree);

   //---------------------------------------------------------------------------
   // Retrieval Functions
   //---------------------------------------------------------------------------
   L_VOID          GetPreamble       (L_UCHAR *pPreamble, L_UINT16 nLength);
   L_UINT32        GetCountValue     (pDICOMELEMENT pElement);
   L_VOID          FreeValue         (pDICOMELEMENT pElement);
   L_BOOL          GetBinaryValue    (pDICOMELEMENT pElement, L_VOID *pValue,  L_UINT32 nLength);
   L_UCHAR         *GetCharValue     (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_INT16        *GetShortValue     (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_INT32        *GetLongValue      (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);   
   L_UINT32        GetLong64Value    (pDICOMELEMENT pElement, L_INT64 *pValue, L_UINT32 nIndex, L_UINT32 nCount);
   L_INT64        *GetLong64Value    (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_FLOAT        *GetFloatValue     (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_DOUBLE       *GetDoubleValue    (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_CHAR         *GetStringValueA   (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_TCHAR        *GetStringValue    (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);

   // L_TCHAR         *GetTheName();

#if defined(_UNICODE)
private:
   L_UINT32        ConvertStringValue(L_CHAR *Source, L_UINT32 SrcSizeInBytes, L_TCHAR *Destination, L_UINT32 DestSizeInWords);
#endif // #if defined(_UNICODE)

public:
   pVALUEAGE       GetAgeValue       (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   pVALUEDATE      GetDateValue      (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);

   L_INT           GetDateRangeValue (pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUEDATERANGE pValue);
   L_INT16         GetTimeRangeValue (pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUETIMERANGE pValue);
   L_INT16         GetDateTimeRangeValue (pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUEDATETIMERANGE pValue);


   pVALUETIME      GetTimeValue      (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   pVALUEDATETIME  GetDateTimeValue  (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_UINT32        GetConvertValue   (pDICOMELEMENT pElement, L_TCHAR *Destination, L_UINT32 DestSizeInWords);

   L_UINT32        GetCountImage     (pDICOMELEMENT pElement);
   L_UINT16        GetInfoImage      (pDICOMELEMENT pElement, pDICOMIMAGE pInfo, L_UINT32 nIndex);
   L_UINT16        GetImage          (pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap,L_UINT uStructSize ,L_UINT32 nIndex, L_INT32 nBitsPerPixel, /*L_INT32 nOrder,*/ L_UINT uFlags ,FILEREADCALLBACK pfnCallback, L_VOID *pUserData);
   L_UINT16        GetImageList      (pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_UINT32 nCount, L_INT32 nBitsPerPixel, /*L_INT32 nOrder,*/ L_UINT uFlags );
   L_UINT16        GetImageList      (pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_UINT32 nCount, L_INT32 nBitsPerPixel, /*L_INT32 nOrder,*/ L_UINT uFlags, GETIMAGECALLBACK pfnCallback, L_VOID *pUserData );

   L_BOOL          GetKeepPixelDataIntactFlag();

   L_UINT16        GetJ2KOptions( pFILEJ2KOPTIONS pOptions, L_INT nSize );
   L_UINT16        GetDefaultJ2KOptions( pFILEJ2KOPTIONS pOptions, L_INT nSize );

   L_DICOM_OFFSET  GetElementOffset(pDICOMELEMENT pElement);

   //---------------------------------------------------------------------------
   // Waveform Functions
   //---------------------------------------------------------------------------
   L_UINT32 GetWaveformGroupCount();
   L_UINT16 GetWaveformGroup(L_UINT32 uIndex, LDicomWaveformGroup* pWaveformGroup);
   L_UINT16 DeleteWaveformGroup(L_UINT32 uIndex, L_UINT16 uReserved);
   L_UINT16 AddWaveformGroup(LDicomWaveformGroup* pWaveformGroup, L_UINT16 uFlags, L_UINT32 uIndex = ELEMENT_INDEX_MAX);
   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   L_VOID          SetPreamble       (L_UCHAR *pPreamble, L_UINT16 nLength);
   L_BOOL          SetBinaryValue    (pDICOMELEMENT pElement, L_VOID *pValue, L_UINT32 nLength);
   L_BOOL          SetCharValue      (pDICOMELEMENT pElement, L_UCHAR *pValue, L_UINT32 nCount);
   L_BOOL          SetShortValue     (pDICOMELEMENT pElement, L_INT16 *pValue, L_UINT32 nCount);
   L_BOOL          SetLongValue      (pDICOMELEMENT pElement, L_INT32 *pValue, L_UINT32 nCount);
   L_BOOL          SetLong64Value    (pDICOMELEMENT pElement, L_INT64 *pValue, L_UINT32 nCount);
   L_BOOL          SetFloatValue     (pDICOMELEMENT pElement, L_FLOAT *pValue, L_UINT32 nCount);
   L_BOOL          SetDoubleValue    (pDICOMELEMENT pElement, L_DOUBLE *pValue, L_UINT32 nCount);
   L_BOOL          SetStringValue    (pDICOMELEMENT pElement, L_TCHAR *pValue, L_UINT32 nCount, L_UINT32 uCharacterSet);
   L_BOOL          SetStringValue    (pDICOMELEMENT pElement, L_TCHAR *pValue, L_UINT32 nCount);

   L_BOOL          SetAgeValue       (pDICOMELEMENT pElement, pVALUEAGE pValue, L_UINT32 nCount);
   L_BOOL          SetDateValue      (pDICOMELEMENT pElement, pVALUEDATE pValue, L_UINT32 nCount);
   L_BOOL          SetTimeValue      (pDICOMELEMENT pElement, pVALUETIME pValue, L_UINT32 nCount);
   L_BOOL          SetDateTimeValue  (pDICOMELEMENT pElement, pVALUEDATETIME pValue, L_UINT32 nCount);
   L_BOOL          SetDateRangeValue      (pDICOMELEMENT pElement, pVALUEDATERANGE pValue, L_UINT32 nCount);
   L_BOOL          SetTimeRangeValue      (pDICOMELEMENT pElement, pVALUETIMERANGE pValue, L_UINT32 nCount);
   L_BOOL          SetDateTimeRangeValue  (pDICOMELEMENT pElement, pVALUEDATETIMERANGE pValue, L_UINT32 nCount);
   L_BOOL          SetConvertValue   (pDICOMELEMENT pElement, L_TCHAR *strText, L_UINT32 nCount);
   L_UINT16        InsertImage       (pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_UINT32 nIndex, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor,L_UINT uFlags, FILESAVECALLBACK pfnCallback, L_VOID *pUserData);
   L_UINT16        InsertImageList   (pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor, L_UINT uFlags );
   L_UINT16        SetImage          (pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor, L_UINT uFlags , FILESAVECALLBACK pfnCallback, L_VOID *pUserData);
   L_UINT16        SetImageList      (pDICOMELEMENT pElement, HBITMAPLIST hList, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor,L_UINT uFlags );
   L_UINT16        DeleteImage       (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_UINT16        ChangeTransferSyntax(L_TCHAR *pszUID, L_INT32 nQFactor, L_UINT32 uFlags);
   L_UINT16        ChangeTransferSyntax(L_TCHAR *pszOutfile, L_TCHAR *pszUID, L_INT32 nQFactor, L_UINT32 uFlags, L_UINT16 uSaveFlags);

   L_VOID          SetKeepPixelDataIntactFlag(L_BOOL bSet);
   
   L_UINT16        SetJ2KOptions( const pFILEJ2KOPTIONS pOptions);

   L_UINT GetLoadFileFlags();
   L_VOID SetLoadFileFlags(L_UINT uLoadFileFlags);

private:
   L_BOOL IsModalityLUTRequired(pBITMAPHANDLE pBitmap, pIMAGEINFO pImageInfo, L_UINT uApplyModalityLUTFlags);

   //---------------------------------------------------------------------------
   // Digital Signatures
   //---------------------------------------------------------------------------
public:
   L_UINT32       GetSignaturesCount(pDICOMELEMENT pItem);
   pDICOMELEMENT  GetSignature(pDICOMELEMENT pItem, L_UINT32 uIndex);
   pDICOMELEMENT  FindSignature(const L_TCHAR* pszSignatureUID);

   L_TCHAR*       GetSignatureUID(pDICOMELEMENT pSignatureItem);
   pVALUEDATETIME GetSignatureDateTime(pDICOMELEMENT pSignatureItem);
   L_UINT16       SaveCertificate(pDICOMELEMENT pSignatureItem, const L_TCHAR* pszFilename, L_UINT16 uFormat = DICOM_CERTIFICATE_FORMAT_PEM);
   L_UINT32       GetSignedElementsCount(pDICOMELEMENT pSignatureItem);
   pDICOMELEMENT  GetSignedElement(pDICOMELEMENT pSignatureItem, L_UINT32 uIndex);
   L_TCHAR*       GetMacTransferSyntax(pDICOMELEMENT pSignatureItem);
   L_TCHAR*       GetMacAlgorithm(pDICOMELEMENT pSignatureItem);

   L_VOID         DeleteSignature(pDICOMELEMENT pSignatureItem);
   L_UINT16       VerifySignature(pDICOMELEMENT pSignatureItem, L_UINT16 uReserved = 0);
   L_UINT16       CreateSignature(pDICOMELEMENT  pItem,
                                  const L_TCHAR*        pszPrivateKeyFile,
                                  const L_TCHAR*        pszCertificateFile,
                                  const L_TCHAR*        pszPassword,
                                  pDICOMELEMENT* ppSignatureItem = NULL,
                                  const L_TCHAR*        pszMacTransferSyntax = NULL,
                                  L_UINT16       uMacAlgorithm = DICOM_MAC_ALGORITHM_RIPEMD160,
                                  L_UINT32*      pElementsToSign = NULL,
                                  L_UINT32       uCount = 0,
                                  L_UINT16       uSecurityProfile = DICOM_SECURITY_PROFILE_NONE,
                                  L_UINT16       uReserved = 0);


   //---------------------------------------------------------------------------
   // LUT Manipulation Functions
   //---------------------------------------------------------------------------
   
   //Modality LUT
   L_UINT16 GetModalityLUTData(L_UINT16 * pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_UINT16 GetModalityLUTAttributes(L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT uStructSize,L_UINT uFlags);
   L_UINT16 SetModalityLUT(L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT16 *pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_UINT16 DeleteModalityLUT(L_UINT32 uFrameIndex, L_UINT uFlags);

   //Palette Color LUT
   L_UINT16 GetPaletteColorLUTAttributes(pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes,L_UINT uStructSize,L_UINT uFlags);
   L_UINT16 GetPaletteColorLUTData(L_UINT16 * pLUTData,L_UINT uDataSize,DICOMPALETTECOLORLUTTYPE PaletteColorLUTType,L_UINT uFlags);
   L_UINT16 SetPaletteColorLUTAttributes(pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes,L_UINT uFlags);
   L_UINT16 SetPaletteColorLUTData(L_UINT16 * pLUTData,L_UINT uDataSize,DICOMPALETTECOLORLUTTYPE PaletteColorLUTType,L_UINT uFlags);
   L_UINT16 DeletePaletteColorLUT(L_UINT uFlags);


   // VOI LUT
   L_UINT16 GetWindowCount (L_UINT32 uFrameIndex, L_UINT *pCount);
   L_UINT16 GetWindow      (L_UINT32 uFrameIndex, L_UINT uWindowIndex ,pDICOMWINDOWATTRIBS pWindowAttributes ,  L_UINT uStructSize,L_UINT uFlags);
   L_UINT16 SetWindow      (L_UINT32 uFrameIndex, L_UINT uWindowIndex ,pDICOMWINDOWATTRIBS pWindowAttributes ,  L_UINT uFlags);
   L_UINT16 DeleteWindow   (L_UINT32 uFrameIndex, L_UINT uFlags);

public:
   L_UINT16 GetVOILUTCount (L_UINT * pCount);
   L_UINT16 GetVOILUT      (L_UINT uVOILUTIndex ,pDICOMVOILUTATTRIBS pVOILUTAttributes ,  L_UINT uStructSize,L_UINT uFlags);
   L_UINT16 SetVOILUT      (L_UINT uVOILUTIndex ,pDICOMVOILUTATTRIBS pVOILUTAttributes ,  L_UINT16 * pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_UINT16 GetVOILUTData  (L_UINT uVOILUTIndex ,L_UINT16 * pLUTData,  L_UINT uDataSize,L_UINT uFlags);
   L_UINT16 DeleteVOILUT   (L_UINT uFlags);

   
   //---------------------------------------------------------------------------
   // Overlay Manipulation Functions
   //---------------------------------------------------------------------------
   L_UINT16 GetOverlayCount            (L_UINT * pCount);
   L_UINT16 GetOverlayAttributes       (L_UINT uOverlayIndex ,pOVERLAYATTRIBUTES    pOverlayAttributes   ,  L_UINT   uStructSize,L_INT *pGroupNumber,L_BOOL * pIsOverlayInDataset , L_UINT uFlags);
   L_UINT16 GetOverlayActivationLayer  (L_UINT uOverlayIndex ,L_TCHAR *             pActivationLayer     ,  L_UINT   uLength);
   L_UINT16 GetOverlayBitmap           (L_UINT uOverlayIndex ,pBITMAPHANDLE         pBitmap              ,  L_UINT   uStructSize,L_UINT uFlags);   
   L_UINT16 GetOverlayBitmapList       (L_UINT uOverlayIndex ,HBITMAPLIST           hList                ,  L_UINT32 uOverlayFrameIndex, L_UINT32 uCount,L_UINT uFlags);
   L_UINT16 SetOverlayAttributes       (L_UINT uOverlayIndex ,pOVERLAYATTRIBUTES    pOverlayAttributes,L_UINT uFlags);
   L_UINT16 SetOverlayBitmap           (L_UINT uOverlayIndex ,pBITMAPHANDLE         pBitmap,L_UINT uFlags);
   L_UINT16 SetOverlayBitmapList       (L_UINT uOverlayIndex ,HBITMAPLIST           hList,L_UINT uFlags);
   L_UINT16 DeleteOverlay              (L_UINT uOverlayIndex ,L_UINT uFlags);

   //---------------------------------------------------------------------------
   // Annotation Functions
   //---------------------------------------------------------------------------
#if !defined(FOR_MANAGED) && !defined(FOR_UWP)

   L_UINT16        AnnSave           (HANNOBJECT      hAnnContainer,
                                      L_UINT          uFormat,
                                      L_BOOL          bSelected,
                                      pSAVEFILEOPTION pSaveOption,
                                      L_INT           nIndex,
                                      L_UINT32       *pnPrivateCreatorTag
                                      );

   L_UINT16        AnnLoad           (pHANNOBJECT     phAnnContainer,
                                      L_INT           nIndex,
                                      pLOADFILEOPTION pLoadOptions
                                     );


   L_UINT16        AnnCount         (L_INT *pFileIndices, L_UINT32 *pnPrivateCreatorTag);

   L_UINT16        AnnDelete        (L_INT nIndex, L_INT nPage); //nIndex: Pass -1 to delete the LEAD Private tag and all files
                                                                 //nPage:   Pass -1 to delete the entire file
                                                                 //         Pass >0 to delete the page

   L_VOID          LoadAnnDLL        ();

   L_UINT16 ConvertLEADAnnObjToDicomAnnObjs(HANNOBJECT hAnnObject, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uFlags);
   virtual L_UINT16 OnConvertLEADAnnObjToDicomAnnObj(const pDICOMGRAPHICOBJECT pGraphicObject, const pDICOMTEXTOBJECT pTextObject);

   L_UINT16 ConvertDicomAnnObjToLEADAnnObj(pHANNOBJECT phAnnObject, pDICOMGRAPHICOBJECT pGraphicObject, pDICOMTEXTOBJECT pTextObject, L_INT32 nDisplayAreaWidth, L_INT32 nDisplayAreaHeight);
   L_UINT16 ConvertDicomAnnObjToLEADAnnObj(pHANNOBJECT phAnnObject, pDICOMGRAPHICOBJECT pGraphicObject = NULL, pDICOMTEXTOBJECT pTextObject= NULL);

#endif // #if !defined(FOR_MANAGED) && !defined(FOR_UWP)

   //---------------------------------------------------------------------------
   // Presentation State Module functions 
   //---------------------------------------------------------------------------   
   L_UINT16 SetPresStateInfo(pDICOMPRESSTATEINFO pPresState);
   L_UINT16 GetPresStateInfo(pDICOMPRESSTATEINFO pPresState, L_UINT uStructSize);
   L_UINT16 AddPresStateImageRefByFileName(L_TCHAR* pszImageFileName, L_INT32* pFrameNumbers = NULL, L_UINT uFramesCount = 0);
   L_UINT16 AddPresStateImageRefByDS(LDicomDS* pDS, L_INT32* pFrameNumbers = NULL, L_UINT uFramesCount = 0);
   L_UINT16 RemovePresStateImageRefBySOPInstance(L_TCHAR* pszSOPInstanceUID);
   L_UINT16 RemoveAllPresStateImageRefs(L_VOID);
   L_TCHAR*  GetPresStateImageRefSOPInstance(pDICOMELEMENT pRefSeriesSQItem, L_UINT uImageIndex);
   L_UINT16 GetPresStateImageRefCount(pDICOMELEMENT pRefSeriesSQItem, L_UINT* pCount);
   pDICOMELEMENT FindFirstPresStateRefSeriesItem();
   pDICOMELEMENT FindNextPresStateRefSeriesItem(pDICOMELEMENT pRefSeriesItem);
   pDICOMELEMENT GetPresStateImageRefBySOPInstance(L_TCHAR* pszSOPInstanceUID);   
   //---------------------------------------------------------------------------
   // Graphic Layer Module functions
   //---------------------------------------------------------------------------    
   L_UINT16 CreateLayer(pDICOMGRAPHICLAYER pGraphicLayer, L_UINT* pLayerIndex);
   L_UINT16 GetLayerInfo(L_UINT uLayerIndex, pDICOMGRAPHICLAYER pGraphicLayer, L_UINT uStructSize);
   L_UINT16 SetLayerInfo(L_UINT uLayerIndex, pDICOMGRAPHICLAYER pGraphicLayer);
   L_UINT16 RemoveLayerByIndex(L_UINT uLayerIndex,L_BOOL bAnnSequence);
   L_UINT16 RemoveLayerByName(L_TCHAR* pszLayerName,L_BOOL bAnnSequence);
   L_UINT16 RemoveAllLayers(L_BOOL bAnnSequence);
   L_UINT16 GetLayerCount(L_UINT* pCount);
   L_UINT16 GetLayerIndex(L_TCHAR* pszLayerName, L_INT* pLayerIndex);
   L_UINT16 GetLayerGraphicObjectCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_UINT16 RemoveLayerGraphicObjects(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16 GetLayerTextObjectCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_UINT16 RemoveLayerTextObjects(pDICOMELEMENT pGraphicAnnSQItem);
   pDICOMELEMENT GetLayerElementByIndex(L_UINT uLayerIndex);
   pDICOMELEMENT GetLayerElementByName(L_TCHAR* pszLayerName);   
   //---------------------------------------------------------------------------
   // Graphic Annotation Module functions 
   //---------------------------------------------------------------------------          
   pDICOMELEMENT FindFirstGraphicAnnSQItem();
   pDICOMELEMENT FindNextGraphicAnnSQItem(pDICOMELEMENT pRefSeriesItem);
   L_TCHAR* GetLayerName(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16 SetLayerName(pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszLayerName);
   L_UINT16 CreateGraphicAnnSQItem(L_UINT32 nIndex, L_TCHAR* pszLayerName);
   // Annotation Referenced Image Sequence Functions 
   L_UINT16 AddLayerImageRef(pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   L_UINT16 GetLayerImageRefCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_TCHAR*  GetLayerImageRefSOPInstance(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uImageIndex);
   L_UINT16 RemoveImageRefFromLayer(pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   L_UINT16 RemoveAllImageRefsFromLayer(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16 RemoveAllImageRefFromAllLayers();
   pDICOMELEMENT GetLayerImageRefElement(pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   // Graphic Annotation Objects functions
   L_UINT16 CreateGraphicObject(pDICOMELEMENT pGraphicAnnSQItem, pDICOMGRAPHICOBJECT pGraphicObject, L_BOOL bCheckLayer = FALSE);
   L_UINT16 RemoveGraphicObject(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex);
   L_UINT16 GetGraphicObjectInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjectIndex, pDICOMGRAPHICOBJECT pGraphicObject, L_UINT uStructSize);
   L_UINT16 SetGraphicObjectInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjectIndex, pDICOMGRAPHICOBJECT pGraphicObject);
   L_UINT16 GetGraphicObjectCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_UINT16 RemoveAllGraphicObjects(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16 GetGraphicObjPointCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex, L_UINT* pPointsCount);
   pDICOMELEMENT GetGraphicObjElement(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex);

   // Compound Graphic
   L_TCHAR* GetCompoundGraphicLayerName(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex);
   L_UINT16 CreateCompoundGraphic(pDICOMELEMENT pGraphicAnnSQItem, pDICOMCOMPOUNDGRAPHIC pCompoundGraphicObject, L_BOOL bCheckLayer);
   L_UINT16 RemoveCompoundGraphic(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex);
   L_UINT16 GetCompoundGraphicInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, pDICOMCOMPOUNDGRAPHIC pCompoundGraphic, L_UINT uStructSize);
   L_UINT16 SetCompoundGraphicInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, pDICOMCOMPOUNDGRAPHIC pCompoundGraphic);
   L_UINT16 GetCompoundGraphicCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_UINT16 RemoveAllCompoundGraphics(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16 GetCompoundGraphicPointCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, L_UINT* pPointsCount);
   L_UINT16 GetCompoundGraphicMajorTickCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, L_UINT* pMajorTickCount);
   pDICOMELEMENT GetCompoundGraphicElement(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uIndex);

   // Graphic Group

   // Text Annotation Objects function
   L_UINT16 CreateTextObject(pDICOMELEMENT pGraphicAnnSQItem, pDICOMTEXTOBJECT pTextObject, L_BOOL bCheckLayer= FALSE);
   L_UINT16 RemoveTextObject(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjIndex);
   L_UINT16 GetTextObjectInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjectIndex, pDICOMTEXTOBJECT pTextObject, L_UINT uStructSize);
   L_UINT16 SetTextObjectInfo(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjectIndex, pDICOMTEXTOBJECT pTextObject);
   L_UINT16 GetTextObjectCount(pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_UINT16 RemoveAllTextObjects(pDICOMELEMENT pGraphicAnnSQItem);
   pDICOMELEMENT GetTextObjElement(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex);
   //L_UINT16 GetAutoScaleParams(L_BOOL *pbAutoScaleApplied, L_DOUBLE *pdAutoScaleSlope, L_DOUBLE *pdAutoScaleIntercept, L_DOUBLE *pdWindowCenter, L_DOUBLE *pdWindowWidth);

   //---------------------------------------------------------------------------
   // Private Element methods
   //---------------------------------------------------------------------------
   L_UINT16 CreatePrivateCreatorDataElement(pDICOMELEMENT pElement, L_UINT16 uElementGroup, L_UINT16 uElementNumber, L_TCHAR *pszIdCode, pDICOMELEMENT *ppPrivateCreatorDataElement);
   L_UINT16 GetNextUnusedPrivateTag(pDICOMELEMENT pPrivateCreatorDataElement, L_UINT32 *puTag);
   pDICOMELEMENT FindFirstPrivateCreatorDataElement(pDICOMELEMENT pElement, L_BOOL bTree, L_TCHAR *pszIdCode, L_UINT16 uElementGroup);
   pDICOMELEMENT FindNextPrivateCreatorDataElement(pDICOMELEMENT pElement, L_BOOL bTree, L_TCHAR *pszIdCode, L_UINT16 uElementGroup);
   pDICOMELEMENT FindFirstPrivateElement(pDICOMELEMENT pPrivateCreatorDataElement);
   pDICOMELEMENT FindNextPrivateElement(pDICOMELEMENT pElement, pDICOMELEMENT pPrivateCreatorDataElement);

   //---------------------------------------------------------------------------
   // Encapsulated Document methods
   //---------------------------------------------------------------------------
   L_UINT16 GetEncapsulatedDocument(pDICOMELEMENT pElement, L_BOOL bChild, L_TCHAR *pszFileDocument, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);
   L_UINT16 SetEncapsulatedDocument(pDICOMELEMENT pElement, L_BOOL bChild, L_TCHAR *pszFileDocument, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);

   static L_TCHAR* GetDefaultDicomTempPath();
   static L_VOID   SetDefaultDicomTempPath(L_TCHAR* szPath);

private:
   L_UINT16 GetEncapsulatedDocument(
      pDICOMELEMENT pElement, 
      L_BOOL bChild, 
      L_TCHAR *pszFileDocument,
      L_UCHAR * pBuffer,
      L_UINT32 *puBufferSize,
      pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, 
      pDICOMCODESEQUENCEITEM pConceptNameCodeSequence
      );

   L_UINT16 SetEncapsulatedDocument(
      pDICOMELEMENT pElement, 
      L_BOOL bChild, 
      L_TCHAR *pszFileDocument, 
      L_UCHAR * pBuffer,
      L_UINT32 uBufferSize,
      pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, 
      pDICOMCODESEQUENCEITEM pConceptNameCodeSequence
      );

   public:
      L_UINT16 GetEncapsulatedDocument(
         pDICOMELEMENT pElement, 
         L_BOOL bChild, 
         L_UCHAR *pBuffer, 
         L_UINT32 *puBufferSize, 
         pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, 
         pDICOMCODESEQUENCEITEM pConceptNameCodeSequence
         );

      L_UINT16 SetEncapsulatedDocument(
         pDICOMELEMENT pElement, 
         L_BOOL bChild, 
         L_UCHAR * pBuffer,
         L_UINT32 uBufferSize,
         pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, 
         pDICOMCODESEQUENCEITEM pConceptNameCodeSequence
         );

   //---------------------------------------------------------------------------
   // Used in Managed DicomNet
   //---------------------------------------------------------------------------
   public: L_LONG AddRefInternal();
   public: L_LONG ReleaseInternal();
   public: L_INT GetIsManaged();
   public: L_VOID SetIsManaged(L_INT nValue);

   //---------------------------------------------------------------------------
   // (Undocumented Functions and Internal use only)
   //---------------------------------------------------------------------------
   L_BOOL          IsBadPixelData(L_UINT32 * pBadCount,L_UINT32 * pGoodCount);
   L_UINT16        LoadDS            (LDicomFile *pFile, L_UINT16 nFlags, L_BOOL bVerify);
   L_UINT16        SaveDS            (LDicomFile *pFile, L_UINT16 nFlags);
   L_UINT32        FindGetValue      (pDICOMELEMENT pElement, L_UINT32 nTag, L_VOID *pValue, L_UINT32 nIndex, L_UINT32 nCount, L_INT16 nType);

   L_UINT          GetPrivateDataUnsignedInt    (L_INT nValue);
   L_DOUBLE        GetPrivateDataDouble         (L_INT nValue);

#if defined(_MSC_VER)
   L_LTDIC_API
#endif
      friend L_UINT32       EXT_FUNCTION L_DicomFindGetValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nTag, L_VOID *pValue, L_UINT32 nIndex, L_UINT32 nCount, L_INT16 nType);
   pDICOMELEMENT   FindSetValue      (pDICOMELEMENT Element, L_UINT32 nTag, L_VOID *pValue, L_UINT32 nCount, L_INT16 nType);
#if defined(_MSC_VER)
   L_LTDIC_API
#endif
      friend L_BOOL EXT_FUNCTION L_DicomInsertUncompressedFrame(LDicomDS *pDS , pDICOMELEMENT pPixelDataElement, L_VOID *pFrameBuffer, L_UINT32 nLength,L_UINT32 nFrameIndex); 
      friend L_BOOL CopyBinaryValue(LDicomDS *pSrcDS, LDicomDS *pDstDS, pDICOMELEMENT pSrcElement, pDICOMELEMENT pDstElement);
   static HINSTANCE  m_hInstance;
   L_VOID SetAnnConversionCallback(pCONVERTLEADANNOBJTODICOMANNPROC pDICOMAnnConversionProc,L_VOID* pDICOMAnnConversionUserData);
   L_BOOL InsertBinaryValue(pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_BOOL GetBinaryValue(pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_UINT32        GetConvertValueA  (pDICOMELEMENT pElement, L_CHAR *pszText);
   L_BOOL          SetStringValueA    (pDICOMELEMENT pElement, L_CHAR *pValue, L_UINT32 nCount);
   L_BOOL          SetConvertValueA   (pDICOMELEMENT pElement, L_CHAR *pszText, L_UINT32 nCount);
   L_UINT          UpdateSpecificCharacterSet();
private:
   LDicomTree           m_Tree;
   L_UINT16             m_nFlags;
   L_VOID *             m_pPrivateData;
   L_CHAR               m_szClass[UID_MAX_SIZE+1];
   L_CHAR               m_pPreamble[DS_PREAMBLE_LENGTH];
   LDicomFile          *m_pInput;
   LDicomFile           m_MyInput;
   LDicomFile           m_MyScratch;
   L_BOOL               m_bConformance;
   DICOMMODULE          m_Module;
   CONFORMANCECALLBACK  m_pfnDebug;
   L_VOID              *m_pDebug;

   L_INT               *m_pCharacterSets;
   L_INT                m_nCharacterSetCount;
   L_LONG m_nReferenceCount;

#if defined(FOR_UNIX)
   L_TCHAR              m_szTempPath[_MAX_PATH];
#endif

   L_INT m_nIsManaged;

#if defined(FOR_XCODE)
   L_UINT16 TryOpenScratch();
   L_BOOL IsScratchOpen();
#endif

   static L_BOOL IsCmpFunctionOk(const L_CHAR* functionName);
   static L_INT CallFltLoadBuffer(L_UCHAR* pInput, L_SIZE_T nLength, L_UCHAR* pOutput, L_INT nFormat, L_INT32 nWidth, L_INT32 nHeight, L_UINT nBitsPerPixel, L_VOID* pLeadHdr, L_UINT uFlags);
   static L_INT CallFltSaveBuffer(L_UCHAR* pInput, L_VOID* pbiInput, L_UCHAR* pOutput, L_SIZE_T* pdwSize, L_INT nQFactor, L_UINT uFlags, L_UINT nFormat, L_UCHAR* pTopBuffer, L_INT nTopBufferHeight);

   static L_BOOL IsJlsFunctionOk(const L_CHAR* functionName);
   static L_INT CallFltLoadBufferJls(L_UCHAR* pInput, L_SIZE_T nLength, L_UCHAR* pOutput, L_INT nFormat, L_INT32 nWidth, L_INT32 nHeight, L_UINT nBitsPerPixel, L_VOID* pLeadHdr, L_UINT uFlags);
   static L_INT CallFltSaveBufferJls(L_UCHAR* pInput, L_VOID* pbiInput, L_UCHAR* pOutput, L_SIZE_T* pdwSize, L_INT nQFactor, L_UINT uFlags, L_UINT nFormat, L_UCHAR* pTopBuffer, L_INT nTopBufferHeight);

   static L_BOOL IsCodecsFunctionOk(const L_CHAR* functionName);
   static L_BOOL IsImgCorFunctionOk(const L_CHAR* functionName);
   static L_BOOL IsLtfilFunctionOk(const L_CHAR* functionName);
   static L_INT CallSaveFile(
      L_TCHAR* pszFile,
      pBITMAPHANDLE pBitmap,
      L_INT nFormat,
      L_INT nBitsPerPixel,
      L_INT nQFactor,
      L_UINT uFlags,
      FILESAVECALLBACK pfnCallback,
      L_VOID* pUserData,
      pSAVEFILEOPTION pSaveOptions);
   static L_INT CallApplyModalityLUT(pBITMAPHANDLE pBitmap, L_UINT16 *pLUT, pDICOMLUTDESCRIPTOR pLUTDescriptor, L_UINT uFlags);
   static L_INT CallApplyLinearModalityLUT(pBITMAPHANDLE pBitmap, L_DOUBLE fIntercept, L_DOUBLE fSlope, L_UINT uFlags);
   static L_INT CallApplyVOILUT(pBITMAPHANDLE pBitmap, L_UINT16 *pLUT, pDICOMLUTDESCRIPTOR pLUTDescriptor, L_UINT uFlags);
   static L_INT CallApplyLinearVOILUT(pBITMAPHANDLE pBitmap, L_DOUBLE fCenter, L_DOUBLE fWidth, L_UINT uFlags);
   static L_INT CallGetMinMaxVal(pBITMAPHANDLE pBitmap, L_INT *pMinVal, L_INT *pMaxVal);
   static L_INT CallGetLinearVOILUT(pBITMAPHANDLE pBitmap, L_DOUBLE *pCenter, L_DOUBLE *pWidth, L_UINT uFlags);
   static L_INT CallCountLUTColors(RGBQUAD *pLUT, L_UINT ulLLUTLen, L_UINT *pNumberOfEntries, L_INT *pFirstIndex, L_UINT uFlags);
#ifdef CAN_HAVE_LUT16
   static L_INT CallCountLUTColorsExt(L_RGBQUAD16 *pLUT, L_UINT ulLLUTLen, L_UINT *pNumberOfEntries, L_INT *pFirstIndex, L_UINT uFlags);
#endif // #ifdef CAN_HAVE_LUT16
   static L_INT CallShiftBitmapData(pBITMAPHANDLE  pDstBitmap, pBITMAPHANDLE  pSrcBitmap, L_UINT uSrcLowBit, L_UINT uSrcHighBit, L_UINT uDstLowBit, L_UINT uDstBitsPerPixel);

   static L_INT CallStartGetMinMaxVal(L_VOID** ppHandle, pBITMAPHANDLE pBitmap, L_UINT32 uFlags);
   static L_INT CallProcessGetMinMaxVal(L_VOID *pHandle, L_UCHAR *pScan, L_UINT *pScanData, L_UINT uScanDataCount);
   static L_INT CallStopGetMinMaxVal(L_VOID *pHandle, L_INT*pMinVal, L_INT*pMaxVal);

   FLTJ2KDECOMPRESSFRAME   m_fltJ2KDecompressFrame;

#if !defined(FOR_UWP)
   HINSTANCE               m_hANN;
   pL_ANNLOADMEMORY        pfnAnnLoadMemory;
   pL_ANNSAVEMEMORY        pfnAnnSaveMemory;
   pL_ANNDELETEPAGEMEMORY  pfnAnnDeletePageMemory;   
   pL_ANNGETPOINTS         m_pfnAnnGetPoints;
   pL_ANNGETPOINTCOUNT     m_pfnAnnGetPointCount;
   pL_ANNGETFILLMODE       m_pfnAnnGetFillMode;
   pL_ANNGETTEXTLEN        m_pfnAnnGetTextLen;
   pL_ANNGETTEXT           m_pfnAnnGetText;
   //pL_ANNGETTEXTA          m_pfnAnnGetTextA;
   pL_ANNGETRECT           m_pfnAnnGetRect;
   pL_ANNGETTYPE           m_pfnAnnGetType;
   pL_ANNCREATE            m_pfnAnnCreate;
   pL_ANNSETPOINTS         m_pfnAnnSetPoints;
   pL_ANNDEFINE            m_pfnAnnDefine;
   pL_ANNSETRECT           m_pfnAnnSetRect;
   pL_ANNSETFILLMODE       m_pfnAnnSetFillMode;
   pL_ANNSETTEXT           m_pfnAnnSetText;
   //pL_ANNSETTEXTA          m_pfnAnnSetTextA;

   pCONVERTLEADANNOBJTODICOMANNPROC m_pDICOMAnnConversionProc;
   L_VOID*                          m_pDICOMAnnConversionUserData;   
#endif // #if !defined(FOR_UWP)



   L_VOID        ResetDS                (L_BOOL bClose);
   L_UINT16      CopyTreeDS             (pDICOMELEMENT pDstParent, LDicomDS *pSrcDS, pDICOMELEMENT pSrcParent);
   L_UINT16      CopyTreeDS             (pDICOMELEMENT pDstParent, LDicomDS *pSrcDS, pDICOMELEMENT pSrcParent, COPYDSCALLBACK pfnCallback, L_VOID *pUserData);
   
   L_UINT16      GetDefaultVR           (pDICOMELEMENT pElement, L_UINT32 nTag, L_BOOL bParent);
   L_UINT16      GetSizeVR              (L_UINT16 nVR);
   L_BOOL        VerifyVR               (pDICOMELEMENT pElement, L_UINT16 nType);
   L_BOOL        GetTS                  (L_UINT16 *pnFlags, L_INT32 *pnCompression, L_CHAR *pszValue);
   L_BOOL        SetTS                  (L_UINT16 nFlags, L_INT32 nCompression);
   L_BOOL        GetClass               (L_UINT32 *pnClass, L_CHAR *pszUID);
   L_BOOL        SetClass               (L_UINT32 nClass);

   L_BOOL        VerifyTypeValue        (pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 *pnCount, L_UINT16 nType);
   L_BOOL        GetTypeValue           (pDICOMELEMENT pElement);
   L_BOOL        SetTypeValue           (pDICOMELEMENT pElement, L_CHAR *pValue, L_UINT32 nCount, L_UINT32 uFlags=0);

   L_BOOL        GetFileBinaryValue     (pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_BOOL        SetFileBinaryValue     (pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_BOOL        InsertFileBinaryValue  (pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_BOOL        DeleteFileBinaryValue  (pDICOMELEMENT pElement, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_UINT32      GetFileBinaryIndex     (pDICOMELEMENT pElement, L_DICOM_OFFSET *nOffset);
   L_BOOL        CopyFileBinaryValue    (pDICOMELEMENT pElement, L_DICOM_OFFSET nOffset1, L_UINT32 nLength, L_UINT16 nVR, L_BOOL bLittleEndian1, LDicomFile *pFile2, L_DICOM_OFFSET nOffset2, L_BOOL bLittleEndian2);
   L_VOID        ConvertFileBinaryValue (L_VOID *pBuffer, L_UINT32 nLength, L_UINT16 nVR, L_BOOL bLittleEndian);

   L_VOID        DelSpaces              (L_CHAR *pszText, L_UINT32 nLength);
   L_VOID        DelSpaces              (L_CHAR *pszText);

   L_UINT32 GetLengthSequence           (pDICOMELEMENT pElement, L_UINT16 nFlags);
   L_UINT32 GetLengthGroup              (pDICOMELEMENT pElement, L_UINT16 nFlags);
   L_UINT32 GetLengthElement            (L_UINT32 nTag, L_UINT16 nVR, L_UINT32 nLength, L_BOOL bLittleEndian, L_BOOL bExplicitVR);
   L_DICOM_OFFSET GetOffsetElement      (pDICOMELEMENT pElement, L_UINT16 nFlags);

   L_UINT16      ReadSequence           (LDicomFile *pInput, pDICOMELEMENT hParent, L_UINT16 nFlags, L_UINT32 *pnLength);
   L_UINT16      WriteSequence          (LDicomFile *pOutput, pDICOMELEMENT pElement, L_UINT16 nFlags);

   L_UINT16      ReadElement            (LDicomFile *pInput, L_UINT32 *pnTag, L_UINT16 *pnVR, L_UINT32 *pnLength, L_BOOL bLittleEndian, L_BOOL bExplicitVR);
   L_UINT16      WriteElement           (LDicomFile *pOutput, L_UINT32 nTag, L_UINT16 nVR, L_UINT32 nLength, L_BOOL bLittleEndian, L_BOOL bExplicitVR);

   L_BOOL        Read                   (LDicomFile *pInput, L_VOID *pBuffer, L_UINT32 nLength, L_UINT16 nVR, L_BOOL bLittleEndian);
   L_BOOL        Write                  (LDicomFile *pOutput, L_VOID *pBuffer, L_UINT32 nLength, L_UINT16 nVR, L_BOOL bLittleEndian);

   L_BOOL        InsertModule           (pDICOMELEMENT pParent, L_UINT32 nModule, L_UINT32 nIndex, L_BOOL bOptional);
   L_VOID        InsertModule           (pDICOMELEMENT pParentElement, pDICOMIOD pParentIOD, L_BOOL bOptional);
   pDICOMIOD     VerifyModule           (pDICOMELEMENT pParent, L_UINT32 nModule);
   L_UINT32      GetCountElementIOD     (pDICOMIOD pIOD, L_BOOL bOptional);

   pDICOMELEMENT GetItemKey             (pDICOMELEMENT pElement);
   pDICOMELEMENT FindAttachKey          (pDICOMELEMENT pElement, L_UINT32 nTag);
   L_VOID        RefreshKeys            ();
   L_UINT32      GetAvailableKey        ();
   L_VOID        InsertModuleKey        (pDICOMELEMENT pParentElement, pDICOMIOD pParentIOD, L_BOOL bOptional);

   L_BOOL        ComputeResolutionFromTag(pDICOMELEMENT pElement, L_UINT32 uTag, pIMAGEINFO pInfo);
   L_UINT16      GetInfoImage           (pDICOMELEMENT pElement, pIMAGEINFO pInfo, L_UINT32 nIndex, L_BOOL nFlags);
   L_UINT16      GetInfoImage2          (pDICOMELEMENT pElement, pIMAGEINFO pInfo, L_UINT32 nIndex, L_BOOL uFlags);
   L_UINT16      SetInfoImage           (pDICOMELEMENT pElement, pIMAGEINFO pInfo, pBITMAPHANDLE pBitmap, L_UINT32 uFrameIndex, L_INT32 nPhotometric, L_BOOL bSave,L_UINT uFlags);
   L_VOID        FreeInfoImage          (pIMAGEINFO pInfo);
   L_UINT16      DecodeSegmentedPaletteColorLUTData(pIMAGEINFO pInfo);
   L_UINT16      DecodeSegmentedPaletteColorLUTData(L_UINT16 *pPaletteBuffer,L_UINT32  uNumEntries,L_UINT32  uSegmentedDataSize);   

   L_UINT16      LoadImage              (pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap,L_UINT uStructSize ,L_UINT32 nIndex, L_INT32 nBitsPerPixel, /*L_INT32 nOrder,*/ L_UINT uFlags ,FILEREADCALLBACK pfnCallback, L_VOID *pUserData);

   L_UINT16      SetPaintParams         (pBITMAPHANDLE pBitmap,IMAGEINFO * pImageInfo);
   //L_BOOL        CanApplyModalityLUT    (pBITMAPHANDLE  pBitmap,L_BOOL VOILUTWillBeApplied,L_INT nOriginalBitmapMinVal,L_INT nOriginalBitmapMaxVal, L_UINT32 uFrameIndex);
   L_UINT16      ApplyModalityLUT       (pBITMAPHANDLE pBitmap,L_UINT uStructSize ,IMAGEINFO * pImageInfo,L_INT nOriginalBitmapMinVal,L_INT nOriginalBitmapMaxVal,L_UINT uApplyModalityLUTFlags);   
   L_UINT16      ApplyVOILUT            (pBITMAPHANDLE pBitmap,L_UINT uStructSize ,IMAGEINFO * pImageInfo, L_UINT uFlags);   
   L_UINT16      SaveImage              (pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_UINT32 nIndex, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor, L_UINT uFlags,FILESAVECALLBACK pfnCallback, L_VOID *pUserData);
   L_UINT16      SetVOIlUT              (L_UINT32      uFrameIndex,pDICOMELEMENT pPixelDataEle,pBITMAPHANDLE pBitmap,L_UINT        uFlags);
   L_UINT16      SetNonLinearVOILUT     (L_UINT32 uFrameIndex, pDICOMELEMENT pElement,pBITMAPHANDLE pBitmap);
   L_UINT16      DeleteImage            (pDICOMELEMENT pElement, L_UINT32 nIndex);
   L_UINT16      RefreshImage           (pDICOMELEMENT pElement);

   L_BOOL        IsElementAffectedByCharacterSet(pDICOMELEMENT pElement);

   L_UINT16 InternalApplyModalityLUT(pBITMAPHANDLE pBitmap, pIMAGEINFO pImageInfo, L_BOOL bLoadGray, L_UINT uDicomGetImageFlags, L_INT nOriginalMinGrayValue, L_INT nOriginalMaxGrayValue);
   L_UINT16      DecodeNONE             (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_UINT32 nIndex, L_VOID* pData);
   L_UINT16      DecodeRLE              (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_VOID* pData);
   L_UINT16      DecodeRLE              (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_UINT uFlags, L_VOID* pData);
   L_UINT16      DecodeJPEG             (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_VOID* pData);
   L_UINT16      DecodeJPEG             (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_BOOL bJpegLS, L_VOID* pData);
   L_UINT16      DecodeJPEGLS           (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_VOID* pData);
   L_UINT16      DecodeJ2K              (pBITMAPHANDLE pBitmap, pIMAGEINFO pInfo, L_BOOL bJPX, L_VOID* pData);

   L_UINT16      DecodeJustLibJ2K       (pIMAGEINFO pInfo, L_UCHAR *pImage,L_UINT32 uImageBuffSize);
   L_UINT16      EncodeNONE             (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_UINT32 *pnLength, L_UINT32 uFlags);
   L_UINT16      EncodeRLE              (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_UINT32 *nLength, L_UINT32 uFlags, pIMAGEINFO pInfo);
   L_UINT16      EncodeJPEG             (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_INT32 nQFactor, L_UINT32 *pnLength);
   L_UINT16      EncodeJPEG             (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_INT32 nQFactor, L_UINT32 *pnLength, L_BOOL bJpegLS);
   L_UINT16      EncodeJPEGLS           (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_INT32 nQFactor, L_UINT32 *pnLength);
   L_UINT16      EncodeJPEG(pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_INT32 nQFactor);

   L_UINT16      EncodeJ2K              (L_UCHAR** ppImage, pBITMAPHANDLE pBitmap, L_INT32 nQFactor, L_UINT32 *pnLength, L_BOOL bLossless, L_BOOL bJPX);

   L_VOID        ConvertYUVtoRGB        (L_UCHAR *pImage, L_UINT32 nPlaneSize, L_BOOL bPlanar);
   L_VOID        Convert12to16          (L_UCHAR *pImage, L_INT nWidth, L_INT nHeight);
   //L_UINT16      GenerateGrayLUT        (pBITMAPHANDLE pBitmap, L_UINT32 nBitsStored, L_UINT32 nHighBit, L_UINT32 nMinVal, L_UINT32 nMaxVal);
   L_HPALETTE    CreateColorPalette     (L_RGBQUAD *pPalette, L_UINT32 nColors);
   L_HPALETTE    CreateGrayPalette      (L_UINT32 nBitsPerPixel);

   L_BOOL        CreatePrivateCreatorElement(pDICOMELEMENT pElement, L_UINT32 uTag);
   L_BOOL        IsAnnPrivateCreatorElement(pDICOMELEMENT pElement);
   pDICOMELEMENT FindAnnPrivateCreatorElement(L_CHAR *pszPrivateString);
   L_INT         GetXRangeValue(pDICOMELEMENT pElement, L_UINT32 nIndex, L_VOID * pValue, L_UINT16 nType, L_UINT32 nCount);
   L_UINT16      UncompressPixelDataElement(L_BOOL bKeepPixelDataIntact, L_UINT32 uFlags);
   L_UINT16      CompressPixelData(L_INT32 nCompression,L_INT32 nQFactor,L_BOOL bKeepPixelDataIntact, L_UINT32 uFlags);

   L_UINT16      ChangeTransferSyntax_Internal(L_TCHAR *pszOutFile, DICOM_TRANSFER_SYNTAXES NewTransferSyntax, L_INT32 nQFactor, L_BOOL bKeepPixelDataIntact, L_UINT32 uFlags, L_UINT16 uSaveFlags);
   L_UINT16      FixBadElements();
   L_UINT16      ValidateJ2KOptions ( const pFILEJ2KOPTIONS pOptions );

   L_UINT16      AddIODSpecificElements(pDICOMELEMENT pParent,pIMAGEINFO pInfo);

   //---------------------------------------------------------------------------
   // Internal LUT Manipulation Functions
   //---------------------------------------------------------------------------
   
   // Modality LUT
   L_UINT16      ResetModalityLUTAttributes(pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT uStructSize);
   L_UINT16      GetLUTDescriptor(pDICOMELEMENT pParentLUTSequenceItem,L_INT nTag,pDICOMLUTDESCRIPTOR pLUTDescriptor,DICOMLUTDESCRIPTORTYPE DescriptorType);
   L_UINT16      SetModalityLUTDescriptor(pDICOMELEMENT pParentLUTSequenceItem,pDICOMLUTDESCRIPTOR pLUTDescriptor);
   L_UINT16      SetLUTDescriptor(pDICOMELEMENT pNeighborElement,pDICOMLUTDESCRIPTOR pLUTDescriptor, L_INT nTag);
   L_UINT16      VerifyModalityLUT(pDICOMMLUTATTRIBS pModalityLUTAttributes);
   L_UINT16      Set8BitLUT(pDICOMELEMENT pLUTDataElement,L_UINT16 *pLUTData,L_UINT uDataSize);
   L_UINT16      InsertModalityLUTSequence(pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT16 *pLUTData,L_UINT uDataSize);

   L_UINT32      SearchModalityLUT(pDICOMELEMENT pNeighbor, pDICOMMLUTATTRIBS pModalityLUTAttributes);


   // v16

  pDICOMELEMENT CreateMultiFrameFunctionalGroupElement(L_UINT32 uTagMultiframeFunctionalGroup, L_UINT32 uElementSequence, L_UINT32 uElement, L_UINT uItemIndex, L_UINT uFlag);
  pDICOMELEMENT FindFunctionalGroupElement(L_UINT32 uTagMultiframeFunctionalGroup, L_UINT32 uElementSequence, L_UINT32 uElement, L_UINT uItemIndex);
  L_UINT32 SearchWindowCenterWidth(pDICOMELEMENT pNeighbor, L_UINT uWindowIndex, pDICOMWINDOWATTRIBS  pWindowAttributes);

   L_INT32       GetItemCount(pDICOMELEMENT pParent);
   pDICOMELEMENT GetItem(pDICOMELEMENT pParent, L_INT nItemIndex);
   pDICOMELEMENT FindChildElement(pDICOMELEMENT pParent, L_UINT32 uTag);
   pDICOMELEMENT FindMultiFrameFunctionalGroupElement(L_UINT32 uElementSequence, L_UINT32 uElement, L_UINT uItemIndex);
   L_BOOL        CanAddMultiFrameFunctionalGroup();
   pDICOMELEMENT FindMultiFrameFunctionGroupVOILUT(L_UINT32 uFrameIndex);
   pDICOMELEMENT FindMultiFrameFunctionGroupModalityLUT(L_UINT32 uFrameIndex);
   L_VOID        GetMultiFrameFunctionGroupLutElements(L_UINT32 uFlags, L_UINT32 uFrameIndex, pDICOMELEMENT *ppElementVOILUT, L_BOOL *pbSharedExistingVOILUT, pDICOMELEMENT *ppElementModalityLUT, L_BOOL *pbSharedExistingModalityLUT);
   L_UINT32      FindFunctionalGroupWindowCenterWidth(L_UINT32 uTagMultiframeFunctionalGroup, L_UINT uItemIndex, pDICOMWINDOWATTRIBS pWindowAttributes, L_UINT uWindowIndex);
   pDICOMELEMENT GetSequenceItem(pDICOMELEMENT pSequence, L_UINT uItem, L_UINT32 uTag);
   L_UINT32      FindFunctionalGroupModalityLUT(L_UINT32 uTagMultiframeFunctionalGroup, L_UINT uItemIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes);
   //L_UINT16      GetModalityLUTAttributesMultiFrame(pDICOMMLUTATTRIBS pModalityLUTAttributes ,L_UINT uStructSize ,L_UINT uFlags, L_INT nFrameIndex);
   L_BOOL        IsSharedMultiFrameFunctionalGroup(pDICOMELEMENT pElement);
   L_BOOL        IsPerFrameMultiFrameFunctionalGroup(pDICOMELEMENT pElement);

   L_BOOL        InsertItemPerFrameMultiFrameFunctionalGroup(L_INT nIndex);
   L_BOOL        DeleteItemPerFrameMultiFrameFunctionalGroup(L_INT nItemFirst, L_INT nItemLast);
   L_BOOL        DeleteMultiFrameSequence(L_UINT32 uElementSequence, L_UINT32 uFrameIndex);


   // Palette Color
   L_UINT16      ResetPaletteColorLUTAttributes(pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes,L_UINT uStructSize);
   L_UINT16      GetPaletteColorDescriptor(pDICOMELEMENT pPaletteColorDescriptorElement,pDICOMLUTDESCRIPTOR pLUTDescriptor);
   L_UINT16      VerifyPaletteColorLUT(pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes);
      

   // VOI LUT 
   pDICOMELEMENT GetVOILUTItem(pDICOMELEMENT pVOILUTSequence,L_UINT uVOILUTIndex);
   L_UINT16      UpdateWindowElement(pDICOMELEMENT pElement, L_UINT uWindowIndex,L_DOUBLE fValue,L_INT nTag);
   L_UINT16      DeleteVOILUTItemElements(pDICOMELEMENT pVOILUTItem,L_INT nTagsToDelete[], L_UINT uTagsCount);
   L_UINT16      InsertVOILUTItemElements(pDICOMELEMENT pVOILUTItem,L_INT nTagsToAdd[],L_UINT uItemCount,L_BOOL bUseVROW);

   //---------------------------------------------------------------------------
   // Internal Overlay Manipulation Functions
   //---------------------------------------------------------------------------
   L_INT    GetOverlayGroupMaskByIndex(L_UINT uOverlayIndex, L_BOOL *pIsActivationLayerOnly);
   L_INT    GetOverlayGroupMaskByIndexActLayer(L_UINT uOverlayIndex);
   L_UINT16 GetOverlayBitmap  (L_UINT uOverlayIndex   ,pBITMAPHANDLE  pBitmap ,L_UINT uStructSize,L_UINT uOverlayFrameIndex,L_UINT uFlags);
   L_UINT16 SetOverlayBitmap  (L_UINT uOverlayIndex   ,pBITMAPHANDLE  pBitmap ,L_UINT uOverlayFrameIndex , L_UINT uFlags);
   L_UINT16 LoadOverlaysIntoBitmap(pBITMAPHANDLE pBitmap,L_UINT uStructSize, L_UINT uImageIndex, L_UINT uFlags);
   L_UINT16 SaveOverlaysFromBitmap(pBITMAPHANDLE pBitmap,L_UINT uFlags);
   L_UINT16 DeleteAllOverlays(L_UINT uFlags);
   
   //---------------------------------------------------------------------------
   // Internal Waveform Functions
   //--------------------------------------------------------------------------- 
   L_UINT16 GetChannelStatusWritten(L_UINT16 uStatus, L_UINT* puIncludedCount, L_CHAR* pszStatusWritten);

   //---------------------------------------------------------------------------
   // Internal Presentation State Functions
   //--------------------------------------------------------------------------- 
   pDICOMELEMENT  GetPresStateImageRefElement(pDICOMELEMENT pRefSeriesSQItem, L_UINT uImageIndex);
   L_VOID         SetTagInstanceNumber(L_INT32 nInstance);
   L_VOID         SetStringTagValue(L_UINT32 uTag, L_TCHAR* pszValue);
   L_BOOL         IsEmptySequence(pDICOMELEMENT pElementSequence);
   L_BOOL         ValidImage(L_TCHAR* pszImageFileName);
   L_BOOL         ValidImage(LDicomDS* pDS);
   L_VOID         GetNewImageInfo(L_CHAR* pszClassUID, L_CHAR* pszInstanceUID, L_CHAR* pszSeriesUID, LDicomDS* pDS);
   L_VOID         GetNewImageInfo(L_CHAR* pszClassUID, L_CHAR* pszInstanceUID, L_CHAR* pszSeriesUID, L_TCHAR* pszImageFileName);
   L_TCHAR*       GetGraphicObjLayerName(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex);
   L_TCHAR*       GetTextObjLayerName(pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex); 
   pDICOMELEMENT  AnnSequenceOfLayer(L_CHAR* pszLayerName);
   pDICOMELEMENT  CopyImageToLayer(pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   L_TCHAR*       GetFirstAnnSequenceLayerName();
   L_TCHAR*       GetAnnSequenceLayerName(pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       RemoveImageRefFromAllAnnotationSequences(L_CHAR* pszSOPInstanceUID);

   L_UINT16       ConvertLEADtoDICOMPoints(pANNPOINT pLeadPoints, pDICOMANNPOINT pDicPoints, L_UINT uLeadPointsCount);
   L_UINT16       ConvertLineObject(HANNOBJECT hLineObj, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertRectangleObject(HANNOBJECT hRectangle, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertEllipseObject(HANNOBJECT hEllipse, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertPolylineObject(HANNOBJECT hPolyLine, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertPolygoneObject(HANNOBJECT hPolygone, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertPointerObject(HANNOBJECT hPointer, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertFreehandObject(HANNOBJECT hFreeHand, pDICOMELEMENT pGraphicAnnSQItem);
   L_INT          GetAnnText(HANNOBJECT hText, L_CHAR* pszAnnText, L_UINT uTextLength);
   L_UINT16       ConvertTextObject(HANNOBJECT hText, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertProtractorObject(HANNOBJECT hProtractor, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertPointObject(HANNOBJECT hPointAnn, pDICOMELEMENT pGraphicAnnSQItem);
   L_UINT16       ConvertInterpolatedLineObject(HANNOBJECT hInterpolatedLine, pDICOMELEMENT pGraphicAnnSQItem, L_BOOL bFillMode);
   L_UINT16       ConvertTextPointerObject(HANNOBJECT hText, pDICOMELEMENT pGraphicAnnSQItem);

#if !defined(FOR_UWP)
   L_UINT16       ConvertDICOMPointIntoLEADObject(pDICOMGRAPHICOBJECT pGraphicObject, pHANNOBJECT phAnnObject, L_INT nDisplayAreaWidth, L_INT nDisplayAreaHeight);
   L_UINT16       ConvertDICOMPolylineIntoLEADObject(pDICOMGRAPHICOBJECT pGraphicObject, pHANNOBJECT phAnnObject, L_INT nDisplayAreaWidth, L_INT nDisplayAreaHeight);   
   L_UINT16       ConvertDICOMEllipseIntoLEADObject(pDICOMGRAPHICOBJECT pGraphicObject, pHANNOBJECT phAnnObject, L_INT nDisplayAreaWidth, L_INT nDisplayAreaHeight);
   L_UINT16       ConvertDICOMCircleIntoLEADObject(pDICOMGRAPHICOBJECT pGraphicObject, pHANNOBJECT phAnnObject, L_INT nDisplayAreaWidth, L_INT nDisplayAreaHeight);
   L_UINT16       ConvertDICOMInterPolatedLineIntoLEADObject(pDICOMGRAPHICOBJECT pGraphicObject, pHANNOBJECT phAnnObject, L_INT nDisplayAreaWidth, L_INT nDisplayAreaHeight);
#endif // #if !defined(FOR_UWP)

   L_UINT16       GetEllipseBounding(pDICOMGRAPHICOBJECT pGraphicObject, L_FLOAT* pfMaxY, L_FLOAT* pfMinY, L_FLOAT* pfMaxX, L_FLOAT* pfMinX);
   L_UINT16       GetCircleRadius(pDICOMGRAPHICOBJECT pGraphicObject, L_FLOAT* pfRadius);
   L_UINT16       GetObjPointsCountBeforeConversion(HANNOBJECT hAnnObject, L_UINT* puPointsCount);   

   L_TCHAR        *GetStringValue    (pDICOMELEMENT pElement, L_UINT32 nIndex);
   L_UINT16       RefreshCharacterSet();

   //****************
   L_VOID         FillRepeatingGroupsModuleElements (pDICOMIOD pModuleIOD ) ;

public:
   // (LEAD's Internal use only)
   L_UINT16      GetFrameBinaryData(pDICOMELEMENT pPixelDataElement,L_INT nFrameIndex,L_UCHAR *pFrameDataBuffer,L_UINT *puFrameDataSize);
private:
   L_UINT16 AutoScaleModalityLUT(pDICOMMLUTATTRIBS pModalityLUTAttributes, pBITMAPHANDLE pBitmap, L_UINT uFlags);
   L_UINT16 GetModalityLUTAttributes(L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes, L_UINT uStructSize, pBITMAPHANDLE pBitmap, L_UINT uFlags);

   L_UINT16 AutoScaleModalityLUT(pDICOMMLUTATTRIBS pModalityLUTAttributes, pBITMAPHANDLE pBitmap, L_INT nOriginalMinGrayValue, L_INT nOriginalMaxGrayValue, L_UINT uFlags);
   L_UINT16 GetModalityLUTAttributes(L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes, L_UINT uStructSize, pBITMAPHANDLE pBitmap, L_INT nOriginalMinGrayValue, L_INT nOriginalMaxGrayValue, L_UINT uFlags);
   L_VOID ModifyImageInfo(L_INT nBppDetectedFromFilter, pIMAGEINFO pInfo);

   friend class LDicomDir;
   friend class CDynamicArray;
   friend class CRleReader;
   friend L_INT InternalLoadFileCB(
      pFILEINFO pInfo, 
      pBITMAPHANDLE pBitmap, 
      L_UCHAR* pBuffer,
      L_UINT uFlags, L_INT nRow, 
      L_INT nLines, 
      L_VOID * pSomeData);


#if !defined(FOR_UWP)
public:
   L_BOOL SetBinaryValue (pDICOMELEMENT pElement, L_HFILE hFile, L_OFFSET nFileOffset, L_UINT32 nLength);
   L_BOOL SetBinaryValue (pDICOMELEMENT pElement, L_HFILE hFile, L_OFFSET nFileOffset, L_UINT32 nLength, L_BOOL bRedirectedFile);
   L_BOOL SetBinaryValue (pDICOMELEMENT pElement, const L_TCHAR* pszFileName);
   L_BOOL RemoveType3EmptyElements();
private:
   L_BOOL InsertFileBinaryValue (pDICOMELEMENT pElement, L_HFILE hFile, L_OFFSET nFileOffset, L_DICOM_OFFSET nOffset, L_UINT32 nLength, L_BOOL bRedirectedFile);
   L_BOOL SetFileBinaryValue (pDICOMELEMENT pElement, L_HFILE hFile, L_OFFSET nFileOffset, L_DICOM_OFFSET nOffset, L_UINT32 nLength, L_BOOL bRedirectedFile);
   L_BOOL StreamFileBinaryValue(L_HFILE hFile, L_OFFSET nFileOffset, LDicomFile *pFile, L_UINT32 nLength, L_UINT16 nVR, L_BOOL bLittleEndian, L_BOOL bRedirectedFile);
   L_BOOL AppendEmptyData(LDicomFile *pFile, L_UINT32 nLength);
#endif
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API HDICOMDS        EXT_FUNCTION L_DicomCreateDS          (L_TCHAR *pszPath);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomFreeDS            (HDICOMDS hDS);

   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomInitDS            (HDICOMDS hDS, L_UINT32 nClass, L_UINT16 nFlags);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomGetInfoDS         (HDICOMDS hDS, L_UINT32 *pnClass, L_UINT16 *pnFlags);

   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomInitCS            (HDICOMDS hDS, L_UINT16 nCommand, L_BOOL bRequest);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomGetInfoCS         (HDICOMDS hDS, L_UINT16 *pnCommand, L_BOOL *pbRequest);

   //---------------------------------------------------------------------------
   // Input and Output Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomLoadDS            (HDICOMDS hDS, L_TCHAR *pszName, L_UINT16 nFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomLoadDSMemory      (HDICOMDS hDS, L_UCHAR *pBuffer, L_UINT32 uBufferSize, L_UINT16 nFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSaveDS            (HDICOMDS hDS, L_TCHAR *pszName, L_UINT16 nFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomCopyDS            (HDICOMDS hDstDS, pDICOMELEMENT pDstParent, HDICOMDS hSrcDS, pDICOMELEMENT pSrcParent);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomCopyDSExt         (HDICOMDS hDstDS, pDICOMELEMENT pDstParent, HDICOMDS hSrcDS, pDICOMELEMENT pSrcParent, COPYDSCALLBACK pfnCallback, L_VOID *pUserData);

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomInsertElement     (HDICOMDS hDS, pDICOMELEMENT pNeighbor, L_BOOL bChild, L_UINT32 nTag, L_UINT16 nVR, L_BOOL bSequence, L_UINT32 nIndex);
   L_LTDIC_API pDICOMMODULE    EXT_FUNCTION L_DicomInsertModule      (HDICOMDS hDS, L_UINT32 nModule, L_BOOL bOptional);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomInsertKey         (HDICOMDS hDS, pDICOMELEMENT pParent, L_TCHAR *pszKey, L_BOOL bOptional);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomInsertBinaryValue (HDICOMDS hDS, pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);

   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomDeleteElement     (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomDeleteModule      (HDICOMDS hDS, L_UINT32 nModule);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomDeleteKey         (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomResetDS           (HDICOMDS hDS);

   //---------------------------------------------------------------------------
   // Iteration Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetRootElement    (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetParentElement  (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetChildElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bVolatile);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetFirstElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetLastElement    (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetPrevElement    (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetNextElement    (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_BOOL bVolatile);
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetLevelElement   (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetCountModule    (HDICOMDS hDS);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomExistsElement     (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomIsVolatileElement (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomConformanceDS     (HDICOMDS hDS, CONFORMANCECALLBACK pfnCallback, L_VOID *pUserData);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomSetDebugDS        (HDICOMDS hDS, CONFORMANCECALLBACK pfnCallback, L_VOID *pUserData);

   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetRootKey        (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetParentKey      (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetChildKey       (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetFirstKey       (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetLastKey        (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetPrevKey        (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomGetNextKey        (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API L_TCHAR*        EXT_FUNCTION L_DicomGetValueKey       (HDICOMDS hDS, pDICOMELEMENT pElement);

   //---------------------------------------------------------------------------
   // Searching Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindFirstElement  (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nTag, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindLastElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nTag, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindFirstDescendant(HDICOMDS hDS, pDICOMELEMENT pParent, L_UINT32 nTag, L_BOOL bNextLevelOnly);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindNextDescendant (HDICOMDS hDS,pDICOMELEMENT pParent, pDICOMELEMENT pElement, L_BOOL bNextLevelOnly);

   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindPrevElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindNextElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMMODULE    EXT_FUNCTION L_DicomFindModule        (HDICOMDS hDS, L_UINT32 nModule);
   L_LTDIC_API pDICOMMODULE    EXT_FUNCTION L_DicomFindIndexModule   (HDICOMDS hDS, L_UINT32 nIndex);

   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindFirstKey      (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *pszKey, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindLastKey       (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *pszKey, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindPrevKey       (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindNextKey       (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomIsBadPixelData    (HDICOMDS hDS,L_UINT32 * pBadCount,L_UINT32 * pGoodCount);

   //---------------------------------------------------------------------------
   // Retrieval Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomGetPreamble       (HDICOMDS hDS, L_UCHAR *pPreamble, L_UINT16 nLength);
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetCountValue     (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomFreeValue         (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomGetBinaryValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_VOID *pValue, L_UINT32 nLength);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomGetBinaryValue2   (HDICOMDS hDS, pDICOMELEMENT pElement, L_VOID *pValue, L_DICOM_OFFSET nOffset, L_UINT32 nLength);
   L_LTDIC_API L_UCHAR*        EXT_FUNCTION L_DicomGetCharValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_INT16*        EXT_FUNCTION L_DicomGetShortValue     (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_INT32*        EXT_FUNCTION L_DicomGetLongValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetLong64Value    (HDICOMDS hDS, pDICOMELEMENT pElement, L_INT64 *pValue, L_UINT32 nIndex,L_UINT32 nCount);
   L_LTDIC_API L_FLOAT*        EXT_FUNCTION L_DicomGetFloatValue     (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_DOUBLE*       EXT_FUNCTION L_DicomGetDoubleValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_CHAR*         EXT_FUNCTION L_DicomGetStringValueA   (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_TCHAR*        EXT_FUNCTION L_DicomGetStringValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API pVALUEAGE       EXT_FUNCTION L_DicomGetAgeValue       (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API pVALUEDATE      EXT_FUNCTION L_DicomGetDateValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);

   L_LTDIC_API L_INT           EXT_FUNCTION L_DicomGetDateRangeValue (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUEDATERANGE pValue);
   L_LTDIC_API L_INT16         EXT_FUNCTION L_DicomGetTimeRangeValue (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUETIMERANGE pValue);
   L_LTDIC_API L_INT16         EXT_FUNCTION L_DicomGetDateTimeRangeValue (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, pVALUEDATETIMERANGE pValue);

   L_LTDIC_API pVALUETIME      EXT_FUNCTION L_DicomGetTimeValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API pVALUEDATETIME  EXT_FUNCTION L_DicomGetDateTimeValue  (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);   
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetConvertValue   (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *Destination, L_UINT32 DestSizeInWords);
   L_LTDIC_API L_UINT32        EXT_FUNCTION L_DicomGetCountImage     (HDICOMDS hDS, pDICOMELEMENT pElement);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetInfoImage      (HDICOMDS hDS, pDICOMELEMENT pElement, pDICOMIMAGE pInfo, L_UINT32 nIndex);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetImage          (HDICOMDS hDS, pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap,L_UINT uStructSize , L_UINT32 nIndex, L_INT32 nBitsPerPixel, L_UINT uFlags, FILEREADCALLBACK pfnCallback, L_VOID *pUserData);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetImageList      (HDICOMDS hDS, pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_UINT32 nCount, L_INT32 nBitsPerPixel, L_UINT uFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetImageListEx    (HDICOMDS hDS, pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_UINT32 nCount, L_INT32 nBitsPerPixel, L_UINT uFlags, GETIMAGECALLBACK pfnCallback, L_VOID *pUserData);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomGetKeepPixelDataIntactFlag(HDICOMDS hDS);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetJ2KOptions( HDICOMDS hDS,pFILEJ2KOPTIONS pOptions, L_INT nSize );
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetDefaultJ2KOptions( HDICOMDS hDS,pFILEJ2KOPTIONS pOptions, L_INT nSize );

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomSetPreamble       (HDICOMDS hDS, L_UCHAR *pPreamble, L_UINT16 nLength);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetBinaryValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_VOID *pValue, L_UINT32 nLength);
#if !defined(FOR_UWP) && !defined(FOR_UNIX)
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetBinaryStream    (HDICOMDS hDS, pDICOMELEMENT pElement, L_HFILE hFile, L_OFFSET nFileOffset, L_UINT32 nLength);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetBinaryFile      (HDICOMDS hDS, pDICOMELEMENT pElement, const L_TCHAR* pszFileName);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomRemoveType3EmptyElements (HDICOMDS hDS);
#endif
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetCharValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_UCHAR *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetShortValue     (HDICOMDS hDS, pDICOMELEMENT pElement, L_INT16 *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetLongValue      (HDICOMDS hDS, pDICOMELEMENT pElement, L_INT32 *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetLong64Value    (HDICOMDS hDS, pDICOMELEMENT pElement, L_INT64* pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetFloatValue     (HDICOMDS hDS, pDICOMELEMENT pElement, L_FLOAT *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetDoubleValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_DOUBLE *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetStringValue    (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *pValue, L_UINT32 nCount, L_UINT32 uCharacterSet);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetStringValue2   (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetAgeValue       (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUEAGE pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetDateValue      (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUEDATE pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetTimeValue      (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUETIME pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetDateTimeValue  (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUEDATETIME pValue, L_UINT32 nCount);

   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetDateRangeValue      (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUEDATERANGE pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetTimeRangeValue      (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUETIMERANGE pValue, L_UINT32 nCount);
   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetDateTimeRangeValue  (HDICOMDS hDS, pDICOMELEMENT pElement, pVALUEDATETIMERANGE pValue, L_UINT32 nCount);

   L_LTDIC_API L_BOOL          EXT_FUNCTION L_DicomSetConvertValue   (HDICOMDS hDS, pDICOMELEMENT pElement, L_TCHAR *strText, L_UINT32 nCount);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomInsertImage       (HDICOMDS hDS, pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_UINT32 nIndex, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor,L_UINT uFlags ,FILESAVECALLBACK pfnCallback, L_VOID *pUserData);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomInsertImageList   (HDICOMDS hDS, pDICOMELEMENT pElement, HBITMAPLIST hList, L_UINT32 nIndex, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor, L_UINT uFlags );
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSetImage          (HDICOMDS hDS, pDICOMELEMENT pElement, pBITMAPHANDLE pBitmap, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor,L_UINT uFlags, FILESAVECALLBACK pfnCallback, L_VOID *pUserData);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSetImageList      (HDICOMDS hDS, pDICOMELEMENT pElement, HBITMAPLIST hList, L_INT32 nCompression, L_INT32 nPhotometric, L_INT32 nBitsPerPixel, L_INT32 nQFactor,L_UINT uFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomDeleteImage       (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT32 nIndex, L_UINT32 nCount);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomChangeTransferSyntax(HDICOMDS hDS, L_TCHAR *pszUID, L_INT32 nQFactor, L_UINT32 uFlags);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomChangeTransferSyntax2(HDICOMDS hDS, L_TCHAR *pszOutfile, L_TCHAR *pszUID, L_INT32 nQFactor, L_UINT32 uFlags, L_UINT16 uSaveFlags);
   L_LTDIC_API L_VOID          EXT_FUNCTION L_DicomSetKeepPixelDataIntactFlag(HDICOMDS hDS, L_BOOL bSet);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSetJ2KOptions(HDICOMDS hDS, const pFILEJ2KOPTIONS pOptions);

   L_LTDIC_API L_INT64 EXT_FUNCTION L_DicomGetElementOffset( HDICOMDS hDS, pDICOMELEMENT pElement);

   //---------------------------------------------------------------------------
   // Overlay Manipulation Functions
   //---------------------------------------------------------------------------

   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetOverlayCount            (HDICOMDS hDS ,L_UINT * pCount);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetOverlayAttributes       (HDICOMDS hDS ,L_UINT uOverlayIndex ,pOVERLAYATTRIBUTES    pOverlayAttributes   ,  L_UINT   uStructSize,L_INT *pGroupNumber,L_BOOL * pIsOverlayInDataset , L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetOverlayActivationLayer  (HDICOMDS hDS ,L_UINT uOverlayIndex ,L_TCHAR *             pActivationLayer     ,  L_UINT   uLength);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetOverlayBitmap           (HDICOMDS hDS ,L_UINT uOverlayIndex ,pBITMAPHANDLE         pBitmap              ,  L_UINT   uStructSize,L_UINT uFlags);   
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetOverlayBitmapList       (HDICOMDS hDS ,L_UINT uOverlayIndex ,HBITMAPLIST           hList                ,  L_UINT32 uOverlayFrameIndex, L_UINT32 uCount,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetOverlayAttributes       (HDICOMDS hDS ,L_UINT uOverlayIndex ,pOVERLAYATTRIBUTES    pOverlayAttributes,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetOverlayBitmap           (HDICOMDS hDS ,L_UINT uOverlayIndex ,pBITMAPHANDLE         pBitmap,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetOverlayBitmapList       (HDICOMDS hDS ,L_UINT uOverlayIndex ,HBITMAPLIST           hList,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeleteOverlay              (HDICOMDS hDS ,L_UINT uOverlayIndex ,L_UINT uFlags);

   
   //---------------------------------------------------------------------------
   // Digital signatures
   //---------------------------------------------------------------------------

   L_LTDIC_API L_UINT32       EXT_FUNCTION L_DicomGetSignaturesCount    (HDICOMDS hDS ,pDICOMELEMENT pItem);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetSignature          (HDICOMDS hDS ,pDICOMELEMENT pItem, L_UINT32 uIndex);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomFindSignature         (HDICOMDS hDS ,const L_TCHAR* pszSignatureUID);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetSignatureUID       (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API pVALUEDATETIME EXT_FUNCTION L_DicomGetSignatureDateTime  (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSaveCertificate       (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem, const L_TCHAR* pszFilename, L_UINT16 uFormat);
   L_LTDIC_API L_UINT32       EXT_FUNCTION L_DicomGetSignedElementsCount(HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetSignedElement      (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem, L_UINT32 uIndex);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetMacTransferSyntax  (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetMacAlgorithm       (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API L_VOID         EXT_FUNCTION L_DicomDeleteSignature       (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomVerifySignature       (HDICOMDS hDS ,pDICOMELEMENT pSignatureItem, L_UINT16 uReserved);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateSignature       (HDICOMDS hDS,
                                                               pDICOMELEMENT  pItem,
                                                               const L_TCHAR*        pszPrivateKeyFile,
                                                               const L_TCHAR*        pszCertificateFile,
                                                               const L_TCHAR*        pszPassword,
                                                               pDICOMELEMENT* ppSignatureItem,
                                                               const L_TCHAR*        pszMacTransferSyntax,
                                                               L_UINT16       uMacAlgorithm,
                                                               L_UINT32*      pElementsToSign,
                                                               L_UINT32       uCount,
                                                               L_UINT16       uSecurityProfile,
                                                               L_UINT16       uReserved);



   //---------------------------------------------------------------------------
   // Waveform Functions
   //---------------------------------------------------------------------------

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetWaveformGroupCount (HDICOMDS hDS );
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetWaveformGroup      (HDICOMDS hDS ,L_UINT32 uIndex, HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeleteWaveformGroup   (HDICOMDS hDS ,L_UINT32 uIndex, L_UINT16 uReserved);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomAddWaveformGroup      (HDICOMDS hDS ,HDICOMWAVEFORMGROUP hDICOMWaveFormGroup, L_UINT16 uFlags, L_UINT32 uIndex);

   
   //---------------------------------------------------------------------------
   // LUT Manipulation Functions
   //---------------------------------------------------------------------------

   //Modality LUT
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetModalityLUTData             (HDICOMDS hDS ,L_UINT16 * pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetModalityLUTAttributes       (HDICOMDS hDS , L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT uStructSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetModalityLUT                 (HDICOMDS hDS ,L_UINT32 uFrameIndex, pDICOMMLUTATTRIBS pModalityLUTAttributes,L_UINT16 *pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeleteModalityLUT              (HDICOMDS hDS ,L_UINT32 uFrameIndex, L_UINT uFlags);

   //Palette Color LUT
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetPaletteColorLUTAttributes   (HDICOMDS hDS ,pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes,L_UINT uStructSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetPaletteColorLUTData         (HDICOMDS hDS ,L_UINT16 * pLUTData,L_UINT uDataSize,DICOMPALETTECOLORLUTTYPE PaletteColorLUTType,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetPaletteColorLUTAttributes   (HDICOMDS hDS ,pDICOMPALCOLORLUTATTRIBS pPaletteColorLUTAttributes,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetPaletteColorLUTData         (HDICOMDS hDS ,L_UINT16 * pLUTData,L_UINT uDataSize,DICOMPALETTECOLORLUTTYPE PaletteColorLUTType,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeletePaletteColorLUT          (HDICOMDS hDS ,L_UINT uFlags);   
   
   // VOI LUT
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetWindowCount                 (HDICOMDS hDS ,L_UINT32 uFrameIndex, L_UINT* pCount);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetWindow                      (HDICOMDS hDS ,L_UINT32 uFrameIndex, L_UINT uWindowIndex ,pDICOMWINDOWATTRIBS pWindowAttributes,  L_UINT uStructSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetWindow                      (HDICOMDS hDS ,L_UINT32 uFrameIndex, L_UINT uWindowIndex ,pDICOMWINDOWATTRIBS pWindowAttributes ,  L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeleteWindow                   (HDICOMDS hDS ,L_UINT32 uFrameIndex, L_UINT uFlags);

   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetVOILUTCount                 (HDICOMDS hDS ,L_UINT * pCount);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetVOILUT                      (HDICOMDS hDS ,L_UINT uVOILUTIndex ,pDICOMVOILUTATTRIBS pVOILUTAttributes ,  L_UINT uStructSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomSetVOILUT                      (HDICOMDS hDS ,L_UINT uVOILUTIndex ,pDICOMVOILUTATTRIBS pVOILUTAttributes ,  L_UINT16 * pLUTData,L_UINT uDataSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomGetVOILUTData                  (HDICOMDS hDS ,L_UINT uVOILUTIndex ,L_UINT16 * pLUTData                      ,  L_UINT uDataSize,L_UINT uFlags);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomDeleteVOILUT                   (HDICOMDS hDS ,L_UINT uFlags);
   
   
   //---------------------------------------------------------------------------
   // Presentation State Functions
   //--------------------------------------------------------------------------- 
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetPresStateInfo(HDICOMDS hDS, pDICOMPRESSTATEINFO pPresState);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetPresStateInfo(HDICOMDS hDS, pDICOMPRESSTATEINFO pPresState, L_UINT uStructSize);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomAddPresStateImageRefByFileName(HDICOMDS hDS, L_TCHAR* pszImageFileName, L_INT32* pFrameNumbers , L_UINT uFramesCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomAddPresStateImageRefByDS(HDICOMDS hDS, HDICOMDS hRefImageDS, L_INT32* FrameNumbers, L_UINT uFramesCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemovePresStateImageRefBySOPInstance(HDICOMDS hDS, L_TCHAR* pszSOPInstanceUID);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllPresStateImageRefs(HDICOMDS hDS);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetPresStateImageRefSOPInstance(HDICOMDS hDS, pDICOMELEMENT pRefSeriesSQItem, L_UINT uImageIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetPresStateImageRefCount(HDICOMDS hDS, pDICOMELEMENT pRefSeriesSQItem, L_UINT* pCount);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomFindFirstPresStateRefSeriesItem(HDICOMDS hDS);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomFindNextPresStateRefSeriesItem(HDICOMDS hDS, pDICOMELEMENT pRefSeriesItem);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetPresStateImageRefBySOPInstance(HDICOMDS hDS, L_TCHAR* pszSOPInstanceUID);      
   //---------------------------------------------------------------------------
   // Graphic Layer Module functions
   //---------------------------------------------------------------------------    
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateLayer(HDICOMDS hDS, pDICOMGRAPHICLAYER pGraphicLayer, L_UINT* pLayerIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerInfo(HDICOMDS hDS, L_UINT uLayerIndex, pDICOMGRAPHICLAYER pGraphicLayer, L_UINT uStructSize);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetLayerInfo(HDICOMDS hDS, L_UINT uLayerIndex, pDICOMGRAPHICLAYER pGraphicLayer);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveLayerByIndex(HDICOMDS hDS, L_UINT uLayerIndex,L_BOOL bAnnSequence);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveLayerByName(HDICOMDS hDS, L_TCHAR* pszLayerName,L_BOOL bAnnSequence);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllLayers(HDICOMDS hDS, L_BOOL bAnnSequence);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerCount(HDICOMDS hDS, L_UINT* pCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerIndex(HDICOMDS hDS, L_TCHAR* pszLayerName, L_INT* pLayerIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerGraphicObjectCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveLayerGraphicObjects(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerTextObjectCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveLayerTextObjects(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetLayerElementByIndex(HDICOMDS hDS, L_UINT uLayerIndex);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetLayerElementByName(HDICOMDS hDS, L_TCHAR* pszLayerName);
   //---------------------------------------------------------------------------
   // Graphic Annotation Module functions 
   //---------------------------------------------------------------------------          
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomFindFirstGraphicAnnSQItem(HDICOMDS hDS);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomFindNextGraphicAnnSQItem(HDICOMDS hDS, pDICOMELEMENT pRefSeriesItem);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetLayerName(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetLayerName(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszLayerName);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateGraphicAnnSQItem(HDICOMDS hDS, L_UINT32 nIndex, L_TCHAR* pszLayerName);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomAddLayerImageRef(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetLayerImageRefCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetLayerImageRefSOPInstance(HDICOMDS hDS,pDICOMELEMENT pGraphicAnnSQItem, L_UINT uImageIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveImageRefFromLayer(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllImageRefsFromLayer(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllImageRefFromAllLayers(HDICOMDS hDS);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetLayerImageRefElement(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_TCHAR* pszImageSOPInstance);
   //---------------------------------------------------------------------------
   // Graphic Annotation Objects functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateGraphicObject(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, pDICOMGRAPHICOBJECT pGraphicObject, L_BOOL bCheckLayer);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveGraphicObject(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetGraphicObjectInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjectIndex, pDICOMGRAPHICOBJECT pGraphicObject, L_UINT uStructSize);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetGraphicObjectInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjectIndex, pDICOMGRAPHICOBJECT pGraphicObject);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetGraphicObjectCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* nCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllGraphicObjects(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetGraphicObjPointCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex, L_UINT* pPointsCount);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetGraphicObjElement(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex);

   //---------------------------------------------------------------------------
   // Compound Graphic functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_TCHAR*       EXT_FUNCTION L_DicomGetCompoundGraphicLayerName(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateCompoundGraphic(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, pDICOMCOMPOUNDGRAPHIC pCompoundGraphicObject, L_BOOL bCheckLayer);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveCompoundGraphic(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uGraphicObjIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetCompoundGraphicInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, pDICOMCOMPOUNDGRAPHIC pCompoundGraphic, L_UINT uStructSize);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetCompoundGraphicInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, pDICOMCOMPOUNDGRAPHIC pCompoundGraphic);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetCompoundGraphicCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllCompoundGraphics(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetCompoundGraphicPointCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, L_UINT* pPointsCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetCompoundGraphicMajorTickCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uCompoundGraphicIndex, L_UINT* pMajorTickCount);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetCompoundGraphicElement(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uIndex);


   //---------------------------------------------------------------------------
   // Text Annotation Objects function
   //---------------------------------------------------------------------------
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomCreateTextObject(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, pDICOMTEXTOBJECT pTextObject, L_BOOL bCheckLayer);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveTextObject(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjIndex);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetTextObjectInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjectIndex, pDICOMTEXTOBJECT pTextObject, L_UINT uStructSize);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomSetTextObjectInfo(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uTextObjectIndex, pDICOMTEXTOBJECT pTextObject);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomGetTextObjectCount(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT* pCount);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomRemoveAllTextObjects(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem);
   L_LTDIC_API pDICOMELEMENT  EXT_FUNCTION L_DicomGetTextObjElement(HDICOMDS hDS, pDICOMELEMENT pGraphicAnnSQItem, L_UINT uObjIndex);

#if !defined(FOR_UWP)
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomConvertLEADAnnObjToDicomAnnObjs(  HDICOMDS hDS,HANNOBJECT hAnnObject,pDICOMELEMENT pGraphicAnnSQItem,pCONVERTLEADANNOBJTODICOMANNPROC pConversionProc,L_VOID* pUserData,L_UINT uFlags);
   L_LTDIC_API L_UINT16       EXT_FUNCTION L_DicomConvertDicomAnnObjToLEADAnnObj(HDICOMDS hDS, pHANNOBJECT phAnnObject, pDICOMGRAPHICOBJECT pGraphicObject, pDICOMTEXTOBJECT pTextObject);
#endif // #if !defined(FOR_UWP)

   //---------------------------------------------------------------------------
   // Private Element methods
   //---------------------------------------------------------------------------
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomCreatePrivateCreatorDataElement     (HDICOMDS hDS, pDICOMELEMENT pElement, L_UINT16 uElementGroup, L_UINT16 uElementNumber, L_TCHAR *pszIdCode, pDICOMELEMENT *ppPrivateCreatorDataElement);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetNextUnusedPrivateTag             (HDICOMDS hDS, pDICOMELEMENT pPrivateCreatorDataElement, L_UINT32 *puTag);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindFirstPrivateCreatorDataElement  (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_TCHAR *pszIdCode, L_UINT16 uElementGroup);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindNextPrivateCreatorDataElement   (HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bTree, L_TCHAR *pszIdCode, L_UINT16 uElementGroup);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindFirstPrivateElement             (HDICOMDS hDS, pDICOMELEMENT pPrivateCreatorDataElement);
   L_LTDIC_API pDICOMELEMENT   EXT_FUNCTION L_DicomFindNextPrivateElement              (HDICOMDS hDS, pDICOMELEMENT pElement, pDICOMELEMENT pPrivateCreatorDataElement);

   //---------------------------------------------------------------------------
   // Encapsulate Document Functions
   //---------------------------------------------------------------------------
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetEncapsulatedDocument(HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bChild, L_TCHAR *pszFileDocument, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSetEncapsulatedDocument(HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bChild, L_TCHAR *pszFileDocument, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);

   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomGetEncapsulatedDocumentMemory(HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bChild, L_UCHAR *pBuffer, L_UINT32 *puBufferSize, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomSetEncapsulatedDocumentMemory(HDICOMDS hDS, pDICOMELEMENT pElement, L_BOOL bChild, L_UCHAR *pBuffer, L_UINT32 uBufferSize, pDICOMENCAPSULATEDDOCUMENT pEncapsulatedDocument, pDICOMCODESEQUENCEITEM pConceptNameCodeSequence);

   //---------------------------------------------------------------------------
   // Annotation Functions
   //---------------------------------------------------------------------------
#if !defined(FOR_MANAGED) && !defined(FOR_UWP)
   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomAnnSave           (HDICOMDS hDS,
                                                          HANNOBJECT      hAnnContainer,
                                                          L_UINT          uFormat,
                                                          L_BOOL          bSelected,
                                                          pSAVEFILEOPTION pSaveOption,
                                                          L_INT           nIndex,
                                                          L_UINT32       *pnPrivateCreatorTag
                                                          );

   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomAnnLoad           (HDICOMDS hDS,
                                                          pHANNOBJECT     phAnnContainer,
                                                          L_INT           nIndex,
                                                          pLOADFILEOPTION pLoadOptions
                                                          );


   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomAnnCount         (HDICOMDS hDS, L_INT *pFileIndices, L_UINT32 *pnPrivateCreatorTag);

   L_LTDIC_API L_UINT16        EXT_FUNCTION L_DicomAnnDelete        (HDICOMDS hDS, L_INT nIndex, L_INT nPage ); //nIndex: Pass -1 to delete the LEAD Private tag and all files
                                                                                                    //nPage:   Pass -1 to delete the entire file
                                                                                                    //         Pass >0 to delete the page

   L_LTDIC_API L_TCHAR*        EXT_FUNCTION  L_DicomGetDefaultDicomTempPath();
   L_LTDIC_API L_VOID          EXT_FUNCTION  L_DicomSetDefaultDicomTempPath(L_TCHAR* szPath);
#endif // #if !defined(FOR_MANAGED) && !defined(FOR_UWP)
#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

//============= CLASS ==========================================================
// Channel Status (003A,0205)
#define DICOM_CHANNEL_STATUS_OK             0x01
#define DICOM_CHANNEL_STATUS_TEST_DATA      0x02
#define DICOM_CHANNEL_STATUS_DISCONNECTED   0x04
#define DICOM_CHANNEL_STATUS_QUESTIONABLE   0x08
#define DICOM_CHANNEL_STATUS_INVALID        0x10
#define DICOM_CHANNEL_STATUS_UNCALIBRATED   0x20
#define DICOM_CHANNEL_STATUS_UNZEROED       0x40

// Waveform Sample Interpretation (5400,1006)
#define DICOM_SAMPLE_INTERPRETATION_SS   0
#define DICOM_SAMPLE_INTERPRETATION_US   1
#define DICOM_SAMPLE_INTERPRETATION_SB   2
#define DICOM_SAMPLE_INTERPRETATION_UB   3
#define DICOM_SAMPLE_INTERPRETATION_MB   4
#define DICOM_SAMPLE_INTERPRETATION_AB   5

// Waveform Originality (003A,0004)
#define DICOM_WAVEFORM_ORIGINALITY_ORIGINAL   0
#define DICOM_WAVEFORM_ORIGINALITY_DERIVED    1

// Temporal Range Type (0040,A130)
#define DICOM_TEMPORAL_RANGE_TYPE_UNDEFINED        0
#define DICOM_TEMPORAL_RANGE_TYPE_POINT            1
#define DICOM_TEMPORAL_RANGE_TYPE_MULTIPOINT       2
#define DICOM_TEMPORAL_RANGE_TYPE_SEGMENT          3
#define DICOM_TEMPORAL_RANGE_TYPE_MULTISEGMENT     4
#define DICOM_TEMPORAL_RANGE_TYPE_BEGIN            5
#define DICOM_TEMPORAL_RANGE_TYPE_END              6



// Waveform Annotation
typedef struct tagDICOMWAVEFORMANNOTATION
{
   L_UINT uStructSize;
   
   // Annotation Value
   L_TCHAR*               pszUnformattedTextValue;
   pDICOMCODESEQUENCEITEM pCodedName;
   pDICOMCODESEQUENCEITEM pCodedValue;
   L_DOUBLE*              pNumericValue;
   L_UINT32               uNumericValueCount;
   pDICOMCODESEQUENCEITEM pMeasurementUnits;
   
   // Annotation Temporal Range
   L_UINT16       uTemporalRangeType;
   L_UINT32*      pRefSamplePositions;
   L_DOUBLE*      pRefTimeOffsets;
   pVALUEDATETIME pRefDatetime;
   L_UINT32       uTemporalPointCount;
   
   L_UINT16*      puAnnGroupNumber;
   
} DICOMWAVEFORMANNOTATION, * pDICOMWAVEFORMANNOTATION;


#if defined(__cplusplus)
class L_LTDIC_CLASS LDicomWaveformGroup;

class L_LTDIC_CLASS LDicomWaveformChannel
{
   public:
   LDicomWaveformChannel();
   virtual ~LDicomWaveformChannel();
   
   LDicomWaveformGroup* GetWaveformGroup();
   L_UINT32 GetIndex();
   
   L_UINT32 SetChannelSamples8(L_UCHAR* pSamples, L_UINT32 uCount);
   L_UINT32 SetChannelSamples16(L_INT16* pSamples, L_UINT32 uCount);
   L_UINT32 SetChannelSamples32(L_INT32* pSamples, L_UINT32 uCount);
   L_INT32* GetChannelSamples(L_UINT32* puNumberOfSamples);
   
   L_UINT16 SetChannelSource(pDICOMCODESEQUENCEITEM pChannelSource);
   pDICOMCODESEQUENCEITEM GetChannelSource();
   L_UINT16 SetChannelSensitivity(L_BOOL bInclude,
                                  L_DOUBLE dChannelSensitivity,
                                  pDICOMCODESEQUENCEITEM pChannelSensitivityUnits,
                                  L_DOUBLE dChannelSensitivityCF = 1.0,
                                  L_DOUBLE dChannelBaseline = 0.0);
   L_UINT16 GetChannelSensitivity(L_BOOL* pbIncluded,
                                  L_DOUBLE* pdChannelSensitivity,
                                  pDICOMCODESEQUENCEITEM pChannelSensitivityUnits,
                                  L_UINT uStructSize,
                                  L_DOUBLE* pdChannelSensitivityCF,
                                  L_DOUBLE* pdChannelBaseline);
   L_VOID   SetChannelStatus(L_UINT16 uStatus);
   L_UINT16 GetChannelStatus();
   L_BOOL   SetChannelTimeSkew(L_DOUBLE dTimeSkew);
   L_BOOL   GetChannelTimeSkew(L_DOUBLE* pdTimeSkew);
   L_BOOL   SetChannelSampleSkew(L_DOUBLE dSampleSkew);
   L_BOOL   GetChannelSampleSkew(L_DOUBLE* pdSampleSkew);
   
   L_BOOL   SetWaveformChannelNumber(L_BOOL bInclude, L_INT32 nChannelNumber);
   L_BOOL   GetWaveformChannelNumber(L_INT32* pnChannelNumber);
   L_BOOL   SetChannelLabel(L_TCHAR* pszLabel);
   L_TCHAR* GetChannelLabel();
   L_BOOL   SetChannelOffset(L_BOOL bInclude, L_DOUBLE dChannelOffset);
   L_BOOL   GetChannelOffset(L_DOUBLE* pdChannelOffset);
   L_BOOL   SetFilterLowFrequency(L_BOOL bInclude, L_DOUBLE dLowFrequency);
   L_BOOL   GetFilterLowFrequency(L_DOUBLE* pdLowFrequency);
   L_BOOL   SetFilterHighFrequency(L_BOOL bInclude, L_DOUBLE dHighFrequency);
   L_BOOL   GetFilterHighFrequency(L_DOUBLE* pdHighFrequency);
   L_BOOL   SetNotchFilterFrequency(L_BOOL bInclude, L_DOUBLE dFrequency);
   L_BOOL   GetNotchFilterFrequency(L_DOUBLE* pdFrequency);
   L_BOOL   SetNotchFilterBandwidth(L_BOOL bInclude, L_DOUBLE dBandwidth);
   L_BOOL   GetNotchFilterBandwidth(L_DOUBLE* pdBandwidth);
   L_BOOL   SetChannelMinimumValue(L_BOOL bInclude, L_INT32 nMinValue);
   L_BOOL   GetChannelMinimumValue(L_INT32* pnMinValue);
   L_BOOL   SetChannelMaximumValue(L_BOOL bInclude, L_INT32 nMaxValue);
   L_BOOL   GetChannelMaximumValue(L_INT32* pnMaxValue);
   
   // Annotations
   L_UINT32 GetAnnotationCount();
   pDICOMWAVEFORMANNOTATION GetAnnotation(L_UINT32 uIndex);
   L_UINT16 AddAnnotation(pDICOMWAVEFORMANNOTATION pAnnotation);
   L_UINT32 DeleteAnnotation(L_UINT32 uIndex);
   
private:
   class CWaveformAnnotation
   {
   public:
      CWaveformAnnotation()
      {
         m_pItem = NULL;
         m_pNextAnnotation = NULL;

         m_Annotation.uStructSize = sizeof(DICOMWAVEFORMANNOTATION);
         m_Annotation.pszUnformattedTextValue = NULL;
         m_Annotation.pCodedName = NULL;
         m_Annotation.pCodedValue = NULL;
         m_Annotation.pNumericValue = NULL;
         m_Annotation.uNumericValueCount = 0;
         m_Annotation.pMeasurementUnits = NULL;
         m_Annotation.uTemporalRangeType = 0;
         m_Annotation.pRefSamplePositions = NULL;
         m_Annotation.pRefTimeOffsets = NULL;
         m_Annotation.pRefDatetime = NULL;
         m_Annotation.uTemporalPointCount = 0;
         m_Annotation.puAnnGroupNumber = NULL;
      }
      
      DICOMWAVEFORMANNOTATION m_Annotation;
      pDICOMELEMENT           m_pItem;
      CWaveformAnnotation*    m_pNextAnnotation;
   };
   
   LDicomWaveformGroup*  m_pParentGroup;
   L_INT32*              m_piChannelSamples;
   L_UINT32              m_uChannelIndex;
   L_UINT16              m_uChannelStatus;
   DICOMCODESEQUENCEITEM m_ChannelSource;
   LDicomDS              m_ChannelDS;
   CWaveformAnnotation*  m_pAnnotations;
   
   L_VOID FreeChannelSource();
   L_BOOL SetCodeSequenceItem(pDICOMELEMENT pAnnotationItem,
                              L_UINT32 uCodeSequenceTag,
                              pDICOMCODESEQUENCEITEM pDstItem,
                              pDICOMCODESEQUENCEITEM pSrcItem);
   
   friend class LDicomWaveformGroup;
};
#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)
   
   L_LTDIC_API HDICOMWAVEFORMCHANNEL       EXT_FUNCTION L_DicomChannelCreate(L_VOID);
   L_LTDIC_API L_VOID                      EXT_FUNCTION L_DicomChannelFree(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API HDICOMWAVEFORMGROUP         EXT_FUNCTION L_DicomChannelGetWaveformGroup (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelGetIndex (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelSetSamples8(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_UCHAR* pSamples, L_UINT32 uCount);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelSetSamples16(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_INT16* pSamples, L_UINT32 uCount);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelSetSamples32(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_INT32* pSamples, L_UINT32 uCount);
   L_LTDIC_API L_INT32*                    EXT_FUNCTION L_DicomChannelGetSamples(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_UINT32* puNumberOfSamples);
   L_LTDIC_API L_UINT16                    EXT_FUNCTION L_DicomChannelSetSource (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,pDICOMCODESEQUENCEITEM pChannelSource);
   L_LTDIC_API pDICOMCODESEQUENCEITEM      EXT_FUNCTION L_DicomChannelGetSource (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API L_UINT16                    EXT_FUNCTION L_DicomChannelSetSensitivity (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude,L_DOUBLE dChannelSensitivity,pDICOMCODESEQUENCEITEM pChannelSensitivityUnits,L_DOUBLE dChannelSensitivityCF ,L_DOUBLE dChannelBaseline);
   L_LTDIC_API L_UINT16                    EXT_FUNCTION L_DicomChannelGetSensitivity (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL* pbIncluded,L_DOUBLE* pdChannelSensitivity,pDICOMCODESEQUENCEITEM pChannelSensitivityUnits,L_UINT uStructSize,L_DOUBLE* pdChannelSensitivityCF,L_DOUBLE* pdChannelBaseline);
   L_LTDIC_API L_VOID                      EXT_FUNCTION L_DicomChannelSetStatus (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_UINT16 uStatus);
   L_LTDIC_API L_UINT16                    EXT_FUNCTION L_DicomChannelGetStatus (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetTimeSkew(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE dTimeSkew);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetTimeSkew(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdTimeSkew);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetSampleSkew(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE dSampleSkew);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetSampleSkew(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdSampleSkew);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetNumber (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_INT32 nChannelNumber);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetNumber (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_INT32* pnChannelNumber);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetLabel(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_TCHAR* pszLabel);
   L_LTDIC_API L_TCHAR*                    EXT_FUNCTION L_DicomChannelGetLabel(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetOffset (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_DOUBLE dChannelOffset);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetOffset (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdChannelOffset);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetFilterLowFrequency (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_DOUBLE dLowFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetFilterLowFrequency (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdLowFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetFilterHighFrequency(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_DOUBLE dHighFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetFilterHighFrequency(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdHighFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetNotchFilterFrequency(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_DOUBLE dFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetNotchFilterFrequency(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdFrequency);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetNotchFilterBandwidth(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_DOUBLE dBandwidth);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetNotchFilterBandwidth(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_DOUBLE* pdBandwidth);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetMinimumValue(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_INT32 nMinValue);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetMinimumValue(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_INT32* pnMinValue);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelSetMaximumValue(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_BOOL bInclude, L_INT32 nMaxValue);
   L_LTDIC_API L_BOOL                      EXT_FUNCTION L_DicomChannelGetMaximumValue(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_INT32* pnMaxValue);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelGetAnnotationCount(HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel);
   L_LTDIC_API pDICOMWAVEFORMANNOTATION    EXT_FUNCTION L_DicomChannelGetAnnotation (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_UINT32 uIndex);
   L_LTDIC_API L_UINT16                    EXT_FUNCTION L_DicomChannelAddAnnotation (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,pDICOMWAVEFORMANNOTATION pAnnotation);
   L_LTDIC_API L_UINT32                    EXT_FUNCTION L_DicomChannelDeleteAnnotation (HDICOMWAVEFORMCHANNEL hDICOMWaveFormChannel,L_UINT32 uIndex);


#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)


//============= CLASS ==========================================================
#if defined(__cplusplus)
class L_LTDIC_CLASS LDicomWaveformGroup
{
   public:
   LDicomWaveformGroup();
   virtual ~LDicomWaveformGroup();
   
   L_VOID   Reset();
   
   L_UINT32 GetNumberOfChannels();
   LDicomWaveformChannel* GetChannel(L_UINT32 uIndex);
   LDicomWaveformChannel* AddChannel(L_UINT32 uIndex = ELEMENT_INDEX_MAX);
   L_UINT32 DeleteChannel(L_UINT32 uIndex);
   L_BOOL   SetNumberOfSamplesPerChannel(L_UINT32 uNumberOfSamples);
   L_UINT32 GetNumberOfSamplesPerChannel();
   L_VOID   SetSamplingFrequency(L_DOUBLE dFrequency);
   L_DOUBLE GetSamplingFrequency();
   L_BOOL   SetSampleInterpretation(L_UINT16 uInterpretation);
   L_UINT16 GetSampleInterpretation();
   
   L_BOOL   SetMultiplexGroupTimeOffset(L_BOOL bInclude, L_DOUBLE dOffset);
   L_BOOL   GetMultiplexGroupTimeOffset(L_DOUBLE* pdOffset);
   L_BOOL   SetTriggerTimeOffset(L_BOOL bInclude, L_DOUBLE dOffset);
   L_BOOL   GetTriggerTimeOffset(L_DOUBLE* pdOffset);
   L_BOOL   SetTriggerSamplePosition(L_BOOL bInclude, L_UINT32 uSamplePosition);
   L_BOOL   GetTriggerSamplePosition(L_UINT32* puSamplePosition);
   L_VOID   SetWaveformOriginality(L_UINT16 uOriginality);
   L_UINT16 GetWaveformOriginality();
   L_BOOL   SetMultiplexGroupLabel(L_TCHAR* pszLabel);
   L_TCHAR* GetMultiplexGroupLabel();
   L_BOOL   SetWaveformPaddingValue(L_BOOL bInclude, L_INT32 nPaddingValue);
   L_BOOL   GetWaveformPaddingValue(L_INT32* pnPaddingValue);
#if !defined(FOR_UWP)
   L_UINT16 LoadAudio(L_TCHAR* pszFilename, L_UINT16 uFlags = 0);
   L_UINT16 SaveAudio(L_TCHAR* pszFilename, L_UINT16 uFlags = 0);
#endif // #if !defined(FOR_UWP)
   
private:
   struct CHANNEL
   {
      LDicomWaveformChannel m_Channel;
      CHANNEL*              m_pNextChannel;
   };
   
   struct WAVEDATA
   {
      L_CHAR*  pData;
      L_UINT32 uDataLength;
   };
   
   CHANNEL* m_pChannels;
   LDicomDS m_GroupDS;
   L_UINT32 m_uSamplesPerChannelCount;
   L_DOUBLE m_dSamplingFrequency;
   L_UINT16 m_uInterpretation;
   L_UINT16 m_uOriginality;
   
   L_BOOL   IsChangeAllowed(L_UINT16 uNewInterpretation, L_UINT* puConversionType);
   L_VOID   UpdateIndexes();
   L_UINT16 ConvertWaveData(L_UINT16 nConversionType, L_VOID* pOldData, L_CHAR* pNewData, L_UINT32 uDataLength, L_BOOL b16BitData = TRUE);
   L_UCHAR  Linear2Alaw(L_INT16 iVal);
   L_UCHAR  Linear2Ulaw(L_INT16 iVal);
   L_INT16  Alaw2Linear(L_UCHAR byVal);
   L_INT16  Ulaw2Linear(L_UCHAR byVal);
   L_UCHAR  Alaw2Ulaw(L_UCHAR byVal);
   L_UCHAR  Ulaw2Alaw(L_UCHAR byVal);
};
#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)
   L_LTDIC_API HDICOMWAVEFORMGROUP     EXT_FUNCTION L_DicomWaveGrpCreate(L_VOID);
   L_LTDIC_API L_VOID                  EXT_FUNCTION L_DicomWaveGrpFree(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_VOID                  EXT_FUNCTION L_DicomWaveGrpReset(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_UINT32                EXT_FUNCTION L_DicomWaveGrpGetNumberOfChannels(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API HDICOMWAVEFORMCHANNEL   EXT_FUNCTION L_DicomWaveGrpGetChannel  (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT32 uIndex);
   L_LTDIC_API HDICOMWAVEFORMCHANNEL   EXT_FUNCTION L_DicomWaveGrpAddChannel  (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT32 uIndex);
   L_LTDIC_API L_UINT32                EXT_FUNCTION L_DicomWaveGrpDeleteChannel(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT32 uIndex);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetNumberOfSamplesPerChannel(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT32 uNumberOfSamples);
   L_LTDIC_API L_UINT32                EXT_FUNCTION L_DicomWaveGrpGetNumberOfSamplesPerChannel(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_VOID                  EXT_FUNCTION L_DicomWaveGrpSetSamplingFrequency   (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_DOUBLE dFrequency);
   L_LTDIC_API L_DOUBLE                EXT_FUNCTION L_DicomWaveGrpGetSamplingFrequency   (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetSampleInterpretation(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT16 uInterpretation);
   L_LTDIC_API L_UINT16                EXT_FUNCTION L_DicomWaveGrpGetSampleInterpretation(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetMultiplexGroupTimeOffset (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_BOOL bInclude, L_DOUBLE dOffset);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpGetMultiplexGroupTimeOffset (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_DOUBLE* pdOffset);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetTriggerTimeOffset   (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_BOOL bInclude, L_DOUBLE dOffset);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpGetTriggerTimeOffset   (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_DOUBLE* pdOffset);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetTriggerSamplePosition    (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_BOOL bInclude, L_UINT32 uSamplePosition);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpGetTriggerSamplePosition    (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT32* puSamplePosition);
   L_LTDIC_API L_VOID                  EXT_FUNCTION L_DicomWaveGrpSetOriginality (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_UINT16 uOriginality);
   L_LTDIC_API L_UINT16                EXT_FUNCTION L_DicomWaveGrpGetOriginality (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetMultiplexGroupLabel (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_TCHAR* pszLabel);
   L_LTDIC_API L_TCHAR*                EXT_FUNCTION L_DicomWaveGrpGetMultiplexGroupLabel (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpSetPaddingValue(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_BOOL bInclude, L_INT32 nPaddingValue);
   L_LTDIC_API L_BOOL                  EXT_FUNCTION L_DicomWaveGrpGetPaddingValue(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_INT32* pnPaddingValue);
#if !defined(FOR_UWP)
   L_LTDIC_API L_UINT16                EXT_FUNCTION L_DicomWaveGrpLoadAudio(HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_TCHAR* pszFilename, L_UINT16 uFlags);
   L_LTDIC_API L_UINT16                EXT_FUNCTION L_DicomWaveGrpSaveAudio (HDICOMWAVEFORMGROUP hDICOMWaveFormGroup,L_TCHAR* pszFilename, L_UINT16 uFlags);
#endif // #if !defined(FOR_UWP)

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)
#endif // #if !defined (EXCLUDE_DICOM_FUNCTIONS)

#if !defined(FOR_UWP)
#if !defined (EXCLUDE_DICOM_FUNCTIONS)
//============= CLASS ==========================================================
// Directory options structure
typedef struct tagDICOMDIROPTIONS
{
   L_INT    nSize;
   L_BOOL   bIncludeSubfolders;
   L_UINT32 uFlags;

} DICOMDIROPTIONS, * pDICOMDIROPTIONS;

// Flags of the Directory options structure
#define DICOMDIR_REJECT_INVALID_FILEID          0x01
#define DICOMDIR_INSERT_ICON_IMAGE_SEQUENCE     0x02

// A status code
#define DICOMDIR_INSERTDICOMFILE_PREADD   300
#define DICOMDIR_INSERTDICOMFILE_FAILURE  350

typedef L_UINT16 (pEXT_CALLBACK INSERTDICOMFILECALLBACK)(HDICOMDIR hDicomDir, const L_TCHAR* pszFileName, HDICOMDS hDS, L_UINT16 uStatus, L_VOID* pUserData);
typedef struct _DICOMDIRCALLBACK
{
   INSERTDICOMFILECALLBACK pfnInsertDicomFile;
   L_VOID                  *pUserData;
} DICOMDIRCALLBACK, *pDICOMDIRCALLBACK;

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomDir : public LDicomDS
{
public:

   //---------------------------------------------------------------------------
   // Initializing Functions
   //---------------------------------------------------------------------------
   LDicomDir(L_TCHAR* pszDICOMDIRDstFolder = NULL, L_TCHAR* pszPath = NULL);
   virtual ~LDicomDir();
    
   //---------------------------------------------------------------------------
   // Input and Output Functions
   //---------------------------------------------------------------------------
   L_UINT16 LoadDS(L_TCHAR* pszName, L_UINT16 nFlags);
   L_UINT16 SaveDicomDir(L_UINT16 uFlags = 0);   
   //---------------------------------------------------------------------------
   // Deletion Functions
   //---------------------------------------------------------------------------
   L_UINT16 ResetDicomDir(const L_TCHAR* pszDICOMDIRDstFolder);

   //---------------------------------------------------------------------------
   // Insertion Functions
   //---------------------------------------------------------------------------
   L_UINT16 InsertDicomFile(L_TCHAR* pszFileName);
   L_UINT16 InsertDicomDS(LDicomDS& DataSet, L_TCHAR* pszFileName);

   //---------------------------------------------------------------------------
   // Modification Functions
   //---------------------------------------------------------------------------
   L_UINT16 SetFileSetID(L_TCHAR* pszFileSetID);
   L_UINT16 SetDescriptorFile(L_TCHAR* pszFileName, L_TCHAR* pszCharSet);
   L_UINT16 SetOptions(const pDICOMDIROPTIONS pOptions);

   //---------------------------------------------------------------------------
   // Retrieval Functions
   //---------------------------------------------------------------------------
   L_UINT16 GetOptions(pDICOMDIROPTIONS pOptions, L_INT nSize) const;

   //---------------------------------------------------------------------------
   // Overridables
   //---------------------------------------------------------------------------   
   virtual L_UINT16 OnInsertDicomFile(const L_TCHAR* pszFileName,
                                      LDicomDS* pDataSet,
                                      L_UINT16 uStatus);

   //---------------------------------------------------------------------------
   // Private Functions (Internal use only)
   //---------------------------------------------------------------------------
   L_VOID           SetCallback(pDICOMDIRCALLBACK pCallback);

   //---------------------------------------------------------------------------
   // Private
   //---------------------------------------------------------------------------
private:
   L_TCHAR*        m_pszDICOMDIRDstFolder;
   DICOMDIROPTIONS m_Options;
   L_BOOL          m_bEnableSearchFolder;

   DICOMDIRCALLBACK m_Callback;


   pDICOMELEMENT FindDirectoryRecord(pDICOMELEMENT pReferencingDR, L_INT nDRType,
                                     const L_TCHAR* pszIdentifier);
   L_VOID        SetSelectionKey(pDICOMELEMENT pDR, LDicomDS& DataSet, L_UINT32 uTag,
                                 L_UINT16 uVR, L_BOOL bEnableDelete = FALSE);
   L_VOID        DeleteDRElement(pDICOMELEMENT pDR, L_UINT32 uTag);
   L_UINT16      GetRelativePath(const L_TCHAR* pszFileName, L_TCHAR** ppszFName) const;
   L_BOOL        CheckFileID(const L_TCHAR* pszFileID) const;
   L_VOID        ResetOptions();
   L_UINT16      SearchFolder(const L_TCHAR* pszFolderName, L_BOOL bIncludeSubfolders);
   L_UINT16      InsertIconImageSequence(pDICOMELEMENT pImageKey, LDicomDS& SourceDataSet);
   L_BOOL        IsDataSetAlreadyPresent(LDicomDS &ds);
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)
   L_LTDIC_API HDICOMDIR   EXT_FUNCTION L_DicomDirCreate(L_TCHAR* pszDICOMDIRDstFolder, L_TCHAR* pszPath);
   L_LTDIC_API L_VOID      EXT_FUNCTION L_DicomDirFree(HDICOMDIR hDicomDir);
   L_LTDIC_API L_VOID      EXT_FUNCTION L_DicomDirSetCallback(HDICOMDIR hDicomDir, pDICOMDIRCALLBACK pCallback);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirLoadDS(HDICOMDIR hDicomDir, L_TCHAR* pszName, L_UINT16 nFlags);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirSave(HDICOMDIR hDicomDir, L_UINT16 uFlags);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirReset(HDICOMDIR hDicomDir, L_TCHAR* pszDICOMDIRDstFolder);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirInsertFile(HDICOMDIR hDicomDir, L_TCHAR* pszFileName);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirInsertDS(HDICOMDIR hDicomDir, HDICOMDS* phDataSet, L_TCHAR* pszFileName);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirSetFileSetID(HDICOMDIR hDicomDir, L_TCHAR* pszFileSetID);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirSetDescriptorFile(HDICOMDIR hDicomDir, L_TCHAR* pszFileName, L_TCHAR* pszCharSet);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirSetOptions(HDICOMDIR hDicomDir, pDICOMDIROPTIONS pOptions);
   L_LTDIC_API L_UINT16    EXT_FUNCTION L_DicomDirGetOptions(HDICOMDIR hDicomDir, pDICOMDIROPTIONS pOptions, L_INT nSize);
#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)
#endif //!defined(FOR_UWP)

//============= CLASS ==========================================================

#define PDU_UNKNOWN                     0x00

#define PDU_ASSOCIATE_REQUEST           0x01
#define PDU_ASSOCIATE_ACCEPT            0x02
#define PDU_ASSOCIATE_REJECT            0x03
#define PDU_DATA_TRANSFER               0x04
#define PDU_RELEASE_REQUEST             0x05
#define PDU_RELEASE_RESPONSE            0x06
#define PDU_ABORT                       0x07

#define PDU_ROLE_NON_SUPPORT               0
#define PDU_ROLE_SUPPORT                   1

#define PDU_MAX_UID_SIZE                  64
#define PDU_MAX_TITLE_SIZE                64
#define PDU_MAX_VERSION_SIZE              16
#define PDU_MIN_MAXIMUM_LENGTH             8

// Associate Accept
#define PDU_ACCEPT_RESULT_SUCCESS           0  // Acceptance
#define PDU_ACCEPT_RESULT_USER_REJECT       1  // User rejection
#define PDU_ACCEPT_RESULT_PROVIDER_REJECT   2  // No reason (provider rejection)
#define PDU_ACCEPT_RESULT_ABSTRACT_SYNTAX   3  // Abstract syntax not supported (provider rejection)
#define PDU_ACCEPT_RESULT_TRANSFER_SYNTAX   4  // Transfer syntaxes not supported (provider rejection)

// Associate Reject
#define PDU_REJECT_RESULT_PERMANENT         1  // Rejected permanent
#define PDU_REJECT_RESULT_TRANSIENT         2  // Rejected transient

#define PDU_REJECT_SOURCE_USER              1  // DICOM UL service-user
#define PDU_REJECT_SOURCE_PROVIDER1         2  // DICOM UL service-provider (ASCE related function)
#define PDU_REJECT_SOURCE_PROVIDER2         3  // DICOM UL service-provider (Presentation related function)

#define PDU_REJECT_REASON_UNKNOWN           1  // No reason given (User - Provider1)
#define PDU_REJECT_REASON_APPLICATION       2  // Application context name not supported (User)
#define PDU_REJECT_REASON_CALLING           3  // Calling AE Title not recognized (User)
#define PDU_REJECT_REASON_CALLED            7  // Called AE Title not recognized (User)

#define PDU_REJECT_REASON_VERSION           2  // Protocol version not supported (Provider1)

#define PDU_REJECT_REASON_CONGESTION        1  // Temporary congestion (Provider2)
#define PDU_REJECT_REASON_LIMIT             2  // Local limit exceeded (Provider2)

// Abort
#define PDU_ABORT_SOURCE_USER               0  // Service user
#define PDU_ABORT_SOURCE_PROVIDER           2  // Service provider

#define PDU_ABORT_REASON_UNKNOWN            0  // Reason no specified (Provider)
#define PDU_ABORT_REASON_UNRECOGNIZED       1  // Unrecognized PDU (Provider)
#define PDU_ABORT_REASON_UNEXPECTED         2  // Unexpected PDU (Provider)
#define PDU_ABORT_REASON_UNRECOGNIZED_PARAM 4  // Unrecognized PDU parameter (Provider)
#define PDU_ABORT_REASON_UNEXPECTED_PARAM   5  // Unexpected PDU parameter (Provider)
#define PDU_ABORT_REASON_INVALID_PARAM      6  // Invalid PDU parameter value (Provider)

//============= CLASS ==========================================================
#if defined(__cplusplus)

#if !defined (EXCLUDE_DICOM_FUNCTIONS)
#if !defined(EXCLUDE_DICOM_NET)
class L_LTDIC_CLASS LDicomAssociate
{
public:
   LDicomAssociate(L_BOOL bRequest);
   ~LDicomAssociate();

   L_VOID    Reset                  (L_BOOL bRequest);
   L_VOID    Default                ();

   L_BOOL    IsRequest              ();
   L_VOID    SetRequest             (L_BOOL bRequest);

   L_UINT16  GetVersion             ();
   L_INT     SetVersion             (L_UINT16 nVersion);

   L_VOID    GetCalled              (L_TCHAR *strCalled, L_UINT32 SizeInWords);
   L_INT     SetCalled              (L_TCHAR *pszName);

   L_VOID    GetCalling             (L_TCHAR *strCalling, L_UINT32 SizeInWords);
   L_INT     SetCalling             (L_TCHAR *pszName);

   L_VOID    GetApplication         (L_TCHAR *strApplication, L_UINT32 SizeInWords);
   L_INT     SetApplication         (L_TCHAR *pszUID);

   L_INT     GetPresentationCount   ();
   L_UCHAR   GetPresentation        (L_INT nIndex);
   L_INT     SetPresentation        (L_INT nIndex, L_UCHAR nID);
   L_INT     AddPresentation        (L_UCHAR nID, L_UCHAR nResult, L_TCHAR *pszAbstract);
   L_VOID    DelPresentation        (L_UCHAR nID);

   L_UCHAR   GetResult              (L_UCHAR nID);
   L_INT     SetResult              (L_UCHAR nID, L_UCHAR nResult);

   L_VOID    GetAbstract            (L_UCHAR nID, L_TCHAR *strAbstract, L_UINT32 SizeInWords);
   L_INT     SetAbstract            (L_UCHAR nID, L_TCHAR *pszUID);
   L_UCHAR   FindAbstract           (L_TCHAR *pszUID);
   L_UCHAR   FindNextAbstract       (L_UCHAR nID, L_TCHAR *pszUID);
   L_INT     GetAbstractCount       (L_TCHAR *pszUID);



   L_INT     GetTransferCount       (L_UCHAR nID);
   L_VOID    GetTransfer            (L_UCHAR nID, L_INT nIndex, L_TCHAR *strTransfer, L_UINT32 SizeInWords);
   L_INT     SetTransfer            (L_UCHAR nID, L_INT nIndex, L_TCHAR *pszUID);
   L_INT     AddTransfer            (L_UCHAR nID, L_TCHAR *pszUID);
   L_VOID    DelTransfer            (L_UCHAR nID, L_INT nIndex);

   L_BOOL    IsRoleSelect           (L_UCHAR nID);
   L_UCHAR   GetUserRole            (L_UCHAR nID);
   L_UCHAR   GetProviderRole        (L_UCHAR nID);
   L_INT     SetRoleSelect          (L_UCHAR nID, L_BOOL bEnabled, L_UCHAR nUser, L_UCHAR nProvider);

   L_UINT32  GetLengthExtended      (L_UCHAR nID);
   L_UCHAR  *GetExtended            (L_UCHAR nID);
   L_INT     SetExtended            (L_UCHAR nID, L_UCHAR *pData, L_UINT32 nLength);

   L_BOOL    IsMaxLength            ();
   L_UINT32  GetMaxLength           ();
   L_INT     SetMaxLength           (L_BOOL bEnabled, L_UINT32 nLength);

   L_BOOL    IsImplementClass       ();
   L_VOID    GetImplementClass      (L_TCHAR *strImplementClass, L_UINT32 SizeInWords);
   L_INT     SetImplementClass      (L_BOOL bEnabled, L_TCHAR *pszUID);

   L_BOOL    IsAsyncOperations      ();
   L_UINT16  GetInvokedOperations   ();
   L_UINT16  GetPerformedOperations ();
   L_INT     SetAsyncOperations     (L_BOOL bEnabled, L_UINT16 nInvoked, L_UINT16 nPerformed);

   L_BOOL    IsImplementVersion     ();
   L_VOID    GetImplementVersion    (L_TCHAR *strImplementVersion, L_UINT32 SizeInWords);
   L_INT     SetImplementVersion    (L_BOOL bEnabled, L_TCHAR *pszVersion);

   L_INT     GetUserInfoCount       ();
   L_UCHAR   GetTypeUserInfo        (L_INT nIndex);
   L_UINT16  GetLengthUserInfo      (L_INT nIndex);
   L_UCHAR   *GetDataUserInfo       (L_INT nIndex);
   L_INT     SetUserInfo            (L_INT nIndex, L_UCHAR nType, L_UCHAR *pData, L_UINT16 nLength);
   L_INT     AddUserInfo            (L_UCHAR nType, L_UCHAR *pData, L_UINT16 nLength);
   L_VOID    DelUserInfo            (L_INT nIndex);

   //Internal Use only
   L_CHAR   *GetAbstractA            (L_UCHAR nID);
   L_INT     SetAbstractA            (L_UCHAR nID, L_CHAR *pszUID);
   L_UCHAR   FindAbstractA           (L_CHAR *pszUID);
   L_UCHAR   FindNextAbstractA       (L_UCHAR nID, L_CHAR *pszUID);
   L_INT     GetAbstractCountA       (L_CHAR *pszUID);
   L_INT     SetTransferA            (L_UCHAR nID, L_INT nIndex, L_CHAR *pszUID);
   L_CHAR   *GetImplementClassA      ();
   L_INT     SetImplementClassA      (L_BOOL bEnabled, L_CHAR *pszUID);
   L_CHAR   *GetImplementVersionA    ();
   L_INT     SetImplementVersionA    (L_BOOL bEnabled, L_CHAR *pszVersion);
   LDicomAssociate *Clone            ();
private:
   friend class LDicomNet;

   L_BOOL     m_bRequest;
   L_UINT16   m_nVersion;
   L_CHAR     m_szCalled[PDU_MAX_TITLE_SIZE+1];
   L_CHAR     m_szCalling[PDU_MAX_TITLE_SIZE+1];
   L_CHAR     m_szApplication[PDU_MAX_UID_SIZE+1];

   L_BOOL     m_bMaxLength;
   L_UINT32   m_nMaxLength;

   L_BOOL     m_bImplementClass;
   L_CHAR     m_szImplementClass[PDU_MAX_UID_SIZE+1];

   L_BOOL     m_bAsyncOperations;
   L_UINT16   m_nInvokedOperations;
   L_UINT16   m_nPerformedOperations;

   L_BOOL     m_bImplementVersion;
   L_CHAR     m_szImplementVersion[PDU_MAX_VERSION_SIZE+1];

   LDicomTree m_Presentation;
   LDicomTree m_RoleSelect;
   LDicomTree m_UserInfo;

   L_INT     GetBinary        (L_CHAR *pBuffer, L_UINT32 *pnLength);
   L_INT     SetBinary        (L_CHAR *pBuffer, L_UINT32 *pnLength, LDicomAssociate *pDicomAssociate);
   L_VOID   *FindPresentation (L_UCHAR nID);
   L_VOID    DelSpaces        (L_CHAR *pszText, L_UINT32 nLength);

   L_INT     AddTransferA      (L_UCHAR nID, L_CHAR *pszUID);
   L_INT     AddPresentationA  (L_UCHAR nID, L_UCHAR nResult, L_CHAR *pszAbstract);
   L_CHAR   *GetTransferA      (L_UCHAR nID, L_INT nIndex);

#if !defined(FOR_UWP) && !defined(FOR_UNIX)
   friend class DicomDataSerializer;
#endif
};

#endif // #if defined(__cplusplus)
#endif //if !defined(EXCLUDE_DICOM_NET)
#endif //#if !defined (EXCLUDE_DICOM_FUNCTIONS)

typedef L_VOID *HDICOMPDU;

// --- Structures --- //

// Basic Film Session Parameters
typedef struct tagFILMSESSIONPARAMETERS
{
   L_UINT  uStructSize;
   L_INT32 nNumberOfCopies;
   L_PCTSTR pszPrintPriority;
   L_PCTSTR pszMediumType;
   L_PCTSTR pszFilmDestination;
   L_PCTSTR pszFilmSessionLabel;
   L_INT32 nMemoryAllocation;
   L_PCTSTR pszOwnerID;
} FILMSESSIONPARAMETERS, * pFILMSESSIONPARAMETERS;

#if !defined(EXCLUDE_DICOM_NET)
#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

L_LTDIC_API HDICOMPDU EXT_FUNCTION L_DicomCreateAssociate        (L_BOOL bRequest);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomFreeAssociate          (HDICOMPDU hPDU);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomResetAssociate         (HDICOMPDU hPDU, L_BOOL bRequest);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDefaultAssociate       (HDICOMPDU hPDU);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsRequest              (HDICOMPDU hPDU);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomSetRequest             (HDICOMPDU hPDU, L_BOOL bRequest);

L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomGetVersion             (HDICOMPDU hPDU);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetVersion             (HDICOMPDU hPDU, L_UINT16 nVersion);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetCalled              (HDICOMPDU hPDU,L_TCHAR *strCalled, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetCalled              (HDICOMPDU hPDU, L_TCHAR *pszName);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetCalling             (HDICOMPDU hPDU,L_TCHAR *strCalling, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetCalling             (HDICOMPDU hPDU, L_TCHAR *pszName);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetApplication         (HDICOMPDU hPDU,L_TCHAR *strApplication, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetApplication         (HDICOMPDU hPDU, L_TCHAR *pszUID);

L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetPresentationCount   (HDICOMPDU hPDU);
L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomGetPresentation        (HDICOMPDU hPDU, L_INT nIndex);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetPresentation        (HDICOMPDU hPDU, L_INT nIndex, L_UCHAR nID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomAddPresentation        (HDICOMPDU hPDU, L_UCHAR nID, L_UCHAR nResult, L_TCHAR *pszAbstract);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDelPresentation        (HDICOMPDU hPDU, L_UCHAR nID);

L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomGetResult              (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetResult              (HDICOMPDU hPDU, L_UCHAR nID, L_UCHAR nResult);

L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetAbstract            (HDICOMPDU hPDU, L_UCHAR nID, L_TCHAR *strAbstract, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetAbstract            (HDICOMPDU hPDU, L_UCHAR nID, L_TCHAR *pszUID);
L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomFindAbstract           (HDICOMPDU hPDU, L_TCHAR *pszUID);

L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomFindNextAbstract       (HDICOMPDU hPDU, L_UCHAR nID, L_TCHAR *pszUID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetAbstractCount       (HDICOMPDU hPDU, L_TCHAR *pszUID);


L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetTransferCount       (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetTransfer            (HDICOMPDU hPDU, L_UCHAR nID, L_INT nIndex, L_TCHAR *strTransfer, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetTransfer            (HDICOMPDU hPDU, L_UCHAR nID, L_INT nIndex, L_TCHAR *pszUID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomAddTransfer            (HDICOMPDU hPDU, L_UCHAR nID, L_TCHAR *pszUID);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDelTransfer            (HDICOMPDU hPDU, L_UCHAR nID, L_INT nIndex);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsRoleSelect           (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomGetUserRole            (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomGetProviderRole        (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetRoleSelect          (HDICOMPDU hPDU, L_UCHAR nID, L_BOOL bEnabled, L_UCHAR nUser, L_UCHAR nProvider);

L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetLengthExtended      (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_UCHAR*  EXT_FUNCTION L_DicomGetExtended            (HDICOMPDU hPDU, L_UCHAR nID);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetExtended            (HDICOMPDU hPDU, L_UCHAR nID, L_UCHAR *pData, L_UINT32 nLength);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsMaxLength            (HDICOMPDU hPDU);
L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetMaxLength           (HDICOMPDU hPDU);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetMaxLength           (HDICOMPDU hPDU, L_BOOL bEnabled, L_UINT32 nLength);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsImplementClass       (HDICOMPDU hPDU);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetImplementClass      (HDICOMPDU hPDU, L_TCHAR *strImplementClass, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetImplementClass      (HDICOMPDU hPDU, L_BOOL bEnabled, L_TCHAR *pszUID);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsAsyncOperations      (HDICOMPDU hPDU);
L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomGetInvokedOperations   (HDICOMPDU hPDU);
L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomGetPerformedOperations (HDICOMPDU hPDU);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetAsyncOperations     (HDICOMPDU hPDU, L_BOOL bEnabled, L_UINT16 nInvoked, L_UINT16 nPerformed);

L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsImplementVersion     (HDICOMPDU hPDU);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomGetImplementVersion    (HDICOMPDU hPDU,L_TCHAR *strImplementVersion, L_UINT32 SizeInWords);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetImplementVersion    (HDICOMPDU hPDU, L_BOOL bEnabled, L_TCHAR *pszVersion);

L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetUserInfoCount       (HDICOMPDU hPDU);
L_LTDIC_API L_UCHAR   EXT_FUNCTION L_DicomGetTypeUserInfo        (HDICOMPDU hPDU, L_INT nIndex);
L_LTDIC_API L_UINT16  EXT_FUNCTION L_DicomGetLengthUserInfo      (HDICOMPDU hPDU, L_INT nIndex);
L_LTDIC_API L_UCHAR*  EXT_FUNCTION L_DicomGetDataUserInfo       (HDICOMPDU hPDU, L_INT nIndex);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSetUserInfo            (HDICOMPDU hPDU, L_INT nIndex, L_UCHAR nType, L_UCHAR *pData, L_UINT16 nLength);
L_LTDIC_API L_INT     EXT_FUNCTION L_DicomAddUserInfo            (HDICOMPDU hPDU, L_UCHAR nType, L_UCHAR *pData, L_UINT16 nLength);
L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomDelUserInfo            (HDICOMPDU hPDU, L_INT nIndex);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

//============= CLASS ==========================================================
#define NET_MAX_ADDRESS_SIZE  16

#if !defined (EXCLUDE_DICOM_FUNCTIONS)

typedef L_VOID *HDICOMNET;

typedef L_VOID (pEXT_CALLBACK CONNECTCALLBACK)                 (HDICOMNET hNet, L_INT nError, L_VOID *pUserData);
#if defined(FOR_UWP)
typedef L_VOID (pEXT_CALLBACK ACCEPTCALLBACK)                  (HDICOMNET hNet, L_INT nError, Platform::Object^ hHandle, L_VOID *pUserData);
#else
typedef L_VOID (pEXT_CALLBACK ACCEPTCALLBACK)                  (HDICOMNET hNet, L_INT nError, L_VOID *pUserData);
#endif 
typedef L_VOID (pEXT_CALLBACK CLOSECALLBACK)                   (HDICOMNET hNet, L_INT nError, HDICOMNET hPeer, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECALLBACK)                 (HDICOMNET hNet, L_INT nError, L_UCHAR nType, L_UCHAR *pBuffer, L_UINT32 nBytes, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK SENDCALLBACK)                    (HDICOMNET hNet, L_INT nError, L_UCHAR nType, L_UINT32 nBytes, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK SENDEXTCALLBACK)                 (HDICOMNET hNet, pDICOMNETDEBUGINFOONSEND pDicomNetDebugInfoOnsend, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEASSOCIATEREQUESTCALLBACK) (HDICOMNET hNet, HDICOMPDU hPDU, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEASSOCIATEACCEPTCALLBACK)  (HDICOMNET hNet, HDICOMPDU hPDU, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEASSOCIATEREJECTCALLBACK)  (HDICOMNET hNet, L_UCHAR nResult, L_UCHAR nSource, L_UCHAR nReason, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEDATACALLBACK)             (HDICOMNET hNet, L_UCHAR nPresentationID, HDICOMDS hCS, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVERELEASEREQUESTCALLBACK)   (HDICOMNET hNet, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVERELEASERESPONSECALLBACK)  (HDICOMNET hNet, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEABORTCALLBACK)            (HDICOMNET hNet, L_UCHAR nSource, L_UCHAR nReason, L_VOID *pUserData);

typedef L_VOID (pEXT_CALLBACK RECEIVECSTOREREQUESTCALLBACK)    (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nPriority, L_TCHAR *pszMoveAE, L_UINT16 nMoveMessageID, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECSTORERESPONSECALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECFINDREQUESTCALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECFINDRESPONSECALLBACK)    (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECGETREQUESTCALLBACK)      (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECGETRESPONSECALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECMOVEREQUESTCALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, L_TCHAR *pszMoveAE, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECMOVERESPONSECALLBACK)    (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECCANCELREQUESTCALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECECHOREQUESTCALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVECECHORESPONSECALLBACK)    (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENREPORTREQUESTCALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nEvent, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENREPORTRESPONSECALLBACK)  (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nEvent, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENGETREQUESTCALLBACK)      (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT32 *pnAttribute, L_UINT32 nCount, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENGETRESPONSECALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENSETREQUESTCALLBACK)      (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENSETRESPONSECALLBACK)     (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENACTIONREQUESTCALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nAction, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENACTIONRESPONSECALLBACK)  (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nAction, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENCREATEREQUESTCALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENCREATERESPONSECALLBACK)  (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENDELETEREQUESTCALLBACK)   (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVENDELETERESPONSECALLBACK)  (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_VOID *pUserData);
typedef L_VOID (pEXT_CALLBACK RECEIVEUNKNOWNCALLBACK)          (HDICOMNET hNet, L_UCHAR nPresentationID, HDICOMDS hCS, HDICOMDS hDS, L_VOID *pUserData);

typedef L_UINT32 (pEXT_CALLBACK GETCHALLENGECALLBACK)          (HDICOMNET hNet, L_UINT64 *nChallenge, L_UINT64 nParameter, L_VOID *pUserData);
typedef L_UINT32 (pEXT_CALLBACK INTERNALAUTHENTICATECALLBACK)  (HDICOMNET hNet, L_UINT64 nChallenge, L_UINT64 *nResponse, L_UINT64 nParameter, L_VOID *pUserData);
typedef L_UINT32 (pEXT_CALLBACK EXTERNALAUTHENTICATECALLBACK)  (HDICOMNET hNet, L_UINT64 nChallenge, L_UINT64 nResponse, L_UINT64 nParameter, L_VOID *pUserData);
typedef L_VOID   (pEXT_CALLBACK ONSECURELINKREADY)             (HDICOMNET hNet, L_UINT32 nError, L_VOID *pUserData);
typedef L_VOID   (pEXT_CALLBACK ONNONSECURESENDISCL)           (HDICOMNET hNet, L_INT nError, L_UCHAR nType, L_UINT32 nLength, L_VOID *pUserData);
typedef L_VOID   (pEXT_CALLBACK ONNONSECURERECEIVEDISCL)       (HDICOMNET hNet, L_INT nError, L_UCHAR *pBuffer, L_UINT32 nLength, L_VOID *pUserData);
//debug only
typedef L_VOID   (pEXT_CALLBACK RECEIVEDISCLPACKET)            (HDICOMNET hNet, L_INT nError, L_UCHAR *pBuffer, L_UINT32 nBytes, L_VOID *pUserData);

typedef L_VOID   (pEXT_CALLBACK BEFORESENDCOMMANDSET)          (HDICOMNET hNet, HDICOMDS hCS, L_VOID *pUserData);


typedef struct _DICOMNETCALLBACK
{
   CONNECTCALLBACK                  pfnConnect;
   ACCEPTCALLBACK                   pfnAccept; 
   CLOSECALLBACK                    pfnClose;  
   RECEIVECALLBACK                  pfnReceive;
   SENDCALLBACK                     pfnSend;      
   RECEIVEASSOCIATEREQUESTCALLBACK  pfnReceiveAssociateRequest;
   RECEIVEASSOCIATEACCEPTCALLBACK   pfnReceiveAssociateAccept; 
   RECEIVEASSOCIATEREJECTCALLBACK   pfnReceiveAssociateReject; 
   RECEIVEDATACALLBACK              pfnReceiveData;            
   RECEIVERELEASEREQUESTCALLBACK    pfnReceiveReleaseRequest;  
   RECEIVERELEASERESPONSECALLBACK   pfnReceiveReleaseResponse; 
   RECEIVEABORTCALLBACK             pfnReceiveAbort;           
   RECEIVECSTOREREQUESTCALLBACK     pfnReceiveCStoreRequest;   
   RECEIVECSTORERESPONSECALLBACK    pfnReceiveCStoreResponse;  
   RECEIVECFINDREQUESTCALLBACK      pfnReceiveCFindRequest;    
   RECEIVECFINDRESPONSECALLBACK     pfnReceiveCFindResponse;   
   RECEIVECGETREQUESTCALLBACK       pfnReceiveCGetRequest;     
   RECEIVECGETRESPONSECALLBACK      pfnReceiveCGetResponse;    
   RECEIVECMOVEREQUESTCALLBACK      pfnReceiveCMoveRequest;    
   RECEIVECMOVERESPONSECALLBACK     pfnReceiveCMoveResponse;   
   RECEIVECCANCELREQUESTCALLBACK    pfnReceiveCCancelRequest;  
   RECEIVECECHOREQUESTCALLBACK      pfnReceiveCEchoRequest;    
   RECEIVECECHORESPONSECALLBACK     pfnReceiveCEchoResponse;   
   RECEIVENREPORTREQUESTCALLBACK    pfnReceiveNReportRequest;  
   RECEIVENREPORTRESPONSECALLBACK   pfnReceiveNReportResponse; 
   RECEIVENGETREQUESTCALLBACK       pfnReceiveNGetRequest;     
   RECEIVENGETRESPONSECALLBACK      pfnReceiveNGetResponse;    
   RECEIVENSETREQUESTCALLBACK       pfnReceiveNSetRequest;     
   RECEIVENSETRESPONSECALLBACK      pfnReceiveNSetResponse;    
   RECEIVENACTIONREQUESTCALLBACK    pfnReceiveNActionRequest;  
   RECEIVENACTIONRESPONSECALLBACK   pfnReceiveNActionResponse; 
   RECEIVENCREATEREQUESTCALLBACK    pfnReceiveNCreateRequest;  
   RECEIVENCREATERESPONSECALLBACK   pfnReceiveNCreateResponse; 
   RECEIVENDELETEREQUESTCALLBACK    pfnReceiveNDeleteRequest;  
   RECEIVENDELETERESPONSECALLBACK   pfnReceiveNDeleteResponse; 
   RECEIVEUNKNOWNCALLBACK           pfnReceiveUnknown; 
   L_VOID                          *pUserData;
// added for ISCL compliance
   GETCHALLENGECALLBACK             pfnGetChallenge;
   INTERNALAUTHENTICATECALLBACK     pfnInternalAuthenticate;
   EXTERNALAUTHENTICATECALLBACK     pfnExternalAuthenticate;
   ONSECURELINKREADY                pfnOnSecureLinkReady;      // used by TLS also
   ONNONSECURESENDISCL              pfnOnNonSecureSendISCL;
   ONNONSECURERECEIVEDISCL          pfnOnNonSecureReceivedISCL;
// debug only
   RECEIVEDISCLPACKET               pfnOnReceivedISCLPacket;
// end of added for ISCL compliance

} DICOMNETCALLBACK, *pDICOMNETCALLBACK;


typedef L_INT (pEXT_CALLBACK PRIVATEKEYPASSWORD)           (HDICOMNET hNet, L_TCHAR *pszPassword, L_INT nSize, L_INT nFlag, L_VOID *pUserData);
typedef L_INT(pEXT_CALLBACK VERIFY)                        (HDICOMNET hNet, L_INT ok, L_TCHAR *pszCertificateString, L_INT nError, L_TCHAR *pszErrorString, L_VOID *pUserData);

typedef struct _DICOMNETCALLBACKEXT
{
   L_UINT                           uStructSize;
   PRIVATEKEYPASSWORD               pfnPrivateKeyPassword;  
   L_VOID                          *pUserData;
   VERIFY                           pfnVerify;
   BEFORESENDCOMMANDSET             pfnBeforeSendCommandSet;
} DICOMNETCALLBACKEXT, *pDICOMNETCALLBACKEXT;

#if defined(__cplusplus)

typedef struct _NETLINK NETLINK, *pNETLINK;
typedef struct _ISCLInternalData ISCLInternalData, *pISCLInternalData;

typedef struct _LDICOMNETPRIVATEDATA
{
   L_INT    nSize;
   L_BOOL   m_bEnable;

   // 0 - normal, 
   // or DEBUG_MODE_ONRECEIVE_SHOW_EXTENDED_INFO, 
   // or DEBUG_MODE_ONSEND_SHOW_EXTENDED_INFO
   L_UINT32 m_DebugModeFlags;

   L_BOOL   m_bUseExtendedOnSend;
   L_BOOL   m_bUseExtendedOnReceive;
   DICOMNETDEBUGINFOONSEND m_DebugInfoOnSend;

   L_UINT32 m_nMethodTypeSSL;       // SSL_METHOD object type
   L_INT    m_nCTX_Options;         //L_SSL_OP_NO_SSLv2, L_SSL_OP_NO_SSLv3, L_SSL_OP_NO_TLSv1
   L_VOID  *m_pfnCTX_VerifyCallback;

   // Callbacks for API
   DICOMNETCALLBACKEXT m_CallbackExt;

   L_BOOL   m_bEnableOptimizedSend ;

   DICOMSOCKETOPTIONS m_SocketOptions;

   L_INT m_nOsVersion;

   L_BOOL m_bDeleteReceiveCS ;// add  this for the case when a CS is received but no DS is (client crash be4 sending complete msg)

   L_INT m_bEnableOptimizedMemorySend ;
   L_UINT32 m_uDicomNetFlags;

   pSSL_CONF_CTX m_pConfCtx;

   LDicomDS *m_pCSCopy;

}LDICOMNETPRIVATEDATA , * pLDICOMNETPRIVATEDATA;

class L_LTDIC_CLASS LDicomNet
{
public:

#if defined(FOR_UNIX)
   L_INT m_Socket;
   L_CHAR *m_pszHostAddress;
   L_INT m_nHostPort;
   L_CHAR *m_pszPeerAddress;
   L_INT m_nPeerPort;
   pthread_t m_SocketThread;
   struct LINKEDLIST *m_pClients;
   pthread_mutex_t m_ListLock;

   pthread_mutex_t m_ServerThreadLock;
   pthread_mutex_t m_SocketThreadLock;
   pthread_mutex_t m_SendThreadLock;

   int m_server_readPipe;
   int m_server_writePipe;
#endif

   pNETLINK m_pNetMessageQueue;
   L_VOID** m_ppNetMessageTracker;
   L_SIZE_T m_NetMessageCount;
   L_SIZE_T m_NetMessageTrackerSize;
   pISCLInternalData m_pISCLIntData;

// added for security - used by TLS and ISCL
   virtual L_VOID OnSecureLinkReady(L_UINT32 nError);  // can be 0 - OK and non-zero -  failure

// added for TLS compliance

   L_CIPHERSUITE  GetCipherFromIndexTLS(L_UINT32 nIndex);
   L_UINT32       SetCipherToIndexTLS(L_UINT32 nIndex, L_CIPHERSUITE cipher);

   L_CIPHERSUITE  GetCiphersuiteTLS();

   L_UINT32       GetEncryptionAlgorithmTLS(L_CIPHERSUITE cipher);
   L_UINT32       GetAuthenticationAlgorithmTLS(L_CIPHERSUITE cipher);
   L_UINT32       GetIntegrityAlgorithmTLS (L_CIPHERSUITE cipher);
   L_UINT32       GetKeyExchangeAlgorithmTLS(L_CIPHERSUITE cipher);

   L_UINT32       GetEncryptKeyLengthTLS (L_CIPHERSUITE cipher);
   L_UINT32       GetMutualAuthKeyLengthTLS (L_CIPHERSUITE cipher);
   L_UINT32       SetClientCertificateTLS(L_TCHAR *pszPathToCertificate, L_UINT32 certType, L_TCHAR *pszPathToKeyFile);
      // certType can be L_TLS_FILETYPE_PEM (clear text) or L_TLS_FILETYPE_ASN1 (binary)
      // the client have zero or one certificate
   L_UINT32       SetServerCertificateTLS(L_TCHAR *pszPathToCertificate, L_UINT32 certType, L_TCHAR *pszPathToKeyFile);
      // the server can have a chain of certificates in a single file
      // certType can be L_TLS_FILETYPE_PEM (clear text) or L_TLS_FILETYPE_ASN1 (binary)
      // AT LEAST ONE certificate is required for a TLS server

// not to be documented
   L_UINT32       GetTLSStatus();
   L_VOID         SetTLSStatus(L_UINT32 nStatus);
      // 0 - non connected
      // 1 - client during TLS handshake
      // 2 - server during TLS_handshake
      // 3 - connected
// end of added for TLS

// added  for ISCL compliance - 18.09.2001
   // interface for ISCL operations:

   L_UINT32 SetMaxCommBlockLengthISCL(L_UINT32 nMaxCommBlockLength);   // maximum communication block size, there are performance
         // advantages if a comm block of ISCL is included into a TCP packet
   L_UINT32 GetCommBlockLengthISCL();     // return the comm block size negotiated
   L_UINT32 SetMaxMessageLengthISCL(L_UINT32 nMsgLength);     // the maximum message length that can be processed - 1MB, 2MB and so on

   L_UINT32 SetMutualAuthAlgISCL(L_UINT32 mutualAuthMode);       // only 4way 3pass
   L_UINT32 SetDefaultEncryptionISCL(L_UINT32 EncryptionMode);   // bulk data encryption algorithm
   L_UINT32 SetDefaultSigningISCL(L_UINT32 SignMode);            // message authentication algorithm
   L_UINT32 GetPeerEncryptionISCL();   // can be checked to see what algorithm of communication the sender tries to use
   L_UINT32 GetPeerMACISCL();      // ATTN: if the crypt/MAC algorithm differs, the message is dropped and the GetPeerEncryption()/GetPeerMAC() will tell me
                                    // the algorithms of crypt/MAC used by the client

   L_UINT32 GetErrorSecure();       // returns the m_nISCLError in ISCL case, or m_nTLSError in case of TLS

   virtual L_UINT32 GetChallengeISCL(L_UINT64 *nChallenge, L_UINT64 nParameter);
   virtual L_UINT32 InternalAuthenticateISCL(L_UINT64 nChallenge, L_UINT64 *nResponse, L_UINT64 nParameter);
   virtual L_UINT32 ExternalAuthenticateISCL(L_UINT64 nChallenge, L_UINT64 nResponse, L_UINT64 nParameter);
         // functions described in ISO 7816-4


   L_UINT32 SetAuthDataISCL(L_VOID *pBuffer, L_UINT32 nLength);    // nLength = 1...128
   L_UINT32 GetPeerAuthDataISCL(L_VOID *pBuffer, L_UINT32 *nLength);
         // if nLength not between 1 and 128 bytes, error
         // used to set or obtain the authentication data exchanged during the mutual authentication (connectISCL/acceptISCL)

   L_UINT32 GetPeerRequestedMessageLengthISCL();      // used if local end refuse to receive
         // peer message because message size bigger than local end max
         // example: a server can use max 1MB message, but a client could try to send a 16 MB message

   L_UINT32 SetMutualAuthKeyISCL(L_UINT32 nIndex, L_UINT64 key);      // key used during mutual authentication
            // it looks unused for the V1.00 of ISCL
   L_UINT32 SetIndexForMutualAuthISCL(L_UINT32 nIndex);
            // index from 1 to 8 for the mutual auth key - see the remark 2 lines up
   L_UINT32 SetEncryptKeyISCL(L_UINT32 nIndex, L_UINT64 key);
            // index from 1 to 8 for the encryption key - used to load communication keys
   L_UINT32 SetIndexForEncryptISCL(L_UINT32 nIndex);
            // index from 1 to 8 to select the encryption key


   L_BOOL   IsISCLQueueEmpty();

   L_UINT32 GetIndexForEncryptISCL();
   L_UINT32 GetIndexForMutualAuthISCL();
   L_UINT32 GetStatusISCL();                          // return the internal status of the object.
         // Description of internal status will be added in docs, see also the source

   L_INT    CloseForced(L_BOOL bForced);

   L_INT32  SendNonSecureISCL(L_UCHAR *pBuffer, L_UINT32 nBytes);
   virtual  L_VOID OnNonSecureSendISCL(L_INT nError, L_UCHAR nType, L_UINT32 nLength);
   virtual  L_VOID OnNonSecureReceivedISCL(L_UINT32 nError, L_UCHAR *pBuffer, L_UINT32 nLength);

   virtual  L_VOID OnReceivedISCLPacket(L_INT nError, L_UCHAR *pBuffer, L_UINT32 nLength);  // error code, buffer and length

   L_UINT32 GetSecureMode();

// end of added for ISCL

   LDicomNet(L_TCHAR *pszPath, L_INT32 nMode);
      // modified for security: Added L_INT32 nMode parameter of constructor.
      // Values for nMode: DICOM_SECURE_ISCL, DICOM_SECURE_TLS, DICOM_SECURE_NONE
      // if a bad value is supplied, security will be DICOM_SECURE_NONE

   LDicomNet(L_TCHAR *pszPath, L_INT32 nMode, L_BOOL bReserved);


   virtual ~LDicomNet();

   static L_INT GetOpenSslVersion(pDICOMOPENSSLVERSION pDicomOpenSslVersion, L_UINT uStructSize, L_UINT uFlagsReserved);
   
#if defined(FOR_MANAGED)
   static L_INT     StartUp                    ( L_INT nManagedAppDomain );
#else
   static L_INT     StartUp                    ();
#endif
   
   static L_VOID    ShutDown                   ();

   L_INT            Connect                    (L_TCHAR *pszHostAddress, L_UINT nHostPort, L_TCHAR *pszPeerAddress, L_UINT nPeerPort);
   L_INT            Listen                     (L_TCHAR *pszHostAddress, L_UINT nHostPort, L_INT nNbPeers);
   L_INT            Connect                    (L_TCHAR *pszHostAddress, L_UINT nHostPort, L_TCHAR *pszPeerAddress, L_UINT nPeerPort, L_INT nIpType);
   L_INT            Listen                     (L_TCHAR *pszHostAddress, L_UINT nHostPort, L_INT nNbPeers, L_INT nIpType);

#if defined(FOR_UWP)
   L_INT            Accept                     (LDicomNet *pNet, Platform::Object^ hHandle);
#else
   L_INT            Accept                     (LDicomNet *pNet);
#endif

   L_VOID           Close                      ();
   
   L_INT            SendAssociateRequest       (LDicomAssociate *pPDU);
   L_INT            SendAssociateAccept        (LDicomAssociate *pPDU);
   L_INT            SendAssociateReject        (L_UCHAR nResult, L_UCHAR nSource, L_UCHAR nReason);
   L_INT            SendData                   (L_UCHAR nPresentationID, LDicomDS *pCS, LDicomDS *pDS);
   L_INT            SendReleaseRequest         ();
   L_INT            SendReleaseResponse        ();
   L_INT            SendAbort                  (L_UCHAR nSource, L_UCHAR nReason);

   L_INT            SendCStoreRequest          (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nPriority, L_TCHAR *pszMoveAE, L_UINT16 nMoveMessageID, LDicomDS *pDS);
   L_INT            SendCStoreResponse         (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);
   L_INT            SendCFindRequest           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, LDicomDS *pDS);
   L_INT            SendCFindResponse          (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, LDicomDS *pDS);
   L_INT            SendCGetRequest            (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, LDicomDS *pDS);
   L_INT            SendCGetResponse           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, LDicomDS *pDS);
   L_INT            SendCMoveRequest           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, L_TCHAR *pszMoveAE, LDicomDS *pDS);
   L_INT            SendCMoveResponse          (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, LDicomDS *pDS);
   L_INT            SendCCancelRequest         (L_UCHAR nPresentationID, L_UINT16 nMessageID);
   L_INT            SendCEchoRequest           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass);
   L_INT            SendCEchoResponse          (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus);

   L_INT            SendNReportRequest         (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nEvent, LDicomDS *pDS);
   L_INT            SendNReportResponse        (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nEvent, LDicomDS *pDS);
   L_INT            SendNGetRequest            (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT32 *pnAttribute, L_UINT16 nCount);
   L_INT            SendNGetResponse           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   L_INT            SendNSetRequest            (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, LDicomDS *pDS);
   L_INT            SendNSetResponse           (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   L_INT            SendNActionRequest         (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nAction, LDicomDS *pDS);
   L_INT            SendNActionResponse        (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nAction, LDicomDS *pDS);
   L_INT            SendNCreateRequest         (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, LDicomDS *pDS);
   L_INT            SendNCreateResponse        (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   L_INT            SendNDeleteRequest         (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance);
   L_INT            SendNDeleteResponse        (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);

   L_VOID           EnableOptimizedSend        (L_BOOL bEnable);

   L_BOOL           IsActivated                ();
   L_BOOL           IsConnected                ();
   L_BOOL           IsAssociated               ();

   L_UINT32         GetQueueSend               ();

   LDicomNet       *GetServer                  ();
   L_UINT32         GetClientCount             ();
   LDicomNet       *GetClient                  (L_UINT nIndex);

   L_INT            GetHostInfo                (L_TCHAR *pszAddress, L_UINT32 AddressSizeInWords, L_UINT *pnPort);
   L_INT            GetPeerInfo                (L_TCHAR *pszAddress, L_UINT32 AddressSizeInWords, L_UINT *pnPort);

   LDicomAssociate *GetAssociate               ();

   LDicomDS        *GetCommandSet              ();

   virtual L_VOID   OnConnect                  (L_INT nError);
#if defined(FOR_UWP)
   virtual L_VOID   OnAccept                   (L_INT nError, Platform::Object ^hHandle);
#else
   virtual L_VOID   OnAccept                   (L_INT nError);
#endif

   virtual L_VOID   OnClose                    (L_INT nError, LDicomNet *pNet);
   virtual L_VOID   OnReceive                  (L_INT nError, L_UCHAR nType, L_UCHAR *pBuffer, L_UINT32 nBytes);
   virtual L_VOID   OnSend                     (L_INT nError, L_UCHAR nType, L_UINT32 nBytes);

   virtual L_VOID   OnReceiveAssociateRequest  (LDicomAssociate *pPDU);
   virtual L_VOID   OnReceiveAssociateAccept   (LDicomAssociate *pPDU);
   virtual L_VOID   OnReceiveAssociateReject   (L_UCHAR nResult, L_UCHAR nSource, L_UCHAR nReason);
   virtual L_VOID   OnReceiveData              (L_UCHAR nPresentationID, LDicomDS *pCS, LDicomDS *pDS);
   virtual L_VOID   OnReceiveReleaseRequest    ();
   virtual L_VOID   OnReceiveReleaseResponse   ();
   virtual L_VOID   OnReceiveAbort             (L_UCHAR nSource, L_UCHAR nReason);

   virtual L_VOID   OnReceiveCStoreRequest     (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nPriority, L_TCHAR *pszMoveAE, L_UINT16 nMoveMessageID, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCStoreResponse    (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);
   virtual L_VOID   OnReceiveCFindRequest      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCFindResponse     (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCGetRequest       (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCGetResponse      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCMoveRequest      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, L_TCHAR *pszMoveAE, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCMoveResponse     (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, LDicomDS *pDS);
   virtual L_VOID   OnReceiveCCancelRequest    (L_UCHAR nPresentationID, L_UINT16 nMessageID);
   virtual L_VOID   OnReceiveCEchoRequest      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass);
   virtual L_VOID   OnReceiveCEchoResponse     (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus);
   virtual L_VOID   OnReceiveNReportRequest    (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nEvent, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNReportResponse   (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nEvent, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNGetRequest       (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT32 *pnAttribute, L_UINT16 nCount);
   virtual L_VOID   OnReceiveNGetResponse      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNSetRequest       (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNSetResponse      (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNActionRequest    (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nAction, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNActionResponse   (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nAction, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNCreateRequest    (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNCreateResponse   (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS *pDS);
   virtual L_VOID   OnReceiveNDeleteRequest    (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance);
   virtual L_VOID   OnReceiveNDeleteResponse   (L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);
   virtual L_VOID   OnReceiveUnknown           (L_UCHAR nPresentationID, LDicomDS *pCS, LDicomDS *pDS);

   L_SSL_CTX  *GetCTX();
   L_INT32   CTXSetOptions(L_UINT uOptions);
   L_INT     SetSLLMethodType(L_INT nMethodType);


   //---------------------------------------------------------------------------
   // Private Functions (Internal use only)
   //---------------------------------------------------------------------------
   L_VOID           SetCallback                (pDICOMNETCALLBACK pCallback);
   L_VOID           SetCallbackExt             (pDICOMNETCALLBACKEXT pCallbackExt);

   L_UINT32 SetDebugMode(L_UINT32 nDebugMode);  // returns the old debug mode
   virtual L_VOID   OnSendExt(pDICOMNETDEBUGINFOONSEND pDicomNetDebugInfoOnsend);
   virtual L_VOID OnCreateCTX(L_SSL_CTX *pCtx);
   virtual L_INT  OnPrivateKeyPassword(L_TCHAR *pszPassword, L_INT nSize, L_INT nFlag);
   virtual L_INT OnVerify(L_INT ok, L_TCHAR *pszCertificateString, L_INT nError, L_TCHAR *pszErrorString);
   virtual L_VOID   OnBeforeSendCommandSet(LDicomDS *pCS);
   L_VOID   FreeISCLData(L_BOOL bFreeISCLMessages);
   L_VOID   TrackISCLMessage(L_VOID* pMessage);
   L_VOID   FreeISCLMessages(L_BOOL bFreeAll);
   
   static L_TCHAR* GetWindowNetClassName( );

   


private:
   L_BOOL                  m_bConnected;
   L_BOOL                  m_bAssociated;
   pLDICOMNETPRIVATEDATA   m_pPrivateData;
   LDicomAssociate         m_AssociateRQ;
   LDicomAssociate         m_AssociateAC;
   LDicomFile              m_SendFile;
   LDicomDS                m_SendCS;
   LDicomFile              m_ReceiveFileCS;
   LDicomFile              m_ReceiveFileDS;
   LDicomDS                *m_pReceiveCS;
   LDicomDS                *m_pReceiveDS;   
   L_TCHAR                 m_szPath[_MAX_PATH];
   DICOMNETCALLBACK        m_Callback;
   static HINSTANCE        m_hLibrary;
   static HINSTANCE        m_hLibrary2;
   static HINSTANCE        m_hLibCry;
   static HINSTANCE        m_hLibTLS;
#if defined(FOR_UWP)
   L_BOOL                  m_bListening;
#endif

#if defined(FOR_MANAGED)
   static L_INT            m_nManagedAppDomain ;

#endif

#if defined(FOR_UWP) || defined(FOR_UNIX)
public:
#endif
   L_UINT16 GetTS       (L_BOOL bCommand, L_CHAR *pszUID);
   L_INT    Send        (L_CHAR *pBuffer, L_UINT32 nBytes);
   L_VOID   Receive     (L_INT nError, L_UCHAR nType, L_UCHAR *pBuffer, L_UINT32 nBytes);
   L_VOID   ReceiveData (L_UCHAR nPresentationID, LDicomDS *pCS, LDicomDS *pDS);
   L_INT    SendData    (L_BOOL bCommand, L_UCHAR nPresentationID, LDicomDS *pDS);

#if defined(FOR_UNIX)
   static L_INT   GetError(L_UINT32 nError);
#endif

private:
    L_VOID   SafeReceiveData(L_UCHAR nPresentationID, LDicomDS *pCS, LDicomDS *pDS);

#if !defined(FOR_UWP) && !defined(FOR_UNIX)
   static L_INT   GetError(L_UINT32 nError);
#else
#if !defined(FOR_UNIX)
   static L_INT GetError(Windows::Networking::Sockets::SocketErrorStatus status);
#endif
#endif
   friend LRESULT CALLBACK L_NetWindowCallback (HWND hWnd, UINT nMessage, WPARAM wParam, LPARAM lParam);
// added for ISCL compliance
   // private members:
   L_UINT32 m_nTLSError;
   L_BOOL   m_bInTransmission;    // set when a transmission is processed
                              // not set when the ISCL layer is ready to accept another job (send/receive)
         // differs from m_Status: m_Status keep his value after exiting (w/ error) from a transmit job)

//   L_BOOL   m_bIsServer;      // to know if I call OnAccept or OnConnect
   L_UINT32 m_SecurityStandard;     // choose between DICOM_ISCL, DICOM_TLS and DICOM_NO_SECURITY
   L_UCHAR  m_AuthData[128];
   L_UCHAR  m_PeerAuthData[128];
   L_UINT32 m_nAuthDataLength, m_nPeerAuthDataLength;
   L_UINT32 m_nDelay_ms;    // wait time before timeout error, in milliseconds - not usable w/ LEADtk

   L_UINT32 m_nMaxCommBlockLength;   // max acceptable, automatically = 8kB
   L_UINT32 m_nCommBlockLength;        // negotiated block size
   L_UINT32 m_nMaxMessageLength;     // the size of the message the object (server or client) is able to send/receive
   L_UINT32 m_nPeerRequestedMsgLength; // the size the other comm end tried to send


   L_UINT32 m_CryptAlg, m_PeerCryptAlg;
   L_UINT32 m_MACAlg, m_PeerMACAlg;   // DESMAC or MD5 or none. MUST be the same for communication

   L_UINT32 m_Status, m_StatusOld;    // internal status (communication wise) and previous status

   L_UINT32 m_mutualAuthAlg; // only 4way 3pass is defined in standard
   L_UINT64 m_AuthKey[8];    // the keys for  mutual auth
   L_UINT64 m_EncryptKey[8]; // the keys used for encryption
   L_UINT32 m_nAuthKeyId, m_nEncryptKeyId;  // 0-based indexes
            // m_nEncryptKeyId is KEY_ONE to KEY_EIGHT or UNIQUE_KEYS
            // ATTN: if uniques keys, then every new message is sent with a key that is negotiated at that moment
   L_UINT64 m_sessionKey;         // this is the key used for en/decryption. It is initialized to the correct key
         // or takes the value negotiated during a "Random number for generating session key" request/response

   L_BOOL   m_bUseAutoChangeKeys;

   L_UINT32 m_nRequestedSendLength;
   L_UINT32 m_nCurrentSendLength;
   L_UCHAR  m_cCurrentType;

   L_UINT32 m_nISCLError;  // used because the function of treating messages does not return values
   L_UINT64 m_n64ServerChallenge, m_n64ServerResponse, m_n64ClientChallenge, m_n64ClientResponse;
         // even if looks weird, the server generates n64ChallengeServer and n64ResponseClient
         // so I check the n64ChServer and n64RespServer if match - it is a n64RespForServerChallenge



   L_UCHAR m_ivec[8];      // m_ivec is the initialization vector for encryption with DES CBC
            // it is set at 0 in connect and accept. If the DESCBC_CHAIN_IVEC_OVER_SIGNATURE or DESCBC_CHAIN_IVEC_OVER_MAC are
            // NOT set, the ivec is set to 0 after every encrypt operation

   L_UCHAR m_sSignature[24];     // I don't use dynamic allocated memory
   L_UCHAR m_sEncryptedSignature[24];

   L_CHAR *m_pRecvEncryptedData, *m_pRecvDecryptedData;
   L_UINT32 m_nRequestedDataLength, m_nRecvDataIndex, m_nRecvDecryptedLength;

   //L_BOOL m_CreateDS;
   L_BOOL m_bReferenceCount;

// private (implementation) methods:

   L_UINT32 Sign(L_VOID *pBuffer, L_UINT32 nLength, L_VOID *pSign, L_UINT32 *nOutLength);
         // generates a MAC code for the data from pBuffer using the current MAC method
         // the length of the MAc is 64 bits for DESMAC and 128 bits for MD5


   L_UINT32 CryptSendDataISCL(L_CHAR *pBuffer, L_UINT32 nLength);
         // gets data from pBuffer and sends through network, encrypted w/ current encryption algorithm
   L_UINT32 CryptSendMACISCL(L_CHAR *pBuffer, L_UINT32 nLength);
         // send a MAC for data in pBuffer, encrypted w/ current algorithm

   L_UINT32 Get32bDataFromOffset(L_UCHAR *pBuffer, L_UINT32 nOffset);
   L_UINT64 Get64bDataFromOffset(L_UCHAR *pBuffer, L_UINT32 nOffset);

   L_INT32  SendRaw(L_CHAR *pBuffer, L_UINT32 nBytes); // just like Send in non secure mode

   L_UINT32 Encrypt (L_VOID *pBufferIn,
                        L_UINT32 nLength,
                        L_VOID *pBufferOut,
                        L_UINT32 *nLengthOut
                       );
         // add padding to pBufferIn, encrypt nLength bytes from pBufferIn
         // and write the encrypted msg into pBufferOut. nLengthOut is the size of encrypted msg
         // if called with pBufferOut == NULL, then return the required length
         // also when nLengthOut is too small
         // returns DICOM_SUCCES if OK, not 0 if nLengthLut too small
         // nLengthOut is updated to the necessary size
         // ivec is the initialization vector. It is used to chain the previous state for the DES CBC encryption algorithm
         // ivec is a 8 bytes array

   L_UINT32 Decrypt (L_VOID *pBufferIn,
                        L_UINT32 nLength,
                        L_VOID *pBufferOut,
                        L_UINT32 *nLengthOut
                       );
         // ATTN: MiDecrypt uses an BufferOut capable to contain a number of
         // blocks (is longer with at most 8 bytes than the actual decrypted message)
         // returns DICOM_SUCCESS if data decrypted and padding removed. Update nLengthOut to correct length of decrypted message
         // return error if decryption failed (could not clear the padding from the end)
         // ivec is the initialization vector. It is used to chain the previous state for the DES CBC encryption algorithm
         // ivec is a 8 bytes array

   L_UINT32 MD5Sign(L_VOID *pBuffer, L_UINT32 nLength, L_VOID *pSign);
      // creates a message authentication code of the L_VOID *pBuffer, put it
      //    into the pSign and returns the length of sign
      // ATTN: as I know the sign method, I know the length of MAC - 16 bytes
   L_UINT32 DESMACSign(L_VOID *pBuffer, L_UINT32 nLength, L_VOID *pSign);
      // this time only 64-bit (8 bytes) data
      // DESMAC use the default key for sign. MD5 does not use key for sign, but at the end
      // the message digest is encrypted with the current encryption key and algorithm (if any)


   L_INT32 LineReset();


   L_INT32  LineConnectionCheckRequest ();
   L_INT32  LineConnectionCheckResponse(L_UINT32 status, L_UINT32 nISCLCommBlockLength);

   L_INT32  MutualAuthRequest          (L_UINT32 mutualAuthMethod,
                                        L_UINT32 mutualKeyPairId
                                       );
   L_INT32  MutualAuthResponse(L_UINT32 status);
   L_INT32  MutualAuthPass1Notification(L_UINT32 status,
                                        L_UINT64 nChallenge,
                                        L_UINT32 nRetGCh
                                       );
   L_INT32  MutualAuthPass2Notification(
                                        L_UINT32 status,
                                        L_UINT64 nResponseCode,
                                        L_UINT64 nChallenge2,
                                        L_UINT32 nOption = 0   // result from GetCh or InternalAuth
                                                                // 0 is OK
                                       );
   L_INT32  MutualAuthPass3Notification(
                                        L_UINT32 status,
                                        L_UINT64 nResponseCode2,
                                        L_UINT32 nOption = 0   // result code from ExtAuth or IntAuth
                                                                // 0 is OK
                                       );
   L_INT32  MutualAuthCompletion(L_UINT32 nAuthCode);
   L_INT32  SendTransmissionRequest    (L_UINT32 EncryptMethod, 
                                        L_UINT32 nEncryptKeyId,
                                        L_UINT32 MessageAuthMethod,
                                        L_UINT32 nMessageLength
                                       );
   L_INT32  SendTransmissionResponse   (L_UINT32 acknoledgeCode,
                                        L_UINT32 nMessageLength
                                       );
   L_INT32  RandomNoForSessionKeyRequest(
                                        L_UINT64 nRndNoForSessionKey,
                                        L_UINT32 nResultCode
                                       );
   L_INT32  RandomNoForSessionKeyResponse(L_UINT32 nResultCode);

   L_INT32  MsgTransmitNotification    (L_VOID *rawData,
                                        L_UINT32 nSplitMsgLength
                                       );

   L_INT32  MsgAuthCode                (L_VOID *pAuthCode,
                                        L_UINT32 nAuthCodeLength
                                       );

   L_INT32  ThroughModeTransmission    (L_VOID *rawData,
                                        L_UINT32 nMessageLength  // is not limited by comm block size
                                       );

   L_INT32  LineDisconnectionRequest();
   L_INT32  LineDisconnectionResponse(L_UINT32 status);

   L_INT32  SetHeader                  (L_VOID *pBuffer,
                                        L_UINT32 indicator,
                                        L_UINT32 messageId,
                                        L_UINT32 nDataLength,
                                        L_UINT32 option,
                                        L_UINT32 timeStamp,
                                        L_UINT32 errNo,
                                        L_UINT32 stuff32_1 = 0,
                                        L_UINT32 stuff32_2 = 0
                                       );

   L_INT32  CreateEmptyMessage(L_VOID **pBuffer, L_UINT32 nLength);
      // allocates a area of size 32+nLength (header and data);

   L_INT32  CopyMessageData(L_VOID *pPacket, L_UINT32 nOffset, L_VOID *pData, L_UINT32 nLength);
      // copy raw data into message data area starting from offset bytes

   L_INT32  OnISCLPacketSend(L_INT nError, L_UINT32 nMsgId, L_UINT32 nLength);

// end of added for ISCL

// added for TLS compliance

   L_SSL_CTX *m_pCtx;

   L_CIPHERSUITE m_ciphersuites[MAX_CIPHERSUITE_COUNT];
   L_CIPHERSUITE m_ActualCiphersuite;
   L_VOID InitializePrivateData(L_TCHAR *pszPath);
   L_INT UpdateCTX(L_SSL_CTX_CREATE *pCtx);

   static L_INT VerifyCB(int ok, X509_STORE_CTX *store);
   static L_INT PrivateKeyPasswordCB(L_CHAR *pszPassword, L_INT nSize, L_INT nFlag, L_VOID *userdata);

public:
// not to be documented
   L_BOOL   m_bISCLConnected;
   L_UINT32 m_nTLSVerifyMode;
   SSL *m_TLSConn;
   static LDicomNet *m_pNetTLS[512];
   HWND             m_hWnd;
   L_VOID SetIsSecureConnected(L_BOOL bIsConnected);
   L_BOOL GetIsSecureConnected();

   L_VOID SetHandshakeDebug(L_BOOL isDebug, L_VOID (*myfn)(LDicomNet *pDic, const char *TLS_STATUS, int ret));

// end of not to be documented
// end of added for TLS

#if defined(FOR_UNIX)
   L_VOID* m_nativeEvent;

   L_UINT32              m_nIndex;
   L_UINT32              m_nLength;
   L_CHAR                *m_pBuffer;
#endif


   private:
   L_VOID Initialize(L_TCHAR *pszPath, L_INT32 nMode);

public:
   L_INT Initialize(L_TCHAR *pszPath, L_INT32 nMode, pL_SSL_CTX_CREATE pCtxCreate);

   L_VOID EnableReferenceCounting(L_BOOL bEnable);

   L_INT GetDefaultSocketOptions(pDICOMSOCKETOPTIONS pOptions, L_UINT uStructSize);
   L_INT GetSocketOptions(pDICOMSOCKETOPTIONS pOptions, L_UINT uStructSize);
   L_INT SetSocketOptions(pDICOMSOCKETOPTIONS pOptions);

   L_VOID    ServerClose ( ) ;

   L_VOID EnableOptimizedMemorySend(L_BOOL bEnable);
   L_BOOL IsOptimizedMemorySendEnabled();

   L_VOID SetFlags(L_UINT32 uDicomNetFlags);
   L_UINT32 GetFlags();

   static L_VOID Breathe();

#if !defined(FOR_UWP) && !defined(FOR_UNIX)
   friend class DicomDataSerializer;
   friend L_INT ProcessAndSendDataSerializers(SOCKET hSocket, L_BOOL& bContinueLater);
   friend class CCertificateCache;

private:
   L_INT SendData_Serilizers_Impl(L_BOOL bCommand, L_UCHAR nPresentationID, LDicomDS *pDS);
   L_UINT32 GetAssociationMaxSize();
protected:
   static L_UINT16 _GetTS (L_BOOL bCommand, L_CHAR *pszUID);
#endif
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)
// modified for security
   // added parameter nMode
   L_LTDIC_API HDICOMNET EXT_FUNCTION L_DicomCreateNet                  (L_TCHAR *pszPath, L_INT32 nMode);
   L_LTDIC_API HDICOMNET EXT_FUNCTION L_DicomCreateNetExt               (L_TCHAR *pszPath, L_INT32 nMode, pL_SSL_CTX_CREATE pCtxCreate);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomInitializeNet              (HDICOMNET hNet, L_TCHAR *pszPath, L_INT32 nMode, pL_SSL_CTX_CREATE pCtxCreate);
// end of modified for security


// added for ISCL compliance
#if !defined(FOR_UNIX)
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetMaxCommBlockLengthISCL(HDICOMNET hNet, L_UINT32 nCommBlockLength);   // maximum communication block size, there are performance
         // advantages if a comm block of ISCL is included into a TCP packet
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetCommBlockLengthISCL(HDICOMNET hNet);     // return the comm block size negotiated
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetMaxMessageLengthISCL(HDICOMNET hNet, L_UINT32 nMsgLength);     // the maximum message length that can be processed - 1MB, 2MB and so on

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetMutualAuthAlgISCL(HDICOMNET hNet, L_UINT32 mutualAuthMode);       // only 4way 3pass
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetDefaultEncryptionISCL(HDICOMNET hNet, L_UINT32 EncryptionMode);   // bulk data encryption algorithm
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetDefaultSigningISCL(HDICOMNET hNet, L_UINT32 SignMode);            // message authentication algorithm
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetPeerEncryptionISCL(HDICOMNET hNet);   // can be checked to see what algorithm of communication the sender tries to use
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetPeerMACISCL(HDICOMNET hNet);      // ATTN: if the crypt/MAC algorithm differs, the message is dropped and the GetPeerEncryption()/GetPeerMAC() will tell me
                                    // the algorithms of crypt/MAC used by the client

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetErrorSecure(HDICOMNET hNet);       // returns the m_nISCLError in ISCL case, or m_nTLSError in case of TLS



         // functions described in ISO 7816-4


   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetAuthDataISCL(HDICOMNET hNet, L_VOID *pBuffer, L_UINT32 nLength);    // nLength = 1...128
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetPeerAuthDataISCL(HDICOMNET hNet, L_VOID *pBuffer, L_UINT32 *nLength);
         // if nLength not between 1 and 128 bytes, error
         // used to set or obtain the authentication data exchanged during the mutual authentication (connectISCL/acceptISCL)

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetPeerRequestedMessageLengthISCL(HDICOMNET hNet);      // used if local end refuse to receive
         // peer mesage because message size bigger than local end max
         // example: a server can use max 1MB message, but a client could try to send a 16 MB message

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetMutualAuthKeyISCL(HDICOMNET hNet, L_UINT32 nIndex, L_UINT64 nKey);      // key used during mutual authentication
            // it looks unused for the V1.00 of ISCL
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetIndexForMutualAuthISCL(HDICOMNET hNet, L_UINT32 nIndex);
            // index from 1 to 8 for the mutual auth key - see the remark 2 lines up
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetEncryptKeyISCL(HDICOMNET hNet, L_UINT32 nIndex, L_UINT64 key);
            // index from 1 to 8 for the encryption key - used to load communication keys
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomSetIndexForEncryptISCL(HDICOMNET hNet, L_UINT32 nIndex);
            // index from 1 to 8 to select the encryption key
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetIndexForEncryptISCL(HDICOMNET hNet);
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetIndexForMutualAuthISCL(HDICOMNET hNet);

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetStatusISCL(HDICOMNET hNet);                          // return the internal status of the object.
         // Description of internal status will be added in docs, see also the source

   L_LTDIC_API L_BOOL   EXT_FUNCTION L_DicomIsISCLQueueEmpty(HDICOMNET hNet);
#endif //#if !defined(FOR_UNIX)

   L_LTDIC_API L_INT    EXT_FUNCTION L_DicomCloseForced(HDICOMNET hNet, L_BOOL bForced);

#if !defined(FOR_UNIX)
   L_LTDIC_API L_INT32  EXT_FUNCTION L_DicomSendNonSecureISCL(HDICOMNET hNet, L_UCHAR *pBuffer, L_UINT32 nBytes);

   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetSecureMode(HDICOMNET hNet);
// end of added for ISCL compliance

// added for TLS compliance
   L_LTDIC_API L_CIPHERSUITE EXT_FUNCTION L_DicomGetCipherFromIndexTLS(HDICOMNET hNet, L_UINT32 nIndex);
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomSetCipherToIndexTLS(HDICOMNET hNet, L_UINT32 nIndex, L_CIPHERSUITE cipher);
   L_LTDIC_API L_CIPHERSUITE EXT_FUNCTION L_DicomGetCiphersuiteTLS(HDICOMNET hNet);
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetEncryptionAlgorithmTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);   
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetAuthenticationAlgorithmTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);   
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetIntegrityAlgorithmTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);   
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetKeyExchangeAlgorithmTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);   
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetEncryptKeyLengthTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomGetMutualAuthKeyLengthTLS(HDICOMNET hNet, L_CIPHERSUITE cipher);
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomSetClientCertificateTLS(HDICOMNET hNet, L_TCHAR *pszPathToCertificateFile, L_UINT32 nCertType, L_TCHAR *pszPathToKeyFile);
   L_LTDIC_API L_UINT32      EXT_FUNCTION L_DicomSetServerCertificateTLS(HDICOMNET hNet, L_TCHAR *pszPathToCertificateFile, L_UINT32 nCertType, L_TCHAR *pszPathToKeyFile);
   L_LTDIC_API L_VOID        EXT_FUNCTION L_DicomSetIsSecureConnected(HDICOMNET hNet, L_BOOL bIsConnected);
   L_LTDIC_API L_BOOL        EXT_FUNCTION L_DicomGetIsSecureConnected(HDICOMNET hNet);
#endif

// end of added for TLS compliance

   L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomFreeNet                    (HDICOMNET hNet);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomStartUp                    (L_VOID);
   L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomShutDown                   (L_VOID);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetOpenSslVersion          (pDICOMOPENSSLVERSION pDicomOpenSslVersion, L_UINT uStructSize, L_UINT uFlagsReserved);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomConnect                    (HDICOMNET hNet, L_TCHAR *pszHostAddress, L_UINT nHostPort, L_TCHAR *pszPeerAddress, L_UINT nPeerPort);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomConnectExt                 (HDICOMNET hNet, L_TCHAR *pszHostAddress, L_UINT nHostPort, L_TCHAR *pszPeerAddress, L_UINT nPeerPort, L_INT nIpType);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomListen                     (HDICOMNET hNet, L_TCHAR *pszHostAddress, L_UINT nHostPort, L_INT nNbPeers);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomListenExt                  (HDICOMNET hNet, L_TCHAR *pszHostAddress, L_UINT nHostPort, L_INT nNbPeers, L_INT nIpType);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomAccept                     (HDICOMNET hNet, HDICOMNET hPeer);
   L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomClose                      (HDICOMNET hNet);
   
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendAssociateRequest       (HDICOMNET hNet, HDICOMPDU hPDU);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendAssociateAccept        (HDICOMNET hNet, HDICOMPDU hPDU);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendAssociateReject        (HDICOMNET hNet, L_UCHAR nResult, L_UCHAR nSource, L_UCHAR nReason);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendData                   (HDICOMNET hNet, L_UCHAR nPresentationID, HDICOMDS hCS, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendReleaseRequest         (HDICOMNET hNet);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendReleaseResponse        (HDICOMNET hNet);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendAbort                  (HDICOMNET hNet, L_UCHAR nSource, L_UCHAR nReason);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCStoreRequest          (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nPriority, L_TCHAR *pszMoveAE, L_UINT16 nMoveMessageID, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCStoreResponse         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCFindRequest           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCFindResponse          (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCGetRequest            (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCGetResponse           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCMoveRequest           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nPriority, L_TCHAR *pszMoveAE, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCMoveResponse          (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus, L_UINT16 nRemaining, L_UINT16 nCompleted, L_UINT16 nFailed, L_UINT16 nWarning, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCCancelRequest         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCEchoRequest           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendCEchoResponse          (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_UINT16 nStatus);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNReportRequest         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nEvent, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNReportResponse        (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nEvent, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNGetRequest            (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT32 *pnAttribute, L_UINT16 nCount);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNGetResponse           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNSetRequest            (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNSetResponse           (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNActionRequest         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nAction, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNActionResponse        (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, L_UINT16 nAction, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNCreateRequest         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNCreateResponse        (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, HDICOMDS hDS);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNDeleteRequest         (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomSendNDeleteResponse        (HDICOMNET hNet, L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR *pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);

   L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsActivated                (HDICOMNET hNet);
   L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsConnected                (HDICOMNET hNet);
   L_LTDIC_API L_BOOL    EXT_FUNCTION L_DicomIsAssociated               (HDICOMNET hNet);

   L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetQueueSend               (HDICOMNET hNet);

   L_LTDIC_API HDICOMNET EXT_FUNCTION L_DicomGetServer                  (HDICOMNET hNet);
   L_LTDIC_API L_UINT32  EXT_FUNCTION L_DicomGetClientCount             (HDICOMNET hNet);
   L_LTDIC_API HDICOMNET EXT_FUNCTION L_DicomGetClient                  (HDICOMNET hNet, L_UINT nIndex);

   L_LTDIC_API HDICOMDS  EXT_FUNCTION L_DicomGetCommandSet              (HDICOMNET hNet);

   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetHostInfo                (HDICOMNET hNet, L_TCHAR *pszAddress, L_UINT32 AddressSizeInWords, L_UINT *pnPort);
   L_LTDIC_API L_INT     EXT_FUNCTION L_DicomGetPeerInfo                (HDICOMNET hNet, L_TCHAR *pszAddress, L_UINT32 AddressSizeInWords, L_UINT *pnPort);

   L_LTDIC_API HDICOMPDU EXT_FUNCTION L_DicomGetAssociate               (HDICOMNET hNet);

   L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomSetCallback                (HDICOMNET hNet, pDICOMNETCALLBACK pCallback);
   L_LTDIC_API L_VOID    EXT_FUNCTION L_DicomSetCallbackExt             (HDICOMNET hNet, pDICOMNETCALLBACKEXT pCallbackExt);

   L_LTDIC_API L_INT    EXT_FUNCTION L_DicomSetSocketOptions            (HDICOMNET hNet, pDICOMSOCKETOPTIONS pOptions);
   L_LTDIC_API L_INT    EXT_FUNCTION L_DicomGetSocketOptions            (HDICOMNET hNet, pDICOMSOCKETOPTIONS pOptions, L_UINT uStructSize);
   L_LTDIC_API L_INT    EXT_FUNCTION L_DicomGetDefaultSocketOptions     (HDICOMNET hNet, pDICOMSOCKETOPTIONS pOptions, L_UINT uStructSize);

   L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomServerClose                 (HDICOMNET hNet);

   L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomEnableOptimizedMemorySend  (HDICOMNET hNet, L_BOOL bEnabled);
   L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomSetFlags                   (HDICOMNET hNet, L_UINT32 uDicomNetFlags);
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomGetFlags                   (HDICOMNET hNet);

   L_LTDIC_API L_BOOL   EXT_FUNCTION L_DicomIsOptimizedMemorySendEnabled (HDICOMNET hNet);
   L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomEnableReferenceCounting      (HDICOMNET hNet, L_BOOL bEnable);
   L_LTDIC_API L_VOID   EXT_FUNCTION L_DicomBreathe(L_VOID);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)
#endif //#if !defined (EXCLUDE_DICOM_FUNCTIONS)
//============= CLASS ==========================================================
// SOP/Meta SOP Classes
#define PRINTSCU_BASIC_GRAYSCALE_PM_META_SOP_CLASS           0x01
#define PRINTSCU_BASIC_COLOR_PM_META_SOP_CLASS               0x02
#define PRINTSCU_PULL_STORED_PM_META_SOP_CLASS               0x04
#define PRINTSCU_BASIC_ANNOTATION_BOX_SOP_CLASS              0x08
#define PRINTSCU_BASIC_PRINT_IMAGE_OVERLAY_BOX_SOP_CLASS     0x10
#define PRINTSCU_PRESENTATION_LUT_SOP_CLASS                  0x20
#define PRINTSCU_PRINT_JOB_SOP_CLASS                         0x40
#define PRINTSCU_PRINTER_CONFIGURATION_RETRIEVAL_SOP_CLASS   0x80

// Statuses
#define PRINTSCU_STATUS_CONNECT                                 1
#define PRINTSCU_STATUS_SEND_ASSOCIATE_RQ                       2
#define PRINTSCU_STATUS_RECEIVE_ASSOCIATE_RJ                    3
#define PRINTSCU_STATUS_RECEIVE_ASSOCIATE_AC                    4
#define PRINTSCU_STATUS_SEND_RELEASE_RQ                         5
#define PRINTSCU_STATUS_CLOSE                                   6
#define PRINTSCU_STATUS_RECEIVE_RELEASE_RP                      7
#define PRINTSCU_STATUS_RECEIVE_RELEASE_RQ                      8
#define PRINTSCU_STATUS_SEND_RELEASE_RP                         9
#define PRINTSCU_STATUS_RECEIVE_ABORT                           10
#define PRINTSCU_STATUS_SEND_CREATE_FILM_SESSION_RQ             11
#define PRINTSCU_STATUS_RECEIVE_CREATE_FILM_SESSION_RSP         12
#define PRINTSCU_STATUS_SEND_UPDATE_FILM_SESSION_RQ             13
#define PRINTSCU_STATUS_RECEIVE_UPDATE_FILM_SESSION_RSP         14
#define PRINTSCU_STATUS_SEND_PRINT_FILM_SESSION_RQ              15
#define PRINTSCU_STATUS_RECEIVE_PRINT_FILM_SESSION_RSP          16
#define PRINTSCU_STATUS_SEND_DELETE_FILM_SESSION_RQ             17
#define PRINTSCU_STATUS_RECEIVE_DELETE_FILM_SESSION_RSP         18
#define PRINTSCU_STATUS_SEND_CREATE_FILM_BOX_RQ                 19
#define PRINTSCU_STATUS_RECEIVE_CREATE_FILM_BOX_RSP             20
#define PRINTSCU_STATUS_SEND_UPDATE_FILM_BOX_RQ                 21
#define PRINTSCU_STATUS_RECEIVE_UPDATE_FILM_BOX_RSP             22
#define PRINTSCU_STATUS_SEND_PRINT_FILM_BOX_RQ                  23
#define PRINTSCU_STATUS_RECEIVE_PRINT_FILM_BOX_RSP              24
#define PRINTSCU_STATUS_SEND_DELETE_FILM_BOX_RQ                 25
#define PRINTSCU_STATUS_RECEIVE_DELETE_FILM_BOX_RSP             26
#define PRINTSCU_STATUS_SEND_UPDATE_IMAGE_BOX_RQ                27
#define PRINTSCU_STATUS_RECEIVE_UPDATE_IMAGE_BOX_RSP            28
#define PRINTSCU_STATUS_SEND_UPDATE_ANNOTATION_BOX_RQ           29
#define PRINTSCU_STATUS_RECEIVE_UPDATE_ANNOTATION_BOX_RSP       30
#define PRINTSCU_STATUS_SEND_GET_PRINTER_INFO_RQ                31
#define PRINTSCU_STATUS_RECEIVE_GET_PRINTER_INFO_RSP            32
#define PRINTSCU_STATUS_SEND_GET_PRINT_JOB_INFO_RQ              33
#define PRINTSCU_STATUS_RECEIVE_GET_PRINT_JOB_INFO_RSP          34
#define PRINTSCU_STATUS_SEND_GET_PRINTER_CONFIG_RQ              35
#define PRINTSCU_STATUS_RECEIVE_GET_PRINTER_CONFIG_RSP          36
#define PRINTSCU_STATUS_SEND_CREATE_PRESENTATION_LUT_RQ         37
#define PRINTSCU_STATUS_RECEIVE_CREATE_PRESENTATION_LUT_RSP     38
#define PRINTSCU_STATUS_SEND_DELETE_PRESENTATION_LUT_RQ         39
#define PRINTSCU_STATUS_RECEIVE_DELETE_PRESENTATION_LUT_RSP     40
#define PRINTSCU_STATUS_SEND_CREATE_OVERLAY_BOX_RQ              41
#define PRINTSCU_STATUS_RECEIVE_CREATE_OVERLAY_BOX_RSP          42
#define PRINTSCU_STATUS_SEND_UPDATE_OVERLAY_BOX_RQ              43
#define PRINTSCU_STATUS_RECEIVE_UPDATE_OVERLAY_BOX_RSP          44
#define PRINTSCU_STATUS_SEND_DELETE_OVERLAY_BOX_RQ              45
#define PRINTSCU_STATUS_RECEIVE_DELETE_OVERLAY_BOX_RSP          46
#define PRINTSCU_STATUS_SEND_CREATE_PULL_PRINT_REQUEST_RQ       47
#define PRINTSCU_STATUS_RECEIVE_CREATE_PULL_PRINT_REQUEST_RSP   48
#define PRINTSCU_STATUS_SEND_PRINT_PULL_PRINT_REQUEST_RQ        49
#define PRINTSCU_STATUS_RECEIVE_PRINT_PULL_PRINT_REQUEST_RSP    50
#define PRINTSCU_STATUS_SEND_DELETE_PULL_PRINT_REQUEST_RQ       51
#define PRINTSCU_STATUS_RECEIVE_DELETE_PULL_PRINT_REQUEST_RSP   52


#define MAX_SIZE   UID_MAX_SIZE + 1


// --- Structures --- //

// Basic Film Box Parameters
typedef struct tagFILMBOXPARAMETERS
{
   L_UINT  uStructSize;
   L_PCTSTR pszImageDisplayFormat;
   L_PCTSTR pszFilmOrientation;
   L_PCTSTR pszFilmSizeID;
   L_PCTSTR pszMagnificationType;
   L_INT32 nMaxDensity;
   L_PCTSTR pszConfigurationInformation;
   L_PCTSTR pszAnnotationDisplayFormatID;
   L_PCTSTR pszSmoothingType;
   L_PCTSTR pszBorderDensity;
   L_PCTSTR pszEmptyImageDensity;
   L_INT32 nMinDensity;
   L_PCTSTR pszTrim;
   L_INT32 nIllumination;
   L_INT32 nReflectedAmbientLight;
   L_PCTSTR pszRequestedResolutionID;

} FILMBOXPARAMETERS, * pFILMBOXPARAMETERS;

// Basic Grayscale/Color Image Box Parameters
typedef struct tagIMAGEBOXPARAMETERS
{
   L_UINT   uStructSize;
   L_INT32  nImagePosition;
   L_PCTSTR  pszPolarity;
   L_PCTSTR  pszMagnificationType;
   L_PCTSTR  pszSmoothingType;
   L_INT32  nMinDensity;
   L_INT32  nMaxDensity;
   L_PCTSTR  pszConfigurationInformation;
   L_DOUBLE dRequestedImageSize;
   L_PCTSTR  pszRequestedDecimateCropBehavior;

} IMAGEBOXPARAMETERS, * pIMAGEBOXPARAMETERS;

// Printer Report Info
typedef struct tagPRINTERREPORTINFO
{
   L_PCTSTR pszPrinterStatusInfo;
   L_PCTSTR pszFilmDestination;
   L_PCTSTR pszPrinterName;

} PRINTERREPORTINFO, * pPRINTERREPORTINFO;

// Printer Info
typedef struct tagPRINTERINFO
{
   L_UINT uStructSize;
   L_TCHAR szPrinterStatus[MAX_SIZE];
   L_TCHAR szPrinterStatusInfo[MAX_SIZE];
   L_TCHAR szPrinterName[MAX_SIZE];
   L_TCHAR szManufacturer[MAX_SIZE];
   L_TCHAR szManufacturerModelName[MAX_SIZE];
   L_TCHAR szDeviceSerialNumber[MAX_SIZE];
   L_TCHAR szSoftwareVersions[MAX_SIZE];
   L_TCHAR szDateOfLastCalibration[MAX_SIZE];
   L_TCHAR szTimeOfLastCalibration[MAX_SIZE];

} PRINTERINFO, * pPRINTERINFO;

// Print Job Report Info
typedef struct tagPRINTJOBREPORTINFO
{
   L_PCTSTR pszExecutionStatusInfo;
   L_PCTSTR pszPrintJobID;
   L_PCTSTR pszFilmSessionLabel;
   L_PCTSTR pszPrinterName;

} PRINTJOBREPORTINFO, * pPRINTJOBREPORTINFO;

// Print Job Info
typedef struct tagPRINTJOBINFO
{
   L_UINT uStructSize;
   L_TCHAR szExecutionStatus[MAX_SIZE];
   L_TCHAR szExecutionStatusInfo[MAX_SIZE];
   L_TCHAR szPrintPriority[MAX_SIZE];
   L_TCHAR szCreationDate[MAX_SIZE];
   L_TCHAR szCreationTime[MAX_SIZE];
   L_TCHAR szPrinterName[MAX_SIZE];
   L_TCHAR szOriginator[MAX_SIZE];

} PRINTJOBINFO, * pPRINTJOBINFO;

// Basic Print Image Overlay Box Parameters
typedef struct tagOVERLAYBOXPARAMETERS
{
   L_UINT  uStructSize;
   L_INT16 nOverlayOriginRow;
   L_INT16 nOverlayOriginColumn;
   L_PCTSTR pszOverlayOrImageMagnification;
   L_INT32 nMagnifyToNumberOfColumns;
   L_PCTSTR pszOverlayMagnificationType;
   L_PCTSTR pszOverlayForegroundDensity;
   L_PCTSTR pszOverlayBackgroundDensity;
   L_PCTSTR pszOverlaySmoothingType;

} OVERLAYBOXPARAMETERS, * pOVERLAYBOXPARAMETERS;

// Stored Print Storage SOP Instance Info
typedef struct tagSTOREDPRINTSTORAGEINSTANCEINFO
{
   L_UINT  uStructSize;
   L_PCTSTR pszRetrieveAETitle;
   L_PCTSTR pszReferencedSOPInstanceUID;
   L_PCTSTR pszStudyInstanceUID;
   L_PCTSTR pszSeriesInstanceUID;
   L_PCTSTR pszPatientID;

} STOREDPRINTSTORAGEINSTANCEINFO, * pSTOREDPRINTSTORAGEINSTANCEINFO;

// Pull Print Request Parameters
typedef struct tagPULLPRINTREQUESTPARAMETERS
{
   L_UINT  uStructSize;
   L_INT32 nNumberOfCopies;
   L_PCTSTR pszPrintPriority;
   L_PCTSTR pszMediumType;
   L_PCTSTR pszFilmDestination;
   L_PCTSTR pszColorImagePrintingFlag;
   L_PCTSTR pszAnnotationFlag;
   L_PCTSTR pszImageOverlayFlag;
   L_PCTSTR pszPresentationLUTFlag;
   L_PCTSTR pszImageBoxPresentationLUTFlag;
   L_PCTSTR pszConfigurationInformation;
   L_PCTSTR pszFilmSessionLabel;
   L_INT32 nMemoryAllocation;
   L_PCTSTR pszCollationFlag;
   L_INT32 nIllumination;
   L_INT32 nReflectedAmbientLight;
   L_PCTSTR pszOwnerID;

} PULLPRINTREQUESTPARAMETERS, * pPULLPRINTREQUESTPARAMETERS;

typedef L_VOID *HDICOMPRINTSCU;
typedef L_VOID (pEXT_CALLBACK PRINTSCUSTATUSCALLBACK)        (HDICOMPRINTSCU hCU, L_UINT16 uStatus, L_UINT16 uOperationStatus, L_VOID* pUserData);
typedef L_VOID (pEXT_CALLBACK PRINTSCUPRINTERREPORTCALLBACK) (HDICOMPRINTSCU hCU, L_UINT16 uEventTypeID, const pPRINTERREPORTINFO pReportInformation, L_VOID* pUserData);
typedef L_VOID (pEXT_CALLBACK PRINTSCUPRINTJOBREPORT)        (HDICOMPRINTSCU hCU, const L_TCHAR * pszPrintJobInstanceUID, L_UINT16 uEventTypeID, const pPRINTJOBREPORTINFO pReportInformation, L_VOID* pUserData);

typedef struct _DICOMPRINTSCUCALLBACK
{
   PRINTSCUSTATUSCALLBACK           pfnStatus;
   PRINTSCUPRINTERREPORTCALLBACK    pfnPrinterReport;
   PRINTSCUPRINTJOBREPORT           pfnPrintJobReport;
   L_VOID                          *pUserData;
} DICOMPRINTSCUCALLBACK, *pDICOMPRINTSCUCALLBACK;

#if !defined(FOR_UWP)

#if !defined (EXCLUDE_DICOM_FUNCTIONS)
#if defined(__cplusplus)
class L_LTDIC_CLASS LDicomPrintSCU : public LDicomNet
{
public:
   LDicomDS m_PrinterConfiguration;
  
public:
   LDicomPrintSCU(L_TCHAR * pszPath = NULL);
   virtual ~LDicomPrintSCU();

   virtual L_VOID OnStatus(L_UINT16 uStatus, L_UINT16 uOperationStatus);
   L_VOID SetTimeout(L_UINT16 uTimeout);

   // Association Functions
   L_INT  Associate(const L_TCHAR * pszPrintScpIP, L_UINT uPrintScpPort, const L_TCHAR * pszCalledTitle, const L_TCHAR * pszCallingTitle, L_UINT16 uSupportedClasses);
   L_INT  Associate(const L_TCHAR * pszPrintScuIP, L_UINT uPrintScuPort, const L_TCHAR * pszPrintScpIP, L_UINT uPrintScpPort, const L_TCHAR *  pszCalledTitle, const L_TCHAR * pszCallingTitle, L_UINT16 uSupportedClasses);
   L_VOID GetAssociateRejectInfo(L_UCHAR* pnResult, L_UCHAR* pnSource, L_UCHAR* pnReason) const;
   L_BOOL IsClassSupported(L_UINT16 uClass);
   L_INT  Release();
   L_VOID GetAbortInfo(L_UCHAR* pnSource, L_UCHAR* pnReason) const;

   L_UINT16 GetLastOperationStatus() const;

   // Basic Film Session Functions
   L_INT   CreateFilmSession(const pFILMSESSIONPARAMETERS pParameters, L_BOOL bColorPrintManagement = FALSE);
   const   L_TCHAR* GetFilmSessionInstanceUID() const;
   L_INT   UpdateFilmSession(const pFILMSESSIONPARAMETERS pParameters);
   L_INT   PrintFilmSession();
   L_INT   DeleteFilmSession();
   L_INT   GetDefaultFilmSessionParameters(pFILMSESSIONPARAMETERS pParameters, L_UINT uStructSize) const;

   // Basic Film Box Functions
   L_INT   CreateFilmBox(const pFILMBOXPARAMETERS pParameters, const L_TCHAR * pszRefPresLUTInstanceUID = NULL);
   const   L_TCHAR*  GetFilmBoxInstanceUID() const;
   L_INT   UpdateFilmBox(const pFILMBOXPARAMETERS pParameters, const L_TCHAR * pszRefPresLUTInstanceUID = NULL);
   L_INT   PrintFilmBox();
   L_INT   DeleteFilmBox();
   L_INT   GetDefaultFilmBoxParameters(pFILMBOXPARAMETERS pParameters, L_UINT uStructSize) const;

   // Basic Grayscale/Color Image Box Functions
   L_UINT32 GetImageBoxesCount() const;
   L_PCTSTR GetImageBoxInstanceUID(L_UINT32 uIndex) const;
   L_INT    UpdateImageBox(const L_TCHAR * pszImageBoxInstanceUID, LDicomDS* pImage,
                           const L_UINT32 uIndex,
                           const pIMAGEBOXPARAMETERS pParameters,
                           const L_TCHAR * pszRefImageOverlayBoxInstanceUID = NULL,
                           const L_TCHAR * pszRefPresLUTInstanceUID = NULL);
   L_INT    GetDefaultImageBoxParameters(pIMAGEBOXPARAMETERS pParameters, L_UINT uStructSize) const;
   L_VOID   FreeImageBoxesInstanceUIDs();

   // Printer Functions
   virtual L_VOID OnPrinterReport(L_UINT16 uEventTypeID, const pPRINTERREPORTINFO pReportInfo);
   L_INT GetPrinterInfo(const pPRINTERINFO pRequiredPrinterInfo, L_BOOL bBasicPrintManagement, L_BOOL bColorPrintManagement);
   L_INT GetPrinterInfo(pPRINTERINFO pPrinterInfo, L_UINT uStructSize) const;

   // Basic Annotation Box Functions
   L_UINT32 GetAnnotationBoxesCount() const;
   L_PCTSTR  GetAnnotationBoxInstanceUID(L_UINT32 uIndex) const;
   L_INT    UpdateAnnotationBox(const L_TCHAR * pszAnnotationBoxInstanceUID, L_UINT16 uAnnotationPosition, const L_TCHAR * pszTextString);
   L_VOID   FreeAnnotationBoxesInstanceUIDs();

   // Presentation LUT Functions
   L_INT   CreatePresentationLUT(LDicomDS* pPresentationLUT, const L_TCHAR * pszPresentationLUTShape = NULL);
   const   L_TCHAR* GetPresentationLUTInstanceUID() const;
   L_INT   DeletePresentationLUT(const L_TCHAR *  pszPresentationLUTInstanceUID);

   // Basic Print Image Overlay Box Functions
   L_INT   CreateOverlayBox(LDicomDS* pOverlay, const pOVERLAYBOXPARAMETERS pParameters);
   const   L_TCHAR* GetOverlayBoxInstanceUID() const;
   L_INT   UpdateOverlayBox(const L_TCHAR * pszOverlayBoxInstanceUID, LDicomDS* pOverlay, const pOVERLAYBOXPARAMETERS pParameters, L_BOOL bUpdateOverlayOrigin);
   L_INT   DeleteOverlayBox(const L_TCHAR * pszOverlayBoxInstanceUID);
   L_INT   GetDefaultOverlayBoxParameters(pOVERLAYBOXPARAMETERS pParameters, L_UINT uStructSize) const;

   // Pull Print Request Functions
   L_INT   CreatePullPrintRequest(const pSTOREDPRINTSTORAGEINSTANCEINFO InstancesInfo,
                                  L_UINT32 uInstancesCount,
                                  const pPULLPRINTREQUESTPARAMETERS pParameters);
   const   L_TCHAR* GetPullPrintRequestInstanceUID() const;
   L_INT   PrintPullPrintRequestSession();
   L_INT   DeletePullPrintRequest();
   L_INT   GetDefaultPullPrintRequestParameters(pPULLPRINTREQUESTPARAMETERS pParameters, L_UINT uStructSize) const;

   // Print Job Functions
   const   L_TCHAR* GetPrintJobInstanceUID() const;
   virtual L_VOID OnPrintJobReport(const L_TCHAR * pszPrintJobInstanceUID, L_UINT16 uEventTypeID, const pPRINTJOBREPORTINFO pReportInfo);
   L_INT GetPrintJobInfo(const L_TCHAR * pszPrintJobInstanceUID, const pPRINTJOBINFO pRequiredPrintJobInfo = NULL);
   L_INT GetPrintJobInfo(pPRINTJOBINFO pPrintJobInfo, L_UINT uStructSize) const;

   // Printer Configuration Retrieval Functions (the retrieved Printer Configuration is stored
   // in m_PrinterConfiguration)
   L_INT  GetPrinterConfiguration();

   L_VOID SetCallback(DICOMPRINTSCUCALLBACK* pCallback);

private:
   DICOMPRINTSCUCALLBACK m_Callback;

   HANDLE   m_hOpCompleteEvent;
   L_INT    m_nOperationResult;
   L_UINT16 m_uTimeout; // In seconds

   L_TCHAR  m_szCalledTitle[MAX_SIZE];
   L_TCHAR  m_szCallingTitle[MAX_SIZE];

   L_UINT16 m_uClassesSupportedByScu; // Specified when calling LDicomPrintSCU::Associate

   static struct ClassesInfo
   {
      L_UINT16 uClass;
      L_CHAR*  pszClassUID;

   } m_Classes[];

   struct
   {
      L_UCHAR m_nResult;
      L_UCHAR m_nSource;
      L_UCHAR m_nReason;

   } m_AssociateRejectInfo;

   struct
   {
      L_UCHAR m_nSource;
      L_UCHAR m_nReason;

   } m_AbortInfo;

   L_UINT16 m_uMessageID;
   L_BOOL   m_bColorPrint;
   L_UINT16 m_uOutstandingOperation; // Note: We operate synchronously
   L_UINT16 m_uLastOperationStatus;

   L_TCHAR m_szFilmSessionInstanceUID[MAX_SIZE];
   L_TCHAR m_szFilmBoxInstanceUID[MAX_SIZE];
   L_TCHAR m_szPrintJobInstanceUID[MAX_SIZE];
   L_TCHAR m_szPresentationLUTInstanceUID[MAX_SIZE];
   L_TCHAR m_szOverlayBoxInstanceUID[MAX_SIZE];
   L_TCHAR m_szPullPrintRequestInstanceUID[MAX_SIZE];

   class CInstanceUID
   {
   public:
      L_TCHAR        m_szInstanceUID[MAX_SIZE];
      CInstanceUID* m_pNextInstanceUID;

      CInstanceUID(L_PCTSTR pszInstanceUID = NULL);
      ~CInstanceUID();
   };
   CInstanceUID* m_ImageBoxInstancesUIDs;
   CInstanceUID* m_AnnotationBoxInstancesUIDs;

   PRINTERINFO  m_PrinterInfo;
   PRINTJOBINFO m_PrintJobInfo;

private:
   L_VOID OnConnect(L_INT nError);
   L_VOID OnReceiveAssociateReject(L_UCHAR nResult, L_UCHAR nSource, L_UCHAR nReason);
   L_VOID OnReceiveAssociateAccept(LDicomAssociate* pPDU);
   L_VOID OnReceiveReleaseResponse();
   L_VOID OnReceiveReleaseRequest();
   L_VOID OnReceiveAbort(L_UCHAR nSource, L_UCHAR nReason);
   L_VOID OnReceiveNCreateResponse(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR* pszInstance, L_UINT16 nStatus, LDicomDS* pDS);
   L_VOID OnReceiveNSetResponse(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus, LDicomDS* pDS);
   L_VOID OnReceiveNActionResponse(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR* pszInstance, L_UINT16 nStatus, L_UINT16 nAction, LDicomDS* pDS);
   L_VOID OnReceiveNDeleteResponse(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR *pszInstance, L_UINT16 nStatus);
   L_VOID OnReceiveNReportRequest(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR* pszInstance, L_UINT16 nEvent, LDicomDS* pDS);
   L_VOID OnReceiveNGetResponse(L_UCHAR nPresentationID, L_UINT16 nMessageID, L_TCHAR* pszClass, L_TCHAR* pszInstance, L_UINT16 nStatus, LDicomDS* pDS);

   L_INT   WaitForOperation();
   L_VOID  Reset();
   L_UCHAR GetPresentationContextID(L_UINT16 uClass);
   L_BOOL  SetAttribute(LDicomDS& List, L_UINT32 uTag, L_PCTSTR pszValue) const;
   L_BOOL  SetAttribute(LDicomDS& List, L_UINT32 uTag, L_INT32 nValue) const;
   L_BOOL  SetAttribute(LDicomDS& List, L_UINT32 uTag, L_DOUBLE dValue) const;
   L_BOOL  InsertReferencedSequence(LDicomDS& DataSet, L_UINT32 uRefSeqTag, const L_TCHAR * pszRefSOPClassUID, const L_TCHAR * pszRefSOPInstanceUID) const;
   L_VOID  StorePrintJobInstanceUID(LDicomDS& ActionReply);
   L_INT   SetImage(LDicomDS& ModificationList, LDicomDS* pImage, L_UINT32 uIndex, L_BOOL bGrayscale) const;
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)
   L_LTDIC_API HDICOMPRINTSCU EXT_FUNCTION L_DicomPrintSCUCreate(const L_TCHAR* pszPath);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUFree(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUSetTimeout(HDICOMPRINTSCU hPrintSCU, L_UINT16 uTimeout);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUAssociate(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszPrintScuIP, L_UINT uPrintScuPort, const L_TCHAR* pszPrintScpIP, L_UINT uPrintScpPort, const L_TCHAR* pszCalledTitle, const L_TCHAR* pszCallingTitle, L_UINT16 uSupportedClasses);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUGetAssociateRejectInfo(HDICOMPRINTSCU hPrintSCU, L_UCHAR* pnResult, L_UCHAR* pnSource, L_UCHAR* pnReason);
   L_LTDIC_API L_BOOL EXT_FUNCTION L_DicomPrintSCUIsClassSupported(HDICOMPRINTSCU hPrintSCU, L_UINT16 uClass);
   L_LTDIC_API L_INT  EXT_FUNCTION L_DicomPrintSCURelease(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUGetAbortInfo(HDICOMPRINTSCU hPrintSCU, L_UCHAR* pnSource, L_UCHAR* pnReason);
   L_LTDIC_API L_UINT16 EXT_FUNCTION L_DicomPrintSCUGetLastOperationStatus(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUCreateFilmSession(HDICOMPRINTSCU hPrintSCU, const pFILMSESSIONPARAMETERS pParameters, L_BOOL bColorPrintManagement);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetFilmSessionInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUUpdateFilmSession(HDICOMPRINTSCU hPrintSCU, const pFILMSESSIONPARAMETERS pParameters);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUPrintFilmSession(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUDeleteFilmSession(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetDefaultFilmSessionParameters(HDICOMPRINTSCU hPrintSCU, pFILMSESSIONPARAMETERS pParameters, L_UINT uStructSize);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUCreateFilmBox(HDICOMPRINTSCU hPrintSCU, const pFILMBOXPARAMETERS pParameters, const L_TCHAR* pszRefPresLUTInstanceUID);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetFilmBoxInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUUpdateFilmBox(HDICOMPRINTSCU hPrintSCU, const pFILMBOXPARAMETERS pParameters, const L_TCHAR* pszRefPresLUTInstanceUID);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUPrintFilmBox(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUDeleteFilmBox(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetDefaultFilmBoxParameters(HDICOMPRINTSCU hPrintSCU, pFILMBOXPARAMETERS pParameters, L_UINT uStructSize);
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomPrintSCUGetImageBoxesCount(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_PCTSTR EXT_FUNCTION L_DicomPrintSCUGetImageBoxInstanceUID(HDICOMPRINTSCU hPrintSCU, L_UINT32 uIndex);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUUpdateImageBox(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszImageBoxInstanceUID, HDICOMDS pImage, L_UINT32 uIndex, const pIMAGEBOXPARAMETERS pParameters, const L_TCHAR* pszRefImageOverlayBoxInstanceUID, const L_TCHAR* pszRefPresLUTInstanceUID);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetDefaultImageBoxParameters(HDICOMPRINTSCU hPrintSCU, pIMAGEBOXPARAMETERS pParameters, L_UINT uStructSize);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUFreeImageBoxesInstanceUIDs(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetPrinterInfo(HDICOMPRINTSCU hPrintSCU, const pPRINTERINFO pRequiredPrinterInfo, L_BOOL bBasicPrintManagement, L_BOOL bColorPrintManagement);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetCurrentPrinterInfo(HDICOMPRINTSCU hPrintSCU, pPRINTERINFO pPrinterInfo, L_UINT uStructSize);
   L_LTDIC_API L_UINT32 EXT_FUNCTION L_DicomPrintSCUGetAnnotationBoxesCount(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_PCTSTR EXT_FUNCTION L_DicomPrintSCUGetAnnotationBoxInstanceUID(HDICOMPRINTSCU hPrintSCU, L_UINT32 uIndex);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUUpdateAnnotationBox(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszAnnotationBoxInstanceUID, L_UINT16 uAnnotationPosition, const L_TCHAR* pszTextString);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUFreeAnnotationBoxesInstanceUIDs(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUCreatePresentationLUT(HDICOMPRINTSCU hPrintSCU, HDICOMDS pPresentationLUT, const L_TCHAR* pszPresentationLUTShape);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetPresentationLUTInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUDeletePresentationLUT(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszPresentationLUTInstanceUID);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUCreateOverlayBox(HDICOMPRINTSCU hPrintSCU, HDICOMDS pOverlay, const pOVERLAYBOXPARAMETERS pParameters);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetOverlayBoxInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUUpdateOverlayBox(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszOverlayBoxInstanceUID, HDICOMDS pOverlay, const pOVERLAYBOXPARAMETERS pParameters, L_BOOL bUpdateOverlayOrigin);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUDeleteOverlayBox(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszOverlayBoxInstanceUID);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetDefaultOverlayBoxParameters(HDICOMPRINTSCU hPrintSCU, pOVERLAYBOXPARAMETERS pParameters, L_UINT uStructSize);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUCreatePullPrintRequest(HDICOMPRINTSCU hPrintSCU, const pSTOREDPRINTSTORAGEINSTANCEINFO InstancesInfo, L_UINT32 uInstancesCount, const pPULLPRINTREQUESTPARAMETERS pParameters);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetPullPrintRequestInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUPrintPullPrintRequestSession(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUDeletePullPrintRequest(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetDefaultPullPrintRequestParameters(HDICOMPRINTSCU hPrintSCU, pPULLPRINTREQUESTPARAMETERS pParameters, L_UINT uStructSize);
   L_LTDIC_API const L_TCHAR* EXT_FUNCTION L_DicomPrintSCUGetPrintJobInstanceUID(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetPrintJobInfo(HDICOMPRINTSCU hPrintSCU, const L_TCHAR* pszPrintJobInstanceUID, const pPRINTJOBINFO pRequiredPrintJobInfo);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetCurrentPrintJobInfo(HDICOMPRINTSCU hPrintSCU, pPRINTJOBINFO pPrintJobInfo, L_UINT uStructSize);
   L_LTDIC_API L_INT EXT_FUNCTION L_DicomPrintSCUGetPrinterConfiguration(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API HDICOMDS EXT_FUNCTION L_DicomPrintSCUGetCurrentPrinterConfiguration(HDICOMPRINTSCU hPrintSCU);
   L_LTDIC_API L_VOID EXT_FUNCTION L_DicomPrintSCUSetCallback(HDICOMPRINTSCU hPrintSCU, DICOMPRINTSCUCALLBACK* pCallback);
#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)
#endif // #if !defined(FOR_UWP)
#endif // #if !defined(EXCLUDE_DICOM_NET)

//============= CLASS ==========================================================
// Start of Context ID definitions 
#define CID_2      L_TEXT("CID 2")
#define CID_4      L_TEXT("CID 4")
#define CID_5      L_TEXT("CID 5")
#define CID_6      L_TEXT("CID 6")
#define CID_7      L_TEXT("CID 7")
#define CID_8      L_TEXT("CID 8")
#define CID_9      L_TEXT("CID 9")
#define CID_10     L_TEXT("CID 10")
#define CID_11     L_TEXT("CID 11")
#define CID_12     L_TEXT("CID 12")
#define CID_13     L_TEXT("CID 13")
#define CID_18     L_TEXT("CID 18")
#define CID_19     L_TEXT("CID 19")
#define CID_20     L_TEXT("CID 20")
#define CID_21     L_TEXT("CID 21")
#define CID_23     L_TEXT("CID 23")
#define CID_25     L_TEXT("CID 25")
#define CID_26     L_TEXT("CID 26")
#define CID_27     L_TEXT("CID 27")
#define CID_29     L_TEXT("CID 29")
#define CID_30     L_TEXT("CID 30")
#define CID_31     L_TEXT("CID 31")
#define CID_32     L_TEXT("CID 32")
#define CID_33     L_TEXT("CID 33")
#define CID_42     L_TEXT("CID 42")
#define CID_43     L_TEXT("CID 43")
#define CID_44     L_TEXT("CID 44")
#define CID_50     L_TEXT("CID 50")
#define CID_60     L_TEXT("CID 60")
#define CID_61     L_TEXT("CID 61")
#define CID_62     L_TEXT("CID 62")
#define CID_63     L_TEXT("CID 63")
#define CID_64     L_TEXT("CID 64")
#define CID_65     L_TEXT("CID 65")
#define CID_66     L_TEXT("CID 66")
#define CID_67     L_TEXT("CID 67")
#define CID_68     L_TEXT("CID 68")
#define CID_69     L_TEXT("CID 69")
#define CID_70     L_TEXT("CID 70")
#define CID_71     L_TEXT("CID 71")
#define CID_72     L_TEXT("CID 72")
#define CID_73     L_TEXT("CID 73")
#define CID_74     L_TEXT("CID 74")
#define CID_75     L_TEXT("CID 75")
#define CID_76     L_TEXT("CID 76")
#define CID_83     L_TEXT("CID 83")
#define CID_84     L_TEXT("CID 84")
#define CID_85     L_TEXT("CID 85")
#define CID_91     L_TEXT("CID 91")
#define CID_92     L_TEXT("CID 92")
#define CID_93     L_TEXT("CID 93")
#define CID_94     L_TEXT("CID 94")
#define CID_100    L_TEXT("CID 100")
#define CID_210    L_TEXT("CID 210")
#define CID_211    L_TEXT("CID 211")
#define CID_212    L_TEXT("CID 212")
#define CID_217    L_TEXT("CID 217")
#define CID_218    L_TEXT("CID 218")
#define CID_219    L_TEXT("CID 219")
#define CID_220    L_TEXT("CID 220")
#define CID_221    L_TEXT("CID 221")
#define CID_222    L_TEXT("CID 222")
#define CID_223    L_TEXT("CID 223")
#define CID_224    L_TEXT("CID 224")
#define CID_225    L_TEXT("CID 225")
#define CID_226    L_TEXT("CID 226")
#define CID_227    L_TEXT("CID 227")
#define CID_228    L_TEXT("CID 228")
#define CID_230    L_TEXT("CID 230")
#define CID_231    L_TEXT("CID 231")
#define CID_240    L_TEXT("CID 240")
#define CID_241    L_TEXT("CID 241")
#define CID_242    L_TEXT("CID 242")
#define CID_244    L_TEXT("CID 244")
#define CID_245    L_TEXT("CID 245")
#define CID_246    L_TEXT("CID 246")
#define CID_247    L_TEXT("CID 247")
#define CID_250    L_TEXT("CID 250")
#define CID_251    L_TEXT("CID 251")
#define CID_252    L_TEXT("CID 252")
#define CID_270    L_TEXT("CID 270")
#define CID_271    L_TEXT("CID 271")
#define CID_280    L_TEXT("CID 280")
#define CID_300    L_TEXT("CID 300")
#define CID_301    L_TEXT("CID 301")
#define CID_400    L_TEXT("CID 400")
#define CID_401    L_TEXT("CID 401")
#define CID_402    L_TEXT("CID 402")
#define CID_403    L_TEXT("CID 403")
#define CID_404    L_TEXT("CID 404")
#define CID_405    L_TEXT("CID 405")
#define CID_501    L_TEXT("CID 501")
#define CID_502    L_TEXT("CID 502")
#define CID_601    L_TEXT("CID 601")
#define CID_602    L_TEXT("CID 602")
#define CID_603    L_TEXT("CID 603")
#define CID_604    L_TEXT("CID 604")
#define CID_605    L_TEXT("CID 605")
#define CID_606    L_TEXT("CID 606")
#define CID_607    L_TEXT("CID 607")
#define CID_608    L_TEXT("CID 608")
#define CID_609    L_TEXT("CID 609")
#define CID_610    L_TEXT("CID 610")
#define CID_611    L_TEXT("CID 611")
#define CID_612    L_TEXT("CID 612")
#define CID_613    L_TEXT("CID 613")
#define CID_614    L_TEXT("CID 614")
#define CID_615    L_TEXT("CID 615")
#define CID_616    L_TEXT("CID 616")
#define CID_617    L_TEXT("CID 617")
#define CID_618    L_TEXT("CID 618")
#define CID_619    L_TEXT("CID 619")
#define CID_620    L_TEXT("CID 620")
#define CID_621    L_TEXT("CID 621")
#define CID_622    L_TEXT("CID 622")
#define CID_623    L_TEXT("CID 623")
#define CID_624    L_TEXT("CID 624")
#define CID_625    L_TEXT("CID 625")
#define CID_626    L_TEXT("CID 626")
#define CID_627    L_TEXT("CID 627")
#define CID_628    L_TEXT("CID 628")
#define CID_629    L_TEXT("CID 629")
#define CID_630    L_TEXT("CID 630")
#define CID_631    L_TEXT("CID 631")
#define CID_632    L_TEXT("CID 632")
#define CID_633    L_TEXT("CID 633")
#define CID_634    L_TEXT("CID 634")
#define CID_635    L_TEXT("CID 635")
#define CID_636    L_TEXT("CID 636")
#define CID_637    L_TEXT("CID 637")
#define CID_638    L_TEXT("CID 638")
#define CID_639    L_TEXT("CID 639")
#define CID_640    L_TEXT("CID 640")
#define CID_641    L_TEXT("CID 641")
#define CID_642    L_TEXT("CID 642")
#define CID_643    L_TEXT("CID 643")
#define CID_644    L_TEXT("CID 644")
#define CID_645    L_TEXT("CID 645")
#define CID_646    L_TEXT("CID 646")
#define CID_647    L_TEXT("CID 647")
#define CID_701    L_TEXT("CID 701")
#define CID_702    L_TEXT("CID 702")
#define CID_703    L_TEXT("CID 703")
#define CID_800    L_TEXT("CID 800")
#define CID_1000   L_TEXT("CID 1000")
#define CID_1001   L_TEXT("CID 1001")
#define CID_1002   L_TEXT("CID 1002")
#define CID_1003   L_TEXT("CID 1003")
#define CID_1004   L_TEXT("CID 1004")
#define CID_1005   L_TEXT("CID 1005")
#define CID_1006   L_TEXT("CID 1006")
#define CID_1010   L_TEXT("CID 1010")
#define CID_1011   L_TEXT("CID 1011")
#define CID_1015   L_TEXT("CID 1015")
#define CID_1200   L_TEXT("CID 1200")
#define CID_1201   L_TEXT("CID 1201")
#define CID_3000   L_TEXT("CID 3000")
#define CID_3001   L_TEXT("CID 3001")
#define CID_3003   L_TEXT("CID 3003")
#define CID_3004   L_TEXT("CID 3004")
#define CID_3005   L_TEXT("CID 3005")
#define CID_3010   L_TEXT("CID 3010")
#define CID_3011   L_TEXT("CID 3011")
#define CID_3014   L_TEXT("CID 3014")
#define CID_3015   L_TEXT("CID 3015")
#define CID_3016   L_TEXT("CID 3016")
#define CID_3019   L_TEXT("CID 3019")
#define CID_3030   L_TEXT("CID 3030")
#define CID_3031   L_TEXT("CID 3031")
#define CID_3032   L_TEXT("CID 3032")
#define CID_3033   L_TEXT("CID 3033")
#define CID_3034   L_TEXT("CID 3034")
#define CID_3035   L_TEXT("CID 3035")
#define CID_3036   L_TEXT("CID 3036")
#define CID_3037   L_TEXT("CID 3037")
#define CID_3038   L_TEXT("CID 3038")
#define CID_3039   L_TEXT("CID 3039")
#define CID_3040   L_TEXT("CID 3040")
#define CID_3041   L_TEXT("CID 3041")
#define CID_3083   L_TEXT("CID 3083")
#define CID_3090   L_TEXT("CID 3090")
#define CID_3101   L_TEXT("CID 3101")
#define CID_3102   L_TEXT("CID 3102")
#define CID_3104   L_TEXT("CID 3104")
#define CID_3106   L_TEXT("CID 3106")
#define CID_3107   L_TEXT("CID 3107")
#define CID_3108   L_TEXT("CID 3108")
#define CID_3110   L_TEXT("CID 3110")
#define CID_3111   L_TEXT("CID 3111")
#define CID_3112   L_TEXT("CID 3112")
#define CID_3113   L_TEXT("CID 3113")
#define CID_3114   L_TEXT("CID 3114")
#define CID_3115   L_TEXT("CID 3115")
#define CID_3116   L_TEXT("CID 3116")
#define CID_3117   L_TEXT("CID 3117")
#define CID_3118   L_TEXT("CID 3118")
#define CID_3119   L_TEXT("CID 3119")
#define CID_3120   L_TEXT("CID 3120")
#define CID_3121   L_TEXT("CID 3121")
#define CID_3122   L_TEXT("CID 3122")
#define CID_3200   L_TEXT("CID 3200")
#define CID_3201   L_TEXT("CID 3201")
#define CID_3202   L_TEXT("CID 3202")
#define CID_3203   L_TEXT("CID 3203")
#define CID_3204   L_TEXT("CID 3204")
#define CID_3205   L_TEXT("CID 3205")
#define CID_3206   L_TEXT("CID 3206")
#define CID_3207   L_TEXT("CID 3207")
#define CID_3208   L_TEXT("CID 3208")
#define CID_3209   L_TEXT("CID 3209")
#define CID_3210   L_TEXT("CID 3210")
#define CID_3211   L_TEXT("CID 3211")
#define CID_3212   L_TEXT("CID 3212")
#define CID_3213   L_TEXT("CID 3213")
#define CID_3215   L_TEXT("CID 3215")
#define CID_3217   L_TEXT("CID 3217")
#define CID_3220   L_TEXT("CID 3220")
#define CID_3221   L_TEXT("CID 3221")
#define CID_3227   L_TEXT("CID 3227")
#define CID_3228   L_TEXT("CID 3228")
#define CID_3229   L_TEXT("CID 3229")
#define CID_3230   L_TEXT("CID 3230")
#define CID_3231   L_TEXT("CID 3231")
#define CID_3232   L_TEXT("CID 3232")
#define CID_3233   L_TEXT("CID 3233")
#define CID_3234   L_TEXT("CID 3234")
#define CID_3235   L_TEXT("CID 3235")
#define CID_3236   L_TEXT("CID 3236")
#define CID_3237   L_TEXT("CID 3237")
#define CID_3238   L_TEXT("CID 3238")
#define CID_3239   L_TEXT("CID 3239")
#define CID_3240   L_TEXT("CID 3240")
#define CID_3241   L_TEXT("CID 3241")
#define CID_3250   L_TEXT("CID 3250")
#define CID_3254   L_TEXT("CID 3254")
#define CID_3261   L_TEXT("CID 3261")
#define CID_3262   L_TEXT("CID 3262")
#define CID_3263   L_TEXT("CID 3263")
#define CID_3271   L_TEXT("CID 3271")
#define CID_3335   L_TEXT("CID 3335")
#define CID_3337   L_TEXT("CID 3337")
#define CID_3339   L_TEXT("CID 3339")
#define CID_3400   L_TEXT("CID 3400")
#define CID_3401   L_TEXT("CID 3401")
#define CID_3402   L_TEXT("CID 3402")
#define CID_3403   L_TEXT("CID 3403")
#define CID_3404   L_TEXT("CID 3404")
#define CID_3405   L_TEXT("CID 3405")
#define CID_3406   L_TEXT("CID 3406")
#define CID_3407   L_TEXT("CID 3407")
#define CID_3408   L_TEXT("CID 3408")
#define CID_3409   L_TEXT("CID 3409")
#define CID_3410   L_TEXT("CID 3410")
#define CID_3411   L_TEXT("CID 3411")
#define CID_3412   L_TEXT("CID 3412")
#define CID_3413   L_TEXT("CID 3413")
#define CID_3414   L_TEXT("CID 3414")
#define CID_3415   L_TEXT("CID 3415")
#define CID_3416   L_TEXT("CID 3416")
#define CID_3418   L_TEXT("CID 3418")
#define CID_3419   L_TEXT("CID 3419")
#define CID_3421   L_TEXT("CID 3421")
#define CID_3422   L_TEXT("CID 3422")
#define CID_3423   L_TEXT("CID 3423")
#define CID_3425   L_TEXT("CID 3425")
#define CID_3426   L_TEXT("CID 3426")
#define CID_3427   L_TEXT("CID 3427")
#define CID_3428   L_TEXT("CID 3428")
#define CID_3429   L_TEXT("CID 3429")
#define CID_3430   L_TEXT("CID 3430")
#define CID_3440   L_TEXT("CID 3440")
#define CID_3441   L_TEXT("CID 3441")
#define CID_3442   L_TEXT("CID 3442")
#define CID_3446   L_TEXT("CID 3446")
#define CID_3448   L_TEXT("CID 3448")
#define CID_3451   L_TEXT("CID 3451")
#define CID_3452   L_TEXT("CID 3452")
#define CID_3453   L_TEXT("CID 3453")
#define CID_3455   L_TEXT("CID 3455")
#define CID_3456   L_TEXT("CID 3456")
#define CID_3458   L_TEXT("CID 3458")
#define CID_3460   L_TEXT("CID 3460")
#define CID_3461   L_TEXT("CID 3461")
#define CID_3462   L_TEXT("CID 3462")
#define CID_3463   L_TEXT("CID 3463")
#define CID_3465   L_TEXT("CID 3465")
#define CID_3466   L_TEXT("CID 3466")
#define CID_3467   L_TEXT("CID 3467")
#define CID_3468   L_TEXT("CID 3468")
#define CID_3469   L_TEXT("CID 3469")
#define CID_3470   L_TEXT("CID 3470")
#define CID_3471   L_TEXT("CID 3471")
#define CID_3472   L_TEXT("CID 3472")
#define CID_3480   L_TEXT("CID 3480")
#define CID_3481   L_TEXT("CID 3481")
#define CID_3482   L_TEXT("CID 3482")
#define CID_3483   L_TEXT("CID 3483")
#define CID_3484   L_TEXT("CID 3484")
#define CID_3485   L_TEXT("CID 3485")
#define CID_3486   L_TEXT("CID 3486")
#define CID_3487   L_TEXT("CID 3487")
#define CID_3488   L_TEXT("CID 3488")
#define CID_3489   L_TEXT("CID 3489")
#define CID_3491   L_TEXT("CID 3491")
#define CID_3492   L_TEXT("CID 3492")
#define CID_3493   L_TEXT("CID 3493")
#define CID_3494   L_TEXT("CID 3494")
#define CID_3495   L_TEXT("CID 3495")
#define CID_3496   L_TEXT("CID 3496")
#define CID_3497   L_TEXT("CID 3497")
#define CID_3500   L_TEXT("CID 3500")
#define CID_3502   L_TEXT("CID 3502")
#define CID_3503   L_TEXT("CID 3503")
#define CID_3510   L_TEXT("CID 3510")
#define CID_3515   L_TEXT("CID 3515")
#define CID_3520   L_TEXT("CID 3520")
#define CID_3524   L_TEXT("CID 3524")
#define CID_3525   L_TEXT("CID 3525")
#define CID_3526   L_TEXT("CID 3526")
#define CID_3527   L_TEXT("CID 3527")
#define CID_3528   L_TEXT("CID 3528")
#define CID_3529   L_TEXT("CID 3529")
#define CID_3530   L_TEXT("CID 3530")
#define CID_3531   L_TEXT("CID 3531")
#define CID_3550   L_TEXT("CID 3550")
#define CID_3551   L_TEXT("CID 3551")
#define CID_3552   L_TEXT("CID 3552")
#define CID_3553   L_TEXT("CID 3553")
#define CID_3554   L_TEXT("CID 3554")
#define CID_3555   L_TEXT("CID 3555")
#define CID_3560   L_TEXT("CID 3560")
#define CID_3600   L_TEXT("CID 3600")
#define CID_3602   L_TEXT("CID 3602")
#define CID_3604   L_TEXT("CID 3604")
#define CID_3606   L_TEXT("CID 3606")
#define CID_3607   L_TEXT("CID 3607")
#define CID_3608   L_TEXT("CID 3608")
#define CID_3609   L_TEXT("CID 3609")
#define CID_3610   L_TEXT("CID 3610")
#define CID_3611   L_TEXT("CID 3611")
#define CID_3612   L_TEXT("CID 3612")
#define CID_3613   L_TEXT("CID 3613")
#define CID_3614   L_TEXT("CID 3614")
#define CID_3615   L_TEXT("CID 3615")
#define CID_3616   L_TEXT("CID 3616")
#define CID_3617   L_TEXT("CID 3617")
#define CID_3618   L_TEXT("CID 3618")
#define CID_3619   L_TEXT("CID 3619")
#define CID_3620   L_TEXT("CID 3620")
#define CID_3621   L_TEXT("CID 3621")
#define CID_3627   L_TEXT("CID 3627")
#define CID_3628   L_TEXT("CID 3628")
#define CID_3629   L_TEXT("CID 3629")
#define CID_3630   L_TEXT("CID 3630")
#define CID_3640   L_TEXT("CID 3640")
#define CID_3641   L_TEXT("CID 3641")
#define CID_3642   L_TEXT("CID 3642")
#define CID_3651   L_TEXT("CID 3651")
#define CID_3663   L_TEXT("CID 3663")
#define CID_3664   L_TEXT("CID 3664")
#define CID_3666   L_TEXT("CID 3666")
#define CID_3667   L_TEXT("CID 3667")
#define CID_3668   L_TEXT("CID 3668")
#define CID_3670   L_TEXT("CID 3670")
#define CID_3671   L_TEXT("CID 3671")
#define CID_3676   L_TEXT("CID 3676")
#define CID_3677   L_TEXT("CID 3677")
#define CID_3678   L_TEXT("CID 3678")
#define CID_3680   L_TEXT("CID 3680")
#define CID_3687   L_TEXT("CID 3687")
#define CID_3688   L_TEXT("CID 3688")
#define CID_3689   L_TEXT("CID 3689")
#define CID_3690   L_TEXT("CID 3690")
#define CID_3691   L_TEXT("CID 3691")
#define CID_3700   L_TEXT("CID 3700")
#define CID_3701   L_TEXT("CID 3701")
#define CID_3703   L_TEXT("CID 3703")
#define CID_3704   L_TEXT("CID 3704")
#define CID_3705   L_TEXT("CID 3705")
#define CID_3706   L_TEXT("CID 3706")
#define CID_3707   L_TEXT("CID 3707")
#define CID_3709   L_TEXT("CID 3709")
#define CID_3710   L_TEXT("CID 3710")
#define CID_3711   L_TEXT("CID 3711")
#define CID_3712   L_TEXT("CID 3712")
#define CID_3713   L_TEXT("CID 3713")
#define CID_3714   L_TEXT("CID 3714")
#define CID_3715   L_TEXT("CID 3715")
#define CID_3716   L_TEXT("CID 3716")
#define CID_3717   L_TEXT("CID 3717")
#define CID_3718   L_TEXT("CID 3718")
#define CID_3719   L_TEXT("CID 3719")
#define CID_3721   L_TEXT("CID 3721")
#define CID_3722   L_TEXT("CID 3722")
#define CID_3723   L_TEXT("CID 3723")
#define CID_3724   L_TEXT("CID 3724")
#define CID_3726   L_TEXT("CID 3726")
#define CID_3727   L_TEXT("CID 3727")
#define CID_3728   L_TEXT("CID 3728")
#define CID_3729   L_TEXT("CID 3729")
#define CID_3730   L_TEXT("CID 3730")
#define CID_3733   L_TEXT("CID 3733")
#define CID_3735   L_TEXT("CID 3735")
#define CID_3736   L_TEXT("CID 3736")
#define CID_3737   L_TEXT("CID 3737")
#define CID_3738   L_TEXT("CID 3738")
#define CID_3739   L_TEXT("CID 3739")
#define CID_3740   L_TEXT("CID 3740")
#define CID_3741   L_TEXT("CID 3741")
#define CID_3742   L_TEXT("CID 3742")
#define CID_3743   L_TEXT("CID 3743")
#define CID_3744   L_TEXT("CID 3744")
#define CID_3745   L_TEXT("CID 3745")
#define CID_3746   L_TEXT("CID 3746")
#define CID_3747   L_TEXT("CID 3747")
#define CID_3748   L_TEXT("CID 3748")
#define CID_3749   L_TEXT("CID 3749")
#define CID_3750   L_TEXT("CID 3750")
#define CID_3752   L_TEXT("CID 3752")
#define CID_3754   L_TEXT("CID 3754")
#define CID_3755   L_TEXT("CID 3755")
#define CID_3756   L_TEXT("CID 3756")
#define CID_3757   L_TEXT("CID 3757")
#define CID_3758   L_TEXT("CID 3758")
#define CID_3760   L_TEXT("CID 3760")
#define CID_3761   L_TEXT("CID 3761")
#define CID_3762   L_TEXT("CID 3762")
#define CID_3764   L_TEXT("CID 3764")
#define CID_3769   L_TEXT("CID 3769")
#define CID_3770   L_TEXT("CID 3770")
#define CID_3772   L_TEXT("CID 3772")
#define CID_3773   L_TEXT("CID 3773")
#define CID_3774   L_TEXT("CID 3774")
#define CID_3777   L_TEXT("CID 3777")
#define CID_3778   L_TEXT("CID 3778")
#define CID_3802   L_TEXT("CID 3802")
#define CID_3804   L_TEXT("CID 3804")
#define CID_3805   L_TEXT("CID 3805")
#define CID_3806   L_TEXT("CID 3806")
#define CID_3807   L_TEXT("CID 3807")
#define CID_3808   L_TEXT("CID 3808")
#define CID_3809   L_TEXT("CID 3809")
#define CID_3810   L_TEXT("CID 3810")
#define CID_3813   L_TEXT("CID 3813")
#define CID_3814   L_TEXT("CID 3814")
#define CID_3815   L_TEXT("CID 3815")
#define CID_3817   L_TEXT("CID 3817")
#define CID_3820   L_TEXT("CID 3820")
#define CID_3821   L_TEXT("CID 3821")
#define CID_3823   L_TEXT("CID 3823")
#define CID_3826   L_TEXT("CID 3826")
#define CID_3827   L_TEXT("CID 3827")
#define CID_3829   L_TEXT("CID 3829")
#define CID_3831   L_TEXT("CID 3831")
#define CID_3832   L_TEXT("CID 3832")
#define CID_3833   L_TEXT("CID 3833")
#define CID_3835   L_TEXT("CID 3835")
#define CID_3836   L_TEXT("CID 3836")
#define CID_3837   L_TEXT("CID 3837")
#define CID_3838   L_TEXT("CID 3838")
#define CID_3839   L_TEXT("CID 3839")
#define CID_3840   L_TEXT("CID 3840")
#define CID_3843   L_TEXT("CID 3843")
#define CID_3850   L_TEXT("CID 3850")
#define CID_4005   L_TEXT("CID 4005")
#define CID_4009   L_TEXT("CID 4009")
#define CID_4010   L_TEXT("CID 4010")
#define CID_4011   L_TEXT("CID 4011")
#define CID_4012   L_TEXT("CID 4012")
#define CID_4013   L_TEXT("CID 4013")
#define CID_4014   L_TEXT("CID 4014")
#define CID_4015   L_TEXT("CID 4015")
#define CID_4016   L_TEXT("CID 4016")
#define CID_4017   L_TEXT("CID 4017")
#define CID_4018   L_TEXT("CID 4018")
#define CID_4019   L_TEXT("CID 4019")
#define CID_4020   L_TEXT("CID 4020")
#define CID_4021   L_TEXT("CID 4021")
#define CID_4025   L_TEXT("CID 4025")
#define CID_4026   L_TEXT("CID 4026")
#define CID_4028   L_TEXT("CID 4028")
#define CID_4029   L_TEXT("CID 4029")
#define CID_4030   L_TEXT("CID 4030")
#define CID_4031   L_TEXT("CID 4031")
#define CID_4032   L_TEXT("CID 4032")
#define CID_4033   L_TEXT("CID 4033")
#define CID_4040   L_TEXT("CID 4040")
#define CID_4042   L_TEXT("CID 4042")
#define CID_4050   L_TEXT("CID 4050")
#define CID_4051   L_TEXT("CID 4051")
#define CID_4052   L_TEXT("CID 4052")
#define CID_4100   L_TEXT("CID 4100")
#define CID_4101   L_TEXT("CID 4101")
#define CID_4102   L_TEXT("CID 4102")
#define CID_4103   L_TEXT("CID 4103")
#define CID_4104   L_TEXT("CID 4104")
#define CID_4105   L_TEXT("CID 4105")
#define CID_4106   L_TEXT("CID 4106")
#define CID_4107   L_TEXT("CID 4107")
#define CID_4108   L_TEXT("CID 4108")
#define CID_4109   L_TEXT("CID 4109")
#define CID_4110   L_TEXT("CID 4110")
#define CID_4111   L_TEXT("CID 4111")
#define CID_4200   L_TEXT("CID 4200")
#define CID_4201   L_TEXT("CID 4201")
#define CID_4202   L_TEXT("CID 4202")
#define CID_4203   L_TEXT("CID 4203")
#define CID_4204   L_TEXT("CID 4204")
#define CID_4205   L_TEXT("CID 4205")
#define CID_4206   L_TEXT("CID 4206")
#define CID_4207   L_TEXT("CID 4207")
#define CID_4208   L_TEXT("CID 4208")
#define CID_4209   L_TEXT("CID 4209")
#define CID_4210   L_TEXT("CID 4210")
#define CID_4211   L_TEXT("CID 4211")
#define CID_4214   L_TEXT("CID 4214")
#define CID_4215   L_TEXT("CID 4215")
#define CID_4216   L_TEXT("CID 4216")
#define CID_4220   L_TEXT("CID 4220")
#define CID_4221   L_TEXT("CID 4221")
#define CID_4222   L_TEXT("CID 4222")
#define CID_4230   L_TEXT("CID 4230")
#define CID_4231   L_TEXT("CID 4231")
#define CID_4232   L_TEXT("CID 4232")
#define CID_4233   L_TEXT("CID 4233")
#define CID_4234   L_TEXT("CID 4234")
#define CID_4235   L_TEXT("CID 4235")
#define CID_4236   L_TEXT("CID 4236")
#define CID_4237   L_TEXT("CID 4237")
#define CID_4238   L_TEXT("CID 4238")
#define CID_4239   L_TEXT("CID 4239")
#define CID_4240   L_TEXT("CID 4240")
#define CID_4241   L_TEXT("CID 4241")
#define CID_4242   L_TEXT("CID 4242")
#define CID_4243   L_TEXT("CID 4243")
#define CID_4244   L_TEXT("CID 4244")
#define CID_4245   L_TEXT("CID 4245")
#define CID_4250   L_TEXT("CID 4250")
#define CID_4251   L_TEXT("CID 4251")
#define CID_4252   L_TEXT("CID 4252")
#define CID_4253   L_TEXT("CID 4253")
#define CID_4254   L_TEXT("CID 4254")
#define CID_4255   L_TEXT("CID 4255")
#define CID_4256   L_TEXT("CID 4256")
#define CID_4257   L_TEXT("CID 4257")
#define CID_4260   L_TEXT("CID 4260")
#define CID_4261   L_TEXT("CID 4261")
#define CID_4262   L_TEXT("CID 4262")
#define CID_4263   L_TEXT("CID 4263")
#define CID_4264   L_TEXT("CID 4264")
#define CID_4265   L_TEXT("CID 4265")
#define CID_4266   L_TEXT("CID 4266")
#define CID_4267   L_TEXT("CID 4267")
#define CID_4268   L_TEXT("CID 4268")
#define CID_4270   L_TEXT("CID 4270")
#define CID_4271   L_TEXT("CID 4271")
#define CID_4272   L_TEXT("CID 4272")
#define CID_4273   L_TEXT("CID 4273")
#define CID_4401   L_TEXT("CID 4401")
#define CID_4402   L_TEXT("CID 4402")
#define CID_4403   L_TEXT("CID 4403")
#define CID_4404   L_TEXT("CID 4404")
#define CID_4405   L_TEXT("CID 4405")
#define CID_4406   L_TEXT("CID 4406")
#define CID_4407   L_TEXT("CID 4407")
#define CID_4408   L_TEXT("CID 4408")
#define CID_4409   L_TEXT("CID 4409")
#define CID_6000   L_TEXT("CID 6000")
#define CID_6001   L_TEXT("CID 6001")
#define CID_6002   L_TEXT("CID 6002")
#define CID_6003   L_TEXT("CID 6003")
#define CID_6004   L_TEXT("CID 6004")
#define CID_6005   L_TEXT("CID 6005")
#define CID_6006   L_TEXT("CID 6006")
#define CID_6007   L_TEXT("CID 6007")
#define CID_6008   L_TEXT("CID 6008")
#define CID_6009   L_TEXT("CID 6009")
#define CID_6010   L_TEXT("CID 6010")
#define CID_6011   L_TEXT("CID 6011")
#define CID_6012   L_TEXT("CID 6012")
#define CID_6013   L_TEXT("CID 6013")
#define CID_6014   L_TEXT("CID 6014")
#define CID_6015   L_TEXT("CID 6015")
#define CID_6016   L_TEXT("CID 6016")
#define CID_6017   L_TEXT("CID 6017")
#define CID_6018   L_TEXT("CID 6018")
#define CID_6019   L_TEXT("CID 6019")
#define CID_6020   L_TEXT("CID 6020")
#define CID_6021   L_TEXT("CID 6021")
#define CID_6022   L_TEXT("CID 6022")
#define CID_6023   L_TEXT("CID 6023")
#define CID_6024   L_TEXT("CID 6024")
#define CID_6025   L_TEXT("CID 6025")
#define CID_6026   L_TEXT("CID 6026")
#define CID_6027   L_TEXT("CID 6027")
#define CID_6028   L_TEXT("CID 6028")
#define CID_6029   L_TEXT("CID 6029")
#define CID_6030   L_TEXT("CID 6030")
#define CID_6031   L_TEXT("CID 6031")
#define CID_6032   L_TEXT("CID 6032")
#define CID_6033   L_TEXT("CID 6033")
#define CID_6034   L_TEXT("CID 6034")
#define CID_6035   L_TEXT("CID 6035")
#define CID_6036   L_TEXT("CID 6036")
#define CID_6037   L_TEXT("CID 6037")
#define CID_6038   L_TEXT("CID 6038")
#define CID_6039   L_TEXT("CID 6039")
#define CID_6040   L_TEXT("CID 6040")
#define CID_6041   L_TEXT("CID 6041")
#define CID_6042   L_TEXT("CID 6042")
#define CID_6043   L_TEXT("CID 6043")
#define CID_6044   L_TEXT("CID 6044")
#define CID_6045   L_TEXT("CID 6045")
#define CID_6046   L_TEXT("CID 6046")
#define CID_6047   L_TEXT("CID 6047")
#define CID_6048   L_TEXT("CID 6048")
#define CID_6050   L_TEXT("CID 6050")
#define CID_6051   L_TEXT("CID 6051")
#define CID_6052   L_TEXT("CID 6052")
#define CID_6053   L_TEXT("CID 6053")
#define CID_6054   L_TEXT("CID 6054")
#define CID_6055   L_TEXT("CID 6055")
#define CID_6056   L_TEXT("CID 6056")
#define CID_6057   L_TEXT("CID 6057")
#define CID_6058   L_TEXT("CID 6058")
#define CID_6059   L_TEXT("CID 6059")
#define CID_6060   L_TEXT("CID 6060")
#define CID_6061   L_TEXT("CID 6061")
#define CID_6062   L_TEXT("CID 6062")
#define CID_6063   L_TEXT("CID 6063")
#define CID_6064   L_TEXT("CID 6064")
#define CID_6065   L_TEXT("CID 6065")
#define CID_6066   L_TEXT("CID 6066")
#define CID_6067   L_TEXT("CID 6067")
#define CID_6068   L_TEXT("CID 6068")
#define CID_6069   L_TEXT("CID 6069")
#define CID_6070   L_TEXT("CID 6070")
#define CID_6071   L_TEXT("CID 6071")
#define CID_6072   L_TEXT("CID 6072")
#define CID_6080   L_TEXT("CID 6080")
#define CID_6081   L_TEXT("CID 6081")
#define CID_6082   L_TEXT("CID 6082")
#define CID_6083   L_TEXT("CID 6083")
#define CID_6084   L_TEXT("CID 6084")
#define CID_6085   L_TEXT("CID 6085")
#define CID_6086   L_TEXT("CID 6086")
#define CID_6087   L_TEXT("CID 6087")
#define CID_6088   L_TEXT("CID 6088")
#define CID_6089   L_TEXT("CID 6089")
#define CID_6090   L_TEXT("CID 6090")
#define CID_6091   L_TEXT("CID 6091")
#define CID_6092   L_TEXT("CID 6092")
#define CID_6093   L_TEXT("CID 6093")
#define CID_6094   L_TEXT("CID 6094")
#define CID_6095   L_TEXT("CID 6095")
#define CID_6096   L_TEXT("CID 6096")
#define CID_6097   L_TEXT("CID 6097")
#define CID_6098   L_TEXT("CID 6098")
#define CID_6099   L_TEXT("CID 6099")
#define CID_6100   L_TEXT("CID 6100")
#define CID_6101   L_TEXT("CID 6101")
#define CID_6102   L_TEXT("CID 6102")
#define CID_6103   L_TEXT("CID 6103")
#define CID_6104   L_TEXT("CID 6104")
#define CID_6105   L_TEXT("CID 6105")
#define CID_6106   L_TEXT("CID 6106")
#define CID_6107   L_TEXT("CID 6107")
#define CID_6108   L_TEXT("CID 6108")
#define CID_6109   L_TEXT("CID 6109")
#define CID_6110   L_TEXT("CID 6110")
#define CID_6111   L_TEXT("CID 6111")
#define CID_6112   L_TEXT("CID 6112")
#define CID_6113   L_TEXT("CID 6113")
#define CID_6114   L_TEXT("CID 6114")
#define CID_6115   L_TEXT("CID 6115")
#define CID_6116   L_TEXT("CID 6116")
#define CID_6117   L_TEXT("CID 6117")
#define CID_6118   L_TEXT("CID 6118")
#define CID_6119   L_TEXT("CID 6119")
#define CID_6120   L_TEXT("CID 6120")
#define CID_6121   L_TEXT("CID 6121")
#define CID_6122   L_TEXT("CID 6122")
#define CID_6123   L_TEXT("CID 6123")
#define CID_6124   L_TEXT("CID 6124")
#define CID_6125   L_TEXT("CID 6125")
#define CID_6126   L_TEXT("CID 6126")
#define CID_6127   L_TEXT("CID 6127")
#define CID_6128   L_TEXT("CID 6128")
#define CID_6129   L_TEXT("CID 6129")
#define CID_6130   L_TEXT("CID 6130")
#define CID_6131   L_TEXT("CID 6131")
#define CID_6132   L_TEXT("CID 6132")
#define CID_6133   L_TEXT("CID 6133")
#define CID_6134   L_TEXT("CID 6134")
#define CID_6135   L_TEXT("CID 6135")
#define CID_6136   L_TEXT("CID 6136")
#define CID_6137   L_TEXT("CID 6137")
#define CID_6138   L_TEXT("CID 6138")
#define CID_6139   L_TEXT("CID 6139")
#define CID_6140   L_TEXT("CID 6140")
#define CID_6141   L_TEXT("CID 6141")
#define CID_6142   L_TEXT("CID 6142")
#define CID_6143   L_TEXT("CID 6143")
#define CID_6144   L_TEXT("CID 6144")
#define CID_6145   L_TEXT("CID 6145")
#define CID_6146   L_TEXT("CID 6146")
#define CID_6147   L_TEXT("CID 6147")
#define CID_6148   L_TEXT("CID 6148")
#define CID_6149   L_TEXT("CID 6149")
#define CID_6151   L_TEXT("CID 6151")
#define CID_6152   L_TEXT("CID 6152")
#define CID_6153   L_TEXT("CID 6153")
#define CID_6154   L_TEXT("CID 6154")
#define CID_6155   L_TEXT("CID 6155")
#define CID_6157   L_TEXT("CID 6157")
#define CID_6158   L_TEXT("CID 6158")
#define CID_6159   L_TEXT("CID 6159")
#define CID_6160   L_TEXT("CID 6160")
#define CID_6161   L_TEXT("CID 6161")
#define CID_6162   L_TEXT("CID 6162")
#define CID_6163   L_TEXT("CID 6163")
#define CID_6164   L_TEXT("CID 6164")
#define CID_6165   L_TEXT("CID 6165")
#define CID_6166   L_TEXT("CID 6166")
#define CID_6200   L_TEXT("CID 6200")
#define CID_6201   L_TEXT("CID 6201")
#define CID_6202   L_TEXT("CID 6202")
#define CID_6203   L_TEXT("CID 6203")
#define CID_6204   L_TEXT("CID 6204")
#define CID_6205   L_TEXT("CID 6205")
#define CID_6206   L_TEXT("CID 6206")
#define CID_6207   L_TEXT("CID 6207")
#define CID_6208   L_TEXT("CID 6208")
#define CID_6209   L_TEXT("CID 6209")
#define CID_6210   L_TEXT("CID 6210")
#define CID_6211   L_TEXT("CID 6211")
#define CID_6212   L_TEXT("CID 6212")
#define CID_6300   L_TEXT("CID 6300")
#define CID_6301   L_TEXT("CID 6301")
#define CID_6302   L_TEXT("CID 6302")
#define CID_6303   L_TEXT("CID 6303")
#define CID_6304   L_TEXT("CID 6304")
#define CID_6401   L_TEXT("CID 6401")
#define CID_6402   L_TEXT("CID 6402")
#define CID_6403   L_TEXT("CID 6403")
#define CID_6404   L_TEXT("CID 6404")
#define CID_6405   L_TEXT("CID 6405")
#define CID_7000   L_TEXT("CID 7000")
#define CID_7001   L_TEXT("CID 7001")
#define CID_7002   L_TEXT("CID 7002")
#define CID_7003   L_TEXT("CID 7003")
#define CID_7004   L_TEXT("CID 7004")
#define CID_7005   L_TEXT("CID 7005")
#define CID_7006   L_TEXT("CID 7006")
#define CID_7008   L_TEXT("CID 7008")
#define CID_7009   L_TEXT("CID 7009")
#define CID_7010   L_TEXT("CID 7010")
#define CID_7011   L_TEXT("CID 7011")
#define CID_7012   L_TEXT("CID 7012")
#define CID_7013   L_TEXT("CID 7013")
#define CID_7014   L_TEXT("CID 7014")
#define CID_7015   L_TEXT("CID 7015")
#define CID_7016   L_TEXT("CID 7016")
#define CID_7017   L_TEXT("CID 7017")
#define CID_7018   L_TEXT("CID 7018")
#define CID_7019   L_TEXT("CID 7019")
#define CID_7021   L_TEXT("CID 7021")
#define CID_7022   L_TEXT("CID 7022")
#define CID_7023   L_TEXT("CID 7023")
#define CID_7024   L_TEXT("CID 7024")
#define CID_7025   L_TEXT("CID 7025")
#define CID_7026   L_TEXT("CID 7026")
#define CID_7027   L_TEXT("CID 7027")
#define CID_7030   L_TEXT("CID 7030")
#define CID_7035   L_TEXT("CID 7035")
#define CID_7036   L_TEXT("CID 7036")
#define CID_7039   L_TEXT("CID 7039")
#define CID_7040   L_TEXT("CID 7040")
#define CID_7041   L_TEXT("CID 7041")
#define CID_7042   L_TEXT("CID 7042")
#define CID_7050   L_TEXT("CID 7050")
#define CID_7060   L_TEXT("CID 7060")
#define CID_7061   L_TEXT("CID 7061")
#define CID_7062   L_TEXT("CID 7062")
#define CID_7063   L_TEXT("CID 7063")
#define CID_7064   L_TEXT("CID 7064")
#define CID_7070   L_TEXT("CID 7070")
#define CID_7100   L_TEXT("CID 7100")
#define CID_7101   L_TEXT("CID 7101")
#define CID_7110   L_TEXT("CID 7110")
#define CID_7111   L_TEXT("CID 7111")
#define CID_7112   L_TEXT("CID 7112")
#define CID_7140   L_TEXT("CID 7140")
#define CID_7150   L_TEXT("CID 7150")
#define CID_7151   L_TEXT("CID 7151")
#define CID_7152   L_TEXT("CID 7152")
#define CID_7153   L_TEXT("CID 7153")
#define CID_7154   L_TEXT("CID 7154")
#define CID_7155   L_TEXT("CID 7155")
#define CID_7156   L_TEXT("CID 7156")
#define CID_7157   L_TEXT("CID 7157")
#define CID_7158   L_TEXT("CID 7158")
#define CID_7159   L_TEXT("CID 7159")
#define CID_7160   L_TEXT("CID 7160")
#define CID_7161   L_TEXT("CID 7161")
#define CID_7162   L_TEXT("CID 7162")
#define CID_7165   L_TEXT("CID 7165")
#define CID_7166   L_TEXT("CID 7166")
#define CID_7167   L_TEXT("CID 7167")
#define CID_7168   L_TEXT("CID 7168")
#define CID_7169   L_TEXT("CID 7169")
#define CID_7170   L_TEXT("CID 7170")
#define CID_7171   L_TEXT("CID 7171")
#define CID_7180   L_TEXT("CID 7180")
#define CID_7181   L_TEXT("CID 7181")
#define CID_7182   L_TEXT("CID 7182")
#define CID_7183   L_TEXT("CID 7183")
#define CID_7184   L_TEXT("CID 7184")
#define CID_7185   L_TEXT("CID 7185")
#define CID_7186   L_TEXT("CID 7186")
#define CID_7191   L_TEXT("CID 7191")
#define CID_7192   L_TEXT("CID 7192")
#define CID_7193   L_TEXT("CID 7193")
#define CID_7194   L_TEXT("CID 7194")
#define CID_7195   L_TEXT("CID 7195")
#define CID_7196   L_TEXT("CID 7196")
#define CID_7197   L_TEXT("CID 7197")
#define CID_7198   L_TEXT("CID 7198")
#define CID_7201   L_TEXT("CID 7201")
#define CID_7202   L_TEXT("CID 7202")
#define CID_7203   L_TEXT("CID 7203")
#define CID_7205   L_TEXT("CID 7205")
#define CID_7210   L_TEXT("CID 7210")
#define CID_7215   L_TEXT("CID 7215")
#define CID_7220   L_TEXT("CID 7220")
#define CID_7221   L_TEXT("CID 7221")
#define CID_7222   L_TEXT("CID 7222")
#define CID_7230   L_TEXT("CID 7230")
#define CID_7250   L_TEXT("CID 7250")
#define CID_7260   L_TEXT("CID 7260")
#define CID_7261   L_TEXT("CID 7261")
#define CID_7262   L_TEXT("CID 7262")
#define CID_7263   L_TEXT("CID 7263")
#define CID_7270   L_TEXT("CID 7270")
#define CID_7271   L_TEXT("CID 7271")
#define CID_7272   L_TEXT("CID 7272")
#define CID_7273   L_TEXT("CID 7273")
#define CID_7274   L_TEXT("CID 7274")
#define CID_7275   L_TEXT("CID 7275")
#define CID_7276   L_TEXT("CID 7276")
#define CID_7277   L_TEXT("CID 7277")
#define CID_7300   L_TEXT("CID 7300")
#define CID_7301   L_TEXT("CID 7301")
#define CID_7302   L_TEXT("CID 7302")
#define CID_7303   L_TEXT("CID 7303")
#define CID_7304   L_TEXT("CID 7304")
#define CID_7305   L_TEXT("CID 7305")
#define CID_7306   L_TEXT("CID 7306")
#define CID_7307   L_TEXT("CID 7307")
#define CID_7308   L_TEXT("CID 7308")
#define CID_7309   L_TEXT("CID 7309")
#define CID_7310   L_TEXT("CID 7310")
#define CID_7320   L_TEXT("CID 7320")
#define CID_7445   L_TEXT("CID 7445")
#define CID_7449   L_TEXT("CID 7449")
#define CID_7450   L_TEXT("CID 7450")
#define CID_7451   L_TEXT("CID 7451")
#define CID_7452   L_TEXT("CID 7452")
#define CID_7453   L_TEXT("CID 7453")
#define CID_7454   L_TEXT("CID 7454")
#define CID_7455   L_TEXT("CID 7455")
#define CID_7456   L_TEXT("CID 7456")
#define CID_7457   L_TEXT("CID 7457")
#define CID_7460   L_TEXT("CID 7460")
#define CID_7461   L_TEXT("CID 7461")
#define CID_7462   L_TEXT("CID 7462")
#define CID_7464   L_TEXT("CID 7464")
#define CID_7465   L_TEXT("CID 7465")
#define CID_7466   L_TEXT("CID 7466")
#define CID_7467   L_TEXT("CID 7467")
#define CID_7468   L_TEXT("CID 7468")
#define CID_7469   L_TEXT("CID 7469")
#define CID_7470   L_TEXT("CID 7470")
#define CID_7471   L_TEXT("CID 7471")
#define CID_7472   L_TEXT("CID 7472")
#define CID_7473   L_TEXT("CID 7473")
#define CID_7474   L_TEXT("CID 7474")
#define CID_7475   L_TEXT("CID 7475")
#define CID_7476   L_TEXT("CID 7476")
#define CID_7477   L_TEXT("CID 7477")
#define CID_7478   L_TEXT("CID 7478")
#define CID_7479   L_TEXT("CID 7479")
#define CID_7480   L_TEXT("CID 7480")
#define CID_7481   L_TEXT("CID 7481")
#define CID_7482   L_TEXT("CID 7482")
#define CID_7483   L_TEXT("CID 7483")
#define CID_7484   L_TEXT("CID 7484")
#define CID_7486   L_TEXT("CID 7486")
#define CID_7490   L_TEXT("CID 7490")
#define CID_7500   L_TEXT("CID 7500")
#define CID_7501   L_TEXT("CID 7501")
#define CID_7550   L_TEXT("CID 7550")
#define CID_7551   L_TEXT("CID 7551")
#define CID_7552   L_TEXT("CID 7552")
#define CID_7553   L_TEXT("CID 7553")
#define CID_7600   L_TEXT("CID 7600")
#define CID_7601   L_TEXT("CID 7601")
#define CID_7701   L_TEXT("CID 7701")
#define CID_7702   L_TEXT("CID 7702")
#define CID_7703   L_TEXT("CID 7703")
#define CID_7704   L_TEXT("CID 7704")
#define CID_7705   L_TEXT("CID 7705")
#define CID_7706   L_TEXT("CID 7706")
#define CID_7707   L_TEXT("CID 7707")
#define CID_7710   L_TEXT("CID 7710")
#define CID_8101   L_TEXT("CID 8101")
#define CID_8102   L_TEXT("CID 8102")
#define CID_8103   L_TEXT("CID 8103")
#define CID_8104   L_TEXT("CID 8104")
#define CID_8109   L_TEXT("CID 8109")
#define CID_8110   L_TEXT("CID 8110")
#define CID_8111   L_TEXT("CID 8111")
#define CID_8112   L_TEXT("CID 8112")
#define CID_8113   L_TEXT("CID 8113")
#define CID_8114   L_TEXT("CID 8114")
#define CID_8115   L_TEXT("CID 8115")
#define CID_8120   L_TEXT("CID 8120")
#define CID_8121   L_TEXT("CID 8121")
#define CID_8122   L_TEXT("CID 8122")
#define CID_8123   L_TEXT("CID 8123")
#define CID_8124   L_TEXT("CID 8124")
#define CID_8125   L_TEXT("CID 8125")
#define CID_8130   L_TEXT("CID 8130")
#define CID_8131   L_TEXT("CID 8131")
#define CID_8132   L_TEXT("CID 8132")
#define CID_8133   L_TEXT("CID 8133")
#define CID_8134   L_TEXT("CID 8134")
#define CID_8201   L_TEXT("CID 8201")
#define CID_8202   L_TEXT("CID 8202")
#define CID_8203   L_TEXT("CID 8203")
#define CID_8300   L_TEXT("CID 8300")
#define CID_8301   L_TEXT("CID 8301")
#define CID_8302   L_TEXT("CID 8302")
#define CID_8303   L_TEXT("CID 8303")
#define CID_9000   L_TEXT("CID 9000")
#define CID_9231   L_TEXT("CID 9231")
#define CID_9233   L_TEXT("CID 9233")
#define CID_9241   L_TEXT("CID 9241")
#define CID_9242   L_TEXT("CID 9242")
#define CID_9243   L_TEXT("CID 9243")
#define CID_9250   L_TEXT("CID 9250")
#define CID_9300   L_TEXT("CID 9300")
#define CID_9301   L_TEXT("CID 9301")
#define CID_9302   L_TEXT("CID 9302")
#define CID_9303   L_TEXT("CID 9303")
#define CID_9401   L_TEXT("CID 9401")
#define CID_9402   L_TEXT("CID 9402")
#define CID_9403   L_TEXT("CID 9403")
#define CID_9500   L_TEXT("CID 9500")
#define CID_9501   L_TEXT("CID 9501")
#define CID_9502   L_TEXT("CID 9502")
#define CID_9503   L_TEXT("CID 9503")
#define CID_9504   L_TEXT("CID 9504")
#define CID_9505   L_TEXT("CID 9505")
#define CID_9506   L_TEXT("CID 9506")
#define CID_9507   L_TEXT("CID 9507")
#define CID_9508   L_TEXT("CID 9508")
#define CID_9509   L_TEXT("CID 9509")
#define CID_9510   L_TEXT("CID 9510")
#define CID_9511   L_TEXT("CID 9511")
#define CID_9512   L_TEXT("CID 9512")
#define CID_9513   L_TEXT("CID 9513")
#define CID_9514   L_TEXT("CID 9514")
#define CID_9515   L_TEXT("CID 9515")
#define CID_9516   L_TEXT("CID 9516")
#define CID_9517   L_TEXT("CID 9517")
#define CID_9518   L_TEXT("CID 9518")
#define CID_9519   L_TEXT("CID 9519")
#define CID_9520   L_TEXT("CID 9520")
#define CID_9521   L_TEXT("CID 9521")
#define CID_9522   L_TEXT("CID 9522")
#define CID_9523   L_TEXT("CID 9523")
#define CID_9524   L_TEXT("CID 9524")
#define CID_9525   L_TEXT("CID 9525")
#define CID_9526   L_TEXT("CID 9526")
#define CID_9527   L_TEXT("CID 9527")
#define CID_9528   L_TEXT("CID 9528")
#define CID_9529   L_TEXT("CID 9529")
#define CID_9530   L_TEXT("CID 9530")
#define CID_9531   L_TEXT("CID 9531")
#define CID_9532   L_TEXT("CID 9532")
#define CID_9533   L_TEXT("CID 9533")
#define CID_9534   L_TEXT("CID 9534")
#define CID_9535   L_TEXT("CID 9535")
#define CID_9536   L_TEXT("CID 9536")
#define CID_9537   L_TEXT("CID 9537")
#define CID_9538   L_TEXT("CID 9538")
#define CID_9539   L_TEXT("CID 9539")
#define CID_9541   L_TEXT("CID 9541")
#define CID_9542   L_TEXT("CID 9542")
#define CID_9543   L_TEXT("CID 9543")
#define CID_9544   L_TEXT("CID 9544")
#define CID_9545   L_TEXT("CID 9545")
#define CID_9546   L_TEXT("CID 9546")
#define CID_9547   L_TEXT("CID 9547")
#define CID_9548   L_TEXT("CID 9548")
#define CID_9549   L_TEXT("CID 9549")
#define CID_9550   L_TEXT("CID 9550")
#define CID_9551   L_TEXT("CID 9551")
#define CID_9552   L_TEXT("CID 9552")
#define CID_9553   L_TEXT("CID 9553")
#define CID_9554   L_TEXT("CID 9554")
#define CID_9555   L_TEXT("CID 9555")
#define CID_9556   L_TEXT("CID 9556")
#define CID_9557   L_TEXT("CID 9557")
#define CID_9558   L_TEXT("CID 9558")
#define CID_9559   L_TEXT("CID 9559")
#define CID_9560   L_TEXT("CID 9560")
#define CID_9561   L_TEXT("CID 9561")
#define CID_9562   L_TEXT("CID 9562")
#define CID_9563   L_TEXT("CID 9563")
#define CID_9564   L_TEXT("CID 9564")
#define CID_9565   L_TEXT("CID 9565")
#define CID_9566   L_TEXT("CID 9566")
#define CID_9567   L_TEXT("CID 9567")
#define CID_9568   L_TEXT("CID 9568")
#define CID_9569   L_TEXT("CID 9569")
#define CID_9570   L_TEXT("CID 9570")
#define CID_10000  L_TEXT("CID 10000")
#define CID_10001  L_TEXT("CID 10001")
#define CID_10002  L_TEXT("CID 10002")
#define CID_10003  L_TEXT("CID 10003")
#define CID_10004  L_TEXT("CID 10004")
#define CID_10006  L_TEXT("CID 10006")
#define CID_10007  L_TEXT("CID 10007")
#define CID_10008  L_TEXT("CID 10008")
#define CID_10009  L_TEXT("CID 10009")
#define CID_10010  L_TEXT("CID 10010")
#define CID_10011  L_TEXT("CID 10011")
#define CID_10013  L_TEXT("CID 10013")
#define CID_10014  L_TEXT("CID 10014")
#define CID_10015  L_TEXT("CID 10015")
#define CID_10016  L_TEXT("CID 10016")
#define CID_10017  L_TEXT("CID 10017")
#define CID_10020  L_TEXT("CID 10020")
#define CID_10021  L_TEXT("CID 10021")
#define CID_10022  L_TEXT("CID 10022")
#define CID_10023  L_TEXT("CID 10023")
#define CID_10024  L_TEXT("CID 10024")
#define CID_10025  L_TEXT("CID 10025")
#define CID_10030  L_TEXT("CID 10030")
#define CID_10031  L_TEXT("CID 10031")
#define CID_10032  L_TEXT("CID 10032")
#define CID_10033  L_TEXT("CID 10033")
#define CID_10034  L_TEXT("CID 10034")
#define CID_10040  L_TEXT("CID 10040")
#define CID_10041  L_TEXT("CID 10041")
#define CID_10043  L_TEXT("CID 10043")
#define CID_10044  L_TEXT("CID 10044")
#define CID_10045  L_TEXT("CID 10045")
#define CID_10046  L_TEXT("CID 10046")
#define CID_10047  L_TEXT("CID 10047")
#define CID_10050  L_TEXT("CID 10050")
#define CID_10060  L_TEXT("CID 10060")
#define CID_10061  L_TEXT("CID 10061")
#define CID_10062  L_TEXT("CID 10062")
#define CID_10063  L_TEXT("CID 10063")
#define CID_10064  L_TEXT("CID 10064")
#define CID_10065  L_TEXT("CID 10065")
#define CID_10066  L_TEXT("CID 10066")
#define CID_10067  L_TEXT("CID 10067")
#define CID_10068  L_TEXT("CID 10068")
#define CID_10069  L_TEXT("CID 10069")
#define CID_10070  L_TEXT("CID 10070")
#define CID_10071  L_TEXT("CID 10071")
#define CID_10072  L_TEXT("CID 10072")
#define CID_10073  L_TEXT("CID 10073")
#define CID_10074  L_TEXT("CID 10074")
#define CID_12001  L_TEXT("CID 12001")
#define CID_12002  L_TEXT("CID 12002")
#define CID_12003  L_TEXT("CID 12003")
#define CID_12004  L_TEXT("CID 12004")
#define CID_12005  L_TEXT("CID 12005")
#define CID_12006  L_TEXT("CID 12006")
#define CID_12007  L_TEXT("CID 12007")
#define CID_12008  L_TEXT("CID 12008")
#define CID_12009  L_TEXT("CID 12009")
#define CID_12011  L_TEXT("CID 12011")
#define CID_12012  L_TEXT("CID 12012")
#define CID_12013  L_TEXT("CID 12013")
#define CID_12014  L_TEXT("CID 12014")
#define CID_12015  L_TEXT("CID 12015")
#define CID_12016  L_TEXT("CID 12016")
#define CID_12017  L_TEXT("CID 12017")
#define CID_12018  L_TEXT("CID 12018")
#define CID_12019  L_TEXT("CID 12019")
#define CID_12020  L_TEXT("CID 12020")
#define CID_12021  L_TEXT("CID 12021")
#define CID_12022  L_TEXT("CID 12022")
#define CID_12023  L_TEXT("CID 12023")
#define CID_12024  L_TEXT("CID 12024")
#define CID_12025  L_TEXT("CID 12025")
#define CID_12030  L_TEXT("CID 12030")
#define CID_12031  L_TEXT("CID 12031")
#define CID_12032  L_TEXT("CID 12032")
#define CID_12033  L_TEXT("CID 12033")
#define CID_12034  L_TEXT("CID 12034")
#define CID_12035  L_TEXT("CID 12035")
#define CID_12100  L_TEXT("CID 12100")
#define CID_12101  L_TEXT("CID 12101")
#define CID_12102  L_TEXT("CID 12102")
#define CID_12103  L_TEXT("CID 12103")
#define CID_12104  L_TEXT("CID 12104")
#define CID_12105  L_TEXT("CID 12105")
#define CID_12106  L_TEXT("CID 12106")
#define CID_12107  L_TEXT("CID 12107")
#define CID_12108  L_TEXT("CID 12108")
#define CID_12109  L_TEXT("CID 12109")
#define CID_12110  L_TEXT("CID 12110")
#define CID_12111  L_TEXT("CID 12111")
#define CID_12112  L_TEXT("CID 12112")
#define CID_12113  L_TEXT("CID 12113")
#define CID_12114  L_TEXT("CID 12114")
#define CID_12115  L_TEXT("CID 12115")
#define CID_12116  L_TEXT("CID 12116")
#define CID_12117  L_TEXT("CID 12117")
#define CID_12118  L_TEXT("CID 12118")
#define CID_12119  L_TEXT("CID 12119")
#define CID_12120  L_TEXT("CID 12120")
#define CID_12121  L_TEXT("CID 12121")
#define CID_12122  L_TEXT("CID 12122")
#define CID_12123  L_TEXT("CID 12123")
#define CID_12124  L_TEXT("CID 12124")
#define CID_12125  L_TEXT("CID 12125")
#define CID_12130  L_TEXT("CID 12130")
#define CID_12131  L_TEXT("CID 12131")
#define CID_12140  L_TEXT("CID 12140")
#define CID_12141  L_TEXT("CID 12141")
#define CID_12200  L_TEXT("CID 12200")
#define CID_12201  L_TEXT("CID 12201")
#define CID_12202  L_TEXT("CID 12202")
#define CID_12203  L_TEXT("CID 12203")
#define CID_12204  L_TEXT("CID 12204")
#define CID_12205  L_TEXT("CID 12205")
#define CID_12206  L_TEXT("CID 12206")
#define CID_12207  L_TEXT("CID 12207")
#define CID_12208  L_TEXT("CID 12208")
#define CID_12209  L_TEXT("CID 12209")
#define CID_12210  L_TEXT("CID 12210")
#define CID_12211  L_TEXT("CID 12211")
#define CID_12212  L_TEXT("CID 12212")
#define CID_12214  L_TEXT("CID 12214")
#define CID_12215  L_TEXT("CID 12215")
#define CID_12216  L_TEXT("CID 12216")
#define CID_12217  L_TEXT("CID 12217")
#define CID_12218  L_TEXT("CID 12218")
#define CID_12219  L_TEXT("CID 12219")
#define CID_12220  L_TEXT("CID 12220")
#define CID_12221  L_TEXT("CID 12221")
#define CID_12222  L_TEXT("CID 12222")
#define CID_12223  L_TEXT("CID 12223")
#define CID_12224  L_TEXT("CID 12224")
#define CID_12226  L_TEXT("CID 12226")
#define CID_12227  L_TEXT("CID 12227")
#define CID_12228  L_TEXT("CID 12228")
#define CID_12229  L_TEXT("CID 12229")
#define CID_12230  L_TEXT("CID 12230")
#define CID_12231  L_TEXT("CID 12231")
#define CID_12232  L_TEXT("CID 12232")
#define CID_12233  L_TEXT("CID 12233")
#define CID_12234  L_TEXT("CID 12234")
#define CID_12235  L_TEXT("CID 12235")
#define CID_12236  L_TEXT("CID 12236")
#define CID_12237  L_TEXT("CID 12237")
#define CID_12238  L_TEXT("CID 12238")
#define CID_12239  L_TEXT("CID 12239")
#define CID_12240  L_TEXT("CID 12240")
#define CID_12241  L_TEXT("CID 12241")
#define CID_12242  L_TEXT("CID 12242")
#define CID_12243  L_TEXT("CID 12243")
#define CID_12244  L_TEXT("CID 12244")
#define CID_12245  L_TEXT("CID 12245")
#define CID_12246  L_TEXT("CID 12246")
#define CID_12247  L_TEXT("CID 12247")
#define CID_12248  L_TEXT("CID 12248")
#define CID_12249  L_TEXT("CID 12249")
#define CID_12250  L_TEXT("CID 12250")
#define CID_12251  L_TEXT("CID 12251")
#define CID_12252  L_TEXT("CID 12252")
#define CID_12253  L_TEXT("CID 12253")
#define CID_12254  L_TEXT("CID 12254")
#define CID_12255  L_TEXT("CID 12255")
#define CID_12257  L_TEXT("CID 12257")
#define CID_12258  L_TEXT("CID 12258")
#define CID_12259  L_TEXT("CID 12259")
#define CID_12260  L_TEXT("CID 12260")
#define CID_12261  L_TEXT("CID 12261")
#define CID_12262  L_TEXT("CID 12262")
#define CID_12263  L_TEXT("CID 12263")
#define CID_12264  L_TEXT("CID 12264")
#define CID_12265  L_TEXT("CID 12265")
#define CID_12266  L_TEXT("CID 12266")
#define CID_12267  L_TEXT("CID 12267")
#define CID_12268  L_TEXT("CID 12268")
#define CID_12269  L_TEXT("CID 12269")
#define CID_12270  L_TEXT("CID 12270")
#define CID_12271  L_TEXT("CID 12271")
#define CID_12272  L_TEXT("CID 12272")
#define CID_12273  L_TEXT("CID 12273")
#define CID_12274  L_TEXT("CID 12274")
#define CID_12275  L_TEXT("CID 12275")
#define CID_12276  L_TEXT("CID 12276")
#define CID_12277  L_TEXT("CID 12277")
#define CID_12279  L_TEXT("CID 12279")
#define CID_12280  L_TEXT("CID 12280")
#define CID_12281  L_TEXT("CID 12281")
#define CID_12282  L_TEXT("CID 12282")
#define CID_12283  L_TEXT("CID 12283")
#define CID_12284  L_TEXT("CID 12284")
#define CID_12285  L_TEXT("CID 12285")
#define CID_12286  L_TEXT("CID 12286")
#define CID_12287  L_TEXT("CID 12287")
#define CID_12288  L_TEXT("CID 12288")
#define CID_12289  L_TEXT("CID 12289")
#define CID_12290  L_TEXT("CID 12290")
#define CID_12291  L_TEXT("CID 12291")
#define CID_12292  L_TEXT("CID 12292")
#define CID_12293  L_TEXT("CID 12293")
#define CID_12294  L_TEXT("CID 12294")
#define CID_12300  L_TEXT("CID 12300")
#define CID_12301  L_TEXT("CID 12301")
#define CID_12302  L_TEXT("CID 12302")
#define CID_12303  L_TEXT("CID 12303")
#define CID_12304  L_TEXT("CID 12304")
#define CID_12305  L_TEXT("CID 12305")
#define CID_12306  L_TEXT("CID 12306")
#define CID_12307  L_TEXT("CID 12307")
// End of Context ID definitions 

#if !defined (EXCLUDE_DICOM_FUNCTIONS)
// Context Group
typedef struct tagDICOMCONTEXTGROUP
{
   GENERICLINK

   L_TCHAR*       pszContextIdentifier;
   L_TCHAR*       pszName;
   L_BOOL         bExtensible;
   pVALUEDATETIME pContextGroupVersion;

} DICOMCONTEXTGROUP, * pDICOMCONTEXTGROUP;

// Coded Concept
typedef struct tagDICOMCODEDCONCEPT
{
   GENERICLINK

   L_TCHAR*        pszCodingSchemeDesignator;
   L_TCHAR*        pszCodingSchemeVersion;
   L_TCHAR*        pszCodeValue;
   L_TCHAR*        pszCodeMeaning;

   pVALUEDATETIME pContextGroupLocalVersion;
   L_TCHAR*        pszContextGroupExtensionCreatorUID;

} DICOMCODEDCONCEPT, * pDICOMCODEDCONCEPT;

#define DICOM_CONTEXTGROUP_DISALLOW_DUPLICATES   0x01

#if defined(__cplusplus)

class L_LTDIC_CLASS LDicomContextGroup
{
public:   
   // Context Groups

   static L_UINT16  LoadXml(L_TCHAR *pszFile, L_UINT uFlags);

   static L_UINT16           Load(L_TCHAR* pszContextID = NULL);
   static L_VOID             Reset();

   static pDICOMCONTEXTGROUP GetFirst();
   static pDICOMCONTEXTGROUP GetLast();
   static pDICOMCONTEXTGROUP GetNext(pDICOMCONTEXTGROUP pContextGroup);
   static pDICOMCONTEXTGROUP GetPrev(pDICOMCONTEXTGROUP pContextGroup);

   static L_UINT32           GetCount();
   static pDICOMCONTEXTGROUP Find(L_TCHAR* pszContextID);
   static pDICOMCONTEXTGROUP FindIndex(L_UINT32 uIndex);

   static pDICOMCONTEXTGROUP Insert(L_TCHAR* pszContextIdentifier,
                                    L_TCHAR* pszName,
                                    L_BOOL bExtensible,
                                    pVALUEDATETIME pContextGroupVersion,
                                    L_UINT16 uFlags = 0);
   static pDICOMCONTEXTGROUP Delete(pDICOMCONTEXTGROUP pContextGroup);
   static L_BOOL             Default(pDICOMCONTEXTGROUP pContextGroup);
   static L_BOOL             Exists(pDICOMCONTEXTGROUP pContextGroup);

   // Coded Concepts

   static pDICOMCODEDCONCEPT GetFirstCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   static pDICOMCODEDCONCEPT GetLastCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   static pDICOMCODEDCONCEPT GetNextCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   static pDICOMCODEDCONCEPT GetPrevCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   static pDICOMCONTEXTGROUP GetContextGroup(pDICOMCODEDCONCEPT pCodedConcept);

   static L_UINT32           GetCountCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   static pDICOMCODEDCONCEPT FindCodedConcept(pDICOMCONTEXTGROUP pContextGroup,
                                              L_TCHAR* pszCodingSchemeDesignator,
                                              L_TCHAR* pszCodeValue);
   static pDICOMCODEDCONCEPT FindIndexCodedConcept(pDICOMCONTEXTGROUP pContextGroup,
                                                   L_UINT32 uIndex);

   static L_BOOL             SetCodeMeaning(pDICOMCODEDCONCEPT pCodedConcept,
                                            L_TCHAR* pszCodeMeaning);
   static pDICOMCODEDCONCEPT InsertCodedConcept(pDICOMCONTEXTGROUP pContextGroup,
                                                L_TCHAR* pszCodingSchemeDesignator,
                                                L_TCHAR* pszCodingSchemeVersion,
                                                L_TCHAR* pszCodeValue,
                                                L_TCHAR* pszCodeMeaning,
                                                pVALUEDATETIME pContextGroupLocalVersion = NULL,
                                                L_TCHAR* pszContextGroupExtensionCreatorUID = NULL,
                                                L_UINT16 uFlags = 0);
   static pDICOMCODEDCONCEPT DeleteCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   static L_BOOL             ExistsCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);

private:
#if 0
   static LDicomTreeEx m_ContextGroupsTable;
#else
   static LDicomTreeEx* m_pContextGroupsTable;
   static LDicomTreeEx& GetContextGroupsTable();
   friend L_VOID EXT_FUNCTION L_DicomEngineShutdown(L_VOID);
   static L_BOOL HasFirst();
#endif // #if 0

   static L_BOOL LoadCodedConcepts(L_UINT32 uContextGroupIndex,
                                   pDICOMCONTEXTGROUP pContextGroup = NULL,
                                   L_BOOL bDeleteIfFailed = TRUE);

   static L_BOOL m_bInitialized;
public:
   static L_VOID SetInitialized(L_BOOL bValue);
};

#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

   // Context Groups
   L_LTDIC_API L_UINT16           EXT_FUNCTION L_DicomLoadContextGroup(L_TCHAR* pszContextID);
   L_LTDIC_API L_VOID             EXT_FUNCTION L_DicomResetContextGroup(L_VOID);

   L_LTDIC_API L_UINT16             EXT_FUNCTION L_DicomLoadXmlContextGroup(L_TCHAR *pszFile, L_UINT uFlags);

   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomGetFirstContextGroup(L_VOID);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomGetLastContextGroup(L_VOID);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomGetNextContextGroup(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomGetPrevContextGroup(pDICOMCONTEXTGROUP pContextGroup);

   L_LTDIC_API L_UINT32           EXT_FUNCTION L_DicomGetCountContextGroup(L_VOID);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomFindContextGroup(L_TCHAR* pszContextID);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomFindIndexContextGroup(L_UINT32 uIndex);

   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomInsertContextGroup(L_TCHAR* pszContextIdentifier, L_TCHAR* pszName, L_BOOL bExtensible, pVALUEDATETIME pContextGroupVersion,L_UINT16 uFlags);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomDeleteContextGroup(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API L_BOOL             EXT_FUNCTION L_DicomDefaultContextGroup(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API L_BOOL             EXT_FUNCTION L_DicomExistsContextGroup(pDICOMCONTEXTGROUP pContextGroup);

   // Coded Concepts

   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomGetFirstCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomGetLastCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomGetNextCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomGetPrevCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   L_LTDIC_API pDICOMCONTEXTGROUP EXT_FUNCTION L_DicomGetCodedConceptGroup(pDICOMCODEDCONCEPT pCodedConcept);

   L_LTDIC_API L_UINT32           EXT_FUNCTION L_DicomGetCountCodedConcept(pDICOMCONTEXTGROUP pContextGroup);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomFindCodedConcept(pDICOMCONTEXTGROUP pContextGroup, L_TCHAR* pszCodingSchemeDesignator, L_TCHAR* pszCodeValue);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomFindIndexCodedConcept(pDICOMCONTEXTGROUP pContextGroup, L_UINT32 uIndex);

   L_LTDIC_API L_BOOL             EXT_FUNCTION L_DicomSetCodedConceptCodeMeaning(pDICOMCODEDCONCEPT pCodedConcept, L_TCHAR* pszCodeMeaning);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomInsertCodedConcept(pDICOMCONTEXTGROUP pContextGroup, L_TCHAR* pszCodingSchemeDesignator, L_TCHAR* pszCodingSchemeVersion, L_TCHAR* pszCodeValue, L_TCHAR* pszCodeMeaning, pVALUEDATETIME pContextGroupLocalVersion, L_TCHAR* pszContextGroupExtensionCreatorUID,L_UINT16 uFlags);
   L_LTDIC_API pDICOMCODEDCONCEPT EXT_FUNCTION L_DicomDeleteCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);
   L_LTDIC_API L_BOOL             EXT_FUNCTION L_DicomExistsCodedConcept(pDICOMCODEDCONCEPT pCodedConcept);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#pragma pack()

#endif //!defined (EXCLUDE_DICOM_FUNCTIONS)

#endif // #if !defined(LTDIC_H)
