#include <iostream>
#include "src/SO3.hpp"
#include "src/SU3.hpp"  

int main() {
    // Define initial and final orientations as axis-angle rotations
    // clt::SO3 initialOrientation(Eigen::Vector3d(1, 0, 0), M_PI / 4);  // Rotate 45 degrees around the x-axis
    // clt::SO3 finalOrientation(Eigen::Vector3d(1, 0, 0), M_PI / 2);    // Rotate 90 degrees around the y-axis

    // // Interpolate between the initial and final orientations
    // double interpolationParameter = 0.5;  // Halfway between initial and final
    // clt::SO3 interpolatedOrientation = clt::SO3::slerp(initialOrientation, finalOrientation, interpolationParameter);

    // // multiply two rotations
    // clt::SO3 result = initialOrientation * finalOrientation;

    // // Print the rotation matrices
    // // printMatrix(result.toRotationMatrix());
    // result.print();
    try {
        Eigen::Matrix3cd mat1;
        mat1 << 1, 0, 0,
                0, 1, 0,
                0, 0, 1;

        Eigen::Matrix3cd mat2;
        mat2 << std::complex<double>(1/std::sqrt(2), 0), std::complex<double>(0, 1/std::sqrt(2)), std::complex<double>(0, 0),
            std::complex<double>(1/std::sqrt(2), 0), std::complex<double>(0, -1/std::sqrt(2)), std::complex<double>(0, 0),
            std::complex<double>(0, 0), std::complex<double>(0, 0), std::complex<double>(1, 0);


        clt::SU3 su3_identity;
        clt::SU3 su3_custom(mat2);

        std::cout << "Identity SU(3) matrix:\n";
        su3_identity.printMatrix();


        std::cout << "Custom SU(3) matrix:\n";
        su3_custom.printMatrix();

        // Example of multiplication
        clt::SU3 result = su3_identity * su3_custom;
        std::cout << "Result of multiplication:\n";
        result.printMatrix();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
