#include <iostream>
#include <list>
using namespace std;

list<int> l[100010];

int main()
{
    int N;

    cin >> N;

    char cmd;
    int x, y;
    
    for (int i = 0; i < N; i++)
    {
        cin >> cmd >> x >> y;
        if (cmd == 'N')
        {
            l[y].push_back(x);
        }
        else
        {
            l[y].splice(l[y].end(), l[x]);
        }
    }

    for (int i = 1; i < 100010; i++)
    {
        for (auto it = l[i].begin(); it != l[i].end(); it++)
        {
            cout << *it << endl;
        }
    }

    return 0;
}
