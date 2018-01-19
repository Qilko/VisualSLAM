# Setup Ubuntu environment

### Install Ubuntu

Install Ubuntu in VMware Fusion

### Install Kdevelop

```
wget -O KDevelop.AppImage https://download.kde.org/stable/kdevelop/5.2.1/bin/linux/KDevelop-5.2.1-x86_64.AppImage
chmod +x KDevelop.AppImage
./KDevelop.AppImage
```

#### Kdevelop 流程

1. 导入现有project
  project -> open/import project: 选中 CMakeLists.txt 所在的文件夹，选择CMake Project

2. 告诉kdevelop想启动那个程序
  - run -> configure launches
  - add -> compiled binary
  - project target 指向 二进制文件

3. 菜单栏：build, debug, execute

### Cmake

For more info, see **CMakeLists.txt**

Install cmake `sudo apt install cmake`

#### How to use cmake

1. make a CMakeLists.txt
2. follow these steps
```
mkdir build
cd build
cmake ..
make
```

#### add library to CMakeLists

静态库以.a为后缀，共享库以.o为后缀。静态库每次被调用都会生成一个副本，而共享库则只有一个副本。
