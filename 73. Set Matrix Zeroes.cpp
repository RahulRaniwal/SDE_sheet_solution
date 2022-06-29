class Solution {
public:
  // Using Extra Space
    void setZeroes(vector<vector<int>>& matrix){       
        // maintain in which row or col i have seen zero
        vector<int> rows(matrix.size() , 0);
        vector<int> cols(matrix[0].size() , 0);
        // iterate over matrix array to keep track in which cell i have found zero
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        // now put zero in row and col of cell where we found a zero
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                
                if(rows[i] == 1 or cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        } 
    }
};

/***********   TC = O(m*n)  SC = O(row size) + O(column size)  ******************/
