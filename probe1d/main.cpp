#include <iostream>
#include "probelib.h"
using namespace std;

int find_treasure(int a, int b) {
    int mid = (a+b)/2;
    
    if (a == b) return a;

    if (probe_check(a, mid)) {
        return find_treasure(a, mid);
    }
    else {
        return find_treasure(mid+1, b);
    }
}

int main() {
    int n = probe_init();
    
    int ans = find_treasure(0, n-1);

    probe_answer(ans);

    return 0;
}