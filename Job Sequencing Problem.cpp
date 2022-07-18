class Solution 
{
    public:
    
    static bool comp(Job a , Job b){
        return(a.profit > b.profit);
    }
    // main function
    vector<int> JobScheduling(Job arr[], int n) { 
        
        // sort on the bases of profit
        sort(arr , arr+n , comp);
        int deadline = 0;
        for(int i = 0; i < n; i++){
            deadline = max(deadline , arr[i].dead);
        }
        
        vector<int> slot(deadline+1 , -1);
        int maxProfit = 0;
        int jobCount = 0;
        
        for(int i = 0; i < n; i++){
            
            for(int j = arr[i].dead; j > 0; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    jobCount++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int>ans(2 , 0);
        ans[0] = jobCount;
        ans[1] = maxProfit;
        return ans;
    } 
};
