class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for (int i = m; i < (int)nums1.size(); i++) {
            nums1[i] = nums2[j];
            j++;
        }
        std::sort(begin(nums1), end(nums1));
    }
};