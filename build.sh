#!/bin/bash
#CC=clang CXX=clang++ cmake -H. -B.build -DCMAKE_TOOLCHAIN_FILE=$HOME/src/vcpkg/scripts/buildsystems/vcpkg.cmake

rm -rf .build
echo "RUNNING BUILD"
CC=clang CXX=clang++ cmake -H. -B.build

cd .build && make

