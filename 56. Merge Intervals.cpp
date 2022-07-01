class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        // sort intervals array
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int idx = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(ans[idx][1] >= intervals[i][0]){
                ans[idx][1] = max(ans[idx][1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
                idx++;
            }
        }
        return ans;
    }
};

/************ TC O(n) ************/
