#include "backpack.h"
void quickSortR(les* a, int N) {
	long i = 0, j = N;
	double temp, p;
	p = a[N >> 1].value;
	les temp1;

	do {
		while (a[i].value < p) i++;
		while (a[j].value > p) j--;

		if (i <= j) {
			temp1 = a[i]; a[i] = a[j]; a[j] = temp1;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0) quickSortR(a, j);
	if (N > i) quickSortR(a + i, N - i);
}