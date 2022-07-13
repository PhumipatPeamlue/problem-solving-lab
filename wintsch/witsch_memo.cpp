#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXINT = 2000;
typedef pair<int,int> ipair;

int N;
vector<ipair> work;
vector<int> weight, best[MAXINT];
map<int,int> memo;

void get_input() {
    cin >> N;
    work.push_back(make_pair(0,0));
    weight.push_back(0);

    for (int i = 0; i < N; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        work.push_back(make_pair(s,t));
        weight.push_back(w);
    }
}

int func(int n) {
    if (n < 1) return 0;
    auto query = memo.find(n);
    if (query != memo.end()) return query->second;

    int i = n-1;
    while (i > 0) {
        if (work[i].second <= work[n].first) break;
        i--;
    }

    int a = weight[n] + func(i), b = func(n-1), res = max(a,b);
    if (a >= b) {
        best[n] = best[i];
        best[n].push_back(n);
    }
    else best[n] = best[n-1];

    memo[n] = res;
    return res;
}

int main() {
    get_input();
    cout << func(N) << endl << best[N].size() << endl;
    for (auto it = best[N].begin(); it != best[N].end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
