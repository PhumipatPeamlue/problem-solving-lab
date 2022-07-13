#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1000;
typedef pair<int,int> ipair;

int N, M = 0;
vector<ipair> pos, pair_node;
vector<pair<double,int> > weight_pair;

void get_input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back(make_pair(x,y));

        for (int j = 0; j < i; j++) {
            int x1 = pos[j].first, y1 = pos[j].second;
            int x2 = pos[i].first, y2 = pos[i].second;
            double W = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

            pair_node.push_back(make_pair(j,i));
            weight_pair.push_back(make_pair(W,M));
            M++;
        }
    }
}

vector<int> parent, Rank;

int find_parent(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void union_find(int pu, int pv) {
    if (Rank[pu] < Rank[pv]) {
        parent[pu] = pv;
    }
    else if (Rank[pv] < Rank[pu]) {
        parent[pv] = pu;
    }
    else {
        parent[pv] = pu;
        Rank[pu]++;
    }
}

double kruskal() {

    for (int i = 0; i < N; i++) {
        parent.push_back(i);
        Rank.push_back(0);
    }

    sort(weight_pair.begin(), weight_pair.end());

    double result = 0;
    int Count = 0;
    for (int i = 0; i < M; i++) {
        int index = weight_pair[i].second;

        int u = pair_node[index].first;
        int v = pair_node[index].second;

        int pu = find_parent(u);
        int pv = find_parent(v);

        if (pu != pv) {
            union_find(pu, pv);
            result += weight_pair[i].first;
            Count++;
            if (Count == N-2) break;
        }
    }
    return result;
}

int main() {
    get_input();
    cout.precision(10);
    cout << kruskal() << endl;
    return 0;
}