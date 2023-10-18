all: mandel_omp

mandel_omp: mandel_omp.c pngwriter.c
	gcc -o $@ -I/opt/homebrew/include/libpng16 -O3 $^ -L/opt/homebrew/lib -lpng

clean:
	rm -rf mandel_omp

