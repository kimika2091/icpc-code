#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, x1, x2, k;
	cin >> n >> x1 >> x2 >> k;
	if (n <= 3) {
		cout << 1 << '\n';
		return;
	}
	if (x1 > x2) swap(x1, x2);
	cout << min(x2 - x1, n + x1 - x2) + k << '\n'; 
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
// 2 1 2 0
// 4 3 2 1 