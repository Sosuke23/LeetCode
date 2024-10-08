// Problem Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        bool ok = true;
        while (ok) {
            ok = false;
            for (int i = 0; i + 1 < (int)s.size(); i++) {
                if (s[i] == 'A' and s[i + 1] == 'B') {
                    ok = true;
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i);
                }
                else if (s[i] == 'C' and s[i + 1] == 'D') {
                    ok = true;
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i);
                }
            }
        }
        
        return (int)s.size();
    }
};