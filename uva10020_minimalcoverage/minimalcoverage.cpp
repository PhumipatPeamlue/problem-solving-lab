#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Start, End;
vector<pair<int,int> > v, ans;

int cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

void get_input() {
    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        v.push_back(make_pair(a,b));
    }
}

void print(vector<pair<int,int> > &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void init() {
    v.clear();
    ans.clear();
}

int main() {

    cin >> N;
    while (N != 0) {
        init();
        Start = 0;

        cin >> End;
        get_input();
        sort(v.begin(), v.end(), cmp);

        while (Start < End) {
            int i;
            for (i = 0; i < v.size(); i++) {
                if (v[i].first <= Start && Start < v[i].second) {
                    Start = v[i].second;
                    ans.push_back(v[i]);
                    break;
                }
            }
            if (i == v.size()) break;
        }
        if (Start < End) cout << 0 << endl;
        else {
            cout << ans.size() << endl;
            print(ans);
        }

        N--;
        if (N != 0) cout << endl;
    }
    return 0;
}