#include <iostream>
#include <vector>
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

int max_point_banana(int n, vector<int> &banana)
{
    int max_point[n+1], res;
    max_point[0] = 0;
    max_point[1] = 0;
    max_point[2] = 0;

    for (int i = 3; i <= n; i++)
    {
        res = max(banana[i] + max_point[i-3], max_point[i-1]);
        max_point[i] = res;
    }

    return max_point[n];
}

int main()
{
    int n;
    vector<int> banana;
    get_input(n, banana);

    cout << max_point_banana(n, banana) << endl;

    return 0;
}