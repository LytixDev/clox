#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "../common.h"

/* types */

typedef double Value;

typedef struct {
    Value *values;
    size_t size;
    size_t capacity;
} ValueArray;


/* functions */

void init_value_array(ValueArray *array);
void write_value_array(ValueArray *array, Value value);
void free_value_array(ValueArray *array);
void print_value(Value value);


#endif /* CLOX_VALUE_H */
