#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> mp(n + 1, vector<int>(m + 1));
	vector <int> row(n + 1), col(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}
	auto left = [&]() -> int {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			bool f = 0;
			for (int j = 1; j <= m; j++) {
				if (mp[i][j] == 1) f = 1;
				else {
					if (f == 1) {
						cnt ++;
					}
				}
			}
		}
		return cnt;
	};
	auto right = [&]() -> int {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			bool f = 0;
			for (int j = m; j >= 1; j--) {
				if (mp[i][j] == 1) f = 1;
				else {
					if (f == 1) {
						cnt ++;
					}
				}
			}
		}
		return cnt;
	};
	auto up = [&]() -> int {
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			bool f = 0;
			for (int i = 1; i <= n; i++) {
				if (mp[i][j] == 1) f = 1;
				else {
					if (f == 1) {
						cnt ++;
					}
				}
			}
		}
		return cnt;
	};
	auto down = [&]() -> int {
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			bool f = 0;
			for (int i = n; i >= 1; i--) {
				if (mp[i][j] == 1) f = 1;
				else {
					if (f == 1) {
						cnt ++;
					}
				}
			}
		}
		return cnt;
	};
	cout << left() + right() + up() + down();
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
