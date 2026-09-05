class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        maxLeft[0] = h[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(h[i], maxLeft[i - 1]);
        }

        maxRight[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], h[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int water = min(maxLeft[i], maxRight[i]) - h[i];
            if (water > 0) totalWater += water;
        }

        return totalWater;
    }
};
