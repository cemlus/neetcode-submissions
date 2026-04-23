class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currSum = 0, minLen = INT_MAX;
        for(int right = 0 ; right < nums.size() ; right++){
            currSum += nums[right];
            while(currSum >= target){
                currSum -= nums[left];
                minLen = min(minLen, right - left + 1);
                left++;
            }
        }
        if(minLen == INT_MAX){
            // means the lenngth didn't change, i.e. no subarray had a sum greater than the target
            cout << currSum << endl;
            return 0;
        }
        return minLen;
    }
};