# 如何使用Eigen

## 简介
Eigen是一个C++开源线性代数库。它提供了快速的有关矩阵的线性代数运算，还包括解方程等功能。许多上层的软件库也在使用Eigen进行矩阵运算，包括g2o、Sophus等。

另外，Eigen有一个特别的地方：它是一个纯用头文件搭建起来的库，并没有.so或者.o那样的二进制文件。所以，在使用时，只需引入Eigen头文件即可，不需要链接库文件。

#### Install eigen

`sudo apt install libeigen3-dev`

#### include eigen in main.cpp

```
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>
```

#### add eigen in CMakeLists.txt
只需要include头文件，不需要`target_link_libraries`库文件（因为没有）

```
include_directories( "/usr/include/eigen3" )
# in osx and brew install
# include_directories( /usr/local/Cellar/eigen/3.3.3/include/eigen3 )
```
