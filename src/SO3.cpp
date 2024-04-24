#include "SO3.hpp"

namespace clt
{
    SO3::SO3(const Eigen::Vector3d& axis, double angle)
    {
        q = Eigen::AngleAxisd(angle, axis.normalized());
    }

    SO3 SO3::operator*(const SO3& other) const
    {
        return SO3(q * other.q);
    }

    Eigen::Matrix3d SO3::toRotationMatrix() const
    {
        return q.toRotationMatrix();
    }

    SO3 SO3::slerp(const SO3& a, const SO3& b, double t)
    {
        return SO3(Eigen::Quaterniond::Identity().slerp(t, a.q.inverse() * b.q) * a.q);
    }

    void SO3::printQuaternion() const 
    {
        std::cout << q.w() << " " << q.x() << "i " << q.y() << "j " << q.z() << "k \n" << std::endl;
    }

    void SO3::printMatrix() const
    {
        std::cout << q.toRotationMatrix() << '\n' << std::endl;
    }
}