class Solution {
public:
    // recursive
    int solve1(vector<vector<int>>& grid , int row , int col , int myrow , int mycol){
        // base case
        if(myrow == row-1 and mycol == col-1){
            return grid[myrow][mycol];
        }
        if(myrow == row or mycol == col){
            return 1e5;
        }
        int goDown =  solve1(grid , row , col , myrow+1 , mycol) + grid[myrow][mycol];
        int goRight = solve1(grid , row , col , myrow , mycol+1) + grid[myrow][mycol];
        
        return min(goDown , goRight);
    }
    
    
    // memoization
    int solve2(vector<vector<int>>&grid , int row , int col , vector<vector<int>>& dp){
        // base case
        if(row == 0 and col == 0){
            return grid[row][col];
        }
        if(row < 0 or col < 0){
            return 1e5;
        }
        // check if answer already exist
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int goUp = solve2(grid , row-1 , col , dp) + grid[row][col];
        int goLeft = solve2(grid , row , col-1 , dp) + grid[row][col];
        
        return dp[row][col] = min(goUp , goLeft);
    }
    
    // tabulation
    int solve3(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> dp(rows , vector<int>(cols , 0));
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                
                if(row == 0 and col == 0){
                    dp[row][col] = grid[0][0];
                }else{
                    int goUp = 0;
                    if(row > 0){
                        goUp = grid[row][col] + dp[row-1][col];
                    }else{
                        goUp = grid[row][col] + 1e5;
                    }
                    
                    int goLeft = 0;
                    if(col > 0){
                        goLeft = grid[row][col] + dp[row][col-1];
                    }else{
                        goLeft = grid[row][col] + 1e5;
                    }
                    // compare and push into dp
                    dp[row][col] = min(goUp , goLeft);
                }
                
                
            }
        }
        
        return dp[rows-1][cols-1];
    }
    // main
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // // recursive
        // return solve1(grid , row , col , 0  , 0);
        
        // // memoization
        // vector<vector<int>> dp(row , vector<int>(col , -1));
        // return solve2(grid , row-1 , col-1 , dp);
        
        // tabulation
        return solve3(grid);
    }
};
