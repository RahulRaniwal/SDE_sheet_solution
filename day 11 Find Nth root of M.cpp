class Solution{
	public:
	int NthRoot(int n, int m){
	    int low = 1;
	    int high = m;
	    
	    while(low <= high){
	        int mid = (low + high)/2;
	        if(pow(mid , n) == m){
	            return mid;
	        }else if(pow(mid , n) > m){
	            high = mid-1;
	        }else{
	            low = mid+1;
	        }
	    }
	    return -1;
	}  
};

/*************** Approach2 *******************/

double power(double num , int n){
    if(n == 0){
        return 1.0;
    }
    return num * power(num , n-1);
}
// main
double findNthRootOfM(int n, long long m) {
	double low = 1;
    double high = m;
    
    while((high-low) > 1e-9){
        double mid = (low+high)/2.0;
        if(power(mid , n) > m){
            high = mid;
        }else{
            low = mid;
        }
    }
    // we can return low or high 
    return low;
}
