class Solution {
public:
    void solve1(vector<int>& candidates , int target , vector<vector<int>>& ans , vector<int>& temp , int idx){
        // base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx and candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
                temp.push_back(candidates[i]);
                solve1(candidates , target-candidates[i] , ans , temp , i+1);
                temp.pop_back();    // backtrack   
        }   
    }
    // main
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> temp;
        solve1(candidates , target , ans , temp , 0);
        return ans;
    }
};
