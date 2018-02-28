#include <iostream>
#include <stdio.h>
#include "backpack.h"
#include "funk.h"
using namespace std;
int main() {
	int n,W;//n-колво вещей,W-обьем тары
	cin >> W;
	cin >> n;
	les *mas = new les[n];
	for (int i = 0; i < n; i++) {
		scanf( "%d%d", &mas[i].weight, &mas[i].cost);
		mas[i].value = mas[i].cost / mas[i].weight;
	}
	quickSortR(mas, n - 1);
	int finmax;
	for (int i = n-1; i >0; i--) {
		finmax = mas[i].weight;
		if (finmax <= W) {
			cout << mas[i].weight<<" ";
			W = W - finmax;
		}
	}
	return 0;
}