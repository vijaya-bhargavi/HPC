#include "walltime.h"
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int N = 2000000000;
  double up = 1.00000001;
  double Sn = 1.00000001;
  int n;
  /* allocate memory for the recursion */
  double *opt = (double *)malloc((N + 1) * sizeof(double));

  if (opt == NULL)
    die("failed to allocate problem size");

  double time_start = wall_time();
  // TODO: YOU NEED TO PARALLELIZE THIS LOOP
  int x=0;
  double new_Sn = Sn;
  #pragma omp parallel for firstprivate(Sn, x) lastprivate(Sn) schedule(guided)
  for (n = 0; n <= N; ++n) {
    if(x==0 || x!=n){
      opt[n] = new_Sn * pow(up, n);
      Sn = opt[n] * up;
    } 
    else {
      opt[n] = Sn;
      Sn *= up;
    }
    x = n + 1;
  }

  printf("Parallel RunTime   :  %f seconds\n", wall_time() - time_start);
  printf("Final Result Sn    :  %.17g \n", Sn);

  double temp = 0.0;
  for (n = 0; n <= N; ++n) {
    temp += opt[n] * opt[n];
  }
  printf("Result ||opt||^2_2 :  %f\n", temp / (double)N);
  printf("\n");

  return 0;
}
