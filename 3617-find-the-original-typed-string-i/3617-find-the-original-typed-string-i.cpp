#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 0;
        for (int i = 1; i < (int)word.size(); i++) {
            if (word[i] == word[i - 1]) {
                res += 1;
            }
        }
        return res + 1;
    }
};

#ifdef freakin23
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif