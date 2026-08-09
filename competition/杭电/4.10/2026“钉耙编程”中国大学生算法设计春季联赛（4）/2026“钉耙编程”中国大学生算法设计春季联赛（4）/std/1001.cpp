#include<bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using i64 = long long;
using u32 = unsigned;

mt19937_64 rnd(random_device{}());

const int mod = 998244353;

struct Node {
	int x, y;
};

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve(int tc)
{	
	int n, m;
	cin >> n >> m;

	vector mp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}

	vector<vector<Node>> pos(n + m);
	for (int i = 1; i <= n; i++) {
		if (mp[i][1] < n + m) {
			pos[mp[i][1]].push_back({i, 1});
		}
	}
	for (int i = 2; i <= m; i++) {
		if (mp[n][i] < n + m) {
			pos[mp[n][i]].push_back({n, i});
		}
	}

	vector vis(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < n + m; i++) {
		if (pos[i].empty()) {
			cout << i << '\n';
			return;
		}
		bool flag = 1;
		for (auto [x, y] : pos[i]) {
			queue<Node> q;
			q.push({x, y});
			vis[x][y] = i + 1;
			while (q.size()) {
				auto [curX, curY] = q.front();
				q.pop();
				if (curX == 1 || curY == m) {
					flag = 0;
					break;
				}
				for (int j = 0; j < 8; j++) {
					int newX = curX + dx[j];
					int newY = curY + dy[j];
					if (newX > n || newX < 1 || newY > m || newY < 1) continue;
					if (mp[newX][newY] != mp[curX][curY]) continue;
					if (vis[newX][newY]) continue;
					vis[newX][newY] = i + 1;
					q.push({newX, newY});
				}
			}
			if (!flag) break;
		}
		if (flag) {
			cout << i << '\n';
			return;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
	   solve(tc);
	}

	return 0;
}