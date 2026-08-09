#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int x, y;
	cin >> x >> y;
	if ((x & 1) && (y & 1)) cout << "NO\n";
	else {
		cout << "YES\n";
	}
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
