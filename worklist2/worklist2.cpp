#include <iostream>
#include <list>
using namespace std;

int N;
list<int> l;

void config_list() {
    char c;
    int n;
    auto it = l.begin();
    cin >> c >> n;
    if (c == 'A') {
        l.push_back(n);
    }
    else if (c == 'I') {
        l.push_front(n);
    }
    else if (c == 'D' && n <= l.size()) {
        advance(it, n-1);
        l.erase(it);
    }
}

void print_list() {
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        config_list();
    }
    print_list();
    return 0;
}

