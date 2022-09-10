class Solution {
public:
    // recursive
    int solve1(string text1 , string text2 , int idx1 , int idx2){
        // base case
        if(idx1 < 0 or idx2 < 0){
            return 0;
        }
        // if both the character of string matches
        if(text1[idx1] == text2[idx2]){
            return 1 + solve1(text1 , text2 , idx1-1 , idx2-1);
        }
        return max(solve1(text1 , text2 , idx1-1 , idx2) , solve1(text1 , text2 , idx1 , idx2-1));
    }
    
    // memoization
    int solve2(string text1 , string text2 , int idx1 , int idx2 , vector<vector<int>>& dp){
        // base case
        if(idx1 < 0 or idx2 < 0){
            return 0;
        }
        // check if ans already exist
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        // if both char matches
        if(text1[idx1] == text2[idx2]){
            dp[idx1][idx2] = 1 + solve2(text1 , text2 , idx1-1 , idx2-1 , dp);
            return dp[idx1][idx2];
        }
        return dp[idx1][idx2] = max(solve2(text1 , text2 , idx1-1 , idx2 , dp) , 
                                     solve2(text1 , text2 , idx1 , idx2-1 , dp));
    }
    
    // tabulation
    int solve3(string text1 , string text2 , int n1 , int n2){
        // vector declaration
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1 , 0));
        
        for(int idx1 = n1-1; idx1 >= 0; idx1--){
            for(int idx2 = n2-1; idx2 >= 0; idx2--){
                // if both char matches
                if(text1[idx1] == text2[idx2]){
                    dp[idx1][idx2] = 1 + dp[idx1+1][idx2+1];
                }else{
                   dp[idx1][idx2] = max(dp[idx1+1][idx2] , dp[idx1][idx2+1]); 
                }
                
            }
        }
        return dp[0][0];
    }
    
    // main
    int longestCommonSubsequence(string text1, string text2){
        
        int n1 = text1.length();
        int n2 = text2.length();
        
        // // recursive
        // return solve1(text1 , text2 , n1-1 , n2-1);
        
        // // memoization
        // vector<vector<int>> dp(n1 , vector<int>(n2 , -1));
        // return solve2(text1 , text2 , n1-1 , n2-1 , dp);
        
        // tabulation
        return solve3(text1 , text2 , n1 , n2);
        
    }
};
