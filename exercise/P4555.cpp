#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Manacher {
	int n;
    string t;
    vector<int> d, end, start;
    Manacher(string s) {
        t = "@";
        for (char c : s) t += '#', t += c;
        t += "#$";
        n = t.size();
        d.resize(n);
		end.resize(n);
		start.resize(n);
        int mid = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            if (i < R) d[i] = min(d[2 * mid - i], R - i);
            while (t[i + (d[i] + 1)] == t[i - (d[i] + 1)]) d[i]++;   
            if (i + d[i] > R) {
                mid = i;
                R = i + d[i];
            }
			end[i + d[i]] = max(end[i + d[i]], d[i]);
			start[i - d[i]] = max(start[i - d[i]], d[i]);
        }
		
    }
	int solve() {
		for (int i = n - 3; i >= 0; i--) {
			end[i] = max(end[i], end[i + 2] - 2); 
		}
		for (int i = 2; i < n; i++) {
			start[i] = max(start[i], start[i - 2] - 2);
		}
		int max_len = 2;
		for (int i = 0; i < n; i++){
			if (end[i] && start[i])
				max_len = max(max_len, end[i] + start[i]);
		}
		return max_len;
	}
    int get_max_len() {
        int max_r = 0;
        for (int x : d) max_r = max(max_r, x);
        return max_r;
    }
    bool is_palindrome(int l, int r) {
        int len = r - l + 1;
        int mid_idx = l + r + 2;
        return d[mid_idx] >= len;
    }
};

void solve() {
	string s;
	cin >> s;
	cout << Manacher(s).solve() << endl;
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