#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long result = 0;

void merge(vector<int> &v, int l, int m, int r) {
    int nl = m-l+1;
    int nr = r-m;
    int left[nl];
    int right[nr];

    for (int i = 0; i < nl; i++) {
        left[i] = v[l+i];
    }
    for (int i = 0; i < nr; i++) {
        right[i] = v[m+1+i];
    }

    int i = 0, j = 0, k = l;
    while (i < nl && j < nr) {
        if (left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        }
        else {
            result += nl - i;

            v[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        v[k] = left[i];
        i++;
        k++;
    }
    while (j <nr) {
        v[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &v, int l, int r) {
    int m;
    if (l < r) {
        m = (l+r)/2;
        merge_sort(v, l, m);
        merge_sort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int N;
vector<int> v;
void get_input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

int main() {
    get_input();

    merge_sort(v, 0, N-1);

    cout << result << endl;

    return 0;
}