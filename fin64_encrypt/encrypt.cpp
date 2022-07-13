#include <iostream>
#include <vector>
using namespace std;

int n, s;
int v[20], tmp[20];
int ans[4][5];

void get_input() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    if (n < 20) {
        for (int i = n; i < 20; i++) {
            v[i] = i-(n-1);
        }
    }
}

void encrypt() {

    for (int i = 0; i < 20; i++) {
        tmp[(i+s)%20] = v[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ans[i][j] = tmp[(5*i)+j];
        }
    }
}

int main() {

    get_input();
    
    encrypt();

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 4; i++) {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;


    return 0;
}