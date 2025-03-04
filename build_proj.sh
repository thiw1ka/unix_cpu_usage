#!/bin/bash

rm -d build -r

cmake -S . -B build -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

cd build

make VEBOSE=1

read -p "Do you want to proceed running executable? (yes/no): " user_input

if [[ "$user_input" == "yes" ]]; then
    ./cpu_usage_logger
fi
