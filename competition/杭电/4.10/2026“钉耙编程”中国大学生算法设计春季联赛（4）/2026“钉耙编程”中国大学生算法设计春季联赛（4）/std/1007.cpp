#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, S;
	cin >> n >> S;

	bool exist = false, extra = false;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		if (x == S) {
			exist = true;
		}
		if (x != S && x != 0) {
			extra = true;
		}

		assert(x >= 0);
	}

	if (!exist || extra) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	cin >> tt;
	while (tt--) solve();
	return 0;
}