#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Line {
public:
    int x1, y1, x2, y2;
    
    Line(int a = 0, int b = 0, int c = 0, int d = 0) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
};

// Check intersection between horizontal (H) & vertical (V)
bool doesIntersect(const Line &H, const Line &V) {
    int hy = H.y1;
    int hxMin = min(H.x1, H.x2);
    int hxMax = max(H.x1, H.x2);

    int vx = V.x1;
    int vyMin = min(V.y1, V.y2);
    int vyMax = max(V.y1, V.y2);

    return (vx >= hxMin && vx <= hxMax && hy >= vyMin && hy <= vyMax);
}

int main() {
    int n;
    cin >> n;

    vector<Line> horizontalLines, verticalLines;

    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        Line L(a, b, c, d);

        // Horizontal line → same y-coordinate
        if(b == d) {
            horizontalLines.push_back(L);
        }
        else {
            verticalLines.push_back(L);
        }
    }

    long long countRectangles = 0;

    // Pick pairs of horizontal lines
    for(int i = 0; i < (int)horizontalLines.size(); i++) {
        for(int j = i + 1; j < (int)horizontalLines.size(); j++) {

            int commonVerticals = 0;

            for(const Line &V : verticalLines) {
                if(doesIntersect(horizontalLines[i], V) &&
                   doesIntersect(horizontalLines[j], V)) {
                    commonVerticals++;
                }
            }

            if(commonVerticals >= 2) {
                countRectangles += 1LL * commonVerticals * (commonVerticals - 1) / 2;
            }
        }
    }

    cout << countRectangles;
    return 0;
}



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // Pass 1: Top-Left → Bottom-Right
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                } else {
                    if(i > 0)
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }

        // Pass 2: Bottom-Right → Top-Left
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i < n - 1)
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if(j < m - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }
        }

        return dist;
    }
};
