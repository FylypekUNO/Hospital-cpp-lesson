cmake_minimum_required(VERSION 3.30)
project(Hospital)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++ -lpthread")

add_executable(Hospital main.cpp
        Utility.cpp
        Utility.h
        Randomiser.cpp
        Randomiser.h
        PatientAccount.cpp
        Pharmacy.cpp
        Surgery.cpp
)
