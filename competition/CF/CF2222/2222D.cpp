#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <ll> a(n + 1), pre(n + 1);
	vector <pair<ll, int>> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		p[i] = {pre[i - 1], i};
	}
	sort(p.begin() + 1, p.end());
	vector<int> c(n + 1);
	for (int i = 1; i <= n; i++) {
		c[p[i].second] = n - i + 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';
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
