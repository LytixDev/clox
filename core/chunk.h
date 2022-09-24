#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "../common.h"
#include "value.h"


/* types */

/* each instruction has a one-byte operation code (opcode) */
typedef enum {
    OP_CONSTANT,        /* constants have 1-byte operands */
    OP_RETURN,
} OpCode;

/* dynamic array of instructions */
typedef struct {
    uint8_t *code;
    size_t size;
    size_t capacity;
    ValueArray constants;
    int *lines;         /* line number in source code that parallels the bytecode */
} Chunk;


/* functions */

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte, int line);
size_t add_constant(Chunk *chunk, Value value);


#endif /* CLOX_CHUNK_H */
