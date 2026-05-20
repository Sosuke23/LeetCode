class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        std::vector<std::pair<int, int>> adj[n];
        std::vector<long long> res(n, 0);

        for (std::vector<int> r : roads) {
            adj[r[0] - 1].push_back({r[1] - 1, r[2]});
            adj[r[1] - 1].push_back({r[0] - 1, r[2]});
        }

        auto D = [&] (int start) {
            std::priority_queue<std::pair<int, int>> pq;
            std::vector<int> travel_cost(n, INT_MAX);
            int min_cost = INT_MAX;
            pq.push({0, start});
            travel_cost[start] = 0;


            while (!pq.empty()) {
                int cost = -pq.top().first;
                int curr_node = pq.top().second;
                pq.pop();

                min_cost = std::min(min_cost, appleCost[curr_node] + (k + 1) * cost);

                for (auto node : adj[curr_node]) {
                    int neighbour = node.first;
                    int neighbour_cost = cost + node.second;
                    if (neighbour_cost < travel_cost[neighbour]) {
                        travel_cost[neighbour] = neighbour_cost;
                        pq.push({-neighbour_cost, neighbour});
                    }
                }
            }

            return min_cost;

        };

        for (int i = 0; i < n; i++) {
            res[i] = D(i);
        }

        return res;
    }
};