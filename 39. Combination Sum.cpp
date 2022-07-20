class Solution {
public:
    // recursive solution
    void solve1(vector<int>& candidates , int target , vector<vector<int>>& ans , vector<int>& temp , int                                                                                                           idx){
        // base case
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == candidates.size()){
            return;
        }
        
        // including value
        temp.push_back(candidates[idx]);
        solve1(candidates , target-candidates[idx] , ans , temp , idx);
        temp.pop_back();    // backtrack
        // excluding value
        solve1(candidates, target , ans , temp , idx+1);
    }
    // main
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> temp;
        solve1(candidates , target , ans , temp , 0);
        return ans;
    }
};
