#include <iostream>
#include <list>
using namespace std;

int main()
{
    string input;
    list<char> l;

    while (getline(cin, input))
    {
        l.clear();

        list<char>::iterator it = l.begin();

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '[') it = l.begin();
            else if (input[i] == ']') it = l.end();
            else l.insert(it, input[i]);
        }

        for (it = l.begin(); it != l.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}