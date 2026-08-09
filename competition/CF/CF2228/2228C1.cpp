#include<bits/stdc++.h>
using namespace std;

using int128 = __int128;

int128 parse_int128(const string& s) {
    if (s.empty()) return 0;
    int128 res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

void solve() {
    string a_str;
    int n;
    cin >> a_str >> n;
    
    vector<int> d(n);
    vector<bool> has_digit(10, false);
    int d_min = 10, d_max = -1;
    int d_min_nonzero = 10;
    
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        has_digit[d[i]] = true;
        d_min = min(d_min, d[i]);
        d_max = max(d_max, d[i]);
        if (d[i] > 0) {
            d_min_nonzero = min(d_min_nonzero, d[i]);
        }
    }
    
    int128 a = parse_int128(a_str);
    int L = a_str.length();
    
    int128 min_diff = -1;
    
    auto check = [&](int128 b) {
        if (b < 0) return;
        int128 diff = (a > b) ? (a - b) : (b - a);
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
        }
    };
    
    if (L > 1) {
        string b_str(L - 1, '0' + d_max);
        check(parse_int128(b_str));
    } else if (has_digit[0]) {
        check(0); 
    }
    
    if (d_min_nonzero != 10) {
        string b_str = "";
        b_str += ('0' + d_min_nonzero);
        b_str += string(L, '0' + d_min);
        check(parse_int128(b_str));
    }
    
    bool prefix_match = true;
    for (int i = 0; i < L; i++) {
        int curr_digit = a_str[i] - '0';
        
        int smaller_d = -1;
        for (int x : d) {
            if (x < curr_digit) smaller_d = max(smaller_d, x);
        }
        if (smaller_d != -1) {
            string b_str = a_str.substr(0, i);
            b_str += ('0' + smaller_d);
            b_str += string(L - 1 - i, '0' + d_max);
            check(parse_int128(b_str));
        }
        
        int larger_d = 10;
        for (int x : d) {
            if (x > curr_digit) larger_d = min(larger_d, x);
        }
        if (larger_d != 10) {
            string b_str = a_str.substr(0, i);
            b_str += ('0' + larger_d);
            b_str += string(L - 1 - i, '0' + d_min);
            check(parse_int128(b_str));
        }
        
        if (!has_digit[curr_digit]) {
            prefix_match = false;
            break;
        }
    }
    if (prefix_match) {
        check(a);
    }
    cout << (long long)min_diff << "\n";
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