#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

int N, M;
vector<char> grid[MAX];

void get_input()
{
    cin >> N >> M;

    char x;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> x;
            grid[i].push_back(x);
        }
    }   
}

bool visited[MAX][MAX];
bool find_exit = false;


void explode(int r, int c)
{
    bool checkRow = 0 <= r && r < N-1,
    checkCol = 0 <= c && c < M-1;

    if (!checkRow || !checkCol) return;
    if (grid[r][c] == '#' || grid[r+1][c] == '#' || grid[r][c+1] == '#' || grid[r+1][c+1] == '#') return;
    if (visited[r][c]) return;

    visited[r][c] = true;

    if (r+1 == N-1)
    {
        find_exit = true;
        return;
    }

    explode(r-1, c);
    explode(r+1, c);
    explode(r, c-1);
    explode(r, c+1);

}

int main()
{
    get_input();

    for (int i = 0; i < N; i++)
    {
        explode(0, i);
        if (find_exit) break;
    }

    if (find_exit) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}