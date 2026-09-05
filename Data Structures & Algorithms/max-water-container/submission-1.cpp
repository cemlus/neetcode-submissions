class Solution {
   public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;

        int maxArea = 0;
        while (l < r) {
            maxArea = max(maxArea, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r]) {
                // since we have a greater height, we won't sacrifice that and would move the other
                // pointer to the next index to get a greater height whilst decreasing the width of
                // the area
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else {
                r--;
                l++;
            }
        }

        return maxArea;
    }
};