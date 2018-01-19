#### 内容
在Eigen中使用四元数、欧拉角和旋转矩阵，演示它们之间的变换方式。

#### use it
add `#include<Eigen/Geometry>` to use this module.

#### 总结
- 旋转矩阵(3x3): Eigen::Matrix3d
- 旋转向量(3x1): Eigen::AngleAxisd
- 欧拉角(3x1): Eigen::Vector3d
- 四元数(4x1): Eigen::Quaterniond
- 欧式变换矩阵(4x4): Eigen::Isometry3d
- 放射变换(4x4): Eigen::Affine3d
- 摄影变换(4x4): Eigen::Projective3d
