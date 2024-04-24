#ifndef IOTEX_OID_H
#define IOTEX_OID_H

#include "include/iotex/build_info.h"

#include "include/iotex/asn1.h"
#include "include/iotex/pk.h"

#include <stddef.h>

#if defined(IOTEX_CIPHER_C)
#include "include/iotex/cipher.h"
#endif

#if defined(IOTEX_MD_C)
#include "include/iotex/md.h"
#endif

/** OID is not found. */
#define IOTEX_ERR_OID_NOT_FOUND                         -0x002E
/** output buffer is too small */
#define IOTEX_ERR_OID_BUF_TOO_SMALL                     -0x000B

/* This is for the benefit of X.509, but defined here in order to avoid
 * having a "backwards" include of x.509.h here */
/*
 * X.509 extension types (internal, arbitrary values for bitsets)
 */
#define IOTEX_OID_X509_EXT_AUTHORITY_KEY_IDENTIFIER    (1 << 0)
#define IOTEX_OID_X509_EXT_SUBJECT_KEY_IDENTIFIER      (1 << 1)
#define IOTEX_OID_X509_EXT_KEY_USAGE                   (1 << 2)
#define IOTEX_OID_X509_EXT_CERTIFICATE_POLICIES        (1 << 3)
#define IOTEX_OID_X509_EXT_POLICY_MAPPINGS             (1 << 4)
#define IOTEX_OID_X509_EXT_SUBJECT_ALT_NAME            (1 << 5)
#define IOTEX_OID_X509_EXT_ISSUER_ALT_NAME             (1 << 6)
#define IOTEX_OID_X509_EXT_SUBJECT_DIRECTORY_ATTRS     (1 << 7)
#define IOTEX_OID_X509_EXT_BASIC_CONSTRAINTS           (1 << 8)
#define IOTEX_OID_X509_EXT_NAME_CONSTRAINTS            (1 << 9)
#define IOTEX_OID_X509_EXT_POLICY_CONSTRAINTS          (1 << 10)
#define IOTEX_OID_X509_EXT_EXTENDED_KEY_USAGE          (1 << 11)
#define IOTEX_OID_X509_EXT_CRL_DISTRIBUTION_POINTS     (1 << 12)
#define IOTEX_OID_X509_EXT_INIHIBIT_ANYPOLICY          (1 << 13)
#define IOTEX_OID_X509_EXT_FRESHEST_CRL                (1 << 14)
#define IOTEX_OID_X509_EXT_NS_CERT_TYPE                (1 << 16)

/*
 * Top level OID tuples
 */
#define IOTEX_OID_ISO_MEMBER_BODIES           "\x2a"          /* {iso(1) member-body(2)} */
#define IOTEX_OID_ISO_IDENTIFIED_ORG          "\x2b"          /* {iso(1) identified-organization(3)} */
#define IOTEX_OID_ISO_CCITT_DS                "\x55"          /* {joint-iso-ccitt(2) ds(5)} */
#define IOTEX_OID_ISO_ITU_COUNTRY             "\x60"          /* {joint-iso-itu-t(2) country(16)} */

/*
 * ISO Member bodies OID parts
 */
#define IOTEX_OID_COUNTRY_US                  "\x86\x48"      /* {us(840)} */
#define IOTEX_OID_ORG_RSA_DATA_SECURITY       "\x86\xf7\x0d"  /* {rsadsi(113549)} */
#define IOTEX_OID_RSA_COMPANY                 IOTEX_OID_ISO_MEMBER_BODIES IOTEX_OID_COUNTRY_US \
                                        IOTEX_OID_ORG_RSA_DATA_SECURITY /* {iso(1) member-body(2) us(840) rsadsi(113549)} */
#define IOTEX_OID_ORG_ANSI_X9_62              "\xce\x3d" /* ansi-X9-62(10045) */
#define IOTEX_OID_ANSI_X9_62                  IOTEX_OID_ISO_MEMBER_BODIES IOTEX_OID_COUNTRY_US \
                                        IOTEX_OID_ORG_ANSI_X9_62

/*
 * ISO Identified organization OID parts
 */
#define IOTEX_OID_ORG_DOD                     "\x06"          /* {dod(6)} */
#define IOTEX_OID_ORG_OIW                     "\x0e"
#define IOTEX_OID_OIW_SECSIG                  IOTEX_OID_ORG_OIW "\x03"
#define IOTEX_OID_OIW_SECSIG_ALG              IOTEX_OID_OIW_SECSIG "\x02"
#define IOTEX_OID_OIW_SECSIG_SHA1             IOTEX_OID_OIW_SECSIG_ALG "\x1a"
#define IOTEX_OID_ORG_CERTICOM                "\x81\x04"  /* certicom(132) */
#define IOTEX_OID_CERTICOM                    IOTEX_OID_ISO_IDENTIFIED_ORG IOTEX_OID_ORG_CERTICOM
#define IOTEX_OID_ORG_TELETRUST               "\x24" /* teletrust(36) */
#define IOTEX_OID_TELETRUST                   IOTEX_OID_ISO_IDENTIFIED_ORG IOTEX_OID_ORG_TELETRUST

/*
 * ISO ITU OID parts
 */
#define IOTEX_OID_ORGANIZATION                "\x01"          /* {organization(1)} */
#define IOTEX_OID_ISO_ITU_US_ORG              IOTEX_OID_ISO_ITU_COUNTRY IOTEX_OID_COUNTRY_US IOTEX_OID_ORGANIZATION /* {joint-iso-itu-t(2) country(16) us(840) organization(1)} */

#define IOTEX_OID_ORG_GOV                     "\x65"          /* {gov(101)} */
#define IOTEX_OID_GOV                         IOTEX_OID_ISO_ITU_US_ORG IOTEX_OID_ORG_GOV /* {joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101)} */

#define IOTEX_OID_ORG_NETSCAPE                "\x86\xF8\x42"  /* {netscape(113730)} */
#define IOTEX_OID_NETSCAPE                    IOTEX_OID_ISO_ITU_US_ORG IOTEX_OID_ORG_NETSCAPE /* Netscape OID {joint-iso-itu-t(2) country(16) us(840) organization(1) netscape(113730)} */

/* ISO arc for standard certificate and CRL extensions */
#define IOTEX_OID_ID_CE                       IOTEX_OID_ISO_CCITT_DS "\x1D" /**< id-ce OBJECT IDENTIFIER  ::=  {joint-iso-ccitt(2) ds(5) 29} */

#define IOTEX_OID_NIST_ALG                    IOTEX_OID_GOV "\x03\x04" /** { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistAlgorithm(4) */

/**
 * Private Internet Extensions
 * { iso(1) identified-organization(3) dod(6) internet(1)
 *                      security(5) mechanisms(5) pkix(7) }
 */
#define IOTEX_OID_INTERNET                    IOTEX_OID_ISO_IDENTIFIED_ORG IOTEX_OID_ORG_DOD "\x01"
#define IOTEX_OID_PKIX                        IOTEX_OID_INTERNET "\x05\x05\x07"

/*
 * Arc for standard naming attributes
 */
#define IOTEX_OID_AT                          IOTEX_OID_ISO_CCITT_DS "\x04" /**< id-at OBJECT IDENTIFIER ::= {joint-iso-ccitt(2) ds(5) 4} */
#define IOTEX_OID_AT_CN                       IOTEX_OID_AT "\x03" /**< id-at-commonName AttributeType:= {id-at 3} */
#define IOTEX_OID_AT_SUR_NAME                 IOTEX_OID_AT "\x04" /**< id-at-surName AttributeType:= {id-at 4} */
#define IOTEX_OID_AT_SERIAL_NUMBER            IOTEX_OID_AT "\x05" /**< id-at-serialNumber AttributeType:= {id-at 5} */
#define IOTEX_OID_AT_COUNTRY                  IOTEX_OID_AT "\x06" /**< id-at-countryName AttributeType:= {id-at 6} */
#define IOTEX_OID_AT_LOCALITY                 IOTEX_OID_AT "\x07" /**< id-at-locality AttributeType:= {id-at 7} */
#define IOTEX_OID_AT_STATE                    IOTEX_OID_AT "\x08" /**< id-at-state AttributeType:= {id-at 8} */
#define IOTEX_OID_AT_ORGANIZATION             IOTEX_OID_AT "\x0A" /**< id-at-organizationName AttributeType:= {id-at 10} */
#define IOTEX_OID_AT_ORG_UNIT                 IOTEX_OID_AT "\x0B" /**< id-at-organizationalUnitName AttributeType:= {id-at 11} */
#define IOTEX_OID_AT_TITLE                    IOTEX_OID_AT "\x0C" /**< id-at-title AttributeType:= {id-at 12} */
#define IOTEX_OID_AT_POSTAL_ADDRESS           IOTEX_OID_AT "\x10" /**< id-at-postalAddress AttributeType:= {id-at 16} */
#define IOTEX_OID_AT_POSTAL_CODE              IOTEX_OID_AT "\x11" /**< id-at-postalCode AttributeType:= {id-at 17} */
#define IOTEX_OID_AT_GIVEN_NAME               IOTEX_OID_AT "\x2A" /**< id-at-givenName AttributeType:= {id-at 42} */
#define IOTEX_OID_AT_INITIALS                 IOTEX_OID_AT "\x2B" /**< id-at-initials AttributeType:= {id-at 43} */
#define IOTEX_OID_AT_GENERATION_QUALIFIER     IOTEX_OID_AT "\x2C" /**< id-at-generationQualifier AttributeType:= {id-at 44} */
#define IOTEX_OID_AT_UNIQUE_IDENTIFIER        IOTEX_OID_AT "\x2D" /**< id-at-uniqueIdentifier AttributeType:= {id-at 45} */
#define IOTEX_OID_AT_DN_QUALIFIER             IOTEX_OID_AT "\x2E" /**< id-at-dnQualifier AttributeType:= {id-at 46} */
#define IOTEX_OID_AT_PSEUDONYM                IOTEX_OID_AT "\x41" /**< id-at-pseudonym AttributeType:= {id-at 65} */

#define IOTEX_OID_UID                         "\x09\x92\x26\x89\x93\xF2\x2C\x64\x01\x01" /** id-domainComponent AttributeType:= {itu-t(0) data(9) pss(2342) ucl(19200300) pilot(100) pilotAttributeType(1) uid(1)} */
#define IOTEX_OID_DOMAIN_COMPONENT            "\x09\x92\x26\x89\x93\xF2\x2C\x64\x01\x19" /** id-domainComponent AttributeType:= {itu-t(0) data(9) pss(2342) ucl(19200300) pilot(100) pilotAttributeType(1) domainComponent(25)} */

/*
 * OIDs for standard certificate extensions
 */
#define IOTEX_OID_AUTHORITY_KEY_IDENTIFIER    IOTEX_OID_ID_CE "\x23" /**< id-ce-authorityKeyIdentifier OBJECT IDENTIFIER ::=  { id-ce 35 } */
#define IOTEX_OID_SUBJECT_KEY_IDENTIFIER      IOTEX_OID_ID_CE "\x0E" /**< id-ce-subjectKeyIdentifier OBJECT IDENTIFIER ::=  { id-ce 14 } */
#define IOTEX_OID_KEY_USAGE                   IOTEX_OID_ID_CE "\x0F" /**< id-ce-keyUsage OBJECT IDENTIFIER ::=  { id-ce 15 } */
#define IOTEX_OID_CERTIFICATE_POLICIES        IOTEX_OID_ID_CE "\x20" /**< id-ce-certificatePolicies OBJECT IDENTIFIER ::=  { id-ce 32 } */
#define IOTEX_OID_POLICY_MAPPINGS             IOTEX_OID_ID_CE "\x21" /**< id-ce-policyMappings OBJECT IDENTIFIER ::=  { id-ce 33 } */
#define IOTEX_OID_SUBJECT_ALT_NAME            IOTEX_OID_ID_CE "\x11" /**< id-ce-subjectAltName OBJECT IDENTIFIER ::=  { id-ce 17 } */
#define IOTEX_OID_ISSUER_ALT_NAME             IOTEX_OID_ID_CE "\x12" /**< id-ce-issuerAltName OBJECT IDENTIFIER ::=  { id-ce 18 } */
#define IOTEX_OID_SUBJECT_DIRECTORY_ATTRS     IOTEX_OID_ID_CE "\x09" /**< id-ce-subjectDirectoryAttributes OBJECT IDENTIFIER ::=  { id-ce 9 } */
#define IOTEX_OID_BASIC_CONSTRAINTS           IOTEX_OID_ID_CE "\x13" /**< id-ce-basicConstraints OBJECT IDENTIFIER ::=  { id-ce 19 } */
#define IOTEX_OID_NAME_CONSTRAINTS            IOTEX_OID_ID_CE "\x1E" /**< id-ce-nameConstraints OBJECT IDENTIFIER ::=  { id-ce 30 } */
#define IOTEX_OID_POLICY_CONSTRAINTS          IOTEX_OID_ID_CE "\x24" /**< id-ce-policyConstraints OBJECT IDENTIFIER ::=  { id-ce 36 } */
#define IOTEX_OID_EXTENDED_KEY_USAGE          IOTEX_OID_ID_CE "\x25" /**< id-ce-extKeyUsage OBJECT IDENTIFIER ::= { id-ce 37 } */
#define IOTEX_OID_CRL_DISTRIBUTION_POINTS     IOTEX_OID_ID_CE "\x1F" /**< id-ce-cRLDistributionPoints OBJECT IDENTIFIER ::=  { id-ce 31 } */
#define IOTEX_OID_INIHIBIT_ANYPOLICY          IOTEX_OID_ID_CE "\x36" /**< id-ce-inhibitAnyPolicy OBJECT IDENTIFIER ::=  { id-ce 54 } */
#define IOTEX_OID_FRESHEST_CRL                IOTEX_OID_ID_CE "\x2E" /**< id-ce-freshestCRL OBJECT IDENTIFIER ::=  { id-ce 46 } */

/*
 * Certificate policies
 */
#define IOTEX_OID_ANY_POLICY              IOTEX_OID_CERTIFICATE_POLICIES "\x00" /**< anyPolicy OBJECT IDENTIFIER ::= { id-ce-certificatePolicies 0 } */

/*
 * Netscape certificate extensions
 */
#define IOTEX_OID_NS_CERT                 IOTEX_OID_NETSCAPE "\x01"
#define IOTEX_OID_NS_CERT_TYPE            IOTEX_OID_NS_CERT  "\x01"
#define IOTEX_OID_NS_BASE_URL             IOTEX_OID_NS_CERT  "\x02"
#define IOTEX_OID_NS_REVOCATION_URL       IOTEX_OID_NS_CERT  "\x03"
#define IOTEX_OID_NS_CA_REVOCATION_URL    IOTEX_OID_NS_CERT  "\x04"
#define IOTEX_OID_NS_RENEWAL_URL          IOTEX_OID_NS_CERT  "\x07"
#define IOTEX_OID_NS_CA_POLICY_URL        IOTEX_OID_NS_CERT  "\x08"
#define IOTEX_OID_NS_SSL_SERVER_NAME      IOTEX_OID_NS_CERT  "\x0C"
#define IOTEX_OID_NS_COMMENT              IOTEX_OID_NS_CERT  "\x0D"
#define IOTEX_OID_NS_DATA_TYPE            IOTEX_OID_NETSCAPE "\x02"
#define IOTEX_OID_NS_CERT_SEQUENCE        IOTEX_OID_NS_DATA_TYPE "\x05"

/*
 * OIDs for CRL extensions
 */
#define IOTEX_OID_PRIVATE_KEY_USAGE_PERIOD    IOTEX_OID_ID_CE "\x10"
#define IOTEX_OID_CRL_NUMBER                  IOTEX_OID_ID_CE "\x14" /**< id-ce-cRLNumber OBJECT IDENTIFIER ::= { id-ce 20 } */

/*
 * X.509 v3 Extended key usage OIDs
 */
#define IOTEX_OID_ANY_EXTENDED_KEY_USAGE      IOTEX_OID_EXTENDED_KEY_USAGE "\x00" /**< anyExtendedKeyUsage OBJECT IDENTIFIER ::= { id-ce-extKeyUsage 0 } */

#define IOTEX_OID_KP                          IOTEX_OID_PKIX "\x03" /**< id-kp OBJECT IDENTIFIER ::= { id-pkix 3 } */
#define IOTEX_OID_SERVER_AUTH                 IOTEX_OID_KP "\x01" /**< id-kp-serverAuth OBJECT IDENTIFIER ::= { id-kp 1 } */
#define IOTEX_OID_CLIENT_AUTH                 IOTEX_OID_KP "\x02" /**< id-kp-clientAuth OBJECT IDENTIFIER ::= { id-kp 2 } */
#define IOTEX_OID_CODE_SIGNING                IOTEX_OID_KP "\x03" /**< id-kp-codeSigning OBJECT IDENTIFIER ::= { id-kp 3 } */
#define IOTEX_OID_EMAIL_PROTECTION            IOTEX_OID_KP "\x04" /**< id-kp-emailProtection OBJECT IDENTIFIER ::= { id-kp 4 } */
#define IOTEX_OID_TIME_STAMPING               IOTEX_OID_KP "\x08" /**< id-kp-timeStamping OBJECT IDENTIFIER ::= { id-kp 8 } */
#define IOTEX_OID_OCSP_SIGNING                IOTEX_OID_KP "\x09" /**< id-kp-OCSPSigning OBJECT IDENTIFIER ::= { id-kp 9 } */

/**
 * Wi-SUN Alliance Field Area Network
 * { iso(1) identified-organization(3) dod(6) internet(1)
 *                      private(4) enterprise(1) WiSUN(45605) FieldAreaNetwork(1) }
 */
#define IOTEX_OID_WISUN_FAN                   IOTEX_OID_INTERNET "\x04\x01\x82\xe4\x25\x01"

#define IOTEX_OID_ON                          IOTEX_OID_PKIX "\x08" /**< id-on OBJECT IDENTIFIER ::= { id-pkix 8 } */
#define IOTEX_OID_ON_HW_MODULE_NAME           IOTEX_OID_ON "\x04" /**< id-on-hardwareModuleName OBJECT IDENTIFIER ::= { id-on 4 } */

/*
 * PKCS definition OIDs
 */

#define IOTEX_OID_PKCS                IOTEX_OID_RSA_COMPANY "\x01" /**< pkcs OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) 1 } */
#define IOTEX_OID_PKCS1               IOTEX_OID_PKCS "\x01" /**< pkcs-1 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) 1 } */
#define IOTEX_OID_PKCS5               IOTEX_OID_PKCS "\x05" /**< pkcs-5 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) 5 } */
#define IOTEX_OID_PKCS9               IOTEX_OID_PKCS "\x09" /**< pkcs-9 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) 9 } */
#define IOTEX_OID_PKCS12              IOTEX_OID_PKCS "\x0c" /**< pkcs-12 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) 12 } */

/*
 * PKCS#1 OIDs
 */
#define IOTEX_OID_PKCS1_RSA           IOTEX_OID_PKCS1 "\x01" /**< rsaEncryption OBJECT IDENTIFIER ::= { pkcs-1 1 } */
#define IOTEX_OID_PKCS1_MD5           IOTEX_OID_PKCS1 "\x04" /**< md5WithRSAEncryption ::= { pkcs-1 4 } */
#define IOTEX_OID_PKCS1_SHA1          IOTEX_OID_PKCS1 "\x05" /**< sha1WithRSAEncryption ::= { pkcs-1 5 } */
#define IOTEX_OID_PKCS1_SHA224        IOTEX_OID_PKCS1 "\x0e" /**< sha224WithRSAEncryption ::= { pkcs-1 14 } */
#define IOTEX_OID_PKCS1_SHA256        IOTEX_OID_PKCS1 "\x0b" /**< sha256WithRSAEncryption ::= { pkcs-1 11 } */
#define IOTEX_OID_PKCS1_SHA384        IOTEX_OID_PKCS1 "\x0c" /**< sha384WithRSAEncryption ::= { pkcs-1 12 } */
#define IOTEX_OID_PKCS1_SHA512        IOTEX_OID_PKCS1 "\x0d" /**< sha512WithRSAEncryption ::= { pkcs-1 13 } */

#define IOTEX_OID_RSA_SHA_OBS         "\x2B\x0E\x03\x02\x1D"

#define IOTEX_OID_PKCS9_EMAIL         IOTEX_OID_PKCS9 "\x01" /**< emailAddress AttributeType ::= { pkcs-9 1 } */

/* RFC 4055 */
#define IOTEX_OID_RSASSA_PSS          IOTEX_OID_PKCS1 "\x0a" /**< id-RSASSA-PSS ::= { pkcs-1 10 } */
#define IOTEX_OID_MGF1                IOTEX_OID_PKCS1 "\x08" /**< id-mgf1 ::= { pkcs-1 8 } */

/*
 * Digest algorithms
 */
#define IOTEX_OID_DIGEST_ALG_MD5              IOTEX_OID_RSA_COMPANY "\x02\x05" /**< id-iotex_md5 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 5 } */
#define IOTEX_OID_DIGEST_ALG_SHA1             IOTEX_OID_ISO_IDENTIFIED_ORG IOTEX_OID_OIW_SECSIG_SHA1 /**< id-iotex_sha1 OBJECT IDENTIFIER ::= { iso(1) identified-organization(3) oiw(14) secsig(3) algorithms(2) 26 } */
#define IOTEX_OID_DIGEST_ALG_SHA224           IOTEX_OID_NIST_ALG "\x02\x04" /**< id-sha224 OBJECT IDENTIFIER ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2) 4 } */
#define IOTEX_OID_DIGEST_ALG_SHA256           IOTEX_OID_NIST_ALG "\x02\x01" /**< id-iotex_sha256 OBJECT IDENTIFIER ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2) 1 } */

#define IOTEX_OID_DIGEST_ALG_SHA384           IOTEX_OID_NIST_ALG "\x02\x02" /**< id-sha384 OBJECT IDENTIFIER ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2) 2 } */

#define IOTEX_OID_DIGEST_ALG_SHA512           IOTEX_OID_NIST_ALG "\x02\x03" /**< id-iotex_sha512 OBJECT IDENTIFIER ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2) 3 } */

#define IOTEX_OID_DIGEST_ALG_RIPEMD160        IOTEX_OID_TELETRUST "\x03\x02\x01" /**< id-ripemd160 OBJECT IDENTIFIER :: { iso(1) identified-organization(3) teletrust(36) algorithm(3) hashAlgorithm(2) ripemd160(1) } */

#define IOTEX_OID_HMAC_SHA1                   IOTEX_OID_RSA_COMPANY "\x02\x07" /**< id-hmacWithSHA1 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 7 } */

#define IOTEX_OID_HMAC_SHA224                 IOTEX_OID_RSA_COMPANY "\x02\x08" /**< id-hmacWithSHA224 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 8 } */

#define IOTEX_OID_HMAC_SHA256                 IOTEX_OID_RSA_COMPANY "\x02\x09" /**< id-hmacWithSHA256 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 9 } */

#define IOTEX_OID_HMAC_SHA384                 IOTEX_OID_RSA_COMPANY "\x02\x0A" /**< id-hmacWithSHA384 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 10 } */

#define IOTEX_OID_HMAC_SHA512                 IOTEX_OID_RSA_COMPANY "\x02\x0B" /**< id-hmacWithSHA512 OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) digestAlgorithm(2) 11 } */

/*
 * Encryption algorithms
 */
#define IOTEX_OID_DES_CBC                     IOTEX_OID_ISO_IDENTIFIED_ORG IOTEX_OID_OIW_SECSIG_ALG "\x07" /**< desCBC OBJECT IDENTIFIER ::= { iso(1) identified-organization(3) oiw(14) secsig(3) algorithms(2) 7 } */
#define IOTEX_OID_DES_EDE3_CBC                IOTEX_OID_RSA_COMPANY "\x03\x07" /**< des-ede3-cbc OBJECT IDENTIFIER ::= { iso(1) member-body(2) -- us(840) rsadsi(113549) encryptionAlgorithm(3) 7 } */
#define IOTEX_OID_AES                         IOTEX_OID_NIST_ALG "\x01" /** aes OBJECT IDENTIFIER ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistAlgorithm(4) 1 } */

/*
 * Key Wrapping algorithms
 */
/*
 * RFC 5649
 */
#define IOTEX_OID_AES128_KW                   IOTEX_OID_AES "\x05" /** id-aes128-wrap     OBJECT IDENTIFIER ::= { aes 5 } */
#define IOTEX_OID_AES128_KWP                  IOTEX_OID_AES "\x08" /** id-aes128-wrap-pad OBJECT IDENTIFIER ::= { aes 8 } */
#define IOTEX_OID_AES192_KW                   IOTEX_OID_AES "\x19" /** id-aes192-wrap     OBJECT IDENTIFIER ::= { aes 25 } */
#define IOTEX_OID_AES192_KWP                  IOTEX_OID_AES "\x1c" /** id-aes192-wrap-pad OBJECT IDENTIFIER ::= { aes 28 } */
#define IOTEX_OID_AES256_KW                   IOTEX_OID_AES "\x2d" /** id-aes256-wrap     OBJECT IDENTIFIER ::= { aes 45 } */
#define IOTEX_OID_AES256_KWP                  IOTEX_OID_AES "\x30" /** id-aes256-wrap-pad OBJECT IDENTIFIER ::= { aes 48 } */
/*
 * PKCS#5 OIDs
 */
#define IOTEX_OID_PKCS5_PBKDF2                IOTEX_OID_PKCS5 "\x0c" /**< id-PBKDF2 OBJECT IDENTIFIER ::= {pkcs-5 12} */
#define IOTEX_OID_PKCS5_PBES2                 IOTEX_OID_PKCS5 "\x0d" /**< id-PBES2 OBJECT IDENTIFIER ::= {pkcs-5 13} */
#define IOTEX_OID_PKCS5_PBMAC1                IOTEX_OID_PKCS5 "\x0e" /**< id-PBMAC1 OBJECT IDENTIFIER ::= {pkcs-5 14} */

/*
 * PKCS#5 PBES1 algorithms
 */
#define IOTEX_OID_PKCS5_PBE_MD5_DES_CBC       IOTEX_OID_PKCS5 "\x03" /**< pbeWithMD5AndDES-CBC OBJECT IDENTIFIER ::= {pkcs-5 3} */
#define IOTEX_OID_PKCS5_PBE_MD5_RC2_CBC       IOTEX_OID_PKCS5 "\x06" /**< pbeWithMD5AndRC2-CBC OBJECT IDENTIFIER ::= {pkcs-5 6} */
#define IOTEX_OID_PKCS5_PBE_SHA1_DES_CBC      IOTEX_OID_PKCS5 "\x0a" /**< pbeWithSHA1AndDES-CBC OBJECT IDENTIFIER ::= {pkcs-5 10} */
#define IOTEX_OID_PKCS5_PBE_SHA1_RC2_CBC      IOTEX_OID_PKCS5 "\x0b" /**< pbeWithSHA1AndRC2-CBC OBJECT IDENTIFIER ::= {pkcs-5 11} */

/*
 * PKCS#8 OIDs
 */
#define IOTEX_OID_PKCS9_CSR_EXT_REQ           IOTEX_OID_PKCS9 "\x0e" /**< extensionRequest OBJECT IDENTIFIER ::= {pkcs-9 14} */

/*
 * PKCS#12 PBE OIDs
 */
#define IOTEX_OID_PKCS12_PBE                      IOTEX_OID_PKCS12 "\x01" /**< pkcs-12PbeIds OBJECT IDENTIFIER ::= {pkcs-12 1} */

#define IOTEX_OID_PKCS12_PBE_SHA1_DES3_EDE_CBC    IOTEX_OID_PKCS12_PBE "\x03" /**< pbeWithSHAAnd3-KeyTripleDES-CBC OBJECT IDENTIFIER ::= {pkcs-12PbeIds 3} */
#define IOTEX_OID_PKCS12_PBE_SHA1_DES2_EDE_CBC    IOTEX_OID_PKCS12_PBE "\x04" /**< pbeWithSHAAnd2-KeyTripleDES-CBC OBJECT IDENTIFIER ::= {pkcs-12PbeIds 4} */
#define IOTEX_OID_PKCS12_PBE_SHA1_RC2_128_CBC     IOTEX_OID_PKCS12_PBE "\x05" /**< pbeWithSHAAnd128BitRC2-CBC OBJECT IDENTIFIER ::= {pkcs-12PbeIds 5} */
#define IOTEX_OID_PKCS12_PBE_SHA1_RC2_40_CBC      IOTEX_OID_PKCS12_PBE "\x06" /**< pbeWithSHAAnd40BitRC2-CBC OBJECT IDENTIFIER ::= {pkcs-12PbeIds 6} */

/*
 * EC key algorithms from RFC 5480
 */

/* id-ecPublicKey OBJECT IDENTIFIER ::= {
 *       iso(1) member-body(2) us(840) ansi-X9-62(10045) keyType(2) 1 } */
#define IOTEX_OID_EC_ALG_UNRESTRICTED         IOTEX_OID_ANSI_X9_62 "\x02\01"

/*   id-ecDH OBJECT IDENTIFIER ::= {
 *     iso(1) identified-organization(3) certicom(132)
 *     schemes(1) ecdh(12) } */
#define IOTEX_OID_EC_ALG_ECDH                 IOTEX_OID_CERTICOM "\x01\x0c"

/*
 * ECParameters namedCurve identifiers, from RFC 5480, RFC 5639, and SEC2
 */

/* secp192r1 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) curves(3) prime(1) 1 } */
#define IOTEX_OID_EC_GRP_SECP192R1        IOTEX_OID_ANSI_X9_62 "\x03\x01\x01"

/* secp224r1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 33 } */
#define IOTEX_OID_EC_GRP_SECP224R1        IOTEX_OID_CERTICOM "\x00\x21"

/* secp256r1 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) curves(3) prime(1) 7 } */
#define IOTEX_OID_EC_GRP_SECP256R1        IOTEX_OID_ANSI_X9_62 "\x03\x01\x07"

/* secp384r1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 34 } */
#define IOTEX_OID_EC_GRP_SECP384R1        IOTEX_OID_CERTICOM "\x00\x22"

/* secp521r1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 35 } */
#define IOTEX_OID_EC_GRP_SECP521R1        IOTEX_OID_CERTICOM "\x00\x23"

/* secp192k1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 31 } */
#define IOTEX_OID_EC_GRP_SECP192K1        IOTEX_OID_CERTICOM "\x00\x1f"

/* secp224k1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 32 } */
#define IOTEX_OID_EC_GRP_SECP224K1        IOTEX_OID_CERTICOM "\x00\x20"

/* secp256k1 OBJECT IDENTIFIER ::= {
 *   iso(1) identified-organization(3) certicom(132) curve(0) 10 } */
#define IOTEX_OID_EC_GRP_SECP256K1        IOTEX_OID_CERTICOM "\x00\x0a"

/* RFC 5639 4.1
 * ecStdCurvesAndGeneration OBJECT IDENTIFIER::= {iso(1)
 * identified-organization(3) teletrust(36) algorithm(3) signature-
 * algorithm(3) ecSign(2) 8}
 * ellipticCurve OBJECT IDENTIFIER ::= {ecStdCurvesAndGeneration 1}
 * versionOne OBJECT IDENTIFIER ::= {ellipticCurve 1} */
#define IOTEX_OID_EC_BRAINPOOL_V1         IOTEX_OID_TELETRUST "\x03\x03\x02\x08\x01\x01"

/* brainpoolP256r1 OBJECT IDENTIFIER ::= {versionOne 7} */
#define IOTEX_OID_EC_GRP_BP256R1          IOTEX_OID_EC_BRAINPOOL_V1 "\x07"

/* brainpoolP384r1 OBJECT IDENTIFIER ::= {versionOne 11} */
#define IOTEX_OID_EC_GRP_BP384R1          IOTEX_OID_EC_BRAINPOOL_V1 "\x0B"

/* brainpoolP512r1 OBJECT IDENTIFIER ::= {versionOne 13} */
#define IOTEX_OID_EC_GRP_BP512R1          IOTEX_OID_EC_BRAINPOOL_V1 "\x0D"

/*
 * SEC1 C.1
 *
 * prime-field OBJECT IDENTIFIER ::= { id-fieldType 1 }
 * id-fieldType OBJECT IDENTIFIER ::= { ansi-X9-62 fieldType(1)}
 */
#define IOTEX_OID_ANSI_X9_62_FIELD_TYPE   IOTEX_OID_ANSI_X9_62 "\x01"
#define IOTEX_OID_ANSI_X9_62_PRIME_FIELD  IOTEX_OID_ANSI_X9_62_FIELD_TYPE "\x01"

/*
 * ECDSA signature identifiers, from RFC 5480
 */
#define IOTEX_OID_ANSI_X9_62_SIG          IOTEX_OID_ANSI_X9_62 "\x04" /* signatures(4) */
#define IOTEX_OID_ANSI_X9_62_SIG_SHA2     IOTEX_OID_ANSI_X9_62_SIG "\x03" /* ecdsa-with-SHA2(3) */

/* ecdsa-with-SHA1 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4) 1 } */
#define IOTEX_OID_ECDSA_SHA1              IOTEX_OID_ANSI_X9_62_SIG "\x01"

/* ecdsa-with-SHA224 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
 *   ecdsa-with-SHA2(3) 1 } */
#define IOTEX_OID_ECDSA_SHA224            IOTEX_OID_ANSI_X9_62_SIG_SHA2 "\x01"

/* ecdsa-with-SHA256 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
 *   ecdsa-with-SHA2(3) 2 } */
#define IOTEX_OID_ECDSA_SHA256            IOTEX_OID_ANSI_X9_62_SIG_SHA2 "\x02"

/* ecdsa-with-SHA384 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
 *   ecdsa-with-SHA2(3) 3 } */
#define IOTEX_OID_ECDSA_SHA384            IOTEX_OID_ANSI_X9_62_SIG_SHA2 "\x03"

/* ecdsa-with-SHA512 OBJECT IDENTIFIER ::= {
 *   iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
 *   ecdsa-with-SHA2(3) 4 } */
#define IOTEX_OID_ECDSA_SHA512            IOTEX_OID_ANSI_X9_62_SIG_SHA2 "\x04"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Base OID descriptor structure
 */
typedef struct iotex_oid_descriptor_t
{
    const char *asn1;               /*!< OID ASN.1 representation       */
    size_t asn1_len;                /*!< length of asn1                 */
#if !defined(IOTEX_X509_REMOVE_INFO)
    const char *name;               /*!< official name (e.g. from RFC)  */
    const char *description;        /*!< human friendly description     */
#endif
} iotex_oid_descriptor_t;

/**
 * \brief           Translate an ASN.1 OID into its numeric representation
 *                  (e.g. "\x2A\x86\x48\x86\xF7\x0D" into "1.2.840.113549")
 *
 * \param buf       buffer to put representation in
 * \param size      size of the buffer
 * \param oid       OID to translate
 *
 * \return          Length of the string written (excluding final NULL) or
 *                  IOTEX_ERR_OID_BUF_TOO_SMALL in case of error
 */
int iotex_oid_get_numeric_string( char *buf, size_t size, const iotex_asn1_buf *oid );

/**
 * \brief          Translate an X.509 extension OID into local values
 *
 * \param oid      OID to use
 * \param ext_type place to store the extension type
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_x509_ext_type( const iotex_asn1_buf *oid, int *ext_type );

/**
 * \brief          Translate an X.509 attribute type OID into the short name
 *                 (e.g. the OID for an X520 Common Name into "CN")
 *
 * \param oid      OID to use
 * \param short_name    place to store the string pointer
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_attr_short_name( const iotex_asn1_buf *oid, const char **short_name );

/**
 * \brief          Translate PublicKeyAlgorithm OID into pk_type
 *
 * \param oid      OID to use
 * \param pk_alg   place to store public key algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_pk_alg( const iotex_asn1_buf *oid, iotex_pk_type_t *pk_alg );

/**
 * \brief          Translate pk_type into PublicKeyAlgorithm OID
 *
 * \param pk_alg   Public key type to look for
 * \param oid      place to store ASN.1 OID string pointer
 * \param olen     length of the OID
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_oid_by_pk_alg( iotex_pk_type_t pk_alg,
                           const char **oid, size_t *olen );

#if defined(IOTEX_ECP_C)
/**
 * \brief          Translate NamedCurve OID into an EC group identifier
 *
 * \param oid      OID to use
 * \param grp_id   place to store group id
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_ec_grp( const iotex_asn1_buf *oid, iotex_ecp_group_id *grp_id );

/**
 * \brief          Translate EC group identifier into NamedCurve OID
 *
 * \param grp_id   EC group identifier
 * \param oid      place to store ASN.1 OID string pointer
 * \param olen     length of the OID
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_oid_by_ec_grp( iotex_ecp_group_id grp_id,
                           const char **oid, size_t *olen );
#endif /* IOTEX_ECP_C */

#if defined(IOTEX_MD_C)
/**
 * \brief          Translate SignatureAlgorithm OID into md_type and pk_type
 *
 * \param oid      OID to use
 * \param md_alg   place to store message digest algorithm
 * \param pk_alg   place to store public key algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_sig_alg( const iotex_asn1_buf *oid,
                     iotex_md_type_t *md_alg, iotex_pk_type_t *pk_alg );

/**
 * \brief          Translate SignatureAlgorithm OID into description
 *
 * \param oid      OID to use
 * \param desc     place to store string pointer
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_sig_alg_desc( const iotex_asn1_buf *oid, const char **desc );

/**
 * \brief          Translate md_type and pk_type into SignatureAlgorithm OID
 *
 * \param md_alg   message digest algorithm
 * \param pk_alg   public key algorithm
 * \param oid      place to store ASN.1 OID string pointer
 * \param olen     length of the OID
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_oid_by_sig_alg( iotex_pk_type_t pk_alg, iotex_md_type_t md_alg,
                            const char **oid, size_t *olen );

/**
 * \brief          Translate hash algorithm OID into md_type
 *
 * \param oid      OID to use
 * \param md_alg   place to store message digest algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_md_alg( const iotex_asn1_buf *oid, iotex_md_type_t *md_alg );

/**
 * \brief          Translate hmac algorithm OID into md_type
 *
 * \param oid      OID to use
 * \param md_hmac  place to store message hmac algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_md_hmac( const iotex_asn1_buf *oid, iotex_md_type_t *md_hmac );
#endif /* IOTEX_MD_C */

#if !defined(IOTEX_X509_REMOVE_INFO)
/**
 * \brief          Translate Extended Key Usage OID into description
 *
 * \param oid      OID to use
 * \param desc     place to store string pointer
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_extended_key_usage( const iotex_asn1_buf *oid, const char **desc );
#endif

/**
 * \brief          Translate certificate policies OID into description
 *
 * \param oid      OID to use
 * \param desc     place to store string pointer
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_certificate_policies( const iotex_asn1_buf *oid, const char **desc );

/**
 * \brief          Translate md_type into hash algorithm OID
 *
 * \param md_alg   message digest algorithm
 * \param oid      place to store ASN.1 OID string pointer
 * \param olen     length of the OID
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_oid_by_md( iotex_md_type_t md_alg, const char **oid, size_t *olen );

#if defined(IOTEX_CIPHER_C)
/**
 * \brief          Translate encryption algorithm OID into cipher_type
 *
 * \param oid           OID to use
 * \param cipher_alg    place to store cipher algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_cipher_alg( const iotex_asn1_buf *oid, iotex_cipher_type_t *cipher_alg );
#endif /* IOTEX_CIPHER_C */

#if defined(IOTEX_PKCS12_C)
/**
 * \brief          Translate PKCS#12 PBE algorithm OID into md_type and
 *                 cipher_type
 *
 * \param oid           OID to use
 * \param md_alg        place to store message digest algorithm
 * \param cipher_alg    place to store cipher algorithm
 *
 * \return         0 if successful, or IOTEX_ERR_OID_NOT_FOUND
 */
int iotex_oid_get_pkcs12_pbe_alg( const iotex_asn1_buf *oid, iotex_md_type_t *md_alg,
                            iotex_cipher_type_t *cipher_alg );
#endif /* IOTEX_PKCS12_C */

#ifdef __cplusplus
}
#endif

#endif /* oid.h */
