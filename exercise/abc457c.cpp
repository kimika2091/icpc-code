#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector <ll> l(n + 1);
	vector <vector<ll>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector <ll> c(n + 1), pre(n + 1);
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + c[i] * l[i];
	}
	for (int i = 1; i <= n; i++) {
		if (k <= pre[i]) {
			k -= pre[i - 1];
			cout << a[i][(k - 1) % l[i]] << '\n';
			break;
		} 
	}

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
