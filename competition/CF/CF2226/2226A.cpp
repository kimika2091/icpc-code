#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int P = 676767677;

void solve() {
	int n;
	cin >> n;
	ll sum = 0, x, f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (i == n && x == 1) f = 1;
		if (x != 1) sum += x, sum %= P;
	}
	cout << (sum + f) % P << '\n';
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
