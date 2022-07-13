#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000000;
typedef pair<int,int> ipair;

int N, M;
vector<int> adj[MAX], cost[MAX], type[MAX];
vector<ipair> extra_road;

void get_input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C, S;
        cin >> A >> B >> C >> S;
        A--; B--;

        adj[A].push_back(B);
        adj[B].push_back(A);
        cost[A].push_back(C);
        cost[B].push_back(C);
        type[A].push_back(S);
        type[B].push_back(S);

        if (S == 1) {
            int x = min(A,B);
            int y = max(A,B);
            extra_road.push_back(make_pair(x,y));
        }
    }
}

bool discovered[MAX];
int min_cost[MAX];
priority_queue<ipair, vector<ipair>, greater<ipair> > heap;

void init() {
    for (int i = 0; i < N; i++) {
        discovered[i] = false;
        min_cost[i] = MAX;
    }
}

int dijskra(int src) {
    int MIN = MAX, round;

    if (extra_road.empty()) {
        round = 1;
    }
    else {
        round = extra_road.size();
    }

    vector<pair<int,int> >::iterator it_vec;
    for (int i = 0; i < round; i++) {
        init();
        min_cost[src] = 0;
        heap.push(make_pair(0,src));
        while (!heap.empty()) {
            ipair p = heap.top();
            int wu = p.first, u = p.second;
            heap.pop();

            if (discovered[u]) {
                continue;
            }
            discovered[u] = true;

            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                int wv = cost[u][j];
                int t = type[u][j];

                if (t == 1) {
                    int x = min(u,v);
                    int y = max(u,v);
                    
                    if (x != extra_road[i].first || y != extra_road[i].second) {
                        continue;
                    }
                }

                if (min_cost[v] > wv + wu) {
                    min_cost[v] = wv + wu;
                    if (!discovered[v]) {
                        heap.push(make_pair(min_cost[v],v));
                    }
                }
            }
        }

        if (min_cost[N-1] < MIN) {
            MIN = min_cost[N-1];
        }
    }

    return MIN;
}

int main() {
    get_input();

    int MIN = dijskra(0);
    
    if (MIN == MAX) {
        cout << -1;
    }
    else {
        cout << MIN;
    }
    cout << endl;

    return 0;
}