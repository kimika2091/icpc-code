#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector <ll> preA(n + 1), preB(n + 1), preC(n + 1);
	for (int i = 0; i < n; i++) {
		preA[i + 1] = preA[i] + (s[i] == 'A');
		preB[i + 1] = preB[i] + (s[i] == 'B');
		preC[i + 1] = preC[i] + (s[i] == 'C');
	}
	ll tot = n * (n + 1) / 2;
	ll AB = 0;
	map <int,int> f;
	for (int i = 0; i <= n; i++) {
		ll t = preA[i] - preB[i];
		AB += f[t];
		f[t] ++;
	}
	ll AC = 0;
	map <int,int> g;
	for (int i = 0; i <= n; i++) {
		ll t = preA[i] - preC[i];
		AC += g[t];
		g[t] ++;
	}
	ll BC = 0;
	map <int,int> h;
	for (int i = 0; i <= n; i++) {
		ll t = preB[i] - preC[i];
		BC += h[t];
		h[t] ++;
	}
	ll ABC = 0;
	map <pair<int, int>,int> k;
	for (int i = 0; i <= n; i++) {
		pair<int, int> t = {preA[i] - preB[i], preA[i] - preC[i]};
		ABC += k[t];
		k[t] ++;
	}
	cout << tot - AB - AC - BC + 2 * ABC  << '\n';
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
