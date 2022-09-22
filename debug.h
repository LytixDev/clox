#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"


/* functions */

void dissasemble_chunk(Chunk *chunk, const char *name);
int dissasemble_instruction(Chunk *chunk, int offset);


#endif /* CLOX_DEBUG_H */
