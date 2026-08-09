#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int P = 998244353;

void solve() {
	string s;
	cin >> s;
	vector <ll> f(3, 0);
	for (int i = 0; i < s.size(); i++) {
		int p = s[i] - 'a';
		if (p == 0) f[0] += (f[1] + f[2] + 1) % P;
		if (p == 1) f[1] += (f[0] + f[2] + 1) % P;
		if (p == 2) f[2] += (f[0] + f[1] + 1) % P;
	}
	cout << (f[0] + f[1] + f[2]) % P << endl;
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
