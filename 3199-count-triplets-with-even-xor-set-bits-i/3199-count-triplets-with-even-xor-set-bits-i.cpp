class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int res = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                for (int k = 0; k < (int)c.size(); k++) {
                    int _xor = (a[i] ^ b[j] ^ c[k]);
                    res += (__builtin_popcount(_xor) % 2 == 0); 
                }
            }
        }
        return res;
    }
};