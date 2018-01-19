#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry> //Eigen Geometry module

//----------------------------use Eigen Geometry module-------------------------
// Eigen/Geometry 提供了各种旋转和平移的表示

int main(int argc, char const *argv[])
{
   // set a 3x3 indentity matrix
   Eigen::Matrix3d R = Eigen::Matrix3d::Identity();

   //-------------------get Rotation Matrix given theta,n-----------------------
   // 创建rotation动作
   //   rot(theta,n) rot 45 degree about z-axis
   //   类型 Eigen::AngleAxisd rot(),
   //     括号里面可以是（theta, n）, 也可以是quaternion q，应该还能是很多其他类型的
   //   旋转向量使用 AngleAxis, 它底层不直接是Matrix，但运算可以当作矩阵（因为重载了运算符）
   Eigen::AngleAxisd rot(M_PI / 4, Eigen::Vector3d(0, 0, 1));
   //   Eigen::AngleAxisd rot_2(q); //q在下面定义这里用不了
   // two ways to see the rotation matrix from rot，都可以返回一个matrix
   // 1. rot.matrix()
   // 2. rot.toRotationMatrix()
   R = rot.matrix();           //等价
   R = rot.toRotationMatrix(); //等价
   cout << "rotation matrix =\n" << R << "\n" << endl;

   // 坐标转换
   // 初始vector p
   Eigen::Vector3d p(1, 0, 0);        //这里用了括号初始化，没有赋值操作
   // p' = rot * p -> p在旋转后的坐标里面的值
   Eigen::Vector3d p_prime = rot * p; //rot.matrix()*p, rot可以直接进行运算（因为重载了运算符）
                                      //也可以用 p_prime = R * p   line23
   cout << "vector p (1,0,0) after rotation = " << p_prime.transpose() << "\n" << endl;

   //-----------------------------Euler Angle-----------------------------------
   // 可以将旋转矩阵直接转换成欧拉角，欧拉角用3个量表示3个自由度
   // 欧拉角将一个一次性的rotation matrix分解成三次旋转，返回每次旋转对应的角度
   // 所有3维matrix都可以使用.eulerAngles(0,1,2)，类型为AngleAxisd的，比如rot不能使用(line19)
   Eigen::Vector3d euler_angles // 返回一个3x1的向量
      = R.eulerAngles(2, 1, 0); // ZYX顺序，即roll pitch yaw顺序
   cout << "yaw pitch roll = " << euler_angles.transpose() << "\n" << endl;

   //------------------------Transformation Matrix------------------------------
   // T = | R | t |
   //     | 0 | 1 |
   // given R，t，create transformation matrix（欧式变换矩阵）
   Eigen::Vector3d   t(1, 2, 4);                        //初始化t，没有赋值操作
   Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); //虽然是3d，但是是4x4的矩阵
   T.rotate(R);                                         //把 R 放到 T 里面
   T.pretranslate(t);                                   //把 t 放到 T 里面
   cout << "Transform matrix = \n" << T.matrix() << "\n" << endl;

   // 坐标转换
   p_prime = T * p; //这里T是4x4，而p是3x1。实际操作是 p'=Rp+t
   cout << "p' after transformation matrix is "
        << p_prime.transpose() << "\n" << endl;

   //-------------------------------Quaternion---------------------------------
   // 将 rotation matrix R 转变为 Quaternion q
   // 用Eigen::Quaternion()
   // 括号里的参数类型可以是Matrix3d,比如R，也可以是AngleAxisd，比如rot
   Eigen::Quaterniond q = Eigen::Quaterniond(rot);
   // 请注意coeffs的顺序是(x,y,z,w),w为实部，前三者为虚部
   cout << "quaternion = \n" << q.coeffs() << "\n" << endl;

   // 坐标转换
   p_prime = q * p; //这里的实际操作是 p'=qpq^(-1)
   cout << "p' after Quaternion transformation is "
        << p_prime.transpose() << "\n" << endl;

   //----对于仿射和射影变换，使用 Eigen::Affine3d 和 Eigen::Projective3d 即可，略-----

   return 0;
}
