class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // we choose a map since it is already sorted by default
        map<int, int> events;

        for(auto it: trips){
            int passengers = it[0];
            int pickup = it[1];
            int dropOff = it[2];

            events[pickup] += passengers;
            events[dropOff] -= passengers;
        }

        int count = 0;

        for(auto it: events){
            count += it.second;

            if(count > capacity) return false;
        }

        return true;
    }
};