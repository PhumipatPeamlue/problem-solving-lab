#include <iostream>
#include <algorithm>
using namespace std;

int bowls[301];

int find_max()
{
    int MAX = -1;
    for (int i = 1; i < 301; i++)
    {
        if (MAX < bowls[i]) MAX = bowls[i];
    }
    return MAX;
}

int main()
{
    int N, input;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        bowls[input]++;
    }

    cout << find_max() << endl;

    return 0;
}
