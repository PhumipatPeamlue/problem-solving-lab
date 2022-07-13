#include <iostream>
using namespace std;

const int MAX_LEVELS = 1000;

struct data {
    int distance;
    int gift;
    int bonus_point;
};

typedef struct data data_t;

data_t requirement[MAX_LEVELS];


int N, M;

void get_input() {
    cin >> N >> M;
    int a, b, c;

    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        requirement[i].distance = a;
        requirement[i].gift = b;
        requirement[i].bonus_point = c;
    }

    requirement[N].distance = 0;
    requirement[N].gift = 0;
    requirement[N].bonus_point = 0;
}

int current_level() {
    int a, b, c, level = 1;
    bool check_a = false, check_b = false, check_c = false;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (!check_a && a >= requirement[level].distance) check_a = true;
        if (!check_b && b >= requirement[level].gift) check_b = true;
        if (!check_c && c >= requirement[level].bonus_point) check_c = true;
        if (check_a && check_b && check_c) {
            check_a = false; check_b = false; check_c = false;
            if (level != N) level++;
        }
    }
    return level;
}

int main() {
    get_input();
    cout << current_level() << endl;
    return 0;
}