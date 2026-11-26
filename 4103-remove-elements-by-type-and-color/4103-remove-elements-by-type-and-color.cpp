class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = (int)types.size();

        std::vector<std::array<int, 3>> st; // {type, color, cnt}
        for (int i = 0; i < n; i++) {
            int type = types[i];
            int color = colors[i];

            if (!st.empty() and st.back()[0] == type and st.back()[1] == color) {
                st.back()[2]++;
            } else {
                st.push_back({type, color, 1});
            }

            if (st.back()[2] == groupSize[type]) {
                st.pop_back();
            }
        }

        return st.empty();
    }
};