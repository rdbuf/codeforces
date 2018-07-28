#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	// vector<char> a(n); for (auto& x : a) cin >> x;
	vector<char> a(26);
	for (int i = 0; i < n; ++i) {
		char ch; cin >> ch;
		a[ch - 'a'] = 1;
	}
	int sum = 0;

	int i = 0, taken = 0;
	while (i < 26 && taken < k) {
		if (!a[i]) {
			++i;
			continue;
		}
		sum += i + 1;
		i += 2;
		taken += 1;
	}
	if (taken < k) cout << -1;
	else cout << sum;
}