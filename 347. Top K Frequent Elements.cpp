struct comp{
    bool operator()(pair<int,int> d1 , pair<int,int> d2){
        return d1.second < d2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , comp> pq;
        for(auto i : map){
            pq.push({i.first , i.second});
        }
        vector<int> ans;
        while(ans.size() != k){
            pair curr = pq.top();
            pq.pop();
            ans.push_back(curr.first);
        }
        return ans;
    }
};
