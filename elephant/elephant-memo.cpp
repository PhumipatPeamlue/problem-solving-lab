#include <iostream>
#include <vector>
#include <map>
using namespace std;

void get_input(int &n, vector<int> &banana)
{
    cin >> n;
    banana.push_back(0);

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        banana.push_back(x);
    }
}

int max_point_banana(int n, vector<int> &banana, map<int,int> &memo)
{
    if (n < 3) return 0;
    auto query = memo.find(n);
    if (query != memo.end()) return query->second;

    int MAX = max_point_banana(n-3, banana, memo);
    int res = max(banana[n] + MAX, max_point_banana(n-1, banana, memo));

    memo[n] = res;
    return res;
}

int main()
{
    int n;
    vector<int> banana;
    map<int,int> memo;
    get_input(n, banana);

    cout << max_point_banana(n, banana, memo) << endl;
    
    return 0;
}
