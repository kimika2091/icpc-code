#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const pair <int, int> win[8][3] = {
	{{1, 1}, {1, 2}, {1, 3}},
	{{2, 1}, {2, 2}, {2, 3}},
	{{3, 1}, {3, 2}, {3, 3}},
	{{1, 1}, {2, 1}, {3, 1}},
	{{1, 2}, {2, 2}, {3, 2}},
	{{1, 3}, {2, 3}, {3, 3}},
	{{1, 1}, {2, 2}, {3, 3}},
	{{1, 3}, {2, 2}, {3, 1}}
};

void solve() {
	int n;
	cin >> n;
	vector <pair<int, int>> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].first >> b[i].second;
	}
	if (n < 2) {
		cout << "Columbina Hyposelenia" << '\n';
		return;
	}
	bool mp[4][4] = {false};
	for (int i = 1; i <= n; i++) {
		mp[a[i].first][a[i].second] = 1;
		mp[b[i].first][b[i].second] = 1;
	}
	bool cur[4][4] = {false};
	if (n == 2) {
		cur[a[1].first][a[1].second] = 1;
		cur[a[2].first][a[2].second] = 1;
	}
	else {
		cur[a[2].first][a[2].second] = 1;
		cur[a[3].first][a[3].second] = 1;
	}
	vector <pair<int, int>> c;
	for (int i = 0; i < 8; i++) {
		int cnt = 0;
		pair <int, int> tmp;
		for (auto [x, y] : win[i]) {
			if (cur[x][y]) cnt++;
			else tmp = {x, y};
		}
		if (cnt == 2 && !mp[tmp.first][tmp.second]) {
			c.push_back(tmp);
		}
	}
	if (!c.empty()) {
		sort(c.begin(), c.end());
		cout << c[0].first << ' ' << c[0].second << '\n';
	}
	else {
		cout << "Columbina Hyposelenia" << '\n';
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