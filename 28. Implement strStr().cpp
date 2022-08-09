class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0){
            return 0;
        }
        if(haystack.length() < needle.length()){
            return -1;
        }
        
        int i;
        int j;
        for(i = 0; i <= haystack.length()-needle.length(); i++){
            for(j = 0; j < needle.length(); j++){
                
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == needle.length()){
                return i;
            }
        }
        return -1;
    }
};
