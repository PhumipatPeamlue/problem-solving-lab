#include <iostream>
#include <cmath>
using namespace std;

int R, L;

bool check_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= ceil(sqrt(n)); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    cin >> R >> L;

    int Count = 0;
    for (int i = R; i <=L; i++) {
        if (i+2 <= L && check_prime(i) && check_prime(i+2)) {
            Count++;
        }
    }

    cout << Count << endl;
    return 0;
}