class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        int n = (int)nums.size();
        std::vector<std::array<int, 2>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        std::sort(begin(arr), end(arr));
        std::vector<int> used(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used[arr[i][1]]) {
                used[arr[i][1]] = 1;
                res += arr[i][0];
                if (arr[i][1] - 1 >= 0) {
                    used[arr[i][1] - 1] = 1;
                }
                if (arr[i][1] + 1 < n) {
                    used[arr[i][1] + 1] = 1;
                }
            }
        }
        return res;
    }
};