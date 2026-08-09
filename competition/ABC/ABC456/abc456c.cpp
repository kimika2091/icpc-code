#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int P = 998244353;

void solve() {
	string s;
	cin >> s;
	ll cur = 1, ans = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			cur ++;
		}
		else {
			ans += cur * (cur + 1) / 2;
			ans %= P;
			cur = 1;
		}
	}
	ans += cur * (cur + 1) / 2;
	ans %= P;
	cout << ans << endl;
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
