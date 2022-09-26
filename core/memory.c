#include <stdlib.h>

#include "memory.h"


/*
 * old_size = 0,        new_size = non-zero     -> allocate new block
 * old_size = non-zero, new_size = 0            -> free allocation 
 * old_size = non-zero, new_size < old_size     -> shrink existing allocation 
 * old_size = non-zero, new_size > old_size     -> grow existing allocation 
 */
void *reallocate(void *pointer, size_t old_size, size_t new_size)
{
    if (new_size == 0) {
        free(pointer);
        return NULL;
    }

    void *res = realloc(pointer, new_size);
    //TODO: better error handling
    if (res == NULL)
        exit(1);

    return res;
}
