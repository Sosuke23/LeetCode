class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& base_time) {
        std::vector<int> adj[n];
        std::vector<int> order;
        for (std::vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        std::vector<long long> res(n);
        std::stack<int> st;
        st.push(0);

        while (!st.empty()) {
            int a = st.top();
            st.pop();
            order.push_back(a);

            for (int nxt_node : adj[a]) {
                st.push(nxt_node);
            }
        }

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            long long earliest = LLONG_MAX, latest = LLONG_MIN;
            for (int nxt_node : adj[order[i]]) {
                earliest = std::min(earliest, res[nxt_node]);
                latest = std::max(latest, res[nxt_node]);
            }

            res[order[i]] = latest == LLONG_MIN ? (long long)base_time[order[i]] : 2 * latest - earliest + base_time[order[i]];
        }

        return res[0];
    }
};