class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq(begin(nums), end(nums));
        long long res = 0;
        while (k--) {
            int a = pq.top();
            if (a == 0) {
                break;
            }
            res += pq.top();
            pq.pop();
            pq.push((a + 2) / 3);
        }
        return res;
    }
};