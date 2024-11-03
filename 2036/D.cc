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
#include <numeric>

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

template<class K, class V> using treemap = std::map<K, V>;
template<class K, class V> using ht = std::unordered_map<K, V>;
template<class K> using sorted_set = std::set<K>;
template<class K> using hs = std::unordered_set<K>;
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

auto Sum(auto it1, auto it2) {
	return std::accumulate(it1, it2, 0);
}

auto Product(auto it1, auto it2) {
	return std::accumulate(it1, it2, 1, [](auto acc, auto x) { return acc * x; });
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

constexpr bool within(const auto& x, const auto& lb, const auto& ub) {
	return lb <= x && x <= ub;
}

struct Data {
	// PUT INPUT DATA HERE
	// ht<I, I> cnt;
	vec<I> d;
	// END

	void read() {
		INP(I, n);
		INP(I, m);
		F(i, n) { INP(string, x); for (char c : x) d.pb(c - '0'); }
		I nlayers = min(n,m) / 2;
		vec<I> ld;
		I cnt = 0;
		LOG(nlayers);
		F(layer, nlayers) {
			LOG(layer);
			F(offset, m - layer*2) { I idx = layer*m + layer + offset; ld.pb(d[idx]); LOG(idx); }
			F(offset, n - layer*2 - 2) { I idx = (layer+1+offset)*m + m-1 - layer; ld.pb(d[idx]); LOG(idx); }
			F(offset, m - layer*2) { I idx = (n - layer)*m - layer - offset - 1; ld.pb(d[idx]); LOG(idx); }
			F(offset, n - layer*2 - 2) { I idx = (n - layer - 2-offset)*m + layer; ld.pb(d[idx]); LOG(idx); }

			LOG(n); LOG(m);
			I sz = ld.size();
			F(i, ld.size()) {
				LOG(ld[i]);
				if (ld[i]==1&&ld[(i+1)%sz]==5&&ld[(i+2)%sz]==4&&ld[(i+3)%sz]==3) cnt+=1;
			}
			ld.clear();
		}
		print(cnt);
	}

	void solve([[maybe_unused]] I testN) {
		LOG(testN);
		cout.flush();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	INP(I, testN);
	F(_i, testN) {
		Data data{};
		data.read();
		data.solve(_i);
	}
}

/***** TEST CASES START *****
входные данныеСкопировать
8
2 4
1543
7777
2 4
7154
8903
2 4
3451
8888
2 2
54
13
2 2
51
43
2 6
432015
512034
4 4
5431
1435
5518
7634
6 4
5432
1152
4542
2432
2302
5942
выходные данныеСкопировать
1
1
0
1
0
2
2
2
*** TEST CASES END ****/
