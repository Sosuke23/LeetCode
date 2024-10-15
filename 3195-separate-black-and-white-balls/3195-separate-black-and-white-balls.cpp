class Solution {
public:
    long long minimumSteps(string s) {
        int z = count(begin(s), end(s), '0');
        int o = count(begin(s), end(s), '1');
        
        string to = string(z, '0') + string(o, '1');
        
        if (s == to) {
            return 0;
        }
        vector<int> p;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                p.push_back(i);
            }
        }
        long long res = 0;
        for (int i = 0; i < (int)p.size(); i++) {
            res += p[i] - i;
        }
        return res;
    }
};