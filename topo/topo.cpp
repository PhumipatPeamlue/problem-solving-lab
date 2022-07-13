#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX = 2e5;

int N, M, Count = 0;
vector<int> adj[MAX];
bool discover[MAX], is_degIn[MAX];

void get_input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        if (!is_degIn[v]) {
            is_degIn[v] = true;
            Count++;
        }
    }
}

list<int> l;
bool loop = false;

void dfs(int u) {
    discover[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!discover[v]) {
            dfs(v);
        }
    }
    l.push_back(u);
}

int main() {
    get_input();

    if (Count == N) cout << "no";
    else {
        for (int i = 1; i < N+1; i++) {
            if (!discover[i]) {
                dfs(i);
            }
        }

        while (!l.empty()) {
            if (l.front() == l.back()) {
                cout << l.back();
            }
            else {
                cout << l.back() << " ";
            }
            l.pop_back();
        }
    }
    cout << endl;
    return 0;
}