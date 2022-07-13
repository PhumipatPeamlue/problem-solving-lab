#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> water_height;

void get_input() {
    cin >> N;
    water_height.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        water_height.push_back(x);
    }
}

int main() {
    get_input();
    int Count = 0;
    for (int i = 1; i <= N; i++) {
        int res = water_height[i-1] - water_height[i];
        if (res > 10) {
            if (res*10 > 700) Count += 700;
            else Count += res*10;
        }
    }
    cout << Count << endl;
    return 0;
}
