all: dotProduct

dotProduct: dotProduct.cpp walltime.h
	
	g++ -o $@ -I/opt/homebrew/include/libpng16 -O3 $^ -L/opt/homebrew/lib -lpng


clean:
	rm -rf dotProduct
