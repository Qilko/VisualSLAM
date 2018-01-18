# 声明要求的cmake最低版本
cmake_minimum_required( VERSION 2.8 )

# 设置编译模式
set( CMAKE_BUILD_TYPE "Debug" )

# 声明一个 cmake 工程
project ( HelloSLAM )


# 添加一个可执行的任务
# add_executable ( 程序名字 源代码文件 )
add_executable( helloSLAM helloSLAM.cpp )

# 把libHelloSLAM.cpp编译成一个叫做hello的静态库，会生成libhello.a
add_library( hello libHelloSLAM.cpp )

# 把libHelloSLAM.cpp编译成一个叫做hello的共享库，会生成libhello_shared.so
add_library( hello_shared SHARED libHelloSLAM.cpp )

# 添加第二个可以执行的程序，名字叫 useHello
add_executable( useHello useHello.cpp )
# 把上面生成的共享库hello_shared链接到程序useHello上
target_link_libraries( useHello hello_shared)
