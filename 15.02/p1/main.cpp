#include <cstdio>
#include "complex_num.h"

int main() {
	complex_num a;
	FILE *fileget, *filetake;
	fileget = fopen("infile.txt" , "r");
	fscanf(fileget , "%d%d", &a.re, &a.im);
	filetake = fopen("outfile.txt" , "w");
	a.countAbs();
	fprintf(filetake, "%.5lf", a.Abs);
	return 0;
}