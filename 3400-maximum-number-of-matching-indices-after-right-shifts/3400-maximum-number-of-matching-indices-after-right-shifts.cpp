class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = (int)nums1.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0, r = i;
            for (int j = 0; j < n; j++) {
                if (nums1[(j + r) % n] == nums2[j]) {
                    cnt++;
                }
            }
            res = std::max(res, cnt);
        }
        return res;
    }
};