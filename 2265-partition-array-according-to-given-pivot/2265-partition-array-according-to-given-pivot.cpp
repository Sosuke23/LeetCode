class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, more;
        for (auto x : nums) {
            if (x < pivot) {
                less.push_back(x);
            } else if (x > pivot) {
                more.push_back(x);
            }
        }
        int pi = count(nums.begin(), nums.end(), pivot);
        vector<int> just(pi, pivot);
        less.insert(less.end(), just.begin(), just.end());
        less.insert(less.end(), more.begin(), more.end());
        return less;
    }
};