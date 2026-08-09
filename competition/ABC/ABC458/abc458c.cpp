#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			ans += min(i, n - i - 1) + 1;
		}
		// cout << ans << '\n';
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