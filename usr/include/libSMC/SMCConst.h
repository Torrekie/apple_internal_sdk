#ifndef _LIBSMC_SMCCONST_H_
#define _LIBSMC_SMCCONST_H_

#include <CoreFoundation/CFBase.h>

/* SMC operations */
typedef CF_ENUM(UInt8, SMCIndex)
{
    /* the user client method name constants */
    kSMCUserClientOpen,
    kSMCUserClientClose,
    kSMCHandleYPCEvent,

    kSMCPlaceholder1,        /* *** LEGACY SUPPORT placeholder */
    kSMCNumberOfMethods,

    /* other constants not mapped to individual methods */
    kSMCReadKey,
    kSMCWriteKey,
    kSMCGetKeyCount,
    kSMCGetKeyFromIndex,
    kSMCGetKeyInfo,

    kSMCFireInterrupt,
    kSMCGetPLimits,
    kSMCGetVers,
    kSMCPlaceholder2,        /* *** LEGACY SUPPORT placeholder */

    kSMCReadStatus,
    kSMCReadResult,

    kSMCVariableCommand
};

#if 0
/* Known Apple arm64 data types */
typedef CF_ENUM(UInt32, SMCDataType) {
    kSMCDataTypeUInt8   = 'ui8 ',
    kSMCDataTypeUInt16  = 'ui16',
    kSMCDataTypeUInt32  = 'ui32',
    kSMCDataTypeUInt64  = 'ui64',
    kSMCDataTypeInt8    = 'si8 ',
    kSMCDataTypeInt16   = 'si16',
    kSMCDataTypeInt32   = 'si32',
    kSMCDataTypeInt64   = 'si64',
    kSMCDataTypeChar    = 'char',
    kSMCDataTypeFloat   = 'flt ', /* 32-bit single-precision IEEE float */
    kSMCDataTypeString  = 'ch8*', /* ASCII string */
    kSMCDataTypeBoolean = 'flag', /* 1 byte, 1 or 0 */
    kSMCDataTypeHex     = 'hex_', /* binary data */
    kSMCDataTypeIOFT    = 'ioft', /* 64-bit unsigned fixed-point value? */
    kSMCDataTypeJST     = '{jst', /* Seems a struct containing si32 and ui32 */
};

typedef CF_ENUM(UInt8, SMCDataAttributes) {
    0x2, /* Variable Read Privilege */
    0x3, /* Variable Read/Write Priv */
    0x6, /* Variable Array Read Privilege */
    0x7, /* Variable Array Read/Write Priv */
    0x11, /* Function Write Privilege */
    0x13, /* Function Read/Write Priv */
    0x15, /* Function Array Write Privilege */
    0x16, /* Function Array Read Privilege */
    0x17, /* Function Array Read/Write Priv */
    0x50, /* Write Function */
    0x54, /* Write Function Array */
    K_CONST = 0x80, /* Read Variable */
    KWPRIV_VAR_RW = 0x81, /* Read Variable Write Privilege */
    0x84, /* Read Variable Array */
    KWPRIV_VAR_FLOAT_RW = 0x85, /* Read Variable Array Write Privilege */
    0x90, /* Read/Write Function */
    0x91, /* Read Function Write Privilege */
    0x95, /* Read Function Array Write Privilege */
    0xC0, /* Read/Write Variable */
    0xC4, /* Read/Write Variable Array */
    0xD0, /* Read/Write Function */
    0xD4, /* Read/Write Function Array */
    0xF0, /* Read/Write Function Paramater */
    0xF4, /* Read/Write Function Array Paramater */
}
#endif

/* general success / error codes */
typedef CF_ENUM(UInt8, SMCReturn) {
    kSMCSuccess = 0,
    // > 0xF0
    kSMCKeySizeExceeded = 0xfb,
    kSMCUnexpectedResult = 0xfd,
    kSMCKextCallError = 0xfe,
    kSMCNotPrevileged = 0xf9,
    kSMCUnknownError = 0xff,
}

/* SMCParamStruct result */
typedef CF_ENUM(UInt8, SMCResult) {
    kSMCSuccess = 0,
    kSMCError   = 1,

    kSMCCommCollision = 0x80,
    kSMCSpuriousData = 0x81,
    kSMCBadCommand = 0x82,
    kSMCBadParameter = 0x83,
    kSMCKeyNotFound = 0x84,
    kSMCKeyNotReadable = 0x85,
    kSMCKeyNotWritable = 0x86,
    kSMCKeySizeMismatch = 0x87,
    kSMCFramingError = 0x88,
    kSMCBadArgumentError = 0x89,
    
    // > 0xB6
    kSMCTimeoutError = 0xb7,
    kSMCKeyIndexRangeError = 0xb8,
    
    kSMCBadFuncParameter = 0xc0,
    kSMCEventBuffWrongOrder = 0xc4,
    kSMCEventBuffReadError = 0xc5,
    kSMCDeviceAccessError = 0xc7,
    kSMCUnsupportedFeature = 0xcb,
    kSMCSMBAccessError = 0xcc,
};

#endif /* _LIBSMC_SMCCONST_H_ */
