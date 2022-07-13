#include <iostream>
#include <algorithm>
using namespace std;

int L, N;

int main() {
    cin >> L >> N;
    int *arr = new int[2*L];

    int A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        for (int j = (A+0.5)*2; j < B*2; j++) {
            arr[j]++;
        }
    }
    sort(arr, arr+2*L);
    
    cout << arr[2*L-1] << endl;
    return 0;
}