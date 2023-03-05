#include <CrashReporterClient.h>

CRASH_REPORTER_CLIENT_HIDDEN
struct crashreporter_annotations_t gCRAnnotations
    __attribute__((used, section("__DATA," CRASHREPORTER_ANNOTATIONS_SECTION)))
    = { CRASHREPORTER_ANNOTATIONS_VERSION, 0, 0, 0, 0, 0, 0, 0 };
