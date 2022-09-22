#include <stdio.h>
#include "chunk.h"
#include "debug.h"


void dissasemble_chunk(Chunk *chunk, const char *name)
{
    printf("== %s == \n", name);

    for (int offset = 0; offset < chunk->size;) {
        offset = dissasemble_instruction(chunk, offset);
    }
}

static int simple_instruction(const char *name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

static int constant_instruction(const char *name, Chunk *chunk, int offset)
{
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);              /* print name of opcode */
    print_value(chunk->constants.values[constant]);     /* print value of operand */
    putchar('\'');
    putchar('\n');
    /* +2 because we store the opcode and a 1-byte operand */
    return offset + 2; 
}

int dissasemble_instruction(Chunk *chunk, int offset)
{
    /* print byte offset of the given instruction */
    printf("%04d ", offset);

    /* print line number in source code */
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1])
        printf("   | ");
    else
        printf("%4d ", chunk->lines[offset]);

    /* opcode */
    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);

        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);

        default:
            printf("Unknown opcode %d\n", instruction);
            /* some opcodes may be longer than one byte */
            return offset + 1;
    }
}

