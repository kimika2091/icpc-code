#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector <vector<int>> pa(2);
	vector <vector<int>> pb(2);
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (a[i] == '1') pa[0].push_back(i);
			if (b[i] == '1') pb[0].push_back(i); 
		}
		else {
			if (a[i] == '1') pa[1].push_back(i);
			if (b[i] == '1') pb[1].push_back(i); 
		}
	}
	if (pa[0].size() != pb[0].size() || pa[1].size() != pb[1].size()) {
		cout << -1 << '\n';
		return;
	}
	int cnt = 0;
	for (int i = 0; i < pa[0].size(); i++) {
		cnt += abs(pa[0][i] / 2 - pb[0][i] / 2);
	}
	for (int i = 0; i < pa[1].size(); i++) {
		cnt += abs(pa[1][i] / 2 - pb[1][i] / 2);
	}
	cout << cnt << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}