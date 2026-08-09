#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll x, y, z;
	cin >> x >> y;
	if (x * 2 < y) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
