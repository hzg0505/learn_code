cmake_minimum_required(VERSION 3.20)

# .sln
PROJECT(v3)

# set(SRC_LIST add.cpp sub.cpp div.cpp mul.cpp  main.cpp)
# 不用枚举所有文件
aux_source_directory(calc SRC)   # 置顶搜索依赖的源文件 calc文件夹 =》 SRC

add_library(calc SHARED ${SRC})  # 生成动态库 生成名为calc的动态库，依赖SRC

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # 指定生成动态库的路径

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 指定可执行程序生成路径

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) # 指定头文件目录

link_directories(${PROJECT_BINARY_DIR}/lib)  # 链接时从哪个目录找静态库

# link_libraries(calc) # 库名

add_executable(v2 main.cpp)

target_link_libraries(v2 calc)
