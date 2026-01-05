#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Apply gravity: stones '*' fall down in each column
void applyGravity(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    for(int col = 0; col < n; col++) {
        int empty = m - 1;
        for(int row = m - 1; row >= 0; row--) {
            if(box[row][col] == '*') {
                swap(box[row][col], box[empty][col]);
                empty--;
            }
        }
    }
}

// Rotate the box 90 degrees right
vector<vector<char>> rotateRight(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> rotated(n, vector<char>(m));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            rotated[j][m - i - 1] = box[i][j];
        }
    }
    return rotated;
}

// Rotate the box 90 degrees left
vector<vector<char>> rotateLeft(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> rotated(n, vector<char>(m));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            rotated[n - j - 1][i] = box[i][j];
        }
    }
    return rotated;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<char>> box(M, vector<char>(N));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> box[i][j];

    int K;
    cin >> K;

    applyGravity(box); // initial gravity

    while(K--) {
        string instr;
        cin >> instr;

        if(instr == "right") {
            box = rotateRight(box);
        } else {
            box = rotateLeft(box);
        }

        applyGravity(box); // gravity after each rotation
    }

    // Print final result
    for(auto &row : box) {
        for(auto &ch : row)
            cout << ch << " ";
        cout << "\n";
    }

    return 0;
}


// this is my code my first submission 


#include<iostream>
#include<vector>

using namespace std; 

void gravi(vector<vector<char>>& grid){
     int row=grid.size() ;
     int col=grid[0].size() ;
     
     for(int i=0;i<row;i++){
         int empty=row-1;
        for(int j=row-1;j>=0;j--){
        	if(grid[i][j]=='*'){
               swap(grid[i][j],grid[empty][i]) ; 
               empty-- ; 
            }
        }
     }
}

vector<vector<char>> rotate90_right(vector<vector<char>>& grid){
      int row=grid.size() ;
     int col=grid[0].size() ;
     vector<vector<char>> ans(col,vector<char>(row)) ;
     
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans[j][row-i-1]=grid[i][j];
        }
     }
     
     return ans;
     
}

vector<vector<char>> rotate90_left(vector<vector<char>>& grid){
      int row=grid.size() ;
     int col=grid[0].size() ;
     
     vector<vector<char>> ans(col,vector<char>(row)) ;
     
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           ans[col-j-1][i]=grid[i][j];
        }
     }
     
     return ans ; 
}


int main(){

    int m , n;
    cin>>m>>n ;
    
    vector<vector<char>> box(m,vector<char>(n)) ;
    
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           cin>>grid[i][j];
           
       }
    }
    
    int k ;
    cin>>k ;
    
    gravi(grid) ;
    
    while(k--){
       string s ;
       cin>>s ;
       
       if(s=="right"){
          grid=rotate90_right(grid) ; 
       }else{
           grid=rotate90_left(grid) ; 
       }
       gravi(grid) ;  
    }
    
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
          cout<<grid[i][j]<<" " ; 
       }
       cout<<endl ; 
    }
    
    
   return 0 ; 
}




#include <bits/stdc++.h>
using namespace std;

void gravi(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    for (int j = 0; j < col; j++) {
        int empty = row - 1;
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][j] == '*') {
                swap(grid[i][j], grid[empty][j]);
                empty--;
            }
        }
    }
}

vector<vector<char>> rotate90_right(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<char>> ans(col, vector<char>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans[j][row - i - 1] = grid[i][j];
        }
    }
    return ans;
}

vector<vector<char>> rotate90_left(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<char>> ans(col, vector<char>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans[col - j - 1][i] = grid[i][j];
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int k;
    cin >> k;

    gravi(grid);

    while (k--) {
        string s;
        cin >> s;
        if (s == "right") {
            grid = rotate90_right(grid);
        } else {
            grid = rotate90_left(grid);
        }
        gravi(grid);
    }

    for (auto &row : grid) {
        for (auto &c : row)
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

void gravi(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    for (int j = 0; j < col; j++) {
        int empty = row - 1;
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][j] == '*') {
                swap(grid[i][j], grid[empty][j]);
                empty--;
            }
        }
    }
}

vector<vector<char>> rotate90_right(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<char>> ans(col, vector<char>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans[j][row - i - 1] = grid[i][j];
        }
    }
    return ans;
}

vector<vector<char>> rotate90_left(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<char>> ans(col, vector<char>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans[col - j - 1][i] = grid[i][j];
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int k;
    cin >> k;

    gravi(grid);

    while (k--) {
        string s;
        cin >> s;
        if (s == "right") {
            grid = rotate90_right(grid);
        } else {
            grid = rotate90_left(grid);
        }
        gravi(grid);
    }

    for (auto &row : grid) {
        for (auto &c : row)
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}
