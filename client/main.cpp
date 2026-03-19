#include <hpx/hpx_main.hpp> 
#include <hpx/include/components.hpp>
#include <hpx/iostream.hpp>
#include "../components/matrix_ops.hpp"

int main() {
    std::size_t N = 100;
    std::vector<int> A(N * N, 1), B(N * N, 2);

    // Create a new instance of the matrix_ops component
    hpx::id_type here = hpx::find_here();
    hpx::future<hpx::id_type> comp_id_future = hpx::new_<matrix_app::server::matrix_ops>(here);
    hpx::id_type comp_id = comp_id_future.get();

    // Invoke the multiplication action asynchronously
    matrix_app::server::matrix_ops::multiply_action multiply;
    hpx::future<std::vector<int>> result_future = hpx::async(multiply, comp_id, A, B, N, N, N);

    // Wait for the result and print (printing the first element)
    std::vector<int> R = result_future.get();
    hpx::cout << "Parallel Matrix Multiplication complete. Element(0,0): " << R[0] << std::endl;

    return 0;
}
