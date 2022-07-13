#include <iostream>
#include <list>
using namespace std;

const int MAX = 1000000;

int N, M, tail[MAX];
list<int> l[MAX];

void get_input()
{
    cin >> N >> M;

    int x, y = 1;
    for (int i = 0; i < N; i++)
    {
        cin >> x;

        for (int j = y; j < y+x; j++)
        {
            l[y].push_back(j);
        }

        tail[y+x-1] = y;
        y += x;
    }
}

int main()
{
    get_input();

    // for (int i = 1; i < 15; i++)
    // {
    //     cout << i << ": ";
    //     for (list<int>::iterator it = l[i].begin(); it != l[i].end(); it++)
    //     {
    //         cout << *it << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i < 15; i++)
    // {
    //     cout << i << ": " << tail[i] << endl;
    // }

    list<int>::iterator it = l[1].begin(), tmp_it;

    char cmd;
    int num;
    for (int i = 0; i < M; i++)
    {
        cin >> cmd;
        if (cmd == 'F' && *it != l[1].back()) it++;
        else if (cmd == 'B' && *it != l[1].front()) it--;
        else if (cmd == 'C')
        {
            cin >> num;
            tmp_it = it;
            tmp_it++;

            int h, t;

            if (tail[num] != 0) 
            {
                h = tail[num];
                tail[num] = 0;
                l[h].reverse();
            }
            else
            {
                h = num;
                t = l[num].back();
                tail[t] = 0;
                
            }

            l[1].splice(tmp_it, l[h]);

            h = *tmp_it;
            t = l[1].back();
            tail[t] = h;
            l[h].splice(l[h].begin(), l[1], tmp_it, l[1].end());

            it++;
        }
        cout << *it << endl;
    }

    return 0;
}