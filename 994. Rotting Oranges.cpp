class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // if grid is empty
        if(grid.empty()){
            return 0;
        }
        
        int mins = 0 , total = 0 , cnt = 0;
        int rows = grid.size() , cols = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 0){
                    total++;
                }
                if(grid[i][j] == 2){
                    q.push(make_pair(i , j));
                }
            }
        }
        
        int dx[4] = {0 , 0 , 1 , -1};
        int dy[4] = {1 , -1 , 0 , 0};
        
        while(!q.empty()){
            int size = q.size();
            cnt += size;
            
            while(size--){
                int p1 = q.front().first;
                int p2 = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = dx[i]+p1;
                    int y = dy[i]+p2;
                    if(x < 0 or y < 0 or x >= rows or y >= cols or grid[x][y] != 1){
                        continue;
                    }
                    grid[x][y] = 2;
                    q.push(make_pair(x , y));
                }
            }
            
            if(!q.empty()){
                mins++;
            }
        }
        
        return total == cnt ? mins : -1;
    }
};
