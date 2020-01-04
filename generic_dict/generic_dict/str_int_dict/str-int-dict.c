/**
 * str-int-dict.c
 *   Dict from string to int.
 */

#include "str-int-dict.h"

// Generic Dict structure
#include "generic/generic-create.gnrc"
#include "generic/generic-put.gnrc"
#include "generic/generic-get.gnrc"
#include "generic/generic-destroy.gnrc"
#include "generic/generic-print.gnrc"

// Type specific methods
#include "typed/str-int-free.c"
#include "typed/str-int-print.c"
#include "typed/str-hash.c"
