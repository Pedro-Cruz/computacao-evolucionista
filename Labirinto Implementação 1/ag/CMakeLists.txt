cmake_minimum_required(VERSION 3.5.1)
project(Doutorado LANGUAGES CXX C)



# Set the names of the executable
SET(EXE_NAME  exec)

SET(SUNDIALS_INC_DIR ${SUNDIALS_INC_DIR} ./header)

INCLUDE_DIRECTORIES(./header)



#Random-----------------------
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#-----------------------------

file(GLOB SOURCES ./src/*.cpp ./main.cpp)

ADD_EXECUTABLE(${EXE_NAME} ${SOURCES})
TARGET_LINK_LIBRARIES(${EXE_NAME})
