class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string a = nums[0];
        int len_a = (int)a.size();
        for (int i = 0;; i++) {
            bitset<16> b(i);
            string st = b.to_string();
            string t = st.substr(16 - len_a);
            if (count(nums.begin(), nums.end(), t) == 0) {
                return t;
            }
        }
        return "";
    }
};