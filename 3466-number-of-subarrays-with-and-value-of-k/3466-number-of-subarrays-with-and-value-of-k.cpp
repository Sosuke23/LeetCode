#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
#define i23 long long
    long long countSubarrays(vector<int>& nums, int k) {
        i23 res = 0;
        unordered_map<i23, i23> mp;
        for (int i = 0; i < (int)nums.size(); ++i) {
            unordered_map<i23, i23> new_mp;
            new_mp[nums[i]]++;
            for (auto& p : mp) {
                int newAnd = p.first & nums[i];
                new_mp[newAnd] += p.second;
            }
            mp = new_mp;
            if (mp.find(k) != mp.end()) {
                res += mp[k];
            }
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