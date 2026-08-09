#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector <int> up(n + 1), down(n + 1), d(n + 1);
	iota(d.begin(), d.end(), 0);
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (down[x] == 0) d[x] = 0;
		else {
			up[down[x]] = 0;
		}
		up[y] = x;
		down[x] = y;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int t = d[i];
		while (t) {
			cnt++;
			t = up[t];
		}
		cout << cnt << ' ';
	}
	cout << '\n';
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
