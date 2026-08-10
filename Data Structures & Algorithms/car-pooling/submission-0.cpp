class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // pickupHeap: {startLocation, passengers}
        // dropoffHeap: {endLocation, passengers}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pickupHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dropoffHeap;

        for (auto &trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            pickupHeap.push({start, passengers});
            dropoffHeap.push({end, passengers});
        }

        int currPassengers = 0;

        while (!pickupHeap.empty() || !dropoffHeap.empty()) {
            int nextLoc;

            if (pickupHeap.empty()) {
                nextLoc = dropoffHeap.top().first;
            } else if (dropoffHeap.empty()) {
                nextLoc = pickupHeap.top().first;
            } else {
                nextLoc = min(pickupHeap.top().first, dropoffHeap.top().first);
            }

            // 1) Process all dropoffs at this location first
            while (!dropoffHeap.empty() && dropoffHeap.top().first == nextLoc) {
                currPassengers -= dropoffHeap.top().second;
                dropoffHeap.pop();
            }

            // 2) Then process all pickups at this location
            while (!pickupHeap.empty() && pickupHeap.top().first == nextLoc) {
                currPassengers += pickupHeap.top().second;
                if (currPassengers > capacity) return false;
                pickupHeap.pop();
            }
        }

        return true;
    }
};