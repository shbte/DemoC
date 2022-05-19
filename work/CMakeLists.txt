# 设置头文件
include_directories(include)

# 添加文件
file(GLOB DIR_MOUDLE2 "src/*.cpp")

# 添加库
add_library(work ${DIR_MOUDLE2})
