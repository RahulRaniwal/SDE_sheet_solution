class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        double ans = 1.0;
        long long pow = n;
        
        if(pow < 0){
            pow = -1*pow;
        }
        while(pow){
            if(pow%2 == 0){
                x = x*x;
                pow = pow/2;
            }else{
                ans = ans*x;
                pow = pow-1;
            }
        }        
        if(n < 0){
            ans = (double)1.0/ans;
        }
        return ans;
    }
};

/************** TC O(logn) *****************/
