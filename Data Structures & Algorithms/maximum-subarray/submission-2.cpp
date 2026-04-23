class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefixSum = 0;
        int maxLen = 0, maxi = INT_MIN;
        int newStart = 0, newEnd = 0;
        int idx = 0;
        int negativeSum = 0;

        if(nums.size() == 1) return nums[0];
        for(int r = 0; r < nums.size() ; r++){
            // new subarray has started, reset idx to keep track of new array
            if(prefixSum == 0) idx = r;

            prefixSum += nums[r];

            if(prefixSum > maxi){
                maxi = prefixSum;
                // find out length of this subarray who's sum is greater that all the previous subarrays
                cout << "index: " << r << endl;
                newStart = idx;
                newEnd = r;
                maxLen = max(maxLen, newEnd - newStart + 1);
            }
            
            if(prefixSum < 0){
                prefixSum = 0;
            }
        }
        return maxi;;
    }
};
