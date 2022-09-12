class Solution {
public:
    // recursive
    bool solve1(vector<int>& nums , int n , int idx , int target){
        // base case
        if(idx == n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        
        bool pick = solve1(nums , n , idx+1 , target-nums[idx]);
        bool notPick = solve1(nums , n ,idx+1 , target);
        return pick or notPick;
    }
    
    // memoization
    bool solve2(vector<int>& nums , int n , int idx , int target , vector<vector<int>>& dp){
        // base case
        if(idx == n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        // check if answer already exist
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        int pick = solve2(nums , n , idx+1 , target-nums[idx] , dp);
        int notPick = solve2(nums , n , idx+1 , target , dp);
        
        return dp[idx][target] = pick or notPick;
    }
    
    // tabulation
    bool solve3(vector<int>& nums , int n , int target){
        
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int t = 0; t <= target; t++){
                int pick = 0;
                if(t-nums[idx] >= 0){
                    pick = dp[idx+1][t-nums[idx]];
                }
                int notPick = dp[idx+1][t];
                
                dp[idx][t] = pick or notPick;
            }
        }
        return dp[0][target];
    }
    
    // main
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        // sum of all elem
        for(auto val : nums){
            total += val;
        }
        // if total is odd then return false it can not be partitioned
        if(total%2 != 0){
            return 0;
        }
        int target = total/2;
        // // recursive
        // return solve1(nums , n , 0 , total/2);
        
        // // // memoization
        // vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        // return solve2(nums , n , 0 , target , dp);
        
        // tabulation
        return solve3(nums , n , target);
    }
};
