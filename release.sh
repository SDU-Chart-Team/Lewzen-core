#!/bin/sh
platform="$1"
ver=$(date +%Y%m%d)

if [ "$platform" = "linux-g++" ]
then
    cd core
    make cc=g++ ar=ar
elif [ "$platform" = "win-g++" ]
then
    cd core
    make cc=x86_64-w64-mingw32-g++ ar=x86_64-w64-mingw32-ar
elif [ "$platform" = "linux-clang++" ]
then
    cd core
    make cc=clang++ ar=llvm-ar
elif [ "$platform" = "linux-em++" ]
then
    cd core
    make cc=em++ ar=emar
else
    echo unsupported platform.
    exit 1
fi

make clean
cd ..
if [ ! -d "release/" ]
then
  mkdir release/
fi
cp core/ release/lewzen-core/ -r
rm core/lewzen-core.lib
cd release/lewzen-core
rm .attr_def -rf
rm .svg_def -rf
rm svg_el/.src_gen -rf
rm svgi_el/.src_gen -rf
rm svgi_el/attr/.src_gen -rf
rm json.hpp
mv lewzen-core.lib ../lewzen-core.lib
rm Makefile
rm geometry/Makefile
rm geometry/coordinate_system/Makefile
rm svg_el/Makefile
rm svgi_el/Makefile
rm svgi_el/attr/Makefile

cd ../..

if [ "$platform" = "linux-g++" ]
then
    tar -czvf ../lewzen-core-linux-g++-${ver}.tar.gz release/*
    rm release/ -rf
elif [ "$platform" = "win-g++" ]
then
    7z a -t7z -r ../lewzen-core-win-g++-${ver}.7z release/*
    rm release/ -rf
elif [ "$platform" = "linux-clang++" ]
then
    tar -czvf ../lewzen-core-linux-clang++-${ver}.tar.gz release/*
    rm release/ -rf
elif [ "$platform" = "linux-em++" ]
then
    tar -czvf ../lewzen-core-linux-em++-${ver}.tar.gz release/*
    rm release/ -rf
else
    echo unsupported platform.
    exit 1
fi