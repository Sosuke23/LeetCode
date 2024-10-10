class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = (int)nums.size();
        int res = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() or nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        for (int i = n - 1; i > res; i--) {
            while (!st.empty() and nums[st.top()] <= nums[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};