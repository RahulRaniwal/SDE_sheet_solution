class Solution{
		

	public:
	// recursive
	int solve1(int arr[] , int n , int curr , int prev){
	    // base case
	    if(curr == n){
	        return 0;
	    }
	    // include a number
	    int include  = 0;
	    if(prev == -1 or arr[curr] > arr[prev]){
	        include = arr[curr] + solve1(arr , n , curr+1 , curr);
	    }
	    int exclude = solve1(arr , n , curr+1 , prev);
	    return max(include , exclude);
	}
	
	// memoization
	int solve2(int arr[] , int n , int curr , int prev , vector<vector<int>>& dp){
	    // base case
	    if(curr == n){
	        return 0;
	    }
	    // check if ans aleady exist
	    if(dp[curr][prev+1] != -1){
	        return dp[curr][prev+1];
	    }
	    
	    // include a number
	    int include = 0;
	    if(prev == -1 or arr[curr] > arr[prev]){
	        include = arr[curr] + solve2(arr , n , curr+1 , curr , dp);
	    }
	    int exclude = solve2(arr , n , curr+1 , prev , dp);
	    
	    return dp[curr][prev+1] = max(include , exclude);
	}
	
	// tabulation
	int solve3(int arr[] , int n){
	    
	    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
	    
	    for(int curr = n-1; curr >= 0; curr--){
	        for(int prev = curr-1; prev >= -1; prev--){
	            
	            int include = 0;
	            if(prev == -1 or arr[curr] > arr[prev]){
	                include = arr[curr] + dp[curr+1][curr+1];
	            }
	            int exclude = dp[curr+1][prev+1];
	            
	            dp[curr][prev+1] = max(include , exclude);
	        }
	    }
	    return dp[0][0];
	}
	
	//main
	int maxSumIS(int arr[], int n){  
	   // // recursive
	   // return solve1(arr , n , 0 , -1);
	   
	   //// memoization
	   //vector<vector<int>> dp(n , vector<int>(n+1 , -1));
	   //return solve2(arr , n , 0 , -1 , dp);
	   
	   // tabulation
	   return solve3(arr , n);
	}  
};
