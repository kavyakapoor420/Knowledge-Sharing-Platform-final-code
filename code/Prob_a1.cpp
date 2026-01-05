#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream> 

using namespace std;

int minLadderHeight(int N, const vector<int>& A) {
    if (N == 1) return 0; 

    int max_diff = 0;
    for (int i = 0; i < N - 1; ++i) {
        int diff = abs(A[i] - A[i + 1]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    return max_diff;
}

void solve(ifstream &input, ofstream &output) {
    int T;
    input >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        input >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            input >> A[i];
        }
        int result = minLadderHeight(N, A);
        output << "Case #" << t << ": " << result << endl;
    }
}

int main() {
    ifstream input("snake_scales_chapter_1_input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    solve(input, output);

    input.close();
    output.close();
    return 0;
}
