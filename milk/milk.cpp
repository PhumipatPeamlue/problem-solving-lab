#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int N, Q;
vector<int> Parent, Rank;

void init() {
    for (int i = 0; i < N; i++) {
        Parent.push_back(i);
        Rank.push_back(0);
    }
}

int find_parent(int u) {
    while (u != Parent[u]) {
        u = Parent[u];
    }
    return u;
}

void union_find(int pu, int pv) {
    if (Rank[pu] < Rank[pv]) {
        Parent[pu] = pv;
    }
    else if (Rank[pv] < Rank[pu]) {
        Parent[pv] = pu;
    }
    else {
        Parent[pv] = pu;
        Rank[pu]++;
    }
}



int main() {
    cin >> N >> Q;

    init();
    
    for (int i = 0; i < Q; i++) {
        char x;
        int u, v;
        cin >> x >> u >> v;
        u--; v--;

        int pu = find_parent(u);
        int pv = find_parent(v);

        if (x == 'c') {
            union_find(pu, pv);
        }
        else if (pu == pv) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }

    }
    return 0;
}