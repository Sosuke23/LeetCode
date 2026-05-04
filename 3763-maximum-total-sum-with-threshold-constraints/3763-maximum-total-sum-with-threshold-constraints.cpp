class Solution {
public:
    long long maxSum(vector<int>& nums, vector<int>& threshold) {
        int n = (int)nums.size();
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({threshold[i], nums[i]});
        }

        int step = 1;
        long long res = 0;

        while (!pq.empty()) {
            std::cout << pq.top().first << " " << pq.top().second << '\n';
            if (pq.top().first > step) {
                return res;
            }
            step++;
            res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};