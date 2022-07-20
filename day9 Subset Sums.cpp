class Solution
{
public:
    // recursive approach
    void solve1(vector<int> arr , int idx , vector<int>& ans , int output){
        // base case
        if(idx < 0){
            ans.push_back(output);
            return;
        }
      // including idx th value in output
        solve1(arr , idx-1 , ans , output+arr[idx]);
      // excluding idx th value in output
        solve1(arr , idx-1 , ans , output);
        
    }
    vector<int> subsetSums(vector<int> arr, int N){      
        vector<int> ans;
        int output = 0;
        solve1(arr , N-1 , ans , output);
        return ans;
    }
};
