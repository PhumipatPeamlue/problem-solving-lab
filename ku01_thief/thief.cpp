#include <iostream>
using namespace std;

int N, K, T;

void get_input()
{
    cin >> N >> K >> T;
}

int find_thief()
{
    int start = 0, count = 1;

    while (1)
    {
        start = (start + K) % N;

        if (start == 0) return count;
        else if (start == T-1)
        {
            return count+1;
        }

        count++;
    }
}

int main()
{
    get_input();
    int res = find_thief();
    cout << res << endl;

    return 0;
}