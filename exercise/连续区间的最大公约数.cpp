#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":\n";
		solve();
	}
	return 0; 
}