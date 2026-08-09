#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// 求当前元素能够取得的、不小于 lower 的最小值
bool get_next(ull a, ull mask, ull lower, ull &res) {
    // mask 中的位可以修改，因此先全部置零
    ull base = a & ~mask;

    if (base >= lower) {
        res = base;
        return true;
    }

    ull d = lower - base;

    // d 中存在但 mask 中不存在的位
    ull bad = d & ~mask;

    ull s;

    if (bad == 0) {
        // d 本身就是 mask 的子掩码
        s = d;
    } else {
        int h = 63 - __builtin_clzll(bad);

        // 寻找最低的 j > h，使 mask_j = 1 且 d_j = 0
        ull higher = ~((1ULL << (h + 1)) - 1);
        ull available = mask & ~d & higher;

        if (available == 0) {
            return false;
        }

        int j = __builtin_ctzll(available);

        // 高于 j 的位保持与 d 相同，第 j 位设 1，低位清零
        ull low_bits = (1ULL << (j + 1)) - 1;
        s = (d & ~low_bits) | (1ULL << j);
    }

    res = base | s;
    return true;
}

bool feasible(const vector<ull> &a, ull mask) {
    ull last = 0;

    for (ull x : a) {
        ull current;
        if (!get_next(x, mask, last, current)) {
            return false;
        }
        last = current;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ull> a(n);
        for (ull &x : a) cin >> x;

        ull answer = 0;

        for (int p = 29; p >= 0; --p) {
            // 尝试不购买第 p 位，同时允许购买全部更低位
            ull test_mask = answer | ((1ULL << p) - 1);

            if (!feasible(a, test_mask)) {
                answer |= 1ULL << p;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}