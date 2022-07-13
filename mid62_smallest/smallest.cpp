#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, Q;
vector<int> v_minrange;

int binsrh(int left , int right, int val) {
    if (left <= right) {
        int mid = (left+right) / 2;

        if (mid == 0 && val > v_minrange[mid]) {
            return 0;
        }
        else if (mid == N-1 && val < v_minrange[mid]) {
            return N;
        }
        
        if (v_minrange[mid] == val) {
            while (mid != N-1 && v_minrange[mid+1] == val) {
                mid++;
            }
            return mid+1;
        }
        else if (val > v_minrange[mid] && val < v_minrange[mid-1]) {
            return mid;
        }

        if (v_minrange[mid] > val) {
            return binsrh(mid+1, right, val);
        }
        else {
            return binsrh(left, mid-1, val);
        }
    }
    return -1;
}

void get_input() {
    cin >> N >> Q;
    int MIN, x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (i == 0) {
            MIN = x;
            v_minrange.push_back(MIN);
        }
        else {
            if (x < MIN) {
                MIN = x;
            }
            v_minrange.push_back(MIN);
        }
    }
}

void printAns() {
    int T, jk;
    for (int i = 0; i < Q; i++) {
        cin >> T >> jk;
        if (T == 1) {
            cout << v_minrange[jk-1] << endl;
        }
        else {
            cout << binsrh(0, N-1, jk) << endl;
        }
    }
}

int main() {
    get_input();
    printAns();
    return 0;
}
