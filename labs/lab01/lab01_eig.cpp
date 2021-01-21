#include "Eigen/Eigen"
#include <iostream>

int main()
{
  // 1. Test the Getting Started code here:
  std::cout << "Getting start with lab01" << std::endl;
  //---------------------------------------

  // 2. Solve the tutorial problems here:
  // a) Create a few vectors and matrices.
  //--------------------------------------
  // Todo: Create vector t.
  // Eigen::Vector3d t{1.0, 0.0, 3.0}; or do like this
  Eigen::Vector3d t;
  t << 1.0,
       0.0,
       3.0;

  // Todo: Create matrix A.
  Eigen::Matrix3d A;
  A << 1.0, 0.0, 3.0,
       4.0, 5.0, 6.0,
       7.0, 8.0, 9.0;

  // Todo: Create identity matrix I.
  // Eigen::Matrix3d I{Eigen::Matrix3d::Identity()};
  Eigen::Matrix3d I;
  I << Eigen::Matrix3d::Identity();


  // Todo: Create matrix T.
  Eigen::Matrix4d T;
  T << A,t,
       0, 0, 0, 1;

  // Todo: Create matrix B.
  // Eigen::Matrix3d B{A.transpose()};
  Eigen::Matrix3d B;
  B << A.transpose();

  // Print the results (uncomment code below).
  std::cout << "a) Create a few vectors and matrices:" << std::endl;
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "t = " << std::endl << t << std::endl << std::endl;
  std::cout << "A = " << std::endl << A << std::endl << std::endl;
  std::cout << "I = " << std::endl << I << std::endl << std::endl;
  std::cout << "T = " << std::endl << T << std::endl << std::endl;
  std::cout << "B = " << std::endl << B << std::endl << std::endl;


  // b) Coefficients.
  //-----------------
  // Todo: Follow lab notes.
  // Set t[2, 1] = 2.0
  t(1) = 2.0;

  // Set A[1, 2] = 2.0
  A(0,1) = 2.0;

  // Perform the corresponding corrections to T
  // T (0, 1) = 2.0;
  // T (1, 3) = 2.0;
  T << A, t,
       0, 0, 0, 1;

  // Print the results.
  std::cout << "b) Coefficients:" << std::endl;
  std::cout << "----------------" << std::endl;
  std::cout << "t = " << std::endl << t << std::endl << std::endl;
  std::cout << "A = " << std::endl << A << std::endl << std::endl;
  std::cout << "T = " << std::endl << T << std::endl << std::endl;

  // c) Block operations.
  //---------------------
  // Todo: Follow lab notes.
  // Extract the second row vector of matrix A, i.e A[2, :]
  // Eigen::RowVector3d r_2 = A.row(1);
  Eigen::RowVector3d r_2;
  r_2 << A.row(1);

  // Extract the second column vector of matrix A, i.e A[:, 2]
  // Eigen::Vector3d c_2 = A.col(1);
  Eigen::Vector3d c_2;
  c_2 << A.col(1);

  // Extract the T_3x4
  // Make an "alias" for this matrix type for convenience. "using" = "import as" in python
  using Matrix34d = Eigen::Matrix<double, 3, 4>;
  Matrix34d T_3x4 = T.topLeftCorner<3, 4>();

  // Print the results.
  std::cout << "c) Block operations:" << std::endl;
  std::cout << "--------------------" << std::endl;
  std::cout << "r_2 = " << std::endl << r_2 << std::endl << std::endl;
  std::cout << "c_2 = " << std::endl << c_2 << std::endl << std::endl;
  std::cout << "T_3x4 = " << std::endl << T_3x4 << std::endl << std::endl;

  // Set the corresponding blocks in A and T to all 0 (so that the second row and col
  // in A are all 0, and the upper 3x4 matrix in T is all 0).
  // Set A[2, :] = 0
  A.row(1).setZero();

  // Set A[:, 2] = 0
  Eigen::Matrix3d::ColXpr c_2_xpr = A.col(1);
  c_2_xpr.setZero();

  // Set T_3x4 = 0
  Eigen::Ref<Matrix34d> T_3x4_ref = T.topLeftCorner<3,4>();
  T_3x4_ref.setZero();

  // Print the result
  std::cout << "After setting blocks to 0:" << std::endl;
  std::cout << "A = " << std::endl << A << std::endl << std::endl;
  std::cout << "T = " << std::endl << T << std::endl << std::endl;

  // d) Matrix and vector arithmetic.
  //---------------------------------
  // Todo: Follow lab notes.

  std::cout << "d) Matrix and vector arithmetic:" << std::endl;
  std::cout << "--------------------------------" << std::endl;
  // Add two vectors, ( t + c_2 )
  std::cout << "t + c_2  =" << std::endl << t + c_2 << std::endl << std::endl;

  // Add two matrices ( A + I )
  std::cout << "A + I =" << std::endl << A + I << std::endl << std::endl;

  // Multiply two matrices, (A + I) * T_3x4
  std::cout << "(A + I) * T_3x4 = " << std::endl << (A + I) * T_3x4 << std::endl << std::endl;

  // Take the cross product between two vectors, ( t.transpose() * c_2 )
  std::cout << "t.transpose() * c_2 = " << std::endl << t.transpose() * c_2 << std::endl << std::endl;

  // Take the dot product between two vectors, ( t.dot(c_2) )
  std::cout << "t.dot() * c_2 = " << std::endl << t.dot(c_2) << std::endl << std::endl;

  // Take the element-wise multiplication between two matrices
  std::cout << "Element-wise B * I = " << std::endl << B.cwiseProduct(I) << std::endl << std::endl;

  // Take the element-wise (array) multiplication between two matrices
  std::cout << "Element-wise (array) B * I = " << std::endl << B.array() * I.array() << std::endl << std::endl;

  // e) Reductions.
  //---------------
  // Todo: Follow lab notes.
  std::cout << "e) Reductions:" << std::endl;
  std::cout << "______________" << std::endl;
  // Take the sum of all elements in a matrix
  std::cout << "Sum of all elements in I = " << std::endl << I.sum() << std::endl;

  // Compute the minimum value in a matrix (also find its position in the matrix)
  Eigen::Matrix3d::Index min_row;
  Eigen::Matrix3d::Index min_col;
  std::cout << "Min in B = " << B.minCoeff(&min_row, &min_col);
  std::cout << " at (" << min_row << ", " << min_col << ")" << std::endl << std::endl;

  // Create a vector that is the maximum of each column in a matrix
  std::cout << "Max of each column in B = " << std::endl << B.colwise().maxCoeff() << std::endl << std::endl;

  // Find the L2-norm of a vector
  std::cout << "L2-norm of t: " << t.norm() << std::endl << std::endl;

  // Find the number of elements in a vector that is greater than a given value.
  std::cout << "Number of elements greater than 3 in B: " << (B.array() > 3.0).count() << std::endl << std::endl;

  return 0;
}

