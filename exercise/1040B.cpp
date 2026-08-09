#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	auto calc = [&](int x) -> pair <bool, vector<int>> {
		int cnt = 0;
		vector <int> q;
		bool flag = false;
		for (int i = x; i <= n; i += 2 * k + 1) {
			if (i + k >= n) {
				q.push_back(i);
				flag = true;
				break;
			}
			q.push_back(i);
		}
		return {flag, q};
	};
	vector <int> ans(n + 1);
	for (int i = 1; i <= k + 1; i++) {
		auto [flag, cur] = calc(i);
		if (flag && ans.size() > cur.size()) {
			ans = cur;
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
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
