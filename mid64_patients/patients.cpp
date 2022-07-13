#include <iostream>
using namespace std;

int N;

void get_input(int current, int *res) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int patients, days;
        cin >> patients >> days;
        for (int j = current; j < current+days; j++) {
            if (j <= N) res[j] += patients;
            else break;
        }
    }
}

void print(int *res) {
    for (int i = 1; i <= N; i++) {
        cout << res[i] << endl;
    }
} 

int main() {
    cin >> N;
    int res[N+1];
    for (int i = 1; i <= N; i++) {
        res[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        get_input(i, res);
    }

    print(res);

    return 0;
}
