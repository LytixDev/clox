#include "common.h"
#include "debug.h"
#include "core/chunk.h"
#include "core/vm.h"


int main(int argc, const char *argv[]) {
    initVM();


    Chunk chunk;

    init_chunk(&chunk);

    size_t constant = add_constant(&chunk, 4.2);
    write_chunk(&chunk, OP_CONSTANT, 123);
    write_chunk(&chunk, constant, 123);

    write_chunk(&chunk, OP_RETURN, 123);
    // for debug purposes
    dissasemble_chunk(&chunk, "test chunk");

    interpret(&chunk);
    freeVM();
    free_chunk(&chunk);

    return 0;
}
