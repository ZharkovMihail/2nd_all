#include<cstdio>
#include<cmath>
#include"quaternions.h"
#include"func.h"

int main()
{
	quaternions a(1, 2, 3, 4), b(10, 100, 1000, 1);
	a.print("a= ");
	b.print("b= ");
	printf("abs a: %.4f\n", sqrt(a.abs()));
	printf("abs b: %.4f\n", sqrt(b.abs()));
	(a + b).print("a + b: ");
	(a - b).print("a - b: ");
	(a * b).print("a * b: ");
	(b * a).print("b * a: ");
	return 0;		
}