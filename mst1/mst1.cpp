#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1e5;
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

const int INFINITY = MAX;
bool discover[MAX];
int min_weight[MAX];

void init() {
    for (int i = 0; i < N; i++) {
        discover[i] = false;
        min_weight[i] = INFINITY;
    }
}

int prim() {
    init();

    min_weight[0] = 0;

    int result = 0, Count = 0;
    while (Count != N) {
        int u = -1, wu = INFINITY;
        for (int i = 0; i < N; i++) {
            if (!discover[i] && min_weight[i] < wu) {
                wu = min_weight[i];
                u = i;
            }
        }
        discover[u] = true;
        result += wu;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (weight[u][i] < min_weight[v]) {
                min_weight[v] = weight[u][i];
            }
        }
        Count++;
    }
    return result;
}

int main() {
    get_input();

    cout << prim() << endl;
    return 0;
}