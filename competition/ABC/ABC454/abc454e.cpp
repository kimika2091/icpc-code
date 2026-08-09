#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (n % 2) {
		cout << "No" << '\n';
		return;
	}
	if ((a + b) % 2 == 0) {
		cout << "No" << '\n';
		return;
	}
	cout << "Yes\n";
	function<string(int, int ,int, int)> dfs = [&](int x1, int y1, int x2, int y2) -> string {
		if (x2 == x1 + 1 && y2 == y1 + 1) {
			if (a == x1) return "DR";
			return "RD";
		}
		if (a > x1 + 1) return string(y2 - y1, 'R') + 'D' + string(y2 - y1, 'L') + 'D' + dfs(x1 + 2, y1, x2, y2);
		if (b > y1 + 1) return string(x2 - x1, 'D') + 'R' + string(x2 - x1, 'U') + 'R' + dfs(x1, y1 + 2, x2, y2);	
		if (a < x2 - 1) return dfs(x1, y1, x2 - 2, y2) + 'D' + string(y2 - y1, 'L') + 'D' + string(y2 - y1, 'R');
		if (b < y2 - 1) return dfs(x1, y1, x2, y2 - 2) + 'R' + string(x2 - x1, 'U') + 'R' + string(x2 - x1, 'D');
	};
	cout << dfs(1, 1, n, n) << '\n';
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
