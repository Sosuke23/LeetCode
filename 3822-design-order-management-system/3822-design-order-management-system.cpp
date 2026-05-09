class OrderManagementSystem {
public:
    std::unordered_map<int, std::pair<std::string, int>> mp;
    OrderManagementSystem() {
    }
    
    void addOrder(int orderId, string orderType, int price) {
        mp[orderId] = {orderType, price};
    }
    
    void modifyOrder(int orderId, int newPrice) {
        mp[orderId].second = newPrice;
    }
    
    void cancelOrder(int orderId) {
        mp.erase(mp.find(orderId));
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        std::vector<int> res;
        for (auto &[order_id, val] : mp) {
            if (val.first == orderType and val.second == price) {
                res.push_back(order_id);
            }
        }
        return res;
    }
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */