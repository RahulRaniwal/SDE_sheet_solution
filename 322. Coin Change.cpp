#include"bits/stdc++.h"
class Solution {
public:
    // recursive
    int solve1(vector<int>& coins , int amount){
        // base case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int temp = solve1(coins , amount-coins[i]);
            if(temp != INT_MAX){
                ans = min(ans , temp+1);
            }
        }
        return ans;
    }
    
    // memoization
    int solve2(vector<int>& coins , int amount , vector<int>& dp){
        if(amount < 0){
            return INT_MAX;
        }
        // check if ans already exist
        if(dp[amount] != -1){
            return dp[amount];
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int temp = solve2(coins , amount-coins[i] , dp);
            if(temp != INT_MAX){
                ans = min(ans , temp+1);
            }
        }
        dp[amount] = ans;
        return ans;
    }
    
    // tabulation
    int solve3(vector<int>& coins , int amount){
        vector<int>dp(amount+1 , INT_MAX);
        
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i-coins[j] >= 0 and dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i] , dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount];
    }
    
    // main
    int coinChange(vector<int>& coins, int amount) {
        // // recursive
        // int res = solve1(coins , amount);
        // if(res == INT_MAX){
        //     return -1;
        // }
        // return res;
        
//         // memoization
//         vector<int>dp(amount+1 , -1);
//         dp[0] = 0;
//         int res = solve2(coins , amount , dp);
//         if(res == INT_MAX){
//             return -1;
//         }
//         return dp[amount];
        
        // tabulation
        int ans = solve3(coins , amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }
};
