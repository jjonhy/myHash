cmake_minimum_required(VERSION 3.20)
project(simulador_fonte)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(simulador_fonte
        Controller.cpp
        Controller.h
        ControllerInterface.h
        Instrucoes.h
        main.cpp
        Mneumonicos.h
        Model.cpp
        Model.h
        ModelInterface.h
        Registradores.h
        Video.h
        View.cpp
        View.h)
