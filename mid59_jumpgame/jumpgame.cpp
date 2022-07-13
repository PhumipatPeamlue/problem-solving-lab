#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int N, power;
vector<int> grid[MAX];

void get_input()
{
    cin >> N >> power;

    int x;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> x;
            grid[i].push_back(x);
        }
    }
}

bool visited[MAX][MAX];
bool find_exit = false;

void explode(int r, int c, int ph)
{
    bool checkRow = 0<=r && r<=N-1, checkCol = 0<=c && c<=N-1;
    if (!checkCol || !checkRow) return;

    int h = grid[r][c];
    if (h - ph > power) return;

    if (visited[r][c]) return;
    visited[r][c] = true;

    if (r == N-1 && c == N-1)
    {
        find_exit = true;
        return;
    }

    explode(r+1, c, grid[r][c]);
    explode(r-1, c, grid[r][c]);
    explode(r, c+1, grid[r][c]);
    explode(r, c-1, grid[r][c]);
}

int main()
{
    get_input();

    explode(1, 0, grid[0][0]);
    explode(0, 1, grid[0][0]);

    if (find_exit) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}