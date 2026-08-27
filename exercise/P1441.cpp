#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (auto &x : a) cin >> x;
	int ans = 0;
	auto calc = [&](int mask) -> int {
		bitset <2001> dp;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) {
				dp |= dp << a[i];
			}
		}
		return static_cast<int>(dp.count()) - 1;
	};
	int cur = (1 << m) - 1, full = (1 << n) - 1;
	if (m == 0) {
		cout << calc(full) << '\n';
		return;
	}
	while (cur <= full) {
		ans = max(ans, calc(full ^ cur));
		int lb = cur & -cur;
		int r = cur + lb;
		cur = r + ((cur ^ r) / lb >> 2); 
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}