class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin() , strs.end());
        string ans = "";
        
        string test = strs[0];
        for(int i = 0; i < test.length(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(test[i] != strs[j][i]){
                    return ans;
                }
            }
            ans += test[i];
        }
        return ans;
    }
};
