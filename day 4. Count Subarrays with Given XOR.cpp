#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x){
    map<int,int> mp;
    int count = 0; 
    int xorr = 0;
    for(int i = 0; i < arr.size(); i++){
        xorr = xorr ^ arr[i];
        if(xorr == x){
            count++;
        }
        int y = xorr^x;
        if(mp.find(y) != mp.end()){
            count += mp[xorr ^ x];
        }
            mp[xorr] += 1;
    }
    return count;
}

/****************** TC O(nlogn) *********************/
