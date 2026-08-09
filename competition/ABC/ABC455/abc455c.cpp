#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n + 1);
	map <int, int> f; 
	ll sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for (int i = 1; i <= n; i++) {
		f[a[i]] ++;	
	}
	vector <ll> p;
	for (auto [num, cnt] : f) {
		p.push_back(1ll * num * cnt);
	}
	if ((int)p.size()<=k) {
		cout << 0;
		return;
	}
	sort(p.begin(),p.end(),[&](int a,int b){return a>b;});
	for (int i = 0; i < k; i++) {
		sum -= p[i];
	}
	cout << sum << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
