#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

void get_input()
{
    cin >> N;
    
    int x;
    v.push_back(0);

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
}

int find_round()
{
    bool get_their_own[N+1];
    int in_hand[N+1], tmp[N+1], count = 0, round = 1;

    for (int i = 1; i < N+1; i++)
    {
        get_their_own[i] = false;
        in_hand[i] = i;
    }

    while (1)
    {
        for (int i = 1; i < N+1; i++)
        {   
            tmp[v[i]] = in_hand[i];
            if (v[i] == in_hand[i] && get_their_own[v[i]] == false)
            {
                get_their_own[v[i]] = true;
                count++;
            }
        }

        if (count == N) break;

        for (int i = 1; i < N+1; i++)
        {
            in_hand[i] = tmp[i];
        }

        round++;
    }

    return round;
}

int main()
{
    get_input();
    cout << find_round() << endl;

    return 0;
}