#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <cstdio>
#include<unordered_set>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // For Code Jam style file handling:
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        bool impossible = false;
        for (int i = 0; i < N; ++i) {
            if (B[i] < A[i]) { // can't lower temperature
                impossible = true;
                break;
            }
        }

        if (impossible) {
            cout << "Case #" << tc << ": -1\n";
            continue;
        }

        unordered_map<int, vector<int>> donors;
        unordered_map<int, vector<int>> targets;
        unordered_set<int> uniqueTemps;

        for (int i = 0; i < N; ++i) {
            donors[A[i]].push_back(i);
            if (A[i] != B[i]) {
                targets[B[i]].push_back(i);
                uniqueTemps.insert(B[i]);
            }
        }

        // Sort target temperatures in descending order
        vector<int> temps(uniqueTemps.begin(), uniqueTemps.end());
        sort(temps.rbegin(), temps.rend());

        vector<pair<int,int>> ops;
        for (int v : temps) {
            if (targets[v].empty()) continue;
            if (donors[v].empty()) {
                impossible = true;
                break;
            }

            int donor = donors[v][0]; // pick first donor for v
            for (int idx : targets[v]) {
                ops.emplace_back(donor + 1, idx + 1); // 1-based index for output
                A[idx] = v;
                donors[v].push_back(idx);
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
