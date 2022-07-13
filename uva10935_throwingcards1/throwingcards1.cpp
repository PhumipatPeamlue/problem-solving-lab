#include <iostream>
#include <list>
using namespace std;

int main()
{
    int N;
    list<int> l;

    while (1)
    {
        l.clear();

        cin >> N;
        if (N == 0) break;

        for (int i = 1; i < N+1; i++)
        {
            l.push_back(i);
        }

        cout << "Discarded cards:";
        while (l.size() > 1)
        {
            cout << " " << l.front();
            if (l.size() > 2) cout << ",";
            l.pop_front();

            l.push_back(l.front());
            l.pop_front();
        }
        cout << endl;

        cout << "Remaining card: ";
        cout << l.front() << endl;
    }
    return 0;
}