#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    seed_seq seed{rd(), rd(), rd(), rd()};
    mt19937 rng(seed);

    // 数据必须小，否则状态压缩暴力会很慢。
    int n = uniform_int_distribution<int>(1, 7)(rng);
    int m = uniform_int_distribution<int>(1, 5)(rng);

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        int len = uniform_int_distribution<int>(1, 3)(rng);
        string s;
        for (int j = 0; j < len; ++j) {
            s += char('a' + uniform_int_distribution<int>(0, 2)(rng));
        }
        cout << s << '\n';
    }
    return 0;
}
