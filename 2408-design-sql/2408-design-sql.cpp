class SQL {
public:
    SQL(std::vector<std::string>& names, std::vector<int>& columns) {
        for (int i = 0; i < names.size(); ++i) {
            std::vector<std::string> header(columns[i]);
            table[names[i]].emplace_back(header);
        }
    }
    
    bool ins(std::string name, std::vector<std::string> row) {
        if (table.find(name) == table.end() || table[name][0].size() != row.size()) {
            return false;
        }

        table[name].emplace_back(row);
        return true;
    }
    
    void rmv(std::string name, int rowId) {
        if (table.find(name) == table.end() || table[name].size() < (rowId + 1)) {
            return;
        }

        table[name][rowId].clear();
    }
    
    std::string sel(std::string name, int rowId, int columnId) {
        if (table.find(name) == table.end() || 
                table[name].size() < (rowId + 1) || 
                table[name][rowId].size() < columnId) {
            return "<null>";
        }

        return table[name][rowId][columnId - 1]; 
    }
    
    std::vector<std::string> exp(std::string name) {
        std::vector<std::string> res;
        if (table.find(name) == table.end()) {
            return res;
        }

        for (int i = 1; i < table[name].size(); ++i) {
            if (table[name][i].size() > 0) {
                std::string row_data;
                row_data += std::to_string(i); row_data += ",";

                for (const std::string& val : table[name][i]) {
                    row_data += val; row_data += ',';
                }

                row_data.pop_back();
                res.emplace_back(row_data);
            }
        }
        return res;
    }

private:
    std::unordered_map<std::string, std::vector<std::vector<std::string>>> table;
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */