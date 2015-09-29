#!/bin/bash

# compile files

echo "Start Compile add number"
echo "g++-5 -std=c++11 -Wall -o add_number add_numbers.cpp"

g++-5 -std=c++11 -Wall -o add_number add_numbers.cpp

if [ $? != 0 ]
then
    echo "Compile error"
fi

echo "./add_number"
./add_number

if [ $? != 1 ]
then
    echo "Excute add_number failed"
fi
