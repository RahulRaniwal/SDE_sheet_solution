class Solution {
public:
    void solve1(vector<int>&nums , int idx , vector<vector<int>>& ans , vector<int> temp , 
                                                                                set<vector<int>>& s){
        // base case
        if(idx < 0){
            if(s.find(temp) == s.end()){
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }
        
        // including idx th index value into temp
        temp.push_back(nums[idx]);
        solve1(nums , idx-1 , ans , temp , s);
        temp.pop_back();
        // excluding idx th index value 
        solve1(nums , idx-1 , ans , temp , s);
    }
    // main
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin() , nums.end());
        // sorting is done so that set does not treat {1,2,3} and {1,3,2} different string
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> s;
        solve1(nums , n-1 , ans , temp , s);
        return ans;
    }
};
