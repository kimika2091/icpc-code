#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int x, y, n, m;
	cin >> x >> y >> n >> m;
	vector <int> a(n), b(m);
	for (int &i : a) cin >> i, i += x;
	for (int &i : b) cin >> i, i += y;
	a.push_back(x), b.push_back(y);
	int Amx = *max_element(a.begin(), a.end());
	int Amn = *min_element(a.begin(), a.end());
	int Bmx = *max_element(b.begin(), b.end());
	int Bmn = *min_element(b.begin(), b.end());
	cout << max({Amx * Bmx, Amx * Bmn, Amn * Bmx, Amn * Bmn}) << '\n';

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