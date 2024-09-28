#!/bin/bash

set -e

gcc -Wall -o ./build/file.exe ./src/*.c 
./build/file.exe
