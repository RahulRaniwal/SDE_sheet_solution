class Solution{

	public:
	int solve1(int coins[] , int M , int V){
	    // base case
	    if(V == 0){
	        return 0;
	    }
	    if(V < 0){
	        return INT_MAX;
	    }
	    
	    int ans = INT_MAX;
	    for(int i = 0; i < M; i++){
	        int temp = solve1(coins , M , V-coins[i]);
	        if(temp != INT_MAX){
	            ans = min(ans , temp+1);
	        }
	    }
	    return ans;
	}
	
	// memoization
	int solve2(int coins[] , int M , int V , vector<int>& dp){
	    // base case
	    if(V == 0){
	        return 0;
	    }
	    if(V < 0){
	        return INT_MAX;
	    }
	    if(dp[V] != -1){
	        return dp[V];
	    }
	    int ans = INT_MAX;
	    for(int i = 0; i < M; i++){
	        int temp = solve2(coins , M , V-coins[i] , dp);
	        if(temp != INT_MAX){
	            ans = min(ans , temp+1);
	        }
	    }
	    dp[V] = ans;
	    return dp[V];
	}
	// tabulation
	int solve3(int coins [] , int M , int V){
	    vector<int> dp(V+1 , INT_MAX);
	    dp[0] = 0;
	    for(int i = 1; i < dp.size(); i++){
	        for(int j = 0; j < M; j++){
	            if(i-coins[j] >= 0 and dp[i-coins[j]] != INT_MAX){
	                dp[i] = min(dp[i] , dp[i-coins[j]]+1);
	            }
	        }
	    }
	    if(dp[V] == INT_MAX){
	        return -1;
	    }
	    return dp[V];
	}
	//main
	int minCoins(int coins[], int M, int V){ 
	    
	   // return solve1(coins , M , V);
// 	   vector<int>dp(V+1 ,  -1);
// 	  int result =  solve2(coins , M , V , dp);
// 	  if(result == INT_MAX){
// 	      return -1;
// 	  }
// 	  return result;
// 	
        return solve3(coins , M , V);
	}
};
