#ifndef _NW_PRIVATE_H_
#define _NW_PRIVATE_H_

#include <Network/Network.h>
#include <sys/socket.h>
#include <os/base.h>

// network_cmds/mptcp_client/conn_lib.h
typedef struct conninfo {
	__uint32_t			ci_flags;			/* see flags in sys/socket.h (CIF_CONNECTING, etc...) */
	__uint32_t			ci_ifindex;			/* outbound interface */
	struct sockaddr		*ci_src;			/* source address */
	struct sockaddr		*ci_dst;			/* destination address */
	int					ci_error;			/* saved error */
	__uint32_t			ci_aux_type;		/* auxiliary data type */
	void				*ci_aux_data;		/* auxiliary data */
} conninfo_t;

__BEGIN_DECLS

extern int copyassocids(int, sae_associd_t **, uint32_t *);
extern void freeassocids(sae_associd_t *);
extern int copyconnids(int, sae_associd_t, sae_connid_t **, uint32_t *);
extern void freeconnids(sae_connid_t *);
extern int copyconninfo(int, sae_connid_t, conninfo_t **);
extern void freeconninfo(conninfo_t *);

// WebKit/Source/WebKit/Platform/spi/Cocoa/NWSPI.h
void nw_parameters_set_account_id(nw_parameters_t, const char * account_id);
void nw_parameters_set_source_application(nw_parameters_t, audit_token_t);
void nw_parameters_set_source_application_by_bundle_id(nw_parameters_t, const char*);
void nw_parameters_set_attributed_bundle_identifier(nw_parameters_t, const char*);
nw_endpoint_t nw_endpoint_create_host_with_numeric_port(const char* hostname, uint16_t port_host_order);
bool nw_nat64_does_interface_index_support_nat64(uint32_t ifindex);
void nw_parameters_set_is_third_party_web_content(nw_parameters_t, bool is_third_party_web_content);
void nw_parameters_set_is_known_tracker(nw_parameters_t, bool is_known_tracker);
void nw_parameters_allow_sharing_port_with_listener(nw_parameters_t, nw_listener_t);

// OpenSSH-319
nw_parameters_t nw_parameters_create_legacy_tcp_socket(nw_parameters_configure_protocol_block_t);
void nw_parameters_set_keepalive_enabled(nw_parameters_t, bool);
void nw_parameters_set_required_address_family(nw_parameters_t, int);
int nw_connection_get_connected_socket(nw_connection_t);
nw_endpoint_t nw_connection_copy_connected_remote_endpoint(nw_connection_t);
__END_DECLS

#endif // _NW_PRIVATE_H_
