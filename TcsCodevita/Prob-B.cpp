#include<iostream>
#include<vector>

using namespace std; 

void gravi(vector<vector<char>>& grid){
     int row=grid.size() ;
     int col=grid[0].size() ;
     
     for(int j=0;j<col;j++){
        int emp=row-1;
        for(int i=row-1;i>=0;i--){
           if(grid[i][j]=='*'){
             swap(grid[i][j],grid[emp][j]) ;
             emp--; 
           }
        }
     }
}

vector<vector<char>> rotate90_right(vector<vector<char>>& grid){
      int row=grid.size() ;
     int col=grid[0].size() ;
     
     vector<vector<char>>ans(col,vector<char>(row)) ;
     
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          ans[j][row-i-1]=grid[i][j];
          
        }
     }
     
     return ans ;
     
     
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
     return ans; 
    
}


int main(){

    int m , n;
    cin>>m>>n ;
    
    vector<vector<char>> grid(m,vector<char>(n)) ;
    
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
      cin>> s;
      
      if(s=="right"){
         grid=rotate90_right(grid) ;
         
      }else{
         grid=rotate90_left(grid) ;
      }
      gravi(grid) ; 
    }
    
    for(auto& row:grid){
       for(auto& ch:row){
          cout<<ch<<" "  ; 
       }
       cout<<endl ; 
    }
    
    
    
   return 0 ; 
}