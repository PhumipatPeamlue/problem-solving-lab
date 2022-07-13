#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200;

int N , M;
vector<char> grid[MAX];

void get_input()
{
    cin >> N >> M;

    char x;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> x;
            grid[i].push_back(x);
        }
    }
}

int Count = 0;

void explode(int r, int c, char dir)
{
    if (c == 0 && dir == 'l') dir = 'r';
    if (c == N-1 && dir == 'r') dir = 'l';

    if (grid[r][c] == '@') return;
    else if (grid[r][c] == '$')
    {
        Count++;
        return;
    }
    else if (grid[r][c] == '.') explode(r+1, c, dir);
    else if (dir == 'l') explode(r, c-1, dir);
    else explode(r, c+1, dir);

}

int main()
{
    get_input();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                explode(0, i, 'l');
            }
            else{
                explode(0, i, 'r');
            }
        }
    }

    cout << Count << " ";

    Count = 0;
    int MAX = -1;

    for (int i = 0; i < M-1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char rem = grid[i][j];
            grid[i][j] = '.';
            Count = 0;
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    if (l == 0)
                    {
                        explode(0, k, 'l');
                    }
                    else{
                        explode(0, k, 'r');
                    }
                }
            }
            grid[i][j] = rem;
            if (MAX < Count) MAX = Count;
        }
    }

    cout << MAX << endl;



    return 0;
}