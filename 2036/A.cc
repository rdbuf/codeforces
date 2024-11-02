#include <algorithm>
#include <format>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdint>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using I = i64;
using UI = u64;

template<class K, class V> using M = std::map<K, V>;
template<class K, class V> using UM = std::unordered_map<K, V>;
template<class K> using S = std::set<K>;
template<class K> using US = std::unordered_set<K>;
template<class T> using vec = std::vector<T>;

#define F(NAME, LIMIT) for (int64_t NAME = 0; NAME < (LIMIT); ++NAME)
#define FT(TYPE, NAME, LIMIT) for (TYPE NAME = 0; NAME < (LIMIT); ++NAME)
#define INP(TYPE, NAME) TYPE NAME; cin >> NAME;
#define pb(X) push_back(X)
#ifdef DEBUG
	#define LOG(VAR) do { cerr << "DEBUG: " << #VAR << " = " << (VAR) << "\n"; } while (false)
#else
	#define LOG(VAR)
#endif

template<class T, class... Ts>
void print(const T& v, const Ts&... vs) {
	cout << v;
	((cout << " " << vs), ...);
	cout << "\n";
}

template<class T>
constexpr bool isin(const auto& x, const std::initializer_list<T>& values) {
	for (const auto& v : values) {
		if (x == v) {
			return true;
		}
	}
	return false;
}

template<class... Ts>
constexpr bool isin(const auto& x, const Ts&... values) {
	return ((x == values) || ... || false);
}

struct Data {
	// PUT INPUT DATA HERE
	vec<I> a;
	// END

	void read() {
		INP(I, n);
		F(j, n) {
			INP(I, x);
			a.pb(x);
		}
	}

	void solve([[maybe_unused]] I testN) {
		bool ok = true;
		F(i, a.size() - 1) {
			ok = ok && isin(abs(a[i] - a[i+1]), {5, 7});
		}
		print(ok ? "YES" : "NO");
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	INP(I, testN);
	F(_i, testN) {
		Data data{};
		data.read();
		data.solve(testN);
	}
}

/***** TEST CASES START *****
входные данныеСкопировать
8
2
114 109
2
17 10
3
76 83 88
8
38 45 38 80 85 92 99 106
5
63 58 65 58 65
8
117 124 48 53 48 43 54 49
5
95 102 107 114 121
10
72 77 82 75 70 75 68 75 68 75
выходные данныеСкопировать
YES
YES
YES
NO
YES
NO
YES
YES
*** TEST CASES END ****/
