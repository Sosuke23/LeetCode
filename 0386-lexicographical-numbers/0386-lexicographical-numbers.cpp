class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        vector<string> s;
        for (auto x : v) {
            s.push_back(to_string(x));
        }
        sort(s.begin(), s.end());
        v.clear();
        for (auto x : s) {
            v.push_back(stoi(x));
        }
        return v;
    }
};