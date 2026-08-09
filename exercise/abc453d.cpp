#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;
	vector <vector<char>> mp(h + 1, vector<char>(w + 1));
	int sx, sy;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> mp[i][j]; 
			if (mp[i][j] == 'S') sx = i, sy = j;
		}
	}
	vector <vector<vector<bool>>> vis(h + 1, vector<vector<bool>>(w + 1, vector<bool>(5)));
	auto check = [&](int x, int y) -> bool {
		if (x < 1 || x > h || y < 1 || y > w) return false;
		if (mp[x][y] == '#') return false;
		return true;
	};
	auto move = [&](int x, int y, int dir) -> tuple<int, int, int> {
		switch (dir){
			case 1:
				x += 1; // D
				break;
			case 2:
				x -= 1; // U
				break;
			case 3:
				y += 1; // R
				break;
			case 4:
				y -= 1; // L
				break;
		}
		return {check(x, y), x, y};
	};
	auto transformation = [&](int dir) -> char {
		switch (dir){
			case 1:
				return 'D';
			case 2:
				return 'U';
			case 3:
				return 'R';
			case 4:
				return 'L';
		}
	};
	string path = "";
	function <void(int, int, int)> dfs = [&](int x, int y, int dir) {
		if (vis[x][y][dir]) return;
		vis[x][y][dir] = 1;
		if (mp[x][y] == 'G') {
			cout << "Yes" << '\n';
			cout << path << '\n';
			exit(0);
		}
		if (mp[x][y] == 'o') {
			auto [f, nx, ny] = move(x, y, dir);
			if (f) {
				path += transformation(dir);
				dfs(nx, ny, dir);
				path.pop_back();
			}
			return;
		}
		if (mp[x][y] == 'x') {
			for (int i = 1; i <= 4; i++) {
				if (i == dir) continue;
				auto [f, nx, ny] = move(x, y, i);
				if (f) {
					path += transformation(i);
					dfs(nx, ny, i);
					path.pop_back();
				}
			}
			return;
		}
		for (int i = 1; i <= 4; i++) {
			auto [f, nx, ny] = move(x, y, i);
			if (f) {
				path += transformation(i);
				dfs(nx, ny, i);
				path.pop_back();
			} 
		}
	};
	auto clear = [&]() -> void {
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				for (int k = 1; k <= 4; k++) {
					vis[i][j][k] = 0;
				}
			}
		}
	};
	for (int i = 1; i <= 4; i++) {
		clear();
		auto [f, nx, ny] = move(sx, sy, i);
		if (f) {
			path = transformation(i);
			dfs(nx, ny, i);
		}
	}
	cout << "No" << '\n';
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
