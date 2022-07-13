#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100010;

int N, M, K;
vector<int> adj[MAX];
int deg[MAX];

void get_input() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
}

bool discover[MAX];
int connected[MAX];

void dfs(int u, int x) {
    discover[u] = true;
    connected[u] = x;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!discover[v]) {
            dfs(v, x);
        }
    }
}

int main() {
    get_input();

    for (int i = 0; i < N; i++) {
        if (!discover[i]) {
            dfs(i, i);
        }
    }

    for (int i = 0; i < K; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        
        if (connected[s] == connected[t]) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}