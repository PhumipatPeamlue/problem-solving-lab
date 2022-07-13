#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX = 100010;

int N, M, S, T;

vector<int> adj[MAX], target;
int layer[MAX];

list<int> queue;
bool discoverd[MAX];


void get_input() {
    cin >> N >> M >> S >> T;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x;

    for (int i = 0; i < S; i++) {
        cin >> x;
        x--;
        queue.push_back(x);
        layer[x] = 0;
        discoverd[x] = true;
    }
    for (int i = 0; i < T; i++) {
        cin >> x;
        x--;
        target.push_back(x);
    }
}

void bfs(int src) {
    while(!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            if (!discoverd[v]) {
                discoverd[v] = true;
                queue.push_back(v);
                layer[v] = layer[u] + 1;
            }
        }
    }
}

void mincost_storage_to_factory() {
    for (vector<int>::iterator it = target.begin(); it != target.end(); it++) {
        cout << layer[*it] << endl;
    }
} 

int main() {
    get_input();
    bfs(queue.front());
    mincost_storage_to_factory();
    return 0;
}