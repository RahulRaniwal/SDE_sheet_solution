class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high){
            int mid = (low + high)/2;
            int idx;
            if(mid%2 == 0){
                idx = mid+1;
            }else{
                idx = mid-1;
            }
            
            // check
            if(nums[mid] == nums[idx]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};
