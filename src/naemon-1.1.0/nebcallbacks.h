#ifndef _NEBCALLBACKS_H
#define _NEBCALLBACKS_H

#if !defined (_NAEMON_H_INSIDE) && !defined (NAEMON_COMPILATION)
#error "Only <naemon/naemon.h> can be included directly."
#endif

#include "nebmodules.h"


/***** CALLBACK TYPES *****/
enum NEBCallbackType {
	NEBCALLBACK_PROCESS_DATA = 0,
	NEBCALLBACK_TIMED_EVENT_DATA,
	NEBCALLBACK_LOG_DATA,
	NEBCALLBACK_SYSTEM_COMMAND_DATA,
	NEBCALLBACK_EVENT_HANDLER_DATA,
	NEBCALLBACK_NOTIFICATION_DATA,
	NEBCALLBACK_SERVICE_CHECK_DATA,
	NEBCALLBACK_HOST_CHECK_DATA,
	NEBCALLBACK_COMMENT_DATA,
	NEBCALLBACK_DOWNTIME_DATA,
	NEBCALLBACK_FLAPPING_DATA,
	NEBCALLBACK_PROGRAM_STATUS_DATA,
	NEBCALLBACK_HOST_STATUS_DATA,
	NEBCALLBACK_SERVICE_STATUS_DATA,
	NEBCALLBACK_ADAPTIVE_PROGRAM_DATA,
	NEBCALLBACK_ADAPTIVE_HOST_DATA,
	NEBCALLBACK_ADAPTIVE_SERVICE_DATA,
	NEBCALLBACK_EXTERNAL_COMMAND_DATA,
	NEBCALLBACK_AGGREGATED_STATUS_DATA,
	NEBCALLBACK_RETENTION_DATA,
	NEBCALLBACK_CONTACT_NOTIFICATION_DATA,
	NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA,
	NEBCALLBACK_ACKNOWLEDGEMENT_DATA,
	NEBCALLBACK_STATE_CHANGE_DATA,
	NEBCALLBACK_CONTACT_STATUS_DATA,
	NEBCALLBACK_ADAPTIVE_CONTACT_DATA,
	NEBCALLBACK_TYPE__COUNT
};

enum NEBCallbackAPIVersion {
	NEB_API_VERSION_1,
	NEB_API_VERSION_2
};

#define NEBCALLBACK_NUMITEMS                          NEBCALLBACK_TYPE__COUNT    /* total number of callback types we have */
#define nebcallback_flag(x) (1 << (x))

/***** CALLBACK FUNCTIONS *****/
NAGIOS_BEGIN_DECL

int neb_register_callback(enum NEBCallbackType callback_type, void *mod_handle, int priority, int (*callback_func)(int, void *));
int neb_register_callback_full(enum NEBCallbackType callback_type, void *mod_handle, int priority, enum NEBCallbackAPIVersion api_version, void *callback_func);
int neb_deregister_callback(enum NEBCallbackType callback_type, void *callback_func);
int neb_deregister_module_callbacks(nebmodule *);

NAGIOS_END_DECL
#endif
