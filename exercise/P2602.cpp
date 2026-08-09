#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[13][2][2][13];

void solve() {
	auto dfs = [&](auto self, int num, int d, int offset, int len, int free, int fix, int sum) -> int {
		if (len == 0) {
			return sum;
		}
		if (dp[len][free][fix][sum] != -1) {
			return dp[len][free][fix][sum];
		}
		int cur = num / offset % 10;
		int limit = free ? 9 : cur;
		int ans = 0;
		for (int i = 0; i <= limit; i++) {
			int now = fix || (i != 0);
			ans += self(self, num, d, offset / 10, len - 1, free || (i < cur), now, sum + (now && i == d));
		}
		dp[len][free][fix][sum] = ans;
		return ans;
	};
	auto build = [&]() {
		for (int a = 0; a <= 12; a++) {
			for (int b = 0; b <= 1; b++) {
				for (int c = 0; c <= 1; c++) {
					for (int d = 0; d <= 12; d++) {
						dp[a][b][c][d] = -1;
					}
				}
			}
		}
	};
	auto count = [&](int x, int d) {
		build();
		int len = 1, offset = 1;
		int tmp = x / 10;
		while (tmp > 0) {
			tmp /= 10;
			offset *= 10;
			len++;
		}
		return dfs(dfs, x, d, offset, len, 0, 0, 0);
	};
	auto compute = [&](int a, int b, int d) {
		return count(b, d) - count(a - 1, d);
	};
	int a, b;
	cin >> a >> b;
	for (int i = 0; i <= 9; i++) {
		cout << compute(a, b, i) << " \n"[i == 9];
	}
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