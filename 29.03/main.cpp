
#include <iostream>
#include <fstream>
#include <map>
#include <string>
 
int main()
{
    setlocale(LC_ALL, "ru");
    using namespace std;
 
    string str;
    ifstream fin("in.txt");
 
    map<string, int> word;
 
    while (!fin.eof()){
    	fin>>str;
        word[str]++;
    }
    fin.close();
 
    map <string, int>::iterator it;
    ofstream fout("out.txt");
    for (it = word.begin(); it != word.end(); it++){
        fout << it->first;
        fout << ' ' << it->second << endl;
    }
    fout.close();
    return 0;
}