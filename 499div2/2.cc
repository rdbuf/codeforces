#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(100);
	for (int i = 0; i < m; ++i) {
		int t; cin >> t;
		a[t-1] += 1;
	}

	int solution = 0;
	for (int days = 1; days <= m / n; ++days) {
		int people_possible = 0;
		for (const auto& x : a) {
			people_possible += x / days;
		}
		if (people_possible >= n) solution = days;
	}
	cout << solution;
}