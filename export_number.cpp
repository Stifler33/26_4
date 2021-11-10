#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main(){
    ifstream exportNumber("contacts_new.csv", ios::binary);
    map<string, string> fonNumber;
    while (!exportNumber.eof()){
        char sy;
        string fac;
        string *facPtr = &fac;
        //fac.c_str();
        char name[60];
        vector<char> vecName;
        char *ptr = &vecName;
        char number[60];
        bool text = true;
        exportNumber.getline(char *vecName, 50,',');
        exportNumber.getline(number, 50, '\r');
        exportNumber.ignore(1,'\n');
        fonNumber[name] = number;
    }
    for (auto &i : fonNumber){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}