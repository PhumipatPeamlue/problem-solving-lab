#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100010;

int N = 0, M;
vector<int> adj[MAX];
bool visited[MAX];
int team[MAX];

void init_adj()
{
    for (int i = 0; i < N; i++)
    {
        adj[i].clear();
    }

}

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

void init_bfs()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        team[i] = -1;
    }

}

bool check_bipartite(int src)
{
    init_bfs();
    queue<int> q;
    q.push(src);
    visited[src] = true;
    team[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            
            if (team[v] == -1)
            {
                team[v] = (team[u]+1)%2;
            }
            else if (team[v] == team[u])
            {
                return false;
            }

            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return true;
}

int main()
{
    int round;
    bool is_bipartite;
    cin >> round;

    for (int i = 0; i < round; i++)
    {
        init_adj();
        get_input();
        is_bipartite = check_bipartite(0);

        if (is_bipartite) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;
}