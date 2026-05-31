class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids ) {
        sort(begin(asteroids ), end(asteroids ));
        typedef long long i64;
        i64 M = mass;
        for (int i = 0; i < (int)asteroids .size(); i++) {
            if (M >= asteroids [i]) {
                M += asteroids [i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};