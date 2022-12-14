#include <stdint.h>
#include <stdlib.h>

#include "chunk.h"
#include "memory.h"


void init_chunk(Chunk *chunk)
{
    chunk->size = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

void free_chunk(Chunk *chunk)
{
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    //init_chunk(chunk);
}

void write_chunk(Chunk *chunk, uint8_t byte)
{
    /* allocate more space */
    if (chunk->size >= chunk->capacity) {
        size_t old_capacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(old_capacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, old_capacity, chunk->capacity);
    }

    chunk->code[chunk->size++] = byte;
}
