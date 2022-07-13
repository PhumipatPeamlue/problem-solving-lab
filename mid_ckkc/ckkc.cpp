#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int x;

int main() {
    cin >> x;

    int Count = 0;
    int xx;
    while (1) {
        cin >> xx;
        if (xx == 0) break;
        Count++;
    }

    int res = x - 2558 + 1 - Count;
    if (res%2 == 0) {
        cout << 'C';
    }
    else {
        cout << 'K';
    }
    cout << endl;

    return 0;
}