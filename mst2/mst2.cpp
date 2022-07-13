#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 2e5;
int N, M;
vector<int> adj[MAX], weight[MAX];

void get_input() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        A--; B--;

        adj[A].push_back(B);
        adj[B].push_back(A);
        weight[A].push_back(W);
        weight[B].push_back(W);
    }
}

set<pair<int,int> > s;
int min_weight[MAX];
bool discover[MAX];

void init() {
    for (int i = 0; i < N; i++) {
        discover[i] = false;
        min_weight[i] = MAX;
    }
}

int prim() {
    init();

    int src = 0;
    min_weight[src] = 0;
    s.insert(make_pair(0,src));

    int result = 0;
    while (!s.empty()) {
        auto it = s.begin();
        int wu = it->first;
        int u = it->second;
        s.erase(it);

        if (discover[u]) continue;

        discover[u] = true;
        result += wu;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int wv = weight[u][i];

            if (!discover[v] && min_weight[v] > wv) {
                min_weight[v] = wv;
                s.insert(make_pair(wv,v));
            }
        }
    }
    return result;
}

int main() {
    get_input();

    cout << prim() << endl;
    return 0;
}