
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        int maxVal = 0;
        for (int i = 0; i < N; ++i) { cin >> A[i]; maxVal = max(maxVal, A[i]); }
        for (int i = 0; i < N; ++i) { cin >> B[i]; maxVal = max(maxVal, B[i]); }

        // Quick impossible check: cannot lower temperature
        bool impossible = false;
        for (int i = 0; i < N; ++i) if (B[i] < A[i]) { impossible = true; break; }
        if (impossible) {
            cout << "Case #" << tc << ": -1\n";
            continue;
        }

        // donors[v] = indices (0-based) which currently have temperature == v
        vector<vector<int>> donors(maxVal + 1);
        for (int i = 0; i < N; ++i) donors[A[i]].push_back(i);

        // targets[v] = indices (0-based) which want temperature v but currently A[i] != v
        vector<vector<int>> targets(maxVal + 1);
        for (int i = 0; i < N; ++i) {
            if (A[i] != B[i]) targets[B[i]].push_back(i);
        }

        vector<pair<int,int>> ops;
        // process v from largest to smallest
        for (int v = maxVal; v >= 0; --v) {
            if (targets[v].empty()) continue;
            if (donors[v].empty()) { impossible = true; break; }

            int donor = donors[v][0]; // pick any donor index that currently has temperature v
            // Use donor to warm all target indices to v
            for (int idx : targets[v]) {
                // idx currently has A[idx] != v
                ops.emplace_back(donor + 1, idx + 1); // store 1-based indices
                A[idx] = v;                 // update current temperature
                donors[v].push_back(idx);   // this index can now act as donor for v as well
            }
        }

        if (impossible) {
            cout << "Case #" << tc << ": -1\n";
        } else {
            cout << "Case #" << tc << ": " << ops.size() << "\n";
            for (auto &p : ops) cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
