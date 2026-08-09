#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char c : s) {
		a += c == '(';
		b += c == ')';
	}
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
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
