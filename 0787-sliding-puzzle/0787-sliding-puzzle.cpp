class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> dict;
        string res = "123450";
        queue<string> wait_queue;
        string status;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                status += to_string(board[i][j]);
            }
        }
        wait_queue.push(status);
        dict[status] = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!wait_queue.empty() && dict.find(res) == dict.end()) {
            string cur = wait_queue.front();
            wait_queue.pop();
            int pos = 0;
            for (int i = 0; i < 6; i++) {
                if (cur[i] == '0') {
                    pos = i;
                    break;
                }
            }
            int x = pos / 3, y = pos % 3, step = dict[cur];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx <= 1 && ny >= 0 && ny <= 2) {
                    string temp(cur);
                    swap(temp[pos], temp[nx * 3 + ny]);
                    if (dict.find(temp) == dict.end()) {
                        dict[temp] = step + 1;
                        wait_queue.push(temp);
                    }
                }
            }
        }
        if (dict.find(res) == dict.end()) {
            return -1;
        }
        return dict[res];
    }
};
