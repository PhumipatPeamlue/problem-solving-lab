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
bool found_ore, found_tree;
int level_2 = 0, level_1 = 0, Count;

void explode(int r, int c)
{
    bool checkRow = 0 <= r && r <= N-1;
    bool checkCol = 0<= c && c <= M-1;

    if (!checkCol || !checkRow) return;
    if (grid[r][c] == '#') return;
    if (visited[r][c]) return;

    visited[r][c] = true;
    Count++;

    if (grid[r][c] == '$') found_ore = true;
    else if (grid[r][c] == '*') found_tree = true;

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
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                found_ore = false;
                found_tree = false;
                Count = 0;
                explode(i, j);

                if (found_ore && found_tree)
                {
                    level_2 += Count;
                }
                else if (found_ore || found_tree)
                {
                    level_1 += Count;
                }
            }
        }
    }

    cout << level_2 << " " << level_1 << endl;

    return 0;
}