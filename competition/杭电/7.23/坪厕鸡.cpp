#include<bits/stdc++.h>
using namespace std;
#define int long long

using PII = pair<int, int>;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a(m + 1), b(m + 1), c(m + 1);
	vector <int> ans(m + 1);
	for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i];
	priority_queue <PII, vector<PII>, greater<PII>> judging; 
	for (int i = 1; i <= m; i++) {
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}