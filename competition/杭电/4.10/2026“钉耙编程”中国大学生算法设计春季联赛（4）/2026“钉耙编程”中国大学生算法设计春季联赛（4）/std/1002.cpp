#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using i64 = long long;
using u32 = unsigned;

mt19937_64 rnd(random_device{}());

constexpr int mod = 998244353;

constexpr int MAX = 810;

constexpr int N = 15;

int a[MAX][MAX], t[MAX][N + 1], nxt[MAX][MAX][N + 2];

int dp[1 << N + 1], add[MAX + 1];

void solve(int tc) {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            int temp = min(min(i, n - i + 1), min(j, n - j + 1));
			for (int k = 0; k <= N + 1; k++) {
				nxt[i][j][k] = temp;
			}
        }
    }

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n + 1; j++) {
			for (int k = 0; k <= N; k++) t[j][k] = j;
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= N; k++) t[j][k] = min(t[j][k], t[j - 1][k] + 1);
			for (int k = 0; k <= N; k++) {
				if (a[i][j] >> k & 1) t[j][k] = 0;
			}
			for (int k = 0; k <= N; k++) nxt[i][j][k] = min(nxt[i][j][k], t[j][k]);
		}
		for (int j = 0; j <= n + 1; j++) {
			for (int k = 0; k <= N; k++) t[j][k] = n - j + 1;
		}
		for (int j = n; j >= 1; j--) {
			for (int k = 0; k <= N; k++) t[j][k] = min(t[j][k], t[j + 1][k] + 1);
			for (int k = 0; k <= N; k++) {
				if (a[i][j] >> k & 1) t[j][k] = 0;
			}
			for (int k = 0; k <= N; k++) nxt[i][j][k] = min(nxt[i][j][k], t[j][k]);
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= n + 1; i++) {
			for (int k = 0; k <= N; k++) t[i][k] = i;
		}
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= N; k++) t[i][k] = min(t[i][k], t[i - 1][k] + 1);
			for (int k = 0; k <= N; k++) {
				if (a[i][j] >> k & 1) t[i][k] = 0;
			}
			for (int k = 0; k <= N; k++) nxt[i][j][k] = min(nxt[i][j][k], t[i][k]);
		}
		for (int i = 0; i <= n + 1; i++) {
			for (int k = 0; k <= N; k++) t[i][k] = n - i + 1;
		}
		for (int i = n; i >= 1; i--) {
			for (int k = 0; k <= N; k++) t[i][k] = min(t[i][k], t[i + 1][k] + 1);
			for (int k = 0; k <= N; k++) {
				if (a[i][j] >> k & 1) t[i][k] = 0;
			}
			for (int k = 0; k <= N; k++) nxt[i][j][k] = min(nxt[i][j][k], t[i][k]);
		}
	}
	
	for (auto& ele : dp) ele = 0;

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> A;
			for (int k = 0; k <= N + 1; k++) {
				A.push_back(nxt[i][j][k]);
				if (k <= N) {
					add[nxt[i][j][k]] |= 1 << k;
				}
			}
			sort(A.begin(), A.end());
			int pre = 0, cur = 0;
			for (auto dis : A) {
				dp[cur] += dis - pre;
				cur |= add[dis];
				pre = dis;
			}
			for (int k = 0; k <= N + 1; k++) {
				add[nxt[i][j][k]] = 0;
			}
		}
	}

	for (int d = 0; d <= N; d++) {
		for (int s = 0; s < 1 << N + 1; s++) {
			if (s & 1 << d) {
				dp[s] += dp[s ^ 1 << d];
			}
		}
	}

    for (int i = 1; i <= q; i++) {
        int card;
        cin >> card;
        card &= (1 << N + 1) - 1;
        cout << dp[card] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}