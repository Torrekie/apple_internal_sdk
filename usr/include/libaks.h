#ifndef __LIBAKS_H__
#define __LIBAKS_H__

#include <sys/types.h>
#include <os/base.h>

typedef enum _aks_keyclass_enum {
/*
    key_class_none,
    key_class_ak,
    key_class_ck,
    key_class_dk,
    key_class_aku,
    key_class_cku,
    key_class_dku,
    key_class_akpu, // implied to exist by some Security code (`SecDbBackupmanager.m`)
*/
    key_class_f = 13,
/*    key_class_last, */
} keyclass_t;


typedef uint32_t keybag_handle_t;

__BEGIN_DECLS

// The whole aks functions are implemented inside libaks.h as static functions, thats frustrating */
static inline io_connect_t _copy_aks_client_connection(const char *path, const char *name) {
	io_connect_t connection = MACH_PORT_NULL;

	io_service_t service = IORegistryEntryFromPath(kIOMasterPortDefault, path);
	if (service != IO_OBJECT_NULL) {
		kern_return_t kr = IOServiceOpen(service, mach_task_self(), 0, &connection);
		IOObjectRelease(service);
		if (kr == KERN_SUCCESS && connection != MACH_PORT_NULL) {
			// validate below
		} else {
			connection = MACH_PORT_NULL;
		}
	}

	if (connection == MACH_PORT_NULL) {
		CFMutableDictionaryRef match = IOServiceMatching(name);
		io_service_t matching = IOServiceGetMatchingService(kIOMasterPortDefault, match);
		if (matching != IO_OBJECT_NULL) {
			(void)IOServiceOpen(matching, mach_task_self(), 0, &connection);
			IOObjectRelease(matching);
		}
	}

	if (connection != MACH_PORT_NULL) {
		kern_return_t kr = IOConnectCallMethod(conn, 0, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

		if (kr != KERN_SUCCESS) {
			IOServiceClose(connection);
			return MACH_PORT_NULL;
		}
	}

	return connection;
}

static inline io_connect_t get_aks_client_connection(void) {
	static dispatch_once_t onceToken = 0;
	static dispatch_queue_t connection_queue;
	static io_connect_t connection;

	dispatch_once(&onceToken, ^{
		connection_queue = dispatch_queue_create("aks-client-queue", NULL);
	});
	dispatch_sync(connection_queue, ^{
		connection = _copy_aks_client_connection("IOService:/IOResources/AppleKeyStore", "AppleKeyStore");
	});
	if (!connection) {
		syslog(LOG_ERR, "failed to open connection to %s\n", "AppleKeyStore");
		return NULL;
	}
	return connection;
}

static inline IOReturn aks_wrap_key(const uint8_t *key, uint32_t key_len, keyclass_t key_class, keybag_handle_t keybag_handle, uint8_t *wrapped, int *wrapped_len, keyclass_t *wrapped_class) {
	IOReturn ret = kIOReturnError;
	io_connect_t connection = get_aks_client_connection();
	if (connection) {
		ret = kIOReturnBadArgument;
		if (!key || !wrapped || !wrapped_len) return ret;

		uint64_t inputScalar[2]; // ghidra told me
		uint64_t output;
		size_t outputCount;
		size_t outputStructCnt = *wrapped_len;

		inputScalar[0] = keybag_handle;
		inputScalar[1] = key_class;

		ret = IOConnectCallMethod(connection, 10, inputScalar, 2, key, key_len, &output, &outputCount, wrapped, &outputStructCnt);
		if (ret != kIOReturnSuccess)
			return ret;

		*wrapped_len = outputStructCnt;
		if (wrapped_class)
			*wrapped_class = output;
	}
	return ret;
}

static inline IOReturn aks_unwrap_key(const uint8_t *key, uint32_t key_len, keyclass_t key_class, keybag_handle_t keybag_handle, uint8_t *wrapped, int *wrapped_len) {
	IOReturn ret = kIOReturnError;
	io_connect_t connection = get_aks_client_connection();
	if (connection) {
		ret = kIOReturnBadArgument;
		if (!key || !wrapped || !wrapped_len) return ret;

		uint64_t inputScalar[2]; // ghidra told me
		uint64_t output;
		size_t outputCount;
		size_t outputStructCnt = *wrapped_len;

		inputScalar[0] = keybag_handle;
		inputScalar[1] = key_class;

		ret = IOConnectCallMethod(connection, 11, inputScalar, 2, key, key_len, NULL, 0, wrapped, &outputStructCnt);
		if (ret != kIOReturnSuccess)
			return ret;

		*wrapped_len = outputStructCnt;
	}
	return ret;
}

__END_DECLS

#endif
