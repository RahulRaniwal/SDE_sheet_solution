class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n , 0);
        vector<int> suff(n , 0);
        
        int preMax = height[0];
        int suffMax = height[n-1];
        for(int i = 0; i < n; i++){
            preMax = max(preMax , height[i]);
            pre[i] = preMax;
        }
        for(int i = n-1; i >= 0; i--){
            suffMax = max(suffMax , height[i]);
            suff[i] = suffMax;
        }
        
        // gaian traverse in the array and create answer
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(pre[i] , suff[i])-height[i];
        }
        return ans;
    }
};

/*************************** TC O(n) SC O(n) *********************************/


/********************* Approach 2 **********************************/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int leftMax = 0;
        int rightMax = 0;
        int left = 0 , right = height.size()-1;
        int ans = 0;
        while(left <= right){
            
            if(height[left] <= height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }else{
                    ans += leftMax-height[left];
                }
                left++;
            }else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    ans += rightMax-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
