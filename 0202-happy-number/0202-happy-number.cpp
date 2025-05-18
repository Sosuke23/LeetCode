class Solution {
public:
    unordered_map<int, bool> mp;
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        if (mp[n] == 1) {
            return false;
        }
        mp[n] = 1;
        int num = 0;
        while (n != 0) {
            int rem = n % 10;
            num += rem * rem;
            n /= 10;
        }
        return isHappy(num);
    }
};
