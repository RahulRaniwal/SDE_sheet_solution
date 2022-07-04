class Solution {
public:
    // recursive
    int uniquePaths(int m , int n , int x , int y){
        // base case
        if((x >= m) or (y >= n)){
            return 0;
        }
        if((x == m-1) and (y == n-1)){
            return 1;
        }
        int movingRight = uniquePaths(m , n , x , y+1);
        int movingDown  = uniquePaths(m , n , x+1 , y);
        return movingRight+movingDown;
    }
    // memoization
    int uniquePaths(int m , int n , int x , int y , vector<vector<int>>& dp){
        // base case
        if((x>= m) or (y >= n)){
            return 0;
        }
        if((x == m-1) and (y == n-1)){
            return 1;
        }
        // check if result already exist or not
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int movingRight = uniquePaths(m , n , x , y+1 , dp);
        int movingDown = uniquePaths(m , n , x+1 , y , dp);
        dp[x][y] = movingRight + movingDown;
        return dp[x][y];
    }
    
    // using combinatrix
    int solution(int m , int n){
        int N = m+n-2;
        int R = m-1;
        double ans = 1.0;
        
        for(int i = 1; i <= R; i++){
            ans = ans*(N-R+i)/i;
        }
        return (int)ans;
    }
    
    // main
    int uniquePaths(int m, int n) {
        // recursive solution
        // return uniquePaths(m , n , 0 , 0);
        
        // memoization
        // vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        // return uniquePaths(m , n , 0 , 0 , dp);
        
        // using combinatrix
        return solution(m , n);
    }
};
