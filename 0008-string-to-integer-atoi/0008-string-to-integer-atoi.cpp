class Solution {
public:
    int myAtoi(string s) {
        int b_isPositive = 1;
        long long int ret = 0;

        int i = 0;
        while (s[i] == ' ')
            i++;

        if (s[i] == '+')
            i++;
        else if (s[i] == '-') {
            i++;
            b_isPositive = 0;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ret = ret * 10 + (s[i] - '0');
            if (ret > INT_MAX)
                return b_isPositive ? INT_MAX : INT_MIN;
            i++;
        }

        return b_isPositive ? ret : -ret;
    }
};