class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool found = true;
        while (found) {
            found = false;
            for (int i = 0; i < (int)s.size(); i++) {
                for (int j = i + 1; j < (int)s.size(); j++) {
                    
                    if (s[i] == s[j] && j - i <= k) {
                        s.erase(j, 1);
                        found = true;
                        break;
                    }

                    if (j - i > k) {
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        }

        return s;
    }
};