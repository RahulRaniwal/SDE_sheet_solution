class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // base case
        if(nums.size() <= 1){
            return;
        }       
        // traverse from back and find v[i] < v[i+1]
        int n = nums.size() , idx1 = 0 , idx2 = 0;
        for(idx1 = n-2; idx1 >= 0; idx1--){
            if(nums[idx1] < nums[idx1+1]){
                break;
            }
        }    
        // if such break point doesn't exist
        if(idx1 < 0){
            reverse(nums.begin() , nums.end());
        }else{
            
        // again traverse from back and find v[idx2] > v[idx1]
            for(idx2 = n-1; idx2 > idx1; idx2--){
                if(nums[idx2] > nums[idx1]){
                    break;
                }
            }
        // swap idx1 and idx2 element
        swap(nums[idx1] , nums[idx2]);
        // than reverse the array form idx to last index
        reverse(nums.begin()+idx1+1 , nums.end());
        }
    }
};

/********************  TC = O(n)   *****************************/
