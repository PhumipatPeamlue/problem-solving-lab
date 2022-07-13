#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 110;

int N, M;
vector<int> adj[MAX];
int deg[MAX];

void get_input() {
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        deg[u]++;
    }
}

bool discover[MAX];
stack<int> st;

void init() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        deg[i] = 0;
        discover[i] = false;
    }
}

void dfs(int u) {
    discover[u] = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!discover[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

int main() {

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        init();

        get_input();

        for (int i = 0; i < N; i++) {
            if (!discover[i]) {
                dfs(i);
            }
        }

        while (1) {
            cout << st.top()+1;
            st.pop();
            if (!st.empty()) {
                cout << " ";
            }
            else {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}