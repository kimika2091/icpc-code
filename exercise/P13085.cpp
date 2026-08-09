#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][11][2];

void solve() {
	auto dfs = [&](auto self, int num, int len, int offset, int pre, int free) -> int {
		if (len == 0) {
			return 1;
		}
		if (dp[len][pre][free] != -1) {
			return dp[len][pre][free];
		}
		int cur = num / offset % 10;
		int limit = free ? 9 : cur;
		int ans = 0;
		for (int i = 0; i <= limit; i++) {
			if (pre == 10) {
				if (i == 0) ans += self(self, num, len - 1, offset / 10, 10, 1);
				else ans += self(self, num, len - 1, offset / 10, i, free || (i < cur));
			}
			else {
				if (labs(pre - i) >= 2) {
					ans += self(self, num, len - 1, offset / 10, i, free || (i < cur));
				}
			}
		}
		dp[len][pre][free] = ans;
		return ans;
	};
	auto build = [&]() -> void {
		for (int a = 0; a <= 19; a++) {
			for (int b = 0; b <= 10; b++) {
				for (int c = 0; c <= 1; c++) {
					dp[a][b][c] = -1;
				}
			}
		}
	};
	auto count = [&](int x) -> int {
		int len = 1, offset = 1;
		int tmp = x / 10;
		while (tmp > 0) {
			tmp /= 10;
			offset *= 10;
			len++;
		}
		build();
		return dfs(dfs, x, len, offset, 10, 0);
	};
	auto compute = [&](int a, int b) -> int {
		return count(b) - count(a - 1);
	};
	int a, b;
	cin >> a >> b;
	cout << compute(a, b) << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}