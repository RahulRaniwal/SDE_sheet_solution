class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1 , i = 1 , dup = nums[0];     
        while(i < nums.size()){
            if(nums[i] == dup){
                i++;
            }else{
                nums[idx] = nums[i];
                dup = nums[i];
                idx++ , i++;
            }
        }
        return idx;
    }
};
