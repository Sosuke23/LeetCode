class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int curr = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            curr = max(arr[i], curr);
            res += (curr == i);
        }
        return res;
    }
};