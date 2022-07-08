class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n = s.length();
        int left = 0 , right = 0;
        int maxLen = INT_MIN;
        unordered_map<char,int> map;
        
        while(right < n){
            map[s[right]]++;
            
            if(map[s[right]] == 1){
                maxLen = max(maxLen , (right-left+1));
            }else if(map[s[right]] > 1){
                while(map[s[right]] > 1){
                    map[s[left]]--;
                    left++;
                }
            }
            right++;
        }
        return maxLen;
        
    }
};

/************ TC O(N)  SC O(n) ***************/
