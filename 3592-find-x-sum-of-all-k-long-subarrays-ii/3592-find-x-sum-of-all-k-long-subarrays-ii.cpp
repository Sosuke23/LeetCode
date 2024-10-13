
class Solution {
public:
    struct Node {
        Node *left, *right;
        int freq, val, size;
        long long sum;
        int priority;
        Node(int f, int v)
            : left(nullptr), right(nullptr), freq(f), val(v), size(1),
              sum((long long)f * v), priority(rand()) {}

        void update() {
            size = 1;
            sum = (long long)freq * val;
            if (left) {
                size += left->size;
                sum += left->sum;
            }
            if (right) {
                size += right->size;
                sum += right->sum;
            }
        }

        bool operator<(const Node& other) const {
            if (freq != other.freq)
                return freq > other.freq;
            else
                return val > other.val;
        }
    };

    void split(Node* node, Node*& left, Node*& right, const Node& key) {
        if (!node) {
            left = right = nullptr;
        } else if (*node < key) {
            split(node->right, node->right, right, key);
            left = node;
        } else {
            split(node->left, left, node->left, key);
            right = node;
        }
        if (node)
            node->update();
    }

    void merge(Node*& node, Node* left, Node* right) {
        if (!left || !right) {
            node = left ? left : right;
        } else if (left->priority > right->priority) {
            merge(left->right, left->right, right);
            node = left;
        } else {
            merge(right->left, left, right->left);
            node = right;
        }
        if (node)
            node->update();
    }

    void insert(Node*& node, Node* item) {
        if (!node) {
            node = item;
        } else if (item->priority > node->priority) {
            split(node, item->left, item->right, *item);
            node = item;
        } else if (*item < *node) {
            insert(node->left, item);
        } else {
            insert(node->right, item);
        }
        if (node)
            node->update();
    }

    void erase(Node*& node, const Node& key) {
        if (!node)
            return;
        if (node->freq == key.freq && node->val == key.val) {
            Node* temp = node;
            merge(node, node->left, node->right);
            delete temp;
        } else if (key < *node) {
            erase(node->left, key);
        } else {
            erase(node->right, key);
        }
        if (node)
            node->update();
    }

    long long getSum(Node* node, int k) {
        if (!node || k <= 0)
            return 0;
        int lsize = node->left ? node->left->size : 0;
        if (lsize >= k) {
            return getSum(node->left, k);
        } else {
            long long res = node->left ? node->left->sum : 0;
            res += (long long)node->freq * node->val;
            if (lsize + 1 == k) {
                return res;
            } else {
                return res + getSum(node->right, k - lsize - 1);
            }
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        Node* root = nullptr;

        for (int i = 0; i < k; ++i) {
            int num = nums[i];
            int f = freq[num];
            if (f > 0) {
                erase(root, Node(f, num));
            }
            freq[num] = f + 1;
            insert(root, new Node(freq[num], num));
        }

        vector<long long> answer;

        for (int i = 0; i <= n - k; ++i) {
            long long sum = getSum(root, x);
            answer.push_back(sum);

            if (i + k == n)
                break;

            int out_num = nums[i];
            int in_num = nums[i + k];

            int f = freq[out_num];
            erase(root, Node(f, out_num));
            freq[out_num] = f - 1;
            if (freq[out_num] > 0) {
                insert(root, new Node(freq[out_num], out_num));
            } else {
                freq.erase(out_num);
            }

            f = freq[in_num];
            if (f > 0) {
                erase(root, Node(f, in_num));
            }
            freq[in_num] = f + 1;
            insert(root, new Node(freq[in_num], in_num));
        }

        destroy(root);

        return answer;
    }

    void destroy(Node* node) {
        if (!node)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};