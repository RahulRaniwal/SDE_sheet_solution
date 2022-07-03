/************** Approach 1 **************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        
        int ans = 0;
        for(auto val : map){
            if(val.second > map[ans]){
                ans = val.first;
            }
        }
        return ans;
    }
};

/********** TC O(n)  SC O(n) *******************/

/****************** Approach 2 ******************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0 , count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                ans = nums[i];
            }
            if(nums[i] == ans){
                count++;
            }else{
                count--;
            }
        }
        return ans;
    }
};

/************* TC O(n) SC O(1) *************/
