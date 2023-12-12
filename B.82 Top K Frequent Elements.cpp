// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        vector<int> v;
        priority_queue<pair<int, int>> q;
        int n = m.size();
        for(auto i: m){
            q.push(make_pair(i.second, i.first));
            if(q.size() > n - k){
                v.push_back(q.top().second);
                q.pop();
            }
        }
        
        return v;
    }
};
