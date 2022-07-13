#include <iostream>
#include <vector>
using namespace std;

const int MAXINT = 2000;

int N;
vector<int> nums;

void get_input() {
    cin >> N;
    nums.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

vector<int> func() {
    vector<int> seq[MAXINT], longest_seq;
    for (int i = 1; i <= N; i++) {
        seq[i].push_back(nums[i]);
        for (int j = 1; j < i; j++) {
            if (nums[j] < nums[i] && seq[j].size()+1 >= seq[i].size()) {
                seq[i] = seq[j];
                seq[i].push_back(nums[i]);
            }
        }
        if (longest_seq.size() <= seq[i].size()) longest_seq = seq[i];
    }
    return longest_seq;
}

int main() {
    get_input();
    vector<int> res = func();
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
