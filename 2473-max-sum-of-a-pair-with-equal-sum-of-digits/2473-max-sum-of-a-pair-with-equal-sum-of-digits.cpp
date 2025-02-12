class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> m;
        for (auto it : nums) {
            int tmp = it;
            int sum = 0;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            m[sum].push_back(it);
        }
        int ans = -1;
        for (auto it : m) {
            sort(it.second.begin(), it.second.end());
            reverse(it.second.begin(), it.second.end());
            if (it.second.size() >= 2)
                ans = max(ans, it.second[0] + it.second[1]);
        }
        return ans;
    }
};