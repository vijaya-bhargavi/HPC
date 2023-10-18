all: recur_seq recur_omp

recur_seq: recur_seq.c
	gcc-13 -O3 $^ -o $@

recur_omp: recur_omp.c
	gcc-13 -O3 -fopenmp $^ -o $@ -lm

clean:
	rm -rf recur_seq recur_omp

