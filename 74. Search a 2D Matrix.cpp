class Solution {
public:
    // by flattnening the 2d array into 1d array
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> vect((rows*cols) , 0);
        
        // flatten the array
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                vect[(i*cols)+j] = matrix[i][j];
            }
        }
        
        /******* Binary search *******/
        int low = 0;
        int high = vect.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(vect[mid] == target){
                return true;
            }else if(vect[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};
/************* TC O(nlogn)  where n is size of 1-d array **************/
