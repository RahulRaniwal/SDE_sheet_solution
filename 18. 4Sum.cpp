class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n-3; i++){
            // for removing duplicacy
            if(i != 0 and nums[i] == nums[i-1]){
                continue;
            }
            
            for(int j = i+1; j < n-2; j++){
                // to remove duplicacy
                if(j != i+1 and nums[j] == nums[j-1]){
                    continue;
                }
                long long  smallTarget = target - (nums[j] + nums[i])*1ll;
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                     long long  sum = (nums[left] + nums[right])*1ll;
                    
                    if(sum > smallTarget){
                        right--;
                    }else if(sum < smallTarget){
                        left++;
                    }else{
                        vector<int>temp = {nums[i] , nums[j] , nums[left] , nums[right]};
                        ans.push_back(temp);                    
                        left++;
                        right--;
                        
                        // for removing duplicacy
                        while(left < right and nums[left] == nums[left-1]){
                            left++;
                        }
                        while(left < right and nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*********** TC O(n^3) ************/
