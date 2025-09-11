class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        vector<pair<int, char>> t;
        for (int i = 0; i < (int)s.size(); i++) {
            if (count(begin(vowel), end(vowel), s[i])) {
                t.push_back({(int)s[i], s[i]});
            }
        }
        sort(begin(t), end(t));
        string res = "";
        int i = 0;
        for (auto x : s) {
            if (count(begin(vowel), end(vowel), x)) {
                res += t[i].second;
                i += 1;
            }
            else {
                res += x;
            }
        }
        return res;
    }
};