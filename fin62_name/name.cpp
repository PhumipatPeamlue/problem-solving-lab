#include <iostream>
#include <string>
using namespace std;

string name;
string str;

void get_input() {
    cin >> name >> str;
}

int count_name() {
    int i = 0, Count = 0;
    for (int j = 0; j < str.size(); j++) {
        if (name[i] == str[j]) {
            i = (i+1)%name.size(); 
            if (i == 0) Count++;
        }
    }
    return Count;
}

int main() {
    get_input();
    cout << count_name() << endl;

    return 0;
}