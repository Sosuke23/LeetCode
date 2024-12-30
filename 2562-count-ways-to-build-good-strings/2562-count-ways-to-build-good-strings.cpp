#define mod 1000000007
#define ll long long
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll> ret(200005);
        set<int> s ;
        for(int i = 0; i < 10; i++){
            s.insert(i);
        }
        ret[0] = 1;
        for(int i = 0; i < 100005; i++){
            ret[i + zero] %= mod;
            ret[i + zero] += ret[i];
            ret[i + one] %= mod;
            ret[i + one] += ret[i];
        }
        ll res = 0;
        for(int i = low; i <= high; i++){
            res = (res + ret[i]) % mod;
        }
        return res;
    }
};
