#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long N, A, B;
vector<long long> v;
void get_input() {
    cin >> N >> A >> B;
    long long x;
    for (long long i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());    
}

long long binsrh_upper(long long left, long long right, long long val) {
    if (right >= left) {
        long long mid = (left+right) / 2;
        if (v[mid] == val) {
            while (mid != N-1 && v[mid+1] == val) {
                mid++;
            }
            return mid;
        }
        else if ((mid == N-1 && v[mid] < val) || (v[mid] < val && v[mid+1] > val)) {
            return mid;
        }
        
        if (v[mid] > val) {
            return binsrh_upper(left, mid-1, val);
        }
        else {
            return binsrh_upper(mid+1, right, val);
        }
    }
    return -1;
}

long long binsrh_lower(long long left, long long right, long long val) {
    if (right >= left) {
        long long mid = (left+right) / 2;
        if (v[mid] == val) {
            while (mid != left && v[mid-1] == val) {
                mid--;
            }
            return mid;
        }
        else if ((mid == left && v[mid] > val) || (v[mid] > val && v[mid-1] < val)) {
            return mid;
        }

        if (v[mid] > val) {
            return binsrh_lower(left, mid-1, val);
        }
        else {
            return binsrh_lower(mid+1, right, val);
        }
    }
    return -1;
}

int main() {
    get_input();
    
    long long count = 0;
    for (long long i = 0; i < N-1; i++) {
        long long upper_b = binsrh_upper(i+1, N-1, B-v[i]),
        lower_b = binsrh_lower(i+1, N-1, abs(A-v[i]));
        
        long long x = upper_b - lower_b + 1;
        if (x > 0) {
            count += x;
        }
    }
    cout << count << endl;
    return 0;
}
