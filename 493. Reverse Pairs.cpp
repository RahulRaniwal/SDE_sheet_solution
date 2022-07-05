class Solution {
public: 
    // merge function
    int merge(vector<int>& nums , int left , int mid , int right){
        int pairCount = 0;
        int j = mid+1;
        
        for(int i = left; i <= mid; i++){
            while(j <= right and nums[i] > 2ll * nums[j]){
                j++;
            }
            pairCount += j-(mid+1);
        }
        vector<int>temp;
        int i = left; 
        j = mid+1;
        while(i <= mid and j <=right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= right){
            temp.push_back(nums[j++]);
        }
        
        for(int i = left; i <= right; i++){
            nums[i] = temp[i-left];
        }
        return pairCount;
    }
    // using merge sort
    int mergeSort(vector<int>& nums , int left , int right){
        // base case
        if(left >= right){
            return 0;
        }
            int pairCount = 0;
            int mid = (left+right)/2;
            pairCount += mergeSort(nums , left , mid);
            pairCount += mergeSort(nums , mid+1 , right);
            pairCount += merge(nums , left , mid , right);
            return pairCount;
        
    }
  // main fucntion
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size()-1);
    }
};

/*********** TC O(nlogn)+O(n) == O(nlogn)  ****************/
