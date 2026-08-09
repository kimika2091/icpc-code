#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
	int l, r;
	bool operator < (const Node & a) const {
		return r < a.r;
	}
};

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	map <int, int> id;
	int o = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!id.count(a[i])) id[a[i]] = ++o;
	}
	vector <vector<Node>> p(o + 1);
	for (int i = 1; i <= n; i++) {
		priority_queue<int> q1;
		priority_queue<int, vector<int>, greater<int>> q2;
		for (int j = i; j <= n; j++) {
			if (q1.empty() || a[j] <= q1.top()) q1.push(a[j]);
			else q2.push(a[j]);
			if (q1.size() > q2.size() + 1) {
				q2.push(q1.top());
				q1.pop();
			}
			else if (q1.size() < q2.size()) {
				q1.push(q2.top());
				q2.pop();
			}
			if ((j - i + 1) & 1) {
				p[id[q1.top()]].push_back({i, j});
			}
		}
	}
	auto calc = [&](vector <Node> &c) -> int {
		if (c.empty()) return 0;
		sort(c.begin(), c.end());
		vector <int> f(n + 1, -1);
		f[0] = 0;
		for (auto [l, r] : c) {
			if (f[l - 1] != -1) {
				f[r] = max(f[r], f[l - 1] + 1);
			}
		}
		return f[n];
	};
	int ans = 0;
	for (int i = 1; i <= o; i++) {
		ans = max(ans, calc(p[i]));
	}
	cout << ans << '\n';
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
