#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    ll tot = n * (n + 1) / 2;
    ll cnt = 0, cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '1') {
            cnt ++;
        }
        else {
            cnt1 += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    cnt1 += cnt * (cnt + 1) / 2;
    cnt = 0;
    for (char c : s) {
        if (c == '0') {
            cnt ++;
        }
        else {
            cnt0 += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    cnt0 += cnt * (cnt + 1) / 2;
    cnt = 0;
    ll cnt01 = tot - cnt0 - cnt1;
    cout << cnt0 + cnt01 * 2 << '\n';
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