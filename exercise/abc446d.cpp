#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	map <int, int> f;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		f[a[i]] = max(f[a[i]], f[a[i] - 1] + 1);
		mx = max(mx, f[a[i]]);
	}
	cout << mx << '\n';
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
