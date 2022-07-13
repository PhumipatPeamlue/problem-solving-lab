#include <iostream>
using namespace std;

void change_dir(int &dir, int tid) {
    while (dir != tid) {
        cout << "R";
        dir = (dir+1)%4;
    }
    cout << "F";
}

int main() {
    string cmd;
    cin >> cmd;
    int dir = 3; // north = 3 east = 0 south = 1 west = 2

    for (int i = 0; i < cmd.length(); i++) {
        if (cmd[i] == 'N') {
            change_dir(dir, 3);
        }
        else if (cmd[i] == 'E') {
            change_dir(dir, 0);
        }
        else if (cmd[i] == 'S') {
            change_dir(dir, 1);
        }
        else if (cmd[i] == 'W') {
            change_dir(dir, 2);
        }
        else {
            dir = 3;
            cout << "Z";
        }
    }
    cout << endl;
    return 0;
}
