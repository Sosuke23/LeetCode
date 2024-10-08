// Problem Link: https://leetcode.com/problems/sentence-similarity-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        auto split = [&](string a) {
            string b = "";
            a += ' ';
            vector<string> words;
            for (int i = 0; i < (int)a.size(); i++) {
                if (a[i] == ' ') {
                    words.push_back(b);
                    b = "";
                } else {
                    b += a[i];
                }
            }
            return words;
        }; 
        vector<string> a = split(s);
        vector<string> b = split(t);

        if ((int)b.size() < (int)a.size()) {
            swap(a, b);
        }

        int i = 0, j = 0;
        int n = (int)a.size(), m = (int)b.size();

        // adding to the end
        while (i < n and j < m and a[i] == b[j]) {
            i++;
            j++;
        }

        if (i == n) {
            return true;
        }

        // adding to the front
        i = n - 1, j = m - 1;
        while (i >= 0 and j >= 0 and a[i] == b[j]) {
            i--;
            j--;
        }
        if (i == -1) {
            return true;
        }

        // check if all words from a are there in b
        i = 0, j = 0;
        while (i < n and j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if (i != n) {
            return false;
        }

        // adding in the middle
        i = 0, j = 0;
        while (i < n and j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                break;
            }
        }
        
        int new_i = n - 1, new_j = m - 1;
        while (new_i >= 0 and new_j >= 0) {
            if (a[new_i] == b[new_j]) {
                new_i--;
                new_j--;
            } else {
                break;
            }
        }
        if (i == 0) {
            return false;
        }
        return (new_i <= i);
    }
};