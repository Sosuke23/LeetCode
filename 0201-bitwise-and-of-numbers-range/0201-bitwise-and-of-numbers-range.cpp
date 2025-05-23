class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt += 1;
        }
        return (left == 0 ? 0 : left << cnt);
    }
};