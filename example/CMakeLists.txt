# 设置头文件
include_directories(include)

# 添加文件
file(GLOB DIR_MODULE1 "src/*.cpp")

# 添加库
add_library(example ${DIR_MODULE1})
