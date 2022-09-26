#include <stdio.h>
#include "memory.h"
#include "value.h"


void init_value_array(ValueArray *array)
{
    array->size = 0;
    array->capacity = 0;
    array->values = NULL;
}

void free_value_array(ValueArray *array)
{
    FREE_ARRAY(uint8_t, array->values, array->capacity);
    //init_chunk(chunk);
}

void write_value_array(ValueArray *array, Value value)
{
    /* allocate more space */
    if (array->size >= array->capacity) {
        size_t old_capacity = array->capacity;
        array->capacity = GROW_CAPACITY(old_capacity);
        array->values = GROW_ARRAY(Value, array->values, old_capacity, array->capacity);
    }

    array->values[array->size++] = value;
}

void print_value(Value value)
{
    printf("%g", value);
}
