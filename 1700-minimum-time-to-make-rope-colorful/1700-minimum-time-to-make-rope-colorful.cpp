class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        colors += '$';
        int n = (int)colors.size();
        char prev = '#';
        priority_queue<int> pq;
        pq.push(neededTime[0]);
        prev = colors[0];
        for (int i = 1; i < n; i++) {
            if (prev == colors[i]) {
                pq.push(neededTime[i]);
            }
            else {
                prev = colors[i];
                pq.pop();
                while (!pq.empty()) {
                    res += pq.top();
                    pq.pop();
                }
                if (i < n - 1)
                pq.push(neededTime[i]);
            }
        }
        return res;
    }
};