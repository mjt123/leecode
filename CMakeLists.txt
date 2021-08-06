#指定CMake编译的最低版本
cmake_minimum_required(VERSION 2.8.12)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread" )

#项目名称
PROJECT(leecodeExercise)

Set(ROOT_DIR "{PROJECT_SOURCE_DIR}/")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB Main_SRCS "source/*_main.cpp")
#foreach(Main_FILE ${Main_SRCS})
#  message(${Main_FILE})
#  get_filename_component(Main_NAME ${Main_FILE} NAME_WE)
#  set(PROJ_NAME "leecodeExercise_${Main_NAME}")
#  message(STATUS "Adding project ${PROJ_NAME}")
#  add_executable("${PROJ_NAME}" ${SRC_FILE})
#endforeach(Main_FILE)
# ADD_EXECUTABLE(${Main_SRC} ${Main_SRC})
foreach (file ${Main_SRCS})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
