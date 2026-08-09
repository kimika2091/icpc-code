#include<bits/stdc++.h>
using namespace std;
#define int long long

const int P = 998244353;

int qpow (int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = a * a % P) {
		if (b & 1) {
			c = c * a % P;
		}
	}
	return c;
}

int inv (int x) { return qpow(x, P - 2); }

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
	}
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