#ifndef _LIBSMC_H_
#define _LIBSMC_H_

#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CFBase.h>

#include <libSMC/SMCConst.h>
#include <libSMC/SMCTypes.h>

__BEGIN_DECLS

#pragma IOKit SMC Functions
/* SMCOpenAppleSMC() opens passed service and return a connection port,
 * IOServiceOpen(service, mach_task_self(), 0, &return) && IOConnectCallScalarMethod(return, kSMCUserClientOpen) */
mach_port_t SMCOpenAppleSMC(io_service_t service);

/* IOConnectCallStructMethod(masterPort, kSMCUserClientClose) && IOServiceClose(masterPort) */
kern_return_t SMCCloseAppleSMC(mach_port_t masterPort);

/* Typically returns IOConnectCallStructMethod(masterPort, kSMCHandleYPCEvent, inputStruct, 168, outputStruct, &outputStructCnt = 168);
 * but return kIOReturnBadArgument when inputStruct->keyInfo.dataSize <= 120 */
kern_return_t SMCKextCall(mach_port_t masterPort, SMCParamStruct *inputStruct, SMCParamStruct *outputStruct);


#pragma SMC Connection
/* SMCOpenConnection() allocates a sufficient x19 size (512), then call SMCOpenAppleSMC() */
mach_port_t *SMCOpenConnection(io_service_t service);

/* SMCOpenConnectionWithDefaultService() calls on top of SMCOpenConnection
 * creating masterPort and acquiring AppleSMC service */
mach_port_t *SMCOpenConnectionWithDefaultService(void);

/* Free the previous allocated x19, call SMCCloseAppleSMC(). Success:0, Error:-1 */
kern_return_t SMCCloseConnection(mach_port_t *masterPort);


#pragma Key Conversions
/*
 _SMCConvertNumericToBytes
 _SMCParseBytesForNumeric
 _SMCReadBigEndianArrayToUIntMax
 _SMCReadLittleEndianArrayToUIntMax
 _SMCSignExtendToIntMax
 */
/* Returns SMCKey in UInt32, put keyString with string */
UInt32 SMCUInt32ToString(SMCKey key, char *keyString);
/* Returns converted SMCKey */
SMCKey SMCMakeUInt32Key(const char *keyString);


#pragma SMC Key Informations & Types
/* Retrieve keyInfo of specified key */
SMCReturn SMCGetKeyInfo(mach_port_t *masterPort, SMCKey key, SMCKeyInfo *keyInfo);

/* Write typeDesc of specified numeric dataType */
SMCReturn SMCGetTypeDescriptionForNumericType(SMCDataType dataType, SMCTypeDescription *typeDesc);

/* Get key of specified number index (#KEY) */
SMCReturn SMCGetKeyFromIndex(mach_port_t *masterPort, UInt32 index, SMCKey *key);


#pragma Read SMC Keys
/* Combination of SMCGetKeyInfo() and SMCReadKeyWithKnownSize(), maxlen must be equal or bigger than size returned by SMCGetKeyInfo() */
SMCReturn SMCReadKey(mach_port_t *masterPort, SMCKey key, UInt8 *bytes, UInt16 maxlen);

/* Combination of SMCGetKeyInfo() and SMCReadKeyAsNumericWithKnownKeyInfo(), also set keyInfo if needed */
SMCReturn SMCReadKeyAsNumeric(mach_port_t *masterPort, SMCKey key, SMCKeyInfo *__nullable keyInfo, double *buffer)

/* No matter how actual type is, read with specified keyInfo and write 8-bit value to buffer */
SMCReturn SMCReadKeyAsNumericWithKnownKeyInfo(mach_port_t *masterPort, SMCKey key, SMCKeyInfo *keyInfo, double *buffer);

/* Wrapper of SMCKextCall(kSMCReadKey), result copied to bytes with length of dataSize */
SMCReturn SMCReadKeyWithKnownSize(mach_port_t *masterPort, SMCKey key, UInt32 dataSize, UInt8 *bytes);

#pragma Write SMC Keys
/* Combination of SMCGetKeyInfo() and SMCWriteKeyWithKnownSize() */
SMCReturn SMCWriteKey(mach_port_t *masterPort, SMCKey key, UInt8 *bytes);

/* Combination of SMCGetKeyInfo(), SMCConvertNumericToBytes() and SMCWriteKeyWithKnownSize() */
SMCReturn SMCWriteKeyAsNumeric(mach_port_t *masterPort, SMCKey key, double value);

/* Wrapper of SMCKextCall(kSMCWriteKey), dataSize should less than 120 */
SMCReturn SMCWriteKeyWithKnownSize(mach_port_t *masterPort, SMCKey key, UInt32 dataSize, UInt8 *bytes);

#pragma SMC Conversions
/* Rewrite bytes to buffer as numeric, with specified SMCTypeDescription */
UInt32 SMCParseBytesForNumeric(UInt8 *bytes, UInt32 size, double *buffer, SMCTypeDescription *typeDesc);

#pragma SMC Accum
/*
 _AccumSetupSettingsCPU
 _AccumSetupSettingsGPU
 _AccumSetupSettingsHP
 _AccumulatorPlatformStructLookupArray
 _SMCAEPopulatePlatform
 _SMCAccumCheckMinMaxSupport
 _SMCAccumGetChannelInfoForKey
 _SMCAccumIsSupported
 _SMCCreateAccumProgrammableChannelsDict1ms
 _SMCCreateAccumProgrammableChannelsDict1sec
 _SMCGetAccumStatus
 _SMCGetAccumStatusFor
 _SMCOSAccumIsSupported
 _SMCOSAccumSampleChannel
 _SMCProgramAccum
 _SMCProgramAccum1Channel
 _SMCProgramAccumDefaults
 _SMCProgramAccumWithoutReset
 _SMCSetAccum1msChannels
 _SMCSetAccum1secChannels
 _SMCSetAccumBitShift
 _SMCSetAccumMode
 _SMCStartAccum
 _SMCStopAccum
 */

/* Either check SMCAEPopulatePlatform() or x19[508] */
bool SMCOSAccumIsSupported(mach_port_t *masterPort);

#pragma SMC Misc

//_SMCRequestMacOSWakeFromAP

__END_DECLS

#endif /* _LIBSMC_H_ */
