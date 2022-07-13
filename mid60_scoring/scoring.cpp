#include <iostream>
using namespace std;

const int MAX = 101;

int N, M;
int best_score[MAX], count_exam[MAX];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int no, score, res;
        cin >> no >> score;
        count_exam[no]++;
        res = max(best_score[no],score);
        best_score[no] = res;
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
        if (count_exam[i] <= 5) total += best_score[i];
    }
    cout << total << endl;

    return 0;
}
