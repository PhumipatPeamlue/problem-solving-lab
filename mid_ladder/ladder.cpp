#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void get_input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

int main() {
    get_input();

    int now = -1;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        now += x;
        if (now > N-1) break;
        now += v[now];
    }
    if (now < 0) cout  << 0;
    else if (now > N-1) cout << N;
    else cout << now+1;
    cout << endl;
    return 0;
}