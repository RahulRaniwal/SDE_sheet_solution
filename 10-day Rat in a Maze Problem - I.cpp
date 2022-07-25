
class Solution{
    public:
    bool isSafe(vector<vector<int>> &m , vector<vector<bool>> &vis , int row , int col , int n){
        if(row < 0 or row >= n or col < 0 or col >= n or m[row][col] != 1 or vis[row][col] == 1){
            return false;
        }
        return true;
    }
    
    void findPath(vector<vector<int>> &m , vector<vector<bool>> &vis , int row , int col , int n , 
                    string path , vector<string> &ans){
        if(row == n-1 and col == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[row][col] = 1;
        // check for down
        if(isSafe(m , vis , row+1 , col , n)){
            findPath(m , vis , row+1 , col , n , path+"D" , ans);
        }
        // check for left
        if(isSafe(m , vis , row , col-1 , n)){
            findPath(m , vis ,row , col-1 , n , path+"L" , ans);
        }
        // check for right
        if(isSafe(m , vis , row , col+1 , n)){
            findPath(m , vis , row , col+1 , n , path+"R" , ans);
        }
        // check for up
        if(isSafe(m , vis , row-1 , col , n)){
            findPath(m , vis , row-1 , col , n , path+"U" , ans);
        }
        // backtrack
        vis[row][col] = 0;
    
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> vis(n , vector<bool>(n , 0));
        vector<string> ans;
        string path = "";
        
        // edge case
        if(m[0][0] == 0 or m[n-1][n-1] == 0){
            return ans;
        }
        findPath(m , vis , 0 , 0 , n , path , ans);
        return ans;
    }
};
