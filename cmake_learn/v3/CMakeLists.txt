cmake_minimum_required(VERSION 3.20)

# .sln
PROJECT(v3)

set(LIBCALC calc) # 定义全局变量

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # 指定可执行程序生成路径

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 指定可执行程序生成路径

# set(CMAKE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories(${PROJECT_BINARY_DIR}/lib)  # 链接时从哪个目录找库

# link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加子节点
add_subdirectory(calc)    # 生成动态库      add开头关键字都是用来生成某些对象
add_subdirectory(src)     # 生成可执行程序


