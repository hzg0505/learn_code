# 生成动态库
aux_source_directory(./ SRC)   # 指定搜索依赖的源文件 calc文件夹 =》 SRC

add_library(${LIBCALC} SHARED ${SRC})  # 生成动态库

# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # 指定生成动态库的路径

# message((./ /include))

# message((${CMAKE_SOURCE_DIR}/include))

# target_include_directories(${LIBCALC}, ${CMAKE_SOURCE_DIR}/include) # 指定目标文件（动态库）和 头文件目录

# target_include_directories(${LIBCALC}, ${CMAKE_SOURCE_DIR}/include) # 指定目标文件（动态库）和 头文件目录