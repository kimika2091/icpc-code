#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, d;
	cin >> n >> d;
	string a;
	cin >> a;
	int g = gcd(n, 2 * d);
	vector <vector<int>> p(n + 1);
	for (int i = 0; i < n; i++) {
		int j = min(i % g, ((- 1 - i) % g + g) % g);
		p[j].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < g; i++) {
		vector <int> cnt(26, 0);
		for (int &x : p[i]) cnt[a[x] - 'a']++;
		ans += p[i].size() - *max_element(cnt.begin(), cnt.end());
	}
	cout << ans << '\n';
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