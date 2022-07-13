#include <iostream>
#include <list>
using namespace std;

const int MAX = 300010;

int N;
list<int> l[MAX];
int line[MAX];

void print_necklace(int index)
{
    for (list<int>::iterator it = l[index].begin(); it != l[index].end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int create_line()
{
    int a, b;
    list<int>::iterator it;
    
    for (int i = 0; i < N-1; i++)
    {
        cin >> a >> b;

        if (line[a] == 0 && line[b] == 0)
        {
            line[b] = b;
            line[a] = b;

            l[b].push_back(b);
            l[b].push_back(a);
        }
        else if (line[a] == 0)
        {
            line[a] = line[b];
            
            it = l[line[b]].begin();
            while (1)
            {
                if (*it == b)
                {
                    it++;
                    break;
                }
                it++;
            }

            l[line[b]].insert(it, a);
        }
        else if (line[b] == 0)
        {
            line[b] = line[a];
            l[line[a]].push_front(b);
        }
        else
        {
            int rem = line[a];

            for (it = l[rem].begin(); it != l[rem].end(); it++)
            {
                line[*it] = line[b];
            }

            it = l[line[b]].begin();
            while (1)
            {
                if (*it == b)
                {
                    it++;
                    break;
                }
                it++;
            }
            l[line[b]].splice(it,l[rem]);
        }
    }
    return line[b];
}

int main()
{
    cin >> N;

    int i = create_line();
    print_necklace(i);
    
    return 0;
}