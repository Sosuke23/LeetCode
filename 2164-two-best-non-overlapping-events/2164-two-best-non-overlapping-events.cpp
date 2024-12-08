class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        int res = 0;
        int curr = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Pq;
        for (int i = 0; i < (int)events.size(); i++) {
            int str = events[i][0];
            int end = events[i][1];
            int val = events[i][2];

            while (!Pq.empty() and Pq.top().first < str) {
                curr = max(curr, Pq.top().second);
                Pq.pop();
            }
            res = max(res, curr + val);
            Pq.emplace(end, val);
        }
        return res;
    }
};