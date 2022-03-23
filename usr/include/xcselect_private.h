#ifndef __XCSELECT_PRIVATE_H__
#define __XCSELECT_PRIVATE_H__

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/errno.h>
#include <sys/sysctl.h>
#include <TargetConditionals.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

#define XCSELECT_VER "2384"

typedef struct _xcselect_manpaths {
	char **paths;
	uint32_t count;
} xcselect_manpaths;

__BEGIN_DECLS
/**
 * \brief Check if the given bundle ID is in developer tool list.
 *
 * \param bundle_id The bundle identifier of developer tool.
 *
 * \returns 1 on success, 0 on fail.
 */
OS_EXPORT
bool xcselect_bundle_is_developer_tool(char *bundle_id);

/**
 * \brief Check given path contained by or maches developer directory.
 *
 * \param developer_dir The path of developer directory, if no value was
 *                      given, current active developer directory path
 *                      will be used to compare.
 *
 * \param path The destinaton path for comparing with developer_dir.
 *
 * \returns 1 on success, 0 on fail.
 */
OS_EXPORT
bool xcselect_developer_dir_matches_path(const char * __nullable developer_dir,
				const char *path);

/**
 * \brief Get the path of current active developer directory.
 *
 * \param buffer The buffer stores the result developer directory path.
 *
 * \param buffer_size The buffer stores the size of resulting string.
 *
 * \param was_environment The buffer indicates that resulting path was
 *                        defined by environment variable (DEVELOPER_DIR).
 *
 * \param was_cltools The buffer indicates that resulting path was
 *                    CommandlineTools instance.
 *
 * \param was_default The buffer indicates that resulting path was
 *                    current active developer directory.
 *
 * \returns 1 on success, 0 on fail.
 */
OS_EXPORT
bool xcselect_get_developer_dir_path(char *buffer, int buffer_size,
				bool *was_environment, bool *was_cltools,
				bool *was_default);

/**
 * \brief Find developer contents from given path.
 *
 * \param path The path for searching developer contents.
 *
 * \param buffer The buffer stores the developer contents path.
 *
 * \param buffer_size The buffer stores the size of resulting string.
 *
 * \param was_cltools The buffer indicates that resulting path was
 *                    under CommandlineTools instance.
 *
 * \returns 1 on success, 0 on fail.
 */
OS_EXPORT
bool xcselect_find_developer_contents_from_path(char * __nonnull path, char *buffer,
				size_t buffer_size, bool *was_cltools);

/**
 * \brief Get the manpath to an SDK.
 *
 * \param sysroot The path for target SDK.
 *
 * \returns a xcselect_manpaths structure on success, otherwise
 *          returns nil.
 */
OS_EXPORT
xcselect_manpaths *xcselect_get_manpaths(char *sysroot);

/**
 * \brief Get current version of libxcselect.
 *
 * \returns a version string.
 */
OS_EXPORT
char *xcselect_get_version(void);

/**
 * \brief Deallocates the memory of given xcselect_manpaths
 *
 * \param xcp The target xcselect_manpaths.
 */
OS_EXPORT
void xcselect_manpaths_free(xcselect_manpaths *xcp);

/**
 * \brief Get the count of paths in given xcselect_manpaths.
 *
 * \param xcp The target xcselect_manpaths.
 *
 * \returns the count of paths in given xcselect_manpaths.
 */
OS_EXPORT
uint32_t xcselect_manpaths_get_num_paths(xcselect_manpaths *xcp);

/**
 * \brief Get the path of manpath with specific id in given xcselect_manpaths.
 *
 * \param xcp The target xcselect_manpaths.
 *
 * \param id The ID for specific manpath.
 *
 * \returns a string on found, otherwise returns nil.
 */
OS_EXPORT
const char *xcselect_manpaths_get_path(xcselect_manpaths *xcp, uint32_t id);

/**
 * \brief Trigger CommandlineTools install request.
 *
 * \param name The name of a command.
 *
 * \returns 1 when successfully triggered, otherwise returns 0.
 */
OS_EXPORT
bool xcselect_trigger_install_request(const char *tool_name);

/**
 * \brief Invoke xcrun to execute a command.
 *
 * \param tool_name The name of a command.
 *
 * \param argc Total count of arguments that being passed to.
 *
 * \param argv Arguments for tool_name.
 *
 * \param require_xcode Set to 0 to proceed. Set to 1 to trigger an error that
 *                      requires Xcode installation.
 */
OS_EXPORT
void xcselect_invoke_xcrun(char *tool_name, int argc, char * __nullable argv[], bool require_xcode);

__END_DECLS

#pragma clang diagnostic pop

#endif
