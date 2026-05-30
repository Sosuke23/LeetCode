class BIT {
    vector<int> arr;
    int size;
    int lowbit(int x) { return x & -x; }

public:
    BIT(int x) : size(x), arr(x, 0) {}
    void update(int pos, int val) {
        while (pos < size) {
            arr[pos] = max(arr[pos], val);
            pos += lowbit(pos);
        }
    }
    int search(int pos) {
        int maxVal = 0;
        while (pos) {
            maxVal = max(maxVal, arr[pos]);
            pos -= lowbit(pos);
        }
        return maxVal;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;
        int maxVal = 0;
        for (const auto& query : queries) {
            if (query[0] == 1)
                obstacles.insert(query[1]);
            maxVal = max(maxVal, query[1]);
        }

        BIT bit(maxVal + 1);
        int pre = 0;
        for (int obstacle : obstacles) {
            bit.update(obstacle, obstacle - pre);
            pre = obstacle;
        }
        obstacles.insert(0);

        reverse(queries.begin(), queries.end());
        vector<bool> res;
        for (const auto& query : queries) {
            int pos = query[1];
            if (query[0] == 1) {
                int prevPos = *prev(obstacles.lower_bound(pos));
                auto iter = obstacles.upper_bound(pos);
                int nextPos = iter != obstacles.end() ? *iter : 0;
                obstacles.erase(pos);
                if (nextPos)
                    bit.update(nextPos, nextPos - prevPos);
            } else {
                int lastObs = *prev(obstacles.upper_bound(pos));
                int maxDist = max(pos - lastObs, bit.search(lastObs));
                res.push_back(maxDist >= query[2]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};