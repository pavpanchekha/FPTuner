#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

INSTALL_PATH=${SCRIPT_LOCATION}/glibc_install

rm -rf glibc glibc_build glibc_install

git clone git://sourceware.org/git/glibc.git
cd glibc
git checkout release/2.32/master

cd ..
mkdir -p glibc_build
cd glibc_build
../glibc/configure  --prefix=${INSTALL_PATH}
make
make install

cd ..
cd glibc_install
mkdir butchered_libm
cp lib/libm* butchered_libm
