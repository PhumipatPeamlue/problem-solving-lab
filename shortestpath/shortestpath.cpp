#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000000;
typedef pair<int,int> ipair;

int N, M;
vector<int> adj[MAX], weight[MAX];

void get_input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
}

bool discovered[MAX];
int min_weight[MAX];
priority_queue<ipair, vector<ipair>, greater<ipair> > heap;

void init() {
    for (int i = 0; i < N; i++) {
        discovered[i] = false;
        min_weight[i] = MAX;
    }
}

int dijkstra(int src) {
    init();
    heap.push(make_pair(0,src));
    min_weight[src] = 0;

    while (!heap.empty()) {
        ipair p = heap.top();
        int wu = p.first, u = p.second;
        heap.pop();
        
        if (discovered[u]) {
            continue;
        }
        discovered[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int wv = weight[u][i], v = adj[u][i];

            if (min_weight[v] > wv + wu) {
                min_weight[v] = wv + wu;

                if (!discovered[v]) {
                    heap.push(make_pair(min_weight[v],v));
                }
            }
        }
    }
    return min_weight[N-1];
}

int main() {
    get_input();
    int ans = dijkstra(0);
    if (ans == MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    cout << endl;

    return 0;
}