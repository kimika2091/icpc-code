#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class Info>
struct ST {
	int n, m;
	vector<Info> a;
	vector<vector<Info>> info;
	ST (const vector<Info>& p, int n) {
		ST::n = n;
		a = p;
		m = __lg(n) + 2;
		init();
	}

	void init() {
		info.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			info[i].resize(m);
		}

		for (int i = 1; i <= n; i++) {
			info[i][0] = a[i];
		}
		for (int j = 1; j < m; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i++) {
				info[i][j] = info[i][j - 1] + info[i + (1 << (j - 1))][j - 1];
			}
		}
	}

	Info query(int l, int r) {
		int k = __lg(r - l + 1);
		return info[l][k] + info[r - (1 << k) + 1][k];
	}
};


struct MAX {
	int x {0};
};

MAX operator+ (const MAX& a, const MAX& b) {
	MAX c;

	c.x = max(a.x, b.x);

	return c;
}

struct GCD {
	int x {0};
};

GCD operator+ (const GCD& a, const GCD& b) {
	GCD c;

	c.x = gcd(a.x, b.x);

	return c;
}

void solve() {
	int n, q;
	cin >> n >> q;

	vector<GCD> a(n + 1);
	vector<MAX> b(n + 1);

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = GCD(x);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[i] = MAX(x);
	}

	ST stg(a, n);
	ST stm(b, n);

	vector<vector<array<int, 3>>> line(n + 1);
	for (int i = 1; i <= n; i++) {
		int p = i;

		while (p > 0) {
			int cur = stg.query(p, i).x;
			int pl = p;
			int lo = 1, hi = p;
			while (lo <= hi) {
				int mid = lo + hi >> 1;
				if (stg.query(mid, i).x == cur) {
					pl = mid;
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}

			line[i].push_back({pl, p, cur});
			p = pl - 1;
		}
		reverse(line[i].begin(), line[i].end());
	}

	while (q--) {
		int L, R;
		cin >> L >> R;

		ll sum = 0, ans = 0;

		for (auto [l, r, v] : line[R]) {
			if (r < L) continue;
			int pl = max(l, L);
			int pr = r;

			int mx = stm.query(pl, pr).x;
			if (mx < sum) continue;
			int cnt = (mx - sum + v - 1) / v;
			sum += 1ll * cnt * v;
			ans += cnt;
		}

		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt = 1;
	cin >> tt;
	while (tt--) solve();

	return 0;
}