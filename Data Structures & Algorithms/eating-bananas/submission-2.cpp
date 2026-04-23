class Solution {
public:
    long long timeTaken(const vector<int>& piles, int k) {
        long long totalTime = 0;
        for (int bananas : piles) {
            totalTime += (bananas + k - 1) / k; // ceil division
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int x : piles) {
            maxi = max(maxi, x);
        }

        int low = 1, hi = maxi;
        int ans = maxi;

        while (low <= hi) {
            int mid = low + (hi - low) / 2;

            if (timeTaken(piles, mid) <= h) {
                ans = mid;
                hi = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;   // need bigger speed
            }
        }

        return ans;
    }
};