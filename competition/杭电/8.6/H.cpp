#include <bits/stdc++.h>
using namespace std;

vector<array<int, 4>> buildFourPositionPermutations() {
    const array<int, 4> identity = {0, 1, 2, 3};
    set<array<int, 4>> visited;
    queue<array<int, 4>> pending;
    visited.insert(identity);
    pending.push(identity);

    while (!pending.empty()) {
        auto current = pending.front();
        pending.pop();

        auto wholeSegment = current;
        swap(wholeSegment[0], wholeSegment[3]);
        if (visited.insert(wholeSegment).second) pending.push(wholeSegment);

        auto twoSegments = current;
        swap(twoSegments[0], twoSegments[1]);
        swap(twoSegments[2], twoSegments[3]);
        if (visited.insert(twoSegments).second) pending.push(twoSegments);
    }

    return {visited.begin(), visited.end()};
}

bool canTransformWhenEqual(
    const string& source,
    const string& target,
    int k,
    const vector<array<int, 4>>& permutations
) {
    const int n = static_cast<int>(source.size());

    if (k == 1) {
        return (source[0] == target[0] && source[1] == target[1])
            || (source[0] == target[1] && source[1] == target[0]);
    }

    const array<int, 4> position = {0, k - 1, k, n - 1};

    for (int i = 0; i < n; ++i) {
        bool movable = false;
        for (int p : position) movable |= (i == p);
        if (!movable && source[i] != target[i]) return false;
    }

    for (const auto& permutation : permutations) {
        bool matches = true;
        for (int i = 0; i < 4; ++i) {
            if (source[position[permutation[i]]] != target[position[i]]) {
                matches = false;
                break;
            }
        }
        if (matches) return true;
    }

    return false;
}

bool canTransform(
    const string& source,
    const string& target,
    int k,
    const vector<array<int, 4>>& fourPositionPermutations
) {
    const int n = static_cast<int>(source.size());

    if (n < 2 * k) {
        for (int i = 1; i + 1 < n; ++i) {
            if (source[i] != target[i]) return false;
        }

        return (source.front() == target.front()
                && source.back() == target.back())
            || (source.front() == target.back()
                && source.back() == target.front());
    }

    if (n == 2 * k) {
        return canTransformWhenEqual(
            source, target, k, fourPositionPermutations
        );
    }

    // For n > 2k, the movable positions are
    // {1, n} union [k, n-k+1] (using one-based indices).
    // Every permutation of those positions can be generated.
    for (int i = 1; i <= k - 2; ++i) {
        if (source[i] != target[i]) return false;
    }
    for (int i = n - k + 1; i <= n - 2; ++i) {
        if (source[i] != target[i]) return false;
    }

    array<int, 26> difference{};
    for (char c : source) ++difference[c - 'a'];
    for (char c : target) --difference[c - 'a'];

    return all_of(difference.begin(), difference.end(), [](int value) {
        return value == 0;
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const auto fourPositionPermutations = buildFourPositionPermutations();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, k;
        string source, target;
        cin >> n >> k >> source >> target;

        cout << (canTransform(
            source, target, k, fourPositionPermutations
        ) ? "Yes\n" : "No\n");
    }

    return 0;
}
