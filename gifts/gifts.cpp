#include <iostream>
using namespace std;

int main()
{
    int N, input, res = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input > 0) res += input;
    }

    cout << res << endl;

    return 0;
}