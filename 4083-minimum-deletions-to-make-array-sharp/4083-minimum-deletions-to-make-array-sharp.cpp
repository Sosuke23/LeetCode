class Solution {
public:
    int minDeletions(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < (int)arr.size() - 1; i++) {
            res += (arr[i] == arr[i + 1]);
        }
        return res;
    }
};