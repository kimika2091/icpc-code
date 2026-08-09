#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int calc(int l, int r, const vector<int>& a, int n) {
    int left = l, right = r;
    while (left >= 0 && right < 2 * n && a[left] == a[right]) {
        left--;
        right++;
    }
    left++;
    right--;
    if (left > right) return 0;
    vector<bool> present(n + 1, false);
    for (int i = left; i <= right; i++) {
        if (a[i] <= n) {
            present[a[i]] = true;
        }
    }
    int mex = 0;
    while (present[mex]) {
        mex++;
    }
    return mex;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    int p1 = -1, p2 = -1;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }
    int ans = 0;
    ans = max(ans, calc(p1, p1, a, n));
    ans = max(ans, calc(p2, p2, a, n));
    if ((p1 + p2) % 2 == 0) {
        ans = max(ans, calc((p1 + p2) / 2, (p1 + p2) / 2, a, n));
    } else {
        ans = max(ans, calc((p1 + p2) / 2, (p1 + p2) / 2 + 1, a, n));
    }
    cout << ans << "\n";
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