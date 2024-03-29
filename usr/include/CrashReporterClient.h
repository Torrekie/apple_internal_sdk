// From WTF/wtf/spi/cocoa/CrashReporterClientSPI.h
#ifndef _CRASHREPORTERCLIENT_H_
#define _CRASHREPORTERCLIENT_H_

#include <os/base.h>
#include <sys/types.h>

#define CRASHREPORTER_ANNOTATIONS_SECTION "__crash_info"
#define CRASHREPORTER_ANNOTATIONS_VERSION 5
#define CRASH_REPORTER_CLIENT_HIDDEN __attribute__((visibility("hidden")))

#define _crc_make_getter(attr) ((const char *)(unsigned long)gCRAnnotations.attr)
#define _crc_make_setter(attr, arg) (gCRAnnotations.attr = (uint64_t)(unsigned long)(arg))
#define CRGetCrashLogMessage() _crc_make_getter(message)
#define CRSetCrashLogMessage(m) _crc_make_setter(message, m)
#define CRSetCrashLogMessage2(m) _crc_make_setter(message2, m)

struct crashreporter_annotations_t {
    uint64_t version;
    uint64_t message;
    uint64_t signature_string;
    uint64_t backtrace;
    uint64_t message2;
    uint64_t thread;
    uint64_t dialog_mode;
    uint64_t abort_cause;
};

__BEGIN_DECLS

CRASH_REPORTER_CLIENT_HIDDEN
extern struct crashreporter_annotations_t gCRAnnotations;

// On MacOSX CrashReporter will display a string for each shared library if
// the shared library has an exported symbol named "__crashreporter_info__".
__attribute__((__used__))
extern const char *__crashreporter_info__;
//asm(".desc ___crashreporter_info__, 0x10");

__END_DECLS

#endif // _CRASHREPORTERCLIENT_H_
