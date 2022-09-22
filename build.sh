#!/bin/sh
# stupid temporary build script

gcc -o clox $(find *.c | xargs) 
