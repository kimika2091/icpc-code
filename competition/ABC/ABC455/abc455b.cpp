#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char mp[25][25];

void solve() {
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> mp[i][j];
		}
	}
	auto check = [&](int h1, int h2, int w1, int w2) -> bool {
		for (int i = h1; i <= h2; i++) {
			for (int j = w1; j <= w2; j++) {
				if (mp[i][j] != mp[h1 + h2 - i][w1 + w2 - j]) return false;
			}
		}
		return true;
	};
	int ans = 0;
	for (int h1 = 1; h1 <= h; h1++) {
		for (int h2 = h1; h2 <= h; h2++) {
			for (int w1 = 1; w1 <= w; w1++) {
				for (int w2 = w1; w2 <= w; w2++) {
					if (check(h1, h2, w1, w2)) ans++;
				}
			}
		}
	}
	cout << ans;
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
