#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector <vector<int>> cnta(2, vector<int>(2));
	vector <vector<int>> cntb(2, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cnta[i & 1][a[i] - '0']++;
		cntb[i & 1][b[i] - '0']++;
	}
	bool f = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (cnta[i][j] != cntb[i][j]) {
				f = 0;
			}
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
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