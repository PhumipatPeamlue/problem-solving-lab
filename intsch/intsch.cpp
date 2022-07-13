#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair <int,int> > v;


int main () {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;

        v.push_back(make_pair(t, s));

    }

    sort(v.begin(), v.end());

    int Count = 1;
    int check = v.begin()->first;
    for (auto it = v.begin()+1; it != v.end(); it++) {
        if (check <= it->second ) {
            check = it->first;
            Count++;
        }
    }

    cout << Count << endl;


    return 0;
}