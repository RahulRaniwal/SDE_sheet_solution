class Solution {
public:
    // counting sort
    void sortColors(vector<int>& nums) { 
        int count0 = 0 , count1 = 0 , count2 = 0; 
      // traverse the array to keep count of number of 0 , 1 and 2.
        for(int i = 0; i < nums.size(); i++){
            switch(nums[i]){
                case 0:
                    count0++;
                    break;
                case 1:
                    count1++;
                    break;
                case 2:
                    count2++;
                    break;
            }
        }
        // traverse in the array again and put zeros first then 1 and at last 2
        int i = 0;
        while(count0 > 0){
            nums[i++] = 0;
            count0--;
        }
        while(count1 > 0){
            nums[i++] = 1;
            count1--;
        }
        while(count2 > 0){
            nums[i++] = 2;
            count2--;
        }
    }
};

/************************* TC O(n)  ****************************/
