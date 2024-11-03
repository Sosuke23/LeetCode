class Solution {
public:
    bool isBalanced(string num) {
        int ev = 0, od = 0;
        for (int i = 0; i < (int)num.size(); i++) {
            if (i & 1) {
                od += (num[i] - '0');
            } else {
                ev += (num[i] - '0');
            }
        }
        return (od == ev);
    }
};