class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = (int)s.size(), count = 0;
        for (int i = 0; i < n; i++) {
            string str1 = "", str2 = "";
            for (int j = i; j < n; j++) {
                str1 += s[j];
                str2 = s[j] + str2;

                if (str1.size() >= k && str2 == str1) {
                    count++;
                    i = j;
                    break;
                }
                if (str1.size() > k) {
                    break;
                }
            }
        }

        return count;
    }
};