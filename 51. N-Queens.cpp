class Solution {
public:
    bool isSafe(vector<string>& chess , int row , int col , int n){
        // check for upper rows
        for(int i = row-1; i >= 0; i--){
            if(chess[i][col] == 'Q'){
                return false;
            }
        }
        // check for left upper diagonal
        for(int i = row-1 , j = col-1; i >= 0 and j >= 0; i-- , j--){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
        // check for right uper diagonal
        for(int i = row-1 , j = col+1; i >= 0 and j < n; i-- , j++){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    // place queen 
    void placeQ(vector<string>&chess , int row , int n , vector<vector<string>>& ans){
        
        // base case
        if(row == n){
            ans.push_back(chess);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isSafe(chess , row , i , n)){
                chess[row][i] = 'Q';  // place queen
                placeQ(chess , row+1 , n , ans);
                chess[row][i] = '.';  // backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string> chess;
        string s(n , '.');
        for(int i = 0; i < n; i++){
            chess.push_back(s);
        }
        vector<vector<string>> ans;
        placeQ(chess , 0 , n , ans);
        return ans;
    }
};
