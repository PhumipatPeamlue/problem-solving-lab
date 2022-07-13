#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int N;
    cin >> N;

    int who[5], power[5];
    for (int i = 1 ; i < 5; i++) {
        int n, max = 0, k;
        for(int j = 1; j < N+1; j++) {
            cin >> n;
            if (n > max) {
                max = n;
                who[i] = j + N*(i-1);
                power[i] = max;
            }
        }
       
        
        if (i == 2 || i == 4) {
            if (power[i-1] > power[i]) {
                swap(who[i-1], who[i]);
                swap(power[i-1], power[i]);
            }
        }
    }
    if (power[2] < power[4]) {
        swap(who[2], who[4]);
    }
    cout << who[2] << " " << who[4] << " " << who[1] << " " << who[3] << endl;
    
    return 0;   
}
