#include <iostream>
#include <list>

using namespace std;

int N, M;
list<int> l;

void get_input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        l.push_back(x);
    }
}

int main() {
    get_input();

    auto it = l.begin();
    for (int i = 0; i < M; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            it = l.begin();
        }
        else if (cmd == 2) {
            if (*it == l.back()) it = l.begin();
            else it++;
        }
        else if (cmd == 3) {
            int x;
            cin >> x;
            l.insert(it,x);
        }
        else {
            int x;
            cin >> x;
            if (*it == l.back()) {
                l.push_back(x);
            }
            else {
                it++;
                l.insert(it,x);
                advance(it,-2);
            }
        }
    }

    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}