#!/bin/bash

g++ Model.cpp -c
# shellcheck disable=SC2046
# shellcheck disable=SC2006
g++ View.cpp -c `pkg-config --libs --cflags gtk+-3.0`
# shellcheck disable=SC2046
# shellcheck disable=SC2006
g++ Controller.cpp -c `pkg-config --libs --cflags gtk+-3.0`
# shellcheck disable=SC2046
g++ main.cpp View.cpp Controller.cpp Model.cpp -O3 -march=native -o sim `pkg-config --libs --cflags gtk+-2.0` -lcurses -pthread -Wall -lgthread-2.0
# shellcheck disable=SC2046
g++ main.cpp View.cpp Controller.cpp Model.cpp -O3 -march=native -o sim `pkg-config --libs --cflags gtk+-2.0` -pthread -Wall -lgthread-2.0
