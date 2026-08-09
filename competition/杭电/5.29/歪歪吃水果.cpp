#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	int c = (n / m) * (n / m);
	if ((a < m * m || b >= c) && (b < m * m || a >= c)) cout << "YES\n";
	else cout << "NO\n";
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
