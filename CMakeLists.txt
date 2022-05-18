cmake_minimum_required(VERSION 3.22)
project(pratica6 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pratica6
        ordenacao.h
        ordenacao.c
        pratica6.c)
