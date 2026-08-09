#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector <int> cnt(5, 0);
	for (char c : s) {
		cnt[c - '0']++;
	}
	int tot = cnt[1] + cnt[3];
	int p2 = 0, p13 = 0;
	int t = tot;
	for (char c : s) {
		if (c == '2') {
			p2++;
		}
		if (c == '1' || c == '3') {
			p13++;
		}
		int cur = p2 + tot - p13;
		t = max(t, cur);
	}
	cout << n - t << '\n';
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
// 12 32 

// 2132 