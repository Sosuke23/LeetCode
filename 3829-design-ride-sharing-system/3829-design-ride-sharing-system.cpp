class RideSharingSystem {
public:

    std::vector<int> rider, driver;
    RideSharingSystem() {
        rider = std::vector<int> ();
        driver = std::vector<int> ();
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if (rider.size() > 0 and driver.size() > 0) {
            int r = rider[0], d = driver[0];
            rider.erase(begin(rider));
            driver.erase(begin(driver));
            return {d, r};
        } else {
            return {-1, -1};
        }
    }
    
    void cancelRider(int riderId) {
        auto it = std::find(begin(rider), end(rider), riderId); 
        if (it != end(rider)) {
            int idx = it - begin(rider);
            rider.erase(begin(rider) + idx);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */