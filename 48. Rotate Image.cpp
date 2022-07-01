class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse the array 
        reverse(matrix.begin() , matrix.end());        
        // swap the symmetry element
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        } 
    }
};
