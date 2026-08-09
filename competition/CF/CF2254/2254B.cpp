#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cur = 1;
	for (int i = 1; i < n; i++) cur += s[i] != s[i - 1];
	int ans = cur;
	for (int i = 1; i < n - 1; i++) {
		ans = min(ans, cur - (s[i] != s[i - 1]) - (s[i + 1] != s[i]) + (s[i - 1] != s[i + 1]));
	}
	cout << ans << '\n';
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