#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXINT  = 2000;

int N;
vector<int> nums;
map<int,vector<int> > memo;

void get_input() {
    cin >> N;
    nums.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

vector<int> func(int n, vector<int> &max) {
    auto query = memo.find(n);
    if (query != memo.end()) return query->second;

    vector<int> res;
    res.push_back(nums[n]);
    for (int i = 1; i < n; i++) {
        vector<int> check = func(i, max);
        if (nums[i] < nums[n] && check.size()+1 >= res.size()) {
            res = check;
            res.push_back(nums[n]);
        }
    }
    if (max.size() <= res.size()) max = res;
    memo[n] = res;
    return res;
}

int main() {
    get_input();
    vector<int> seq, longest_seq;
    seq = func(N, longest_seq);

    cout << longest_seq.size() << endl;
    for (auto it = longest_seq.begin(); it != longest_seq.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
