#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"


/* macros */

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, old_size, new_size) \
    (type *)reallocate(pointer, sizeof(type) * (old_size), \
        sizeof(type) * (new_size))

#define FREE_ARRAY(type, pointer, old_size) \
    reallocate(pointer, sizeof(type) * (old_size), 0)


/* functions */

void *reallocate(void *pointer, size_t old_size, size_t new_size);



#endif /* CLOX_MEMORY_H */
