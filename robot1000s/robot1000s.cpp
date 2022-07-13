#include <iostream>
using namespace std;

int main()
{
    string cmd;
    int lost_cmd;
    cin >> cmd >> lost_cmd;

    int count_N = 0, 
    count_S = 0,
    count_E = 0,
    count_W = 0;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i] == 'N') count_N++;
        else if (cmd[i] == 'S') count_S++;
        else if (cmd[i] == 'E') count_E++;
        else count_W++;
    }

    int MIN = min(count_N, count_S) + min(count_E, count_W);
    
    cout << (cmd.size() - MIN - abs(lost_cmd - MIN)) * 2 << endl;

    return 0;
}
