class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.size() == 0){
            return;
        }
        if(nums2.size() == 0){
            return;
        }
        
        int idx1 = m-1 , idx2 = n-1 , i = m+n-1;
        
        while(idx1 >= 0 and idx2 >= 0){
            
            if(nums1[idx1] > nums2[idx2]){
                nums1[i--] = nums1[idx1--];
            }else{
                nums1[i--] = nums2[idx2--];
            }
        }
        
        while(idx1 >= 0){
            nums1[i--] = nums1[idx1--];
        }
        while(idx2 >= 0){
            nums1[i--] = nums2[idx2--];
        }
    }
};
