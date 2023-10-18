#include "omp.h"
int main(){
    #pragma omp parallel{
        int id = get_thread_num();
        printf("%d", id);
        printf("%d", id);
        return 0;
    }

}