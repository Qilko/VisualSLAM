# Setup Ubuntu environment

### Install Ubuntu

Install Ubuntu in VMware Fusion

### Install Kdevelop

```
wget -O KDevelop.AppImage https://download.kde.org/stable/kdevelop/5.2.1/bin/linux/KDevelop-5.2.1-x86_64.AppImage
chmod +x KDevelop.AppImage
./KDevelop.AppImage
```

### Cmake

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
