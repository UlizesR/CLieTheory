#ifndef SU3_HPP
#define SU3_HPP

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <complex>

namespace clt {

    class SU3 {
    private:
        Eigen::Matrix3cd M;  // Complex double 3x3 matrix

    public:
        SU3() : M(Eigen::Matrix3cd::Identity()) {}

        // Constructor from an Eigen::Matrix3cd
        SU3(const Eigen::Matrix3cd& mat);

        // Operator overloading for matrix multiplication
        SU3 operator*(const SU3& other) const;

        // Get the matrix
        Eigen::Matrix3cd toMatrix() const;

        // Print the matrix
        void printMatrix() const;

        // Check if a matrix is unitary
        static bool isUnitary(const Eigen::Matrix3cd& mat);
    };
}

#endif // SU3_HPP
