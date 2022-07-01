class Solution {
public:
    // using floyad cycle in which we traverse by slow values indexat every iteration
    int findDuplicate(vector<int>& nums){
        
        int slow = nums[0];
        int fast = nums[0];
        
       do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/************** TC O(n) **********************/
