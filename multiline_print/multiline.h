#ifndef MULTILINE_PRINT_H
#define MULTILINE_PRINT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARROW_SIZE 7

void append_column(char *seq, char delim);
void flush(void);

#endif // MULTILINE_PRINT_H