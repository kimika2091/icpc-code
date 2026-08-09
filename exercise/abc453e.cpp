#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<int MOD>
struct Mint {
    int v;
    Mint(long long _v = 0) {
        if (_v < 0) v = (_v % MOD + MOD) % MOD;
        else v = _v % MOD;
    }

    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = 1LL * v * o.v % MOD; return *this; }
    
    friend Mint qpow(Mint a, long long p) {
        Mint res = 1;
        for (; p; p >>= 1, a *= a) if (p & 1) res *= a;
        return res;
    }
    
    Mint inv() const { return qpow(*this, MOD - 2); }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    
    bool operator==(const Mint& o) const { return v == o.v; }
    bool operator!=(const Mint& o) const { return v != o.v; }

    friend ostream& operator<<(ostream& os, const Mint& a) { return os << a.v; }
    friend istream& operator>>(istream& is, Mint& a) { long long t; is >> t; a = Mint(t); return is; }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

const int MAXN = 2e5 + 5;
mint fac[MAXN], invFac[MAXN];

void precompute_combinations(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    invFac[n] = fac[n].inv();
    for (int i = n - 1; i >= 0; i--) invFac[i] = invFac[i + 1] * (i + 1);
}

mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invFac[k] * invFac[n - k];
}

void solve() {
	int n;
	cin >> n;
	vector <int> d1(n + 2), d2(n + 2);
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		d1[x]++, d1[y + 1]--;
		int l = max(x, n - y), r = min(y, n - x);
		if (l <= r) d2[l]++, d2[r + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		d1[i] += d1[i - 1];
		d2[i] += d2[i - 1];
	}
	mint ans(0);
	for (int i = 1; i < n; i++) {
		int can_a = d1[i] , can_b = d1[n - i], can_ab = d2[i];
		can_a -= can_ab;
		can_b -= can_ab;
		if (can_a + can_b + can_ab < n) continue;
		ans += C(can_ab, i - can_a);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	precompute_combinations(2e5);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
