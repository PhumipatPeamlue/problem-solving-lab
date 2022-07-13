#include <iostream>
using namespace std;

pair<int,int> findLocation(string &str)
{
    int x = 0, y = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'N') y++;
        else if (str[i] == 'E') x++;
        else if (str[i] == 'S') y--;
        else if (str[i] == 'W') x--;
        else x = 0, y = 0;
    }

    pair<int,int> location = make_pair(x,y);
    
    return location;
}

int main()
{
    string input;
    cin >> input;

    pair<int,int> location = findLocation(input);
    cout << location.first << " " << location.second << endl;

    return 0;
}