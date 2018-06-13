using namespace std;
#include <cmath> 
#include <stdio.h>
#include <fstream>
#include <iostream>
//#include <utility>
class dot {
public:
	double x;
	double y;
	dot(double a, double b) {
		this->x = a;
		this->y = b;
	}
	dot() {}
};
class line {
public:
	//Ax+By+C=0; 
	double A;
	double B;
	double C;
	double x1, x2, y1, y2;
	line() { };
	line(dot d1, dot d2) {
		this->A = d1.y - d2.y;
		this->B = d2.x - d1.x;
		this->C = d1.x*d2.y - d2.x*d1.y;
		this->x1 = d1.x;
		this->x2 = d2.x;
		this->y1 = d1.y;
		this->y2 = d2.y;
	}
	bool check(dot f) {
		int x = f.x;
		int y = f.y;
		if (((x<this->x1) && (x>this->x2) && (y<this->y1) && (y>this->y2)) || ((x>this->x1) && (x<this->x2) && (y<this->y1) && (y>this->y2)) || ((x<this->x1) && (x>this->x2) && (y>this->y1) && (y<this->y2)) || ((x>this->x1) && (x<this->x2) && (y>this->y1) && (y<this->y2))) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Pair {
public:
	double first;
	double second;
	Pair(){}
	Pair(double a, double b) {
		first = a;
		second = b;
	}
};
class point {
public:
	int angle = 15;
	double x, y;
	Pair vec[5];
	double vectorx, vectory;
	point(double a, double b,double v1,double v2) {
		x = a;
		y = b;
		vectorx = v1;
		vectory = v2;
		for (int i = -2; i < 3; i++) {
		vec[i + 2].first = -sin(angle*i)*v2 + cos(angle*i)*v1;
		vec[i + 2].second = cos(angle*i)*v2 + sin(angle*i)*v1;
		}
		vec[2].first = v1;
		vec[2].second = v2;
	}	
};

double det(double a, double b, double c, double d) {
	return a * d - b * c;
}
const double L = 1.7;
class perc {
public:
	int nInput;
	int nOutput;
	double *arrin,*arrout;
	perc(int a, int b) 
	{
		nInput = a;
		nOutput = b;
		arrin = new double[nInput];
		arrout = new double[nOutput];
		for (int i = 0; i<nInput; i++)
		{
			arrin[i] = 0;
		}
		for (int i = 0; i<nOutput; i++)
		{
			arrout[i] = 0;
		}
	}
	void changeinw(double a,int n) {
		this->arrin[n] = a;
	}
	void changeoutw(double a, int n) {
		this->arrout[n] = a;
	}
	double sum(double *arr) {
		double res = 0;
		for (int i = 0; i < nInput; i++) {
			res+=arr[i] * arrin[i];
		}
		return res;
	}
	~perc()
	{
		delete[](arrout);
		delete[](arrin);
	}

};

const double EPS = 1e-9;
dot cross(point p, line pl,int i) {
	line m(dot(p.x, p.y), dot(p.x + p.vec[i].first, p.y + p.vec[i].second));
	double zn = det(m.A, m.B, pl.A, pl.B);
	if (abs(zn) < EPS)
		return dot(p.x, p.y);
	dot res;
	res.x = -det(m.C, m.B, pl.C, pl.B) / zn;
	res.y = -det(m.A, m.C, pl.A, pl.C) / zn;
	return res;
}
double fAct(double x) {
	return 1 / (1 + exp( -x ));
}

int main(){
	int amountdotS = 5;
	dot *dotS=new dot[amountdotS]{
		dot(7.9,6.15),dot(9.28,8.23),dot(11.48,8.11),dot(12.48,6.2),dot(10.24,4.31),
	};
	int amountdotB = 9;
	dot *dotB = new dot[amountdotB]{
		dot(4,8),dot(6.45,10.7),dot(11.26,11.33),dot(16,10),dot(18.62,6.35),dot(16.44,2.33),dot(11.58,0.75),dot(6.5,1.15),dot(4.05,4.23),
	};

	line *lineS = new line[amountdotS];
	for (int i = 0; i < amountdotS-1; i++) {
		lineS[i] = line(dotS[i], dotS[i + 1]);
	}
	lineS[amountdotS - 1] = line(dotS[0], dotS[amountdotS - 1]);
	line *lineB = new line[amountdotB];
	for (int i = 0; i < amountdotB - 1; i++) {
		lineB[i] = line(dotB[i], dotB[i + 1]);
	}
	lineB[amountdotB - 1] = line(dotB[0], dotB[amountdotB - 1]);

	point car(10.28, 2.53, 2.18, 1.04);
	//car.vectorx = 2.18;
	//car.vectory = 1.04;

	double *column1 = new double[5];
	double *column2 = new double[3];
	double *column3 = new double[3];
	double *column4 = new double[5];

	double distance[5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < amountdotB; j++) {
			dot cros = cross(car, lineB[j], i);
			if (lineB[j].check(cros)) {
				double f = car.vec[i].first / (cros.x - car.x);
				if (f > 0) {
					distance[i] = sqrt(pow((cros.x - car.x), 2) + pow((cros.y - car.y), 2));
				}
			}
		}
		for (int k = 0; k < amountdotS; k++) {
			dot cros = cross(car, lineS[k], i);
			if (lineS[k].check(cros)) {
				double f = car.vec[i].first / (cros.x - car.x);
				if (f > 0) {
					double p = sqrt(pow((cros.x - car.x), 2) + pow((cros.y - car.y), 2));
					if (p < distance[i]) {
						distance[i] = p;
					}
				}
			}
		}
	}

	int Id[5];
	for (int i = 0; i < 5; i++) {
		Id[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		if (distance[i] < L) {
			Id[i] = 1;
			i = 10;
		}
		else {
			if (i == 4) {
				cout << "stop";
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		column1[i] = fAct(distance[i]);
	}
	perc *perc1 = new perc[3]{
		perc(5, 3),perc(5, 3),perc(5, 3),
	};
	for (int i = 0; i < 3; i++) {
		column2[i] = fAct(perc1[i].sum(column1));
	}
	
	perc *perc2 = new perc[3]{
		perc(3, 5),perc(3, 5),perc(3, 5),
	};
	for (int i = 0; i < 3; i++) {
		column3[i] = fAct(perc2[i].sum(column2));
	}
	perc *perc3 = new perc[5]{
		perc(3,0),perc(3, 0),perc(3, 0),perc(3, 0),perc(3, 0),
	};
	double maxx=-2;
	int h;
	for (int i = 0; i < 5; i++) {
		column4[i] = fAct(perc3[i].sum(column3));
		if (maxx < column4[i]) {
			maxx = column4[i];
			h = i;
		}
	}
	int O[5];
	double summis[3];
	summis[0] = summis[1] = summis[2] = 0;
	int mistake[5];
	double neww;

	for (int i; i < 5; i++) {
		if (h != i) {
			O[i] = 0;
		}
		else {
			O[i] = 1;
		}
		mistake[i] = (O[i] - Id[i])*column4[i]*(1 - column4[i]);
		for (int j; j < 3; j++) {			
			neww = perc3[i].arrin[j] - mistake[i];
			perc3[i].changeinw(neww, j);
			perc2[j].changeoutw(neww, i);
		}
	}

	double mistake2[3];
	for (int i; i < 3; i++) {
		double x = 0;
		for (int j; j < 5; j++) {
			x += perc2[i].arrout[j] * mistake[j];
		}
		mistake2[i] = x*(1- column3[i] )*column3[i];
	}
	for (int i; i < 3; i++) {
		for (int j; j < 3; j++) {
			neww=perc2[i].arrin[j] - mistake2[i] * column3[i];
			perc2[i].changeinw(neww, j);
			perc1[j].changeoutw(neww, i);
		}
	}

	double mistake3[3];
	for (int i; i < 3; i++) {
		double x = 0;
		for (int j; j < 3; j++) {
			x += perc1[i].arrout[j] * mistake2[j];
		}
		mistake3[i] = x * (1 - column2[i])*column2[i];
	}
	for (int i; i < 3; i++) {
		for (int j; j < 5; j++) {
			neww = perc1[i].arrin[j] - mistake3[i] * column2[i];
			perc1[i].changeinw(neww, j);
		}
	}
	ofstream fout;
	fout.open("myfile.txt");
	fout << "kek";
	fout.close();
	cout << "+";
	delete[]dotB;
	delete[]dotS;
	return 0;
}