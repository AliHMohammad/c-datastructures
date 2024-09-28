#!/bin/bash

set -e

gcc -Wall -o ./build/file ./src/*.c 
./build/file
