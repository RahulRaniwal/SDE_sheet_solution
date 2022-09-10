class Solution {
public:
    // recursive
    int solve1(vector<int>& nums , int n , int curr , int prev){
        // base case
        if(curr == n){
            return 0;
        }
        int include = 0;
        if(prev == -1 or nums[curr] > nums[prev]){
            include = 1 + solve1(nums , n , curr+1,  curr);
        }
        int exclude = solve1(nums , n , curr+1 , prev);
        return max(include , exclude);
    }
    
    // memoization
    int solve2(vector<int>& nums , int n , int curr , int prev , vector<vector<int>>& dp){
        // base case
        if(curr == n){
            return 0;
        }
        // check if ans already exist
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev];
        }
        
        int include = 0;
        if(prev == -1 or nums[curr] > nums[prev]){
            include = 1 + solve2(nums , n , curr+1 , curr , dp);
        }
        int exclude = solve2(nums , n , curr+1 , prev , dp);
        
        dp[curr][prev+1] = max(include , exclude);
        return dp[curr][prev+1];
    }
    
    // tabulation
    int solve3(vector<int>& nums , int n){
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev>= -1; prev--){
                
                int include = 0;
                if(prev == -1 or nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(include , exclude);
            }
        }
        return dp[0][0];
    }
    // main
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // // recursive
        // return solve1(nums , n , 0 , -1);
        
        // // memoization
        // vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        // return solve2(nums , n , 0 , -1 , dp);
        
        //tabulation
        return solve3(nums , n);
    }
};


/*****************  DP with memoization *****************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp with binary search
        int n = nums.size();
        
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int idx = lower_bound(ans.begin() , ans.end() , nums[i])-ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};
