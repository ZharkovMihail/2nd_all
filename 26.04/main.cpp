#include <regex>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;
int main(){
	string str;
	ifstream fin("in.txt");
	regex regex("http:.*");
	list<string> adresses;
	int c=0;
	while (!fin.eof()){
		fin >> str;
		if (regex_match(str.begin(), str.end(), regex)){
			str.insert(4, "s");
		}
		adresses.push_front(str);
		c++;
	}
	fin.close();
	ofstream fout("out.txt");
	for (int i = 1; i < c; i++)
	{
		fout << adresses.front();
		adresses.pop_front();
	}
	return 0;
	fout.close();
}