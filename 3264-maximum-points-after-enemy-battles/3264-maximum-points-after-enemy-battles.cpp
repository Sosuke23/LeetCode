class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(begin(enemyEnergies), end(enemyEnergies));
        int mn = enemyEnergies[0];
        if (currentEnergy < mn) {
            return 0;
        }
        long long pref = currentEnergy;
        for (int i = 1; i < (int)enemyEnergies.size(); i++) {
            pref += enemyEnergies[i];
        }
        long long res = pref / mn;
        return res;
    }
};