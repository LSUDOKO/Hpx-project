#pragma once
#include <hpx/include/components.hpp>
#include <hpx/include/actions.hpp>
#include <vector>

namespace matrix_app { namespace server {
    // Component server implementation
    struct matrix_ops : hpx::components::component_base<matrix_ops> {
        // Parallel multiplication function logic
        std::vector<int> multiply(std::vector<int> const& A, std::vector<int> const& B, 
                                 std::size_t rowsA, std::size_t colsA, std::size_t colsB);

        // Define the action type for remote/asynchronous invocation
        HPX_DEFINE_COMPONENT_ACTION(matrix_ops, multiply, multiply_action);
    };
}}

// Register the action declaration for system-wide visibility
HPX_REGISTER_ACTION_DECLARATION(matrix_app::server::matrix_ops::multiply_action, matrix_multiply_action);
