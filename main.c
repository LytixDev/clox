#include "common.h"
#include "chunk.h"
#include "debug.h"


int main(int argc, const char *argv[]) {
    Chunk chunk;

    init_chunk(&chunk);

    size_t constant = add_constant(&chunk, 4.2);
    write_chunk(&chunk, OP_CONSTANT, 123);
    write_chunk(&chunk, constant, 123);

    write_chunk(&chunk, OP_RETURN, 123);
    dissasemble_chunk(&chunk, "test chunk");
    free_chunk(&chunk);

    return 0;
}
