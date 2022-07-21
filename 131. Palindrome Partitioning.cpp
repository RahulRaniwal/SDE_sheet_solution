class Solution {
public:
    // check palindrome
    bool isPalindrome(string s , int si , int ei){
        while(si <= ei){
            if(s[si] != s[ei]){
                return false;
            }
            si++; ei--;
        }
        return true;
    }
    
    // recursive approach
    void solve1(string s , int idx , vector<vector<string>>& ans , vector<string>& temp){
        // base case
        if(idx == s.length()){
            ans.push_back(temp);
        }
        
        for(int i = idx; i < s.length(); i++){
            if(isPalindrome(s , idx , i)){
                temp.push_back(s.substr(idx , i-idx+1));
                solve1(s , i+1 , ans , temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve1(s , 0 , ans , temp);
        return ans;
    }
};
