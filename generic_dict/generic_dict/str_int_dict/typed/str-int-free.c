#include "generic-dict.h"

inline void FUNC_POSTFIX(free_key)(KEY_TYPE *key) {
    free(key);
}

inline void FUNC_POSTFIX(free_value)(VALUE_TYPE *value) {
    free(value);
}