#!/bin/sh

# Compile
gcc -std=c89 -Wall src/main.c -o target/main.out

# Run
target/main.out
