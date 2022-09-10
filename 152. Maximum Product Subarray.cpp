class Solution {
public:
    // similar to max sum of subarray
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN; int p = 1;
        // start traversing from left
        for(int i = 0; i < nums.size(); i++){
            if(p == 0){
                p = 1;
            }
            p *= nums[i];
            maxProduct = max(maxProduct , p);
        }
        // start taversing from right
        p = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(p == 0){
                p = 1;
            }
            p *= nums[i];
            maxProduct = max(maxProduct , p);
        }
        return maxProduct;
    }
};
