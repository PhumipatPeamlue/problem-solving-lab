#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, Q;
vector<int> price;
void get_input() {
    cin >> N >> Q;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        price.push_back(x);
    }
    sort(price.begin(), price.end());
}

int binsearch(int left, int right, int val) {
    if (right >= left) {
        int mid = (left + right) / 2;
        if ((mid == N-1 && price[mid] <= val) || 
        (price[mid] <= val && val < price[mid+1])) {
            return mid+1;
        }

        if (price[mid] < val) {
            return binsearch(mid+1, right, val);
        }
        else {
            return binsearch(left, mid-1, val);
        }
    }
    return -1;
}


int main() {
    get_input();
    int x, y;
    //     use upper_bound
    // for (int i = 0; i < Q; i++) {
    //     cin >> x >> y;
    //     auto it = upper_bound(price.begin(), price.end(), price[x-1]+y);
    //     cout << it-price.begin() << endl;
    // }

    //      use binary search
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << binsearch(0, N-1, price[x-1]+y) << endl;
    }
    return 0;
}
