#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int x;
	cin >> x;
	if (x >= 3 && x <= 18) cout << "Yes\n";
	else cout <<"No\n";
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
