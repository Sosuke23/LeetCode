struct Node {
    int next[26];
    int idx;
    int len;

    Node() {
        memset(next, -1, sizeof(next));
        idx = -1;
        len = 1e9;
    }
};

class Trie {
private:
    vector<Node> trie;

public:
    Trie() {
        trie.push_back(Node()); 
    }

    void insert(string &s, int idx) {
        int cur = 0;
        int sz = s.size();

        for (int i = sz - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (trie[cur].next[c] == -1) {
                trie[cur].next[c] = trie.size();
                trie.push_back(Node());
            }

            cur = trie[cur].next[c];
            if (trie[cur].len > sz || (trie[cur].len == sz && trie[cur].idx > idx)) {
                trie[cur].len = sz;
                trie[cur].idx = idx;
            }
        }
    }

    int match(string &s) {
        int cur = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (trie[cur].next[c] == -1) return trie[cur].idx;
            cur = trie[cur].next[c];
        }
        return trie[cur].idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        Trie trie;
        int idx = 0;
        for (int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
            if (wordsContainer[i].size() < wordsContainer[idx].size()) idx = i;
        }

        vector<int> ans;
        for (string &s : wordsQuery) {
            int val = trie.match(s);
            if (val == -1) val = idx;
            ans.push_back(val);
        }

        return ans;
    }
};