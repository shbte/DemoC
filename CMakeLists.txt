cmake_minimum_required(VERSION 2.8.12)
project(Cmake_test)

# 设置头文件
# include_directories(include)

add_subdirectory(example)
add_subdirectory(work)

# 如果想使用gdb调试功能，这里必须手动设置成Debug模式
set(CMAKE_BUILD_TYPE Debug)

#设置执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置源文件
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
AUX_SOURCE_DIRECTORY(./example EXAMPLE_DIR_SRCS)
AUX_SOURCE_DIRECTORY(./work WORK_DIR_SRCS)

# 设置编译可执行文件
ADD_EXECUTABLE(cmake_main ${DIR_SRCS} ${EXAMPLE_DIR_SRCS} ${WORK_DIR_SRCS})

# 将库链接进可执行文件中
target_link_libraries(cmake_main example)
target_link_libraries(cmake_main work)
