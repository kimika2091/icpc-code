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
	vector <int> f(100 * n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			for (int k = 100 * n; k >= j * (100 / a[i]); k--) {
				f[k] |= f[k - j * (100 / a[i])]; 
			}
		}
	}
	for (int i = 0; i <= 100 * n; i++) if (!f[i]) {cout << "No" << '\n'; return;}
	cout << "Yes" << '\n';
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
