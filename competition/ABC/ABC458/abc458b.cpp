#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int t = 0;
			if (i + 1 <= n) t++;
			if (i - 1 >= 1) t++;
			if (j + 1 <= m) t++;
			if (j - 1 >= 1) t++;
			cout << t << " \n"[j == m];
		}
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