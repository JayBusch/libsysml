#rm -rf .build
cmake -H. -B.build -DCMAKE_TOOLCHAIN_FILE=$HOME/src/vcpkg/scripts/buildsystems/vcpkg.cmake
cd .build && make

