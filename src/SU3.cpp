#include "SU3.hpp"

namespace clt {

    // Constructor from an Eigen::Matrix3cd
    SU3::SU3(const Eigen::Matrix3cd& mat) {
        if (isUnitary(mat)) {
            M = mat;
        } else {
            throw std::invalid_argument("Matrix is not unitary");
        }
    }

    bool SU3::isUnitary(const Eigen::Matrix3cd& mat) {
        const double epsilon = 1e-6;
        Eigen::Matrix3cd identity = Eigen::Matrix3cd::Identity();

        // Check if the matrix is unitary:
        // U^dagger * U should equal the identity matrix, considering numerical precision.
        // U^dagger is the conjugate transpose of U.
        bool isUnitaryMatrix = (mat.adjoint() * mat - identity).norm() < epsilon;

        // Check if the determinant of U is exactly 1 (within numerical precision).
        // This is important because SU(n) matrices must have a determinant of 1.
        bool hasUnitDeterminant = std::abs(mat.determinant()) - 1 < epsilon;

        return isUnitaryMatrix && hasUnitDeterminant;
    }


    // Operator overloading for matrix multiplication
    SU3 SU3::operator*(const SU3& other) const {
        return SU3(M * other.M);
    }

    // Get the matrix
    Eigen::Matrix3cd SU3::toMatrix() const {
        return M;
    }

    // Print the matrix
    void SU3::printMatrix() const {
        std::cout << M << '\n' << std::endl;
    }
}
