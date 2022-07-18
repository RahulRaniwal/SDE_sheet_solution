class Solution
{
    public:
    static bool comp(Item a , Item b){
        double val1 = (double)a.value/(double)a.weight;
        double val2 = (double)b.value/(double)b.weight;
        return val1>val2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        
        sort(arr , arr+n , comp);
        vector<double> perUnit(n , 0);
        for(int i = 0; i < n; i++){
            perUnit[i] = (double)arr[i].value/(double)arr[i].weight;
        }
        
        int currW = 0;
        double total = 0;
        for(int i = 0; i < n; i++){
            if(currW + arr[i].weight <= W){
                currW += arr[i].weight;
                total += (double)arr[i].value;
            }else{
                int remain = W - currW;
                total += perUnit[i]*(double)remain;
                break;
            }
        }
        return total;
    }
        
};
