#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int ans = 0, cur = 0;
    int r = 0, b = 0;
    for (char c : s) {

        if (c == 'R') { 
            if (b > 0) {
                b--;
                r++;
            }
            else {
                cur++;
                r++;
            }
        }
        else if (c == 'B') {
            if (r > 0) {
                r--;
                b++;
            }
            else {
                cur++;
                b++;
            }
        }
        else {
            ans = max(ans, cur);
            cur = r = b = 0;
        }
    }
    ans = max(ans, cur);
    cout << max(ans, 1LL) << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}
