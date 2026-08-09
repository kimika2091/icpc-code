#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	auto check = [&](int x) -> bool {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] < x) {
				cnt += (x - a[i] + i - 1) / i;
			}
			if (cnt > k) return false;
		}
		return true;
	};
	int L = 1, R = 2e18, mid, ans;
	while (L <= R) {
		mid = L + R >> 1;
		if (check(mid)) {
			ans = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
