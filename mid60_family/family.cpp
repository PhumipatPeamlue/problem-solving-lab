#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, M;
vector<int> v;
// list<int> l;

void read_input() {
    cin >> N >> M;
    int x;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            v.push_back(0);
        }
        else {
            cin >> x;
            v.push_back(x);
        }
    }
}

void check_family() {
    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;

        if (A == 1 || B == 1) {
            cout << 1 << endl;
        }
        else {
            int tmp1 = v[A-1];
            while (tmp1 != B && tmp1 != 1) {
                tmp1 = v[tmp1-1];
            }
            int tmp2 = v[B-1];
            while (tmp2 != A && tmp2 != 1) {
                tmp2 = v[tmp2-1];
            }
            if (tmp1 == B) {
                cout << B << endl;
            }
            else if (tmp2 == A) {
                cout << A << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        
    }
}

// void printl() {
//     for (auto it = l.begin(); it != l.end(); it++) {
//         cout << *it << endl;
//     }
// }

int main() {
    read_input();

    check_family();
    
    return 0;
}
