#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string temp = s;
        int n = s.size();
        for (int i = 0; i < (int)s.size(); i++) {
            s[i] = temp[(i + k) % (int)s.size()];
        }
        return s;
    }
};

#ifdef freakin23
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif