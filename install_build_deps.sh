#!/bin/bash
#apt install -y --no-install-recommends libx11-dev libxrandr-dev mesa-utils freeglut3-dev libudev-dev libfreetype-dev libopenal-dev libvorbis-dev libflac-dev libsfml-dev libc6-dev libboost-all-dev

#apt install -y --no-install-recommends libc6-dev libboost-all-dev

cd dependencies
git clone 'https://chromium.googlesource.com/chromium/tools/depot_tools.git'
export PATH="${PWD}/depot_tools:${PATH}"

git clone https://skia.googlesource.com/skia.git
cd skia
ls -al

python tools/git-sync-deps

bin/gn gen out/Static --args='is_official_build=true cc="clang" cxx="clang++" skia_use_system_harfbuzz=false'
bin/gn gen out/Shared --args='is_official_build=true is_component_build=true cc="clang" cxx="clang++" skia_use_system_harfbuzz=false'

ninja -C out/Static

#tools/install_dependencies.sh

cd ..

