#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int minChanges(string st) {
        int res = 0;
        for (int i = 0; i < (int)st.size(); i += 2) {
            res += (st[i] != st[i + 1]);
        }
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