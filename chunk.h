#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H


#include "common.h"

/* types */

/* each instruction has a one-byte operation code (opcode) */
typedef enum {
    OP_RETURN,
} OpCode;

/* dynamic array of instructions */
typedef struct {
    uint8_t *code;
    size_t size;
    size_t capacity;
} Chunk;


/* functions */

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);


#endif /* CLOX_CHUNK_H */
