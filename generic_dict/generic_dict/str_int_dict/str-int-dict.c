/**
 * str-int-dict.c
 *   Dict from string to int.
 */

#include "str-int-dict.h"

// Generic Dict structure
#include "../generic_dict/generic-create.gnrc"
#include "../generic_dict/generic-put.gnrc"
#include "../generic_dict/generic-get.gnrc"
#include "../generic_dict/generic-destroy.gnrc"
#include "../generic_dict/generic-print.gnrc"

// Type specific methods
#include "typed/str-int-free.c"
#include "typed/str-int-print.c"
#include "typed/str-hash.c"
