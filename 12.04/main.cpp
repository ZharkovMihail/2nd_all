#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Point
{
public:
	int x;
	int y;
	string z;
	Point(int _x, int _y, string _z) : x(_x), y(_y), z(_z) {}
};

int main()
{
	int c=55;
	ofstream fout;
	string k= "kek";
	Point pnt(c, c, k);
	fout.open("File.txt", ofstream::app);
	if (!fout.is_open()){
			cout << "Ошибка при открытии" << endl;
		}else{
			cout << "открыт" << endl;
			fout.write(reinterpret_cast<char *>(&pnt), sizeof(Point));
		}
	fout.close();
	ifstream fin;
	fin.open("File.txt");
	if (!fin.is_open()){
			cout << "Ошибка при открытии" << endl;
		}else{
			cout << "открыт"<<endl;
			Point point;
			while(fin.read(reinterpret_cast<char*>(&point), sizeof(Point)))
			{
				cout <<  point.x << " " << point.y << " " << point.z << endl;
			}			
	}
	fin.close();
    return 0;
}
