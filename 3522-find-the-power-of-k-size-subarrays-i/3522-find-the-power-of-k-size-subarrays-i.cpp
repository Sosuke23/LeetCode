class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> res;
        deque<int> deq;
        deq.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (deq.back() + 1 == nums[i]) {
                deq.push_back(nums[i]);
            } else {
                deq.clear();
                deq.push_back(nums[i]);
            }

            if (i >= k - 1) {
                if ((int)deq.size() == k) {
                    res.push_back(deq.back());
                    deq.pop_front();
                } else {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};
