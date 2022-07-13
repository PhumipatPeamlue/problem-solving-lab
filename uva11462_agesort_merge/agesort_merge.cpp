#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int l, int m, int r) {
    int range_left = m-l+1;
    int range_right = r-m;
    int left[range_left];
    int right[range_right];

    for (int i = 0; i < range_left; i++) {
        left[i] = v[l+i];
    }
    for (int i = 0; i < range_right; i++) {
        right[i] = v[m+1+i];
    }

    int i = 0, j = 0, k = l;
    while (i < range_left && j < range_right) {
        if (left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        }
        else {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < range_left) {
        v[k] = left[i];
        i++; k++;
    }
    while (j < range_right) {
        v[k] = right[j];
        j++; k++;
    }

}

void merge_sort(vector<int> &v, int l, int r) {
    int m;
    if (l < r) {
        m = (l+r)/2;
        merge_sort(v, l ,m);
        merge_sort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int N;
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<int> v;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        merge_sort(v, 0, N-1);

        for (int i = 0; i < N; i++) {
            cout << v[i];
            if (i != N-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}