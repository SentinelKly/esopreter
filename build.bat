@echo off

mkdir bin
gcc src/main.c src/deadfish.c src/brainfuck.c -o bin/esopreter.exe