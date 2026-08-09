#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a * 3 <= b) {
		cout << 1ll * a * n << '\n';
		return;
	}
	int t = n / 3;
	int s = n % 3;
	cout << 1ll * t * b + min(b, s * a) << '\n'; 
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