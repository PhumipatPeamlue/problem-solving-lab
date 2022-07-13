#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long N;
vector<long> vec_x, vec_y;

int main() {
    cin >> N;

    for (long i = 0; i < N; i++) {
        long x, y;
        cin >> x >> y;

        long x_new = x+y, y_new = y-x;

        vec_x.push_back(x_new);
        vec_y.push_back(y_new);
    }

    sort(vec_x.begin(), vec_x.end());
    sort(vec_y.begin(), vec_y.end());

    long xc, yc;
    if (N%2 == 0) {
        xc = (vec_x[(N/2)-1] + vec_x[N/2]) / 2;
        yc = (vec_y[(N/2)-1] + vec_y[N/2]) / 2;
    }
    else {
        xc = vec_x[N/2];
        yc = vec_y[N/2];
    }

    long res = 0;
    for (long i = 0; i < N; i++) {
        res = res + abs(vec_x[i]-xc) + abs(vec_y[i]-yc);
    }

    cout << res << endl;
    return 0;
}
