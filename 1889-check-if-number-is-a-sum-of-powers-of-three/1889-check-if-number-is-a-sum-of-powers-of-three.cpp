class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (int i = 0; i < (1 << 16); i++) {
            int sum = 0;
            for (int j = 0; j <= 15; j++) {
                if (i & (1 << j))  {
                    sum += pow(3, j);
                }
                if (sum > n) {
                    break;
                }
            }
            if (sum == n) {
                return true;
            }
        }
        return false;
    }
};