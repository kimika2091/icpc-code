#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
	vector <int> a(n + 1), b(n + 1), F(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
	vector <vector<int>> match(n + 2), mismatch(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i]) {
            match[a[i]].push_back(i);
        } 
		else {
            mismatch[a[i]].push_back(i);
            mismatch[b[i]].push_back(i);
        }
    }
    for (int i = n; i >= 1; --i) {
        int m = 0, m_sz = match[i + 1].size();
        int mm = 0, mm_sz = mismatch[i + 1].size();
        for (int idx : match[i]) {
            while (m < m_sz && match[i + 1][m] <= idx) m++;
            int next_match = (m == m_sz) ? n + 1 : match[i + 1][m];
            while (mm < mm_sz && mismatch[i + 1][mm] <= idx) mm++;
            int next_mismatch = (mm == mm_sz) ? n + 1 : mismatch[i + 1][mm];
            if (next_mismatch < next_match) F[idx] = next_mismatch;
            else if (next_match <= n) F[idx] = F[next_match];
            else F[idx] = n + 1;
        }
    }
    int m = 0, m_sz = match[1].size();
    int mm = 0, mm_sz = mismatch[1].size();
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (m < m_sz && match[1][m] < i) m++;
        int next_match = (m == m_sz) ? n + 1 : match[1][m];
        while (mm < mm_sz && mismatch[1][mm] < i) mm++;
        int next_mismatch = (mm == mm_sz) ? n + 1 : mismatch[1][mm];
        int j;
        if (next_mismatch < next_match) j = next_mismatch;
        else if (next_match <= n) j = F[next_match];
        else j = n + 1;
        ans += (j - i);
    }
    cout << ans << '\n';
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