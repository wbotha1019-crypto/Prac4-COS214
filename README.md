# Prac4-COS214

# TaskForge - COS 214 Practical 4

Emergency response coordination system using Composite, Iterator, State and Decorator.

Team: Nicole Bare, Jezelle Govender, Rudolph

## Docker

    docker build -t taskforge .
    docker run --rm taskforge

Shell inside the container for GDB and Valgrind:

    docker run --rm -it taskforge bash
    make valgrind
    gdb ./taskforge

## Without Docker

    make
    ./taskforge
    make valgrind
    make gdb
    make clean

## Layout

- *.h, *.cpp, main.cpp - source
- makefile, Dockerfile
- docs/ - diagrams, report, gdb_session.txt, valgrind_output.txt
- DESIGN_NOTES.md - implementation notes
