// Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int open = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (open) {
                    open--;
                } else {
                    res++;
                }
            }
        }
        return res + open;
    }
};