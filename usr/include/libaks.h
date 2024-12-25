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
#if 0
static keybag_handle_t get_aks_client_connection()

static keybag_handle_t get_keybag(void)
{
  /* The original impl is objc involved, so this is a simplified version */
  static dispatch_once_t once;
  static keybag_handle_t handle;

  dispatch_once(&once, ^{
    if (aks_get_system(NULL, &handle)) abort();
  });
  return handle;
}

IOReturn aks_unwrap_key(const uint8_t *source, uint32_t textLength, keyclass_t keyclass, keybag_handle_t keybag, uint8_t *data, int *dest_len);

#endif
__END_DECLS

#endif
