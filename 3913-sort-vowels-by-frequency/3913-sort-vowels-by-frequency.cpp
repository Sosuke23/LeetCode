class Solution {
public:
    string sortVowels(string s) {
        int n = (int)s.size();
        vector<array<int, 3>> a(5);
        a[0][2] = a[1][2] = a[2][2] = a[3][2] = a[4][2] = -1;
        a[0][1] = a[1][1] = a[2][1] = a[3][1] = a[4][1] = 0;
        a[0][0] = 0, a[1][0] = ('e' - 'a'), a[2][0] = ('i' - 'a'), a[3][0] = ('o' - 'a'), a[4][0] = ('u' - 'a');

        unordered_set<char> uset = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            if (uset.count(s[i])) {
                if (s[i] == 'a') {
                    if (a[0][2] == -1) {
                        a[0][2] = i;
                    }
                    a[0][1]++;
                } else if (s[i] == 'e') {
                    if (a[1][2] == -1) {
                        a[1][2] = i;
                    }
                    a[1][1]++;
                } else if (s[i] == 'i') {
                    if (a[2][2] == -1) {
                        a[2][2] = i;
                    }
                    a[2][1]++;
                } else if (s[i] == 'o') {
                    if (a[3][2] == -1) {
                        a[3][2] = i;
                    }
                    a[3][1]++;
                } else if (s[i] == 'u') {
                    if (a[4][2] == -1) {
                        a[4][2] = i;
                    }
                    a[4][1]++;
                }
            }
        }

        sort(begin(a), end(a), [&] (const auto &i, const auto &j) {
            if (i[1] == j[1]) {
                return i[2] > j[2];
            }
            return i[1] < j[1];
        });

        std::string res = "";
        for (char x : s) {
            if (uset.count(x)) {
                res += 'a' + a.back()[0];
                a.back()[1]--;
                if (a.back()[1] == 0) {
                    a.pop_back();
                }
            } else {
                res += x;
            }
        }


        return res;
    }
};