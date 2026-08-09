#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <vector<char>> mp(3, vector<char>(n + 1)); 
	for (int i = 1; i <= 2; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> mp[i][j];
		}
	}
	vector <vector<bool>> f(3, vector<bool>(n + 1, 0));
	auto move = [&](int x, int y) -> pair<int, int> {
		if (mp[x][y] == '<' && y - 1 >= 1) return {x, y - 1};
		if (mp[x][y] == '>' && y + 1 <= n) return {x, y + 1};
		return {-1, -1};
	};
	function <void(int, int)> dfs = [&](int x, int y) {
		if (f[x][y]) return;
		f[x][y] = 1;
		if (y - 1 >= 1) { auto [nx, ny] = move(x, y - 1); if (nx != -1) dfs(nx, ny); }
		if (y + 1 <= n) { auto [nx, ny] = move(x, y + 1); if (nx != -1) dfs(nx, ny); }
		if (x - 1 >= 1) { auto [nx, ny] = move(x - 1, y); if (nx != -1) dfs(nx, ny); }
		if (x + 1 <= 2) { auto [nx, ny] = move(x + 1, y); if (nx != -1) dfs(nx, ny); }
	};
	dfs(1, 1);
	cout << (f[2][n] ? "YES" : "NO") << '\n';
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
