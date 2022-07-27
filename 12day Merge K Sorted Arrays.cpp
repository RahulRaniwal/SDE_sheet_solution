#include"bits/stdc++.h"
class triplet{
    public:
    int val;
    int listIdx;
    int dataIdx;
    
    triplet(int val , int listIdx , int dataIdx){
        this->val = val;
        this->listIdx = listIdx;
        this->dataIdx = dataIdx;
    }
};

    struct comp{
        bool operator()(triplet a  , triplet b){
            return a.val > b.val;
        }
    };
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    
    priority_queue<triplet ,vector<triplet> , comp> pq;
    
    for(int i = 0; i < k; i++){
        pq.push(triplet(kArrays[i][0] , i , 0));
    }
    vector<int> ans;    // ans vector to be return
    
    while(!pq.empty()){
        triplet temp = pq.top();
        pq.pop();
        int num = temp.val;
        int li = temp.listIdx;
        int di = temp.dataIdx;
        
        ans.push_back(num);
        di++;
        if(di < kArrays[li].size()){
            num = kArrays[li][di];
            pq.push({num , li , di});
        }
    }
    return ans;
}
