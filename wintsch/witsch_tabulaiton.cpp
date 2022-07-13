#include <iostream>
#include <vector>
using namespace std;

const int MAXINT = 2000;
typedef pair<int,int> ipair;

int N, best_val[MAXINT];
vector<ipair> work;
vector<int> weight, best_ele[MAXINT];


void get_input() {
    cin >> N;
    work.push_back(make_pair(0,0));
    weight.push_back(0);

    for (int i = 0; i < N; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        work.push_back(make_pair(s,t));
        weight.push_back(w);
    }
}

int main() {
    get_input();

    for (int i = 1; i <= N; i++) {
        int j = i-1;
        while (j > 0) {
            if (work[j].second <= work[i].first) break;
            j--;
        }
        int a = weight[i] + best_val[j], b = best_val[i-1];
        if (a >= b) {
            best_val[i] = a;
            best_ele[i] = best_ele[j];
            best_ele[i].push_back(i);
        }
        else {
            best_val[i] = b;
            best_ele[i] = best_ele[i-1];
        }
    }
    cout << best_val[N] << endl;
    cout << best_ele[N].size() << endl;
    for (auto it = best_ele[N].begin(); it != best_ele[N].end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
