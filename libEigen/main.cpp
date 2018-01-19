#include <iostream>
using namespace std;

#include <ctime>

// use eigin in c++
// Eigen Core part
#include <Eigen/Core>
// 稠密矩阵的代数运算
#include <Eigen/Dense>

#define MATRIX_SIZE    50

//---------------------介绍eigen库的基本用法-----------------------
//内置类型：Eigen::Matrix<>，适用于所有向量和矩阵
//这是一个模版类，三个参数为：数据类型，行，列

int main(int argc, char const *argv[])
{
   //---------------------创建不同类型的向量或者矩阵------------------

   //声明一个2*3的float矩阵
   Eigen::Matrix<float, 2, 3> matrix_23;

   //Eigen 通过 typedef 提供了许多内置类型，不过底层仍然是 Eigen::Matrix
   //例如， Vector3d三位向量 就是 Eigen::Matrix<double,3,1>
   Eigen::Vector3d            v_3d;   //这两个等价, 但是这个数据类型是double
   Eigen::Matrix<float, 3, 1> v_3d_1; //这两个等价，这个数据类型是float

   //Matrix3d 实质上是 Eigen::Matrix<double, 3, 3>
   Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); //初始化为零

   //动态大小的矩阵，矩阵大小不确定
   //第一行用最基本的类型，第二行是eigen用typedef提供的
   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
   Eigen::MatrixXd matrix_dynamic_1;

   //---------------------对Eigen矩阵的操作------------------

   //数据初始化
   matrix_23 << 1, 2, 3, 4, 5, 6;

   //输出
   cout << "直接用cout输出\n" << matrix_23 << endl;
   //遍历矩阵元素
   //
   // for (size_t i = 0; i < 2; i++)
   // {
   //    for (size_t j = 0; j < 3; j++)
   //    {
   //       cout << matrix_23(i, j) << "\t";
   //    }
   //    cout << endl;
   // }

   //矩阵间乘法，或者矩阵和向量
   //要注意的：
   //1. 两个对象内元素的数据类型要一样
   //   Wrong example:
   //   Eigen::Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
   //2. 遵循矩阵乘法规则, 例如矩阵维度
   //   Wrong example:
   //   Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;
   v_3d << 3, 2, 1;   //v_3d数据类型是double
   v_3d_1 << 4, 5, 6; //v_3d_1数据类型是float

   //四则运算 用 + - * /
   //这里展示乘法
   //matrix_23数据类型是float，如果要和v_3d相乘，需要显示转换
   //Eigen为了性能，不会提供隐士转换，转换成员函数是 .cast<double>()
   Eigen::Matrix<double, 2, 1> result  = matrix_23.cast<double>() * v_3d;
   Eigen::Matrix<float, 2, 1>  result2 = matrix_23 * v_3d_1;

   //矩阵运算
   matrix_33 = Eigen::Matrix3d::Random();                             //随机3x3的矩阵，但是感觉怎么都不变...
   cout << "matrix \n" << matrix_33 << endl << endl;
   cout << "matrix transpose\n" << matrix_33.transpose() << endl;     // 转置
   cout << "matrix sum\n" << matrix_33.sum() << endl;                 // 各元素和
   cout << "matrix trace\n" << matrix_33.trace() << endl;             // 迹
   cout << "matrix inverse\n" << matrix_33.inverse() << endl;         // 逆
   cout << "matrix determinant\n" << matrix_33.determinant() << endl; // 行列式


   //----------------------eigenvalues & eigenvectors-----------------
   // Computes eigenvalues and eigenvectors of selfadjoint matrices.
   // define a selfadjoint Matrix
   Eigen::Matrix3d S = matrix_33.transpose() * matrix_33;
   // use solver on 3x3 matrix S
   Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> es(S);
   cout << "Eigen values = \n" << es.eigenvalues() << endl;
   cout << "Eigen vectors = \n" << es.eigenvectors() << endl;


   //-------------------------解方程-----------------------------
   //Solve matrix_NN * x = v_Nd
   //直接求逆求解 与 QR decomposition求解
   //define matrix_NN and v_Nd
   Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
   matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE); //另一种使用random的用法
   Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd;
   v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);
   Eigen::Matrix<double, MATRIX_SIZE, 1> x;
   //set timer
   clock_t time_start = clock();
   //1. solve by inverse, time used is4.151ms
   x = matrix_NN.inverse() * v_Nd;
   cout << "time used is" << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;
   //2. solve by QR decomposition, time used is0.082ms
   time_start = clock();
   x          = matrix_NN.colPivHouseholderQr().solve(v_Nd);
   cout << "time used is" << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

   return 0;
}
