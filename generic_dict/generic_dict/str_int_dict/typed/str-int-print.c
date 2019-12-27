#include "str-int-dict.h"

char * print_items_str_int(struct Bucket *bucket) {
    int size;
    size = 11 + strlen(bucket->key) + (log10(*bucket->value) + 1);


    char *bucket_as_str = malloc((size + 1) * sizeof(char));
    sprintf(bucket_as_str, "key: %s\nval: %d", bucket->key, *bucket->value);
    
    return bucket_as_str;
}