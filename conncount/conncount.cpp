#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100010;

int N, M;
vector<int> adj[MAX];

void get_input()
{
    cin >> N >> M;

    int u, v;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool visited[MAX];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

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
            }
        }
        
    }

}

int main()
{
    get_input();

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}