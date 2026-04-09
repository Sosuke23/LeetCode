class EventManager {
public:
    
    std::unordered_map<int, int> mp; // {eventId, priority}
    std::priority_queue<pair<int, int>> pq; // {priority, -eventId}

    EventManager(vector<vector<int>>& events) {
        for (std::vector<int> &e : events) {
            mp[e[0]] = e[1];
            pq.push({e[1], -e[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [priority, eventId] = pq.top();
            eventId = -eventId;

            if (mp.count(eventId) && mp[eventId] == priority) {
                pq.pop();
                mp.erase(eventId);
                return eventId;
            }

            pq.pop();
        }

        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */