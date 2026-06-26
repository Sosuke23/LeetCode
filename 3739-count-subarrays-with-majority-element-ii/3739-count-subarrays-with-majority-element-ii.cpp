#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        long long res = 0;
        ordered_set<pair<int, int>> st;
        for (int i = 0; i <= n; i++) {
            res += st.order_of_key({pref[i], INT_MIN});
            st.insert({pref[i], i});
        }
        return res;
    }
};