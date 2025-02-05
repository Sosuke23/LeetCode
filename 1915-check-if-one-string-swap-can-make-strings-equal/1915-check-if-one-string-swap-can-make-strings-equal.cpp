class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> idx;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                idx.push_back(i);
            }
            if (idx.size() >= 2) {
                break;
            }
        }
        if (idx.size() == 1) {
            return false;
        }
        else if (idx.size() == 0) {
            return true;
        }
        else {
            swap(s2[idx[0]], s2[idx[1]]);
            return s1 == s2;
        }
    }
};