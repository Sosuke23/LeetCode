class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0;
        unordered_set<int> p(begin(arr), end(arr));
        for (int i = 0; i < (int)arr.size(); i++) {
            for (int j = i + 1; j < (int)arr.size(); j++) {
                int prev = arr[j], curr = arr[i] + arr[j];
                int c = 2;
                while (p.find(curr) != p.end()) {
                    int nxt = prev + curr;
                    prev = curr;
                    curr = nxt;
                    res = max(res, ++c);
                } 
            }
        }
        return res >= 3 ? res : 0;
    }
};