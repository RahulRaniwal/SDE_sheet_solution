class Solution {
public:
    // boyer moore algo
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = -1 , num2 = -1 , cnt1 = 0 , cnt2 = 0 , size = nums.size();        
        for(int i = 0; i < size; i++){
            
            if(nums[i] == num1){
                cnt1++;
            }else if(nums[i] == num2){
                cnt2++;
            }else if(cnt1 == 0){
                num1 =nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0){
                num2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }  
        
        cnt1 = 0 , cnt2 = 0;
        for(auto val : nums){
            if(val == num1){
                cnt1++;
            }else if(val == num2){
                cnt2++;
            }
        }
        vector<int>ans;     // ans vector
        if(cnt1 > size/3){
            ans.push_back(num1);
        }
    if(cnt2 > size/3 and num2 != num1){
            ans.push_back(num2);
        }
        return ans;
    }
};

/************** TC O(n) SC = O(1) ************/
