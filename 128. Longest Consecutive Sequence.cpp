class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s (nums.begin() , nums.end());
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int currLen = 1;
            int left = nums[i] , right = nums[i];
            
            while(s.find(left-1) != s.end()){
                currLen++;
                s.erase(left-1);
                left--;
            }
            while(s.find(right+1) != s.end()){
                currLen++;
                s.erase(right+1);
                right++;
            }
            maxLen = max(maxLen , currLen);
        }
        return maxLen;
    }
};

/*********** TC O(n)  ***********/
