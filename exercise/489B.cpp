#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n, m;
	cin >> n;
	vector <int> a(n + 1),  c(105, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1, x; i <= m; i++) cin >> x, c[x] ++;
	sort(a.begin() + 1, a.end());
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[a[i] - 1]) ans ++, c[a[i] - 1] --;
		else if (c[a[i]]) ans ++, c[a[i]] --;
		else if (c[a[i] + 1]) ans ++, c[a[i] + 1] --;
	}
	cout << ans << endl;
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
