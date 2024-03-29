# apple_internal_sdk
Guessed headers of non-public Apple SDK

## Current Status

### PrivateFrameworks

 - APFS.framework
    - APFS.h & APFSConstants.h
       - Now able to compile `mount` and `fsck` (Targeting iOS) in diskdev_cmds-667.100.2

 - AssertionServices.framework
    - BackBoardServices headers

 - BackBoardServices.framework
    - LLDB debugserver compiles

 - CoreSymbolication.framework
    - CoreSymbolication.h
       - dtrace-370.40.1 compile pass

 - FrontBoardServices.framework
    - LLDB debugserver compiles

 - MediaKit.framework
    - Now able to compile `mount` (Targeting iOS) in diskdev_cmds-667.100.2

 - MobileCoreServices.framework
    - LS*.h

 - SpringBoardServices.framework
    - SpringBoardServices.h
       - `debugserver` now can use with SpringBoard applications

### Headers

 - Cambria.framework (liboah & libRosetta)
    - Cambria/Cambria.h & Cambria/Traps.h
       - Most functions are now having prototypes

 - CrashReporterClient.h
    - Fully functional

 - apfs
    - apfs/apfs_fsctl.h
       - Now compiles `mtree` in file_cmds-321.100.11
       - Only few defines and prototypes
    - Other headers not implemented yet

 - corecrypto
    - Most headers are from previous XNU versions which was not shown in latest

 - ktrace.framework
    - ktrace/session.h & ktrace/private.h
       - `fs_usage` and `dyld_usage` now works
       - Only few defines and prototypes

 - perfdata.framework
    - perfdata/perfdata.h & perfdata/perfcheck_keys.h
    - `ioclasscount` in IOKitTools-122 compiles and works
    - XNU tests does not compile yet
    - All `pdunit_*` constants declared
    - `pdwriter_*` functions partially declared
    - `json_*` functions not declared at all

 - liblockdown
    - lockdown.h
       - LLDB debugserver compiles

 - mach-o
    - mach-o/dyld_priv.h
       - From dyld-852.2
       - Apple stripped few constants which related with version control
          - `dyld_fall_20*_os_versions` and `dyld_platform_version_*` defines

 - os
    - os/feature_private.h
       - Implemented APIs in `/usr/lib/system/libsystem_featureflags.dylib` which used in other Apple OSSes

 - sandbox
    - sandbox/private.h
       - Only few defines and prototypes
    - sandbox/rootless.h
       - Most `rootless_*` functions implemented

 - sysmon
    - sysmon.h
       - `pkill`/`pgrep` now works

 - xcselect_private.h
    - Implemented APIs in `/usr/lib/libxcselect.dylib`

 - xpc
    - xpc/private.h
       - As many prototypes as I could figure out

### Libraries

 - libCrashReporterClient
    - An implementation of it under `misc/CrashReporterClient`

 - liboah
    - A text based stub file which was not included within MacOSX.framework

## TODO

- [x] Fix `ktrace_event_t` in <ktrace/session.h>
- [ ] Other headers in /usr/include/apfs
- [ ] Installer for this project
- [ ] Text-Based stubs for libraries not presenting in SDKs
- [ ] corecrypto
- [ ] liblockdown
- [ ] libsystemstats
- [ ] CoreRoutine
- [ ] libspindump_priv.h
- [ ] SoftLinking headers
