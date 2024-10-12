class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end());
        int i = 0, j = nums.size() - 1;
        int a = 0, b = 0;

        while (i < j) {
            if (v[i].first + v[j].first > target)
                j--;
            else if (v[i].first + v[j].first < target)
                i++;
            else if (v[i].first + v[j].first == target) {
                a = v[i].second;
                b = v[j].second;
                break;
            }
        }
        return {a, b};
    }
};