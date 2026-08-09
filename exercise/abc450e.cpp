#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string x, y;
	cin >> x >> y;
	vector <ll> len;
	ll a = x.size(), b = y.size(), d = 0;
	len.push_back(a);
	len.push_back(b);
	while (d <= 1e18) {
		d = b + a;
		a = b;
		b = d;
		len.push_back(d);
	}
	int m = len.size(), len_x = x.size(), len_y = y.size(); 
	vector <array<ll, 26>> cnt(m), pre_x(len_x + 1), pre_y(len_y + 1);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < len_x; j++) {
			pre_x[j + 1][i] = pre_x[j][i] + (x[j] - 'a' == i);
		}
		for (int j = 0; j < len_y; j++) {
			pre_y[j + 1][i] = pre_y[j][i] + (y[j] - 'a' == i);
		}
	}
	for (char c : x) cnt[0][c - 'a'] ++;
	for (char c : y) cnt[1][c - 'a'] ++;
	for (int i = 2; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			cnt[i][j] = cnt[i - 1][j] + cnt[i - 2][j];
		}
	}
	function <ll(int, ll, char)> dfs = [&](int cur, ll p, char c) -> ll {
		if (cur == 0) {
			return pre_x[p][c - 'a'];
		}
		if (cur == 1) {
			return pre_y[p][c - 'a'];
		}
		if (p < len[cur - 1]) return dfs(cur - 1, p, c);
		else return cnt[cur - 1][c - 'a'] + dfs(cur - 2, p - len[cur - 1], c);
	};
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		ll l, r;
		char c;
		cin >> l >> r >> c;
		cout << dfs(m - 1, r, c) - dfs(m - 1, l - 1, c) << '\n';
	}
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
