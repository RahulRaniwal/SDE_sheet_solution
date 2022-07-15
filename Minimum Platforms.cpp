class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
    	
    	sort(arr , arr+n);
    	sort(dep , dep+n);
    	int i = 1 , j = 0 , platform = 1 , maxPlatform = 1;
    	while(i < n and j < n){
    	    if(arr[i] <= dep[j]){
    	        platform++;
    	        i++;
    	    }else if(arr[i] > dep[j]){
    	        platform--;
    	        j++;
    	    }
    	    maxPlatform = max(platform , maxPlatform);
    	}
    	return maxPlatform;
    }
};
