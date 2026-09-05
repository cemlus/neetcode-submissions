class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int l = 0, r = n - 1;
        int maxLeft = height[l], maxRight = height[r];

        int totalWater = 0;
        while(l < r){
            if(maxLeft < maxRight){
                l++;
                maxLeft = max(height[l], maxLeft);
                totalWater += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(height[r], maxRight);
                totalWater += maxRight - height[r];
            }
        }
        return totalWater;
    }
};