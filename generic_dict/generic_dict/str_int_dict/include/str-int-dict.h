#ifndef STRING_INT_DICT_H
#define STRING_INT_DICT_H

/**
 * str-int-dict.h
 *   Dict from string to int.
 */

#undef VALUE_TYPE
#undef FUNC_POSTFIX

#define VALUE_TYPE int
#define FUNC_POSTFIX(NAME) NAME ## _str_int

#include "generic-dict.h"
#include <math.h>

#endif // STRING_INT_DICT_H
