#include <iostream>
#include <cmath>
using namespace std;

int N, a, b, R;

int pow2_distance(int x, int y) {
    return pow(a-x,2) + pow(b-y,2);
}

bool is_kidnap(int x, int y) {
    if (pow2_distance(x,y) <= pow(R,2)) return true;
    else return false;
}

int main() {
    int x, y, Count = 0;
    cin >> N >> a >> b >> R;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (is_kidnap(x,y)) Count++;
    }
    cout << Count << endl;
    return 0;
}