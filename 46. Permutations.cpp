class Solution {
public:
    //recursive function
    void solve1(vector<int> nums , int idx , vector<vector<int>>& ans){
        // base case
        if(idx == nums.size()-1){
            ans.push_back(nums);
            return;
        }       
        for(int i = idx; i < nums.size(); i++){
            swap(nums[i] , nums[idx]);
            solve1(nums , idx+1 , ans);
            swap(nums[i] , nums[idx]);  // backtrack
        }
    }
    // main function
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve1(nums , 0 , ans);
        return ans;
    }
};
