class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        std::set<int> st;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != target[i]) {
                st.insert(nums[i]);
            }
        }

        return (int)st.size();
    }
};