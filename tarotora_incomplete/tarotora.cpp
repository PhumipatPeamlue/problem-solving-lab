#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

int N, n, k;
vector<pair<int,int> > v;
map<pair<int,pair<int,int> >, int> memo;

void get_input() {
    cin >> n >> k;
    v.push_back(make_pair(0,0));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
}

int func(int i, int l, int r) {
    if (abs(l-r) > k) return -1;
    if (i == 0) return 0;
    pair<int,int> lr = make_pair(l,r);
    pair<int,pair<int,int> > p = make_pair(n,lr);
    auto query = memo.find(p);
    if (query != memo.end()) return query->second;

    int use_taro, use_tora;
    int a = func(i-1, l+1, r), b = func(i-1, l, r+1);
    if (a == -1) use_taro = INT32_MAX;
    else use_taro = v[i].first + a;
    if (b == -1) use_tora = INT32_MAX;
    else use_tora = v[i].second + b;

    int res = min(use_taro, use_tora);
    memo[p] = res;
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        v.clear();
        memo.clear();
        get_input();
        cout << func(n, 0, 0) << endl;
    }
}