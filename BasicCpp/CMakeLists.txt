# 声明要求的cmake最低版本
cmake_minimum_required( VERSION 2.8 )

# 声明一个 cmake 工程
project ( HelloSLAM )

# 添加一个可执行的任务
# add_executable ( 程序名字 源代码文件 )
add_executable( helloSLAM helloSLAM.cpp )
