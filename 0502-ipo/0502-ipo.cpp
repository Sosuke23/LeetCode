class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int)profits.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {capital[i], profits[i]};
        }
        
        sort(begin(arr), end(arr));
        priority_queue<int> pq;

        int j = 0;
        while (j < n && k > 0) {
            if (arr[j].first <= w) {
                pq.push(arr[j].second);
                j++;
            } else {
                if (pq.empty()) {
                    return w;
                } else {
                    w += pq.top();
                    pq.pop();
                    k -= 1;
                }
            }
        }

        while (k-- && !pq.empty()) {
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};