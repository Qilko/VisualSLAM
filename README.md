# VisualSLAM Learning Notes
参考图书：

高翔, 张涛, 颜沁睿, 刘毅 《视觉SLAM十四讲：从理论到实践》，电子工业出版社, 2017

## Chapter 2

#### 视觉SLAM框架

1. 传感器数据读取(Sensor Data): 视觉SLAM中主要为图像信息读取和预处理；如果在机器人中，还有码盘、IMU等信息的读取和同步。
2. 视觉里程计(Frontend Visual Odometry): 估算相邻图像间相机的运动，以及局部地图的样子。
3. 后端优化(Backend Optimization): 后端接受不同时刻视觉里程计测量的相机位姿，以及回环检测信息，对他们进行优化，得到全局一致的轨迹和地图。
4. 回环检测(Loop Closing): 负责检测机器人是否到达过先前的位置，若果是，把信息传递给后端优化处理。
5. 建图(Mapping): 根据估计的轨迹，建立与任务要求对应的地图。

#### 实践：基于Ubuntu用Kdevelop创建Cmake项目

## Chapter 3

### 三维空间的刚体运动描述

- 旋转矩阵
- 变换矩阵
- 四元数
- 欧拉角

### 实践：Eigen库
