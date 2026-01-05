#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        // Prefix XOR
        vector<ll> prefix(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prefix[i + 1] = prefix[i] ^ A[i];
        }

        unordered_map<ll, long long> freq;
        unordered_map<ll, long long> prefixSumIndex;
        long long xor0_subarrays = 0;

        // Count XOR = 0 subarrays
        for (int i = 0; i <= N; i++) {
            xor0_subarrays += freq[prefix[i]];
            freq[prefix[i]]++;
        }

        // Total length sum of all subarrays
        long long total_length_sum = 0;
        for (int i = 0; i < N; i++) {
            total_length_sum += (long long)(i + 1) * (N - i);
        }

        // Subarrays of length 1 with A[i] == 0 should contribute 0 instead of 1
        long long single_zero_count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == 0) single_zero_count++;
        }

        // Final cost:
        // Normally: total_length_sum - xor0_subarrays
        // But single zero subarrays are over-counted by 1 each
        long long total_cost = total_length_sum - xor0_subarrays - single_zero_count;

        cout << "Case #" << t << ": " << total_cost << "\n";
    }

    return 0;
}
