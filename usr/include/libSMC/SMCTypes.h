#ifndef _LIBSMC_SMCTYPES_H_
#define _LIBSMC_SMCTYPES_H_

#include <CoreFoundation/CFBase.h>

typedef     UInt32  SMCKey;
typedef     UInt32  SMCDataType;
typedef     UInt8   SMCDataAttributes;

/* they use much calling convention, consider use this typedef */
/* typedef mach_port_t *SMCConnection; */

/* a struct to hold the SMC version */
typedef struct SMCVersion {
    unsigned char    major;
    unsigned char    minor;
    unsigned char    build;
    unsigned char    reserved;    // padding for alignment
    unsigned short   release;
} SMCVersion;

typedef struct SMCPLimitData {
    UInt16    version;
    UInt16    length;
    UInt32    cpuPLimit;
    UInt32    gpuPLimit;
    UInt32    memPLimit;
} SMCPLimitData;

/* a struct to hold the key info data */
typedef struct SMCKeyInfoData {
    UInt32               dataSize; // This should be UInt32, not IOByteCount
    SMCDataType          dataType;
    SMCDataAttributes    dataAttributes;
} SMCKeyInfoData;

/* the struct passed back and forth between the kext and UC */
/* sizeof(SMCParamStruct) should be 168 or 80, depending on whether uses bytes[32] or bytes[120] */
typedef struct SMCParamStruct {
    SMCKey               key;
    struct SMCParam {
        SMCVersion          vers;
        SMCPLimitData       pLimitData;
        SMCKeyInfoData      keyInfo;

        SMCResult           result;
        UInt8               status;

        UInt8               data8;
        UInt32              data32;
        UInt8               bytes[120];
    } param;
} SMCParamStruct;

typedef struct SMCKeyInfo {
    CF_ENUM(UInt32, keyType) {
        Numeric,
        Bytes,
        FixedPoint,
    };
    UInt32 keyAttributes; /* A copy of dataAttributes */
    struct SMCTypeDescription {
        UInt32 format;
        UInt16 sign;
        UInt16 bit;
        UInt32 offset; /* the address of current SMCKeyInfo */
        UInt16 size;
    } desc;
} SMCKeyInfo;

#endif /* _LIBSMC_SMCTYPES_H_ */
