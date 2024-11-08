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
template<class K> using set = std::unordered_set<K>;
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
constexpr bool isin2(const auto& x, const Ts&... values) {
	return ((x == values) || ... || false);
}

struct Data {
	// PUT INPUT DATA HERE
	// ht<I, I> cnt;
	vec<I> cnt;
	// END

	void read() {
		INP(I, n);
		INP(I, k);
		cnt.resize(k+1);
		F(j, k) {
			INP(I, b);
			INP(I, c);
			cnt[b]+=c;
		}
		std::nth_element(cnt.begin()+1, cnt.end()-min(n,k), cnt.end());
		auto sum = Sum(cnt.end() - min(n,k), cnt.end());
		print(sum);
	}

	void solve([[maybe_unused]] I testN) {
		LOG(testN);
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
4
3 3
2 6
2 7
1 15
1 3
2 6
2 7
1 15
6 2
1 7
2 5
190000 1
1 1000
выходные данныеСкопировать
28
15
12
1000
*** TEST CASES END ****/
