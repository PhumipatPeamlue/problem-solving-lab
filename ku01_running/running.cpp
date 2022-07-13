#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int N, K;
vector <int> v;

void get_input()
{
    cin >> N >> K;

    int x;
    for (int i = 0; i < N; i++) 
    {
        cin >> x;
        v.push_back(x);
    }
}

int find_min_value()
{
    return *min_element(v.begin(), v.end());
}

void print_end_race()
{
    int MIN = find_min_value();
    int count = 0;
    
    for (int i = 0; i < N; i++)
    {
        if ((ull)v[i]*(K-1) < (ull)MIN*K) count++;
    }
    
    cout << count << endl;
}

int main()
{
    get_input();
    print_end_race();

    return 0;
}