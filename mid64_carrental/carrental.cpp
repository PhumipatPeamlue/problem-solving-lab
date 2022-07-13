#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int K, N;
vector<int> C, P, W, product;

void get_input() {
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        C.push_back(x);
        P.push_back(y);
        W.push_back(z);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        product.push_back(x);
    }
}

int main() {
    get_input();

    vector<int> v;

    for (int i = 0; i < K; i++) {
        int sum_w = 0, Count = 1;
        bool over_w = false;
        for (int j = 0; j < N; j++) {
            if (product[j] > W[i]) {
                over_w = true;
                break;
            }
            else {
                if (sum_w + product[j] > W[i]) {
                    Count++;
                    sum_w = 0;
                }
                sum_w += product[j];
            }
        }
        if (!over_w) {
            v.push_back(C[i]+Count*P[i]);
        }
    }

    sort(v.begin(), v.end());
    cout << v.front() << endl;

    return 0;
}