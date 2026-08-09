#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s = "HelloWorld";
	int n;
	cin >> n;
	for (int i = 0; i < s.size(); i++) {
		if (i == n - 1) continue;
		cout << s[i];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}