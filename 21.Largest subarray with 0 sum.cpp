class Solution{
    public:
    // using hashing and prefix sum
    int maxLen(vector<int>&A, int n){   
        unordered_map<int,int> map;
        int maxLength = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                maxLength = i+1;
            }else if(map.find(sum) != map.end()){
                maxLength = max(maxLength , i - map[sum]);
            }else{
                map[sum] = i;
            }
        }
        return maxLength;
    }
};

/*************** TC O(n) **************/
/*************** SC O(n) *************/
