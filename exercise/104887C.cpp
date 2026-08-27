#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int r, c, m, k;
	cin >> r >> c >> m >> k;
	if (k > min(r, c) || k > m || m > 1LL * k * max(r, c)) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	vector <vector<int>> g(r + 1, vector<int>(c + 1));
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		g[i][i] = 1;
		cnt++;
	}
	if (r < c) {
		for (int i = 1; i <= r && cnt < m; i++) {
			for (int j = 1; j <= c && cnt < m; j++) {
				if (!g[i][j]) {
					g[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	else {
		for (int j = 1; j <= c && cnt < m; j++) {
			for (int i = 1; i <= r && cnt < m; i++) {
				if (!g[i][j]) {
					g[i][j] = 1;
					cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << (g[i][j] ? '#' : '.');
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}