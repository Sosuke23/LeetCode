const int MOD = 1e9 + 7;

class LazySegmentTree {
private:
    vector<long long> tree, lazy, original;
    int n;

    long long mod(long long x) {
        return (x % MOD + MOD) % MOD;
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = 1LL * arr[start] * arr[start] % MOD;
            original[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = mod(tree[2 * node] + tree[2 * node + 1]);
            original[node] = mod(original[2 * node] + original[2 * node + 1]);
        }
    }

    void push(int node, int start, int end) {
    if (lazy[node] != 0) {
        int len = end - start + 1;
        tree[node] = mod(tree[node] 
                        + mod(2 * mod(lazy[node] * original[node]) 
                        + mod(len * mod(lazy[node] * lazy[node]))));
        original[node] = mod(original[node] + len * lazy[node]);
        
        if (start != end) {
            lazy[2 * node] = mod(lazy[2 * node] + lazy[node]);
            lazy[2 * node + 1] = mod(lazy[2 * node + 1] + lazy[node]);
        }
        lazy[node] = 0;
    }
}


    void update(int node, int start, int end, int l, int r, int value) {
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] = mod(lazy[node] + value);
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, value);
        update(2 * node + 1, mid + 1, end, l, r, value);
        tree[node] = mod(tree[2 * node] + tree[2 * node + 1]);
        original[node] = mod(original[2 * node] + original[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        push(node, start, end);
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return mod(query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        original.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void update(int l, int r, int value) {
        update(1, 0, n - 1, l, r, value);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector < int > distincts;
        map < int , vector <int> > pos;
        int n = nums.size();
        for(int i = 0;i<n;++i) {
            pos[nums[i]].push_back(i);
            distincts.push_back(pos.size());
        }
        for(auto &a : pos) {
            reverse(a.second.begin() , a.second.end());
        }
        LazySegmentTree lst(distincts);
        long long ans = 0;
        for(int i = 0;i<nums.size();++i) {
            ans += lst.query(i , n - 1);
            ans %= MOD;
            lst.update(i , n - 1 , -1);
            pos[nums[i]].pop_back();
            if(pos[nums[i]].size()) {
                lst.update(pos[nums[i]].back() , n - 1 , 1);
            }
        }
        return ans;
    }
};