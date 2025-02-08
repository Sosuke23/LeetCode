class NumberContainers {
public:
    map<int, int> mp;
    map<int, set<int>> pos;
    NumberContainers() {}
    
    void change(int index, int number) {
        if (mp.count(index)) {
            pos[mp[index]].erase(index);
        }
        mp[index] = number;
        pos[number].insert(index);
    }
    
    int find(int number) {
        if (pos[number].empty()) {
            return -1;
        } 
        return *pos[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */