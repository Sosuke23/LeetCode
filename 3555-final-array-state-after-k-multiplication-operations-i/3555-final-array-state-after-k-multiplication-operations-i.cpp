class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto f = pq.top();
            pq.pop();
            pq.push({f.first * multiplier, f.second});
        }
        vector<int> res((int)nums.size(), 0);
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            res[f.second] = f.first;
        }
        return res;
    }
};