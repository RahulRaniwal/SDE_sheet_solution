class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        for(int i = 0; i < n-2; i++){
            if(i != 0 and nums[i] == nums[i-1]){
                continue;
            }
            int target = (-1*nums[i]);
            int left = i+1 , right = n-1; 
            while(left < right){ 
                int sum = (nums[left]+nums[right]);
                if(sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else{  // we found the triplet
                    ans.push_back({nums[i] , nums[left] , nums[right]});
                    left++ , right--;
                    
                         // to remove duplicacy
                    while(left < right and nums[left] == nums[left-1]){
                            left++;
                        }
                     while(left < right and nums[right] == nums[right+1]){
                            right--;
                        }
                    }  
                }
         }
        return ans;
    }
};
