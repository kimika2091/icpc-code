#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1), b, c, d, e;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if(a[i] % 2 != 0 && a[i] % 3 != 0) b.push_back(a[i]);
		if(a[i] % 2 != 0 && a[i] % 3 == 0) c.push_back(a[i]);
		if(a[i] % 2 == 0 && a[i] % 3 != 0) d.push_back(a[i]);
		if(a[i] % 2 == 0 && a[i] % 3 == 0) e.push_back(a[i]);
	}
	for (int i : e) cout << i << ' ';
	for (int i : c) cout << i << ' ';
	for (int i : b) cout << i << ' ';
	for (int i : d) cout << i << ' ';
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
