class Solution {
public:

    int daysTaken(vector<int> weights, int capacity){
        int load = 0;
        int days = 1;
        for(int i = 0; i < weights.size(); i++){
            // use a greedy way to include different packages
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int lo = maxi;
        int hi = sum;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            cout << "days: " << daysTaken(weights, mid) << endl;
            cout << mid << endl;
            if(daysTaken(weights, mid) <= days){
                // decrease capacity
                hi = mid;
            } else {
                // increase capacity
                lo = mid + 1;
            }
        }
        return lo;

    }
};