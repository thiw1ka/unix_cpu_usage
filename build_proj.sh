#!/bin/bash

cd build

rm cpu_usage_logger

cmake.. -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..

make VEBOSE=1

read -p "Do you want to proceed running executable? (yes/no): " user_input

if [[ "$user_input" == "yes" ]]; then
    ./cpu_usage_logger
fi
