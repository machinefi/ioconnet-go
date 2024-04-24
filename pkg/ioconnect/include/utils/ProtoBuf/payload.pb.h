/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_PAYLOAD_PB_H_INCLUDED
#define PB_PAYLOAD_PB_H_INCLUDED
#include "include/utils/ProtoBuf/pb.h"
#include "include/utils/ProtoBuf/packconfirm.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _Payload_UserDataType {
    Payload_UserDataType_JSON = 0,
    Payload_UserDataType_PB = 1,
    Payload_UserDataType_RAW = 2
} Payload_UserDataType;

typedef enum _Payload_PackageType {
    Payload_PackageType_UNKNOW = 0,
    Payload_PackageType_QUERY = 1,
    Payload_PackageType_COMFIRM = 2,
    Payload_PackageType_USERDATA = 3
} Payload_PackageType;

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(65) Payload_pubkey_t;
typedef PB_BYTES_ARRAY_T(64) Payload_sign_t;
typedef PB_BYTES_ARRAY_T(6) Payload_mac_t;
typedef PB_BYTES_ARRAY_T(320) Payload_user_t;
typedef struct _Payload {
    Payload_PackageType ptype;
    Payload_pubkey_t pubkey;
    Payload_sign_t sign;
    Payload_mac_t mac;
    Payload_UserDataType dtype;
    Payload_user_t user;
    bool has_pConfirm;
    Confirm pConfirm;
} Payload;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _Payload_UserDataType_MIN Payload_UserDataType_JSON
#define _Payload_UserDataType_MAX Payload_UserDataType_RAW
#define _Payload_UserDataType_ARRAYSIZE ((Payload_UserDataType)(Payload_UserDataType_RAW+1))

#define _Payload_PackageType_MIN Payload_PackageType_UNKNOW
#define _Payload_PackageType_MAX Payload_PackageType_USERDATA
#define _Payload_PackageType_ARRAYSIZE ((Payload_PackageType)(Payload_PackageType_USERDATA+1))

#define Payload_ptype_ENUMTYPE Payload_PackageType
#define Payload_dtype_ENUMTYPE Payload_UserDataType


/* Initializer values for message structs */
#define Payload_init_default                     {_Payload_PackageType_MIN, {0, {0}}, {0, {0}}, {0, {0}}, _Payload_UserDataType_MIN, {0, {0}}, false, Confirm_init_default}
#define Payload_init_zero                        {_Payload_PackageType_MIN, {0, {0}}, {0, {0}}, {0, {0}}, _Payload_UserDataType_MIN, {0, {0}}, false, Confirm_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define Payload_ptype_tag                        1
#define Payload_pubkey_tag                       2
#define Payload_sign_tag                         3
#define Payload_mac_tag                          4
#define Payload_dtype_tag                        5
#define Payload_user_tag                         6
#define Payload_pConfirm_tag                     7

/* Struct field encoding specification for nanopb */
#define Payload_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    ptype,             1) \
X(a, STATIC,   SINGULAR, BYTES,    pubkey,            2) \
X(a, STATIC,   SINGULAR, BYTES,    sign,              3) \
X(a, STATIC,   SINGULAR, BYTES,    mac,               4) \
X(a, STATIC,   SINGULAR, UENUM,    dtype,             5) \
X(a, STATIC,   SINGULAR, BYTES,    user,              6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  pConfirm,          7)
#define Payload_CALLBACK NULL
#define Payload_DEFAULT NULL
#define Payload_pConfirm_MSGTYPE Confirm

extern const pb_msgdesc_t Payload_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Payload_fields &Payload_msg

/* Maximum encoded size of messages (where known) */
#define Payload_size                             648

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
