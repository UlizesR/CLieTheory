#pragma once

#include <eigen3/Eigen/Geometry>  
#include <iostream>

namespace clt
{
    class SO3
    {
    private:
        Eigen::Quaterniond q;  // Quaternion representing the rotation

    public:
        // Construct from an Eigen quaternion
        SO3(const Eigen::Quaterniond& quat) : q(quat.normalized()) {}
        // Construct from axis-angle
        SO3(const Eigen::Vector3d& axis, double angle);

        // Operator overloading for multiplication
        SO3 operator*(const SO3& other) const;

        // Convert SO3 to a rotation matrix
        Eigen::Matrix3d toRotationMatrix() const;

        // Static method for interpolation between two SO3 elements
        static SO3 slerp(const SO3& a, const SO3& b, double t);

        // Print the quaternion
        void printQuaternion() const;

        // Print the rotation matrix
        void printMatrix() const;
    };
}