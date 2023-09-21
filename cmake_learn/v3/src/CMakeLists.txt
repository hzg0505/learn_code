add_executable(v3 main.cpp)    # 可执行文件 执行

# target_include_directories(v3 ${CMAKE_CURRENT_SOURCE_DIR}/include) # 指定头文件

target_link_libraries(v3 ${LIBCALC})  # 指定需要链接的库




