class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        priority_queue<int> pq(begin(gifts), end(gifts));
        while (!pq.empty() and k--) {
            int f = pq.top();
            pq.pop();
            f = sqrt(f);
            pq.push(f);
        }

        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};