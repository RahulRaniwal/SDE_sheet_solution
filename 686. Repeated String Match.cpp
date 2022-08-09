class Solution {
public:
    
    bool match(string x , string y){
        
        int n = x.length();
        int m = y.length();
        
        for(int i = 0; i <= n-m; i++){
            int j;
            for(j = 0; j < m; j++){
                if(x[i+j] !=y[j]){
                    break;
                }
            }
                if(j == m){
                    return true;
                }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        
        int count = 0;
        string comp = "";
        
        while(comp.length() < b.length()){
            comp += a;
            count++;
        }
        
        if(match(comp , b)){
            return count;
        }
        if(match(comp+a , b)){
            return count+1;
        }
        return -1;
    }
};
