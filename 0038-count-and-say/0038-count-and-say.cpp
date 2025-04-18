class Solution {
public:
    string countAndSay(int n) {

        if (n == 1)
            return "1";
        if (n == 2)
            return "11";

        string str = "11";
        string ans = "";
        for (int i = 3; i <= n; i++) {
            ans = "";
            int count = 1;
            int j;
            for (j = 1; j < str.size(); j++) {

                if (str[j] != str[j - 1]) {
                    ans += count + '0';
                    ans += str[j - 1];
                    count = 1;

                } else
                    count++;
            }
            ans += count + '0';
            ans += str[j - 1];

            str = ans;
        }
        return str;
    }
};