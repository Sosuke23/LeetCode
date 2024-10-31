#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:

    void f(string curr, int n, vector<string>& res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        f(curr + '1', n, res);
        if (curr.empty() || curr.back() != '0') {
            f(curr + '0', n, res);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        f("", n, res);
        return res;
    }
};

#ifdef freakin23
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif