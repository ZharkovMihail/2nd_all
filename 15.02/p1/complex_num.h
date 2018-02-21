#include <cmath>

struct complex_num {
	int im;
	int re;
	double Abs;
	void countAbs() {
		Abs = sqrt(im * im + re * re);
	}		
};