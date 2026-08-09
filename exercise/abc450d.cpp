#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= k;
	sort(a.begin() + 1, a.end());
	int ans = a[n] - a[1];
	for (int i = n; i > 1; i--) {
		ans = min(ans, a[i - 1] - (a[i] - k));
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
