#include <stdio.h>
#include "../common.h"
#include "value.h"
#include "vm.h"

VM vm;


void initVM()
{
}

void freeVM()
{
}

/* runs and interprets the actual bytecode instructions */
static InterpretResult run()
{
#define READ_BYTE() (*vm.ip++)  /* ip always points to the *next* byte of code to be used */
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    while (1) {
#ifdef DEBUG_TRACE_EXECUTION
#       include "../debug.h"
        dissasemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif /* DEBUG_TRACE_EXECUTION */
        uint8_t instruction;
        /* dispatching the instruction */
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                print_value(constant);
                putchar('\n');
                break;
            }

            case OP_RETURN:
                return INTERPRET_OK;
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}

