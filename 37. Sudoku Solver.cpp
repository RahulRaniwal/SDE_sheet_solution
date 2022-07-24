class Solution {
public:
    bool isSafe(vector<vector<char>>& board , int row , int col , char value){
        // check for row and col
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][col] == value){
                return false;
            }
            if(board[row][i] == value){
                return false;
            }
        }
        // check for sub matrix
        int newRow = (row/3)*3;
        int newCol = (col/3)*3;
        for(int i = newRow; i < newRow+3; i++){
            for(int j = newCol; j < newCol+3; j++){
                if(board[i][j] ==value){
                    return false;
                }
            }
        }
        return true;
    }
    
    //solve helper
    bool solveSudoku(vector<vector<char>>& board , int row , int col , int n){
        if(row == n){
            return true;
        }
        if( col == n){
            return solveSudoku(board , row+1, 0 , n);
        }
        if(board[row][col] != '.'){
            return solveSudoku(board , row , col+1 , n);
        }
        for(int val = '1'; val <= '9'; val++){
            if(isSafe(board , row , col , val)){
                board[row][col] = val;  // place value
                
                if(solveSudoku(board , row , col+1 , n)){
                    return true;
                }
                board[row][col] = '.';  // backtrack
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveSudoku(board , 0 , 0 , n);
        
    }
};
