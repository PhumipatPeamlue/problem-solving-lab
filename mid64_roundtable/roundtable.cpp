#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void get_input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

const int MAX = 500010;
int range[MAX];

int solve() {
	int Max = 1;

	for (int i = 1; i < N+1; i++) {
		int x = i - v[i-1];
		if (x < 0) {
			x = N + x;
		}
		range[x]++;

		if (Max < range[x]) {
			Max = range[x];
		}
	}

	return Max;
}

int main() {
	

	get_input();

	cout << solve() << endl;
	return 0;
}