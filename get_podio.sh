#!/bin/bash

repository="https://github.com/AIDASoft/podio"
local_dir="podio"

if [ -d $local_dir ]
then 
    printf "Removing old repository...\n"
    rm -rf $local_dir
fi

printf "Cloning...\n"
git clone $repository $local_dir

cd $local_dir

printf "Compiling...\n"
source ./init.sh
mkdir build
mkdir install
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
make -j 4 install

printf "Running tests...\n"
make test