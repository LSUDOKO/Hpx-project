#include "matrix_ops.hpp"
#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>

namespace matrix_app { namespace server {
    std::vector<int> matrix_ops::multiply(std::vector<int> const& A, std::vector<int> const& B, 
                                         std::size_t rowsA, std::size_t colsA, std::size_t colsB) {
        std::size_t rowsB = colsA;
        std::vector<int> R(rowsA * colsB);

        // Parallelize the outer loop using hpx::execution::par
        hpx::experimental::for_loop(hpx::execution::par, 0, rowsA, [&](auto i) {
            for (std::size_t j = 0; j < colsB; ++j) {
                int sum = 0;
                for (std::size_t k = 0; k < rowsB; ++k) {
                    sum += A[i * colsA + k] * B[k * colsB + j];
                }
                R[i * colsB + j] = sum;
            }
        });
        return R;
    }
}}

// Boilerplate for component module and factory registration
HPX_REGISTER_COMPONENT_MODULE();
typedef hpx::components::component<matrix_app::server::matrix_ops> matrix_ops_type;
HPX_REGISTER_COMPONENT(matrix_ops_type, matrix_ops);
HPX_REGISTER_ACTION(matrix_app::server::matrix_ops::multiply_action, matrix_multiply_action);
