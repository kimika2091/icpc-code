#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> answer;
        answer.reserve(n);

        if (n == 1) {
            answer.push_back(1);
        } else if (n % 2 == 0) {
            int k = n / 2;
            answer.push_back(1);
            for (int low = k, high = k + 1; high <= n; --low, ++high) {
                answer.push_back(high);
                if (low >= 2) answer.push_back(low);
            }
        } else {
            int k = n / 2;
            answer.push_back(1);
            answer.push_back(k + 2);
            answer.push_back(2);
            for (int low = k + 1, high = k + 3; high <= n; --low, ++high) {
                answer.push_back(low);
                answer.push_back(high);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << answer[i];
        }
        cout << '\n';
    }

    return 0;
}
