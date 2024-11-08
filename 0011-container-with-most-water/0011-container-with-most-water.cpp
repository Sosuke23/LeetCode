class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int i = 0, j = n - 1;
        int res = 0;
        while (i < j) {
            int curr = std::min(height[i], height[j]) * (j - i);
            res = std::max(res, curr);

            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};