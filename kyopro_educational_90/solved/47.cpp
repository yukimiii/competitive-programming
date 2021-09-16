#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

/**
 * @brief Rolling-Hash(ローリングハッシュ)
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 * @docs docs/rolling-hash.md
 */
struct RollingHash
{
	static const uint64_t mod = (1ull << 61ull) - 1;
	using uint128_t = __uint128_t;
	vector<uint64_t> power;
	const uint64_t base;

	static inline uint64_t add(uint64_t a, uint64_t b)
	{
		if ((a += b) >= mod)
			a -= mod;
		return a;
	}

	static inline uint64_t mul(uint64_t a, uint64_t b)
	{
		uint128_t c = (uint128_t)a * b;
		return add(c >> 61, c & mod);
	}

	static inline uint64_t generate_base()
	{
		mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);
		return rand(mt);
	}

	inline void expand(size_t sz)
	{
		if (power.size() < sz + 1)
		{
			int pre_sz = (int)power.size();
			power.resize(sz + 1);
			for (int i = pre_sz - 1; i < sz; i++)
			{
				power[i + 1] = mul(power[i], base);
			}
		}
	}

	explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

	vector<uint64_t> build(const string &s) const
	{
		int sz = s.size();
		vector<uint64_t> hashed(sz + 1);
		for (int i = 0; i < sz; i++)
		{
			hashed[i + 1] = add(mul(hashed[i], base), s[i]);
		}
		return hashed;
	}

	template <typename T>
	vector<uint64_t> build(const vector<T> &s) const
	{
		int sz = s.size();
		vector<uint64_t> hashed(sz + 1);
		for (int i = 0; i < sz; i++)
		{
			hashed[i + 1] = add(mul(hashed[i], base), s[i]);
		}
		return hashed;
	}

	uint64_t query(const vector<uint64_t> &s, int l, int r)
	{
		expand(r - l);
		return add(s[r], mod - mul(s[l], power[r - l]));
	}

	uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len)
	{
		expand(h2len);
		return add(mul(h1, power[h2len]), h2);
	}

	int lcp(const vector<uint64_t> &a, int l1, int r1, const vector<uint64_t> &b, int l2, int r2)
	{
		int len = min(r1 - l1, r2 - l2);
		int low = 0, high = len + 1;
		while (high - low > 1)
		{
			int mid = (low + high) / 2;
			if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
				low = mid;
			else
				high = mid;
		}
		return low;
	}
};
int main()
{
	int n;
	string s, t;
	string r, g, b;
	cin >> n;
	cin >> s >> t;
	REP(i, n)
	{
		if (s[i] == 'R')
		{
			r += 'R';
			g += 'B';
			b += 'G';
		}
		else if (s[i] == 'G')
		{
			r += 'B';
			g += 'G';
			b += 'R';
		}
		else if (s[i] == 'B')
		{
			r += 'G';
			g += 'R';
			b += 'B';
		}
	}
	ll ans = 0;
	RollingHash roll;
	auto rhr = roll.build(r);
	auto rhg = roll.build(g);
	auto rhb = roll.build(b);
	auto rht = roll.build(t);
	REP(i, n)
	{
		// cout << t.compare(n - 1 - i, i, r, 0, i) << endl;
		if (roll.query(rht, 0, i + 1) == roll.query(rhr, n - 1 - i, n) || roll.query(rht, 0, i + 1) == roll.query(rhg, n - 1 - i, n) || roll.query(rht, 0, i + 1) == roll.query(rhb, n - 1 - i, n))
		{
			ans++;
			// cout << i << endl;
		}
	}
	FOR(i, 1, n)
	{
		if (roll.query(rht, i, n) == roll.query(rhr, 0, n - i) || roll.query(rht, i, n) == roll.query(rhg, 0, n - i) || roll.query(rht, i, n) == roll.query(rhb, 0, n - i))
		{
			// cout << i << endl;
			ans++;
		}
		// 	if (t.compare(0, i + 1, r, n - i - 1, i + 1) == 0 || t.compare(0, i + 1, g, n - i - 1, i + 1) == 0 || t.compare(0, i + 1, b, n - i - 1, i + 1) == 0)
		// 		ans++;
	}

	// cout << r << endl;
	// cout << g << endl;
	// cout << b << endl;
	cout << ans << endl;
	return (0);
}
