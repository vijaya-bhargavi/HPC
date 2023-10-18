#include <omp.h>
#include <iostream>

int main()
{
    std::cout << omp_get_num_threads() << '\n';
    #pragma omp parallel for
     
    
}