#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100010;
typedef pair<int,int> ipair;

int N, R, layer[MAX];
vector<ipair> v;
vector<int> adj[MAX];
bool visited[MAX];

void make_graph()
{
    int x, y;
    
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x,y));

        for (int j = 0; j < i+2; j++)
        {
            int a = (v[j].first - v[i+2].first) * (v[j].first - v[i+2].first),
            b = (v[j].second - v[i+2].second) * (v[j].second - v[i+2].second),
            check = a + b;

            if (check <= R*R)
            {
                adj[j].push_back(i+2);
                adj[i+2].push_back(j);
            }

        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    layer[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                layer[v] = layer[u] + 1;
            }
        }
    }

}

int main()
{
    cin >> N >> R;

    if (R*R > 100*100) cout << 1 << endl;
    else
    {
        v.push_back(make_pair(0,0));
        v.push_back(make_pair(100,100));

        make_graph();

        layer[1] = -1;
        bfs(0);
        cout << layer[1] << endl;
    }
    
    return 0;
}