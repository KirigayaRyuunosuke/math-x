#!/bin/bash

g++ main.cpp src/*.cpp -o program;  # compile
./program;                          # run
rm -f program;                      # remove
