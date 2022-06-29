class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascals;      
        for(int i = 0; i < numRows; i++){
            vector<int> temp(i+1 , 1);
            for(int j = 1; j < i; j++){
                temp[j] = pascals[i-1][j] + pascals[i-1][j-1];
            }
            pascals.push_back(temp);
        }
        return pascals;
    }
};
