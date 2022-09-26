#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"

/* types */

typedef struct {
    Chunk *chunk;
    uint8_t *ip;        /* instruction pointer */
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;


/* functions */

void initVM();
void freeVM();
InterpretResult interpret(Chunk *chunk);


#endif /* CLOX_VM_H */
